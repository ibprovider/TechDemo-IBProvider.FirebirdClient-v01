////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__ports__base_v01
//! \file    remote_fb__ports__base_v01__initializers__pset01_v01__init_p11.cpp
//! \brief   Инициализация порта для 11-го протокола.
//! \author  Kovalenko Dmitry
//! \date    11.12.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/base/v01/initializers/pset01/v01/remote_fb__ports__base_v01__initializers__pset01_v01.h"
#include "source/db_client/remote_fb/transmission/pset01/p11/remote_fb__transmission__pset01__p11a__packet_stream.h"
#include "source/db_client/remote_fb/transmission/pset01/p11/remote_fb__transmission__pset01__p11s__packet_stream.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

#include "source/db_obj/dbms_fb/v02_5_0/db_obj__dbms_fb__v02_5_0__factories.h"
#include "source/db_obj/ib_base/ib_sys_data.h"
#include "source/db_obj/isc_base/isc_initialize_utils.h"

#include "source/external/icu/ibp_external__icu__loader_factory.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace base_v01{namespace initializers{namespace pset01{namespace v01{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortInitializer_PSET01_v01

void RemoteFB__PortInitializer_PSET01_v01::Helper__FinishConnect_P11
                        (const oledb_lib::OLEDB_Props2__Data__Values* const pDsPropValues,
                         port_type*                                   const pPort,
                         const protocol::set01::PACKET_V01&                 packet,
                         wstr_box_type                                const ucs2_database_name,
                         RemoteFB__ClientConnectBlock_v1&                   clientConnectBlock,
                         const tag_connect_finalizator&                     FinalOpFuncs)
{
 assert(pDsPropValues);
 assert(pPort);
 assert(packet.operation==protocol::set01::op_accept);
 assert(packet.p_acpt.p_acpt__version==protocol::FB_PROTOCOL_VERSION11);

 //-----------------------------------------------------------------------
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__PortInitializer_PSET01_v01::Helper__FinishConnect_P11";

 switch(packet.p_acpt.p_acpt__architecture)
 {
  case protocol::FB_CURRENT_ARCHITECTURE:
  {
   self_type::Helper__Initialize__SetProtocolInfo_P10_P11_P12
    (pPort,
     clientConnectBlock,
     packet.p_acpt,
     &transmission::pset01::p11::RemoteFB__PSET01__P11S__PacketStream::Instance);

   break;
  }//case - current [симметричный протокол]

  case protocol::arch_generic:
  {
   self_type::Helper__Initialize__SetProtocolInfo_P10_P11_P12
    (pPort,
     clientConnectBlock,
     packet.p_acpt,
     &transmission::pset01::p11::RemoteFB__PSET01__P11A__PacketStream::Instance);

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

 // 00.01
 const external::icu::ICU__Loader::self_ptr
  spIcuLoader
   (external::icu::create_icu_loader
     (pDsPropValues));

 assert(spIcuLoader);

 // 00.02
 const db_obj::t_db_charset_manager_v2_ptr
  spCsMng
   (isc_base::isc_create_charset_manager_v2
     (pDsPropValues,
      spIcuLoader,
      ib_base::g_ods_cs__ib04_0_0));

 assert(spCsMng);

 // 01. Сервис для обработки ошибок
 pPort->RegService
  (db_obj::__db_guid<db_obj::dbms_fb::common::fb_common__svc__status_vector_utils>(),
   db_obj::dbms_fb::v02_5_0::create_svc__status_vector_utils(spCsMng));

 //-----------------------------------------------------------------------
 assert(FinalOpFuncs.P11);

 FinalOpFuncs.P11
  (pPort,
   ucs2_database_name,
   clientConnectBlock); //throw

 assert(pPort->m_ID.has_value());
}//Helper__FinishConnect_P11

////////////////////////////////////////////////////////////////////////////////
}/*nms v01*/}/*nms pset01*/}/*nms initializers*/}/*nms base_v01*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
