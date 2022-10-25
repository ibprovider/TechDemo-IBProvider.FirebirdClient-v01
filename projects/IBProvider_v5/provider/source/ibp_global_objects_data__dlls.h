////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_global_objects_data__dlls.h
//! \brief   Работа с глобальными данными. DLLs.
//! \author  Kovalenko Dmitry
//! \date    24.01.2019
#ifndef _ibp_global_objects_data__dlls_H_
#define _ibp_global_objects_data__dlls_H_

#include "source/os/ibp_os__dll_loader.h"

#if defined(IBP_BUILD_TESTCODE) && !defined(NDEBUG)
#include <structure/debug/t_debug__mt_guard_rw.h>
#endif

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class IBP_GlobalObjectsData__DLLs

class IBP_GlobalObjectsData__DLLs LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef IBP_GlobalObjectsData__DLLs       self_type;

 public: //typedefs ------------------------------------------------------
#ifdef IBP_BUILD_TESTCODE
  class tagTestInitializer;
#endif // IBP_BUILD_TESTCODE

 public:
  /// <summary>
  ///  Getting an object, which services an external DLL. THROW.
  /// </summary>
  //! \param[in] DLL_Name
  //!  Path to DLL
  //! \param[in] DLL_Lock_Rule
  //!  Rules of DLL-locking in memory.
  //!
  //! <seealso cref="ibp::t_ibp_propval_dll_lock_rule"/>
  static os::t_ibp_os__dll_ptr GetDLL(t_ibp_str_box DLL_Name,
                                      long          DLL_Lock_Rule);

  /// <summary>
  ///  Releasing of a DLL loader.
  /// </summary>
  //! \param[in,out] pspDllLoader
  //!  The valid pointer to smart-pointer to a DLL loader.
  //!
  //!  (*pspDllLoader) will be released.
  static void ReleaseDLL(os::t_ibp_os__dll_loader::self_ptr* pspDllLoader);

 private:
#ifdef IBP_BUILD_TESTCODE
  class tagTestData;

  static void TEST_CODE__Initialize();

  static void TEST_CODE__Deinitialize();

 private:
#ifndef NDEBUG
  static structure::t_debug__mt_guard_rw sm_TEST_CODE__GUARD_RW;
#endif
#endif
};//class IBP_GlobalObjectsData__DLLs

////////////////////////////////////////////////////////////////////////////////
//class IBP_GlobalObjectsData__DLLs::tagTestInitializer

#ifdef IBP_BUILD_TESTCODE

class IBP_GlobalObjectsData__DLLs::tagTestInitializer COMP_W000006_CLASS_FINAL
{
 private:
  typedef tagTestInitializer                          self_type;

  tagTestInitializer(const self_type&);
  self_type& operator = (const self_type&);

 public:
  tagTestInitializer()
  {
   TEST_CODE__Initialize();
  }//tagTestInitializer

  //----------------------------------------------------------------------
 ~tagTestInitializer()
  {
   TEST_CODE__Deinitialize();
  }//~tagTestInitializer
};//class IBP_GlobalObjectsData__DLLs::tagTestInitializer

#endif //IBP_BUILD_TESTCODE

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif