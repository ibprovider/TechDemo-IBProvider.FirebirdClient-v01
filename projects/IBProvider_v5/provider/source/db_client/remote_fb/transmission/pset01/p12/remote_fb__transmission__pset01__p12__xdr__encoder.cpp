////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01__p12
//! \file    remote_fb__transmission__pset01__p12__xdr__encoder.cpp
//! \brief   ??????? ??? ???????? ?????? ? ??????? ?????.
//! \author  Kovalenko Dmitry
//! \date    10.05.2015.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset01/p12/remote_fb__transmission__pset01__p12__xdr__encoder.h"
#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__encoder.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__P12__XDR__Encoder::tag_blr_reader

class RemoteFB__PSET01__P12__XDR__Encoder::tag_blr_reader
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
};//class RemoteFB__PSET01__P12__XDR__Encoder::tag_blr_reader

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
 typedef RemoteFB__XDR__Encoder xdr;

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

     _VERIFY(structure::align_memory_size(offset,c_align));

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

      //[2015-05-16] ? ?????????? ?????? ????? ????????????? ?????? ??? ??????? ??????.
      assert_msg(false,"varchar_len: "<<varchar_len);

      t_ibp_error exc(E_FAIL,
                      ibp_mce_isc__bug_check__incorrect_varchar_data_length_1);

      exc<<varchar_len;

      exc.raise_me();
     }//if

     if(sqllen<size_t(varchar_len))
     {
      //ERROR - [BUG CHECK] incorrect varchar length

      //[2015-05-16] ? ?????????? ?????? ????? ????????????? ?????? ??? ??????? ??????.
      assert_msg(false,"varchar_len: "<<varchar_len<<". buf_size: "<<sqllen);

      t_ibp_error exc(E_FAIL,
                      ibp_mce_isc__bug_check__varchar_data_length_is_greater_than_buffer_size_2);

      exc<<varchar_len<<sqllen;

      exc.raise_me();
     }//if

     if(isc_api::ibp_isc_max_varchar_length<size_t(varchar_len))
     {
      //ERROR - [BUG CHECK] incorrect varchar length

      //[2015-05-16] ? ?????????? ?????? ????? ????????????? ?????? ??? ??????? ??????.
      assert_msg(false,"varchar_len: "<<varchar_len);

      t_ibp_error exc(E_FAIL,
                      ibp_mce_isc__bug_check__incorrect_varchar_data_length_1);

      exc<<varchar_len;

      exc.raise_me();
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

     _VERIFY(structure::align_memory_size(offset,c_align));

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

     _VERIFY(structure::align_memory_size(offset,c_align));

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

     _VERIFY(structure::align_memory_size(offset,c_align));

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

     _VERIFY(structure::align_memory_size(offset,c_align));

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

     _VERIFY(structure::align_memory_size(offset,c_align));

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

     _VERIFY(structure::align_memory_size(offset,c_align));

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

     _VERIFY(structure::align_memory_size(offset,c_align));

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

     _VERIFY(structure::align_memory_size(offset,c_align));

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

     _VERIFY(structure::align_memory_size(offset,c_align));

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

    default:
    {
     //ERROR - [BUG CHECK] unexpected typeID
     assert_msg(false,"typeID"<<int(typeID));

     t_ibp_error exc(E_FAIL,
                     ibp_mce_isc__unk_blr_data_type_1);

     exc<<typeID;

     exc.raise_me();
    }//default
   }//switch
  }
  catch(const std::exception& e)
  {
   t_ibp_error exc(e);

   exc.add_error(E_FAIL,
                 ibp_subsystem__remote_fb__p12,
                 ibp_mce_remote__encode_packet__xdr__error_in_element_of_msg_data_buffer_1);

   exc<<iElement;

   exc.raise_me();
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

//------------------------------------------------------------------------
void RemoteFB__PSET01__P12__XDR__Encoder::encode__array_slice
                                           (buf_type*                const pBuf,
                                            const asd_type&                ArrSliceDescr,
                                            size_t                   const slice_size,
                                            const protocol::P_UCHAR* const slice)
{
 assert(pBuf);

 CHECK_READ_TYPED_PTR(slice,slice_size)

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PSET01__P12__XDR__Encoder::encode__array_slice";

 //-----------------------------------------
 //????????
 //1. ????? ?????????? ?????????? ? ??? ???????????? ????????? ???????
 //
 //   ??? ????? ????? ?????????? SDL.
 //
 //   ?????????, ??? ???? ?? ????? ????????? ? ??????????? ???????????? ??????.
 //
 //2. ?????????? ???????? ??????? ? ???? ???????????

 //----------------------------------------- 1.
 if(ArrSliceDescr.m_element_total_length==0)
 {
  //ERROR - [BUG CHECK] ??????? ????? ????????

  RemoteFB__ErrorUtils::Throw_BugCheck__InvalidArray__ZeroSizeOfElement
   (c_bugcheck_src,
    L"#001",
    ArrSliceDescr.m_element_blr_typeid);
 }//if

 if((slice_size%ArrSliceDescr.m_element_total_length)!=0)
 {
  //ERROR - ??????????????? ??????? ?????? ? ???????? ???????

  t_ibp_error exc(E_FAIL,
                  ibp_mce_isc__bug_check__inconsistent_sizes_of_slice_and_element_5);

  exc<<c_bugcheck_src
     <<L"#002"
     <<slice_size
     <<ArrSliceDescr.m_element_total_length
     <<ArrSliceDescr.m_element_blr_typeid;

  exc.raise_me();
 }//if

 //const size_t nElements=slice_size/ArrSliceDescr.m_element_total_length;

 //-----------------------------------------
 typedef RemoteFB__XDR__Encoder xdr;

 assert_s(sizeof(protocol::P_UCHAR)==1);

 for(const protocol::P_UCHAR *pElement=slice,*_eElement=slice+slice_size;
     pElement!=_eElement;
     pElement+=ArrSliceDescr.m_element_total_length)
 {
  switch(ArrSliceDescr.m_element_blr_typeid)
  {
   case isc_api::ibp_isc_blr_dtype__short:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_SHORT));

    //????????? ????????????
    assert((reinterpret_cast<size_t>(pElement)%sizeof(protocol::P_SHORT))==0);

    xdr::encode__p_short
     (pBuf,
      reinterpret_cast<const protocol::P_SHORT*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__short

   case isc_api::ibp_isc_blr_dtype__long:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_LONG));

    //????????? ????????????
    assert((reinterpret_cast<size_t>(pElement)%sizeof(protocol::P_LONG))==0);

    xdr::encode__p_long
     (pBuf,
      reinterpret_cast<const protocol::P_LONG*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__long

   case isc_api::ibp_isc_blr_dtype__int64:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_INT64));

    //????????? ????????????. ? 32-?????? ????????? ????? ???? 4? ??????? ????????????.
    assert((reinterpret_cast<size_t>(pElement)%min(sizeof(protocol::P_INT64),sizeof(size_t)))==0);

    xdr::encode__p_int64
     (pBuf,
      reinterpret_cast<const protocol::P_INT64*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__int64

   case isc_api::ibp_isc_blr_dtype__float:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_FLOAT));

    //????????? ????????????
    assert((reinterpret_cast<size_t>(pElement)%sizeof(protocol::P_FLOAT))==0);

    xdr::encode__p_float
     (pBuf,
      reinterpret_cast<const protocol::P_FLOAT*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__float

   case isc_api::ibp_isc_blr_dtype__double:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_DOUBLE));

    //????????? ????????????
    assert((reinterpret_cast<size_t>(pElement)%min(sizeof(protocol::P_DOUBLE),sizeof(size_t)))==0);

    xdr::encode__p_double
     (pBuf,
      reinterpret_cast<const protocol::P_DOUBLE*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__double

   case isc_api::ibp_isc_blr_dtype__sql_time:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(isc_api::t_ibp_isc_time));

    //????????? ????????????
    assert((reinterpret_cast<size_t>(pElement)%sizeof(isc_api::t_ibp_isc_time))==0);

    xdr::encode__p_ulong_as_p_long
     (pBuf,
      reinterpret_cast<const isc_api::t_ibp_isc_time*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__sql_time

   case isc_api::ibp_isc_blr_dtype__sql_date:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(isc_api::t_ibp_isc_date));

    //????????? ????????????
    assert((reinterpret_cast<size_t>(pElement)%sizeof(isc_api::t_ibp_isc_date))==0);

    xdr::encode__p_long
     (pBuf,
      reinterpret_cast<const isc_api::t_ibp_isc_date*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__sql_date

   case isc_api::ibp_isc_blr_dtype__timestamp:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(isc_api::t_ibp_isc_timestamp));

    //????????? ????????????
    assert((reinterpret_cast<size_t>(&reinterpret_cast<const isc_api::t_ibp_isc_timestamp*>(pElement)->timestamp_date)%sizeof(isc_api::t_ibp_isc_date))==0);
    assert((reinterpret_cast<size_t>(&reinterpret_cast<const isc_api::t_ibp_isc_timestamp*>(pElement)->timestamp_time)%sizeof(isc_api::t_ibp_isc_time))==0);

    xdr::encode__p_long
     (pBuf,
      &reinterpret_cast<const isc_api::t_ibp_isc_timestamp*>(pElement)->timestamp_date);

    xdr::encode__p_ulong_as_p_long
     (pBuf,
      &reinterpret_cast<const isc_api::t_ibp_isc_timestamp*>(pElement)->timestamp_time);

    break;
   }//case - ibp_isc_blr_dtype__timestamp

   case isc_api::ibp_isc_blr_dtype__text2:
   {
    xdr::encode__opaque
     (pBuf,
      ArrSliceDescr.m_element_total_length,
      pElement);

    break;
   }//case ibp_isc_blr_dtype__text2

   default:
   {
    //ERROR - unknown blr data type

    t_ibp_error exc(E_FAIL,
                    ibp_mce_isc__bug_check__unknown_blr_data_type_3);

    exc<<c_bugcheck_src
       <<L"#003"
       <<ArrSliceDescr.m_element_blr_typeid;

    exc.raise_me();
   }//default
  }//switch ArrSliceDescr.m_element_blr_typeid
 }//for pElement
}//encode__array_slice

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
