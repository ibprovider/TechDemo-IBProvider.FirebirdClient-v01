////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_bit8__text_stream__ucs2_to_mbc.h
//! \brief   ��������� ������ UCS2-�������� � ����� MultiByte-��������
//! \author  Kovalenko Dmitry
//! \date    07.12.2008
#ifndef _ibp_cs_bit8__text_stream__ucs2_to_mbc_H_
#define _ibp_cs_bit8__text_stream__ucs2_to_mbc_H_

#include "source/charsets/cs_code/ibp_cs_bit8.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_bit8::tag_text_stream__ucs2_to_mbc

/// <summary>
///  ��������� ������ UCS2-�������� � ����� MultiByte-��������
/// </summary>
class t_ibp_cs_bit8::tag_text_stream__ucs2_to_mbc LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(db_obj::t_db_text_stream__mbc)
{
 private:
  using self_type=tag_text_stream__ucs2_to_mbc;

  tag_text_stream__ucs2_to_mbc(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~tag_text_stream__ucs2_to_mbc();

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] charset
  //!  Not NULL. ������� �������� ����������� MultiByte-��������
  //! \param[in] source__ucs2
  //!  Not NULL. �������� ����� UCS2-��������
  tag_text_stream__ucs2_to_mbc(const t_ibp_cs_bit8*            charset,
                               db_obj::t_db_text_stream__ucs2* source__ucs2);

  //t_db_text_stream__mbc interface --------------------------------------
  /// <summary>
  ///  ������ ��������
  /// </summary>
  //! \param[in]  op_ctx
  //! \param[in]  mbc_buffer_size
  //! \param[out] mbc_buffer
  //! \param[out] cb_readed
  //!  Not NULL
  //! \return
  //! - db_cs_result__ok
  //! - db_cs_result__fail
  virtual db_obj::t_db_cs_result
           read_mbc
            (db_obj::t_db_operation_context& op_ctx,
             size_type                       mbc_buffer_size,
             char*                           mbc_buffer,
             size_type*                      cb_readed) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private: //internal typedefs --------------------------------------------
  typedef structure::t_multi_thread_traits               thread_traits;
  typedef thread_traits::guard_type                      guard_type;
  typedef thread_traits::lock_guard_type                 lock_guard_type;

 private:
  ///MT-������ �������
  guard_type m_guard;

  ///������� �������� ��������� ������ MultiByte-��������
  t_ibp_cs_bit8::self_cptr const m_charset;

  ///����� MultiByte-��������
  db_obj::t_db_text_stream__ucs2_ptr const m_source__ucs2;

 private:
  ///������� ������� � ������ �������� ������
  size_type m_buffer_pos;

  ///���������� �������� � ������ �������� ������
  size_type m_buffer_size;

  ///����� �������� ������
  wchar_t m_buffer[4*1024];
};//class t_ibp_cs_bit8::tag_text_stream__ucs2_to_mbc

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
