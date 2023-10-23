////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__inet
//! \file    remote_fb__ports__factories__inet.h
//! \brief   Фабрика класса удаленного порта для работы через TCP/IP.
//! \author  Kovalenko Dmitry
//! \date    29.08.2016
#ifndef _remote_fb__ports__factories__inet_H_
#define _remote_fb__ports__factories__inet_H_

#include "source/db_client/remote_fb/ports/streams/inet/remote_fb__ports__streams__inet__socket.h"
#include "source/db_client/remote_fb/ports/remote_fb__port.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__data__values.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace factories{namespace inet{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__inet
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortFactory__INET

/// <summary>
///  Вспомогательный класс для конструирования удаленного порта для работы через TCP/IP.
/// </summary>
class RemoteFB__PortFactory__INET LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__PortFactory__INET;

 public: //typedefs ------------------------------------------------------
  using wstr_box_type=lib::structure::t_const_wstr_box;

 public:
  /// <summary>
  ///  Распознавание строки подключения "host_name:database_path"
  /// </summary>
  //! \param[in]  ucs2DbLocation
  //! \param[out] pUcs2HostName
  //!  Not null.
  //! \param[out] pUcs2PortName
  //!  Not null.
  //! \param[out] pUcs2DatabaseName
  //!  Not null.
  //! \return
  //!  true, если распознанно подключение по TCP/IP
  //!
  //! \attention
  //!  Неподдерживается однобуквенное имя хоста
  static bool Analyze_v2(wstr_box_type ucs2DbLocation,
                         std::wstring* pUcs2HostName,
                         std::wstring* pUcs2PortName,
                         std::wstring* pUcs2DatabaseName);

  /// <summary>
  ///  Распознавание строки подключения с (нестандартным) форматом "inet://сетевой_путь"
  /// </summary>
  //! \param[in]  ucs2DbLocation
  //! \param[out] pUcs2HostName
  //!  Not null.
  //! \param[out] pUcs2PortName
  //!  Not null.
  //! \param[out] pUcs2DatabaseName
  //!  Not null.
  //! \return
  //!  true, если распознанно подключение по TCP/IP
  //!
  //! В случае ошибки формата будет генерироваться исключение.
  static bool Analyze_v3(wstr_box_type ucs2DbLocation,
                         std::wstring* pUcs2HostName,
                         std::wstring* pUcs2PortName,
                         std::wstring* pUcs2DatabaseName);

  /// <summary>
  ///  Распознавание строки подключения с (нестандартным) форматом "inet4://сетевой_путь"
  /// </summary>
  //! \param[in]  ucs2DbLocation
  //! \param[out] pUcs2HostName
  //!  Not null.
  //! \param[out] pUcs2PortName
  //!  Not null.
  //! \param[out] pUcs2DatabaseName
  //!  Not null.
  //! \return
  //!  true, если распознанно подключение по TCP/IP
  //!
  //! В случае ошибки формата будет генерироваться исключение.
  static bool Analyze_v3__inet4
                        (wstr_box_type ucs2DbLocation,
                         std::wstring* pUcs2HostName,
                         std::wstring* pUcs2PortName,
                         std::wstring* pUcs2DatabaseName);

  /// <summary>
  ///  Распознавание строки подключения с (нестандартным) форматом "inet6://сетевой_путь"
  /// </summary>
  //! \param[in]  ucs2DbLocation
  //! \param[out] pUcs2HostName
  //!  Not null.
  //! \param[out] pUcs2PortName
  //!  Not null.
  //! \param[out] pUcs2DatabaseName
  //!  Not null.
  //! \return
  //!  true, если распознанно подключение по TCP/IP
  //!
  //! В случае ошибки формата будет генерироваться исключение.
  static bool Analyze_v3__inet6
                        (wstr_box_type ucs2DbLocation,
                         std::wstring* pUcs2HostName,
                         std::wstring* pUcs2PortName,
                         std::wstring* pUcs2DatabaseName);
 public:
  /// <summary>
  ///  Создание подключения к базе данных.
  /// </summary>
  //! \param[in] socketFamily
  //! \param[in] ucs2_host
  //!  Not null.
  //! \param[in] ucs2_port
  //! \param[in] ucs2_database_name
  //!  Not null, not empty
  //! \param[in] pDsPropValues
  //!  Параметры подключения к базе данных. Not null.
  //! \return
  //!  Порт подключения
  static RemoteFB__PortPtr
          ConnectToDatabase
           (int                                                  socketFamily,
            wstr_box_type                                        ucs2_host,
            wstr_box_type                                        ucs2_port,
            wstr_box_type                                        ucs2_database_name,
            oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues);

 public:
  /// <summary>
  ///  Создание базы данных и подключение к ней.
  /// </summary>
  //! \param[in] socketFamily
  //! \param[in] ucs2_host
  //!  Not null.
  //! \param[in] ucs2_port
  //! \param[in] ucs2_database_name
  //!  Not null, not empty
  //! \param[in] pDsPropValues
  //!  Параметры создания и подключения к базе данных. Not null.
  //! \return
  //!  Порт подключения
  static RemoteFB__PortPtr
          CreateDatabase
           (int                                                  socketFamily,
            wstr_box_type                                        ucs2_host,
            wstr_box_type                                        ucs2_port,
            wstr_box_type                                        ucs2_database_name,
            oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues);

 private:
  struct tag_init_funcs;

  static RemoteFB__PortPtr
          Helper__CreateAndInitPort
           (const tag_init_funcs&                                InitFuncs,
            int                                                  socketFamily,
            wstr_box_type                                        ucs2_host,
            wstr_box_type                                        ucs2_port,
            wstr_box_type                                        ucs2_database_name,
            oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues);

 private:
  static bool Helper__Analyze_v3(wstr_box_type ucs2DbLocationPrefix,
                                 wstr_box_type ucs2DbLocation,
                                 std::wstring* pUcs2HostName,
                                 std::wstring* pUcs2PortName,
                                 std::wstring* pUcs2DatabaseName);

  static bool Helper__IsSpace(wchar_t ch);

  static wstr_box_type::iterator Helper__SkeepSpace(wstr_box_type::iterator i,
                                                    wstr_box_type::iterator e);
 private:
  static ports::streams::inet::RemoteFB__INET_Socket::self_ptr
   Helper__CreateSocket(int           const socketFamily,
                        wstr_box_type const ucs2_host,
                        wstr_box_type const ucs2_port);

 private:
  COMP_CONF_DECLSPEC_NORETURN
  static void Helper__ThrowErr__IncorrectFormatOfStringWithDbLocation();

  COMP_CONF_DECLSPEC_NORETURN
  static void Helper__ThrowErr__IncorrectFormatOfStringWithDbLocation__NoPort(wstr_box_type hostName);

 private:
  /// Указатели на функции для создания базы данных
  static const tag_init_funcs sm_init_funcs_for_create_db;

  /// Указатели на функции для подключения базы данных
  static const tag_init_funcs sm_init_funcs_for_connect_db;

 private:
  static const wstr_box_type::char_type sm_inet_prefix[];
  static const wstr_box_type::char_type sm_inet4_prefix[];
  static const wstr_box_type::char_type sm_inet6_prefix[];
};//class RemoteFB__PortFactory__INET

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms inet*/}/*nms factories*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
