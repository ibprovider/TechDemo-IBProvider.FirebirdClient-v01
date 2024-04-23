////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_jis_traits.cc
//! \brief   Алгоритмы преобразования кодовых страниц SJIS_0208 и EUCJ_0208
//! \author  Kovalenko Dmitry
//! \date    30.09.2008
#ifndef _ibp_cs_jis_traits_CC_
#define _ibp_cs_jis_traits_CC_

#include "source/charsets/ibp_charset_const.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_sjis_0208_traits

template<typename InputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_sjis_0208_traits::convert_single_own_to_unicode_v3
                                           (InputIterator& source,
                                            InputIterator  source_end,
                                            wchar_t*       result_buffer,
                                            size_t&        result_size)
{
 CHECK_WRITE_TYPED_PTR(result_buffer,result_size);

 //-------
 const size_t original_result_size=result_size;

 result_size=0;

 if(source==source_end)
  return db_obj::db_cs_result__ok;

 uchar_type  own_ch_1=*source;
 uchar_type  own_ch_2;

 ++source;

 if(IsAsciiCh(own_ch_1) || IsSjisSingleCh(own_ch_1))
 {
  assert(size_t(own_ch_1)<256);

  assert(sm_sjis__to_unicode_map_size>=1);

  //---
  assert(structure::can_numeric_cast<size_t>(sm_sjis__to_unicode_map[0]));

  assert(structure::can_numeric_cast<size_t>(own_ch_1));

  //---
  assert(size_t(sm_sjis__to_unicode_map[0])<sm_sjis__from_unicode_mapping_array_size);

  assert(size_t(own_ch_1)<sm_sjis__from_unicode_mapping_array_size);

  //---
  assert(size_t(sm_sjis__to_unicode_map[0])<sm_sjis__from_unicode_mapping_array_size-own_ch_1);

  const wchar_t
   result_wc=sm_sjis__from_unicode_mapping_array
                 [sm_sjis__from_unicode_map[0]+own_ch_1];

  if(result_wc==IBP_CS_CANT_MAP && own_ch_1!=IBP_CS_CANT_MAP%256)
   return db_obj::db_cs_result__fail;

  if(original_result_size<1)
   return db_obj::db_cs_result__trunc;

  result_buffer[0]=result_wc;
 }
 else
 {
  if(!IsValidCh_1(own_ch_1))
   return db_obj::db_cs_result__fail;

  if(source==source_end)
   return db_obj::db_cs_result__input_trunc; //CS_BAD_INPUT

  own_ch_2=*source;

  ++source;

  if(!IsValidCh_2(own_ch_2))
   return db_obj::db_cs_result__fail; //CS_BAD_INPUT

  //----
  uchar_type jis_ch_1;
  uchar_type jis_ch_2;

  self_type::S2E(own_ch_1,own_ch_2,&jis_ch_1,&jis_ch_2);

  jis_ch_1&=uchar_type(0x7F);
  jis_ch_2&=uchar_type(0x7F);

  //----
  assert(structure::can_numeric_cast<size_t>(jis_ch_1));

  assert(size_t(jis_ch_1)<self_type::sm_jis__to_unicode_map_size);

  assert(structure::can_numeric_cast<size_t>(jis_ch_2));

  assert(size_t(jis_ch_2)
          <self_type::sm_jis__to_unicode_mapping_array_size);

  assert(structure::can_numeric_cast<size_t>(self_type::sm_jis__to_unicode_map[jis_ch_1]));

  assert(size_t(self_type::sm_jis__to_unicode_map[jis_ch_1])
          <self_type::sm_jis__to_unicode_mapping_array_size);

  assert(size_t(self_type::sm_jis__to_unicode_map[jis_ch_1])
          <self_type::sm_jis__to_unicode_mapping_array_size-jis_ch_2);

  //----
  const wchar_t
   result_wc=self_type::sm_jis__to_unicode_mapping_array
                 [self_type::sm_jis__to_unicode_map[jis_ch_1]+jis_ch_2];

  if(result_wc==IBP_CS_CANT_MAP &&
     !(jis_ch_1==(IBP_CS_CANT_MAP/256) && jis_ch_2==(IBP_CS_CANT_MAP%256)))
  {
   return db_obj::db_cs_result__fail; //CS_CONVERT_ERROR
  }//if

  if(original_result_size<1)
   return db_obj::db_cs_result__trunc;

  result_buffer[0]=result_wc;
 }//else

 result_size=1;

 return db_obj::db_cs_result__ok;
}//convert_single_own_to_unicode_v3

//------------------------------------------------------------------------
template<typename InputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_sjis_0208_traits::convert_single_unicode_to_own_v3
                                           (InputIterator& source,
                                            InputIterator  source_end,
                                            char*          result_buffer,
                                            size_t&        result_size)
{
 CHECK_WRITE_TYPED_PTR(result_buffer,result_size);

 //-------
 const size_t original_result_size=result_size;

 result_size=0;

 if(source==source_end)
  return db_obj::db_cs_result__ok;

 const ushort_type wc=*source;

 assert(structure::can_numeric_cast<size_t>(wc/256));
 assert(size_t(wc/256)<self_type::sm_jis__from_unicode_map_size);
 assert(size_t(self_type::sm_jis__from_unicode_map[wc/256])
         <self_type::sm_jis__from_unicode_mapping_array_size);

 assert(structure::can_numeric_cast<size_t>(wc%256));
 assert(size_t(wc%256)<self_type::sm_jis__from_unicode_mapping_array_size);
 assert(size_t(self_type::sm_jis__from_unicode_map[wc/256])
         <self_type::sm_jis__from_unicode_mapping_array_size-(wc%256));

 ushort_type jis_ch=self_type::sm_jis__from_unicode_mapping_array
                     [self_type::sm_jis__from_unicode_map[wc/256]+wc%256];

 if(jis_ch==IBP_CS_CANT_MAP && wc!=IBP_CS_CANT_MAP)
 {
  /* Handle the non-JIS codes in SJIS (ASCII & half-width Kana) */

  assert(structure::can_numeric_cast<size_t>(wc/256));
  assert(size_t(wc/256)<self_type::sm_sjis__from_unicode_map_size);
  assert(size_t(self_type::sm_sjis__from_unicode_map[wc/256])
          <self_type::sm_sjis__from_unicode_mapping_array_size);

  assert(structure::can_numeric_cast<size_t>(wc%256));
  assert(size_t(wc%256)<self_type::sm_sjis__from_unicode_mapping_array_size);
  assert(size_t(self_type::sm_sjis__from_unicode_map[wc/256])
          <self_type::sm_sjis__from_unicode_mapping_array_size-(wc%256));

  jis_ch=self_type::sm_sjis__from_unicode_mapping_array
          [self_type::sm_sjis__from_unicode_map[wc/256]+wc%256];
 }//if

 /* Step 2: Convert from JIS code to SJIS */
 uchar_type own_ch_1=uchar_type(jis_ch/256);
 uchar_type own_ch_2=uchar_type(jis_ch%256);

 if(own_ch_1==0)
 {
  /* ASCII character */

  //! \todo IBProvider specific assert ?
  //assert_msg(self_type::IsAsciiCh(own_ch_2),
  //           "own_ch_2=="<<unsigned(own_ch_2));

  if(original_result_size<1)
   return db_obj::db_cs_result__trunc;

  result_buffer[0]=own_ch_2;

  result_size=1;
 }//if - Ascii
 else
 {
  self_type::Seven2Eight(&own_ch_1,&own_ch_2);

  if(own_ch_1==0)
  {
   /* half-width kana ? */
   assert(self_type::IsSjisSingleCh(own_ch_2));

   if(original_result_size<1)
    return db_obj::db_cs_result__trunc;

   result_buffer[0]=own_ch_2;

   result_size=1;
  }//if
  else
  {
   assert(self_type::IsValidCh_1(own_ch_1));
   assert(self_type::IsValidCh_2(own_ch_2));

   if(original_result_size<2)
    return db_obj::db_cs_result__trunc;

   result_buffer[0]=own_ch_1;
   result_buffer[1]=own_ch_2;

   result_size=2;
  }//else
 }//else

 ++source;

 return db_obj::db_cs_result__ok;
}//convert_single_unicode_to_own_v3

//------------------------------------------------------------------------
template<typename InputIterator,typename OutputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_sjis_0208_traits::ucs2_to_own(InputIterator&  source,
                                        InputIterator   source_end,
                                        OutputIterator  dest)
{
 for(;source!=source_end;++source)
 {
  const ushort_type wc=*source;

  assert(structure::can_numeric_cast<size_t>(wc/256));
  assert(size_t(wc/256)<self_type::sm_jis__from_unicode_map_size);
  assert(size_t(self_type::sm_jis__from_unicode_map[wc/256])
          <self_type::sm_jis__from_unicode_mapping_array_size);

  assert(structure::can_numeric_cast<size_t>(wc%256));
  assert(size_t(wc%256)<self_type::sm_jis__from_unicode_mapping_array_size);
  assert(size_t(self_type::sm_jis__from_unicode_map[wc/256])
          <self_type::sm_jis__from_unicode_mapping_array_size-(wc%256));

  ushort_type jis_ch=self_type::sm_jis__from_unicode_mapping_array
                      [self_type::sm_jis__from_unicode_map[wc/256]+wc%256];

  if(jis_ch==IBP_CS_CANT_MAP && wc!=IBP_CS_CANT_MAP)
  {
   /* Handle the non-JIS codes in SJIS (ASCII & half-width Kana) */

   assert(structure::can_numeric_cast<size_t>(wc/256));
   assert(size_t(wc/256)<self_type::sm_sjis__from_unicode_map_size);
   assert(size_t(self_type::sm_sjis__from_unicode_map[wc/256])
           <self_type::sm_sjis__from_unicode_mapping_array_size);

   assert(structure::can_numeric_cast<size_t>(wc%256));
   assert(size_t(wc%256)<self_type::sm_sjis__from_unicode_mapping_array_size);
   assert(size_t(self_type::sm_sjis__from_unicode_map[wc/256])
           <self_type::sm_sjis__from_unicode_mapping_array_size-(wc%256));

   jis_ch=self_type::sm_sjis__from_unicode_mapping_array
           [self_type::sm_sjis__from_unicode_map[wc/256]+wc%256];
  }//if

  /* Step 2: Convert from JIS code to SJIS */
  uchar_type own_ch_1=uchar_type(jis_ch/256);
  uchar_type own_ch_2=uchar_type(jis_ch%256);

  if(own_ch_1==0)
  {
   /* ASCII character */

   //! \todo IBProvider specific assert ?
   //assert_msg(self_type::IsAsciiCh(own_ch_2),
   //           "own_ch_2=="<<unsigned(own_ch_2));

   *dest=own_ch_2;

   ++dest;

   continue;
  }//if - Ascii

  self_type::Seven2Eight(&own_ch_1,&own_ch_2);

  if(own_ch_1==0)
  {
   /* half-width kana ? */
   assert(self_type::IsSjisSingleCh(own_ch_2));

   *dest=own_ch_2;

   ++dest;

   continue;
  }//if

  assert(self_type::IsValidCh_1(own_ch_1));
  assert(self_type::IsValidCh_2(own_ch_2));

  *dest=own_ch_1;

  ++dest;

  *dest=own_ch_2;

  ++dest;
 }//for

 return db_obj::db_cs_result__ok;
}//ucs2_to_own

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_eucj_0208_traits

template<typename InputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_eucj_0208_traits::convert_single_own_to_unicode_v3
                                           (InputIterator& source,
                                            InputIterator  source_end,
                                            wchar_t*       result_buffer,
                                            size_t&        result_size)
{
 CHECK_WRITE_PTR(result_buffer,result_size*sizeof(*result_buffer));

 //-------
 const size_t original_result_size=result_size;

 result_size=0;

 if(source==source_end)
  return db_obj::db_cs_result__ok;

 uchar_type  own_ch_1=*source;
 uchar_type  own_ch_2;

 ++source;

 if(self_type::IsSingleCh(own_ch_1))
 {
  /*it is ASCII */
  if(original_result_size<1)
   return db_obj::db_cs_result__trunc;

  result_buffer[0]=own_ch_1;
 }
 else
 {
  //! \note IBP specific check.
  if(!IsValidCh_1(own_ch_1))
   return db_obj::db_cs_result__fail; //CS_BAD_INPUT

  if(source==source_end)
   return db_obj::db_cs_result__input_trunc; //CS_BAD_INPUT

  own_ch_2=*source;

  ++source;

  //! \note IBP specific check.
  if(!IsValidCh_2(own_ch_2))
   return db_obj::db_cs_result__fail; //CS_BAD_INPUT

  //----
  const uchar_type jis_ch_1=uchar_type(own_ch_1&uchar_type(0x7F));
  const uchar_type jis_ch_2=uchar_type(own_ch_2&uchar_type(0x7F));

  //----
  assert(structure::can_numeric_cast<size_t>(jis_ch_1));

  assert(size_t(jis_ch_1)<self_type::sm_jis__to_unicode_map_size);

  assert(structure::can_numeric_cast<size_t>(jis_ch_2));

  assert(size_t(jis_ch_2)
          <self_type::sm_jis__to_unicode_mapping_array_size);

  assert(structure::can_numeric_cast<size_t>(self_type::sm_jis__to_unicode_map[jis_ch_1]));

  assert(size_t(self_type::sm_jis__to_unicode_map[jis_ch_1])
          <self_type::sm_jis__to_unicode_mapping_array_size);

  assert(size_t(self_type::sm_jis__to_unicode_map[jis_ch_1])
          <self_type::sm_jis__to_unicode_mapping_array_size-jis_ch_2);

  //----
  const wchar_t result_wc=self_type::sm_jis__to_unicode_mapping_array
                 [self_type::sm_jis__to_unicode_map[jis_ch_1]+jis_ch_2];

  if(result_wc==IBP_CS_CANT_MAP &&
     !(jis_ch_1==(IBP_CS_CANT_MAP/256) && jis_ch_2==(IBP_CS_CANT_MAP%256)))
  {
   return db_obj::db_cs_result__fail; //CS_CONVERT_ERROR
  }//if

  if(original_result_size<1)
   return db_obj::db_cs_result__trunc;

  result_buffer[0]=result_wc;
 }//else

 result_size=1;

 return db_obj::db_cs_result__ok;
}//convert_single_own_to_unicode_v3

//------------------------------------------------------------------------
template<typename InputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_eucj_0208_traits::convert_single_unicode_to_own_v3
                                       (InputIterator& source,
                                        InputIterator  source_end,
                                        char*          result_buffer,
                                        size_t&        result_size)
{
 CHECK_WRITE_TYPED_PTR(result_buffer,result_size);

 //-------
 const size_t original_result_size=result_size;

 result_size=0;

 if(source==source_end)
  return db_obj::db_cs_result__ok;

 //--------
 uchar_type own_ch_1;
 uchar_type own_ch_2;

 //--------
 const ushort_type wc=(*source);

 if(wc<=127) //FB: <=0x007F
 {
  //ASCII range characters map directly -- others go to the table
  own_ch_1=0;

  own_ch_2=uchar_type(wc%256);
 }
 else
 {
  assert(structure::can_numeric_cast<size_t>(wc/256));
  assert(size_t(wc/256)<self_type::sm_jis__from_unicode_map_size);
  assert(size_t(self_type::sm_jis__from_unicode_map[wc/256])
          <self_type::sm_jis__from_unicode_mapping_array_size);

  assert(structure::can_numeric_cast<size_t>(wc%256));
  assert(size_t(wc%256)<self_type::sm_jis__from_unicode_mapping_array_size);
  assert(size_t(self_type::sm_jis__from_unicode_map[wc/256])
          <self_type::sm_jis__from_unicode_mapping_array_size-(wc%256));

  const ushort_type jis_ch=self_type::sm_jis__from_unicode_mapping_array
                            [self_type::sm_jis__from_unicode_map[wc/256]+wc%256];

  if(jis_ch==IBP_CS_CANT_MAP && wc!=IBP_CS_CANT_MAP)
   return db_obj::db_cs_result__fail;//CS_CONVERT_ERROR

  own_ch_1=uchar_type(jis_ch/256);
  own_ch_2=uchar_type(jis_ch%256);
 }//else

 if(own_ch_1==0)
 {
  assert(self_type::IsSingleCh(own_ch_2));

  if(original_result_size<1)
   return db_obj::db_cs_result__trunc;

  result_buffer[0]=own_ch_2;

  result_size=1;
 }
 else
 {
  assert((own_ch_1&0x80)==0);
  assert((own_ch_2&0x80)==0);

  own_ch_1|=0x80;
  own_ch_2|=0x80;

  assert(self_type::IsValidCh_1(own_ch_1));
  assert(self_type::IsValidCh_2(own_ch_2));

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
 t_ibp_cs_eucj_0208_traits::ucs2_to_own(InputIterator&  source,
                                        InputIterator   source_end,
                                        OutputIterator  dest)
{
 uchar_type own_ch_1;
 uchar_type own_ch_2;

 for(;source!=source_end;++source)
 {
  const ushort_type wc=(*source);

  if(wc<=127) //FB: <=0x007F
  {
   //ASCII range characters map directly -- others go to the table
   own_ch_1=0;

   own_ch_2=uchar_type(wc%256);
  }
  else
  {
   assert(structure::can_numeric_cast<size_t>(wc/256));
   assert(size_t(wc/256)<self_type::sm_jis__from_unicode_map_size);
   assert(size_t(self_type::sm_jis__from_unicode_map[wc/256])
           <self_type::sm_jis__from_unicode_mapping_array_size);

   assert(structure::can_numeric_cast<size_t>(wc%256));
   assert(size_t(wc%256)<self_type::sm_jis__from_unicode_mapping_array_size);
   assert(size_t(self_type::sm_jis__from_unicode_map[wc/256])
           <self_type::sm_jis__from_unicode_mapping_array_size-(wc%256));

   const ushort_type jis_ch=self_type::sm_jis__from_unicode_mapping_array
                             [self_type::sm_jis__from_unicode_map[wc/256]+wc%256];

   if(jis_ch==IBP_CS_CANT_MAP && wc!=IBP_CS_CANT_MAP)
    return db_obj::db_cs_result__fail;//CS_CONVERT_ERROR

   own_ch_1=uchar_type(jis_ch/256);
   own_ch_2=uchar_type(jis_ch%256);
  }//else

  if(own_ch_1==0)
  {
   assert(self_type::IsSingleCh(own_ch_2));

   *dest=own_ch_2;

   ++dest;
  }
  else
  {
   assert((own_ch_1&0x80)==0);
   assert((own_ch_2&0x80)==0);

   own_ch_1|=0x80;
   own_ch_2|=0x80;

   assert(self_type::IsValidCh_1(own_ch_1));
   assert(self_type::IsValidCh_2(own_ch_2));

   *dest=own_ch_1;

   ++dest;

   *dest=own_ch_2;

   ++dest;
  }//else
 }//for source

 return db_obj::db_cs_result__ok;
}//ucs2_to_own

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#endif
