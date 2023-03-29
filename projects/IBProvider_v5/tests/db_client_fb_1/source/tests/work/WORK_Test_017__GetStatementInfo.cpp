////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_017__GetStatementInfo.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/db_obj/fb_base/fb_api.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////

#define _LOCAL_CHECK_VALUE(point,actual_v,expected_v)   \
  if((actual_v)!=(expected_v))                          \
  {                                                     \
   structure::str_formatter fmsg("point [%1]. Expected value: [%2]. Actual value: [%3]."); \
                                                        \
   fmsg<<(point)<<(expected_v)<<(actual_v);             \
                                                        \
   throw std::runtime_error(fmsg.str());                \
  }

//------------------------------------------------------------------------
#define _LOCAL_MAKE_WSTR(t) L##t

//------------------------------------------------------------------------
#define _LOCAL_CHECK_TAG(id,ptr,end)                    \
 {                                                      \
  self_type::helper__check_tag                          \
   ((tracer),                                           \
    _LOCAL_MAKE_WSTR(#id),                              \
    (id),                                               \
    (&ptr),                                             \
    (end));                                             \
 }

//------------------------------------------------------------------------
#define _LOCAL_CHECK_INT_TAG(id,value,ptr,end)          \
 {                                                      \
  self_type::helper__check_tag__Int                     \
   ((tracer),                                           \
    _LOCAL_MAKE_WSTR(#id),                              \
    (id),                                               \
    (value),                                            \
    (&ptr),                                             \
    (end));                                             \
 }

//------------------------------------------------------------------------
#define _LOCAL_CHECK_STR_TAG(id,value,ptr,end)          \
 {                                                      \
  self_type::helper__check_tag__Str                     \
   ((tracer),                                           \
    _LOCAL_MAKE_WSTR(#id),                              \
    (id),                                               \
    (value),                                            \
    (&ptr),                                             \
    (end));                                             \
 }

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

  static void test_100__data__stmt_type_id
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_101__data__2xstmt_type_id
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_102__data__stmt_type_id__batch_fetch__stmt_type_id
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_GetStmtInfo_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);

  static const wchar_t* helper__get_GetStmtInfo_subsystem_id
                          (remote_fb::RemoteFB__Connector* pConnector);

  static void helper__check_tag
                          (TTSO_Tracer&          tracer,
                           const wchar_t*        tagSign,
                           unsigned char         expected_tagID,
                           const unsigned char** pptr,
                           const unsigned char*  end);

  static void helper__check_tag__Int
                          (TTSO_Tracer&          tracer,
                           const wchar_t*        tagSign,
                           unsigned char         expected_tagID,
                           long                  expected_tagValue,
                           const unsigned char** pptr,
                           const unsigned char*  end);

  static void helper__check_tag__Str
                          (TTSO_Tracer&          tracer,
                           const wchar_t*        tagSign,
                           unsigned char         expected_tagID,
                           const char*           expected_tagValue,
                           const unsigned char** pptr,
                           const unsigned char*  end);

  static size_t helper__read_tag_length
                          (TTSO_Tracer&          tracer,
                           const wchar_t*        tagSign,
                           const unsigned char** pptr,
                           const unsigned char*  end);
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

   svc::RemoteFB_Connector__GetStatementInfo
    (tracer,
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
   svc::RemoteFB_Connector__GetStatementInfo
    (tracer,
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
  spConnector2
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns2));

 //-----------------------------------------
 remote_fb::RemoteFB__InfoBuffer ResultBuffer(2);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__GetStatementInfo
    (tracer,
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

 svc::RemoteFB_Connector__GetStatementInfo
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   /*Incornation*/0,
   /*cItems*/0,
   /*pItems*/nullptr,
   ResultBuffer);

 remote_fb::RemoteFB__InfoBuffer::const_pointer        p=ResultBuffer.buffer();
 remote_fb::RemoteFB__InfoBuffer::const_pointer const _e=ResultBuffer.buffer_end();

 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_end,
   p,
   _e);
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
  svc::RemoteFB_Connector__GetStatementInfo
   (tracer,
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
  svc::RemoteFB_Connector__GetStatementInfo
   (tracer,
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
  svc::RemoteFB_Connector__GetStatementInfo
   (tracer,
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
  svc::RemoteFB_Connector__GetStatementInfo
   (tracer,
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
//TEST 100

void WORK_Test_017__GetStatementInfo::tag_impl::test_100__data__stmt_type_id
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
 const unsigned char req_items[]=
  {
   isc_api::ibp_isc_info_sql_stmt_type,
  };//req_items

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(16);

 svc::RemoteFB_Connector__GetStatementInfo
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   /*Incornation*/0,
   /*cItems*/_LCPI_DIM_(req_items),
   /*pItems*/req_items,
   ResultBuffer);

 remote_fb::RemoteFB__InfoBuffer::const_pointer        p=ResultBuffer.buffer();
 remote_fb::RemoteFB__InfoBuffer::const_pointer const _e=ResultBuffer.buffer_end();

 //-------------------------------------------------------- ibp_isc_info_sql_stmt_type
 {
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_stmt_type,
    lcpi::ibp::fb_api::ibp_fb_info_sql_stmt_start_trans,
    p,
    _e);
 }//local

 //-------------------------------------------------------- ibp_isc_info_end
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_end,
   p,
   _e);

 //-------------------------------------------------------- STOP
 {
  // [2023-03-24] It is expected

  _TSO_CHECK(p==_e);
 }
}//test_100__data__stmt_type_id

////////////////////////////////////////////////////////////////////////////////
//TEST 101

void WORK_Test_017__GetStatementInfo::tag_impl::test_101__data__2xstmt_type_id
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
 const unsigned char req_items[]=
  {
   isc_api::ibp_isc_info_sql_stmt_type,
   isc_api::ibp_isc_info_sql_stmt_type,
  };//req_items

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(16);

 svc::RemoteFB_Connector__GetStatementInfo
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   /*Incornation*/0,
   /*cItems*/_LCPI_DIM_(req_items),
   /*pItems*/req_items,
   ResultBuffer);

 remote_fb::RemoteFB__InfoBuffer::const_pointer        p=ResultBuffer.buffer();
 remote_fb::RemoteFB__InfoBuffer::const_pointer const _e=ResultBuffer.buffer_end();

 //-------------------------------------------------------- ibp_isc_info_sql_stmt_type (1,2)
 for(size_t nValue=0;nValue!=2;)
 {
  ++nValue;

  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_stmt_type,
    lcpi::ibp::fb_api::ibp_fb_info_sql_stmt_start_trans,
    p,
    _e);
 }//local

 //-------------------------------------------------------- ibp_isc_info_end
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_end,
   p,
   _e);

 //-------------------------------------------------------- STOP
 {
  // [2023-03-24] It is expected

  _TSO_CHECK(p==_e);
 }
}//test_101__data__2xstmt_type_id

////////////////////////////////////////////////////////////////////////////////
//TEST 102

void WORK_Test_017__GetStatementInfo::tag_impl::test_102__data__stmt_type_id__batch_fetch__stmt_type_id
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
 const unsigned char req_items[]=
  {
   isc_api::ibp_isc_info_sql_stmt_type,
   isc_api::ibp_isc_info_sql_batch_fetch,
   isc_api::ibp_isc_info_sql_stmt_type,
  };//req_items

 remote_fb::RemoteFB__InfoBuffer ResultBuffer(16);

 svc::RemoteFB_Connector__GetStatementInfo
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   /*Incornation*/0,
   /*cItems*/_LCPI_DIM_(req_items),
   /*pItems*/req_items,
   ResultBuffer);

 remote_fb::RemoteFB__InfoBuffer::const_pointer        p=ResultBuffer.buffer();
 remote_fb::RemoteFB__InfoBuffer::const_pointer const _e=ResultBuffer.buffer_end();

 //-------------------------------------------------------- ibp_isc_info_sql_stmt_type
 {
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_stmt_type,
    lcpi::ibp::fb_api::ibp_fb_info_sql_stmt_start_trans,
    p,
    _e);
 }//local

 //-------------------------------------------------------- ibp_isc_info_sql_stmt_type
 {
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_batch_fetch,
    1,
    p,
    _e);
 }//local

 //-------------------------------------------------------- ibp_isc_info_sql_stmt_type
 {
  _LOCAL_CHECK_INT_TAG
   (isc_api::ibp_isc_info_sql_stmt_type,
    lcpi::ibp::fb_api::ibp_fb_info_sql_stmt_start_trans,
    p,
    _e);
 }//local

 //-------------------------------------------------------- ibp_isc_info_end
 _LOCAL_CHECK_TAG
  (isc_api::ibp_isc_info_end,
   p,
   _e);

 //-------------------------------------------------------- STOP
 {
  // [2023-03-24] It is expected

  _TSO_CHECK(p==_e);
 }
}//test_102__data__stmt_type_id__batch_fetch__stmt_type_id

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
  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_HLP__GetStatementInfo_v01::exec";

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
  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return errSvc::sm_subsysID__remote_fb;

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_GetStmtInfo_subsystem_id

////////////////////////////////////////////////////////////////////////////////

void WORK_Test_017__GetStatementInfo::tag_impl::helper__check_tag
                          (TTSO_Tracer&                tracer,
                           const wchar_t*        const tagSign,
                           unsigned char         const expected_tagID,
                           const unsigned char** const pptr,
                           const unsigned char*  const end)
{
 assert(pptr);
 assert((*pptr)<=end);

 tracer<<L"check tag ["<<tagSign<<L"]"<<send;

 const auto*& p=*pptr;
 const auto* _e=end;

 _TSO_CHECK(p!=_e);

 _LOCAL_CHECK_VALUE
  ("#check_tag_id",
   *p,
   expected_tagID);

 ++p;
}//helper__check_tag

////////////////////////////////////////////////////////////////////////////////

void WORK_Test_017__GetStatementInfo::tag_impl::helper__check_tag__Int
                          (TTSO_Tracer&                tracer,
                           const wchar_t*        const tagSign,
                           unsigned char         const expected_tagID,
                           long                  const expected_tagValue,
                           const unsigned char** const pptr,
                           const unsigned char*  const end)
{
 assert(pptr);
 assert((*pptr)<=end);

 tracer<<L"check int tag ["<<tagSign<<L"]"<<send;

 const auto*& p=*pptr;
 const auto* _e=end;

 _TSO_CHECK(p!=_e);

 _LOCAL_CHECK_VALUE
  ("#check_tag_id",
   *p,
   expected_tagID);

 ++p;

 _TSO_CHECK(p!=_e);
 _TSO_CHECK(isc_api::ibp_isc__info_tag__data_length__byte_count<=(_e-p));

 const size_t itemValueLength
  =helper__read_tag_length
    (tracer,
     tagSign,
     pptr,
     end);

 _LOCAL_CHECK_VALUE
  ("#check_length",
   itemValueLength,
   4);

 long itemValue=0;

 ibp::isc_base::isc_portable_format_to_integer::exec
  (itemValueLength,
   p,
   &itemValue,
   ibp::ibp_subsystem__remote_fb,
   L"itemValue");

 _LOCAL_CHECK_VALUE
  ("#check_value",
   itemValue,
   expected_tagValue);

 p+=itemValueLength;
}//helper__check_tag__Int

////////////////////////////////////////////////////////////////////////////////

void WORK_Test_017__GetStatementInfo::tag_impl::helper__check_tag__Str
                          (TTSO_Tracer&                tracer,
                           const wchar_t*        const tagSign,
                           unsigned char         const expected_tagID,
                           const char*           const expected_tagValue,
                           const unsigned char** const pptr,
                           const unsigned char*  const end)
{
 assert(pptr);
 assert((*pptr)<=end);
 assert(expected_tagValue);

 tracer<<L"check str tag ["<<tagSign<<L"]"<<send;

 const auto*& p=*pptr;
 const auto* _e=end;

 _TSO_CHECK(p!=_e);

 _LOCAL_CHECK_VALUE
  ("#check_tag_id",
   *p,
   expected_tagID);

 ++p;

 _TSO_CHECK(p!=_e);
 _TSO_CHECK(isc_api::ibp_isc__info_tag__data_length__byte_count<=(_e-p));

 const size_t itemValueLength
  =helper__read_tag_length
    (tracer,
     tagSign,
     pptr,
     end);

 const size_t expected_tagValueSize
  =strlen(expected_tagValue);

 _LOCAL_CHECK_VALUE
  ("#check_length",
   itemValueLength,
   expected_tagValueSize);

 if(memcmp(expected_tagValue,p,expected_tagValueSize)!=0)
 {
  structure::str_formatter
   fmsg
    ("Wrong tag value: [%1].\n"
     "Expected value : [%2].");

  fmsg
   <<TestServices::PrepareStrForPrint(structure::make_str_box((const char*)p   ,expected_tagValueSize))
   <<TestServices::PrepareStrForPrint(structure::make_str_box(expected_tagValue,expected_tagValueSize));

  throw std::runtime_error(fmsg);
 }//if

 p+=itemValueLength;
}//helper__check_tag__Str

////////////////////////////////////////////////////////////////////////////////

size_t WORK_Test_017__GetStatementInfo::tag_impl::helper__read_tag_length
                          (TTSO_Tracer&                tracer,
                           const wchar_t*        const tagSign,
                           const unsigned char** const pptr,
                           const unsigned char*  const end)
{
 assert(pptr);
 assert((*pptr)<=end);

 tracer<<L"read tag ["<<tagSign<<L"] length ...";

 const auto*& p=*pptr;
 const auto* _e=end;

 size_t itemValueLength=0;

 try
 {
  _TSO_CHECK(p!=_e);
  _TSO_CHECK(isc_api::ibp_isc__info_tag__data_length__byte_count<=(_e-p));

  ibp::isc_base::isc_portable_format_to_integer::exec
   (isc_api::ibp_isc__info_tag__data_length__byte_count,
    p,
    &itemValueLength,
    ibp::ibp_subsystem__remote_fb,
    L"itemValueLength");
 }
 catch(...)
 {
  tracer<<L"FAILED!"<<send;
  throw;
 }

 tracer<<itemValueLength<<send;

 p+=isc_api::ibp_isc__info_tag__data_length__byte_count;

 _TSO_CHECK(itemValueLength<=size_t(_e-p));

 return itemValueLength;
}//helper__read_tag_length

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

 DEF_TEST_DESCR
  ("100.data.stmt_type_id",
   test_100__data__stmt_type_id)

 DEF_TEST_DESCR
  ("101.data.2xstmt_type_id",
   test_101__data__2xstmt_type_id)

 DEF_TEST_DESCR
  ("102.data.stmt_type_id__batch_fetch__stmt_type_id",
   test_102__data__stmt_type_id__batch_fetch__stmt_type_id)
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
 structure::str_formatter
  ftestID("RemoteFB.WORK.017.GetStatementInfo.ptype__%1.%2");

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
#undef _LOCAL_CHECK_INT_TAG
#undef _LOCAL_MAKE_WSTR
#undef _LOCAL_CHECK_VALUE
////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
