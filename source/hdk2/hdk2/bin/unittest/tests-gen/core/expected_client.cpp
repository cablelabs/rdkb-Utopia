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

// actual_client.cpp - [Generated by hdkcli_cpp]

// Local header.
#include "actual_client.h"

using namespace HDK;

Cisco_HNAP::ActionStruct::ActionStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Action)
{
}

HDK_XML_Int Cisco_HNAP::ActionStruct::get_Member() const throw()
{
    return HDK_XML_GetEx_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Member, 0);
}

void Cisco_HNAP::ActionStruct::set_Member(HDK_XML_Int value) throw()
{
    (void)HDK_XML_Set_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Member, value);
}

Cisco_HNAP::ActionResponseStruct::ActionResponseStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Action)
{
}

enum Cisco_HNAP::ActionResult Cisco_HNAP::ActionResponseStruct::get_ActionResult() const throw()
{
    return (enum Cisco_HNAP::ActionResult)ACTUAL_CLIENT_MOD_GetEx_ActionResult(GetStruct(), ACTUAL_CLIENT_MOD_Element_ActionResult, ACTUAL_CLIENT_MOD_Enum_ActionResult__UNKNOWN__);
}

Cisco_HNAP_Sub::ActionSubStruct::ActionSubStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Sub_ActionSub)
{
}

HDK_XML_Int Cisco_HNAP_Sub::ActionSubStruct::get_MemberSub() const throw()
{
    return HDK_XML_GetEx_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Sub_MemberSub, 0);
}

void Cisco_HNAP_Sub::ActionSubStruct::set_MemberSub(HDK_XML_Int value) throw()
{
    (void)HDK_XML_Set_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Sub_MemberSub, value);
}

Cisco_HNAP_Sub::ActionSubResponseStruct::ActionSubResponseStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Sub_ActionSub)
{
}

enum Cisco_HNAP_Sub::ActionSubResult Cisco_HNAP_Sub::ActionSubResponseStruct::get_ActionSubResult() const throw()
{
    return (enum Cisco_HNAP_Sub::ActionSubResult)ACTUAL_CLIENT_MOD_GetEx_Sub_ActionSubResult(GetStruct(), ACTUAL_CLIENT_MOD_Element_Sub_ActionSubResult, ACTUAL_CLIENT_MOD_Enum_Sub_ActionSubResult__UNKNOWN__);
}

Cisco::ActionExtStruct::ActionExtStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Cisco_ActionExt)
{
}

HDK_XML_Int Cisco::ActionExtStruct::get_MemberExt() const throw()
{
    return HDK_XML_GetEx_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Cisco_MemberExt, 0);
}

void Cisco::ActionExtStruct::set_MemberExt(HDK_XML_Int value) throw()
{
    (void)HDK_XML_Set_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Cisco_MemberExt, value);
}

Cisco::ActionExtResponseStruct::ActionExtResponseStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Cisco_ActionExt)
{
}

enum Cisco::ActionExtResult Cisco::ActionExtResponseStruct::get_ActionExtResult() const throw()
{
    return (enum Cisco::ActionExtResult)ACTUAL_CLIENT_MOD_GetEx_Cisco_ActionExtResult(GetStruct(), ACTUAL_CLIENT_MOD_Element_Cisco_ActionExtResult, ACTUAL_CLIENT_MOD_Enum_Cisco_ActionExtResult__UNKNOWN__);
}

Cisco_Sub::ActionExtSubStruct::ActionExtSubStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Cisco_Sub_ActionExtSub)
{
}

HDK_XML_Int Cisco_Sub::ActionExtSubStruct::get_MemberExtSub() const throw()
{
    return HDK_XML_GetEx_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Cisco_Sub_MemberExtSub, 0);
}

void Cisco_Sub::ActionExtSubStruct::set_MemberExtSub(HDK_XML_Int value) throw()
{
    (void)HDK_XML_Set_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Cisco_Sub_MemberExtSub, value);
}

Cisco_Sub::ActionExtSubResponseStruct::ActionExtSubResponseStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Cisco_Sub_ActionExtSub)
{
}

enum Cisco_Sub::ActionExtSubResult Cisco_Sub::ActionExtSubResponseStruct::get_ActionExtSubResult() const throw()
{
    return (enum Cisco_Sub::ActionExtSubResult)ACTUAL_CLIENT_MOD_GetEx_Cisco_Sub_ActionExtSubResult(GetStruct(), ACTUAL_CLIENT_MOD_Element_Cisco_Sub_ActionExtSubResult, ACTUAL_CLIENT_MOD_Enum_Cisco_Sub_ActionExtSubResult__UNKNOWN__);
}

Purenetworks_HNAP::ActionLegacy2Struct::ActionLegacy2Struct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Purenetworks_HNAP_ActionLegacy2)
{
}

HDK_XML_Int Purenetworks_HNAP::ActionLegacy2Struct::get_MemberLegacy2() const throw()
{
    return HDK_XML_GetEx_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Purenetworks_HNAP_MemberLegacy2, 0);
}

void Purenetworks_HNAP::ActionLegacy2Struct::set_MemberLegacy2(HDK_XML_Int value) throw()
{
    (void)HDK_XML_Set_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Purenetworks_HNAP_MemberLegacy2, value);
}

Purenetworks_HNAP::ActionLegacy2ResponseStruct::ActionLegacy2ResponseStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Purenetworks_HNAP_ActionLegacy2)
{
}

enum Purenetworks_HNAP::ActionLegacy2Result Purenetworks_HNAP::ActionLegacy2ResponseStruct::get_ActionLegacy2Result() const throw()
{
    return (enum Purenetworks_HNAP::ActionLegacy2Result)ACTUAL_CLIENT_MOD_GetEx_Purenetworks_HNAP_ActionLegacy2Result(GetStruct(), ACTUAL_CLIENT_MOD_Element_Purenetworks_HNAP_ActionLegacy2Result, ACTUAL_CLIENT_MOD_Enum_Purenetworks_HNAP_ActionLegacy2Result__UNKNOWN__);
}

Purenetworks_HNAP_Sub::ActionLegacy2SubStruct::ActionLegacy2SubStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_PN_Sub_ActionLegacy2Sub)
{
}

HDK_XML_Int Purenetworks_HNAP_Sub::ActionLegacy2SubStruct::get_MemberLegacy2Sub() const throw()
{
    return HDK_XML_GetEx_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_PN_Sub_MemberLegacy2Sub, 0);
}

void Purenetworks_HNAP_Sub::ActionLegacy2SubStruct::set_MemberLegacy2Sub(HDK_XML_Int value) throw()
{
    (void)HDK_XML_Set_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_PN_Sub_MemberLegacy2Sub, value);
}

Purenetworks_HNAP_Sub::ActionLegacy2SubResponseStruct::ActionLegacy2SubResponseStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_PN_Sub_ActionLegacy2Sub)
{
}

enum Purenetworks_HNAP_Sub::ActionLegacy2SubResult Purenetworks_HNAP_Sub::ActionLegacy2SubResponseStruct::get_ActionLegacy2SubResult() const throw()
{
    return (enum Purenetworks_HNAP_Sub::ActionLegacy2SubResult)ACTUAL_CLIENT_MOD_GetEx_PN_Sub_ActionLegacy2SubResult(GetStruct(), ACTUAL_CLIENT_MOD_Element_PN_Sub_ActionLegacy2SubResult, ACTUAL_CLIENT_MOD_Enum_PN_Sub_ActionLegacy2SubResult__UNKNOWN__);
}

Purenetworks_HNAP1::ActionLegacyStruct::ActionLegacyStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_PN_ActionLegacy)
{
}

HDK_XML_Int Purenetworks_HNAP1::ActionLegacyStruct::get_MemberLegacy() const throw()
{
    return HDK_XML_GetEx_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_PN_MemberLegacy, 0);
}

void Purenetworks_HNAP1::ActionLegacyStruct::set_MemberLegacy(HDK_XML_Int value) throw()
{
    (void)HDK_XML_Set_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_PN_MemberLegacy, value);
}

Purenetworks_HNAP1::ActionLegacyResponseStruct::ActionLegacyResponseStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_PN_ActionLegacy)
{
}

enum Purenetworks_HNAP1::ActionLegacyResult Purenetworks_HNAP1::ActionLegacyResponseStruct::get_ActionLegacyResult() const throw()
{
    return (enum Purenetworks_HNAP1::ActionLegacyResult)ACTUAL_CLIENT_MOD_GetEx_PN_ActionLegacyResult(GetStruct(), ACTUAL_CLIENT_MOD_Element_PN_ActionLegacyResult, ACTUAL_CLIENT_MOD_Enum_PN_ActionLegacyResult__UNKNOWN__);
}

Purenetworks_HNAP1_Sub::ActionSubLegacyStruct::ActionSubLegacyStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Purenetworks_HNAP1_Sub_ActionSubLegacy)
{
}

HDK_XML_Int Purenetworks_HNAP1_Sub::ActionSubLegacyStruct::get_MemberLegacySub() const throw()
{
    return HDK_XML_GetEx_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Purenetworks_HNAP1_Sub_MemberLegacySub, 0);
}

void Purenetworks_HNAP1_Sub::ActionSubLegacyStruct::set_MemberLegacySub(HDK_XML_Int value) throw()
{
    (void)HDK_XML_Set_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Purenetworks_HNAP1_Sub_MemberLegacySub, value);
}

Purenetworks_HNAP1_Sub::ActionSubLegacyResponseStruct::ActionSubLegacyResponseStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Purenetworks_HNAP1_Sub_ActionSubLegacy)
{
}

enum Purenetworks_HNAP1_Sub::ActionSubLegacyResult Purenetworks_HNAP1_Sub::ActionSubLegacyResponseStruct::get_ActionSubLegacyResult() const throw()
{
    return (enum Purenetworks_HNAP1_Sub::ActionSubLegacyResult)ACTUAL_CLIENT_MOD_GetEx_Purenetworks_HNAP1_Sub_ActionSubLegacyResult(GetStruct(), ACTUAL_CLIENT_MOD_Element_Purenetworks_HNAP1_Sub_ActionSubLegacyResult, ACTUAL_CLIENT_MOD_Enum_Purenetworks_HNAP1_Sub_ActionSubLegacyResult__UNKNOWN__);
}

Purenetworks::ActionLegacyExtStruct::ActionLegacyExtStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Purenetworks_ActionLegacyExt)
{
}

HDK_XML_Int Purenetworks::ActionLegacyExtStruct::get_MemberLegacyExt() const throw()
{
    return HDK_XML_GetEx_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Purenetworks_MemberLegacyExt, 0);
}

void Purenetworks::ActionLegacyExtStruct::set_MemberLegacyExt(HDK_XML_Int value) throw()
{
    (void)HDK_XML_Set_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Purenetworks_MemberLegacyExt, value);
}

Purenetworks::ActionLegacyExtResponseStruct::ActionLegacyExtResponseStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Purenetworks_ActionLegacyExt)
{
}

enum Purenetworks::ActionLegacyExtResult Purenetworks::ActionLegacyExtResponseStruct::get_ActionLegacyExtResult() const throw()
{
    return (enum Purenetworks::ActionLegacyExtResult)ACTUAL_CLIENT_MOD_GetEx_Purenetworks_ActionLegacyExtResult(GetStruct(), ACTUAL_CLIENT_MOD_Element_Purenetworks_ActionLegacyExtResult, ACTUAL_CLIENT_MOD_Enum_Purenetworks_ActionLegacyExtResult__UNKNOWN__);
}

Purenetworks_Sub::ActionLegacyExtSubStruct::ActionLegacyExtSubStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Purenetworks_Sub_ActionLegacyExtSub)
{
}

HDK_XML_Int Purenetworks_Sub::ActionLegacyExtSubStruct::get_MemberLegacyExtSub() const throw()
{
    return HDK_XML_GetEx_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Purenetworks_Sub_MemberLegacyExtSub, 0);
}

void Purenetworks_Sub::ActionLegacyExtSubStruct::set_MemberLegacyExtSub(HDK_XML_Int value) throw()
{
    (void)HDK_XML_Set_Int(GetStruct(), ACTUAL_CLIENT_MOD_Element_Purenetworks_Sub_MemberLegacyExtSub, value);
}

Purenetworks_Sub::ActionLegacyExtSubResponseStruct::ActionLegacyExtSubResponseStruct() throw() :
    Struct(ACTUAL_CLIENT_MOD_Element_Purenetworks_Sub_ActionLegacyExtSub)
{
}

enum Purenetworks_Sub::ActionLegacyExtSubResult Purenetworks_Sub::ActionLegacyExtSubResponseStruct::get_ActionLegacyExtSubResult() const throw()
{
    return (enum Purenetworks_Sub::ActionLegacyExtSubResult)ACTUAL_CLIENT_MOD_GetEx_Purenetworks_Sub_ActionLegacyExtSubResult(GetStruct(), ACTUAL_CLIENT_MOD_Element_Purenetworks_Sub_ActionLegacyExtSubResult, ACTUAL_CLIENT_MOD_Enum_Purenetworks_Sub_ActionLegacyExtSubResult__UNKNOWN__);
}

bool HDK::InitializeClient() throw()
{
    return !!HDK_CLI_Init();
}

void HDK::UninitializeClient() throw()
{
    HDK_CLI_Cleanup();
}

HDK::ClientError Cisco_HNAP::Action
(
    HDK::ITarget* pTarget,
    const Cisco_HNAP::ActionStruct & input,
    enum Cisco_HNAP::ActionResult* presult /* = NULL */,
    unsigned int timeoutSecs /* = 0 */
) throw()
{
    if (!pTarget)
    {
        return ClientError_InvalidArg;
    }

    Cisco_HNAP::ActionResponseStruct output;

    ClientError error = pTarget->Request(timeoutSecs,
                                         ACTUAL_CLIENT_MOD_Module(),
                                         ACTUAL_CLIENT_MOD_MethodEnum_Action,
                                         input,
                                         &output);

    const HDK_MOD_Method* pMethod = HDK_MOD_GetMethod(ACTUAL_CLIENT_MOD_Module(), ACTUAL_CLIENT_MOD_MethodEnum_Action);

    // Get the result value.
    enum Cisco_HNAP::ActionResult result = output.get_ActionResult();
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

HDK::ClientError Cisco_HNAP_Sub::ActionSub
(
    HDK::ITarget* pTarget,
    const Cisco_HNAP_Sub::ActionSubStruct & input,
    enum Cisco_HNAP_Sub::ActionSubResult* presult /* = NULL */,
    unsigned int timeoutSecs /* = 0 */
) throw()
{
    if (!pTarget)
    {
        return ClientError_InvalidArg;
    }

    Cisco_HNAP_Sub::ActionSubResponseStruct output;

    ClientError error = pTarget->Request(timeoutSecs,
                                         ACTUAL_CLIENT_MOD_Module(),
                                         ACTUAL_CLIENT_MOD_MethodEnum_Sub_ActionSub,
                                         input,
                                         &output);

    const HDK_MOD_Method* pMethod = HDK_MOD_GetMethod(ACTUAL_CLIENT_MOD_Module(), ACTUAL_CLIENT_MOD_MethodEnum_Sub_ActionSub);

    // Get the result value.
    enum Cisco_HNAP_Sub::ActionSubResult result = output.get_ActionSubResult();
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

HDK::ClientError Cisco::ActionExt
(
    HDK::ITarget* pTarget,
    const Cisco::ActionExtStruct & input,
    enum Cisco::ActionExtResult* presult /* = NULL */,
    unsigned int timeoutSecs /* = 0 */
) throw()
{
    if (!pTarget)
    {
        return ClientError_InvalidArg;
    }

    Cisco::ActionExtResponseStruct output;

    ClientError error = pTarget->Request(timeoutSecs,
                                         ACTUAL_CLIENT_MOD_Module(),
                                         ACTUAL_CLIENT_MOD_MethodEnum_Cisco_ActionExt,
                                         input,
                                         &output);

    const HDK_MOD_Method* pMethod = HDK_MOD_GetMethod(ACTUAL_CLIENT_MOD_Module(), ACTUAL_CLIENT_MOD_MethodEnum_Cisco_ActionExt);

    // Get the result value.
    enum Cisco::ActionExtResult result = output.get_ActionExtResult();
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

HDK::ClientError Cisco_Sub::ActionExtSub
(
    HDK::ITarget* pTarget,
    const Cisco_Sub::ActionExtSubStruct & input,
    enum Cisco_Sub::ActionExtSubResult* presult /* = NULL */,
    unsigned int timeoutSecs /* = 0 */
) throw()
{
    if (!pTarget)
    {
        return ClientError_InvalidArg;
    }

    Cisco_Sub::ActionExtSubResponseStruct output;

    ClientError error = pTarget->Request(timeoutSecs,
                                         ACTUAL_CLIENT_MOD_Module(),
                                         ACTUAL_CLIENT_MOD_MethodEnum_Cisco_Sub_ActionExtSub,
                                         input,
                                         &output);

    const HDK_MOD_Method* pMethod = HDK_MOD_GetMethod(ACTUAL_CLIENT_MOD_Module(), ACTUAL_CLIENT_MOD_MethodEnum_Cisco_Sub_ActionExtSub);

    // Get the result value.
    enum Cisco_Sub::ActionExtSubResult result = output.get_ActionExtSubResult();
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

HDK::ClientError Purenetworks_HNAP::ActionLegacy2
(
    HDK::ITarget* pTarget,
    const Purenetworks_HNAP::ActionLegacy2Struct & input,
    enum Purenetworks_HNAP::ActionLegacy2Result* presult /* = NULL */,
    unsigned int timeoutSecs /* = 0 */
) throw()
{
    if (!pTarget)
    {
        return ClientError_InvalidArg;
    }

    Purenetworks_HNAP::ActionLegacy2ResponseStruct output;

    ClientError error = pTarget->Request(timeoutSecs,
                                         ACTUAL_CLIENT_MOD_Module(),
                                         ACTUAL_CLIENT_MOD_MethodEnum_Purenetworks_HNAP_ActionLegacy2,
                                         input,
                                         &output);

    const HDK_MOD_Method* pMethod = HDK_MOD_GetMethod(ACTUAL_CLIENT_MOD_Module(), ACTUAL_CLIENT_MOD_MethodEnum_Purenetworks_HNAP_ActionLegacy2);

    // Get the result value.
    enum Purenetworks_HNAP::ActionLegacy2Result result = output.get_ActionLegacy2Result();
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

HDK::ClientError Purenetworks_HNAP_Sub::ActionLegacy2Sub
(
    HDK::ITarget* pTarget,
    const Purenetworks_HNAP_Sub::ActionLegacy2SubStruct & input,
    enum Purenetworks_HNAP_Sub::ActionLegacy2SubResult* presult /* = NULL */,
    unsigned int timeoutSecs /* = 0 */
) throw()
{
    if (!pTarget)
    {
        return ClientError_InvalidArg;
    }

    Purenetworks_HNAP_Sub::ActionLegacy2SubResponseStruct output;

    ClientError error = pTarget->Request(timeoutSecs,
                                         ACTUAL_CLIENT_MOD_Module(),
                                         ACTUAL_CLIENT_MOD_MethodEnum_PN_Sub_ActionLegacy2Sub,
                                         input,
                                         &output);

    const HDK_MOD_Method* pMethod = HDK_MOD_GetMethod(ACTUAL_CLIENT_MOD_Module(), ACTUAL_CLIENT_MOD_MethodEnum_PN_Sub_ActionLegacy2Sub);

    // Get the result value.
    enum Purenetworks_HNAP_Sub::ActionLegacy2SubResult result = output.get_ActionLegacy2SubResult();
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

HDK::ClientError Purenetworks_HNAP1::ActionLegacy
(
    HDK::ITarget* pTarget,
    const Purenetworks_HNAP1::ActionLegacyStruct & input,
    enum Purenetworks_HNAP1::ActionLegacyResult* presult /* = NULL */,
    unsigned int timeoutSecs /* = 0 */
) throw()
{
    if (!pTarget)
    {
        return ClientError_InvalidArg;
    }

    Purenetworks_HNAP1::ActionLegacyResponseStruct output;

    ClientError error = pTarget->Request(timeoutSecs,
                                         ACTUAL_CLIENT_MOD_Module(),
                                         ACTUAL_CLIENT_MOD_MethodEnum_PN_ActionLegacy,
                                         input,
                                         &output);

    const HDK_MOD_Method* pMethod = HDK_MOD_GetMethod(ACTUAL_CLIENT_MOD_Module(), ACTUAL_CLIENT_MOD_MethodEnum_PN_ActionLegacy);

    // Get the result value.
    enum Purenetworks_HNAP1::ActionLegacyResult result = output.get_ActionLegacyResult();
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

HDK::ClientError Purenetworks_HNAP1_Sub::ActionSubLegacy
(
    HDK::ITarget* pTarget,
    const Purenetworks_HNAP1_Sub::ActionSubLegacyStruct & input,
    enum Purenetworks_HNAP1_Sub::ActionSubLegacyResult* presult /* = NULL */,
    unsigned int timeoutSecs /* = 0 */
) throw()
{
    if (!pTarget)
    {
        return ClientError_InvalidArg;
    }

    Purenetworks_HNAP1_Sub::ActionSubLegacyResponseStruct output;

    ClientError error = pTarget->Request(timeoutSecs,
                                         ACTUAL_CLIENT_MOD_Module(),
                                         ACTUAL_CLIENT_MOD_MethodEnum_Purenetworks_HNAP1_Sub_ActionSubLegacy,
                                         input,
                                         &output);

    const HDK_MOD_Method* pMethod = HDK_MOD_GetMethod(ACTUAL_CLIENT_MOD_Module(), ACTUAL_CLIENT_MOD_MethodEnum_Purenetworks_HNAP1_Sub_ActionSubLegacy);

    // Get the result value.
    enum Purenetworks_HNAP1_Sub::ActionSubLegacyResult result = output.get_ActionSubLegacyResult();
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

HDK::ClientError Purenetworks::ActionLegacyExt
(
    HDK::ITarget* pTarget,
    const Purenetworks::ActionLegacyExtStruct & input,
    enum Purenetworks::ActionLegacyExtResult* presult /* = NULL */,
    unsigned int timeoutSecs /* = 0 */
) throw()
{
    if (!pTarget)
    {
        return ClientError_InvalidArg;
    }

    Purenetworks::ActionLegacyExtResponseStruct output;

    ClientError error = pTarget->Request(timeoutSecs,
                                         ACTUAL_CLIENT_MOD_Module(),
                                         ACTUAL_CLIENT_MOD_MethodEnum_Purenetworks_ActionLegacyExt,
                                         input,
                                         &output);

    const HDK_MOD_Method* pMethod = HDK_MOD_GetMethod(ACTUAL_CLIENT_MOD_Module(), ACTUAL_CLIENT_MOD_MethodEnum_Purenetworks_ActionLegacyExt);

    // Get the result value.
    enum Purenetworks::ActionLegacyExtResult result = output.get_ActionLegacyExtResult();
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

HDK::ClientError Purenetworks_Sub::ActionLegacyExtSub
(
    HDK::ITarget* pTarget,
    const Purenetworks_Sub::ActionLegacyExtSubStruct & input,
    enum Purenetworks_Sub::ActionLegacyExtSubResult* presult /* = NULL */,
    unsigned int timeoutSecs /* = 0 */
) throw()
{
    if (!pTarget)
    {
        return ClientError_InvalidArg;
    }

    Purenetworks_Sub::ActionLegacyExtSubResponseStruct output;

    ClientError error = pTarget->Request(timeoutSecs,
                                         ACTUAL_CLIENT_MOD_Module(),
                                         ACTUAL_CLIENT_MOD_MethodEnum_Purenetworks_Sub_ActionLegacyExtSub,
                                         input,
                                         &output);

    const HDK_MOD_Method* pMethod = HDK_MOD_GetMethod(ACTUAL_CLIENT_MOD_Module(), ACTUAL_CLIENT_MOD_MethodEnum_Purenetworks_Sub_ActionLegacyExtSub);

    // Get the result value.
    enum Purenetworks_Sub::ActionLegacyExtSubResult result = output.get_ActionLegacyExtSubResult();
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
