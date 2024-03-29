////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_base64_mime__text_stream__ucs2_to_mbc.h
//! \brief   BASE64 [MIME]. ��������� ������ UCS2-�������� � ����� MBC-��������.
//! \author  Kovalenko Dmitry
//! \date    18.11.2008
#ifndef _ibp_cs_base64_mime__text_stream__ucs2_to_mbc_H_
#define _ibp_cs_base64_mime__text_stream__ucs2_to_mbc_H_

#include "source/charsets/cs_code/ibp_cs_base64_mime.h"
#include <structure/charsets/t_base64_mime__block_decoder.h>

#include <lcpi/lib/structure/mt/t_guard.h>
#include <lcpi/lib/structure/mt/t_lock_guard.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_base64_mime::tag_text_stream__ucs2_to_mbc

/// <summary>
///  BASE64 [MIME]. ��������� ������ UCS2-�������� � ����� MBC-��������.
/// </summary>
class t_ibp_cs_base64_mime::tag_text_stream__ucs2_to_mbc LCPI_CPP_CFG__CLASS__FINAL
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

 public: //typedefs ------------------------------------------------------
  typedef wchar_t                                         source_char_type;
  typedef structure::t_char_traits2<source_char_type>     source_char_traits2;

  typedef char                                            dest_char_type;

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] source__ucs2
  //!  ����� �������� UCS2-��������. Not NULL.
  explicit tag_text_stream__ucs2_to_mbc(db_obj::t_db_text_stream__ucs2* source__ucs2);

  //t_db_text_stream__mbc interface --------------------------------------
  /// <summary>
  ///  ������ ��������
  /// </summary>
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
  using guard_type
   =lib::structure::mt::t_guard;

  using lock_guard_type
   =lib::structure::mt::t_lock_guard<guard_type>;

  /// <summary>
  ///  ������������ ��������� ����������
  /// </summary>
  enum tag_state_id
  {
   ///��������� MIME ��������
   state_id__process_mime_chars      =0,

   ///��������� ������������ ��������
   state_id__process_terminate_space =1,
  };//enum tag_state_id

  using mime_decoder_type
   =structure::charsets::t_base64_mime__block_decoder<source_char_type>;

 private:
  /// <summary>
  ///  ��������� ���������� ������� �� m_source__ucs2
  /// </summary>
  //! \return
  //!  ��� ���������� ��� read_mbc
  db_obj::t_db_cs_result ev_finish()const;

 private:
  ///MT-������ �������
  guard_type m_guard;

 private:
  ///����� �������� UCS2-��������. Not NULL.
  db_obj::t_db_text_stream__ucs2_ptr const m_source__ucs2;

  ///��������� ����������
  tag_state_id m_state_id;

  ///������� ������ � MIME-���������
  mime_decoder_type m_mime_decoder;

 private:
  ///������� ������� � ������ �������� ������
  size_type m_buffer_pos;

  ///���������� �������� � ������ �������� ������
  size_type m_buffer_size;

  ///����� �������� ������
  source_char_type m_buffer[4*1024];
};//class t_ibp_cs_base64_mime::tag_text_stream__ucs2_to_mbc

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
