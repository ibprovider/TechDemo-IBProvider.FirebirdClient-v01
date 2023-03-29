////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01__p12
//! \file    remote_fb__transmission__pset01__p12__xdr__decoder.cpp
//! \brief   ������� ��� ���������� ������ �������� ������.
//! \author  Kovalenko Dmitry
//! \date    27.05.2015.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset01/p12/remote_fb__transmission__pset01__p12__xdr__decoder.h"
#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__decoder.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__P12__XDR__Decoder::tag_blr_reader

class RemoteFB__PSET01__P12__XDR__Decoder::tag_blr_reader
{
 private:
  typedef tag_blr_reader self_type;

  tag_blr_reader(const self_type&);
  self_type& operator = (const self_type&);

 public:
  tag_blr_reader(size_t                   const DEBUG_CODE(msg_blr_size),
                 const protocol::P_UCHAR* const msg_blr)
   :m_ptr(msg_blr)
  #ifndef NDEBUG
   ,m_end(msg_blr+msg_blr_size)
  #endif
  {;}

  //interface -------------------------------------------------------------
#ifndef NDEBUG
  bool debug__eof()const
  {
   return m_ptr==m_end;
  }//debug__eof
#endif

  protocol::P_UCHAR cur()const
  {
   assert(m_ptr<m_end);

   return *m_ptr;
  }//cur

  protocol::P_UCHAR read()
  {
   assert(m_ptr<m_end);

   const protocol::P_UCHAR result=*m_ptr;

   ++m_ptr;

   return result;
  }//read

  protocol::P_USHORT read_word()
  {
   protocol::P_USHORT result=this->read();

   result+=protocol::P_USHORT(protocol::P_USHORT(this->read())<<8);

   return result;
  }//read_word

  void next()
  {
   assert(m_ptr<m_end);

   ++m_ptr;
  }//next

 private:
  const protocol::P_UCHAR*       m_ptr;
 #ifndef NDEBUG
  const protocol::P_UCHAR* const m_end;
 #endif
};//class RemoteFB__PSET01__P12__XDR__Decoder::tag_blr_reader

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__P12__XDR__Decoder

void RemoteFB__PSET01__P12__XDR__Decoder::decode__sql_message
                                           (buf_type*                const pBuf,
                                            size_t                   const msg_blr_size,
                                            const protocol::P_UCHAR* const msg_blr,
                                            size_t                   const DEBUG_CODE(msg_data_size),
                                            protocol::P_UCHAR*       const msg_data)
{
 assert(pBuf);

 CHECK_READ_TYPED_PTR(msg_blr,msg_blr_size);

 CHECK_WRITE_TYPED_PTR(msg_data,msg_data_size);

 //-----------------------------------------------------------------------
 if(msg_blr_size==0)
 {
  assert(msg_data_size==0);

  return;
 }//if

 //-----------------------------------------------------------------------
 typedef RemoteFB__XDR__Decoder xdr;

 tag_blr_reader blr_reader(msg_blr_size,msg_blr);

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

     xdr::decode__opaque
      (pBuf,
       L"sql_message.text",
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

     _VERIFY(structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

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

     offset+=sizeof(isc_api::isc_varchar_size_type);

     xdr::decode__opaque
      (pBuf,
       L"sql_message.varchar.data",
       static_cast<size_t>(varchar_len),
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

     _VERIFY(structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_SHORT)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_short
      (pBuf,
       L"sql_message.short",
       reinterpret_cast<protocol::P_SHORT*>(msg_data+offset));

     offset+=sizeof(protocol::P_SHORT);

     break;
    }//ibp_isc_blr_dtype__short

    case isc_api::ibp_isc_blr_dtype__long:
    {
     blr_reader.next(); //sqlscale

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__long;

     assert_s(c_align==sizeof(protocol::P_LONG));

     _VERIFY(structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_LONG)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_long
      (pBuf,
       L"sql_message.long",
       reinterpret_cast<protocol::P_LONG*>(msg_data+offset));

     offset+=sizeof(protocol::P_LONG);

     break;
    }//ibp_isc_blr_dtype__long

    case isc_api::ibp_isc_blr_dtype__int64:
    {
     blr_reader.next(); //sqlscale

     //----
     const size_t c_align=isc_api::ibp_isc_type_align__int64;

     assert_s(c_align==sizeof(protocol::P_INT64));

     _VERIFY(structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_INT64)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_int64
      (pBuf,
       L"sql_message.int64",
       reinterpret_cast<protocol::P_INT64*>(msg_data+offset));

     offset+=sizeof(protocol::P_INT64);

     break;
    }//ibp_isc_blr_dtype__int64

    case isc_api::ibp_isc_blr_dtype__float:
    {
     const size_t c_align=isc_api::ibp_isc_type_align__float;

     assert_s(c_align==sizeof(protocol::P_FLOAT));

     _VERIFY(structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_FLOAT)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_float
      (pBuf,
       L"sql_message.float",
       reinterpret_cast<protocol::P_FLOAT*>(msg_data+offset));

     offset+=sizeof(protocol::P_FLOAT);

     break;
    }//ibp_isc_blr_dtype__float

    case isc_api::ibp_isc_blr_dtype__double:
    {
     const size_t c_align=isc_api::ibp_isc_type_align__double;

     assert_s(c_align==sizeof(protocol::P_DOUBLE));

     _VERIFY(structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_DOUBLE)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_double
      (pBuf,
       L"sql_message.double",
       reinterpret_cast<protocol::P_DOUBLE*>(msg_data+offset));

     offset+=sizeof(protocol::P_DOUBLE);

     break;
    }//ibp_isc_blr_dtype__double

    case isc_api::ibp_isc_blr_dtype__sql_time:
    {
     const size_t c_align=isc_api::ibp_isc_type_align__time;

     assert_s(c_align==sizeof(isc_api::t_ibp_isc_time));

     _VERIFY(structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_isc_time)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_ulong_as_p_long
      (pBuf,
       L"sql_message.sql_time",
       reinterpret_cast<isc_api::t_ibp_isc_time*>(msg_data+offset));

     offset+=sizeof(isc_api::t_ibp_isc_time);

     break;
    }//ibp_isc_blr_dtype__sql_time

    case isc_api::ibp_isc_blr_dtype__sql_date:
    {
     const size_t c_align=isc_api::ibp_isc_type_align__date;

     assert_s(c_align==sizeof(isc_api::t_ibp_isc_date));

     _VERIFY(structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(isc_api::t_ibp_isc_date)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_long
      (pBuf,
       L"sql_message.sql_date",
       reinterpret_cast<isc_api::t_ibp_isc_date*>(msg_data+offset));

     offset+=sizeof(isc_api::t_ibp_isc_date);

     break;
    }//ibp_isc_blr_dtype__sql_date

    case isc_api::ibp_isc_blr_dtype__timestamp:
    {
     const size_t c_align=isc_api::ibp_isc_type_align__timestamp;

     _VERIFY(structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

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

     offset+=sizeof(isc_api::t_ibp_isc_timestamp);

     break;
    }//ibp_isc_blr_dtype__timestamp

    case isc_api::ibp_isc_blr_dtype__quad:
    {
     blr_reader.next(); //sqlscale

     //----
     assert_s(sizeof(db_obj::DB_IBQUAD)==sizeof(protocol::P_BID));

     const size_t c_align=isc_api::ibp_isc_type_align__quad;

     _VERIFY(structure::align_memory_size(offset,c_align));

     assert(offset<=msg_data_size);

     assert((offset%c_align)==0);

     assert(sizeof(protocol::P_BID)<=(msg_data_size-offset));

     assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

     xdr::decode__p_bid
      (pBuf,
       L"sql_message.quad.high",
       L"sql_message.quad.low",
       reinterpret_cast<protocol::P_BID*>(msg_data+offset));

     offset+=sizeof(protocol::P_BID);

     break;
    }//ibp_isc_blr_dtype__quad

    default:
    {
     //ERROR - [BUG CHECK] unexpected typeID
     assert_msg(false,"typeID"<<int(typeID));

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
     ibp_mce_remote__decode_packet__xdr__error_in_element_of_msg_data_buffer_1,
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
}//decode__sql_message

//------------------------------------------------------------------------
void RemoteFB__PSET01__P12__XDR__Decoder::decode__array_slice
                                           (buf_type*          const pBuf,
                                            const asd_type&          ArrSliceDescr,
                                            size_t             const szSlice,
                                            protocol::P_UCHAR* const pSlice)
{
 assert(pBuf);

 CHECK_WRITE_TYPED_PTR(pSlice,szSlice);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PSET01__P12__XDR__Decoder::decode__array_slice";

 //-----------------------------------------
 if(ArrSliceDescr.m_element_total_length==0)
 {
  //ERROR - [BUG CHECK] ������� ����� �������� �������

  RemoteFB__ErrorUtils::Throw_BugCheck__InvalidArray__ZeroSizeOfElement
   (c_bugcheck_src,
    L"#001",
    ArrSliceDescr.m_element_blr_typeid);
 }//if

 if((szSlice%ArrSliceDescr.m_element_total_length)!=0)
 {
  //ERROR - [BUG CHECK] ��������������� ������� ������ � �������� �������

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_isc__bug_check__inconsistent_sizes_of_slice_and_element_5,
    c_bugcheck_src,
    L"#002",
    szSlice,
    ArrSliceDescr.m_element_total_length,
    ArrSliceDescr.m_element_blr_typeid);
 }//if

 //-----------------------------------------
 typedef RemoteFB__XDR__Decoder xdr;

 //-----------------------------------------
 assert_s(sizeof(protocol::P_UCHAR)==1);

 protocol::P_UCHAR* pElement=pSlice;

 protocol::P_UCHAR* _eElement=pSlice+szSlice;

 try
 {
  for(;pElement!=_eElement;pElement+=ArrSliceDescr.m_element_total_length)
  {
   switch(ArrSliceDescr.m_element_blr_typeid)
   {
    case isc_api::ibp_isc_blr_dtype__short:
    {
     typedef protocol::P_SHORT              value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%sizeof(value_type))==0);

     xdr::decode__p_short
      (pBuf,
       L"array_slice.short",
       reinterpret_cast<value_type*>(pElement));

     break;
    }//case - ibp_isc_blr_dtype__short

    case isc_api::ibp_isc_blr_dtype__long:
    {
     typedef protocol::P_LONG               value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%sizeof(value_type))==0);

     xdr::decode__p_long
      (pBuf,
       L"array_slice.long",
       reinterpret_cast<value_type*>(pElement));

     break;
    }//case - ibp_isc_blr_dtype__long

    case isc_api::ibp_isc_blr_dtype__int64:
    {
     typedef protocol::P_INT64              value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%min(sizeof(value_type),sizeof(size_t)))==0);

     xdr::decode__p_int64
      (pBuf,
       L"array_slice.int64",
       reinterpret_cast<value_type*>(pElement));

     break;
    }//case - ibp_isc_blr_dtype__int64

    case isc_api::ibp_isc_blr_dtype__float:
    {
     typedef protocol::P_FLOAT              value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%sizeof(value_type))==0);

     xdr::decode__p_float
      (pBuf,
       L"array_slice.float",
       reinterpret_cast<value_type*>(pElement));

     break;
    }//case - ibp_isc_blr_dtype__float

    case isc_api::ibp_isc_blr_dtype__double:
    {
     typedef protocol::P_DOUBLE             value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%min(sizeof(value_type),sizeof(size_t)))==0);

     xdr::decode__p_double
      (pBuf,
       L"array_slice.double",
       reinterpret_cast<value_type*>(pElement));

     break;
    }//case - ibp_isc_blr_dtype__double

    case isc_api::ibp_isc_blr_dtype__sql_date:
    {
     typedef isc_api::t_ibp_isc_date        value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%sizeof(value_type))==0);

     xdr::decode__p_long
      (pBuf,
       L"array_slice.sql_date",
       reinterpret_cast<value_type*>(pElement));

     break;
    }//case - ibp_isc_blr_dtype__sql_date

    case isc_api::ibp_isc_blr_dtype__sql_time:
    {
     typedef isc_api::t_ibp_isc_time        value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%sizeof(value_type))==0);

     xdr::decode__p_ulong_as_p_long
      (pBuf,
       L"array_slice.sql_time",
       reinterpret_cast<value_type*>(pElement));

     break;
    }//case - ibp_isc_blr_dtype__sql_time

    case isc_api::ibp_isc_blr_dtype__timestamp:
    {
     typedef isc_api::t_ibp_isc_timestamp   value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(&reinterpret_cast<value_type*>(pElement)->timestamp_date)%sizeof(isc_api::t_ibp_isc_date))==0);
     assert((reinterpret_cast<size_t>(&reinterpret_cast<value_type*>(pElement)->timestamp_time)%sizeof(isc_api::t_ibp_isc_time))==0);

     xdr::decode__p_long
      (pBuf,
       L"array_slice.timestamp.date",
       &reinterpret_cast<value_type*>(pElement)->timestamp_date);

     xdr::decode__p_ulong_as_p_long
      (pBuf,
       L"array_slice.timestamp.time",
       &reinterpret_cast<value_type*>(pElement)->timestamp_time);

     break;
    }//case - ibp_isc_blr_dtype__timestamp

    case isc_api::ibp_isc_blr_dtype__text2:
    {
     xdr::decode__opaque
      (pBuf,
       L"array_slice.text2",
       ArrSliceDescr.m_element_total_length,
       pElement);

     break;
    }//isc_api::ibp_isc_blr_dtype__text2

    default:
    {
     //ERROR - [BUG CHECK] unexpected typeID
     assert_msg(false,"typeID"<<int(ArrSliceDescr.m_element_blr_typeid));

     IBP_ErrorUtils::Throw__Error
      (E_FAIL,
       ibp_mce_isc__unk_blr_data_type_1,
       ArrSliceDescr.m_element_blr_typeid);
    }//default
   }//switch
  }//for[ever]
 }
 catch(const std::exception& e)
 {
  //��������� ���������� � ���������� ������ �������� �������

  IBP_ErrorUtils::Throw__Error
   (e,
    E_FAIL,
    ibp_subsystem__remote_fb__p12,
    ibp_mce_remote__decode_packet__xdr__error_in_element_of_slice_data_buffer_1,
    size_t(pElement-pSlice));
 }//catch
}//decode__array_slice

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
