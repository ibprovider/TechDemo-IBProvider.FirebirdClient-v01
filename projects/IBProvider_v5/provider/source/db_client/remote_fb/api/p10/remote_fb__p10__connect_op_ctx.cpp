////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p10
//! \file    remote_fb__p10__connect_op_ctx.cpp
//! \brief   Контекст операции подключения/создания базы данных.
//! \author  Kovalenko Dmitry
//! \date    03.12.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p10/remote_fb__p10__connect_op_ctx.h"
#include "source/db_client/remote_fb/api/p10/remote_fb__p10__dpb_v1_values_installer.h"
#include "source/db_client/remote_fb/remote_fb__client_connect_block_v1.h"
#include "source/db_client/remote_fb/remote_fb__utils.h"

#include "source/db_obj/isc_base/isc_api.h"
#include "source/db_obj/isc_base/isc_base__dbparams_for_attach__processor.h"
#include "source/db_obj/isc_base/isc_base__dbparams_for_create__processor.h"

#include "source/error_services/ibp_error_utils.h"

#include "source/Version/ibp_v05_info_data.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p10{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P10__ConnectOpCtx

RemoteFB__P10__ConnectOpCtx::RemoteFB__P10__ConnectOpCtx
                                      (const RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                                       bool                            const  setNewDbParams)
 :m_dpb(L"DPB",isc_api::ibp_isc_dpb_version1)
{
 this->Helper__BuildDPB
  (clientConnectBlock,
   setNewDbParams);
}//RemoteFB__P10__ConnectOpCtx

//------------------------------------------------------------------------
RemoteFB__P10__ConnectOpCtx::~RemoteFB__P10__ConnectOpCtx()
{;}

//helper methods ---------------------------------------------------------
void RemoteFB__P10__ConnectOpCtx::Helper__BuildDPB
                                      (const RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                                       bool                             const setNewDbParams)
{
 assert(clientConnectBlock.m_AuthKind!=RemoteFB__ClientConnectBlock_v1::auth_kind__none);

 if(clientConnectBlock.m_AuthKind==RemoteFB__ClientConnectBlock_v1::auth_kind__sspi)
 {
  IBP_ThrowIntegratedAuthIsNotSupported
   (ibp_subsystem__remote_fb__p10,
    IBP_SUBSYSTEM_SIGN__REMOTE_FB,
    IBP_VI_PRODUCT_VER_STRING1); //throw
 }//if auth_kind__sspi

 assert(clientConnectBlock.m_AuthKind==RemoteFB__ClientConnectBlock_v1::auth_kind__legacy);

 //-----------------------------------------------------------------------
 //установка параметров подключения

 RemoteFB__P10__DpbV1_ValuesInstaller
  installer
   (&m_dpb,
    clientConnectBlock.m_spDsPropValues);

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

 //-----------------------------------------
 //isc_dpb_dummy_packet_interval
 // [2015-02-11] пока забъем. будут проблемы, добавим.

 //-----------------------------------------
 //Не поддерживаются 10-ым протоколом

 //fb_api::ibp_frb_dpb_process_id

 //fb_api::ibp_frb_dpb_process_name

 //----------------------------------------
 //isc_dpb_working_directory для locahost-подключения

 // [2015-02-01] После размышлений, решил его не передавать.
 // причина - херня какая-та. Мы подключаемся по сети.
 // Наверное не факт, что localhost это именно локальный компьютер...
}//Helper__BuildDPB

////////////////////////////////////////////////////////////////////////////////
}/*nms p10*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
