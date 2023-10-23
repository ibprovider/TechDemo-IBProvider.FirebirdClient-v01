////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v003
//! \file    ibp_cs_icu_v003.h
//! \brief   Внешняя кодовая страница из ICU v3
//! \author  Kovalenko Dmitry
//! \date    08.10.2008
#ifndef _ibp_cs_icu_v003_H_
#define _ibp_cs_icu_v003_H_

#include "source/charsets/cs_code/icu/v003/ibp_cs_icu_v003__provider.h"
#include "source/db_obj/db_charset.h"

namespace lcpi{namespace ibp{namespace charsets{namespace cs_code{namespace icu{namespace v003{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_cs_icu_v003
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_icu

/// <summary>
///  Внешняя кодовая страница из ICU v3
/// </summary>
class t_ibp_cs_icu LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(db_obj::t_db_charset)
{
 private:
  using self_type=t_ibp_cs_icu;

  t_ibp_cs_icu(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  ///Self smart-pointer
  using self_ptr
   =lib::structure::t_smart_object_ptr<self_type>;

  ///Self smart-pointer
  using self_cptr
   =structure::t_smart_object_ptr<const self_type>;

  using cs_name_box_type
   =lib::structure::t_basic_const_str_box<db_obj::t_db_charset_info::charset_name_type::value_type>;

 private:
  class tag_conv_holder;
  class tag_text_stream__mbc_to_ucs2;
  class tag_text_stream__mbc_buffer_to_ucs2;
  class tag_text_stream__ucs2_to_mbc;

 private:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] pICU
  //!  Not NULL
  //! \param[in] cs_info
  //! \param[in] icu_cs_name
  t_ibp_cs_icu(t_ibp_icu_provider*              pICU,
               const db_obj::t_db_charset_info& cs_info,
               const std::string&               icu_cs_name);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~t_ibp_cs_icu();

 public:
  /// <summary>
  ///  Фабрика класса
  /// </summary>
  //! \param[in] pICU
  //!  Not NULL
  //! \param[in] cs_name
  //!  Название кодовой страницы
  //! \param[in] must_be_created
  static self_ptr create(t_ibp_icu_provider*     pICU,
                         const cs_name_box_type& cs_name,
                         bool                    must_be_created);

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
           sb_to_unicode(ansi_streambuf_type& in_buf,
                         wchar_t*             ws,
                         size_type&           wsz)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  //вычисление длины потока в другой кодовой странице
  virtual bool sb_len_as_unicode(ansi_streambuf_type& in_buf,size_type& wsz)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Переконвертация UNICODE-строки с сохранением результата в BLOB
  /// </summary>
  //! \param[in]  source
  //! \param[in]  source_size
  //! \param[in]  writer
  //!  Not NULL
  virtual bool unicode_to_blob(const wchar_t*                  source,
                               size_type                       source_size,
                               db_obj::t_db_seq_stream_writer* writer)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  /// <summary>
  ///  Вызов ucnv_toUnicode и проверка работы
  /// </summary>
  //! \param[in]     conv
  //! \param[in,out] target_pptr
  //! \param[in]     target_end
  //! \param[in,out] source_pptr
  //! \param[in]     source_end
  //! \param[in]     flush
  //! \param[in,out] err
  void call__ucnv_toUnicode(api::UConverter*  conv,
                            api::UChar**      target_pptr,
                            const api::UChar* target_end,
                            const char**      source_pptr,
                            const char*       source_end,
                            bool              flush,
                            api::UErrorCode*  err)const;


  /// <summary>
  ///  Вызов ucnv_fromUnicode и проверка работы
  /// </summary>
  //! \param[in]     conv
  //! \param[in,out] target_pptr
  //! \param[in]     target_end
  //! \param[in,out] source_pptr
  //! \param[in]     source_end
  //! \param[in]     flush
  //! \param[in,out] err
  void call__ucnv_fromUnicode(api::UConverter*   conv,
                              char**             target_pptr,
                              const char*        target_end,
                              const api::UChar** source_pptr,
                              const api::UChar*  source_end,
                              bool               flush,
                              api::UErrorCode*   err)const;

 private:
  /// <summary>
  ///  Генерация BUG-CHECK ошибки
  /// </summary>
  //! \param[in] func_name
  //! \param[in] check_point
  COMP_CONF_DECLSPEC_NORETURN
  void Throw_BugCheck(const char* func_name,const wchar_t* check_point)const;

 private:
  ///Описание кодовой страницы
  const db_obj::t_db_charset_info m_cs_info;

  ///Провайдер к ICU API
  const t_ibp_icu_provider::self_ptr m_spICU;

  ///Ascii-имя кодовой страницы ICU
  const std::string m_icu_cs_name;
};//class t_ibp_cs_icu

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_icu::tag_conv_holder

/// <summary>
///  Класс для управления указателем на UConverter
/// </summary>
class t_ibp_cs_icu::tag_conv_holder LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef tag_conv_holder                   self_type;

  tag_conv_holder(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  enum enum_conv_direction
  {
   conv_direction__to_unicode   =0x01,
   conv_direction__from_unicode =0x02,

   conv_direction__both         =conv_direction__to_unicode|
                                 conv_direction__from_unicode
  };//enum_conv_direction

  typedef unsigned conv_direction_flags_type;

 public:
  /// <summary>
  ///  Конструктор инициализации. THROW
  /// </summary>
  //! \param[in] pICU
  //!  Not NULL
  explicit tag_conv_holder(t_ibp_icu_provider* pICU);

  /// <summary>
  ///  Конструктор инициализации. THROW
  /// </summary>
  //! \param[in] charset
  //!  Not NULL
  //! \param[in] direction_flags
  //!  Направление конвертирования
  tag_conv_holder(const t_ibp_cs_icu*       charset,
                  conv_direction_flags_type direction_flags);

  /// <summary>
  ///  Конструктор инициализации. THROW
  /// </summary>
  //! \param[in] pICU
  //!  Not NULL
  //! \param[in] icu_cs_name
  //! \param[in] direction_flags
  //!  Направление конвертирования
  tag_conv_holder(t_ibp_icu_provider*       pICU,
                  const std::string&        icu_cs_name,
                  conv_direction_flags_type direction_flags);

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~tag_conv_holder();

  //----------------------------------------------------------------------
  /// <summary>
  ///  Конструирование объекта
  /// </summary>
  //! \param[in] icu_cs_name
  //! \param[in] direction_flags
  //!  Направление конвертирования
  //! \param[in] must_be_created
  //!  Если false, то обрабатывается ошибка U_FILE_ACCESS_ERROR
  bool create(const std::string&        icu_cs_name,
              conv_direction_flags_type direction_flags,
              bool                      must_be_created);

  //selectors ------------------------------------------------------------
  /// <summary>
  ///  Получение указателя на ICU конвертор
  /// </summary>
  api::UConverter* ptr()const
   {return m_ptr;}

 private:
  /// <summary>
  ///  Освобождение ICU-конвертора
  /// <summary>
  void free();

 private:
  ///Указатель на провайдер ICU API
  const t_ibp_icu_provider::self_ptr m_spICU;

  ///ICU конвертор
  api::UConverter* m_ptr;
};//class t_ibp_cs_icu::tag_conv_holder

////////////////////////////////////////////////////////////////////////////////
}/*nms v003*/}/*nms icu*/}/*nms cs_code*/}/*nms charsets*/}/*nms ibp*/}/*nms lcpi*/
#endif
