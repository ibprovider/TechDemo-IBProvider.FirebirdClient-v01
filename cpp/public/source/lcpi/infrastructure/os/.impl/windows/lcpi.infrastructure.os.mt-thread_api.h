////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. Thread API.
//                                                 Kovalenko Dmitry. 26.03.2024.
#ifndef _lcpi_infrastructure_os_mt_impl_windows__thread_api_H_
#define _lcpi_infrastructure_os_mt_impl_windows__thread_api_H_

#include <lcpi/.config.h>

#include <chrono>
#include <Windows.h>

namespace lcpi{namespace infrastructure{namespace os{namespace mt{
////////////////////////////////////////////////////////////////////////////////

#define LCPI_OS__DECLARE_THREAD_ROUTINE(Name) \
 unsigned __stdcall Name (void* pArg)

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi

class LCPI_OS__ThreadApi LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=LCPI_OS__ThreadApi;

 public:
  using THREAD_ID     = DWORD;

  using THREAD_HANDLE = HANDLE;
  using EVENT_HANDLE  = HANDLE;

  using TICK_VALUE    = std::int64_t;

  using TIME_RATIO    = std::ratio<1,10*1000*1000>; //10 microseconds
  using TIME_DURATION = std::chrono::duration<TICK_VALUE,TIME_RATIO>;

 public:
  enum class WaitResultCode
  {
   Ok      =0,
   Timeout =1,
  };//enum WaitResultCode

  class MultiWaitResult LCPI_CPP_CFG__CLASS__FINAL
  {
   public:
    WaitResultCode Code;
    size_t         ObjectIndex;

    MultiWaitResult(WaitResultCode const _Code,size_t const _ObjectIndex)
     :Code(_Code)
     ,ObjectIndex(_ObjectIndex)
    {
    }
  };//class MultiWaitResult

  using TimeOut_t=DWORD;

  static const TimeOut_t Infinite=(TimeOut_t)-1;

 public: //Thread functions ----------------------------------------------
  using THREAD_ROUTINE=unsigned (__stdcall *) (void*);

  static THREAD_ID GetCurrentThreadId();

  static THREAD_HANDLE CreateThread(THREAD_ROUTINE,void* pArg);

  static void WaitAndCloseThread(THREAD_HANDLE hThread);

  static WaitResultCode WaitForSingleThread(THREAD_HANDLE hThread,TimeOut_t milliseconds);

 public: //Event functions -----------------------------------------------
  static EVENT_HANDLE CreateEvent(bool ManualReset,bool InitialState);

  static void CloseEvent(EVENT_HANDLE hEvent);

  static void SetEvent(EVENT_HANDLE hEvent);

  static void ResetEvent(EVENT_HANDLE hEvent);

  static WaitResultCode WaitForSingleEvent(EVENT_HANDLE hEvent,TimeOut_t milliseconds);

  static MultiWaitResult WaitForMultipleEvents
                             (size_t              cEvents,
                              const EVENT_HANDLE* rghEvents,
                              bool                waitAll,
                              TimeOut_t           milliseconds);

 public:
  static void GetCurrentThreadUsageTimes(TIME_DURATION* pKernelTime,TIME_DURATION* pUserTime);

 private:
  class ErrorUtils;
  class Helper;
};//class LCPI_OS__ThreadApi

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi

inline LCPI_OS__ThreadApi::THREAD_ID LCPI_OS__ThreadApi::GetCurrentThreadId()
{
 return ::GetCurrentThreadId();
}//GetCurrentThreadID

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms os*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
