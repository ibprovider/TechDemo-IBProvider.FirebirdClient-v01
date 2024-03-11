////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_019__StmtExecute__v2_lazy_send.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__encoder.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/error_services/ibp_sqlstate_codes.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl

class WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
 #ifdef NDEBUG
  static void test_001__bug_check__zero_stmt_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_002__bug_check__null_stmt_id
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_003__bug_check__bad_owner_cn
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_004__bug_check__bad_owner_cn_of_tr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_005__bug_check__bad_tr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 #endif

 public: //---------------------------------------------------------------
 #ifdef NDEBUG
  static void test_013__bug_check__incorrect_input_version
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_014__bug_check__incorrect_output_version
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 #endif

 public:
 #ifdef NDEBUG
  static void test_017__err__exec_defer_exec_without_tr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 #endif

 public:
  static void test_018__defer_exec_and_commit
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_019__defer_exec_and_rollback
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_020__defer_exec_and_sql_commit
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_021__defer_exec_and_sql_rollback
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_022__check_drop_stmts_before_exec
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_030__close_and_execute
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_030__close_and_execute__err__hack_unprep_stmt
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_030__close_and_execute__err__hack_unprep_stmt__fb3
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_031__close_and_execute2
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_StmtExec_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);

  static const wchar_t* helper__get_StmtExec_subsystem_id
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_001__bug_check__zero_stmt_handle
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
 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   svc::remote_fb_tr_handle_type hTr(nullptr);
   svc::remote_fb_stmt_handle_type hStmt(nullptr);

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

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_bugcheck_src(spConnector),
     L"#003");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_001__bug_check__zero_stmt_handle

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 002

#ifdef NDEBUG

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_002__bug_check__null_stmt_id
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
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt==nullptr);


 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtExecute
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmtCopy,
     /*pInXSQLDA*/nullptr,
     /*pOutXSQLDA*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_bugcheck_src(spConnector),
     L"#004");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_002__bug_check__null_stmt_id

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_003__bug_check__bad_owner_cn
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
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);
 _TSO_CHECK(hStmt->m_ID.is_defer());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns2;

 const svc::remote_fb_connector_ptr
  spConnector2
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns2));

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtExecute
    (tracer,
     spConnector2,
     OpCtx,
     &hTr,
     &hStmt,
     /*pInXSQLDA*/nullptr,
     /*pOutXSQLDA*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_bugcheck_src(spConnector),
     L"#005");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

}//test_003__bug_check__bad_owner_cn

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 004

#ifdef NDEBUG

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_004__bug_check__bad_owner_cn_of_tr
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
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns2;

 const svc::remote_fb_connector_ptr
  spConnector2
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns2));

 //-----------------------------------------
 TestOperationContext OpCtx2(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt2(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector2,
   &hStmt2);

 _TSO_CHECK(hStmt2!=nullptr);

 _TSO_CHECK(hStmt2->m_pParentPort==spConnector2->GetPort());

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtExecute
    (tracer,
     spConnector2,
     OpCtx2,
     &hTr,
     &hStmt2,
     /*pInXSQLDA*/nullptr,
     /*pOutXSQLDA*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__tr_err__bug_check__bad_tr_handle
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_bugcheck_src(spConnector),
     L"#002");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

}//test_004__bug_check__bad_owner_cn_of_tr

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 005

#ifdef NDEBUG

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_005__bug_check__bad_tr
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
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr_copy(hTr);

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr_copy);

 _TSO_CHECK(!hTr_copy);

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

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__tr_err__bug_check__bad_tr_handle
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_bugcheck_src(spConnector),
     L"#001");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

}//test_005__bug_check__bad_tr

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 013

#ifdef NDEBUG

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_013__bug_check__incorrect_input_version
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
   "insert into TEST_MODIFY_ROW (COL_INTEGER) values (?);");

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(/*n*/1);

 db_obj::t_dbvalue__i4   columnValue=0;
 short                   columnInd=0;

 xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
 xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqlsubtype =0;
 xsqlda->sqlvar[0].sqlscale   =0;
 xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&columnValue);
 xsqlda->sqlvar[0].sqlind     =&columnInd;

 xsqlda->sqld=1;

 //-----------------------------------------
 const short bad_versions[]={-2,-1,0,2,3};

 for(size_t i=0;i!=_DIM_(bad_versions);++i)
 {
  xsqlda->version=bad_versions[i];

  try
  {
   svc::RemoteFB_Connector__StmtExecute
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     /*pInXSQLDA*/xsqlda,
     /*pOutXSQLDA*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_code(exc.com_code(),E_FAIL);

   errSvc::check_err_rec__xsqlda_err__incorrect_version
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Check_XSQLDA",
     L"#001",
     L"pInXSQLDA",
     bad_versions[i]);

   continue;
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
}//test_013__bug_check__incorrect_input_version

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 014

#ifdef NDEBUG

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_014__bug_check__incorrect_output_version
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
   "insert into TEST_MODIFY_ROW (COL_INTEGER) values (0) returning COL_INTEGER;");

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(/*n*/1);

 db_obj::t_dbvalue__i4   columnValue=0;
 short                   columnInd=0;

 xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
 xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqlsubtype =0;
 xsqlda->sqlvar[0].sqlscale   =0;
 xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&columnValue);
 xsqlda->sqlvar[0].sqlind     =&columnInd;

 xsqlda->sqld=1;

 //-----------------------------------------
 const short bad_versions[]={-2,-1,0,2,3};

 for(size_t i=0;i!=_DIM_(bad_versions);++i)
 {
  xsqlda->version=bad_versions[i];

  try
  {
   svc::RemoteFB_Connector__StmtExecute
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     /*pInXSQLDA*/nullptr,
     /*pOutXSQLDA*/xsqlda);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_code(exc.com_code(),E_FAIL);

   errSvc::check_err_rec__xsqlda_err__incorrect_version
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Check_XSQLDA",
     L"#001",
     L"pOutXSQLDA",
     bad_versions[i]);

   continue;
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
}//test_014__bug_check__incorrect_output_version

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 017

#ifdef NDEBUG

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_017__err__exec_defer_exec_without_tr
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);

 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 for(;;)
 {
  try
  {
   svc::remote_fb_tr_handle_type null_hTr;

   svc::RemoteFB_Connector__StmtExecute
    (tracer,
     spConnector,
     OpCtx,
     &null_hTr,
     &hStmt,
     /*IN*/nullptr,
     /*OUT*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__defer_exec_stmt_requires_tr_context
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_subsystem_id(spConnector));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_017__err__exec_defer_exec_without_tr

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 018

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_018__defer_exec_and_commit
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);

 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));
 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*IN*/nullptr,
   /*OUT*/nullptr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));

 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr);
 _TSO_CHECK(!hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));

 _TSO_CHECK(!hStmt->m_pClosingTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_018__defer_exec_and_commit

////////////////////////////////////////////////////////////////////////////////
//019

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_019__defer_exec_and_rollback
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);

 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));
 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*IN*/nullptr,
   /*OUT*/nullptr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));

 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 //-----------------------------------------
 svc::RemoteFB_Connector__Rollback
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr);
 _TSO_CHECK(!hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));

 _TSO_CHECK(!hStmt->m_pClosingTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_019__defer_exec_and_rollback

////////////////////////////////////////////////////////////////////////////////
//020

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_020__defer_exec_and_sql_commit
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hTrStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hTrStmt);

 _TSO_CHECK(hTrStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hTrStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "commit");

 _TSO_CHECK(hTrStmt);
 _TSO_CHECK(hTrStmt->m_PFlags.test(hTrStmt->PFLAG__PREPARED));
 _TSO_CHECK(!hTrStmt->m_PFlags.test(hTrStmt->PFLAG__DEFER_EXECUTE));
 _TSO_CHECK(hTrStmt->m_EFlags.equal(0));

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));
 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*IN*/nullptr,
   /*OUT*/nullptr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));

 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hTrStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 _TSO_CHECK(!hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr);
 _TSO_CHECK(!hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));

 _TSO_CHECK(!hStmt->m_pClosingTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hTrStmt);

 _TSO_CHECK(!hTrStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_020__defer_exec_and_sql_commit

////////////////////////////////////////////////////////////////////////////////
//021

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_021__defer_exec_and_sql_rollback
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hTrStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hTrStmt);

 _TSO_CHECK(hTrStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hTrStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "rollback");

 _TSO_CHECK(hTrStmt);
 _TSO_CHECK(hTrStmt->m_PFlags.test(hTrStmt->PFLAG__PREPARED));
 _TSO_CHECK(!hTrStmt->m_PFlags.test(hTrStmt->PFLAG__DEFER_EXECUTE));
 _TSO_CHECK(hTrStmt->m_EFlags.equal(0));

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));
 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*IN*/nullptr,
   /*OUT*/nullptr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));

 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hTrStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 _TSO_CHECK(!hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr);
 _TSO_CHECK(!hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));

 _TSO_CHECK(!hStmt->m_pClosingTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hTrStmt);

 _TSO_CHECK(!hTrStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_021__defer_exec_and_sql_rollback

////////////////////////////////////////////////////////////////////////////////
//022

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_022__check_drop_stmts_before_exec
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 svc::remote_fb_tr_handle_type hTr(nullptr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt1(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt1);

 _TSO_CHECK(hStmt1);
 _TSO_CHECK(hStmt1->m_ID.is_defer());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt1,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "set transaction");

 _TSO_CHECK(!hTr);
 _TSO_CHECK(hStmt1->m_ID.has_value());
 _TSO_CHECK(hStmt1->m_PFlags.test(hStmt1->PFLAG__PREPARED))
 _TSO_CHECK(!hStmt1->m_PFlags.test(hStmt1->PFLAG__DEFER_EXECUTE))

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt1,
   /*IN*/nullptr,
   /*OUT*/nullptr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hStmt1->m_ID.has_value());
 _TSO_CHECK(hStmt1->m_PFlags.test(hStmt1->PFLAG__PREPARED))
 _TSO_CHECK(!hStmt1->m_PFlags.test(hStmt1->PFLAG__DEFER_EXECUTE))

 _TSO_CHECK(hStmt1->m_pParentTr);
 _TSO_CHECK(hStmt1->m_pParentTr==hTr);

 _TSO_CHECK(hStmt1->m_EFlags.equal(0));

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt2(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt2);

 _TSO_CHECK(hStmt2);
 _TSO_CHECK(spConnector->GetData()->DeletedStmtList__GetCount()==0);
 _TSO_CHECK(!spConnector->GetData()->DeletedStmtList__GetHead());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt2,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL");

 _TSO_CHECK(hStmt2);
 _TSO_CHECK(hStmt2->m_PFlags.test(hStmt2->PFLAG__PREPARED));
 _TSO_CHECK(hStmt2->m_PFlags.test(hStmt2->PFLAG__DEFER_EXECUTE));
 _TSO_CHECK(hStmt2->m_EFlags.equal(0));

 _TSO_CHECK(spConnector->GetData()->DeletedStmtList__GetCount()==0);
 _TSO_CHECK(!spConnector->GetData()->DeletedStmtList__GetHead());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt1);

 _TSO_CHECK(!hStmt1);
 _TSO_CHECK(spConnector->GetData()->DeletedStmtList__GetCount()==1);
 _TSO_CHECK(spConnector->GetData()->DeletedStmtList__GetHead());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt2,
   /*IN*/nullptr,
   /*OUT*/nullptr);

 _TSO_CHECK(hStmt2);
 _TSO_CHECK(hStmt2->m_PFlags.test(hStmt2->PFLAG__PREPARED));
 _TSO_CHECK(hStmt2->m_PFlags.test(hStmt2->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt2->m_pParentTr==hTr);
 _TSO_CHECK(hStmt2->m_EFlags.test(hStmt2->EFLAG__EXECUTION_WAS_DEFERRED));

 _TSO_CHECK(hStmt2->m_pClosingTr==nullptr);

 _TSO_CHECK(spConnector->GetData()->DeletedStmtList__GetCount()==0);
 _TSO_CHECK(!spConnector->GetData()->DeletedStmtList__GetHead());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);
 _TSO_CHECK(!hTr);

 _TSO_CHECK(hStmt2);
 _TSO_CHECK(!hStmt2->m_pParentTr);
 _TSO_CHECK(!hStmt2->m_EFlags.test(hStmt2->EFLAG__EXECUTION_WAS_DEFERRED));

 _TSO_CHECK(!hStmt2->m_pClosingTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt2);

 _TSO_CHECK(!hStmt2);
 _TSO_CHECK(spConnector->GetData()->DeletedStmtList__GetCount()==1);
 _TSO_CHECK(spConnector->GetData()->DeletedStmtList__GetHead());

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 _TSO_CHECK(spConnector->GetData()->DeletedStmtList__GetCount()==0);
 _TSO_CHECK(!spConnector->GetData()->DeletedStmtList__GetHead());
}//test_022__check_drop_stmts_before_exec

////////////////////////////////////////////////////////////////////////////////
//030

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_030__close_and_execute
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "insert into NUM (N_1_0) values (0);");

 _TSO_CHECK(hTr);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED))
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE))

 //-----------------------------------------
 for(size_t pass=0;pass!=3;)
 {
  ++pass;

  tracer<<L"---------------------------- pass: "<<pass<<send;

  svc::RemoteFB_Connector__StmtExecute
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    /*IN*/nullptr,
    /*OUT*/nullptr);

  _TSO_CHECK(hTr);
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED))
  _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE))

  _TSO_CHECK(hStmt->m_pParentTr);
  _TSO_CHECK(hStmt->m_pParentTr==hTr);

  _TSO_CHECK(hStmt->m_EFlags.equal(0));

  _TSO_CHECK(!hStmt->m_pClosingTr)

  //----------------------------------------
  svc::RemoteFB_Connector__StmtClose
   (tracer,
    spConnector,
    &hStmt);

  _TSO_CHECK(!hStmt->m_pParentTr);
  _TSO_CHECK(hStmt->m_pClosingTr==hTr);
 }//for pass

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);
 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_030__close_and_execute

////////////////////////////////////////////////////////////////////////////////
//030

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_030__close_and_execute__err__hack_unprep_stmt
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "insert into NUM (N_1_0) values (0);");

 _TSO_CHECK(hTr);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED))
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE))

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*IN*/nullptr,
   /*OUT*/nullptr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED))
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE))

 _TSO_CHECK(hStmt->m_pParentTr);
 _TSO_CHECK(hStmt->m_pParentTr==hTr);

 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 _TSO_CHECK(!hStmt->m_pClosingTr)

 //----------------------------------------
 svc::RemoteFB_Connector__StmtClose
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt->m_pParentTr);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr);

 //-----------------------------------------
 svc::HACK__UnprepareStmt
  (tracer,
   spConnector,
   &hStmt);

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
     /*IN*/nullptr,
     /*OUT*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   //”дивительно, но на закрытие неподготовленного курсора сервер не ругаетс€.

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__srv_err__attempt_to_execute_unprepared_sql_stmt
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   break;
  }//if

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_030__close_and_execute__err__hack_unprep_stmt

////////////////////////////////////////////////////////////////////////////////
//030

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_030__close_and_execute__err__hack_unprep_stmt__fb3
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "insert into NUM (N_1_0) values (0);");

 _TSO_CHECK(hTr);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED))
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE))

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*IN*/nullptr,
   /*OUT*/nullptr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED))
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE))

 _TSO_CHECK(hStmt->m_pParentTr);
 _TSO_CHECK(hStmt->m_pParentTr==hTr);

 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 _TSO_CHECK(!hStmt->m_pClosingTr)

 //----------------------------------------
 svc::RemoteFB_Connector__StmtClose
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt->m_pParentTr);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr);

 //-----------------------------------------
 svc::HACK__UnprepareStmt
  (tracer,
   spConnector,
   &hStmt);

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
     /*IN*/nullptr,
     /*OUT*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,3);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));
   _TSO_CHECK(exc.get_record(2));

   errSvc::check_err_rec__srv_err__failed_to_close_stmt__reclose__fb3
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   errSvc::check_err_rec__stmt_err__failed_to_close_stmt
    (tracer,
     exc.get_record(1));

   errSvc::check_err_rec__srv_err__attempt_to_execute_unprepared_sql_stmt__fb3
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(2));

   break;
  }//if

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_030__close_and_execute__err__hack_unprep_stmt__fb3

////////////////////////////////////////////////////////////////////////////////
//031

void WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::test_031__close_and_execute2
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "insert into NUM (N_1_0) values (-2) returning N_1_0;");

 _TSO_CHECK(hTr);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED))
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE))

 //-----------------------------------------
 db_obj::t_dbvalue__i4 outParam__value=0;
 short                 outParam__sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqlsubtype =0;
 xsqlda->sqlvar[0].sqllen     =sizeof(outParam__value);
 xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&outParam__value);
 xsqlda->sqlvar[0].sqlind     =&outParam__sqlind;

 xsqlda->sqld=1;

 //-----------------------------------------
 for(size_t pass=0;pass!=3;)
 {
  ++pass;

  tracer<<L"---------------------------- pass: "<<pass<<send;

  outParam__sqlind=-1;
  outParam__value=123;

  svc::RemoteFB_Connector__StmtExecute
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    /*IN*/nullptr,
    /*OUT*/xsqlda);

  _TSO_CHECK(hTr);
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED))
  _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE))

  _TSO_CHECK(hStmt->m_pParentTr);
  _TSO_CHECK(hStmt->m_pParentTr==hTr);

  _TSO_CHECK(hStmt->m_EFlags.equal(0));

  _TSO_CHECK(!hStmt->m_pClosingTr);

  _TSO_CHECK(outParam__sqlind==0);
  _TSO_CHECK(outParam__value==-2);

  //----------------------------------------
  svc::RemoteFB_Connector__StmtClose
   (tracer,
    spConnector,
    &hStmt);

  _TSO_CHECK(!hStmt->m_pParentTr);
  _TSO_CHECK(hStmt->m_pClosingTr==hTr);
 }//for pass

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);
 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_031__close_and_execute2

////////////////////////////////////////////////////////////////////////////////

const wchar_t*
 WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::helper__get_StmtExec_bugcheck_src
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
   return L"RemoteFB__API_P12_LAZY_SEND__ExecuteStatement::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13_LAZY_SEND__ExecuteStatement::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_StmtExec_bugcheck_src

//------------------------------------------------------------------------
const wchar_t*
 WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::helper__get_StmtExec_subsystem_id
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
   return errSvc::sm_subsysID__remote_fb_p12;

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return errSvc::sm_subsysID__remote_fb_p13;

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_StmtExec_subsystem_id

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_019__StmtExecute__v2_lazy_send::tag_descr

struct WORK_Test_019__StmtExecute__v2_lazy_send::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_019__StmtExecute__v2_lazy_send::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_019__StmtExecute__v2_lazy_send::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_019__StmtExecute__v2_lazy_send::tag_descr
 WORK_Test_019__StmtExecute__v2_lazy_send::sm_Tests[]=
{
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("001.bug_check.zero_stmt_handle",
   test_001__bug_check__zero_stmt_handle)

 DEF_TEST_DESCR
  ("002.bug_check.null_stmt_id",
   test_002__bug_check__null_stmt_id)

 DEF_TEST_DESCR
  ("003.bug_check.bad_owner_cn",
   test_003__bug_check__bad_owner_cn)

 DEF_TEST_DESCR
  ("004.bug_check.bad_owner_cn_of_tr",
   test_004__bug_check__bad_owner_cn_of_tr)

 DEF_TEST_DESCR
  ("005.bug_check.bad_tr",
   test_005__bug_check__bad_tr)
#endif

 //-----------------------------------------------------------------------
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("013.bug_check.incorrect_input_version",
   test_013__bug_check__incorrect_input_version)

 DEF_TEST_DESCR
  ("014.bug_check.incorrect_output_version",
   test_014__bug_check__incorrect_output_version)
#endif

 //-----------------------------------------------------------------------
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("017.exec_defer_exec_without_tr",
   test_017__err__exec_defer_exec_without_tr)
#endif

 //-----------------------------------------------------------------------
 DEF_TEST_DESCR
  ("018.defer_exec_and_commit",
   test_018__defer_exec_and_commit)

 DEF_TEST_DESCR
  ("019.defer_exec_and_rollback",
   test_019__defer_exec_and_rollback)

 DEF_TEST_DESCR
  ("020.defer_exec_and_sql_commit",
   test_020__defer_exec_and_sql_commit)

 DEF_TEST_DESCR
  ("021.defer_exec_and_sql_rollback",
   test_021__defer_exec_and_sql_rollback)

 DEF_TEST_DESCR
  ("022.check_drop_stmts_before_exec",
   test_022__check_drop_stmts_before_exec)

#ifdef NDEBUG
 //ќтключить, когда CloseStmt научитс€ самосто€тельно вы€вл€ть запросы без курсора

 //[2016-04-28] ќтключил, но оставил в релизной сборке.

 DEF_TEST_DESCR
  ("030.close_and_execute",
   test_030__close_and_execute)

 DEF_TEST_DESCR2
  ("030.close_and_execute.err.hack_unprep_stmt",
   test_030__close_and_execute__err__hack_unprep_stmt,
   "SRV<FB-3 || SRV!=FB")

 DEF_TEST_DESCR2
  ("030.close_and_execute.err.hack_unprep_stmt.fb3",
   test_030__close_and_execute__err__hack_unprep_stmt__fb3,
   "SRV>=FB-3")
#endif

#ifdef NDEBUG
 //[2016-10-11] пока оставим этот тест в релизной сборке
 DEF_TEST_DESCR
  ("031.close_and_execute2",
   test_031__close_and_execute2)
#endif
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_019__StmtExecute__v2_lazy_send

void WORK_Test_019__StmtExecute__v2_lazy_send::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                                       //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__lazy_send)-1);  //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter
  ftestID("RemoteFB.WORK.019.StmtExecute.v2.ptype__%1.%2");

 TTSO_TestData_v2 Data;

 for(;it;++it)
 {
  assert(it[iTest]<_DIM_(sm_Tests));
  assert(it[iPType]<_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__lazy_send));

  //----------------------------------------
  Data.m_RemoteFB__ProtocolType
   =g_TestCfg__RemoteFB__ProtocolTypes__lazy_send[it[iPType]];

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
