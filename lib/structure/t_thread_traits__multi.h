////////////////////////////////////////////////////////////////////////////////
//Library for thread's configurations
//                                               Dmitry Kovalenko. 07.09.2019
#ifndef _t_thread_traits__multi_H_
#define _t_thread_traits__multi_H_

#include <lcpi/lib/.config.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

class t_thread_traits__multi;

////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__multi

class t_thread_traits__multi LCPI_CPP_CFG__CLASS__FINAL
{
 private: //lock classes -------------------------------------------------
  class tag_guard;
  class tag_lock_guard;

 public: //typedefs ------------------------------------------------------
  using int_type=long;

  using guard_type=tag_guard;

  using lock_guard_type=tag_lock_guard;

 public: //---------------------------------------------------------------
  static void add(volatile int_type* const x,int_type a);

  static int_type increment(volatile int_type* const x);

  static int_type decrement(volatile int_type* const x);

  template<typename T1,typename T2>
  static T1 exchange(volatile T1* const target,T2 const value);

 private:
  class tag_exchange__enum;

  class tag_exchange__std;
};//class t_thread_traits__multi

////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__multi::tag_guard

class t_thread_traits__multi::tag_guard LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_guard;

  tag_guard(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  using lock_type=tag_lock_guard;

 public:
  tag_guard();

 ~tag_guard();

  //guard interface ------------------------------------------------------
  void lock();

  void unlock();

 #ifndef NDEBUG
  void debug__CheckThreadIsOwner(DWORD ThreadID)const;

  void debug__CheckThreadIsNotOwner(DWORD ThreadID)const;

  void debug__CheckCurrentThreadIsOwner()const;

  void debug__CheckCurrentThreadIsNotOwner()const;
 #endif

 private:
  CRITICAL_SECTION m_cs;

 private:
 #ifndef NDEBUG
  LONG m_cntLock;

  DWORD m_OwnerThreadID;
 #endif
};//class t_thread_traits__multi::tag_guard

////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__multi::tag_lock_guard

class t_thread_traits__multi::tag_lock_guard LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_lock_guard;

  tag_lock_guard(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  using guard_type=t_thread_traits__multi::guard_type;

 public:
  tag_lock_guard(guard_type& x)
   :m_guard(&x)
  {
   m_guard->lock();
  }

 ~tag_lock_guard()
  {
   this->unlock();
  }

  void unlock()
  {
   if(this->m_guard)
   {
    m_guard->unlock();

    m_guard=NULL;
   }
  }//unlock

 private:
  guard_type* m_guard;
};//class t_thread_traits__multi

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_thread_traits__multi.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
