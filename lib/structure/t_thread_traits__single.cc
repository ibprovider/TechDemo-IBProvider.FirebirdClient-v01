////////////////////////////////////////////////////////////////////////////////
//Library for thread's configurations
//                                                 Dmitry Kovalenko. 07.09.2019.
#ifndef _t_thread_traits__single_CC_
#define _t_thread_traits__single_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__single

template<typename T1,typename T2>
inline void t_thread_traits__single::add(volatile T1* const x,T2 const a)
{
 assert(x!=nullptr);

 (*x)+=a;
}//add

//------------------------------------------------------------------------
template<typename T>
inline T t_thread_traits__single::increment(volatile T* const x)
{
 assert(x!=nullptr);

 return ++(*x);
}//increment

//------------------------------------------------------------------------
template<typename T>
inline T t_thread_traits__single::decrement(volatile T* const x)
{
 assert(x!=nullptr);

 return --(*x);
}//decrement

//------------------------------------------------------------------------
template<typename T1,typename T2>
inline T1 t_thread_traits__single::exchange(volatile T1* const target,T2 const value)
{
 assert(target!=nullptr);

 const T1 prev_value=*target;

 (*target)=value;

 return prev_value;
}//exchange

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
