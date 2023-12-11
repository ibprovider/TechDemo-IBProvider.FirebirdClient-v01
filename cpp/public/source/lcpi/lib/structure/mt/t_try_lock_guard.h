////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 29.09.2020.
#ifndef _cpp_public_lcpi_lib_structure_mt__t_try_lock_guard_H_
#define _cpp_public_lcpi_lib_structure_mt__t_try_lock_guard_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////
//class t_try_lock_guard

template<class TGuard>
class t_try_lock_guard LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_try_lock_guard<TGuard>;

  t_try_lock_guard(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using guard_type=TGuard;

 public:
  explicit t_try_lock_guard(guard_type& guard);

 ~t_try_lock_guard();

  //interface ------------------------------------------------------------
  bool owns_lock()const;

 private:
  guard_type* m_pGuard;
};//class t_try_lock_guard

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/mt/t_try_lock_guard.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
