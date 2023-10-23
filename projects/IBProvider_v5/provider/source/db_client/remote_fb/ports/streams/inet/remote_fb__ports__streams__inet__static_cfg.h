////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__inet
//! \file    remote_fb__ports__streams__inet__static_cfg.h
//! \brief   Настройки для TCP/IP соединения с сервером.
//! \author  Kovalenko Dmitry
//! \date    30.10.2014.
#ifndef _remote_fb__ports__streams__inet__static_cfg_H_
#define _remote_fb__ports__streams__inet__static_cfg_H_

#include "source/db_client/remote_fb/ports/streams/inet/remote_fb__ports__streams__inet__types.h"
#include "source/ibp_char.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace streams{namespace inet{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__inet
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__INET_StaticCfg

/// <summary>
///  Настройки для TCP/IP соединения с сервером.
/// </summary>
class RemoteFB__INET_StaticCfg LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  using inet_types=RemoteFB__INET_Types;

  using port_number_type=inet_types::port_number_type;

 public:
  static const t_ibp_char* const c_WinSockDllName;

  static const size_t c_MAX_HOST_NAME_SIZE = 256;

  static const size_t c_MAX_HOST_ADDRESS_NUMBER = 8;

  static const char* const c_FB_SERVICE_NAME;

  static const port_number_type c_FB_SERVICE_PORT;

  //! \brief
  //!  Размер сетевого пакета по-умолчанию.
  static const size_t c_FB_PACKET_SIZE = 16*1024;

  //! \brief
  //!  Флаги отправки данных в порт
  static const int c_FB_SEND_FLAGS = 0;

  //! \brief
  //!  Флаги чтения данных из порта
  static const int c_FB_RECV_FLAGS = 0;

  //! \brief
  //!  Максимальное число последовательных вызовов операции send, возвративших ноль.
  static const size_t c_MAX_DUMMY_SEND_OP = 100;
};//class RemoteFB__INET_StaticCfg

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms inet*/}/*nms streams*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
