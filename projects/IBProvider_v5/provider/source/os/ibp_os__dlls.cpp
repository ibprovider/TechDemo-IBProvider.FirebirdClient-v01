////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os
//! \file    ibp_os__dlls.h
//! \brief   Manager of DLLs.
//! \author  Kovalenko Dmitry
//! \date    01.09.2022
#include <_pch_.h>
#pragma hdrstop

#include "source/os/ibp_os__dlls.h"
#include "source/os/ibp_os__dll_proxy.h"

namespace lcpi{namespace ibp{namespace os{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os__dlls

t_ibp_os__dlls::t_ibp_os__dlls()
{
}

//------------------------------------------------------------------------
t_ibp_os__dlls::~t_ibp_os__dlls()
{
#ifndef NDEBUG

 //
 // The check of DLLs which were stayed in the global cache.
 //
 // They must be locked.
 //
 for(items_type::const_iterator x=m_items.cbegin(),_e=m_items.cend();x!=_e;++x)
 {
  assert((*x).GetDllLoader());
  assert((*x).GetDllLoader()->get_cntRef()==1);

  if((*x).IsLockUntilUnload())
   continue;

  if((*x).GetDllLoader()->is_locked_in_memory())
   continue;

  assert(false);
 }//for x

#endif
}//~t_ibp_os__dlls

//interface --------------------------------------------------------------
t_ibp_os__dll_ptr t_ibp_os__dlls::GetDLL(t_ibp_str_box const DLL_Name,
                                         long          const DLL_Lock_Rule)
{
 t_ibp_os__dll_loader::self_ptr
  spDLL
   (structure::not_null_ptr
     (new t_ibp_os__dll_loader
       (DLL_Name))); //throw

 const lock_guard_type __lock(m_guard);

 auto x=m_items.insert(__STL_MOVE_VALUE(spDLL));

 assert((*x.first).GetDllLoader());

 spDLL=structure::not_null_ptr((*x.first).GetDllLoader());

 assert(spDLL);

 if(DLL_Lock_Rule==ibprovider::ibp_propval_dll_lock_rule__unload)
 {
  (*x.first).SetLockUntilUnload();

  assert((*x.first).IsLockUntilUnload());

  return spDLL;
 }//if

 if(DLL_Lock_Rule==ibprovider::ibp_propval_dll_lock_rule__no_unload)
 {
  spDLL->lock_in_memory();

  return spDLL;
 }//if

 //DEFAULT: Force unload

 t_ibp_os__dll_ptr
  spDllProxy
   =structure::not_null_ptr
     (new t_ibp_os__dll_proxy
       (this,
        __STL_MOVE_VALUE(spDLL)));

 assert(spDllProxy);

 return spDllProxy;
}//GetDLL

//------------------------------------------------------------------------
void t_ibp_os__dlls::ReleaseDLL(t_ibp_os__dll_loader::self_ptr* const pspDllLoader)
{
 assert(pspDllLoader);
 assert(*pspDllLoader);

 const lock_guard_type __lock(m_guard);

 auto x=m_items.find(pspDllLoader->ptr());

 assert(x!=m_items.end());
 assert((*x).GetDllLoader());

 // It's the same pointer!
 assert((*x).GetDllLoader()==pspDllLoader->ptr());
 assert((*x).GetDllLoader()->get_cntRef()>=2);

 pspDllLoader->Release();

 assert(!(*pspDllLoader));

 assert((*x).GetDllLoader()->get_cntRef()>=1);

 //if(x==m_items.end())
 //{
 // return;
 //}

 if((*x).GetDllLoader()->get_cntRef()>1)
 {
  //DLL has external users. It will be saved in cache.

  return;
 }//if

 if((*x).GetDllLoader()->is_locked_in_memory())
 {
  //DLL was disabled for unload from memory. It will be saved in cache.

  return;
 }//if

 if((*x).IsLockUntilUnload())
 {
  //DLL is holded until our unload. It will be saved in cache.

  return;
 }//if

 //It need to unload DLL from memory.

 m_items.erase(x);

 return;
}//ReleaseDLL

////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
