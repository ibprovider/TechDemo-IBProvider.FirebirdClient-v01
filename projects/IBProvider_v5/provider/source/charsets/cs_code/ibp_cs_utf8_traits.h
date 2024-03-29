////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_utf8_traits.h
//! \brief   Алгоритмы преобразования кодовой страницы UTF8
//! \author  Kovalenko Dmitry
//! \date    23.07.2011
#ifndef _ibp_cs_utf8_traits_H_
#define _ibp_cs_utf8_traits_H_

#include "source/db_obj/db_charset.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_utf8_traits

/// <summary>
///  Алгоритмы преобразования кодовой страницы UTF8
/// </summary>
class t_ibp_cs_utf8_traits LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_ibp_cs_utf8_traits;

 public: //consts --------------------------------------------------------
  ///минимальный размер символа кодовой страницы
  static const size_t c_char_size__min=sizeof(char);

  ///максимальный размер символа кодовой страницы
  static const size_t c_char_size__max=4*sizeof(char);

  ///максимальное количество UCS2 (wchar_t) символов для представления одного UNICODE символа
  static const size_t c_max_ucs2_in_one_symbol=2;

 public:
  t_ibp_cs_utf8_traits(){;}

  /// <summary>
  ///  Conversion of single OWN symbol into UNICODE symbol
  /// </summary>
  //! \param[in,out] source
  //! \param[in]     source_end
  //! \param[out]    result_buffer
  //! \param[in,out] result_size
  //! \return
  //!  - db_cs_result__ok
  //!  - db_cs_result__fail
  //!  - db_cs_result__trunc
  template<typename InputIterator>
  db_obj::t_db_cs_result
   convert_single_own_to_unicode_v3
    (InputIterator& source,
     InputIterator  source_end,
     wchar_t*       result_buffer,
     size_t&        result_size)const;

  /// <summary>
  ///  Conversion of single UNICODE symbol to OWN symbol
  /// </summary>
  //! \param[in,out] source
  //! \param[in]     source_end
  //! \param[out]    result_buffer
  //! \param[in,out] result_size
  //! \return
  //!  - db_cs_result__ok
  //!  - db_cs_result__fail
  //!  - db_cs_result__trunc
  template<typename InputIterator>
  db_obj::t_db_cs_result
   convert_single_unicode_to_own_v3
    (InputIterator& source,
     InputIterator  source_end,
     char*          result_buffer,
     size_t&        result_size)const;

  /// <summary>
  ///  Generic algorithm for translation of UNICODE chars into own codepage
  /// </summary>
  //! \param[in,out] source
  //! \param[in]     source_end
  //! \param[in]     dest
  template<typename InputIterator,typename OutputIterator>
  db_obj::t_db_cs_result
   ucs2_to_own
    (InputIterator&  source,
     InputIterator   source_end,
     OutputIterator  dest)const;
};//class t_ibp_cs_utf8_traits

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/cs_code/ibp_cs_utf8_traits.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
