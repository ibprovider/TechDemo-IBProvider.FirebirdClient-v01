////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01__p12
//! \file    remote_fb__transmission__pset01__p12__xdr__encoder.cpp
//! \brief   ������� ��� �������� ������ � ������� �����.
//! \author  Kovalenko Dmitry
//! \date    10.05.2015.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset01/p12/remote_fb__transmission__pset01__p12__xdr__encoder.h"
#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__encoder.h"
#include "source/db_client/remote_fb/remote_fb__blr_reader_v1.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__P12__XDR__Encoder

void RemoteFB__PSET01__P12__XDR__Encoder::encode__sql_message
                                           (buf_type*                const pBuf,
                                            size_t                   const msg_blr_size,
                                            const protocol::P_UCHAR* const msg_blr,
                                            size_t                   const DEBUG_CODE(msg_data_size),
                                            const protocol::P_UCHAR* const msg_data)
{
 assert(pBuf);

 CHECK_READ_TYPED_PTR(msg_blr,msg_blr_size);

 CHECK_READ_TYPED_PTR(msg_data,msg_data_size);

 //-----------------------------------------------------------------------
 if(msg_blr_size==0)
 {
  assert(msg_data_size==0);

  return;
 }//if

 //-----------------------------------------------------------------------
 using xdr=RemoteFB__XDR__Encoder;

 RemoteFB__BlrReader_v1 blr_reader(msg_blr_size,msg_blr);

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

 size_t offset=0;

 for(size_t iElement=0;iElement!=cPars;++iElement)
 {
  assert(offset<=msg_data_size);

  try
  {
   switch(const protocol::P_UCHAR typeID=blr_reader.read())
   {
    case isc_api::ibp_isc_blr_dtype__text:
    {
     const size_t sqllen=blr_reader.read_word();

     assert(sqllen<=msg_data_size);

     assert(offset<=(msg_data_size-sqllen));

     xdr::encode__opaque
      (pBuf,
       sqllen,
       msg_data+offset);

     offset+=sqllen;

     break;
    }//case ibp_isc_blr_dtype__text

    case isc_api::ibp_isc_blr_dtype__varying:
    {
     const size_t sqllen=blr_reader.read_word();

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__varying;

     assert_s(c_align==sizeof(isc_api::isc_varchar_size_type));

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::isc_varchar_size_type)<=(msg_data_size-offset));

     assert(sqllen<=(msg_data_size-offset-sizeof(isc_api::isc_varchar_size_type)));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     const isc_api::isc_varchar_size_type
      varchar_len=*reinterpret_cast<const isc_api::isc_varchar_size_type*>(msg_data+offset);

     if(varchar_len<0)
     {
      //ERROR - [BUG CHECK] incorrect varchar length

      //[2015-05-16] � ���������� ������ ����� ������������� ������ ��� ������� �����.
      assert_msg(false,"varchar_len: "<<varchar_len);

      IBP_ErrorUtils::Throw__Error
       (E_FAIL,
        ibp_mce_isc__bug_check__incorrect_varchar_data_length_1,
        varchar_len);
     }//if

     if(sqllen<size_t(varchar_len))
     {
      //ERROR - [BUG CHECK] incorrect varchar length

      //[2015-05-16] � ���������� ������ ����� ������������� ������ ��� ������� �����.
      assert_msg(false,"varchar_len: "<<varchar_len<<". buf_size: "<<sqllen);

      IBP_ErrorUtils::Throw__Error
       (E_FAIL,
        ibp_mce_isc__bug_check__varchar_data_length_is_greater_than_buffer_size_2,
        varchar_len,
        sqllen);
     }//if

     if(isc_api::ibp_isc_max_varchar_length<size_t(varchar_len))
     {
      //ERROR - [BUG CHECK] incorrect varchar length

      //[2015-05-16] � ���������� ������ ����� ������������� ������ ��� ������� �����.
      assert_msg(false,"varchar_len: "<<varchar_len);

      IBP_ErrorUtils::Throw__Error
      (E_FAIL,
       ibp_mce_isc__bug_check__incorrect_varchar_data_length_1,
       varchar_len);
     }//if

     offset+=sizeof(isc_api::isc_varchar_size_type);

     xdr::encode__p_short
      (pBuf,
       &varchar_len);

     xdr::encode__opaque
      (pBuf,
       varchar_len,
       msg_data+offset);

     offset+=sqllen;

     break;
    }//ibp_isc_blr_dtype__varying

    case isc_api::ibp_isc_blr_dtype__short:
    {
     blr_reader.next(); //sqlscale

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__short;

     assert_s(c_align==sizeof(protocol::P_SHORT));

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_SHORT)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::encode__p_short
      (pBuf,
       reinterpret_cast<const protocol::P_SHORT*>(msg_data+offset));

     offset+=sizeof(protocol::P_SHORT);

     break;
    }//ibp_isc_blr_dtype__short

    case isc_api::ibp_isc_blr_dtype__long:
    {
     blr_reader.next(); //sqlscale

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__long;

     assert_s(c_align==sizeof(protocol::P_LONG));

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_LONG)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::encode__p_long
      (pBuf,
       reinterpret_cast<const protocol::P_LONG*>(msg_data+offset));

     offset+=sizeof(protocol::P_LONG);

     break;
    }//ibp_isc_blr_dtype__long

    case isc_api::ibp_isc_blr_dtype__int64:
    {
     blr_reader.next(); //sqlscale

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__int64;

     assert_s(c_align==sizeof(protocol::P_INT64));

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_INT64)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::encode__p_int64
      (pBuf,
       reinterpret_cast<const protocol::P_INT64*>(msg_data+offset));

     offset+=sizeof(protocol::P_INT64);

     break;
    }//ibp_isc_blr_dtype__int64

    case isc_api::ibp_isc_blr_dtype__float:
    {
     const size_t c_align=isc_api::ibp_isc_type_align__float;

     assert_s(c_align==sizeof(protocol::P_FLOAT));

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_FLOAT)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::encode__p_float
      (pBuf,
       reinterpret_cast<const protocol::P_FLOAT*>(msg_data+offset));

     offset+=sizeof(protocol::P_FLOAT);

     break;
    }//ibp_isc_blr_dtype__float

    case isc_api::ibp_isc_blr_dtype__double:
    {
     const size_t c_align=isc_api::ibp_isc_type_align__double;

     assert_s(c_align==sizeof(protocol::P_DOUBLE));

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_DOUBLE)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::encode__p_double
      (pBuf,
       reinterpret_cast<const protocol::P_DOUBLE*>(msg_data+offset));

     offset+=sizeof(protocol::P_DOUBLE);

     break;
    }//ibp_isc_blr_dtype__double

    case isc_api::ibp_isc_blr_dtype__sql_time:
    {
     const size_t c_align=isc_api::ibp_isc_type_align__time;

     assert_s(c_align==sizeof(isc_api::t_ibp_isc_time));

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_isc_time)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::encode__p_ulong_as_p_long
      (pBuf,
       reinterpret_cast<const isc_api::t_ibp_isc_time*>(msg_data+offset));

     offset+=sizeof(isc_api::t_ibp_isc_time);

     break;
    }//ibp_isc_blr_dtype__sql_time

    case isc_api::ibp_isc_blr_dtype__sql_date:
    {
     const size_t c_align=isc_api::ibp_isc_type_align__date;

     assert_s(c_align==sizeof(isc_api::t_ibp_isc_date));

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_isc_date)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::encode__p_long
      (pBuf,
       reinterpret_cast<const isc_api::t_ibp_isc_date*>(msg_data+offset));

     offset+=sizeof(isc_api::t_ibp_isc_date);

     break;
    }//ibp_isc_blr_dtype__sql_date

    case isc_api::ibp_isc_blr_dtype__timestamp:
    {
     const size_t c_align=isc_api::ibp_isc_type_align__timestamp;

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_isc_timestamp)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::encode__p_long
      (pBuf,
       &reinterpret_cast<const isc_api::t_ibp_isc_timestamp*>(msg_data+offset)->timestamp_date);

     xdr::encode__p_ulong_as_p_long
      (pBuf,
       &reinterpret_cast<const isc_api::t_ibp_isc_timestamp*>(msg_data+offset)->timestamp_time);

     offset+=sizeof(isc_api::t_ibp_isc_timestamp);

     break;
    }//ibp_isc_blr_dtype__timestamp

    case isc_api::ibp_isc_blr_dtype__quad:
    {
     blr_reader.next(); //sqlscale

     //----
     assert_s(sizeof(db_obj::DB_IBQUAD)==sizeof(protocol::P_BID));

     const size_t c_align=isc_api::ibp_isc_type_align__quad;

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_BID)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::encode__p_bid
      (pBuf,
       reinterpret_cast<const protocol::P_BID*>(msg_data+offset));

     offset+=sizeof(protocol::P_BID);

     break;
    }//ibp_isc_blr_dtype__quad

    case isc_api::ibp_fb030_blr_dtype__bool:
    {
     assert_s(sizeof(isc_api::t_ibp_fb030_bool)==1);

     const size_t c_align=isc_api::ibp_fb030_type_align__bool;

     assert_s(c_align==sizeof(isc_api::t_ibp_fb030_bool));

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_fb030_bool)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

      xdr::encode__opaque
       (pBuf,
        sizeof(isc_api::t_ibp_fb030_bool),
        msg_data+offset);

     offset+=sizeof(isc_api::t_ibp_fb030_bool);

     break;
    }//ibp_fb030_blr_dtype__bool

    case isc_api::ibp_fb040_blr_dtype__int128:
    {
     blr_reader.next(); //sqlscale

     //----
     const size_t c_align=isc_api::ibp_fb040_type_align__int128;

     assert_s(c_align==sizeof(protocol::P_INT128().data.low));
     assert_s(c_align==sizeof(protocol::P_INT128().data.high));

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_INT128)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::encode__p_int128
      (pBuf,
       reinterpret_cast<const protocol::P_INT128*>(msg_data+offset));

     offset+=sizeof(protocol::P_INT128);

     break;
    }//ibp_fb040_blr_dtype__int128

    case isc_api::ibp_fb040_blr_dtype__decfloat16:
    {
     assert_s(sizeof(isc_api::t_ibp_fb040_decfloat16)==8);

     const size_t c_align=isc_api::ibp_fb040_type_align__decfloat16;

     assert_s(c_align==sizeof(isc_api::t_ibp_fb040_decfloat16));

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_fb040_decfloat16)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     assert_s(std::is_same<protocol::P_DECFLOAT16 LCPI__LITER_COMMA isc_api::t_ibp_fb040_decfloat16>::value);

     xdr::encode__p_decfloat16
      (pBuf,
       reinterpret_cast<const protocol::P_DECFLOAT16*>(msg_data+offset));

     offset+=sizeof(isc_api::t_ibp_fb040_decfloat16);

     break;
    }//ibp_fb040_blr_dtype__decfloat16

    case isc_api::ibp_fb040_blr_dtype__decfloat34:
    {
     assert_s(sizeof(isc_api::t_ibp_fb040_decfloat34)==16);

     const size_t c_align=isc_api::ibp_fb040_type_align__decfloat34;

     assert_s(c_align==sizeof(isc_api::t_ibp_fb040_decfloat34().data.low));
     assert_s(c_align==sizeof(isc_api::t_ibp_fb040_decfloat34().data.high));

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_fb040_decfloat34)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     assert_s(std::is_same<protocol::P_DECFLOAT34 LCPI__LITER_COMMA isc_api::t_ibp_fb040_decfloat34>::value);

     xdr::encode__p_decfloat34
      (pBuf,
       reinterpret_cast<const protocol::P_DECFLOAT34*>(msg_data+offset));

     offset+=sizeof(isc_api::t_ibp_fb040_decfloat34);

     break;
    }//ibp_fb040_blr_dtype__decfloat34

    case isc_api::ibp_fb040_blr_dtype__timestamp_with_tz:
    {
     using value_type=isc_api::t_ibp_fb040_timestamp_with_tz;

     const size_t c_align=isc_api::ibp_fb040_type_align__timestamp_with_tz;

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(value_type)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::encode__fb040_timestamp_with_tz
      (pBuf,
       reinterpret_cast<const value_type*>(msg_data+offset));

     offset+=sizeof(value_type);

     break;
    }//ibp_fb040_blr_dtype__timestamp_with_tz

    case isc_api::ibp_fb040_blr_dtype__time_with_tz:
    {
     using value_type=isc_api::t_ibp_fb040_time_with_tz;

     const size_t c_align=isc_api::ibp_fb040_type_align__time_with_tz;

     _VERIFY(lib::structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(value_type)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::encode__fb040_time_with_tz
      (pBuf,
       reinterpret_cast<const value_type*>(msg_data+offset));

     offset+=sizeof(value_type);

     break;
    }//ibp_fb040_blr_dtype__time_with_tz

    default:
    {
     //ERROR - [BUG CHECK] unexpected typeID
     assert_msg(false,"typeID: "<<int(typeID));

     IBP_ErrorUtils::Throw__Error
      (E_FAIL,
       ibp_mce_isc__unk_blr_data_type_1,
       typeID);
    }//default
   }//switch
  }
  catch(const std::exception& e)
  {
   IBP_ErrorUtils::Throw__Error
    (e,
     E_FAIL,
     ibp_subsystem__remote_fb__p12,
     ibp_mce_remote__encode_packet__xdr__error_in_element_of_msg_data_buffer_1,
     iElement);
  }//catch
 }//for[ever]

 assert(offset==msg_data_size);

 MSG_BLR__SKIP_TAG(end);
 MSG_BLR__SKIP_TAG(eoc);

 assert(blr_reader.debug__eof());

 //-----------------------------------------------------------------------
 #undef MSG_BLR__SKIP_TAG
 #undef MSG_BLR__SKIP_BYTE
}//encode__sql_message

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
