////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__stmt__get_columns.h
//! \brief   Getting the column definitions of statement.
//! \author  Kovalenko Dmitry
//! \date    27.04.2015
#ifndef _remote_fb__api_p12__stmt__get_columns_H_
#define _remote_fb__api_p12__stmt__get_columns_H_

#include "source/db_client/remote_fb/api/helpers/remote_fb__api_hlp__stmt__get_columns_v01.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Getting the column definitions of statement.
/// </summary>
using RemoteFB__API_P12__GetColumns
 =helpers::RemoteFB__API_HLP__GetColumns_v01;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
