////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_005__Rollback__v2_lazy_send.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_005__Rollback__v2_lazy_send::tag_impl

class WORK_Test_005__Rollback__v2_lazy_send::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_100__check_drop_stmt_before_op
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_101__check_drop_closed_blob_before_op
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_102__check_drop_canceled_blob_before_op
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
};//class WORK_Test_005__Rollback__v2_lazy_send

////////////////////////////////////////////////////////////////////////////////
//TEST 100

void WORK_Test_005__Rollback__v2_lazy_send::tag_impl::test_100__check_drop_stmt_before_op
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
 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());
 _TSO_CHECK(hTr->m_ID.has_value())

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
   "INSERT INTO DUAL (ID) VALUES (2)");

 //-----------------------------------------
 const auto hCopyStmt(hStmt);

 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt);

 _TSO_CHECK(hCopyStmt);
 _TSO_CHECK(hCopyStmt->m_ID.is_wait_drop());

 _TSO_CHECK(spConnector->GetData()->DeletedStmtList__GetCount()==1);
 _TSO_CHECK(spConnector->GetData()->DeletedStmtList__GetHead()==hCopyStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__Rollback
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 _TSO_CHECK(hCopyStmt);
 _TSO_CHECK(hCopyStmt->m_ID.is_null());

 _TSO_CHECK(spConnector->GetData()->DeletedStmtList__GetCount()==0);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_100__check_drop_stmt_before_op

////////////////////////////////////////////////////////////////////////////////
//TEST 101

void WORK_Test_005__Rollback__v2_lazy_send::tag_impl::test_101__check_drop_closed_blob_before_op
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
 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());
 _TSO_CHECK(hTr->m_ID.has_value())

 //-----------------------------------------
 svc::remote_fb_blob_handle_type hBlob(nullptr);

 db_obj::DB_IBBLOBID blobID={};

 svc::RemoteFB_Connector__CreateBlob
  (tracer,
   spConnector,
   &hTr,
   &hBlob,
   &blobID);

 _TSO_CHECK(hTr);

 _TSO_CHECK(hBlob);
 _TSO_CHECK(hBlob->m_pParentTr==hTr.ptr());
 _TSO_CHECK(hBlob->m_ID.has_value());

 //-----------------------------------------
 const auto hCopyBlob(hBlob);

 _TSO_CHECK(hCopyBlob);

 svc::RemoteFB_Connector__CloseBlob
  (tracer,
   spConnector,
   &hBlob);

 _TSO_CHECK(!hBlob);

 _TSO_CHECK(hCopyBlob->m_ID.is_wait_close());
 _TSO_CHECK(hCopyBlob->m_pParentTr==hTr);
 _TSO_CHECK(hCopyBlob->m_pOwnerCnNClosedBlobList==spConnector->GetData());

 _TSO_CHECK(spConnector->GetData()->DeletedBlobList__GetCount()==1);
 _TSO_CHECK(spConnector->GetData()->DeletedBlobList__GetHead()==hCopyBlob);

 //-----------------------------------------
 svc::RemoteFB_Connector__Rollback
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 _TSO_CHECK(hCopyBlob)
 _TSO_CHECK(hCopyBlob->m_ID.is_null());
 _TSO_CHECK(hCopyBlob->m_pParentTr==nullptr);
 _TSO_CHECK(hCopyBlob->m_pOwnerCnNClosedBlobList==nullptr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_101__check_drop_closed_blob_before_op

////////////////////////////////////////////////////////////////////////////////
//TEST 102

void WORK_Test_005__Rollback__v2_lazy_send::tag_impl::test_102__check_drop_canceled_blob_before_op
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
 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());
 _TSO_CHECK(hTr->m_ID.has_value())

 //-----------------------------------------
 svc::remote_fb_blob_handle_type hBlob(nullptr);

 db_obj::DB_IBBLOBID blobID={};

 svc::RemoteFB_Connector__CreateBlob
  (tracer,
   spConnector,
   &hTr,
   &hBlob,
   &blobID);

 _TSO_CHECK(hTr);

 _TSO_CHECK(hBlob);
 _TSO_CHECK(hBlob->m_pParentTr==hTr.ptr());
 _TSO_CHECK(hBlob->m_ID.has_value());

 //-----------------------------------------
 const auto hCopyBlob(hBlob);

 _TSO_CHECK(hCopyBlob);

 svc::RemoteFB_Connector__CancelBlob
  (tracer,
   spConnector,
   &hBlob);

 _TSO_CHECK(!hBlob);

 _TSO_CHECK(hCopyBlob->m_ID.is_wait_cancel());
 _TSO_CHECK(hCopyBlob->m_pParentTr==hTr);
 _TSO_CHECK(hCopyBlob->m_pOwnerCnNClosedBlobList==spConnector->GetData());

 _TSO_CHECK(spConnector->GetData()->DeletedBlobList__GetCount()==1);
 _TSO_CHECK(spConnector->GetData()->DeletedBlobList__GetHead()==hCopyBlob);

 //-----------------------------------------
 svc::RemoteFB_Connector__Rollback
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 _TSO_CHECK(hCopyBlob)
 _TSO_CHECK(hCopyBlob->m_ID.is_null());
 _TSO_CHECK(hCopyBlob->m_pParentTr==nullptr);
 _TSO_CHECK(hCopyBlob->m_pOwnerCnNClosedBlobList==nullptr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_102__check_drop_canceled_blob_before_op

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_005__Rollback__v2_lazy_send::tag_descr

struct WORK_Test_005__Rollback__v2_lazy_send::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_005__Rollback__v2_lazy_send::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_005__Rollback__v2_lazy_send::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_005__Rollback__v2_lazy_send::tag_descr
 WORK_Test_005__Rollback__v2_lazy_send::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("100.check_drop_stmt_before_op",
   test_100__check_drop_stmt_before_op)

 DEF_TEST_DESCR
  ("101.check_drop_closed_blob_before_op",
   test_101__check_drop_closed_blob_before_op)

 DEF_TEST_DESCR
  ("102.check_drop_canceled_blob_before_op",
   test_102__check_drop_canceled_blob_before_op)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_005__Rollback__v2_lazy_send

void WORK_Test_005__Rollback__v2_lazy_send::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                                          //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__lazy_send)-1);     //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter
  ftestID("RemoteFB.WORK.005.Trans.Rollback.v2.ptype__%1.%2");

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
