////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_text_stream__mbc_buffer_to_ucs2.h
//! \brief   Универсальный конвертор массива MultiByte-символов в поток UCS2-символов
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
///  Универсальный конвертор массива MultiByte-символов в поток UCS2-символов
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
  ///  Деструктор
  /// </summary>
  virtual ~t_ibp_text_stream__mbc_buffer_to_ucs2();

 public: //typedefs ------------------------------------------------------
  typedef TCharset                                    charset_type;
  typedef typename charset_type::self_cptr            charset_cptr;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] charset
  //!  Not NULL. Кодовая страница входящего потока MultiByte-символов
  //! \param[in] source_buffer
  //! \param[in] source_buffer_size
  t_ibp_text_stream__mbc_buffer_to_ucs2(const charset_type* charset,
                                        const char*         source_buffer,
                                        size_type           source_buffer_size);
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

 private:
  ///Текущая позиция в буфере с невыгруженными UCS2-символами
  size_t m_target_buffer_pos;

  ///Количество символов в буфере с невыгруженными UCS2-символами
  size_t m_target_buffer_size;

  ///Буфер невыгруженных UCS2-символов
  wchar_t m_target_buffer[ibp_limc_MaxUnicodeSymbolsForOneMultiByteSymbol];

 private:
  ///Текущая позиция в буфере входящих данных
  size_type m_source_buffer_pos;

  ///Количество символов в буфере входящих данных
  const size_type m_source_buffer_size;

  ///Буфер входящих данных
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
