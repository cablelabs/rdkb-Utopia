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

#ifndef __HDK_DEVICE_H__
#define __HDK_DEVICE_H__

#include "hdk_mod.h"
#include "hdk_srv.h"
#include "hdk_xml.h"

#include "utctx.h"

#ifdef HNAP_DEBUG
#include <stdio.h>
#endif

/*
 * Macro to control public exports
 */
#define HDK_ADI_EXPORT_PREFIX extern
#ifdef HDK_ADI_BUILD
# define HDK_ADI_EXPORT HDK_ADI_EXPORT_PREFIX __attribute__ ((visibility("default")))
#else
# define HDK_ADI_EXPORT HDK_ADI_EXPORT_PREFIX
#endif

typedef struct _HDK_SRV_DeviceContext
{
    /* Utopia context */
    UtopiaContext utopiaCtx;

    /* Request file handle for debug */
#ifdef HNAP_DEBUG
    FILE* fhRequest;
#endif
    /* Log file handle for logging */
#ifdef HDK_LOGGING
    FILE* fhLogging;
#endif
} HDK_SRV_DeviceContext;

/* MACRO for accessing utopiaCtx pointer given the pMethodCtx */
#define pUTCtx(pMethodCtx) (&((HDK_SRV_DeviceContext*)pMethodCtx->pModuleCtx->pModuleCtx)->utopiaCtx)

/* Initialize device context */
HDK_ADI_EXPORT void HDK_SRV_Device_Init(HDK_SRV_DeviceContext* pDeviceCtx);

/* Free device context */
HDK_ADI_EXPORT void HDK_SRV_Device_Free(HDK_SRV_DeviceContext* pDeviceCtx, int fCommit);


/* Device ADIGet implementation */
HDK_ADI_EXPORT const char* HDK_SRV_Device_ADIGet(HDK_MOD_MethodContext* pMethodCtx, const char* pszNamespace,
                                                 const char* pszName);

/* Device ADISet implementation */
HDK_ADI_EXPORT int HDK_SRV_Device_ADISet(HDK_MOD_MethodContext* pMethodCtx, const char* pszNamespace,
                                         const char* pszName, const char* pszValue);


#endif  /* __HDK_DEVICE_H__ */
