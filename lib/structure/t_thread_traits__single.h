////////////////////////////////////////////////////////////////////////////////
//Library for thread's configurations
//                                               Dmitry Kovalenko. 07.09.2019
#ifndef __lcpi_lib_structure__t_thread_traits__single_H_
#define __lcpi_lib_structure__t_thread_traits__single_H_

#include <lcpi/lib/.config.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

class t_thread_traits__single;

////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__single

class t_thread_traits__single LCPI_CPP_CFG__CLASS__FINAL
{
 private: //lock classes -------------------------------------------------
  class tag_guard;
  class tag_lock_guard;

 public: //typedefs ------------------------------------------------------
  using guard_type=tag_guard;

  using lock_guard_type=tag_lock_guard;

 public: //---------------------------------------------------------------
  template<typename T1,typename T2>
  static void add(volatile T1*  x,T2 a);

  template<typename T>
  static T increment(volatile T* x);

  template<typename T>
  static T decrement(volatile T* x);

  template<typename T1,typename T2>
  static T1 exchange(volatile T1* target,T2 value);
};//t_thread_traits__single

////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__single::tag_guard

class t_thread_traits__single::tag_guard LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_guard;

  tag_guard(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  using lock_type=tag_lock_guard;

 public:
  tag_guard(){;}

  //guard interface ------------------------------------------------------
  void lock()   {;}
  void unlock() {;}
};//class t_thread_traits__single::tag_guard

////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__single::tag_lock_guard

class t_thread_traits__single::tag_lock_guard LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_lock_guard;

  tag_lock_guard(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  using guard_type=t_thread_traits__single::guard_type;

 public:
  tag_lock_guard(guard_type& /*x*/)
  {
  }

  void unlock()
  {
  }
};//class t_thread_traits__single

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_thread_traits__single.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
