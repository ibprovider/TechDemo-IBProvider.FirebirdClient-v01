////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02__p13
//! \file    remote_fb__transmission__pset02__p13__op__encoder.cpp
//! \brief   Набор утилит для упаковки операций
//! \author  Kovalenko Dmitry
//! \date    20.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset02/p13/remote_fb__transmission__pset02__p13__op__encoder.h"
#include "source/db_client/remote_fb/transmission/pset02/p13/remote_fb__transmission__pset02__p13__xdr__encoder.h"
#include "source/db_client/remote_fb/transmission/pset02/remote_fb__transmission__pset02__xdr__encoder.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle_data__statement.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__get_array_slice_descr.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__P13__OpEncoder

void RemoteFB__PSET02__P13__OpEncoder::encode__op_execute__a
                               (op_ctx_type&                       op_ctx,
                                const protocol::set02::PACKET_V02& packet)
{
 assert(packet.operation==protocol::set02::op_execute);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::arch_generic);

 const handles::RemoteFB__HandleData_Statement::self_ptr
  spStmtData
   (RemoteFB__GetService<handles::RemoteFB__HandleData_Statement>(op_ctx));

 assert(spStmtData);

 typedef RemoteFB__PSET02__P13__XDR__Encoder  xdr13;
 typedef RemoteFB__PSET02__XDR__Encoder       xdr;

 const protocol::set02::P_OP_SQLDATA* const p_sqldata=&packet.p_sqldata;

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

 if(p_sqldata->p_sqldata__messages>0)
 {
  assert(p_sqldata->p_sqldata__messages==1);

  assert(p_sqldata->p_sqldata__blr.cstr_length>0);

  xdr13::encode__sql_message
   (spBuf,
    spStmtData->m_InParams__MSG_DATA_DESCRS.size(),
    spStmtData->m_InParams__MSG_DATA_DESCRS.data(),
    spStmtData->m_InParams__MSG_DATA.size(),
    spStmtData->m_InParams__MSG_DATA.buffer(),
    spStmtData->m_InParams__MSG_NULLS.size(),
    spStmtData->m_InParams__MSG_NULLS.buffer());
 }//if
#ifndef NDEBUG
 else
 {
  assert(p_sqldata->p_sqldata__messages==0);

  assert(p_sqldata->p_sqldata__blr.cstr_length==0);

  assert(spStmtData->m_InParams__MSG_DATA.empty());

  assert(spStmtData->m_InParams__MSG_NULLS.empty());
 }//else
#endif
}//encode__op_execute__a

//------------------------------------------------------------------------
void RemoteFB__PSET02__P13__OpEncoder::encode__op_execute2__a
                               (op_ctx_type&                       op_ctx,
                                const protocol::set02::PACKET_V02& packet)
{
 assert(packet.operation==protocol::set02::op_execute2);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::arch_generic);

 const handles::RemoteFB__HandleData_Statement::self_ptr
  spStmtData
   (RemoteFB__GetService<handles::RemoteFB__HandleData_Statement>(op_ctx));

 assert(spStmtData);

 typedef RemoteFB__PSET02__P13__XDR__Encoder  xdr13;
 typedef RemoteFB__PSET02__XDR__Encoder       xdr;

 const protocol::set02::P_OP_SQLDATA* const p_sqldata=&packet.p_sqldata;

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

 if(p_sqldata->p_sqldata__messages>0)
 {
  assert(p_sqldata->p_sqldata__messages==1);

  assert(p_sqldata->p_sqldata__blr.cstr_length>0);

  xdr13::encode__sql_message
   (spBuf,
    spStmtData->m_InParams__MSG_DATA_DESCRS.size(),
    spStmtData->m_InParams__MSG_DATA_DESCRS.data(),
    spStmtData->m_InParams__MSG_DATA.size(),
    spStmtData->m_InParams__MSG_DATA.buffer(),
    spStmtData->m_InParams__MSG_NULLS.size(),
    spStmtData->m_InParams__MSG_NULLS.buffer());
 }//if
#ifndef NDEBUG
 else
 {
  assert(p_sqldata->p_sqldata__messages==0);

  assert(p_sqldata->p_sqldata__blr.cstr_length==0);

  assert(spStmtData->m_InParams__MSG_DATA.empty());

  assert(spStmtData->m_InParams__MSG_NULLS.empty());
 }//else
#endif

 xdr::encode__p_cstring_const
  (spBuf,
   &p_sqldata->p_sqldata__out_blr);

 xdr::encode__p_ushort_as_p_short
  (spBuf,
   &p_sqldata->p_sqldata__out_message_number);
}//encode__op_execute2__a

//------------------------------------------------------------------------
void RemoteFB__PSET02__P13__OpEncoder::encode__op_put_slice__a
                               (op_ctx_type&                        op_ctx,
                                const protocol::set02::PACKET_V02&  packet)
{
 assert(packet.operation==protocol::set02::op_put_slice);

 //-----------------------------------------
 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::arch_generic);

 //-----------------------------------------
 //можно было бы, конечно, восстановить описание массива из SDL (а так и было изначально),
 //но все таки лучше потребовать готовое описание от вызыващей стороны.

 const RemoteFB__OpSvc__GetArraySliceDescrPtr
  spGetDescr
   (RemoteFB__GetService<RemoteFB__OpSvc__GetArraySliceDescr>(op_ctx));

 assert(spGetDescr);

 //-----------------------------------------
 typedef RemoteFB__PSET02__P13__XDR__Encoder  xdr13;
 typedef RemoteFB__PSET02__XDR__Encoder       xdr;

 const protocol::set02::P_OP_PUT_SLC* const p_put_slc=&packet.p_put_slc;

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

 xdr13::encode__array_slice
  (spBuf,
   spGetDescr->GetArraySliceDescr(),
   p_put_slc->p_put_slc__slice.lstr_length,
   p_put_slc->p_put_slc__slice.lstr_address);
}//encode__op_put_slice__a

//------------------------------------------------------------------------
void RemoteFB__PSET02__P13__OpEncoder::encode__op_exec_immediate2__a
                               (op_ctx_type&                        op_ctx,
                                const protocol::set02::PACKET_V02&  packet)
{
 assert(packet.operation==protocol::set02::op_exec_immediate2);

 const RemoteFB__PortWriterPtr
  spBuf
   (RemoteFB__GetService<RemoteFB__PortWriter>(op_ctx));

 assert(spBuf);
 assert(spBuf->debug__get_protocol_architecture()==protocol::arch_generic);

 const handles::RemoteFB__HandleData_Statement::self_ptr
  spStmtData
   (RemoteFB__GetService<handles::RemoteFB__HandleData_Statement>(op_ctx));

 assert(spStmtData);

 typedef RemoteFB__PSET02__P13__XDR__Encoder  xdr13;
 typedef RemoteFB__PSET02__XDR__Encoder       xdr;

 const protocol::set02::P_OP_SQLST* const p_sqlst=&packet.p_sqlst;

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
  assert(!spStmtData->m_InParams__MSG_DATA.empty());

  assert(!spStmtData->m_InParams__MSG_DATA_DESCRS.empty());
  assert(!spStmtData->m_InParams__MSG_NULLS.empty());

  xdr13::encode__sql_message
   (spBuf,
    spStmtData->m_InParams__MSG_DATA_DESCRS.size(),
    spStmtData->m_InParams__MSG_DATA_DESCRS.data(),
    spStmtData->m_InParams__MSG_DATA.size(),
    spStmtData->m_InParams__MSG_DATA.buffer(),
    spStmtData->m_InParams__MSG_NULLS.size(),
    spStmtData->m_InParams__MSG_NULLS.buffer());
 }//if
#ifndef NDEBUG
 else
 {
  assert(p_sqlst->p_sqlst__messages==0);

  assert(p_sqlst->p_sqlst__blr.cstr_length==0);

  assert(spStmtData->m_InParams__MSG_DATA.empty());

  assert(spStmtData->m_InParams__MSG_DATA_DESCRS.empty());

  assert(spStmtData->m_InParams__MSG_NULLS.empty());
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
 // MAP(xdr_long, reinterpret_cast<SLONG&>(prep_stmt->p_sqlst_buffer_length));
 //  p_sqlst_buffer_length was USHORT in older versions
 // fixupLength(xdrs, prep_stmt->p_sqlst_buffer_length);

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

 xdr::encode__p_ulong_length_as_p_long__pset02
  (spBuf,
   &p_sqlst->p_sqlst__buffer_length);
}//encode__op_exec_immediate2__a

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
