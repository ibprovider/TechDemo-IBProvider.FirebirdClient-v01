////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_param_buffer_v1_builder.h
//! \brief   Класс для формирования буфера с параметрами (v2).
//! \author  Kovalenko Dmitry
//! \date    20.04.2016
#ifndef _isc_param_buffer_v2_builder_H_
#define _isc_param_buffer_v2_builder_H_

#include "source/db_obj/db_memory.h"
#include <structure/t_tmp_seg_buffer.h>
#include <structure/t_const_str_box.h>
#include <string>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_param_buffer_v2_builder

/// <summary>
///  Класс для формирования буфера с параметрами (v2).
/// </summary>
///  Структура элемента буфера: <tagID (1 byte)><length (1 byte)><data (max 255 bytes)>.
class t_isc_param_buffer_v2_builder
{
 private:
  typedef t_isc_param_buffer_v2_builder          self_type;

  t_isc_param_buffer_v2_builder(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef size_t                                 size_type;

  typedef unsigned char                          byte_type;

  typedef long                                   long_type;

  typedef byte_type                              tag_id_type;

  typedef unsigned __int32                       tag_size_type;

  typedef structure::t_const_str_box             mbc_str_box_type;

  typedef structure::t_const_wstr_box            ucs2_str_box_type;

  static const tag_size_type c_max_tag_size=255;

 public:
  /// <summary>
  ///  Конструктор по-умолчанию.
  /// </summary>
  //! \param[in] bufTypeName
  t_isc_param_buffer_v2_builder(structure::wstr_parameter bufTypeName);

  /// <summary>
  ///  Конструктор инициализации.
  /// </summary>
  //! \param[in] bufTypeName
  //! \param[in] bufPrefix
  //!  Идентификатор структуры буфера.
  t_isc_param_buffer_v2_builder(structure::wstr_parameter bufTypeName,
                                byte_type                 bufPrefix);

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~t_isc_param_buffer_v2_builder();

  //Selectors ------------------------------------------------------------
  /// <summary>
  ///  Получение имени типа буфера
  /// </summary>
  const std::wstring& GetBufferTypeName()const;

  /// <summary>
  ///  Получение размера сформированного буфера
  /// </summary>
  size_type GetBufferLength()const;

  /// <summary>
  ///  Получение указателя на сформированный буфер
  /// </summary>
  const byte_type* GetBuffer();

  //Inserters ------------------------------------------------------------
  /// <summary>
  ///  Добавляем данные с нулевой длинной.
  /// </summary>
  //! \param[in] tagID
  //! \return
  //!  Ссылка на самого себя.
  self_type& AppendTag(tag_id_type    tagID);

  /// <summary>
  ///  Добавляем byte-данные.
  /// </summary>
  //! \param[in] tagID
  //! \param[in] v
  //! \return
  //!  Ссылка на самого себя.
  self_type& AppendByte(tag_id_type    tagID,
                        byte_type      v);

  /// <summary>
  ///  Добавляем long-данные.
  /// </summary>
  //! \param[in] tagID
  //! \param[in] v
  //! \return
  //!  Ссылка на самого себя.
  self_type& AppendInt(tag_id_type    tagID,
                       long_type      v);

  /// <summary>
  ///  Добавляем строковые данные.
  /// </summary>
  //! \param[in] tagID
  //! \param[in] tagSIGN
  //!  Символьный идентификатор тега. Not NULL.
  //! \param[in] str
  //! \return
  //!  Ссылка на самого себя.
  self_type& AppendMbcString(tag_id_type      tagID,
                             const wchar_t*   tagSIGN,
                             mbc_str_box_type str);

  /// <summary>
  ///  Добавляем строковые данные.
  /// </summary>
  //! \param[in] tagID
  //! \param[in] tagSIGN
  //!  Символьный идентификатор тега. Not NULL.
  //! \param[in] str
  //! \return
  //!  Ссылка на самого себя.
  self_type& AppendMbcString(tag_id_type       tagID,
                             const wchar_t*    tagSIGN,
                             ucs2_str_box_type str);

  /// <summary>
  ///  Добавляем строковые данные в UTF8 кодировке.
  /// </summary>
  //! \param[in] tagID
  //! \param[in] tagSIGN
  //!  Символьный идентификатор тега. Not NULL.
  //! \param[in] str
  //! \return
  //!  Ссылка на самого себя.
  self_type& AppendMbcString_AsUTF8(tag_id_type       tagID,
                                    const wchar_t*    tagSIGN,
                                    ucs2_str_box_type str);

  /// <summary>
  ///  Добавляем бинарные данные.
  /// </summary>
  //! \param[in] tagID
  //! \param[in] tagSIGN
  //!  Символьный идентификатор тега. Not NULL.
  //! \param[in] cb
  //! \param[in] pv
  //! \return
  //!  Ссылка на самого себя.
  self_type& AppendBytes(tag_id_type    tagID,
                         const wchar_t* tagSIGN,
                         size_t         cb,
                         const void*    pv);

 private:
  typedef db_obj::t_db_memory_allocator                     allocator_type;

  typedef structure::t_tmp_seg_buffer<byte_type,
                                      128,
                                      allocator_type>       buffer_type;
 private:
  void helper__push_length(tag_size_type valueSize);


  COMP_CONF_DECLSPEC_NORETURN
  void helper__throw_error__value_is_too_large(tag_id_type      tagID,
                                               const wchar_t*   tagSIGN,
                                               size_t           valueSize)const;

 private:
  const std::wstring m_bufTypeName;

  buffer_type m_buffer;
};//class t_isc_param_buffer_v2_builder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
