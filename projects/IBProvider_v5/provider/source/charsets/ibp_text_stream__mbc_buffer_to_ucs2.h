////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_text_stream__mbc_buffer_to_ucs2.h
//! \brief   ������������� ��������� ������� MultiByte-�������� � ����� UCS2-��������
//! \author  Kovalenko Dmitry
//! \date    08.12.2008
#ifndef _ibp_text_stream__mbc_buffer_to_ucs2_H_
#define _ibp_text_stream__mbc_buffer_to_ucs2_H_

#include "source/db_obj/db_text_stream__ucs2.h"
#include "source/db_obj/db_text_stream__mbc.h"
#include "source/ibp_limits.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_text_stream__mbc_buffer_to_ucs2

/// <summary>
///  ������������� ��������� ������� MultiByte-�������� � ����� UCS2-��������
/// </summary>
template<class TCharset>
class t_ibp_text_stream__mbc_buffer_to_ucs2
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(db_obj::t_db_text_stream__ucs2)
{
 private:
  typedef t_ibp_text_stream__mbc_buffer_to_ucs2<TCharset>    self_type;

  t_ibp_text_stream__mbc_buffer_to_ucs2(const self_type&);
  self_type& operator = (const self_type&);

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~t_ibp_text_stream__mbc_buffer_to_ucs2();

 public: //typedefs ------------------------------------------------------
  typedef TCharset                                    charset_type;
  typedef typename charset_type::self_cptr            charset_cptr;

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] charset
  //!  Not NULL. ������� �������� ��������� ������ MultiByte-��������
  //! \param[in] source_buffer
  //! \param[in] source_buffer_size
  t_ibp_text_stream__mbc_buffer_to_ucs2(const charset_type* charset,
                                        const char*         source_buffer,
                                        size_type           source_buffer_size);
  //t_db_text_stream__ucs2 interface -------------------------------------
  /// <summary>
  ///  ������ UCS2-��������
  /// </summary>
  //! \param[in]  ucs2_buffer_size
  //! \param[out] ucs2_buffer
  //! \param[out] cb_readed
  //!  Not NULL
  virtual db_obj::t_db_cs_result read_ucs2(size_type  ucs2_buffer_size,
                                           wchar_t*   ucs2_buffer,
                                           size_type* cb_readed) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private: //internal typedefs --------------------------------------------
  typedef structure::t_multi_thread_traits               thread_traits;
  typedef thread_traits::guard_type                      guard_type;
  typedef thread_traits::lock_guard_type                 lock_guard_type;

 private:
  ///MT-������ �������
  guard_type m_guard;

  ///��������� �� ������� �������� ������ MultiByte-��������
  charset_cptr const m_charset;

 private:
  ///������� ������� � ������ � �������������� UCS2-���������
  size_t m_target_buffer_pos;

  ///���������� �������� � ������ � �������������� UCS2-���������
  size_t m_target_buffer_size;

  ///����� ������������� UCS2-��������
  wchar_t m_target_buffer[ibp_limc_MaxUnicodeSymbolsForOneMultiByteSymbol];

 private:
  ///������� ������� � ������ �������� ������
  size_type m_source_buffer_pos;

  ///���������� �������� � ������ �������� ������
  const size_type m_source_buffer_size;

  ///����� �������� ������
  const char* const m_source_buffer;
};//class t_ibp_text_stream__mbc_buffer_to_ucs2

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/ibp_text_stream__mbc_buffer_to_ucs2.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
