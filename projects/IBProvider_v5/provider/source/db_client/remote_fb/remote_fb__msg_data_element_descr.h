////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__msg_data_element_descr.h
//! \brief   Описатель элемента MSG-буфера с данными.
//! \author  Kovalenko Dmitry
//! \date    18.05.2015.
#ifndef _remote_fb__msg_data_element_descr_H_
#define _remote_fb__msg_data_element_descr_H_

#include "source/db_obj/isc_base/isc_msg_data_element_descrs.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Описатель элемента MSG-буфера с данными.
/// </summary>
using RemoteFB__MsgDataElementDescr
 =isc_base::t_isc_msg_data_element_descr;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  The container of RemoteFB__MsgDataElementDescr.
/// </summary>
using RemoteFB__MsgDataElementDescrs
 =isc_base::t_isc_msg_data_element_descrs;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
