////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02__p13
//! \file    remote_fb__transmission__pset02__p13__op__decoder.cpp
//! \brief   Набор утилит для распаковки операций
//! \author  Kovalenko Dmitry
//! \date    20.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset02/p13/remote_fb__transmission__pset02__p13__op__decoder.h"
#include "source/db_client/remote_fb/transmission/pset02/p13/remote_fb__transmission__pset02__p13__xdr__decoder.h"
#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__decoder.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__stmt_execute_data_v2.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__get_array_slice_descr.h"
#include "source/db_client/remote_fb/remote_fb__fetch_result.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__P13__OpDecoder

void RemoteFB__PSET02__P13__OpDecoder::decode__op_sql_response__a
                                           (RemoteFB__PortOperationContext& op_ctx,
                                            protocol::set02::PACKET_V02&    packet)
{
 assert(packet.operation==protocol::set02::op_sql_response);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PSET02__P13__OpDecoder::decode__op_sql_response__a";

 //-----------------------------------------
 const RemoteFB__PortReaderPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortReader>(op_ctx)); //throw

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::arch_generic);

 const RemoteFB__OpSvc__StmtExecuteData_v2::self_ptr
  spStmtData
   (RemoteFB__GetService<RemoteFB__OpSvc__StmtExecuteData_v2>(op_ctx));

 assert(spStmtData);

 //-----------------------------------------
 typedef RemoteFB__PSET02__P13__XDR__Decoder xdr13;
 typedef RemoteFB__XDR__Decoder              xdr;

 protocol::set02::P_OP_SQLDATA* const p_sqldata=&packet.p_sqldata;

 xdr::decode__p_ushort_as_p_short
  (spBuf,
   L"protocol::set02::P_OP_SQLDATA::p_sqldata__messages",
   &p_sqldata->p_sqldata__messages);

 switch(p_sqldata->p_sqldata__messages)
 {
  case 0:
   break;

  case 1:
  {
   if(spStmtData->OutMsg_BLR.empty())
   {
    //ERROR - [BUG CHECK] неожиданное получение пакета op_sql_response.

    IBP_ErrorUtils::Throw__BugCheck__DEBUG
     (c_bugcheck_src,
      L"#001",
      L"unexpected situation");
   }//if

   xdr13::decode__sql_message
    (spBuf,
     spStmtData->OutMsg_DATA_DESCRS.size(),
     spStmtData->OutMsg_DATA_DESCRS.data(),
     spStmtData->OutMsg_DATA.size(),
     spStmtData->OutMsg_DATA.data(),
     spStmtData->OutMsg_NULLS.size(),
     spStmtData->OutMsg_NULLS.data());

   break;
  }//case 1

  default:
  {
   //ERROR - [BUG CHECK] У нас проблема. Мы ожидаем отсутствие или одно OUT-сообщение.

   IBP_ErrorUtils::Throw__BugCheck__DEBUG
    (c_bugcheck_src,
     L"#002",
     L"unexpected value of p_sqldata_messages: %1",
     p_sqldata->p_sqldata__messages);
  }//default
 }//switch p_sqldata_messages
}//decode__op_sql_response__a

//------------------------------------------------------------------------
void RemoteFB__PSET02__P13__OpDecoder::decode__op_fetch_response__a
                                           (RemoteFB__PortOperationContext& op_ctx,
                                            protocol::set02::PACKET_V02&    packet)
{
 assert(packet.operation==protocol::set02::op_fetch_response);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PSET02__P13__OpDecoder::decode__op_fetch_response__a";

 //-----------------------------------------
 const RemoteFB__PortReaderPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortReader>(op_ctx)); //throw

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::arch_generic);

 const RemoteFB__FetchResult::self_ptr
  spFetchResult
   (RemoteFB__GetService<RemoteFB__FetchResult>(op_ctx));

 assert(spFetchResult);
 assert(spFetchResult->m_ProcessedFetchCount<=spFetchResult->m_RequestedFetchCount);

 //-----------------------------------------
 typedef RemoteFB__PSET02__P13__XDR__Decoder xdr13;
 typedef RemoteFB__XDR__Decoder              xdr;

 protocol::set02::P_OP_SQLDATA* const p_sqldata=&packet.p_sqldata;

 //-----------------------------------------
 xdr::decode__p_ulong_as_p_long
  (spBuf,
   L"protocol::set02::P_OP_SQLDATA::p_sqldata__status",
   &p_sqldata->p_sqldata__status);

 xdr::decode__p_ushort_as_p_short
  (spBuf,
   L"protocol::set02::P_OP_SQLDATA::p_sqldata__messages",
   &p_sqldata->p_sqldata__messages);

 switch(p_sqldata->p_sqldata__messages)
 {
  case 0:
   break;

  case 1:
  {
   if(spFetchResult->m_OutMSG_BLR.empty())
   {
    //ERROR - [BUG CHECK] неожиданное получение пакета op_fetch_response.

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#001",
      me_bug_check__unexpected_situation_0);
   }//if

   //---------------------------------------
   if(spFetchResult->m_ProcessedFetchCount==spFetchResult->m_RequestedFetchCount)
   {
    //ERROR - [BUG CHECK] У нас проблема. Мы получили больше рядов чем запрашивали.

    IBP_ErrorUtils::Throw__BugCheck__DEBUG
     (c_bugcheck_src,
      L"#002",
      L"exceeded the expected number of rows: %1",
      spFetchResult->m_RequestedFetchCount);
   }//if

   assert(spFetchResult->m_ProcessedFetchCount<spFetchResult->m_RequestedFetchCount);

   //---------------------------------------
   protocol::P_UCHAR* const pRowDataBlock=spFetchResult->ROWS__AllocBlock(); //throw?

   ++spFetchResult->m_ProcessedFetchCount;

   try
   {
    xdr13::decode__sql_message
     (spBuf,
      spFetchResult->m_OutMSG_DATA_DESCRS.size(),
      spFetchResult->m_OutMSG_DATA_DESCRS.data(),
      spFetchResult->ROWS__GetDataSize(),
      pRowDataBlock,
      spFetchResult->m_OutMSG_NULLS.size(),
      spFetchResult->m_OutMSG_NULLS.data()); //throw
   }
   catch(...)
   {
    //В случае проблем, освобождаем последний выделенный блок.
    spFetchResult->ROWS__FreeLastBlock();

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

   IBP_ErrorUtils::Throw__BugCheck__DEBUG
    (c_bugcheck_src,
     L"#003",
     L"unexpected value of p_sqldata_messages: %1",
     p_sqldata->p_sqldata__messages);
  }//default
 }//switch p_sqldata_messages
}//decode__op_fetch_response__a

//------------------------------------------------------------------------
void RemoteFB__PSET02__P13__OpDecoder::decode__op_slice__a
                                           (RemoteFB__PortOperationContext& op_ctx,
                                            protocol::set02::PACKET_V02&    packet)
{
 assert(packet.operation==protocol::set02::op_slice);

 //-----------------------------------------
 //const wchar_t* const c_bugcheck_src
 // =L"RemoteFB__PSET02__P13__OpDecoder::decode__op_slice__a";

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
 typedef RemoteFB__XDR__Decoder xdr;

 protocol::set02::P_OP_SLC_DATA* const p_slc_data=&packet.p_slc_data;

 //-----------------------------------------
 xdr::decode__p_ulong_as_p_long
  (spBuf,
   L"protocol::set02::P_OP_SLC_DATA::p_slc_data__length",
   &p_slc_data->p_slc_data__length);

 //-----------------------------------------
 xdr::decode__p_ulong_as_p_long
  (spBuf,
   L"protocol::set02::P_OP_SLC_DATA::p_slc_data__slice.lstr_length",
   &p_slc_data->p_slc_data__slice.lstr_length);

 protocol::P_UCHAR* const lstr_address
  =RemoteFB__AllocPacketMemory<protocol::P_UCHAR>
    (spMem,
     RemoteFB__PacketMemory::mem_id__p_op_slice__data,
     p_slc_data->p_slc_data__slice.lstr_length); //throw

 xdr::decode__array_slice
  (spBuf,
   spGetDescr->GetArraySliceDescr(),
   p_slc_data->p_slc_data__slice.lstr_length,
   lstr_address);

 p_slc_data->p_slc_data__slice.lstr_address
  =lstr_address;
}//decode__op_slice__a

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
