////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__connect_op_ctx.cpp
//! \brief   �������� �������� �����������/�������� ���� ������.
//! \author  Kovalenko Dmitry
//! \date    17.02.2019
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__p13__connect_op_ctx.h"
#include "source/db_client/remote_fb/remote_fb__client_connect_block_v2.h"
#include "source/db_client/remote_fb/remote_fb__utils.h"

#include "source/db_obj/fb_base/fb_api.h"

#include "source/db_obj/isc_base/isc_api.h"
#include "source/db_obj/isc_base/isc_base__dbparams_for_attach__processor.h"
#include "source/db_obj/isc_base/isc_base__dbparams_for_create__processor.h"

#include "source/oledb/ibp_oledb__prop__names.h"

#include "source/error_services/ibp_error_utils.h"

#include "source/Version/ibp_v05_info_data.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__ConnectOpCtx

RemoteFB__P13__ConnectOpCtx::RemoteFB__P13__ConnectOpCtx
                                      (RemoteFB__ClientConnectBlock_v2& clientConnectBlock,
                                       bool                      const  setNewDbParams)
 :m_dpb(L"DPB",fb_api::ibp_frb_dbp_version2)
{
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

 //-----------------------------------------------------------------------
 this->Helper__BuildDPB
  (clientConnectBlock,
   setNewDbParams);
}//RemoteFB__P13__ConnectOpCtx

//------------------------------------------------------------------------
RemoteFB__P13__ConnectOpCtx::~RemoteFB__P13__ConnectOpCtx()
{;}

//helper methods ---------------------------------------------------------
void RemoteFB__P13__ConnectOpCtx::Helper__BuildDPB
                                      (RemoteFB__ClientConnectBlock_v2& clientConnectBlock,
                                       bool                       const setNewDbParams)
{
 /// ��������� ������ ���������� � ������� �������� UTF8

 m_dpb.AppendTag
  (fb_api::ibp_frb_dpb_utf8_filename);

 //-----------------------------------------------------------------------
 //��������� ���������� �����������

 isc_base::isc_base__dbparams_for_attach__processor::set_dbinit_params
  (clientConnectBlock.m_spDsPropValues,
   this);

 if(setNewDbParams)
 {
  //��������� ���������� ����� ���� ������

  isc_base::isc_base__dbparams_for_create__processor::set_newdb_params
   (clientConnectBlock.m_spDsPropValues,
    this);
 }//if

 //-----------------------------------------------------------------------
 //��������� ��������������

 if(!clientConnectBlock.m_authComplete)
 {
  //���������� ������� �������� ������ �������������� �� �������.

  //����� �������� ��� Win_SSPI � Wire_Crypt=Disabled.

  //�������, �������. �� ��� ��� ��� ��� �������������� � FB3.

  //---------- ����������� ������ � ������� ��������������
  assert(clientConnectBlock.GetCurrentAuthPlugin());

  clientConnectBlock.GetCurrentAuthPlugin()->authenticate(clientConnectBlock); //throw

  //--------- ����������� ������ � DPB

  //���������� ��� �������
  m_dpb.AppendMbcString_AsUTF8
   (fb_api::ibp_frb_dpb_auth_plugin_name,
    L"frb_dpb_auth_plugin_name",
    clientConnectBlock.GetCurrentAuthPlugin()->get_name());

  //���������� ��� ������� ��� ������������ ������� ������ ��������� ��������
  m_dpb.AppendMbcString_AsUTF8
   (fb_api::ibp_frb_dpb_auth_plugin_list,
    L"frb_dpb_auth_plugin_list",
    clientConnectBlock.GetCurrentAuthPlugin()->get_name());

  //���������� ������ ��������������

  //[2016-09-12] ���������, ��� ������ ����� ����.
  assert(!clientConnectBlock.m_dataFromAuthPlugin.empty());

  m_dpb.AppendBytes
   (fb_api::ibp_frb_dpb_specific_auth_data,
    L"frb_dpb_specific_auth_data",
    clientConnectBlock.m_dataFromAuthPlugin.size(),
    clientConnectBlock.m_dataFromAuthPlugin.buffer());
 }//if !clientConnectBlock.m_authComplete

 //-----------------------------------------------------------------------
 //other_params

 //-----------------------------------------------------------------------
 //isc_dpb_dummy_packet_interval
 // [2015-02-11] ���� ������. ����� ��������, �������.

 //-----------------------------------------------------------------------
 m_dpb.AppendInt
  (fb_api::ibp_frb_dpb_process_id,
   ::GetCurrentProcessId());

 m_dpb.AppendMbcString_AsUTF8
  (fb_api::ibp_frb_dpb_process_name,
   L"frb_dpb_process_name",
   RemoteFB__Utils::GetCurrentProcessName());

 m_dpb.AppendMbcString_AsUTF8
  (fb_api::ibp_frb_dpb_client_version,
   L"frb_dpb_client_version",
   RemoteFB__Utils::BuildFbClientSign());

 //-----------------------------------------------------------------------
 //isc_dpb_working_directory ��� locahost-�����������

 // [2015-02-01] ����� �����������, ����� ��� �� ����������.
 // ������� - ����� �����-��. �� ������������ �� ����.
 // �������� �� ����, ��� localhost ��� ������ ��������� ���������...
}//Helper__BuildDPB

//isc_base__dbparams_for_attach__installer interface ---------------------
void RemoteFB__P13__ConnectOpCtx::set_dbinit_param___auth__integrated(wstr_box_type const UNUSED_ARG(propValue))
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___auth__integrated);

 m_DEBUG__was_installed__dbinit_param___auth__integrated=true;
#endif

 /*NOP*/
}//set_dbinit_param___auth__integrated

//------------------------------------------------------------------------
void RemoteFB__P13__ConnectOpCtx::set_dbinit_param___auth__user_id(wstr_box_type const UNUSED_ARG(propValue))
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___auth__user_id);

 m_DEBUG__was_installed__dbinit_param___auth__user_id=true;
#endif

 /*NOP*/
}//set_dbinit_param___auth__user_id

//------------------------------------------------------------------------
void RemoteFB__P13__ConnectOpCtx::set_dbinit_param___auth__password(wstr_box_type const UNUSED_ARG(propValue))
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___auth__password);

 m_DEBUG__was_installed__dbinit_param___auth__password=true;
#endif

 /*NOP*/
}//set_dbinit_param___auth__password

//------------------------------------------------------------------------
void RemoteFB__P13__ConnectOpCtx::set_dbinit_param___auth__rolename(wstr_box_type const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___auth__rolename);

 m_DEBUG__was_installed__dbinit_param___auth__rolename=true;
#endif

 //[2019-02-17] ������ �� ������������ ������ ������

 m_dpb.AppendMbcString_AsUTF8
  (isc_api::ibp_isc_dpb_sql_role_name,
   L"isc_dpb_sql_role_name",
   propValue);
}//set_dbinit_param___auth__rolename

//------------------------------------------------------------------------
void RemoteFB__P13__ConnectOpCtx::set_dbinit_param___ctype(wstr_box_type const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___ctype);

 m_DEBUG__was_installed__dbinit_param___ctype=true;
#endif

 //[2019-02-17] ������ �� ������������ ������ ������

 //�������� � ������� ��������� ���������

 m_dpb.AppendMbcString
  (isc_api::ibp_isc_dpb_lc_ctype,
   L"isc_dpb_lc_ctype",
   propValue);
}//set_dbinit_param___ctype

//------------------------------------------------------------------------
void RemoteFB__P13__ConnectOpCtx::set_dbinit_param___garbage_collect(bool const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___garbage_collect);

 m_DEBUG__was_installed__dbinit_param___garbage_collect=true;
#endif

 if(propValue)
  return;

 m_dpb.AppendTag
  (isc_api::ibp_isc_dpb_no_garbage_collect);
}//set_dbinit_param___garbage_collect

//------------------------------------------------------------------------
void RemoteFB__P13__ConnectOpCtx::set_dbinit_param___num_buffers(long const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___num_buffers);

 m_DEBUG__was_installed__dbinit_param___num_buffers=true;
#endif

 m_dpb.AppendInt
  (isc_api::ibp_isc_dpb_num_buffers,
   propValue);
}//set_dbinit_param___num_buffers

//------------------------------------------------------------------------
void RemoteFB__P13__ConnectOpCtx::set_dbinit_param___enable_db_trigger(long const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___enable_db_trigger);

 m_DEBUG__was_installed__dbinit_param___enable_db_trigger=true;
#endif

 if(propValue)
  return;

 m_dpb.AppendByte
  (fb_api::ibp_frb_dpb_no_db_triggers,
   1);
}//set_dbinit_param___enable_db_trigger

//------------------------------------------------------------------------
void RemoteFB__P13__ConnectOpCtx::set_dbinit_param___sys_encrypt_password(wstr_box_type const UNUSED_ARG(propValue))
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__dbinit_param___sys_encrypt_password);

 m_DEBUG__was_installed__dbinit_param___sys_encrypt_password=true;
#endif

 IBP_ThrowInitPropCantPassIntoDBClient
  (ibp_subsystem__remote_fb__p13,
   IBP_DBPROP_NAME__INIT__SYS_ENCRYPT_PASSWORD,
   IBP_SUBSYSTEM_SIGN__REMOTE_FB,
   IBP_VI_PRODUCT_VER_STRING1); //throw
}//set_dbinit_param___sys_encrypt_password

//isc_base__dbparams_for_create__installer interface ---------------------
void RemoteFB__P13__ConnectOpCtx::set_newdb_param___db_dialect(long const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__newdb_param___db_dialect);

 m_DEBUG__was_installed__newdb_param___db_dialect=true;
#endif

 m_dpb.AppendInt
  (isc_api::ibp_isc_dpb_SQL_dialect,
   propValue);
}//set_newdb_param___db_dialect

//------------------------------------------------------------------------
void RemoteFB__P13__ConnectOpCtx::set_newdb_param___page_size(long const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__newdb_param___page_size);

 m_DEBUG__was_installed__newdb_param___page_size=true;
#endif

 m_dpb.AppendInt
  (isc_api::ibp_isc_dpb_page_size,
   propValue);
}//set_newdb_param___page_size

//------------------------------------------------------------------------
void RemoteFB__P13__ConnectOpCtx::set_newdb_param___type_of_db_users(long const propValue)
{
#ifndef NDEBUG
 assert(!m_DEBUG__was_installed__newdb_param___type_of_db_users);

 m_DEBUG__was_installed__newdb_param___type_of_db_users=true;
#endif

 if(propValue==ibprovider::ibp_propval__newdb__type_of_db_users__server)
  return;

 IBP_ThrowInitPropCantProcessCurrentDBClient_I4
  (ibp_subsystem__remote_fb__p13,
   IBP_DBPROP_NAME__DSCREATE__TYPE_OF_DATABASE_USERS,
   IBP_SUBSYSTEM_SIGN__REMOTE_FB,
   IBP_VI_PRODUCT_VER_STRING1,
   propValue); //throw
}//set_newdb_param___type_of_db_users

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
