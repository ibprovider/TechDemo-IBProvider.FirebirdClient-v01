////////////////////////////////////////////////////////////////////////////////
//Library for thread's configurations
//                                               Dmitry Kovalenko. 07.09.2019
#ifndef _lcpi_lib_structure__t_thread_traits__multi_H_
#define _lcpi_lib_structure__t_thread_traits__multi_H_

#include <structure/mt/t_guard.h>
#include <structure/mt/t_lock_guard.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

class t_thread_traits__multi;

////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__multi

class t_thread_traits__multi LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  using guard_type=structure::t_guard;

  using lock_guard_type=structure::t_lock_guard<guard_type>;

 public: //---------------------------------------------------------------
  template<typename T1,typename T2>
  static void add(volatile T1* x,T2 a);

  template<typename T>
  static T increment(volatile T* x);

  template<typename T>
  static T decrement(volatile T* x);

  template<typename T1,typename T2>
  static T1 exchange(volatile T1* target,T2 value);
};//class t_thread_traits__multi

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_thread_traits__multi.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
