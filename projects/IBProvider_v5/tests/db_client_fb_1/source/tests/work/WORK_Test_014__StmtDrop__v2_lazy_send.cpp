////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_014__StmtDrop__v2_lazy_send.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_014__StmtDrop__v2_lazy_send::tag_impl

class WORK_Test_014__StmtDrop__v2_lazy_send::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
#ifdef NDEBUG
  static void test_001__bug_check__zero_stmt_handle
               (TTSO_GlobalContext* const pParams,
                context_type*       const pCtx,
                const TTSO_TestData_v2&   Data);

  static void test_002__bug_check__null_stmt_id
               (TTSO_GlobalContext* const pParams,
                context_type*       const pCtx,
                const TTSO_TestData_v2&   Data);

  static void test_003__bug_check__bad_stmt_cn_owner
               (TTSO_GlobalContext* const pParams,
                context_type*       const pCtx,
                const TTSO_TestData_v2&   Data);
#endif

 public:
  static void test_100__drop_defered
               (TTSO_GlobalContext* const pParams,
                context_type*       const pCtx,
                const TTSO_TestData_v2&   Data);

  static void test_101__drop_allocated
               (TTSO_GlobalContext* const pParams,
                context_type*       const pCtx,
                const TTSO_TestData_v2&   Data);

  static void test_102__send_drop_op_to_srv
               (TTSO_GlobalContext* const pParams,
                context_type*       const pCtx,
                const TTSO_TestData_v2&   Data);

 private:
  static const wchar_t* helper__get_StmtDrop_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_014__StmtDrop__v2_lazy_send::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void WORK_Test_014__StmtDrop__v2_lazy_send::tag_impl::test_001__bug_check__zero_stmt_handle
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
   svc::RemoteFB_Connector__StmtDrop
    (tracer,
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
     helper__get_StmtDrop_bugcheck_src(spConnector),
     L"#001");

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;

  break;
 }//for[ever]

 _TSO_CHECK(hStmt==nullptr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//helper__test_001__bug_check__zero_stmt_handle

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 002

#ifdef NDEBUG

void WORK_Test_014__StmtDrop__v2_lazy_send::tag_impl::test_002__bug_check__null_stmt_id
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
 remote_fb::handles::RemoteFB__StmtHandle
  hStmt(remote_fb::handles::RemoteFB__HandleData_Statement::Create());

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtDrop
    (tracer,
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
     helper__get_StmtDrop_bugcheck_src(spConnector),
     L"#002");

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;

  break;
 }//for[ever]

 _TSO_CHECK(hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_002__bug_check__null_stmt_id

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void WORK_Test_014__StmtDrop__v2_lazy_send::tag_impl::test_003__bug_check__bad_stmt_cn_owner
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

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer())

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns2;

 const svc::remote_fb_connector_ptr
  spConnector2
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns2));

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtDrop
    (tracer,
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
     helper__get_StmtDrop_bugcheck_src(spConnector),
     L"#003");

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;

  break;
 }//for[ever]

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer())

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_pParentPort==nullptr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector2);
}//test_003__bug_check__bad_stmt_cn_owner

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 100

void WORK_Test_014__StmtDrop__v2_lazy_send::tag_impl::test_100__drop_defered
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

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer())

 //-----------------------------------------
 auto const hCopyStmt(hStmt);

 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt);

 _TSO_CHECK(hCopyStmt->m_ID.is_null());
 _TSO_CHECK(hCopyStmt->m_pParentPort==nullptr);

 _TSO_CHECK(hCopyStmt->m_ID.is_null());

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_100__drop_defered

////////////////////////////////////////////////////////////////////////////////
//TEST 101

void WORK_Test_014__StmtDrop__v2_lazy_send::tag_impl::test_101__drop_allocated
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

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer())

 //-----------------------------------------
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (remote_fb::protocol::P_USHORT)cns.db_dialect_Ex.value(),
   "set transaction");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 _TSO_CHECK(!hTr);

 //-----------------------------------------
 auto const hCopyStmt(hStmt);

 auto const copyStmtSrvID=hStmt->m_ID.get_value();

 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt);

 _TSO_CHECK(hCopyStmt->m_pParentPort==nullptr);

 _TSO_CHECK(hCopyStmt->m_ID.is_wait_drop());
 _TSO_CHECK(hCopyStmt->m_ID.get_wait_drop()==copyStmtSrvID);

 _TSO_CHECK(hCopyStmt->get_cntRef()>1);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 _TSO_CHECK(hCopyStmt->get_cntRef()==1);
}//test_101__drop_allocated

////////////////////////////////////////////////////////////////////////////////
//TEST 102

void WORK_Test_014__StmtDrop__v2_lazy_send::tag_impl::test_102__send_drop_op_to_srv
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
 for(size_t pass=0;pass!=3;)
 {
  ++pass;

  tracer<<L"-------------------------------- pass: "<<pass<<send;

  //------
  remote_fb::handles::RemoteFB__StmtHandle hStmt(nullptr);

  svc::RemoteFB_Connector__StmtAllocate
   (tracer,
    spConnector,
    &hStmt);

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_ID.is_defer())

  //-----------------------------------------
  svc::remote_fb_tr_handle_type hTr(nullptr);

  svc::RemoteFB_Connector__StmtPrepare
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    (remote_fb::protocol::P_USHORT)cns.db_dialect_Ex.value(),
    "set transaction");

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_ID.has_value());

  _TSO_CHECK(!hTr);

  //----------------------------------------
  _TSO_CHECK(spConnector->GetData()->DeletedStmtList__GetCount()==0);

  _TSO_CHECK(!spConnector->GetData()->DeletedStmtList__GetHead());

  //-----------------------------------------
  auto const hCopyStmt(hStmt);

  auto const copyStmtSrvID=hStmt->m_ID.get_value();

  svc::RemoteFB_Connector__StmtDrop
   (tracer,
    spConnector,
    &hStmt);

  _TSO_CHECK(!hStmt);

  _TSO_CHECK(hCopyStmt->m_pParentPort==nullptr);

  _TSO_CHECK(hCopyStmt->m_ID.is_wait_drop());
  _TSO_CHECK(hCopyStmt->m_ID.get_wait_drop()==copyStmtSrvID);

  _TSO_CHECK(hCopyStmt->get_cntRef()>1);

  _TSO_CHECK(spConnector->GetData()->DeletedStmtList__GetHead()==hCopyStmt);

  _TSO_CHECK(spConnector->GetData()->DeletedStmtList__GetCount()==1);
 }//for pass

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_102__send_drop_op_to_srv

////////////////////////////////////////////////////////////////////////////////

const wchar_t* WORK_Test_014__StmtDrop__v2_lazy_send::tag_impl::helper__get_StmtDrop_bugcheck_src
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
   return L"RemoteFB__API_P12_LAZY_SEND__DropStatement::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13_LAZY_SEND__DropStatement::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_StmtDrop_bugcheck_src

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_014__StmtDrop__v2_lazy_send::tag_descr

struct WORK_Test_014__StmtDrop__v2_lazy_send::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_014__StmtDrop__v2_lazy_send::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_014__StmtDrop__v2_lazy_send::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_014__StmtDrop__v2_lazy_send::tag_descr
 WORK_Test_014__StmtDrop__v2_lazy_send::sm_Tests[]=
{
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("001.bug_check.zero_stmt_handle",
   test_001__bug_check__zero_stmt_handle)

 DEF_TEST_DESCR
  ("002.bug_check.null_stmt_id",
   test_002__bug_check__null_stmt_id)

 DEF_TEST_DESCR
  ("003.bug_check.bad_stmt_cn_owner",
   test_003__bug_check__bad_stmt_cn_owner)
#endif

 DEF_TEST_DESCR
  ("100.drop_defered",
   test_100__drop_defered)

 DEF_TEST_DESCR
  ("101.drop_allocated",
   test_101__drop_allocated)

 DEF_TEST_DESCR
  ("102.send_drop_op_to_srv",
   test_102__send_drop_op_to_srv)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_014__StmtDrop__v2_lazy_send

void WORK_Test_014__StmtDrop__v2_lazy_send::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                                       //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__lazy_send)-1);    //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter ftestID("RemoteFB.WORK.014.StmtDrop.v2.ptype__%1.%2");

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
