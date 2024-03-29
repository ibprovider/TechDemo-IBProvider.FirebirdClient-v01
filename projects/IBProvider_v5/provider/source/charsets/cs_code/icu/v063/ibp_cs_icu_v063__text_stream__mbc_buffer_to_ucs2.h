////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v063
//! \file    ibp_cs_icu_v063__text_stream__mbc_buffer_to_ucs2.h
//! \brief   ��������� ������� MultiByte-�������� � ����� UCS2-��������
//! \author  Kovalenko Dmitry
//! \date    15.06.2023
#ifndef _ibp_cs_icu_v063__text_stream__mbc_buffer_to_ucs2_H_
#define _ibp_cs_icu_v063__text_stream__mbc_buffer_to_ucs2_H_

#include "source/charsets/cs_code/icu/v063/ibp_cs_icu_v063.h"
#include "source/ibp_limits.h"

#include <lcpi/lib/structure/mt/t_guard.h>
#include <lcpi/lib/structure/mt/t_lock_guard.h>

namespace lcpi{namespace ibp{namespace charsets{namespace cs_code{namespace icu{namespace v063{
////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v063
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_icu::tag_text_stream__mbc_buffer_to_ucs2

/// <summary>
///  ��������� ������� MultiByte-�������� � ����� UCS2-��������
/// </summary>
class t_ibp_cs_icu::tag_text_stream__mbc_buffer_to_ucs2 LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(db_obj::t_db_text_stream__ucs2)
{
 private:
  using self_type=tag_text_stream__mbc_buffer_to_ucs2;

  tag_text_stream__mbc_buffer_to_ucs2(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~tag_text_stream__mbc_buffer_to_ucs2();

 public: //typedefs ------------------------------------------------------
  typedef t_ibp_cs_icu                              charset_type;
  typedef charset_type::tag_conv_holder             tag_conv_holder;
  typedef charset_type::self_cptr                   charset_cptr;

  typedef size_t                                    size_type;

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] charset
  //! \param[in] source_buffer
  //! \param[in] source_buffer_size
  tag_text_stream__mbc_buffer_to_ucs2(const charset_type* charset,
                                      const char*         source_buffer,
                                      size_type           source_buffer_size);

  //t_db_text_stream__ucs2 interface -------------------------------------
  /// <summary>
  ///  ������ UCS2-��������
  /// </summary>
  //! \param[in]  op_ctx
  //! \param[in]  ucs2_buffer_size
  //! \param[out] ucs2_buffer
  //! \param[out] cb_readed
  //!  Not NULL
  virtual db_obj::t_db_cs_result
           read_ucs2
            (db_obj::t_db_operation_context& op_ctx,
             size_type                       ucs2_buffer_size,
             wchar_t*                        ucs2_buffer,
             size_type*                      cb_readed) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private: //internal typedefs --------------------------------------------
  using guard_type
   =lib::structure::mt::t_guard;

  using lock_guard_type
   =lib::structure::mt::t_lock_guard<guard_type>;

 private:
  ///MT-������ �������
  guard_type m_guard;

  ///��������� �� ������� �������� MultiByte-��������
  charset_cptr const m_charset;

  ///ICU-���������
  tag_conv_holder m_icu_conv;

 private:
  ///������� ������� � ������ � �������������� UCS2-���������
  size_t m_target_buffer_pos;

  ///���������� �������� � ������ � �������������� UCS2-���������
  size_t m_target_buffer_size;

  ///����� ������������� UCS2-��������
  wchar_t m_target_buffer[4*1024];

 private:
  ///������� ������� � ������ �������� ������
  size_type m_source_buffer_pos;

  ///���������� �������� � ������ �������� ������
  const size_type m_source_buffer_size;

  ///����� �������� ������
  const char* const m_source_buffer;
};//class t_ibp_cs_icu::tag_text_stream__mbc_buffer_to_ucs2

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms v063*/}/*nms icu*/}/*nms cs_code*/}/*nms charsets*/}/*nms ibp*/}/*nms lcpi*/
#endif
