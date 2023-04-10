////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01__p12
//! \file    remote_fb__transmission__pset01__p12__op__decoder.cpp
//! \brief   Набор утилит для распаковки операций
//! \author  Kovalenko Dmitry
//! \date    27.05.2015.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset01/p12/remote_fb__transmission__pset01__p12__op__decoder.h"
#include "source/db_client/remote_fb/transmission/pset01/p12/remote_fb__transmission__pset01__p12__xdr__decoder.h"
#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__decoder.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle_data__statement.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__get_array_slice_descr.h"
#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__P12__OpDecoder

void RemoteFB__PSET01__P12__OpDecoder::decode__op_sql_response__a
                                           (RemoteFB__PortOperationContext& op_ctx,
                                            protocol::set01::PACKET_V01&    packet)
{
 assert(packet.operation==protocol::set01::op_sql_response);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PSET01__P12__OpDecoder::decode__op_sql_response__a";

 //-----------------------------------------
 const RemoteFB__PortReaderPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortReader>(op_ctx)); //throw

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::arch_generic);

 const handles::RemoteFB__HandleData_Statement::self_ptr
  spStmtData
   (RemoteFB__GetService<handles::RemoteFB__HandleData_Statement>(op_ctx));

 assert(spStmtData);

 //-----------------------------------------
 typedef RemoteFB__PSET01__P12__XDR__Decoder xdr12;
 typedef RemoteFB__XDR__Decoder              xdr;

 protocol::set01::P_OP_SQLDATA* const p_sqldata=&packet.p_sqldata;

 xdr::decode__p_ushort_as_p_short
  (spBuf,
   L"protocol::set01::P_OP_SQLDATA::p_sqldata__messages",
   &p_sqldata->p_sqldata__messages);

 switch(p_sqldata->p_sqldata__messages)
 {
  case 0:
   break;

  case 1:
  {
   if(spStmtData->m_OutParams__MSG_BLR.empty())
   {
    //ERROR - [BUG CHECK] неожиданное получение пакета op_sql_response.

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#001",
      L"unexpected situation");
   }//if

   xdr12::decode__sql_message
    (spBuf,
     spStmtData->m_OutParams__MSG_BLR.size(),
     spStmtData->m_OutParams__MSG_BLR.buffer(),
     spStmtData->m_OutParams__MSG_DATA.size(),
     spStmtData->m_OutParams__MSG_DATA.buffer());

   break;
  }//case 1

  default:
  {
   //ERROR - [BUG CHECK] У нас проблема. Мы ожидаем отсутствие или одно OUT-сообщение.

   structure::wstr_formatter
    freason(L"unexpected value of p_sqldata_messages: %1");

   freason<<p_sqldata->p_sqldata__messages;

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#002",
     freason.c_str());
  }//default
 }//switch p_sqldata_messages
}//decode__op_sql_response__a

//------------------------------------------------------------------------
void RemoteFB__PSET01__P12__OpDecoder::decode__op_fetch_response__a
                                           (RemoteFB__PortOperationContext& op_ctx,
                                            protocol::set01::PACKET_V01&    packet)
{
 assert(packet.operation==protocol::set01::op_fetch_response);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PSET01__P12__OpDecoder::decode__op_fetch_response__a";

 //-----------------------------------------
 const RemoteFB__PortReaderPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortReader>(op_ctx)); //throw

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::arch_generic);

 const handles::RemoteFB__HandleData_Statement::self_ptr
  spStmt
   (RemoteFB__GetService<handles::RemoteFB__HandleData_Statement>(op_ctx));

 assert(spStmt);
 assert(spStmt->m_spFetchResult);
 assert(spStmt->m_spFetchResult->m_ProcessedFetchCount<=spStmt->m_spFetchResult->m_RequestedFetchCount);

 //-----------------------------------------
 typedef RemoteFB__PSET01__P12__XDR__Decoder xdr12;
 typedef RemoteFB__XDR__Decoder              xdr;

 protocol::set01::P_OP_SQLDATA* const p_sqldata=&packet.p_sqldata;

 //-----------------------------------------
 xdr::decode__p_ulong_as_p_long
  (spBuf,
   L"protocol::set01::P_OP_SQLDATA::p_sqldata__status",
   &p_sqldata->p_sqldata__status);

 xdr::decode__p_ushort_as_p_short
  (spBuf,
   L"protocol::set01::P_OP_SQLDATA::p_sqldata__messages",
   &p_sqldata->p_sqldata__messages);

 switch(p_sqldata->p_sqldata__messages)
 {
  case 0:
   break;

  case 1:
  {
   if(spStmt->m_OutParams__MSG_BLR.empty())
   {
    //ERROR - [BUG CHECK] неожиданное получение пакета op_fetch_response.

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#001",
      me_bug_check__unexpected_situation_0);
   }//if

   //---------------------------------------
   if(spStmt->m_spFetchResult->m_ProcessedFetchCount==spStmt->m_spFetchResult->m_RequestedFetchCount)
   {
    //ERROR - [BUG CHECK] У нас проблема. Мы получили больше рядов чем запрашивали.

    structure::wstr_formatter freason(L"exceeded the expected number of rows: %1");

    freason<<spStmt->m_spFetchResult->m_RequestedFetchCount;

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#002",
      freason.c_str());
   }//if

   assert(spStmt->m_spFetchResult->m_ProcessedFetchCount<spStmt->m_spFetchResult->m_RequestedFetchCount);

   //---------------------------------------
   protocol::P_UCHAR* const pRowDataBlock=spStmt->m_spFetchResult->ROWS__AllocBlock(); //throw?

   ++spStmt->m_spFetchResult->m_ProcessedFetchCount;

   try
   {
    xdr12::decode__sql_message
     (spBuf,
      spStmt->m_OutParams__MSG_BLR.size(),
      spStmt->m_OutParams__MSG_BLR.buffer(),
      spStmt->m_spFetchResult->ROWS__GetDataSize(),
      pRowDataBlock); //throw
   }
   catch(...)
   {
    //В случае проблем, освобождаем последний выделенный блок.
    spStmt->m_spFetchResult->ROWS__FreeLastBlock();

    //Количество запрошенных данных (m_ProcessedFetchCount) не уменьшаем,
    //Потому что это общий счетчик обработанных ответов с данными рядов.

    //И возобновляем исключение.
    throw;
   }//catch

   break;
  }//case 1

  default:
  {
   //ERROR - [BUG CHECK] У нас проблема. Мы ожидаем отсутствие или одно OUT-сообщение.

   structure::wstr_formatter freason(L"unexpected value of p_sqldata_messages: %1");

   freason<<p_sqldata->p_sqldata__messages;

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#003",
     freason.c_str());
  }//default
 }//switch p_sqldata_messages
}//decode__op_fetch_response__a

//------------------------------------------------------------------------
void RemoteFB__PSET01__P12__OpDecoder::decode__op_slice__a
                                           (RemoteFB__PortOperationContext& op_ctx,
                                            protocol::set01::PACKET_V01&    packet)
{
 assert(packet.operation==protocol::set01::op_slice);

 //-----------------------------------------
 //const wchar_t* const c_bugcheck_src
 // =L"RemoteFB__PSET01__P12__OpDecoder::decode__op_slice__a";

 //-----------------------------------------
 const RemoteFB__PortReaderPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortReader>(op_ctx)); //throw

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::arch_generic);

 //-----------------------------------------
 const RemoteFB__PacketMemoryPtr
  spMem
   (RemoteFB__GetService<RemoteFB__PacketMemory>(op_ctx)); //throw

 assert(spMem);

 //-----------------------------------------
 const RemoteFB__OpSvc__GetArraySliceDescrPtr
  spGetDescr
   (RemoteFB__GetService<RemoteFB__OpSvc__GetArraySliceDescr>(op_ctx));

 assert(spGetDescr);

 //-----------------------------------------
 typedef RemoteFB__PSET01__P12__XDR__Decoder xdr12;
 typedef RemoteFB__XDR__Decoder              xdr;

 protocol::set01::P_OP_SLC_DATA* const p_slc_data=&packet.p_slc_data;

 //-----------------------------------------
 xdr::decode__p_ulong_as_p_long
  (spBuf,
   L"protocol::set01::P_OP_SLC_DATA::p_slc_data__length",
   &p_slc_data->p_slc_data__length);

 //-----------------------------------------
 xdr::decode__p_ulong_as_p_long
  (spBuf,
   L"protocol::set01::P_OP_SLC_DATA::p_slc_data__slice.lstr_length",
   &p_slc_data->p_slc_data__slice.lstr_length);

 protocol::P_UCHAR* const lstr_address
  =RemoteFB__AllocPacketMemory<protocol::P_UCHAR>
    (spMem,
     RemoteFB__PacketMemory::mem_id__p_op_slice__data,
     p_slc_data->p_slc_data__slice.lstr_length); //throw

 xdr12::decode__array_slice
  (spBuf,
   spGetDescr->GetArraySliceDescr(),
   p_slc_data->p_slc_data__slice.lstr_length,
   lstr_address);

 p_slc_data->p_slc_data__slice.lstr_address
  =lstr_address;
}//decode__op_slice__a

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
