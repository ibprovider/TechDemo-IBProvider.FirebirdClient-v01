////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os
//! \file    ibp_os__dll.h
//! \brief   The interface of a dynamic library (DLL) loader.
//! \author  Kovalenko Dmitry
//! \date    30.08.2022
#ifndef _ibp_os__dll_H_
#define _ibp_os__dll_H_

#include "source/ibp_memory.h"

namespace lcpi{namespace ibp{namespace os{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os__dll

class COMP_CONF_DECLSPEC_NOVTABLE t_ibp_os__dll:public IBP_SmartInterface
{
 public:
  using pfn_service_obj_creator
   =IBP_SmartObjectPtr (*)();

 public:
  /// <summary>
  ///  Getting a handle of DLL
  /// </summary>
  virtual HINSTANCE get_dll_handle()const=0;

  /// <summary>
  ///  Getting a pointer to the enter into DLL. THROW
  /// </summary>
  //! \param[in] point_name
  virtual FARPROC get_proc_address(LPCSTR point_name)const=0;//throw

  /// <summary>
  ///  Trying to get a pointer to enter into DLL.
  /// </summary>
  //! \param[in] point_name
  virtual FARPROC try_get_proc_address(LPCSTR point_name)const=0;

  /// <summary>
  ///  Getting a DLL service object. THROW.
  /// </summary>
  //! \param[in] rServiceObjID
  //! \param[in] pfnServiceObjCreator
  //!  Pointer to the creator of a service object.
  //! \return
  //!  Not NULL.
  virtual IBP_SmartObjectPtr get_service_obj(REFGUID                 rServiceObjID,
                                             pfn_service_obj_creator pfnServiceObjCreator)=0;
};//class t_ibp_os__dll

////////////////////////////////////////////////////////////////////////////////

using t_ibp_os__dll_ptr
 =structure::t_smart_object_ptr<t_ibp_os__dll>;

////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
