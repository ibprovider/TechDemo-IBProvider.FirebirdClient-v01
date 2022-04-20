////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_bit8_map.h
//! \brief   ��������� � ������� ��� �������������� ������� ������� BIT8
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
///  ��������� � ������� ��� �������������� ������� ������� BIT8
/// </summary>
struct t_ibp_cs_bit8_map
{
 public: //typedefs ------------------------------------------------------
  typedef unsigned short            ushort_type;
  typedef unsigned char             uchar_type;
  typedef size_t                    size_type;

  ///��� ������� �������������� BIT8 � UCS2
  typedef const ushort_type         to_unicode_map_type[256];

  ///��� ������� ������� ��������������� �� UCS2 � BIT8
  typedef const ushort_type         from_unicode_map_type[256];

 public: //---------------------------------------------------------------
  ///������� �������������� BIT8 � UCS2
  to_unicode_map_type*              to_unicode_map;

  ///������ ������ � ������������� UCS2 �� BIT8
  const uchar_type*                 from_unicode_mapping_array;

  ///���������� ��������� � from_unicode_mapping_array
  size_type                         from_unicode_mapping_array_size;

  ///������ ������ from_unicode_mapping_array
  from_unicode_map_type*            from_unicode_map;
};//struct t_ibp_cs_bit8_map

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
