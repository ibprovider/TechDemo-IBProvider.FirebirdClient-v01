////////////////////////////////////////////////////////////////////////////////
//Classes for multi-threaded programs for Win32
//                                                 Dmitry Kovalenko. 12.04.2004.
#ifndef _win32_mt_H_
#define _win32_mt_H_

#include <win32lib/win32_handle.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//content

class TSynchronizeObject;
class TCriticalSection;
class TLockCriticalSection;
class TThread;
class TMutex;
class TLockMutex;
class TEvent;
class TSemaphore;
class SWMRG;
class TLockSWMRGToRead;
class TLockSWMRGToWrite;

////////////////////////////////////////////////////////////////////////////////
//class TSynchronizeObject

class TSynchronizeObject:public THandleWin32
{
 private:
  using self_type=TSynchronizeObject;

  TSynchronizeObject(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 protected:
  TSynchronizeObject()
  {
  }

 public:
  DWORD Wait(long const Milliseconds=INFINITE)const
  {
   assert(this->handle!=0);

   return ::WaitForSingleObject(this->handle,Milliseconds);
  }//Wait
};//class TSynchronizeObject

////////////////////////////////////////////////////////////////////////////////
//class TCriticalSection

class TCriticalSection LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=TCriticalSection;

  TCriticalSection(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  TCriticalSection()
   {
    ::InitializeCriticalSection(&m_section);
   }

 ~TCriticalSection()
  {
   ::DeleteCriticalSection(&m_section);
  }

  operator CRITICAL_SECTION& ()
  {
   return m_section;
  }

  void Enter()
  {
   ::EnterCriticalSection(&m_section);
  }

  void Leave()
  {
   ::LeaveCriticalSection(&m_section);
  }

 private:
  CRITICAL_SECTION m_section;
};//class TCriticalSection

////////////////////////////////////////////////////////////////////////////////
//class TLockCriticalSection

class TLockCriticalSection LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=TLockCriticalSection;

  TLockCriticalSection(const self_type&)=delete;
  TLockCriticalSection(const CRITICAL_SECTION&)=delete;

  self_type& operator = (const self_type&);

 public:
  TLockCriticalSection(CRITICAL_SECTION& section)
   :m_section(section)
  {
   ::EnterCriticalSection(&m_section);
  }

 ~TLockCriticalSection()
  {
   ::LeaveCriticalSection(&m_section);
  }

 private:
  CRITICAL_SECTION& m_section;
};//class TLockCriticalSection

////////////////////////////////////////////////////////////////////////////////
//class TThread

class TThread LCPI_CPP_CFG__CLASS__FINAL
 :public TSynchronizeObject
{
 private:
  using self_type=TThread;
  using inherited=TSynchronizeObject;

  TThread(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using thread_entry_point_func_ex
   =unsigned (__stdcall *)
     (void* pvParam);

 public:
  DWORD ThreadID;

 public:
  TThread();

 ~TThread();

  virtual BOOL Close() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 public:
  bool Create(LPSECURITY_ATTRIBUTES  Attributes,
              DWORD                  StackSize,
              LPTHREAD_START_ROUTINE pStartAddress,
              LPVOID                 pvParameter,
              DWORD                  CreationFlag);

  bool BeginEx(LPSECURITY_ATTRIBUTES      Attributes,
               unsigned                   StackSize,
               thread_entry_point_func_ex pStartAddress,
               LPVOID                     pvParameter,
               unsigned                   CreationFlag);

  //FALSE - error
  //*pExitCode==STILL_ACTIVE - thread not terminate
  BOOL  GetExitCode(LPDWORD pExitCode)  {return ::GetExitCodeThread(handle,pExitCode);}
  int   GetPriority()                   {return ::GetThreadPriority(handle);}
  BOOL  SetPriority(int nPriority)      {return ::SetThreadPriority(handle,nPriority);}

  //[2018-12-23]
  //DWORD Resume()                        {return ::ResumeThread(handle);}
  //DWORD Suspend()                       {return ::SuspendThread(handle);}
  //BOOL  Terminate()                     {return ::TerminateThread(handle,0);}
};//class TThread

////////////////////////////////////////////////////////////////////////////////
//class TMutex

class TMutex LCPI_CPP_CFG__CLASS__FINAL
 :public TSynchronizeObject
{
 private:
  using self_type=TMutex;
  using inherited=TSynchronizeObject;

  TMutex(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  TMutex();

  bool Create(LPSECURITY_ATTRIBUTES Attributes,
              bool                  InitialOwner,
              LPCTSTR               lpName=NULL);

  BOOL Release()
  {
   return ::ReleaseMutex(handle);
  }
};//class TMutex

////////////////////////////////////////////////////////////////////////////////
//class TLockMutex

class TLockMutex LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=TLockMutex;
  using inherited=TSynchronizeObject;

  TLockMutex(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 protected:
  HANDLE m_hMutex;

 public:
  TLockMutex(HANDLE hMutex);

 ~TLockMutex();

  void Lock(HANDLE hMutex);

  void UnLock();
};//class TLockMutex

////////////////////////////////////////////////////////////////////////////////
//class TEvent

class TEvent LCPI_CPP_CFG__CLASS__FINAL
 :public TSynchronizeObject
{
 private:
  using self_type=TEvent;
  using inherited=TSynchronizeObject;

  TEvent(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  TEvent();

  bool Create(LPSECURITY_ATTRIBUTES Attributes,
              bool                  ManualReset,
              bool                  InitialState,
              LPCTSTR               lpName=NULL);

  BOOL Set()
  {
   assert(this->handle!=0);

   return ::SetEvent(this->handle);
  }//Set

  BOOL Reset()
  {
   assert(this->handle!=0);

   return ::ResetEvent(this->handle);
  }//Reset

  BOOL Pulse()
  {
   assert(this->handle!=0);

   return ::PulseEvent(this->handle);
  }//Pulse
};//class TEvent

////////////////////////////////////////////////////////////////////////////////
//class TSemaphore

class TSemaphore LCPI_CPP_CFG__CLASS__FINAL
 :public TSynchronizeObject
{
 private:
  using self_type=TSemaphore;
  using inherited=TSynchronizeObject;

  TSemaphore(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  TSemaphore();

  bool Create(LPSECURITY_ATTRIBUTES Attributes,
              long                  InitialCount,
              long                  MaxCount,
              LPCTSTR               lpName=NULL);

  BOOL Release(long ReleaseCount,long* PreviusCount);
};//class TSemaphore

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
#endif
