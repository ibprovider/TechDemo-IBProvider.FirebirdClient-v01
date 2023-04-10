////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__stmt__get_info.cpp
//! \brief   Получение сведений о запросе.
//! \author  Kovalenko Dmitry
//! \date    19.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__stmt__get_info.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__srv_operation.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/db_operation_reg.h"
#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error.h"
#include <structure/t_pointer_cast.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__GetStatementInfo::tagOpMemoryBuffer

class RemoteFB__API_P13__GetStatementInfo::tagOpMemoryBuffer:public RemoteFB__MemoryPool
{
 private:
  typedef tagOpMemoryBuffer                 self_type;
  typedef RemoteFB__MemoryPool              inherited;

  tagOpMemoryBuffer(const self_type&);
  self_type& operator = (const self_type&);

 public:
  tagOpMemoryBuffer(RemoteFB__InfoBuffer* pInfoBuffer);

  virtual ~tagOpMemoryBuffer();

  //interface ------------------------------------------------------------
  virtual void* allocate(enumMemoryID memID,
                         size_t       sz) COMP_W000004_OVERRIDE_FINAL;

 private:
  RemoteFB__InfoBuffer* const m_pInfoBuffer;

#ifndef NDEBUG
  bool m_DEBUG__BufferForBlobWasAllocated;
#endif
};//class RemoteFB__API_P13__GetStatementInfo::tagOpMemoryBuffer

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__GetStatementInfo::tagOpMemoryBuffer

RemoteFB__API_P13__GetStatementInfo::tagOpMemoryBuffer::tagOpMemoryBuffer
                                           (RemoteFB__InfoBuffer* const pInfoBuffer)
 :m_pInfoBuffer(pInfoBuffer)
#ifndef NDEBUG
 ,m_DEBUG__BufferForBlobWasAllocated(false)
#endif
{
 assert(m_pInfoBuffer);
}//tagOpMemoryBuffer

//------------------------------------------------------------------------
RemoteFB__API_P13__GetStatementInfo::tagOpMemoryBuffer::~tagOpMemoryBuffer()
{;}

//interface --------------------------------------------------------------
void* RemoteFB__API_P13__GetStatementInfo::tagOpMemoryBuffer::allocate
                                           (enumMemoryID const memID,
                                            size_t       const sz)
{
 assert(m_pInfoBuffer);

 if(memID==mem_id__p_op_resp__data)
 {
  //запрос на выделение памяти под информационные данные

  //разрешаем только однократное выделение памяти
  assert(!m_DEBUG__BufferForBlobWasAllocated);

  DEBUG_CODE(m_DEBUG__BufferForBlobWasAllocated=true;)

  assert_s(sizeof((*m_pInfoBuffer)[0])==1);

  return m_pInfoBuffer->alloc(sz); //no throw!
 }//if memID==mem_id__p_op_resp__p_resp_data

 return inherited::allocate(memID,sz);
}//allocate

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__GetStatementInfo

RemoteFB__API_P13__GetStatementInfo RemoteFB__API_P13__GetStatementInfo::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__GetStatementInfo::RemoteFB__API_P13__GetStatementInfo()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13__GetStatementInfo::~RemoteFB__API_P13__GetStatementInfo()
{;}

//------------------------------------------------------------------------
void RemoteFB__API_P13__GetStatementInfo::internal__exec__direct
               (db_obj::t_db_operation_context& OpCtx,
                RemoteFB__ConnectorData*  const pData,
                stmt_handle_type*         const pStmtHandle,
                unsigned short            const Incornation,
                unsigned short            const cItems,
                const unsigned char*      const pItems,
                RemoteFB__InfoBuffer&           ResultBuffer)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pStmtHandle!=nullptr);

 CHECK_READ_TYPED_PTR(pItems,cItems);

 //
 // It was cleared in 'exec' method.
 //
 assert(ResultBuffer.empty());

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__GetStatementInfo::internal__exec__direct";

 //-----------------------------------------
 RemoteFB__P13__SrvOperation serverOperation(pData);

 db_obj::t_db_operation_reg regServerOperation(OpCtx,&serverOperation);

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_info_sql;

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  packet.operation = c_OperationID;

  packet.p_info.p_info__object=(*pStmtHandle)->m_ID.get_value();

  packet.p_info.p_info__incarnation=Incornation;

  packet.p_info.p_info__items.cstr_length=cItems;

  packet.p_info.p_info__items.cstr_address=pItems;

  packet.p_info.p_info__buffer_length
   =structure::get_numeric_limits(packet.p_info.p_info__buffer_length).max_value();

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  //------ Let's define the boundaries of work with the server
  RemoteFB__P13__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  pData->GetPort()->send_packet
   (portOpCtx,
    packet); //throw

  sendFrame.complete(); //throw
 }//local

 //----------------------------------------- 4. get response
 for(;;)
 {
  tagOpMemoryBuffer memoryPool(&ResultBuffer);

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set02::PACKET_V02 packet;

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet); //throw

  if(packet.operation==protocol::set02::op_response)
  {
   pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult
    (pData,
     c_OperationID,
     packet.p_resp,
     E_FAIL); //throw

   //результат должен быть записан непосредственно в буфер получателя
   assert(packet.p_resp.p_resp__data.cstr_length==ResultBuffer.size());
   assert(packet.p_resp.p_resp__data.cstr_address==ResultBuffer.buffer());

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#004",
    packet.operation);
 }//for[ever]
}//internal__exec__direct

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
