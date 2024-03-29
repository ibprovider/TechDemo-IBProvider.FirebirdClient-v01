////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_base64_mime__text_stream__mbc_buffer_to_ucs2.h
//! \brief   BASE64 [MIME]. Конвертор массива MBC-символов в поток UCS2 символов.
//! \author  Kovalenko Dmitry
//! \date    19.11.2010
#ifndef _ibp_cs_base64_mime__text_stream__mbc_buffer_to_ucs2_H_
#define _ibp_cs_base64_mime__text_stream__mbc_buffer_to_ucs2_H_

#include "source/charsets/cs_code/ibp_cs_base64_mime.h"
#include <structure/charsets/t_base64_mime__block_decoder.h>

#include <lcpi/lib/structure/mt/t_guard.h>
#include <lcpi/lib/structure/mt/t_lock_guard.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_base64_mime::tag_text_stream__mbc_buffer_to_ucs2

/// <summary>
///  BASE64 [MIME]. Конвертор массива MBC-символов в поток UCS2 символов.
/// <summary>
class t_ibp_cs_base64_mime::tag_text_stream__mbc_buffer_to_ucs2 LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(db_obj::t_db_text_stream__ucs2)
{
 private:
  using self_type=t_ibp_cs_base64_mime::tag_text_stream__mbc_buffer_to_ucs2;

  t_ibp_cs_base64_mime::tag_text_stream__mbc_buffer_to_ucs2(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~tag_text_stream__mbc_buffer_to_ucs2();

 public: //typedefs ------------------------------------------------------
  typedef char                                            source_char_type;
  typedef structure::t_char_traits2<source_char_type>     source_char_traits2;

  typedef wchar_t                                         dest_char_type;

 public:
  /// <summary>
  ///  Конструктор инициалиализации
  /// </summary>
  //! \param[in] source_buffer
  //!  Указатель на буфер входящих MBC-символов
  //! \param[in] source_buffer_size
  //!  Количество символов в source_buffer
  tag_text_stream__mbc_buffer_to_ucs2(const source_char_type* source_buffer,
                                      size_type               source_buffer_size);

  //t_db_text_stream__ucs2 interface -------------------------------------
  /// <summary>
  ///  Чтение UCS2-символов
  /// </summary>
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

  /// <summary>
  ///  Перечисление состояний конвертора
  /// </summary>
  enum tag_state_id
  {
   ///Обработка MIME символов
   state_id__process_mime_chars      =0,

   ///Обработка терминальных пробелов
   state_id__process_terminate_space =1,
  };//enum tag_state_id

  typedef structure::charsets::t_base64_mime__block_decoder<source_char_type>
   mime_decoder_type;

 private:
  /// <summary>
  ///  Обработка завершения выборки из m_source__mbc
  /// </summary>
  //! \return
  //!  Код завершения для read_ucs2
  db_obj::t_db_cs_result ev_finish()const;

 private:
  ///MT-защита объекта
  guard_type m_guard;

 private:
  ///Указатель на буфер обрабатываемых MBC-символов
  const source_char_type* const m_source_buffer;

  ///Количество символов в m_source_buffer
  const size_type               m_source_buffer_size;

  ///Текущая позиция в m_source_buffer
  size_type                     m_source_buffer_pos;

 private:
  ///Состояние конвертора
  tag_state_id                  m_state_id;

  ///Декодер потока с MIME-символами
  mime_decoder_type             m_mime_decoder;
};//class t_ibp_cs_base64_mime::tag_text_stream__mbc_buffer_to_ucs2

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
