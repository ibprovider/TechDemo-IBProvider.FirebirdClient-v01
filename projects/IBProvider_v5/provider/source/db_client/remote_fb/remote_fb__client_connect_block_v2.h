////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__client_connect_block_v2.h
//! \brief   ����� ��� ���������� ������� �����������.
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

#include <structure/stl/t_stl_set.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ClientConnectBlock_v2

/// <summary>
///  ����� ��� ���������� ������� �����������
/// </summary>
class RemoteFB__ClientConnectBlock_v2
{
 private:
  typedef RemoteFB__ClientConnectBlock_v2       self_type;

  RemoteFB__ClientConnectBlock_v2(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef RemoteFB__MemoryAllocator            allocator_type;

  typedef structure::t_void_simple_buffer
           <allocator_type>                    data_buffer_type;

 public:
  /// <summary>
  ///  �������� ���������� ���� ��������� �����������.
  /// </summary>
  struct tag_expected_ptype_descr
  {
   //! \note
   //!  ����������� � �������� ����������� ������������ ������������.

   public:
    typedef unsigned                                 ptype_id_type;
    typedef structure::t_value_with_null<unsigned>   ptype_id_type_N;

   public:
    /// ������������� ���������� ���� (����� ���� �� ���������).
    ptype_id_type_N  ptypeID;

    /// ��������� ���������� ����
    std::wstring     ptypeSign;

   public:
    tag_expected_ptype_descr();

    tag_expected_ptype_descr(ptype_id_type               _ptypeID,
                             structure::t_const_wstr_box _ptypeSign);

    explicit tag_expected_ptype_descr(structure::t_const_wstr_box _ptypeSign);

   ~tag_expected_ptype_descr();

    bool operator == (ptype_id_type id)const;

    bool operator != (ptype_id_type id)const;
  };//struct tag_expected_ptype_descr

  typedef tag_expected_ptype_descr             expected_ptype_descr_type;

  typedef structure::t_value_with_null
           <expected_ptype_descr_type>         expected_ptype_descr_type_N;

 private:
  typedef structure::t_smart_vector
            <RemoteFB__InternalCryptKey,
             RemoteFB__MemoryAllocator>        crypt_keys_type;

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
  /// �������� ���������� ���� ��������� ����������
  expected_ptype_descr_type_N m_expectedPTypeDescr;

 public:
  /// <summary>
  ///  ����������� �������������
  /// </summary>
  //! \param[in] pDsPropValues
  //!  Not null
  explicit RemoteFB__ClientConnectBlock_v2(oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues);

  /// <summary>
  ///  �����������
  /// </summary>
 ~RemoteFB__ClientConnectBlock_v2();

  //----------------------------------------------------------------------

  /// <summary>
  ///  ����������� ������� ������� ��������������
  /// </summary>
  //! \param[in] pFactory
  //!  Not null.
  //!
  //!  �� ����������� ����������� ������ �������� � ���������� ������.
  void RegAuthPluginFactory(plugins::auth::RemoteFB__Plugin_Auth_Factory* pFactory);

  /// <summary>
  ///  ��������� �������� ������� ��������������
  /// </summary>
  //! \param[in] pluginName
  //!  ��� �������.
  //!
  //!  � ������ ������������ ����� ����� ������������� ����������.
  bool SetCurrentAuthPlugin2(structure::t_const_wstr_box pluginName);

  /// <summary>
  ///  ��������� �������� ������� ��������������
  /// </summary>
  //! \return
  //!  Not null.
  //!
  //! \attention
  //!  ������ ������ ���� �������������� ���������� � ������� ������ SetCurrentAuthPlugin.
  const plugins::auth::RemoteFB__Plugin_AuthPtr& GetCurrentAuthPlugin()const;

  /// <summary>
  ///  ��������� ������ ��������� �������� ��������������.
  /// </summary>
  //! \return
  //!  ������ �� ������� ���� �������� ��������������.
  const std::wstring& GetAuthPluginNames();

 private:
  typedef structure::t_smart_vector
           <plugins::auth::RemoteFB__Plugin_Auth_Factory,
            allocator_type>                         auth_plugins_type;

 private:
  /// <summary>
  ///  ����� ������� ������� �������������� �� �����.
  /// </summary>
  //! \param[in] pluginName
  //! \return
  //!  NULL, ���� ��� �� ��������.
  plugins::auth::RemoteFB__Plugin_Auth_Factory*
   Helper__FindAuthPluginFactory(structure::t_const_wstr_box pluginName)const;

  /// <summary>
  ///  �������� ������������ ����� ������� ��������������
  /// </summary>
  //! \param[in] pluginName
  //! \return
  //!  false, ���� ��� ����������� (������ ��� �������� ������������ �������).
  static bool Helper__CheckAuthPluginName(structure::t_const_wstr_box pluginName);

 private:
  class tag_plugin_name_less
  {
   public:
    bool operator () (const structure::t_const_wstring& n1,
                      const structure::t_const_wstring& n2)const
    {
     return n1.compare(n2)<0;
    }
  };//class tag_plugin_name_less

 private:
  /// ������� ������ ��������������
  plugins::auth::RemoteFB__Plugin_AuthPtr
   m_spCurrentAuthPlugin;

  /// ������ ������ �������� ��������������
  auth_plugins_type
   m_AuthPlugins;

  /// <summary>
  ///  ������ � ���������� ������������������ �������� ��������������
  /// </summary>
  ///  ����������� �� ����������.
  structure::t_value_with_null<std::wstring>
   m_AuthPluginNames;

  /// ��������� ���� �������������� �������� ��������������
  structure::t_stl_set<structure::t_const_wstring,tag_plugin_name_less,allocator_type>
   m_UsedAuthPlugins;
};//class RemoteFB__ClientConnectBlock_v2

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
