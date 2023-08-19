////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_010__DetachDatabase.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_010__DetachDatabase::tag_impl

class WORK_Test_010__DetachDatabase::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_002__err__bad_cn_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

#ifdef NDEBUG
 public:
  static void test_003__bug_check__bad_cn_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
#endif

 public:
  static void test_004__err__has_active_tr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_005__err__has_prep_tr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_DetachDb_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_010__DetachDatabase

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void WORK_Test_010__DetachDatabase::tag_impl::test_001
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
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_001

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void WORK_Test_010__DetachDatabase::tag_impl::test_002__err__bad_cn_handle
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

 _TSO_CHECK(spConnector->GetPort()->m_ID.has_value());

 //-----------------------------------------
 //Выполняем операцию отключения от базы данных минуя конектор

 svc::HACK__DetachCn
  (tracer,
   spConnector);

 //-----------------------------------------
 try
 {
  svc::RemoteFB_Connector__DetachDatabase
   (tracer,
    spConnector);
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

  errSvc::check_err_rec__srv_err__bad_cn_handle
   (tracer,
    spConnector->GetData()->m_DBMS_Name,
    exc.get_record(0));

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_002__err__bad_cn_handle

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void WORK_Test_010__DetachDatabase::tag_impl::test_003__bug_check__bad_cn_handle
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
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 //-----------------------------------------
 try
 {
  svc::RemoteFB_Connector__DetachDatabase
   (tracer,
    spConnector);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,
                           1);

  errSvc::check_err_rec__cn_err__bug_check__bad_cn_handle
                                           (tracer,
                                            exc.get_record(0),
                                            helper__get_DetachDb_bugcheck_src(spConnector),
                                            L"#001");
  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_003__bug_check__bad_cn_handle

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 004

void WORK_Test_010__DetachDatabase::tag_impl::test_004__err__has_active_tr
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
 svc::remote_fb_tr_handle_type tr_handle1(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &tr_handle1);

 //-----------------------------------------
 svc::remote_fb_tr_handle_type tr_handle2(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &tr_handle2);

 //-----------------------------------------
 try
 {
  svc::RemoteFB_Connector__DetachDatabase
   (tracer,
    spConnector);
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

  errSvc::check_err_rec__srv_err__failed_to_detach__has_active_tr
   (tracer,
    exc.get_record(0),
    spConnector->GetData()->m_DBMS_Name,
    2);

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_004__err__has_active_tr

////////////////////////////////////////////////////////////////////////////////
//TEST 005

void WORK_Test_010__DetachDatabase::tag_impl::test_005__err__has_prep_tr
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
 svc::remote_fb_tr_handle_type tr_handle1(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &tr_handle1);

 svc::RemoteFB_Connector__PrepareTransaction
  (tracer,
   spConnector,
   &tr_handle1,
   0,
   nullptr);

 //-----------------------------------------
 try
 {
  svc::RemoteFB_Connector__DetachDatabase
   (tracer,
    spConnector);
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

  errSvc::check_err_rec__srv_err__failed_to_detach__has_active_tr
   (tracer,
    exc.get_record(0),
    spConnector->GetData()->m_DBMS_Name,
    1);

  return;
 }//catch

 tracer(tso_msg_warning,-1)<<L"We wait the error!"<<send;
}//test_004__err__has_prep_tr

////////////////////////////////////////////////////////////////////////////////

const wchar_t* WORK_Test_010__DetachDatabase::tag_impl::helper__get_DetachDb_bugcheck_src
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
   return L"RemoteFB__API_P12__DetachDatabase::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__DetachDatabase::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_DetachDb_bugcheck_src

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_010__DetachDatabase::tag_descr

struct WORK_Test_010__DetachDatabase::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_010__DetachDatabase::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_010__DetachDatabase::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_010__DetachDatabase::tag_descr
 WORK_Test_010__DetachDatabase::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001",
   test_001)

 DEF_TEST_DESCR
  ("002.err.bad_cn_handle",
   test_002__err__bad_cn_handle)

#ifdef NDEBUG
 DEF_TEST_DESCR
  ("003.bug_check.bad_cn_handle",
   test_003__bug_check__bad_cn_handle)
#endif

 DEF_TEST_DESCR
  ("004.err.has_active_tr",
   test_004__err__has_active_tr)

 DEF_TEST_DESCR
  ("005.err.has_prep_tr",
   test_005__err__has_prep_tr)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_010__DetachDatabase

void WORK_Test_010__DetachDatabase::create(TTSO_PushTest*      const pTestPusher,
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
 structure::str_formatter ftestID("RemoteFB.WORK.010.DetachDatabase.ptype__%1.%2");

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
    (structure::not_null_ptr
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
}//namespace ibp_test
