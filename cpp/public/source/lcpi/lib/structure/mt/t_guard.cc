////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 29.09.2020.
#ifndef _cpp_public_lcpi_lib_structure_mt__t_guard_CC_
#define _cpp_public_lcpi_lib_structure_mt__t_guard_CC_

#include <lcpi/lib/structure/mt/interlocked.h>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////
//class t_guard

inline t_guard::t_guard()
{
#ifndef NDEBUG
 m_cntLock=0;

 m_OwnerThreadID=0;
#endif
}//t_guard

//------------------------------------------------------------------------
inline t_guard::~t_guard()
{
 LCPI__assert_msg(m_cntLock==0,"m_cntLock="<<m_cntLock<<". m_OwnerThreadID="<<m_OwnerThreadID);
 LCPI__assert_msg(m_OwnerThreadID==0,"m_OwnerThreadID="<<m_OwnerThreadID);
}//~t_guard

//guard interface --------------------------------------------------------
inline void t_guard::lock()
{
 m_cs.lock();

#ifndef NDEBUG
 if(m_cntLock==0)
 {
  LCPI__assert(m_OwnerThreadID==0);

  interlocked::exchange(&m_OwnerThreadID,self_type::debug__get_current_thread_id());
 }
 else
 {
  LCPI__assert(m_OwnerThreadID==self_type::debug__get_current_thread_id());
 }//else

 interlocked::increment(&m_cntLock);
#endif
}//lock

//------------------------------------------------------------------------
inline bool t_guard::try_lock()
{
 if(!m_cs.try_lock())
  return false;

#ifndef NDEBUG
 if(m_cntLock==0)
 {
  LCPI__assert(m_OwnerThreadID==0);

  interlocked::exchange(&m_OwnerThreadID,self_type::debug__get_current_thread_id());
 }
 else
 {
  LCPI__assert(m_OwnerThreadID==self_type::debug__get_current_thread_id());
 }//else

 interlocked::increment(&m_cntLock);
#endif

 return true;
}//try_lock

//------------------------------------------------------------------------
inline void t_guard::unlock()
{
 LCPI__assert(m_cntLock>0);
 LCPI__assert(m_OwnerThreadID==self_type::debug__get_current_thread_id());

#ifndef NDEBUG
 if(interlocked::decrement(&m_cntLock)==0)
  interlocked::exchange(&m_OwnerThreadID,thread_id_type(0));
#endif

 m_cs.unlock();
}//unlock

//------------------------------------------------------------------------
#ifndef NDEBUG

inline
void t_guard::debug__CheckIsUnlocked()const
{
 LCPI__assert_msg(m_cntLock==0,"m_cntLock="<<m_cntLock<<". m_OwnerThreadID="<<m_OwnerThreadID);
 LCPI__assert_msg(m_OwnerThreadID==0,"m_OwnerThreadID="<<m_OwnerThreadID);
}//debug__CheckIsUnlocked

#endif // !NDEBUG

//------------------------------------------------------------------------
#ifndef NDEBUG

inline
void t_guard::debug__CheckThreadIsOwner(thread_id_type const ThreadID)const
{
 LCPI__assert(m_cntLock>0);
 LCPI__assert(m_OwnerThreadID==ThreadID);
}//debug__CheckThreadIsOwner

#endif // !NDEBUG

//------------------------------------------------------------------------
#ifndef NDEBUG

inline
void t_guard::debug__CheckThreadIsNotOwner(thread_id_type const ThreadID)const
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
 LCPI__assert(m_OwnerThreadID==self_type::debug__get_current_thread_id());
}//debug__CheckCurrentThreadIsOwner

#endif // !NDEBUG

//------------------------------------------------------------------------
#ifndef NDEBUG

inline
void t_guard::debug__CheckCurrentThreadIsNotOwner()const
{
 LCPI__assert(m_OwnerThreadID!=self_type::debug__get_current_thread_id());
}//debug__CheckCurrentThreadIsNotOwner

#endif // !NDEBUG

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
