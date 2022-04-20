////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <win32lib/win32_mt.h>
#include <process.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//class TThread

win32lib::TThread::TThread()
 :ThreadID(0)
{
}

//------------------------------------------------------------------------
win32lib::TThread::~TThread()
{
 _VERIFY(this->Close());
}//~TThread

//------------------------------------------------------------------------
BOOL win32lib::TThread::Close()
{
 this->ThreadID=0;

 return inherited::Close();
}//Close

//------------------------------------------------------------------------
bool win32lib::TThread::Create(LPSECURITY_ATTRIBUTES  const pAttributes,
                               DWORD                  const StackSize,
                               LPTHREAD_START_ROUTINE const pStartAddress,
                               LPVOID                 const pParameter,
                               DWORD                  const CreationFlag)
{
 if(!this->Close())
  return false;

 this->handle=::CreateThread(pAttributes,
                             StackSize,
                             pStartAddress,
                             pParameter,
                             CreationFlag,
                             &this->ThreadID);

 return this->handle!=NULL;
}//Create

//------------------------------------------------------------------------
bool win32lib::TThread::BeginEx(LPSECURITY_ATTRIBUTES      const Attributes,
                                unsigned                   const StackSize,
                                thread_entry_point_func_ex const pStartAddress,
                                LPVOID                     const pvParameter,
                                unsigned                   const CreationFlag)
{
 if(!this->Close())
  return false;

 unsigned uThreadID(0);

 this->handle=reinterpret_cast<HANDLE>(_beginthreadex(Attributes,
                                                      StackSize,
                                                      pStartAddress,
                                                      pvParameter,
                                                      CreationFlag,
                                                      &uThreadID));
 if(this->handle==NULL)
  return false;

 assert(this->handle!=NULL);

 this->ThreadID=uThreadID;

 return true;
}//BeginEx

////////////////////////////////////////////////////////////////////////////////
//class TMutex

TMutex::TMutex()
{
}

//------------------------------------------------------------------------
bool TMutex::Create(LPSECURITY_ATTRIBUTES const Attributes,
                    bool                  const InitialOwner,
                    LPCTSTR               const lpName)
{
 assert(this->handle==NULL);

 this->handle=::CreateMutex(Attributes,InitialOwner,lpName);

 return this->handle!=NULL;
}//Create

////////////////////////////////////////////////////////////////////////////////
//class TLockMutex

TLockMutex::TLockMutex(HANDLE hMutex)
 :m_hMutex(NULL)
{
 this->Lock(hMutex);
}

//------------------------------------------------------------------------
TLockMutex::~TLockMutex()
{
 this->UnLock();
}

//------------------------------------------------------------------------
void TLockMutex::Lock(HANDLE hMutex)
{
 assert(m_hMutex==NULL);

 m_hMutex=hMutex;

 ::WaitForSingleObject(m_hMutex,INFINITE);
}//Lock

//------------------------------------------------------------------------
void TLockMutex::UnLock()
{
 if(m_hMutex!=NULL)
 {
  ::ReleaseMutex(m_hMutex);

  m_hMutex=NULL;
 }
}//UnLock

////////////////////////////////////////////////////////////////////////////////
//class TEvent

TEvent::TEvent()
{
 assert(this->handle==NULL);
}//TEvent

//------------------------------------------------------------------------
bool TEvent::Create(LPSECURITY_ATTRIBUTES const Attributes,
                    bool                  const ManualReset,
                    bool                  const InitialState,
                    LPCTSTR               const lpName)
{
 assert(this->handle==NULL);

 if(!this->Close())
  return false;

 assert(this->handle==NULL);

 this->handle=::CreateEvent(Attributes,ManualReset,InitialState,lpName);

 return this->handle!=NULL;
}//Create

////////////////////////////////////////////////////////////////////////////////
//class TSemaphore

TSemaphore::TSemaphore()
{
}

//------------------------------------------------------------------------
bool TSemaphore::Create(LPSECURITY_ATTRIBUTES const Attributes,
                        long                  const InitialCount,
                        long                  const MaxCount,
                        LPCTSTR               const lpName)
{
 assert(this->handle==NULL);

 this->handle=::CreateSemaphore(Attributes,InitialCount,MaxCount,lpName);

 return this->handle!=NULL;
}//Create

//------------------------------------------------------------------------
BOOL TSemaphore::Release(long  const ReleaseCount,
                         long* const PreviusCount)
{
 assert(this->handle!=NULL);

 return ::ReleaseSemaphore(this->handle,ReleaseCount,PreviusCount);
}//Release

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
