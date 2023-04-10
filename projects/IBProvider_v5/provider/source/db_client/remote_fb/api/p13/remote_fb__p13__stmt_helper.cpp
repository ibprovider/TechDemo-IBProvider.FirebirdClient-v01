////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__stmt_helper.cpp
//! \brief   ��������������� ����� � ����� ��� ������ � ���������.
//! \author  Kovalenko Dmitry
//! \date    17.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__p13__stmt_helper.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__utilities.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/set01/remote_fb__api_hlp__xsqlda_set01__utilities.h"
#include "source/db_client/remote_fb/transmission/pset02/remote_fb__transmission__pset02__op__info.h"
#include <structure/t_pointer_cast.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__StmtHelper

void RemoteFB__P13__StmtHelper::BuildPacket__op_prepare_statement
                                           (protocol::set02::PACKET_V02*  const pPacket,
                                            tr_handle_type*               const pTrHandle,
                                            protocol::P_OBJCT             const stmtID,
                                            protocol::P_USHORT            const SQL_dialect,
                                            sql_str_box_type              const SQL_str)
{
 assert(pPacket);

 //-----------------------------------------
 pPacket->init();

 //-----------------------------------------
 pPacket->operation = protocol::set02::op_prepare_statement;

 //------------- p_sqlst_transaction
 if(pTrHandle!=nullptr && (*pTrHandle)!=nullptr)
  pPacket->p_sqlst.p_sqlst__transaction=(*pTrHandle)->m_ID.get_value();

 //------------- p_sqlst_statement
 pPacket->p_sqlst.p_sqlst__statement=stmtID;

 //------------- p_sqlst_SQL_dialect
 pPacket->p_sqlst.p_sqlst__SQL_dialect=SQL_dialect;

 //------------- p_sqlst_SQL_str
 CHECK_READ_TYPED_PTR(SQL_str.ptr,SQL_str.len);

 RemoteFB__P13__Utilities::CheckAndSetLength__CSTRING_CONST_V2
  (&pPacket->p_sqlst.p_sqlst__SQL_str,
   SQL_str.len,
   ibp_mce_cmd_stmt_too_long_2);

 assert(pPacket->p_sqlst.p_sqlst__SQL_str.cstr_length==SQL_str.len);

 assert_s(sizeof(*pPacket->p_sqlst.p_sqlst__SQL_str.cstr_address)==sizeof(*SQL_str.ptr));

 structure::reinterpret_ptr_cast
  (&pPacket->p_sqlst.p_sqlst__SQL_str.cstr_address,
   SQL_str.ptr);

 //------------- p_sqlst_items
 assert_s(_DIM_(helpers::RemoteFB__API_HLP__XSQLDA_SET01__Utilities::sm_sql_info__prepare)<=protocol::set02::C_CSTRING_V2_MAX_LENGTH_P13);

 pPacket->p_sqlst.p_sqlst__items.cstr_length
  =_DIM_(helpers::RemoteFB__API_HLP__XSQLDA_SET01__Utilities::sm_sql_info__prepare);

 pPacket->p_sqlst.p_sqlst__items.cstr_address
  =helpers::RemoteFB__API_HLP__XSQLDA_SET01__Utilities::sm_sql_info__prepare;

 //------------- p_sqlst_buffer_length
 pPacket->p_sqlst.p_sqlst__buffer_length
  =protocol::set02::C_INFO_BUF_SIZE_P13;
}//BuildPacket__op_prepare

//------------------------------------------------------------------------
void RemoteFB__P13__StmtHelper::BuildPacket__op_execute
                                           (protocol::set02::PACKET_V02*  const pPacket,
                                            tr_data_type*                 const pTr,
                                            stmt_data_type*               const pStmt)
{
 assert(pPacket);
 assert(pStmt);

 pPacket->operation = protocol::set02::op_execute;

 //---------------------------------------- p_sqldata_statement
 pPacket->p_sqldata.p_sqldata__statement=pStmt->m_ID.get_value();

 //---------------------------------------- p_sqldata_transaction
 pPacket->p_sqldata.p_sqldata__transaction=pTr?pTr->m_ID.get_value():0;

 //---------------------------------------- p_sqldata_blr
 RemoteFB__P13__Utilities::CheckAndSetLength__CSTRING_CONST_V2
  (&pPacket->p_sqldata.p_sqldata__blr,
   pStmt->m_InParams__MSG_BLR.size(),
   ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3,
   L"pInXSQLDA");

 assert(pPacket->p_sqldata.p_sqldata__blr.cstr_length==pStmt->m_InParams__MSG_BLR.size());

 pPacket->p_sqldata.p_sqldata__blr.cstr_address=pStmt->m_InParams__MSG_BLR.buffer();

 //---------------------------------------- p_sqldata_message_number
 pPacket->p_sqldata.p_sqldata__message_number=0;

 //---------------------------------------- p_sqldata_messages
 pPacket->p_sqldata.p_sqldata__messages=pStmt->m_InParams__MSG_BLR.empty()?0:1;
}//BuildPacket__op_execute

//------------------------------------------------------------------------
protocol::P_USHORT RemoteFB__P13__StmtHelper::ComputeBatchSize
                                           (size_t const szMsgData)
{
 // When batches of records are returned, they are returned as
 //    follows:
 //     <op_fetch_response> <data_record 1>
 //     <op_fetch_response> <data_record 2>
 // 	...
 //     <op_fetch_response> <data_record n-1>
 //     <op_fetch_response> <data_record n>

 // end-of-batch is indicated by setting p_sqldata_messages to
 // 0 in the op_fetch_response.  End of cursor is indicated
 // by setting p_sqldata_status to a non-zero value.

 assert(szMsgData>0);

 const size_t cbFetchResponsePacket
  =transmission::pset02::RemoteFB__PSET02__OpInfo::get_size__op_fetch_response(szMsgData);

 assert(cbFetchResponsePacket>0);

 const size_t cbFetchResponsePacket0
  =transmission::pset02::RemoteFB__PSET02__OpInfo::get_size__op_fetch_response(0);

 assert(cbFetchResponsePacket0>0);

 //-----------------------------------------
 size_t cPackets
  =Helper__ComputePacketNumber
    (protocol::FB_DESIRED_ROWS_PER_BATCH,
     cbFetchResponsePacket,
     cbFetchResponsePacket0);

 if(protocol::FB_MAX_PACKETS_PER_BATCH<cPackets)
 {
  cPackets
   =Helper__ComputePacketNumber
     (protocol::FB_MIN_ROWS_PER_BATCH,
      cbFetchResponsePacket,
      cbFetchResponsePacket0);
 }//if

 if(cPackets<protocol::FB_MIN_PACKETS_PER_BATCH)
  cPackets=protocol::FB_MIN_PACKETS_PER_BATCH;

 assert(cPackets>0);

 assert(cbFetchResponsePacket0<protocol::FB_SERVER_PACKET_SIZE);

 size_t cResultRows
  =((cPackets*protocol::FB_SERVER_PACKET_SIZE)-cbFetchResponsePacket0)/cbFetchResponsePacket;

 if(cResultRows<protocol::FB_MIN_ROWS_PER_BATCH)
  cResultRows=protocol::FB_MIN_ROWS_PER_BATCH;

 if(structure::t_numeric_limits<protocol::P_USHORT>::max_value()<cResultRows)
  cResultRows=structure::t_numeric_limits<protocol::P_USHORT>::max_value();

 assert(cResultRows>0);

 return static_cast<protocol::P_USHORT>(cResultRows);
}//ComputeBatchSize

//------------------------------------------------------------------------
size_t RemoteFB__P13__StmtHelper::Helper__ComputePacketNumber
                                           (size_t const cRows,
                                            size_t const cbPacket,
                                            size_t const cbPacket0)
{
 assert_s(protocol::FB_SERVER_PACKET_SIZE>0);

 //! \todo
 //!  �������� �������� ������������

 return (((cRows*cbPacket)                       // data set
          + cbPacket0                            // used in 1st pkt
          + (protocol::FB_SERVER_PACKET_SIZE-1)) // to round up
         / protocol::FB_SERVER_PACKET_SIZE);
}//Helper__ComputePacketNumber

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
