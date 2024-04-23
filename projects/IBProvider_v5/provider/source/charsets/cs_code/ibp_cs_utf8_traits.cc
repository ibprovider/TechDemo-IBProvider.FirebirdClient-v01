////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_utf8_traits.cc
//! \brief   Алгоритмы преобразования кодовой страницы UTF8
//! \author  Kovalenko Dmitry
//! \date    23.07.2011
#ifndef _ibp_cs_utf8_traits_CC_
#define _ibp_cs_utf8_traits_CC_

#include <lcpi/lib/structure/charsets/cs_cvt__single_utf8_to_utf16.h>
#include <lcpi/lib/structure/charsets/cs_cvt__utf16_to_utf8.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_utf8_traits

#define IBP_TRANSLATE_UTF8_CVT_RESULT(cvt_result)    \
 switch(cvt_result)                                  \
 {                                                   \
  case cs_nms::cs_cvt_result_code::ok:               \
   return db_obj::db_cs_result__ok;                  \
                                                     \
  case cs_nms::cs_cvt_result_code::small_output:     \
   return db_obj::db_cs_result__trunc;               \
                                                     \
  case cs_nms::cs_cvt_result_code::trunc_input:      \
   return db_obj::db_cs_result__input_trunc;         \
                                                     \
  default:                                           \
   return db_obj::db_cs_result__fail;                \
 }//switch cvt_result

//------------------------------------------------------------------------
template<typename InputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_utf8_traits::convert_single_own_to_unicode_v3
                        (InputIterator& source,
                         InputIterator  source_end,
                         wchar_t* const result_buffer,
                         size_t&        result_size)
{
 CHECK_WRITE_TYPED_PTR(result_buffer,result_size);

 //-------
 namespace cs_nms=lib::structure::charsets;

 const auto
  result
   =cs_nms::cs_cvt__single_utf8_to_utf16
     (source,
      source_end,
      result_buffer,
      result_buffer+result_size);

 source
  =result.input;

 LCPI__assert(result.output>=(result_buffer));
 LCPI__assert(result.output<=(result_buffer+result_size));

 result_size
  =(result.output-result_buffer);

 IBP_TRANSLATE_UTF8_CVT_RESULT(result.code)
}//convert_single_own_to_unicode_v3

//------------------------------------------------------------------------
template<typename InputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_utf8_traits::convert_single_unicode_to_own_v3
                        (InputIterator& source,
                         InputIterator  source_end,
                         char*    const result_buffer,
                         size_t&        result_size)
{
 CHECK_WRITE_TYPED_PTR(result_buffer,result_size);

 //-------
 namespace cs_nms=lib::structure::charsets;

 const auto
  result
   =cs_nms::cs_cvt__single_utf16_to_utf8
     (source,
      source_end,
      result_buffer,
      result_buffer+result_size);

 source
  =result.input;

 LCPI__assert(result.output>=(result_buffer));
 LCPI__assert(result.output<=(result_buffer+result_size));

 result_size
  =(result.output-result_buffer);

 IBP_TRANSLATE_UTF8_CVT_RESULT(result.code)
}//convert_single_unicode_to_own_v3

//------------------------------------------------------------------------
template<typename InputIterator,typename OutputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_utf8_traits::ucs2_to_own
                        (InputIterator& source,
                         InputIterator  source_end,
                         OutputIterator dest)
{
 namespace cs_nms=lib::structure::charsets;

 const auto
  result
   =cs_nms::cs_cvt__utf16_to_utf8
     (source,
      source_end,
      dest);

 source=result.input;

 IBP_TRANSLATE_UTF8_CVT_RESULT(result.code)
}//ucs2_to_own

//------------------------------------------------------------------------
#undef IBP_TRANSLATE_UTF8_CVT_RESULT

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
