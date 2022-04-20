////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_bit8_map.h
//! \brief   Структура с данными для преобразования кодовых страниц BIT8
//! \author  Kovalenko Dmitry
//! \date    27.09.2005
#ifndef _ibp_cs_bit8_map_H_
#define _ibp_cs_bit8_map_H_

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//struct t_ibp_cs_bit8_map

/// <summary>
///  Структура с данными для преобразования кодовых страниц BIT8
/// </summary>
struct t_ibp_cs_bit8_map
{
 public: //typedefs ------------------------------------------------------
  typedef unsigned short            ushort_type;
  typedef unsigned char             uchar_type;
  typedef size_t                    size_type;

  ///Тип таблицы преобразования BIT8 в UCS2
  typedef const ushort_type         to_unicode_map_type[256];

  ///Тип индекса таблицы конвертирования из UCS2 в BIT8
  typedef const ushort_type         from_unicode_map_type[256];

 public: //---------------------------------------------------------------
  ///Таблица преобразования BIT8 в UCS2
  to_unicode_map_type*              to_unicode_map;

  ///Массив секций с отображениями UCS2 на BIT8
  const uchar_type*                 from_unicode_mapping_array;

  ///Количество элементов в from_unicode_mapping_array
  size_type                         from_unicode_mapping_array_size;

  ///Индекс секций from_unicode_mapping_array
  from_unicode_map_type*            from_unicode_map;
};//struct t_ibp_cs_bit8_map

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
