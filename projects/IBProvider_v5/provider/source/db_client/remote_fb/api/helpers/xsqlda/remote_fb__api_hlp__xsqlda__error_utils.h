////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__xsqlda__error_utils.h
//! \brief   Утилиты для обработки ошибок XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    20.09.2016
#ifndef _remote_fb__api_hlp__xsqlda__error_utils_H_
#define _remote_fb__api_hlp__xsqlda__error_utils_H_

#include "source/db_obj/isc_base/helpers/xsqlda/isc_api_hlp__xsqlda__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_hlp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__XSQLDA__ErrorUtils

/// <summary>
///  Утилиты для обработки ошибок XSQLDA / XSQLVAR.
/// </summary>
using RemoteFB__API_HLP__XSQLDA__ErrorUtils
 =isc_base::helpers::ISC_API_HLP__XSQLDA__ErrorUtils;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
