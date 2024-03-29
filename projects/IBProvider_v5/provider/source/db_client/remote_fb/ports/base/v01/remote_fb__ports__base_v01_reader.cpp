////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__ports__base_v01
//! \file    remote_fb__ports__base_v01_reader.cpp
//! \brief   Реализация интерфейса читателя из стандартного порта.
//! \author  Kovalenko Dmitry
//! \date    29.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01_reader.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace base_v01{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Port_BASE_v01::tag_reader

RemoteFB__Port_BASE_v01::tag_reader::tag_reader(RemoteFB__Port_BASE_v01* const pPort)
 :m_spPort(lib::structure::not_null_ptr(pPort))
{
 assert(m_spPort);
}//tag_reader

//------------------------------------------------------------------------
RemoteFB__Port_BASE_v01::tag_reader::~tag_reader()
{;}

//reader interface -------------------------------------------------------

#ifndef NDEBUG

protocol::P_ARCH RemoteFB__Port_BASE_v01::tag_reader::debug__get_protocol_architecture()const
{
 assert(m_spPort);

 return m_spPort->debug__get_protocol_architecture();
}//debug__get_protocol_architecture

#endif //NDEBUG

//------------------------------------------------------------------------
// [2015-12-07]
//  Возникла непонятная проблем с тестовой сборкой.
//   - сработал ассерт, проверяющий m_spPort->m_read_state.
//     - отладчик показывает что состояние корректное.
//     - стеки выглядят поврежденными.
//
//  Так что, для улучшения диагностики, сначала делаем копию состояния, а потом
//  её проверим. Кроме того, выводим в сообщении адрес порта и this.

#ifndef NDEBUG

#define IBP__LOCAL_DEBUG_CODE__CHECK_PORT_READ_STATE(req_state)           \
 {                                                                        \
  const rw_state_type debug__port__read_state=m_spPort->m_read_state;     \
                                                                          \
  assert_msg(debug__port__read_state==(req_state),                        \
             "state="<<debug__port__read_state<<"\n"                      \
             "port=0x"<<std::hex<<m_spPort.ptr()<<"\n"                    \
             "this=0x"<<std::hex<<this);                                  \
 }

#else

#define IBP__LOCAL_DEBUG_CODE__CHECK_PORT_READ_STATE(req_state)

#endif

//------------------------------------------------------------------------
void RemoteFB__Port_BASE_v01::tag_reader::begin_read()
{
 // Переводим порт из свободного состояния в состояние чтения

 assert(m_spPort);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__Port_BASE_v01::tag_reader::begin_read";

 //-----------------------------------------
 switch(rw_state_type const copyOfPortState=m_spPort->m_port_state)
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
  prevState
   =lib::structure::mt::interlocked::compare_exchange
     (&m_spPort->m_read_state,
      c_state__in_use,
      c_state__none);

 switch(prevState)
 {
  case c_state__none:
  {
   return;
  }//case

  case c_state__in_use:
  {
   //ERROR - [BUG CHECK] порт уже заблокирован другой операцией чтения

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#002",
     L"port is already locked by another read-operation");
  }//case

  case c_state__failed:
  {
   //ERROR - предыдущая операция чтения из порта завершилась с ошибками.

   IBP_ThrowSimpleError
    (E_FAIL,
     ibp_subsystem__remote_fb,
     ibp_mce_remote__cant_read_from_port__prev_read_op_was_failed_0);
  }//case

  default:
  {
   //ERROR - [BUG CHECK] неизвестное read-состояние порта

   structure::wstr_formatter freason(L"unexpected read-state of port: %1");

   freason<<prevState;

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#003",
     freason.c_str());
  }//default
 }//switch prevState
}//begin_read

//------------------------------------------------------------------------
void RemoteFB__Port_BASE_v01::tag_reader::end_read(bool const success)
{
 // Переводим порт из состояния чтения в свободное состояние

 assert(m_spPort);

 IBP__LOCAL_DEBUG_CODE__CHECK_PORT_READ_STATE(c_state__in_use)

 if(success)
 {
  DEBUG_CODE(const rw_state_type prevState=)
   lib::structure::mt::interlocked::exchange
    (&m_spPort->m_read_state,
     c_state__none);

  assert(prevState==c_state__in_use);
 }
 else
 {
  assert(!success);

  DEBUG_CODE(const rw_state_type prevState=)
   lib::structure::mt::interlocked::exchange
    (&m_spPort->m_read_state,
     c_state__failed);

  assert(prevState==c_state__in_use);
 }//else
}//end_read

//------------------------------------------------------------------------
void RemoteFB__Port_BASE_v01::tag_reader::read__long(protocol::P_LONG* const pv)
{
 assert(pv);
 assert(m_spPort);

 IBP__LOCAL_DEBUG_CODE__CHECK_PORT_READ_STATE(c_state__in_use)

 protocol::P_LONG x DEBUG_CODE(=lib::structure::negative_one);

 this->helper__read(sizeof(x),&x); //throw

 (*pv)=m_spPort->internal__ntohl(&x);
}//read__long

//------------------------------------------------------------------------
void RemoteFB__Port_BASE_v01::tag_reader::read__bytes(size_type          const n,
                                                      protocol::P_UCHAR* const pb)
{
 assert(m_spPort);

 IBP__LOCAL_DEBUG_CODE__CHECK_PORT_READ_STATE(c_state__in_use)

 //-------
 return this->helper__read(n*sizeof(*pb),pb); //throw
}//read__bytes

//helper methods ---------------------------------------------------------
void RemoteFB__Port_BASE_v01::tag_reader::helper__read(size_type const cb,
                                                       void*     const pv)const
{
 auto remain_cb=cb;
 auto next_pv  =pv;

 for(DEBUG_CODE(size_t debug__nPass=0);remain_cb!=0;)
 {
  assert(remain_cb>0);

  DEBUG_CODE(++debug__nPass;)

  size_t const readed=m_spPort->m_spSocket->Read2(remain_cb,next_pv); //throw

  assert(readed>0);
  assert(readed<=remain_cb);

  assert_s(sizeof(char)==1);

  remain_cb-=readed;
  next_pv   =reinterpret_cast<char*>(next_pv)+readed;
 }//for remain_cb!=0
}//helper__read

//------------------------------------------------------------------------
void RemoteFB__Port_BASE_v01::tag_reader::helper__throw_error__port_has_failed_state()const
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
   ibp_mce_remote__cant_read_from_port__port_has_failed_state_0);

 exc.set_last_error_as_primary();

 exc.raise_me();
}//helper__throw_error__port_has_failed_state

////////////////////////////////////////////////////////////////////////////////
}/*nms base_v01*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
