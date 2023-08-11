////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v052
//! \file    ibp_cs_icu_v052__text_stream__ucs2_to_mbc.h
//! \brief   Конвертор потока UCS2-символов в поток MultiByte-символов
//! \author  Kovalenko Dmitry
//! \date    20.07.2017
#ifndef _ibp_cs_icu_v052__text_stream__ucs2_to_mbc_H_
#define _ibp_cs_icu_v052__text_stream__ucs2_to_mbc_H_

#include "source/charsets/cs_code/icu/v052/ibp_cs_icu_v052.h"
#include "source/ibp_limits.h"

namespace lcpi{namespace ibp{namespace charsets{namespace cs_code{namespace icu{namespace v052{
////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v052
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_icu::tag_text_stream__ucs2_to_mbc

class t_ibp_cs_icu::tag_text_stream__ucs2_to_mbc LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(db_obj::t_db_text_stream__mbc)
{
 private:
  typedef tag_text_stream__ucs2_to_mbc   self_type;

  tag_text_stream__ucs2_to_mbc(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~tag_text_stream__ucs2_to_mbc();

 public: //typedefs ------------------------------------------------------
  typedef t_ibp_cs_icu                              charset_type;
  typedef charset_type::tag_conv_holder             tag_conv_holder;
  typedef charset_type::self_cptr                   charset_cptr;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] charset
  //!  Not NULL
  //! \param[in] source_ucs2
  //!  Not NULL
  tag_text_stream__ucs2_to_mbc(const charset_type*             charset,
                               db_obj::t_db_text_stream__ucs2* source__ucs2);

  //t_db_text_stream__mbc interface --------------------------------------
  /// <summary>
  ///  Чтение символов
  /// </summary>
  //! \param[in]  mbc_buffer_size
  //! \param[out] mbc_buffer
  //! \param[out] cb_readed
  //!  Not NULL
  //! \return
  //! - db_cs_result__ok
  //! - db_cs_result__fail
  virtual db_obj::t_db_cs_result read_mbc(size_type  mbc_buffer_size,
                                          char*      mbc_buffer,
                                          size_type* cb_readed) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private: //internal typedefs --------------------------------------------
  typedef structure::t_multi_thread_traits               thread_traits;
  typedef thread_traits::guard_type                      guard_type;
  typedef thread_traits::lock_guard_type                 lock_guard_type;

 private:
  ///MT-защита объекта
  guard_type m_guard;

  ///Указатель на кодовую страницу потока MultiByte-символов
  charset_cptr const m_charset;

  ///Поток MultiByte-символов
  db_obj::t_db_text_stream__ucs2_ptr const m_source__ucs2;

  ///ICU-конвертор
  tag_conv_holder m_icu_conv;

  ///Достижение конца входящего потока
  bool m_get_eof;

 private:
  ///Текущая позиция в буфере с невыгруженными MultiByte-символами
  size_t m_target_buffer_pos;

  ///Количество символов в буфере с невыгруженными MultiByte-символами
  size_t m_target_buffer_size;

  ///Буфер невыгруженных UCS2-символов
  char   m_target_buffer[8*1024];

 private:
  ///Текущая позиция в буфере входящих данных
  size_type m_source_buffer_pos;

  ///Количество символов в буфере входящих данных
  size_type m_source_buffer_size;

  ///Буфер входящих данных
  wchar_t m_source_buffer[4*1024];
};//class t_ibp_cs_icu::tag_text_stream__ucs2_to_mbc

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms v052*/}/*nms icu*/}/*nms cs_code*/}/*nms charsets*/}/*nms ibp*/}/*nms lcpi*/
#endif
