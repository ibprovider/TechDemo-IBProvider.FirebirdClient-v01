////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_036__StmtFetch_M__v0.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__encoder.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__msg_v1.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/error_services/ibp_sqlstate_codes.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

#include <array>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_036__StmtFetch_M__v0::tag_impl

class WORK_Test_036__StmtFetch_M__v0::tag_impl
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

  static void test_004__err__not_prepared
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 #ifdef NDEBUG
  static void test_005__err__not_executed
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 #endif

 #ifdef NDEBUG
  static void test_008__bug_check__fetch_after_eof
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 #endif

 public: //---------------------------------------------------------------
  static void test_100__select_empty_rowset
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_101__select_one_row_with_one_col
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_101__select_one_row_with_one_col__for_update
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public:
  static void test_F00__select_empty_rowset
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_F01__select_one_row
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public:
  static void test_200__reexecution
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static void helper_101__select_one_row_with_one_col
               (TTSO_GlobalContext*      pParams,
                context_type*            pCtx,
                const TTSO_TestData_v2&  Data,
                const char*              pszSQL);

 private:
  static const wchar_t* helper__get_fetch_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);

  static const wchar_t* helper__get_fetch_subsystem
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_036__StmtFetch_M__v0::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void WORK_Test_036__StmtFetch_M__v0::tag_impl::test_001__bug_check__zero_stmt_handle
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

   svc::RemoteFB_Connector__StmtFetch_M
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     /*pOutMsg*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_fetch_bugcheck_src(spConnector),
     L"#001");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_001__bug_check__zero_stmt_handle

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 002

#ifdef NDEBUG

void WORK_Test_036__StmtFetch_M__v0::tag_impl::test_002__bug_check__null_stmt_id
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
 _TSO_CHECK(hStmt->m_ID.is_defer()==spConnector->GetPort()->TestPortFlag__lazy());
 _TSO_CHECK(hStmt->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt==nullptr);

 _TSO_CHECK(hStmtCopy)
 _TSO_CHECK(hStmtCopy->m_ID.is_null());

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtFetch_M
    (tracer,
     spConnector,
     OpCtx,
     &hStmtCopy,
     /*pOutMsg*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_fetch_bugcheck_src(spConnector),
     L"#002");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_002__bug_check__null_stmt_id

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void WORK_Test_036__StmtFetch_M__v0::tag_impl::test_003__bug_check__bad_owner_cn
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
  spConnector2
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns2));

 //-----------------------------------------
 TestOperationContext OpCtx2(params);

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtFetch_M
    (tracer,
     spConnector2,
     OpCtx2,
     &hStmt,
     /*pOutMsg*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__bug_check__bad_stmt_handle
    (tracer,
     exc.get_record(0),
     helper__get_fetch_bugcheck_src(spConnector),
     L"#003");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

}//test_003__bug_check__bad_owner_cn

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 004

void WORK_Test_036__StmtFetch_M__v0::tag_impl::test_004__err__not_prepared
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
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 svc::remote_fb_out_msg_v1 OutMsg;

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtFetch_M
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     &OutMsg);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__not_prepared
    (tracer,
     exc.get_record(0),
     helper__get_fetch_subsystem(spConnector));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt);

 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(!hStmt);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_004__err__not_prepared

////////////////////////////////////////////////////////////////////////////////
//TEST 005

#ifdef NDEBUG

void WORK_Test_036__StmtFetch_M__v0::tag_impl::test_005__err__not_executed
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
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL");

 //-----------------------------------------
 svc::remote_fb_out_msg_v1 OutMsg;

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtFetch_M
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     &OutMsg);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__stmt_err__fetch_from_closed_cursor
    (tracer,
     exc.get_record(0),
     helper__get_fetch_subsystem(spConnector));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt);

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
}//test_005__err__not_executed

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 008

#ifdef NDEBUG

void WORK_Test_036__StmtFetch_M__v0::tag_impl::test_008__bug_check__fetch_after_eof
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
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL where 1=0");

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(/*n*/1);
 //
 // db_obj::t_dbvalue__i4   columnValue=0;
 // short                   columnInd=0;
 //
 // xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
 // xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[0].sqlsubtype =0;
 // xsqlda->sqlvar[0].sqlscale   =0;
 // xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&columnValue);
 // xsqlda->sqlvar[0].sqlind     =&columnInd;
 //
 // xsqlda->sqld=1;

 //------------------------------------------------- OUTPUT
 const std::array<unsigned char,12> OutMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__long,   // data type
  /*  7 */ 0,                                  // data scale
  /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /*  9 */ 0,                                  // indicator scale
  /* 10 */ isc_api::ibp_isc_blr_end,
  /* 11 */ isc_api::ibp_isc_blr_eoc,
 };//OutMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
 {
  //---- value [long]
  0xFF,
  0xFF,
  0xFF,
  0xFF,
  //---- indicator [short]
  0xFE,
  0xFE,
 };//OutMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> OutMsg__DATA_DESCRS;

 OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_out_msg_v1 OutMsg;

 OutMsg.blr        =OutMsg__BLR;
 OutMsg.data       =OutMsg__DATA;
 OutMsg.descrs     =OutMsg__DATA_DESCRS;
 OutMsg.data_align =4;

 //-----------------------------------------
 bool fetchResult
  =svc::RemoteFB_Connector__StmtFetch_M
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     &OutMsg);

 _TSO_CHECK(hStmt);

 _TSO_CHECK(!fetchResult); //EOF!

 //-----------------------------------------
 for(size_t nPass=0;nPass!=3;)
 {
  ++nPass;

  tracer<<L"-------------------------------- "<<nPass<<L"."<<send;

  try
  {
   svc::RemoteFB_Connector__StmtFetch_M
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     &OutMsg); //throw!
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

   errSvc::check_err_rec__stmt_err__fetch_after_eof
    (tracer,
     exc.get_record(0),
     helper__get_fetch_subsystem(spConnector));

   continue;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for nPass

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
}//test_008__bug_check__fetch_after_eof

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 100

void WORK_Test_036__StmtFetch_M__v0::tag_impl::test_100__select_empty_rowset
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
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "select ID from DUAL where 1=0");

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(/*n*/1);
 //
 // db_obj::t_dbvalue__i4   columnValue=0;
 // short                   columnInd=0;
 //
 // xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
 // xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[0].sqlsubtype =0;
 // xsqlda->sqlvar[0].sqlscale   =0;
 // xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&columnValue);
 // xsqlda->sqlvar[0].sqlind     =&columnInd;
 //
 // xsqlda->sqld=1;

 //------------------------------------------------- OUTPUT
 const std::array<unsigned char,12> OutMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__long,   // data type
  /*  7 */ 0,                                  // data scale
  /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /*  9 */ 0,                                  // indicator scale
  /* 10 */ isc_api::ibp_isc_blr_end,
  /* 11 */ isc_api::ibp_isc_blr_eoc,
 };//OutMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
 {
  //---- value [long]
  0xFF,
  0xFF,
  0xFF,
  0xFF,
  //---- indicator [short]
  0xFE,
  0xFE,
 };//OutMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> OutMsg__DATA_DESCRS;

 OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_out_msg_v1 OutMsg;

 OutMsg.blr        =OutMsg__BLR;
 OutMsg.data       =OutMsg__DATA;
 OutMsg.descrs     =OutMsg__DATA_DESCRS;
 OutMsg.data_align =4;

 //-----------------------------------------
 bool fetchResult
  =svc::RemoteFB_Connector__StmtFetch_M
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     &OutMsg);

 _TSO_CHECK(hStmt);

 _TSO_CHECK(!fetchResult); //EOF!

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
}//test_100__select_empty_rowset

////////////////////////////////////////////////////////////////////////////////
//TEST 101

void WORK_Test_036__StmtFetch_M__v0::tag_impl::test_101__select_one_row_with_one_col
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams);
 assert(pCtx);

 return helper_101__select_one_row_with_one_col
         (pParams,
          pCtx,
          Data,
          "select ID from DUAL");
}//test_101__select_one_row_with_one_col

//------------------------------------------------------------------------
void WORK_Test_036__StmtFetch_M__v0::tag_impl::test_101__select_one_row_with_one_col__for_update
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams);
 assert(pCtx);

 return helper_101__select_one_row_with_one_col
         (pParams,
          pCtx,
          Data,
          "select ID from DUAL for update");
}//test_101__select_one_row_with_one_col__for_update

//------------------------------------------------------------------------
void WORK_Test_036__StmtFetch_M__v0::tag_impl::helper_101__select_one_row_with_one_col
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data,
                                            const char*         const pszSQL)
{
 assert(pParams);
 assert(pCtx);
 assert(pszSQL);

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
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   pszSQL);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 //-----------------------------------------
 //XSQLDA_V1_Wrapper xsqlda(/*n*/1);
 //
 //db_obj::t_dbvalue__i4   columnValue=0;
 //short                   columnInd=0;
 //
 //xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
 //xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_long|1;
 //xsqlda->sqlvar[0].sqlsubtype =0;
 //xsqlda->sqlvar[0].sqlscale   =0;
 //xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&columnValue);
 //xsqlda->sqlvar[0].sqlind     =&columnInd;
 //
 //xsqlda->sqld=1;

 //------------------------------------------------- OUTPUT
 const std::array<unsigned char,12> OutMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__long,   // data type
  /*  7 */ 0,                                  // data scale
  /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /*  9 */ 0,                                  // indicator scale
  /* 10 */ isc_api::ibp_isc_blr_end,
  /* 11 */ isc_api::ibp_isc_blr_eoc,
 };//OutMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
 {
  //---- value [long]
  0xFF,
  0xFF,
  0xFF,
  0xFF,
  //---- indicator [short]
  0xFE,
  0xFE,
 };//OutMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> OutMsg__DATA_DESCRS;

 OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_out_msg_v1 OutMsg;

 OutMsg.blr        =OutMsg__BLR;
 OutMsg.data       =OutMsg__DATA;
 OutMsg.descrs     =OutMsg__DATA_DESCRS;
 OutMsg.data_align =4;

 //-----------------------------------------
 bool fetchResult
  =svc::RemoteFB_Connector__StmtFetch_M
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     &OutMsg);

 _TSO_CHECK(hStmt);

 _TSO_CHECK(fetchResult);

 //-----------------------------------------
 {
  db_obj::t_dbvalue__i4 columnValue;

  assert_s(sizeof(columnValue)==4);

  memcpy(&columnValue,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(columnValue));

  _TSO_CHECK_MSG(columnValue==1,"columnValue="<<columnValue);
 }//local

 //-----------------------------------------
 {
  db_obj::t_dbvalue__i2 columnInd;

  assert_s(sizeof(columnInd)==2);

  memcpy(&columnInd,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(columnInd));

  _TSO_CHECK_MSG(columnInd==0,"columnInd="<<columnInd);
 }//local

 //-----------------------------------------
 fetchResult
  =svc::RemoteFB_Connector__StmtFetch_M
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     &OutMsg);

 _TSO_CHECK(hStmt);

 _TSO_CHECK(!fetchResult); //EOF

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
}//helper_101__select_one_row_with_one_col

////////////////////////////////////////////////////////////////////////////////
//TEST F00

void WORK_Test_036__StmtFetch_M__v0::tag_impl::test_F00__select_empty_rowset
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
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
    "execute block\n"
    "returns(X INTEGER)\n"
    "AS\n"
    "BEGIN\n"
    " EXCEPTION EXC__SP_PAUSE_FETCH_ERR;\n"
    " SUSPEND;\n"
    "END;");

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(/*n*/1);
 //
 // db_obj::t_dbvalue__i4   columnValue=0;
 // short                   columnInd=0;
 //
 // xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
 // xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[0].sqlsubtype =0;
 // xsqlda->sqlvar[0].sqlscale   =0;
 // xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&columnValue);
 // xsqlda->sqlvar[0].sqlind     =&columnInd;
 //
 // xsqlda->sqld=1;

 //------------------------------------------------- OUTPUT
 const std::array<unsigned char,12> OutMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__long,   // data type
  /*  7 */ 0,                                  // data scale
  /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /*  9 */ 0,                                  // indicator scale
  /* 10 */ isc_api::ibp_isc_blr_end,
  /* 11 */ isc_api::ibp_isc_blr_eoc,
 };//OutMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
 {
  //---- value [long]
  0xFF,
  0xFF,
  0xFF,
  0xFF,
  //---- indicator [short]
  0xFE,
  0xFE,
 };//OutMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> OutMsg__DATA_DESCRS;

 OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_out_msg_v1 OutMsg;

 OutMsg.blr        =OutMsg__BLR;
 OutMsg.data       =OutMsg__DATA;
 OutMsg.descrs     =OutMsg__DATA_DESCRS;
 OutMsg.data_align =4;

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtFetch_M
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     &OutMsg);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_code(exc.com_code(),E_FAIL);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__partially
    (tracer,
     exc.get_record(0),
     spConnector->GetData()->m_DBMS_Name,
     L"SP_PAUSE_FETCH_ERR");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt);

 _TSO_CHECK(hStmt->m_spFetchResult);
 _TSO_CHECK(hStmt->m_spFetchResult->m_State==hStmt->m_spFetchResult->state__failed);

 _TSO_CHECK(hStmt->m_spFetchResult->m_FetchErr.com_code()==E_FAIL);

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
}//test_F00__select_empty_rowset

////////////////////////////////////////////////////////////////////////////////
//TEST F01

void WORK_Test_036__StmtFetch_M__v0::tag_impl::test_F01__select_one_row
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
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
    "execute block\n"
    "returns(X INTEGER)\n"
    "AS\n"
    "BEGIN\n"
    " x=-123; SUSPEND;\n"
    " EXCEPTION EXC__SP_PAUSE_FETCH_ERR;\n"
    " SUSPEND;\n"
    "END;");

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(/*n*/1);
 //
 // db_obj::t_dbvalue__i4   columnValue=0;
 // short                   columnInd=0;
 //
 // xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
 // xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[0].sqlsubtype =0;
 // xsqlda->sqlvar[0].sqlscale   =0;
 // xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&columnValue);
 // xsqlda->sqlvar[0].sqlind     =&columnInd;
 //
 // xsqlda->sqld=1;

 //------------------------------------------------- OUTPUT
 const std::array<unsigned char,12> OutMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__long,   // data type
  /*  7 */ 0,                                  // data scale
  /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /*  9 */ 0,                                  // indicator scale
  /* 10 */ isc_api::ibp_isc_blr_end,
  /* 11 */ isc_api::ibp_isc_blr_eoc,
 };//OutMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
 {
  //---- value [long]
  0xFF,
  0xFF,
  0xFF,
  0xFF,
  //---- indicator [short]
  0xFE,
  0xFE,
 };//OutMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> OutMsg__DATA_DESCRS;

 OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_out_msg_v1 OutMsg;

 OutMsg.blr        =OutMsg__BLR;
 OutMsg.data       =OutMsg__DATA;
 OutMsg.descrs     =OutMsg__DATA_DESCRS;
 OutMsg.data_align =4;

 //-----------------------------------------
 const bool fetchResult
  =svc::RemoteFB_Connector__StmtFetch_M
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     &OutMsg);

 _TSO_CHECK(fetchResult)

 //_TSO_CHECK(columnValue==-123);
 //_TSO_CHECK(columnInd==0);

 //-----------------------------------------
 {
  db_obj::t_dbvalue__i4 columnValue;

  assert_s(sizeof(columnValue)==4);

  memcpy(&columnValue,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(columnValue));

  _TSO_CHECK_MSG(columnValue==-123,"columnValue="<<columnValue);
 }//local

 //-----------------------------------------
 {
  db_obj::t_dbvalue__i2 columnInd;

  assert_s(sizeof(columnInd)==2);

  memcpy(&columnInd,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(columnInd));

  _TSO_CHECK_MSG(columnInd==0,"columnInd="<<columnInd);
 }//local

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtFetch_M
    (tracer,
     spConnector,
     OpCtx,
     &hStmt,
     &OutMsg);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_code(exc.com_code(),E_FAIL);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__partially
    (tracer,
     exc.get_record(0),
     spConnector->GetData()->m_DBMS_Name,
     L"SP_PAUSE_FETCH_ERR");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hStmt);

 _TSO_CHECK(hStmt->m_spFetchResult);
 _TSO_CHECK(hStmt->m_spFetchResult->m_State==hStmt->m_spFetchResult->state__failed);

 _TSO_CHECK(hStmt->m_spFetchResult->m_FetchErr.com_code()==E_FAIL);

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
}//test_F01__select_one_row

////////////////////////////////////////////////////////////////////////////////
//TEST 200

void WORK_Test_036__StmtFetch_M__v0::tag_impl::test_200__reexecution
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
 svc::remote_fb_tr_handle_type hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.is_defer()==spConnector->GetPort()->TestPortFlag__lazy());

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
    "select ID from DUAL;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 for(size_t pass=0;pass!=5;)
 {
  ++pass;

  tracer<<L"-------------------------------- pass: "<<pass<<send;

  svc::RemoteFB_Connector__StmtExecute
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    /*in*/nullptr,
    /*out*/nullptr);

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_pParentTr==hTr);
  _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED)==spConnector->GetPort()->TestPortFlag__lazy());
  _TSO_CHECK(!hStmt->m_spFetchResult);

  if(!spConnector->GetPort()->TestPortFlag__lazy())
  {
   _TSO_CHECK(!hStmt->m_pClosingTr);
  }
  else
  if(pass==1)
  {
   _TSO_CHECK(!hStmt->m_pClosingTr);
  }
  else
  {
   _TSO_CHECK(pass>1);

   //продолжает висеть отложенное закрытие курсора
   _TSO_CHECK(hStmt->m_pClosingTr==hTr);
  }

  //----------------------------------------
//  XSQLDA_V1_Wrapper xsqlda(/*n*/1);
//
//  db_obj::t_dbvalue__i4   columnValue=0;
//  short                   columnInd=0;
//
//  xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
//  xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_long|1;
//  xsqlda->sqlvar[0].sqlsubtype =0;
//  xsqlda->sqlvar[0].sqlscale   =0;
//  xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&columnValue);
//  xsqlda->sqlvar[0].sqlind     =&columnInd;
//
//  xsqlda->sqld=1;

  //------------------------------------------------ OUTPUT
  const std::array<unsigned char,12> OutMsg__BLR=
  {
   /*  0 */ isc_api::ibp_isc_blr_version5,
   /*  1 */ isc_api::ibp_isc_blr_begin,
   /*  2 */ isc_api::ibp_isc_blr_message,
   /*  3 */ 0, // message number
   /*  4 */ 2, // cPars_lower
   /*  5 */ 0, // cPars_upper
   /*  6 */ isc_api::ibp_isc_blr_dtype__long,   // data type
   /*  7 */ 0,                                  // data scale
   /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
   /*  9 */ 0,                                  // indicator scale
   /* 10 */ isc_api::ibp_isc_blr_end,
   /* 11 */ isc_api::ibp_isc_blr_eoc,
  };//OutMsg__BLR

  //----------------------------------------
  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
  {
   //---- value [long]
   0xFF,
   0xFF,
   0xFF,
   0xFF,
   //---- indicator [short]
   0xFE,
   0xFE,
  };//OutMsg__DATA

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> OutMsg__DATA_DESCRS;

  OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
  OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
  OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

  //----------------------------------------
  svc::remote_fb_out_msg_v1 OutMsg;

  OutMsg.blr        =OutMsg__BLR;
  OutMsg.data       =OutMsg__DATA;
  OutMsg.descrs     =OutMsg__DATA_DESCRS;
  OutMsg.data_align =4;

  //----------------------------------------
  svc::RemoteFB_Connector__StmtFetch_M_ToRow
   (tracer,
    spConnector,
    OpCtx,
    &hStmt,
    &OutMsg);

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_pClosingTr==nullptr)
  _TSO_CHECK(!hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
  _TSO_CHECK(hStmt->m_spFetchResult);

  //----------------------------------------
  {
   db_obj::t_dbvalue__i4 columnValue;

   assert_s(sizeof(columnValue)==4);

   memcpy(&columnValue,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(columnValue));

   _TSO_CHECK_MSG(columnValue==1,"columnValue="<<columnValue);
  }//local

  //-----------------------------------------
  {
   db_obj::t_dbvalue__i2 columnInd;

   assert_s(sizeof(columnInd)==2);

   memcpy(&columnInd,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(columnInd));

   _TSO_CHECK_MSG(columnInd==0,"columnInd="<<columnInd);
  }//local

  //-----------------------------------------
  svc::RemoteFB_Connector__StmtClose
   (tracer,
    spConnector,
    &hStmt);

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_pParentTr==nullptr);
  _TSO_CHECK(!hStmt->m_spFetchResult);

  if(!spConnector->GetPort()->TestPortFlag__lazy())
  {
   _TSO_CHECK(!hStmt->m_pClosingTr);
  }
  else
  {
   _TSO_CHECK(hStmt->m_pClosingTr==hTr);
  }
 }//for pass

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
}//test_200__reexecution

////////////////////////////////////////////////////////////////////////////////

const wchar_t* WORK_Test_036__StmtFetch_M__v0::tag_impl::helper__get_fetch_bugcheck_src
                                           (remote_fb::RemoteFB__Connector* pConnector)
{
 assert(pConnector);

 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 switch(const auto v=pConnector->GetPort()->get_protocol_version())
 {
  case remote_fb::protocol::FB_PROTOCOL_VERSION10:
  case remote_fb::protocol::FB_PROTOCOL_VERSION11:
  case remote_fb::protocol::FB_PROTOCOL_VERSION12:
   if(pConnector->GetPort()->TestPortFlag__lazy())
    return L"RemoteFB__API_P12_LAZY_SEND__FetchStatement_M::exec";

   return L"RemoteFB__API_P12__FetchStatement_M::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   if(pConnector->GetPort()->TestPortFlag__lazy())
    return L"RemoteFB__API_P13_LAZY_SEND__FetchStatement_M::exec";

   return L"RemoteFB__API_P13__FetchStatement_M::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_fetch_bugcheck_src

//------------------------------------------------------------------------
const wchar_t* WORK_Test_036__StmtFetch_M__v0::tag_impl::helper__get_fetch_subsystem
                                           (remote_fb::RemoteFB__Connector* pConnector)
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
}//helper__get_fetch_subsystem

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_036__StmtFetch_M__v0::tag_descr

struct WORK_Test_036__StmtFetch_M__v0::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_036__StmtFetch_M__v0::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_036__StmtFetch_M__v0::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_036__StmtFetch_M__v0::tag_descr
 WORK_Test_036__StmtFetch_M__v0::sm_Tests[]=
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

 //-----------------------------------------
 DEF_TEST_DESCR
  ("004.not_prepared",
   test_004__err__not_prepared)

 //-----------------------------------------
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("005.not_executed",
   test_005__err__not_executed)
#endif

 //-----------------------------------------
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("008.bug_check.fetch_after_eof",
   test_008__bug_check__fetch_after_eof)
#endif

 //-----------------------------------------
 DEF_TEST_DESCR
  ("100.select_empty_rowset",
   test_100__select_empty_rowset)

 DEF_TEST_DESCR
  ("101.select_one_row_with_one_col",
   test_101__select_one_row_with_one_col)

 DEF_TEST_DESCR
  ("101.select_one_row_with_one_col.for_update",
   test_101__select_one_row_with_one_col__for_update)

 DEF_TEST_DESCR
  ("F00.select_empty_rowset",
   test_F00__select_empty_rowset)

 DEF_TEST_DESCR
  ("F01.select_one_row",
   test_F01__select_one_row)

 DEF_TEST_DESCR
  ("200.reexecution",
   test_200__reexecution)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_036__StmtFetch_M__v0

void WORK_Test_036__StmtFetch_M__v0::create
                                           (TTSO_PushTest*      const pTestPusher,
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
  ftestID("RemoteFB.WORK.036.StmtFetch_M.v0.ptype__%1.%2");

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
