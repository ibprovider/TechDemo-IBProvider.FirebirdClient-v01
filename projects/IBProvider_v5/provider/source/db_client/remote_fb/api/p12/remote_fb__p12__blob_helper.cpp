////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__p12__blob_helper.cpp
//! \brief   ¬спомогательный класс с кодом дл€ работы с блобами.
//! \author  Kovalenko Dmitry
//! \date    20.09.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__p12__blob_helper.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P12__BlobHelper

void RemoteFB__P12__BlobHelper::WriteSegment(RemoteFB__ConnectorData* const pData,
                                             protocol::P_OBJCT        const blobSrvID,
                                             protocol::P_USHORT       const cbData,
                                             const void*              const pvData)
{
 assert(pData);
 assert(pData->GetPort());

 CHECK_READ_PTR(pvData,cbData);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P12__BlobHelper::WriteSegment";

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_put_segment;

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_sgmt.p_sgmt_blob
  packet.p_sgmt.p_sgmt__blob=blobSrvID;

  //---------------------------------------- p_sgmt.p_sgmt_length
  packet.p_sgmt.p_sgmt__length=cbData;

  //---------------------------------------- p_sgmt.p_sgmt_segment
  packet.p_sgmt.p_sgmt__segment.cstr_length=cbData;

  packet.p_sgmt.p_sgmt__segment.cstr_address=reinterpret_cast<const protocol::P_UCHAR*>(pvData);

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  pData->GetPort()->send_packet(portOpCtx,
                                packet); //throw
 }//local

 //----------------------------------------- 4. get response
 for(;;)
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set01::PACKET_V01 packet;

  pData->GetPort()->receive_packet(portOpCtx,
                                   packet); //throw

  if(packet.operation==protocol::set01::op_response)
  {
   pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
    (pData,
     c_OperationID,
     packet.p_resp,
     E_FAIL); //throw

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#001",
    packet.operation);
 }//for[ever]

 //----------------------------------------- EXIT
}//WriteSegment

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
