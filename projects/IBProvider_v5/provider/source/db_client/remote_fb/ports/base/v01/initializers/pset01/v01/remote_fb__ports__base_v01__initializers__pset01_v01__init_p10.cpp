////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__ports__base_v01
//! \file    remote_fb__ports__base_v01__initializers__pset01_v01__init_p10.cpp
//! \brief   Инициализация порта для 10-го протокола.
//! \author  Kovalenko Dmitry
//! \date    05.12.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/base/v01/initializers/pset01/v01/remote_fb__ports__base_v01__initializers__pset01_v01.h"
#include "source/db_client/remote_fb/transmission/pset01/p10/remote_fb__transmission__pset01__p10a__packet_stream.h"
#include "source/db_client/remote_fb/transmission/pset01/p10/remote_fb__transmission__pset01__p10s__packet_stream.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/dbms_fb/v02_5_0/db_obj__dbms_fb__v02_5_0__factories.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace base_v01{namespace initializers{namespace pset01{namespace v01{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortInitializer_PSET01_v01

void RemoteFB__PortInitializer_PSET01_v01::Helper__FinishConnect_P10
                                           (port_type*                   const pPort,
                                            const protocol::set01::PACKET_V01& packet,
                                            wstr_box_type                const ucs2_database_name,
                                            RemoteFB__ClientConnectBlock_v1&   clientConnectBlock,
                                            const tag_connect_finalizator&     FinalOpFuncs)
{
 assert(pPort);
 assert(packet.operation==protocol::set01::op_accept);
 assert(packet.p_acpt.p_acpt__version==protocol::FB_PROTOCOL_VERSION10);

 //-----------------------------------------------------------------------
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__PortInitializer_PSET01_v01::Helper__FinishConnect_P10";

 switch(packet.p_acpt.p_acpt__architecture)
 {
  case protocol::FB_CURRENT_ARCHITECTURE:
  {
   self_type::Helper__Initialize__SetProtocolInfo_P10_P11_P12
    (pPort,
     clientConnectBlock,
     packet.p_acpt,
     &transmission::pset01::p10::RemoteFB__PSET01__P10S__PacketStream::Instance);

   break;
  }//case - current [симметричный протокол]

  case protocol::arch_generic:
  {
   self_type::Helper__Initialize__SetProtocolInfo_P10_P11_P12
    (pPort,
     clientConnectBlock,
     packet.p_acpt,
     &transmission::pset01::p10::RemoteFB__PSET01__P10A__PacketStream::Instance);

   break;
  }//case - generic [асимметричный протокол]

  default:
  {
   //ERROR - [BUG CHECK] accepted unexpected protocol architecture

   RemoteFB__ErrorUtils::Throw_BugCheck_AcceptedUnexpectedProtocolArchitecture
    (c_bugcheck_src,
     L"#001",
     packet.p_acpt.p_acpt__architecture);
  }//default
 }//switch

 //Регистрация сервисов --------------------------------------------------

 //1. Сервис для обработки ошибок
 pPort->RegService
  (db_obj::__db_guid<db_obj::dbms_fb::common::fb_common__svc__status_vector_utils>(),
   db_obj::dbms_fb::v02_5_0::create_svc__status_vector_utils());

 //-----------------------------------------------------------------------
 assert(FinalOpFuncs.P10);

 FinalOpFuncs.P10
  (pPort,
   ucs2_database_name,
   clientConnectBlock); //throw

 assert(pPort->m_ID.has_value());
}//Helper__FinishConnect_P10

////////////////////////////////////////////////////////////////////////////////
}/*nms v01*/}/*nms pset01*/}/*nms initializers*/}/*nms base_v01*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
