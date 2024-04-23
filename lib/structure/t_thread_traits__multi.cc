////////////////////////////////////////////////////////////////////////////////
//Library for thread's configurations
//                                                 Dmitry Kovalenko. 07.09.2019
#ifndef _lcpi_lib_structure__t_thread_traits__multi_CC_
#define _lcpi_lib_structure__t_thread_traits__multi_CC_

#include <structure/mt/interlocked.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_thread_traits__multi

template<typename T1,typename T2>
inline void t_thread_traits__multi::add(volatile T1* const x,T2 a)
{
 assert(x!=nullptr);

 interlocked::add(x,a);
}//add

//------------------------------------------------------------------------
template<typename T>
inline T t_thread_traits__multi::increment(volatile T* const x)
{
 assert(x!=nullptr);

 return interlocked::increment(x);
}//increment

//------------------------------------------------------------------------
template<typename T>
inline T t_thread_traits__multi::decrement(volatile T* const x)
{
 assert(x!=nullptr);

 return interlocked::decrement(x);
}//decrement

//------------------------------------------------------------------------
template<typename T1,typename T2>
inline T1 t_thread_traits__multi::exchange(volatile T1* const target,T2 const value)
{
 assert(target!=nullptr);

 return interlocked::exchange(target,value);
}//exchange

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
