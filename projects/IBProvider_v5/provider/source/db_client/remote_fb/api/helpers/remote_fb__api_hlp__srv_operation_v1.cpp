////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__srv_operation_v1.cpp
//! \brief   Объект операции с сервером базы данных.
//! \author  Kovalenko Dmitry
//! \date    19.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/remote_fb__api_hlp__srv_operation_v1.h"
#include "source/db_client/remote_fb/api/svc/remote_fb__api_svc__db__cancel_operation.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_obj/fb_base/fb_api.h"
#include "source/db_obj/db_service_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__SrvOperation_v1

RemoteFB__API_HLP__SrvOperation_v1::RemoteFB__API_HLP__SrvOperation_v1
                                           (RemoteFB__ConnectorData* const pCnData)
 :m_spCnData(lib::structure::not_null_ptr(pCnData))
 ,m_state(c_state__before_send)
#ifndef NDEBUG
 ,m_debug__op_cancel_was_sended(0)
#endif
{
 assert(m_spCnData);
}//RemoteFB__API_HLP__SrvOperation_v1

//------------------------------------------------------------------------
RemoteFB__API_HLP__SrvOperation_v1::~RemoteFB__API_HLP__SrvOperation_v1()
{;}

//operation interface ----------------------------------------------------
void RemoteFB__API_HLP__SrvOperation_v1::cancel()
{
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__SrvOperation_v1::cancel";

 const state_type
  prevState
   =lib::structure::mt::interlocked::exchange
     (&m_state,
      self_type::c_state__cancelled);

 switch(prevState)
 {
  case c_state__after_send:
  {
   //Отправляем op_cancel
   assert(!m_debug__op_cancel_was_sended);

#ifndef NDEBUG
   lib::structure::mt::interlocked::exchange(&m_debug__op_cancel_was_sended,1);
#endif

   api::RemoteFB__SVC__CancelDbOperation_Ptr spCancelSvc;

   db_obj::query_db_service__if_it_exists(m_spCnData.ptr(),&spCancelSvc);

   if(!spCancelSvc)
    helper__throw_err__cancel_not_support();

   spCancelSvc->exec(m_spCnData);//throw

   break;
  }//case after_send

  case c_state__cancelled:
  {
   //мы уже установили признак отмены операции

   //проверяем, что отмена выполнения в принципе поддерживается.
   if(!m_spCnData->query_service(db_obj::__db_guid<api::RemoteFB__SVC__CancelDbOperation>()))
    helper__throw_err__cancel_not_support();

   break;
  }//case cancelled

  case c_state__before_send:
  {
   //Отмена операции будет выполнена её собственным потоком в on_after_send

   //проверяем, что отмена выполнения в принципе поддерживается.
   if(!m_spCnData->query_service(db_obj::__db_guid<api::RemoteFB__SVC__CancelDbOperation>()))
    helper__throw_err__cancel_not_support();

   break;
  }//case before_send

  default:
  {
   //ERROR - [BUG CHECK] неизвестное состояние.

   self_type::helper__throw_bug_check__unk_state
    (c_bugcheck_src,
     L"#001",
     prevState);
  }//default
 }//switch
}//cancel

//------------------------------------------------------------------------
void RemoteFB__API_HLP__SrvOperation_v1::on_before_send()
{
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__SrvOperation_v1::on_before_send";

 const state_type
  prevState
   =lib::structure::mt::interlocked::compare_exchange
     (&m_state,
      self_type::c_state__before_send,
      self_type::c_state__after_send);

 switch(prevState)
 {
  case c_state__before_send:
  {
   //это мы первый раз вызвали данный метод

   break;
  }//case before_send

  case c_state__after_send:
  {
   //отправка вторичного пакета операции

   break;
  }//case after_send

  case c_state__cancelled:
  {
   //ERROR - операция была отменена.

   IBP_ThrowOperationWasCancelled();
  }//case cancelled

  default:
  {
   //ERROR - [BUG CHECK] неизвестное состояние.

   self_type::helper__throw_bug_check__unk_state
    (c_bugcheck_src,
     L"#001",
     prevState);
  }//default
 }//switch prevState
}//on_before_send

//------------------------------------------------------------------------
void RemoteFB__API_HLP__SrvOperation_v1::on_after_send()
{
 assert(m_spCnData);
 assert(m_spCnData->GetPort());

 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__SrvOperation_v1::on_after_send";

 try
 {
  const state_type
   prevState
    =lib::structure::mt::interlocked::compare_exchange
      (&m_state,
       c_state__after_send,
       c_state__before_send);

  switch(prevState)
  {
   case c_state__before_send:
   {
    //нормальное завершение отправки команды на сервер

    break;
   }//case before_send

   case c_state__cancelled:
   {
    //Пока мы отправляли запрос на сервер была выполнена отмена операции.
    //Нужно отправить op_cancel на сервер.

    assert(!m_debug__op_cancel_was_sended);

#ifndef NDEBUG
    lib::structure::mt::interlocked::exchange(&m_debug__op_cancel_was_sended,1);
#endif

    //отправляем, только если отмена операций поддерживается.
    api::RemoteFB__SVC__CancelDbOperation_Ptr spCancelSvc;

    db_obj::query_db_service__if_it_exists(m_spCnData.ptr(),&spCancelSvc);

    if(spCancelSvc)
     spCancelSvc->exec(m_spCnData);//throw

    break;
   }//case cancelled

   default:
   {
    //ERROR - [BUG CHECK] неизвестное состояние.

    self_type::helper__throw_bug_check__unk_state
     (c_bugcheck_src,
      L"#001",
      prevState);
   }//default
  }//switch prevState
 }
 catch(...)
 {
  //если возникла ошибка, то порт перешел в несогласованное состояние.

  RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(m_spCnData->GetPort());

  assert(false);
 }//catch
}//on_after_send

//helper methods ---------------------------------------------------------
void RemoteFB__API_HLP__SrvOperation_v1::helper__throw_err__cancel_not_support()
{
 IBP_ThrowSimpleError_safe
  (DB_E_CANTCANCEL,
   ibp_mce_cmd_cancel_not_supported_0);
}//helper__throw_err__cancel_not_support

//------------------------------------------------------------------------
void RemoteFB__API_HLP__SrvOperation_v1::helper__throw_bug_check__unk_state
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            state_type     const stateID)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   L"unknown state: %1",
   stateID);
}//helper__throw_bug_check__unk_state

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__SrvOperation_v1::tag_send_frame

RemoteFB__API_HLP__SrvOperation_v1::tag_send_frame::tag_send_frame
                                           (RemoteFB__API_HLP__SrvOperation_v1* const pOp)
 :m_spOp(lib::structure::not_null_ptr(pOp))
{
 assert(m_spOp);

 m_spOp->on_before_send(); //throw
}//tag_send_frame

//------------------------------------------------------------------------
RemoteFB__API_HLP__SrvOperation_v1::tag_send_frame::~tag_send_frame()
{
}

//------------------------------------------------------------------------
void RemoteFB__API_HLP__SrvOperation_v1::tag_send_frame::complete()
{
 assert(m_spOp);

 RemoteFB__API_HLP__SrvOperation_v1::self_ptr spOp;

 spOp.swap(m_spOp);

 assert(spOp);
 assert(!m_spOp);

 spOp->on_after_send();
}//complete

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
