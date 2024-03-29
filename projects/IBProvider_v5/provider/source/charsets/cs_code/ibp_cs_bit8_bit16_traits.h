////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_bit8_bit16_traits.h
//! \brief   ��������� � ������� ��� �������������� ������� ������� BIT8-BIT16
//! \author  Kovalenko Dmitry
//! \date    28.09.2008
#ifndef _ibp_cs_bit8_bit16_traits_H_
#define _ibp_cs_bit8_bit16_traits_H_

#include "source/db_obj/db_charset.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//struct t_ibp_cs_bit8_bit16_traits

/// <summary>
///  ��������� � ������� ��� �������������� ������� ������� BIT8_BIT16
/// </summary>
struct t_ibp_cs_bit8_bit16_traits LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  typedef unsigned short                    ushort_type;
  typedef unsigned char                     uchar_type;
  typedef size_t                            size_type;

  ///��������� �� ������� �������� �������
  using PFnTestChar
   =bool (*)
     (uchar_type ch);

 public: //consts --------------------------------------------------------
  ///����������� ������ ������� ������� ��������
  static const size_t c_char_size__min=sizeof(uchar_type);

  ///������������ ������ ������� ������� ��������
  static const size_t c_char_size__max=sizeof(ushort_type);

  ///������������ ���������� UCS2 (wchar_t) �������� ��� ������������� ������ UNICODE �������
  static const size_t c_max_ucs2_in_one_symbol=1;

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  t_ibp_cs_bit8_bit16_traits(const ushort_type* to_unicode_mapping_array,
                             size_type          to_unicode_mapping_array_size,
                             const ushort_type* to_unicode_map,
                             size_type          to_unicode_map_size,
                             const ushort_type* from_unicode_mapping_array,
                             size_type          from_unicode_mapping_array_size,
                             const ushort_type* from_unicode_map,
                             size_type          from_unicode_map_size,
                             PFnTestChar        is_single_ch_symbol,
                             PFnTestChar        is_valid_ch_1,
                             PFnTestChar        is_valid_ch_2);

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
  //!  - db_cs_result__input_trunc
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

 private: //--------------------------------------------------------------
  ///������ ������ � ������������� UCS2 �� BIT8_BIT16
  const ushort_type*                m_to_unicode_mapping_array;

  ///���������� ��������� � from_unicode_mapping_array
  size_type                         m_to_unicode_mapping_array_size;

  ///������ ������ to_unicode_mapping_array
  const ushort_type*                m_to_unicode_map;

  ///���������� ��������� � to_unicode_map
  size_type                         m_to_unicode_map_size;

 private: //--------------------------------------------------------------
  ///������ ������ � ������������� UCS2 �� BIT8_BIT16
  const ushort_type*                m_from_unicode_mapping_array;

  ///���������� ��������� � from_unicode_mapping_array
  size_type                         m_from_unicode_mapping_array_size;

  ///������ ������ from_unicode_mapping_array
  const ushort_type*                m_from_unicode_map;

  ///���������� ��������� � from_unicode_map
  size_type                         m_from_unicode_map_size;

 private: //--------------------------------------------------------------
  ///��������� �� ������� ����������� ������������ �������
  PFnTestChar                       m_is_single_ch_symbol;

  ///��������� �� ������� ������������ ������� ������� � ������������������
  PFnTestChar                       m_is_valid_ch_1;

  ///��������� �� ������� ������������ ������� ������� � ������������������
  PFnTestChar                       m_is_valid_ch_2;

};//struct t_ibp_cs_bit8_bit16_traits

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/cs_code/ibp_cs_bit8_bit16_traits.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
