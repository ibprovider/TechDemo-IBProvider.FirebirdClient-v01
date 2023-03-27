////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_portable_format_to_integer.cpp
//! \brief   ‘ункции дл€ работы с транспортным форматом INT-значений
//! \author  Kovalenko Dmitry
//! \date    23.04.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include "source/error_services/ibp_error_utils.h"
#include <limits.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////

bool isc_portable_integer__is_zero(size_t      const sz,
                                   const void* const pv)
{
 CHECK_READ_PTR(pv,sz);

 typedef unsigned char byte_type;

 assert_s(sizeof(byte_type)==1);

 const byte_type* b=reinterpret_cast<const byte_type*>(pv);
 const byte_type* e=b+sz;

 for(;b!=e;++b)
 {
  if((*b)!=0)
   return false;
 }//for

 return true;
}//isc_portable_integer__is_zero

////////////////////////////////////////////////////////////////////////////////
//class isc_portable_format_to_integer

bool isc_portable_format_to_integer::exec_r(size_t            const sz,
                                            const void*       const pv,
                                            unsigned __int16* const result)
{
 return self_type::helper__to_integer__generic__unsigned(sz,pv,result);
}//exec_r - uint16

//------------------------------------------------------------------------
bool isc_portable_format_to_integer::exec_r(size_t            const sz,
                                            const void*       const pv,
                                            unsigned __int32* const result)
{
 return self_type::helper__to_integer__generic__unsigned(sz,pv,result);
}//exec_r - uint32

//------------------------------------------------------------------------
bool isc_portable_format_to_integer::exec_r(size_t            const sz,
                                            const void*       const pv,
                                            unsigned __int64* const result)
{
 return self_type::helper__to_integer__generic__unsigned(sz,pv,result);
}//exec_r - uint64

//------------------------------------------------------------------------
bool isc_portable_format_to_integer::exec_r(size_t            const sz,
                                            const void*       const pv,
                                            unsigned long*    const result)
{
 return self_type::helper__to_integer__generic__unsigned(sz,pv,result);
}//exec_r - ulong

//------------------------------------------------------------------------
bool isc_portable_format_to_integer::exec_r(size_t            const sz,
                                            const void*       const pv,
                                            signed __int16*   const result)
{
 return self_type::helper__to_integer__generic__signed(sz,pv,result);
}//exec_r - int16

//------------------------------------------------------------------------
bool isc_portable_format_to_integer::exec_r(size_t            const sz,
                                            const void*       const pv,
                                            signed __int32*   const result)
{
 return self_type::helper__to_integer__generic__signed(sz,pv,result);
}//exec_r - int32

//------------------------------------------------------------------------
bool isc_portable_format_to_integer::exec_r(size_t            const sz,
                                            const void*       const pv,
                                            signed __int64*   const result)
{
 return self_type::helper__to_integer__generic__signed(sz,pv,result);
}//exec_r - int64

//------------------------------------------------------------------------
bool isc_portable_format_to_integer::exec_r(size_t            const sz,
                                            const void*       const pv,
                                            signed long*      const result)
{
 return self_type::helper__to_integer__generic__signed(sz,pv,result);
}//exec_r - long

//------------------------------------------------------------------------
bool isc_portable_format_to_integer::exec_r(size_t                                          const sz,
                                            const void*                                     const pv,
                                            structure::t_value_with_null<unsigned __int16>* const result)
{
 return self_type::helper__to_integerN__generic__unsigned(sz,pv,result);
}//exec_r - uint16_N

//------------------------------------------------------------------------
bool isc_portable_format_to_integer::exec_r(size_t                                          const sz,
                                            const void*                                     const pv,
                                            structure::t_value_with_null<unsigned __int32>* const result)
{
 return self_type::helper__to_integerN__generic__unsigned(sz,pv,result);
}//exec_r - uint32_N

//------------------------------------------------------------------------
bool isc_portable_format_to_integer::exec_r(size_t                                          const sz,
                                            const void*                                     const pv,
                                            structure::t_value_with_null<unsigned __int64>* const result)
{
 return self_type::helper__to_integerN__generic__unsigned(sz,pv,result);
}//exec_r - uint64_N

//------------------------------------------------------------------------
bool isc_portable_format_to_integer::exec_r(size_t                                       const sz,
                                            const void*                                  const pv,
                                            structure::t_value_with_null<unsigned long>* const result)
{
 return self_type::helper__to_integerN__generic__unsigned(sz,pv,result);
}//exec_r - ulong_N

//------------------------------------------------------------------------
bool isc_portable_format_to_integer::exec_r(size_t                                        const sz,
                                            const void*                                   const pv,
                                            structure::t_value_with_null<signed __int16>* const result)
{
 return self_type::helper__to_integerN__generic__signed(sz,pv,result);
}//exec_r - int16_N

//------------------------------------------------------------------------
bool isc_portable_format_to_integer::exec_r(size_t                                        const sz,
                                            const void*                                   const pv,
                                            structure::t_value_with_null<signed __int32>* const result)
{
 return self_type::helper__to_integerN__generic__signed(sz,pv,result);
}//exec_r - int32_N

//------------------------------------------------------------------------
bool isc_portable_format_to_integer::exec_r(size_t                                        const sz,
                                            const void*                                   const pv,
                                            structure::t_value_with_null<signed __int64>* const result)
{
 return self_type::helper__to_integerN__generic__signed(sz,pv,result);
}//exec_r - int64_N

//------------------------------------------------------------------------
bool isc_portable_format_to_integer::exec_r(size_t                                     const sz,
                                            const void*                                const pv,
                                            structure::t_value_with_null<signed long>* const result)
{
 return self_type::helper__to_integerN__generic__signed(sz,pv,result);
}//exec_r - long_N

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                  const sz,
                                          const void*             const pv,
                                          unsigned __int16*       const result,
                                          ibp::t_ibp_subsystem_id const subsystem,
                                          const wchar_t*          const value_sign)
{
 if(!self_type::helper__to_integer__generic__unsigned(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"unsigned __int16",
    sz);
 }//if
}//exec

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                  const sz,
                                          const void*             const pv,
                                          unsigned __int32*       const result,
                                          ibp::t_ibp_subsystem_id const subsystem,
                                          const wchar_t*          const value_sign)
{
 if(!self_type::helper__to_integer__generic__unsigned(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"unsigned __int32",
    sz);
 }//if
}//exec

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                  const sz,
                                          const void*             const pv,
                                          unsigned __int64*       const result,
                                          ibp::t_ibp_subsystem_id const subsystem,
                                          const wchar_t*          const value_sign)
{
 if(!self_type::helper__to_integer__generic__unsigned(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"unsigned __int64",
    sz);
 }//if
}//exec

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                  const sz,
                                          const void*             const pv,
                                          unsigned long*          const result,
                                          ibp::t_ibp_subsystem_id const subsystem,
                                          const wchar_t*          const value_sign)
{
 if(!self_type::helper__to_integer__generic__unsigned(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"unsigned long",
    sz);
 }//if
}//exec

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                  const sz,
                                          const void*             const pv,
                                          signed __int16*         const result,
                                          ibp::t_ibp_subsystem_id const subsystem,
                                          const wchar_t*          const value_sign)
{
 if(!self_type::helper__to_integer__generic__signed(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"signed __int16",
    sz);
 }//if
}//exec

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                  const sz,
                                          const void*             const pv,
                                          signed __int32*         const result,
                                          ibp::t_ibp_subsystem_id const subsystem,
                                          const wchar_t*          const value_sign)
{
 if(!self_type::helper__to_integer__generic__signed(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"signed __int32",
    sz);
 }//if
}//exec

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                  const sz,
                                          const void*             const pv,
                                          signed __int64*         const result,
                                          ibp::t_ibp_subsystem_id const subsystem,
                                          const wchar_t*          const value_sign)
{
 if(!self_type::helper__to_integer__generic__signed(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"signed __int64",
    sz);
 }//if
}//exec

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                  const sz,
                                          const void*             const pv,
                                          signed long*            const result,
                                          ibp::t_ibp_subsystem_id const subsystem,
                                          const wchar_t*          const value_sign)
{
 if(!self_type::helper__to_integer__generic__signed(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"signed long",
    sz);
 }//if
}//exec

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                                          const sz,
                                          const void*                                     const pv,
                                          structure::t_value_with_null<unsigned __int16>* const result,
                                          ibp::t_ibp_subsystem_id                         const subsystem,
                                          const wchar_t*                                  const value_sign)
{
 if(!self_type::helper__to_integerN__generic__unsigned(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"unsigned __int16",
    sz);
 }//if
}//exec

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                                          const sz,
                                          const void*                                     const pv,
                                          structure::t_value_with_null<unsigned __int32>* const result,
                                          ibp::t_ibp_subsystem_id                         const subsystem,
                                          const wchar_t*                                  const value_sign)
{
 if(!self_type::helper__to_integerN__generic__unsigned(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"unsigned __int32",
    sz);
 }//if
}//exec

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                                          const sz,
                                          const void*                                     const pv,
                                          structure::t_value_with_null<unsigned __int64>* const result,
                                          ibp::t_ibp_subsystem_id                         const subsystem,
                                          const wchar_t*                                  const value_sign)
{
 if(!self_type::helper__to_integerN__generic__unsigned(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"unsigned __int64",
    sz);
 }//if
}//exec

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                                          sz,
                                          const void*                                     pv,
                                          structure::t_value_with_null<unsigned long>*    result,
                                          ibp::t_ibp_subsystem_id                         subsystem,
                                          const wchar_t*                                  value_sign)
{
 if(!self_type::helper__to_integerN__generic__unsigned(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"unsigned long",
    sz);
 }//if
}//exec

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                                        const sz,
                                          const void*                                   const pv,
                                          structure::t_value_with_null<signed __int16>* const result,
                                          ibp::t_ibp_subsystem_id                       const subsystem,
                                          const wchar_t*                                const value_sign)
{
 if(!self_type::helper__to_integerN__generic__signed(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"signed __int16",
    sz);
 }//if
}//exec

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                                        const sz,
                                          const void*                                   const pv,
                                          structure::t_value_with_null<signed __int32>* const result,
                                          ibp::t_ibp_subsystem_id                       const subsystem,
                                          const wchar_t*                                const value_sign)
{
 if(!self_type::helper__to_integerN__generic__signed(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"signed __int32",
    sz);
 }//if
}//exec

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                                        const sz,
                                          const void*                                   const pv,
                                          structure::t_value_with_null<signed __int64>* const result,
                                          ibp::t_ibp_subsystem_id                       const subsystem,
                                          const wchar_t*                                const value_sign)
{
 if(!self_type::helper__to_integerN__generic__signed(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"signed __int64",
    sz);
 }//if
}//exec

//------------------------------------------------------------------------
void isc_portable_format_to_integer::exec(size_t                                        sz,
                                          const void*                                   pv,
                                          structure::t_value_with_null<signed long>*    result,
                                          ibp::t_ibp_subsystem_id                       subsystem,
                                          const wchar_t*                                value_sign)
{
 if(!self_type::helper__to_integerN__generic__signed(sz,pv,result))
 {
  helper__throw_error__bad_format
   (subsystem,
    value_sign,
    L"signed long",
    sz);
 }//if
}//exec

//helper methods ---------------------------------------------------------
template<typename result_type>
bool isc_portable_format_to_integer::helper__to_integer__generic__unsigned
                                           (size_t       const sz,
                                            const void*  const pv,
                                            result_type* const result)
{
 assert(!structure::t_numeric_limits<result_type>::is_signed);

 //јлгоритм рассчитан исключительно на 8-битные байты (char).
 #if(CHAR_BIT!=8)
  #error "Unsupport numbers of bits in byte"
 #endif

 CHECK_READ_PTR(pv,sz);
 assert(result);

 //--------
 (*result)=0;

 //--------
 typedef unsigned char byte_type;

 assert_s(sizeof(byte_type)==1);

 //--------
 const byte_type* b(reinterpret_cast<const byte_type*>(pv));

 result_type tmp_result(0);

 size_t n=0;

 size_t const c=min(sizeof(result_type),sz);

 //--------
 //»спользуем €вное число 8,
 // потому что при упаковке тоже используетс€ конкретное число
 for(long shift=0;n<c;++n,++b,shift+=8)
 {
  tmp_result=result_type(tmp_result+(result_type(*b)<<shift));
 }//for

 //--------
 for(;n<sz;++n,++b)
 {
  if((*b)!=0)
   return false;
 }//for

 //--------
 (*result)=tmp_result;

 return true;
}//helper__to_integer__generic__unsigned

//------------------------------------------------------------------------
template<typename result_type>
bool isc_portable_format_to_integer::helper__to_integerN__generic__unsigned
              (size_t                                     const sz,
               const void*                                const pv,
               structure::t_value_with_null<result_type>* const result)
{
 assert(result);

 result->reset();

 result_type x(0);

 if(!self_type::helper__to_integer__generic__unsigned(sz,pv,&x))
  return false;

 (*result)=x;

 return true;
}//helper__to_integerN__generic__unsigned

//------------------------------------------------------------------------
template<typename result_type>
bool isc_portable_format_to_integer::helper__to_integer__generic__signed
                                           (size_t       const sz,
                                            const void*  const pv,
                                            result_type* const result)
{
 assert(structure::t_numeric_limits<result_type>::is_signed);

 //јлгоритм рассчитан исключительно на 8-битные байты (char).
 #if(CHAR_BIT!=8)
  #error "Unsupport numbers of bits in byte"
 #endif

 CHECK_READ_PTR(pv,sz);
 assert(result);

 //--------
 (*result)=0;

 //--------
 typedef unsigned char byte_type;

 assert_s(sizeof(byte_type)==1);

 //--------
 const byte_type* b(reinterpret_cast<const byte_type*>(pv));

 result_type tmp_result(0);

 size_t n=0;

 if(sizeof(result_type)<sz)
 {
  //--------
  //»спользуем €вное число 8,
  // потому что при упаковке тоже используетс€ конкретное число
  for(long shift=0;n<sizeof(result_type);++n,++b,shift+=8)
  {
   tmp_result=result_type(tmp_result+(result_type(*b)<<shift));
  }//for

  //--------
  if(tmp_result>=0)
  {
   for(;n<sz;++n,++b)
   {
    if((*b)!=0)
     return false;
   }//for
  }
  else //отрицательный результат
  {
   for(;n<sz;++n,++b)
   {
    if((*b)!=0xFF)
     return false;
   }//for
  }//else
 }
 else
 if(sz>0)
 {
  assert(sz<=sizeof(result_type));

  //--------
  //»спользуем €вное число 8,
  // потому что при упаковке тоже используетс€ конкретное число

  long shift=0;

  for(;n<sz;++n,++b,shift+=8)
  {
   tmp_result=result_type(tmp_result+(result_type(*b)<<shift));
  }//for

  //--------
  if((reinterpret_cast<const byte_type*>(pv)[sz-1]&0x80)!=0)
  {
   //формируем отрицательное число

   for(;n<sizeof(result_type);++n,shift+=8)
   {
    tmp_result=result_type(tmp_result+(result_type(byte_type(0xFF))<<shift));
   }//for
  }//if
 }//else - if

 //--------
 (*result)=tmp_result;

 return true;
}//helper__to_integer__generic__signed

//------------------------------------------------------------------------
template<typename result_type>
bool isc_portable_format_to_integer::helper__to_integerN__generic__signed
              (size_t                                     const sz,
               const void*                                const pv,
               structure::t_value_with_null<result_type>* const result)
{
 assert(result);

 result->reset();

 result_type x(0);

 if(!self_type::helper__to_integer__generic__signed(sz,pv,&x))
  return false;

 (*result)=x;

 return true;
}//helper__to_integerN__generic__signed

//------------------------------------------------------------------------
void isc_portable_format_to_integer::helper__throw_error__bad_format
                                           (ibp::t_ibp_subsystem_id const subsystem,
                                            const wchar_t*          const value_sign,
                                            const wchar_t*          const value_type_sign,
                                            size_t                  const buf_length)
{
 assert(value_sign);
 assert(value_type_sign);

 //[2015-04-25] формально, у нас не должно быть проблем с пустым буфером
 assert(buf_length>0);

 //ERROR - ошибка преобразование транспортного формата в число

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   subsystem,
   ibp::ibp_mce_isc__bad_transport_format_of_integer_value_3,
   value_sign,
   value_type_sign,
   buf_length);
}//helper__throw_error__bad_format

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
