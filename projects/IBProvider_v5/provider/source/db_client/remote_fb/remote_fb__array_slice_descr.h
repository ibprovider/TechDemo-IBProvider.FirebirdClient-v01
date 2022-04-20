////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__array_slice_descr.h
//! \brief   �������� ������ �� ���������� ��������� �������.
//! \author  Kovalenko Dmitry
//! \date    28.09.2015.
#ifndef _remote_fb__array_slice_descr_H_
#define _remote_fb__array_slice_descr_H_

#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ArraySliceDescr

/// <summary>
///  �������� ������ �� ���������� ��������� �������.
/// </summary>
class RemoteFB__ArraySliceDescr
{
 private:
  typedef RemoteFB__ArraySliceDescr         self_type;

  RemoteFB__ArraySliceDescr(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef unsigned __int8                   byte_type;

  typedef unsigned __int8                   blr_typeid_type;
  typedef signed   __int8                   sql_scale_type;
  typedef unsigned __int16                  sql_length_type;
  typedef unsigned __int16                  sql_text_props_type;

  typedef signed __int32                    range_bound_type;

  struct tag_bound
  {
   range_bound_type  lower;
   range_bound_type  upper;
  };

 public:
  /// ��� �������, � ������� ����������� ������
  std::wstring     m_relation_name;

  /// ��� �������, � ������� ����������� ������
  std::wstring     m_field_name;

  /// BLR-��� �������� �������
  blr_typeid_type  m_element_blr_typeid;

  /// ������� �������� �������
  sql_scale_type   m_element_sql_scale;

  /// ��������� ��������� ������ (������� �������� � �������)
  sql_text_props_type m_element_sql_text_props;

  /// <summary>
  ///  SQL-����� �������� �������
  /// </summary>
  //! \note
  //!  ����� ���������� �� ������������ ������� �������� � ������.
  sql_length_type  m_element_sql_length;

  /// <summary>
  ///  ������ ������ �������� ������� � ������
  /// <summary>
  size_t m_element_total_length;

  /// <summary>
  ///  ���������� ��������� � m_bounds
  /// </summary>
  byte_type m_bounds_number;

  /// <summary>
  ///  ������������ ������������ �������
  /// </summary>
  tag_bound m_bounds[isc_api::isc_max_array_dimensions_v1];

 public:
  /// <summary>
  ///  ����������� ��-���������.
  /// </summary>
  RemoteFB__ArraySliceDescr();

  /// <summary>
  ///  ����������.
  /// </summary>
 ~RemoteFB__ArraySliceDescr();

  /// <summary>
  ///  �������������
  /// </summary>
  void Init();

  /// <summary>
  ///  ���������� ������ ����� ��������� � �������.
  /// </summary>
  size_t GetElementCount()const;

  /// <summary>
  ///  ���������� ������� ������ ��� �������� ��������� �������.
  /// </summary>
  size_t GetMemorySize()const;

 private:
  COMP_CONF_DECLSPEC_NORETURN
  void Helper__ThrowErr__CantCalcElementCount()const;
};//class RemoteFB__ArraySliceDescr

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
