////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_034__StmtExecute_M__v3.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__xdr__encoder.h"
#include "source/db_client/remote_fb/ports/base/v01/remote_fb__ports__base_v01_writer.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__msg_v1.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/isc_base/isc_api.h"
#include "source/error_services/ibp_sqlstate_codes.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

#include <array>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_034__StmtExecute_M__v3::tag_impl

class WORK_Test_034__StmtExecute_M__v3::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public: //---------------------------------------------------------------
  static void test_006__err__not_prepared
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public: //---------------------------------------------------------------
#ifdef NDEBUG
  static void test_E201__bug_check__bad_inMsg__null_ptr_on_descrs
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_E202__bug_check__bad_inMsg__null_ptr_on_blr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_E203__bug_check__bad_inMsg__null_ptr_on_data
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_E204__bug_check__bad_inMsg__unexpected_blr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_E205__bug_check__bad_inMsg__unexpected_blr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_E206__bug_check__bad_inMsg__no_blr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_E207__bug_check__bad_inMsg__no_data
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
#endif

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

  // static void test_S007__insert__with_param1__core_bug__4785
  //              (TTSO_GlobalContext*     pParams,
  //               context_type*           pCtx,
  //               const TTSO_TestData_v2& Data);

  static void test_S007__insert__with_param1
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_S008__insert__with_param3
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public: //---------------------------------------------------------------
  static void test_IN_NN001__short
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN002__long
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN003__int64
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN004__float
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN005__double
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN006__type_time
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN007__type_date
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN008__timestamp
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN009__char
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN009__char__len0
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN010__varchar
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN011__boolean
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_NN012__int128
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public:
  static void test_IN_N001__array_null
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_N002__blob_null
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public:
  static void test_IN_OUT_001__short
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_OUT_002__long
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_OUT_003__int64
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_OUT_004__float
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_IN_OUT_005__double
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_StmtExec_bugcheck_src__test_msg
                          (remote_fb::RemoteFB__Connector* pConnector);

  static const wchar_t* helper__get_StmtExec_subsystem_id
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_034__StmtExecute_M__v3

////////////////////////////////////////////////////////////////////////////////
//TEST 006

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_006__err__not_prepared
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
 typedef TestServices svc;

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
   svc::RemoteFB_Connector__StmtExecute_M
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt);
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
     helper__get_StmtExec_subsystem_id(spConnector));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]
}//test_006__err__not_prepared

////////////////////////////////////////////////////////////////////////////////
//TEST E201

#ifdef NDEBUG
void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_E201__bug_check__bad_inMsg__null_ptr_on_descrs
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
 typedef TestServices svc;

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
   "insert into NUM (N_1_0) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(1);
 //
 // xsqlda->sqld=1;
 //
 // signed __int32 xparam0_value=5;
 // short          xparam0_ind=0;
 //
 // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 // xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 const std::array<unsigned char,12> InMsg__BLR=
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
 };//InMsg__BLR

 //-----------------------------------------
 const structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [long]
  5,
  0,
  0,
  0,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =4;

 //SET BAD DATA
 InMsg.descrs =ibp::IBP_BufferView<const svc::remote_fb_in_msg_v1::descr_type>(InMsg__DATA_DESCRS.size(),nullptr);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtExecute_M
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     &InMsg,
     /*pOutMsg*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__test_msg_bug_check__nullptr_to_descrs
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_bugcheck_src__test_msg(spConnector),
     L"#001",
     L"pInMsg",
     InMsg__DATA_DESCRS.size());

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_E201__bug_check__bad_inMsg__null_ptr_on_descrs
#endif

////////////////////////////////////////////////////////////////////////////////
//TEST E202

#ifdef NDEBUG
void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_E202__bug_check__bad_inMsg__null_ptr_on_blr
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
 typedef TestServices svc;

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
   "insert into NUM (N_1_0) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(1);
 //
 // xsqlda->sqld=1;
 //
 // signed __int32 xparam0_value=5;
 // short          xparam0_ind=0;
 //
 // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 // xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 const std::array<unsigned char,12> InMsg__BLR=
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
 };//InMsg__BLR

 //-----------------------------------------
 const structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [long]
  5,
  0,
  0,
  0,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =4;

 //SET BAD DATA
 InMsg.blr =ibp::IBP_BufferView<const svc::remote_fb_in_msg_v1::byte_type>(InMsg__BLR.size(),nullptr);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtExecute_M
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     &InMsg,
     /*pOutMsg*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__test_msg_bug_check__nullptr_to_blr
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_bugcheck_src__test_msg(spConnector),
     L"#002",
     L"pInMsg",
     InMsg__BLR.size());

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_E202__bug_check__bad_inMsg__null_ptr_on_blr
#endif

////////////////////////////////////////////////////////////////////////////////
//TEST E203

#ifdef NDEBUG
void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_E203__bug_check__bad_inMsg__null_ptr_on_data
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
 typedef TestServices svc;

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
   "insert into NUM (N_1_0) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(1);
 //
 // xsqlda->sqld=1;
 //
 // signed __int32 xparam0_value=5;
 // short          xparam0_ind=0;
 //
 // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 // xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 const std::array<unsigned char,12> InMsg__BLR=
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
 };//InMsg__BLR

 //-----------------------------------------
 const structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [long]
  5,
  0,
  0,
  0,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =4;

 //SET BAD DATA
 InMsg.data =ibp::IBP_BufferView<const svc::remote_fb_in_msg_v1::byte_type>(InMsg__DATA.size(),nullptr);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtExecute_M
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     &InMsg,
     /*pOutMsg*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__test_msg_bug_check__nullptr_to_data
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_bugcheck_src__test_msg(spConnector),
     L"#003",
     L"pInMsg",
     InMsg__DATA.size());

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_E203__bug_check__bad_inMsg__null_ptr_on_data
#endif

////////////////////////////////////////////////////////////////////////////////
//TEST E204

#ifdef NDEBUG
void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_E204__bug_check__bad_inMsg__unexpected_blr
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
 typedef TestServices svc;

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
   "insert into NUM (N_1_0) values (1);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(1);
 //
 // xsqlda->sqld=1;
 //
 // signed __int32 xparam0_value=5;
 // short          xparam0_ind=0;
 //
 // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 // xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 const std::array<unsigned char,12> InMsg__BLR=
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
 };//InMsg__BLR

 ////-----------------------------------------
 //const structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 //{
 // //---- value [long]
 // 5,
 // 0,
 // 0,
 // 0,
 // //---- indicator [short]
 // 0,
 // 0,
 //};//InMsg__DATA

 //-----------------------------------------
 //std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;
 //
 //InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 //InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 //InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 //InMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 //InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 //InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr    =InMsg__BLR;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtExecute_M
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     &InMsg,
     /*pOutMsg*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__test_msg_bug_check__unexpected_blr
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_bugcheck_src__test_msg(spConnector),
     L"#004",
     L"pInMsg",
     InMsg__BLR.size());

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_E204__bug_check__bad_inMsg__unexpected_blr
#endif

////////////////////////////////////////////////////////////////////////////////
//TEST E205

#ifdef NDEBUG
void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_E205__bug_check__bad_inMsg__unexpected_blr
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
 typedef TestServices svc;

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
   "insert into NUM (N_1_0) values (1);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(1);
 //
 // xsqlda->sqld=1;
 //
 // signed __int32 xparam0_value=5;
 // short          xparam0_ind=0;
 //
 // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 // xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 //const std::array<unsigned char,12> InMsg__BLR=
 //{
 // /*  0 */ isc_api::ibp_isc_blr_version5,
 // /*  1 */ isc_api::ibp_isc_blr_begin,
 // /*  2 */ isc_api::ibp_isc_blr_message,
 // /*  3 */ 0, // message number
 // /*  4 */ 2, // cPars_lower
 // /*  5 */ 0, // cPars_upper
 // /*  6 */ isc_api::ibp_isc_blr_dtype__long,   // data type
 // /*  7 */ 0,                                  // data scale
 // /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
 // /*  9 */ 0,                                  // indicator scale
 // /* 10 */ isc_api::ibp_isc_blr_end,
 // /* 11 */ isc_api::ibp_isc_blr_eoc,
 //};//InMsg__BLR

 ////-----------------------------------------
 const structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [long]
  5,
  0,
  0,
  0,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA__DATA

 //-----------------------------------------
 //std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;
 //
 //InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 //InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 //InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 //InMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 //InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 //InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.data    =InMsg__DATA;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtExecute_M
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     &InMsg,
     /*pOutMsg*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__test_msg_bug_check__unexpected_data
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_bugcheck_src__test_msg(spConnector),
     L"#005",
     L"pInMsg",
     InMsg__DATA.size());

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_E205__bug_check__bad_inMsg__unexpected_blr
#endif

////////////////////////////////////////////////////////////////////////////////
//TEST E206

#ifdef NDEBUG
void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_E206__bug_check__bad_inMsg__no_blr
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
 typedef TestServices svc;

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
   "insert into NUM (N_1_0) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(1);
 //
 // xsqlda->sqld=1;
 //
 // signed __int32 xparam0_value=5;
 // short          xparam0_ind=0;
 //
 // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 // xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 const std::array<unsigned char,12> InMsg__BLR=
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
 };//InMsg__BLR

 //-----------------------------------------
 const structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [long]
  5,
  0,
  0,
  0,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 //InMsg.blr    =InMsg__BLR;
 InMsg.data   =InMsg__DATA;
 InMsg.descrs =InMsg__DATA_DESCRS;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtExecute_M
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     &InMsg,
     /*pOutMsg*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__test_msg_bug_check__no_blr
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_bugcheck_src__test_msg(spConnector),
     L"#006",
     L"pInMsg",
     InMsg__DATA_DESCRS.size());

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_E206__bug_check__bad_inMsg__no_blr
#endif

////////////////////////////////////////////////////////////////////////////////
//TEST E207

#ifdef NDEBUG
void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_E207__bug_check__bad_inMsg__no_data
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
 typedef TestServices svc;

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
   "insert into NUM (N_1_0) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(1);
 //
 // xsqlda->sqld=1;
 //
 // signed __int32 xparam0_value=5;
 // short          xparam0_ind=0;
 //
 // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 // xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 const std::array<unsigned char,12> InMsg__BLR=
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
 };//InMsg__BLR

 //-----------------------------------------
 const structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [long]
  5,
  0,
  0,
  0,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr    =InMsg__BLR;
 //InMsg.data   =InMsg__DATA;
 InMsg.descrs =InMsg__DATA_DESCRS;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtExecute_M
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     &hStmt,
     &InMsg,
     /*pOutMsg*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__test_msg_bug_check__no_data
    (tracer,
     exc.get_record(0),
     helper__get_StmtExec_bugcheck_src__test_msg(spConnector),
     L"#007",
     L"pInMsg",
     InMsg__DATA_DESCRS.size());

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_E207__bug_check__bad_inMsg__no_data
#endif

////////////////////////////////////////////////////////////////////////////////
//TEST S001

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_S001__insert__without_params
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
 typedef TestServices svc;

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
   "insert into NUM (TEST_ID) values (NULL);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S001__insert__without_params

////////////////////////////////////////////////////////////////////////////////
//TEST S002

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_S002__set_transaction
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
 typedef TestServices svc;

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
   nullptr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   "set transaction;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S002__set_transaction

////////////////////////////////////////////////////////////////////////////////
//TEST S003

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_S003__commit
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
 typedef TestServices svc;

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
   nullptr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   "commit;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt);

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 _TSO_CHECK(!hTrCopy->m_pParentPort);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S003__commit

////////////////////////////////////////////////////////////////////////////////
//TEST S004

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_S004__commit_retain
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
 typedef TestServices svc;

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
   nullptr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   "commit retain;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 const auto hTrIDCopy=hTr->m_ID.get_value();

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt);

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

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
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S004__commit_retain

////////////////////////////////////////////////////////////////////////////////
//TEST S005

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_S005__rollback
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
 typedef TestServices svc;

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
   nullptr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   "rollback;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt);

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 _TSO_CHECK(!hTrCopy->m_pParentPort);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S005__rollback

////////////////////////////////////////////////////////////////////////////////
//TEST S006

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_S006__rollback_retain
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
 typedef TestServices svc;

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
   nullptr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   "rollback retain;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 const auto hTrIDCopy=hTr->m_ID.get_value();

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt);

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTrCopy->m_ID.has_value());
 _TSO_CHECK(hTrCopy->m_ID.get_value()==hTrIDCopy);

 _TSO_CHECK(hTrCopy->m_pParentPort);

 //-----------------------------------------
 svc::RemoteFB_Connector__Rollback
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S006__rollback_retain

////////////////////////////////////////////////////////////////////////////////
//TEST S007

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_S007__insert__with_param1
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
 typedef TestServices svc;

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
   "insert into NUM (N_1_0) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(1);
 //
 // xsqlda->sqld=1;
 //
 // signed __int32 xparam0_value=5;
 // short          xparam0_ind=0;
 //
 // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 // xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 const std::array<unsigned char,12> InMsg__BLR=
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
 };//InMsg__BLR

 //-----------------------------------------
 const structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [long]
  5,
  0,
  0,
  0,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =4;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*pOutMsg*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S007__insert__with_param1

////////////////////////////////////////////////////////////////////////////////
//TEST S008

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_S008__insert__with_param3
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
 typedef TestServices svc;

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
   "insert into NUM (N_1_0,N_2_0,N_3_0) values (?,?,?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(3);
 //
 // xsqlda->sqld=3;
 //
 // signed __int32 xparam0_value=6;
 // short          xparam0_ind=0;
 //
 // signed __int32 xparam1_value=7;
 // short          xparam1_ind=-1;
 //
 // signed __int32 xparam2_value=8;
 // short          xparam2_ind=0;
 //
 // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 // xsqlda->sqlvar[0].sqlind =&xparam0_ind;
 //
 // xsqlda->sqlvar[1].sqltype=isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[1].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xparam1_value);
 // xsqlda->sqlvar[1].sqlind =&xparam1_ind;
 //
 // xsqlda->sqlvar[2].sqltype=isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[2].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[2].sqldata=reinterpret_cast<char*>(&xparam2_value);
 // xsqlda->sqlvar[2].sqlind =&xparam2_ind;

 const std::array<unsigned char,20> InMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 6, // cPars_lower  (2*cColumns)
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__long,   // data type
  /*  7 */ 0,                                  // data scale
  /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /*  9 */ 0,                                  // indicator scale
  /* 10 */ isc_api::ibp_isc_blr_dtype__long,   // data type
  /* 11 */ 0,                                  // data scale
  /* 12 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /* 13 */ 0,                                  // indicator scale
  /* 14 */ isc_api::ibp_isc_blr_dtype__long,   // data type
  /* 15 */ 0,                                  // data scale
  /* 16 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /* 17 */ 0,                                  // indicator scale
  /* 18 */ isc_api::ibp_isc_blr_end,
  /* 19 */ isc_api::ibp_isc_blr_eoc,
 };//InMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [long]
  6,
  0,
  0,
  0,
  //---- indicator [short]
  0,
  0,
  //---- aligning bytes
  0,
  0,
  //---- value [long]
  7,
  0,
  0,
  0,
  //---- indicator [short]
  0xFF,
  0xFF,
  //---- aligning bytes
  0,
  0,
  //---- value [long]
  8,
  0,
  0,
  0,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,3> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 InMsg__DATA_DESCRS[1].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 InMsg__DATA_DESCRS[1].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 InMsg__DATA_DESCRS[1].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[1].m_msg_value_block_size   =4;
 InMsg__DATA_DESCRS[1].m_msg_value_block_offset =8;
 InMsg__DATA_DESCRS[1].m_msg_sqlind_offset      =12;

 InMsg__DATA_DESCRS[2].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 InMsg__DATA_DESCRS[2].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 InMsg__DATA_DESCRS[2].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[2].m_msg_value_block_size   =4;
 InMsg__DATA_DESCRS[2].m_msg_value_block_offset =16;
 InMsg__DATA_DESCRS[2].m_msg_sqlind_offset      =20;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =4;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*pOutMSG*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S008__insert__with_param3

////////////////////////////////////////////////////////////////////////////////
//TEST NN001

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_NN001__short
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
   "insert into TEST_MODIFY_ROW (COL_SMALLINT) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 //XSQLDA_V1_Wrapper xsqlda(1);
 //
 //xsqlda->sqld=1;
 //
 signed __int16 xparam0_value=222;
 ////short          xparam0_ind=0;
 //
 //xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_short;
 //xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 //xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 //xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 const std::array<unsigned char,12> InMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__short,  // data type
  /*  7 */ 0,                                  // data scale
  /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /*  9 */ 0,                                  // indicator scale
  /* 10 */ isc_api::ibp_isc_blr_end,
  /* 11 */ isc_api::ibp_isc_blr_eoc,
 };//InMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [short]
  0,
  0,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 memcpy(&InMsg__DATA[0],&xparam0_value,sizeof(xparam0_value));

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__short;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_short;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =2;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =2;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =2;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*pOutMSG*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN001__short

////////////////////////////////////////////////////////////////////////////////
//TEST NN002

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_NN002__long
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
   "insert into TEST_MODIFY_ROW (COL_INTEGER) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(1);
 //
 // xsqlda->sqld=1;
 //
 signed __int32 xparam0_value=4444;
 // //short          xparam0_ind=0;
 //
 // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long;
 // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 // xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 const std::array<unsigned char,12> InMsg__BLR=
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
 };//InMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [long]
  0,
  0,
  0,
  0,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 memcpy(&InMsg__DATA[0],&xparam0_value,sizeof(xparam0_value));

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =4;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*pOutMSG*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN002__long

////////////////////////////////////////////////////////////////////////////////
//TEST NN003

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_NN003__int64
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
   "insert into TEST_MODIFY_ROW (COL_BIGINT) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 LONG       __tmp_val_for_align=0;__tmp_val_for_align;
 signed __int64   xparam0_values[]={INT64_MIN,INT64_MIN+1,-1,0,1,INT64_MAX-1,INT64_MAX};
 //short          xparam0_ind=0;

 for(size_t i=0;i!=_DIM_(xparam0_values);++i)
 {
  tracer<<L"-------------------------- ["<<i<<L"]: "<<xparam0_values[i]<<send;

  // XSQLDA_V1_Wrapper xsqlda(1);
  //
  // xsqlda->sqld=1;
  //
  // //short          xparam0_ind=0;
  //
  // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_int64;
  // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_values[i]);
  // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_values[i]);
  // xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

  const std::array<unsigned char,12> InMsg__BLR=
  {
   /*  0 */ isc_api::ibp_isc_blr_version5,
   /*  1 */ isc_api::ibp_isc_blr_begin,
   /*  2 */ isc_api::ibp_isc_blr_message,
   /*  3 */ 0, // message number
   /*  4 */ 2, // cPars_lower
   /*  5 */ 0, // cPars_upper
   /*  6 */ isc_api::ibp_isc_blr_dtype__int64,  // data type
   /*  7 */ 0,                                  // data scale
   /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
   /*  9 */ 0,                                  // indicator scale
   /* 10 */ isc_api::ibp_isc_blr_end,
   /* 11 */ isc_api::ibp_isc_blr_eoc,
  };//InMsg__BLR

  //----------------------------------------
  const auto v=xparam0_values[i];

  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
  {
   //---- value [int64]
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   //---- indicator [short]
   0,
   0,
  };//InMsg__DATA

  memcpy(&InMsg__DATA[0],&v,sizeof(v));

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

  InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__int64;
  InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_int64;
  InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  InMsg__DATA_DESCRS[0].m_msg_value_block_size   =8;
  InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =8;

  //----------------------------------------
  svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =8;

  //----------------------------------------
  svc::RemoteFB_Connector__StmtExecute_M
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    &InMsg,
    /*pOutMSG*/nullptr);

  _TSO_CHECK(hTr==hTrCopy);
  _TSO_CHECK(hTr->m_ID.has_value());

  _TSO_CHECK(hStmt==hStmtCopy);
  _TSO_CHECK(hStmt->m_ID.has_value());
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 //-----------------------------------------
 _TSO_CHECK(__tmp_val_for_align==0);
}//test_IN_NN003__int64

////////////////////////////////////////////////////////////////////////////////
//TEST NN004

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_NN004__float
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
   "insert into TEST_MODIFY_ROW (COL_FLOAT) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(1);
 //
 // xsqlda->sqld=1;
 //
 float     xparam0_value=123;
 // //short     xparam0_ind=0;
 //
 // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_float;
 // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 // xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 const std::array<unsigned char,11> InMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__float,  // data type
  /*  7 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /*  8 */ 0,                                  // indicator scale
  /*  9 */ isc_api::ibp_isc_blr_end,
  /* 10 */ isc_api::ibp_isc_blr_eoc,
 };//InMsg__BLR

 //-----------------------------------------
 assert_s(sizeof(float)==4);

 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [float]
  0,
  0,
  0,
  0,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 memcpy(&InMsg__DATA[0],&xparam0_value,sizeof(xparam0_value));

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__float;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_float;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =4;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*pOutMSG*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN004__float

////////////////////////////////////////////////////////////////////////////////
//TEST NN005

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_NN005__double
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
   "insert into TEST_MODIFY_ROW (COL_DOUBLE) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 //XSQLDA_V1_Wrapper xsqlda(1);
 //
 //xsqlda->sqld=1;
 //
 LONG       __tmp_val_for_align=0;__tmp_val_for_align;
 double     xparam0_value=54321.5;
 ////short     xparam0_ind=0;
 //
 //xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_double;
 //xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 //xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 //xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 const std::array<unsigned char,11> InMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__double, // data type
  /*  7 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /*  8 */ 0,                                  // indicator scale
  /*  9 */ isc_api::ibp_isc_blr_end,
  /* 10 */ isc_api::ibp_isc_blr_eoc,
 };//InMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [double]
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 memcpy(&InMsg__DATA[0],&xparam0_value,sizeof(xparam0_value));

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__double;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_double;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =8;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =8;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =8;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*pOutMSG*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 //-----------------------------------------
 _TSO_CHECK(__tmp_val_for_align==0);
}//test_IN_NN005__double

////////////////////////////////////////////////////////////////////////////////
//TEST NN006

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_NN006__type_time
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
   "insert into TEST_MODIFY_ROW (COL_TYPE_TIME) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 //XSQLDA_V1_Wrapper xsqlda(1);
 //
 //xsqlda->sqld=1;
 //
 const isc_api::t_ibp_isc_time  c_tm__sec      =10000;
 const isc_api::t_ibp_isc_time  c_tm__min      =c_tm__sec*60;
 const isc_api::t_ibp_isc_time  c_tm__hour     =c_tm__min*60;

 isc_api::t_ibp_isc_time  xparam0_value=5000+1*c_tm__sec+2*c_tm__min+3*c_tm__hour;
 ////short                  xparam0_ind=0;
 //
 //xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_type_time;
 //xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 //xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 //xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 const std::array<unsigned char,11> InMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__sql_time, // data type
  /*  7 */ isc_api::ibp_isc_blr_dtype__short,    // indicator type
  /*  8 */ 0,                                    // indicator scale
  /*  9 */ isc_api::ibp_isc_blr_end,
  /* 10 */ isc_api::ibp_isc_blr_eoc,
 };//InMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [t_ibp_isc_time]
  0,
  0,
  0,
  0,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 memcpy(&InMsg__DATA[0],&xparam0_value,sizeof(xparam0_value));

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__sql_time;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_type_time;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =4;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*pOutMSG*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN006__type_time

////////////////////////////////////////////////////////////////////////////////
//TEST NN007

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_NN007__type_date
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
   "insert into TEST_MODIFY_ROW (COL_TYPE_DATE) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(1);
 //
 // xsqlda->sqld=1;
 //
 isc_api::t_ibp_isc_date  xparam0_value=1;
 // //short                  xparam0_ind=0;
 //
 // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_type_date;
 // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 // xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 const std::array<unsigned char,11> InMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__sql_date, // data type
  /*  7 */ isc_api::ibp_isc_blr_dtype__short,    // indicator type
  /*  8 */ 0,                                    // indicator scale
  /*  9 */ isc_api::ibp_isc_blr_end,
  /* 10 */ isc_api::ibp_isc_blr_eoc,
 };//InMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [t_ibp_isc_date]
  0,
  0,
  0,
  0,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 memcpy(&InMsg__DATA[0],&xparam0_value,sizeof(xparam0_value));

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__sql_date;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_type_date;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =4;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*pOutMSG*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN007__type_date

////////////////////////////////////////////////////////////////////////////////
//TEST NN008

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_NN008__timestamp
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
   "insert into TEST_MODIFY_ROW (COL_TIMESTAMP) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(1);
 //
 // xsqlda->sqld=1;
 //
 const isc_api::t_ibp_isc_time  c_tm__sec      =10000;
 const isc_api::t_ibp_isc_time  c_tm__min      =c_tm__sec*60;
 const isc_api::t_ibp_isc_time  c_tm__hour     =c_tm__min*60;

 isc_api::t_ibp_isc_timestamp  xparam0_value={1,1234+5*c_tm__sec+6*c_tm__min+7*c_tm__hour};
 // //short                       xparam0_ind=0;
 //
 // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_timestamp;
 // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 // xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 const std::array<unsigned char,11> InMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__timestamp, // data type
  /*  7 */ isc_api::ibp_isc_blr_dtype__short,     // indicator type
  /*  8 */ 0,                                     // indicator scale
  /*  9 */ isc_api::ibp_isc_blr_end,
  /* 10 */ isc_api::ibp_isc_blr_eoc,
 };//InMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [t_ibp_isc_timestamp]
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 memcpy(&InMsg__DATA[0],&xparam0_value,sizeof(xparam0_value));

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__timestamp;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_timestamp;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =8;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =8;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =4;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*pOutMSG*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN008__timestamp

////////////////////////////////////////////////////////////////////////////////
//TEST NN009

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_NN009__char
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
 params.set_dbprop_init__ctype(L"ASCII");

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
   "insert into TEST_MODIFY_ROW (COL_CHAR_10) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 //XSQLDA_V1_Wrapper xsqlda(1);
 //
 //xsqlda->sqld=1;
 //
 char      xparam0_value[]={'1','2','3','4','5','6',' ','8','A',};
 ////short   xparam0_ind=0;
 //
 //xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_text;
 //xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 //xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 //xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 const std::array<unsigned char,13> InMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__text,      // data type
  /*  7 */ 9,                                     // the low byte of length
  /*  8 */ 0,                                     // the high byte of length
  /*  9 */ isc_api::ibp_isc_blr_dtype__short,     // indicator type
  /* 10 */ 0,                                     // indicator scale
  /* 11 */ isc_api::ibp_isc_blr_end,
  /* 12 */ isc_api::ibp_isc_blr_eoc,
 };//InMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [char(9)]
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  //---- align
  123,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 memcpy(&InMsg__DATA[0],&xparam0_value,sizeof(xparam0_value));

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__text;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_text;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =9;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =10;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =2;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*pOutMSG*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN009__char

////////////////////////////////////////////////////////////////////////////////
//TEST NN009

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_NN009__char__len0
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
 params.set_dbprop_init__ctype(L"ASCII");

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
   "insert into TEST_MODIFY_ROW (COL_CHAR_10) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 //XSQLDA_V1_Wrapper xsqlda(1);
 //
 //xsqlda->sqld=1;
 //
 ////short   xparam0_ind=0;
 //
 //xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_text;
 //xsqlda->sqlvar[0].sqllen =0;
 //xsqlda->sqlvar[0].sqldata=nullptr;
 //xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 const std::array<unsigned char,13> InMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__text,      // data type
  /*  7 */ 0,                                     // the low byte of length
  /*  8 */ 0,                                     // the high byte of length
  /*  9 */ isc_api::ibp_isc_blr_dtype__short,     // indicator type
  /* 10 */ 0,                                     // indicator scale
  /* 11 */ isc_api::ibp_isc_blr_end,
  /* 12 */ isc_api::ibp_isc_blr_eoc,
 };//InMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [char(0)]
  //---- align
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__text;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_text;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =0;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =2;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*pOutMSG*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN009__char__len0

////////////////////////////////////////////////////////////////////////////////
//TEST NN010

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_NN010__varchar
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
 params.set_dbprop_init__ctype(L"ASCII");

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
   "insert into TEST_MODIFY_ROW (COL_VARCHAR_10) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(1);
 //
 // xsqlda->sqld=1;
 //
 //struct tag_varchar_data
 //{
 // short length;
 // char  value[5];
 //};//struct tag_varchar_data
 //
 //tag_varchar_data xparam0_data={4,{'1','2','3',' '}};
 //short          xparam0_ind=0;
 //
 // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_varying;
 // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_data.value);
 // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_data);
 // xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 const std::array<unsigned char,13> InMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__varying,   // data type
  /*  7 */ 5,                                     // the low byte of length
  /*  8 */ 0,                                     // the high byte of length
  /*  9 */ isc_api::ibp_isc_blr_dtype__short,     // indicator type
  /* 10 */ 0,                                     // indicator scale
  /* 11 */ isc_api::ibp_isc_blr_end,
  /* 12 */ isc_api::ibp_isc_blr_eoc,
 };//InMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [varchar(5)]
  4, //size1
  0, //size2
  '1',
  '2',
  '3',
  ' ',
  '+', // garbage
  //---- align
  '-', // it is being ignored
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__varying;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_varying;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =7;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =8;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =2;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*pOutMSG*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_NN010__varchar

////////////////////////////////////////////////////////////////////////////////
//TEST NN011

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_NN011__boolean
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
   "insert into TEST_MODIFY_ROW (COL_BOOLEAN) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 //XSQLDA_V1_Wrapper xsqlda(1);
 //
 //xsqlda->sqld=1;
 //
 LONG       __tmp_val_for_align=0;__tmp_val_for_align;
 isc_api::t_ibp_fb030_bool xparam0_value=isc_api::ibp_fb030_false;
 ////short     xparam0_ind=0;
 //
 //xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_double;
 //xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 //xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 //xsqlda->sqlvar[0].sqlind =nullptr;//&xparam0_ind;

 //-----------------------------------------
 const std::array<unsigned char,11> InMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_fb030_blr_dtype__bool, // data type
  /*  7 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /*  8 */ 0,                                  // indicator scale
  /*  9 */ isc_api::ibp_isc_blr_end,
  /* 10 */ isc_api::ibp_isc_blr_eoc,
 };//InMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [bool]
  0xFF,
  //---- align
  0xFE,
  //---- indicator [short]
  0,
  0,
 };//InMsg__DATA

 memcpy(&InMsg__DATA[0],&xparam0_value,sizeof(xparam0_value));

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_fb030_blr_dtype__bool;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_fb030_sql_boolean;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =1;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =2;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =2;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*pOutMSG*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 //-----------------------------------------
 _TSO_CHECK(__tmp_val_for_align==0);
}//test_IN_NN011__boolean

////////////////////////////////////////////////////////////////////////////////
//TEST NN012

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_NN012__int128
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
   "insert into TEST_MODIFY_ROW (COL_INT128) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 LONG __tmp_val_for_align=0;__tmp_val_for_align;

 isc_api::t_ibp_fb040_int128 xparam0_values[]=
  {
   db_obj::make_fb040_int128(1,0),
   db_obj::make_fb040_int128(0,1),
  };

 //short          xparam0_ind=0;

 for(size_t i=0;i!=_DIM_(xparam0_values);++i)
 {
  tracer<<L"-------------------------- ["<<i<<L"]: "<<xparam0_values[i]<<send;

  const std::array<unsigned char,12> InMsg__BLR=
  {
   /*  0 */ isc_api::ibp_isc_blr_version5,
   /*  1 */ isc_api::ibp_isc_blr_begin,
   /*  2 */ isc_api::ibp_isc_blr_message,
   /*  3 */ 0, // message number
   /*  4 */ 2, // cPars_lower
   /*  5 */ 0, // cPars_upper
   /*  6 */ isc_api::ibp_fb040_blr_dtype__int128,  // data type
   /*  7 */ 0,                                     // data scale
   /*  8 */ isc_api::ibp_isc_blr_dtype__short,     // indicator type
   /*  9 */ 0,                                     // indicator scale
   /* 10 */ isc_api::ibp_isc_blr_end,
   /* 11 */ isc_api::ibp_isc_blr_eoc,
  };//InMsg__BLR

  //----------------------------------------
  const auto v=xparam0_values[i];

  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
  {
   //---- value [int128]
   0,0,
   0,0,
   0,0,
   0,0,
   0,0,
   0,0,
   0,0,
   0,0,
   //---- indicator [short]
   0,
   0,
  };//InMsg__DATA

  memcpy(&InMsg__DATA[0],&v,sizeof(v));

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

  InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_fb040_blr_dtype__int128;
  InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_fb040_sql_int128;
  InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  InMsg__DATA_DESCRS[0].m_msg_value_block_size   =16;
  InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =16;

  //----------------------------------------
  svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =8;

  //----------------------------------------
  svc::RemoteFB_Connector__StmtExecute_M
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    &InMsg,
    /*pOutMSG*/nullptr);

  _TSO_CHECK(hTr==hTrCopy);
  _TSO_CHECK(hTr->m_ID.has_value());

  _TSO_CHECK(hStmt==hStmtCopy);
  _TSO_CHECK(hStmt->m_ID.has_value());
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 //-----------------------------------------
 _TSO_CHECK(__tmp_val_for_align==0);
}//test_IN_NN012__int128

////////////////////////////////////////////////////////////////////////////////
//TEST N001

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_N001__array_null
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
   "insert into TEST_MODIFY_ROW (COL_INT_ARRAY) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 //XSQLDA_V1_Wrapper xsqlda(1);
 //
 //xsqlda->sqld=1;
 //
 //db_obj::DB_IBARRAYID    xparam0_value={};
 //short                   xparam0_ind=-1;
 //
 //xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_array|1;
 //xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 //xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 //xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 const std::array<unsigned char,12> InMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__quad,   // data type
  /*  7 */ 0,                                  // data scale
  /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /*  9 */ 0,                                  // indicator scale
  /* 10 */ isc_api::ibp_isc_blr_end,
  /* 11 */ isc_api::ibp_isc_blr_eoc,
 };//InMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [quad]
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  //---- indicator [short]   NULL (-1)
  0xFF,
  0xFF,
 };//InMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__quad;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_array;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =8;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =8;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

  InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =4;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*pOutMSG*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_N001__array_null

////////////////////////////////////////////////////////////////////////////////
//TEST N002

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_N002__blob_null
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
   "insert into TEST_MODIFY_ROW (COL_INT_ARRAY) values (?);");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 //XSQLDA_V1_Wrapper xsqlda(1);
 //
 //xsqlda->sqld=1;
 //
 //db_obj::DB_IBBLOBID     xparam0_value={};
 //short                   xparam0_ind=-1;
 //
 //xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_blob|1;
 //xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 //xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 //xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 const std::array<unsigned char,12> InMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 2, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__quad,   // data type
  /*  7 */ 0,                                  // data scale
  /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /*  9 */ 0,                                  // indicator scale
  /* 10 */ isc_api::ibp_isc_blr_end,
  /* 11 */ isc_api::ibp_isc_blr_eoc,
 };//InMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
 {
  //---- value [quad]
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  //---- indicator [short]   NULL (-1)
  0xFF,
  0xFF,
 };//InMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__quad;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_blob;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =8;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =8;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =4;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*pOutMSG*/nullptr);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_N002__blob_null

////////////////////////////////////////////////////////////////////////////////
//TEST IN_OUT 001

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_OUT_001__short
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 using value_type=signed __int16;

 assert_s(sizeof(value_type)==2);

 //-----------------------------------------
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
   "insert into TEST_MODIFY_ROW (COL_SMALLINT) values (?) RETURNING COL_SMALLINT;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 struct tag_test_value
 {
  value_type set_value;
  short      set_indicator;

  value_type get_value;
  short      get_indicator;
 };//struct tag_test_value

 using limit_t=std::numeric_limits<value_type>;

 const tag_test_value test_values[]=
 {
  { (limit_t::min)()    ,    0, (limit_t::min)()     ,    0},
  { (limit_t::min)()+1  ,    0, (limit_t::min)()+1   ,    0},
  { -1                  ,    0, -1                   ,    0},
  {  0                  ,    0,  0                   ,    0},
  { (limit_t::max)()    ,   -1, -1                   ,   -1},
  {  1                  ,    0,  1                   ,    0},
  { (limit_t::max)()-1  ,    0, (limit_t::max)()-1   ,    0},
  { (limit_t::max)()    ,    0, (limit_t::max)()     ,    0},
 };//test_values

 for(size_t i=0;i!=_DIM_(test_values);++i)
 {
  const auto& testValue=test_values[i];

  tracer<<L"-------------------------- ["<<i<<L"]: "<<testValue.set_value<<" [ind: "<<testValue.set_indicator<<"]"<<send;

  //------------------------------------------------- INPUT
  const std::array<unsigned char,12> InMsg__BLR=
  {
   /*  0 */ isc_api::ibp_isc_blr_version5,
   /*  1 */ isc_api::ibp_isc_blr_begin,
   /*  2 */ isc_api::ibp_isc_blr_message,
   /*  3 */ 0, // message number
   /*  4 */ 2, // cPars_lower
   /*  5 */ 0, // cPars_upper
   /*  6 */ isc_api::ibp_isc_blr_dtype__short,  // data type
   /*  7 */ 0,                                  // data scale
   /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
   /*  9 */ 0,                                  // indicator scale
   /* 10 */ isc_api::ibp_isc_blr_end,
   /* 11 */ isc_api::ibp_isc_blr_eoc,
  };//InMsg__BLR

  //----------------------------------------
  const auto input_value=testValue.set_value;

  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
  {
   //---- value [short]
   0,
   0,
   //---- indicator [short]
   0,
   0,
  };//InMsg__DATA

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

  InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__short;
  InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_short;
  InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  InMsg__DATA_DESCRS[0].m_msg_value_block_size   =2;
  InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =2;

  //----------------------------------------
  memcpy(&InMsg__DATA[InMsg__DATA_DESCRS[0].m_msg_value_block_offset],&input_value,sizeof(input_value));
  memcpy(&InMsg__DATA[InMsg__DATA_DESCRS[0].m_msg_sqlind_offset],&testValue.set_indicator,sizeof(testValue.set_indicator));

  //------------------------------------------------- OUTPUT
  const std::array<unsigned char,12> OutMsg__BLR=
  {
   /*  0 */ isc_api::ibp_isc_blr_version5,
   /*  1 */ isc_api::ibp_isc_blr_begin,
   /*  2 */ isc_api::ibp_isc_blr_message,
   /*  3 */ 0, // message number
   /*  4 */ 2, // cPars_lower
   /*  5 */ 0, // cPars_upper
   /*  6 */ isc_api::ibp_isc_blr_dtype__short,  // data type
   /*  7 */ 0,                                  // data scale
   /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
   /*  9 */ 0,                                  // indicator scale
   /* 10 */ isc_api::ibp_isc_blr_end,
   /* 11 */ isc_api::ibp_isc_blr_eoc,
  };//OutMsg__BLR

  //----------------------------------------
  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
  {
   //---- value [short]
   0xFF,
   0xFF,
   //---- indicator [short]
   0xFE,
   0xFE,
  };//OutMsg__DATA

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> OutMsg__DATA_DESCRS;

  OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__short;
  OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_short;
  OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =2;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =2;

  //----------------------------------------
  svc::remote_fb_in_msg_v1 InMsg;

  InMsg.blr        =InMsg__BLR;
  InMsg.data       =InMsg__DATA;
  InMsg.descrs     =InMsg__DATA_DESCRS;
  InMsg.data_align =2;

  svc::remote_fb_out_msg_v1 OutMsg;

  OutMsg.blr        =OutMsg__BLR;
  OutMsg.data       =OutMsg__DATA;
  OutMsg.descrs     =OutMsg__DATA_DESCRS;
  OutMsg.data_align =2;

  //----------------------------------------
  svc::RemoteFB_Connector__StmtExecute_M
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    &InMsg,
    &OutMsg);

  _TSO_CHECK(hTr==hTrCopy);
  _TSO_CHECK(hTr->m_ID.has_value());

  _TSO_CHECK(hStmt==hStmtCopy);
  _TSO_CHECK(hStmt->m_ID.has_value());

  //----------------------------------------
  short out_null_indicator=123;

  memcpy(&out_null_indicator,&OutMsg__DATA.data()[OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(out_null_indicator));

  if(out_null_indicator!=testValue.get_indicator)
  {
   tracer(tso_msg_error,-1)
    <<L"The wrong OUT-parameter null indiciator: "<<out_null_indicator<<L". The expected value is "<<testValue.get_indicator<<"."<<send;
  }
  else
  {
   tracer
    <<L"OK. The OUT-parameter null indiciator is correct: "<<out_null_indicator<<L"."<<send;
  }//else

  if(out_null_indicator==0)
  {
   auto out_value=input_value; out_value=0;

   memcpy(&out_value,&OutMsg__DATA.data()[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(out_value));

   if(out_value!=testValue.get_value)
   {
    tracer(tso_msg_error,-1)
     <<L"The wrong OUT-parameter value: "<<out_value<<L". The expected value is "<<testValue.get_value<<L"."<<send;
   }
   else
   {
    tracer
     <<L"OK. The OUT-parameter value is correct: "<<out_value<<L"."<<send;
   }//else
  }//local
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_OUT_001__short

////////////////////////////////////////////////////////////////////////////////
//TEST IN_OUT 002

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_OUT_002__long
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 using value_type=signed __int32;

 assert_s(sizeof(value_type)==4);

 //-----------------------------------------
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
   "insert into TEST_MODIFY_ROW (COL_INTEGER) values (?) RETURNING COL_INTEGER;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 struct tag_test_value
 {
  value_type set_value;
  short      set_indicator;

  value_type get_value;
  short      get_indicator;
 };//struct tag_test_value

 using limit_t=std::numeric_limits<value_type>;

 const tag_test_value test_values[]=
 {
  { (limit_t::min)()    ,    0, (limit_t::min)()     ,    0},
  { (limit_t::min)()+1  ,    0, (limit_t::min)()+1   ,    0},
  { -1                  ,    0, -1                   ,    0},
  {  0                  ,    0,  0                   ,    0},
  { (limit_t::max)()    ,   -1, -1                   ,   -1},
  {  1                  ,    0,  1                   ,    0},
  { (limit_t::max)()-1  ,    0, (limit_t::max)()-1   ,    0},
  { (limit_t::max)()    ,    0, (limit_t::max)()     ,    0},
 };//test_values

 for(size_t i=0;i!=_DIM_(test_values);++i)
 {
  const auto& testValue=test_values[i];

  tracer<<L"-------------------------- ["<<i<<L"]: "<<testValue.set_value<<" [ind: "<<testValue.set_indicator<<"]"<<send;

  //------------------------------------------------- INPUT
  const std::array<unsigned char,12> InMsg__BLR=
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
  };//InMsg__BLR

  //----------------------------------------
  const auto input_value=testValue.set_value;

  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
  {
   //---- value [int64]
   0,
   0,
   0,
   0,
   //---- indicator [short]
   0,
   0,
  };//InMsg__DATA

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

  InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
  InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
  InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  InMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
  InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

  //----------------------------------------
  memcpy(&InMsg__DATA[InMsg__DATA_DESCRS[0].m_msg_value_block_offset],&input_value,sizeof(input_value));
  memcpy(&InMsg__DATA[InMsg__DATA_DESCRS[0].m_msg_sqlind_offset],&testValue.set_indicator,sizeof(testValue.set_indicator));

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
  svc::remote_fb_in_msg_v1 InMsg;

  InMsg.blr        =InMsg__BLR;
  InMsg.data       =InMsg__DATA;
  InMsg.descrs     =InMsg__DATA_DESCRS;
  InMsg.data_align =4;

  svc::remote_fb_out_msg_v1 OutMsg;

  OutMsg.blr        =OutMsg__BLR;
  OutMsg.data       =OutMsg__DATA;
  OutMsg.descrs     =OutMsg__DATA_DESCRS;
  OutMsg.data_align =4;

  //----------------------------------------
  svc::RemoteFB_Connector__StmtExecute_M
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    &InMsg,
    &OutMsg);

  _TSO_CHECK(hTr==hTrCopy);
  _TSO_CHECK(hTr->m_ID.has_value());

  _TSO_CHECK(hStmt==hStmtCopy);
  _TSO_CHECK(hStmt->m_ID.has_value());

  //----------------------------------------
  short out_null_indicator=123;

  memcpy(&out_null_indicator,&OutMsg__DATA.data()[OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(out_null_indicator));

  if(out_null_indicator!=testValue.get_indicator)
  {
   tracer(tso_msg_error,-1)
    <<L"The wrong OUT-parameter null indiciator: "<<out_null_indicator<<L". The expected value is "<<testValue.get_indicator<<"."<<send;
  }
  else
  {
   tracer
    <<L"OK. The OUT-parameter null indiciator is correct: "<<out_null_indicator<<L"."<<send;
  }//else

  if(out_null_indicator==0)
  {
   auto out_value=input_value; out_value=0;

   memcpy(&out_value,&OutMsg__DATA.data()[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(out_value));

   if(out_value!=testValue.get_value)
   {
    tracer(tso_msg_error,-1)
     <<L"The wrong OUT-parameter value: "<<out_value<<L". The expected value is "<<testValue.get_value<<L"."<<send;
   }
   else
   {
    tracer
     <<L"OK. The OUT-parameter value is correct: "<<out_value<<L"."<<send;
   }//else
  }//if
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_OUT_002__long

////////////////////////////////////////////////////////////////////////////////
//TEST IN_OUT 003

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_OUT_003__int64
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 using value_type=signed __int64;

 assert_s(sizeof(value_type)==8);

 //-----------------------------------------
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
   "insert into TEST_MODIFY_ROW (COL_BIGINT) values (?) RETURNING COL_BIGINT;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 struct tag_test_value
 {
  value_type set_value;
  short      set_indicator;

  value_type get_value;
  short      get_indicator;
 };//struct tag_test_value

 using limit_t=std::numeric_limits<value_type>;

 const tag_test_value test_values[]=
 {
  { (limit_t::min)()    ,    0, (limit_t::min)()     ,    0},
  { (limit_t::min)()+1  ,    0, (limit_t::min)()+1   ,    0},
  { -1                  ,    0, -1                   ,    0},
  {  0                  ,    0,  0                   ,    0},
  { (limit_t::max)()    ,   -1, -1                   ,   -1},
  {  1                  ,    0,  1                   ,    0},
  { (limit_t::max)()-1  ,    0, (limit_t::max)()-1   ,    0},
  { (limit_t::max)()    ,    0, (limit_t::max)()     ,    0},
 };//test_values

 for(size_t i=0;i!=_DIM_(test_values);++i)
 {
  const auto& testValue=test_values[i];

  tracer<<L"-------------------------- ["<<i<<L"]: "<<testValue.set_value<<" [ind: "<<testValue.set_indicator<<"]"<<send;

  //------------------------------------------------- INPUT
  const std::array<unsigned char,12> InMsg__BLR=
  {
   /*  0 */ isc_api::ibp_isc_blr_version5,
   /*  1 */ isc_api::ibp_isc_blr_begin,
   /*  2 */ isc_api::ibp_isc_blr_message,
   /*  3 */ 0, // message number
   /*  4 */ 2, // cPars_lower
   /*  5 */ 0, // cPars_upper
   /*  6 */ isc_api::ibp_isc_blr_dtype__int64,  // data type
   /*  7 */ 0,                                  // data scale
   /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
   /*  9 */ 0,                                  // indicator scale
   /* 10 */ isc_api::ibp_isc_blr_end,
   /* 11 */ isc_api::ibp_isc_blr_eoc,
  };//InMsg__BLR

  //----------------------------------------
  const auto input_value=testValue.set_value;

  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
  {
   //---- value [int64]
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   //---- indicator [short]
   0,
   0,
  };//InMsg__DATA

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

  InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__int64;
  InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_int64;
  InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  InMsg__DATA_DESCRS[0].m_msg_value_block_size   =8;
  InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =8;

  //----------------------------------------
  memcpy(&InMsg__DATA[InMsg__DATA_DESCRS[0].m_msg_value_block_offset],&input_value,sizeof(input_value));
  memcpy(&InMsg__DATA[InMsg__DATA_DESCRS[0].m_msg_sqlind_offset],&testValue.set_indicator,sizeof(testValue.set_indicator));

  //------------------------------------------------- OUTPUT
  const std::array<unsigned char,12> OutMsg__BLR=
  {
   /*  0 */ isc_api::ibp_isc_blr_version5,
   /*  1 */ isc_api::ibp_isc_blr_begin,
   /*  2 */ isc_api::ibp_isc_blr_message,
   /*  3 */ 0, // message number
   /*  4 */ 2, // cPars_lower
   /*  5 */ 0, // cPars_upper
   /*  6 */ isc_api::ibp_isc_blr_dtype__int64,  // data type
   /*  7 */ 0,                                  // data scale
   /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
   /*  9 */ 0,                                  // indicator scale
   /* 10 */ isc_api::ibp_isc_blr_end,
   /* 11 */ isc_api::ibp_isc_blr_eoc,
  };//OutMsg__BLR

  //----------------------------------------
  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
  {
   //---- value [int64]
   0xFF,
   0xFF,
   0xFF,
   0xFF,
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

  OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__int64;
  OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_int64;
  OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =8;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =8;

  //----------------------------------------
  svc::remote_fb_in_msg_v1 InMsg;

  InMsg.blr        =InMsg__BLR;
  InMsg.data       =InMsg__DATA;
  InMsg.descrs     =InMsg__DATA_DESCRS;
  InMsg.data_align =8;

  svc::remote_fb_out_msg_v1 OutMsg;

  OutMsg.blr        =OutMsg__BLR;
  OutMsg.data       =OutMsg__DATA;
  OutMsg.descrs     =OutMsg__DATA_DESCRS;
  OutMsg.data_align =8;

  //----------------------------------------
  svc::RemoteFB_Connector__StmtExecute_M
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    &InMsg,
    &OutMsg);

  _TSO_CHECK(hTr==hTrCopy);
  _TSO_CHECK(hTr->m_ID.has_value());

  _TSO_CHECK(hStmt==hStmtCopy);
  _TSO_CHECK(hStmt->m_ID.has_value());

  //----------------------------------------
  short out_null_indicator=123;

  memcpy(&out_null_indicator,&OutMsg__DATA.data()[OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(out_null_indicator));

  if(out_null_indicator!=testValue.get_indicator)
  {
   tracer(tso_msg_error,-1)
    <<L"The wrong OUT-parameter null indiciator: "<<out_null_indicator<<L". The expected value is "<<testValue.get_indicator<<"."<<send;
  }
  else
  {
   tracer
    <<L"OK. The OUT-parameter null indiciator is correct: "<<out_null_indicator<<L"."<<send;
  }//else

  if(out_null_indicator==0)
  {
   auto out_value=input_value; out_value=0;

   memcpy(&out_value,&OutMsg__DATA.data()[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(out_value));

   if(out_value!=testValue.get_value)
   {
    tracer(tso_msg_error,-1)
     <<L"The wrong OUT-parameter value: "<<out_value<<L". The expected value is "<<testValue.get_value<<L"."<<send;
   }
   else
   {
    tracer
     <<L"OK. The OUT-parameter value is correct: "<<out_value<<L"."<<send;
   }//else
  }//if
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_OUT_003__int64

////////////////////////////////////////////////////////////////////////////////
//TEST IN_OUT 004

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_OUT_004__float
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 using value_type=float;

 assert_s(sizeof(value_type)==4);

 //-----------------------------------------
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
   "insert into TEST_MODIFY_ROW (COL_FLOAT) values (?) RETURNING COL_FLOAT;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 struct tag_test_value
 {
  value_type set_value;
  short      set_indicator;

  value_type get_value;
  short      get_indicator;
 };//struct tag_test_value

 using limit_t=std::numeric_limits<value_type>;

 const tag_test_value test_values[]=
 {
  { (limit_t::min)()    ,    0, (limit_t::min)()     ,    0},
  { (limit_t::min)()+1  ,    0, (limit_t::min)()+1   ,    0},
  { -1                  ,    0, -1                   ,    0},
  {  0                  ,    0,  0                   ,    0},
  { (limit_t::max)()    ,   -1, -1                   ,   -1},
  {  1                  ,    0,  1                   ,    0},
  { (limit_t::max)()-1  ,    0, (limit_t::max)()-1   ,    0},
  { (limit_t::max)()    ,    0, (limit_t::max)()     ,    0},
 };//test_values

 for(size_t i=0;i!=_DIM_(test_values);++i)
 {
  const auto& testValue=test_values[i];

  tracer<<L"-------------------------- ["<<i<<L"]: "<<testValue.set_value<<" [ind: "<<testValue.set_indicator<<"]"<<send;

  //------------------------------------------------- INPUT
  const std::array<unsigned char,11> InMsg__BLR=
  {
   /*  0 */ isc_api::ibp_isc_blr_version5,
   /*  1 */ isc_api::ibp_isc_blr_begin,
   /*  2 */ isc_api::ibp_isc_blr_message,
   /*  3 */ 0, // message number
   /*  4 */ 2, // cPars_lower
   /*  5 */ 0, // cPars_upper
   /*  6 */ isc_api::ibp_isc_blr_dtype__float,  // data type
   /*  7 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
   /*  8 */ 0,                                  // indicator scale
   /*  9 */ isc_api::ibp_isc_blr_end,
   /* 10 */ isc_api::ibp_isc_blr_eoc,
  };//InMsg__BLR

  //----------------------------------------
  const auto input_value=testValue.set_value;

  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
  {
   //---- value [float]
   0,
   0,
   0,
   0,
   //---- indicator [short]
   0,
   0,
  };//InMsg__DATA

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

  InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__float;
  InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_float;
  InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  InMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
  InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

  //----------------------------------------
  memcpy(&InMsg__DATA[InMsg__DATA_DESCRS[0].m_msg_value_block_offset],&input_value,sizeof(input_value));
  memcpy(&InMsg__DATA[InMsg__DATA_DESCRS[0].m_msg_sqlind_offset],&testValue.set_indicator,sizeof(testValue.set_indicator));

  //------------------------------------------------- OUTPUT
  const std::array<unsigned char,11> OutMsg__BLR=
  {
   /*  0 */ isc_api::ibp_isc_blr_version5,
   /*  1 */ isc_api::ibp_isc_blr_begin,
   /*  2 */ isc_api::ibp_isc_blr_message,
   /*  3 */ 0, // message number
   /*  4 */ 2, // cPars_lower
   /*  5 */ 0, // cPars_upper
   /*  6 */ isc_api::ibp_isc_blr_dtype__float,  // data type
   /*  7 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
   /*  8 */ 0,                                  // indicator scale
   /*  9 */ isc_api::ibp_isc_blr_end,
   /* 10 */ isc_api::ibp_isc_blr_eoc,
  };//OutMsg__BLR

  //----------------------------------------
  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
  {
   //---- value [float]
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

  OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__float;
  OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_float;
  OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

  //----------------------------------------
  {
   value_type c_neg_one=-1;

   memcpy(&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],&c_neg_one,sizeof(c_neg_one));
  }

  //----------------------------------------
  svc::remote_fb_in_msg_v1 InMsg;

  InMsg.blr        =InMsg__BLR;
  InMsg.data       =InMsg__DATA;
  InMsg.descrs     =InMsg__DATA_DESCRS;
  InMsg.data_align =4;

  svc::remote_fb_out_msg_v1 OutMsg;

  OutMsg.blr        =OutMsg__BLR;
  OutMsg.data       =OutMsg__DATA;
  OutMsg.descrs     =OutMsg__DATA_DESCRS;
  OutMsg.data_align =4;

  //----------------------------------------
  svc::RemoteFB_Connector__StmtExecute_M
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    &InMsg,
    &OutMsg);

  _TSO_CHECK(hTr==hTrCopy);
  _TSO_CHECK(hTr->m_ID.has_value());

  _TSO_CHECK(hStmt==hStmtCopy);
  _TSO_CHECK(hStmt->m_ID.has_value());

  //----------------------------------------
  short out_null_indicator=123;

  memcpy(&out_null_indicator,&OutMsg__DATA.data()[OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(out_null_indicator));

  if(out_null_indicator!=testValue.get_indicator)
  {
   tracer(tso_msg_error,-1)
    <<L"The wrong OUT-parameter null indiciator: "<<out_null_indicator<<L". The expected value is "<<testValue.get_indicator<<"."<<send;
  }
  else
  {
   tracer
    <<L"OK. The OUT-parameter null indiciator is correct: "<<out_null_indicator<<L"."<<send;
  }//else

  if(out_null_indicator==0)
  {
   auto out_value=input_value; out_value=0;

   memcpy(&out_value,&OutMsg__DATA.data()[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(out_value));

   if(out_value!=testValue.get_value)
   {
    tracer(tso_msg_error,-1)
     <<L"The wrong OUT-parameter value: "<<out_value<<L". The expected value is "<<testValue.get_value<<L"."<<send;
   }
   else
   {
    tracer
     <<L"OK. The OUT-parameter value is correct: "<<out_value<<L"."<<send;
   }//else
  }//local
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_OUT_004__float

////////////////////////////////////////////////////////////////////////////////
//TEST IN_OUT 005

void WORK_Test_034__StmtExecute_M__v3::tag_impl::test_IN_OUT_005__double
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 using value_type=double;

 assert_s(sizeof(value_type)==8);

 //-----------------------------------------
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
   "insert into TEST_MODIFY_ROW (COL_DOUBLE) values (?) RETURNING COL_DOUBLE;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 struct tag_test_value
 {
  value_type set_value;
  short      set_indicator;

  value_type get_value;
  short      get_indicator;
 };//struct tag_test_value

 using limit_t=std::numeric_limits<value_type>;

 const tag_test_value test_values[]=
 {
  { (limit_t::min)()    ,    0, (limit_t::min)()     ,    0},
  { (limit_t::min)()+1  ,    0, (limit_t::min)()+1   ,    0},
  { -1                  ,    0, -1                   ,    0},
  {  0                  ,    0,  0                   ,    0},
  { (limit_t::max)()    ,   -1, -1                   ,   -1},
  {  1                  ,    0,  1                   ,    0},
  { (limit_t::max)()-1  ,    0, (limit_t::max)()-1   ,    0},
  { (limit_t::max)()    ,    0, (limit_t::max)()     ,    0},
 };//test_values

 for(size_t i=0;i!=_DIM_(test_values);++i)
 {
  const auto& testValue=test_values[i];

  tracer<<L"-------------------------- ["<<i<<L"]: "<<testValue.set_value<<" [ind: "<<testValue.set_indicator<<"]"<<send;

  //------------------------------------------------- INPUT
  const std::array<unsigned char,11> InMsg__BLR=
  {
   /*  0 */ isc_api::ibp_isc_blr_version5,
   /*  1 */ isc_api::ibp_isc_blr_begin,
   /*  2 */ isc_api::ibp_isc_blr_message,
   /*  3 */ 0, // message number
   /*  4 */ 2, // cPars_lower
   /*  5 */ 0, // cPars_upper
   /*  6 */ isc_api::ibp_isc_blr_dtype__double, // data type
   /*  7 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
   /*  8 */ 0,                                  // indicator scale
   /*  9 */ isc_api::ibp_isc_blr_end,
   /* 10 */ isc_api::ibp_isc_blr_eoc,
  };//InMsg__BLR

  //----------------------------------------
  const auto input_value=testValue.set_value;

  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
  {
   //---- value [double]
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   //---- indicator [short]
   0,
   0,
  };//InMsg__DATA

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

  InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__double;
  InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_double;
  InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  InMsg__DATA_DESCRS[0].m_msg_value_block_size   =8;
  InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =8;

  //----------------------------------------
  memcpy(&InMsg__DATA[InMsg__DATA_DESCRS[0].m_msg_value_block_offset],&input_value,sizeof(input_value));
  memcpy(&InMsg__DATA[InMsg__DATA_DESCRS[0].m_msg_sqlind_offset],&testValue.set_indicator,sizeof(testValue.set_indicator));

  //------------------------------------------------- OUTPUT
  const std::array<unsigned char,11> OutMsg__BLR=
  {
   /*  0 */ isc_api::ibp_isc_blr_version5,
   /*  1 */ isc_api::ibp_isc_blr_begin,
   /*  2 */ isc_api::ibp_isc_blr_message,
   /*  3 */ 0, // message number
   /*  4 */ 2, // cPars_lower
   /*  5 */ 0, // cPars_upper
   /*  6 */ isc_api::ibp_isc_blr_dtype__double, // data type
   /*  7 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
   /*  8 */ 0,                                  // indicator scale
   /*  9 */ isc_api::ibp_isc_blr_end,
   /* 10 */ isc_api::ibp_isc_blr_eoc,
  };//OutMsg__BLR

  //----------------------------------------
  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
  {
   //---- value [float]
   0xFF,
   0xFF,
   0xFF,
   0xFF,
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

  OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__double;
  OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_double;
  OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =8;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =8;

  //----------------------------------------
  {
   value_type c_neg_one=-1;

   memcpy(&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],&c_neg_one,sizeof(c_neg_one));
  }

  //----------------------------------------
  svc::remote_fb_in_msg_v1 InMsg;

  InMsg.blr        =InMsg__BLR;
  InMsg.data       =InMsg__DATA;
  InMsg.descrs     =InMsg__DATA_DESCRS;
  InMsg.data_align =8;

  svc::remote_fb_out_msg_v1 OutMsg;

  OutMsg.blr        =OutMsg__BLR;
  OutMsg.data       =OutMsg__DATA;
  OutMsg.descrs     =OutMsg__DATA_DESCRS;
  OutMsg.data_align =8;

  //----------------------------------------
  svc::RemoteFB_Connector__StmtExecute_M
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    &InMsg,
    &OutMsg);

  _TSO_CHECK(hTr==hTrCopy);
  _TSO_CHECK(hTr->m_ID.has_value());

  _TSO_CHECK(hStmt==hStmtCopy);
  _TSO_CHECK(hStmt->m_ID.has_value());

  //----------------------------------------
  short out_null_indicator=123;

  memcpy(&out_null_indicator,&OutMsg__DATA.data()[OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(out_null_indicator));

  if(out_null_indicator!=testValue.get_indicator)
  {
   tracer(tso_msg_error,-1)
    <<L"The wrong OUT-parameter null indiciator: "<<out_null_indicator<<L". The expected value is "<<testValue.get_indicator<<"."<<send;
  }
  else
  {
   tracer
    <<L"OK. The OUT-parameter null indiciator is correct: "<<out_null_indicator<<L"."<<send;
  }//else

  if(out_null_indicator==0)
  {
   auto out_value=input_value; out_value=0;

   memcpy(&out_value,&OutMsg__DATA.data()[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(out_value));

   if(out_value!=testValue.get_value)
   {
    tracer(tso_msg_error,-1)
     <<L"The wrong OUT-parameter value: "<<out_value<<L". The expected value is "<<testValue.get_value<<L"."<<send;
   }
   else
   {
    tracer
     <<L"OK. The OUT-parameter value is correct: "<<out_value<<L"."<<send;
   }//else
  }//local
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(!hTr);
 _TSO_CHECK(!hTrCopy->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_IN_OUT_005__double

////////////////////////////////////////////////////////////////////////////////

const wchar_t*
 WORK_Test_034__StmtExecute_M__v3::tag_impl::helper__get_StmtExec_bugcheck_src__test_msg
                                           (remote_fb::RemoteFB__Connector* const pConnector)
{
 assert(pConnector);

 typedef TestServices svc;

 switch(const auto v=pConnector->GetPort()->get_protocol_version())
 {
  case remote_fb::protocol::FB_PROTOCOL_VERSION10:
  case remote_fb::protocol::FB_PROTOCOL_VERSION11:
  case remote_fb::protocol::FB_PROTOCOL_VERSION12:
  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_HLP__Msg_v1__Utilities::Helper__TestMsg";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_StmtExec_bugcheck_src__test_msg

//------------------------------------------------------------------------
const wchar_t*
 WORK_Test_034__StmtExecute_M__v3::tag_impl::helper__get_StmtExec_subsystem_id
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
}//helper__get_StmtExec_subsystem_id

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_034__StmtExecute_M__v3::tag_descr

struct WORK_Test_034__StmtExecute_M__v3::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_034__StmtExecute_M__v3::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_034__StmtExecute_M__v3::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_034__StmtExecute_M__v3::tag_descr
 WORK_Test_034__StmtExecute_M__v3::sm_Tests[]=
{
 //-----------------------------------------------------------------------
 DEF_TEST_DESCR
  ("006.err.not_prepared",
   test_006__err__not_prepared)

 //-----------------------------------------------------------------------
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("E201.bug_check.bad_inMsg.null_ptr_on_descrs",
   test_E201__bug_check__bad_inMsg__null_ptr_on_descrs)

 DEF_TEST_DESCR
  ("E202.bug_check.bad_inMsg.null_ptr_on_blr",
   test_E202__bug_check__bad_inMsg__null_ptr_on_blr)

 DEF_TEST_DESCR
  ("E203.bug_check.bad_inMsg.null_ptr_on_data",
   test_E203__bug_check__bad_inMsg__null_ptr_on_data)

 DEF_TEST_DESCR
  ("E204.bug_check.bad_inMsg.unexpected_blr",
   test_E204__bug_check__bad_inMsg__unexpected_blr)

 DEF_TEST_DESCR
  ("E205.bug_check.bad_inMsg.unexpected_blr",
   test_E205__bug_check__bad_inMsg__unexpected_blr)

 DEF_TEST_DESCR
  ("E206.bug_check.bad_inMsg.no_blr",
   test_E206__bug_check__bad_inMsg__no_blr)

 DEF_TEST_DESCR
  ("E207.bug_check.bad_inMsg.no_data",
   test_E207__bug_check__bad_inMsg__no_data)
#endif

 //-----------------------------------------------------------------------
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

#if 0
 DEF_TEST_DESCR
  ("S007.insert.with_param1.core_bug_4785",
   test_S007__insert__with_param1__core_bug__4785)
#endif

 DEF_TEST_DESCR
  ("S007.insert.with_param1",
   test_S007__insert__with_param1)

 DEF_TEST_DESCR
  ("S008.insert.with_param3",
   test_S008__insert__with_param3)

 DEF_TEST_DESCR
  ("IN.NN001.short",
   test_IN_NN001__short)

 DEF_TEST_DESCR
  ("IN.NN002.long",
   test_IN_NN002__long)

 DEF_TEST_DESCR
  ("IN.NN003.int64",
   test_IN_NN003__int64)

 DEF_TEST_DESCR
  ("IN.NN004.float",
   test_IN_NN004__float)

 DEF_TEST_DESCR
  ("NN005.double",
   test_IN_NN005__double)

 DEF_TEST_DESCR
  ("IN.NN006.type_time",
   test_IN_NN006__type_time)

 DEF_TEST_DESCR
  ("IN.NN007.type_date",
   test_IN_NN007__type_date)

 DEF_TEST_DESCR
  ("IN.NN008.timestamp",
   test_IN_NN008__timestamp)

 DEF_TEST_DESCR
  ("IN.NN009.char",
   test_IN_NN009__char)

 DEF_TEST_DESCR
  ("IN.NN009.char.len0",
   test_IN_NN009__char__len0)

 DEF_TEST_DESCR
  ("IN.NN010.varchar",
   test_IN_NN010__varchar)

 DEF_TEST_DESCR2
  ("IN.NN011.boolean",
   test_IN_NN011__boolean,
   "NE__BOOLEAN")

 DEF_TEST_DESCR2
  ("IN.NN012.int128",
   test_IN_NN012__int128,
   "NE__INT128")

 DEF_TEST_DESCR
  ("IN.N001.array.null",
   test_IN_N001__array_null)

 DEF_TEST_DESCR
  ("IN.N002.blob.null",
   test_IN_N002__blob_null)

 DEF_TEST_DESCR
  ("IN_OUT.001.short",
   test_IN_OUT_001__short)

 DEF_TEST_DESCR
  ("IN_OUT.002.long",
   test_IN_OUT_002__long)

 DEF_TEST_DESCR
  ("IN_OUT.003.int64",
   test_IN_OUT_003__int64)

 DEF_TEST_DESCR
  ("IN_OUT.004.float",
   test_IN_OUT_004__float)

 DEF_TEST_DESCR
  ("IN_OUT.005.double",
   test_IN_OUT_005__double)
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_034__StmtExecute_M__v3

void WORK_Test_034__StmtExecute_M__v3::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                                       //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);  //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter
  ftestID("RemoteFB.WORK.034.StmtExecute_M.v3.ptype__%1.%2");

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
