////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_008__CommitRetaining.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_008__CommitRetaining::tag_impl

class WORK_Test_008__CommitRetaining::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

#ifdef NDEBUG
 public:
  static void test_002__bug_check__zero_tr_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_003__bug_check__bad_tr_owner
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
#endif

 public:
  static void test_005__err__bad_tr_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_CommitRetaining_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_008__CommitRetaining::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void WORK_Test_008__CommitRetaining::tag_impl::test_001
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 svc::remote_fb_tr_handle_type tr_handle(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &tr_handle);

 _TSO_CHECK(tr_handle!=nullptr);

 //-----------------------------------------
 for(size_t n=1;n!=3;++n)
 {
  svc::RemoteFB_Connector__CommitRetaining
   (tracer,
    spConnector,
    &tr_handle);

  _TSO_CHECK(tr_handle!=nullptr);
 }//for n

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &tr_handle);

 _TSO_CHECK(tr_handle==nullptr);
}//test_001

////////////////////////////////////////////////////////////////////////////////
//TEST 002

#ifdef NDEBUG

void WORK_Test_008__CommitRetaining::tag_impl::test_002__bug_check__zero_tr_handle
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 svc::remote_fb_tr_handle_type tr_handle(nullptr);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__CommitRetaining
    (tracer,
     spConnector,
     &tr_handle);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,
                           1);

   errSvc::check_err_rec__tr_err__bug_check__bad_tr_handle
    (tracer,
     exc.get_record(0),
     helper__get_CommitRetaining_bugcheck_src(spConnector),
     L"#001");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(tr_handle==nullptr);
}//test_002__bug_check__zero_tr_handle

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void WORK_Test_008__CommitRetaining::tag_impl::test_003__bug_check__bad_tr_owner
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns1;

 const svc::remote_fb_connector_ptr
  spConnector1
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns1));

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns2;

 const svc::remote_fb_connector_ptr
  spConnector2
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns2));

 //-----------------------------------------
 svc::remote_fb_tr_handle_type tr_handle1(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector1,
   &tr_handle1);

 _TSO_CHECK(tr_handle1!=nullptr);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__CommitRetaining
    (tracer,
     spConnector2,
     &tr_handle1);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,
                           1);

   errSvc::check_err_rec__tr_err__bug_check__bad_tr_handle
    (tracer,
     exc.get_record(0),
     helper__get_CommitRetaining_bugcheck_src(spConnector1),
     L"#003");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(tr_handle1!=nullptr);

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector1,
   &tr_handle1);

 _TSO_CHECK(tr_handle1==nullptr);
}//test_003__bug_check__bad_tr_owner

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 005

void WORK_Test_008__CommitRetaining::tag_impl::test_005__err__bad_tr_handle
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns;

 const svc::remote_fb_connector_ptr
  spConnector
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns));

 //-----------------------------------------
 svc::remote_fb_tr_handle_type tr_handle(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &tr_handle);

 _TSO_CHECK(tr_handle!=nullptr);

 _TSO_CHECK(tr_handle->m_ID.has_value());

 //-----------------------------------------
 svc::HACK__CommitTr
  (tracer,
   spConnector,
   &tr_handle);

 //-----------------------------------------
 try
 {
  svc::RemoteFB_Connector__CommitRetaining
   (tracer,
    spConnector,
    &tr_handle);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,
                          1);

  errSvc::check_err_rec__srv_err__bad_tr_handle
   (tracer,
    spConnector->GetData()->m_DBMS_Name,
    exc.get_record(0));

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_005__err__bad_tr_handle

////////////////////////////////////////////////////////////////////////////////

const wchar_t* WORK_Test_008__CommitRetaining::tag_impl::helper__get_CommitRetaining_bugcheck_src
                                           (remote_fb::RemoteFB__Connector* const pConnector)
{
 assert(pConnector);

 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 switch(const auto v=pConnector->GetPort()->get_protocol_version())
 {
  case remote_fb::protocol::FB_PROTOCOL_VERSION10:
  case remote_fb::protocol::FB_PROTOCOL_VERSION11:
  case remote_fb::protocol::FB_PROTOCOL_VERSION12:
   return L"RemoteFB__API_P12__CommitRetaining::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__CommitRetaining::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_CommitRetaining_bugcheck_src

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_008__CommitRetaining::tag_descr

struct WORK_Test_008__CommitRetaining::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_008__CommitRetaining::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_008__CommitRetaining::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_008__CommitRetaining::tag_descr
 WORK_Test_008__CommitRetaining::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001",
   test_001)

#ifdef NDEBUG
 DEF_TEST_DESCR
  ("002.bug_check.zero_tr_handle",
   test_002__bug_check__zero_tr_handle)

 DEF_TEST_DESCR
  ("003.bug_check.bad_tr_owner",
   test_003__bug_check__bad_tr_owner)
#endif

 DEF_TEST_DESCR
  ("005.err.bad_tr_handle",
   test_005__err__bad_tr_handle)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_008__CommitRetaining

void WORK_Test_008__CommitRetaining::create(TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                               //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);     //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter ftestID("RemoteFB.WORK.008.Trans.CommitRetaining.ptype__%1.%2");

 TTSO_TestData_v2 Data;

 for(;it;++it)
 {
  assert(it[iTest]<_DIM_(sm_Tests));
  assert(it[iPType]<_DIM_(g_TestCfg__RemoteFB__ProtocolTypes));

  //----------------------------------------
  Data.m_RemoteFB__ProtocolType
   =g_TestCfg__RemoteFB__ProtocolTypes[it[iPType]];

  ftestID
   <<structure::flush
   <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value())
   <<sm_Tests[it[iTest]].pTestSign;

  const TTSO_TestPtr
   spTest
    (lib::structure::not_null_ptr
      (new TTSO_TestFunc_v2
        (pParams,
         ftestID.c_str(),
         sm_Tests[it[iTest]].Func,
         Data,
         sm_Tests[it[iTest]].pExecRules)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
