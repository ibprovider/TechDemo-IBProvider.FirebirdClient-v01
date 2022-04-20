////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__operation_context.cpp
//! \brief   Реализация контекста операции.
//! \author  Kovalenko Dmitry
//! \date    17.05.2015.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__operation_context.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__OperationContext

RemoteFB__OperationContext::RemoteFB__OperationContext()
{;}

//------------------------------------------------------------------------
RemoteFB__OperationContext::RemoteFB__OperationContext(RemoteFB__PacketMemory* const pMem)
{
 assert(pMem);

 m_services.push_back(svc_data_type(RemoteFB__PacketMemory::svcID,structure::not_null_ptr(pMem)));
}//RemoteFB__OperationContext

//------------------------------------------------------------------------
RemoteFB__OperationContext::~RemoteFB__OperationContext()
{;}

//interface --------------------------------------------------------------
RemoteFB__SmartObjectPtr RemoteFB__OperationContext::query_service(REFGUID serviceID)
{
 for(size_t i=0,_c=m_services.size();i!=_c;++i)
 {
  if(m_services[i].first!=serviceID)
   continue;

  assert(m_services[i].second);

  return structure::not_null_ptr(m_services[i].second.ptr());
 }//for i

 return nullptr;
}//query_service

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
