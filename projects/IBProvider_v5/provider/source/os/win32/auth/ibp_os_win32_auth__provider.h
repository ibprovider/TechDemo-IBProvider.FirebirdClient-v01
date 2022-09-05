////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32_auth__provider.h
//! \brief   Провайдер Windows Authentication API
//! \author  Kovalenko Dmitry
//! \date    25.11.2014
#ifndef _ibp_os_win32_auth__provider_H_
#define _ibp_os_win32_auth__provider_H_

#include "source/os/win32/auth/ibp_os_win32_auth__api.h"
#include "source/os/win32/ibp_os_win32__dll_entry_point.h"
//#include "source/ibp_memory.h"

namespace lcpi{namespace ibp{namespace os{namespace win32{namespace auth{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_os_win32
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_auth__provider

#define DEF_AUTH_POINT(func_name)                                         \
 t_ibp_os_win32__dll_entry_point<API::AUTH__pfn__##func_name> m_##func_name

/// <summary>
///  Провайдер Windows Socket API
/// </summary>
class t_auth__provider:public IBP_SmartMemoryObject
{
 private:
  typedef t_auth__provider                          self_type;

  t_auth__provider(const self_type&);
  self_type& operator = (const self_type);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>  self_ptr;

  typedef t_ibp_os__dll                             dll_type;
  typedef t_ibp_os__dll_ptr                         dll_ptr;

 private:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] pDLL
  //!  Not null.
  t_auth__provider(dll_type* pDLL);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~t_auth__provider();

 public:
  DEF_AUTH_POINT(AcquireCredentialsHandle);
  DEF_AUTH_POINT(DeleteSecurityContext);
  DEF_AUTH_POINT(FreeCredentialsHandle);
  //DEF_AUTH_POINT(QueryContextAttributes);
  //DEF_AUTH_POINT(FreeContextBuffer);
  DEF_AUTH_POINT(InitializeSecurityContext);
  //DEF_AUTH_POINT(AcceptSecurityContext);

 public:
  /// <summary>
  ///  Фабрика класса.
  /// </summary>
  //! \param[in] pDLL
  //!  Not null.
  static self_ptr create(dll_type* pDLL);

  //interface ------------------------------------------------------------
  API::AUTH__PCredHandle GetCredHandle()
  {
   return &m_hCred;
  }//GetCredHandle

 private:
  /// Указатель на загрузчик DLL
  dll_ptr const m_spDLL;

 private:
  API::AUTH__CredHandle  m_hCred;
  API::AUTH__TimeStamp   m_timeOut;
};//class t_auth__provider

#undef DEF_AUTH_POINT

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms auth*/}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
