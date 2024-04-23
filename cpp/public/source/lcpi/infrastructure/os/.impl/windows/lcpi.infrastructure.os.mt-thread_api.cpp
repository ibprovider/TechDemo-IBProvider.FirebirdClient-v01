////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. Thread API.
//                                                 Kovalenko Dmitry. 15.03.2024.
#include <_pch_.h>
//#pragma hdrstop

#include <lcpi/infrastructure/os/.impl/windows/lcpi.infrastructure.os.mt-thread_api.h>
#include <process.h>

namespace lcpi{namespace infrastructure{namespace os{namespace mt{
////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi::ErrorUtils

class LCPI_OS__ThreadApi::ErrorUtils LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=ErrorUtils;

 public:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowBugCheckError
               (const char* bugcheck_src,
                const char* bugcheck_reason);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowBugCheckError__UnknownWaitResult
               (const char* bugcheck_src,
                DWORD         wait_result);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowBugCheckError__InvalidArgumentValue
               (const char* bugcheck_src,
                const char* argument_name,
                const char* argument_value);

 public:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowSystemError(std::string msg);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowSystemError__CreateThread_Failed();

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowSystemError__GetThreadTimes_Failed();

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowSystemError__WaitForThread_Failed();

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowSystemError__CreateEvent_Failed();

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowSystemError__CloseEvent_Failed();

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowSystemError__SetEvent_Failed();

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowSystemError__ResetEvent_Failed();

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowSystemError__WaitForEvent_Failed();
};//class LCPI_OS__ThreadApi::ErrorUtils

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi - helper methods

void LCPI_OS__ThreadApi::ErrorUtils::ThrowBugCheckError
               (const char* const bugcheck_src,
                const char* const bugcheck_reason)
{
 LCPI__assert(bugcheck_src);
 LCPI__assert(bugcheck_reason);

 std::string errMsg="[BUG CHECK][";

 errMsg+=bugcheck_src;
 errMsg+="] - ";
 errMsg+=bugcheck_reason;
 errMsg+=".";

 throw std::runtime_error(errMsg);
}//ThrowBugCheckError

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowBugCheckError__UnknownWaitResult
               (const char* const bugcheck_src,
                DWORD       const wait_result)
{
 LCPI__assert(bugcheck_src);

 const std::string
  errReason
   ="Unknown wait result code ["+std::to_string(wait_result)+"]";

 self_type::ThrowBugCheckError
  (bugcheck_src,
   errReason.c_str());
}//ThrowBugCheckError__UnknownWaitResult

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowBugCheckError__InvalidArgumentValue
               (const char* const bugcheck_src,
                const char* const argument_name,
                const char* const argument_value)
{
 LCPI__assert(bugcheck_src);
 LCPI__assert(argument_name);
 LCPI__assert(argument_value);

 std::string errReason;

 errReason ="An invalid argument [";
 errReason+=argument_name;
 errReason+="] value [";
 errReason+=argument_value;
 errReason+="]";

 self_type::ThrowBugCheckError
  (bugcheck_src,
   errReason.c_str());
}//ThrowBugCheckError__InvalidArgumentValue

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowSystemError(std::string msg)
{
 const auto lastSystemErrorCode=::GetLastError();

 throw std::system_error(lastSystemErrorCode,std::system_category(),LCPI_STL_MOVE_VALUE(msg));
}//ThrowSystemError

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowSystemError__CreateThread_Failed()
{
 self_type::ThrowSystemError("Win32 thread is not created.");
}//ThrowSystemError__CreateThread_Failed

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowSystemError__GetThreadTimes_Failed()
{
 self_type::ThrowSystemError("The call of GetThreadTimes failed.");
}//ThrowSystemError__GetThreadTimes_Failed

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowSystemError__WaitForThread_Failed()
{
 self_type::ThrowSystemError("Waiting for Win32 thread failed.");
}//ThrowSystemError__WaitForThread_Failed

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowSystemError__CreateEvent_Failed()
{
 self_type::ThrowSystemError("Win32 event is not created.");
}//ThrowSystemError__CreateEvent_Failed

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowSystemError__CloseEvent_Failed()
{
 self_type::ThrowSystemError("Win32 event is not closed.");
}//ThrowSystemError__CloseEvent_Failed

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowSystemError__SetEvent_Failed()
{
 ErrorUtils::ThrowSystemError("Win32 event is not set.");
}//ThrowSystemError__SetEvent_Failed

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowSystemError__ResetEvent_Failed()
{
 ErrorUtils::ThrowSystemError("Win32 event is not reset.");
}//ThrowSystemError__ResetEvent_Failed

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ErrorUtils::ThrowSystemError__WaitForEvent_Failed()
{
 self_type::ThrowSystemError("Waiting for Win32 event failed.");
}//ThrowSystemError__WaitForEvent_Failed

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi::Helper

class LCPI_OS__ThreadApi::Helper LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  static TICK_VALUE FileTimeToTimeValue(const FILETIME& FileTime)
  {
   return (static_cast<TICK_VALUE>(FileTime.dwHighDateTime)<<32)+FileTime.dwLowDateTime;
  }//FileTimeToTimeValue
};//class LCPI_OS__ThreadApi::Helper

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi

LCPI_OS__ThreadApi::THREAD_HANDLE
 LCPI_OS__ThreadApi::CreateThread(THREAD_ROUTINE routine,void* pArg)
{
 LCPI__assert(routine!=nullptr);

 unsigned uThreadID=0;

 THREAD_HANDLE const
  hThread
   =reinterpret_cast<HANDLE>
     (_beginthreadex
       (nullptr,
        0,
        routine,
        pArg,
        0,
        &uThreadID));

 if(hThread==NULL)
  ErrorUtils::ThrowSystemError__CreateThread_Failed();

 return hThread;
}//CreateThread

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::WaitAndCloseThread(THREAD_HANDLE const hThread)
{
 LCPI__assert(hThread!=NULL);

#ifndef NDEBUG
 DWORD const debug__WaitResult=
#endif
  ::WaitForSingleObject
    (hThread,
     INFINITE);

 LCPI__assert(debug__WaitResult==WAIT_OBJECT_0);

#ifndef NDEBUG
 DWORD const debug__CloseResult=
#endif
 ::CloseHandle(hThread);

 LCPI__assert_s(TRUE==1);

 LCPI__assert(debug__CloseResult==TRUE);
}//WaitAndCloseThread

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::WaitResultCode
 LCPI_OS__ThreadApi::WaitForSingleThread(THREAD_HANDLE const hThread,
                                         TimeOut_t     const milliseconds)
{
 LCPI__assert(hThread!=NULL);

 const char* const c_bugcheck_src
  ="LCPI_OS__ThreadApi::WaitForSingleEvent";

 DWORD const
  dwResult
   =::WaitForSingleObject
      (hThread,
       milliseconds);

 switch(dwResult)
 {
  case WAIT_TIMEOUT:
   return WaitResultCode::Timeout;

  case WAIT_OBJECT_0:
   return WaitResultCode::Ok;

  case WAIT_FAILED:
   ErrorUtils::ThrowSystemError__WaitForThread_Failed();
 }//switch dwResult

 ErrorUtils::ThrowBugCheckError__UnknownWaitResult
  (c_bugcheck_src,
   dwResult);
}//WaitForSingleThread

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::EVENT_HANDLE
 LCPI_OS__ThreadApi::CreateEvent
                        (bool ManualReset,
                         bool InitialState)
{
 const EVENT_HANDLE
  handle
   =::CreateEvent
      (nullptr,
       ManualReset,
       InitialState,
       nullptr);

 if(handle==NULL)
  ErrorUtils::ThrowSystemError__CreateEvent_Failed();

 return handle;
}//CreateEvent

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::CloseEvent(EVENT_HANDLE const hEvent)
{
 LCPI__assert(hEvent!=NULL);

 if(!::CloseHandle(hEvent))
  ErrorUtils::ThrowSystemError__CloseEvent_Failed();
}//CloseEvent

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::SetEvent(EVENT_HANDLE hEvent)
{
 LCPI__assert(hEvent!=NULL);

 if(!::SetEvent(hEvent))
  ErrorUtils::ThrowSystemError__SetEvent_Failed();
}//SetEvent

//------------------------------------------------------------------------
void LCPI_OS__ThreadApi::ResetEvent(EVENT_HANDLE hEvent)
{
 LCPI__assert(hEvent!=NULL);

 if(!::ResetEvent(hEvent))
  ErrorUtils::ThrowSystemError__ResetEvent_Failed();
}//ResetEvent

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::WaitResultCode
 LCPI_OS__ThreadApi::WaitForSingleEvent
                        (EVENT_HANDLE const hEvent,
                         TimeOut_t    const milliseconds)
{
 LCPI__assert(hEvent!=NULL);

 const char* const c_bugcheck_src
  ="LCPI_OS__ThreadApi::WaitForSingleEvent";

 DWORD const
  dwResult
   =::WaitForSingleObject
      (hEvent,
       milliseconds);

 switch(dwResult)
 {
  case WAIT_TIMEOUT:
   return WaitResultCode::Timeout;

  case WAIT_OBJECT_0:
   return WaitResultCode::Ok;

  case WAIT_FAILED:
   ErrorUtils::ThrowSystemError__WaitForEvent_Failed();
 }//switch

 ErrorUtils::ThrowBugCheckError__UnknownWaitResult
  (c_bugcheck_src,
   dwResult);
}//WaitForSingleEvent

//------------------------------------------------------------------------
LCPI_OS__ThreadApi::MultiWaitResult
 LCPI_OS__ThreadApi::WaitForMultipleEvents
                        (size_t              const cEvents,
                         const EVENT_HANDLE* const rghEvents,
                         bool                const waitAll,
                         TimeOut_t           const milliseconds)
{
 LCPI__assert(cEvents>0);
 LCPI__assert(cEvents<=MAXIMUM_WAIT_OBJECTS);

 LCPI__CHECK_READ_TYPED_PTR(rghEvents,cEvents);

 LCPI__assert_s(FALSE==0);
 LCPI__assert_s(TRUE==1);

 const char* const c_bugcheck_src
  ="LCPI_OS__ThreadApi::WaitForMultipleEvents";

 if(cEvents==0 || cEvents>MAXIMUM_WAIT_OBJECTS)
 {
  ErrorUtils::ThrowBugCheckError__InvalidArgumentValue
   (c_bugcheck_src,
    "cEvents",
    std::to_string(cEvents).c_str());
 }//if

 LCPI__assert(MAXIMUM_WAIT_OBJECTS<(std::numeric_limits<DWORD>::max)());

 DWORD const
  dwResult
   =::WaitForMultipleObjects
       ((DWORD)cEvents,
        rghEvents,
        waitAll?TRUE:FALSE,
        milliseconds);

 switch(dwResult)
 {
  case WAIT_TIMEOUT:
   return MultiWaitResult(WaitResultCode::Timeout,(std::numeric_limits<size_t>::max)());

  case WAIT_FAILED:
   ErrorUtils::ThrowSystemError__WaitForEvent_Failed();

  default:
   break;
 }//switch dwResult

 if(dwResult>=WAIT_OBJECT_0 && dwResult<=(WAIT_OBJECT_0+cEvents))
  return MultiWaitResult(WaitResultCode::Ok,dwResult-WAIT_OBJECT_0);

 ErrorUtils::ThrowBugCheckError__UnknownWaitResult
  (c_bugcheck_src,
   dwResult);
}//WaitForMultipleEvents

////////////////////////////////////////////////////////////////////////////////
//class LCPI_OS__ThreadApi - thread time functions

void LCPI_OS__ThreadApi::GetCurrentThreadUsageTimes
                             (TIME_DURATION* const pKernelTime,
                              TIME_DURATION* const pUserTime)
{
 LCPI__assert(pKernelTime!=nullptr);
 LCPI__assert(pUserTime!=nullptr);

 LCPI__assert(TIME_DURATION::zero()==TIME_DURATION());

 (*pKernelTime)=TIME_DURATION::zero();
 (*pUserTime)=TIME_DURATION::zero();

 FILETIME tmp={0};
 FILETIME KernelTime={0};
 FILETIME UserTime={0};

 LCPI__assert_s(FALSE==0);

 if(::GetThreadTimes(::GetCurrentThread(),&tmp,&tmp,&KernelTime,&UserTime)==FALSE)
  ErrorUtils::ThrowSystemError__GetThreadTimes_Failed();

 (*pKernelTime)=TIME_DURATION(Helper::FileTimeToTimeValue(KernelTime));

 (*pUserTime)=TIME_DURATION(Helper::FileTimeToTimeValue(UserTime));
}//GetCurrentThreadUsageTimes

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms os*/}/*nms infrastructure*/}/*nms lcpi*/
