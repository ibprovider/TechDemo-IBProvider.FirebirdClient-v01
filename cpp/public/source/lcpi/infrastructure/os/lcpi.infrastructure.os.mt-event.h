////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. Atomic functions.
//                                                 Kovalenko Dmitry. 15.03.2024.
#ifndef _lcpi_infrastructure_os_mt__event_H_
#define _lcpi_infrastructure_os_mt__event_H_

#include <lcpi/infrastructure/os/lcpi.infrastructure.os.mt-thread_api.h>

namespace lcpi{namespace infrastructure{namespace os{namespace mt{
////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__Event

class LCPI_OS__Event LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=LCPI_OS__Event;

  LCPI_OS__Event(const self_type&)=delete;
  self_type& operator = (const self_type)=delete;

 public:
  using EVENT_HANDLE=LCPI_OS__ThreadApi::EVENT_HANDLE;

  using WaitResultCode=LCPI_OS__ThreadApi::WaitResultCode;

  using TimeOut_t=LCPI_OS__ThreadApi::TimeOut_t;

 public:
  LCPI_OS__Event(bool ManualReset,bool InitialState)
   :m_hEvent(LCPI_OS__ThreadApi::CreateEvent(ManualReset,InitialState)) //throw
  {
   LCPI__assert(m_hEvent!=EVENT_HANDLE());
  }//LCPI_OS__Event

 ~LCPI_OS__Event()
  {
   LCPI__assert(m_hEvent!=EVENT_HANDLE());

   try
   {
    LCPI_OS__ThreadApi::CloseEvent(m_hEvent);
   }
   catch(...)
   {
    LCPI__assert(false);
   }
  }//~LCPI_OS__Event

  //interface ------------------------------------------------------------
  EVENT_HANDLE GetNativeHandle()const
  {
   LCPI__assert(m_hEvent!=EVENT_HANDLE());

   return m_hEvent;
  }//GetNativeHandle

  //----------------------------------------------------------------------
  void Set__Throw()
  {
   LCPI__assert(m_hEvent!=EVENT_HANDLE());

   return LCPI_OS__ThreadApi::SetEvent(m_hEvent);
  }//Set__Throw

  //----------------------------------------------------------------------
  void Reset__Throw()
  {
   LCPI__assert(m_hEvent!=EVENT_HANDLE());

   return LCPI_OS__ThreadApi::ResetEvent(m_hEvent);
  }//Reset__Throw

  //----------------------------------------------------------------------
  WaitResultCode Wait__Throw(TimeOut_t milliseconds)const
  {
   LCPI__assert(m_hEvent!=EVENT_HANDLE());

   return LCPI_OS__ThreadApi::WaitForSingleEvent(m_hEvent,milliseconds);
  }//Wait__Throw

 private:
  EVENT_HANDLE m_hEvent;
};//class LCPI_OS__Event

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms os*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
