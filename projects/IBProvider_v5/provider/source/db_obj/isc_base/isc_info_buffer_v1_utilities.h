////////////////////////////////////////////////////////////////////////////////
//! \ingroup  isc_base
//! \file     isc_info_buffer_v1_utilities.h
//! \brief    Utilities for work with information buffer (v1).
//! \author   Kovalenko Dmitry
//! \date     26.03.2023
#ifndef _isc_info_buffer_v1_utilities_H_
#define _isc_info_buffer_v1_utilities_H_

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class isc_info_buffer_v1_utilities

/// <summary>
///  Utilities for work with information buffer (v1).
/// </summary>
class isc_info_buffer_v1_utilities
{
 public:
  using byte_type=unsigned char;

 public:
  /// <summary>
  ///  Skipping a block.
  /// </summary>
  static const byte_type* skip_element_data
                             (const byte_type* beg,
                              const byte_type* end,
                              long             tagID);
};//class isc_info_buffer_v1_utilities

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
