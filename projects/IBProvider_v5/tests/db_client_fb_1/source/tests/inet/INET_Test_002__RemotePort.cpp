////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/inet/INET_Test_002__RemotePort.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/db_client/remote_fb/transmission/pset01/p12/remote_fb__transmission__pset01__p12a__packet_stream.h"
#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__op__encoder.h"
#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__xdr__encoder.h"
#include "source/db_client/remote_fb/remote_fb__utils.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__db__get_info.h"
#include "source/db_obj/dbms_fb/v02_5_0/api/db_obj__dbms_fb__v02_5_0__api__error_codes.h"
#include "source/db_obj/dbms_fb/v03_0_0/api/db_obj__dbms_fb__v03_0_0__api__error_codes.h"
#include "source/db_obj/isc_base/isc_param_buffer_v1_builder.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/error_services/ibp_sqlstate_codes.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/charsets/t_cs_utf8.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class INET_Test_002__RemotePort::tag_impl

class INET_Test_002__RemotePort::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_03__connect
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_03__connect__inet4
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_03__connect__inet6
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_05__connect__bad_pswd__fb25
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_05__connect__bad_pswd__fb30
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 private:
  static void test_05__connect__bad_pswd__impl
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx,
                LONG                lNativeErrCode);

 public:
  static void test_06__connect__no_pswd__pset01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_06__connect__no_pswd__pset02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_07__connect__no_params__pset01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_07__connect__no_params__pset02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_08__connect__trust_auth_SSPI
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_09__connect__unk_rus_db_name
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_10__connect__very_long_database_name_pset01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_10__connect__very_long_database_name_pset02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_10__create__very_long_database_name_pset01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_10__create__very_long_database_name_pset02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_11__connect__cant_convert_dbname_to_utf8__p12
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_11__connect__cant_convert_dbname_to_utf8__pset02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_12__connect__cant_convert_pswd_to_utf8__p12
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_12__connect__cant_convert_pswd_to_utf8__pset02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_13__connect__max_database_name_length
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_E04__not_supported_parch__pset01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_E04__not_supported_parch__pset02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_E05__requested_protocol_type_not_supported__p10
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_E05__requested_protocol_type_not_supported__p11
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_E05__requested_protocol_type_not_supported__p12
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_E05__requested_protocol_type_not_supported__p13
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 private:
  static void test_E05__requested_protocol_type_not_supported__impl
               (TTSO_GlobalContext*         pParams,
                context_type*               pCtx,
                structure::t_const_wstr_box subsystemName,
                unsigned                    protocol_version);
 public:
  static void test_E06__not_supported_protocol
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 private:
  static const wchar_t* const sm_E06_data[];
};//class INET_Test_002__RemotePort::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 03

void INET_Test_002__RemotePort::tag_impl::test_03__connect
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db)->m_value));

 //-----------------------------------------
 typedef TestServices svc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 const svc::remote_fb_inet_port_ptr
  spPort
   =svc::RemoteFB_INET_Port__ConnectToDatabase
     (tracer,
      ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
      hostName.c_str(),
      nullptr,
      dbName.c_str(),
      params);
}//test_03__connect

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_03__connect__inet4
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db)->m_value));

 //-----------------------------------------
 typedef TestServices svc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 const svc::remote_fb_inet_port_ptr
  spPort
   =svc::RemoteFB_INET_Port__ConnectToDatabase
     (tracer,
      ibp::os::win32::winsock::API::WinSock__AF_INET,
      hostName.c_str(),
      nullptr,
      dbName.c_str(),
      params);
}//test_03__connect__inet4

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_03__connect__inet6
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db)->m_value));

 //-----------------------------------------
 typedef TestServices svc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 const svc::remote_fb_inet_port_ptr
  spPort
   =svc::RemoteFB_INET_Port__ConnectToDatabase
     (tracer,
      ibp::os::win32::winsock::API::WinSock__AF_INET6,
      hostName.c_str(),
      nullptr,
      dbName.c_str(),
      params);
}//test_03__connect__inet6

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_05__connect__bad_pswd__fb25
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 return test_05__connect__bad_pswd__impl
         (pParams,
          pCtx,
          ibp::db_obj::dbms_fb::v02_5_0::api::ibp_fb_v25_err__login);
}//test_05__connect__bad_pswd__fb25

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_05__connect__bad_pswd__fb30
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 return test_05__connect__bad_pswd__impl
         (pParams,
          pCtx,
          ibp::db_obj::dbms_fb::v03_0_0::api::ibp_fb_v30_err__login);
}//test_05__connect__bad_pswd__fb30

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_05__connect__bad_pswd__impl
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            LONG                const lNativeErrCode)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db)->m_value));

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"badabum");

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__ConnectToDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__srv_err__bad_login
   (tracer,
    errSvc::utf8_to_wstring(errSvc::sm_srcID__UnknownDBMS),
    exc.get_record(0));

  errSvc::error_rec__check_sqlstate_and_native_code
   (tracer,
    exc.get_record(0),
    L"28000", //IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS
    lNativeErrCode /*ibp::db_obj::dbms_fb::v02_5_0::api::ibp_fb_v25_err__login*/);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_05__connect__bad_pswd__impl

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_06__connect__no_pswd__pset01
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db)->m_value));

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__ConnectToDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__cant_detect_auth_method
   (tracer,
    errSvc::utf8_to_wstring(errSvc::sm_srcID__IBProvider),
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_pset01);

  errSvc::error_rec__check_sqlstate_and_native_code
   (tracer,
    exc.get_record(0),
    L"28000", //IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS
    DB_SEC_E_AUTH_FAILED);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_06__connect__no_pswd__pset01

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_06__connect__no_pswd__pset02
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db)->m_value));

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__ConnectToDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__cant_detect_auth_method
   (tracer,
    errSvc::utf8_to_wstring(errSvc::sm_srcID__IBProvider),
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_pset02);

  errSvc::error_rec__check_sqlstate_and_native_code
   (tracer,
    exc.get_record(0),
    L"28000", //IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS
    DB_SEC_E_AUTH_FAILED);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_06__connect__no_pswd__pset02

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_07__connect__no_params__pset01
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db)->m_value));

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__ConnectToDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__cant_detect_auth_method
   (tracer,
    errSvc::utf8_to_wstring(errSvc::sm_srcID__IBProvider),
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_pset01);

  errSvc::error_rec__check_sqlstate_and_native_code
   (tracer,
    exc.get_record(0),
    L"28000", //IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS
    DB_SEC_E_AUTH_FAILED);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_07__connect__no_params__pset01

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_07__connect__no_params__pset02
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db)->m_value));

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set02);

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__ConnectToDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__cant_detect_auth_method
   (tracer,
    errSvc::utf8_to_wstring(errSvc::sm_srcID__IBProvider),
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_pset02);

  errSvc::error_rec__check_sqlstate_and_native_code
   (tracer,
    exc.get_record(0),
    L"28000", //IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS
    DB_SEC_E_AUTH_FAILED);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_07__connect__no_params__pset02

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_08__connect__trust_auth_SSPI
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db)->m_value));

 //-----------------------------------------
 typedef TestServices svc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__integrated_auth(L"SSPI");

 const svc::remote_fb_inet_port_ptr
  spPort
   =svc::RemoteFB_INET_Port__ConnectToDatabase
     (tracer,
      ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
      hostName.c_str(),
      nullptr,
      dbName.c_str(),
      params);
}//test_08__connect__trust_auth_SSPI

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_09__connect__unk_rus_db_name
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(errSvc::utf8_to_wstring("бла_бла_бла_датабазе.дб"));

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");
 params.set_dbprop_init__ctype_system(L"win1251");

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__ConnectToDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__srv_err__unk_db_name
   (tracer,
    exc.get_record(0),
    errSvc::utf8_to_wstring(errSvc::sm_srcID__UnknownDBMS),
    dbName);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_09__connect__unk_rus_db_name

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_10__connect__very_long_database_name_pset01
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(1024*128,L'x');

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__ConnectToDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__db_name_is_too_long
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_p12,
    dbName.size(),
    65535);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_10__connect__very_long_database_name_pset01

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_10__connect__very_long_database_name_pset02
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(1024*128,L'x');

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set02);

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__ConnectToDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__db_name_is_too_long
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_pset02,
    dbName.size(),
    65535);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_10__connect__very_long_database_name_pset02

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_10__create__very_long_database_name_pset01
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(1024*128,L'x');

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__CreateDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__db_name_is_too_long
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_p12,
    dbName.size(),
    65535);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_10__create__very_long_database_name_pset01

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_10__create__very_long_database_name_pset02
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(1024*128,L'x');

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set02);

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__CreateDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__db_name_is_too_long
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_pset02,
    dbName.size(),
    65535);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_10__create__very_long_database_name_pset02

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_11__connect__cant_convert_dbname_to_utf8__p12
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 std::wstring dbName;

 dbName+=wchar_t(structure::charsets::cs_utf8::traits::c_SURROGATE_HIGH_START);
 dbName+=wchar_t(structure::charsets::cs_utf8::traits::c_SURROGATE_HIGH_START);

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__12);

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__ConnectToDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__translate_db_name_to_utf8
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_p12);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_11__connect__cant_convert_dbname_to_utf8__p12

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_11__connect__cant_convert_dbname_to_utf8__pset02
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 std::wstring dbName;

 dbName+=wchar_t(structure::charsets::cs_utf8::traits::c_SURROGATE_HIGH_START);
 dbName+=wchar_t(structure::charsets::cs_utf8::traits::c_SURROGATE_HIGH_START);

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set02);

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__ConnectToDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__translate_db_name_to_utf8
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_pset02);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_11__connect__cant_convert_dbname_to_utf8__pset02

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_12__connect__cant_convert_pswd_to_utf8__p12
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 std::wstring
  dbName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db)->m_value));

 //-----------------------------------------
 std::wstring bad_ucs2;

 bad_ucs2+=wchar_t(structure::charsets::cs_utf8::traits::c_SURROGATE_HIGH_START);
 bad_ucs2+=wchar_t(structure::charsets::cs_utf8::traits::c_SURROGATE_HIGH_START);

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(bad_ucs2);

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__12);

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__ConnectToDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__translate_cn_param_to_utf8
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_p12,
    L"Password");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_12__connect__cant_convert_pswd_to_utf8__p12

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_12__connect__cant_convert_pswd_to_utf8__pset02
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 std::wstring
  dbName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db)->m_value));

 //-----------------------------------------
 std::wstring bad_ucs2;

 bad_ucs2+=wchar_t(structure::charsets::cs_utf8::traits::c_SURROGATE_HIGH_START);
 bad_ucs2+=wchar_t(structure::charsets::cs_utf8::traits::c_SURROGATE_HIGH_START);

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(bad_ucs2);

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set02);

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__ConnectToDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__translate_cn_param_to_utf8
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb,
    L"Password");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_12__connect__cant_convert_pswd_to_utf8__pset02

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_13__connect__max_database_name_length
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const std::wstring
  hostName(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__inet_host)->m_value));

 const std::wstring
  dbName(USHRT_MAX,L'x');

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort
    =svc::RemoteFB_INET_Port__ConnectToDatabase
      (tracer,
       ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
       hostName.c_str(),
       nullptr,
       dbName.c_str(),
       params);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec
   (tracer,
    exc.get_record(0),
    errSvc::utf8_to_wstring(errSvc::sm_srcID__UnknownDBMS),
    L"Firebird::string - length exceeds predefined limit");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_13__connect__max_database_name_length

////////////////////////////////////////////////////////////////////////////////
//TEST E04

void INET_Test_002__RemotePort::tag_impl::test_E04__not_supported_parch__pset01
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 //-----------------------------------------
 structure::wstr_formatter dbLocation(L"inet://[%1]/%2");

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__db)->m_value;

 params.set_dbprop_init__location(dbLocation.str());
 
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 params.set_dbprop_init__remote__protocol_arch(L" generic, AAA ");

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 try
 {
  svc::RemoteFB_Connector__ConnectToDatabase
   (tracer,
    params,
    cns); //throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__unsupported_protocol_architecture
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_pset01,
    L"AAA");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_E04__not_supported_parch__pset01

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_E04__not_supported_parch__pset02
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 //-----------------------------------------
 structure::wstr_formatter dbLocation(L"inet://[%1]/%2");

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__db)->m_value;

 params.set_dbprop_init__location(dbLocation.str());
 
 params.set_dbprop_init__remote__protocol_arch(L" generic, AAA ");

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set02);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 try
 {
  svc::RemoteFB_Connector__ConnectToDatabase
   (tracer,
    params,
    cns); //throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__unsupported_protocol_architecture
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_pset02,
    L"AAA");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_E04__not_supported_parch__pset02

////////////////////////////////////////////////////////////////////////////////
//TEST E05

void INET_Test_002__RemotePort::tag_impl::test_E05__requested_protocol_type_not_supported__p10
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 test_E05__requested_protocol_type_not_supported__impl
  (pParams,
   pCtx,
   TestCheckErrors::sm_subsysID__remote_fb_pset01,
   10);
}//test_E05__requested_protocol_type_not_supported__p10

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_E05__requested_protocol_type_not_supported__p11
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 test_E05__requested_protocol_type_not_supported__impl
  (pParams,
   pCtx,
   TestCheckErrors::sm_subsysID__remote_fb_pset01,
   11);
}//test_E05__requested_protocol_type_not_supported__p11

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_E05__requested_protocol_type_not_supported__p12
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 test_E05__requested_protocol_type_not_supported__impl
  (pParams,
   pCtx,
   TestCheckErrors::sm_subsysID__remote_fb_pset01,
   12);
}//test_E05__requested_protocol_type_not_supported__p12

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_E05__requested_protocol_type_not_supported__p13
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 test_E05__requested_protocol_type_not_supported__impl
  (pParams,
   pCtx,
   TestCheckErrors::sm_subsysID__remote_fb_pset02,
   13);
}//test_E05__requested_protocol_type_not_supported__p13

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_E05__requested_protocol_type_not_supported__impl
                                           (TTSO_GlobalContext*         const pParams,
                                            context_type*               const pCtx,
                                            structure::t_const_wstr_box const subsystemName,
                                            unsigned                    const protocol_version)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 //-----------------------------------------
 structure::wstr_formatter dbLocation(L"inet://[%1]/%2");

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__db)->m_value;

 params.set_dbprop_init__location(dbLocation.str());
 
 params.set_dbprop_init__remote__protocol_type(L" AAA ");

 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 try
 {
  svc::RemoteFB_Connector__ConnectToDatabase
   (tracer,
    params,
    cns); //throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec___ibp_mce_remote__requested_protocol_type_not_supported_2
   (tracer,
    exc.get_record(0),
    subsystemName,
    L" AAA ", //save spaces
    protocol_version);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_E05__requested_protocol_type_not_supported__impl

////////////////////////////////////////////////////////////////////////////////
//TEST E06

const wchar_t* const INET_Test_002__RemotePort::tag_impl::sm_E06_data[]=
{
 L" ABC ",
 L"10 ",
 L" 10",
 L" 10 ",
};//sm_E06_data

//------------------------------------------------------------------------
void INET_Test_002__RemotePort::tag_impl::test_E06__not_supported_protocol
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 //-----------------------------------------
 structure::wstr_formatter dbLocation(L"inet://[%1]/%2");

 dbLocation<<pParams->args().get(c_prog_arg__inet_host)->m_value
           <<pParams->args().get(c_prog_arg__db)->m_value;


 params.set_dbprop_init__location(dbLocation.str());
 params.set_dbprop_init__user_id(L"sysdba");
 params.set_dbprop_init__password(L"masterkey");

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 for(const auto x : sm_E06_data)
 {
  tracer<<L"--------------------------------"<<send;
  
  params.set_dbprop_init__remote__protocol(x);
  
  try
  {
   svc::RemoteFB_Connector__ConnectToDatabase
   (tracer,
    params,
    cns); //throw
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;
 
   errSvc::print_exception_ok(tracer,exc);
 
   errSvc::check_err_count(exc,1);
 
   errSvc::check_err_rec__unsupported_protocol
    (tracer,
     exc.get_record(0),
     errSvc::sm_subsysID__remote_fb_inet,
     x);
 
   continue;
  }//catch

  tracer(tso_msg_error,-1)
   <<L"We wait the error!"
   <<send;
 }//for each x
}//test_E06__not_supported_protocol

////////////////////////////////////////////////////////////////////////////////
//struct INET_Test_002__RemotePort::tag_descr

struct INET_Test_002__RemotePort::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class INET_Test_002__RemotePort::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,INET_Test_002__RemotePort::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const INET_Test_002__RemotePort::tag_descr
 INET_Test_002__RemotePort::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("03.connect",
   test_03__connect)

 DEF_TEST_DESCR
  ("03.connect__inet4",
   test_03__connect__inet4)

 DEF_TEST_DESCR2
  ("03.connect__inet6",
   test_03__connect__inet6,
   "SRV>=FB-3")

 DEF_TEST_DESCR2
  ("05.connect.bad_pswd.fb25",
   test_05__connect__bad_pswd__fb25,
   "SRV<=FB-2.5")

 DEF_TEST_DESCR2
  ("05.connect.bad_pswd.fb30",
   test_05__connect__bad_pswd__fb30,
   "SRV>=FB-3")

 DEF_TEST_DESCR2
  ("06.connect.no_pswd.pset01",
   test_06__connect__no_pswd__pset01,
   "SRV<=FB-2.5")

 DEF_TEST_DESCR2
  ("06.connect.no_pswd.pset02",
   test_06__connect__no_pswd__pset02,
   "SRV>=FB-3")

 DEF_TEST_DESCR2
  ("07.connect.no_params.pset01",
   test_07__connect__no_params__pset01,
   "SRV<=FB-2.5")

 DEF_TEST_DESCR2
  ("07.connect.no_params.pset02",
   test_07__connect__no_params__pset02,
   "SRV>=FB-3")

 DEF_TEST_DESCR
  ("08.connect.trust_auth.SSPI",
   test_08__connect__trust_auth_SSPI)

 DEF_TEST_DESCR
  ("09.connect.unk_rus_db_name",
   test_09__connect__unk_rus_db_name)

 DEF_TEST_DESCR2
  ("10.connect.very_long_db_name.pset01",
   test_10__connect__very_long_database_name_pset01,
   "SRV<FB-3")

 DEF_TEST_DESCR2
  ("10.connect.very_long_db_name.pset02",
   test_10__connect__very_long_database_name_pset02,
   "SRV>=FB-3")

 DEF_TEST_DESCR2
  ("10.create.very_long_db_name.pset01",
   test_10__create__very_long_database_name_pset01,
   "SRV<FB-3")

 DEF_TEST_DESCR2
  ("10.create.very_long_db_name.pset02",
   test_10__create__very_long_database_name_pset02,
   "SRV>=FB-3")

 DEF_TEST_DESCR2
  ("11.connect.cant_convert_db_name_to_utf8.p12",
   test_11__connect__cant_convert_dbname_to_utf8__p12,
   "SRV<FB-3")

 DEF_TEST_DESCR2
  ("11.connect.cant_convert_db_name_to_utf8.pset02",
   test_11__connect__cant_convert_dbname_to_utf8__pset02,
   "SRV>=FB-3")

 DEF_TEST_DESCR2
  ("12.connect.cant_convert_pswd_to_utf8.p12",
   test_12__connect__cant_convert_pswd_to_utf8__p12,
   "SRV>=FB-2.5 && SRV<FB-3")

 DEF_TEST_DESCR2
  ("12.connect.cant_convert_pswd_to_utf8.pset02",
   test_12__connect__cant_convert_pswd_to_utf8__pset02,
   "SRV>=FB-3")

 DEF_TEST_DESCR
  ("13.connect.max_database_name_length",
   test_13__connect__max_database_name_length)

 DEF_TEST_DESCR2
  ("E04.err.not_supported_parch.pset01",
   test_E04__not_supported_parch__pset01,
   "SRV<FB-3")

 DEF_TEST_DESCR2
  ("E04.err.not_supported_parch.pset02",
   test_E04__not_supported_parch__pset02,
   "SRV>=FB-3")

 DEF_TEST_DESCR2
  ("E05.err.not_supported_ptype.p10",
   test_E05__requested_protocol_type_not_supported__p10,
   "SRV<FB-2.1")

 DEF_TEST_DESCR2
  ("E05.err.not_supported_ptype.p11",
   test_E05__requested_protocol_type_not_supported__p11,
   "SRV>=FB-2.1 && SRV<FB-2.5")

 DEF_TEST_DESCR2
  ("E05.err.not_supported_ptype.p12",
   test_E05__requested_protocol_type_not_supported__p12,
   "SRV>=FB-2.5 && SRV<FB-3")

 DEF_TEST_DESCR2
  ("E05.err.not_supported_ptype.p13",
   test_E05__requested_protocol_type_not_supported__p13,
   "SRV>=FB-3")

 DEF_TEST_DESCR
  ("E06.err.not_supported_protocol",
   test_E06__not_supported_protocol)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class INET_Test_002__RemotePort

void INET_Test_002__RemotePort::create(TTSO_PushTest*      const pTestPusher,
                                       TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter ftestID("RemoteFB.INET.002.RemotePort.%1");

 for(const tag_descr& d : sm_Tests)
 {
  ftestID<<structure::flush
         <<d.pTestSign;

  const TTSO_TestPtr
   spTest
    (lib::structure::not_null_ptr
      (new TTSO_TestFunc
        (pParams,
         ftestID.c_str(),
         d.Func,
         d.pExecRules)));

  pTestPusher->PushTest(spTest);
 }//for d
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
