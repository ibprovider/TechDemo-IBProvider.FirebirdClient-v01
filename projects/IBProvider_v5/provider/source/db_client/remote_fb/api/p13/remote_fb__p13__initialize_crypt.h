////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__initialize_crypt.h
//! \brief   Утилиты подключения. Инициализация шифрования подключения.
//! \author  Kovalenko Dmitry
//! \date    12.09.2016
#ifndef _remote_fb__p13__initialize_crypt_H_
#define _remote_fb__p13__initialize_crypt_H_

#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01.h"
#include "source/db_client/remote_fb/remote_fb__internal_crypt_key.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__InitializeCrypt

/// <summary>
///  Утилиты подключения. Инициализация шифрования подключения.
/// </summary>
class RemoteFB__P13__InitializeCrypt LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef RemoteFB__P13__InitializeCrypt              self_type;

 public: //typedefs ------------------------------------------------------
  typedef ports::base_v01::RemoteFB__Port_BASE_v01    port_type;

 public:
  /// <summary>
  ///  Инициализация шифрования подключения. THROW.
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] clientConnectBlock
  static void exec(port_type*                             pPort,
                   const RemoteFB__ClientConnectBlock_v2& clientConnectBlock);

 private:
  /// <summary>
  ///  Уведомление сервера об используемом плагине шифрования
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] pKnownServerKey
  //!  Not null.
  //! \param[in] pCryptKey
  static bool Helper__TryKey
               (port_type*                        pPort,
                const RemoteFB__KnownServerKey*   pKnownServerKey,
                const RemoteFB__InternalCryptKey* pCryptKey);

  /// <summary>
  ///  Получение объекта ввода/вывода с поддержкой шифрования
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] cryptPluginName
  //! \param[in] pCryptKey
  //!
  //! Возвращаемый объект не привязывается к нижележащему потоку
  //!
  static RemoteFB__PortStreamPtr
   Helper__CreateNotBindedCryptStream
               (const port_type*                  pPort,
                structure::t_const_wstr_box       cryptPluginName,
                const RemoteFB__InternalCryptKey* pCryptKey);
};//class RemoteFB__P13__InitializeCrypt

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
