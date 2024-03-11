////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_bit8.h
//! \brief   Управляющий класс для кодовых страниц BIT8
//! \author  Kovalenko Dmitry
//! \date    27.09.2005
#ifndef _ibp_cs_bit8_H_
#define _ibp_cs_bit8_H_

#include "source/charsets/cs_code/ibp_cs_bit8_map.h"
#include "source/db_obj/db_charset.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_bit8

/// <summary>
///  Управляющий класс для кодовых страниц BIT8
/// </summary>
class t_ibp_cs_bit8 LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(db_obj::t_db_charset)
{
 private:
  using self_type=t_ibp_cs_bit8;

  t_ibp_cs_bit8(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~t_ibp_cs_bit8();

 public: //typedefs ------------------------------------------------------
  using self_cptr=lib::structure::t_smart_object_ptr<const self_type>;

  typedef t_ibp_cs_bit8_map                                data_type;

  typedef data_type::uchar_type                            uchar_type;
  typedef data_type::ushort_type                           ushort_type;

 private:
  class tag_text_stream__mbc_to_ucs2;
  class tag_text_stream__mbc_buffer_to_ucs2;
  class tag_text_stream__ucs2_to_mbc;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] charset_info
  //! \param[in] data
  t_ibp_cs_bit8(const db_obj::t_db_charset_info& charset_info,
                const data_type*                 data);

  //t_db_charset interface -----------------------------------------------
  virtual const db_obj::t_db_charset_info& get_info()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

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
                             structure::t_const_str_box s)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

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
                               structure::t_const_wstr_box ws)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Конвертирование потока MBC-символов в поток UCS2-символов
  /// </summary>
  //! \param[in] mbc_stream
  virtual db_obj::t_db_text_stream__ucs2_ptr
           mbc_stream_to_ucs2_stream(db_obj::t_db_text_stream__mbc* mbc_stream)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Конвертирование массива MBC-символов в поток UCS2-символов
  /// </summary>
  //! \param[in] mbc_buffer
  //! \param[in] mbc_buffer_size
  virtual db_obj::t_db_text_stream__ucs2_ptr
           mbc_buffer_to_ucs2_stream(const char* mbc_buffer,
                                     size_type   mbc_buffer_size)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Конвертирование потока UCS2-символов в поток MBC-символов
  /// </summary>
  //! \param[in] ucs2_stream
  virtual db_obj::t_db_text_stream__mbc_ptr
           ucs2_stream_to_mbc_stream(db_obj::t_db_text_stream__ucs2* ucs2_stream)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual db_obj::t_db_cs_result
           sb_to_unicode
            (ansi_streambuf_type& in_buf,
             wchar_t*             ws,
             size_type&           wsz)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  //вычисление длины потока в другой кодовой странице
  virtual bool sb_len_as_unicode(ansi_streambuf_type& in_buf,size_type& wsz)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Переконвертация UNICODE-строки с сохранением результата в BLOB
  /// </summary>
  //! \param[in]  op_ctx
  //! \param[in]  source
  //! \param[in]  source_size
  //! \param[in]  writer
  //!  Not NULL
  virtual bool unicode_to_blob(db_obj::t_db_operation_context& op_ctx,
                               const wchar_t*                  source,
                               size_type                       source_size,
                               db_obj::t_db_seq_stream_writer* writer)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  ///Описание кодовой страницы
  const db_obj::t_db_charset_info m_charset_info;

  ///Указатель на таблицы перекодирования
  const data_type* const m_data;
};//class t_ibp_cs_bit8

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
