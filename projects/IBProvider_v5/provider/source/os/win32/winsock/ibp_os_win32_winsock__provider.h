////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32_winsock__provider.h
//! \brief   Провайдер Windows Socket API
//! \author  Kovalenko Dmitry
//! \date    10.11.2014
#ifndef _ibp_os_win32_winsock__provider_H_
#define _ibp_os_win32_winsock__provider_H_

#include "source/os/win32/winsock/ibp_os_win32_winsock__api.h"
#include "source/os/win32/ibp_os_win32__dll_entry_point.h"
#include "source/ibp_memory.h"

namespace lcpi{namespace ibp{namespace os{namespace win32{namespace winsock{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_os_win32
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_winsock__provider

#define DEF_WINSOCK_POINT(func_name)                                          \
 t_ibp_os_win32__dll_entry_point<API::WinSock__fn__##func_name*> m_##func_name

/// <summary>
///  Провайдер Windows Socket API
/// </summary>
class t_winsock__provider:public IBP_SmartMemoryObject
{
 private:
  typedef t_winsock__provider                            self_type;

  t_winsock__provider(const self_type&);
  self_type& operator = (const self_type);

 public: //typedefs ------------------------------------------------------
  typedef lib::structure::t_smart_object_ptr<self_type>  self_ptr;

  typedef t_ibp_os__dll                                  dll_type;
  typedef t_ibp_os__dll_ptr                              dll_ptr;

 private:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] pDLL
  //!  Not null.
  t_winsock__provider(dll_type* pDLL);

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~t_winsock__provider();

 public:
  DEF_WINSOCK_POINT(WSAStartup);
  DEF_WINSOCK_POINT(WSACleanup);
  DEF_WINSOCK_POINT(WSAGetLastError);
  DEF_WINSOCK_POINT(WSAAddressToStringA);
  DEF_WINSOCK_POINT(socket);
  DEF_WINSOCK_POINT(closesocket);
  DEF_WINSOCK_POINT(setsockopt);
  DEF_WINSOCK_POINT(connect);
  DEF_WINSOCK_POINT(send);
  DEF_WINSOCK_POINT(recv);
  DEF_WINSOCK_POINT(ntohs);
  DEF_WINSOCK_POINT(ntohl);
  DEF_WINSOCK_POINT(htons);
  DEF_WINSOCK_POINT(htonl);
  DEF_WINSOCK_POINT(freeaddrinfo);
  DEF_WINSOCK_POINT(getaddrinfo);

 public:
  /// <summary>
  ///  Фабрика класса.
  /// </summary>
  //! \param[in] pDLL
  //!  Not null.
  static self_ptr create(dll_type* pDLL);

  //interface ------------------------------------------------------------
  
  /// <summary>
  ///  Преобразование сетевого адреса в строку
  /// </summary>
  //! \param[in] cbAddr
  //! \param[in] pAddr
  //! \param[in] pStr
  bool address_to_string(size_t                        cbAddr,
                         const API::WinSock__sockaddr* pAddr,
                         std::string*                  pStr);

 private:
  /// Указатель на загрузчик DLL
  dll_ptr const m_spDLL;
};//class t_winsock__provider

#undef DEF_WINSOCK_POINT

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms winsock*/}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
