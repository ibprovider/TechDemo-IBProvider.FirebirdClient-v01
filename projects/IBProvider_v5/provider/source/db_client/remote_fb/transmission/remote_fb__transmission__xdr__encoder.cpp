////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission
//! \file    remote_fb__transmission__xdr__encoder.cpp
//! \brief   ������� ��� �������� ������ � ������� �����.
//! \author  Kovalenko Dmitry
//! \date    23.11.2014.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__encoder.h"
#include "source/db_client/remote_fb/remote_fb__array_slice_descr.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__XDR__Encoder

const protocol::P_UCHAR
 RemoteFB__XDR__Encoder::sm_bytes_filler4[protocol::FB_PACKET_FIELD_ALIGN]
  ={};

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_arch
                              (buf_type*               const pBuf,
                               const protocol::P_ARCH* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 const protocol::P_LONG tmp=*pv;

 pBuf->write__long(&tmp);
}//encode__p_arch

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_objct
                              (buf_type*                const pBuf,
                               const protocol::P_OBJCT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_SHORT)==sizeof(*pv));

 const protocol::P_LONG tmp=*reinterpret_cast<const protocol::P_SHORT*>(pv);

 pBuf->write__long(&tmp);
}//encode__p_objct

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_short
                              (buf_type*                const pBuf,
                               const protocol::P_SHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 const protocol::P_LONG tmp=*pv;

 pBuf->write__long(&tmp);
}//encode__p_short

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_long
                              (buf_type*               const pBuf,
                               const protocol::P_LONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 pBuf->write__long(pv);
}//encode__p_long

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_int64
                              (buf_type*                const pBuf,
                               const protocol::P_INT64* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_INT64)==2*sizeof(protocol::P_LONG));

 const protocol::P_LONG h=static_cast<protocol::P_LONG>(((*pv)>>32)&0x00000000FFFFFFFF);

 pBuf->write__long(&h);

 const protocol::P_LONG l=static_cast<protocol::P_LONG>((*pv)&0x00000000FFFFFFFF);

 pBuf->write__long(&l);
}//encode__p_int64

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_ushort
                              (buf_type*                 const pBuf,
                               const protocol::P_USHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 const protocol::P_LONG tmp=*pv;

 pBuf->write__long(&tmp);
}//encode__p_ushort

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_ushort_as_p_long
                              (buf_type*                 const pBuf,
                               const protocol::P_USHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 const protocol::P_LONG tmp=*pv;

 pBuf->write__long(&tmp);
}//encode__p_ushort_as_p_long

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_ushort_as_p_short
                              (buf_type*                 const pBuf,
                               const protocol::P_USHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(*pv)==sizeof(protocol::P_SHORT));

 return self_type::encode__p_short
         (pBuf,
          reinterpret_cast<const protocol::P_SHORT*>(pv));
}//encode__p_ushort_as_p_short

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_ulong_as_p_long
                              (buf_type*                const pBuf,
                               const protocol::P_ULONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_LONG)==sizeof(*pv));

 pBuf->write__long(reinterpret_cast<const protocol::P_LONG*>(pv));
}//encode__p_ulong_as_p_long

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_float
                              (buf_type*                const pBuf,
                               const protocol::P_FLOAT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_FLOAT)==sizeof(protocol::P_LONG));

 pBuf->write__long(reinterpret_cast<const protocol::P_LONG*>(pv));
}//encode__p_float

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_double
                              (buf_type*                 const pBuf,
                               const protocol::P_DOUBLE* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_DOUBLE)==sizeof(protocol::P_INT64));
 assert_s(sizeof(protocol::P_DOUBLE)==2*sizeof(protocol::P_LONG));

 const protocol::P_INT64 i64=*reinterpret_cast<const protocol::P_INT64*>(pv);

 const protocol::P_LONG h=static_cast<protocol::P_LONG>((i64>>32)&0x00000000FFFFFFFF);

 pBuf->write__long(&h);

 const protocol::P_LONG l=static_cast<protocol::P_LONG>(i64&0x00000000FFFFFFFF);

 pBuf->write__long(&l);
}//encode__p_double

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_bid(buf_type*              const pBuf,
                                           const protocol::P_BID* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 self_type::encode__p_ulong_as_p_long(pBuf,
                                      &pv->high);

 self_type::encode__p_ulong_as_p_long(pBuf,
                                      &pv->low);
}//encode__p_bid

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__opaque(buf_type*                const pBuf,
                                            size_t                   const sz,
                                            const protocol::P_UCHAR* const pv)
{
 assert(pBuf!=nullptr);

 CHECK_READ_TYPED_PTR(pv,sz);

 pBuf->write__bytes(sz,pv);

 //-----------------------------------------
 self_type::helper__write_align_cch(pBuf,
                                    sz);
}//encode__opaque

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__array_slice
                                           (buf_type*                const pBuf,
                                            const asd_type&                ArrSliceDescr,
                                            size_t                   const slice_size,
                                            const protocol::P_UCHAR* const slice)
{
 assert(pBuf);

 CHECK_READ_TYPED_PTR(slice,slice_size)

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__XDR__Encoder::encode__array_slice";

 //-----------------------------------------
 //��������
 //1. ����� ���������� ���������� � ��� ������������ ��������� �������
 //
 //   ��� ����� ����� ���������� SDL.
 //
 //   ���������, ��� ���� �� ����� ��������� � ����������� ������������ ������.
 //
 //2. ���������� �������� ������� � ���� �����������

 //----------------------------------------- 1.
 if(ArrSliceDescr.m_element_total_length==0)
 {
  //ERROR - [BUG CHECK] ������� ����� ��������

  RemoteFB__ErrorUtils::Throw_BugCheck__InvalidArray__ZeroSizeOfElement
   (c_bugcheck_src,
    L"#001",
    ArrSliceDescr.m_element_blr_typeid);
 }//if

 if((slice_size%ArrSliceDescr.m_element_total_length)!=0)
 {
  //ERROR - ��������������� ������� ������ � �������� �������

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_isc__bug_check__inconsistent_sizes_of_slice_and_element_5,
    c_bugcheck_src,
    L"#002",
    slice_size,
    ArrSliceDescr.m_element_total_length,
    ArrSliceDescr.m_element_blr_typeid);
 }//if

 //const size_t nElements=slice_size/ArrSliceDescr.m_element_total_length;

 //-----------------------------------------
 typedef self_type xdr;

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

    //��������� ������������
    assert((reinterpret_cast<size_t>(pElement)%sizeof(protocol::P_SHORT))==0);

    xdr::encode__p_short
     (pBuf,
      reinterpret_cast<const protocol::P_SHORT*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__short

   case isc_api::ibp_isc_blr_dtype__long:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_LONG));

    //��������� ������������
    assert((reinterpret_cast<size_t>(pElement)%sizeof(protocol::P_LONG))==0);

    xdr::encode__p_long
     (pBuf,
      reinterpret_cast<const protocol::P_LONG*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__long

   case isc_api::ibp_isc_blr_dtype__int64:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_INT64));

    //��������� ������������. � 32-������ ��������� ����� ���� 4� ������� ������������.
    assert((reinterpret_cast<size_t>(pElement)%min(sizeof(protocol::P_INT64),sizeof(size_t)))==0);

    xdr::encode__p_int64
     (pBuf,
      reinterpret_cast<const protocol::P_INT64*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__int64

   case isc_api::ibp_isc_blr_dtype__float:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_FLOAT));

    //��������� ������������
    assert((reinterpret_cast<size_t>(pElement)%sizeof(protocol::P_FLOAT))==0);

    xdr::encode__p_float
     (pBuf,
      reinterpret_cast<const protocol::P_FLOAT*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__float

   case isc_api::ibp_isc_blr_dtype__double:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_DOUBLE));

    //��������� ������������
    assert((reinterpret_cast<size_t>(pElement)%min(sizeof(protocol::P_DOUBLE),sizeof(size_t)))==0);

    xdr::encode__p_double
     (pBuf,
      reinterpret_cast<const protocol::P_DOUBLE*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__double

   case isc_api::ibp_isc_blr_dtype__sql_time:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(isc_api::t_ibp_isc_time));

    //��������� ������������
    assert((reinterpret_cast<size_t>(pElement)%sizeof(isc_api::t_ibp_isc_time))==0);

    xdr::encode__p_ulong_as_p_long
     (pBuf,
      reinterpret_cast<const isc_api::t_ibp_isc_time*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__sql_time

   case isc_api::ibp_isc_blr_dtype__sql_date:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(isc_api::t_ibp_isc_date));

    //��������� ������������
    assert((reinterpret_cast<size_t>(pElement)%sizeof(isc_api::t_ibp_isc_date))==0);

    xdr::encode__p_long
     (pBuf,
      reinterpret_cast<const isc_api::t_ibp_isc_date*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__sql_date

   case isc_api::ibp_isc_blr_dtype__timestamp:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(isc_api::t_ibp_isc_timestamp));

    //��������� ������������
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
   }//case - ibp_isc_blr_dtype__text2

   case isc_api::ibp_fb030_blr_dtype__bool:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(isc_api::t_ibp_fb030_bool));

    //checking an alignment
    assert((reinterpret_cast<size_t>(pElement)%sizeof(isc_api::t_ibp_fb030_bool))==0);

    xdr::encode__opaque
     (pBuf,
      sizeof(isc_api::t_ibp_fb030_bool),
      pElement);

    break;
   }//case - ibp_fb030_blr_dtype__bool

   default:
   {
    //ERROR - unknown blr data type

    IBP_ErrorUtils::Throw__Error
     (E_FAIL,
      ibp_mce_isc__bug_check__unknown_blr_data_type_3,
      c_bugcheck_src,
      L"#003",
      ArrSliceDescr.m_element_blr_typeid);
   }//default
  }//switch ArrSliceDescr.m_element_blr_typeid
 }//for pElement
}//encode__array_slice

//helper methods ---------------------------------------------------------
void RemoteFB__XDR__Encoder::helper__write_align_cch(buf_type* const pBuf,
                                                     size_t    const cch)
{
 if(size_t l=(cch%protocol::FB_PACKET_FIELD_ALIGN))
 {
  assert(l>0);
  assert(l<protocol::FB_PACKET_FIELD_ALIGN);

  l=(protocol::FB_PACKET_FIELD_ALIGN-l);

  assert(l<=_DIM_(sm_bytes_filler4));

  pBuf->write__bytes(l,sm_bytes_filler4);
 }//if
}//helper__write_align_cch

////////////////////////////////////////////////////////////////////////////////
}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
