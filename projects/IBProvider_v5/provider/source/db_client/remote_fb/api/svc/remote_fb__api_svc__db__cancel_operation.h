////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_svc
//! \file    remote_fb__api_svc__db__cancel_operation.h
//! \brief   Сервис отмены выполнения операции.
//! \author  Kovalenko Dmitry
//! \date    04.12.2015
#ifndef _remote_fb__api_svc__db__cancel_operation_H_
#define _remote_fb__api_svc__db__cancel_operation_H_

#include "source/db_client/remote_fb/api/remote_fb__api.h"
#include "source/db_client/remote_fb/remote_fb__memory.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_svc
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__SVC__CancelDbOperation

/// <summary>
///  Сервис отмены выполнения операции.
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE RemoteFB__SVC__CancelDbOperation:public RemoteFB__SmartInterface
{
 public:
  /// <summary>
  ///  Отмена выполнения операции.
  /// </summary>
  //! \param[in]  pData
  //!  Not null.
  virtual void exec(RemoteFB__ConnectorData* pData)=0;
};//class RemoteFB__SVC__CancelDbOperation

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
