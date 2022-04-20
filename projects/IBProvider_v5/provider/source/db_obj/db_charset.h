////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_charset.h
//! \brief   Интерфейс перекодировщика кодовой страницы
//! \author  Kovalenko Dmitry
//! \date    05.10.2008
#ifndef _db_charset_H_
#define _db_charset_H_

#include "source/db_obj/db_charset_info.h"
#include "source/db_obj/db_text_stream__mbc.h"
#include "source/db_obj/db_text_stream__ucs2.h"
#include <structure/stream/t_istream_buffer.h>
#include <structure/utilities/string/string_compare_v2.h>

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_db_charset

/// <summary>
///  Интерфейс перекодировщика кодовой страницы
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE t_db_charset:public t_db_smart_interface
{
 public: //typedefs ------------------------------------------------------
  ///Тип, используемый для определения размера
  typedef size_t                                     size_type;

  typedef structure::t_basic_istream_buffer<char>    ansi_streambuf_type;

  class tag_less_by_name;

 public:
  /// <summary>
  ///  Получение описания кодовой страницы
  /// <summary>
  virtual const t_db_charset_info& get_info()const=0;

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
                             structure::t_const_str_box s)const=0;

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
                               structure::t_const_wstr_box ws)const=0;

  /// <summary>
  ///  Конвертирование потока MBC-символов в поток UCS2-символов
  /// </summary>
  //! \param[in] mbc_stream
  virtual t_db_text_stream__ucs2_ptr
           mbc_stream_to_ucs2_stream(t_db_text_stream__mbc* mbc_stream)const=0;

  /// <summary>
  ///  Конвертирование массива MBC-символов в поток UCS2-символов
  /// </summary>
  //! \param[in] mbc_buffer
  //! \param[in] mbc_buffer_size
  //! \return
  //!  Поток UCS2-символов
  //!
  //! \note Копирование массива MBC-символов не осуществляется
  virtual t_db_text_stream__ucs2_ptr
           mbc_buffer_to_ucs2_stream(const char* mbc_buffer,
                                     size_type   mbc_buffer_size)const=0;

  /// <summary>
  ///  Конвертирование потока UCS2-символов в поток MBC-символов
  /// </summary>
  //! \param[in] ucs2_stream
  virtual t_db_text_stream__mbc_ptr
           ucs2_stream_to_mbc_stream(t_db_text_stream__ucs2* ucs2_stream)const=0;

  /// <summary>
  ///  Конвертирование символьного потока в UNICODE символы
  /// </summary>
  //! \param[in]     in_buf
  //!  Поток символов
  //! \param[out]    ws
  //!  Указатель на результирующий буфер
  //! \param[in,out] wsz
  //!  На входе здесь передается размер ws.
  //!  На выходе возвращается количество записанных символов.
  virtual t_db_cs_result sb_to_unicode(ansi_streambuf_type&  in_buf,
                                       wchar_t*              ws,
                                       size_type&            wsz)const=0;

  /// <summary>
  ///  Вычисление длины потока в виде UNICODE символов
  /// </summary>
  //! \param[in,out] in_buf
  //! \param[out]    wsz
  //!  Число UNICODE символов
  //! \return
  //!  \b true - OK
  virtual bool sb_len_as_unicode(ansi_streambuf_type& in_buf,
                                 size_type&           wsz)const=0;

  /// <summary>
  ///  Переконвертация UNICODE-строки с сохранением результата в BLOB
  /// </summary>
  //! \param[in]  source
  //! \param[in]  source_size
  //! \param[in]  writer
  //!  Not NULL
  virtual bool unicode_to_blob(const wchar_t*          source,
                               size_type               source_size,
                               t_db_seq_stream_writer* writer)const=0;
};//class t_db_charset

////////////////////////////////////////////////////////////////////////////////
//class t_db_charset

class t_db_charset::tag_less_by_name
{
 public: //typedefs ------------------------------------------------------
  using cs_name_box_type
   =structure::t_basic_const_str_box<db_obj::t_db_charset_info::charset_name_type::value_type>;

 public:
  tag_less_by_name(){;}

  bool operator () (const t_db_charset* const cs1,const t_db_charset* const cs2)const
  {
   assert(cs1);
   assert(cs2);

   return helper__less(cs1->get_info().name,cs2->get_info().name);
  }

  bool operator () (const t_db_charset* const cs,cs_name_box_type::pointer name)const=delete;
  bool operator () (cs_name_box_type::pointer name,const t_db_charset* const cs)const=delete;

  bool operator () (const t_db_charset* const cs,const cs_name_box_type& name)const
  {
   assert(cs);

   return helper__less(cs->get_info().name,name);
  }

  bool operator () (const cs_name_box_type& name,const t_db_charset* const cs)const
  {
   assert(cs);

   return helper__less(name,cs->get_info().name);
  }

 private:
  static bool helper__less(const cs_name_box_type& n1,const cs_name_box_type& n2)
  {
   return structure::string_compare_v2
           (n1.data(),
            n1.size(),
            n2.data(),
            n2.size())<0;
  }//helper__less
};//class t_db_charset::tag_less_by_name

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
