////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32_winsock__provider.cpp
//! \brief   Провайдер Windows Socket API
//! \author  Kovalenko Dmitry
//! \date    10.11.2014
#include <_pch_.h>
#pragma hdrstop

#include "source/os/win32/winsock/ibp_os_win32_winsock__provider.h"
#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{namespace os{namespace win32{namespace winsock{
////////////////////////////////////////////////////////////////////////////////
//class t_winsock__provider

#define INIT_WINSOCK_POINT(func_name)  \
 m_##func_name(pDLL,#func_name)

t_winsock__provider::t_winsock__provider(dll_type* const pDLL)
 :INIT_WINSOCK_POINT(WSAStartup)
 ,INIT_WINSOCK_POINT(WSACleanup)
 ,INIT_WINSOCK_POINT(WSAGetLastError)
 ,INIT_WINSOCK_POINT(WSAAddressToStringA)
 ,INIT_WINSOCK_POINT(socket)
 ,INIT_WINSOCK_POINT(closesocket)
 ,INIT_WINSOCK_POINT(setsockopt)
 ,INIT_WINSOCK_POINT(connect)
 ,INIT_WINSOCK_POINT(send)
 ,INIT_WINSOCK_POINT(recv)
 ,INIT_WINSOCK_POINT(ntohs)
 ,INIT_WINSOCK_POINT(ntohl)
 ,INIT_WINSOCK_POINT(htons)
 ,INIT_WINSOCK_POINT(htonl)
 ,INIT_WINSOCK_POINT(freeaddrinfo)
 ,INIT_WINSOCK_POINT(getaddrinfo)
 ,m_spDLL(lib::structure::not_null_ptr(pDLL))
{
 assert(m_spDLL);

 this->m_WSAStartup.point(); //throw
 this->m_WSACleanup.point(); //throw

 //-----------------------------------------
 API::WinSock__WSAData wsadata={};

 const WORD version = MAKEWORD(2, 0);

 const int wsaError = m_WSAStartup.point()(version, &wsadata); //throw?

 if(wsaError!=0)
 {
  //ERROR - WSAStartup failed;

  IBP_ErrorUtils::Throw__ErrorWithCustomErrorObject
   (E_FAIL,
    ibp_mce_winsock__failed_to_initialize_1,
    IBP_CreateCustomErrorFor_CnFailed(),
    wsaError);
 }//if
}//t_winsock__provider

#undef INIT_WINSOCK_POINT

//------------------------------------------------------------------------
t_winsock__provider::~t_winsock__provider()
{
 assert(m_WSACleanup.test_point());

 DEBUG_CODE(const int wsaError=)m_WSACleanup.point()(); //throw?

 //! \todo
 //!  Добавить вывод WSAGetLastError

 assert(wsaError!=API::WinSock__SOCKET_ERROR);
}//~t_winsock__provider

//------------------------------------------------------------------------
t_winsock__provider::self_ptr
 t_winsock__provider::create(dll_type* const pDLL)
{
 assert(pDLL);

 return lib::structure::not_null_ptr(new self_type(pDLL));
}//create

//------------------------------------------------------------------------
bool t_winsock__provider::address_to_string(size_t                        const cbAddr,
                                            const API::WinSock__sockaddr* const pAddr,
                                            std::string*                  const pStr)
{
 assert(pStr);

 if(!m_WSAAddressToStringA.test_point())
  return false;

 if(!cbAddr || !structure::can_numeric_cast<DWORD>(cbAddr))
  return false;

 if(!pAddr)
  return false;

 CHECK_READ_PTR(pAddr,cbAddr);

 char  tmpBuf[256];
 DWORD tmpBufSize=_DIM_(tmpBuf);

 const int c=m_WSAAddressToStringA.point()
                (const_cast<winsock::API::WinSock__sockaddr*>(pAddr),
                 static_cast<DWORD>(cbAddr),
                 /*lpProtocolInfo*/nullptr,
                 tmpBuf,
                 &tmpBufSize);

 if(c==0)
 {
  //Manual:
  // lpdwAddressStringLength [in, out] (tmpBufSize)
  //       On output, this parameter returns the length of the string
  //       including the NULL terminator actually copied into the buffer
  //       pointed to by the lpszAddressString parameter.

  assert(tmpBufSize<=_DIM_(tmpBuf));

  assert(tmpBufSize>0);

  if(tmpBufSize==0)
   return false;

  if(tmpBufSize>_DIM_(tmpBuf))
   return false;

  pStr->assign(tmpBuf,tmpBufSize-1);

  return true;
 }//if c==0

 assert(c==winsock::API::WinSock__SOCKET_ERROR);

 //! \todo
 //!  Можно добавить обработку ошибки WSAEFAULT и выделить буфер требуемой длины.

 return false;
}//address_to_string

////////////////////////////////////////////////////////////////////////////////
}/*nms winsock*/}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
