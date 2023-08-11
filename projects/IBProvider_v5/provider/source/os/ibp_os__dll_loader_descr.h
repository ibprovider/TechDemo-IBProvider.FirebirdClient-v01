////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os
//! \file    ibp_os__dll_loader_descr.h
//! \brief   The descriptor with DLL Loader data
//! \author  Kovalenko Dmitry
//! \date    18.09.2022
#ifndef _ibp_os__dll_loader_descr_H_
#define _ibp_os__dll_loader_descr_H_

#include "source/os/ibp_os__dll_loader.h"

#include <structure/tree/t_tree_avl.h>

namespace lcpi{namespace ibp{namespace os{
////////////////////////////////////////////////////////////////////////////////
//containing

class t_ibp_os__dll_loader_descr_less_operator;
class t_ibp_os__dll_loader_descr;

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os__dll_loader_descr_less_operator

class t_ibp_os__dll_loader_descr_less_operator LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  bool operator () (const t_ibp_os__dll* const p1,
                    const t_ibp_os__dll* const p2)const;

  bool operator () (const t_ibp_os__dll_loader_descr& d1,
                    const t_ibp_os__dll*        const p2)const;

  bool operator () (const t_ibp_os__dll*        const p1,
                    const t_ibp_os__dll_loader_descr& d2)const;

  bool operator () (const t_ibp_os__dll_loader_descr& d1,
                    const t_ibp_os__dll_loader_descr& d2)const;
};//class t_ibp_os__dll_loader_descr_less_operator

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os__dll_loader_descr

class t_ibp_os__dll_loader_descr LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_ibp_os__dll_loader_descr;

  t_ibp_os__dll_loader_descr(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using children_type
   =structure::t_tree_avl
      <t_ibp_os__dll_loader::self_ptr,
       t_ibp_os__dll_loader_descr_less_operator,
       IBP_MemoryAllocator>;

 public:
  children_type m_children;

  explicit t_ibp_os__dll_loader_descr(t_ibp_os__dll_loader::self_ptr&& spLoader)
   :m_spDllLoader(__STL_MOVE_VALUE(spLoader))
   ,m_LockUntilUnload(false)
  {
   assert(m_spDllLoader);
  }

  //interface ------------------------------------------------------------
  bool IsLockUntilUnload()const
  {
   return m_LockUntilUnload;
  }//IsLockUntilUnload

  //----------------------------------------------------------------------
  void SetLockUntilUnload()
  {
   m_LockUntilUnload=true;
  }//SetLockUntilUnload

  //----------------------------------------------------------------------
  t_ibp_os__dll_loader* GetDllLoader()const
  {
   assert(m_spDllLoader);

   return m_spDllLoader;
  }//GetDllLoader

 private:
  t_ibp_os__dll_loader::self_ptr m_spDllLoader;

  bool m_LockUntilUnload;
};//class t_ibp_os__dll_loader_descr

////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
