////////////////////////////////////////////////////////////////////////////////
//Library for thread's configurations
//                                                 Dmitry Kovalenko. 07.09.2019
#ifndef _t_thread_traits__multi_CC_
#define _t_thread_traits__multi_CC_

#include <structure/mt/interlocked.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__multi

inline void t_thread_traits__multi::add(volatile int_type* const x,int_type a)
{
 ::InterlockedExchangeAdd(const_cast<int_type*>(x),a);
}//add

//------------------------------------------------------------------------
inline t_thread_traits__multi::int_type t_thread_traits__multi::increment(volatile int_type* const x)
{
 return interlocked::increment(x);
}//increment

//------------------------------------------------------------------------
inline t_thread_traits__multi::int_type t_thread_traits__multi::decrement(volatile int_type* const x)
{
 return interlocked::decrement(x);
}//decrement

//------------------------------------------------------------------------
template<typename T1,typename T2>
inline T1 t_thread_traits__multi::exchange(volatile T1* const target,T2 const value)
{
 using _e
  =typename std::conditional
     <std::is_enum<T1>::value,
      tag_exchange__enum,
      tag_exchange__std>::type;

 return _e::exec(target,value);
}//exchange

////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__multi::tag_exchange__enum

class t_thread_traits__multi::tag_exchange__enum
{
 public:
  template<typename T1>
  static T1 exec(volatile T1* const target,T1 const value)
  {
   assert_s(std::is_enum<T1>::value);

   typedef typename std::underlying_type<T1>::type _ut;

   assert_s(sizeof(_ut)==sizeof(T1));

   return static_cast<T1>
           (tag_exchange__std::exec
             ((_ut*)target,
              static_cast<_ut>(value)));
  }//exec
};//struct t_thread_traits__multi::tag_exchange__enum

////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__multi::tag_exchange__std

class t_thread_traits__multi::tag_exchange__std
{
 public:
  static long exec(volatile long* const target,long const value)
  {
   assert(target);

   return ::InterlockedExchange(target,value);
  }//exec

  static int exec(volatile int* const target,int const value)
  {
   assert(target);
   assert_s(sizeof(long)==sizeof(int));

   return (int)::InterlockedExchange((volatile long*)target,(long)value);
  }//exec
};//struct t_thread_traits__multi::tag_exchange__std

////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__multi::tag_guard

inline
t_thread_traits__multi::tag_guard::tag_guard()
{
#ifndef NDEBUG
 m_cntLock=0;

 m_OwnerThreadID=0;
#endif

 ::InitializeCriticalSection(&m_cs);
}//tag_guard

//------------------------------------------------------------------------
inline
t_thread_traits__multi::tag_guard::~tag_guard()
{
 assert_msg(m_cntLock==0,"m_cntLock="<<m_cntLock<<". m_OwnerThreadID="<<m_OwnerThreadID);
 assert_msg(m_OwnerThreadID==0,"m_OwnerThreadID="<<m_OwnerThreadID);

 ::DeleteCriticalSection(&m_cs);
}//~tag_guard

//guard interface --------------------------------------------------------
inline
void t_thread_traits__multi::tag_guard::lock()
{
 ::EnterCriticalSection(&m_cs);

#ifndef NDEBUG
 if(m_cntLock==0)
 {
  assert(m_OwnerThreadID==0);

  ::InterlockedExchange(&m_OwnerThreadID,::GetCurrentThreadId());
 }
 else
 {
  assert(m_OwnerThreadID==::GetCurrentThreadId());
 }//else

 ::InterlockedIncrement(&m_cntLock);
#endif
}//lock

//------------------------------------------------------------------------
inline
void t_thread_traits__multi::tag_guard::unlock()
{
 assert(m_cntLock>0);
 assert(m_OwnerThreadID==::GetCurrentThreadId());

#ifndef NDEBUG
 if(::InterlockedDecrement(&m_cntLock)==0)
  ::InterlockedExchange(&m_OwnerThreadID,0);
#endif

 ::LeaveCriticalSection(&m_cs);
}//unlock

//------------------------------------------------------------------------
#ifndef NDEBUG

inline
void t_thread_traits__multi::tag_guard::debug__CheckThreadIsOwner(DWORD const ThreadID)const
{
 assert(m_cntLock>0);
 assert(m_OwnerThreadID==ThreadID);
}//debug__CheckThreadIsOwner

#endif // !NDEBUG

//------------------------------------------------------------------------
#ifndef NDEBUG

inline
void t_thread_traits__multi::tag_guard::debug__CheckThreadIsNotOwner(DWORD const ThreadID)const
{
 assert(m_OwnerThreadID!=ThreadID);
}//debug__CheckThreadIsNotOwner

#endif // !NDEBUG

//------------------------------------------------------------------------
#ifndef NDEBUG

inline
void t_thread_traits__multi::tag_guard::debug__CheckCurrentThreadIsOwner()const
{
 assert(m_cntLock>0);
 assert(m_OwnerThreadID==::GetCurrentThreadId());
}//debug__CheckCurrentThreadIsOwner

#endif // !NDEBUG

//------------------------------------------------------------------------
#ifndef NDEBUG

inline
void t_thread_traits__multi::tag_guard::debug__CheckCurrentThreadIsNotOwner()const
{
 assert(m_OwnerThreadID!=::GetCurrentThreadId());
}//debug__CheckCurrentThreadIsNotOwner

#endif // !NDEBUG

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
