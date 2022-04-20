////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_ascii_traits.h
//! \brief   ��������� �������������� ������� �������� ASCII
//! \author  Kovalenko Dmitry
//! \date    16.10.2008
#ifndef _ibp_cs_ascii_traits_H_
#define _ibp_cs_ascii_traits_H_

#include "source/db_obj/db_charset.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� �������������� ������� �������� ASCII
/// </summary>
class t_ibp_cs_ascii_traits
{
 private:
  typedef t_ibp_cs_ascii_traits             self_type;

 public: //consts --------------------------------------------------------
  ///����������� ������ ������� ������� ��������
  static const size_t c_char_size__min=sizeof(char);

  ///������������ ������ ������� ������� ��������
  static const size_t c_char_size__max=sizeof(char);

  ///������������ ���������� UCS2 (wchar_t) �������� ��� ������������� ������ UNICODE �������
  static const size_t c_max_ucs2_in_one_char=1;

 public:
  t_ibp_cs_ascii_traits(){;}

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
};//class t_ibp_cs_ascii_traits

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/cs_code/ibp_cs_ascii_traits.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
