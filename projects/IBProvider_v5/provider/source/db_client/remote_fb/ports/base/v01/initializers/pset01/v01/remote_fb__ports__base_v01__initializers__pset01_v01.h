////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__ports__base_v01
//! \file    remote_fb__ports__base_v01__initializers__pset01_v01.h
//! \brief   Утилиты для настройки порта подключения (P10, P11, P12)
//! \author  Kovalenko Dmitry
//! \date    29.08.2016
#ifndef _remote_fb__ports__base_v01__initializers__pset01_v01_H_
#define _remote_fb__ports__base_v01__initializers__pset01_v01_H_

#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01__forward.h"
#include "source/db_client/remote_fb/remote_fb__client_connect_block_v1.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace base_v01{namespace initializers{namespace pset01{namespace v01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__ports__base_v01
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortInitializer_PSET01_v01

/// <summary>
///  Утилиты для настройки порта подключения (P10, P11, P12)
/// </summary>
class RemoteFB__PortInitializer_PSET01_v01
{
 private:
  using self_type=RemoteFB__PortInitializer_PSET01_v01;

 public: //typedefs ------------------------------------------------------
  using port_type=RemoteFB__Port_BASE_v01;

  using wstr_box_type=lib::structure::t_const_wstr_box;

 public:
  /// <summary>
  ///  Попытка подключения базы данных
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] ucs2_database_name
  //! \param[in] pDsPropValues
  //!  Параметры подключения к базе данных. Not null.
  //! \return
  //!  Null, если сервер отверг подключение
  static bool TryConnectToDatabase
               (port_type*                                           pPort,
                wstr_box_type                                        ucs2_database_name,
                oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues);

  /// <summary>
  ///  Попытка создания и подключения базы данных
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] ucs2_database_name
  //! \param[in] pDsPropValues
  //!  Параметры создания и подключения к базе данных. Not null.
  //! \return
  //!  Null, если сервер отверг подключение
  static bool TryCreateDatabase
               (port_type*                                           pPort,
                wstr_box_type                                        ucs2_database_name,
                oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues);

 private:
  struct tag_connect_finalizator LCPI_CPP_CFG__CLASS__FINAL
  {
   public:
    using init_pfunc_type
     =void (*)
       (RemoteFB__Port*                        pPort,
        wstr_box_type                          ucs2_database_name,
        RemoteFB__ClientConnectBlock_v1&       clientConnectBlock);

   public:
    init_pfunc_type P10;
    init_pfunc_type P11;
    init_pfunc_type P12;
  };//struct tag_connect_finalizator

 private:
  /// <summary>
  ///  Контейнер с номерами версий протокола.
  /// </summary>
  //! \note
  //!  У нас три версии: 10, 11, 12
  //!  Дублирование не допускается.
  using pversions_type
   =lib::structure::t_fix_vector<protocol::P_PROTOCOL_VERSION,3>;

  /// <summary>
  ///  Контейнер с идентификаторами архитектур протокола.
  /// </summary>
  //! \note
  //!  У нас только две поддерживаемые архитектуры: generic и symmetric.
  //!  Дублирование не допускается.
  using parchs_type
   =structure::t_fix_vector<protocol::P_ARCH,2>;

 private:
  static bool Helper__TryConnect
               (port_type*                                           pPort,
                wstr_box_type                                        ucs2_database_name,
                oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
                const tag_connect_finalizator&                       FinalOpFuncs);

 private:
  /// <summary>
  ///  Установка плагина аутентификации. THROW.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  //! \param[in]     authPluginName
  //!  Имя плагина аутентификации
  //!
  //! В случае неизвестного имени плагина аутентификации будет сгенерировано исключение.
  static void Helper__TryConnect__SetAuthPlugin
               (RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                const wstr_box_type              authPluginName);

  static void Helper__TryConnect__SetAuthPlugin__Win_Sspi
               (RemoteFB__ClientConnectBlock_v1& clientConnectBlock);

  static void Helper__TryConnect__SetAuthPlugin__Legacy_Auth
               (RemoteFB__ClientConnectBlock_v1& clientConnectBlock);

  /// <summary>
  ///  Регистрация плагинов аутентификации по-умолчанию. THROW.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  //! \return
  //!  Not null.
  //!
  //!  Если не удалось определить способ аутентификации,
  //!  то будет сгенерировано исключение.
  static void Helper__TryConnect__RegDefaultAuthPlugin
               (RemoteFB__ClientConnectBlock_v1& clientConnectBlock);

 private:
  static void Helper__TryConnect__GetProtocolArchitectures
               (const oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
                parchs_type&                                               parchs);

 private:
  using expected_ptype_descr_type
   =RemoteFB__ClientConnectBlock_v1::expected_ptype_descr_type;

  using expected_ptype_descr_type_N
   =RemoteFB__ClientConnectBlock_v1::expected_ptype_descr_type_N;

  static void Helper__TryConnect__GetProtocolType__P10_P11_P12
               (const oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
                expected_ptype_descr_type_N*                               pExpectedProtocolType,
                protocol::P_USHORT*                                        pMinProtocolType,
                protocol::P_USHORT*                                        pMaxProtocolType);

 private:
  /// <summary>
  ///  Финализатор подключения по 10-му протоколу
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] packet
  //!  Пакет с подтверждением подключения
  //! \param[in] ucs2_database_name
  //! \param[in] clientConnectBlock
  //!  Блок с данными подключения к базе данных
  //! \param[in] FinalOpFuncs
  static void Helper__FinishConnect_P10
               (port_type*                         pPort,
                const protocol::set01::PACKET_V01& packet,
                wstr_box_type                      ucs2_database_name,
                RemoteFB__ClientConnectBlock_v1&   clientConnectBlock,
                const tag_connect_finalizator&     FinalOpFuncs);

  /// <summary>
  ///  Финализатор подключения по 11-му протоколу
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] packet
  //!  Пакет с подтверждением подключения
  //! \param[in] ucs2_database_name
  //! \param[in] clientConnectBlock
  //!  Блок с данными подключения к базе данных
  //! \param[in] FinalOpFuncs
  static void Helper__FinishConnect_P11
               (port_type*                         pPort,
                const protocol::set01::PACKET_V01& packet,
                wstr_box_type                      ucs2_database_name,
                RemoteFB__ClientConnectBlock_v1&   clientConnectBlock,
                const tag_connect_finalizator&     FinalOpFuncs);

  /// <summary>
  ///  Финализатор подключения по 12-му протоколу
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] packet
  //!  Пакет с подтверждением подключения
  //! \param[in] ucs2_database_name
  //! \param[in] clientConnectBlock
  //!  Блок с данными подключения к базе данных
  //! \param[in] FinalOpFuncs
  static void Helper__FinishConnect_P12
               (port_type*                         pPort,
                const protocol::set01::PACKET_V01& packet,
                wstr_box_type                      ucs2_database_name,
                RemoteFB__ClientConnectBlock_v1&   clientConnectBlock,
                const tag_connect_finalizator&     FinalOpFuncs);

 private:
  /// <summary>
  ///  Сохраняем данные о протоколе установленного подключения
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] clientConnectBlock
  //! \param[in] acpt
  //! \param[in] pPacketStream
  //!  Поток пакетов установленного соединения. Not NULL.
  static void Helper__Initialize__SetProtocolInfo_P10_P11_P12
        (port_type*                             pPort,
         const RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
         const protocol::set01::P_OP_ACPT&      acpt,
         transmission::RemoteFB__PacketStream*  pPacketStream);

 private:
  /// Набор функций для завершения создания базы данных
  static const tag_connect_finalizator sm_finalizator_for_create;

  /// Набор функций для завершения подключения базы данных
  static const tag_connect_finalizator sm_finalizator_for_attach;
};//class RemoteFB__PortInitializer_PSET01_v01

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms v01*/}/*nms pset01*/}/*nms initializers*/}/*nms base_v01*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
