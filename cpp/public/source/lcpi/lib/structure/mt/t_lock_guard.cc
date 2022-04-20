////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 29.09.2020.
#ifndef _cpp_public_lcpi_lib_structure_mt__t_lock_guard_CC_
#define _cpp_public_lcpi_lib_structure_mt__t_lock_guard_CC_

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////
//class t_lock_guard

template<class TGuard>
t_lock_guard<TGuard>::t_lock_guard(guard_type& x)
 :m_guard(x)
{
 m_guard.lock();
}//t_lock_guard

//------------------------------------------------------------------------
template<class TGuard>
t_lock_guard<TGuard>::~t_lock_guard()
{
 m_guard.unlock();
}//~t_lock_guard

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
