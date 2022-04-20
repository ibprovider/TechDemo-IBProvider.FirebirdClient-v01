////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__inet
//! \file    remote_fb__ports__inet.h
//! \brief   Реализация удаленного порта для работы через TCP/IP.
//! \author  Kovalenko Dmitry
//! \date    28.10.2014.
#ifndef _remote_fb__ports__inet_H_
#define _remote_fb__ports__inet_H_

#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01.h"
#include "source/db_client/remote_fb/ports/streams/inet/remote_fb__ports__streams__inet__socket.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace inet{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__inet
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port_INET

/// <summary>
///  Реализация удаленного порта для работы через TCP/IP.
/// </summary>
/// - Класс реализует MT-блокировку для операции отправки пакетов.
/// - Не допускаются параллельные вызовы получения пакетов.
/// - Не допускаются параллельный вызов получения пакетов и вызов
///   отправки пакета с регистрацией объекта отложенного чтения ответа.
class RemoteFB__Port_INET:public ports::base_v01::RemoteFB__Port_BASE_v01
{
 private:
  typedef RemoteFB__Port_INET                                  self_type;
  typedef ports::base_v01::RemoteFB__Port_BASE_v01             inherited;

  RemoteFB__Port_INET(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>             self_ptr;

 private:
  /// <summary>
  ///  Конструктор инициализации.
  /// </summary>
  //! \param[in] pSocket
  //!  Not null.
  //! \param[in] pPacketStream
  //!  Not null.
  RemoteFB__Port_INET(streams::inet::RemoteFB__INET_Socket* pSocket,
                      transmission::RemoteFB__PacketStream* pPacketStream);

  /// <summary>
  ///  Деструктор.
  /// </summary>
  virtual ~RemoteFB__Port_INET();

 public:
  /// <summary>
  ///  Фабрика класса.
  /// </summary>
  //! \param[in] pSocket
  //!  Not null.
  //! \return
  //!  Not null.
  static self_ptr Create_PSET01(streams::inet::RemoteFB__INET_Socket* pSocket);

  /// <summary>
  ///  Фабрика класса.
  /// </summary>
  //! \param[in] pSocket
  //!  Not null.
  //! \return
  //!  Not null.
  static self_ptr Create_PSET02(streams::inet::RemoteFB__INET_Socket* pSocket);

 private:
  virtual protocol::P_LONG internal__htonl(const protocol::P_LONG* pv)const COMP_W000004_OVERRIDE_FINAL;

  virtual protocol::P_LONG internal__ntohl(const protocol::P_LONG* pv)const COMP_W000004_OVERRIDE_FINAL;

 private:
  /// Провайдер Windows Socket API.
  ibp::os::win32::winsock::t_winsock__provider::self_ptr const m_spProvider;
};//class RemoteFB__Port_INET

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms inet*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
