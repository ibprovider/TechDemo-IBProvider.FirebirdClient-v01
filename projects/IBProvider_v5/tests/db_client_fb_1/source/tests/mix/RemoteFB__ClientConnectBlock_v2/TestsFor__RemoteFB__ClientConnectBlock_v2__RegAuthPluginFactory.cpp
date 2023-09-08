////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/mix/RemoteFB__ClientConnectBlock_v2/TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/db_client/remote_fb/plugins/auth/legacy/remote_fb__plugin_auth_legacy_factory.h"
#include "source/db_client/remote_fb/remote_fb__client_connect_block_v2.h"
#include <structure/test_obj/t_tso_user.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_impl

class TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

  typedef signed long                       target_type;

 public:
  static void test_01__multiple_registration
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_02__incorrect_auth_service_name
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 private:
  class tag_factory_02;

  struct tag_data_02;

  static tag_data_02 const sm_data_02[];
};//class TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_impl

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_impl::tag_factory_02

class TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_impl::tag_factory_02
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(remote_fb::plugins::auth::RemoteFB__Plugin_Auth_Factory)
{
 private:
  typedef tag_factory_02                    self_type;

  tag_factory_02(const self_type&);
  self_type& operator = (const self_type&);

 public:
  tag_factory_02(const wchar_t* pwszName)
   :m_wstrName(name_type::create<TTSO_MemoryAllocator>(pwszName))
  {;}

  //factory interface ----------------------------------------------------
  virtual name_type get_name()const COMP_W000004_OVERRIDE_FINAL
  {
   return m_wstrName;
  }//get_name

  virtual remote_fb::plugins::auth::RemoteFB__Plugin_AuthPtr create_plugin()const COMP_W000004_OVERRIDE_FINAL
  {
   assert(false);

   throw std::runtime_error("TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_impl::tag_factory_02::create_plugin - not implemented");
  }//create_plugin

 private:
  const name_type m_wstrName;
};//class TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_impl::tag_factory_02

////////////////////////////////////////////////////////////////////////////////
//TEST 01

void TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_impl::test_01__multiple_registration
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 clientConnectBlock.RegAuthPluginFactory
  (remote_fb::plugins::auth::legacy::RemoteFB__Plugin_Auth_Legacy_Factory::Create());

 try
 {
  clientConnectBlock.RegAuthPluginFactory
   (remote_fb::plugins::auth::legacy::RemoteFB__Plugin_Auth_Legacy_Factory::Create());
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

  errSvc::check_err_rec__bug_check__auth_service_factory_already_was_registered
   (tracer,
    exc.get_record(0),
    L"RemoteFB__ClientConnectBlock_v2::RegAuthPluginFactory",
    L"#001",
    L"Legacy_Auth");

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_01__multiple_registration

////////////////////////////////////////////////////////////////////////////////
//TEST 02

struct TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_impl::tag_data_02
{
 const wchar_t* name;
};//tag_data_02

//------------------------------------------------------------------------
TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_impl::tag_data_02
 const TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_impl::sm_data_02[]=
{
 {L" "},
 {L"\r"},
 {L"\n"},
 {L"aaa,vvv"},
 {L"aaa;ccc"},
 {L"aaa\t"},
#if NDEBUG
 {L""},
#endif
};//sm_data_02

//------------------------------------------------------------------------
void TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_impl::test_02__incorrect_auth_service_name
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 TestCnParams cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 for(size_t i=0;i!=_DIM_(sm_data_02);++i)
 {
  tracer<<L"--------------------------------- "<<i<<L"."<<send;

  tag_factory_02 f(sm_data_02[i].name);

  try
  {
   clientConnectBlock.RegAuthPluginFactory(&f);//throw
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

   errSvc::check_err_rec__cn_err__incorrect_auth_service_name
    (tracer,
     exc.get_record(0),
     errSvc::sm_subsysID__remote_fb,
     sm_data_02[i].name);

   continue;
  }//catch

  tracer(tso_msg_error,-1)
   <<L"We wait the error!"
   <<send;
 }//for i
}//test_02__incorrect_auth_service_name

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_descr

struct TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_impl::func},

const TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::tag_descr
 TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::sm_Tests[]=
{
 DEF_TEST_DESCR("01.multiple_registration",
                test_01__multiple_registration)

 DEF_TEST_DESCR("02.incorrect_auth_service_name",
                test_02__incorrect_auth_service_name)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory

void TestsFor__RemoteFB__ClientConnectBlock_v2__RegAuthPluginFactory::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter
  ftestID("RemoteFB.mix.RemoteFB__ClientConnectBlock_v2.RegAuthPluginFactory.%1");

 for(const tag_descr& d : sm_Tests)
 {
  ftestID<<structure::flush
         <<d.pTestSign;

  const TTSO_TestPtr spTest(new TTSO_TestFunc(pParams,
                                              ftestID.c_str(),
                                              d.Func));
  pTestPusher->PushTest(spTest);
 }//for d
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
