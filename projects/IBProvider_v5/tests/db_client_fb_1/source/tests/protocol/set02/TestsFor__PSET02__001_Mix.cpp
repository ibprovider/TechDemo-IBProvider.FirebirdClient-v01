////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/protocol/set02/TestsFor__PSET02__001_Mix.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"

#include <structure/test_obj/t_tso_user.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__PSET02__001_Mix::tag_impl

class TestsFor__PSET02__001_Mix::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001__unsupported_auth_svc
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_002__conflict_with_integrated_security
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_003__define_Win_SSPI_and_Integrated_Security
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

#ifdef NDEBUG
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
};//class TestsFor__PSET02__001_Mix::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__PSET02__001_Mix::tag_impl::test_001__unsupported_auth_svc
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

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set02);

 params.set_dbprop_init__remote__auth(L"UUUUU");

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort=svc::RemoteFB_INET_Port__ConnectToDatabase
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

  errSvc::check_err_rec__cn_err__auth_service_not_supported
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_pset02,
    L"UUUUU");

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
}//test_001__unsupported_auth_svc

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__PSET02__001_Mix::tag_impl::test_002__conflict_with_integrated_security
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

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set02);

 params.set_dbprop_init__remote__auth(L"Srp");

 params.set_dbprop_init__integrated_auth(L"SSPI");

 try
 {
  const svc::remote_fb_inet_port_ptr
   spPort=svc::RemoteFB_INET_Port__ConnectToDatabase
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
    errSvc::sm_subsysID__remote_fb_pset02,
    L"Srp",
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
//TEST 001

void TestsFor__PSET02__001_Mix::tag_impl::test_003__define_Win_SSPI_and_Integrated_Security
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

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set02);

 params.set_dbprop_init__remote__auth(L"Win_Sspi");

 params.set_dbprop_init__integrated_auth(L"SSPI");

 const svc::remote_fb_inet_port_ptr
  spPort=svc::RemoteFB_INET_Port__ConnectToDatabase
                                           (tracer,
                                            ibp::os::win32::winsock::API::WinSock__AF_UNSPEC,
                                            hostName.c_str(),
                                            nullptr,
                                            dbName.c_str(),
                                            params);
}//test_003__define_Win_SSPI_and_Integrated_Security

////////////////////////////////////////////////////////////////////////////////
//TEST E01

#ifdef NDEBUG

void TestsFor__PSET02__001_Mix::tag_impl::test_E01__bug_check__bad_parch__001
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
 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set02);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 params.set_dbprop_init__remote__protocol_arch(L"  ,  ");

 params.set_dbprop_init__user_id(L"xxx");
 params.set_dbprop_init__password(L"yyy");

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 try
 {
  svc::RemoteFB_Connector__ConnectToDatabase(tracer,params,cns); //throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__bug_check__mistake_in_parch_list
   (tracer,
    exc.get_record(0),
    L"RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect__GetProtocolArchitectures",
    L"#001");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_E01__bug_check__bad_parch__001

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST E02

#ifdef NDEBUG

void TestsFor__PSET02__001_Mix::tag_impl::test_E02__bug_check__bad_parch__002
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
 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set02);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 params.set_dbprop_init__remote__protocol_arch(L" symmetric  , generic , generic ");

 params.set_dbprop_init__user_id(L"xxx");
 params.set_dbprop_init__password(L"yyy");

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 try
 {
  svc::RemoteFB_Connector__ConnectToDatabase(tracer,params,cns); //throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__bug_check__mult_enum_of_parch
   (tracer,
    exc.get_record(0),
    L"RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect__GetProtocolArchitectures",
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

void TestsFor__PSET02__001_Mix::tag_impl::test_E03__bug_check__bad_parch__003
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
 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__set02);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 params.set_dbprop_init__remote__protocol_arch(L"");

 params.set_dbprop_init__user_id(L"xxx");
 params.set_dbprop_init__password(L"yyy");

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 try
 {
  svc::RemoteFB_Connector__ConnectToDatabase(tracer,params,cns); //throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__bug_check__empty_list_of_parchs
   (tracer,
    exc.get_record(0),
    L"RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect__GetProtocolArchitectures",
    L"#003");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_E03__bug_check__bad_parch__003

#endif

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__PSET02__001_Mix::tag_descr

struct TestsFor__PSET02__001_Mix::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class TestsFor__PSET02__001_Mix::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,TestsFor__PSET02__001_Mix::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const TestsFor__PSET02__001_Mix::tag_descr
 TestsFor__PSET02__001_Mix::sm_Tests[]=
{
 DEF_TEST_DESCR2
  ("001.unsupported_auth_svc",
   test_001__unsupported_auth_svc,
   "NE__P13")

 DEF_TEST_DESCR2
  ("002.conflict_with_integrated_security",
   test_002__conflict_with_integrated_security,
   "NE__P13")

 DEF_TEST_DESCR2
  ("003.define_Win_SSPI_and_Integrated_Security",
   test_003__define_Win_SSPI_and_Integrated_Security,
   "NE__P13")

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
//class TestsFor__PSET02__001_Mix

void TestsFor__PSET02__001_Mix::create(TTSO_PushTest*      const pTestPusher,
                                    TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter
  ftestID("RemoteFB.protocol.set02.001.Mix.%1");

 for(const tag_descr& d : sm_Tests)
 {
  ftestID<<structure::flush
         <<d.pTestSign;

  const TTSO_TestPtr spTest(new TTSO_TestFunc(pParams,
                                              ftestID.c_str(),
                                              d.Func,
                                              d.pExecRules));
  pTestPusher->PushTest(spTest);
 }//for d
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
