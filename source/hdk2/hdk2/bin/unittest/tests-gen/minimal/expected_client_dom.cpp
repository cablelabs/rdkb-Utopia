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
 * Copyright (c) 2008-2010 Cisco Systems, Inc. All rights reserved.
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

// actual_client_dom.cpp - [Generated by hdkcli_cpp]

// Local header.
#include "actual_client_dom.h"

using namespace HDK;

Cisco::CiscoActionStruct::CiscoActionStruct() throw() :
    Struct(ACTUAL_CLIENT_DOM_MOD_Element_Cisco_CiscoAction)
{
}

Cisco::CiscoActionResponseStruct::CiscoActionResponseStruct() throw() :
    Struct(ACTUAL_CLIENT_DOM_MOD_Element_Cisco_CiscoAction)
{
}

enum Cisco::CiscoActionResult Cisco::CiscoActionResponseStruct::get_CiscoActionResult() const throw()
{
    return (enum Cisco::CiscoActionResult)ACTUAL_CLIENT_DOM_MOD_GetEx_Cisco_CiscoActionResult(GetStruct(), ACTUAL_CLIENT_DOM_MOD_Element_Cisco_CiscoActionResult, ACTUAL_CLIENT_DOM_MOD_Enum_Cisco_CiscoActionResult__UNKNOWN__);
}

bool HDK::InitializeClient() throw()
{
    return !!HDK_CLI_Init();
}

void HDK::UninitializeClient() throw()
{
    HDK_CLI_Cleanup();
}

HDK::ClientError Cisco::CiscoAction
(
    HDK::ITarget* pTarget,
    enum Cisco::CiscoActionResult* presult /* = NULL */,
    unsigned int timeoutSecs /* = 0 */
) throw()
{
    if (!pTarget)
    {
        return ClientError_InvalidArg;
    }
    Cisco::CiscoActionStruct input;

    Cisco::CiscoActionResponseStruct output;

    ClientError error = pTarget->Request(timeoutSecs,
                                         ACTUAL_CLIENT_DOM_MOD_Module(),
                                         ACTUAL_CLIENT_DOM_MOD_MethodEnum_Cisco_CiscoAction,
                                         input,
                                         &output);

    const HDK_MOD_Method* pMethod = HDK_MOD_GetMethod(ACTUAL_CLIENT_DOM_MOD_Module(), ACTUAL_CLIENT_DOM_MOD_MethodEnum_Cisco_CiscoAction);

    // Get the result value.
    enum Cisco::CiscoActionResult result = output.get_CiscoActionResult();
    if (NULL != presult)
    {
        *presult = result;
    }

    // Determine if there was an HNAP-result, and whether it was an error or not.
    if ((ClientError_OK == error) && (HDK_XML_BuiltinElement_Unknown != pMethod->hnapResultElement))
    {
        if ((pMethod->hnapResultOK != (int)result) && (pMethod->hnapResultREBOOT != (int)result))
        {
            // An HNAP error response.
            error = HDK::ClientError_HnapMethod;
        }
    }

    return error;
}
