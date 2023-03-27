////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__stmt__allocate.cpp
//! \brief   �������� ����������� �������.
//! \author  Kovalenko Dmitry
//! \date    24.02.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__allocate.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__AllocateStatement

RemoteFB__API_P12__AllocateStatement RemoteFB__API_P12__AllocateStatement::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12__AllocateStatement::RemoteFB__API_P12__AllocateStatement()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12__AllocateStatement::~RemoteFB__API_P12__AllocateStatement()
{;}

//------------------------------------------------------------------------
void RemoteFB__API_P12__AllocateStatement::exec(RemoteFB__ConnectorData* const pData,
                                                stmt_handle_type*        const pStmtHandle)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(!pData->GetPort()->TestPortFlag__lazy());
 assert(pStmtHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12__AllocateStatement::exec";

 //----------------------------------------- �������� �������������� �����������
 if(!pData->GetPort()->m_ID.has_value())
 {
  //ERROR - ���������������� ���������� �����������

  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadCnHandle
   (c_bugcheck_src,
    L"#001");
 }//if

 //-----------------------------------------
 if((*pStmtHandle)!=nullptr)
 {
  //ERROR - [BUG CHECK] ��������� �������� ����������� �������

  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_StmtHandleNotZero
   (c_bugcheck_src,
    L"#002");
 }//if

 //-----------------------------------------
 //�������������� ������ ����������� ����������

 stmt_handle_type
  NewStmtHandle(handles::RemoteFB__HandleData_Statement::Create()); //throw

 assert(NewStmtHandle!=nullptr);

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_allocate_statement;

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_rlse.p_rlse_object
  packet.p_rlse.p_rlse__object=pData->GetPort()->m_ID.get_value();

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  pData->GetPort()->send_packet
   (portOpCtx,
    packet); //throw
 }//local

 //----------------------------------------- 4. get response
 for(;;)
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set01::PACKET_V01 packet;

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet); //throw

  if(packet.operation==protocol::set01::op_response)
  {
   pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
    (pData,
     c_OperationID,
     packet.p_resp,
     E_FAIL); //throw

   //���������� ������������� ����������� �������
   assert(NewStmtHandle!=nullptr);

   NewStmtHandle->m_ID.set_value(&packet.p_resp.p_resp__object);

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#003",
    packet.operation);
 }//for[ever]

 //----------------------------------------- EXIT

 // ����������� ������� � ������
 pData->StmtList__Add(NewStmtHandle);

 // ���������� ���������� ���������� �������
 (*pStmtHandle)=__STL_MOVE_VALUE(NewStmtHandle);

 assert(*pStmtHandle);
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
