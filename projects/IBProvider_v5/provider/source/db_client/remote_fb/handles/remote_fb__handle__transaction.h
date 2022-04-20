////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__handles
//! \file    remote_fb__handle__transaction.h
//! \brief   Дескриптор транзакции.
//! \author  Kovalenko Dmitry
//! \date    16.02.2015
#ifndef _remote_fb__handle__transaction_H_
#define _remote_fb__handle__transaction_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle_data__transaction.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace handles{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__handles
//! @{
////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Дескриптор транзакции.
/// </summary>
typedef RemoteFB__HandleData_Transaction::self_ptr      RemoteFB__TrHandle;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms handles*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
