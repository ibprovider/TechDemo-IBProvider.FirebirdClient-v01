////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/protocol/set01/TestsFor__PSET01__001_Mix.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"

#include <structure/test_obj/t_tso_user.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__PSET01__001_Mix::tag_impl

class TestsFor__PSET01__001_Mix::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_002__conflict_with_integrated_security
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_003__define_Win_SSPI_and_Integrated_Security
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_004__wire_crypt___disabled
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_005__wire_crypt___enabled
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_006__wire_crypt___required
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

#ifdef NDEBUG
  static void test_007__wire_crypt___unk_value
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
#endif

 public:
  static void test_C01__wire_compression___disabled
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_C02__wire_compression___enabled
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_C03__wire_compression___required
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

#ifdef NDEBUG
  static void test_C04__wire_compression___unk_value
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
#endif

#ifdef NDEBUG
 public:
  static void test_E01__bug_check__bad_parch__001
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_E02__bug_check__bad_parch__002
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_E03__bug_check__bad_parch__003
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
#endif
};//class TestsFor__PSET01__001_Mix::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void TestsFor__PSET01__001_Mix::tag_impl::test_002__conflict_with_integrated_security
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);
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

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 params.set_dbprop_init__remote__auth(L"Legacy_Auth");

 params.set_dbprop_init__integrated_auth(L"SSPI");

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
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__incompatible_auth_settings
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_pset01,
    L"Legacy_Auth",
    L"SSPI");

  errSvc::check_err_code
   (exc.com_code(),
    DB_SEC_E_AUTH_FAILED);

  errSvc::error_rec__check_sqlstate_and_native_code
   (tracer,
    exc.get_record(0),
    L"28000", //IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS
    DB_SEC_E_AUTH_FAILED);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_002__conflict_with_integrated_security

////////////////////////////////////////////////////////////////////////////////
//TEST 003

void TestsFor__PSET01__001_Mix::tag_impl::test_003__define_Win_SSPI_and_Integrated_Security
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

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

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 params.set_dbprop_init__remote__auth(L"Win_Sspi");

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
}//test_003__define_Win_SSPI_and_Integrated_Security

////////////////////////////////////////////////////////////////////////////////
//TEST 004

void TestsFor__PSET01__001_Mix::tag_impl::test_004__wire_crypt___disabled
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 params.set_dbprop_init__remote__wire_crypt(ibprovider::ibp_propval__remote__wire_crypt__disabled);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 params.set_dbprop_init__user_id(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_user,true)->m_value));

 params.set_dbprop_init__password(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_password,true)->m_value));

 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_004__wire_crypt___disabled

////////////////////////////////////////////////////////////////////////////////
//TEST 005

void TestsFor__PSET01__001_Mix::tag_impl::test_005__wire_crypt___enabled
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 params.set_dbprop_init__remote__wire_crypt(ibprovider::ibp_propval__remote__wire_crypt__enabled);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 params.set_dbprop_init__user_id(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_user,true)->m_value));

 params.set_dbprop_init__password(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_password,true)->m_value));

 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_005__wire_crypt___enabled

////////////////////////////////////////////////////////////////////////////////
//TEST 006

void TestsFor__PSET01__001_Mix::tag_impl::test_006__wire_crypt___required
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 params.set_dbprop_init__remote__wire_crypt(ibprovider::ibp_propval__remote__wire_crypt__required);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 params.set_dbprop_init__user_id(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_user,true)->m_value));

 params.set_dbprop_init__password(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_password,true)->m_value));

 isc_base::t_isc_connection_settings cns;

 try
 {
  svc::RemoteFB_Connector__ConnectToDatabase
   (tracer,
    params,
    cns);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__wire_crypt_not_supported
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_pset01);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_006__wire_crypt___required

////////////////////////////////////////////////////////////////////////////////
//TEST 007

#ifdef NDEBUG

void TestsFor__PSET01__001_Mix::tag_impl::test_007__wire_crypt___unk_value
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 params.set_dbprop_init__remote__wire_crypt(IBP_T("BLA-BLA-BLA"));

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 params.set_dbprop_init__user_id(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_user,true)->m_value));

 params.set_dbprop_init__password(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_password,true)->m_value));

 isc_base::t_isc_connection_settings cns;

 try
 {
  svc::RemoteFB_Connector__ConnectToDatabase
   (tracer,
    params,
    cns);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__bug_check__unknown_property_value
   (tracer,
    exc.get_record(0),
    L"IBP_OLEDB_Props2__Values__DATASOURCE::Get_Remote_WireCrypt",
    L"#001",
    L"remote:wire_crypt",
    L"BLA-BLA-BLA");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_007__wire_crypt___unk_value

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST C01

void TestsFor__PSET01__001_Mix::tag_impl::test_C01__wire_compression___disabled
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 params.set_dbprop_init__remote__wire_compression(ibprovider::ibp_propval__remote__wire_compression__disabled);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 params.set_dbprop_init__user_id(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_user,true)->m_value));

 params.set_dbprop_init__password(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_password,true)->m_value));

 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_C01__wire_compression___disabled

////////////////////////////////////////////////////////////////////////////////
//TEST C02

void TestsFor__PSET01__001_Mix::tag_impl::test_C02__wire_compression___enabled
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 params.set_dbprop_init__remote__wire_compression(ibprovider::ibp_propval__remote__wire_compression__enabled);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 params.set_dbprop_init__user_id(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_user,true)->m_value));

 params.set_dbprop_init__password(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_password,true)->m_value));

 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_C01__wire_compression___enabled

////////////////////////////////////////////////////////////////////////////////
//TEST C02

void TestsFor__PSET01__001_Mix::tag_impl::test_C03__wire_compression___required
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 params.set_dbprop_init__remote__wire_compression(ibprovider::ibp_propval__remote__wire_compression__required);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 params.set_dbprop_init__user_id(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_user,true)->m_value));

 params.set_dbprop_init__password(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_password,true)->m_value));

 isc_base::t_isc_connection_settings cns;

 try
 {
  svc::RemoteFB_Connector__ConnectToDatabase
   (tracer,
    params,
    cns);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec___ibp_mce_remote__wire_compression_not_supported_0
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_pset01);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_C03__wire_compression___required

////////////////////////////////////////////////////////////////////////////////
//TEST C04

#ifdef NDEBUG

void TestsFor__PSET01__001_Mix::tag_impl::test_C04__wire_compression___unk_value
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices svc;

 svc::dbprops_type params(pParams);

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 params.set_dbprop_init__remote__wire_compression(IBP_T("BLA-BLA-BLA"));

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 params.set_dbprop_init__user_id(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_user,true)->m_value));

 params.set_dbprop_init__password(structure::tstr_to_wstr(pParams->args().get(c_prog_arg__db_password,true)->m_value));

 isc_base::t_isc_connection_settings cns;

 try
 {
  svc::RemoteFB_Connector__ConnectToDatabase
   (tracer,
    params,
    cns);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok
   (tracer,
    exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__bug_check__unknown_property_value
   (tracer,
    exc.get_record(0),
    L"IBP_OLEDB_Props2__Values__DATASOURCE::Get_Remote_WireCompression",
    L"#001",
    L"remote:wire_compression",
    L"BLA-BLA-BLA");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_C04__wire_compression___unk_value

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST E01

#ifdef NDEBUG

void TestsFor__PSET01__001_Mix::tag_impl::test_E01__bug_check__bad_parch__001
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
 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 params.set_dbprop_init__remote__protocol_arch(L"  ,  ");

 params.set_dbprop_init__user_id(L"xxx");
 params.set_dbprop_init__password(L"yyy");

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

  errSvc::check_err_rec__bug_check__mistake_in_parch_list
   (tracer,
    exc.get_record(0),
    L"RemoteFB__PortInitializer_PSET01_v01::Helper__TryConnect__GetProtocolArchitectures",
    L"#001");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_E01__bug_check__bad_parch__001

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST E02

#ifdef NDEBUG

void TestsFor__PSET01__001_Mix::tag_impl::test_E02__bug_check__bad_parch__002
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
 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 params.set_dbprop_init__remote__protocol_arch(L" symmetric  , generic , generic ");

 params.set_dbprop_init__user_id(L"xxx");
 params.set_dbprop_init__password(L"yyy");

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

  errSvc::check_err_rec__bug_check__mult_enum_of_parch
   (tracer,
    exc.get_record(0),
    L"RemoteFB__PortInitializer_PSET01_v01::Helper__TryConnect__GetProtocolArchitectures",
    L"#002",
    L"generic");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_E02__bug_check__bad_parch__002

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST E03

#ifdef NDEBUG

void TestsFor__PSET01__001_Mix::tag_impl::test_E03__bug_check__bad_parch__003
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
 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set01);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 params.set_dbprop_init__remote__protocol_arch(L"");

 params.set_dbprop_init__user_id(L"xxx");
 params.set_dbprop_init__password(L"yyy");

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

  errSvc::check_err_rec__bug_check__empty_list_of_parchs
   (tracer,
    exc.get_record(0),
    L"RemoteFB__PortInitializer_PSET01_v01::Helper__TryConnect__GetProtocolArchitectures",
    L"#003");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_E03__bug_check__bad_parch__003

#endif

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__PSET01__001_Mix::tag_descr

struct TestsFor__PSET01__001_Mix::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class TestsFor__PSET01__001_Mix::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,TestsFor__PSET01__001_Mix::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const TestsFor__PSET01__001_Mix::tag_descr
 TestsFor__PSET01__001_Mix::sm_Tests[]=
{
 DEF_TEST_DESCR2
  ("002.conflict_with_integrated_security",
   test_002__conflict_with_integrated_security,
   "NE__PSET01")

 DEF_TEST_DESCR2
  ("003.define_Win_SSPI_and_Integrated_Security",
   test_003__define_Win_SSPI_and_Integrated_Security,
   "NE__PSET01 && NE__AUTH__WIN_SSPI")

 DEF_TEST_DESCR2
  ("004.wire_crypt.disabled",
   test_004__wire_crypt___disabled,
   "NE__PSET01")

 DEF_TEST_DESCR2
  ("005.wire_crypt.enabled",
   test_005__wire_crypt___enabled,
   "NE__PSET01")

 DEF_TEST_DESCR2
  ("006.wire_crypt.required",
   test_006__wire_crypt___required,
   "NE__PSET01")

#ifdef NDEBUG
 DEF_TEST_DESCR2
  ("007.wire_crypt.err.unk_value",
   test_007__wire_crypt___unk_value,
   "NE__PSET01")
#endif

 DEF_TEST_DESCR2
  ("C01.wire_compression.disabled",
   test_C01__wire_compression___disabled,
   "NE__PSET01")

 DEF_TEST_DESCR2
  ("C02.wire_compression.enabled",
   test_C02__wire_compression___enabled,
   "NE__PSET01")

 DEF_TEST_DESCR2
  ("C03.wire_compression.required",
   test_C03__wire_compression___required,
   "NE__PSET01")

#ifdef NDEBUG
 DEF_TEST_DESCR2
  ("C04.wire_compression.err.unk_value",
   test_C04__wire_compression___unk_value,
   "NE__PSET01")
#endif

#ifdef NDEBUG
 DEF_TEST_DESCR
  ("E01.bug_check.bad_parch.001",
   test_E01__bug_check__bad_parch__001)

 DEF_TEST_DESCR
  ("E02.bug_check.bad_parch.002",
   test_E02__bug_check__bad_parch__002)

 DEF_TEST_DESCR
  ("E03.bug_check.bad_parch.003",
   test_E03__bug_check__bad_parch__003)
#endif
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__PSET01__001_Mix

void TestsFor__PSET01__001_Mix::create(TTSO_PushTest*      const pTestPusher,
                                       TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter
  ftestID("RemoteFB.protocol.set01.001.Mix.%1");

 for(const tag_descr& d : sm_Tests)
 {
  ftestID<<structure::flush
         <<d.pTestSign;

  const TTSO_TestPtr
   spTest
    (structure::not_null_ptr
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
