////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__process_auth_response.h
//! \brief   Утилиты подключения. Обработка данных ответа авторизации.
//! \author  Kovalenko Dmitry
//! \date    12.09.2016
#ifndef _remote_fb__p13__process_auth_response_H_
#define _remote_fb__p13__process_auth_response_H_

#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__ProcessAuthResponse

/// <summary>
///  Утилиты подключения. Обработка данных ответа авторизации.
/// </summary>
class RemoteFB__P13__ProcessAuthResponse LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  /// <summary>
  ///  Обработка ответа аутентификации. THROW.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  //! \param[in]     pResponse_AuthPluginName
  //! \param[in]     pResponse_AuthPluginData
  static void exec
               (RemoteFB__ClientConnectBlock_v2&           clientConnectBlock,
                const protocol::set02::P_CSTRING_CONST_V2* pResponse_AuthPluginName,
                const protocol::set02::P_CSTRING_CONST_V2* pResponse_AuthPluginData);
};//class RemoteFB__P13__ProcessAuthResponse

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
