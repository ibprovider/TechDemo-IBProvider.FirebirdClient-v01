////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32_auth__api.h
//! \brief   Описание Windows Authentication API
//! \author  Kovalenko Dmitry
//! \date    25.11.2014
#ifndef _ibp_os_win32_auth__api_H_
#define _ibp_os_win32_auth__api_H_

#define SECURITY_WIN32

#include <security.h>

namespace lcpi{namespace ibp{namespace os{namespace win32{namespace auth{namespace API{
////////////////////////////////////////////////////////////////////////////////
//typedefs

typedef SECURITY_STATUS                     AUTH__SECURITY_STATUS;

typedef CredHandle                          AUTH__CredHandle;
typedef PCredHandle                         AUTH__PCredHandle;

typedef CtxtHandle                          AUTH__CtxtHandle;

typedef TimeStamp                           AUTH__TimeStamp;

typedef SecBuffer                           AUTH__SecBuffer;

typedef SecBufferDesc                       AUTH__SecBufferDesc;

////////////////////////////////////////////////////////////////////////////////
//Function prototypes

typedef ACQUIRE_CREDENTIALS_HANDLE_FN
 AUTH__pfn__AcquireCredentialsHandle;

typedef DELETE_SECURITY_CONTEXT_FN
 AUTH__pfn__DeleteSecurityContext;

typedef FREE_CREDENTIALS_HANDLE_FN
 AUTH__pfn__FreeCredentialsHandle;

typedef QUERY_CONTEXT_ATTRIBUTES_FN
 AUTH__pfn__QueryContextAttributes;

typedef FREE_CONTEXT_BUFFER_FN
 AUTH__pfn__FreeContextBuffer;

typedef INITIALIZE_SECURITY_CONTEXT_FN
 AUTH__pfn__InitializeSecurityContext;

typedef ACCEPT_SECURITY_CONTEXT_FN
 AUTH__pfn__AcceptSecurityContext;

////////////////////////////////////////////////////////////////////////////////
}/*nms API*/}/*nms auth*/}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
