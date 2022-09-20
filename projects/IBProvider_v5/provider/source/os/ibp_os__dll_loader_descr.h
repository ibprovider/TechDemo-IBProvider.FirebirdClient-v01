////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os
//! \file    ibp_os__dll_loader_descr.h
//! \brief   The descriptor with DLL Loader data
//! \author  Kovalenko Dmitry
//! \date    18.09.2022
#ifndef _ibp_os__dll_loader_descr_H_
#define _ibp_os__dll_loader_descr_H_

#include "source/os/ibp_os__dll_loader.h"

namespace lcpi{namespace ibp{namespace os{
////////////////////////////////////////////////////////////////////////////////
//containing

class t_ibp_os__dll_loader_descr;
class t_ibp_os__dll_loader_descr_less_operator;

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os__dll_loader_descr

class t_ibp_os__dll_loader_descr LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  t_ibp_os__dll_loader_descr(t_ibp_os__dll_loader::self_ptr&& spLoader)
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
//class t_ibp_os__dll_loader_descr_less_operator

class t_ibp_os__dll_loader_descr_less_operator LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  bool operator () (const t_ibp_os__dll_loader* const p1,
                    const t_ibp_os__dll_loader* const p2)const
  {
   assert(p1);
   assert(p2);

   return p1->get_dll_handle()<p2->get_dll_handle();
  }//operator p1<p2

  //----------------------------------------------------------------------
  bool operator () (const t_ibp_os__dll_loader_descr& d1,
                    const t_ibp_os__dll_loader* const p2)const
  {
   assert(d1.GetDllLoader());
   assert(p2);

   return d1.GetDllLoader()->get_dll_handle()<p2->get_dll_handle();
  }//operator d1<p2

  //----------------------------------------------------------------------
  bool operator () (const t_ibp_os__dll_loader* const p1,
                    const t_ibp_os__dll_loader_descr& d2)const
  {
   assert(p1);
   assert(d2.GetDllLoader());

   return p1->get_dll_handle()<d2.GetDllLoader()->get_dll_handle();
  }//operator p1<d2

  //----------------------------------------------------------------------
  bool operator () (const t_ibp_os__dll_loader_descr& d1,
                    const t_ibp_os__dll_loader_descr& d2)const
  {
   assert(d1.GetDllLoader());
   assert(d2.GetDllLoader());

   return d1.GetDllLoader()->get_dll_handle()<d2.GetDllLoader()->get_dll_handle();
  }//operator d1<d2
};//class t_ibp_os__dll_loader_descr_less_operator

////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
