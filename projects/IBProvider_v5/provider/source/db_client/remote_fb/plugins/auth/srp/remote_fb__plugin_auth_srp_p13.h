////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_srp_p13.h
//! \brief   Реализация плагина для SRP-аутентификации [Firebird 3.0]
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
  typedef RemoteFB__Plugin_Auth::name_type                 name_type;

  typedef IBP_BigInteger::bytes_type                       bytes_type;

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
class RemoteFB__Plugin_Auth_SRP_P13_Data_Impl
 :public REMOTE_FB__DEF_INTERFACE_IMPL_DYNAMIC(RemoteFB__Plugin_Auth_SRP_P13_Data)
{
 private:
  typedef RemoteFB__Plugin_Auth_SRP_P13_Data_Impl          self_type;

  RemoteFB__Plugin_Auth_SRP_P13_Data_Impl(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr
           <RemoteFB__Plugin_Auth_SRP_P13_Data>            self_ptr;

 private:
  RemoteFB__Plugin_Auth_SRP_P13_Data_Impl();

  virtual ~RemoteFB__Plugin_Auth_SRP_P13_Data_Impl();

 public:
  static self_ptr Create();

  //RemoteFB__Plugin_Auth_SRP_P13_Data interface -------------------------
  virtual name_type getPluginName()const COMP_W000004_OVERRIDE_FINAL;

  virtual std::string getClientKey()const COMP_W000004_OVERRIDE_FINAL;

  virtual void calcClientSessionKeyAndProof
        (bytes_type*                pSessionKey,
         std::string*               pClientProof,
         structure::t_const_str_box account,
         structure::t_const_str_box salt,
         structure::t_const_str_box password,
         const char*                serverPubKey)const COMP_W000004_OVERRIDE_FINAL;

 private: //typedefs -----------------------------------------------------
  typedef SecureHashAlgorithms
   sha_type;

  typedef db_obj::dbms_fb::v03_0_0::fb_v03_0_0__auth__srp_remote_password<sha_type>
   rem_password_type;

 private: //--------------------------------------------------------------
  const name_type m_PluginName;

  /// Данные SRP-аутентификации
  rem_password_type m_RemotePswd;
};//class RemoteFB__Plugin_Auth_SRP_P13_Data_Impl

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_SRP_P13

/// <summary>
///  Реализация плагина для SRP-аутентификации [Firebird 3.0]
/// </summary>
class RemoteFB__Plugin_Auth_SRP_P13
 :public REMOTE_FB__DEF_INTERFACE_IMPL_DYNAMIC(RemoteFB__Plugin_Auth)
{
 private:
  typedef RemoteFB__Plugin_Auth_SRP_P13         self_type;

  RemoteFB__Plugin_Auth_SRP_P13(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef RemoteFB__Plugin_Auth_SRP_P13_Data    data_type;

 private:
  /// <summary>
  ///  Конструктор по-умолчанию.
  /// </summary>
  //! \param[in] pData
  //!  Not null
  RemoteFB__Plugin_Auth_SRP_P13(data_type* pData);

  /// <summary>
  ///  Деструктор.
  /// </summary>
  virtual ~RemoteFB__Plugin_Auth_SRP_P13();

 public:
  /// <summary>
  ///  Фабрика класса.
  /// </summary>
  template<class SecureHashAlgorithms,const wchar_t* pName>
  static RemoteFB__Plugin_AuthPtr Create();

  //interface ------------------------------------------------------------
  /// <summary>
  ///  Строка с именем сервиса аутентификации.
  /// </summary>
  //! \return
  //!  Непустая строка.
  virtual name_type get_name()const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Определение данных аутентификации в буфере с параметрами инициализации подключения.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  virtual void def_auth_params_in_cpb(RemoteFB__ClientConnectBlock_v2& clientConnectBlock)COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Установка данных аутентификации.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  virtual void authenticate(RemoteFB__ClientConnectBlock_v2& clientConnectBlock)COMP_W000004_OVERRIDE_FINAL;

 private:
  typedef structure::t_smart_object_ptr<data_type> data_ptr;

 private:
  ///Данные аутентификации.
  const data_ptr m_spData;

  ///Порядковый номер вызова метода authenticate
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
