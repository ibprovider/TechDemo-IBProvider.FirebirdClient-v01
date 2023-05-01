////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_msg_data_element_descr.h
//! \brief   The descriptor of message data element.
//! \author  Kovalenko Dmitry
//! \date    19.04.2023
#ifndef _isc_msg_data_element_descr_H_
#define _isc_msg_data_element_descr_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_msg_data_element_descr

/// <summary>
///  The descriptor of message data element.
/// </summary>
struct t_isc_msg_data_element_descr LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  /// The size of block with data.
  size_t m_msg_value_block_size;

  /// The offset of a block with data.
  size_t m_msg_value_block_offset;

  /// The offset of inficator of data state.
  size_t m_msg_sqlind_offset;

  /// The BLR-type of data element.
  unsigned m_msg_blrtype;

 public:
  /// The identifier of SQL-datatype, for that was calculated this block of data.
  short m_xvar_sqltype;

  /// The scale of value.
  short m_xvar_sqlscale;

 public:
  /// <summary>
  ///  Default constructor.
  /// </summary>
  t_isc_msg_data_element_descr();
};//struct t_isc_msg_data_element_descr

////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

// it is used only in debug code
inline bool operator == (const t_isc_msg_data_element_descr& x1,const t_isc_msg_data_element_descr& x2)
{
 if(x1.m_msg_value_block_size!=x2.m_msg_value_block_size)
  return false;

 if(x1.m_msg_value_block_offset!=x2.m_msg_value_block_offset)
  return false;

 if(x1.m_msg_sqlind_offset!=x2.m_msg_sqlind_offset)
  return false;

 if(x1.m_msg_blrtype!=x2.m_msg_blrtype)
  return false;

 if(x1.m_xvar_sqltype!= x2.m_xvar_sqltype)
  return false;

 if(x1.m_xvar_sqlscale!=x2.m_xvar_sqlscale)
  return false;

 return true;
}//operator ==

#endif // NDEBUG

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
