////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__client_connect_block_v2.h
//! \brief   Класс для управления данными подключения.
//! \author  Kovalenko Dmitry
//! \date    08.10.2016
#ifndef _remote_fb__client_connect_block_v2_H_
#define _remote_fb__client_connect_block_v2_H_

#include "source/db_client/remote_fb/plugins/auth/remote_fb__plugin_auth_factory.h"
#include "source/db_client/remote_fb/remote_fb__known_server_key_array.h"
#include "source/db_client/remote_fb/remote_fb__internal_crypt_key.h"
#include "source/db_obj/isc_base/isc_param_buffer_v1_builder.h" //CPB

#include "source/oledb/props2/values/datasource/ibp_oledb__props2__values__datasource.h"

#include <structure/t_value_with_null.h>

#include <lcpi/lib/structure/stl/t_stl_set.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ClientConnectBlock_v2

/// <summary>
///  Класс для управления данными подключения
/// </summary>
class RemoteFB__ClientConnectBlock_v2 LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__ClientConnectBlock_v2;

  RemoteFB__ClientConnectBlock_v2(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using allocator_type=RemoteFB__MemoryAllocator;

  using data_buffer_type
   =structure::t_void_simple_buffer<allocator_type>;

 public:
  /// <summary>
  ///  Описание ожидаемого типа протокола подключения.
  /// </summary>
  struct tag_expected_ptype_descr LCPI_CPP_CFG__CLASS__FINAL
  {
   //! \note
   //!  Конструктор и оператор копирования генерируются компилятором.

   public:
    using ptype_id_type   =unsigned;
    using ptype_id_type_N =structure::t_value_with_null<ptype_id_type>;

   public:
    /// Идентификатор ожидаемого типа (может быть не определен).
    ptype_id_type_N  ptypeID;

    /// Сигнатура ожидаемого типа
    std::wstring     ptypeSign;

   public:
    tag_expected_ptype_descr();

    tag_expected_ptype_descr
     (ptype_id_type                    _ptypeID,
      lib::structure::t_const_wstr_box _ptypeSign);

    explicit tag_expected_ptype_descr
     (lib::structure::t_const_wstr_box _ptypeSign);

   ~tag_expected_ptype_descr();

    bool operator == (ptype_id_type id)const;

    bool operator != (ptype_id_type id)const;
  };//struct tag_expected_ptype_descr

  using expected_ptype_descr_type=tag_expected_ptype_descr;

  using expected_ptype_descr_type_N
   =structure::t_value_with_null<expected_ptype_descr_type>;

 private:
  using crypt_keys_type
   =structure::t_smart_vector
     <RemoteFB__InternalCryptKey,
      RemoteFB__MemoryAllocator>;

 public: //---------------------------------------------------------------
  const oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE::self_ptr m_spDsPropValues;

  const ibp_ipropval__remote__wire_crypt m_DsProp__WireCrypt;

  const ibp_ipropval__remote__wire_compression m_DsProp__WireCompression;

 public:
  /// Initial connection parameter block
  isc_base::t_isc_param_buffer_v1_builder m_CPB;

 public:
  bool m_authComplete;

  data_buffer_type m_dataFromAuthPlugin;

  data_buffer_type m_dataForAuthPlugin;

  /// Server sends to client keys known by it, they are stored here
  RemoteFB__KnownServerKeyArray m_knownServerKeys;

  /// Wire crypt keys that came from plugin(s) last time
  crypt_keys_type m_cryptKeys;

 public:
  /// Описание ожидаемого типа протокола соединения
  expected_ptype_descr_type_N m_expectedPTypeDescr;

 public:
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] pDsPropValues
  //!  Not null
  explicit RemoteFB__ClientConnectBlock_v2(oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues);

  /// <summary>
  ///  Десктруктор
  /// </summary>
 ~RemoteFB__ClientConnectBlock_v2();

  //----------------------------------------------------------------------

  /// <summary>
  ///  Регистрация фабрики плагина аутентификации
  /// </summary>
  //! \param[in] pFactory
  //!  Not null.
  //!
  //!  Не допускается регистрация фабрик плагинов с идентичным именем.
  void RegAuthPluginFactory(plugins::auth::RemoteFB__Plugin_Auth_Factory* pFactory);

  /// <summary>
  ///  Установка текущего плагина аутентификации
  /// </summary>
  //! \param[in] pluginName
  //!  Имя плагина.
  //!
  //!  В случае неизвестного имени будет сгенерировано исключение.
  bool SetCurrentAuthPlugin2(structure::t_const_wstr_box pluginName);

  /// <summary>
  ///  Получение текущего плагина аутентификации
  /// </summary>
  //! \return
  //!  Not null.
  //!
  //! \attention
  //!  Плагин должен быть предварительно установлен с помощью метода SetCurrentAuthPlugin.
  const plugins::auth::RemoteFB__Plugin_AuthPtr& GetCurrentAuthPlugin()const;

  /// <summary>
  ///  Получение списка доступных плагинов аутентификации.
  /// </summary>
  //! \return
  //!  Строка со списком имен плагинов аутентификации.
  const std::wstring& GetAuthPluginNames();

 private:
  using auth_plugins_type
   =structure::t_smart_vector
     <plugins::auth::RemoteFB__Plugin_Auth_Factory,
      allocator_type>;

 private:
  /// <summary>
  ///  Поиск фабрики плагина аутентификации по имени.
  /// </summary>
  //! \param[in] pluginName
  //! \return
  //!  NULL, если имя не опознано.
  plugins::auth::RemoteFB__Plugin_Auth_Factory*
   Helper__FindAuthPluginFactory(structure::t_const_wstr_box pluginName)const;

  /// <summary>
  ///  Проверка корректности имени плагина аутентификации
  /// </summary>
  //! \param[in] pluginName
  //! \return
  //!  false, если имя некорректно (пустое или содержит недопустимые символы).
  static bool Helper__CheckAuthPluginName(structure::t_const_wstr_box pluginName);

 private:
  class tag_plugin_name_less LCPI_CPP_CFG__CLASS__FINAL
  {
   public:
    bool operator () (const lib::structure::t_const_wstring& n1,
                      const lib::structure::t_const_wstring& n2)const
    {
     return n1.compare(n2)<0;
    }
  };//class tag_plugin_name_less

 private:
  /// Текущий плагин аутентификации
  plugins::auth::RemoteFB__Plugin_AuthPtr
   m_spCurrentAuthPlugin;

  /// Список фабрик плагинов аутентификации
  auth_plugins_type
   m_AuthPlugins;

  /// <summary>
  ///  Строка с названиями зарегистрированных плагинов аутентификации
  /// </summary>
  ///  Формируется по требованию.
  structure::t_value_with_null<std::wstring>
   m_AuthPluginNames;

  /// Множество имен использованных плагинов аутентификации
  lib::structure::t_stl_set<lib::structure::t_const_wstring,tag_plugin_name_less,allocator_type>
   m_UsedAuthPlugins;
};//class RemoteFB__ClientConnectBlock_v2

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
