////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_octets.h
//! \brief   Заглушка для представления кодовой страницы OCTETS
//! \author  Kovalenko Dmitry
//! \date    22.01.2009
#ifndef _ibp_cs_octets_H_
#define _ibp_cs_octets_H_

#include "source/db_obj/db_charset.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_octets

/// <summary>
///  Заглушка для представления кодовой страницы OCTETS
/// </summary>
class t_ibp_cs_octets:public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(db_obj::t_db_charset)
{
 private:
  typedef t_ibp_cs_octets                   self_type;

  t_ibp_cs_octets(const self_type&);
  self_type& operator = (const self_type&);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~t_ibp_cs_octets();

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] cs_info
  explicit t_ibp_cs_octets(const db_obj::t_db_charset_info& cs_info);

  //t_db_charset interface -----------------------------------------------
  virtual const db_obj::t_db_charset_info&
           get_info()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

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

  virtual db_obj::t_db_text_stream__ucs2_ptr
           mbc_stream_to_ucs2_stream(db_obj::t_db_text_stream__mbc* mbc_stream)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual db_obj::t_db_text_stream__ucs2_ptr
           mbc_buffer_to_ucs2_stream(const char* mbc_buffer,
                                     size_type   mbc_buffer_size)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual db_obj::t_db_text_stream__mbc_ptr
           ucs2_stream_to_mbc_stream(db_obj::t_db_text_stream__ucs2* ucs2_stream)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual db_obj::t_db_cs_result
           sb_to_unicode(ansi_streambuf_type& in_buf,
                         wchar_t*             ws,
                         size_type&           wsz)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  //вычисление длины потока в другой кодовой странице
  virtual bool sb_len_as_unicode(ansi_streambuf_type& in_buf,
                                 size_type&           wsz)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool unicode_to_blob(db_obj::t_db_operation_context& op_ctx,
                               const wchar_t*                  source,
                               size_type                       source_size,
                               db_obj::t_db_seq_stream_writer* writer)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  ///Описание кодовой страницы
  const db_obj::t_db_charset_info m_cs_info;
};//class t_ibp_cs_octets

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
