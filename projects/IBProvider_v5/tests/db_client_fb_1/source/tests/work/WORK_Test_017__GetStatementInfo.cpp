////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_017__GetStatementInfo.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_017__GetStatementInfo::tag_impl

class WORK_Test_017__GetStatementInfo::tag_impl
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
 #endif

 public:
  static void test_004__query_empty_items
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_005__err__close_cn__fb2_5
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_005__err__close_cn
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_006__err__drop_stmt
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_007__err__not_prepared
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_GetStmtInfo_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);

  static const wchar_t* helper__get_GetStmtInfo_subsystem_id
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_017__GetStatementInfo::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void WORK_Test_017__GetStatementInfo::tag_impl::test_001__bug_check__zero_stmt_handle
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

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(100);

 for(;;)
 {
  try
  {
   svc::remote_fb_stmt_handle_type hStmt(nullptr);

   svc::RemoteFB_Connector__GetStatementInfo(tracer,
                                             spConnector,
                                             OpCtx,
                                             &hStmt,
                                             /*Incornation*/0,
                                             /*cItems*/0,
                                             /*pItems*/nullptr,
                                             ResultBuffer);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_GetStmtInfo_bugcheck_src(spConnector),
     L"#001");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(ResultBuffer.empty());
}//test_001__bug_check__zero_stmt_handle

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 002

#ifdef NDEBUG

void WORK_Test_017__GetStatementInfo::tag_impl::test_002__bug_check__null_stmt_id
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
 remote_fb::RemoteFB__InfoBuffer ResultBuffer(1);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__GetStatementInfo(tracer,
                                             spConnector,
                                             OpCtx,
                                             &hStmtCopy,
                                             /*Incornation*/0,
                                             /*cItems*/0,
                                             /*pItems*/nullptr,
                                             ResultBuffer);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_GetStmtInfo_bugcheck_src(spConnector),
     L"#002");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(ResultBuffer.empty());
}//test_002__bug_check__null_stmt_id

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void WORK_Test_017__GetStatementInfo::tag_impl::test_003__bug_check__bad_owner_cn
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
  spConnector2(svc::RemoteFB_Connector__ConnectToDatabase
                                           (tracer,
                                            params,
                                            cns2));

 //-----------------------------------------
 remote_fb::RemoteFB__InfoBuffer ResultBuffer(2);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__GetStatementInfo(tracer,
                                             spConnector2,
                                             OpCtx,
                                             &hStmt,
                                             /*Incornation*/0,
                                             /*cItems*/0,
                                             /*pItems*/nullptr,
                                             ResultBuffer);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_GetStmtInfo_bugcheck_src(spConnector),
     L"#003");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(ResultBuffer.empty());
}//test_003__bug_check__bad_owner_cn

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 004

void WORK_Test_017__GetStatementInfo::tag_impl::test_004__query_empty_items
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
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "set transaction");

 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::RemoteFB__InfoBuffer ResultBuffer(2);

 svc::RemoteFB_Connector__GetStatementInfo(tracer,
                                           spConnector,
                                           OpCtx,
                                           &hStmt,
                                           /*Incornation*/0,
                                           /*cItems*/0,
                                           /*pItems*/nullptr,
                                           ResultBuffer);

 remote_fb::RemoteFB__InfoBuffer::const_pointer        p=ResultBuffer.buffer();
 remote_fb::RemoteFB__InfoBuffer::const_pointer const _e=ResultBuffer.buffer_end();

 while(p!=_e)
 {
  if((*p)==isc_api::ibp_isc_info_end)
   break;

  tracer(tso_msg_error,-1)
   <<L"Unexpected data in result buffer. FirstByte: "<<*p<<L". "
     L"BufferSize: "<<ResultBuffer.size()<<L"."
   <<send;

  break;
 }//while
}//test_004__query_empty_items

////////////////////////////////////////////////////////////////////////////////
//TEST 005 [PSET01]

void WORK_Test_017__GetStatementInfo::tag_impl::test_005__err__close_cn__fb2_5
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
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "set transaction");

 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::HACK__DetachCn(tracer,spConnector);

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(2);

 try
 {
  svc::RemoteFB_Connector__GetStatementInfo(tracer,
                                            spConnector,
                                            OpCtx,
                                            &hStmt,
                                            /*Incornation*/0,
                                            /*cItems*/0,
                                            /*pItems*/nullptr,
                                            ResultBuffer);
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

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_005__err__close_cn__fb2_5

////////////////////////////////////////////////////////////////////////////////
//TEST 005 [!PSET01]

void WORK_Test_017__GetStatementInfo::tag_impl::test_005__err__close_cn
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
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "set transaction");

 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::HACK__DetachCn(tracer,spConnector);

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(2);

 try
 {
  svc::RemoteFB_Connector__GetStatementInfo(tracer,
                                            spConnector,
                                            OpCtx,
                                            &hStmt,
                                            /*Incornation*/0,
                                            /*cItems*/0,
                                            /*pItems*/nullptr,
                                            ResultBuffer);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__srv_err__bad_cn_handle
   (tracer,
    spConnector->GetData()->m_DBMS_Name,
    exc.get_record(0));

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_005__err__close_cn

////////////////////////////////////////////////////////////////////////////////
//TEST 006

void WORK_Test_017__GetStatementInfo::tag_impl::test_006__err__drop_stmt
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
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "set transaction");

 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::HACK__DropStmt(tracer,
                     spConnector,
                     &hStmt);
 _TSO_CHECK(hStmt);

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(2);

 try
 {
  svc::RemoteFB_Connector__GetStatementInfo(tracer,
                                            spConnector,
                                            OpCtx,
                                            &hStmt,
                                            /*Incornation*/0,
                                            /*cItems*/0,
                                            /*pItems*/nullptr,
                                            ResultBuffer);
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

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//test_006__err__drop_stmt

////////////////////////////////////////////////////////////////////////////////
//TEST 007

void WORK_Test_017__GetStatementInfo::tag_impl::test_007__err__not_prepared
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

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(2);

 //-----------------------------------------
 try
 {
  svc::RemoteFB_Connector__GetStatementInfo(tracer,
                                            spConnector,
                                            OpCtx,
                                            &hStmt,
                                            /*Incornation*/0,
                                            /*cItems*/0,
                                            /*pItems*/nullptr,
                                            ResultBuffer);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__stmt_err__not_prepared
   (tracer,
    exc.get_record(0),
    helper__get_GetStmtInfo_subsystem_id(spConnector));

  return;
 }//catch

 svc::Throw_WeWaitTheError();
}//helper__test_007__err__not_prepared

////////////////////////////////////////////////////////////////////////////////

const wchar_t*
 WORK_Test_017__GetStatementInfo::tag_impl::helper__get_GetStmtInfo_bugcheck_src
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
   return L"RemoteFB__API_P12__GetStatementInfo::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__GetStatementInfo::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_GetStmtInfo_bugcheck_src

//------------------------------------------------------------------------
const wchar_t*
 WORK_Test_017__GetStatementInfo::tag_impl::helper__get_GetStmtInfo_subsystem_id
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
}//helper__get_GetStmtInfo_subsystem_id

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_017__GetStatementInfo::tag_descr

struct WORK_Test_017__GetStatementInfo::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_017__GetStatementInfo::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_017__GetStatementInfo::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_017__GetStatementInfo::tag_descr
 WORK_Test_017__GetStatementInfo::sm_Tests[]=
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
  ("004.query_empty_items",
   test_004__query_empty_items)

 DEF_TEST_DESCR2
  ("005.err.close_cn.fb2_5",
   test_005__err__close_cn__fb2_5,
   "SRV<FB-3")

 DEF_TEST_DESCR2
  ("005.err.close_cn",
   test_005__err__close_cn,
   "!(SRV<FB-3)")

 DEF_TEST_DESCR
  ("006.err.drop_stmt",
   test_006__err__drop_stmt)

 DEF_TEST_DESCR
  ("007.err.not_prepared",
   test_007__err__not_prepared)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_017__GetStatementInfo

void WORK_Test_017__GetStatementInfo::create(TTSO_PushTest*      const pTestPusher,
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
 structure::str_formatter ftestID("RemoteFB.WORK.017.GetStatementInfo.ptype__%1.%2");

 TTSO_TestData_v2 Data;

 for(;it;++it)
 {
  assert(it[iTest]<_DIM_(sm_Tests));
  assert(it[iPType]<_DIM_(g_TestCfg__RemoteFB__ProtocolTypes));

  //----------------------------------------
  Data.m_RemoteFB__ProtocolType
   =g_TestCfg__RemoteFB__ProtocolTypes[it[iPType]];

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
