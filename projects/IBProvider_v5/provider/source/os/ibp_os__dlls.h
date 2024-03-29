////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os
//! \file    ibp_os__dlls.h
//! \brief   Manager of DLLs.
//! \author  Kovalenko Dmitry
//! \date    01.09.2022
#ifndef _ibp_os__dlls_H_
#define _ibp_os__dlls_H_

#include "source/os/ibp_os__dll_loader_descr.h"

namespace lcpi{namespace ibp{namespace os{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os__dlls

class t_ibp_os__dlls LCPI_CPP_CFG__CLASS__FINAL
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
  ///  Getting an object, which services an external DLL. THROW.
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

  /// <summary>
  ///  Definition an unloading order.
  /// </summary>
  //! \param[in] pFirst
  //!  The first unloaded DLL.
  //! \param[in] pSecond
  //!  The second unloaded DLL.
  void DefUnloadOrder(t_ibp_os__dll* pFirst,t_ibp_os__dll* pSecond);

 private:
  using guard_type
   =lib::structure::mt::t_guard;

  using lock_guard_type
   =lib::structure::mt::t_lock_guard<guard_type>;

  using items_type
   =structure::t_tree_avl
     <t_ibp_os__dll_loader_descr,
      t_ibp_os__dll_loader_descr_less_operator,
      IBP_MemoryAllocator>;

 private:
  void Helper__ReleaseDLL(os::t_ibp_os__dll_loader::self_ptr* pspDllLoader);

 private:
  guard_type m_guard;
  items_type m_items;
};//class t_ibp_os__dlls

////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
