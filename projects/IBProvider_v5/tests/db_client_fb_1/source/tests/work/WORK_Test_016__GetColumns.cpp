////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_016__GetColumns.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_016__GetColumns::tag_impl

class WORK_Test_016__GetColumns::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public: //---------------------------------------------------------------
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
 #endif

 public: //---------------------------------------------------------------
  static void test_004__err__not_prepared
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public: //---------------------------------------------------------------
 #ifdef NDEBUG
  static void test_005__err__incorrect_xsqlda_version
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 #endif

 public: //---------------------------------------------------------------
  static void test_006__ok__sqln0__column1
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_006__ok__sqln0__column2
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 private:
  static void helper_006
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data,
                const char*             str_SQL,
                short                   sqld);

 public:
  static void test_007__ok__column1
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_007__ok__column2
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public:
  static void test_008__ok__column2000
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_008__ok__column3000
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_008__ok__column5000
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_008__ok__column32k
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static void helper_008
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data,
                short                   cCols);

 public:
  static void test_009__err__drop_stmt
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_GetColumns_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);

  static const wchar_t* helper__get_GetColumns_subsystem_id
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_016__GetColumns

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void WORK_Test_016__GetColumns::tag_impl::test_001__bug_check__zero_stmt_handle
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

 XSQLDA_V1_Wrapper xsqlda(0);

 for(;;)
 {
  try
  {
   svc::remote_fb_stmt_handle_type hStmt(nullptr);

   svc::RemoteFB_Connector__GetColumns
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     xsqlda);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_GetColumns_bugcheck_src(spConnector),
     L"#002");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_001__bug_check__zero_stmt_handle

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 002

#ifdef NDEBUG

void WORK_Test_016__GetColumns::tag_impl::test_002__bug_check__null_stmt_id
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
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt==nullptr);


 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(0);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__GetColumns
    (tracer,
     spConnector,
     OpCtx,
     &hStmtCopy,
     xsqlda);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_GetColumns_bugcheck_src(spConnector),
     L"#003");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_002__bug_check__null_stmt_id

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void WORK_Test_016__GetColumns::tag_impl::test_003__bug_check__bad_owner_cn
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
 XSQLDA_V1_Wrapper xsqlda(0);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__GetColumns
    (tracer,
     spConnector2,
     OpCtx,
     &hStmt,
     xsqlda);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_GetColumns_bugcheck_src(spConnector),
     L"#004");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

}//test_003__bug_check__bad_owner_cn

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 004

void WORK_Test_016__GetColumns::tag_impl::test_004__err__not_prepared
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
 XSQLDA_V1_Wrapper xsqlda(0);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__GetColumns
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     xsqlda);
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
     helper__get_GetColumns_subsystem_id(spConnector));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_004__err__not_prepared

////////////////////////////////////////////////////////////////////////////////
//TEST 005

#ifdef NDEBUG

void WORK_Test_016__GetColumns::tag_impl::test_005__err__incorrect_xsqlda_version
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
 short bad_versions[]={-2,-1,0,2,3};

 XSQLDA_V1_Wrapper xsqlda(0);

 for(size_t i=0;i!=_DIM_(bad_versions);++i)
 {
  try
  {
   xsqlda->version=bad_versions[i];

   svc::RemoteFB_Connector__GetColumns
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     xsqlda);
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

   errSvc::check_err_rec__xsqlda_err__incorrect_version
    (tracer,
     exc.get_record(0),
     helper__get_GetColumns_bugcheck_src(spConnector),
     L"#001",
     L"xsqlda",
     bad_versions[i]);

   continue;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_005__err__incorrect_xsqlda_version

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 006 - column1

void WORK_Test_016__GetColumns::tag_impl::test_006__ok__sqln0__column1
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 helper_006
  (pParams,
   pCtx,
   Data,
   "select ID from DUAL;",
   1);
}//test_006__ok__sqln0__column1

////////////////////////////////////////////////////////////////////////////////
//TEST 006 - column2

void WORK_Test_016__GetColumns::tag_impl::test_006__ok__sqln0__column2
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 helper_006
  (pParams,
   pCtx,
   Data,
   "select ID,ID from DUAL;",
   2);
}//test_006__ok__sqln0__column2

////////////////////////////////////////////////////////////////////////////////
//HELPER 006

void WORK_Test_016__GetColumns::tag_impl::helper_006
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data,
                                            const char*         const str_SQL,
                                            short               const sqld)
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
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   str_SQL);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(0);

 svc::RemoteFB_Connector__GetColumns
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   xsqlda);

 svc::XSQLDA_check_sqld(tracer,xsqlda,sqld);
}//helper_006

////////////////////////////////////////////////////////////////////////////////
//TEST 007

void WORK_Test_016__GetColumns::tag_impl::test_007__ok__column1
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
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   "select ID from DUAL");

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 svc::RemoteFB_Connector__GetColumns
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   xsqlda);

 svc::XSQLDA_check_sqld
  (tracer,
   xsqlda,
   1);

 svc::XSQLVAR_check
  (tracer,
   &xsqlda->sqlvar[0],
   /*sqltype*/    isc_api::ibp_isc_sql_long,
   /*sqlsubtype*/ 0,
   /*sqlscale*/   0,
   /*sqllen*/     sizeof(isc_api::isc_long),
   /*sqlname*/    "ID",
   /*relname*/    "DUAL",
   /*ownname*/    "GAMER",
   /*aliasname*/  "ID");
}//test_007__ok__column1

////////////////////////////////////////////////////////////////////////////////
//TEST 007

void WORK_Test_016__GetColumns::tag_impl::test_007__ok__column2
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
 svc::RemoteFB_Connector__StmtPrepare
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     (unsigned short)cns.db_dialect_Ex.value(),
     "select N_1_0 as C1, N_1_1 as C2 from NUM");

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 svc::RemoteFB_Connector__GetColumns
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   xsqlda);

 svc::XSQLDA_check_sqld
  (tracer,
   xsqlda,
   2);

 svc::XSQLVAR_check
  (tracer,
   &xsqlda->sqlvar[0],
   /*sqltype*/    isc_api::ibp_isc_sql_short|1,
   /*sqlsubtype*/ 1,
   /*sqlscale*/   0,
   /*sqllen*/     sizeof(isc_api::isc_short),
   /*sqlname*/    "N_1_0",
   /*relname*/    "NUM",
   /*ownname*/    "GAMER",
   /*aliasname*/  "C1");

 svc::XSQLVAR_check
  (tracer,
   &xsqlda->sqlvar[1],
   /*sqltype*/    isc_api::ibp_isc_sql_short|1,
   /*sqlsubtype*/ 1,
   /*sqlscale*/   -1,
   /*sqllen*/     sizeof(isc_api::isc_short),
   /*sqlname*/    "N_1_1",
   /*relname*/    "NUM",
   /*ownname*/    "GAMER",
   /*aliasname*/  "C2");
}//test_007__ok__column2

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void WORK_Test_016__GetColumns::tag_impl::test_008__ok__column2000
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 helper_008
  (pParams,
   pCtx,
   Data,
   2000);
}//test_008__ok__column2000

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void WORK_Test_016__GetColumns::tag_impl::test_008__ok__column3000
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 helper_008
  (pParams,
   pCtx,
   Data,
   3000);
}//test_008__ok__column3000

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void WORK_Test_016__GetColumns::tag_impl::test_008__ok__column5000
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 helper_008
  (pParams,
   pCtx,
   Data,
   5000);
}//test_008__ok__column5000

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void WORK_Test_016__GetColumns::tag_impl::test_008__ok__column32k
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 helper_008
  (pParams,
   pCtx,
   Data,
   32000);
}//test_008__ok__column32k

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void WORK_Test_016__GetColumns::tag_impl::helper_008
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data,
                                            short               const cCols)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);
 assert(cCols>=0);

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
 std::vector<std::string> AliasNames;

 std::string sql("select ");

 {
  for(size_t n=0;n<size_t(cCols);++n)
  {
   std::string cc;

   for(size_t c=n;;)
   {
    cc+=char('A'+(c%26));

    if(c<26)
     break;

    c=c/26;
   }//for

   std::reverse(cc.begin(),cc.end());

   cc+="0";

   AliasNames.push_back(cc);

   if(n>0)
    sql+=",";

   //if(n>0 && (n%64)==0)
   // sql+="\n";

   sql+="ID as ";

   sql+=cc;
  }//for n

  sql+=" from DUAL;";
 }//local

 assert(AliasNames.size()==size_t(cCols));

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   sql);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda((size_t)cCols);

 svc::RemoteFB_Connector__GetColumns
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   xsqlda);

 svc::XSQLDA_check_sqld
  (tracer,
   xsqlda,
   cCols);

 for(size_t i=0;i!=(size_t)cCols;++i)
 {
  try
  {
   svc::XSQLVAR_check
    (&xsqlda->sqlvar[i],
     /*sqltype*/    isc_api::ibp_isc_sql_long,
     /*sqlsubtype*/ 0,
     /*sqlscale*/   0,
     /*sqllen*/     sizeof(isc_api::isc_long),
     /*sqlname*/    "ID",
     /*relname*/    "DUAL",
     /*ownname*/    "GAMER",
     /*aliasname*/  AliasNames[i]);
  }
  catch(...)
  {
   tracer(tso_msg_error,-1)<<L"XSQLVAR With problem: "<<i<<send;

   throw;
  }//catch
 }//for i
}//helper_008

////////////////////////////////////////////////////////////////////////////////
//TEST 009

void WORK_Test_016__GetColumns::tag_impl::test_009__err__drop_stmt
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
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   "select ID from DUAL");

 //-----------------------------------------
 (hStmt)->m_PFlags.clear(remote_fb::handles::RemoteFB__HandleData_Statement::PFLAG__CACHE_COLS_INFO);

 svc::HACK__DropStmt
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 try
 {
  svc::RemoteFB_Connector__GetColumns
   (tracer,
    spConnector,
    OpCtx,
    &hStmt,
    xsqlda);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__srv_err__invalid_req_handle
   (tracer,
    spConnector->GetData()->m_DBMS_Name,
    exc.get_record(0));

  errSvc::check_err_rec__stmt_err__errors_in_get_columns_operation
   (tracer,
    exc.get_record(1));

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_009__err__drop_stmt

////////////////////////////////////////////////////////////////////////////////

const wchar_t*
 WORK_Test_016__GetColumns::tag_impl::helper__get_GetColumns_bugcheck_src
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
  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_HLP__GetColumns_v01::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_StmtPrepare_bugcheck_src

//------------------------------------------------------------------------
const wchar_t*
 WORK_Test_016__GetColumns::tag_impl::helper__get_GetColumns_subsystem_id
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
  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return errSvc::sm_subsysID__remote_fb;

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_GetColumns_subsystem_id

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_016__GetColumns::tag_descr

struct WORK_Test_016__GetColumns::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_016__GetColumns::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_016__GetColumns::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_016__GetColumns::tag_descr
 WORK_Test_016__GetColumns::sm_Tests[]=
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
#endif

 DEF_TEST_DESCR
  ("004.err.not_prepared",
   test_004__err__not_prepared)

#ifdef NDEBUG
 DEF_TEST_DESCR
  ("005.err.incorrect_xsqlda_version",
   test_005__err__incorrect_xsqlda_version)
#endif

 DEF_TEST_DESCR
  ("006.ok.sqln0.column1",
   test_006__ok__sqln0__column1)

 DEF_TEST_DESCR
  ("006.ok.sqln0.column2",
   test_006__ok__sqln0__column2)

 DEF_TEST_DESCR
  ("007.ok.column1",
   test_007__ok__column1)

 DEF_TEST_DESCR
  ("007.ok.column2",
   test_007__ok__column2)

 DEF_TEST_DESCR
  ("008.ok.column2000",
   test_008__ok__column2000)

 DEF_TEST_DESCR
  ("008.ok.column3000",
   test_008__ok__column3000)

 DEF_TEST_DESCR
  ("008.ok.column5000",
   test_008__ok__column5000)

 DEF_TEST_DESCR2
  ("008.ok.column32k",
   test_008__ok__column32k,
   "NE__PSET02")

 DEF_TEST_DESCR
  ("009.err.drop_stmt",
   test_009__err__drop_stmt)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_016__GetColumns

void WORK_Test_016__GetColumns::create(TTSO_PushTest*      const pTestPusher,
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
 structure::str_formatter ftestID("RemoteFB.WORK.016.GetColumns.ptype__%1.%2");

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
