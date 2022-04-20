////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_bit8_bit16_traits.cc
//! \brief   Структура с данными для преобразования кодовых страниц BIT8-BIT16
//! \author  Kovalenko Dmitry
//! \date    30.09.2008
#ifndef _ibp_cs_bit8_bit16_traits_CC_
#define _ibp_cs_bit8_bit16_traits_CC_

#include "source/charsets/ibp_charset_const.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_bit8_bit16

inline t_ibp_cs_bit8_bit16_traits::t_ibp_cs_bit8_bit16_traits
                         (const ushort_type* to_unicode_mapping_array,
                          size_type          to_unicode_mapping_array_size,
                          const ushort_type* to_unicode_map,
                          size_type          to_unicode_map_size,
                          const ushort_type* from_unicode_mapping_array,
                          size_type          from_unicode_mapping_array_size,
                          const ushort_type* from_unicode_map,
                          size_type          from_unicode_map_size,
                          PFnTestChar        is_single_ch_symbol,
                          PFnTestChar        is_valid_ch_1,
                          PFnTestChar        is_valid_ch_2)
 :m_to_unicode_mapping_array         (to_unicode_mapping_array)
 ,m_to_unicode_mapping_array_size    (to_unicode_mapping_array_size)
 ,m_to_unicode_map                   (to_unicode_map)
 ,m_to_unicode_map_size              (to_unicode_map_size)
 ,m_from_unicode_mapping_array       (from_unicode_mapping_array)
 ,m_from_unicode_mapping_array_size  (from_unicode_mapping_array_size)
 ,m_from_unicode_map                 (from_unicode_map)
 ,m_from_unicode_map_size            (from_unicode_map_size)
 ,m_is_single_ch_symbol              (is_single_ch_symbol)
 ,m_is_valid_ch_1                    (is_valid_ch_1)
 ,m_is_valid_ch_2                    (is_valid_ch_2)
{
 CHECK_READ_TYPED_PTR(m_to_unicode_mapping_array,m_to_unicode_mapping_array_size);

 CHECK_READ_TYPED_PTR(m_to_unicode_map,m_to_unicode_map_size);

 CHECK_READ_TYPED_PTR(m_from_unicode_mapping_array,m_from_unicode_mapping_array_size);

 CHECK_READ_TYPED_PTR(m_from_unicode_map,m_from_unicode_map_size);

 assert(m_is_single_ch_symbol);
 assert(m_is_valid_ch_1);
 assert(m_is_valid_ch_2);
}//t_ibp_cs_bit8_bit16_traits

//------------------------------------------------------------------------
template<typename InputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_bit8_bit16_traits::convert_single_own_to_unicode_v3
                                           (InputIterator& source,
                                            InputIterator  source_end,
                                            wchar_t*       result_buffer,
                                            size_t&        result_size)const
{
 CHECK_WRITE_TYPED_PTR(result_buffer,result_size);

 //-------
 const size_t original_result_size=result_size;

 result_size=0;

 if(source==source_end)
  return db_obj::db_cs_result__ok;

 uchar_type own_ch_1=*source;
 uchar_type own_ch_2;

 ++source;

 if(m_is_single_ch_symbol(own_ch_1))
 {
  /*it is ASCII */
  own_ch_2=own_ch_1;

  own_ch_1=0;
 }
 else
 {
  if(!m_is_valid_ch_1(own_ch_1))
   return db_obj::db_cs_result__fail; //CS_BAD_INPUT

  if(source==source_end)
   return db_obj::db_cs_result__input_trunc; //CS_BAD_INPUT

  own_ch_2=*source;

  ++source;

  if(!m_is_valid_ch_2(own_ch_2))
   return db_obj::db_cs_result__fail; //CS_BAD_INPUT
 }//else

 /* Convert from OWN to UNICODE */
 assert(structure::can_numeric_cast<size_t>(own_ch_1));
 assert(size_t(own_ch_1)<m_to_unicode_map_size);
 assert(size_t(m_to_unicode_map[own_ch_1])<m_to_unicode_mapping_array_size);

 assert(structure::can_numeric_cast<size_t>(own_ch_2));
 assert(size_t(own_ch_2)<m_to_unicode_mapping_array_size);
 assert(size_t(m_to_unicode_map[own_ch_1])<m_to_unicode_mapping_array_size-own_ch_2);

 const wchar_t result_wc=m_to_unicode_mapping_array[m_to_unicode_map[own_ch_1]+own_ch_2];

 if(result_wc==IBP_CS_CANT_MAP &&
    !(own_ch_1==(IBP_CS_CANT_MAP/256) && own_ch_2==(IBP_CS_CANT_MAP%256)))
 {
  return db_obj::db_cs_result__fail; //CS_CONVERT_ERROR
 }//if

 if(original_result_size<1)
  return db_obj::db_cs_result__trunc;

 //------
 result_buffer[0]=result_wc;

 result_size=1;

 return db_obj::db_cs_result__ok;
}//convert_single_own_to_unicode_v3

//------------------------------------------------------------------------
template<typename InputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_bit8_bit16_traits::convert_single_unicode_to_own_v3
                                           (InputIterator& source,
                                            InputIterator  source_end,
                                            char*          result_buffer,
                                            size_t&        result_size)const
{
 CHECK_WRITE_TYPED_PTR(result_buffer,result_size);

 //-------
 const size_t original_result_size=result_size;

 result_size=0;

 if(source==source_end)
  return db_obj::db_cs_result__ok;

 //------- Convert from UNICODE to OWN code
 const ushort_type wc=(*source);

 assert(structure::can_numeric_cast<size_t>(wc/256));
 assert(size_t(wc/256)<m_from_unicode_map_size);
 assert(size_t(m_from_unicode_map[wc/256])<m_from_unicode_mapping_array_size);

 assert(structure::can_numeric_cast<size_t>(wc%256));
 assert(size_t(wc%256)<m_from_unicode_mapping_array_size);
 assert(size_t(m_from_unicode_map[wc/256])<m_from_unicode_mapping_array_size-(wc%256));

 const ushort_type
  own_ch=m_from_unicode_mapping_array[m_from_unicode_map[wc/256]+(wc%256)];

 if(own_ch==IBP_CS_CANT_MAP && wc!=IBP_CS_CANT_MAP)
  return db_obj::db_cs_result__fail;//CS_CONVERT_ERROR

 const uchar_type own_ch_1 =static_cast<uchar_type>(own_ch/256);
 const uchar_type own_ch_2 =static_cast<uchar_type>(own_ch-(256*own_ch_1));

 if(own_ch_1==0)
 {
  assert_msg(m_is_single_ch_symbol(own_ch_2),"wc="<<unsigned(wc));

  if(original_result_size<1)
   return db_obj::db_cs_result__trunc;

  result_buffer[0]=own_ch_2;

  result_size=1;
 }
 else
 {
  //verification of conversion table
  assert(m_is_valid_ch_1(own_ch_1));
  assert(m_is_valid_ch_2(own_ch_2));

  if(original_result_size<2)
   return db_obj::db_cs_result__trunc;

  result_buffer[0]=own_ch_1;
  result_buffer[1]=own_ch_2;

  result_size=2;
 }//else

 ++source;

 return db_obj::db_cs_result__ok;
}//convert_single_unicode_to_own_v3

//------------------------------------------------------------------------
template<typename InputIterator,typename OutputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_bit8_bit16_traits::ucs2_to_own(InputIterator& source,
                                         InputIterator  source_end,
                                         OutputIterator dest)const
{
 for(;source!=source_end;++source)
 {
  /* Convert from UNICODE to OWN code */
  const ushort_type wc=(*source);

  assert(structure::can_numeric_cast<size_t>(wc/256));
  assert(size_t(wc/256)<m_from_unicode_map_size);
  assert(size_t(m_from_unicode_map[wc/256])<m_from_unicode_mapping_array_size);

  assert(structure::can_numeric_cast<size_t>(wc%256));
  assert(size_t(wc%256)<m_from_unicode_mapping_array_size);
  assert(size_t(m_from_unicode_map[wc/256])<m_from_unicode_mapping_array_size-(wc%256));

  const ushort_type
   own_ch=m_from_unicode_mapping_array[m_from_unicode_map[wc/256]+(wc%256)];

  if(own_ch==IBP_CS_CANT_MAP && wc!=IBP_CS_CANT_MAP)
   return db_obj::db_cs_result__fail;//CS_CONVERT_ERROR

  const uchar_type own_ch_1 =static_cast<uchar_type>(own_ch/256);
  const uchar_type own_ch_2 =static_cast<uchar_type>(own_ch-(256*own_ch_1));

  if(own_ch_1==0)
  {
   assert_msg(m_is_single_ch_symbol(own_ch_2),"wc="<<unsigned(wc));

   *dest=own_ch_2;

   ++dest;
  }
  else
  {
   //verification of conversion table
   assert(m_is_valid_ch_1(own_ch_1));
   assert(m_is_valid_ch_2(own_ch_2));

   *dest=own_ch_1;

   ++dest;

   *dest=own_ch_2;

   ++dest;
  }//else
 }//for

 return db_obj::db_cs_result__ok;
}//ucs2_to_own

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif