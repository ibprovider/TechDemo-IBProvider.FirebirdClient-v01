////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os
//! \file    ibp_os__dlls.h
//! \brief   Manager of DLLs.
//! \author  Kovalenko Dmitry
//! \date    01.09.2022
#ifndef _ibp_os__dlls_H_
#define _ibp_os__dlls_H_

#include "source/os/ibp_os__dll_loader.h"

#include <structure/tree/t_tree_avl.h>

namespace lcpi{namespace ibp{namespace os{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os__dlls

class t_ibp_os__dlls COMP_W000006_CLASS_FINAL
 :public IBP_SmartMemoryObject
{
 private:
  typedef t_ibp_os__dlls                              self_type;

  t_ibp_os__dlls(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~t_ibp_os__dlls();

 public:
  typedef structure::t_smart_object_ptr<self_type>    self_ptr;

 public:
  t_ibp_os__dlls();

  //interface ------------------------------------------------------------

  /// <summary>
  ///  Getting an object, which services an enternal DLL. THROW.
  /// </summary>
  //! \param[in] DLL_Name
  //!  Path to DLL
  //! \param[in] DLL_Lock_Rule
  //!  Rules of DLL-locking in memory.
  //!
  //! <seealso cref="ibp::t_ibp_propval_dll_lock_rule"/>
  t_ibp_os__dll_ptr GetDLL(t_ibp_str_box DLL_Name,
                           long          DLL_Lock_Rule);

  /// <summary>
  ///  Releasing of a DLL loader.
  /// </summary>
  //! \param[in,out] pspDllLoader
  //!  The valid pointer to smart-pointer to a DLL loader.
  //!
  //!  (*pspDllLoader) will be released.
  void ReleaseDLL(t_ibp_os__dll_loader::self_ptr* pspDllLoader);

 private:
  typedef structure::t_multi_thread_traits         thread_traits;

  typedef thread_traits::guard_type                guard_type;
  typedef thread_traits::lock_guard_type           lock_guard_type;

  typedef structure::t_tree_avl
           <t_ibp_os__dll_descr,
            t_ibp_os__dll_less_operator,
            IBP_MemoryAllocator>                   items_type;

 private:
  guard_type m_guard;
  items_type m_items;
};//class t_ibp_os__dlls

////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
