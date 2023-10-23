////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02__p13
//! \file    remote_fb__transmission__pset02__p13__xdr__decoder.cpp
//! \brief   Утилиты для распаковки данных сетевого пакета.
//! \author  Kovalenko Dmitry
//! \date    20.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset02/p13/remote_fb__transmission__pset02__p13__xdr__decoder.h"
#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__decoder.h"
#include "source/db_client/remote_fb/remote_fb__msg_data_element_descr.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__P13__XDR__Decoder

void RemoteFB__PSET02__P13__XDR__Decoder::decode__sql_message
                                           (buf_type*          const pBuf,
                                            size_t             const msg_descrs_count,
                                            const mded_type*   const msg_descrs,
                                            size_t             const DEBUG_CODE(msg_data_size),
                                            protocol::P_UCHAR* const msg_data,
                                            size_t             const msg_nulls_size,
                                            protocol::P_UCHAR* const msg_nulls)
{
 assert(pBuf);

 CHECK_READ_TYPED_PTR(msg_descrs,msg_descrs_count);

 CHECK_WRITE_TYPED_PTR(msg_data,msg_data_size);

 CHECK_WRITE_TYPED_PTR(msg_nulls,msg_nulls_size);

 //-----------------------------------------------------------------------
 if(msg_descrs_count==0)
 {
  assert(msg_data_size==0);

  assert(msg_nulls_size==0);

  return;
 }//if msg_descrs_count==0

 assert(msg_descrs_count>0);

 assert(msg_data_size>0); //[2016-09-21]
 assert(msg_nulls_size>0);

 assert_s(CHAR_BIT==8);

#ifndef NDEBUG
 {
  const size_t ExpectedNullsBufferLength
   =((msg_descrs_count/8) + (((msg_descrs_count%8)!=0)?1:0));

  assert(ExpectedNullsBufferLength==msg_nulls_size);
 }//local
#endif

 //-----------------------------------------------------------------------
 using xdr=RemoteFB__XDR__Decoder;

 //-----------------------------------------------------------------------

 //загрузка битовой маски с NULL-состояниями значений
 xdr::decode__opaque
  (pBuf,
   L"sql_message.nulls",
   msg_nulls_size,
   msg_nulls);

 //-----------------------------------------------------------------------

 //перегрузка NULL-значений
 {
  size_t NullIndex=0;

  protocol::P_UCHAR NullMask=0x01;

  for(size_t iDescr=0;iDescr!=msg_descrs_count;++iDescr)
  {
   assert(NullIndex<msg_nulls_size);

   assert(NullMask==0x01 ||
          NullMask==0x02 ||
          NullMask==0x04 ||
          NullMask==0x08 ||
          NullMask==0x10 ||
          NullMask==0x20 ||
          NullMask==0x40 ||
          NullMask==0x80);

   //-----
   const mded_type& MsgElementDescr=msg_descrs[iDescr];

   assert(MsgElementDescr.m_msg_sqlind_offset<msg_data_size);

   assert(sizeof(protocol::P_SHORT)<=(msg_data_size-MsgElementDescr.m_msg_sqlind_offset));

   assert((reinterpret_cast<size_t>(msg_data+MsgElementDescr.m_msg_sqlind_offset)%isc_api::ibp_isc_type_align__short)==0);

   (*reinterpret_cast<protocol::P_SHORT*>(msg_data+MsgElementDescr.m_msg_sqlind_offset))
     =((msg_nulls[NullIndex]&NullMask)?-1:0);

   //-----
   if(NullMask!=0x80)
   {
    NullMask=(NullMask<<1);
   }
   else
   {
    NullMask=0x01;

    ++NullIndex;
   }//else
  }//for iDescr
 }//local

 //-----------------------------------------------------------------------
 for(size_t iDescr=0;iDescr!=msg_descrs_count;++iDescr)
 {
  const mded_type& MsgElementDescr=msg_descrs[iDescr];

  assert(MsgElementDescr.m_msg_sqlind_offset<msg_data_size);

  assert(sizeof(protocol::P_SHORT)<=(msg_data_size-MsgElementDescr.m_msg_sqlind_offset));

  assert((reinterpret_cast<size_t>(msg_data+MsgElementDescr.m_msg_sqlind_offset)%isc_api::ibp_isc_type_align__short)==0);

  if((*reinterpret_cast<protocol::P_SHORT*>(msg_data+MsgElementDescr.m_msg_sqlind_offset))==-1)
   continue;

  //мы только что установили значение этого индикатора
  assert((*reinterpret_cast<protocol::P_SHORT*>(msg_data+MsgElementDescr.m_msg_sqlind_offset))==0);

  const size_t offset=MsgElementDescr.m_msg_value_block_offset;

  assert(MsgElementDescr.m_msg_value_block_size<=msg_data_size);

  assert(offset<=(msg_data_size-MsgElementDescr.m_msg_value_block_size));

  try
  {
   switch(MsgElementDescr.m_msg_blrtype)
   {
    case isc_api::ibp_isc_blr_dtype__text:
    {
     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_text);

     const size_t sqllen=MsgElementDescr.m_msg_value_block_size;

     assert(sqllen<=msg_data_size);

     assert(offset<=(msg_data_size-sqllen));

     xdr::decode__opaque
      (pBuf,
       L"sql_message.text",
       sqllen,
       msg_data+offset);

     break;
    }//case ibp_isc_blr_dtype__text

    case isc_api::ibp_isc_blr_dtype__varying:
    {
     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_varying);

     assert(sizeof(isc_api::isc_varchar_size_type)<=MsgElementDescr.m_msg_value_block_size);

     const size_t sqllen=(MsgElementDescr.m_msg_value_block_size-sizeof(isc_api::isc_varchar_size_type));

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__varying;

     assert_s(c_align==sizeof(isc_api::isc_varchar_size_type));

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::isc_varchar_size_type)<=(msg_data_size-offset));

     assert(sqllen<=(msg_data_size-offset-sizeof(isc_api::isc_varchar_size_type)));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     //----
     isc_api::isc_varchar_size_type varchar_len;

     xdr::decode__p_short
      (pBuf,
       L"sql_message.varchar.len",
       &varchar_len);

     if(varchar_len<0)
     {
      //ERROR - [BUG CHECK] incorrect varchar length

      //assert_msg(false,"varchar_len: "<<varchar_len);

      IBP_ErrorUtils::Throw__Error
       (E_FAIL,
        ibp_mce_isc__bug_check__incorrect_varchar_data_length_1,
        varchar_len);
     }//if

     if(sqllen<size_t(varchar_len))
     {
      //ERROR - [BUG CHECK] incorrect varchar length

      //assert_msg(false,"varchar_len: "<<varchar_len<<". buf_size: "<<sqllen);

      IBP_ErrorUtils::Throw__Error
       (E_FAIL,
        ibp_mce_isc__bug_check__varchar_data_length_is_greater_than_buffer_size_2,
        varchar_len,
        sqllen);
     }//if

     if(isc_api::ibp_isc_max_varchar_length<size_t(varchar_len))
     {
      //ERROR - [BUG CHECK] incorrect varchar length

      //assert_msg(false,"varchar_len: "<<varchar_len);

      IBP_ErrorUtils::Throw__Error
       (E_FAIL,
        ibp_mce_isc__bug_check__incorrect_varchar_data_length_1,
        varchar_len);
     }//if

     assert(structure::can_numeric_cast<size_t>(varchar_len));

     (*reinterpret_cast<isc_api::isc_varchar_size_type*>(msg_data+offset))
      =varchar_len;

     xdr::decode__opaque
      (pBuf,
       L"sql_message.varchar.data",
       static_cast<size_t>(varchar_len),
       msg_data+offset+sizeof(isc_api::isc_varchar_size_type));

     break;
    }//ibp_isc_blr_dtype__varying

    case isc_api::ibp_isc_blr_dtype__short:
    {
     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_short);

     assert(MsgElementDescr.m_msg_value_block_size==sizeof(protocol::P_SHORT));

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__short;

     assert_s(c_align==sizeof(protocol::P_SHORT));

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_SHORT)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_short
      (pBuf,
       L"sql_message.short",
       reinterpret_cast<protocol::P_SHORT*>(msg_data+offset));

     break;
    }//ibp_isc_blr_dtype__short

    case isc_api::ibp_isc_blr_dtype__long:
    {
     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_long);

     assert(MsgElementDescr.m_msg_value_block_size==sizeof(protocol::P_LONG));

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__long;

     assert_s(c_align==sizeof(protocol::P_LONG));

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_LONG)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_long
      (pBuf,
       L"sql_message.long",
       reinterpret_cast<protocol::P_LONG*>(msg_data+offset));

     break;
    }//ibp_isc_blr_dtype__long

    case isc_api::ibp_isc_blr_dtype__int64:
    {
     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_int64);

     assert(MsgElementDescr.m_msg_value_block_size==sizeof(protocol::P_INT64));

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__int64;

     assert_s(c_align==sizeof(protocol::P_INT64));

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_INT64)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_int64
      (pBuf,
       L"sql_message.int64",
       reinterpret_cast<protocol::P_INT64*>(msg_data+offset));

     break;
    }//ibp_isc_blr_dtype__int64

    case isc_api::ibp_isc_blr_dtype__float:
    {
     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_float);

     assert(MsgElementDescr.m_msg_value_block_size==sizeof(protocol::P_FLOAT));

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__float;

     assert_s(c_align==sizeof(protocol::P_FLOAT));

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_FLOAT)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_float
      (pBuf,
       L"sql_message.float",
       reinterpret_cast<protocol::P_FLOAT*>(msg_data+offset));

     break;
    }//ibp_isc_blr_dtype__float

    case isc_api::ibp_isc_blr_dtype__double:
    {
     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_double);

     assert(MsgElementDescr.m_msg_value_block_size==sizeof(protocol::P_DOUBLE));

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__double;

     assert_s(c_align==sizeof(protocol::P_DOUBLE));

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_DOUBLE)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_double
      (pBuf,
       L"sql_message.double",
       reinterpret_cast<protocol::P_DOUBLE*>(msg_data+offset));

     break;
    }//ibp_isc_blr_dtype__double

    case isc_api::ibp_isc_blr_dtype__sql_time:
    {
     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_type_time);

     assert(MsgElementDescr.m_msg_value_block_size==sizeof(isc_api::t_ibp_isc_time));

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__time;

     assert_s(c_align==sizeof(isc_api::t_ibp_isc_time));

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_isc_time)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_ulong_as_p_long
      (pBuf,
       L"sql_message.sql_time",
       reinterpret_cast<isc_api::t_ibp_isc_time*>(msg_data+offset));

     break;
    }//ibp_isc_blr_dtype__sql_time

    case isc_api::ibp_isc_blr_dtype__sql_date:
    {
     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_type_date);

     assert(MsgElementDescr.m_msg_value_block_size==sizeof(isc_api::t_ibp_isc_date));

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__date;

     assert_s(c_align==sizeof(isc_api::t_ibp_isc_date));

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_isc_date)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_long
      (pBuf,
       L"sql_message.sql_date",
       reinterpret_cast<isc_api::t_ibp_isc_date*>(msg_data+offset));

     break;
    }//ibp_isc_blr_dtype__sql_date

    case isc_api::ibp_isc_blr_dtype__timestamp:
    {
     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_timestamp);

     assert(MsgElementDescr.m_msg_value_block_size==sizeof(isc_api::t_ibp_isc_timestamp));

     //----
#ifndef NDEBUG
     const size_t c_align=isc_api::ibp_isc_type_align__timestamp;
#endif

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_isc_timestamp)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_long
      (pBuf,
       L"sql_message.timestamp.date",
       &reinterpret_cast<isc_api::t_ibp_isc_timestamp*>(msg_data+offset)->timestamp_date);

     xdr::decode__p_ulong_as_p_long
      (pBuf,
       L"sql_message.timestamp.time",
       &reinterpret_cast<isc_api::t_ibp_isc_timestamp*>(msg_data+offset)->timestamp_time);

     break;
    }//ibp_isc_blr_dtype__timestamp

    case isc_api::ibp_isc_blr_dtype__quad:
    {
     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_blob ||
            MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_array);

     assert(MsgElementDescr.m_msg_value_block_size==sizeof(protocol::P_BID));

     //----
     assert_s(sizeof(db_obj::DB_IBQUAD)==sizeof(protocol::P_BID));

#ifndef NDEBUG
     const size_t c_align=isc_api::ibp_isc_type_align__quad;
#endif

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_BID)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_bid
      (pBuf,
       L"sql_message.quad.high",
       L"sql_message.quad.low",
       reinterpret_cast<protocol::P_BID*>(msg_data+offset));

     break;
    }//ibp_isc_blr_dtype__quad

    case isc_api::ibp_fb030_blr_dtype__bool:
    {
     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_fb030_sql_boolean);

     assert(MsgElementDescr.m_msg_value_block_size==sizeof(isc_api::t_ibp_fb030_bool));

     //----
     const size_t c_align=isc_api::ibp_fb030_type_align__bool;

     assert_s(c_align==sizeof(isc_api::t_ibp_fb030_bool));

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_fb030_bool)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__opaque
      (pBuf,
       L"sql_message.boolean",
       sizeof(isc_api::t_ibp_fb030_bool),
       msg_data+offset);

     break;
    }//case ibp_fb030_blr_dtype__bool

    case isc_api::ibp_fb040_blr_dtype__int128:
    {
     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_fb040_sql_int128);

     assert(MsgElementDescr.m_msg_value_block_size==sizeof(protocol::P_INT128));

     //----
     const size_t c_align=isc_api::ibp_fb040_type_align__int128;

     assert_s(c_align==sizeof(protocol::P_INT128().data.low));
     assert_s(c_align==sizeof(protocol::P_INT128().data.high));

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_INT128)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_int128
      (pBuf,
       L"sql_message.int128.data.low",
       L"sql_message.int128.data.high",
       reinterpret_cast<protocol::P_INT128*>(msg_data+offset));

     break;
    }//ibp_fb040_blr_dtype__int128

    case isc_api::ibp_fb040_blr_dtype__decfloat16:
    {
     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_fb040_sql_decfloat16);

     assert(MsgElementDescr.m_msg_value_block_size==sizeof(protocol::P_DECFLOAT16));

     //----
     const size_t c_align=isc_api::ibp_fb040_type_align__decfloat16;

     assert_s(c_align==sizeof(protocol::P_DECFLOAT16().value));

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_DECFLOAT16)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_decfloat16
      (pBuf,
       L"sql_message.decfloat16.value",
       reinterpret_cast<protocol::P_DECFLOAT16*>(msg_data+offset));

     break;
    }//ibp_fb040_blr_dtype__decfloat16

    case isc_api::ibp_fb040_blr_dtype__decfloat34:
    {
     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_fb040_sql_decfloat34);

     assert(MsgElementDescr.m_msg_value_block_size==sizeof(protocol::P_DECFLOAT34));

     //----
     const size_t c_align=isc_api::ibp_fb040_type_align__decfloat34;

     assert_s(c_align==sizeof(protocol::P_DECFLOAT34().data.low));
     assert_s(c_align==sizeof(protocol::P_DECFLOAT34().data.high));

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_DECFLOAT34)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_decfloat34
      (pBuf,
       L"sql_message.decfloat34.data.low",
       L"sql_message.decfloat34.data.high",
       reinterpret_cast<protocol::P_DECFLOAT34*>(msg_data+offset));

     break;
    }//ibp_fb040_blr_dtype__decfloat34

    case isc_api::ibp_fb040_blr_dtype__timestamp_with_tz:
    {
     using value_type=isc_api::t_ibp_fb040_timestamp_with_tz;

     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_fb040_sql_timestamp_with_tz);

     assert(MsgElementDescr.m_msg_value_block_size==sizeof(value_type));

     //----
#ifndef NDEBUG
     const size_t c_align=isc_api::ibp_fb040_type_align__timestamp_with_tz;
#endif

     assert((offset%c_align)==0);

     assert(sizeof(value_type)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__fb040_timestamp_with_tz
      (pBuf,
       L"sql_message.timestamp_with_tz.utc_date",
       L"sql_message.timestamp_with_tz.utc_time",
       L"sql_message.timestamp_with_tz.time_zone",
       reinterpret_cast<value_type*>(msg_data+offset));

     break;
    }//ibp_fb040_blr_dtype__timestamp_with_tz

    case isc_api::ibp_fb040_blr_dtype__time_with_tz:
    {
     using value_type=isc_api::t_ibp_fb040_time_with_tz;

     assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_fb040_sql_time_with_tz);

     assert(MsgElementDescr.m_msg_value_block_size==sizeof(value_type));

     //----
#ifndef NDEBUG
     const size_t c_align=isc_api::ibp_fb040_type_align__time_with_tz;
#endif

     assert((offset%c_align)==0);

     assert(sizeof(value_type)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__fb040_time_with_tz
      (pBuf,
       L"sql_message.time_with_tz.utc_time",
       L"sql_message.time_with_tz.time_zone",
       reinterpret_cast<value_type*>(msg_data+offset));

     break;
    }//ibp_fb040_blr_dtype__time_with_tz

    default:
    {
     //ERROR - [BUG CHECK] unexpected typeID
     assert_msg(false,"typeID: "<<unsigned(MsgElementDescr.m_msg_blrtype));

     IBP_ErrorUtils::Throw__Error
      (E_FAIL,
       ibp_mce_isc__unk_blr_data_type_1,
       MsgElementDescr.m_msg_blrtype);
    }//default
   }//switch
  }
  catch(const std::exception& e)
  {
   IBP_ErrorUtils::Throw__Error
    (e,
     E_FAIL,
     ibp_subsystem__remote_fb__p13,
     ibp_mce_remote__decode_packet__xdr__error_in_element_of_msg_data_buffer_1,
     iDescr);
  }//catch
 }//for iDescr
}//decode__sql_message

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
