////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p10
//! \file    remote_fb__p10__dpb_v1_values_installer.cpp
//! \brief    онтекст операции подключени€/создани€ базы данных.
//! \author  Kovalenko Dmitry
//! \date    03.12.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p10/remote_fb__p10__dpb_v1_values_installer.h"
#include "source/db_client/remote_fb/remote_fb__enc_crypt.h"
#include "source/db_client/remote_fb/remote_fb__utils.h"

#include "source/db_obj/fb_base/fb_api.h"

#include "source/db_obj/isc_base/isc_api.h"

#include "source/oledb/ibp_oledb__prop__names.h"

#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_utils.h"
#include "source/error_services/ibp_error_messages.h"

#include "source/Version/ibp_v05_info_data.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__data__values.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p10{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P10__DpbV1_ValuesInstaller

RemoteFB__P10__DpbV1_ValuesInstaller::RemoteFB__P10__DpbV1_ValuesInstaller
                                      (dpb_type*                              const pDPB,
                                       oledb_lib::OLEDB_Props2__Data__Values* const pDsPropValues)
 :m_pDPB(pDPB)
 ,m_pDsPropValues(pDsPropValues)
{
 assert(m_pDPB);
 assert(m_pDsPropValues);

#ifndef NDEBUG
 m_DEBUG__was_installed__dbinit_param___auth__integrated        =false;
 m_DEBUG__was_installed__dbinit_param___auth__user_id           =false;
 m_DEBUG__was_installed__dbinit_param___auth__password          =false;
 m_DEBUG__was_installed__dbinit_param___auth__rolename          =false;
 m_DEBUG__was_installed__dbinit_param___ctype                   =false;
 m_DEBUG__was_installed__dbinit_param___garbage_collect         =false;
 m_DEBUG__was_installed__dbinit_param___num_buffers             =false;
 m_DEBUG__was_installed__dbinit_param___enable_db_trigger       =false;
 m_DEBUG__was_installed__dbinit_param___sys_encrypt_password    =false;

 m_DEBUG__was_installed__newdb_param___db_dialect               =false;
 m_DEBUG__was_installed__newdb_param___page_size                =false;
 m_DEBUG__was_installed__newdb_param___type_of_db_users         =false;
#endif
}//RemoteFB__P10__DpbV1_ValuesInstaller

 //------------------------------------------------------------------------
RemoteFB__P10__DpbV1_ValuesInstaller::~RemoteFB__P10__DpbV1_ValuesInstaller()
{;}

//isc_base__dbparams_for_attach__installer interface ---------------------
void RemoteFB__P10__DpbV1_ValuesInstaller::set_dbinit_param___auth__integrated(wstr_box_type const UNUSED_ARG(propValue))
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___auth__integrated);

 m_DEBUG__was_installed__dbinit_param___auth__integrated=true;
#endif

 //[2019-02-16] мы не должны сюда попадать.

 IBP_BUG_CHECK__DEBUG
  (L"RemoteFB__P10__DpbV1_ValuesInstaller::set_dbinit_param___auth__integrated",
   L"#001",
   me_bug_check__unexpected_situation_0)
}//set_dbinit_param___auth__integrated

//------------------------------------------------------------------------
void RemoteFB__P10__DpbV1_ValuesInstaller::set_dbinit_param___auth__user_id(wstr_box_type const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___auth__user_id);

 m_DEBUG__was_installed__dbinit_param___auth__user_id=true;
#endif

 m_pDPB->AppendMbcString
  (isc_api::ibp_isc_dpb_user_name,
   L"isc_dpb_user_name",
   propValue);

 ole_lib::TVariant varUserName(propValue);

 assert(varUserName.vt==VT_BSTR);

 RemoteFB__Utils::System_CharUpperBStr
  (varUserName.bstrVal,
   L"DbUserName");

 m_pDsPropValues->Direct__SetValue
  (DBPROPSET_DATASOURCEINFO,
   DBPROP_USERNAME,
   DBPROPOPTIONS_REQUIRED,
   varUserName);
}//set_dbinit_param___auth__user_id

//------------------------------------------------------------------------
void RemoteFB__P10__DpbV1_ValuesInstaller::set_dbinit_param___auth__password(wstr_box_type const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___auth__password);

 m_DEBUG__was_installed__dbinit_param___auth__password=true;
#endif

 bool error=false;

 std::string mbc_str;

 structure::tstr_to_tstr(&mbc_str,propValue,&error);

 if(error)
 {
  //ERROR - ошибка конвертировани€
  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb__p10,
    ibp_mce_common__failed_to_convert_cn_param_to_system_codepage_1,
    L"Password");
 }//if

 char pwt[64/*MAX_PASSWORD_LENGTH*/ + 2];

 RemoteFB__ENC_crypt::ENC_crypt
  (pwt,
   sizeof pwt,
   mbc_str.c_str(),
   /*PASSWORD_SALT*/"9z");

 const char* const password_b=pwt+2;
 const char* const password_e=std::find(password_b,const_cast<const char*>(_END_(pwt)),0);

 const size_t password_sz=(password_e-password_b);

 //декларативна€ проверка
 assert((password_e-pwt)<=RemoteFB__ENC_crypt::c_RESULT_SIZE);

 m_pDPB->AppendMbcString
  (isc_api::ibp_isc_dpb_password_enc,
   L"isc_dpb_password_enc",
   dpb_type::mbc_str_box_type(password_b,password_sz));
}//set_dbinit_param___auth__password

//------------------------------------------------------------------------
void RemoteFB__P10__DpbV1_ValuesInstaller::set_dbinit_param___auth__rolename(wstr_box_type const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___auth__rolename);

 m_DEBUG__was_installed__dbinit_param___auth__rolename=true;
#endif

 //[2019-02-16] –аньше мы игнорировали пустую строку

 m_pDPB->AppendMbcString
  (isc_api::ibp_isc_dpb_sql_role_name,
   L"isc_dpb_sql_role_name",
   propValue);
}//set_dbinit_param___auth__rolename

//------------------------------------------------------------------------
void RemoteFB__P10__DpbV1_ValuesInstaller::set_dbinit_param___ctype(wstr_box_type const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___ctype);

 m_DEBUG__was_installed__dbinit_param___ctype=true;
#endif

 //[2019-02-16] –аньше мы игнорировали пустую строку

 //передаем в текущей системной кодировке

 m_pDPB->AppendMbcString
  (isc_api::ibp_isc_dpb_lc_ctype,
   L"isc_dpb_lc_ctype",
   propValue);
}//set_dbinit_param___ctype

//------------------------------------------------------------------------
void RemoteFB__P10__DpbV1_ValuesInstaller::set_dbinit_param___garbage_collect(bool const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___garbage_collect);

 m_DEBUG__was_installed__dbinit_param___garbage_collect=true;
#endif

 if(propValue)
  return;

 m_pDPB->AppendTag
  (isc_api::ibp_isc_dpb_no_garbage_collect);
}//set_dbinit_param___garbage_collect

//------------------------------------------------------------------------
void RemoteFB__P10__DpbV1_ValuesInstaller::set_dbinit_param___num_buffers(long const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___num_buffers);

 m_DEBUG__was_installed__dbinit_param___num_buffers=true;
#endif

 m_pDPB->AppendInt
  (isc_api::ibp_isc_dpb_num_buffers,
   propValue);
}//set_dbinit_param___num_buffers

//------------------------------------------------------------------------
void RemoteFB__P10__DpbV1_ValuesInstaller::set_dbinit_param___enable_db_trigger(long const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___enable_db_trigger);

 m_DEBUG__was_installed__dbinit_param___enable_db_trigger=true;
#endif

 if(propValue)
  return;

 m_pDPB->AppendByte
  (fb_api::ibp_frb_dpb_no_db_triggers,
   1);
}//set_dbinit_param___enable_db_trigger

//------------------------------------------------------------------------
void RemoteFB__P10__DpbV1_ValuesInstaller::set_dbinit_param___sys_encrypt_password(wstr_box_type const UNUSED_ARG(propValue))
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___sys_encrypt_password);

 m_DEBUG__was_installed__dbinit_param___sys_encrypt_password=true;
#endif

 IBP_ThrowInitPropCantPassIntoDBClient
  (ibp_subsystem__remote_fb__p10,
   IBP_DBPROP_NAME__INIT__SYS_ENCRYPT_PASSWORD,
   IBP_SUBSYSTEM_SIGN__REMOTE_FB,
   IBP_VI_PRODUCT_VER_STRING1); //throw
}//set_dbinit_param___sys_encrypt_password

//isc_base__dbparams_for_create__installer interface ---------------------
void RemoteFB__P10__DpbV1_ValuesInstaller::set_newdb_param___db_dialect(long const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__newdb_param___db_dialect);

 m_DEBUG__was_installed__newdb_param___db_dialect=true;
#endif

 m_pDPB->AppendInt
  (isc_api::ibp_isc_dpb_SQL_dialect,
   propValue);
}//set_newdb_param___db_dialect

//------------------------------------------------------------------------
void RemoteFB__P10__DpbV1_ValuesInstaller::set_newdb_param___page_size(long const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__newdb_param___page_size);

 m_DEBUG__was_installed__newdb_param___page_size=true;
#endif

 m_pDPB->AppendInt
  (isc_api::ibp_isc_dpb_page_size,
   propValue);
}//set_newdb_param___page_size

//------------------------------------------------------------------------
void RemoteFB__P10__DpbV1_ValuesInstaller::set_newdb_param___type_of_db_users(long const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__newdb_param___type_of_db_users);

 m_DEBUG__was_installed__newdb_param___type_of_db_users=true;
#endif

 if(propValue==ibprovider::ibp_propval__newdb__type_of_db_users__server)
  return;

 IBP_ThrowInitPropCantProcessCurrentDBClient_I4
  (ibp_subsystem__remote_fb__p10,
   IBP_DBPROP_NAME__DSCREATE__TYPE_OF_DATABASE_USERS,
   IBP_SUBSYSTEM_SIGN__REMOTE_FB,
   IBP_VI_PRODUCT_VER_STRING1,
   propValue); //throw
}//set_newdb_param___type_of_db_users

////////////////////////////////////////////////////////////////////////////////
}/*nms p10*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
