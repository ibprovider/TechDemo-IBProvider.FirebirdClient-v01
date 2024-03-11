////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__dll_init_mutex.h
//! \brief   The mutex for DLL initialization.
//! \author  Kovalenko Dmitry
//! \date    31.08.2022
#ifndef _ibp_os_win32__dll_init_mutex_H_
#define _ibp_os_win32__dll_init_mutex_H_

#include "source/ibp_memory.h"

#include <structure/t_closure.h>

namespace lcpi{namespace ibp{namespace os{namespace win32{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_os_win32
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os_win32__dll_init_mutex

class t_ibp_os_win32__dll_init_mutex LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_SmartMemoryObject
{
 private:
  using self_type=t_ibp_os_win32__dll_init_mutex;

  t_ibp_os_win32__dll_init_mutex(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  virtual ~t_ibp_os_win32__dll_init_mutex();

 public: //typedefs ------------------------------------------------------
  using self_ptr
   =lib::structure::t_smart_object_ptr<self_type>;

  using op_func_type
   =structure::t_closure_r0<void>;

 public:
  t_ibp_os_win32__dll_init_mutex();

  void do_initialize(op_func_type op_func);

  void do_uninitialize(op_func_type op_func);

 private:
  typedef structure::t_multi_thread_traits                 thread_traits;
  typedef thread_traits::guard_type                        guard_type;
  typedef thread_traits::lock_guard_type                   lock_guard_type;

 private:
  guard_type m_InitGuard;

  unsigned __int64 m_cInits;
};//class t_ibp_os_win32__dll_init_mutex

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
