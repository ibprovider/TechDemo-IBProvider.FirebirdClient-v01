////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__op__encoder.cpp
//! \brief   Набор утилит для упаковки операций
//! \author  Kovalenko Dmitry
//! \date    26.11.2014.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__op__encoder.h"
#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__xdr__encoder.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__stmt_execute_data_v1.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__OpEncoder

void RemoteFB__PSET01__OpEncoder::encode__op_connect
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_connect);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_CNCT* const p_cnct=&packet.p_cnct;

 assert(packet.p_cnct.p_cnct__count<=_DIM_(p_cnct->p_cnct__versions));

 xdr::encode__p_op
  (spBuf,
   &p_cnct->p_cnct__operation);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_cnct->p_cnct__cversion);

 xdr::encode__p_arch
  (spBuf,
  &p_cnct->p_cnct__client);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_cnct->p_cnct__file);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_cnct->p_cnct__count);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_cnct->p_cnct__user_id);

 //----
 {
  const protocol::set01::P_OP_CNCT::P_OP_CNCT_REPEAT*       p=p_cnct->p_cnct__versions;
  const protocol::set01::P_OP_CNCT::P_OP_CNCT_REPEAT* const e=p+packet.p_cnct.p_cnct__count;

  assert(p<=e);

  for(;p!=e;++p)
  {
   xdr::encode__p_ushort_as_p_short
    (spBuf,
     &p->p_cnct__version);

   xdr::encode__p_arch
    (spBuf,
     &p->p_cnct__architecture);

   xdr::encode__p_ushort
    (spBuf,
     &p->p_cnct__min_type);

   xdr::encode__p_ushort
    (spBuf,
     &p->p_cnct__max_type);

   xdr::encode__p_ushort_as_p_short
    (spBuf,
     &p->p_cnct__weight);
  }//for p
 }//local
}//encode__op_connect

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_attach
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_attach);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_ATCH* const p_atch=&packet.p_atch;

 //MAP(xdr_short, reinterpret_cast<SSHORT&>(attach->p_atch_database));
 //MAP(xdr_cstring_const, attach->p_atch_file);
 //MAP(xdr_cstring_const, attach->p_atch_dpb);

 xdr::encode__p_objct
  (spBuf,
   &p_atch->p_atch__database);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_atch->p_atch__file);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_atch->p_atch__dpb);
}//encode__op_attach

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_create
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_create);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_ATCH* const p_atch=&packet.p_atch;

 //MAP(xdr_short, reinterpret_cast<SSHORT&>(attach->p_atch_database));
 //MAP(xdr_cstring_const, attach->p_atch_file);
 //MAP(xdr_cstring_const, attach->p_atch_dpb);

 xdr::encode__p_objct
  (spBuf,
   &p_atch->p_atch__database);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_atch->p_atch__file);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_atch->p_atch__dpb);
}//encode__op_create

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_detach
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_detach);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__XDR__Encoder xdr;

 const protocol::set01::P_OP_RLSE* const p_rlse=&packet.p_rlse;

 xdr::encode__p_objct
  (spBuf,
   &p_rlse->p_rlse__object);
}//encode__op_detach

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_drop_database
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_drop_database);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__XDR__Encoder xdr;

 const protocol::set01::P_OP_RLSE* const p_rlse=&packet.p_rlse;

 xdr::encode__p_objct
  (spBuf,
   &p_rlse->p_rlse__object);
}//encode__op_drop_database

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_trusted_auth
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_trusted_auth);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_TRAU* const p_trau=&packet.p_trau;

 xdr::encode__p_cstring_const
  (spBuf,
   &p_trau->p_trau__data);
}//encode__op_trusted_auth

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_info_database
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_info_database);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_INFO* const p_info=&packet.p_info;

 xdr::encode__p_objct
  (spBuf,
   &p_info->p_info__object);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_info->p_info__incarnation);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_info->p_info__items);

 xdr::encode__p_ushort_length_as_p_short__pset01
  (spBuf,
   &p_info->p_info__buffer_length);
}//encode__op_info_database

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_transaction
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_transaction);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_STTR* const p_sttr=&packet.p_sttr;

 xdr::encode__p_objct
  (spBuf,
   &p_sttr->p_sttr__database);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_sttr->p_sttr__tpb);
}//encode__op_transaction

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_rollback
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_rollback);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__XDR__Encoder xdr;

 const protocol::set01::P_OP_RLSE* const p_rlse=&packet.p_rlse;

 xdr::encode__p_objct
  (spBuf,
   &p_rlse->p_rlse__object);
}//encode__op_rollback

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_rollback_retaining
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_rollback_retaining);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__XDR__Encoder xdr;

 const protocol::set01::P_OP_RLSE* const p_rlse=&packet.p_rlse;

 xdr::encode__p_objct
  (spBuf,
   &p_rlse->p_rlse__object);
}//encode__op_rollback_retaining

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_commit
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_commit);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__XDR__Encoder xdr;

 const protocol::set01::P_OP_RLSE* const p_rlse=&packet.p_rlse;

 xdr::encode__p_objct
  (spBuf,
   &p_rlse->p_rlse__object);
}//encode__op_commit

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_commit_retaining
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_commit_retaining);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__XDR__Encoder xdr;

 const protocol::set01::P_OP_RLSE* const p_rlse=&packet.p_rlse;

 xdr::encode__p_objct
  (spBuf,
   &p_rlse->p_rlse__object);
}//encode__op_commit_retaining

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_prepare2
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_prepare2);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_PREP* const p_prep=&packet.p_prep;

 xdr::encode__p_objct
  (spBuf,
   &p_prep->p_prep__transaction);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_prep->p_prep__data);
}//encode__op_prepare2

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_allocate_statement
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_allocate_statement);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__XDR__Encoder xdr;

 const protocol::set01::P_OP_RLSE* const p_rlse=&packet.p_rlse;

 xdr::encode__p_objct
  (spBuf,
   &p_rlse->p_rlse__object);
}//encode__op_allocate_statement

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_free_statement
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_free_statement);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__XDR__Encoder xdr;

 const protocol::set01::P_OP_SQLFREE* const p_sqlfree=&packet.p_sqlfree;

 // MAP(xdr_short, reinterpret_cast<SSHORT&>(free_stmt->p_sqlfree_statement));
 // MAP(xdr_short, reinterpret_cast<SSHORT&>(free_stmt->p_sqlfree_option));

 xdr::encode__p_objct
  (spBuf,
   &p_sqlfree->p_sqlfree__statement);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqlfree->p_sqlfree__option);
}//encode__op_free_statement

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_prepare_statement
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_prepare_statement);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_SQLST* const p_sqlst=&packet.p_sqlst;

 //MAP(xdr_short, reinterpret_cast<SSHORT&>(prep_stmt->p_sqlst_transaction));
 //MAP(xdr_short, reinterpret_cast<SSHORT&>(prep_stmt->p_sqlst_statement));
 //MAP(xdr_short, reinterpret_cast<SSHORT&>(prep_stmt->p_sqlst_SQL_dialect));
 //MAP(xdr_cstring_const, prep_stmt->p_sqlst_SQL_str);
 //MAP(xdr_cstring_const, prep_stmt->p_sqlst_items);
 //MAP(xdr_short, reinterpret_cast<SSHORT&>(prep_stmt->p_sqlst_buffer_length));

 xdr::encode__p_objct
  (spBuf,
   &p_sqlst->p_sqlst__transaction);

 xdr::encode__p_objct
  (spBuf,
   &p_sqlst->p_sqlst__statement);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqlst->p_sqlst__SQL_dialect);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_sqlst->p_sqlst__SQL_str);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_sqlst->p_sqlst__items);

 xdr::encode__p_ushort_length_as_p_short__pset01
  (spBuf,
   &p_sqlst->p_sqlst__buffer_length);
}//encode__op_prepare_statement

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_info_sql
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_info_sql);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_INFO* const p_info=&packet.p_info;

 xdr::encode__p_objct
  (spBuf,
   &p_info->p_info__object);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_info->p_info__incarnation);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_info->p_info__items);

 xdr::encode__p_ushort_length_as_p_short__pset01
  (spBuf,
   &p_info->p_info__buffer_length);
}//encode__op_info_sql

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_execute__s
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_execute);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::FB_CURRENT_ARCHITECTURE);

 const RemoteFB__OpSvc__StmtExecuteData_v1::self_ptr
  spStmtData
   (RemoteFB__GetService<RemoteFB__OpSvc__StmtExecuteData_v1>(op_ctx));

 assert(spStmtData);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_SQLDATA* const p_sqldata=&packet.p_sqldata;

 //-----------------------------------------
 xdr::encode__p_objct
  (spBuf,
   &p_sqldata->p_sqldata__statement);

 xdr::encode__p_objct
  (spBuf,
   &p_sqldata->p_sqldata__transaction);

 //! \note
 //!  В оригинальной версии здесь понакручено (xdr_sql_blr)
 xdr::encode__p_cstring_const
  (spBuf,
   &p_sqldata->p_sqldata__blr);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqldata->p_sqldata__message_number);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqldata->p_sqldata__messages);

 // в случае симметричного протокола передаем MSG-буфер без трансформации
 if(p_sqldata->p_sqldata__messages>0)
 {
  assert(p_sqldata->p_sqldata__messages==1);

  assert(p_sqldata->p_sqldata__blr.cstr_length>0);

  xdr::encode__opaque
   (spBuf,
    spStmtData->InMsg_DATA.size(),
    spStmtData->InMsg_DATA.data());
 }
#ifndef NDEBUG
 else
 {
  assert(p_sqldata->p_sqldata__messages==0);

  assert(p_sqldata->p_sqldata__blr.cstr_length==0);

  assert(spStmtData->InMsg_DATA.empty());
 }//else
#endif
}//encode__op_execute__s

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_execute2__s
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_execute2);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::FB_CURRENT_ARCHITECTURE);

 const RemoteFB__OpSvc__StmtExecuteData_v1::self_ptr
  spStmtData
   (RemoteFB__GetService<RemoteFB__OpSvc__StmtExecuteData_v1>(op_ctx));

 assert(spStmtData);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_SQLDATA* const p_sqldata=&packet.p_sqldata;

 //-----------------------------------------
 xdr::encode__p_objct
  (spBuf,
   &p_sqldata->p_sqldata__statement);

 xdr::encode__p_objct
  (spBuf,
   &p_sqldata->p_sqldata__transaction);

 //! \note
 //!  В оригинальной версии здесь понакручено (xdr_sql_blr)
 xdr::encode__p_cstring_const
  (spBuf,
   &p_sqldata->p_sqldata__blr);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqldata->p_sqldata__message_number);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqldata->p_sqldata__messages);

 // в случае симметричного протокола передаем MSG-буфер без трансформации
 if(p_sqldata->p_sqldata__messages>0)
 {
  assert(p_sqldata->p_sqldata__messages==1);

  assert(p_sqldata->p_sqldata__blr.cstr_length>0);

  xdr::encode__opaque
   (spBuf,
    spStmtData->InMsg_DATA.size(),
    spStmtData->InMsg_DATA.data());
 }
#ifndef NDEBUG
 else
 {
  assert(p_sqldata->p_sqldata__messages==0);

  assert(p_sqldata->p_sqldata__blr.cstr_length==0);

  assert(spStmtData->InMsg_DATA.empty());
 }//else
#endif

 xdr::encode__p_cstring_const
  (spBuf,
   &p_sqldata->p_sqldata__out_blr);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqldata->p_sqldata__out_message_number);
}//encode__op_execute2__s

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_fetch
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_fetch);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 //sqldata = &p->p_sqldata;
 //MAP(xdr_short, reinterpret_cast<SSHORT&>(sqldata->p_sqldata_statement));
 //if(!xdr_sql_blr(xdrs,
 //                (SLONG) sqldata->p_sqldata_statement,
 //                &sqldata->p_sqldata_blr,
 //                true,
 //                TYPE_PREPARED))
 //{
 // return P_FALSE(xdrs, p);
 //}
 //MAP(xdr_short, reinterpret_cast<SSHORT&>(sqldata->p_sqldata_message_number));
 //MAP(xdr_short, reinterpret_cast<SSHORT&>(sqldata->p_sqldata_messages));

 const protocol::set01::P_OP_SQLDATA* const p_sqldata=&packet.p_sqldata;

 //-----------------------------------------
 xdr::encode__p_objct
  (spBuf,
   &p_sqldata->p_sqldata__statement);

 //! \note
 //!  В оригинальной версии здесь понакручено (xdr_sql_blr)
 xdr::encode__p_cstring_const
  (spBuf,
   &p_sqldata->p_sqldata__blr);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqldata->p_sqldata__message_number);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqldata->p_sqldata__messages);
}//encode__op_fetch

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_open_blob2
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_open_blob2);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_BLOB* const p_blob=&packet.p_blob;

 //MAP(xdr_cstring_const, blob->p_blob_bpb);
 //MAP(xdr_short, reinterpret_cast<SSHORT&>(blob->p_blob_transaction));
 //MAP(xdr_quad, blob->p_blob_id);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_blob->p_blob__bpb);

 xdr::encode__p_objct
  (spBuf,
   &p_blob->p_blob__transaction);

 xdr::encode__p_bid
  (spBuf,
   &p_blob->p_blob__id);
}//encode__op_open_blob2

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_create_blob2
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_create_blob2);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_BLOB* const p_blob=&packet.p_blob;

 //MAP(xdr_cstring_const, blob->p_blob_bpb);
 //MAP(xdr_short, reinterpret_cast<SSHORT&>(blob->p_blob_transaction));
 //MAP(xdr_quad, blob->p_blob_id);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_blob->p_blob__bpb);

 xdr::encode__p_objct
  (spBuf,
   &p_blob->p_blob__transaction);

 xdr::encode__p_bid
  (spBuf,
   &p_blob->p_blob__id);
}//encode__op_create_blob2

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_close_blob
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_close_blob);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__XDR__Encoder xdr;

 const protocol::set01::P_OP_RLSE* const p_rlse=&packet.p_rlse;

 xdr::encode__p_objct
  (spBuf,
   &p_rlse->p_rlse__object);
}//encode__op_close_blob

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_cancel_blob
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_cancel_blob);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__XDR__Encoder xdr;

 const protocol::set01::P_OP_RLSE* const p_rlse=&packet.p_rlse;

 xdr::encode__p_objct
  (spBuf,
   &p_rlse->p_rlse__object);
}//encode__op_cancel_blob

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_info_blob
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_info_blob);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_INFO* const p_info=&packet.p_info;

 xdr::encode__p_objct
  (spBuf,
   &p_info->p_info__object);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_info->p_info__incarnation);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_info->p_info__items);

 xdr::encode__p_ushort_length_as_p_short__pset01
  (spBuf,
   &p_info->p_info__buffer_length);
}//encode__op_info_blob

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_get_segment
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_get_segment);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_SGMT* const p_sgmt=&packet.p_sgmt;

 //MAP(xdr_short, reinterpret_cast<SSHORT&>(segment->p_sgmt_blob));
 //MAP(xdr_short, reinterpret_cast<SSHORT&>(segment->p_sgmt_length));
 //MAP(xdr_cstring_const, segment->p_sgmt_segment);

 xdr::encode__p_objct
  (spBuf,
   &p_sgmt->p_sgmt__blob);

 //мы не должны запрашивать данные нулевой длины
 assert(p_sgmt->p_sgmt__length>0);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sgmt->p_sgmt__length);

 //[2015-09-17] Мы не ожидаем здесь передачу каких либо данных.
 assert(p_sgmt->p_sgmt__segment.cstr_length==0);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_sgmt->p_sgmt__segment);
}//encode__op_get_segment

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_put_segment
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_put_segment);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_SGMT* const p_sgmt=&packet.p_sgmt;

 //MAP(xdr_short, reinterpret_cast<SSHORT&>(segment->p_sgmt_blob));
 //MAP(xdr_short, reinterpret_cast<SSHORT&>(segment->p_sgmt_length));
 //MAP(xdr_cstring_const, segment->p_sgmt_segment);

 xdr::encode__p_objct
  (spBuf,
   &p_sgmt->p_sgmt__blob);

 //ФОРМАЛЬНО, мы не должны передавать данные нулевой длины
 assert(p_sgmt->p_sgmt__length>0);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sgmt->p_sgmt__length);

 assert(p_sgmt->p_sgmt__segment.cstr_length==p_sgmt->p_sgmt__length);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_sgmt->p_sgmt__segment);
}//encode__op_put_segment

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_put_slice__s
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_put_slice);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::FB_CURRENT_ARCHITECTURE);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_PUT_SLC* const p_put_slc=&packet.p_put_slc;

 //MAP(xdr_short, reinterpret_cast<SSHORT&>(slice->p_slc_transaction));
 //MAP(xdr_quad, slice->p_slc_id);
 //MAP(xdr_long, reinterpret_cast<SLONG&>(slice->p_slc_length));
 //MAP(xdr_cstring, slice->p_slc_sdl);
 //MAP(xdr_longs, slice->p_slc_parameters);

 xdr::encode__p_objct
  (spBuf,
   &p_put_slc->p_put_slc__transaction);

 xdr::encode__p_bid
  (spBuf,
   &p_put_slc->p_put_slc__id);

 xdr::encode__p_ulong_as_p_long
  (spBuf,
   &p_put_slc->p_put_slc__slice.lstr_length);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_put_slc->p_put_slc__sdl);

 xdr::encode__p_longs
  (spBuf,
   &p_put_slc->p_put_slc__parameters);

 //----------------------------------------- p_put_slc_slice
 xdr::encode__p_ulong_as_p_long
  (spBuf,
   &p_put_slc->p_put_slc__slice.lstr_length);

 //! \note
 //!  В оригинальном коде здесь идет выгрузка блоками с максимальной длинной FB_MAX_OPAQUE.
 //!  Мы на это забъем и будем выгружать сразу.
 //!
 //!  Проблем не должно возникнуть, потому что FB_MAX_OPAQUE кратен FB_PACKET_FIELD_ALIGN.

 assert_s((protocol::FB_MAX_OPAQUE%protocol::FB_PACKET_FIELD_ALIGN)==0);

 xdr::encode__opaque
  (spBuf,
   p_put_slc->p_put_slc__slice.lstr_length,
   p_put_slc->p_put_slc__slice.lstr_address);
}//encode__op_put_slice__s

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_get_slice
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_get_slice);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_GET_SLC* const p_get_slc=&packet.p_get_slc;

 //MAP(xdr_short, reinterpret_cast<SSHORT&>(slice->p_slc_transaction));
 //MAP(xdr_quad, slice->p_slc_id);
 //MAP(xdr_long, reinterpret_cast<SLONG&>(slice->p_slc_length));
 //MAP(xdr_cstring, slice->p_slc_sdl);
 //MAP(xdr_longs, slice->p_slc_parameters);

 xdr::encode__p_objct
  (spBuf,
   &p_get_slc->p_get_slc__transaction);

 xdr::encode__p_bid
  (spBuf,
   &p_get_slc->p_get_slc__id);

 xdr::encode__p_ulong_as_p_long
  (spBuf,
   &p_get_slc->p_get_slc__length);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_get_slc->p_get_slc__sdl);

 xdr::encode__p_longs
  (spBuf,
   &p_get_slc->p_get_slc__parameters);

 //----------------------------------------- p_get_slc_slice
 const protocol::P_ULONG zeroUI4=0;

 xdr::encode__p_ulong_as_p_long
  (spBuf,
   &zeroUI4);
}//encode__op_get_slice

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_cancel
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_cancel);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__XDR__Encoder xdr;

 const protocol::set01::P_OP_CANCEL* const p_cancel=&packet.p_cancel;

 //MAP(xdr_short, reinterpret_cast<SSHORT&>(cancel_op->p_co_kind));

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_cancel->p_cancel__kind);
}//encode__op_cancel

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_exec_immediate
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_exec_immediate);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_SQLST* const p_sqlst=&packet.p_sqlst;

 //MAP(xdr_short, reinterpret_cast<SSHORT&>(prep_stmt->p_sqlst_transaction));
 //MAP(xdr_short, reinterpret_cast<SSHORT&>(prep_stmt->p_sqlst_statement));
 //MAP(xdr_short, reinterpret_cast<SSHORT&>(prep_stmt->p_sqlst_SQL_dialect));
 //MAP(xdr_cstring_const, prep_stmt->p_sqlst_SQL_str);
 //MAP(xdr_cstring_const, prep_stmt->p_sqlst_items);
 //MAP(xdr_short, reinterpret_cast<SSHORT&>(prep_stmt->p_sqlst_buffer_length));

 //---------- проверяем поля, значения которых ДОЛЖНЫ быть фиксированы.
 assert(p_sqlst->p_sqlst__statement==0);

 assert(p_sqlst->p_sqlst__items.cstr_length==0);

 assert(p_sqlst->p_sqlst__items.cstr_address==nullptr);

 assert(p_sqlst->p_sqlst__buffer_length==0);

 //----------
 xdr::encode__p_objct
  (spBuf,
   &p_sqlst->p_sqlst__transaction);

 xdr::encode__p_objct
  (spBuf,
   &p_sqlst->p_sqlst__statement);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqlst->p_sqlst__SQL_dialect);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_sqlst->p_sqlst__SQL_str);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_sqlst->p_sqlst__items);

 xdr::encode__p_ushort_length_as_p_short__pset01
  (spBuf,
   &p_sqlst->p_sqlst__buffer_length);
}//encode__op_exec_immediate

//------------------------------------------------------------------------
void RemoteFB__PSET01__OpEncoder::encode__op_exec_immediate2__s
                               (RemoteFB__PortOperationContext&    op_ctx,
                                const protocol::set01::PACKET_V01& packet)
{
 assert(packet.operation==protocol::set01::op_exec_immediate2);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::FB_CURRENT_ARCHITECTURE);

 const RemoteFB__OpSvc__StmtExecuteData_v1::self_ptr
  spStmtData
   (RemoteFB__GetService<RemoteFB__OpSvc__StmtExecuteData_v1>(op_ctx));

 assert(spStmtData);

 typedef RemoteFB__PSET01__XDR__Encoder xdr;

 const protocol::set01::P_OP_SQLST* const p_sqlst=&packet.p_sqlst;

 //----------------------------------------- part1 - code
 // prep_stmt = &p->p_sqlst;
 // if (!xdr_sql_blr(xdrs, (SLONG) - 1, &prep_stmt->p_sqlst_blr, false, TYPE_IMMEDIATE))
 // {
 //     return P_FALSE(xdrs, p);
 // }
 // MAP(xdr_short, reinterpret_cast<SSHORT&>(prep_stmt->p_sqlst_message_number));
 // MAP(xdr_short, reinterpret_cast<SSHORT&>(prep_stmt->p_sqlst_messages));
 // if (prep_stmt->p_sqlst_messages)
 // {
 //     if (!xdr_sql_message(xdrs, (SLONG) - 1))
 //         return P_FALSE(xdrs, p);
 // }
 // if (!xdr_sql_blr(xdrs, (SLONG) - 1, &prep_stmt->p_sqlst_out_blr, true, TYPE_IMMEDIATE))
 // {
 //     return P_FALSE(xdrs, p);
 // }
 // MAP(xdr_short, reinterpret_cast<SSHORT&>(prep_stmt->p_sqlst_out_message_number));
 // Fall into ...

 //------------
 //! \note
 //!  В оригинальной версии здесь понакручено (xdr_sql_blr)
 xdr::encode__p_cstring_const
  (spBuf,
   &p_sqlst->p_sqlst__blr);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqlst->p_sqlst__message_number);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqlst->p_sqlst__messages);

 if(p_sqlst->p_sqlst__messages>0)
 {
  assert(p_sqlst->p_sqlst__messages==1);

  assert(p_sqlst->p_sqlst__blr.cstr_length>0);

  //m_InParams__MSG_DATA содержит как минимум один индикатор NULL
  assert(!spStmtData->InMsg_DATA.empty());

  xdr::encode__opaque
   (spBuf,
    spStmtData->InMsg_DATA.size(),
    spStmtData->InMsg_DATA.data());
 }//if
#ifndef NDEBUG
 else
 {
  assert(p_sqlst->p_sqlst__messages==0);

  assert(p_sqlst->p_sqlst__blr.cstr_length==0);

  assert(spStmtData->InMsg_DATA.empty());
 }//else
#endif

 xdr::encode__p_cstring_const
  (spBuf,
   &p_sqlst->p_sqlst__out_blr);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqlst->p_sqlst__out_message_number);

 //----------------------------------------- part2 - code
 // prep_stmt = &p->p_sqlst;
 // MAP(xdr_short, reinterpret_cast<SSHORT&>(prep_stmt->p_sqlst_transaction));
 // MAP(xdr_short, reinterpret_cast<SSHORT&>(prep_stmt->p_sqlst_statement));
 // MAP(xdr_short, reinterpret_cast<SSHORT&>(prep_stmt->p_sqlst_SQL_dialect));
 // MAP(xdr_cstring_const, prep_stmt->p_sqlst_SQL_str);
 // MAP(xdr_cstring_const, prep_stmt->p_sqlst_items);
 // MAP(xdr_short, reinterpret_cast<SSHORT&>(prep_stmt->p_sqlst_buffer_length));

 //---------- проверяем поля, значения которых ДОЛЖНЫ быть фиксированы.
 assert(p_sqlst->p_sqlst__statement==0);

 assert(p_sqlst->p_sqlst__items.cstr_length==0);

 assert(p_sqlst->p_sqlst__items.cstr_address==nullptr);

 assert(p_sqlst->p_sqlst__buffer_length==0);

 //----------
 xdr::encode__p_objct
  (spBuf,
   &p_sqlst->p_sqlst__transaction);

 xdr::encode__p_objct
  (spBuf,
   &p_sqlst->p_sqlst__statement);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqlst->p_sqlst__SQL_dialect);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_sqlst->p_sqlst__SQL_str);

 xdr::encode__p_cstring_const
  (spBuf,
   &p_sqlst->p_sqlst__items);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqlst->p_sqlst__buffer_length);
}//encode__op_exec_immediate2__s

////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
