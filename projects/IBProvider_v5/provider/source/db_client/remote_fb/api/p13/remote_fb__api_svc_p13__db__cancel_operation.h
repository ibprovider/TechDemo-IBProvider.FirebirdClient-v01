////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_svc_p13__db__cancel_operation.h
//! \brief   Сервис отмены выполнения операции.
//! \author  Kovalenko Dmitry
//! \date    23.09.2016
#ifndef _remote_fb__api_svc_p13__db__cancel_operation_H_
#define _remote_fb__api_svc_p13__db__cancel_operation_H_

#include "source/db_client/remote_fb/api/svc/remote_fb__api_svc__db__cancel_operation.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__SVC_P13__CancelDbOperation

/// <summary>
///  Сервис отмены выполнения операции.
/// </summary>
class RemoteFB__SVC_P13__CancelDbOperation LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__SVC__CancelDbOperation)
{
 private:
  using self_type=RemoteFB__SVC_P13__CancelDbOperation;

  RemoteFB__SVC_P13__CancelDbOperation(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private:
  RemoteFB__SVC_P13__CancelDbOperation();

  virtual ~RemoteFB__SVC_P13__CancelDbOperation();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  Отмена выполнения операции.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  virtual void exec(RemoteFB__ConnectorData* pData)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__SVC_P13__CancelDbOperation

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
