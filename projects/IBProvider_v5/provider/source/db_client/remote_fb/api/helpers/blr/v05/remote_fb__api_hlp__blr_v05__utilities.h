////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__blr_v05__utilities.h
//! \brief   Utilities for work with BLR (v05).
//! \author  Kovalenko Dmitry
//! \date    18.04.2023
#ifndef _remote_fb__api_hlp__blr_v05__utilities_H_
#define _remote_fb__api_hlp__blr_v05__utilities_H_

#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/structure/ibp_buffer_view.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_hlp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__BLR_V05__Utilities

/// <summary>
///  Утилиты для обработки XSQLDA / XSQLVAR (V1).
/// </summary>
class RemoteFB__API_HLP__BLR_V05__Utilities
{
 private:
  using self_type=RemoteFB__API_HLP__BLR_V05__Utilities;

 public: //typedefs ------------------------------------------------------
  using byte_type=unsigned char;

  using descr_type=RemoteFB__MsgDataElementDescr;

 public:
  /// <summary>
  ///  Calculating the maximum size of memory for storing the data in XDR format.
  /// </summary>
  //! \param[in] Blr
  //!  Can be NULL.
  //! \attention
  //!  It is supposed that Blr is correct. This will be checked with asserts.
  static size_t Calc_BLR_MAX_XDR_SIZE
                             (const IBP_BufferView<const byte_type>& Blr);

#ifndef NDEBUG
  static void Debug__CHECK_BLR(const IBP_BufferView<const byte_type>&  msg_blr,
                               const IBP_BufferView<const descr_type>& msg_descrs,
                               const IBP_BufferView<const byte_type>&  msg_data,
                               size_t                                  msg_data_align);
#endif
};//class RemoteFB__API_HLP__BLR_V05__Utilities

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
