////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_021__StmtClose__v1_no_lazy.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_021__StmtClose__v1_no_lazy::tag_impl

class WORK_Test_021__StmtClose__v1_no_lazy::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public: //---------------------------------------------------------------
 #ifdef NDEBUG
  static void test_002__bug_check__zero_stmt_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_003__bug_check__null_stmt_id
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_004__bug_check__bad_owner_cn
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 #endif

 public: //---------------------------------------------------------------
  static void test_005__err__no_cn
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public: //---------------------------------------------------------------
  static void test_006__err__not_prepared
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public: //---------------------------------------------------------------
  static void test_007__err__not_executed
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public: //---------------------------------------------------------------
  static void test_008__err__hack_drop_stmt
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_009__err__hack_close_stmt
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_009__err__hack_close_stmt__fb3
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_StmtClose_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);

  static const wchar_t* helper__get_StmtClose_subsystem_id
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_021__StmtClose__v1_no_lazy::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void WORK_Test_021__StmtClose__v1_no_lazy::tag_impl::test_001
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
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL");

 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));

 _TSO_CHECK(!hStmt->m_pParentTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute(tracer,
                                      spConnector,
                                      OpCtx,
                                      &hTr,
                                      &hStmt,
                                      /*in*/nullptr,
                                      /*out*/nullptr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hTr);

 _TSO_CHECK(hStmt->m_pParentTr==hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtClose(tracer,
                                    spConnector,
                                    &hStmt);

 _TSO_CHECK(hStmt);

 _TSO_CHECK(!hStmt->m_pParentTr);

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

 _TSO_CHECK(hStmt==nullptr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_001

////////////////////////////////////////////////////////////////////////////////
//TEST 002

#ifdef NDEBUG

void WORK_Test_021__StmtClose__v1_no_lazy::tag_impl::test_002__bug_check__zero_stmt_handle
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
 remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtClose(tracer,
                                     spConnector,
                                     &hStmt);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_StmtClose_bugcheck_src(spConnector),
     L"#001");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt==nullptr);
}//test_002__bug_check__zero_stmt_handle

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void WORK_Test_021__StmtClose__v1_no_lazy::tag_impl::test_003__bug_check__null_stmt_id
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
   svc::RemoteFB_Connector__StmtClose(tracer,
                                      spConnector,
                                      &hStmtCopy);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_StmtClose_bugcheck_src(spConnector),
     L"#002");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_003__bug_check__null_stmt_id

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 004

#ifdef NDEBUG

void WORK_Test_021__StmtClose__v1_no_lazy::tag_impl::test_004__bug_check__bad_owner_cn
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
  spConnector2(svc::RemoteFB_Connector__ConnectToDatabase
                                           (tracer,
                                            params,
                                            cns2));

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtClose(tracer,
                                      spConnector2,
                                      &hStmt);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_StmtClose_bugcheck_src(spConnector),
     L"#003");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

}//test_004__bug_check__bad_owner_cn

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 005

void WORK_Test_021__StmtClose__v1_no_lazy::tag_impl::test_005__err__no_cn
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
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL");

 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));

 _TSO_CHECK(!hStmt->m_pParentTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute(tracer,
                                      spConnector,
                                      OpCtx,
                                      &hTr,
                                      &hStmt,
                                      /*in*/nullptr,
                                      /*out*/nullptr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hTr);

 _TSO_CHECK(hStmt->m_pParentTr==hTr);

 //-----------------------------------------
 svc::HACK__CommitTr(tracer,spConnector,&hTr);

 assert(hTr);

 //Выполняем операцию отключения от базы данных минуя конектор

 svc::HACK__DetachCn(tracer,spConnector);

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtClose(tracer,
                                      spConnector,
                                      &hStmt);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__srv_err__invalid_req_handle
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 //дескриптор не трогается
 _TSO_CHECK(hStmt!=nullptr);

 _TSO_CHECK(hStmt->m_pParentTr);

 _TSO_CHECK(hStmt->m_pParentTr==hTr);
}//test_005__err__no_cn

////////////////////////////////////////////////////////////////////////////////
//TEST 006

void WORK_Test_021__StmtClose__v1_no_lazy::tag_impl::test_006__err__not_prepared
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
   svc::RemoteFB_Connector__StmtClose(tracer,
                                      spConnector,
                                      &hStmt);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__attempt_to_close_a_closed_cursor
    (tracer,
     exc.get_record(0),
     helper__get_StmtClose_subsystem_id(spConnector));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt==nullptr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_006__err__not_prepared

////////////////////////////////////////////////////////////////////////////////
//TEST 007

void WORK_Test_021__StmtClose__v1_no_lazy::tag_impl::test_007__err__not_executed
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
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL");

 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));

 _TSO_CHECK(!hStmt->m_pParentTr);

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtClose(tracer,
                                      spConnector,
                                      &hStmt);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__attempt_to_close_a_closed_cursor
    (tracer,
     exc.get_record(0),
     helper__get_StmtClose_subsystem_id(spConnector));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt==nullptr);

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
}//test_007__err__not_executed

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void WORK_Test_021__StmtClose__v1_no_lazy::tag_impl::test_008__err__hack_drop_stmt
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
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL");

 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));

 _TSO_CHECK(!hStmt->m_pParentTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute(tracer,
                                      spConnector,
                                      OpCtx,
                                      &hTr,
                                      &hStmt,
                                      /*in*/nullptr,
                                      /*out*/nullptr);

 //-----------------------------------------
 svc::HACK__DropStmt(tracer,
                     spConnector,
                     &hStmt);

 for(size_t nPass=0;nPass!=3;)
 {
  ++nPass;

  tracer<<L"-------------------------------- pass: "<<nPass<<send;

  try
  {
   svc::RemoteFB_Connector__StmtClose(tracer,
                                      spConnector,
                                      &hStmt);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__srv_err__invalid_req_handle
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   continue;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt);

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
}//test_008__err__hack_drop_stmt

////////////////////////////////////////////////////////////////////////////////
//TEST 009

void WORK_Test_021__StmtClose__v1_no_lazy::tag_impl::test_009__err__hack_close_stmt
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
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL");

 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));

 _TSO_CHECK(!hStmt->m_pParentTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute(tracer,
                                      spConnector,
                                      OpCtx,
                                      &hTr,
                                      &hStmt,
                                      /*in*/nullptr,
                                      /*out*/nullptr);

 //-----------------------------------------
 svc::HACK__CloseStmt(tracer,
                      spConnector,
                      &hStmt);

 for(size_t nPass=0;nPass!=3;)
 {
  ++nPass;

  tracer<<L"-------------------------------- pass: "<<nPass<<send;

  try
  {
   svc::RemoteFB_Connector__StmtClose(tracer,
                                      spConnector,
                                      &hStmt);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__srv_err__failed_to_close_stmt__reclose
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   continue;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt);

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
}//test_009__err__hack_close_stmt

////////////////////////////////////////////////////////////////////////////////
//TEST 009

void WORK_Test_021__StmtClose__v1_no_lazy::tag_impl::test_009__err__hack_close_stmt__fb3
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
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction(tracer,
                                           spConnector,
                                           &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL");

 _TSO_CHECK(hStmt->m_PFlags.test(hStmt->PFLAG__PREPARED));

 _TSO_CHECK(!hStmt->m_pParentTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute(tracer,
                                      spConnector,
                                      OpCtx,
                                      &hTr,
                                      &hStmt,
                                      /*in*/nullptr,
                                      /*out*/nullptr);

 //-----------------------------------------
 svc::HACK__CloseStmt(tracer,
                      spConnector,
                      &hStmt);

 for(size_t nPass=0;nPass!=3;)
 {
  ++nPass;

  tracer<<L"-------------------------------- pass: "<<nPass<<send;

  try
  {
   svc::RemoteFB_Connector__StmtClose(tracer,
                                      spConnector,
                                      &hStmt);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__srv_err__failed_to_close_stmt__reclose__fb3
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   continue;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt);

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
}//test_009__err__hack_close_stmt__fb3

////////////////////////////////////////////////////////////////////////////////

const wchar_t*
 WORK_Test_021__StmtClose__v1_no_lazy::tag_impl::helper__get_StmtClose_bugcheck_src
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
   return L"RemoteFB__API_P12__CloseStatement::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__CloseStatement::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_StmtClose_bugcheck_src

//------------------------------------------------------------------------
const wchar_t*
 WORK_Test_021__StmtClose__v1_no_lazy::tag_impl::helper__get_StmtClose_subsystem_id
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
}//helper__get_StmtClose_subsystem_id

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_021__StmtClose__v1_no_lazy::tag_descr

struct WORK_Test_021__StmtClose__v1_no_lazy::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_021__StmtClose__v1_no_lazy::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_021__StmtClose__v1_no_lazy::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_021__StmtClose__v1_no_lazy::tag_descr
 WORK_Test_021__StmtClose__v1_no_lazy::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001",
   test_001)

 //-----------------------------------------
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("002.bug_check.zero_stmt_handle",
   test_002__bug_check__zero_stmt_handle)

 DEF_TEST_DESCR
  ("003.bug_check.null_stmt_id",
   test_003__bug_check__null_stmt_id)

 DEF_TEST_DESCR
  ("004.bug_check.bad_owner_cn",
   test_004__bug_check__bad_owner_cn)
#endif

 //-----------------------------------------
 DEF_TEST_DESCR
  ("005.err.no_cn",
   test_005__err__no_cn)

 //-----------------------------------------
 DEF_TEST_DESCR
  ("006.err.not_prepared",
   test_006__err__not_prepared)

 //-----------------------------------------
 DEF_TEST_DESCR
  ("007.err.not_executed",
   test_007__err__not_executed)

 //-----------------------------------------
 DEF_TEST_DESCR
  ("008.err.close_after_hack_drop_stmt",
   test_008__err__hack_drop_stmt)

 DEF_TEST_DESCR2
  ("009.err.close_after_hack_close_stmt",
   test_009__err__hack_close_stmt,
   "SRV<FB-3")

 DEF_TEST_DESCR2
  ("009.err.close_after_hack_close_stmt.fb3",
   test_009__err__hack_close_stmt__fb3,
   "SRV>=FB-3")
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_021__StmtClose__v1_no_lazy

void WORK_Test_021__StmtClose__v1_no_lazy::create
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
 structure::str_formatter ftestID("RemoteFB.WORK.021.StmtClose.v1.ptype__%1.%2");

 TTSO_TestData_v2 Data;

 for(;it;++it)
 {
  assert(it[iTest]<_DIM_(sm_Tests));
  assert(it[iPType]<_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__no_lazy));

  //----------------------------------------
  Data.m_RemoteFB__ProtocolType
   =g_TestCfg__RemoteFB__ProtocolTypes__no_lazy[it[iPType]];

  ftestID<<structure::flush
         <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value())
         <<sm_Tests[it[iTest]].pTestSign;

  const TTSO_TestPtr spTest(new TTSO_TestFunc_v2(pParams,
                                                 ftestID.c_str(),
                                                 sm_Tests[it[iTest]].Func,
                                                 Data,
                                                 sm_Tests[it[iTest]].pExecRules));
  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
