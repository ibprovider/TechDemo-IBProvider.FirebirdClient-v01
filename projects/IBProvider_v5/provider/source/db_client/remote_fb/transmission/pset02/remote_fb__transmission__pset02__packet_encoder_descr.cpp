////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02
//! \file    remote_fb__transmission__pset02__packet_encoder_descr.cpp
//! \brief   Описание упаковщика пакета
//! \author  Kovalenko Dmitry
//! \date    10.07.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset02/remote_fb__transmission__pset02__packet_encoder_descr.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{
////////////////////////////////////////////////////////////////////////////////
//struct RemoteFB__PSET02__PacketEncoderDescr

#ifndef NDEBUG
void RemoteFB__PSET02__PacketEncoderDescr::Debug__CheckArray
                                           (size_t           const szArray,
                                            const self_type* const pArray)
{
 CHECK_READ_TYPED_PTR(pArray,szArray);

 for(size_t i=0;i!=szArray;++i)
 {
  if(pArray[i].OperationID==protocol::set02::op_void)
  {
   assert(pArray[i].PacketEncoder==nullptr);

   continue;
  }//if

  assert(pArray[i].OperationID==(protocol::set02::P_OP)i);

  assert(pArray[i].PacketEncoder!=nullptr);
 }//for i
}//Debug__CheckArray
#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
