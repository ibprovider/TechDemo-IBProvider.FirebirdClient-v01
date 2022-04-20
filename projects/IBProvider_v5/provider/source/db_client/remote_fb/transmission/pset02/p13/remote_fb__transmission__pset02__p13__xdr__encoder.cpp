////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02__p13
//! \file    remote_fb__transmission__pset02__p13__xdr__encoder.cpp
//! \brief   Утилиты для упаковки данных в сетевой пакет.
//! \author  Kovalenko Dmitry
//! \date    20.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset02/p13/remote_fb__transmission__pset02__p13__xdr__encoder.h"
#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__encoder.h"
#include "source/db_client/remote_fb/remote_fb__msg_data_element_descr.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__P13__XDR__Encoder

void RemoteFB__PSET02__P13__XDR__Encoder::encode__sql_message
                                           (buf_type*                const pBuf,
                                            size_t                   const msg_descrs_count,
                                            const mded_type*         const msg_descrs,
                                            size_t                   const DEBUG_CODE(msg_data_size),
                                            const protocol::P_UCHAR* const msg_data,
                                            size_t                   const msg_nulls_size,
                                            const protocol::P_UCHAR* const msg_nulls)
{
 assert(pBuf);

 CHECK_READ_TYPED_PTR(msg_descrs,msg_descrs_count);

 CHECK_READ_TYPED_PTR(msg_data,msg_data_size);

 CHECK_READ_TYPED_PTR(msg_nulls,msg_nulls_size);

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

#ifndef NDEBUG
 {
  assert(CHAR_BIT==8);

  const size_t ExpectedNullsBufferLength
   =((msg_descrs_count/8) + (((msg_descrs_count%8)!=0)?1:0));

  assert(ExpectedNullsBufferLength==msg_nulls_size);
 }//local
#endif

 //-----------------------------------------------------------------------
 typedef RemoteFB__XDR__Encoder xdr;

 //-----------------------------------------------------------------------
 //передаем массив с флагами NULL-состояний значений

 xdr::encode__opaque
  (pBuf,
   msg_nulls_size,
   msg_nulls);

 //-----------------------------------------------------------------------
 size_t NullIndex=0;

 unsigned char NullMask=0x01;

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

  if((msg_nulls[NullIndex]&NullMask)==0)
  {
   try
   {
    const mded_type& MsgElementDescr=msg_descrs[iDescr];

    const size_t offset=MsgElementDescr.m_msg_value_block_offset;

    switch(MsgElementDescr.m_msg_blrtype)
    {
     case isc_api::ibp_isc_blr_dtype__text:
     {
      assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_text ||
             MsgElementDescr.m_xvar_sqltype==isc_api::ibp_fb25_sql_null);

      const size_t sqllen=MsgElementDescr.m_msg_value_block_size;

      assert(sqllen<=msg_data_size);

      assert(offset<=(msg_data_size-sqllen));

      xdr::encode__opaque
       (pBuf,
        sqllen,
        msg_data+offset);

      break;
     }//case ibp_isc_blr_dtype__text

     case isc_api::ibp_isc_blr_dtype__varying:
     {
      assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_varying);

      assert(sizeof(isc_api::isc_varchar_size_type)<=MsgElementDescr.m_msg_value_block_size);

      const size_t sqllen=MsgElementDescr.m_msg_value_block_size-sizeof(isc_api::isc_varchar_size_type);

      const size_t c_align=isc_api::ibp_isc_type_align__varying;

      assert_s(c_align==sizeof(isc_api::isc_varchar_size_type));

      assert(offset<=msg_data_size);

      assert((offset%c_align)==0);

      assert(MsgElementDescr.m_msg_value_block_size<=(msg_data_size-offset));

      assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

      const isc_api::isc_varchar_size_type
       varchar_len=*reinterpret_cast<const isc_api::isc_varchar_size_type*>(msg_data+offset);

      if(varchar_len<0)
      {
       //ERROR - [BUG CHECK] incorrect varchar length

       //[2015-05-16] В отладочной сборке будем останавливать работу для разбора полёта.
       assert_msg(false,"varchar_len: "<<varchar_len);

       t_ibp_error exc(E_FAIL,
                       ibp_mce_isc__bug_check__incorrect_varchar_data_length_1);

       exc<<varchar_len;

       exc.raise_me();
      }//if

      if(sqllen<size_t(varchar_len))
      {
       //ERROR - [BUG CHECK] incorrect varchar length

       //[2015-05-16] В отладочной сборке будем останавливать работу для разбора полёта.
       assert_msg(false,"varchar_len: "<<varchar_len<<". buf_size: "<<sqllen);

       t_ibp_error exc(E_FAIL,
                       ibp_mce_isc__bug_check__varchar_data_length_is_greater_than_buffer_size_2);

       exc<<varchar_len<<sqllen;

       exc.raise_me();
      }//if

      if(isc_api::ibp_isc_max_varchar_length<size_t(varchar_len))
      {
       //ERROR - [BUG CHECK] incorrect varchar length

       //[2015-05-16] В отладочной сборке будем останавливать работу для разбора полёта.
       assert_msg(false,"varchar_len: "<<varchar_len);

       t_ibp_error exc(E_FAIL,
                       ibp_mce_isc__bug_check__incorrect_varchar_data_length_1);

       exc<<varchar_len;

       exc.raise_me();
      }//if

      xdr::encode__p_short
       (pBuf,
        &varchar_len);

      xdr::encode__opaque
       (pBuf,
        varchar_len,
        msg_data+offset+sizeof(isc_api::isc_varchar_size_type));

      break;
     }//ibp_isc_blr_dtype__varying

     case isc_api::ibp_isc_blr_dtype__short:
     {
      assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_short);

      assert(MsgElementDescr.m_msg_value_block_size==sizeof(protocol::P_SHORT));

      const size_t c_align=isc_api::ibp_isc_type_align__short;

      assert_s(c_align==sizeof(protocol::P_SHORT));

      assert(offset<=msg_data_size);

      assert((offset%c_align)==0);

      assert(sizeof(protocol::P_SHORT)<=(msg_data_size-offset));

      assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

      xdr::encode__p_short
       (pBuf,
        reinterpret_cast<const protocol::P_SHORT*>(msg_data+offset));

      break;
     }//ibp_isc_blr_dtype__short

     case isc_api::ibp_isc_blr_dtype__long:
     {
      assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_long);

      assert(MsgElementDescr.m_msg_value_block_size==sizeof(protocol::P_LONG));

      const size_t c_align=isc_api::ibp_isc_type_align__long;

      assert_s(c_align==sizeof(protocol::P_LONG));

      assert(offset<=msg_data_size);

      assert((offset%c_align)==0);

      assert(sizeof(protocol::P_LONG)<=(msg_data_size-offset));

      assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

      xdr::encode__p_long
       (pBuf,
        reinterpret_cast<const protocol::P_LONG*>(msg_data+offset));

      break;
     }//ibp_isc_blr_dtype__long

     case isc_api::ibp_isc_blr_dtype__int64:
     {
      assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_int64);

      assert(MsgElementDescr.m_msg_value_block_size==sizeof(protocol::P_INT64));

      const size_t c_align=isc_api::ibp_isc_type_align__int64;

      assert_s(c_align==sizeof(protocol::P_INT64));

      assert(offset<=msg_data_size);

      assert((offset%c_align)==0);

      assert(sizeof(protocol::P_INT64)<=(msg_data_size-offset));

      assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

      xdr::encode__p_int64
       (pBuf,
        reinterpret_cast<const protocol::P_INT64*>(msg_data+offset));

      break;
     }//ibp_isc_blr_dtype__int64

     case isc_api::ibp_isc_blr_dtype__float:
     {
      assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_float);

      assert(MsgElementDescr.m_msg_value_block_size==sizeof(protocol::P_FLOAT));

      const size_t c_align=isc_api::ibp_isc_type_align__float;

      assert_s(c_align==sizeof(protocol::P_FLOAT));

      assert(offset<=msg_data_size);

      assert((offset%c_align)==0);

      assert(sizeof(protocol::P_FLOAT)<=(msg_data_size-offset));

      assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

      xdr::encode__p_float
       (pBuf,
        reinterpret_cast<const protocol::P_FLOAT*>(msg_data+offset));

      break;
     }//ibp_isc_blr_dtype__float

     case isc_api::ibp_isc_blr_dtype__double:
     {
      assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_double);

      assert(MsgElementDescr.m_msg_value_block_size==sizeof(protocol::P_DOUBLE));

      const size_t c_align=isc_api::ibp_isc_type_align__double;

      assert_s(c_align==sizeof(protocol::P_DOUBLE));

      assert(offset<=msg_data_size);

      assert((offset%c_align)==0);

      assert(sizeof(protocol::P_DOUBLE)<=(msg_data_size-offset));

      assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

      xdr::encode__p_double
       (pBuf,
        reinterpret_cast<const protocol::P_DOUBLE*>(msg_data+offset));

      break;
     }//ibp_isc_blr_dtype__double

     case isc_api::ibp_isc_blr_dtype__sql_time:
     {
      assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_type_time);

      assert(MsgElementDescr.m_msg_value_block_size==sizeof(isc_api::t_ibp_isc_time));

      const size_t c_align=isc_api::ibp_isc_type_align__time;

      assert_s(c_align==sizeof(isc_api::t_ibp_isc_time));

      assert(offset<=msg_data_size);

      assert((offset%c_align)==0);

      assert(sizeof(isc_api::t_ibp_isc_time)<=(msg_data_size-offset));

      assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

      xdr::encode__p_ulong_as_p_long
       (pBuf,
        reinterpret_cast<const isc_api::t_ibp_isc_time*>(msg_data+offset));

      break;
     }//ibp_isc_blr_dtype__sql_time

     case isc_api::ibp_isc_blr_dtype__sql_date:
     {
      assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_type_date);

      assert(MsgElementDescr.m_msg_value_block_size==sizeof(isc_api::t_ibp_isc_date));

      const size_t c_align=isc_api::ibp_isc_type_align__date;

      assert_s(c_align==sizeof(isc_api::t_ibp_isc_date));

      assert(offset<=msg_data_size);

      assert((offset%c_align)==0);

      assert(sizeof(isc_api::t_ibp_isc_date)<=(msg_data_size-offset));

      assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

      xdr::encode__p_long
       (pBuf,
        reinterpret_cast<const isc_api::t_ibp_isc_date*>(msg_data+offset));

      break;
     }//ibp_isc_blr_dtype__sql_date

     case isc_api::ibp_isc_blr_dtype__timestamp:
     {
      assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_timestamp);

      assert(MsgElementDescr.m_msg_value_block_size==sizeof(isc_api::t_ibp_isc_timestamp));

#ifndef NDEBUG
      const size_t c_align=isc_api::ibp_isc_type_align__timestamp;
#endif

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

      break;
     }//ibp_isc_blr_dtype__timestamp

     case isc_api::ibp_isc_blr_dtype__quad:
     {
      assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_blob ||
             MsgElementDescr.m_xvar_sqltype==isc_api::ibp_isc_sql_array);

      assert(MsgElementDescr.m_msg_value_block_size==sizeof(protocol::P_BID));

      assert_s(sizeof(db_obj::DB_IBQUAD)==sizeof(protocol::P_BID));

#ifndef NDEBUG
      const size_t c_align=isc_api::ibp_isc_type_align__quad;
#endif

      assert(offset<=msg_data_size);

      assert((offset%c_align)==0);

      assert(sizeof(protocol::P_BID)<=(msg_data_size-offset));

      assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

      xdr::encode__p_bid
       (pBuf,
        reinterpret_cast<const protocol::P_BID*>(msg_data+offset));

      break;
     }//ibp_isc_blr_dtype__quad

     case isc_api::ibp_fb30_blr_dtype__bool:
     {
      assert(MsgElementDescr.m_xvar_sqltype==isc_api::ibp_fb30_sql_boolean);

      assert(MsgElementDescr.m_msg_value_block_size==sizeof(isc_api::t_ibp_fb30_bool));

      const size_t c_align=isc_api::ibp_fb30_type_align__bool;

      assert_s(c_align==sizeof(isc_api::t_ibp_fb30_bool));

      assert(offset<=msg_data_size);

      assert((offset%c_align)==0);

      assert(sizeof(isc_api::t_ibp_fb30_bool)<=(msg_data_size-offset));

      assert((reinterpret_cast<size_t>(msg_data+offset)%c_align)==0);

      xdr::encode__opaque
       (pBuf,
        sizeof(isc_api::t_ibp_fb30_bool),
        msg_data+offset);

      break;
     }//ibp_fb30_blr_dtype__bool

     default:
     {
      //ERROR - [BUG CHECK] unexpected typeID
      assert_msg(false,"typeID"<<unsigned(MsgElementDescr.m_msg_blrtype));

      t_ibp_error exc(E_FAIL,
                      ibp_mce_isc__unk_blr_data_type_1);

      exc<<MsgElementDescr.m_msg_blrtype;

      exc.raise_me();
     }//default
    }//switch
   }
   catch(const std::exception& e)
   {
    t_ibp_error exc(e);

    exc.add_error(E_FAIL,
                  ibp_subsystem__remote_fb__p13,
                  ibp_mce_remote__encode_packet__xdr__error_in_element_of_msg_data_buffer_1);

    exc<<(2*iDescr);

    exc.raise_me();
   }//catch
  }//if not null value

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
}//encode__sql_message

//------------------------------------------------------------------------
void RemoteFB__PSET02__P13__XDR__Encoder::encode__array_slice
                                           (buf_type*                const pBuf,
                                            const asd_type&                ArrSliceDescr,
                                            size_t                   const slice_size,
                                            const protocol::P_UCHAR* const slice)
{
 assert(pBuf);

 CHECK_READ_TYPED_PTR(slice,slice_size)

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PSET02__P13__XDR__Encoder::encode__array_slice";

 //-----------------------------------------
 //Сценарий
 //1. Нужно определить количество и тип передаваемых элементов массива
 //
 //   Для этого нужно обработать SDL.
 //
 //   Формально, при этом мы можем проверить и размерность передаваемых данных.
 //
 //2. Отправляем элементы массива в порт подключения

 //----------------------------------------- 1.
 if(ArrSliceDescr.m_element_total_length==0)
 {
  //ERROR - [BUG CHECK] нулевая длина элемента

  RemoteFB__ErrorUtils::Throw_BugCheck__InvalidArray__ZeroSizeOfElement
   (c_bugcheck_src,
    L"#001",
    ArrSliceDescr.m_element_blr_typeid);
 }//if

 if((slice_size%ArrSliceDescr.m_element_total_length)!=0)
 {
  //ERROR - Несогласованные размеры буфера и элемента массива

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

    //проверяем выравнивание
    assert((reinterpret_cast<size_t>(pElement)%sizeof(protocol::P_SHORT))==0);

    xdr::encode__p_short
     (pBuf,
      reinterpret_cast<const protocol::P_SHORT*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__short

   case isc_api::ibp_isc_blr_dtype__long:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_LONG));

    //проверяем выравнивание
    assert((reinterpret_cast<size_t>(pElement)%sizeof(protocol::P_LONG))==0);

    xdr::encode__p_long
     (pBuf,
      reinterpret_cast<const protocol::P_LONG*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__long

   case isc_api::ibp_isc_blr_dtype__int64:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_INT64));

    //проверяем выравнивание. в 32-битном бинарнике может быть 4х байтное выравнивание.
    assert((reinterpret_cast<size_t>(pElement)%min(sizeof(protocol::P_INT64),sizeof(size_t)))==0);

    xdr::encode__p_int64
     (pBuf,
      reinterpret_cast<const protocol::P_INT64*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__int64

   case isc_api::ibp_isc_blr_dtype__float:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_FLOAT));

    //проверяем выравнивание
    assert((reinterpret_cast<size_t>(pElement)%sizeof(protocol::P_FLOAT))==0);

    xdr::encode__p_float
     (pBuf,
      reinterpret_cast<const protocol::P_FLOAT*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__float

   case isc_api::ibp_isc_blr_dtype__double:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_DOUBLE));

    //проверяем выравнивание
    assert((reinterpret_cast<size_t>(pElement)%min(sizeof(protocol::P_DOUBLE),sizeof(size_t)))==0);

    xdr::encode__p_double
     (pBuf,
      reinterpret_cast<const protocol::P_DOUBLE*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__double

   case isc_api::ibp_isc_blr_dtype__sql_time:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(isc_api::t_ibp_isc_time));

    //проверяем выравнивание
    assert((reinterpret_cast<size_t>(pElement)%sizeof(isc_api::t_ibp_isc_time))==0);

    xdr::encode__p_ulong_as_p_long
     (pBuf,
      reinterpret_cast<const isc_api::t_ibp_isc_time*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__sql_time

   case isc_api::ibp_isc_blr_dtype__sql_date:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(isc_api::t_ibp_isc_date));

    //проверяем выравнивание
    assert((reinterpret_cast<size_t>(pElement)%sizeof(isc_api::t_ibp_isc_date))==0);

    xdr::encode__p_long
     (pBuf,
      reinterpret_cast<const isc_api::t_ibp_isc_date*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__sql_date

   case isc_api::ibp_isc_blr_dtype__timestamp:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(isc_api::t_ibp_isc_timestamp));

    //проверяем выравнивание
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

   case isc_api::ibp_fb30_blr_dtype__bool:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(isc_api::t_ibp_fb30_bool));

    //проверяем выравнивание
    assert((reinterpret_cast<size_t>(pElement)%sizeof(isc_api::t_ibp_fb30_bool))==0);

    xdr::encode__opaque
     (pBuf,
      sizeof(isc_api::t_ibp_fb30_bool),
      pElement);

    break;
   }//case - ibp_fb30_blr_dtype__bool

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
}/*nms p13*/}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
