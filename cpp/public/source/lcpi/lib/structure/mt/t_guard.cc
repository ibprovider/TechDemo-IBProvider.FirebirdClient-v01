////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 29.09.2020.
#ifndef _cpp_public_lcpi_lib_structure_mt__t_guard_CC_
#define _cpp_public_lcpi_lib_structure_mt__t_guard_CC_

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////
//class t_guard

inline t_guard::t_guard()
{
#ifndef NDEBUG
 m_cntLock=0;

 m_OwnerThreadID=0;
#endif

 ::InitializeCriticalSection(&m_cs);
}//t_guard

//------------------------------------------------------------------------
inline t_guard::~t_guard()
{
 LCPI__assert_msg(m_cntLock==0,"m_cntLock="<<m_cntLock<<". m_OwnerThreadID="<<m_OwnerThreadID);
 LCPI__assert_msg(m_OwnerThreadID==0,"m_OwnerThreadID="<<m_OwnerThreadID);

 ::DeleteCriticalSection(&m_cs);
}//~t_guard

//guard interface --------------------------------------------------------
inline void t_guard::lock()
{
 ::EnterCriticalSection(&m_cs);

#ifndef NDEBUG
 if(m_cntLock==0)
 {
  LCPI__assert(m_OwnerThreadID==0);

  ::InterlockedExchange(&m_OwnerThreadID,::GetCurrentThreadId());
 }
 else
 {
  LCPI__assert(m_OwnerThreadID==::GetCurrentThreadId());
 }//else

 ::InterlockedIncrement(&m_cntLock);
#endif
}//lock

//------------------------------------------------------------------------
inline bool t_guard::try_lock()
{
 LCPI__assert_s(FALSE==0);

 if(::TryEnterCriticalSection(&m_cs)==0)
  return false;

#ifndef NDEBUG
 if(m_cntLock==0)
 {
  LCPI__assert(m_OwnerThreadID==0);

  ::InterlockedExchange(&m_OwnerThreadID,::GetCurrentThreadId());
 }
 else
 {
  LCPI__assert(m_OwnerThreadID==::GetCurrentThreadId());
 }//else

 ::InterlockedIncrement(&m_cntLock);
#endif

 return true;
}//try_lock

//------------------------------------------------------------------------
inline void t_guard::unlock()
{
 LCPI__assert(m_cntLock>0);
 LCPI__assert(m_OwnerThreadID==::GetCurrentThreadId());

#ifndef NDEBUG
 if(::InterlockedDecrement(&m_cntLock)==0)
  ::InterlockedExchange(&m_OwnerThreadID,0);
#endif

 ::LeaveCriticalSection(&m_cs);
}//unlock

//------------------------------------------------------------------------
#ifndef NDEBUG

inline
void t_guard::debug__CheckThreadIsOwner(DWORD const ThreadID)const
{
 LCPI__assert(m_cntLock>0);
 LCPI__assert(m_OwnerThreadID==ThreadID);
}//debug__CheckThreadIsOwner

#endif // !NDEBUG

//------------------------------------------------------------------------
#ifndef NDEBUG

inline
void t_guard::debug__CheckThreadIsNotOwner(DWORD const ThreadID)const
{
 LCPI__assert(m_OwnerThreadID!=ThreadID);
}//debug__CheckThreadIsNotOwner

#endif // !NDEBUG

//------------------------------------------------------------------------
#ifndef NDEBUG

inline
void t_guard::debug__CheckCurrentThreadIsOwner()const
{
 LCPI__assert(m_cntLock>0);
 LCPI__assert(m_OwnerThreadID==::GetCurrentThreadId());
}//debug__CheckCurrentThreadIsOwner

#endif // !NDEBUG

//------------------------------------------------------------------------
#ifndef NDEBUG

inline
void t_guard::debug__CheckCurrentThreadIsNotOwner()const
{
 LCPI__assert(m_OwnerThreadID!=::GetCurrentThreadId());
}//debug__CheckCurrentThreadIsNotOwner

#endif // !NDEBUG

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
