////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__add_server_keys.h
//! \brief   Утилиты подключения. Регистрация типов серверных ключей для шифрования.
//! \author  Kovalenko Dmitry
//! \date    12.09.2016
#ifndef _remote_fb__p13__add_server_keys_H_
#define _remote_fb__p13__add_server_keys_H_

#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__AddServerKeys

/// <summary>
///  Утилиты подключения. Регистрация типов серверных ключей для шифрования.
/// </summary>
class RemoteFB__P13__AddServerKeys LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  /// <summary>
  ///  Регистрация ключей, полученных от сервера. THROW.
  /// </summary>
  //! \param[in] clientConnectBlock
  //! \param[in] cb
  //! \param[in] pv
  static void exec(RemoteFB__ClientConnectBlock_v2& clientConnectBlock,
                   size_t                           cb,
                   const void*                      pv);
};//class RemoteFB__P13__AddServerKeys

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
