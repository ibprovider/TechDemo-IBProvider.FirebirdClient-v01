////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__ports__base_v01
//! \file    remote_fb__ports__base_v01_writer.cpp
//! \brief   Реализация интерфейса писателя в стандартный порт.
//! \author  Kovalenko Dmitry
//! \date    29.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01_writer.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace base_v01{
////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

#define IBP__LOCAL_DEBUG_CODE__CHECK_PORT_WRITE_STATE(req_state)          \
 {                                                                        \
  const rw_state_type debug__port__write_state=m_spPort->m_write_state;   \
                                                                          \
  assert_msg(debug__port__write_state==(req_state),                       \
             "state="<<debug__port__write_state<<"\n"                     \
             "port=0x"<<std::hex<<m_spPort.ptr()<<"\n"                    \
             "this=0x"<<std::hex<<this);                                  \
 }

#else

#define IBP__LOCAL_DEBUG_CODE__CHECK_PORT_WRITE_STATE(req_state)

#endif

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port_BASE_v01::tag_writer

RemoteFB__Port_BASE_v01::tag_writer::tag_writer(RemoteFB__Port_BASE_v01* const pPort,
                                                bool                     const IsDeferredPacket)
 :m_spPort(structure::not_null_ptr(pPort))
 ,m_IsDeferredPacket(IsDeferredPacket)
{
 assert(m_spPort);
}//tag_writer

//------------------------------------------------------------------------
RemoteFB__Port_BASE_v01::tag_writer::~tag_writer()
{;}

//writer interface -------------------------------------------------------

#ifndef NDEBUG

protocol::P_ARCH RemoteFB__Port_BASE_v01::tag_writer::debug__get_protocol_architecture()const
{
 assert(m_spPort);

 return m_spPort->debug__get_protocol_architecture();
}//debug__get_protocol_architecture

#endif //NDEBUG

//------------------------------------------------------------------------
void RemoteFB__Port_BASE_v01::tag_writer::begin_write()
{
 assert(m_spPort);

 // 1. Переводим порт из свободного состояния в состояние записи

 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__Port_BASE_v01::tag_writer::begin_write";

 // ---------------------------------------- 0.
 switch(RemoteFB__Port_BASE_v01::rw_state_type const copyOfPortState=m_spPort->m_port_state)
 {
  case c_state__none:
  {
   break;
  }//case - none

  case c_state__failed:
  {
   this->helper__throw_error__port_has_failed_state();

   assert(false);
  }//case - failed

  default:
  {
   //ERROR - [BUG CHECK] неизвестное read-состояние порта

   structure::wstr_formatter freason(L"unexpected state of port: %1");

   freason<<copyOfPortState;

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#001",
     freason.c_str());
  }//default
 }//switch

 // ---------------------------------------- 1.
 const rw_state_type
  prevState=::InterlockedCompareExchange(&m_spPort->m_write_state,
                                         c_state__in_use,
                                         c_state__none);
 switch(prevState)
 {
  case c_state__none:
  {
   return;
  }//case - none

  case c_state__in_use:
  {
   //ERROR - [BUG CHECK] порт уже заблокирован другой операцией записи

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#002",
     L"port is already locked by another write-operation");
  }//case - in_use

  case c_state__failed:
  {
   //ERROR - предыдущая операция записи в порт завершилась с ошибками.

   IBP_ThrowSimpleError
    (E_FAIL,
     ibp_subsystem__remote_fb,
     ibp_mce_remote__cant_write_to_port__prev_write_op_was_failed_0);
  }//case

  default:
  {
   //ERROR - [BUG CHECK] неизвестное write-состояние порта

   structure::wstr_formatter freason(L"unexpected write-state of port: %1");

   freason<<prevState;

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#003",
     freason.c_str());
  }//default
 }//switch prevState
}//begin_write

//------------------------------------------------------------------------
void RemoteFB__Port_BASE_v01::tag_writer::end_write(bool const success)
{
 assert(m_spPort);

 IBP__LOCAL_DEBUG_CODE__CHECK_PORT_WRITE_STATE(c_state__in_use)

 if(!success)
 {
  DEBUG_CODE(const rw_state_type prevState=)
   ::InterlockedExchange(&m_spPort->m_write_state,c_state__failed);

  assert(prevState==c_state__in_use);

  return;
 }//if !success

 assert(success);

 //! \todo
 //!  Добавить отладочную проверку наличия отправляемых данных

 if(!m_IsDeferredPacket)
 {
  m_spPort->m_spSocket->FlushWriteBuf(); //throw
 }//if

 // Переводим порт из состояния записи в свободное состояние

 DEBUG_CODE(const rw_state_type prevState=)
  ::InterlockedExchange(&m_spPort->m_write_state,c_state__none);

 assert(prevState==c_state__in_use);
}//end_write

//------------------------------------------------------------------------
void RemoteFB__Port_BASE_v01::tag_writer::write__long(const protocol::P_LONG* const pv)
{
 assert(pv);
 assert(m_spPort);

 IBP__LOCAL_DEBUG_CODE__CHECK_PORT_WRITE_STATE(c_state__in_use)

 const protocol::P_LONG x=m_spPort->internal__htonl(pv);

 return m_spPort->m_spSocket->Write(sizeof(x),&x);
}//write__long

//------------------------------------------------------------------------
void RemoteFB__Port_BASE_v01::tag_writer::write__bytes
                                           (size_t                   const n,
                                            const protocol::P_UCHAR* const pb)
{
 assert(m_spPort);

 IBP__LOCAL_DEBUG_CODE__CHECK_PORT_WRITE_STATE(c_state__in_use)

 return m_spPort->m_spSocket->Write(n,pb);
}//write__bytes

//helper methods ---------------------------------------------------------
void RemoteFB__Port_BASE_v01::tag_writer::helper__throw_error__port_has_failed_state()const
{
 t_ibp_error exc(E_FAIL);

 {
  assert(m_spPort);

  const lock_guard_type __lockPortStateData(m_spPort->m_port_state_guard);

  assert(m_spPort->m_port_state==c_state__failed);

  for(size_t i=0,_c=m_spPort->m_port_state_errors.get_record_count();i!=_c;++i)
   exc.add_error(m_spPort->m_port_state_errors.get_record(i));
 }//local

 exc.add_error
  (E_FAIL,
   ibp_subsystem__remote_fb,
   ibp_mce_remote__cant_write_to_port__port_has_failed_state_0);

 exc.set_last_error_as_primary();

 exc.raise_me();
}//helper__throw_error__port_has_failed_state

////////////////////////////////////////////////////////////////////////////////
}/*nms base_v01*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
