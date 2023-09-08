////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_018__GetParameters.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_018__GetParameters::tag_impl

class WORK_Test_018__GetParameters::tag_impl
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
  static void test_006__ok__sqln0__param1
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_006__ok__sqln0__param2
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
  static void test_008__ok__paramN
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_008__ok__param2000
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_008__ok__param3000
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_008__ok__param5000
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_008__ok__param32k
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  struct tag_data_008
  {
   std::string name;
   size_t      precision;
   size_t      scale;
  };//struct tag_data_008

  static void helper_008
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data,
                short                   cCols);

 public:
  static void test_007__ok__param1
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_007__ok__param2
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public:
  static void test_009__err__drop_stmt
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_GetParams_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);

  static const wchar_t* helper__get_GetParams_subsystem_id
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_018__GetParameters::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void WORK_Test_018__GetParameters::tag_impl::test_001__bug_check__zero_stmt_handle
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

   svc::RemoteFB_Connector__GetParameters
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
     helper__get_GetParams_bugcheck_src(spConnector),
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

void WORK_Test_018__GetParameters::tag_impl::test_002__bug_check__null_stmt_id
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
   svc::RemoteFB_Connector__GetParameters
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
     helper__get_GetParams_bugcheck_src(spConnector),
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

void WORK_Test_018__GetParameters::tag_impl::test_003__bug_check__bad_owner_cn
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
   svc::RemoteFB_Connector__GetParameters
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
     helper__get_GetParams_bugcheck_src(spConnector),
     L"#004");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

}//test_003__bug_check__bad_owner_cn

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 004

void WORK_Test_018__GetParameters::tag_impl::test_004__err__not_prepared
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
   svc::RemoteFB_Connector__GetParameters
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
     helper__get_GetParams_subsystem_id(spConnector));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_004__err__not_prepared

////////////////////////////////////////////////////////////////////////////////
//TEST 005

#ifdef NDEBUG

void WORK_Test_018__GetParameters::tag_impl::test_005__err__incorrect_xsqlda_version
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

   svc::RemoteFB_Connector__GetParameters
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

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_code
    (exc.com_code(),
     E_FAIL);

   errSvc::check_err_rec__xsqlda_err__incorrect_version
    (tracer,
     exc.get_record(0),
     helper__get_GetParams_bugcheck_src(spConnector),
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

void WORK_Test_018__GetParameters::tag_impl::test_006__ok__sqln0__param1
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 helper_006
  (pParams,
   pCtx,
   Data,
   "select * from DUAL where ID=?;",
   1);
}//helper__test_005__err__incorrect_xsqlda_version

////////////////////////////////////////////////////////////////////////////////
//TEST 006 - column2

void WORK_Test_018__GetParameters::tag_impl::test_006__ok__sqln0__param2
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 helper_006
  (pParams,
   pCtx,
   Data,
   "select * from DUAL where ID=? AND ID=?;",
   2);
}//test_006__ok__sqln0__param2

////////////////////////////////////////////////////////////////////////////////
//HELPER 006

void WORK_Test_018__GetParameters::tag_impl::helper_006
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

 svc::RemoteFB_Connector__GetParameters
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   xsqlda);

 svc::XSQLDA_check_sqld(tracer,xsqlda,sqld);
}//helper_006

////////////////////////////////////////////////////////////////////////////////
//TEST 007

void WORK_Test_018__GetParameters::tag_impl::test_007__ok__param1
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
   "insert into NUM_ARRAY_NN (N_1_1) values(?);");

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 svc::RemoteFB_Connector__GetParameters
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
   /*sqltype*/    isc_api::ibp_isc_sql_array,
   /*sqlsubtype*/ 0,
   /*sqlscale*/   0,
   /*sqllen*/     sizeof(db_obj::DB_IBARRAYID),
   /*sqlname*/    "N_1_1",
   /*relname*/    "NUM_ARRAY_NN",
   /*ownname*/    "",
   /*aliasname*/  "");
}//test_007__ok__param1

////////////////////////////////////////////////////////////////////////////////
//TEST 007

void WORK_Test_018__GetParameters::tag_impl::test_007__ok__param2
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
   "insert into TEST_MODIFY_ROW (COL_INTEGER,COL_INT_ARRAY) values(?,?);");

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 svc::RemoteFB_Connector__GetParameters
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
   /*sqltype*/    isc_api::ibp_isc_sql_long|1,
   /*sqlsubtype*/ 0,
   /*sqlscale*/   0,
   /*sqllen*/     sizeof(isc_api::isc_long),
   /*sqlname*/    "",
   /*relname*/    "",
   /*ownname*/    "",
   /*aliasname*/  "");

 svc::XSQLVAR_check
  (tracer,
   &xsqlda->sqlvar[1],
   /*sqltype*/    isc_api::ibp_isc_sql_array|1
   ,
   /*sqlsubtype*/ 0,
   /*sqlscale*/   0,
   /*sqllen*/     sizeof(db_obj::DB_IBARRAYID),
   /*sqlname*/    "COL_INT_ARRAY",
   /*relname*/    "TEST_MODIFY_ROW",
   /*ownname*/    "",
   /*aliasname*/  "");
}//test_007__ok__param2

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void WORK_Test_018__GetParameters::tag_impl::test_008__ok__paramN
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
   1400);
}//test_008__ok__paramN

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void WORK_Test_018__GetParameters::tag_impl::test_008__ok__param2000
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
}//test_008__ok__param2000

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void WORK_Test_018__GetParameters::tag_impl::test_008__ok__param3000
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
}//test_008__ok__param3000

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void WORK_Test_018__GetParameters::tag_impl::test_008__ok__param5000
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
}//test_008__ok__param5000

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void WORK_Test_018__GetParameters::tag_impl::test_008__ok__param32k
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
   32535);
}//test_008__ok__param32k

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void WORK_Test_018__GetParameters::tag_impl::helper_008
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
 std::vector<tag_data_008> Names;

 {
  structure::str_formatter fname("N_%1_%2");

  while(Names.size()<size_t(cCols))
  {
   for(size_t p=1;p!=9 && Names.size()<size_t(cCols);++p)
   {
    for(size_t s=0;s<=p && Names.size()<size_t(cCols);++s)
    {
     fname<<structure::flush<<p<<s;

     tag_data_008 d;

     d.name=fname.str();

     d.precision=p;

     d.scale=s;

     Names.push_back(d);
    }//for s
   }//for p
  }//local

  assert(Names.size()==size_t(cCols));
 }//local

 std::string sql="select * from NUM where ";

 for(size_t i=0;i!=Names.size();++i)
 {
  if(i>0)
   sql+=" AND ";

  sql+=Names[i].name;
  sql+="=?";
 }//for i

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

 svc::RemoteFB_Connector__GetParameters
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
   short sqltype;
   short sqllen;

   if(Names[i].precision<5)
   {
    sqltype=isc_api::ibp_isc_sql_short;
    sqllen=2;
   }
   else
   if(Names[i].precision<10)
   {
    sqltype=isc_api::ibp_isc_sql_long;
    sqllen=4;
   }
   else
   {
    sqltype=isc_api::ibp_isc_sql_int64;
    sqllen=8;
   }

   svc::XSQLVAR_check
    (&xsqlda->sqlvar[i],
     /*sqltype*/    sqltype|1,
     /*sqlsubtype*/ 1,
     /*sqlscale*/   -(short)Names[i].scale,
     /*sqllen*/     sqllen,
     /*sqlname*/    "",
     /*relname*/    "",
     /*ownname*/    "",
     /*aliasname*/  "");
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

void WORK_Test_018__GetParameters::tag_impl::test_009__err__drop_stmt
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
   "select ID from DUAL where ID=?");

 //-----------------------------------------
 (hStmt)->m_PFlags.clear(remote_fb::handles::RemoteFB__HandleData_Statement::PFLAG__CACHE_PARAMS_INFO);

 svc::HACK__DropStmt
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 try
 {
  svc::RemoteFB_Connector__GetParameters
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

  errSvc::check_err_rec__stmt_err__errors_in_get_parameters_operation
   (tracer,
    exc.get_record(1));

  return;
 }//catch

  svc::Throw_WeWaitTheError();
}//test_009__err__drop_stmt

////////////////////////////////////////////////////////////////////////////////

const wchar_t*
 WORK_Test_018__GetParameters::tag_impl::helper__get_GetParams_bugcheck_src
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
   return L"RemoteFB__API_HLP__GetParameters_v01::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_GetParams_bugcheck_src

//------------------------------------------------------------------------
const wchar_t*
 WORK_Test_018__GetParameters::tag_impl::helper__get_GetParams_subsystem_id
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
}//helper__get_GetParams_subsystem_id

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_018__GetParameters::tag_descr

struct WORK_Test_018__GetParameters::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_018__GetParameters::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_018__GetParameters::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_018__GetParameters::tag_descr
 WORK_Test_018__GetParameters::sm_Tests[]=
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

 //-----------------------------------------------------------------------
 DEF_TEST_DESCR
  ("004.err.not_prepared",
   test_004__err__not_prepared)

 //-----------------------------------------------------------------------
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("005.err.incorrect_xsqlda_version",
   test_005__err__incorrect_xsqlda_version)
#endif

 //-----------------------------------------------------------------------
 DEF_TEST_DESCR
  ("006.ok.sqln0.param1",
   test_006__ok__sqln0__param1)

 DEF_TEST_DESCR
  ("006.ok.sqln0.param2",
   test_006__ok__sqln0__param2)

 DEF_TEST_DESCR
  ("007.ok.param1",
   test_007__ok__param1)

 DEF_TEST_DESCR
  ("007.ok.param2",
   test_007__ok__param2)

 DEF_TEST_DESCR
  ("008.ok.paramN",
   test_008__ok__paramN)
 
 //----------------------------------------- Problem with Server <FB-3
 DEF_TEST_DESCR2
  ("008.ok.param2000",
   test_008__ok__param2000,
   "SRV!=FB || SRV>=FB-3")

 DEF_TEST_DESCR2
  ("008.ok.param3000",
   test_008__ok__param3000,
   "SRV!=FB || SRV>=FB-3")

 DEF_TEST_DESCR2
  ("008.ok.param5000",
   test_008__ok__param5000,
   "SRV!=FB || SRV>=FB-3")

 // FB3: Stack overflow
 //DEF_TEST_DESCR2
 // ("008.ok.param32k",
 //  test_008__ok__param32k,
 //  "SRV!=FB || SRV>=FB-3")

 //-----------------------------------------
 DEF_TEST_DESCR
  ("009.err.drop_stmt",
   test_009__err__drop_stmt)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_018__GetParameters

void WORK_Test_018__GetParameters::create(TTSO_PushTest*      const pTestPusher,
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
 structure::str_formatter ftestID("RemoteFB.WORK.018.GetParameters.ptype__%1.%2");

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
}/*nms ibp_tests*/}/*nms lcpi*/
