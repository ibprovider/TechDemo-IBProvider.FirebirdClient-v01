////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_015__StmtPrepare__v1_no_lazy.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/dbms_fb/v02_5_0/api/db_obj__dbms_fb__v02_5_0__api__error_codes.h"
#include "source/error_services/ibp_sqlstate_codes.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl

class WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl
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
  static void test_006__err__bad_sql
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_007__ok__insert
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_007__ok__update_with_param1
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_007__ok__update_with_param2
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_007__ok__select1
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_007__ok__select2
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 private:
  static void helper_007__ok
               (TTSO_GlobalContext*           pParams,
                context_type*                 pCtx,
                const TTSO_TestData_v2&       Data,
                structure::t_const_str_box    SQL_str);

 public:
  static void test_008__prepare_after_execution
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_StmtPrepare_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_015__StmtPrepare__v1_no_lazy

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl::test_001__bug_check__zero_stmt_handle
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

void WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl::test_002__bug_check__null_stmt_id
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
   svc::RemoteFB_Connector__StmtPrepare
    (tracer,
     spConnector,
     OpCtx,
     /*pTr*/nullptr,
     &hStmtCopy,
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

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_002__bug_check__null_stmt_id

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl::test_003__bug_check__bad_owner_cn
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

void WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl::test_004__bug_check__bad_owner_cn_of_tr
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
}//test_004__bug_check__bad_owner_cn_of_tr

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 005

#ifdef NDEBUG

void WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl::test_005__bug_check__bad_tr
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

}//test_005__bug_check__bad_tr

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 006

void WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl::test_006__err__bad_sql
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
}//test_006__err__bad_sql

////////////////////////////////////////////////////////////////////////////////
//TEST 007 - insert

void WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl::test_007__ok__insert
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 helper_007__ok
  (pParams,
   pCtx,
   Data,
   "insert into DUAL (id) values(1);");
}//test_007__ok__insert

////////////////////////////////////////////////////////////////////////////////
//TEST 007 - update with param1

void WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl::test_007__ok__update_with_param1
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 helper_007__ok
  (pParams,
  pCtx,
  Data,
  "update DUAL set id=?;");
}//test_007__ok__update_with_param1

////////////////////////////////////////////////////////////////////////////////
//TEST 007 - update with param2

void WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl::test_007__ok__update_with_param2
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 helper_007__ok
  (pParams,
   pCtx,
   Data,
   "update DUAL set id=? where ID=?;");
}//test_007__ok__update_with_param2

////////////////////////////////////////////////////////////////////////////////
//TEST 007 - select1

void WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl::test_007__ok__select1
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 helper_007__ok
  (pParams,
   pCtx,
   Data,
   "select ID from DUAL;");
}//test_007__ok__select1

////////////////////////////////////////////////////////////////////////////////
//TEST 007 - select2

void WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl::test_007__ok__select2
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 helper_007__ok
  (pParams,
   pCtx,
   Data,
   "select ID,ID from DUAL;");
}//test_007__ok__select2

////////////////////////////////////////////////////////////////////////////////
//helper_007__ok

void WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl::helper_007__ok
                                           (TTSO_GlobalContext*        const pParams,
                                            context_type*              const pCtx,
                                            const TTSO_TestData_v2&          Data,
                                            structure::t_const_str_box const SQL_str)
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

 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   SQL_str);

 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt);

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
}//helper_007__ok

////////////////////////////////////////////////////////////////////////////////
//008

void WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl::test_008__prepare_after_execution
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

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*IN*/nullptr,
   /*OUT*/nullptr);

 for(size_t nPass=0;nPass!=3;)
 {
  ++nPass;

  tracer<<L"-------------------------------- pass: "<<nPass<<send;

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
      static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
      "select ID from DUAL");
   }
   catch(const ibp::t_ibp_error& exc)
   {
    typedef TestCheckErrors errSvc;

    errSvc::print_exception_ok(tracer,
                               exc);

    errSvc::check_err_count(exc,1);

    errSvc::check_err_rec__srv_err__prepare_stmt_with_open_cursor
     (tracer,
      spConnector->GetData()->m_DBMS_Name,
      exc.get_record(0));

    break;
   }//catch

   svc::Throw_WeWaitTheError();
  }//for[ever]
 }//for nPass

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
}//test_008__prepare_after_execution

////////////////////////////////////////////////////////////////////////////////

const wchar_t*
 WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl::helper__get_StmtPrepare_bugcheck_src
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
   return L"RemoteFB__API_P12__PrepareStatement::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__PrepareStatement::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_StmtPrepare_bugcheck_src

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_015__StmtPrepare__v1_no_lazy::tag_descr

struct WORK_Test_015__StmtPrepare__v1_no_lazy::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_015__StmtPrepare__v1_no_lazy::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_015__StmtPrepare__v1_no_lazy::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_015__StmtPrepare__v1_no_lazy::tag_descr
 WORK_Test_015__StmtPrepare__v1_no_lazy::sm_Tests[]=
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
  ("006.err.bad_sql",
   test_006__err__bad_sql)

 DEF_TEST_DESCR
  ("007.ok.insert",
   test_007__ok__insert)

 DEF_TEST_DESCR
  ("007.ok.update_with_param1",
   test_007__ok__update_with_param1)

 DEF_TEST_DESCR
  ("007.ok.update_with_param2",
   test_007__ok__update_with_param2)

 DEF_TEST_DESCR
  ("007.ok.select1",
   test_007__ok__select1)

 DEF_TEST_DESCR
  ("007.ok.select2",
   test_007__ok__select2)

 DEF_TEST_DESCR
  ("008.prepare_after_execution",
   test_008__prepare_after_execution)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_015__StmtPrepare__v1_no_lazy

void WORK_Test_015__StmtPrepare__v1_no_lazy::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                                       //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__no_lazy)-1);    //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter ftestID("RemoteFB.WORK.015.StmtPrepare.v1.ptype__%1.%2");

 TTSO_TestData_v2 Data;

 for(;it;++it)
 {
  assert(it[iTest]<_DIM_(sm_Tests));
  assert(it[iPType]<_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__no_lazy));

  //----------------------------------------
  Data.m_RemoteFB__ProtocolType
   =g_TestCfg__RemoteFB__ProtocolTypes__no_lazy[it[iPType]];

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
