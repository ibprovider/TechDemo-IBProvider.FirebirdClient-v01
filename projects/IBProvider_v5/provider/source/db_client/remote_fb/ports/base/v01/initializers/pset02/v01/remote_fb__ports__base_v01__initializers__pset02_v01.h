////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__ports__base_v01
//! \file    remote_fb__ports__base_v01__initializers__pset02_v01.h
//! \brief   ������� ��� ��������� ����� ����������� (P13)
//! \author  Kovalenko Dmitry
//! \date    31.08.2016
#ifndef _remote_fb__ports__base_v01__initializers__pset02_v01_H_
#define _remote_fb__ports__base_v01__initializers__pset02_v01_H_

#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02__forward.h"
#include "source/db_client/remote_fb/remote_fb__client_connect_block_v2.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace base_v01{namespace initializers{namespace pset02{namespace v01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__ports__base_v01
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortInitializer_PSET02_v01

/// <summary>
///  ������� ��� ��������� ����� ����������� (P13)
/// </summary>
class RemoteFB__PortInitializer_PSET02_v01
{
 private:
  typedef RemoteFB__PortInitializer_PSET02_v01  self_type;

 public: //typedefs ------------------------------------------------------
  typedef RemoteFB__Port_BASE_v01               port_type;

  typedef structure::t_const_wstr_box           wstr_box_type;

 public:
  /// <summary>
  ///  ������� ����������� ���� ������
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] ucs2_database_name
  //! \param[in] pDsPropValues
  //!  ��������� ����������� � ���� ������. Not null.
  //! \return
  //!  Null, ���� ������ ������ �����������
  static bool TryConnectToDatabase
               (port_type*                                           pPort,
                wstr_box_type                                        ucs2_database_name,
                oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues);

  /// <summary>
  ///  ������� �������� � ����������� ���� ������
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] ucs2_database_name
  //! \param[in] pDsPropValues
  //!  ��������� �������� � ����������� � ���� ������. Not null.
  //! \return
  //!  Null, ���� ������ ������ �����������
  static bool TryCreateDatabase
               (port_type*                                           pPort,
                wstr_box_type                                        ucs2_database_name,
                oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues);

 private:
  struct tag_connect_finalizator
  {
   public:
    typedef void (*init_p13_func_type)
      (port_type*                       pPort,
       wstr_box_type                    ucs2_database_name,
       RemoteFB__ClientConnectBlock_v2& clientConnectBlock);

   public:
    init_p13_func_type P13;
  };//struct tag_connect_finalizator

 private:
  /// <summary>
  ///  ��������� � �������� ������ ���������.
  /// </summary>
  //! \note
  //!  � ��� ���� ������: 13
  //!  ������������ �� �����������.
  typedef structure::t_fix_vector<1,protocol::P_PROTOCOL_VERSION> pversions_type;

  /// <summary>
  ///  ��������� � ���������������� ���������� ���������.
  /// </summary>
  //! \note
  //!  � ��� ������ ��� �������������� �����������: generic � symmetric.
  //!  ������������ �� �����������.
  typedef structure::t_fix_vector<2,protocol::P_ARCH> parchs_type;

 private:
  static bool Helper__TryConnect
               (port_type*                                           pPort,
                wstr_box_type                                        ucs2_database_name,
                oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
                const tag_connect_finalizator&                       FinalOpFuncs);

 private:
  /// <summary>
  ///  ��������� ������� ��������������. THROW.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  //! \param[in]     authPluginName
  //!  ��� ������� ��������������
  //!
  //! � ������ ������������ ����� ������� �������������� ����� ������������� ����������.
  static void Helper__TryConnect__SetAuthPlugin
               (RemoteFB__ClientConnectBlock_v2& clientConnectBlock,
                const wstr_box_type              authPluginName);

  static void Helper__TryConnect__SetAuthPlugin__Win_Sspi
               (RemoteFB__ClientConnectBlock_v2& clientConnectBlock);

  static void Helper__TryConnect__SetAuthPlugin__Srp
               (RemoteFB__ClientConnectBlock_v2& clientConnectBlock);

  static void Helper__TryConnect__SetAuthPlugin__Srp224
               (RemoteFB__ClientConnectBlock_v2& clientConnectBlock);

  static void Helper__TryConnect__SetAuthPlugin__Srp256
               (RemoteFB__ClientConnectBlock_v2& clientConnectBlock);

  static void Helper__TryConnect__SetAuthPlugin__Srp384
               (RemoteFB__ClientConnectBlock_v2& clientConnectBlock);

  static void Helper__TryConnect__SetAuthPlugin__Srp512
               (RemoteFB__ClientConnectBlock_v2& clientConnectBlock);

  static void Helper__TryConnect__SetAuthPlugin__Legacy_Auth
               (RemoteFB__ClientConnectBlock_v2& clientConnectBlock);

  /// <summary>
  ///  ����������� �������� �������������� ��-���������. THROW.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  //! \return
  //!  Not null.
  //!
  //!  ���� �� ������� ���������� ������ ��������������,
  //!  �� ����� ������������� ����������.
  static void Helper__TryConnect__RegDefaultAuthPlugin
               (RemoteFB__ClientConnectBlock_v2& clientConnectBlock);

 private:
  static void Helper__TryConnect__GetProtocolArchitectures
               (const oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
                parchs_type&                                               parchs);

 private:
  typedef RemoteFB__ClientConnectBlock_v2::expected_ptype_descr_type   expected_ptype_descr_type;
  typedef RemoteFB__ClientConnectBlock_v2::expected_ptype_descr_type_N expected_ptype_descr_type_N;

  static void Helper__TryConnect__GetProtocolType
               (const oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* pDsPropValues,
                expected_ptype_descr_type_N*                               pExpectedProtocolType,
                protocol::P_USHORT*                                        pMinProtocolType,
                protocol::P_USHORT*                                        pMaxProtocolType);

 private:
  /// <summary>
  ///  ������������ ����������� ����������� �� 13-�� ���������
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] acceptPacket
  //!  ����� � �������������� �����������. ������ ���� �� ����������.
  //! \param[in] ucs2_database_name
  //! \param[in] clientConnectBlock
  //!  ���� � ������� ����������� � ���� ������
  //! \param[in] FinalOpFuncs
  static void Helper__FinishConnect_P13__cond_accept
               (port_type*                         pPort,
                const protocol::set02::PACKET_V02& acceptPacket,
                wstr_box_type                      ucs2_database_name,
                RemoteFB__ClientConnectBlock_v2&   clientConnectBlock,
                const tag_connect_finalizator&     FinalOpFuncs);

  /// <summary>
  ///  ����������� ����������� ����������� �� 13-�� ���������
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] acceptPacket
  //!  ����� � �������������� �����������. ������ ���� �� ����������.
  //! \param[in] ucs2_database_name
  //! \param[in] clientConnectBlock
  //!  ���� � ������� ����������� � ���� ������
  //! \param[in] FinalOpFuncs
  static void Helper__FinishConnect_P13__accept_data
               (port_type*                         pPort,
                const protocol::set02::PACKET_V02& acceptPacket,
                wstr_box_type                      ucs2_database_name,
                RemoteFB__ClientConnectBlock_v2&   clientConnectBlock,
                const tag_connect_finalizator&     FinalOpFuncs);

 private:
  struct tagAcceptConnectFuncs
  {
   public:
    typedef void (*accept_func_pointer)
     (port_type*                         pPort,
      const protocol::set02::PACKET_V02& acceptPacket,
      wstr_box_type                      ucs2_database_name,
      RemoteFB__ClientConnectBlock_v2&   clientConnectBlock,
      const tag_connect_finalizator&     FinalOpFuncs);

   public:
    accept_func_pointer P13;
  };//struct tagAcceptConnectFuncs

  //������� ��� ������������� ���������� �����������
  static const tagAcceptConnectFuncs sm_accept_funcs__cond_accept;

  //������� ��� ������������ ���������� �����������
  static const tagAcceptConnectFuncs sm_accept_funcs__accept_data;

 private:
  /// <summary>
  ///  ��������� ������ � ��������� �������������� �����������
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] clientConnectBlock
  //! \param[in] acpt
  //! \param[in] pPacketStream
  //!  ����� ������� �������������� ����������. Not NULL.
  static void Helper__Initialize__SetProtocolInfo_P13
               (port_type*                             pPort,
                const RemoteFB__ClientConnectBlock_v2& clientConnectBlock,
                const protocol::set02::P_OP_ACPT&      acpt,
                transmission::RemoteFB__PacketStream*  pPacketStream);

 private:
  /// ����� ������� ��� ���������� �������� ���� ������
  static const tag_connect_finalizator sm_finalizator_for_create;

  /// ����� ������� ��� ���������� ����������� ���� ������
  static const tag_connect_finalizator sm_finalizator_for_attach;
};//class RemoteFB__PortInitializer_PSET02_v01

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms v01*/}/*nms pset02*/}/*nms initializers*/}/*nms base_v01*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
