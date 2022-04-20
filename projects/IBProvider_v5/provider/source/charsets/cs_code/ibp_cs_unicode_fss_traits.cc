////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_unicode_fss_traits.cc
//! \brief   Алгоритмы преобразования кодовой страницы UNICODE_FSS
//! \author  Kovalenko Dmitry
//! \date    23.07.2011
#ifndef _ibp_cs_unicode_fss_traits_CC_
#define _ibp_cs_unicode_fss_traits_CC_

#include <structure/charsets/t_cs_utf_fss.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_unicode_fss_traits

#define IBP_TRANSLATE_FSS_CVT_RESULT(cvt_result)     \
 switch(cvt_result)                                  \
 {                                                   \
  case cs_fss::cs_cvt_result__ok:                    \
   return db_obj::db_cs_result__ok;                  \
                                                     \
  case cs_fss::cs_cvt_result__small_output:          \
   return db_obj::db_cs_result__trunc;               \
                                                     \
  case cs_fss::cs_cvt_result__trunc_input:           \
   return db_obj::db_cs_result__input_trunc;         \
                                                     \
  default:                                           \
   return db_obj::db_cs_result__fail;                \
 }//switch cvt_result

//------------------------------------------------------------------------
template<typename InputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_unicode_fss_traits::convert_single_own_to_unicode_v3
                                           (InputIterator& source,
                                            InputIterator  source_end,
                                            wchar_t* const result_buffer,
                                            size_t&        result_size)const
{
 namespace cs_fss=structure::charsets::cs_utf_fss;

 cs_fss::t_cs_cvt_result cvt_result=cs_fss::cs_cvt_result__ok;

 source=cs_fss::single_fss_to_ucs2(source,
                                   source_end,
                                   result_buffer,
                                   result_size,
                                   &cvt_result);

 IBP_TRANSLATE_FSS_CVT_RESULT(cvt_result)
}//convert_single_own_to_unicode_v3

//------------------------------------------------------------------------
template<typename InputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_unicode_fss_traits::convert_single_unicode_to_own_v3
                                           (InputIterator&       source,
                                            InputIterator        source_end,
                                            char*          const result_buffer,
                                            size_t&              result_size)const
{
 namespace cs_fss=structure::charsets::cs_utf_fss;

 cs_fss::t_cs_cvt_result cvt_result=cs_fss::cs_cvt_result__ok;

 source=cs_fss::single_ucs2_to_fss(source,
                                   source_end,
                                   result_buffer,
                                   result_size,
                                   &cvt_result);

 IBP_TRANSLATE_FSS_CVT_RESULT(cvt_result)
}//convert_single_unicode_to_own_v3

//------------------------------------------------------------------------
template<typename InputIterator,typename OutputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_unicode_fss_traits::ucs2_to_own(InputIterator&  source,
                                          InputIterator   source_end,
                                          OutputIterator  dest)const
{
 namespace cs_fss=structure::charsets::cs_utf_fss;

 cs_fss::t_cs_cvt_result cvt_result=cs_fss::cs_cvt_result__ok;

 source=cs_fss::ucs2_to_fss(source,
                            source_end,
                            dest,
                            &cvt_result);

 IBP_TRANSLATE_FSS_CVT_RESULT(cvt_result)
}//ucs2_to_own

//------------------------------------------------------------------------
#undef IBP_TRANSLATE_FSS_CVT_RESULT

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
