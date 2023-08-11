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
 try // suppresses exceptions
 {
  while(!m_items.empty())
  {
   const auto c=m_items.size();

   for(auto x=m_items.begin(),_e=m_items.end();x!=_e;++x)
   {
    assert((*x).GetDllLoader());

    if((*x).GetDllLoader()->get_cntRef()>1)
     continue;

    t_ibp_os__dll_loader_descr::children_type children;

    std::swap((*x).m_children,children); //no throw

    assert((*x).m_children.empty());

    m_items.erase(x);

    for(auto& child:children)
     this->Helper__ReleaseDLL(&child); //no throw

    break; //restart
   }//for x

   // [2023-06-29] No cycles!
   assert(m_items.size()<c);

   // This guard will prevent an infinite cycle
   if(c==m_items.size())
    break;
  }//while !m_items.empty()

  //
  // [2023-06-27] Expected
  //
  assert(m_items.empty());
 }
 catch(...)
 {
  assert(false);
 }//catch
}//~t_ibp_os__dlls

//interface --------------------------------------------------------------
t_ibp_os__dll_ptr t_ibp_os__dlls::GetDLL(t_ibp_str_box const DLL_Name,
                                         long          const DLL_Lock_Rule)
{
 const lock_guard_type __lock(m_guard);

 t_ibp_os__dll_loader::self_ptr
  spDLL
   (structure::not_null_ptr
     (new t_ibp_os__dll_loader
       (DLL_Name))); //throw

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

 return this->Helper__ReleaseDLL(pspDllLoader);
}//ReleaseDLL

//------------------------------------------------------------------------
void t_ibp_os__dlls::DefUnloadOrder(t_ibp_os__dll* const pFirst,
                                    t_ibp_os__dll* const pSecond)
{
 assert(pFirst);
 assert(pSecond);

 const lock_guard_type __lock(m_guard);

 const auto x1=m_items.find(pFirst);

 assert(x1!=m_items.end());

 const auto x2=m_items.find(pSecond);

 assert(x2!=m_items.end());

 if(x1==x2)
 {
  // [2023-06-26] I don't have an idea about this situation.
  assert(false);

  return;
 }//if

 assert(x1!=x2);

 assert((*x1).GetDllLoader());
 assert((*x2).GetDllLoader());

 (*x1).m_children.insert((*x2).GetDllLoader()); //throw
}//DefUnloadOrder

//------------------------------------------------------------------------
void t_ibp_os__dlls::Helper__ReleaseDLL(t_ibp_os__dll_loader::self_ptr* const pspDllLoader)
{
 assert(pspDllLoader);
 assert(*pspDllLoader);

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

 t_ibp_os__dll_loader_descr::children_type children;

 std::swap((*x).m_children,children);

 assert((*x).m_children.empty());

 m_items.erase(x);

 for(auto& c:children)
 {
  this->Helper__ReleaseDLL(&c);
 }//for c

 return;
}//Helper__ReleaseDLL

////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
