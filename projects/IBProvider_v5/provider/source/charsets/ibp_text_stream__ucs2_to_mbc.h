////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_text_stream__ucs2_to_mbc.h
//! \brief   ������������� ��������� ������ UCS2-�������� � ����� MultiByte-��������
//! \author  Kovalenko Dmitry
//! \date    09.12.2008
#ifndef _ibp_text_stream__ucs2_to_mbc_H_
#define _ibp_text_stream__ucs2_to_mbc_H_

#include "source/db_obj/db_text_stream__mbc.h"
#include "source/db_obj/db_text_stream__ucs2.h"
#include "source/ibp_limits.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_text_stream__ucs2_to_mbc

/// <summary>
///  ������������� ��������� ������ UCS2-�������� � ����� MultiByte-��������
/// </summary>
template<class TCharset>
class t_ibp_text_stream__ucs2_to_mbc
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(db_obj::t_db_text_stream__mbc)
{
 private:
  typedef t_ibp_text_stream__ucs2_to_mbc<TCharset>    self_type;

  t_ibp_text_stream__ucs2_to_mbc(const self_type&);
  self_type& operator = (const self_type&);

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~t_ibp_text_stream__ucs2_to_mbc();

 public: //typedefs ------------------------------------------------------
  typedef TCharset                                    charset_type;
  typedef typename charset_type::self_cptr            charset_cptr;

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] charset
  //!  Not NULL. ������� �������� ���������� ������ MultiByte-��������
  //! \param[in] source__ucs2
  //!  Not NULL
  t_ibp_text_stream__ucs2_to_mbc(const charset_type*             charset,
                                 db_obj::t_db_text_stream__ucs2* source__ucs2);


  //t_db_text_stream__ucs2 interface -------------------------------------
  /// <summary>
  ///  ������ MultiByte-��������
  /// </summary>
  //! \param[in]  mbc_buffer_size
  //! \param[out] mbc_buffer
  //! \param[out] cb_readed
  //!  Not NULL
  virtual db_obj::t_db_cs_result read_mbc(size_type  mbc_buffer_size,
                                          char*      mbc_buffer,
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

  ///����� UCS2-��������
  db_obj::t_db_text_stream__ucs2_ptr const m_source__ucs2;

 private:
  ///������� ������� � ������ � �������������� MultiByte-���������
  size_t m_target_buffer_pos;

  ///���������� �������� � ������ � �������������� MultiByte-���������
  size_t m_target_buffer_size;

  ///����� ������������� MultiByte-��������
  char   m_target_buffer[ibp_limc_MaxByteOfOneMultiByteSymbol];

 private:
  ///������� ������� � ������ �������� ������
  size_type m_source_buffer_pos;

  ///���������� �������� � ������ �������� ������
  size_type m_source_buffer_size;

  ///����� �������� ������
  wchar_t m_source_buffer[4*1024];
};//class t_ibp_text_stream__ucs2_to_mbc

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/ibp_text_stream__ucs2_to_mbc.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
