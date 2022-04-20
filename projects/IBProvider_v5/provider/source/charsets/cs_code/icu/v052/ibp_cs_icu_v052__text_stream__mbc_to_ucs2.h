////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v052
//! \file    ibp_cs_icu_v052__text_stream__mbc_to_ucs2.h
//! \brief   Конвертор потока MultiByte-символов в поток UCS2-символов
//! \author  Kovalenko Dmitry
//! \date    20.07.2017
#ifndef _ibp_cs_icu_v052__text_stream__mbc_to_ucs2_H_
#define _ibp_cs_icu_v052__text_stream__mbc_to_ucs2_H_

#include "source/charsets/cs_code/icu/v052/ibp_cs_icu_v052.h"
#include "source/ibp_limits.h"

namespace lcpi{namespace ibp{namespace charsets{namespace cs_code{namespace icu{namespace v052{
////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v052
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_icu::tag_text_stream__mbc_to_ucs2

class t_ibp_cs_icu::tag_text_stream__mbc_to_ucs2
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(db_obj::t_db_text_stream__ucs2)
{
 private:
  typedef tag_text_stream__mbc_to_ucs2              self_type;

  tag_text_stream__mbc_to_ucs2(const self_type&);
  self_type& operator = (const self_type&);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~tag_text_stream__mbc_to_ucs2();

 public: //typedefs ------------------------------------------------------
  typedef t_ibp_cs_icu                              charset_type;
  typedef charset_type::tag_conv_holder             tag_conv_holder;
  typedef charset_type::self_cptr                   charset_cptr;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  tag_text_stream__mbc_to_ucs2(const charset_type*            charset,
                               db_obj::t_db_text_stream__mbc* source__mbc);

  //t_db_text_stream__ucs2 interface -------------------------------------
  /// <summary>
  ///  Чтение UCS2-символов
  /// </summary>
  //! \param[in]  ucs2_buffer_size
  //! \param[out] ucs2_buffer
  //! \param[out] cb_readed
  //!  Not NULL
  virtual db_obj::t_db_cs_result read_ucs2(size_type  ucs2_buffer_size,
                                           wchar_t*   ucs2_buffer,
                                           size_type* cb_readed) COMP_W000004_OVERRIDE_FINAL;

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
  db_obj::t_db_text_stream__mbc_ptr const m_source__mbc;

  ///ICU-конвертор
  tag_conv_holder m_icu_conv;

  ///Достижение конца входящего потока
  bool m_get_eof;

 private:
  ///Текущая позиция в буфере с невыгруженными UCS2-символами
  size_t m_target_buffer_pos;

  ///Количество символов в буфере с невыгруженными UCS2-символами
  size_t m_target_buffer_size;

  ///Буфер невыгруженных UCS2-символов
  wchar_t m_target_buffer[4*1024];

 private:
  ///Текущая позиция в буфере входящих данных
  size_type m_source_buffer_pos;

  ///Количество символов в буфере входящих данных
  size_type m_source_buffer_size;

  ///Буфер входящих данных
  char m_source_buffer[8*1024];
};//class t_ibp_cs_icu::tag_text_stream__mbc_to_ucs2

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms v052*/}/*nms icu*/}/*nms cs_code*/}/*nms charsets*/}/*nms ibp*/}/*nms lcpi*/
#endif
