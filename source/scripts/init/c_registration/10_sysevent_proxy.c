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
 * Copyright (c) 2010 by Cisco Systems, Inc. All Rights Reserved.
 *
 * This work is subject to U.S. and international copyright laws and
 * treaties. No part of this work may be used, practiced, performed,
 * copied, distributed, revised, modified, translated, abridged, condensed,
 * expanded, collected, compiled, linked, recast, transformed or adapted
 * without the prior written consent of Cisco Systems, Inc. Any use or
 * exploitation of this work without authorization could subject the
 * perpetrator to criminal and civil liability.
 */
#include <stdio.h>
#include <stdlib.h>
#include "srvmgr/srvmgr.h"

const char* SERVICE_NAME            = "sysevent_proxy";
const char* SERVICE_DEFAULT_HANDLER = "/etc/utopia/service.d/service_sysevent_proxy.sh";
const char* SERVICE_CUSTOM_EVENTS[] = { 
                                        "bootstrap_dns-status|/etc/utopia/service.d/service_sysevent_proxy.sh",
                                        NULL 
                                      };


void srv_register(void) {
   sm_register(SERVICE_NAME, SERVICE_DEFAULT_HANDLER, SERVICE_CUSTOM_EVENTS);
   system ("/etc/utopia/service.d/pmon.sh register syseventd_proxy");
}

void srv_unregister(void) {
   system ("/etc/utopia/service.d/pmon.sh unregister syseventd_proxy");
   sm_unregister(SERVICE_NAME);
}

int main(int argc, char **argv)
{
   cmd_type_t choice = parse_cmd_line(argc, argv);

   switch(choice) {
      case(nochoice):
      case(start):
         srv_register();
         break;
      case(stop):
         srv_unregister();
         break;
      case(restart):
         srv_unregister();
         srv_register();
         break;
      default:
         printf("%s called with invalid parameter (%s)\n", argv[0], 1==argc ? "" : argv[1]);
   }
   return(0);
}
