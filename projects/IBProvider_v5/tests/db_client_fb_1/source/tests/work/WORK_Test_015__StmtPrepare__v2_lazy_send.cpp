////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_015__StmtPrepare__v2_lazy_send.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/dbms_fb/v02_5_0/api/db_obj__dbms_fb__v02_5_0__api__error_codes.h"
#include "source/error_services/ibp_sqlstate_codes.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl

class WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl
{
 private:
  typedef tag_impl                          self_type;

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

 public:
  static void test_006_ok__insert
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_007_ok__insert
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_008__err__bad_sql
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_009__err__bad_sql
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_010__err__bad_sql
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_011_ok__select
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_012_ok__select_with_param
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_013__prepare_two_sql
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_014_ok__insert_with_returnings
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_015__prepare_after_close
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_016__prepare_after_hack_close
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_017__err2__close_and_prepare
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_017__err2__close_and_prepare__fb3
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_018__err__prepare_of_deferred_exec
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_StmtPrepare_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);

  static const wchar_t* helper__get_StmtPrepare_subsystem_id
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_001__bug_check__zero_stmt_handle
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
   svc::remote_fb_stmt_handle_type hStmt(nullptr);

   svc::RemoteFB_Connector__StmtPrepare
    (tracer,
     spConnector,
     OpCtx,
     /*pTr*/nullptr,
     &hStmt,
     /*SQL_dialect*/0,
     "");
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_StmtPrepare_bugcheck_src(spConnector),
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

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_002__bug_check__null_stmt_id
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
 svc::remote_fb_stmt_handle_type
  hStmt(remote_fb::handles::RemoteFB__HandleData_Statement::Create());

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_null());

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtPrepare
    (tracer,
     spConnector,
     OpCtx,
     /*phTr*/nullptr,
     &hStmt,
     /*SQL_dialect*/0,
     "");
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_StmtPrepare_bugcheck_src(spConnector),
     L"#004");

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;

  break;
 }//for[ever]

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_002__bug_check__null_stmt_id

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_003__bug_check__bad_owner_cn
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
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt!=nullptr);

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
   svc::RemoteFB_Connector__StmtPrepare
    (tracer,
     spConnector2,
     OpCtx,
     /*pTr*/nullptr,
     &hStmt,
     /*SQL_dialect*/0,
     "");
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_StmtPrepare_bugcheck_src(spConnector),
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

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_004__bug_check__bad_owner_cn_of_tr
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams);
 assert(pCtx);
 assert(bugcheck_src);

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
 isc_base::t_isc_connection_settings cns2;

 const svc::remote_fb_connector_ptr
  spConnector2
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns2));

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
   svc::RemoteFB_Connector__StmtPrepare
    (tracer,
     spConnector2,
     OpCtx,
     &hTr,
     &hStmt2,
     /*SQL_dialect*/0,
     "");
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__tr_err__bug_check__bad_tr_handle
    (tracer,
     exc.get_record(0),
     helper__get_StmtPrepare_bugcheck_src(spConnector),
     L"#002");

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

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector2);
}//test_004__bug_check__bad_owner_cn_of_tr

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 005

#ifdef NDEBUG

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_005__bug_check__bad_tr
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
   svc::RemoteFB_Connector__StmtPrepare
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     /*SQL_dialect*/0,
     "");
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__tr_err__bug_check__bad_tr_handle
    (tracer,
     exc.get_record(0),
     helper__get_StmtPrepare_bugcheck_src(spConnector),
     L"#001");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_005__bug_check__bad_tr

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 006

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_006_ok__insert
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
 svc::remote_fb_tr_handle_type hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (short)cns.db_dialect_Ex.value(),
   "insert into DUAL (ID) values (1);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_006_ok__insert

////////////////////////////////////////////////////////////////////////////////
//TEST 007

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_007_ok__insert
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
 svc::remote_fb_tr_handle_type hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (short)cns.db_dialect_Ex.value(),
   "insert into DUAL (ID) values (1);");

 _TSO_CHECK(hTr);
 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 auto const copyStmtID=hStmt->m_ID.get_value();

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (short)cns.db_dialect_Ex.value(),
   "insert into DUAL (ID) values (2);");

 _TSO_CHECK(hTr);
 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(copyStmtID==hStmt->m_ID.get_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_007_ok__insert

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_008__err__bad_sql
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

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtPrepare
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     /*SQL_dialect*/0,
     "insert into DUMMMY_DUMMY4321 (id) values(0);");
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,
                           1);

   //errSvc::check_err_rec__cn_err__bad_login(tracer,
   //                                         exc.get_record(0));

   errSvc::error_rec__check_sqlstate_and_native_code
    (tracer,
     exc.get_record(0),
     L"42S02", //IBP_SQLSTATE__42S02__ODBC__BASE_TABLE_OR_VIEW_NOT_FOUND
     ibp::db_obj::dbms_fb::v02_5_0::api::ibp_fb_v25_err__dsql_relation_err);

   errSvc::check_err_code
    (exc.com_code(),
     DB_E_NOTABLE);

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_008__err__bad_sql

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_009__err__bad_sql
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

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (short)cns.db_dialect_Ex.value(),
   "insert into DUAL (ID) values(123);");

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtPrepare
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     /*SQL_dialect*/0,
     "insert into DUMMMY_DUMMY4321 (id) values(0);");
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count
    (exc,
     1);

   //errSvc::check_err_rec__cn_err__bad_login(tracer,
   //                                         exc.get_record(0));

   errSvc::error_rec__check_sqlstate_and_native_code
    (tracer,
     exc.get_record(0),
     L"42S02", //IBP_SQLSTATE__42S02__ODBC__BASE_TABLE_OR_VIEW_NOT_FOUND
     ibp::db_obj::dbms_fb::v02_5_0::api::ibp_fb_v25_err__dsql_relation_err);

   errSvc::check_err_code
    (exc.com_code(),
     DB_E_NOTABLE);

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_009__err__bad_sql

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_010__err__bad_sql
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

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 for(size_t pass=0;pass!=3;)
 {
  ++pass;

  tracer<<L"------------------------------------- pass: "<<pass<<send;

  try
  {
   svc::RemoteFB_Connector__StmtPrepare
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     /*SQL_dialect*/0,
     "insert into DUMMMY_DUMMY4321 (id) values(0);");
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count
    (exc,
     1);

   //errSvc::check_err_rec__cn_err__bad_login(tracer,
   //                                         exc.get_record(0));

   errSvc::error_rec__check_sqlstate_and_native_code
    (tracer,
     exc.get_record(0),
     L"42S02", //IBP_SQLSTATE__42S02__ODBC__BASE_TABLE_OR_VIEW_NOT_FOUND
     ibp::db_obj::dbms_fb::v02_5_0::api::ibp_fb_v25_err__dsql_relation_err);

   errSvc::check_err_code
    (exc.com_code(),
     DB_E_NOTABLE);

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_010__err__bad_sql

////////////////////////////////////////////////////////////////////////////////
//TEST 011

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_011_ok__select
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
 svc::remote_fb_tr_handle_type hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 for(size_t pass=0;pass!=3;)
 {
  ++pass;

  tracer<<L"------------------------ pass: "<<pass<<send;

  svc::RemoteFB_Connector__StmtPrepare
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    (short)cns.db_dialect_Ex.value(),
    "select ID from DUAL;");

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));
  _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());
 }//for pass

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_011_ok__select

////////////////////////////////////////////////////////////////////////////////
//TEST 012

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_012_ok__select_with_param
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
 svc::remote_fb_tr_handle_type hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 for(size_t pass=0;pass!=3;)
 {
  ++pass;

  tracer<<L"------------------------ pass: "<<pass<<send;

  svc::RemoteFB_Connector__StmtPrepare
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    (short)cns.db_dialect_Ex.value(),
    "select ID from DUAL where ID=?;");

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));
  _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());
 }//for pass

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_012_ok__select_with_param

////////////////////////////////////////////////////////////////////////////////
//TEST 013

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_013__prepare_two_sql
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
 svc::remote_fb_tr_handle_type hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt1(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt1);

 _TSO_CHECK(hStmt1);
 _TSO_CHECK(hStmt1->m_ID.is_defer());
 _TSO_CHECK(hStmt1->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt2(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt2);

 _TSO_CHECK(hStmt2);
 _TSO_CHECK(hStmt2->m_ID.is_defer());
 _TSO_CHECK(hStmt2->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt1,
   (short)cns.db_dialect_Ex.value(),
   "select ID as C0 from DUAL;");

 _TSO_CHECK(hStmt1);
 _TSO_CHECK(hStmt1->m_ID.has_value());
 _TSO_CHECK(hStmt1->m_PFlags.test(hStmt1->PFLAG__PREPARED));
 _TSO_CHECK(hStmt1->m_PFlags.test(hStmt1->PFLAG__DEFER_EXECUTE));
 _TSO_CHECK(hStmt1->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 try
 {
  //1. подключиться отладчиком к серверу
  //2. поставить точку прерывания на op_allocate_statement (server.cpp)
  //3. смоделировать ошибку создания запроса, например, bad_db:
  //   - allocate_statement
  //   - bad_db
  //   - bad_port_context
  //     - пропустить if(rdb) и заставить вернуть ошибку (false)

  svc::RemoteFB_Connector__StmtPrepare
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt2,
    (short)cns.db_dialect_Ex.value(),
    "select ID as C1,ID as C2 from DUAL;");

  _TSO_CHECK(hStmt2);
  _TSO_CHECK(hStmt2->m_ID.has_value());
  _TSO_CHECK(hStmt2->m_PFlags.test(hStmt2->PFLAG__PREPARED));
  _TSO_CHECK(hStmt2->m_PFlags.test(hStmt2->PFLAG__DEFER_EXECUTE));
  _TSO_CHECK(hStmt2->m_pParentPort==spConnector->GetPort());
 }
 catch(...)
 {
  TTSO_ExceptionRouter::route(tracer);
 }//catch

 //-----------------------------------------
 //у первого запроса сбрасываем флаг загрузки сведений о колонках.
 //заставим его перечитать данные с сервера

 hStmt1->m_PFlags.clear(hStmt1->PFLAG__CACHE_COLS_INFO);

 XSQLDA_V1_Wrapper xsqlda(2);

 svc::RemoteFB_Connector__GetColumns
  (tracer,
   spConnector,
   OpCtx,
   &hStmt1,
   xsqlda);

 if(xsqlda->sqld!=1)
 {
  //последний prepare(hStmt2) подготовил нам hStmt1.

  tracer(tso_msg_error,-1)<<"sqld:"<<xsqlda->sqld<<send;
 }//if

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_013__prepare_two_sql

////////////////////////////////////////////////////////////////////////////////
//TEST 014

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_014_ok__insert_with_returnings
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
 svc::remote_fb_tr_handle_type hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 for(size_t pass=0;pass!=3;)
 {
  ++pass;

  tracer<<L"------------------------ pass: "<<pass<<send;

  svc::RemoteFB_Connector__StmtPrepare
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    (short)cns.db_dialect_Ex.value(),
    "insert into DUAL (ID) values(0) returning ID;");

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
  _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));
  _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());
 }//for pass

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_014_ok__insert_with_returnings

////////////////////////////////////////////////////////////////////////////////
//TEST 015

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_015__prepare_after_close
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
 svc::remote_fb_tr_handle_type hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(/*n*/1);

 db_obj::t_dbvalue__i4   columnValue=-123;
 short                   columnInd=0;

 xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
 xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqlsubtype =0;
 xsqlda->sqlvar[0].sqlscale   =0;
 xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&columnValue);
 xsqlda->sqlvar[0].sqlind     =&columnInd;

 xsqlda->sqld=1;

 for(size_t pass=0;pass!=3;)
 {
  ++pass;

  tracer<<L"------------------------ pass: "<<pass<<send;

  _TSO_CHECK(!hStmt->m_pParentTr);

  svc::RemoteFB_Connector__StmtPrepare
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    (short)cns.db_dialect_Ex.value(),
    "select ID from DUAL");

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

  _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

  _TSO_CHECK(hStmt->m_pParentTr==nullptr);
  _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

  _TSO_CHECK(hStmt->m_EFlags.test(structure::negative_one)==0);

  //----------------------------------------
  svc::RemoteFB_Connector__StmtExecute
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    /*in*/nullptr,
    /*out*/nullptr);

  _TSO_CHECK(hStmt)
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

  _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

  _TSO_CHECK(hStmt->m_pParentTr==hTr);
  _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

  _TSO_CHECK(!hStmt->m_spFetchResult)

  _TSO_CHECK(hStmt->m_EFlags.equal(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));

  //----------------------------------------
  svc::RemoteFB_Connector__StmtFetch_ToRow
   (tracer,
    spConnector,
    OpCtx,
    &hStmt,
    xsqlda);

  _TSO_CHECK(hStmt)
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

  _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

  _TSO_CHECK(hStmt->m_pParentTr==hTr);
  _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

  _TSO_CHECK(hStmt->m_spFetchResult)

  _TSO_CHECK(hStmt->m_EFlags.equal(0));

  //----------------------------------------
  svc::RemoteFB_Connector__StmtClose
   (tracer,
    spConnector,
    &hStmt);

  _TSO_CHECK(hStmt)
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

  _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

  _TSO_CHECK(hStmt->m_pParentTr==nullptr);
  _TSO_CHECK(hStmt->m_pClosingTr==hTr);

  _TSO_CHECK(!hStmt->m_spFetchResult)

  _TSO_CHECK(hStmt->m_EFlags.equal(0));
 }//for pass

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----
 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==nullptr);
 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 _TSO_CHECK(!hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_015__prepare_after_close

////////////////////////////////////////////////////////////////////////////////
//TEST 016

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_016__prepare_after_hack_close
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
 svc::remote_fb_tr_handle_type hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(/*n*/1);

 db_obj::t_dbvalue__i4   columnValue=-123;
 short                   columnInd=0;

 xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
 xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqlsubtype =0;
 xsqlda->sqlvar[0].sqlscale   =0;
 xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&columnValue);
 xsqlda->sqlvar[0].sqlind     =&columnInd;

 xsqlda->sqld=1;

 for(size_t pass=0;pass!=3;)
 {
  ++pass;

  tracer<<L"------------------------ pass: "<<pass<<send;

  _TSO_CHECK(!hStmt->m_pParentTr);

  svc::RemoteFB_Connector__StmtPrepare
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    (short)cns.db_dialect_Ex.value(),
    "select ID from DUAL");

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

  _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

  _TSO_CHECK(hStmt->m_pParentTr==nullptr);
  _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

  _TSO_CHECK(hStmt->m_EFlags.test(structure::negative_one)==0);

  //----------------------------------------
  svc::RemoteFB_Connector__StmtExecute
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    /*in*/nullptr,
    /*out*/nullptr);

  _TSO_CHECK(hStmt)
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

  _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

  _TSO_CHECK(hStmt->m_pParentTr==hTr);
  _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

  _TSO_CHECK(!hStmt->m_spFetchResult)

  _TSO_CHECK(hStmt->m_EFlags.equal(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));

  //----------------------------------------
  svc::RemoteFB_Connector__StmtFetch_ToRow
   (tracer,
    spConnector,
    OpCtx,
    &hStmt,
    xsqlda);

  _TSO_CHECK(hStmt)
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

  _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

  _TSO_CHECK(hStmt->m_pParentTr==hTr);
  _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

  _TSO_CHECK(hStmt->m_spFetchResult)

  _TSO_CHECK(hStmt->m_EFlags.equal(0));

  //----------------------------------------
  svc::RemoteFB_Connector__StmtClose
   (tracer,
    spConnector,
    &hStmt);

  _TSO_CHECK(hStmt)
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

  _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

  _TSO_CHECK(hStmt->m_pParentTr==nullptr);
  _TSO_CHECK(hStmt->m_pClosingTr==hTr);

  _TSO_CHECK(!hStmt->m_spFetchResult)

  _TSO_CHECK(hStmt->m_EFlags.equal(0));

  //----------------------------------------
  svc::HACK__CloseStmt
   (tracer,
    spConnector,
    &hStmt);

  _TSO_CHECK(hStmt)
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
  _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

  _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

  _TSO_CHECK(hStmt->m_pParentTr==nullptr);
  _TSO_CHECK(hStmt->m_pClosingTr==hTr);

  _TSO_CHECK(!hStmt->m_spFetchResult)

  _TSO_CHECK(hStmt->m_EFlags.equal(0));
 }//for pass

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----
 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==nullptr);
 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 _TSO_CHECK(!hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_016__prepare_after_hack_close

////////////////////////////////////////////////////////////////////////////////
//TEST 017

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_017__err2__close_and_prepare
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
 svc::remote_fb_tr_handle_type hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(/*n*/1);

 db_obj::t_dbvalue__i4   columnValue=-123;
 short                   columnInd=0;

 xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
 xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqlsubtype =0;
 xsqlda->sqlvar[0].sqlscale   =0;
 xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&columnValue);
 xsqlda->sqlvar[0].sqlind     =&columnInd;

 xsqlda->sqld=1;

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (short)cns.db_dialect_Ex.value(),
   "select ID from DUAL");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==nullptr);
 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 _TSO_CHECK(hStmt->m_EFlags.test(structure::negative_one)==0);

 //----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 _TSO_CHECK(!hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));

 //----------------------------------------
 svc::RemoteFB_Connector__StmtFetch_ToRow
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   xsqlda);

 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 _TSO_CHECK(hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //----------------------------------------
 svc::RemoteFB_Connector__StmtClose
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==nullptr);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr);

 _TSO_CHECK(!hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //----------------------------------------
 svc::HACK__CloseStmt
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==nullptr);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr);

 _TSO_CHECK(!hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtPrepare
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     (short)cns.db_dialect_Ex.value(),
     "1+QUQUQUQUQ");
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   //1. close error
   //2. ibprovider hint message
   //3. prepare error
   errSvc::check_err_count(exc,3);

   errSvc::check_err_rec__srv_err__failed_to_close_stmt__reclose
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   errSvc::check_err_rec__stmt_err__failed_to_close_stmt
    (tracer,
     exc.get_record(1));

   // Dynamic SQL Error
   errSvc::check_err_rec__partially
    (tracer,
     exc.get_record(2),
     spConnector->GetData()->m_DBMS_Name,
     L"-104");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==nullptr);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr);

 _TSO_CHECK(!hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);
 _TSO_CHECK(!hTr);

 //-----
 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==nullptr);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr);

 _TSO_CHECK(!hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_017__err2__close_and_prepare

////////////////////////////////////////////////////////////////////////////////
//TEST 017

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_017__err2__close_and_prepare__fb3
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
 svc::remote_fb_tr_handle_type hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(/*n*/1);

 db_obj::t_dbvalue__i4   columnValue=-123;
 short                   columnInd=0;

 xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
 xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqlsubtype =0;
 xsqlda->sqlvar[0].sqlscale   =0;
 xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&columnValue);
 xsqlda->sqlvar[0].sqlind     =&columnInd;

 xsqlda->sqld=1;

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (short)cns.db_dialect_Ex.value(),
   "select ID from DUAL");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==nullptr);
 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 _TSO_CHECK(hStmt->m_EFlags.test(structure::negative_one)==0);

 //----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 _TSO_CHECK(!hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));

 //----------------------------------------
 svc::RemoteFB_Connector__StmtFetch_ToRow
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   xsqlda);

 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 _TSO_CHECK(hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //----------------------------------------
 svc::RemoteFB_Connector__StmtClose
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==nullptr);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr);

 _TSO_CHECK(!hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //----------------------------------------
 svc::HACK__CloseStmt
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==nullptr);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr);

 _TSO_CHECK(!hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtPrepare
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     (short)cns.db_dialect_Ex.value(),
     "1+QUQUQUQUQ");
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   //1. close error
   //2. ibprovider hint message
   //3. prepare error
   errSvc::check_err_count(exc,3);

   errSvc::check_err_rec__srv_err__failed_to_close_stmt__reclose__fb3
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   errSvc::check_err_rec__stmt_err__failed_to_close_stmt
    (tracer,
     exc.get_record(1));

   // Dynamic SQL Error
   errSvc::check_err_rec__partially
    (tracer,
     exc.get_record(2),
     spConnector->GetData()->m_DBMS_Name,
     L"-104");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==nullptr);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr);

 _TSO_CHECK(!hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----
 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(!hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==nullptr);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr);

 _TSO_CHECK(!hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_017__err2__close_and_prepare__fb3

////////////////////////////////////////////////////////////////////////////////
//TEST 018

void WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::test_018__err__prepare_of_deferred_exec
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
 svc::remote_fb_tr_handle_type hTr;

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (short)cns.db_dialect_Ex.value(),
   "select ID from DUAL");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==nullptr);
 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 _TSO_CHECK(hStmt->m_EFlags.test(structure::negative_one)==0);

 //----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 _TSO_CHECK(!hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtPrepare
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     (short)cns.db_dialect_Ex.value(),
     "select ID from DUAL");
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__attempt_to_prepare_stmt_with_open_cursor
    (tracer,
     exc.get_record(0),
     helper__get_StmtPrepare_subsystem_id(spConnector));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 _TSO_CHECK(!hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);
 _TSO_CHECK(!hTr);

 //-----
 _TSO_CHECK(hStmt)
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__DEFER_EXECUTE));

 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 _TSO_CHECK(hStmt->m_pParentTr==nullptr);
 _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

 _TSO_CHECK(!hStmt->m_spFetchResult)

 _TSO_CHECK(hStmt->m_EFlags.equal(0));

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_018__err__prepare_of_deferred_exec

////////////////////////////////////////////////////////////////////////////////

const wchar_t*
 WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::helper__get_StmtPrepare_bugcheck_src
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
   return L"RemoteFB__API_P12_LAZY_SEND__PrepareStatement::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13_LAZY_SEND__PrepareStatement::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_StmtPrepare_bugcheck_src

//------------------------------------------------------------------------
const wchar_t*
 WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::helper__get_StmtPrepare_subsystem_id
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
}//helper__get_StmtPrepare_subsystem_id

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_015__StmtPrepare__v2_lazy_send::tag_descr

struct WORK_Test_015__StmtPrepare__v2_lazy_send::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_015__StmtPrepare__v2_lazy_send::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_015__StmtPrepare__v2_lazy_send::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_015__StmtPrepare__v2_lazy_send::tag_descr
 WORK_Test_015__StmtPrepare__v2_lazy_send::sm_Tests[]=
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

 DEF_TEST_DESCR
  ("006.ok.insert",
   test_006_ok__insert)

 DEF_TEST_DESCR
  ("007.ok.insert",
   test_007_ok__insert)

 DEF_TEST_DESCR
  ("008.err.bad_sql",
   test_008__err__bad_sql)

 DEF_TEST_DESCR
  ("009.err.bad_sql",
   test_009__err__bad_sql)

 DEF_TEST_DESCR
  ("010.err.bad_sql",
   test_010__err__bad_sql)

 DEF_TEST_DESCR
  ("011.ok.select",
   test_011_ok__select)

 DEF_TEST_DESCR
  ("012.ok.select_with_param",
   test_012_ok__select_with_param)

 DEF_TEST_DESCR
  ("013.prepare_two_sql",
   test_013__prepare_two_sql)

 DEF_TEST_DESCR
  ("014.insert_with_returning",
   test_014_ok__insert_with_returnings)

 DEF_TEST_DESCR
  ("015.prepare_after_close",
   test_015__prepare_after_close)

 DEF_TEST_DESCR
  ("016.prepare_after_hack_close",
   test_016__prepare_after_hack_close)

 DEF_TEST_DESCR2
  ("017.err2.close_and_prepare",
   test_017__err2__close_and_prepare,
   "SRV<FB-3")

 DEF_TEST_DESCR2
  ("017.err2.close_and_prepare.fb3",
   test_017__err2__close_and_prepare__fb3,
   "SRV>=FB-3")

 DEF_TEST_DESCR
  ("018.err.prepare_of_deferred_exec",
   test_018__err__prepare_of_deferred_exec)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_015__StmtPrepare__v2_lazy_send

void WORK_Test_015__StmtPrepare__v2_lazy_send::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                                         //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__lazy_send)-1);    //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter ftestID("RemoteFB.WORK.015.StmtPrepare.v2.ptype__%1.%2");

 TTSO_TestData_v2 Data;

 for(;it;++it)
 {
  assert(it[iTest]<_DIM_(sm_Tests));
  assert(it[iPType]<_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__lazy_send));

  //----------------------------------------
  Data.m_RemoteFB__ProtocolType
   =g_TestCfg__RemoteFB__ProtocolTypes__lazy_send[it[iPType]];

  ftestID<<structure::flush
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
