////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_004__StartTransaction__v1.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_004__StartTransaction__v1::tag_impl

class WORK_Test_004__StartTransaction__v1::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001__no_params
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

#ifdef NDEBUG
 public:
  static void test_002__bug_check__tr_handle_not_zero
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
#endif

 public:
  static void test_003__err__too_large_tpb
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_004__err__bad_tpb_ver
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_005__err__bad_tpb
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_006__err__no_cn
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_StartTr_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_004__StartTransaction__v1::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void WORK_Test_004__StartTransaction__v1::tag_impl::test_001__no_params
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
}//test_001__no_params

////////////////////////////////////////////////////////////////////////////////
//TEST 002

#ifdef NDEBUG

void WORK_Test_004__StartTransaction__v1::tag_impl::test_002__bug_check__tr_handle_not_zero
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

 const svc::remote_fb_tr_handle_type tr_handle2=tr_handle;

 _TSO_CHECK(tr_handle!=nullptr);
 _TSO_CHECK(tr_handle2!=nullptr);

 _TSO_CHECK(tr_handle==tr_handle2);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StartTransaction
    (tracer,
     spConnector,
     &tr_handle);

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

   errSvc::check_err_rec__tr_err__bug_check__tr_handle_not_zero
    (tracer,
     exc.get_record(0),
     helper__get_StartTr_bugcheck_src(spConnector),
     L"#002");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(tr_handle==tr_handle2);
}//test_002__bug_check__tr_handle_not_zero

#endif

/////////////////////////////////////////////////////////////////////////////////
//TEST 003

void WORK_Test_004__StartTransaction__v1::tag_impl::test_003__err__too_large_tpb
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
 const structure::t_typed_simple_buffer
         <unsigned char,TTSO_MemoryAllocator>  tpb(1024*1024);

 svc::remote_fb_tr_handle_type tr_handle(nullptr);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StartTransaction
    (tracer,
     spConnector,
     &tr_handle,
     tpb.size(),
     tpb.buffer());
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

   errSvc::check_err_rec__common_err__formed_buf_is_too_large
    (tracer,
     exc.get_record(0),
     errSvc::sm_subsysID__remote_fb_p12,
     L"TPB",
     tpb.size(),
     structure::t_numeric_limits<unsigned short>::max_value());

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(tr_handle==nullptr);
}//test_003__err__too_large_tpb

/////////////////////////////////////////////////////////////////////////////////
//TEST 004

void WORK_Test_004__StartTransaction__v1::tag_impl::test_004__err__bad_tpb_ver
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
 const unsigned char tpb[16]={0};

 svc::remote_fb_tr_handle_type tr_handle(nullptr);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StartTransaction
    (tracer,
     spConnector,
     &tr_handle,
     _DIM_(tpb),
     tpb);
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

   errSvc::check_err_rec__srv_err__bad_tpb_ver
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(tr_handle==nullptr);
}//test_004__err__bad_tpb_ver

/////////////////////////////////////////////////////////////////////////////////
//TEST 005

void WORK_Test_004__StartTransaction__v1::tag_impl::test_005__err__bad_tpb
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
 const unsigned char tpb[]={isc_api::ibp_isc_tpb_version3,255};

 svc::remote_fb_tr_handle_type tr_handle(nullptr);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StartTransaction
    (tracer,
     spConnector,
     &tr_handle,
     _DIM_(tpb),
     tpb);
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

   errSvc::check_err_rec__srv_err__bad_tpb
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(tr_handle==nullptr);
}//test_005__err__bad_tpb

////////////////////////////////////////////////////////////////////////////////
//TEST 006

void WORK_Test_004__StartTransaction__v1::tag_impl::test_006__err__no_cn
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
 //Выполняем операцию отключения от базы данных минуя конектор

 svc::HACK__DetachCn
  (tracer,
   spConnector);

 //-----------------------------------------
 svc::remote_fb_tr_handle_type tr_handle(nullptr);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StartTransaction
    (tracer,
     spConnector,
     &tr_handle);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__srv_err__bad_cn_handle
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(tr_handle==nullptr);
}//test_006__err__no_cn

////////////////////////////////////////////////////////////////////////////////

const wchar_t* WORK_Test_004__StartTransaction__v1::tag_impl::helper__get_StartTr_bugcheck_src
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
   return L"RemoteFB__API_P12__StartTransaction::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__StartTransaction::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_StartTr_bugcheck_src

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_004__StartTransaction__v1::tag_descr

struct WORK_Test_004__StartTransaction__v1::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_004__StartTransaction__v1::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_004__StartTransaction__v1::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_004__StartTransaction__v1::tag_descr
 WORK_Test_004__StartTransaction__v1::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001.no_params",
   test_001__no_params)

#ifdef NDEBUG
 DEF_TEST_DESCR
  ("002.bug_check.tr_handle_not_zero",
   test_002__bug_check__tr_handle_not_zero)
#endif

 DEF_TEST_DESCR2
  ("003.err.too_large_tpb",
   test_003__err__too_large_tpb,
   "SRV<FB-3")

 DEF_TEST_DESCR
  ("004.err.bad_tpb_ver",
   test_004__err__bad_tpb_ver)

 DEF_TEST_DESCR
  ("005.err.bad_tpb",
   test_005__err__bad_tpb)

 DEF_TEST_DESCR
  ("006.err.no_cn",
   test_006__err__no_cn)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_004__StartTransaction__v1

void WORK_Test_004__StartTransaction__v1::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                              //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);    //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter ftestID("RemoteFB.WORK.004.Trans.StartTransaction.v1.ptype__%1.%2");

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
