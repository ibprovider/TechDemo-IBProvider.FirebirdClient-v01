////////////////////////////////////////////////////////////////////////////////
//Library for thread's configurations
//                                               Dmitry Kovalenko. 07.09.2019
#ifndef _t_thread_traits__single_H_
#define _t_thread_traits__single_H_

#include <lcpi/lib/.config.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

class t_thread_traits__single;

////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__single

class t_thread_traits__single
{
 private: //lock classes -------------------------------------------------
  class tag_guard;
  class tag_lock_guard;

 public: //typedefs ------------------------------------------------------
  typedef long                         int_type;
  typedef tag_guard                    guard_type;
  typedef tag_lock_guard               lock_guard_type;

 public: //---------------------------------------------------------------
  static void add(volatile int_type* const x,int_type const a);

  static int_type increment(volatile int_type* const x);

  static int_type decrement(volatile int_type* const x);

  static int_type exchange(volatile int_type* const target,int_type const value);
};//t_thread_traits__single

////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__single::tag_guard

class t_thread_traits__single::tag_guard
{
 private:
  typedef tag_guard                            self_type;

  tag_guard(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef tag_lock_guard                       lock_type;

 public:
  tag_guard(){;}

  //guard interface ------------------------------------------------------
  void lock()   {;}
  void unlock() {;}
};//class t_thread_traits__single::tag_guard

////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__single::tag_lock_guard

class t_thread_traits__single::tag_lock_guard
{
 private:
  typedef tag_lock_guard                            self_type;

  tag_lock_guard(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef t_thread_traits__single::guard_type        guard_type;

 public:
  tag_lock_guard(guard_type& /*x*/)
   {;}

  void unlock()
   {;}
};//class t_thread_traits__single

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_thread_traits__single.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
