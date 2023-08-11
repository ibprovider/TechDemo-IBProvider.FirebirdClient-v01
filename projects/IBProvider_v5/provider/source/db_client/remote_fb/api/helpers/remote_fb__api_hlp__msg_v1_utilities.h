////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__msg_v1_utilities.h
//! \brief   Helpers for MSG-classes [v1].
//! \author  Kovalenko Dmitry
//! \date    18.04.2023
#ifndef _remote_fb__api_hlp__msg_v1_utilities_H_
#define _remote_fb__api_hlp__msg_v1_utilities_H_

#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/structure/ibp_buffer_view.h"
#include "source/ibp_subsystem_ids.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_hlp
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__Msg_v1__Utilities

/// <summary>
///  Helpers for MSG-classes [v1].
/// </summary>
class RemoteFB__API_HLP__Msg_v1__Utilities
{
 private:
  using self_type=RemoteFB__API_HLP__Msg_v1__Utilities;

 public:
  /// <summary>
  ///  Testing a IN-message object.
  /// </summary>
  /// <param name="pInMsg">
  ///  A pointer to the message object. Can be null.
  /// </param>
  /// <returns>
  ///  The number of values in pInMsg.
  /// </returns>
  static size_t TestMsg(const RemoteFB__InMsg_v1* pInMsg);

  /// <summary>
  ///  Testing a OUT-message object.
  /// </summary>
  /// <param name="pOutMsg">
  ///  A pointer to the message object. Can be null.
  /// </param>
  ///  The number of values in pOutMsg.
  /// </returns>
  static size_t TestMsg(const RemoteFB__OutMsg_v1* pOutMsg);

  /// <summary>
  ///  Testing a OUT-message object.
  /// </summary>
  /// <param name="pOutMsg">
  ///  A pointer to the message object. Can be null.
  /// </param>
  /// <param name="minSQLD">
  ///  The minimal count of described elements in pOutMsg.
  /// </param>
  /// <param name="subsystemID"/>
  static void TestMsg(const RemoteFB__OutMsg_v1* pOutMsg,
                      size_t                     minSQLD,
                      t_ibp_subsystem_id         subsystemID);

 private:
  template<class TMSG>
  static size_t Helper__TestMsg(const TMSG*    pMsg,
                                const wchar_t* pMsgSign);
};//class RemoteFB__API_HLP__Msg_v1__Utilities

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
