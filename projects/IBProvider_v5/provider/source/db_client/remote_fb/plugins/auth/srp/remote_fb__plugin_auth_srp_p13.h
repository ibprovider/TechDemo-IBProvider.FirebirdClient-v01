////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_srp_p13.h
//! \brief   ���������� ������� ��� SRP-�������������� [Firebird 3.0]
//! \author  Kovalenko Dmitry
//! \date    12.07.2016
#ifndef _remote_fb__plugin_auth_srp_p13_H_
#define _remote_fb__plugin_auth_srp_p13_H_

#include "source/db_client/remote_fb/plugins/auth/remote_fb__plugin_auth.h"
#include "source/db_obj/dbms_fb/v03_0_0/db_obj__dbms_fb__v03_0_0__auth__srp_remote_password.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace plugins{namespace auth{namespace srp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__plugin_auth
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_SRP_P13_Data

class RemoteFB__Plugin_Auth_SRP_P13_Data
 :public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  using name_type=RemoteFB__Plugin_Auth::name_type;

  using bytes_type=IBP_BigInteger::bytes_type;

 public:
  static const size_t c_expectedSaltAndKeySize
   =2*(db_obj::dbms_fb::v03_0_0::fb_v03_0_0__auth__srp_remote_password_data::SRP_SALT_SIZE
      +db_obj::dbms_fb::v03_0_0::fb_v03_0_0__auth__srp_remote_password_data::SRP_KEY_SIZE
      +2);

 public:
  virtual name_type getPluginName()const=0;

  virtual std::string getClientKey()const=0;

  virtual void calcClientSessionKeyAndProof
        (bytes_type*                pSessionKey,
         std::string*               pClientProof,
         structure::t_const_str_box account,
         structure::t_const_str_box salt,
         structure::t_const_str_box password,
         const char*                serverPubKey)const=0;
};//class RemoteFB__Plugin_Auth_SRP_P13_Data

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_SRP_P13_Data_Impl

template<class SecureHashAlgorithms,const wchar_t* pName>
class RemoteFB__Plugin_Auth_SRP_P13_Data_Impl LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_DYNAMIC(RemoteFB__Plugin_Auth_SRP_P13_Data)
{
 private:
  using self_type=RemoteFB__Plugin_Auth_SRP_P13_Data_Impl;

  RemoteFB__Plugin_Auth_SRP_P13_Data_Impl(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr
   =lib::structure::t_smart_object_ptr<RemoteFB__Plugin_Auth_SRP_P13_Data>;

 private:
  RemoteFB__Plugin_Auth_SRP_P13_Data_Impl();

  virtual ~RemoteFB__Plugin_Auth_SRP_P13_Data_Impl();

 public:
  static self_ptr Create();

  //RemoteFB__Plugin_Auth_SRP_P13_Data interface -------------------------
  virtual name_type getPluginName()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual std::string getClientKey()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void calcClientSessionKeyAndProof
        (bytes_type*                pSessionKey,
         std::string*               pClientProof,
         structure::t_const_str_box account,
         structure::t_const_str_box salt,
         structure::t_const_str_box password,
         const char*                serverPubKey)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private: //typedefs -----------------------------------------------------
  using sha_type
   =SecureHashAlgorithms;

  using rem_password_type
   =db_obj::dbms_fb::v03_0_0::fb_v03_0_0__auth__srp_remote_password<sha_type>;

 private: //--------------------------------------------------------------
  const name_type m_PluginName;

  /// ������ SRP-��������������
  rem_password_type m_RemotePswd;
};//class RemoteFB__Plugin_Auth_SRP_P13_Data_Impl

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_SRP_P13

/// <summary>
///  ���������� ������� ��� SRP-�������������� [Firebird 3.0]
/// </summary>
class RemoteFB__Plugin_Auth_SRP_P13 LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_DYNAMIC(RemoteFB__Plugin_Auth)
{
 private:
  using self_type=RemoteFB__Plugin_Auth_SRP_P13;

  RemoteFB__Plugin_Auth_SRP_P13(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  using data_type=RemoteFB__Plugin_Auth_SRP_P13_Data;

 private:
  /// <summary>
  ///  ����������� ��-���������.
  /// </summary>
  //! \param[in] pData
  //!  Not null
  RemoteFB__Plugin_Auth_SRP_P13(data_type* pData);

  /// <summary>
  ///  ����������.
  /// </summary>
  virtual ~RemoteFB__Plugin_Auth_SRP_P13();

 public:
  /// <summary>
  ///  ������� ������.
  /// </summary>
  template<class SecureHashAlgorithms,const wchar_t* pName>
  static RemoteFB__Plugin_AuthPtr Create();

  //interface ------------------------------------------------------------
  /// <summary>
  ///  ������ � ������ ������� ��������������.
  /// </summary>
  //! \return
  //!  �������� ������.
  virtual name_type get_name()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  ����������� ������ �������������� � ������ � ����������� ������������� �����������.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  virtual void def_auth_params_in_cpb(RemoteFB__ClientConnectBlock_v2& clientConnectBlock)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  ��������� ������ ��������������.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  virtual void authenticate(RemoteFB__ClientConnectBlock_v2& clientConnectBlock)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  using data_ptr=lib::structure::t_smart_object_ptr<data_type>;

 private:
  ///������ ��������������.
  const data_ptr m_spData;

  ///���������� ����� ������ ������ authenticate
  unsigned m_step;
};//class RemoteFB__Plugin_Auth_SRP_P13

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms srp*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/db_client/remote_fb/plugins/auth/srp/remote_fb__plugin_auth_srp_p13.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
