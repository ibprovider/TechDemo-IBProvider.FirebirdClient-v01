////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_019__StmtExecute__v3.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__xdr__encoder.h"
#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01_writer.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/error_services/ibp_sqlstate_codes.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_019__StmtExecute__v3::tag_impl

class WORK_Test_019__StmtExecute__v3::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public: //---------------------------------------------------------------
  static void test_006__err__not_prepared
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public: //---------------------------------------------------------------
 #ifdef NDEBUG
  static void test_007__bug_check__incorrect_input_sqld
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_008__bug_check__incorrect_input_sqln
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_009__bug_check__incorrect_output_sqld
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_010__bug_check__incorrect_output_sqln
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 #endif

 public: //---------------------------------------------------------------
  static void test_011__err__too_big_in_params_blr__1
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_011__err__too_big_in_params_blr__2
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_012__err__too_big_out_params_blr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public: //---------------------------------------------------------------
  static void test_014__err__op_execute__hack_commit_tr
                (TTSO_GlobalContext*     pParams,
                 context_type*           pCtx,
                 const TTSO_TestData_v2& Data);

  static void test_015__err__op_execute2__hack_commit_tr
                (TTSO_GlobalContext*     pParams,
                 context_type*           pCtx,
                 const TTSO_TestData_v2& Data);

 public: //---------------------------------------------------------------
  static void test_S001__insert__without_params
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_S002__set_transaction
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_S003__commit
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_S004__commit_retain
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_S005__rollback
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_S006__rollback_retain
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_S007__insert__with_param1__core_bug__4785
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_S007__insert__with_param1
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_S008__insert__with_param3
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public: //---------------------------------------------------------------
  static void test_IN_NN001__short
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN002__long
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN003__int64
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN004__float
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN005__double
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN006__type_time
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN007__type_date
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN008__timestamp
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN009__char
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN009__char__len0
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN010__varchar
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN011__sqlnull
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public:
  static void test_IN_N001__array_null
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_N002__blob_null
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_StmtExec_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);

  static const wchar_t* helper__get_StmtExec_subsystem_id
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_019__StmtExecute__v3

////////////////////////////////////////////////////////////////////////////////
//TEST 006

void WORK_Test_019__StmtExecute__v3::tag_impl::test_006__err__not_prepared
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

   //errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_code
    (exc.com_code(),
     DB_E_NOTPREPARED);

   errSvc::check_err_rec__stmt_err__not_prepared
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_subsystem_id(spConnector));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_006__err__not_prepared

////////////////////////////////////////////////////////////////////////////////
//TEST 007

#ifdef NDEBUG

void WORK_Test_019__StmtExecute__v3::tag_impl::test_007__bug_check__incorrect_input_sqld
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
   "insert into NUM (N_1_1) values (?);");

 XSQLDA_V1_Wrapper xsqlda(0);

 xsqlda->sqld=-1;

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
     /*pInXSQLDA*/xsqlda,
     /*pOutXSQLDA*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__xsqlda_err__bug_check__incorrect_sqld
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_subsystem_id(spConnector),
     L"pInXSQLDA",
     -1);

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
}//test_007__bug_check__incorrect_input_sqld

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 008

#ifdef NDEBUG

void WORK_Test_019__StmtExecute__v3::tag_impl::test_008__bug_check__incorrect_input_sqln
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
   "insert into NUM (N_1_1) values (?);");

 XSQLDA_V1_Wrapper xsqlda(0);

 xsqlda->sqld=2;

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
     /*pInXSQLDA*/xsqlda,
     /*pOutXSQLDA*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__xsqlda_err__bug_check__incorrect_sqln
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_subsystem_id(spConnector),
     L"pInXSQLDA",
     0,
     2);

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
}//helper__test_008__bug_check__incorrect_input_sqln

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 009

#ifdef NDEBUG

void WORK_Test_019__StmtExecute__v3::tag_impl::test_009__bug_check__incorrect_output_sqld
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
   "insert into NUM (N_1_1) values (0) returning N_1_1;");

 XSQLDA_V1_Wrapper xsqlda(0);

 xsqlda->sqld=-1;

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
     /*pOutXSQLDA*/xsqlda);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__xsqlda_err__bug_check__incorrect_sqld
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_subsystem_id(spConnector),
     L"pOutXSQLDA",
     -1);

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
}//test_009__bug_check__incorrect_output_sqld

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 010

#ifdef NDEBUG

void WORK_Test_019__StmtExecute__v3::tag_impl::test_010__bug_check__incorrect_output_sqln
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
   "insert into NUM (N_1_1) values (0) returning N_1_1;");

 XSQLDA_V1_Wrapper xsqlda(0);

 xsqlda->sqld=2;

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
     /*pOutXSQLDA*/xsqlda);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__xsqlda_err__bug_check__incorrect_sqln
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_subsystem_id(spConnector),
     L"pOutXSQLDA",
     0,
     2);

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
}//test_010__bug_check__incorrect_output_sqln

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 011

void WORK_Test_019__StmtExecute__v3::tag_impl::test_011__err__too_big_in_params_blr__1
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
   "insert into NUM (N_1_1) values (?);");

 XSQLDA_V1_Wrapper xsqlda(SHRT_MAX);

 xsqlda->sqld=SHRT_MAX;

 db_obj::t_dbvalue__i2 xvalue=0;

 assert_s(sizeof(xvalue)==2);

 for(size_t i=0;i!=SHRT_MAX;++i)
 {
  xsqlda->sqlvar[i].sqltype=isc_api::ibp_isc_sql_short;
  xsqlda->sqlvar[i].sqllen =2;
  xsqlda->sqlvar[i].sqldata=reinterpret_cast<char*>(&xvalue);
 }

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
     /*pInXSQLDA*/xsqlda,
     /*pOutXSQLDA*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__xsqlda_err__blr_data_is_too_long
    (tracer,
     exc.get_record(0),
     errSvc::sm_subsysID__remote_fb_p12,
     L"pInXSQLDA",
     131076,
     USHRT_MAX);

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
}//test_011__err__too_big_in_params_blr__1

//------------------------------------------------------------------------
void WORK_Test_019__StmtExecute__v3::tag_impl::test_011__err__too_big_in_params_blr__2
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
   "insert into NUM (N_1_1) values (?);");

 XSQLDA_V1_Wrapper xsqlda(SHRT_MAX);

 xsqlda->sqld=SHRT_MAX;

 db_obj::t_dbvalue__i2 xvalue=0;

 assert_s(sizeof(xvalue)==2);

 for(size_t i=0;i!=SHRT_MAX;++i)
 {
  xsqlda->sqlvar[i].sqltype=isc_api::ibp_isc_sql_short;
  xsqlda->sqlvar[i].sqllen =2;
  xsqlda->sqlvar[i].sqldata=reinterpret_cast<char*>(&xvalue);
 }

 //-----------
 XSQLDA_V1_Wrapper out_xsqlda(1);

 out_xsqlda->sqld=1;

 out_xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_short;
 out_xsqlda->sqlvar[0].sqllen =2;
 out_xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);

 //-----------
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
     /*pInXSQLDA*/xsqlda,
     /*pOutXSQLDA*/out_xsqlda);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__xsqlda_err__blr_data_is_too_long
    (tracer,
     exc.get_record(0),
     errSvc::sm_subsysID__remote_fb_p12,
     L"pInXSQLDA",
     131076,
     USHRT_MAX);

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
}//test_011__err__too_big_in_params_blr__2

////////////////////////////////////////////////////////////////////////////////
//TEST 012

void WORK_Test_019__StmtExecute__v3::tag_impl::test_012__err__too_big_out_params_blr
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
   "insert into NUM (N_1_1) values (?);");

 XSQLDA_V1_Wrapper xsqlda(SHRT_MAX);

 xsqlda->sqld=SHRT_MAX;

 db_obj::t_dbvalue__i2 xvalue=0;

 assert_s(sizeof(xvalue)==2);

 for(size_t i=0;i!=SHRT_MAX;++i)
 {
  xsqlda->sqlvar[i].sqltype=isc_api::ibp_isc_sql_short;
  xsqlda->sqlvar[i].sqllen =2;
  xsqlda->sqlvar[i].sqldata=reinterpret_cast<char*>(&xvalue);
 }

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
     /*pOutXSQLDA*/xsqlda);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__xsqlda_err__blr_data_is_too_long
    (tracer,
     exc.get_record(0),
     errSvc::sm_subsysID__remote_fb_p12,
     L"pOutXSQLDA",
     131076,
     USHRT_MAX);

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
}//test_012__err__too_big_out_params_blr

////////////////////////////////////////////////////////////////////////////////
//TEST 014

void WORK_Test_019__StmtExecute__v3::tag_impl::test_014__err__op_execute__hack_commit_tr
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into NUM (TEST_ID) values (NULL);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::HACK__CommitTr
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

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

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__srv_err__bad_tr_handle
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_014__err__op_execute__hack_commit_tr

////////////////////////////////////////////////////////////////////////////////
//TEST 015

void WORK_Test_019__StmtExecute__v3::tag_impl::test_015__err__op_execute2__hack_commit_tr
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into NUM (TEST_ID) values (NULL) returning N_1_0;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::HACK__CommitTr
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 db_obj::t_dbvalue__i2 columnValue=0;
 short                 columnInd=0;

 XSQLDA_V1_Wrapper outXSQLDA(1);

 outXSQLDA->sqlvar[0].sqllen     =sizeof(columnValue);
 outXSQLDA->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_short|1;
 outXSQLDA->sqlvar[0].sqlsubtype =0;
 outXSQLDA->sqlvar[0].sqlscale   =0;
 outXSQLDA->sqlvar[0].sqldata    =reinterpret_cast<char*>(&columnValue);
 outXSQLDA->sqlvar[0].sqlind     =&columnInd;

 outXSQLDA->sqld=1;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

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
     outXSQLDA);
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

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__srv_err__bad_tr_handle
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_015__err__op_execute2__hack_commit_tr

////////////////////////////////////////////////////////////////////////////////
//TEST S001

void WORK_Test_019__StmtExecute__v3::tag_impl::test_S001__insert__without_params
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into NUM (TEST_ID) values (NULL);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S001__insert__without_params

////////////////////////////////////////////////////////////////////////////////
//TEST S002

void WORK_Test_019__StmtExecute__v3::tag_impl::test_S002__set_transaction
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

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
   nullptr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   "set transaction;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S002__set_transaction

////////////////////////////////////////////////////////////////////////////////
//TEST S003

void WORK_Test_019__StmtExecute__v3::tag_impl::test_S003__commit
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   nullptr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   "commit;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 _TSO_CHECK(!hTrCopy->m_pParentPort);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S003__commit

////////////////////////////////////////////////////////////////////////////////
//TEST S004

void WORK_Test_019__StmtExecute__v3::tag_impl::test_S004__commit_retain
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   nullptr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   "commit retain;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 const auto hTrIDCopy=hTr->m_ID.get_value();

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTrCopy->m_ID.has_value());
 _TSO_CHECK(hTrCopy->m_ID.get_value()==hTrIDCopy);

 _TSO_CHECK(hTrCopy->m_pParentPort);

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S004__commit_retain

////////////////////////////////////////////////////////////////////////////////
//TEST S005

void WORK_Test_019__StmtExecute__v3::tag_impl::test_S005__rollback
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   nullptr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   "rollback;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 _TSO_CHECK(!hTrCopy->m_pParentPort);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S005__rollback

////////////////////////////////////////////////////////////////////////////////
//TEST S006

void WORK_Test_019__StmtExecute__v3::tag_impl::test_S006__rollback_retain
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   nullptr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   "rollback retain;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 const auto hTrIDCopy=hTr->m_ID.get_value();

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTrCopy->m_ID.has_value());
 _TSO_CHECK(hTrCopy->m_ID.get_value()==hTrIDCopy);

 _TSO_CHECK(hTrCopy->m_pParentPort);

 //-----------------------------------------
 svc::RemoteFB_Connector__Rollback
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S006__rollback_retain

////////////////////////////////////////////////////////////////////////////////
//TEST S007

void WORK_Test_019__StmtExecute__v3::tag_impl::test_S007__insert__with_param1__core_bug__4785
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into NUM (N_1_0) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 {
  typedef remote_fb::transmission::pset01::RemoteFB__PSET01__XDR__Encoder xdr;

  const remote_fb::protocol::set01::P_OP opID=remote_fb::protocol::set01::op_execute;

  remote_fb::protocol::set01::P_OP_SQLDATA p_sqldata={};

  p_sqldata.p_sqldata__statement=hStmt->m_ID.get_value();

  p_sqldata.p_sqldata__transaction=hTr->m_ID.get_value();

  remote_fb::protocol::P_UCHAR blr[]={0x05,0x02,0x04,0x00,0x02,0x00,0x08,0x00,0x07,0x00,0xff,0x4c};

  p_sqldata.p_sqldata__blr.cstr_length=sizeof(blr);

  p_sqldata.p_sqldata__blr.cstr_address=blr;

  //----------------------------------------
  remote_fb::RemoteFB__PortPtr spPort(spConnector->GetPort());

  svc::remote_fb_inet_port_type*
   const pINetPort(dynamic_cast<svc::remote_fb_inet_port_type*>(spPort.ptr()));

  svc::remote_fb_inet_port_type::tag_writer
   portWriter(pINetPort,/*IsDeferredPacket*/false);

  //----------------------------------------
  tracer<<L"Send bad packet ..."<<send;

  try
  {
   remote_fb::RemoteFB__OperationContext portOpCtx;

   portOpCtx.reg_svc(&portWriter);

   remote_fb::RemoteFB__PortWriteGuard wguard(portOpCtx);

   xdr::encode__p_op
    (&portWriter,
     &opID);

   xdr::encode__p_objct
    (&portWriter,
     &p_sqldata.p_sqldata__statement);

   xdr::encode__p_objct
    (&portWriter,
     &p_sqldata.p_sqldata__transaction);

   //! \note
   //!  ¬ оригинальной версии здесь понакручено (xdr_sql_blr)
   xdr::encode__p_cstring_const
    (&portWriter,
     &p_sqldata.p_sqldata__blr);

   xdr::encode__p_ushort_as_p_short
    (&portWriter,
     &p_sqldata.p_sqldata__message_number);

   for(size_t n=0;n!=1024*1024*1024;++n)
   {
    xdr::encode__p_ushort_as_p_short
     (&portWriter,
      &p_sqldata.p_sqldata__messages);
   }//for

   //----------------------------------------
   wguard.complete();

   tracer(tso_msg_warning,-1)<<L"We wait the error ..."<<send;
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);
  }//catch
 }//local
}//test_S007__insert__with_param1__core_bug__4785

////////////////////////////////////////////////////////////////////////////////
//TEST S007

void WORK_Test_019__StmtExecute__v3::tag_impl::test_S007__insert__with_param1
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into NUM (N_1_0) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 signed __int32 xparam0_value=5;
 short          xparam0_ind=0;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S007__insert__with_param1

////////////////////////////////////////////////////////////////////////////////
//TEST S008

void WORK_Test_019__StmtExecute__v3::tag_impl::test_S008__insert__with_param3
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into NUM (N_1_0,N_2_0,N_3_0) values (?,?,?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(3);

 xsqlda->sqld=3;

 signed __int32 xparam0_value=6;
 short          xparam0_ind=0;

 signed __int32 xparam1_value=7;
 short          xparam1_ind=-1;

 signed __int32 xparam2_value=8;
 short          xparam2_ind=0;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 xsqlda->sqlvar[1].sqltype=isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[1].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xparam1_value);
 xsqlda->sqlvar[1].sqlind =&xparam1_ind;

 xsqlda->sqlvar[2].sqltype=isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[2].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[2].sqldata=reinterpret_cast<char*>(&xparam2_value);
 xsqlda->sqlvar[2].sqlind =&xparam2_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S008__insert__with_param3

////////////////////////////////////////////////////////////////////////////////
//TEST NN001

void WORK_Test_019__StmtExecute__v3::tag_impl::test_IN_NN001__short
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into TEST_MODIFY_ROW (COL_SMALLINT) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 signed __int16 xparam0_value=222;
 //short          xparam0_ind=0;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_short;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN001__short

////////////////////////////////////////////////////////////////////////////////
//TEST NN002

void WORK_Test_019__StmtExecute__v3::tag_impl::test_IN_NN002__long
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into TEST_MODIFY_ROW (COL_INTEGER) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 signed __int32 xparam0_value=4444;
 //short          xparam0_ind=0;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN002__long

////////////////////////////////////////////////////////////////////////////////
//TEST NN003

void WORK_Test_019__StmtExecute__v3::tag_impl::test_IN_NN003__int64
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into TEST_MODIFY_ROW (COL_BIGINT) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 LONG       __tmp_val_for_align=0;__tmp_val_for_align;
 signed __int64   xparam0_values[]={INT64_MIN,INT64_MIN+1,-1,0,1,INT64_MAX-1,INT64_MAX};
 //short          xparam0_ind=0;

 for(size_t i=0;i!=_DIM_(xparam0_values);++i)
 {
  tracer<<L"-------------------------- ["<<i<<L"]: "<<xparam0_values[i]<<send;

  XSQLDA_V1_Wrapper xsqlda(1);

  xsqlda->sqld=1;

  //short          xparam0_ind=0;

  xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_int64;
  xsqlda->sqlvar[0].sqllen =sizeof(xparam0_values[i]);
  xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_values[i]);
  xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

  //-----------------------------------------
  svc::RemoteFB_Connector__StmtExecute
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    /*pInXSQLDA*/xsqlda,
    /*pOutXSQLDA*/nullptr);

  _TSO_CHECK(hTr==hTrCopy);
  _TSO_CHECK(hTr->m_ID.has_value());

  _TSO_CHECK(hStmt==hStmtCopy);
  _TSO_CHECK(hStmt->m_ID.has_value());
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 //-----------------------------------------
 _TSO_CHECK(__tmp_val_for_align==0);
}//test_IN_NN003__int64

////////////////////////////////////////////////////////////////////////////////
//TEST NN004

void WORK_Test_019__StmtExecute__v3::tag_impl::test_IN_NN004__float
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into TEST_MODIFY_ROW (COL_FLOAT) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 float     xparam0_value=123;
 //short     xparam0_ind=0;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_float;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN004__float

////////////////////////////////////////////////////////////////////////////////
//TEST NN005

void WORK_Test_019__StmtExecute__v3::tag_impl::test_IN_NN005__double
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into TEST_MODIFY_ROW (COL_DOUBLE) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 LONG       __tmp_val_for_align=0;__tmp_val_for_align;
 double     xparam0_value=54321.5;
 //short     xparam0_ind=0;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_double;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 //-----------------------------------------
 _TSO_CHECK(__tmp_val_for_align==0);
}//test_IN_NN005__double

////////////////////////////////////////////////////////////////////////////////
//TEST NN006

void WORK_Test_019__StmtExecute__v3::tag_impl::test_IN_NN006__type_time
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into TEST_MODIFY_ROW (COL_TYPE_TIME) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 const isc_api::t_ibp_isc_time  c_tm__sec      =10000;
 const isc_api::t_ibp_isc_time  c_tm__min      =c_tm__sec*60;
 const isc_api::t_ibp_isc_time  c_tm__hour     =c_tm__min*60;

 isc_api::t_ibp_isc_time  xparam0_value=5000+1*c_tm__sec+2*c_tm__min+3*c_tm__hour;
 //short                  xparam0_ind=0;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_type_time;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN006__type_time

////////////////////////////////////////////////////////////////////////////////
//TEST NN007

void WORK_Test_019__StmtExecute__v3::tag_impl::test_IN_NN007__type_date
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into TEST_MODIFY_ROW (COL_TYPE_DATE) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 isc_api::t_ibp_isc_date  xparam0_value=1;
 //short                  xparam0_ind=0;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_type_date;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN007__type_date

////////////////////////////////////////////////////////////////////////////////
//TEST NN008

void WORK_Test_019__StmtExecute__v3::tag_impl::test_IN_NN008__timestamp
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into TEST_MODIFY_ROW (COL_TIMESTAMP) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 const isc_api::t_ibp_isc_time  c_tm__sec      =10000;
 const isc_api::t_ibp_isc_time  c_tm__min      =c_tm__sec*60;
 const isc_api::t_ibp_isc_time  c_tm__hour     =c_tm__min*60;

 isc_api::t_ibp_isc_timestamp  xparam0_value={1,1234+5*c_tm__sec+6*c_tm__min+7*c_tm__hour};
 //short                       xparam0_ind=0;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_timestamp;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN008__timestamp

////////////////////////////////////////////////////////////////////////////////
//TEST NN009

void WORK_Test_019__StmtExecute__v3::tag_impl::test_IN_NN009__char
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
 params.set_dbprop_init__ctype(L"ASCII");

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

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into TEST_MODIFY_ROW (COL_CHAR_10) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 char      xparam0_value[]={'1','2','3','4','5','6',' ','8','A',};
 //short   xparam0_ind=0;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_text;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN009__char

////////////////////////////////////////////////////////////////////////////////
//TEST NN009

void WORK_Test_019__StmtExecute__v3::tag_impl::test_IN_NN009__char__len0
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
 params.set_dbprop_init__ctype(L"ASCII");

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

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into TEST_MODIFY_ROW (COL_CHAR_10) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 //short   xparam0_ind=0;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_text;
 xsqlda->sqlvar[0].sqllen =0;
 xsqlda->sqlvar[0].sqldata=nullptr;
 xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN009__char__len0

////////////////////////////////////////////////////////////////////////////////
//TEST NN010

void WORK_Test_019__StmtExecute__v3::tag_impl::test_IN_NN010__varchar
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
 params.set_dbprop_init__ctype(L"ASCII");

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

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into TEST_MODIFY_ROW (COL_VARCHAR_10) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 struct tag_varchar_data
 {
  short length;
  char  value[10];
 };//tag_varchar_data

 tag_varchar_data xparam0_data={4,{'1','2','3',' '}};
 //short          xparam0_ind=0;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_varying;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_data.value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_data);
 xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN010__varchar

////////////////////////////////////////////////////////////////////////////////
//TEST NN011

void WORK_Test_019__StmtExecute__v3::tag_impl::test_IN_NN011__sqlnull
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "update TEST_MODIFY_ROW set TEST_ID=TEST_ID where TEST_ID=-1 and ? is NULL and 1=0;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 //short          xparam0_ind=0;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_fb025_sql_null;
 xsqlda->sqlvar[0].sqllen =0;
 xsqlda->sqlvar[0].sqldata=nullptr;
 xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN011__sqlnull

////////////////////////////////////////////////////////////////////////////////
//TEST N001

void WORK_Test_019__StmtExecute__v3::tag_impl::test_IN_N001__array_null
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into TEST_MODIFY_ROW (COL_INT_ARRAY) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 db_obj::DB_IBARRAYID    xparam0_value={};
 short                   xparam0_ind=-1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_array|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_N001__array_null

////////////////////////////////////////////////////////////////////////////////
//TEST N002

void WORK_Test_019__StmtExecute__v3::tag_impl::test_IN_N002__blob_null
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
 _TSO_CHECK(!cns.db_dialect_Ex.null());

 _TSO_CHECK(structure::can_numeric_cast<unsigned short>(cns.db_dialect_Ex.value()));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into TEST_MODIFY_ROW (COL_INT_ARRAY) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 db_obj::DB_IBBLOBID     xparam0_value={};
 short                   xparam0_ind=-1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_blob|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_N002__blob_null

////////////////////////////////////////////////////////////////////////////////

const wchar_t*
 WORK_Test_019__StmtExecute__v3::tag_impl::helper__get_StmtExec_bugcheck_src
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
   return L"RemoteFB__API_P12__ExecuteStatement::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__ExecuteStatement::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_StmtExec_bugcheck_src

//------------------------------------------------------------------------
const wchar_t*
 WORK_Test_019__StmtExecute__v3::tag_impl::helper__get_StmtExec_subsystem_id
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
//struct WORK_Test_019__StmtExecute__v3::tag_descr

struct WORK_Test_019__StmtExecute__v3::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_019__StmtExecute__v3::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_019__StmtExecute__v3::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_019__StmtExecute__v3::tag_descr
 WORK_Test_019__StmtExecute__v3::sm_Tests[]=
{
 //-----------------------------------------------------------------------
 DEF_TEST_DESCR
  ("006.err.not_prepared",
   test_006__err__not_prepared)

 //-----------------------------------------------------------------------
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("007.bug_check.incorrect_input_sqld",
   test_007__bug_check__incorrect_input_sqld)

 DEF_TEST_DESCR
  ("008.bug_check.incorrect_input_sqln",
   test_008__bug_check__incorrect_input_sqln)

 DEF_TEST_DESCR
  ("009.bug_check.incorrect_output_sqld",
   test_009__bug_check__incorrect_output_sqld)

 DEF_TEST_DESCR
  ("010.bug_check.incorrect_output_sqln",
   test_010__bug_check__incorrect_output_sqln)
#endif

  //----------------------------------------------------------------------
 DEF_TEST_DESCR2
  ("011.bug_check.too_big_in_params_blr.1",
   test_011__err__too_big_in_params_blr__1,
   "!NE__PSET02")

 DEF_TEST_DESCR2
  ("011.bug_check.too_big_in_params_blr.2",
   test_011__err__too_big_in_params_blr__2,
   "!NE__PSET02")

 DEF_TEST_DESCR2
  ("012.bug_check.too_big_out_params_blr",
   test_012__err__too_big_out_params_blr,
   "!NE__PSET02")

 //-----------------------------------------------------------------------
 DEF_TEST_DESCR
  ("014.err.op_execute.hack_commit_tr",
   test_014__err__op_execute__hack_commit_tr)

 DEF_TEST_DESCR
  ("015.err.op_execute2.hack_commit_tr",
   test_015__err__op_execute2__hack_commit_tr)

 DEF_TEST_DESCR
  ("S001.insert.without_params",
   test_S001__insert__without_params)

 DEF_TEST_DESCR
  ("S002.set_transaction",
   test_S002__set_transaction)

 DEF_TEST_DESCR
  ("S003.commit",
   test_S003__commit)

 DEF_TEST_DESCR
  ("S004.commit_retain",
   test_S004__commit_retain)

 DEF_TEST_DESCR
  ("S005.rollback",
   test_S005__rollback)

 DEF_TEST_DESCR
  ("S006.rollback_retain",
   test_S006__rollback_retain)

 DEF_TEST_DESCR
  ("S007.insert.with_param1.core_bug_4785",
   test_S007__insert__with_param1__core_bug__4785)

 DEF_TEST_DESCR
  ("S007.insert.with_param1",
   test_S007__insert__with_param1)

 DEF_TEST_DESCR
  ("S008.insert.with_param3",
   test_S008__insert__with_param3)

 DEF_TEST_DESCR
  ("IN.NN001.short",
   test_IN_NN001__short)

 DEF_TEST_DESCR
  ("IN.NN002.long",
   test_IN_NN002__long)

 DEF_TEST_DESCR
  ("IN.NN003.int64",
   test_IN_NN003__int64)

 DEF_TEST_DESCR
  ("IN.NN004.float",
   test_IN_NN004__float)

 DEF_TEST_DESCR
  ("NN005.double",
   test_IN_NN005__double)

 DEF_TEST_DESCR
  ("IN.NN006.type_time",
   test_IN_NN006__type_time)

 DEF_TEST_DESCR
  ("IN.NN007.type_date",
   test_IN_NN007__type_date)

 DEF_TEST_DESCR
  ("IN.NN008.timestamp",
   test_IN_NN008__timestamp)

 DEF_TEST_DESCR
  ("IN.NN009.char",
   test_IN_NN009__char)

 DEF_TEST_DESCR
  ("IN.NN009.char.len0",
   test_IN_NN009__char__len0)

 DEF_TEST_DESCR
  ("IN.NN010.varchar",
   test_IN_NN010__varchar)

 DEF_TEST_DESCR
  ("IN.NN011.sql_null",
   test_IN_NN011__sqlnull)

 DEF_TEST_DESCR
  ("IN.N001.array.null",
   test_IN_N001__array_null)

 DEF_TEST_DESCR
  ("IN.N002.blob.null",
   test_IN_N002__blob_null)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_019__StmtExecute__v3

void WORK_Test_019__StmtExecute__v3::create(TTSO_PushTest*      const pTestPusher,
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
  ftestID("RemoteFB.WORK.019.StmtExecute.v3.ptype__%1.%2");

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
