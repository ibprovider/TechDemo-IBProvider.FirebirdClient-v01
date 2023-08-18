////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_M01__WorkWithCursor.h"
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

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_M01__WorkWithCursor::tag_impl

class WORK_Test_M01__WorkWithCursor::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001__select
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_002__close_by_commit
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_003__close_by_rollback
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_004__close_by_sql_commit
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_005__close_by_sql_rollback
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
};//class WORK_Test_M01__WorkWithCursor

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void WORK_Test_M01__WorkWithCursor::tag_impl::test_001__select
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

 //-----------------------------------------
 for(size_t nPass=0;nPass!=5;)
 {
  ++nPass;

  tracer<<L"------------------------------ pass: "<<nPass<<send;

  svc::RemoteFB_Connector__StmtExecute
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    /*IN*/nullptr,
    /*OUT*/nullptr);

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_pParentTr==hTr);

  svc::RemoteFB_Connector__StmtClose
   (tracer,
    spConnector,
    &hStmt);

  _TSO_CHECK(hStmt);
  _TSO_CHECK(!hStmt->m_pParentTr);
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
}//test_001__select

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void WORK_Test_M01__WorkWithCursor::tag_impl::test_002__close_by_commit
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

 _TSO_CHECK(hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr);

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

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_pParentTr==hTr);

 //-----------------------------------------
 const auto copy_hTr(hTr);

 _TSO_CHECK(copy_hTr);

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr);

 _TSO_CHECK(copy_hTr->m_ID.is_null());
 _TSO_CHECK(!copy_hTr->m_pParentPort);

 _TSO_CHECK(copy_hTr->m_Statements.empty());

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
}//test_002__close_by_commit

////////////////////////////////////////////////////////////////////////////////
//TEST 003

void WORK_Test_M01__WorkWithCursor::tag_impl::test_003__close_by_rollback
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

 _TSO_CHECK(hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr);

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

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_pParentTr==hTr);

 //-----------------------------------------
 const auto copy_hTr(hTr);

 _TSO_CHECK(copy_hTr);

 svc::RemoteFB_Connector__Rollback
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr);

 _TSO_CHECK(copy_hTr->m_ID.is_null());
 _TSO_CHECK(!copy_hTr->m_pParentPort);

 _TSO_CHECK(copy_hTr->m_Statements.empty());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt);

 _TSO_CHECK(copy_hTr->m_ID.is_null());
 _TSO_CHECK(!copy_hTr->m_pParentPort);

 _TSO_CHECK(copy_hTr->m_Statements.empty());

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_003__close_by_rollback

////////////////////////////////////////////////////////////////////////////////
//TEST 004

void WORK_Test_M01__WorkWithCursor::tag_impl::test_004__close_by_sql_commit
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

 _TSO_CHECK(hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt2(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt2);

 _TSO_CHECK(hStmt2);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   /*phTr*/nullptr,
   &hStmt2,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "commit");

 _TSO_CHECK(hTr);

 _TSO_CHECK(hStmt2);
 _TSO_CHECK(!hStmt2->m_pParentTr);

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

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_pParentTr==hTr);

 //----------------------------------------- COMMIT
 const auto copy_hTr(hTr);

 _TSO_CHECK(copy_hTr);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt2,
   /*IN*/nullptr,
   /*OUT*/nullptr);

 _TSO_CHECK(!hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr);

 _TSO_CHECK(hStmt2);
 _TSO_CHECK(!hStmt2->m_pParentTr);

 _TSO_CHECK(copy_hTr->m_ID.is_null());
 _TSO_CHECK(!copy_hTr->m_pParentPort);

 _TSO_CHECK(copy_hTr->m_Statements.empty());

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
   &hStmt2);

 _TSO_CHECK(!hStmt2);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_004__close_by_sql_commit

////////////////////////////////////////////////////////////////////////////////
//TEST 005

void WORK_Test_M01__WorkWithCursor::tag_impl::test_005__close_by_sql_rollback
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

 _TSO_CHECK(!cns.db_dialect_Ex.null());

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

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL");

 _TSO_CHECK(hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt2(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt2);

 _TSO_CHECK(hStmt2);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   /*phTr*/nullptr,
   &hStmt2,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "rollback");

 _TSO_CHECK(hTr);

 _TSO_CHECK(hStmt2);
 _TSO_CHECK(!hStmt2->m_pParentTr);

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

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_pParentTr==hTr);

 //----------------------------------------- ROLLBACK
 const auto copy_hTr(hTr);

 _TSO_CHECK(copy_hTr);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt2,
   /*IN*/nullptr,
   /*OUT*/nullptr);

 _TSO_CHECK(!hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr);

 _TSO_CHECK(hStmt2);
 _TSO_CHECK(!hStmt2->m_pParentTr);

 _TSO_CHECK(copy_hTr->m_ID.is_null());
 _TSO_CHECK(!copy_hTr->m_pParentPort);

 _TSO_CHECK(copy_hTr->m_Statements.empty());

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
   &hStmt2);

 _TSO_CHECK(!hStmt2);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_005__close_by_sql_rollback

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_M01__WorkWithCursor::tag_descr

struct WORK_Test_M01__WorkWithCursor::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class WORK_Test_M01__WorkWithCursor::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,WORK_Test_M01__WorkWithCursor::tag_impl::func},

const WORK_Test_M01__WorkWithCursor::tag_descr
 WORK_Test_M01__WorkWithCursor::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001.select",
   test_001__select)

 DEF_TEST_DESCR
  ("002.close_by_commit",
   test_002__close_by_commit)

 DEF_TEST_DESCR
  ("003.close_by_rollback",
   test_003__close_by_rollback)

 DEF_TEST_DESCR
  ("004.close_by_sql_commit",
   test_004__close_by_sql_commit)

 DEF_TEST_DESCR
  ("005.close_by_sql_rollback",
   test_005__close_by_sql_rollback)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_M01__WorkWithCursor

void WORK_Test_M01__WorkWithCursor::create(TTSO_PushTest*      const pTestPusher,
                                           TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                             //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);   //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter ftestID("RemoteFB.WORK.M01.WorkWithCursor.ptype__%1.%2");

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
