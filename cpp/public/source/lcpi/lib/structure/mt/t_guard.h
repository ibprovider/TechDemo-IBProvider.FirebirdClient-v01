////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 29.09.2020.
#ifndef _cpp_public_lcpi_lib_structure_mt__t_guard_H_
#define _cpp_public_lcpi_lib_structure_mt__t_guard_H_

#include <lcpi/infrastructure/os/lcpi.infrastructure.os-critical_section.h>
#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////
//class t_guard

class t_guard LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_guard;

  t_guard(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
#ifndef NDEBUG
  using thread_id_type=DWORD;
#endif

 public:
  t_guard();

 ~t_guard();

  //guard interface ------------------------------------------------------
  void lock();

  bool try_lock();

  void unlock();

#ifndef NDEBUG
  void debug__CheckThreadIsOwner(thread_id_type ThreadID)const;

  void debug__CheckThreadIsNotOwner(thread_id_type ThreadID)const;

  void debug__CheckCurrentThreadIsOwner()const;

  void debug__CheckCurrentThreadIsNotOwner()const;
#endif

 private:
#ifndef NDEBUG
 static thread_id_type debug__get_current_thread_id()
 {
  return ::GetCurrentThreadId();
 }
#endif

 private:
  infrastructure::os::LCPI_OS__CriticalSection m_cs;

 private:
#ifndef NDEBUG
  unsigned m_cntLock;

  thread_id_type m_OwnerThreadID;
#endif
};//class t_guard

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/mt/t_guard.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
