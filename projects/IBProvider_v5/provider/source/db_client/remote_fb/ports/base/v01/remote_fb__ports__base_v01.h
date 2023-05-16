////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__ports__base_v01
//! \file    remote_fb__ports__base_v01.h
//! \brief   Базовая реализация удаленного порта.
//! \author  Kovalenko Dmitry
//! \date    29.08.2016
#ifndef _remote_fb__ports__base_v01_H_
#define _remote_fb__ports__base_v01_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/ports/remote_fb__port_stream.h"
#include "source/db_client/remote_fb/transmission/remote_fb__transmission__packet_stream.h"
#include "source/error_services/ibp_error_collection.h"
#include "source/ibp_debug.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace base_v01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__ports__base_v01
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port_BASE_v01

/// <summary>
///  Базовая реализация удаленного порта.
/// </summary>
/// - Класс реализует MT-блокировку для операции отправки пакетов.
/// - Не допускаются параллельные вызовы получения пакетов.
/// - Не допускаются параллельный вызов получения пакетов и вызов
///   отправки пакета с регистрацией объекта отложенного чтения ответа.
class RemoteFB__Port_BASE_v01:public RemoteFB__Port
{
 private:
  typedef RemoteFB__Port_BASE_v01                              self_type;
  typedef RemoteFB__Port                                       inherited;

  RemoteFB__Port_BASE_v01(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>             self_ptr;

  typedef structure::t_const_wstr_box                          wstr_box_type;

  typedef size_t                                               size_type;

 public:
  //открыты для доступа из инициализаторов

  /// Сокет подключения к серверу.
  RemoteFB__PortStreamPtr m_spSocket;

  /// Флаги порта.
  structure::t_value_with_null<port_flags_type> m_PortFlags;

  /// Версия протокола подключения.
  structure::t_value_with_null<protocol::P_PROTOCOL_VERSION> m_ProtocolVersion;

  /// Архитектура протокола подключения.
  structure::t_value_with_null<protocol::P_ARCH> m_ProtocolArchitecture;

  /// Объект отправки/получения пакетов
  transmission::RemoteFB__PacketStream* m_pPacketStream;

 protected:
  /// <summary>
  ///  Конструктор инициализации.
  /// </summary>
  //! \param[in] pSocket
  //!  Not null.
  //! \param[in] pPacketStream
  //!  Not null.
  RemoteFB__Port_BASE_v01(RemoteFB__PortStream*                 pSocket,
                          transmission::RemoteFB__PacketStream* pPacketStream);

  /// <summary>
  ///  Деструктор.
  /// </summary>
  virtual ~RemoteFB__Port_BASE_v01();

 public:

  /// <summary>
  ///  Регистрация вспомогательного сервиса.
  /// </summary>
  //! \param[in] svcID
  //! \param[in] pSvc
  //!  Not null.
  void RegService(REFGUID                   svcID,
                  RemoteFB__SmartInterface* pSvc);

 public:

  //port interface -------------------------------------------------------
  /// <summary>
  ///  Отправка пакета в порт.
  /// </summary>
  //! \param[in] op_ctx
  //! \param[in] packet
  virtual void send_packet(RemoteFB__PortOperationContext& op_ctx,
                           const protocol::PACKET&         packet) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Отложенная отправка пакета в порт.
  /// </summary>
  //! \param[in] op_ctx
  //! \param[in] packet
  virtual void send_packet_with_delay(RemoteFB__PortOperationContext& op_ctx,
                                      const protocol::PACKET&         packet) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Чтение пакета из порта.
  /// </summary>
  //! \param[in]  op_ctx
  //! \param[out] packet
  virtual void receive_packet(RemoteFB__PortOperationContext& op_ctx,
                              protocol::PACKET&               packet) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Запрещаем порту обслуживать подключение.
  /// </summary>
  //! \param[in] pExc
  //!  Указатель на описание ошибки, которая привела к блокировке порта. Can be NULL.
  //! \attention
  //!  Этот метод может вызываться из за того, что порт находится в заблокированном состоянии.
  //!  Поэтому реализация ДОЛЖНА игнорировать повторные вызовы.
  virtual void set_invalid_port_state_v2(const std::exception* pExc)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Тестирование недействительного состояния порта.
  /// </summary>
  virtual bool port_has_invalid_state()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Получение версии протокола.
  /// </summary>
  virtual protocol::P_PROTOCOL_VERSION get_protocol_version()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Получение флагов порта.
  /// </summary>
  virtual port_flags_type get_port_flags()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  //t_db_service_provider interface --------------------------------------
  /// <summary>
  /// Запрос сервисного объекта
  /// </summary>
  //! \param[in] rguidService
  //!  Идентификатор сервиса
  //! \return
  //!  Возвращает указатель на сервисный объект. Если запрашиваемый
  //!  сервис не поддерживается, то возвращается NULL
  virtual db_obj::t_db_object_ptr query_service(REFGUID rguidService)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 public:
 #ifndef NDEBUG
  protocol::P_ARCH debug__get_protocol_architecture()const;
 #endif

 private:
  virtual protocol::P_LONG internal__htonl(const protocol::P_LONG* pv)const=0;

  virtual protocol::P_LONG internal__ntohl(const protocol::P_LONG* pv)const=0;

 private:
  class tag_send_ctx;
  class tag_recv_ctx;

#ifndef IBP_BUILD_TESTCODE
 private:
#else
 public:
#endif

  class tag_writer;
  class tag_reader;

 private: //typedefs -----------------------------------------------------
  typedef structure::t_multi_thread_traits::guard_type          guard_type;
  typedef structure::t_multi_thread_traits::lock_guard_type     lock_guard_type;

  /// MT-блокировка отправки пакетов
  guard_type m_PacketSendGuard;

 #ifndef NDEBUG
  /// Отладочная блокировка для контроля монопольной работы процесса получения пакетов
  /// и доступа к m_PacketReceivers.
  t_ibp_debug__mt_guard m_Debug__PacketReceiveGuard;
 #endif

 private:
  typedef ULONG rw_state_type;

  static const rw_state_type c_state__none   =0;
  static const rw_state_type c_state__in_use =1;
  static const rw_state_type c_state__failed =2;

 private:
  /// MT-защита общего состояния порта
  guard_type m_port_state_guard;

  /// Общее состояние порта
  rw_state_type m_port_state;

  /// Коллекция ошибок, описывающих причину блокировки порта
  t_ibp_error_collection m_port_state_errors;

 private:
  /// Состояние операции чтения
  rw_state_type m_read_state;

  /// Состояние операции записи
  rw_state_type m_write_state;

 private:
  typedef structure::t_stl_map
           <GUID,
            RemoteFB__SmartObjectPtr,
            ole_lib::TGuidLess,
            RemoteFB__MemoryAllocator>      services_type;

  ///Вспомогательные сервисы для работы с подключением
  services_type m_Services;
};//class RemoteFB__Port_BASE_v01

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms base_v01*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
