////////////////////////////////////////////////////////////////////////////////
//Library for thread's configurations
//                                                 Dmitry Kovalenko. 07.09.2019.
#ifndef _t_thread_traits__single_CC_
#define _t_thread_traits__single_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__single

inline void t_thread_traits__single::add(volatile int_type* const x,int_type const a)
{
 (*x)+=a;
}//add

//------------------------------------------------------------------------
inline t_thread_traits__single::int_type t_thread_traits__single::increment(volatile int_type* const x)
{
 return ++(*x);
}//increment

//------------------------------------------------------------------------
inline t_thread_traits__single::int_type t_thread_traits__single::decrement(volatile int_type* const x)
{
 return --(*x);
}//decrement

//------------------------------------------------------------------------
inline t_thread_traits__single::int_type t_thread_traits__single::exchange(volatile int_type* const target,int_type const value)
{
 const int_type prev_value=*target;

 (*target)=value;

 return prev_value;
}//exchange

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
