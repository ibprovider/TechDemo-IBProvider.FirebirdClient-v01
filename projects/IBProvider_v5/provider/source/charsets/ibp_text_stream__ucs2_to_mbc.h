////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_text_stream__ucs2_to_mbc.h
//! \brief   Универсальный конвертор потока UCS2-символов в поток MultiByte-символов
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
///  Универсальный конвертор потока UCS2-символов в поток MultiByte-символов
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
  ///  Деструктор
  /// </summary>
  virtual ~t_ibp_text_stream__ucs2_to_mbc();

 public: //typedefs ------------------------------------------------------
  typedef TCharset                                    charset_type;
  typedef typename charset_type::self_cptr            charset_cptr;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] charset
  //!  Not NULL. Кодовая страница исходящего потока MultiByte-символов
  //! \param[in] source__ucs2
  //!  Not NULL
  t_ibp_text_stream__ucs2_to_mbc(const charset_type*             charset,
                                 db_obj::t_db_text_stream__ucs2* source__ucs2);


  //t_db_text_stream__ucs2 interface -------------------------------------
  /// <summary>
  ///  Чтение MultiByte-символов
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
  ///MT-защита объекта
  guard_type m_guard;

  ///Указатель на кодовую страницу потока MultiByte-символов
  charset_cptr const m_charset;

  ///Поток UCS2-символов
  db_obj::t_db_text_stream__ucs2_ptr const m_source__ucs2;

 private:
  ///Текущая позиция в буфере с невыгруженными MultiByte-символами
  size_t m_target_buffer_pos;

  ///Количество символов в буфере с невыгруженными MultiByte-символами
  size_t m_target_buffer_size;

  ///Буфер невыгруженных MultiByte-символов
  char   m_target_buffer[ibp_limc_MaxByteOfOneMultiByteSymbol];

 private:
  ///Текущая позиция в буфере входящих данных
  size_type m_source_buffer_pos;

  ///Количество символов в буфере входящих данных
  size_type m_source_buffer_size;

  ///Буфер входящих данных
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
