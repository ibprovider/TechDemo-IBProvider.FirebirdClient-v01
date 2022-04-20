////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_bit8_bit16.h
//! \brief   Управляющий класс для кодовых страниц BIT8-BIT16
//! \author  Kovalenko Dmitry
//! \date    28.09.2008
#ifndef _ibp_cs_bit8_bit16_H_
#define _ibp_cs_bit8_bit16_H_

#include "source/db_obj/db_charset.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_bit8_bit16

/// <summary>
///  Управляющий класс для кодовых страниц BIT8-BIT16
/// </summary>
///  Требования к TCS_Traits
///  - t_db_cs_result convert_single_own_to_unicode_v3(...)
///  - t_db_cs_result convert_single_unicode_to_own_v3(...)
///  - t_db_cs_result ucs2_to_own(...)
template<class TCS_Traits>
class t_ibp_cs_bit8_bit16:public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(db_obj::t_db_charset)
{
 private:
  typedef t_ibp_cs_bit8_bit16<TCS_Traits>                 self_type;

  t_ibp_cs_bit8_bit16(const self_type&);
  self_type& operator = (const self_type&);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~t_ibp_cs_bit8_bit16();

 public:
  typedef structure::t_smart_object_ptr<const self_type>  self_cptr;

  typedef TCS_Traits                                      data_type;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] charset_info
  //! \param[in] data
  t_ibp_cs_bit8_bit16(const db_obj::t_db_charset_info& charset_info,
                      const data_type*                 data);

  //interface t_ibp_charset ----------------------------------------------
  virtual const db_obj::t_db_charset_info& get_info()const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  From ASCII to UCS2
  /// </summary>
  //! \param[out] pws
  //!  Not null.
  //! \param[in]  s
  //! \return
  //!  - \b true  - Успешное конвертирование
  //!  - \b false - Произошла ошибка конвертирования
  //!
  //! В случае ошибки конвертирования, значение (*pws) не определено
  virtual bool to_unicode_v2(std::wstring*              pws,
                             structure::t_const_str_box s)const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  From UCS2 To ASCII
  /// </summary>
  //! \param[out] ps
  //!  Not null.
  //! \param[in]  ws
  //! \return
  //!  - \b true  - Успешное конвертирование
  //!  - \b false - Произошла ошибка конвертирования
  //!
  //! В случае ошибки конвертирования, значение (*ps) не определено
  virtual bool from_unicode_v2(std::string*                ps,
                               structure::t_const_wstr_box ws)const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Конвертирование потока MBC-символов в поток UCS2-символов
  /// </summary>
  //! \param[in] mbc_stream
  virtual db_obj::t_db_text_stream__ucs2_ptr
           mbc_stream_to_ucs2_stream(db_obj::t_db_text_stream__mbc* mbc_stream)const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Конвертирование массива MBC-символов в поток UCS2-символов
  /// </summary>
  //! \param[in] mbc_buffer
  //! \param[in] mbc_buffer_size
  virtual db_obj::t_db_text_stream__ucs2_ptr
           mbc_buffer_to_ucs2_stream(const char* mbc_buffer,
                                     size_type   mbc_buffer_size)const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Конвертирование потока UCS2-символов в поток MBC-символов
  /// </summary>
  //! \param[in] ucs2_stream
  virtual db_obj::t_db_text_stream__mbc_ptr
           ucs2_stream_to_mbc_stream(db_obj::t_db_text_stream__ucs2* ucs2_stream)const COMP_W000004_OVERRIDE_FINAL;

  virtual db_obj::t_db_cs_result sb_to_unicode(ansi_streambuf_type& in_buf,
                                               wchar_t*             ws,
                                               size_type&           wsz)const COMP_W000004_OVERRIDE_FINAL;

  //вычисление длины потока в другой кодовой странице
  virtual bool sb_len_as_unicode(ansi_streambuf_type& in_buf,size_type& wsz)const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Переконвертация UNICODE-строки с сохранением результата в BLOB
  /// </summary>
  //! \param[in]  source
  //! \param[in]  source_size
  //! \param[in]  writer
  //!  Not NULL
  virtual bool unicode_to_blob(const wchar_t*                  source,
                               size_type                       source_size,
                               db_obj::t_db_seq_stream_writer* writer)const COMP_W000004_OVERRIDE_FINAL;

 public: //интерфейс коммуникации с потоковыми конверторами --------------
  db_obj::t_db_cs_result single_mbc_to_ucs2(const char**   source_beg,
                                            const char*    source_end,
                                            wchar_t*       target,
                                            size_t&        target_size)const;

  db_obj::t_db_cs_result single_ucs2_to_mbc(const wchar_t** source_beg,
                                            const wchar_t*  source_end,
                                            char*           target,
                                            size_t&         target_size)const;
 private:
  ///Описание кодовой страницы
  const db_obj::t_db_charset_info  m_charset_info;

  ///Указатель на таблицы перекодирования
  const data_type* const   m_data;
};//class t_ibp_cs_bit8_bit16

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <source/charsets/cs_code/ibp_cs_bit8_bit16.cc>
////////////////////////////////////////////////////////////////////////////////
#endif