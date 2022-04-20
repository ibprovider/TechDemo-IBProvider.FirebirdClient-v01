////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_bit8__text_stream__mbc_buffer_to_ucs2.h
//! \brief   ��������� ������� MultiByte-�������� � ����� UCS2-��������
//! \author  Kovalenko Dmitry
//! \date    12.12.2008
#ifndef _ibp_cs_bit8__text_stream__mbc_buffer_to_ucs2_H_
#define _ibp_cs_bit8__text_stream__mbc_buffer_to_ucs2_H_

#include "source/charsets/cs_code/ibp_cs_bit8.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_bit8::tag_text_stream__mbc_buffer_to_ucs2

/// <summary>
///  ��������� ������� MultiByte-�������� � ����� UCS2-��������
/// </summary>
class t_ibp_cs_bit8::tag_text_stream__mbc_buffer_to_ucs2
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(db_obj::t_db_text_stream__ucs2)
{
 private:
  typedef tag_text_stream__mbc_buffer_to_ucs2             self_type;

  tag_text_stream__mbc_buffer_to_ucs2(const self_type&);
  self_type& operator = (const self_type&);

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~tag_text_stream__mbc_buffer_to_ucs2();

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] charset
  //!  Not NULL. ������� �������� ������� MultiByte-��������
  //! \param[in] source_buffer
  //! \param[in] source_buffer_size
  tag_text_stream__mbc_buffer_to_ucs2(const t_ibp_cs_bit8* charset,
                                      const char*          source_buffer,
                                      size_type            source_buffer_size);

  //t_db_text_stream__ucs2 interface -------------------------------------
  /// <summary>
  ///  ������ UCS2-��������
  /// </summary>
  //! \param[in]  ucs2_buffer_size
  //! \param[out] ucs2_buffer
  //! \param[out] cb_readed
  //!  Not NULL
  virtual db_obj::t_db_cs_result
           read_ucs2
            (size_type  ucs2_buffer_size,
             wchar_t*   ucs2_buffer,
             size_type* cb_readed) COMP_W000004_OVERRIDE_FINAL;

 private: //internal typedefs --------------------------------------------
  typedef structure::t_multi_thread_traits               thread_traits;
  typedef thread_traits::guard_type                      guard_type;
  typedef thread_traits::lock_guard_type                 lock_guard_type;

 private:
  ///MT-������ �������
  guard_type m_guard;

  ///������� �������� ��������� ������ MultiByte-��������
  t_ibp_cs_bit8::self_cptr const m_charset;

 private:
  ///������� ������� � ������ �������� ������
  size_type m_source_buffer_pos;

  ///���������� �������� � ������ �������� ������
  size_type const m_source_buffer_size;

  ///����� �������� ������
  const char* const m_source_buffer;
};//class t_ibp_cs_bit8::tag_text_stream__mbc_buffer_to_ucs2

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
