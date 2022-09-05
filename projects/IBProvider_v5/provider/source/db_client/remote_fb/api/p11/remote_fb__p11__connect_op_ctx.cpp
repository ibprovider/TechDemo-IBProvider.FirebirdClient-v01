////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p11
//! \file    remote_fb__p11__connect_op_ctx.cpp
//! \brief   Контекст операции подключения/создания базы данных.
//! \author  Kovalenko Dmitry
//! \date    11.12.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p11/remote_fb__p11__connect_op_ctx.h"
#include "source/db_client/remote_fb/api/p11/remote_fb__p11__dpb_v1_values_installer.h"

#include "source/db_client/remote_fb/remote_fb__client_connect_block_v1.h"
#include "source/db_client/remote_fb/remote_fb__utils.h"

#include "source/db_obj/fb_base/fb_api.h"

#include "source/db_obj/isc_base/isc_api.h"
#include "source/db_obj/isc_base/isc_base__dbparams_for_attach__processor.h"
#include "source/db_obj/isc_base/isc_base__dbparams_for_create__processor.h"

#include "source/ibp_global_objects_data__dlls.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p11{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P11__ConnectOpCtx

RemoteFB__P11__ConnectOpCtx::RemoteFB__P11__ConnectOpCtx
                                      (const RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                                       bool                             const setNewDbParams)
 :m_dpb(L"DPB",isc_api::ibp_isc_dpb_version1)
 ,m_CnUseIntegratedAuth(false)
{
 this->Helper__BuildDPB
  (clientConnectBlock,
   setNewDbParams);
}//RemoteFB__P11__ConnectOpCtx

//------------------------------------------------------------------------
RemoteFB__P11__ConnectOpCtx::~RemoteFB__P11__ConnectOpCtx()
{;}

//interface --------------------------------------------------------------
bool RemoteFB__P11__ConnectOpCtx::cn_use_integ_auth()const
{
 return m_CnUseIntegratedAuth;
}//cn_use_integ_auth

//------------------------------------------------------------------------
bool RemoteFB__P11__ConnectOpCtx::auth_data_is_completed()const
{
 // [2016-08-31]
 //  Не надо вызывать этот метод, если у нас ни разу не вызывался
 //  метод request_auth_data.
 assert(m_CnUseIntegratedAuth);

 return m_AuthData.is_completed();
}//auth_data_is_completed

//------------------------------------------------------------------------
void RemoteFB__P11__ConnectOpCtx::request_auth_data
                                               (size_t      const cbInput,
                                                const void* const pvInput,
                                                auth_output_type& Output)
{
 m_CnUseIntegratedAuth=true;

 if(!m_spAuthProvider)
 {
  typedef auth_provider_type                provider_type;
  typedef os::t_ibp_os__dll_ptr             dll_ptr;

  const dll_ptr
   spDll
    (IBP_GlobalObjectsData__DLLs::GetDLL
      (IBP_T("secur32.dll"),
       ibprovider::ibp_propval_dll_lock_rule__unload));

  assert(spDll);

  m_spAuthProvider=provider_type::create(spDll);

  assert(m_spAuthProvider);
 }//if !m_spAuthProvider

 assert(m_spAuthProvider);

 return m_AuthData.request(m_spAuthProvider,
                           cbInput,
                           pvInput,
                           Output); //throw
}//request_auth_data

//helper methods ---------------------------------------------------------
void RemoteFB__P11__ConnectOpCtx::Helper__BuildDPB(const RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                                                   bool                             const setNewDbParams)
{
 assert(!m_CnUseIntegratedAuth);

 assert(clientConnectBlock.m_AuthKind!=RemoteFB__ClientConnectBlock_v1::auth_kind__none);

 if(clientConnectBlock.m_AuthKind==RemoteFB__ClientConnectBlock_v1::auth_kind__sspi)
 {
  auth_output_type auth_data;

  this->request_auth_data(0,
                          nullptr,
                          auth_data);

  assert(m_CnUseIntegratedAuth);

  //[2016-08-23] Ожидается, что данные точно есть.
  assert(!auth_data.empty());

  m_dpb.AppendBytes(fb_api::ibp_frb_dpb_trusted_auth,
                    L"frb_dpb_trusted_auth",
                    auth_data.size(),
                    auth_data.buffer());

  clientConnectBlock.m_spDsPropValues->Direct__SetValue
   (DBPROPSET_DATASOURCEINFO,
    DBPROP_USERNAME,
    DBPROPOPTIONS_REQUIRED,
    ole_lib::TVariant(RemoteFB__Utils::BuildWinSspiUserName()));
 }
#ifndef NDEBUG
 else
 {
  assert(clientConnectBlock.m_AuthKind==RemoteFB__ClientConnectBlock_v1::auth_kind__legacy);

  assert(!m_CnUseIntegratedAuth);
 }//else
#endif

 //-----------------------------------------------------------------------
 //установка параметров подключения

 RemoteFB__P11__DpbV1_ValuesInstaller
  installer
   (&m_dpb,
    clientConnectBlock.m_spDsPropValues,
    m_CnUseIntegratedAuth);

 isc_base::isc_base__dbparams_for_attach__processor::set_dbinit_params
  (clientConnectBlock.m_spDsPropValues,
   &installer);

 if(setNewDbParams)
 {
  //установка параметров новой базы данных

  isc_base::isc_base__dbparams_for_create__processor::set_newdb_params
   (clientConnectBlock.m_spDsPropValues,
    &installer);
 }//if setNewDbParams

 //-----------------------------------------------------------------------
 //other_params

 //-----------------------------------------------------------------------
 //isc_dpb_dummy_packet_interval
 // [2015-02-11] пока забъем. будут проблемы, добавим.

 //-----------------------------------------------------------------------
 m_dpb.AppendInt
  (fb_api::ibp_frb_dpb_process_id,
   ::GetCurrentProcessId());

 m_dpb.AppendMbcString
  (fb_api::ibp_frb_dpb_process_name,
   L"frb_dpb_process_name",
   RemoteFB__Utils::GetCurrentProcessName());

 //-----------------------------------------------------------------------
 //isc_dpb_working_directory для locahost-подключения

 // [2015-02-01] После размышлений, решил его не передавать.
 // причина - херня какая-та. Мы подключаемся по сети.
 // Наверное не факт, что localhost это именно локальный компьютер...
}//Helper__BuildDPB

////////////////////////////////////////////////////////////////////////////////
}/*nms p11*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
