////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02
//! \file    remote_fb__transmission__pset02__op__decoder.cpp
//! \brief   Набор утилит для распаковки операций
//! \author  Kovalenko Dmitry
//! \date    10.07.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset02/remote_fb__transmission__pset02__op__decoder.h"
#include "source/db_client/remote_fb/transmission/pset02/remote_fb__transmission__pset02__xdr__decoder.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle_data__statement.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"
#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__OpDecoder

void RemoteFB__PSET02__OpDecoder::decode__op_cond_accept
                           (RemoteFB__PortOperationContext& op_ctx,
                            protocol::set02::PACKET_V02&    packet)
{
 assert(packet.operation==protocol::set02::op_cond_accept);

 const RemoteFB__PortReaderPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortReader>(op_ctx)); //throw

 assert(spBuf);

 const RemoteFB__PacketMemoryPtr
  spMem
   (RemoteFB__GetService<RemoteFB__PacketMemory>(op_ctx)); //throw

 assert(spMem);

 // MAP(xdr_short, reinterpret_cast<SSHORT&>(accept_with_data->p_acpt_version));
 // MAP(xdr_enum, reinterpret_cast<xdr_op&>(accept_with_data->p_acpt_architecture));
 // MAP(xdr_u_short, accept_with_data->p_acpt_type);
 // MAP(xdr_cstring, accept_with_data->p_acpt_data);
 // MAP(xdr_cstring, accept_with_data->p_acpt_plugin);
 // MAP(xdr_u_short, accept_with_data->p_acpt_authenticated);
 // MAP(xdr_cstring, accept_with_data->p_acpt_keys);

 typedef RemoteFB__PSET02__XDR__Decoder xdr;

 protocol::set02::P_OP_ACPD* const p_acpd=&packet.p_acpd;

 xdr::decode__p_short
  (spBuf,
   L"protocol::set02::P_OP_ACPD::p_acpt__version",
   reinterpret_cast<protocol::P_SHORT*>(&p_acpd->p_acpt__version));

 xdr::decode__p_arch
  (spBuf,
   L"protocol::set02::P_OP_ACPD::p_acpt__architecture",
   &p_acpd->p_acpt__architecture);

 xdr::decode__p_ushort
  (spBuf,
   L"protocol::set02::P_OP_ACPD::p_acpt__type",
   &p_acpd->p_acpt__type);

 xdr::decode__p_cstring_const
  (spBuf,
   spMem,
   RemoteFB__PacketMemory::mem_id__p_op_acpd__data,
   L"protocol::set02::P_OP_ACPD::p_acpd__data::cstr_length",
   L"protocol::set02::P_OP_ACPD::p_acpd__data::cstr_address",
   &p_acpd->p_acpd__data);

 xdr::decode__p_cstring_const
  (spBuf,
   spMem,
   RemoteFB__PacketMemory::mem_id__p_op_acpd__plugin,
   L"protocol::set02::P_OP_ACPD::p_acpd__plugin::cstr_length",
   L"protocol::set02::P_OP_ACPD::p_acpd__plugin::cstr_address",
   &p_acpd->p_acpd__plugin);

 xdr::decode__p_ushort
  (spBuf,
   L"protocol::set02::P_OP_ACPD::p_acpd__authenticated",
   &p_acpd->p_acpd__authenticated);

 xdr::decode__p_cstring_const
  (spBuf,
   spMem,
   RemoteFB__PacketMemory::mem_id__p_op_acpd__keys,
   L"protocol::set02::P_OP_ACPD::p_acpd__keys::cstr_length",
   L"protocol::set02::P_OP_ACPD::p_acpd__keys::cstr_address",
   &p_acpd->p_acpd__keys);
}//decode__op_cond_accept

//------------------------------------------------------------------------
void RemoteFB__PSET02__OpDecoder::decode__op_accept_data
                           (RemoteFB__PortOperationContext& op_ctx,
                            protocol::set02::PACKET_V02&    packet)
{
 assert(packet.operation==protocol::set02::op_accept_data);

 const RemoteFB__PortReaderPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortReader>(op_ctx)); //throw

 assert(spBuf);

 const RemoteFB__PacketMemoryPtr
  spMem
   (RemoteFB__GetService<RemoteFB__PacketMemory>(op_ctx)); //throw

 assert(spMem);

 // MAP(xdr_short, reinterpret_cast<SSHORT&>(accept_with_data->p_acpt_version));
 // MAP(xdr_enum, reinterpret_cast<xdr_op&>(accept_with_data->p_acpt_architecture));
 // MAP(xdr_u_short, accept_with_data->p_acpt_type);
 // MAP(xdr_cstring, accept_with_data->p_acpt_data);
 // MAP(xdr_cstring, accept_with_data->p_acpt_plugin);
 // MAP(xdr_u_short, accept_with_data->p_acpt_authenticated);
 // MAP(xdr_cstring, accept_with_data->p_acpt_keys);

 typedef RemoteFB__PSET02__XDR__Decoder xdr;

 protocol::set02::P_OP_ACPD* const p_acpd=&packet.p_acpd;

 xdr::decode__p_short
  (spBuf,
   L"protocol::set02::P_OP_ACPD::p_acpt__version",
   reinterpret_cast<protocol::P_SHORT*>(&p_acpd->p_acpt__version));

 xdr::decode__p_arch
  (spBuf,
   L"protocol::set02::P_OP_ACPD::p_acpt__architecture",
   &p_acpd->p_acpt__architecture);

 xdr::decode__p_ushort
  (spBuf,
   L"protocol::set02::P_OP_ACPD::p_acpt__type",
   &p_acpd->p_acpt__type);

 xdr::decode__p_cstring_const
  (spBuf,
   spMem,
   RemoteFB__PacketMemory::mem_id__p_op_acpd__data,
   L"protocol::set02::P_OP_ACPD::p_acpd__data::cstr_length",
   L"protocol::set02::P_OP_ACPD::p_acpd__data::cstr_address",
   &p_acpd->p_acpd__data);

 xdr::decode__p_cstring_const
  (spBuf,
   spMem,
   RemoteFB__PacketMemory::mem_id__p_op_acpd__plugin,
   L"protocol::set02::P_OP_ACPD::p_acpd__plugin::cstr_length",
   L"protocol::set02::P_OP_ACPD::p_acpd__plugin::cstr_address",
   &p_acpd->p_acpd__plugin);

 xdr::decode__p_ushort
  (spBuf,
   L"protocol::set02::P_OP_ACPD::p_acpd__authenticated",
   &p_acpd->p_acpd__authenticated);

 xdr::decode__p_cstring_const
  (spBuf,
   spMem,
   RemoteFB__PacketMemory::mem_id__p_op_acpd__keys,
   L"protocol::set02::P_OP_ACPD::p_acpd__keys::cstr_length",
   L"protocol::set02::P_OP_ACPD::p_acpd__keys::cstr_address",
   &p_acpd->p_acpd__keys);
}//decode__op_accept_data

//------------------------------------------------------------------------
void RemoteFB__PSET02__OpDecoder::decode__op_reject
                           (RemoteFB__PortOperationContext& UNUSED_ARG(op_ctx),
                            protocol::set02::PACKET_V02&    DEBUG_CODE(packet))
{
 assert(packet.operation==protocol::set02::op_reject);
}//decode__op_reject

//------------------------------------------------------------------------
void RemoteFB__PSET02__OpDecoder::decode__op_response
                           (RemoteFB__PortOperationContext& op_ctx,
                            protocol::set02::PACKET_V02&    packet)
{
 assert(packet.operation==protocol::set02::op_response);

 const RemoteFB__PortReaderPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortReader>(op_ctx)); //throw

 assert(spBuf);

 const RemoteFB__PacketMemoryPtr
  spMem
   (RemoteFB__GetService<RemoteFB__PacketMemory>(op_ctx)); //throw

 assert(spMem);

 //MAP(xdr_short, reinterpret_cast<SSHORT&>(response->p_resp_object));
 //MAP(xdr_quad, response->p_resp_blob_id);
 //MAP(xdr_cstring, response->p_resp_data);
 //return xdr_status_vector(xdrs, response->p_resp_status_vector) ?
 //                         P_TRUE(xdrs, p) : P_FALSE(xdrs, p);

 typedef RemoteFB__PSET02__XDR__Decoder xdr;

 protocol::set02::P_OP_RESP* const p_resp=&packet.p_resp;

 xdr::decode__p_objct
  (spBuf,
   L"protocol::set02::P_OP_RESP::p_resp__object",
   &p_resp->p_resp__object);

 xdr::decode__p_bid
  (spBuf,
   L"protocol::set02::P_OP_RESP::p_resp__blob_id::high",
   L"protocol::set02::P_OP_RESP::p_resp__blob_id::low",
   &p_resp->p_resp__blob_id);

 xdr::decode__p_cstring_const
  (spBuf,
   spMem,
   RemoteFB__PacketMemory::mem_id__p_op_resp__data,
   L"protocol::set02::P_OP_RESP::p_resp__data::cstr_length",
   L"protocol::set02::P_OP_RESP::p_resp__data::cstr_address",
   &p_resp->p_resp__data);

 xdr::decode__status_vector__eset02
  (spBuf,
   spMem,
   RemoteFB__PacketMemory::mem_id__p_op_resp__status_vector,
   protocol::set02::C_STATUS_VECTOR_MAX_SIZE,
   L"protocol::set02::P_OP_RESP::p_resp__status_vector",
   &p_resp->p_resp__status_vector);
}//decode__op_response

//------------------------------------------------------------------------
void RemoteFB__PSET02__OpDecoder::decode__op_dummy
                           (RemoteFB__PortOperationContext& UNUSED_ARG(op_ctx),
                            protocol::set02::PACKET_V02&    DEBUG_CODE(packet))
{
 assert(packet.operation==protocol::set02::op_dummy);
}//decode__op_dummy

//------------------------------------------------------------------------
void RemoteFB__PSET02__OpDecoder::decode__op_cont_auth
                           (RemoteFB__PortOperationContext& op_ctx,
                            protocol::set02::PACKET_V02&    packet)
{
 assert(packet.operation==protocol::set02::op_cont_auth);

 const RemoteFB__PortReaderPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortReader>(op_ctx)); //throw

 assert(spBuf);

 const RemoteFB__PacketMemoryPtr
  spMem
   (RemoteFB__GetService<RemoteFB__PacketMemory>(op_ctx)); //throw

 assert(spMem);

 //-----------------------------------------
 // MAP(xdr_cstring, auth->p_data);
 // MAP(xdr_cstring, auth->p_name);
 // MAP(xdr_cstring, auth->p_list);
 // MAP(xdr_cstring, auth->p_keys);

 typedef RemoteFB__PSET02__XDR__Decoder xdr;

 protocol::set02::P_OP_AUTH_CONT* const p_auth_cont=&packet.p_auth_cont;

 xdr::decode__p_cstring_const
  (spBuf,
   spMem,
   RemoteFB__PacketMemory::mem_id__p_op_auth_cont__data,
   L"protocol::set02::P_OP_AUTH_CONT::p_auth_cont__data::cstr_length",
   L"protocol::set02::P_OP_AUTH_CONT::p_auth_cont__data::cstr_address",
   &p_auth_cont->p_auth_cont__data);

 xdr::decode__p_cstring_const
  (spBuf,
   spMem,
   RemoteFB__PacketMemory::mem_id__p_op_auth_cont__name,
   L"protocol::set02::P_OP_AUTH_CONT::p_auth_cont__name::cstr_length",
   L"protocol::set02::P_OP_AUTH_CONT::p_auth_cont__name::cstr_address",
   &p_auth_cont->p_auth_cont__name);

 xdr::decode__p_cstring_const
  (spBuf,
   spMem,
   RemoteFB__PacketMemory::mem_id__p_op_auth_cont__list,
   L"protocol::set02::P_OP_AUTH_CONT::p_auth_cont__list::cstr_length",
   L"protocol::set02::P_OP_AUTH_CONT::p_auth_cont__list::cstr_address",
   &p_auth_cont->p_auth_cont__list);

 xdr::decode__p_cstring_const
  (spBuf,
   spMem,
   RemoteFB__PacketMemory::mem_id__p_op_auth_cont__keys,
   L"protocol::set02::P_OP_AUTH_CONT::p_auth_cont__keys::cstr_length",
   L"protocol::set02::P_OP_AUTH_CONT::p_auth_cont__keys::cstr_address",
   &p_auth_cont->p_auth_cont__keys);
}//decode__op_cont_auth

//------------------------------------------------------------------------
void RemoteFB__PSET02__OpDecoder::decode__op_sql_response__s
                           (RemoteFB__PortOperationContext& op_ctx,
                            protocol::set02::PACKET_V02&    packet)
{
 assert(packet.operation==protocol::set02::op_sql_response);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__PSET02__OpDecoder::decode__op_sql_response__s";

 //-----------------------------------------
 const RemoteFB__PortReaderPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortReader>(op_ctx)); //throw

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::FB_CURRENT_ARCHITECTURE);

 const handles::RemoteFB__HandleData_Statement::self_ptr
  spStmtData
   (RemoteFB__GetService<handles::RemoteFB__HandleData_Statement>(op_ctx));

 assert(spStmtData);

 //-----------------------------------------
 typedef RemoteFB__XDR__Decoder xdr;

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
   if(spStmtData->m_OutParams__MSG_BLR.empty())
   {
    //ERROR - [BUG CHECK] неожиданное получение пакета op_sql_response.

    IBP_ErrorUtils::Throw__BugCheck__DEBUG
     (c_bugcheck_src,
      L"#001",
      L"unexpected situation");

    assert(false);
   }//if

   xdr::decode__opaque
    (spBuf,
     L"protocol::set02::P_OP_SQLDATA::message_data",
     spStmtData->m_OutParams__MSG_DATA.size(),
     spStmtData->m_OutParams__MSG_DATA.buffer());

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
 }//switch
}//decode__op_sql_response__s

//------------------------------------------------------------------------
void RemoteFB__PSET02__OpDecoder::decode__op_fetch_response__s
                           (RemoteFB__PortOperationContext& op_ctx,
                            protocol::set02::PACKET_V02&    packet)
{
 assert(packet.operation==protocol::set02::op_fetch_response);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PSET02__OpDecoder::decode__op_fetch_response__s";

 //-----------------------------------------
 const RemoteFB__PortReaderPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortReader>(op_ctx)); //throw

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::FB_CURRENT_ARCHITECTURE);

 const handles::RemoteFB__HandleData_Statement::self_ptr
  spStmt
   (RemoteFB__GetService<handles::RemoteFB__HandleData_Statement>(op_ctx));

 assert(spStmt);
 assert(spStmt->m_spFetchResult);
 assert(spStmt->m_spFetchResult->m_ProcessedFetchCount<=spStmt->m_spFetchResult->m_RequestedFetchCount);

 //-----------------------------------------
 typedef RemoteFB__XDR__Decoder xdr;

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
   if(spStmt->m_OutParams__MSG_BLR.empty())
   {
    //ERROR - [BUG CHECK] неожиданное получение пакета op_fetch_response.

    IBP_ErrorUtils::Throw__BugCheck__DEBUG
     (c_bugcheck_src,
      L"#001",
      me_bug_check__unexpected_situation_0);
   }//if

   //---------------------------------------
   if(spStmt->m_spFetchResult->m_ProcessedFetchCount==spStmt->m_spFetchResult->m_RequestedFetchCount)
   {
    //ERROR - [BUG CHECK] У нас проблема. Мы получили больше рядов чем запрашивали.

    IBP_ErrorUtils::Throw__BugCheck__DEBUG
     (c_bugcheck_src,
      L"#002",
      L"exceeded the expected number of rows: %1",
      spStmt->m_spFetchResult->m_RequestedFetchCount);
   }//if

   assert(spStmt->m_spFetchResult->m_ProcessedFetchCount<spStmt->m_spFetchResult->m_RequestedFetchCount);

   //---------------------------------------
   protocol::P_UCHAR* const pRowDataBlock=spStmt->m_spFetchResult->ROWS__AllocBlock(); //throw?

   ++spStmt->m_spFetchResult->m_ProcessedFetchCount;

   xdr::decode__opaque
    (spBuf,
     L"protocol::set02::P_OP_SQLDATA::message_data",
     spStmt->m_spFetchResult->ROWS__GetDataSize(),
     pRowDataBlock); //throw

   break;
  }//case 1

  default:
  {
   //ERROR - [BUG CHECK] У нас проблема. Мы ожидаем отсутствие или одно OUT-сообщение.

   IBP_ErrorUtils::Throw__BugCheck__DEBUG
    (c_bugcheck_src,
     L"#003",
     L"unexpected value of p_sqldata__messages: %1",
     p_sqldata->p_sqldata__messages);
  }//default
 }//switch p_sqldata_messages
}//decode__op_fetch_response__s

//------------------------------------------------------------------------
void RemoteFB__PSET02__OpDecoder::decode__op_slice__s
                           (RemoteFB__PortOperationContext& op_ctx,
                            protocol::set02::PACKET_V02&    packet)
{
 assert(packet.operation==protocol::set02::op_slice);

 //-----------------------------------------
 //const wchar_t* const c_bugcheck_src
 // =L"RemoteFB__PSET02__OpDecoder::decode__op_slice__s";

 //-----------------------------------------
 const RemoteFB__PortReaderPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortReader>(op_ctx)); //throw

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::FB_CURRENT_ARCHITECTURE);

 //-----------------------------------------
 const RemoteFB__PacketMemoryPtr
  spMem
   (RemoteFB__GetService<RemoteFB__PacketMemory>(op_ctx)); //throw

 assert(spMem);

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

 protocol::P_UCHAR* lstr_address
  =RemoteFB__AllocPacketMemory<protocol::P_UCHAR>
    (spMem,
     RemoteFB__PacketMemory::mem_id__p_op_slice__data,
     p_slc_data->p_slc_data__slice.lstr_length); //throw

 xdr::decode__opaque
  (spBuf,
   L"protocol::set02::P_OP_SLC_DATA::p_slc_data__slice",
   p_slc_data->p_slc_data__slice.lstr_length,
   lstr_address);

 p_slc_data->p_slc_data__slice.lstr_address
  =lstr_address;
}//decode__op_slice__s

////////////////////////////////////////////////////////////////////////////////
}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
