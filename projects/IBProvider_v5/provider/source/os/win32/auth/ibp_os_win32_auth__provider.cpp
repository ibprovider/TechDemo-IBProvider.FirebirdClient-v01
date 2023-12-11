////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32_auth__provider.cpp
//! \brief   ѕровайдер Windows Authentication API
//! \author  Kovalenko Dmitry
//! \date    25.11.2014
#include <_pch_.h>
#pragma hdrstop

#include "source/os/win32/auth/ibp_os_win32_auth__provider.h"
#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{namespace os{namespace win32{namespace auth{
////////////////////////////////////////////////////////////////////////////////
//class t_auth__provider

//макрос нужен дл€ правильного преобразовани€ имени функции, которое тоже может
//быть представлено макросом, в строку.
#define BUILD_TEXT(x) #x

#define INIT_AUTH_POINT(func_name)  \
 m_##func_name(pDLL,BUILD_TEXT(func_name))

//------------------------------------------------------------------------
t_auth__provider::t_auth__provider(dll_type* const pDLL)
 :INIT_AUTH_POINT(AcquireCredentialsHandle)
 ,INIT_AUTH_POINT(DeleteSecurityContext)
 ,INIT_AUTH_POINT(FreeCredentialsHandle)
 //,INIT_AUTH_POINT(QueryContextAttributes)
 //,INIT_AUTH_POINT(FreeContextBuffer)
 ,INIT_AUTH_POINT(InitializeSecurityContext)
 //,INIT_AUTH_POINT(AcceptSecurityContext)
 ,m_spDLL(lib::structure::not_null_ptr(pDLL))
 ,m_hCred()
 ,m_timeOut()
{
 assert(m_spDLL);

 m_AcquireCredentialsHandle.point(); //throw
 m_FreeCredentialsHandle.point(); //throw

 const API::AUTH__SECURITY_STATUS
  authErr
   =m_AcquireCredentialsHandle.point()
     (/*pszPrincipal*/nullptr,
      /*pszPackage*/const_cast<TCHAR*>(_T("NTLM")),
      /*fCredentialUse*/SECPKG_CRED_BOTH,
      /*pvLogonId*/nullptr,
      /*pAuthData*/nullptr,
      /*pGetKeyFn*/nullptr,
      /*pvGetKeyArgument*/nullptr,
      /*phCredential*/&m_hCred,
      /*ptsExpiry*/&m_timeOut);

 if(authErr!=SEC_E_OK)
 {
  //ERROR - ошибка инициализации AUTH

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_win32__auth__fail_func_call_2,
    m_AcquireCredentialsHandle.point_name(),
    authErr);
 }//if
}//t_auth__provider

#undef INIT_AUTH_POINT
#undef BUILD_TEXT

//------------------------------------------------------------------------
t_auth__provider::~t_auth__provider()
{
 assert(m_FreeCredentialsHandle.test_point());

 DEBUG_CODE(API::AUTH__SECURITY_STATUS const authErr=)
  m_FreeCredentialsHandle.point()(&m_hCred); //throw?

 assert_msg(authErr==SEC_E_OK,"authErr="<<authErr);
}//~t_auth__provider

//------------------------------------------------------------------------
t_auth__provider::self_ptr
 t_auth__provider::create(dll_type* const pDLL)
{
 assert(pDLL);

 return lib::structure::not_null_ptr(new self_type(pDLL));
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms auth*/}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/