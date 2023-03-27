////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_max_obj_name_len.h
//! \brief   The information about max database object name length
//! \author  Kovalenko Dmitry
//! \date    10.03.2023
#ifndef _isc_max_obj_name_len_H_
#define _isc_max_obj_name_len_H_

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//enum tag_isc_max_obj_name_len_kind

/// <summary>
///  The enumeration of max name length kinds
/// </summary>
enum class tag_isc_max_obj_name_len_kind
{
 /// Not defined.
 not_defined      =0,

 /// Length in UNICODE_FSS bytes.
 in_fss_bytes     =1,
};//enum tag_isc_max_obj_name_len_kind

////////////////////////////////////////////////////////////////////////////////
//class t_isc_max_obj_name_len

/// <summary>
///  The information about max database object name length.
/// </summary>
class t_isc_max_obj_name_len
{
 public: //typedefs ------------------------------------------------------
  using kind_type=tag_isc_max_obj_name_len_kind;

 public:
  t_isc_max_obj_name_len();

  //modificators ---------------------------------------------------------
  void reset();

  void set_in_fss_bytes(size_t value);

  //selectors ------------------------------------------------------------
  size_t get_value()const;

  kind_type get_kind()const;

  bool is_not_defined()const;

  bool is_in_fss_bytes()const;

 private:
  size_t m_value;

  kind_type m_kind;
};//class t_isc_max_obj_name_len

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
