////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/api/p13/RemoteFB__P13__ProcessAuthResponse/TestsFor__RemoteFB__P13__ProcessAuthResponse.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__process_auth_response.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"
#include "source/db_client/remote_fb/plugins/auth/legacy/remote_fb__plugin_auth_legacy_factory.h"
#include "source/db_client/remote_fb/plugins/auth/win_sspi/remote_fb__plugin_auth_win_sspi_factory.h"
#include "source/db_client/remote_fb/remote_fb__client_connect_block_v2.h"
#include <structure/test_obj/t_tso_user.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__P13__ProcessAuthResponse::tag_impl

class TestsFor__RemoteFB__P13__ProcessAuthResponse::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001__bugcheck_001
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_002__unk_auth_plugin_name
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_003__cycle_in_auth_plugin_reassign
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 private:
  static void helper__check_auth_plugin_name
               (remote_fb::plugins::auth::RemoteFB__Plugin_Auth* pAuthPlugin,
                const wchar_t*                                   pName);

  static void helper__check_auth_plugin_name
               (const wchar_t* pActualName,
                const wchar_t* pExpectedName);
};//class TestsFor__RemoteFB__P13__ProcessAuthResponse::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__RemoteFB__P13__ProcessAuthResponse::tag_impl::test_001__bugcheck_001
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 remote_fb::protocol::set02::P_CSTRING_CONST_V2 resp__AuthPluginName={};
 remote_fb::protocol::set02::P_CSTRING_CONST_V2 resp__AuthPluginData={};

 //-----------------------------------------
 const remote_fb::protocol::P_UCHAR bad_data[]={0xFF,0xFF};

 resp__AuthPluginName.cstr_length
  =sizeof(bad_data);

 resp__AuthPluginName.cstr_address
  =bad_data;

 //-----------------------------------------
 svc::dbprops_type cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2 clientConnectBlock(cn_params);

 try
 {
  remote_fb::api::p13::RemoteFB__P13__ProcessAuthResponse::exec
   (clientConnectBlock,
    &resp__AuthPluginName,
    &resp__AuthPluginData);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok
   (tracer,exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__bug_check__cant_convert_auth_service_name_from_utf8_to_wstr
   (tracer,
    exc.get_record(0),
    L"RemoteFB__P13__ProcessAuthResponse::exec",
    L"#001");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_001__bugcheck_001

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void TestsFor__RemoteFB__P13__ProcessAuthResponse::tag_impl::test_002__unk_auth_plugin_name
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 remote_fb::protocol::set02::P_CSTRING_CONST_V2 resp__AuthPluginName={};
 remote_fb::protocol::set02::P_CSTRING_CONST_V2 resp__AuthPluginData={};

 //-----------------------------------------
 const remote_fb::protocol::P_UCHAR auth_plugin_name[]={' ','a','b','c',' '};

 resp__AuthPluginName.cstr_length
  =sizeof(auth_plugin_name);

 resp__AuthPluginName.cstr_address
  =auth_plugin_name;

 //-----------------------------------------
 svc::dbprops_type cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2 clientConnectBlock(cn_params);

 remote_fb::plugins::auth::RemoteFB__Plugin_Auth_FactoryPtr
  spF(remote_fb::plugins::auth::legacy::RemoteFB__Plugin_Auth_Legacy_Factory::Create());

 _TSO_CHECK(spF);

 clientConnectBlock.RegAuthPluginFactory
  (spF);

 _TSO_CHECK(clientConnectBlock.SetCurrentAuthPlugin2(spF->get_name()));

 _TSO_CHECK(clientConnectBlock.GetCurrentAuthPlugin());

 self_type::helper__check_auth_plugin_name
  (clientConnectBlock.GetCurrentAuthPlugin(),
   L"Legacy_Auth");

 try
 {
  remote_fb::api::p13::RemoteFB__P13__ProcessAuthResponse::exec
   (clientConnectBlock,
    &resp__AuthPluginName,
    &resp__AuthPluginData);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok
   (tracer,exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__cn_err__unk_auth_service_name
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb,
    L" abc ");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_002__unk_auth_plugin_name

////////////////////////////////////////////////////////////////////////////////
//TEST 003

void TestsFor__RemoteFB__P13__ProcessAuthResponse::tag_impl::test_003__cycle_in_auth_plugin_reassign
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 remote_fb::protocol::set02::P_CSTRING_CONST_V2 resp__AuthPluginName={};
 remote_fb::protocol::set02::P_CSTRING_CONST_V2 resp__AuthPluginData={};

 //-----------------------------------------
 const remote_fb::protocol::P_UCHAR auth_plugin_name[]
  ={'L','e','g','a','c','y','_','A','u','t','h'};

 resp__AuthPluginName.cstr_length
  =sizeof(auth_plugin_name);

 resp__AuthPluginName.cstr_address
  =auth_plugin_name;

 //-----------------------------------------
 svc::dbprops_type cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2 clientConnectBlock(cn_params);

 //-----------------------------------------
 remote_fb::plugins::auth::RemoteFB__Plugin_Auth_FactoryPtr
  spF1(remote_fb::plugins::auth::legacy::RemoteFB__Plugin_Auth_Legacy_Factory::Create());

 _TSO_CHECK(spF1);

 clientConnectBlock.RegAuthPluginFactory
  (spF1);

 //-----------------------------------------
 remote_fb::plugins::auth::RemoteFB__Plugin_Auth_FactoryPtr
  spF2(remote_fb::plugins::auth::win_sspi::RemoteFB__Plugin_Auth_WinSSPI_Factory::Create());

 _TSO_CHECK(spF2);

 clientConnectBlock.RegAuthPluginFactory
  (spF2);

 //-----------------------------------------
 _TSO_CHECK(clientConnectBlock.SetCurrentAuthPlugin2(spF1->get_name()));

 _TSO_CHECK(clientConnectBlock.GetCurrentAuthPlugin());

 self_type::helper__check_auth_plugin_name
  (clientConnectBlock.GetCurrentAuthPlugin(),
   L"Legacy_Auth");

 //-----------------------------------------
 _TSO_CHECK(clientConnectBlock.SetCurrentAuthPlugin2(spF2->get_name()));

 _TSO_CHECK(clientConnectBlock.GetCurrentAuthPlugin());

 self_type::helper__check_auth_plugin_name
  (clientConnectBlock.GetCurrentAuthPlugin(),
   L"Win_Sspi");

 try
 {
  remote_fb::api::p13::RemoteFB__P13__ProcessAuthResponse::exec
   (clientConnectBlock,
    &resp__AuthPluginName,
    &resp__AuthPluginData);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok
   (tracer,exc);

  errSvc::check_err_count
   (exc,
    1);

  errSvc::check_err_rec__bug_check__auth_service_already_was_used
   (tracer,
    exc.get_record(0),
    L"RemoteFB__ClientConnectBlock_v2::SetCurrentAuthPlugin",
    L"#002",
    L"Legacy_Auth");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_003__cycle_in_auth_plugin_reassign

////////////////////////////////////////////////////////////////////////////////
//Helper methods

void TestsFor__RemoteFB__P13__ProcessAuthResponse::tag_impl::helper__check_auth_plugin_name
               (remote_fb::plugins::auth::RemoteFB__Plugin_Auth* const pAuthPlugin,
                const wchar_t*                                   const pName)
{
 _TSO_CHECK(pAuthPlugin);

 helper__check_auth_plugin_name(pAuthPlugin->get_name().data(),
                                pName);
}//helper__check_auth_plugin_name

//------------------------------------------------------------------------
void TestsFor__RemoteFB__P13__ProcessAuthResponse::tag_impl::helper__check_auth_plugin_name
               (const wchar_t* const pActualName,
                const wchar_t* const pExpectedName)
{
 bool eq=false;

 if(pActualName==nullptr)
  eq=(pExpectedName==nullptr);
 else
 if(pExpectedName==nullptr)
  eq=false;
 else
  eq=(wcscmp(pActualName,pExpectedName)==0);

 if(eq)
  return;

 structure::str_formatter fmsg("incorrect auth_plugin name.\n"
                               "Actual   : [%1].\n"
                               "Expected : [%2].");

 fmsg<<(pActualName?pActualName:L"#NULL")
     <<(pExpectedName?pExpectedName:L"#NULL");

 throw std::runtime_error(fmsg.str());
}//helper__check_auth_plugin_name

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__RemoteFB__P13__ProcessAuthResponse::tag_descr

struct TestsFor__RemoteFB__P13__ProcessAuthResponse::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class TestsFor__RemoteFB__P13__ProcessAuthResponse::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,TestsFor__RemoteFB__P13__ProcessAuthResponse::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const TestsFor__RemoteFB__P13__ProcessAuthResponse::tag_descr
 TestsFor__RemoteFB__P13__ProcessAuthResponse::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001.bugcheck__001",
   test_001__bugcheck_001)

 DEF_TEST_DESCR
  ("002.unk_auth_plugin_name",
   test_002__unk_auth_plugin_name)

 DEF_TEST_DESCR
  ("003.cycle_in_auth_plugin_reassign",
   test_003__cycle_in_auth_plugin_reassign)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__P13__ProcessAuthResponse

void TestsFor__RemoteFB__P13__ProcessAuthResponse::create
                                     (TTSO_PushTest*      const pTestPusher,
                                      TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter
  ftestID("RemoteFB.API.P13.ProcessAuthResponse.%1");


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
}/*nms ibp_tests*/}/*nms lcpi*/
