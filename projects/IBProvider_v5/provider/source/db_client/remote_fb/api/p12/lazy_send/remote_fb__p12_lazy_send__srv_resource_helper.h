////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12_lazy_send
//! \file    remote_fb__p12_lazy_send__srv_resource_helper.h
//! \brief   Ќабор вспомогательных утилит дл€ управлени€ ресурсами подключени€.
//! \author  Kovalenko Dmitry
//! \date    31.10.2015
#ifndef _remote_fb__p12_lazy_send__srv_resource_helper_H_
#define _remote_fb__p12_lazy_send__srv_resource_helper_H_

#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12_lazy_send
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P12_LAZY_SEND__SrvResourceHelper

/// <summary>
///  Ќабор вспомогательных утилит дл€ управлени€ ресурсами подключени€.
/// </summary>
class RemoteFB__P12_LAZY_SEND__SrvResourceHelper LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__P12_LAZY_SEND__SrvResourceHelper;

 public:
  /// <summary>
  ///  ќсвобождаем запросы, освобождение которых было отложено.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  static void ProcessDeferReleasedResources__STMT(RemoteFB__ConnectorData* pData);

  /// <summary>
  ///  ќсвобождаем ресурсы, освобождение которых было отложено.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  static void ProcessDeferReleasedResources(RemoteFB__ConnectorData* pData);

 private:
  /// <summary>
  ///  ѕроталкиваем удаление запросов.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  static void Helper__DropStmts(RemoteFB__ConnectorData* pData);

  /// <summary>
  ///  ѕроталкиваем освобождение блобов
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  static void Helper__ReleaseBlobs(RemoteFB__ConnectorData* pData);

 private:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Helper__ThrowBugCheck__UnkBlobHandleState
                                           (const wchar_t* place,
                                            const wchar_t* point,
                                            int            blobState);
};//class RemoteFB__P12_LAZY_SEND__SrvResourceHelper

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
