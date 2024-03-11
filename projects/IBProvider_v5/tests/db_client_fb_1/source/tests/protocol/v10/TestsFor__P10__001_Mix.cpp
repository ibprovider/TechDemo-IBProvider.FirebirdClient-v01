////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/protocol/v10/TestsFor__P10__001_Mix.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"

#include <structure/test_obj/t_tso_user.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__P10__001_Mix::tag_impl

class TestsFor__P10__001_Mix::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001__err__win_sspi
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_002__err__integ_sec
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
};//class TestsFor__P10__001_Mix::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__P10__001_Mix::tag_impl::test_001__err__win_sspi
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

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__10);

 params.set_dbprop_init__remote__auth(L"win_sspi");

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 //-----------------------------------------
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

  errSvc::check_err_rec__cn_err__integ_sec_not_supported
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_p10);

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
}//test_001__err__win_sspi

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void TestsFor__P10__001_Mix::tag_impl::test_002__err__integ_sec
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

 params.set_dbprop_init__remote__protocol(ibprovider::ibp_propval__remote__protocol__10);

 params.set_dbprop_init__integrated_auth(L"SSPI");

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));

 //-----------------------------------------
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

  errSvc::check_err_rec__cn_err__integ_sec_not_supported
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_p10);

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
}//test_002__err__integ_sec

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__P10__001_Mix::tag_descr

struct TestsFor__P10__001_Mix::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class TestsFor__P10__001_Mix::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,TestsFor__P10__001_Mix::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const TestsFor__P10__001_Mix::tag_descr
 TestsFor__P10__001_Mix::sm_Tests[]=
{
 DEF_TEST_DESCR2
  ("001.err.win_sspi",
   test_001__err__win_sspi,
   "NE__P10")

 DEF_TEST_DESCR2
  ("001.err.integ_sec",
   test_002__err__integ_sec,
   "NE__P10")
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__P10__001_Mix

void TestsFor__P10__001_Mix::create(TTSO_PushTest*      const pTestPusher,
                                    TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter
  ftestID("RemoteFB.protocol.v10.001.Mix.%1");

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
