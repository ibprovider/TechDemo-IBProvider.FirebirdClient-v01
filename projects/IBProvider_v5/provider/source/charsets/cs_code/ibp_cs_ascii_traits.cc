////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_ascii_traits.cc
//! \brief   Алгоритмы преобразования кодовой страницы ASCII
//! \author  Kovalenko Dmitry
//! \date    16.10.2008
#ifndef _ibp_cs_ascii_traits_CC_
#define _ibp_cs_ascii_traits_CC_

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_ascii_traits

template<typename InputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_ascii_traits::convert_single_own_to_unicode_v3
                                             (InputIterator& source,
                                              InputIterator  source_end,
                                              wchar_t*       result_buffer,
                                              size_t&        result_size)
{
 CHECK_WRITE_TYPED_PTR(result_buffer,result_size);

 //-----
 const size_t original_result_size=result_size;

 result_size=0;

 if(source==source_end)
  return db_obj::db_cs_result__ok;

 const UINT ch=UINT(*source);

 if(ch>127)
  return db_obj::db_cs_result__fail;

 if(original_result_size<1)
  return db_obj::db_cs_result__trunc;

 result_buffer[0]=wchar_t(ch);

 result_size=1;

 ++source;

 return db_obj::db_cs_result__ok;
}//convert_single_own_to_unicode_v3

//------------------------------------------------------------------------
template<typename InputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_ascii_traits::convert_single_unicode_to_own_v3
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

 const UINT wch=*source;

 if(wch>127)
  return db_obj::db_cs_result__fail;

 if(original_result_size<1)
  return db_obj::db_cs_result__trunc;

 result_buffer[0]=char(wch);

 result_size=1;

 ++source;

 return db_obj::db_cs_result__ok;
}//convert_single_unicode_to_own_v3

//------------------------------------------------------------------------
template<typename InputIterator,typename OutputIterator>
db_obj::t_db_cs_result
 t_ibp_cs_ascii_traits::ucs2_to_own(InputIterator&  source,
                                    InputIterator   source_end,
                                    OutputIterator  dest)
{
 for(;source!=source_end;++source,++dest)
 {
  const UINT wch=(*source);

  if(wch>127)
   return db_obj::db_cs_result__fail;

  *dest=char(wch);
 }//for source

 return db_obj::db_cs_result__ok;
}//ucs2_to_own

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
