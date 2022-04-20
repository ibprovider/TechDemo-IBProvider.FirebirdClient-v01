////////////////////////////////////////////////////////////////////////////////
//BASE64 MIME. Block Decoder
//                                               Kovalenko Dmitry. 19.11.2010.
#ifndef _t_base64_mime__block_decoder_H_
#define _t_base64_mime__block_decoder_H_

#include <structure/t_char_traits2.h>

namespace structure{namespace charsets{
////////////////////////////////////////////////////////////////////////////////
//class t_base64_mime__block_decoder

/// <summary>
///  Класс для раскодирования четырех-символьного блока MIME-строки
/// <summary>
template<typename charT>
class t_base64_mime__block_decoder
{
 private:
  typedef t_base64_mime__block_decoder<charT>   self_type;

  t_base64_mime__block_decoder(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef charT                                 char_type;
  typedef structure::t_char_traits2<char_type>  char_traits2;

  typedef unsigned __int8                       byte_type;

  typedef size_t                                size_type;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  t_base64_mime__block_decoder();
  
  //interface ------------------------------------------------------------
  /// <summary>
  ///  Завершено формирование трехбайтного блока
  /// </summary>
  bool complete()const;
  
  /// <summary>
  ///  Количество байт в результирующем массиве
  /// </summary>
  //! \attention
  //!  Вызывать только для сформированного блока
  size_type result_size()const;

  /// <summary>
  ///  Получение байта из результирующего массива
  /// </summary>
  //! \param[in] i
  //!  Индекс байта
  //!
  //! \attention
  //!  Вызывать только для сформированного блока
  byte_type result_byte(size_type i)const;

  /// <summary>
  ///  Обработка MIME-символа
  /// </summary>
  //! \return
  //!  true, если символ был обработан без ошибок
  bool push(char_type mime_ch);

 private:
  typedef std::pair<byte_type,bool>         decode_ch_result_type;

 private:
  /// <summary>
  ///  Сброс буфера с байтами
  /// </summary>
  void reset_bytes();
  
  /// <summary>
  ///  Декодирование BASE64 символа
  /// </summary>
  //! \param[in] base64_ch
  static decode_ch_result_type decode_ch(char_type base64_ch);

 private:
  ///Число MIME-символов текущего блока
  size_type m_nMimeChars;

  ///Число выравнивающих символов
  size_type m_nAlignChars;

  byte_type m_Bytes[3];
};//class t_base64_mime__block_decoder

////////////////////////////////////////////////////////////////////////////////
}/*nms charsets*/}/*nms structure*/
////////////////////////////////////////////////////////////////////////////////
#include <structure/charsets/t_base64_mime__block_decoder.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
