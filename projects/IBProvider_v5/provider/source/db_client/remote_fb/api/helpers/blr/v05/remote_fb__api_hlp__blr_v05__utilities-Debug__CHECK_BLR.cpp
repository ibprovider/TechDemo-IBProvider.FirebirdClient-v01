////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__blr_v05__utilities-Calc_BLR_MAX_XDR_SIZE.cpp
//! \brief   Utilities for work with BLR (v05).
//! \author  Kovalenko Dmitry
//! \date    18.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/blr/v05/remote_fb__api_hlp__blr_v05__utilities.h"
#include "source/db_client/remote_fb/remote_fb__msg_data_element_descr.h"
#include "source/db_client/remote_fb/remote_fb__blr_reader_v1.h"
#include "source/db_obj/isc_base/isc_api.h"
#include "source/ibp_memory_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__BLR_V05__Utilities

#ifndef NDEBUG

void RemoteFB__API_HLP__BLR_V05__Utilities::Debug__CHECK_BLR
                                           (const IBP_BufferView<const byte_type>&  msg_blr,
                                            const IBP_BufferView<const descr_type>& msg_descrs,
                                            const IBP_BufferView<const byte_type>&  msg_data,
                                            size_t                            const msg_data_align)
{
 CHECK_READ_TYPED_PTR(msg_blr.data(),msg_blr.size());
 CHECK_READ_TYPED_PTR(msg_descrs.data(),msg_descrs.size());

 //-----------------------------------------------------------------------
 if(msg_blr.empty())
 {
  assert_msg(msg_descrs.empty(),"msg_descrs.size: "<<msg_descrs.size());
  assert_msg(msg_data.empty(),"msg_data.size: "<<msg_data.size());

  assert_msg(msg_data_align==1,"msg_data_align: "<<msg_data_align);

  return;
 }//if

 assert(!msg_blr.empty());
 assert(msg_blr.size()>0);

 assert(msg_data_align>0);

 //-----------------------------------------------------------------------
 RemoteFB__BlrReader_v1 blr_reader(msg_blr.size(),msg_blr.data());

 //-----------------------------------------------------------------------
 #define MSG_BLR__SKIP_BYTE(value)                    \
 {                                                    \
  assert(blr_reader.cur()==(value));                  \
  blr_reader.next();                                  \
 }

 #define MSG_BLR__SKIP_TAG(tag)                       \
  MSG_BLR__SKIP_BYTE(isc_api::ibp_isc_blr_##tag)

 //-----------------------------------------------------------------------
 MSG_BLR__SKIP_TAG(version5);
 MSG_BLR__SKIP_TAG(begin);
 MSG_BLR__SKIP_TAG(message);
 MSG_BLR__SKIP_BYTE(0)  //message number?

 const size_t cPars=blr_reader.read_word();

 assert((cPars%2)==0);

 assert((cPars/2)==msg_descrs.size());

 //---------------------------
 const auto msg_data_size=msg_data.size();
 const auto msg_data_ptr =msg_data.data();

 size_t offset=0;

 size_t expectedAlign=1;

 for(size_t iElement=0;iElement!=msg_descrs.size();++iElement)
 {
  const auto& current_descr=msg_descrs[iElement];

  {
   assert(offset<=msg_data_size);

   //--------------------------
   const protocol::P_UCHAR curret_data_blr_typeID=blr_reader.read();

   assert(current_descr.m_msg_blrtype==curret_data_blr_typeID);

   //--------------------------
   switch(curret_data_blr_typeID)
   {
    case isc_api::ibp_isc_blr_dtype__text:
    {
     assert(current_descr.m_xvar_sqltype==isc_api::ibp_isc_sql_text ||
            current_descr.m_xvar_sqltype==isc_api::ibp_fb025_sql_null);

     //----
     assert(current_descr.m_msg_value_block_offset==offset);

     const size_t sqllen=blr_reader.read_word();

     assert(sqllen<=msg_data_size);

     assert(current_descr.m_msg_value_block_size==sqllen);

     assert(offset<=(msg_data_size-sqllen));

     offset+=sqllen;

     assert(offset<=msg_data_size);

     break;
    }//case ibp_isc_blr_dtype__text

    case isc_api::ibp_isc_blr_dtype__varying:
    {
     assert(current_descr.m_xvar_sqltype==isc_api::ibp_isc_sql_varying);

     //----
     const size_t sqllen=blr_reader.read_word();

     assert(sqllen<=msg_data_size);

     assert(current_descr.m_msg_value_block_size==sqllen+sizeof(isc_api::isc_varchar_size_type));

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__varying;

     assert_s(c_align==sizeof(isc_api::isc_varchar_size_type));

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

     assert(current_descr.m_msg_value_block_offset==offset);

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::isc_varchar_size_type)<=(msg_data_size-offset));

     assert(sqllen<=(msg_data_size-offset-sizeof(isc_api::isc_varchar_size_type)));

     assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

     //----
     offset+=sizeof(isc_api::isc_varchar_size_type);
     offset+=sqllen;

     assert(offset<=msg_data_size);

     break;
    }//ibp_isc_blr_dtype__varying

    case isc_api::ibp_isc_blr_dtype__short:
    {
     assert(current_descr.m_xvar_sqltype==isc_api::ibp_isc_sql_short);

     assert(current_descr.m_msg_value_block_size==sizeof(db_obj::t_dbvalue__i2));

     {
      signed __int8 const s=(signed __int8)blr_reader.cur(); //sqlscale

      assert(s==0 || s<0);
      assert(s>=-db_obj::dbprecision__isc_numeric_on_smallint);

      assert(current_descr.m_xvar_sqlscale==s);
     }//local

     //----
     blr_reader.next(); //sqlscale

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__short;

     assert_s(c_align==sizeof(protocol::P_SHORT));

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

     assert(current_descr.m_msg_value_block_offset==offset);

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_SHORT)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

     offset+=sizeof(protocol::P_SHORT);

     assert(offset<=msg_data_size);

     break;
    }//ibp_isc_blr_dtype__short

    case isc_api::ibp_isc_blr_dtype__long:
    {
     assert(current_descr.m_xvar_sqltype==isc_api::ibp_isc_sql_long);

     assert(current_descr.m_msg_value_block_size==sizeof(db_obj::t_dbvalue__i4));

     {
      signed __int8 const s=(signed __int8)blr_reader.cur(); //sqlscale

      assert(s==0 || s<0);
      assert(s>=-db_obj::dbprecision__isc_numeric_on_integer);

      assert(current_descr.m_xvar_sqlscale==s);
     }//local

     //----
     blr_reader.next(); //sqlscale

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__long;

     assert_s(c_align==sizeof(protocol::P_LONG));

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

     assert(current_descr.m_msg_value_block_offset==offset);

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_LONG)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

     offset+=sizeof(protocol::P_LONG);

     assert(offset<=msg_data_size);

     break;
    }//ibp_isc_blr_dtype__long

    case isc_api::ibp_isc_blr_dtype__int64:
    {
     assert(current_descr.m_xvar_sqltype==isc_api::ibp_isc_sql_int64);

     assert(current_descr.m_msg_value_block_size==sizeof(db_obj::t_dbvalue__i8));

     {
      signed __int8 const s=(signed __int8)blr_reader.cur(); //sqlscale

      assert(s==0 || s<0);
      assert(s>=-db_obj::dbprecision__isc_numeric_on_int64);

      assert(current_descr.m_xvar_sqlscale==s);
     }//local

     //----
     blr_reader.next(); //sqlscale

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__int64;

     assert_s(c_align==sizeof(protocol::P_INT64));

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

     assert(current_descr.m_msg_value_block_offset==offset);

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_INT64)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

     offset+=sizeof(protocol::P_INT64);

     assert(offset<=msg_data_size);

     break;
    }//ibp_isc_blr_dtype__int64

    case isc_api::ibp_isc_blr_dtype__float:
    {
     assert(current_descr.m_xvar_sqltype==isc_api::ibp_isc_sql_float);

     assert(current_descr.m_msg_value_block_size==sizeof(db_obj::t_dbvalue__r4));

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__float;

     assert_s(c_align==sizeof(protocol::P_FLOAT));

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

     assert(current_descr.m_msg_value_block_offset==offset);

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_FLOAT)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

     offset+=sizeof(protocol::P_FLOAT);

     assert(offset<=msg_data_size);

     break;
    }//ibp_isc_blr_dtype__float

    case isc_api::ibp_isc_blr_dtype__double:
    {
     assert(current_descr.m_xvar_sqltype==isc_api::ibp_isc_sql_double);

     assert(current_descr.m_msg_value_block_size==sizeof(db_obj::t_dbvalue__r8));

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__double;

     assert_s(c_align==sizeof(protocol::P_DOUBLE));

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

     assert(current_descr.m_msg_value_block_offset==offset);

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_DOUBLE)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

     offset+=sizeof(protocol::P_DOUBLE);

     assert(offset<=msg_data_size);

     break;
    }//ibp_isc_blr_dtype__double

    case isc_api::ibp_isc_blr_dtype__sql_time:
    {
     assert(current_descr.m_xvar_sqltype==isc_api::ibp_isc_sql_type_time);

     assert(current_descr.m_msg_value_block_size==sizeof(db_obj::t_dbvalue__isc_time));

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__time;

     assert_s(c_align==sizeof(isc_api::t_ibp_isc_time));

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

     assert(current_descr.m_msg_value_block_offset==offset);

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_isc_time)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

     offset+=sizeof(isc_api::t_ibp_isc_time);

     assert(offset<=msg_data_size);

     break;
    }//ibp_isc_blr_dtype__sql_time

    case isc_api::ibp_isc_blr_dtype__sql_date:
    {
     assert(current_descr.m_xvar_sqltype==isc_api::ibp_isc_sql_type_date);

     assert(current_descr.m_msg_value_block_size==sizeof(db_obj::t_dbvalue__isc_date));

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__date;

     assert_s(c_align==sizeof(isc_api::t_ibp_isc_date));

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

     assert(current_descr.m_msg_value_block_offset==offset);

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_isc_date)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

     offset+=sizeof(isc_api::t_ibp_isc_date);

     assert(offset<=msg_data_size);

     break;
    }//ibp_isc_blr_dtype__sql_date

    case isc_api::ibp_isc_blr_dtype__timestamp:
    {
     assert(current_descr.m_xvar_sqltype==isc_api::ibp_isc_sql_timestamp);

     assert(current_descr.m_msg_value_block_size==sizeof(db_obj::t_dbvalue__isc_timestamp));

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__timestamp;

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

     assert(current_descr.m_msg_value_block_offset==offset);

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_isc_timestamp)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

     offset+=sizeof(isc_api::t_ibp_isc_timestamp);

     assert(offset<=msg_data_size);

     break;
    }//ibp_isc_blr_dtype__timestamp

    case isc_api::ibp_isc_blr_dtype__quad:
    {
     assert(current_descr.m_xvar_sqltype==isc_api::ibp_isc_sql_blob ||
            current_descr.m_xvar_sqltype==isc_api::ibp_isc_sql_array);

     assert(current_descr.m_msg_value_block_size==sizeof(db_obj::DB_IBQUAD));

     //----
     blr_reader.next(); //sqlscale

     //----
     assert_s(sizeof(db_obj::DB_IBQUAD)==sizeof(protocol::P_BID));

     const size_t c_align=isc_api::ibp_isc_type_align__quad;

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

     assert(current_descr.m_msg_value_block_offset==offset);

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_BID)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

     offset+=sizeof(protocol::P_BID);

     assert(offset<=msg_data_size);

     break;
    }//ibp_isc_blr_dtype__quad

    case isc_api::ibp_fb030_blr_dtype__bool:
    {
     assert(current_descr.m_xvar_sqltype==isc_api::ibp_fb030_sql_boolean);

     assert(current_descr.m_msg_value_block_size==sizeof(isc_api::t_ibp_fb030_bool));

     //----
     assert_s(sizeof(isc_api::t_ibp_fb030_bool)==1);

     const size_t c_align=isc_api::ibp_fb030_type_align__bool;

     assert_s(c_align==sizeof(isc_api::t_ibp_fb030_bool));

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

     assert(current_descr.m_msg_value_block_offset==offset);

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_fb030_bool)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

     offset+=sizeof(isc_api::t_ibp_fb030_bool);

     assert(offset<=msg_data_size);

     break;
    }//ibp_fb030_blr_dtype__bool

    case isc_api::ibp_fb040_blr_dtype__int128:
    {
     assert_s(std::is_same<db_obj::t_dbvalue__fb040_int128 _LITER_COMMA_ isc_api::t_ibp_fb040_int128>::value);
     assert_s(std::is_same<db_obj::t_dbvalue__fb040_int128 _LITER_COMMA_ protocol::P_INT128>::value);

     assert(current_descr.m_xvar_sqltype==isc_api::ibp_fb040_sql_int128);

     assert(current_descr.m_msg_value_block_size==sizeof(isc_api::t_ibp_fb040_int128));

     {
      signed __int8 const s=(signed __int8)blr_reader.cur(); //sqlscale

      assert(s==0 || s<0);
      assert(s>=-db_obj::dbprecision__fb040_numeric_on_int128);

      assert(current_descr.m_xvar_sqlscale==s);
     }//local

     //----
     blr_reader.next(); //sqlscale

     //----
     const size_t c_align=isc_api::ibp_fb040_type_align__int128;

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

     assert(current_descr.m_msg_value_block_offset==offset);

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_fb040_int128)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

     offset+=sizeof(isc_api::t_ibp_fb040_int128);

     assert(offset<=msg_data_size);

     break;
    }//ibp_fb040_blr_dtype__int128

    case isc_api::ibp_fb040_blr_dtype__decfloat16:
    {
     assert(current_descr.m_xvar_sqltype==isc_api::ibp_fb040_sql_decfloat16);

     assert(current_descr.m_msg_value_block_size==sizeof(isc_api::t_ibp_fb040_decfloat16));

     //----
     assert_s(sizeof(isc_api::t_ibp_fb040_decfloat16)==8);

     const size_t c_align=isc_api::ibp_fb040_type_align__decfloat16;

     assert_s(c_align==sizeof(isc_api::t_ibp_fb040_decfloat16));

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

     assert(current_descr.m_msg_value_block_offset==offset);

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_fb040_decfloat16)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

     offset+=sizeof(isc_api::t_ibp_fb040_decfloat16);

     assert(offset<=msg_data_size);

     break;
    }//ibp_fb040_blr_dtype__decfloat16

    case isc_api::ibp_fb040_blr_dtype__decfloat34:
    {
     assert(current_descr.m_xvar_sqltype==isc_api::ibp_fb040_sql_decfloat34);

     assert(current_descr.m_msg_value_block_size==sizeof(isc_api::t_ibp_fb040_decfloat34));

     //----
     assert_s(sizeof(isc_api::t_ibp_fb040_decfloat34)==16);

     const size_t c_align=isc_api::ibp_fb040_type_align__decfloat34;

     assert_s(c_align==sizeof(isc_api::t_ibp_fb040_decfloat34().data.low));
     assert_s(c_align==sizeof(isc_api::t_ibp_fb040_decfloat34().data.high));

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

     assert(current_descr.m_msg_value_block_offset==offset);

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_fb040_decfloat34)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

     offset+=sizeof(isc_api::t_ibp_fb040_decfloat34);

     assert(offset<=msg_data_size);

     break;
    }//ibp_fb040_blr_dtype__decfloat34

    case isc_api::ibp_fb040_blr_dtype__timestamp_with_tz:
    {
     assert(current_descr.m_xvar_sqltype==isc_api::ibp_fb040_sql_timestamp_with_tz);

     assert_s(std::is_same<db_obj::t_dbvalue__fb040_timestamp_with_tz LCPI__LITER_COMMA isc_api::t_ibp_fb040_timestamp_with_tz>::value);

     assert(current_descr.m_msg_value_block_size==sizeof(isc_api::t_ibp_fb040_timestamp_with_tz));

     //----
     const size_t c_align=isc_api::ibp_fb040_type_align__timestamp_with_tz;

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

     assert(current_descr.m_msg_value_block_offset==offset);

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_fb040_timestamp_with_tz)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

     offset+=sizeof(isc_api::t_ibp_fb040_timestamp_with_tz);

     assert(offset<=msg_data_size);

     break;
    }//ibp_fb040_blr_dtype__timestamp_with_tz

    default:
    {
     //ERROR - [BUG CHECK] unexpected typeID
     assert_msg(false,"curret_data_blr_typeID: "<<int(curret_data_blr_typeID));
    }//default
   }//switch curret_data_blr_typeID
  }//local

  //---------------------------------------- check indicator data
  {
   const protocol::P_UCHAR curret_ind_blr_typeID=blr_reader.read();

   assert(curret_ind_blr_typeID==isc_api::ibp_isc_blr_dtype__short);

   //--------------------------
   blr_reader.next(); //sqlscale

   //----
   const size_t c_align=isc_api::ibp_isc_type_align__short;

   assert_s(c_align==sizeof(protocol::P_SHORT));

     offset
      =IBP_Memory_Utils::AlignMemLength
       (offset,
        c_align,
        &expectedAlign);

   assert(current_descr.m_msg_sqlind_offset==offset);

   assert(offset<=msg_data_size);

   assert((offset%c_align)==0);

   assert(sizeof(protocol::P_SHORT)<=(msg_data_size-offset));

   assert((reinterpret_cast<size_t>(msg_data_ptr+offset)%c_align)==0);

   offset+=sizeof(protocol::P_SHORT);

   assert(offset<=msg_data_size);
  }//local
 }//for iElement

 assert_msg
  (msg_data_size==offset,
   "msg_data_size="<<msg_data_size<<" "
   "offset="<<offset);

 assert_msg
  (msg_data_align==expectedAlign,
   "msg_data_align="<<msg_data_align<<" "
   "expectedAlign="<<expectedAlign);

 MSG_BLR__SKIP_TAG(end);
 MSG_BLR__SKIP_TAG(eoc);

 assert(blr_reader.debug__eof());

 //-----------------------------------------------------------------------
 #undef MSG_BLR__SKIP_TAG
 #undef MSG_BLR__SKIP_BYTE
}//Debug__CHECK_BLR

#endif // !NDEBUG

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
