////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__ports__base_v01
//! \file    remote_fb__ports__base_v01.cpp
//! \brief   Базовая реализация удаленного порта.
//! \author  Kovalenko Dmitry
//! \date    29.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01_writer.h"
#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01_reader.h"
#include "source/db_obj/db_utility.h"
#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace base_v01{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port_BASE_v01::tag_send_ctx

class RemoteFB__Port_BASE_v01::tag_send_ctx:public RemoteFB__PortOperationContext
{
 private:
  typedef tag_send_ctx                      self_type;

  tag_send_ctx(const self_type&);
  self_type& operator = (const self_type&);

 public:
  tag_send_ctx(RemoteFB__PortOperationContext& base_ctx,
               RemoteFB__PortWriter*           pPortWriter);

 ~tag_send_ctx();

  //interface ------------------------------------------------------------
  virtual RemoteFB__SmartObjectPtr query_service(REFGUID serviceID)COMP_W000004_OVERRIDE_FINAL;

 private:
  RemoteFB__PortOperationContext& m_base_ctx;

  RemoteFB__PortWriterPtr const m_spPortWriter;
};//class RemoteFB__Port_BASE_v01::tag_send_ctx

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port_BASE_v01::tag_send_ctx

RemoteFB__Port_BASE_v01::tag_send_ctx::tag_send_ctx
                                           (RemoteFB__PortOperationContext& base_ctx,
                                            RemoteFB__PortWriter*   const   pPortWriter)
 :m_base_ctx(base_ctx)
 ,m_spPortWriter(structure::not_null_ptr(pPortWriter))
{
 assert(m_spPortWriter);
}//tag_send_ctx

//------------------------------------------------------------------------
RemoteFB__Port_BASE_v01::tag_send_ctx::~tag_send_ctx()
{
}//~tag_send_ctx

//interface --------------------------------------------------------------
RemoteFB__SmartObjectPtr RemoteFB__Port_BASE_v01::tag_send_ctx::query_service(REFGUID serviceID)
{
 assert(m_spPortWriter);

 if(serviceID==RemoteFB__PortWriter::svcID)
  return structure::not_null_ptr(m_spPortWriter.ptr());

 return m_base_ctx.query_service(serviceID);
}//query_service

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port_BASE_v01::tag_recv_ctx

class RemoteFB__Port_BASE_v01::tag_recv_ctx:public RemoteFB__PortOperationContext
{
 private:
  typedef tag_recv_ctx                      self_type;

  tag_recv_ctx(const self_type&);
  self_type& operator = (const self_type&);

 public:
  tag_recv_ctx(RemoteFB__PortOperationContext& base_ctx,
               RemoteFB__PortReader*           pPortReader);

 ~tag_recv_ctx();

  //interface ------------------------------------------------------------
  virtual RemoteFB__SmartObjectPtr query_service(REFGUID serviceID)COMP_W000004_OVERRIDE_FINAL;

 private:
  RemoteFB__PortOperationContext& m_base_ctx;

  RemoteFB__PortReaderPtr const m_spPortReader;
};//class RemoteFB__Port_BASE_v01::tag_recv_ctx

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port_BASE_v01::tag_recv_ctx

RemoteFB__Port_BASE_v01::tag_recv_ctx::tag_recv_ctx
                                           (RemoteFB__PortOperationContext& base_ctx,
                                            RemoteFB__PortReader*   const   pPortReader)
 :m_base_ctx(base_ctx)
 ,m_spPortReader(structure::not_null_ptr(pPortReader))
{
 assert(m_spPortReader);
}//tag_recv_ctx

//------------------------------------------------------------------------
RemoteFB__Port_BASE_v01::tag_recv_ctx::~tag_recv_ctx()
{
}//~tag_recv_ctx

//interface --------------------------------------------------------------
RemoteFB__SmartObjectPtr RemoteFB__Port_BASE_v01::tag_recv_ctx::query_service(REFGUID serviceID)
{
 assert(m_spPortReader);

 if(serviceID==RemoteFB__PortReader::svcID)
  return structure::not_null_ptr(m_spPortReader.ptr());

 return m_base_ctx.query_service(serviceID);
}//query_service

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port_BASE_v01

RemoteFB__Port_BASE_v01::RemoteFB__Port_BASE_v01(RemoteFB__PortStream*                 const pSocket,
                                                 transmission::RemoteFB__PacketStream* const pPacketStream)
 :m_spSocket         (structure::not_null_ptr(pSocket))
 ,m_PacketSendGuard  ()
 ,m_port_state_guard ()
 ,m_port_state       (c_state__none)
 ,m_read_state       (c_state__none)
 ,m_write_state      (c_state__none)
 ,m_pPacketStream    (pPacketStream)
{
 assert(m_spSocket);
 assert(m_pPacketStream);

 //! \todo
 //!  Set PortFlag__dummy_pckt_set flag?
}//RemoteFB__Port_BASE_v01

//------------------------------------------------------------------------
RemoteFB__Port_BASE_v01::~RemoteFB__Port_BASE_v01()
{
}//~RemoteFB__Port_BASE_v01

//------------------------------------------------------------------------
void RemoteFB__Port_BASE_v01::RegService(REFGUID                         svcID,
                                         RemoteFB__SmartInterface* const pSvc)
{
 assert(pSvc);

 _VERIFY(m_Services.insert(services_type::value_type(svcID,pSvc)) DEBUG_CODE(.second));
}//Helper__RegService

//port interface ---------------------------------------------------------
void RemoteFB__Port_BASE_v01::send_packet(RemoteFB__PortOperationContext& op_ctx,
                                          const protocol::PACKET&         packet)
{
 //Недопускаем рекурсивный вызов из операций, связанных с получением пакета.
 assert(!m_Debug__PacketReceiveGuard.current_thread_is_owner());

 assert(m_pPacketStream!=nullptr);

 // Возможен параллельный вызов для отправки операции op_cancel.
 //
 // Note: op_cancel не получает ответы от сервера.

 /// 1. Блокировка порта для монопольной отправки пакета.
 const lock_guard_type __lock_send_packet(m_PacketSendGuard);

 /// 2. Настройка контекста операции
 RemoteFB__Port_BASE_v01::tag_writer portWriter(this,/*IsDeferredPacket*/false);

 tag_send_ctx send_ctx(op_ctx,
                       &portWriter);

 /// 3. Отправка пакета.
 m_pPacketStream->SendPacket(send_ctx,
                             packet); //throw
}//send_packet

//------------------------------------------------------------------------
void RemoteFB__Port_BASE_v01::send_packet_with_delay(RemoteFB__PortOperationContext& op_ctx,
                                                     const protocol::PACKET&         packet)
{
 //Недопускаем рекурсивный вызов из операций, связанных с получением пакета.
 assert(!m_Debug__PacketReceiveGuard.current_thread_is_owner());

 assert(m_pPacketStream!=nullptr);

 // Возможен параллельный вызов send_packet.

 /// 1. Блокировка порта для монопольной отправки пакета.
 const lock_guard_type __lock_send_packet(m_PacketSendGuard);

 /// 2. Настройка контекста операции
 RemoteFB__Port_BASE_v01::tag_writer portWriter(this,/*IsDeferredPacket*/true);

 tag_send_ctx send_ctx(op_ctx,
                       &portWriter);

 /// 3. Отправка пакета.
 m_pPacketStream->SendPacket(send_ctx,
                             packet); //throw
}//send_packet_with_delay

//------------------------------------------------------------------------
void RemoteFB__Port_BASE_v01::receive_packet(RemoteFB__PortOperationContext& op_ctx,
                                             protocol::PACKET&               packet)
{
 #ifndef NDEBUG
  /// Отладочный контроль монопольной загрузки пакетов.
  const t_ibp_debug__mt_guard_lock __lockReceive(m_Debug__PacketReceiveGuard);
 #endif

 tag_reader portReader(this);

 tag_recv_ctx recv_ctx(op_ctx,
                       &portReader);

 return m_pPacketStream->ReceivePacket(recv_ctx,
                                       packet);
}//receive_packet

//------------------------------------------------------------------------
void RemoteFB__Port_BASE_v01::set_invalid_port_state_v2(const std::exception* const pExc)
{
 lock_guard_type __lockPortState(m_port_state_guard);

 const rw_state_type prevPortState
  =::InterlockedCompareExchange(&m_port_state,c_state__failed,c_state__none);

 if(prevPortState==c_state__failed)
  return; //порт уже был переведен в заблокированное состояние

 assert(prevPortState==c_state__none);

 //[2018-04-12] По идее, список должен быть пустым.
 assert(m_port_state_errors.empty());

 if(pExc!=nullptr)
  m_port_state_errors.add(*pExc); //throw
}//set_invalid_port_state_v2

//------------------------------------------------------------------------
bool RemoteFB__Port_BASE_v01::port_has_invalid_state()const
{
 return m_port_state==c_state__failed;
}//port_has_invalid_state

//------------------------------------------------------------------------
protocol::P_PROTOCOL_VERSION RemoteFB__Port_BASE_v01::get_protocol_version()const
{
 //версия протокола определяется и устанавливается в процессе конструирования объекта.
 assert(!m_ProtocolVersion.null());

 return m_ProtocolVersion.value();
}//get_protocol_version

//------------------------------------------------------------------------
RemoteFB__Port_BASE_v01::port_flags_type RemoteFB__Port_BASE_v01::get_port_flags()const
{
 assert(!m_PortFlags.null());

 return m_PortFlags.value();
}//get_port_flags

//t_db_service_provider interface ----------------------------------------
db_obj::t_db_object_ptr RemoteFB__Port_BASE_v01::query_service(REFGUID rguidService)
{
 const services_type::const_iterator x(m_Services.find(rguidService));

 if(x!=m_Services.end())
 {
  assert((*x).second);

  return (*x).second;
 }//if

 return nullptr;
}//query_service

//debug interface --------------------------------------------------------
#ifndef NDEBUG

protocol::P_ARCH RemoteFB__Port_BASE_v01::debug__get_protocol_architecture()const
{
 assert(!m_ProtocolArchitecture.null());

 return m_ProtocolArchitecture.value();
}//debug__get_protocol_architecture

#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms base_v01*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
