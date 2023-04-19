////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_033__GetDatabaseInfo.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_033__GetDatabaseInfo::tag_impl

class WORK_Test_033__GetDatabaseInfo::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
 #ifdef NDEBUG
  static void test_001__bug_check__bad_cn
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 #endif

  static void test_002__err__hack_close_cn
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_003__err__no_tags
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_004__end_tag_only
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_GetDatabaseInfo_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_033__GetDatabaseInfo::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void WORK_Test_033__GetDatabaseInfo::tag_impl::test_001__bug_check__bad_cn
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

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

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 //-----------------------------------------
 for(;;)
 {
  const remote_fb::protocol::P_UCHAR tags[]={isc_api::ibp_isc_info_end};

  remote_fb::RemoteFB__InfoBuffer infoBuf;

  try
  {
   svc::RemoteFB_Connector__GetDatabaseInfo(tracer,
                                            spConnector,
                                            /*Incornation*/0,
                                            _DIM_(tags),
                                            tags,
                                            infoBuf); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__cn_err__bug_check__bad_cn_handle
    (tracer,
     exc.get_record(0),
     helper__get_GetDatabaseInfo_bugcheck_src(spConnector),
     L"#001");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_001__bug_check__bad_cn

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void WORK_Test_033__GetDatabaseInfo::tag_impl::test_002__err__hack_close_cn
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

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

 svc::HACK__DetachCn
  (tracer,
   spConnector);

 //-----------------------------------------
 for(;;)
 {
  const remote_fb::protocol::P_UCHAR tags[]={isc_api::ibp_isc_info_end};

  remote_fb::RemoteFB__InfoBuffer infoBuf;

  try
  {
   svc::RemoteFB_Connector__GetDatabaseInfo(tracer,
                                            spConnector,
                                            /*Incornation*/0,
                                            _DIM_(tags),
                                            tags,
                                            infoBuf); //throw!
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
}//test_002__err__hack_close_cn

////////////////////////////////////////////////////////////////////////////////
//TEST 003

void WORK_Test_033__GetDatabaseInfo::tag_impl::test_003__err__no_tags
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

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
 for(;;)
 {
  remote_fb::RemoteFB__InfoBuffer infoBuf;

  try
  {
   svc::RemoteFB_Connector__GetDatabaseInfo(tracer,
                                            spConnector,
                                            /*Incornation*/0,
                                            0,
                                            nullptr,
                                            infoBuf); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__srv_err__incorrect_params_to_internal_func_INF_database_info
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_003__err__no_tags

////////////////////////////////////////////////////////////////////////////////
//TEST 004

void WORK_Test_033__GetDatabaseInfo::tag_impl::test_004__end_tag_only
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

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

 {
  const remote_fb::protocol::P_UCHAR tags[]={isc_api::ibp_isc_info_end};

  remote_fb::RemoteFB__InfoBuffer infoBuf;

  svc::RemoteFB_Connector__GetDatabaseInfo(tracer,
                                           spConnector,
                                           /*Incornation*/0,
                                           _DIM_(tags),
                                           tags,
                                           infoBuf); //throw!

  _TSO_CHECK(infoBuf.size()==1);

  _TSO_CHECK(infoBuf[0]==isc_api::ibp_isc_info_end);
 }//local

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_004__end_tag_only

////////////////////////////////////////////////////////////////////////////////

const wchar_t* WORK_Test_033__GetDatabaseInfo::tag_impl::helper__get_GetDatabaseInfo_bugcheck_src
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
   return L"RemoteFB__API_P12__GetDatabaseInfo::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__GetDatabaseInfo::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_GetDatabaseInfo_bugcheck_src

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_033__GetDatabaseInfo::tag_descr

struct WORK_Test_033__GetDatabaseInfo::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class WORK_Test_033__GetDatabaseInfo::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,WORK_Test_033__GetDatabaseInfo::tag_impl::func},

const WORK_Test_033__GetDatabaseInfo::tag_descr
 WORK_Test_033__GetDatabaseInfo::sm_Tests[]=
{
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("001.bug_check.bad_cn",
   test_001__bug_check__bad_cn)
#endif

 DEF_TEST_DESCR
  ("002.err.hack_close_cn",
   test_002__err__hack_close_cn)

 DEF_TEST_DESCR
  ("003.err.no_tags",
   test_003__err__no_tags)

 DEF_TEST_DESCR
  ("004.end_tag_only",
   test_004__end_tag_only)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_033__GetDatabaseInfo

void WORK_Test_033__GetDatabaseInfo::create(TTSO_PushTest*      const pTestPusher,
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
 structure::str_formatter ftestID("RemoteFB.WORK.033.GetDatabaseInfo.ptype__%1.%2");

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
         Data)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
