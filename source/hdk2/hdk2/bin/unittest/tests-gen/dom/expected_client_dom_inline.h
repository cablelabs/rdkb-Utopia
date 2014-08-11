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

#pragma once

// actual_client_dom_inline.h - [Generated by hdkcli_cpp]

// Non-generated client code.
#include "hdk_cli_cpp.h"

// Underlying schema module.
#include "actual_client_dom_mod.h"


namespace HDK
{

    namespace Cisco
    {
        ///
        /// \brief CiscoStruct
        ///      <a>http://cisco.com/HNAPExt/CiscoStruct</a>
        ///
        class CiscoStructStruct : public Struct
        {
        public:
            //
            // Constructors/Destructor.
            //
            CiscoStructStruct() throw() :
                Struct(ACTUAL_CLIENT_DOM_MOD_Element_Cisco_CiscoStruct)
            {
            }

            CiscoStructStruct(HDK_XML_Struct* phdkstruct) throw() :
                Struct(phdkstruct)
            {
            }

            ///
            /// \brief Get the a value.
            ///
            HDK_XML_Int get_a() const throw()
            {
                return HDK_XML_GetEx_Int(GetStruct(), ACTUAL_CLIENT_DOM_MOD_Element_Cisco_a, 0);
            }

            ///
            /// \brief Set the a value.
            ///
            void set_a(HDK_XML_Int value) throw()
            {
                (void)HDK_XML_Set_Int(GetStruct(), ACTUAL_CLIENT_DOM_MOD_Element_Cisco_a, value);
            }

            ///
            /// \brief Get the b value.
            ///
            const char* get_b() const throw()
            {
                return HDK_XML_GetEx_String(GetStruct(), ACTUAL_CLIENT_DOM_MOD_Element_Cisco_b, 0);
            }

            ///
            /// \brief Set the b value.
            ///
            void set_b(const char* value) throw()
            {
                (void)HDK_XML_Set_String(GetStruct(), ACTUAL_CLIENT_DOM_MOD_Element_Cisco_b, value);
            }

            ///
            /// \brief Get the c value.
            ///
            HDK_XML_Long get_c() const throw()
            {
                return HDK_XML_GetEx_Long(GetStruct(), ACTUAL_CLIENT_DOM_MOD_Element_Cisco_c, 0);
            }

            ///
            /// \brief Set the c value.
            ///
            void set_c(HDK_XML_Long value) throw()
            {
                (void)HDK_XML_Set_Long(GetStruct(), ACTUAL_CLIENT_DOM_MOD_Element_Cisco_c, value);
            }

            ///
            /// \brief Serialize to/from an XML file.
            ///
            bool FromFile(const char* pszFile) throw()
            {
                return HDK::Struct::DeserializeFromFile(ACTUAL_CLIENT_DOM_MOD_Schema_Cisco_CiscoStruct(), pszFile);
            }
            bool ToFile(const char* pszFile) const throw()
            {
                return HDK::Struct::SerializeToFile(ACTUAL_CLIENT_DOM_MOD_Schema_Cisco_CiscoStruct(), pszFile, 0);
            }

        }; // class CiscoStructStruct : public Struct

        ///
        /// \brief CiscoStructToo
        ///      <a>http://cisco.com/HNAPExt/CiscoStructToo</a>
        ///
        class CiscoStructTooStruct : public Struct
        {
        public:
            //
            // Constructors/Destructor.
            //
            CiscoStructTooStruct() throw() :
                Struct(ACTUAL_CLIENT_DOM_MOD_Element_Cisco_CiscoStructToo)
            {
            }

            CiscoStructTooStruct(HDK_XML_Struct* phdkstruct) throw() :
                Struct(phdkstruct)
            {
            }

            ///
            /// \brief Get the s value.
            ///
            CiscoStructStruct get_s() const throw()
            {
                return HDK_XML_Get_Struct(GetStruct(), ACTUAL_CLIENT_DOM_MOD_Element_Cisco_s);
            }

            ///
            /// \brief Set the s value.
            ///
            void set_s(const CiscoStructStruct& value) throw()
            {
                (void)HDK_XML_SetEx_Struct(GetStruct(), ACTUAL_CLIENT_DOM_MOD_Element_Cisco_s, value);
            }

            ///
            /// \brief Get the d value.
            ///
            HDK_XML_Int get_d() const throw()
            {
                return HDK_XML_GetEx_Int(GetStruct(), ACTUAL_CLIENT_DOM_MOD_Element_Cisco_d, 0);
            }

            ///
            /// \brief Set the d value.
            ///
            void set_d(HDK_XML_Int value) throw()
            {
                (void)HDK_XML_Set_Int(GetStruct(), ACTUAL_CLIENT_DOM_MOD_Element_Cisco_d, value);
            }

            ///
            /// \brief Get the e value.
            ///
            const char* get_e() const throw()
            {
                return HDK_XML_GetEx_String(GetStruct(), ACTUAL_CLIENT_DOM_MOD_Element_Cisco_e, 0);
            }

            ///
            /// \brief Set the e value.
            ///
            void set_e(const char* value) throw()
            {
                (void)HDK_XML_Set_String(GetStruct(), ACTUAL_CLIENT_DOM_MOD_Element_Cisco_e, value);
            }

            ///
            /// \brief Serialize to/from an XML file.
            ///
            bool FromFile(const char* pszFile) throw()
            {
                return HDK::Struct::DeserializeFromFile(ACTUAL_CLIENT_DOM_MOD_Schema_Cisco_CiscoStructToo(), pszFile);
            }
            bool ToFile(const char* pszFile) const throw()
            {
                return HDK::Struct::SerializeToFile(ACTUAL_CLIENT_DOM_MOD_Schema_Cisco_CiscoStructToo(), pszFile, 0);
            }

        }; // class CiscoStructTooStruct : public Struct

    } // namespace Cisco
} // namespace HDK
