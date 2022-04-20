////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__stmt__prepare.cpp
//! \brief   ���������� �������.
//! \author  Kovalenko Dmitry
//! \date    21.04.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__prepare.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__stmt_helper.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__srv_operation.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/set01/remote_fb__api_hlp__xsqlda_set01__utilities.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/db_operation_reg.h"
#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__PrepareStatement

RemoteFB__API_P12__PrepareStatement RemoteFB__API_P12__PrepareStatement::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12__PrepareStatement::RemoteFB__API_P12__PrepareStatement()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12__PrepareStatement::~RemoteFB__API_P12__PrepareStatement()
{;}

//------------------------------------------------------------------------
void RemoteFB__API_P12__PrepareStatement::exec
                                           (db_obj::t_db_operation_context& OpCtx,
                                            RemoteFB__ConnectorData*  const pData,
                                            tr_handle_type*           const pTrHandle,
                                            stmt_handle_type*         const pStmtHandle,
                                            protocol::P_USHORT        const SQL_dialect,
                                            sql_str_box_type          const SQL_str,
                                            unsigned long*            const pStmtTypeID)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(!pData->GetPort()->TestPortFlag__lazy());
 assert(pStmtHandle!=nullptr);
 assert(pStmtTypeID!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12__PrepareStatement::exec";

 //-----------------------------------------
 (*pStmtTypeID)=0;

 //-----------------------------------------
 RemoteFB__P12__SrvOperation serverOperation(pData);

 db_obj::t_db_operation_reg regServerOperation(OpCtx,&serverOperation);

 //----------------------------------------- �������� ����������� ����������
 if(pTrHandle!=nullptr && (*pTrHandle)!=nullptr)
 {
  if(!(*pTrHandle)->m_ID.has_value())
  {
   assert(false);

   RemoteFB__ErrorUtils::Throw_BugCheck_BadTrHandle
    (c_bugcheck_src,
     L"#001");
  }//if

  pData->BugCheck__CheckTr
   (*pTrHandle,
    c_bugcheck_src,
    L"#002");
 }//if - �������� ��������� ���������� ����������

 //----------------------------------------- �������� ����������� �������
 if((*pStmtHandle)==nullptr)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (c_bugcheck_src,
    L"#003");
 }//if

 if(!(*pStmtHandle)->m_ID.has_value())
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (c_bugcheck_src,
    L"#004");
 }//if

 pData->BugCheck__CheckStmt
  (*pStmtHandle,
   c_bugcheck_src,
   L"#005");

 //-----------------------------------------------------------------------
 //
 // ���������, ������ ������ ��������� � �������� ���������. � ��������� ������,
 // ������ ���������� ������ "The prepare statement identifies a prepare
 // statement with an open cursor".
 //
 // �� �� ������� ������ [2015-08-26] ��� ����������� ���������� � �������
 // ������� ��������� �������. ��� ��� �� ����� ������� - ��� ���������,
 // ��� ���������� FETCH-��������.
 //
 // ������� ����������� ����������� ��������� � ���������� ������.

 assert(!(*pStmtHandle)->m_spFetchResult);

 //-----------------------------------------------------------------------
 (*pStmtHandle)->ResetPrepareState();

 assert(!(*pStmtHandle)->m_EFlags.test(structure::negative_one));

 assert(!(*pStmtHandle)->m_pParentTr);

 //-----------------------------------------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_prepare_statement;

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

  RemoteFB__P12__StmtHelper::BuildPacket__op_prepare_statement
   (&packet,
    pTrHandle,
    (*pStmtHandle)->m_ID.get_value(),
    SQL_dialect,
    SQL_str);

  assert(packet.operation==c_OperationID);

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  //------ ���������� ����� ������ �������� � ��������
  RemoteFB__P12__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  pData->GetPort()->send_packet(portOpCtx,
                                packet); //throw

  sendFrame.complete(); //throw
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

   if(packet.p_resp.p_resp__object)
   {
    //���� �� ������� ����� ����� ������ ��������� � ��� ����� � ��� ������.
    //������� ������ ���������� ��� BUG-CHECK ������.

    //(*pStmtHandle)->m_PFlags.set(stmt_data_type::PFLAG__BLOB);

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#006",
      me_bug_check__unsupported_stmt_kind__BLOB_0)
   }//if

   //��������� ��������������� ������
   helpers::RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Process_PrepareInfoBuf
    (*pStmtHandle,
     packet.p_resp.p_resp__data.cstr_length,
     packet.p_resp.p_resp__data.cstr_address);
   
   assert(!(*pStmtHandle)->m_StmtTypeID.null());

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#007",
    packet.operation);
 }//for[ever]

 //----------------------------------------- EXIT
 (*pStmtHandle)->m_PFlags.set(stmt_data_type::PFLAG__PREPARED);

 //-----------------------------------------
 assert(!(*pStmtHandle)->m_StmtTypeID.null());

 (*pStmtTypeID)=(*pStmtHandle)->m_StmtTypeID.value();
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
