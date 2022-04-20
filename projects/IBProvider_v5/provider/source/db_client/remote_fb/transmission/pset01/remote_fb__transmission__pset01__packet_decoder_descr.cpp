////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__packet_decoder_descr.cpp
//! \brief   Описание распаковщика пакета
//! \author  Kovalenko Dmitry
//! \date    15.02.2015.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__packet_decoder_descr.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//struct RemoteFB__PSET01__PacketDecoderDescr

#ifndef NDEBUG
void RemoteFB__PSET01__PacketDecoderDescr::Debug__CheckArray
                                           (size_t           const szArray,
                                            const self_type* const pArray)
{
 CHECK_READ_TYPED_PTR(pArray,szArray);

 for(size_t i=0;i!=szArray;++i)
 {
  if(pArray[i].OperationID==protocol::set01::op_void)
  {
   assert(pArray[i].PacketDecoder==nullptr);

   continue;
  }//if

  assert(pArray[i].OperationID==(protocol::set01::P_OP)i);

  assert(pArray[i].PacketDecoder!=nullptr);
 }//for i
}//Debug__CheckArray
#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
