////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 29.09.2020.
#ifndef _cpp_public_lcpi_lib_structure_mt__t_try_lock_guard_CC_
#define _cpp_public_lcpi_lib_structure_mt__t_try_lock_guard_CC_

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////
//class t_try_lock_guard

template<class TGuard>
t_try_lock_guard<TGuard>::t_try_lock_guard(guard_type& x)
 :m_pGuard(nullptr)
{
 if(x.try_lock())
  m_pGuard=&x;
}//t_try_lock_guard

//------------------------------------------------------------------------
template<class TGuard>
t_try_lock_guard<TGuard>::~t_try_lock_guard()
{
 if(m_pGuard)
  m_pGuard->unlock();
}//~t_try_lock_guard

//------------------------------------------------------------------------
template<class TGuard>
bool t_try_lock_guard<TGuard>::owns_lock()const
{
 return m_pGuard!=nullptr;
}//owns_lock

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
