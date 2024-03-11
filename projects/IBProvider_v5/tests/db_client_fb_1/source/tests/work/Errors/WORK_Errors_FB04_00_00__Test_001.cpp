////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/Errors/WORK_Errors_FB04_00_00__Test_001.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/error_services/ibp_sqlstate_codes.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Errors_FB04_00_00__Test_001::tag_impl

class WORK_Errors_FB04_00_00__Test_001::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public: //---------------------------------------------------------------
  static void test_001__bad_timezone_region
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_002__bad_timezone_ID
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
};//class WORK_Errors_FB04_00_00__Test_001

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void WORK_Errors_FB04_00_00__Test_001::tag_impl::test_001__bad_timezone_region
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

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
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (remote_fb::protocol::P_SHORT)cns.db_dialect_Ex.value(),
   "insert into TEST_MODIFY_ROW (COL_TIMESTAMP_WITH_TZ) values ('2023-08-17 22:24:01.2345ZZZ');");

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtExecute
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     /*pInXSQLDA*/nullptr,
     /*pOutXSQLDA*/nullptr);
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

   errSvc::check_err_code
    (exc.com_code(),
     E_FAIL);

   errSvc::check_err_rec__srv_err__invalid_time_zone_region
    (tracer,
     errSvc::sm_srcID_wstr__Firebird,
     exc.get_record(0),
     L"ZZZ");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_001__bad_timezone_region

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void WORK_Errors_FB04_00_00__Test_001::tag_impl::test_002__bad_timezone_ID
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

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
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (remote_fb::protocol::P_SHORT)cns.db_dialect_Ex.value(),
   "insert into TEST_MODIFY_ROW (COL_INTEGER) values (EXTRACT(TIMEZONE_HOUR FROM CAST(? AS TIMESTAMP WITH TIME ZONE)));");

 //-----------------------------------------
 db_obj::t_dbvalue__fb040_timestamp_with_tz
  xvalue
   =db_obj::make_fb040_timestamp_with_tz(0,0,40013);

 XSQLDA_V1_Wrapper in_xsqlda(1);

 in_xsqlda->sqld=1;

 in_xsqlda->sqlvar[0].sqltype  =isc_api::ibp_fb040_sql_timestamp_with_tz;
 in_xsqlda->sqlvar[0].sqllen   =sizeof(xvalue);
 in_xsqlda->sqlvar[0].sqlscale =0;
 in_xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(&xvalue);
 in_xsqlda->sqlvar[0].sqlind   =nullptr;

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtExecute
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     /*pInXSQLDA*/in_xsqlda.ptr(),
     /*pOutXSQLDA*/nullptr);
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

   errSvc::check_err_code
    (exc.com_code(),
     E_FAIL);

   errSvc::check_err_rec__srv_err__invalid_time_zone_ID
    (tracer,
     errSvc::sm_srcID_wstr__Firebird,
     exc.get_record(0),
     40013);

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_002__bad_timezone_ID

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Errors_FB04_00_00__Test_001::tag_descr

struct WORK_Errors_FB04_00_00__Test_001::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Errors_FB04_00_00__Test_001::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Errors_FB04_00_00__Test_001::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Errors_FB04_00_00__Test_001::tag_descr
 WORK_Errors_FB04_00_00__Test_001::sm_Tests[]=
{
 DEF_TEST_DESCR2
  ("001.bad_timezone_region",
   test_001__bad_timezone_region,
   "SRV>=FB-4")

 DEF_TEST_DESCR2
  ("002.bad_timezone_ID",
   test_002__bad_timezone_ID,
   "SRV>=FB-4")
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Errors_FB04_00_00__Test_001

void WORK_Errors_FB04_00_00__Test_001::create
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
 structure::str_formatter
  ftestID("RemoteFB.WORK.Errors.FB_04_0_0.001.ptype__%1.%2");

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

  const TTSO_TestPtr spTest
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
