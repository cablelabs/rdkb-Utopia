/**********************************************************************
   Copyright [2014] [Cisco Systems, Inc.]
 
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
 
       http://www.apache.org/licenses/LICENSE-2.0
 
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
**********************************************************************/

/*
 * Copyright (c) 2008-2009 Cisco Systems, Inc. All rights reserved.
 *
 * Cisco Systems, Inc. retains all right, title and interest (including all
 * intellectual property rights) in and to this computer program, which is
 * protected by applicable intellectual property laws.  Unless you have obtained
 * a separate written license from Cisco Systems, Inc., you are not authorized
 * to utilize all or a part of this computer program for any purpose (including
 * reproduction, distribution, modification, and compilation into object code),
 * and you must immediately destroy or return to Cisco Systems, Inc. all copies
 * of this computer program.  If you are licensed by Cisco Systems, Inc., your
 * rights to utilize this computer program are limited by the terms of that
 * license.  To obtain a license, please contact Cisco Systems, Inc.
 *
 * This computer program contains trade secrets owned by Cisco Systems, Inc.
 * and, unless unauthorized by Cisco Systems, Inc. in writing, you agree to
 * maintain the confidentiality of this computer program and related information
 * and to not disclose this computer program and related information to any
 * other person or entity.
 *
 * THIS COMPUTER PROGRAM IS PROVIDED AS IS WITHOUT ANY WARRANTIES, AND CISCO
 * SYSTEMS, INC. EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED,
 * INCLUDING THE WARRANTIES OF MERCHANTIBILITY, FITNESS FOR A PARTICULAR
 * PURPOSE, TITLE, AND NONINFRINGEMENT.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "utapi.h"
#include "utapi_util.h"

// Global
char ulog_msg[1024];
int  err_rc;
char s_intbuf[16];
char s_tokenbuf[256];



/* Helper function to map from HDK_Enum to string */
char* s_EnumToStr (EnumString_Map* pMap, int iEnum)
{
    if (!pMap)
    {
        return 0;
    }

    for(;pMap->pszStr; ++pMap)
    {
        if (iEnum == pMap->iEnum)
        {
            return pMap->pszStr;
        }
    }

    return 0;
}

int s_StrToEnum (EnumString_Map* pMap, const char *iStr)
{
    if (!pMap || !iStr)
    {
        return -1;
    }

    for(;pMap->pszStr; ++pMap)
    {
        if (0 == strcmp(iStr, pMap->pszStr))
        {
            return pMap->iEnum;
        }
    }

    return -1;
}

/*
 * find delim, replace with '\0' and return ptr after delim char
 * returns null if no delim found
 */
char *chop_str (char *str, char delim)
{
    char *p;

    if (str && (p = strchr(str, delim))) {
        *p = '\0';
        return p+1;
    }
    return NULL;
}


/*
 * Utility routines
 */
int IsValid_IPAddr (const char *ip)
{
    struct in_addr in;

    if (ip && *ip && inet_aton(ip, &in)) {
        return TRUE;
    }
    return FALSE;
}

int IsValid_IPAddrLastOctet (int ipoctet)
{
    if (ipoctet > 1 && ipoctet < 255) {
        return TRUE;
    }
    return FALSE;
}

int IsValid_Netmask (const char *ip)
{
    // Unused
    (void) ip;
    return TRUE;
}

int IsValid_MACAddr (const char *mac)
{
    // Unused
    (void) mac;
    return TRUE;
}

boolean_t IsInteger (const char *str)
{
    int i; 

    for (i = 0; str[i]; i++) {
        if (!isdigit(str[i])) {
            return FALSE;
        }
    }
    return TRUE;
}

/*
 * IPV4 Address check functions
 */
/* addr is in network order */
int IsSameNetwork(unsigned long addr1, unsigned long addr2, unsigned long mask)
{
    return (addr1 & mask) == (addr2 & mask);
}

/* addr is in network order */
int IsLoopback(unsigned long addr)
{
    return (addr & htonl(0xff000000)) == htonl(0x7f000000);
}

/* addr is in network order */
int IsMulticast(unsigned long addr)
{
    return (addr & htonl(0xf0000000)) == htonl(0xe0000000);
}

/* addr is in network order */
int IsBroadcast(unsigned long addr, unsigned long net, unsigned long mask)
{
    /* all ones or all zeros (old) */
    if (addr == 0xffffffff)
        return 1;

    /* on the same sub network and host bits are all ones */
    if (IsSameNetwork(addr, net, mask)
            && (addr & ~mask) == (0xffffffff & ~mask))
        return 1;

    return 0;
}

/* addr is in network order */
int IsNetworkAddr(unsigned long addr, unsigned long net, unsigned long mask)
{
    if (IsSameNetwork(addr, net, mask)
            && (addr & ~mask) == 0)
        return 1;

    return 0;
}

/* addr is in network order */
int IsNetmaskValid(unsigned long netmask)
{
    unsigned long mask;
    unsigned long hostorder = ntohl(netmask);

    /* first zero */
    for (mask = 1UL << 31 ; mask != 0; mask >>= 1)
        if ((hostorder & mask) == 0)
            break;

    /* there is no one ? */
    for (; mask != 0; mask >>= 1)
        if ((hostorder & mask) != 0)
            return 0;

    return 1;
}

void s_get_interface_mac (char *ifname, char *out_buf, int bufsz)
{
    int fd;
    struct ifreq ifr;

    bzero(&ifr, sizeof(struct ifreq));
    if ((fd = socket(PF_INET, SOCK_RAW, IPPROTO_RAW)) >= 0) {
        ifr.ifr_addr.sa_family = AF_INET;
        strncpy(ifr.ifr_name, ifname, 16);
        if (ioctl(fd, SIOCGIFHWADDR, &ifr) == 0) {
            snprintf(out_buf, bufsz, "%.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n",
                    (unsigned char)ifr.ifr_hwaddr.sa_data[0],
                    (unsigned char)ifr.ifr_hwaddr.sa_data[1],
                    (unsigned char)ifr.ifr_hwaddr.sa_data[2],
                    (unsigned char)ifr.ifr_hwaddr.sa_data[3],
                    (unsigned char)ifr.ifr_hwaddr.sa_data[4],
                    (unsigned char)ifr.ifr_hwaddr.sa_data[5]);
        } 
        close(fd);
    }
}

int s_sysevent_connect (token_t *out_se_token)
{
    static int     sysevent_fd = -1;
    static token_t sysevent_token = 0;


    if (0 > sysevent_fd) {
        unsigned short sysevent_port = SE_SERVER_WELL_KNOWN_PORT;
        char           sysevent_ip[19];
        char          *sysevent_name = "utapi";

        snprintf(sysevent_ip, sizeof(sysevent_ip), "127.0.0.1");
        sysevent_fd =  sysevent_open(sysevent_ip, sysevent_port, SE_VERSION, sysevent_name, &sysevent_token);
        ulogf(ULOG_CONFIG, UL_UTAPI, "%s: open new sysevent fd %d", __FUNCTION__, sysevent_fd);
    }

    *out_se_token = sysevent_token;
    return sysevent_fd;
}


/*
 * Set wrappers
 */
int Utopia_SetInt (UtopiaContext *ctx, UtopiaValue ixUtopia, int value)
{
    char intbuf[32];

    snprintf(intbuf, sizeof(intbuf), "%d", value);
    return (0 == Utopia_Set(ctx, ixUtopia, intbuf)) ? ERR_UTCTX_OP : SUCCESS;
}

int Utopia_SetBool (UtopiaContext *ctx, UtopiaValue ixUtopia, boolean_t value)
{
    return (0 == Utopia_Set(ctx, ixUtopia, (value) ? "1" : "0"))  ? ERR_UTCTX_OP : SUCCESS;
}

int Utopia_SetIndexedInt (UtopiaContext *ctx, UtopiaValue ixUtopia,
                                 int iIndex, int value)
{
    char intbuf[32];

    snprintf(intbuf, sizeof(intbuf), "%d", value);
    return (0 == Utopia_SetIndexed(ctx, ixUtopia, iIndex, intbuf)) ? ERR_UTCTX_OP : SUCCESS;
}

/*
 * Set 0 - for FALSE,  1 - for TRUE
 */
int Utopia_SetIndexedBool (UtopiaContext *ctx, UtopiaValue ixUtopia,
                                  int iIndex, boolean_t value)
{
    return (0 == Utopia_SetIndexed(ctx, ixUtopia, iIndex, (TRUE == value) ? "1" : "0"))  ? ERR_UTCTX_OP : SUCCESS;
}

int Utopia_SetNamedInt (UtopiaContext *ctx, UtopiaValue ixUtopia, char *prefix, int value)
{
    char intbuf[32];

    snprintf(intbuf, sizeof(intbuf), "%d", value);
    return (0 == Utopia_SetNamed(ctx, ixUtopia, prefix, intbuf)) ? ERR_UTCTX_OP : SUCCESS;
}

int Utopia_SetNamedBool (UtopiaContext *ctx, UtopiaValue ixUtopia, char *prefix, boolean_t value)
{
    return (0 == Utopia_SetNamed(ctx, ixUtopia, prefix, (TRUE == value) ? "1" : "0")) ? ERR_UTCTX_OP : SUCCESS;
}

int Utopia_SetNamedLong (UtopiaContext *ctx, UtopiaValue ixUtopia, char *prefix, unsigned long value)
{
    char longbuf[32];

    snprintf(longbuf, sizeof(longbuf), "%u", value);
    return (0 == Utopia_SetNamed(ctx, ixUtopia, prefix, longbuf)) ? ERR_UTCTX_OP : SUCCESS;
}



/*
 * Get wrappers
 */
int Utopia_GetInt (UtopiaContext *ctx, UtopiaValue ixUtopia, int *out_int)
{
    char intbuf[16] = {0};

    if (0 == Utopia_Get(ctx, ixUtopia, intbuf, sizeof(intbuf))) {
        return ERR_UTCTX_OP;
    }
    if (FALSE == IsInteger(intbuf)) {
        return ERR_INVALID_INT_VALUE;
    }
    *out_int = atoi(intbuf);
    return SUCCESS;
}

int Utopia_GetIndexedInt (UtopiaContext *ctx, UtopiaValue ixUtopia,
                                 int index, int *out_int)
{
    char intbuf[16] = {0};

    if (0 == Utopia_GetIndexed(ctx, ixUtopia, index, intbuf, sizeof(intbuf))) {
        return ERR_UTCTX_OP;
    }
    if (FALSE == IsInteger(intbuf)) {
        return ERR_INVALID_INT_VALUE;
    }
    *out_int = atoi(intbuf);
    return SUCCESS;
}

int Utopia_GetBool (UtopiaContext *ctx, UtopiaValue ixUtopia,
                           boolean_t *out_bool)
{
    char intbuf[16] = {0};

    if (0 == Utopia_Get(ctx, ixUtopia, intbuf, sizeof(intbuf))) {
        return ERR_UTCTX_OP;
    }
    *out_bool = (0 == strcmp(intbuf, "1")) ? TRUE : FALSE;
    return SUCCESS;
}

int Utopia_GetIndexedBool (UtopiaContext *ctx, UtopiaValue ixUtopia,
                                  int index, boolean_t *out_bool)
{
    char intbuf[16];

    if (0 == Utopia_GetIndexed(ctx, ixUtopia, index, intbuf, sizeof(intbuf))) {
        return ERR_UTCTX_OP;
    }
    *out_bool = (0 == strcmp(intbuf, "1")) ? TRUE : FALSE;
    return SUCCESS;
}

int Utopia_GetIndexed2Int (UtopiaContext *ctx, UtopiaValue ixUtopia,
                                  int index1, int index2, int *out_int)
{
    char intbuf[16] = {0};

    if (0 == Utopia_GetIndexed2(ctx, ixUtopia, index1, index2, intbuf, sizeof(intbuf))) {
        return ERR_UTCTX_OP;
    }
    if (FALSE == IsInteger(intbuf)) {
        return ERR_INVALID_INT_VALUE;
    }
    *out_int = atoi(intbuf);
    return SUCCESS;
}

int Utopia_GetIndexed2Bool (UtopiaContext *ctx, UtopiaValue ixUtopia,
                                   int index1, int index2, boolean_t *out_bool)
{
    char intbuf[16];

    if (0 == Utopia_GetIndexed2(ctx, ixUtopia, index1, index2, intbuf, sizeof(intbuf))) {
        return ERR_UTCTX_OP;
    }
    *out_bool = (0 == strcmp(intbuf, "1")) ? TRUE : FALSE;
    return SUCCESS;
}

int Utopia_GetNamedBool (UtopiaContext *ctx, UtopiaValue ixUtopia,
                           char *name, boolean_t *out_bool)
{
    char intbuf[16] = {0};

    if (0 == Utopia_GetNamed(ctx, ixUtopia, name, intbuf, sizeof(intbuf))) {
        return ERR_UTCTX_OP;
    }
    *out_bool = (0 == strcmp(intbuf, "1")) ? TRUE : FALSE;
    return SUCCESS;
}

int Utopia_GetNamedInt (UtopiaContext *ctx, UtopiaValue ixUtopia,
                                 char *name, int *out_int)
{
    char intbuf[16] = {0};

    if (0 == Utopia_GetNamed(ctx, ixUtopia, name, intbuf, sizeof(intbuf))) {
        return ERR_UTCTX_OP;
    }
    if (FALSE == IsInteger(intbuf)) {
        return ERR_INVALID_INT_VALUE;
    }
    *out_int = atoi(intbuf);
    return SUCCESS;
}

int Utopia_GetNamedLong (UtopiaContext *ctx, UtopiaValue ixUtopia,
                                 char *name, unsigned long *out_long)
{
    char longbuf[32] = {0};

    if (0 == Utopia_GetNamed(ctx, ixUtopia, name, longbuf, sizeof(longbuf))) {
        return ERR_UTCTX_OP;
    }
    if (FALSE == IsInteger(longbuf)) {
        return ERR_INVALID_INT_VALUE;
    }
    *out_long = atol(longbuf);
    return SUCCESS;
}

