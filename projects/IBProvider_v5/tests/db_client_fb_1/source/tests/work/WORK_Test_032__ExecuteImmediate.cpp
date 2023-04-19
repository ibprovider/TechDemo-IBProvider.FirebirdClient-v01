////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_032__ExecuteImmediate.h"
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
//class WORK_Test_032__ExecuteImmediate::tag_impl

class WORK_Test_032__ExecuteImmediate::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
 #ifdef NDEBUG
  static void test_001__bug_check__bad_tr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_002__bug_check__bad_owner_cn_of_tr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 #endif

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

 public: //---------------------------------------------------------------
  static void test_015__execute_error
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_016__execute2_error
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

  //----
  static void test_S007__insert__with_in_param1
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_S008__insert__with_in_param3
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  //----
  static void test_S009__insert__with_out_param1
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_S010__insert__with_out_param3
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_S011__insert__with_in1_out2
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_S012__insert__blob
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_exec_immed_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);

  static const wchar_t* helper__get_exec_immed_subsystem
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_032__ExecuteImmediate::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void WORK_Test_032__ExecuteImmediate::tag_impl::test_001__bug_check__bad_tr
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
 auto hCopyTr(hTr);

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__ExecuteImmediate
    (tracer,
     spConnector,
     OpCtx,
     &hCopyTr,
     static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
     "delete from DUAL",
     /*in*/nullptr,
     /*out*/nullptr); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__tr_err__bug_check__bad_tr_handle
    (tracer,
     exc.get_record(0),
     helper__get_exec_immed_bugcheck_src(spConnector),
     L"#001");

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;
  break;
 }//for[ever]

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_001__bug_check__bad_tr

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 002

#ifdef NDEBUG

void WORK_Test_032__ExecuteImmediate::tag_impl::test_002__bug_check__bad_owner_cn_of_tr
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
   svc::RemoteFB_Connector__ExecuteImmediate
    (tracer,
     spConnector2,
     OpCtx,
     &hTr,
     static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
     "delete from DUAL",
     /*in*/nullptr,
     /*out*/nullptr); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__tr_err__bug_check__bad_tr_handle
    (tracer,
     exc.get_record(0),
     helper__get_exec_immed_bugcheck_src(spConnector),
     L"#002");

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;
  break;
 }//for[ever]

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector2);
}//test_002__bug_check__bad_owner_cn_of_tr

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 007

#ifdef NDEBUG

void WORK_Test_032__ExecuteImmediate::tag_impl::test_007__bug_check__incorrect_input_sqld
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);

 _TSO_CHECK(hTr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(0);

 xsqlda->sqld=-1;

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__ExecuteImmediate
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     (remote_fb::protocol::P_SHORT)cns.db_dialect_Ex.value(),
     "insert into NUM (N_1_1) values (?);",
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
     helper__get_exec_immed_subsystem(spConnector),
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

void WORK_Test_032__ExecuteImmediate::tag_impl::test_008__bug_check__incorrect_input_sqln
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
 XSQLDA_V1_Wrapper xsqlda(0);

 xsqlda->sqld=2;

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__ExecuteImmediate
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     (remote_fb::protocol::P_SHORT)cns.db_dialect_Ex.value(),
     "insert into NUM (N_1_1) values (?);",
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
     helper__get_exec_immed_subsystem(spConnector),
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
}//test_008__bug_check__incorrect_input_sqln

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 009

#ifdef NDEBUG

void WORK_Test_032__ExecuteImmediate::tag_impl::test_009__bug_check__incorrect_output_sqld
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);

 _TSO_CHECK(hTr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(0);

 xsqlda->sqld=-1;

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__ExecuteImmediate
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     (remote_fb::protocol::P_SHORT)cns.db_dialect_Ex.value(),
     "insert into NUM (N_1_1) values (0) returning N_1_1;",
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
     helper__get_exec_immed_subsystem(spConnector),
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

void WORK_Test_032__ExecuteImmediate::tag_impl::test_010__bug_check__incorrect_output_sqln
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);

 _TSO_CHECK(hTr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(0);

 xsqlda->sqld=2;

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__ExecuteImmediate
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     (remote_fb::protocol::P_SHORT)cns.db_dialect_Ex.value(),
     "insert into NUM (N_1_1) values (0) returning N_1_1;",
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
     helper__get_exec_immed_subsystem(spConnector),
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

void WORK_Test_032__ExecuteImmediate::tag_impl::test_011__err__too_big_in_params_blr__1
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

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__ExecuteImmediate
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     (remote_fb::protocol::P_SHORT)cns.db_dialect_Ex.value(),
     "insert into NUM (N_1_1) values (?);",
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
     helper__get_exec_immed_subsystem(spConnector),
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
void WORK_Test_032__ExecuteImmediate::tag_impl::test_011__err__too_big_in_params_blr__2
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

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__ExecuteImmediate
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     (remote_fb::protocol::P_SHORT)cns.db_dialect_Ex.value(),
     "insert into NUM (N_1_1) values (?);",
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
     helper__get_exec_immed_subsystem(spConnector),
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

void WORK_Test_032__ExecuteImmediate::tag_impl::test_012__err__too_big_out_params_blr
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

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__ExecuteImmediate
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     (remote_fb::protocol::P_SHORT)cns.db_dialect_Ex.value(),
     "insert into NUM (N_1_1) values (0) returning N_1_1;",
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
     helper__get_exec_immed_subsystem(spConnector),
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
//TEST 013

#ifdef NDEBUG

void WORK_Test_032__ExecuteImmediate::tag_impl::test_013__bug_check__incorrect_input_version
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
   svc::RemoteFB_Connector__ExecuteImmediate
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     (remote_fb::protocol::P_SHORT)cns.db_dialect_Ex.value(),
     "insert into TEST_MODIFY_ROW (COL_INTEGER) values (?);",
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

void WORK_Test_032__ExecuteImmediate::tag_impl::test_014__bug_check__incorrect_output_version
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
   svc::RemoteFB_Connector__ExecuteImmediate
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     (remote_fb::protocol::P_SHORT)cns.db_dialect_Ex.value(),
     "insert into TEST_MODIFY_ROW (COL_INTEGER) values (0) returning COL_INTEGER;",
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
//TEST 015

void WORK_Test_032__ExecuteImmediate::tag_impl::test_015__execute_error
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
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__ExecuteImmediate
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
     "insert into NUM (TEST_ID) values (NULL);",
     /*pInXSQLDA*/nullptr,
     /*pOutXSQLDA*/nullptr);
  
   _TSO_CHECK(!hTr);
  }
  catch(ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__srv_err__bad_tr_handle
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_015__execute_error

////////////////////////////////////////////////////////////////////////////////
//TEST 016

void WORK_Test_032__ExecuteImmediate::tag_impl::test_016__execute2_error
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
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper out_xsqlda(3);

 out_xsqlda->sqld=2;

 signed __int32 out_xparam0_value=321;
 short          out_xparam0_ind=123;

 signed __int32 out_xparam1_value=233;
 short          out_xparam1_ind=432;

 out_xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 out_xsqlda->sqlvar[0].sqllen =sizeof(out_xparam0_value);
 out_xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&out_xparam0_value);
 out_xsqlda->sqlvar[0].sqlind =&out_xparam0_ind;

 out_xsqlda->sqlvar[1].sqltype=isc_api::ibp_isc_sql_long|1;
 out_xsqlda->sqlvar[1].sqllen =sizeof(out_xparam0_value);
 out_xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&out_xparam1_value);
 out_xsqlda->sqlvar[1].sqlind =&out_xparam1_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__ExecuteImmediate
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
     "insert into NUM (TEST_ID) values (NULL) returning N_1_0,N_2_1;",
     /*pInXSQLDA*/nullptr,
     /*pOutXSQLDA*/out_xsqlda);
  
   _TSO_CHECK(!hTr);
  }
  catch(ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__srv_err__bad_tr_handle
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_016__execute2_error

////////////////////////////////////////////////////////////////////////////////
//TEST S001

void WORK_Test_032__ExecuteImmediate::tag_impl::test_S001__insert__without_params
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);
 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "insert into NUM (TEST_ID) values (NULL);",
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S001__insert__without_params

////////////////////////////////////////////////////////////////////////////////
//TEST S002

void WORK_Test_032__ExecuteImmediate::tag_impl::test_S002__set_transaction
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
 svc::RemoteFB_Connector__ExecuteImmediate
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "set transaction;",
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());
 _TSO_CHECK(hTrCopy->m_pParentPort==nullptr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S002__set_transaction

////////////////////////////////////////////////////////////////////////////////
//TEST S003

void WORK_Test_032__ExecuteImmediate::tag_impl::test_S003__commit
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);
 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "commit;",
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 _TSO_CHECK(!hTrCopy->m_pParentPort);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S003__commit

////////////////////////////////////////////////////////////////////////////////
//TEST S004

void WORK_Test_032__ExecuteImmediate::tag_impl::test_S004__commit_retain
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);
 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);

 const auto hTrIDCopy=hTr->m_ID.get_value();

 svc::RemoteFB_Connector__ExecuteImmediate
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "commit retain;",
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/nullptr);

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
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S004__commit_retain

////////////////////////////////////////////////////////////////////////////////
//TEST S005

void WORK_Test_032__ExecuteImmediate::tag_impl::test_S005__rollback
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);
 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "rollback;",
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 _TSO_CHECK(!hTrCopy->m_pParentPort);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S005__rollback

////////////////////////////////////////////////////////////////////////////////
//TEST S006

void WORK_Test_032__ExecuteImmediate::tag_impl::test_S006__rollback_retain
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);
 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);

 const auto hTrIDCopy=hTr->m_ID.get_value();

 svc::RemoteFB_Connector__ExecuteImmediate
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "rollback retain;",
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTrCopy->m_ID.has_value());
 _TSO_CHECK(hTrCopy->m_ID.get_value()==hTrIDCopy);

 _TSO_CHECK(hTrCopy->m_pParentPort);

 //-----------------------------------------
 svc::RemoteFB_Connector__Rollback(tracer,
                                   spConnector,
                                   &hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S006__rollback_retain

////////////////////////////////////////////////////////////////////////////////
//TEST S007

void WORK_Test_032__ExecuteImmediate::tag_impl::test_S007__insert__with_in_param1
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);
 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "insert into NUM (N_1_0) values (?);",
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S007__insert__with_in_param1

////////////////////////////////////////////////////////////////////////////////
//TEST S008

void WORK_Test_032__ExecuteImmediate::tag_impl::test_S008__insert__with_in_param3
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);
 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

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
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into NUM (N_1_0,N_2_0,N_3_0) values (?,?,?);",
   /*pInXSQLDA*/xsqlda,
   /*pOutXSQLDA*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S008__insert__with_in_param3

////////////////////////////////////////////////////////////////////////////////
//TEST S009

void WORK_Test_032__ExecuteImmediate::tag_impl::test_S009__insert__with_out_param1
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);
 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 signed __int32 xparam0_value=5;
 short          xparam0_ind=-1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "insert into NUM (N_1_0) values (-5) returning N_1_0;",
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/xsqlda);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 _TSO_CHECK(xparam0_value==-5)
 _TSO_CHECK(xparam0_ind==0)
 
 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S009__insert__with_out_param1

////////////////////////////////////////////////////////////////////////////////
//TEST S010

void WORK_Test_032__ExecuteImmediate::tag_impl::test_S010__insert__with_out_param3
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);
 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(3);

 xsqlda->sqld=3;

 signed __int32 xparam0_value=6;
 short          xparam0_ind=-1;

 signed __int32 xparam1_value=7;
 short          xparam1_ind=0;

 signed __int32 xparam2_value=8;
 short          xparam2_ind=-2;

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
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into NUM (N_1_0,N_2_0,N_3_0) values (3,NULL,-543) returning N_1_0,N_2_0,N_3_0;",
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/xsqlda);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 _TSO_CHECK(xparam0_value==3);
 _TSO_CHECK(xparam1_value==0);
 _TSO_CHECK(xparam2_value==-543);

 _TSO_CHECK(xparam0_ind==0);
 _TSO_CHECK(xparam1_ind==-1);
 _TSO_CHECK(xparam2_ind==0);

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S010__insert__with_out_param3

////////////////////////////////////////////////////////////////////////////////
//TEST S011

void WORK_Test_032__ExecuteImmediate::tag_impl::test_S011__insert__with_in1_out2
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

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);
 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper in_xsqlda(3);

 in_xsqlda->sqld=1;

 signed __int32 in_xparam0_value=6;
 short          in_xparam0_ind=-1;

 in_xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 in_xsqlda->sqlvar[0].sqllen =sizeof(in_xparam0_value);
 in_xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&in_xparam0_value);
 in_xsqlda->sqlvar[0].sqlind =&in_xparam0_ind;

 //-----------------------------------------
 XSQLDA_V1_Wrapper out_xsqlda(3);

 out_xsqlda->sqld=2;

 signed __int32 out_xparam0_value=321;
 short          out_xparam0_ind=123;

 signed __int32 out_xparam1_value=233;
 short          out_xparam1_ind=432;

 out_xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 out_xsqlda->sqlvar[0].sqllen =sizeof(out_xparam0_value);
 out_xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&out_xparam0_value);
 out_xsqlda->sqlvar[0].sqlind =&out_xparam0_ind;

 out_xsqlda->sqlvar[1].sqltype=isc_api::ibp_isc_sql_long|1;
 out_xsqlda->sqlvar[1].sqllen =sizeof(out_xparam0_value);
 out_xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&out_xparam1_value);
 out_xsqlda->sqlvar[1].sqlind =&out_xparam1_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into NUM (N_1_0,N_2_0) values (?,62) returning N_1_0,N_2_0;",
   /*pInXSQLDA*/  in_xsqlda,
   /*pOutXSQLDA*/ out_xsqlda);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 _TSO_CHECK(out_xparam0_value==0);
 _TSO_CHECK(out_xparam1_value==62);

 _TSO_CHECK(out_xparam0_ind==-1);
 _TSO_CHECK(out_xparam1_ind==0);

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S011__insert__with_in1_out2

////////////////////////////////////////////////////////////////////////////////
//TEST S012

void WORK_Test_032__ExecuteImmediate::tag_impl::test_S012__insert__blob
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
 db_obj::DB_IBBLOBID newBlobID;

 svc::remote_fb_blob_handle_type hBlob;

 svc::RemoteFB_Connector__CreateBlob
  (tracer,
   spConnector,
   &hTr,
   &hBlob,
   &newBlobID);

 _TSO_CHECK(hBlob);
 
 const char testBlobData[]={0,1,2,3,4,5,6,0,8,9};

 svc::RemoteFB_Connector__WriteBlob
  (tracer,
   spConnector,
   &hBlob,
   sizeof(testBlobData),
   testBlobData);

 svc::RemoteFB_Connector__CloseBlob
  (tracer,
   spConnector,
   &hBlob);

 //-----------------------------------------
 XSQLDA_V1_Wrapper in_xsqlda(3);

 in_xsqlda->sqld=1;

 in_xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_blob;
 in_xsqlda->sqlvar[0].sqllen =sizeof(newBlobID);
 in_xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&newBlobID);
 in_xsqlda->sqlvar[0].sqlind =nullptr;

 //-----------------------------------------
 XSQLDA_V1_Wrapper out_xsqlda(3);

 out_xsqlda->sqld=1;

 db_obj::DB_IBBLOBID out_xparam0_value={};

 out_xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_blob;
 out_xsqlda->sqlvar[0].sqllen =sizeof(out_xparam0_value);
 out_xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&out_xparam0_value);
 out_xsqlda->sqlvar[0].sqlind =nullptr;

 //-----------------------------------------
 svc::RemoteFB_Connector__ExecuteImmediate
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into BIN_BLOB_TABLE (BIN_DATA) values (?) returning BIN_DATA;",
   /*pInXSQLDA*/  in_xsqlda,
   /*pOutXSQLDA*/ out_xsqlda);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //----------------------------------------- read blob data
 svc::RemoteFB_Connector__OpenBlob
  (tracer,
   spConnector,
   &hTr,
   &hBlob,
   out_xparam0_value);

 _TSO_CHECK(hBlob);

 //-----------------------------------------
 char readedBlobData[sizeof(testBlobData)+10]={};

 size_t actualReadedData=0;

 svc::RemoteFB_Connector__ReadBlob
  (tracer,
   spConnector,
   &hBlob,
   sizeof(readedBlobData),
   readedBlobData,
   &actualReadedData);

 if(!structure::equal(testBlobData,
                       _END_(testBlobData),
                       readedBlobData,
                       readedBlobData+actualReadedData))
 {
  tracer(tso_msg_error,-1)<<L"Readed wrong blob data!"<<send;
 }//if

 //-----------------------------------------
 svc::RemoteFB_Connector__CloseBlob
  (tracer,
   spConnector,
   &hBlob);

 _TSO_CHECK(!hBlob);

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
}//test_S012__insert__blob

////////////////////////////////////////////////////////////////////////////////

const wchar_t* WORK_Test_032__ExecuteImmediate::tag_impl::helper__get_exec_immed_bugcheck_src
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
   return L"RemoteFB__API_P12__ExecuteImmediate::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__ExecuteImmediate::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_exec_immed_bugcheck_src

//------------------------------------------------------------------------
const wchar_t* WORK_Test_032__ExecuteImmediate::tag_impl::helper__get_exec_immed_subsystem
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
}//helper__get_exec_immed_subsystem

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_032__ExecuteImmediate::tag_descr

struct WORK_Test_032__ExecuteImmediate::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_032__ExecuteImmediate::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_032__ExecuteImmediate::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_032__ExecuteImmediate::tag_descr
 WORK_Test_032__ExecuteImmediate::sm_Tests[]=
{
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("001.bug_check.bad_tr",
   test_001__bug_check__bad_tr)

 DEF_TEST_DESCR
  ("002.bug_check.bad_owner_cn_of_tr",
   test_002__bug_check__bad_owner_cn_of_tr)
#endif

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

#ifdef NDEBUG
 DEF_TEST_DESCR
  ("013.bug_check.incorrect_input_version",
   test_013__bug_check__incorrect_input_version)

 DEF_TEST_DESCR
  ("014.bug_check.incorrect_output_version",
   test_014__bug_check__incorrect_output_version)
#endif

 DEF_TEST_DESCR
  ("015.execute_error",
   test_015__execute_error)

 DEF_TEST_DESCR
  ("016.execute2_error",
   test_016__execute2_error)

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
  ("S007.insert.with_in_param1",
   test_S007__insert__with_in_param1)

 DEF_TEST_DESCR
  ("S008.insert.with_in_param3",
   test_S008__insert__with_in_param3)

 DEF_TEST_DESCR
  ("S009.insert.with_out_param1",
   test_S009__insert__with_out_param1)

 DEF_TEST_DESCR
  ("S010.insert.with_out_param3",
   test_S010__insert__with_out_param3)

 DEF_TEST_DESCR
  ("S011.insert.with_in1_out2",
   test_S011__insert__with_in1_out2)

 DEF_TEST_DESCR
  ("S012.insert.blob",
   test_S012__insert__blob)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_032__ExecuteImmediate

void WORK_Test_032__ExecuteImmediate::create(TTSO_PushTest*      const pTestPusher,
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
  ftestID("RemoteFB.WORK.032.ExecuteImmediate.ptype__%1.%2");

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
