/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2015 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

/**********************************************************************
   Copyright [2015] [Cisco Systems, Inc.]
 
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
#include "service_multinet_base.h"
#include "puma6_plat_sw.h"
#include "puma6_plat_map.h"
#include "service_multinet_ep.h"

#include <stdio.h>
#include <string.h>

static unsigned char bLibInited = 0;


static int psm_get_record(const char *name, char *val, int size)
{
    FILE *fp;
    char cmd[256];

    snprintf(cmd, sizeof(cmd), "psmcli get %s", name);

    if ((fp = popen(cmd, "rb")) == NULL) {
        return -1;
    }

    fgets(val, size, fp);

    pclose(fp);
    return 0;
}

int configVlan_ESW(PSWFabHALArg args, int numArgs, BOOL up) {
    int i;
    PSwPortState portState;
    
    char cmdBuff[128];
    char ifname[80];
    
    for (i = 0; i < numArgs; ++i ) {
        
        portState = (PSwPortState) args[i].portID;
        stringIDExtSw(portState, ifname, sizeof(ifname));
        
        //#Args: netid, netvid, members...
        sprintf(cmdBuff, "%s %s %d %d \"%s%s\"", SERVICE_MULTINET_DIR "/handle_sw.sh", up ? "addVlan" : "delVlan", args[i].hints.network->inst, args[i].vidParams.vid, ifname, args[i].vidParams.tagging ? "-t" : "");
        
        system(cmdBuff);
        
    }
    
}

int configVlan_WiFi(PSWFabHALArg args, int numArgs, BOOL up) {
    int i;
    
    char cmdBuff[128];
    
    for (i = 0; i < numArgs; ++i ) {

        
        //#Args: netid, netvid, members...
        sprintf(cmdBuff, "%s %s %d %d \"%s%s\"", SERVICE_MULTINET_DIR "/handle_wifi.sh", up ? "addVlan" : "delVlan", args[i].hints.network->inst, args[i].vidParams.vid, (char*)args[i].portID, args[i].vidParams.tagging ? "-t" : "");
        
        system(cmdBuff);
        
    }
    
}

int stringIDIntSw (void* portID, char* stringbuf, int bufSize) {
    PSwPortState portState = (PSwPortState) portID;
    int retval = snprintf(stringbuf, bufSize, "%s", portState->stringID);
    
    return retval ? retval + 1 : 0;
}

int eventIDSw (void* portID, char* stringbuf, int bufSize) {
    PSwPortState portState = (PSwPortState) portID;
    return (eventIDFromStringPortID((void*)portState->stringID, stringbuf, bufSize));
}

int stringIDExtSw (void* portID, char* stringbuf, int bufSize) {
    PSwPortState portState = (PSwPortState) portID;
    int retval = snprintf(stringbuf, bufSize, "%s", portState->stringID);
    
    return retval ? retval + 1 : 0;
}

int configVlan_ISW(PSWFabHALArg args, int numArgs, BOOL up) {
    int i;
    PSwPortState portState;
    char cmdBuff[128];
    char ifname[80];
    
    for (i = 0; i < numArgs; ++i ) {
        portState = (PSwPortState) args[i].portID;
        stringIDIntSw(portState, ifname, sizeof(ifname));
        
        //#Args: netid, netvid, members...
        sprintf(cmdBuff, "%s %s %d %d \"%s%s\"", SERVICE_MULTINET_DIR "/handle_sw.sh", up ? "addVlan" : "delVlan", args[i].hints.network->inst, args[i].vidParams.vid, ifname, args[i].vidParams.tagging ? "-t" : "");
        
        system(cmdBuff);
    }
}