////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_035__ExecuteImmediate_M.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/db_client/remote_fb/remote_fb__msg_v1.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

#include <array>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_035__ExecuteImmediate_M::tag_impl

class WORK_Test_035__ExecuteImmediate_M::tag_impl
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
};//class WORK_Test_035__ExecuteImmediate_M::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_001__bug_check__bad_tr
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
   svc::RemoteFB_Connector__ExecuteImmediate_M
    (tracer,
     spConnector,
     OpCtx,
     &hCopyTr,
     static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
     "delete from DUAL"); //throw!
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

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_002__bug_check__bad_owner_cn_of_tr
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
   svc::RemoteFB_Connector__ExecuteImmediate_M
    (tracer,
     spConnector2,
     OpCtx,
     &hTr,
     static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
     "delete from DUAL"); //throw!
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
//TEST 015

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_015__execute_error
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
   svc::RemoteFB_Connector__ExecuteImmediate_M
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
     "insert into NUM (TEST_ID) values (NULL);");

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

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_016__execute2_error
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
 // XSQLDA_V1_Wrapper out_xsqlda(3);
 //
 // out_xsqlda->sqld=2;
 //
 // signed __int32 out_xparam0_value=321;
 // short          out_xparam0_ind=123;
 //
 // signed __int32 out_xparam1_value=233;
 // short          out_xparam1_ind=432;
 //
 // out_xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 // out_xsqlda->sqlvar[0].sqllen =sizeof(out_xparam0_value);
 // out_xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&out_xparam0_value);
 // out_xsqlda->sqlvar[0].sqlind =&out_xparam0_ind;
 //
 // out_xsqlda->sqlvar[1].sqltype=isc_api::ibp_isc_sql_long|1;
 // out_xsqlda->sqlvar[1].sqllen =sizeof(out_xparam0_value);
 // out_xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&out_xparam1_value);
 // out_xsqlda->sqlvar[1].sqlind =&out_xparam1_ind;

 //------------------------------------------------- OUTPUT
 const std::array<unsigned char,16> OutMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 4, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__long,   // data type         [0]
  /*  7 */ 0,                                  // data scale
  /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /*  9 */ 0,                                  // indicator scale
  /* 10 */ isc_api::ibp_isc_blr_dtype__long,   // data type         [1]
  /* 11 */ (unsigned char)(-1),                // data scale
  /* 12 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /* 13 */ 0,                                  // indicator scale
  /* 14 */ isc_api::ibp_isc_blr_end,
  /* 15 */ isc_api::ibp_isc_blr_eoc,
 };//OutMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
 {
           //---- value [long]
  /*  0 */ 0xFF,
  /*  1 */ 0xFF,
  /*  2 */ 0xFF,
  /*  3 */ 0xFF,
           //---- indicator [short]
  /*  4 */ 0xFE,
  /*  5 */ 0xFE,
           //--- bytes for an alignment
  /*  6 */ 0xFE,
  /*  7 */ 0xFE,
           //---- value [long]
  /*  8 */ 0xFF,
  /*  9 */ 0xFF,
  /* 10 */ 0xFF,
  /* 11 */ 0xFF,
           //---- indicator [short]
  /* 12 */ 0xFE,
  /* 13 */ 0xFE,
 };//OutMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,2> OutMsg__DATA_DESCRS;

 OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 OutMsg__DATA_DESCRS[1].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 OutMsg__DATA_DESCRS[1].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 OutMsg__DATA_DESCRS[1].m_xvar_sqlscale          =-1;
 OutMsg__DATA_DESCRS[1].m_msg_value_block_size   =4;
 OutMsg__DATA_DESCRS[1].m_msg_value_block_offset =8;
 OutMsg__DATA_DESCRS[1].m_msg_sqlind_offset      =12;

 //-----------------------------------------
 svc::remote_fb_out_msg_v1 OutMsg;

 OutMsg.blr        =OutMsg__BLR;
 OutMsg.data       =OutMsg__DATA;
 OutMsg.descrs     =OutMsg__DATA_DESCRS;
 OutMsg.data_align =4;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__ExecuteImmediate_M
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
     "insert into NUM (TEST_ID) values (NULL) returning N_1_0,N_2_1;",
     /*pInXSQLDA*/nullptr,
     /*pOutXSQLDA*/&OutMsg);

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

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_S001__insert__without_params
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
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "insert into NUM (TEST_ID) values (NULL);");

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

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_S002__set_transaction
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
 svc::RemoteFB_Connector__ExecuteImmediate_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "set transaction;");

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

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_S003__commit
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
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "commit;");

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

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_S004__commit_retain
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
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);

 const auto hTrIDCopy=hTr->m_ID.get_value();

 svc::RemoteFB_Connector__ExecuteImmediate_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "commit retain;");

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

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_S005__rollback
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
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "rollback;");

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

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_S006__rollback_retain
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
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);

 const auto hTrIDCopy=hTr->m_ID.get_value();

 svc::RemoteFB_Connector__ExecuteImmediate_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "rollback retain;");

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
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_S006__rollback_retain

////////////////////////////////////////////////////////////////////////////////
//TEST S007

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_S007__insert__with_in_param1
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
 // XSQLDA_V1_Wrapper xsqlda(1);
 //
 // xsqlda->sqld=1;
 //
 signed __int32 xparam0_value=5;
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
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "insert into NUM (N_1_0) values (?);",
   &InMsg,
   nullptr);

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

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_S008__insert__with_in_param3
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
 //XSQLDA_V1_Wrapper xsqlda(3);
 //
 //xsqlda->sqld=3;
 //
 signed __int32 xparam0_value=6;
 short          xparam0_ind=0;
 //
 signed __int32 xparam1_value=7;
 short          xparam1_ind=-1;
 //
 signed __int32 xparam2_value=8;
 short          xparam2_ind=0;
 //
 //xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 //xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 //xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 //xsqlda->sqlvar[0].sqlind =&xparam0_ind;
 //
 //xsqlda->sqlvar[1].sqltype=isc_api::ibp_isc_sql_long|1;
 //xsqlda->sqlvar[1].sqllen =sizeof(xparam0_value);
 //xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xparam1_value);
 //xsqlda->sqlvar[1].sqlind =&xparam1_ind;
 //
 //xsqlda->sqlvar[2].sqltype=isc_api::ibp_isc_sql_long|1;
 //xsqlda->sqlvar[2].sqllen =sizeof(xparam0_value);
 //xsqlda->sqlvar[2].sqldata=reinterpret_cast<char*>(&xparam2_value);
 //xsqlda->sqlvar[2].sqlind =&xparam2_ind;

 //-----------------------------------------
 const std::array<unsigned char,20> InMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 6, // cPars_lower
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
  //---- value [long] [0]
  0xFE,
  0xFE,
  0xFE,
  0xFE,
  //---- indicator [short]
  0xFE,
  0xFE,
  //---- alignment
  0xFE,
  0xFE,
  //---- value [long] [1]
  0xFE,
  0xFE,
  0xFE,
  0xFE,
  //---- indicator [short]
  0xFE,
  0xFE,
  //---- alignment
  0xFE,
  0xFE,
  //---- value [long] [2]
  0xFE,
  0xFE,
  0xFE,
  0xFE,
  //---- indicator [short]
  0xFE,
  0xFE,
 };//InMsg__DATA

 assert_s(sizeof(short)==2);

 assert(InMsg__DATA.size()==(24-2));

 memcpy(&InMsg__DATA[0] ,&xparam0_value,sizeof(xparam0_value));
 memcpy(&InMsg__DATA[8] ,&xparam1_value,sizeof(xparam1_value));
 memcpy(&InMsg__DATA[16],&xparam2_value,sizeof(xparam2_value));

 memcpy(&InMsg__DATA[4] ,&xparam0_ind,sizeof(xparam0_ind));
 memcpy(&InMsg__DATA[12],&xparam1_ind,sizeof(xparam1_ind));
 memcpy(&InMsg__DATA[20],&xparam2_ind,sizeof(xparam2_ind));

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
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into NUM (N_1_0,N_2_0,N_3_0) values (?,?,?);",
   &InMsg,
   nullptr);

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

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_S009__insert__with_out_param1
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
 // XSQLDA_V1_Wrapper xsqlda(1);
 //
 // xsqlda->sqld=1;
 //
 // signed __int32 xparam0_value=5;
 // short          xparam0_ind=-1;
 //
 // xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 // xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 // xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 // xsqlda->sqlvar[0].sqlind =&xparam0_ind;

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
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "insert into NUM (N_1_0) values (-5) returning N_1_0;",
   nullptr,
   &OutMsg);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 {
  //----------------------------------------
  short out_null_indicator=123;

  memcpy(&out_null_indicator,&OutMsg__DATA.data()[OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(out_null_indicator));

  if(out_null_indicator!=0)
  {
   tracer(tso_msg_error,-1)
    <<L"The wrong OUT-parameter null indiciator: "<<out_null_indicator<<L". The expected value is "<<0<<"."<<send;
  }
  else
  {
   tracer
    <<L"OK. The OUT-parameter null indiciator is correct: "<<out_null_indicator<<L"."<<send;
  }//else

  if(out_null_indicator==0)
  {
   signed __int32 out_value=0;

   memcpy(&out_value,&OutMsg__DATA.data()[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(out_value));

   if(out_value!=-5)
   {
    tracer(tso_msg_error,-1)
     <<L"The wrong OUT-parameter value: "<<out_value<<L". The expected value is "<<-5<<L"."<<send;
   }
   else
   {
    tracer
     <<L"OK. The OUT-parameter value is correct: "<<out_value<<L"."<<send;
   }//else
  }//if
 }//local

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

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_S010__insert__with_out_param3
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
 // XSQLDA_V1_Wrapper xsqlda(3);
 //
 // xsqlda->sqld=3;
 //
 // signed __int32 xparam0_value=6;
 // short          xparam0_ind=-1;
 //
 // signed __int32 xparam1_value=7;
 // short          xparam1_ind=0;
 //
 // signed __int32 xparam2_value=8;
 // short          xparam2_ind=-2;
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

 //------------------------------------------------- OUTPUT
 const std::array<unsigned char,20> OutMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 6, // cPars_lower
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
  //---- alignment
  0xFE,
  0xFE,
  //---- value [long]
  0xFF,
  0xFF,
  0xFF,
  0xFF,
  //---- indicator [short]
  0xFE,
  0xFE,
  //---- alignment
  0xFE,
  0xFE,
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
 std::array<svc::remote_fb_in_msg_v1::descr_type,3> OutMsg__DATA_DESCRS;

 assert(OutMsg__DATA.size()==24-2);

 OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 OutMsg__DATA_DESCRS[1].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 OutMsg__DATA_DESCRS[1].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 OutMsg__DATA_DESCRS[1].m_xvar_sqlscale          =0;
 OutMsg__DATA_DESCRS[1].m_msg_value_block_size   =4;
 OutMsg__DATA_DESCRS[1].m_msg_value_block_offset =8;
 OutMsg__DATA_DESCRS[1].m_msg_sqlind_offset      =12;

 OutMsg__DATA_DESCRS[2].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 OutMsg__DATA_DESCRS[2].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 OutMsg__DATA_DESCRS[2].m_xvar_sqlscale          =0;
 OutMsg__DATA_DESCRS[2].m_msg_value_block_size   =4;
 OutMsg__DATA_DESCRS[2].m_msg_value_block_offset =16;
 OutMsg__DATA_DESCRS[2].m_msg_sqlind_offset      =20;

 //-----------------------------------------
 svc::remote_fb_out_msg_v1 OutMsg;

 OutMsg.blr        =OutMsg__BLR;
 OutMsg.data       =OutMsg__DATA;
 OutMsg.descrs     =OutMsg__DATA_DESCRS;
 OutMsg.data_align =4;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into NUM (N_1_0,N_2_0,N_3_0) values (3,NULL,-543) returning N_1_0,N_2_0,N_3_0;",
   nullptr,
   &OutMsg);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 //_TSO_CHECK(xparam0_value==3);
 //_TSO_CHECK(xparam1_value==0);
 //_TSO_CHECK(xparam2_value==-543);
 //
 //_TSO_CHECK(xparam0_ind==0);
 //_TSO_CHECK(xparam1_ind==-1);
 //_TSO_CHECK(xparam2_ind==0);

 {
  //----------------------------------------
  const auto& descr=OutMsg__DATA_DESCRS[0];

  short out_null_indicator=123;

  memcpy(&out_null_indicator,&OutMsg__DATA.data()[descr.m_msg_sqlind_offset],sizeof(out_null_indicator));

  if(out_null_indicator!=0)
  {
   tracer(tso_msg_error,-1)
    <<L"The wrong OUT-parameter null indiciator: "<<out_null_indicator<<L". The expected value is "<<0<<"."<<send;
  }
  else
  {
   tracer
    <<L"OK. The OUT-parameter null indiciator is correct: "<<out_null_indicator<<L"."<<send;
  }//else

  if(out_null_indicator==0)
  {
   signed __int32 out_value=0;

   memcpy(&out_value,&OutMsg__DATA.data()[descr.m_msg_value_block_offset],sizeof(out_value));

   if(out_value!=3)
   {
    tracer(tso_msg_error,-1)
     <<L"The wrong OUT-parameter value: "<<out_value<<L". The expected value is "<<3<<L"."<<send;
   }
   else
   {
    tracer
     <<L"OK. The OUT-parameter value is correct: "<<out_value<<L"."<<send;
   }//else
  }//if
 }//local

 {
  //----------------------------------------
  const auto& descr=OutMsg__DATA_DESCRS[1];

  short out_null_indicator=123;

  memcpy(&out_null_indicator,&OutMsg__DATA.data()[descr.m_msg_sqlind_offset],sizeof(out_null_indicator));

  if(out_null_indicator!=-1)
  {
   tracer(tso_msg_error,-1)
    <<L"The wrong OUT-parameter null indiciator: "<<out_null_indicator<<L". The expected value is "<<-1<<"."<<send;
  }
  else
  {
   tracer
    <<L"OK. The OUT-parameter null indiciator is correct: "<<out_null_indicator<<L"."<<send;
  }//else
 }//local

 {
  //----------------------------------------
  const auto& descr=OutMsg__DATA_DESCRS[2];

  short out_null_indicator=123;

  memcpy(&out_null_indicator,&OutMsg__DATA.data()[descr.m_msg_sqlind_offset],sizeof(out_null_indicator));

  if(out_null_indicator!=0)
  {
   tracer(tso_msg_error,-1)
    <<L"The wrong OUT-parameter null indiciator: "<<out_null_indicator<<L". The expected value is "<<0<<"."<<send;
  }
  else
  {
   tracer
    <<L"OK. The OUT-parameter null indiciator is correct: "<<out_null_indicator<<L"."<<send;
  }//else

  if(out_null_indicator==0)
  {
   signed __int32 out_value=0;

   memcpy(&out_value,&OutMsg__DATA.data()[descr.m_msg_value_block_offset],sizeof(out_value));

   if(out_value!=-543)
   {
    tracer(tso_msg_error,-1)
     <<L"The wrong OUT-parameter value: "<<out_value<<L". The expected value is "<<-543<<L"."<<send;
   }
   else
   {
    tracer
     <<L"OK. The OUT-parameter value is correct: "<<out_value<<L"."<<send;
   }//else
  }//if
 }//local

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

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_S011__insert__with_in1_out2
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
 // XSQLDA_V1_Wrapper in_xsqlda(3);
 //
 // in_xsqlda->sqld=1;
 //
 signed __int32 in_xparam0_value=6;
 short          in_xparam0_ind=-1;
 //
 // in_xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 // in_xsqlda->sqlvar[0].sqllen =sizeof(in_xparam0_value);
 // in_xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&in_xparam0_value);
 // in_xsqlda->sqlvar[0].sqlind =&in_xparam0_ind;

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

 assert_s(sizeof(in_xparam0_value)==4);
 assert_s(sizeof(in_xparam0_ind)==2);

 memcpy(&InMsg__DATA[0],&in_xparam0_value,sizeof(in_xparam0_value));
 memcpy(&InMsg__DATA[4],&in_xparam0_ind  ,sizeof(in_xparam0_ind));

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
 // XSQLDA_V1_Wrapper out_xsqlda(3);
 //
 // out_xsqlda->sqld=2;
 //
 // signed __int32 out_xparam0_value=321;
 // short          out_xparam0_ind=123;
 //
 // signed __int32 out_xparam1_value=233;
 // short          out_xparam1_ind=432;
 //
 // out_xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 // out_xsqlda->sqlvar[0].sqllen =sizeof(out_xparam0_value);
 // out_xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&out_xparam0_value);
 // out_xsqlda->sqlvar[0].sqlind =&out_xparam0_ind;
 //
 // out_xsqlda->sqlvar[1].sqltype=isc_api::ibp_isc_sql_long|1;
 // out_xsqlda->sqlvar[1].sqllen =sizeof(out_xparam0_value);
 // out_xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&out_xparam1_value);
 // out_xsqlda->sqlvar[1].sqlind =&out_xparam1_ind;

 //------------------------------------------------- OUTPUT
 const std::array<unsigned char,16> OutMsg__BLR=
 {
  /*  0 */ isc_api::ibp_isc_blr_version5,
  /*  1 */ isc_api::ibp_isc_blr_begin,
  /*  2 */ isc_api::ibp_isc_blr_message,
  /*  3 */ 0, // message number
  /*  4 */ 4, // cPars_lower
  /*  5 */ 0, // cPars_upper
  /*  6 */ isc_api::ibp_isc_blr_dtype__long,   // data type
  /*  7 */ 0,                                  // data scale
  /*  8 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /*  9 */ 0,                                  // indicator scale
  /* 10 */ isc_api::ibp_isc_blr_dtype__long,   // data type
  /* 11 */ 0,                                  // data scale
  /* 12 */ isc_api::ibp_isc_blr_dtype__short,  // indicator type
  /* 13 */ 0,                                  // indicator scale
  /* 14 */ isc_api::ibp_isc_blr_end,
  /* 15 */ isc_api::ibp_isc_blr_eoc,
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
  //---- alignment
  0xFE,
  0xFE,
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
 std::array<svc::remote_fb_in_msg_v1::descr_type,2> OutMsg__DATA_DESCRS;

 assert(OutMsg__DATA.size()==16-2);

 OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 OutMsg__DATA_DESCRS[1].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 OutMsg__DATA_DESCRS[1].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 OutMsg__DATA_DESCRS[1].m_xvar_sqlscale          =0;
 OutMsg__DATA_DESCRS[1].m_msg_value_block_size   =4;
 OutMsg__DATA_DESCRS[1].m_msg_value_block_offset =8;
 OutMsg__DATA_DESCRS[1].m_msg_sqlind_offset      =12;

 //-----------------------------------------
 svc::remote_fb_out_msg_v1 OutMsg;

 OutMsg.blr        =OutMsg__BLR;
 OutMsg.data       =OutMsg__DATA;
 OutMsg.descrs     =OutMsg__DATA_DESCRS;
 OutMsg.data_align =4;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTrCopy(hTr);

 svc::RemoteFB_Connector__ExecuteImmediate_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into NUM (N_1_0,N_2_0) values (?,62) returning N_1_0,N_2_0;",
   &InMsg,
   &OutMsg);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 // _TSO_CHECK(out_xparam0_value==0);
 // _TSO_CHECK(out_xparam1_value==62);
 //
 // _TSO_CHECK(out_xparam0_ind==-1);
 // _TSO_CHECK(out_xparam1_ind==0);

 {
  //----------------------------------------
  const auto& descr=OutMsg__DATA_DESCRS[0];

  short out_null_indicator=123;

  memcpy(&out_null_indicator,&OutMsg__DATA.data()[descr.m_msg_sqlind_offset],sizeof(out_null_indicator));

  if(out_null_indicator!=-1)
  {
   tracer(tso_msg_error,-1)
    <<L"The wrong OUT-parameter null indiciator: "<<out_null_indicator<<L". The expected value is "<<-1<<"."<<send;
  }
  else
  {
   tracer
    <<L"OK. The OUT-parameter null indiciator is correct: "<<out_null_indicator<<L"."<<send;
  }//else
 }//local

 {
  //----------------------------------------
  const auto& descr=OutMsg__DATA_DESCRS[1];

  short out_null_indicator=123;

  memcpy(&out_null_indicator,&OutMsg__DATA.data()[descr.m_msg_sqlind_offset],sizeof(out_null_indicator));

  if(out_null_indicator!=0)
  {
   tracer(tso_msg_error,-1)
    <<L"The wrong OUT-parameter null indiciator: "<<out_null_indicator<<L". The expected value is "<<0<<"."<<send;
  }
  else
  {
   tracer
    <<L"OK. The OUT-parameter null indiciator is correct: "<<out_null_indicator<<L"."<<send;
  }//else

  if(out_null_indicator==0)
  {
   signed __int32 out_value=0;

   memcpy(&out_value,&OutMsg__DATA.data()[descr.m_msg_value_block_offset],sizeof(out_value));

   if(out_value!=62)
   {
    tracer(tso_msg_error,-1)
     <<L"The wrong OUT-parameter value: "<<out_value<<L". The expected value is "<<62<<L"."<<send;
   }
   else
   {
    tracer
     <<L"OK. The OUT-parameter value is correct: "<<out_value<<L"."<<send;
   }//else
  }//if
 }//local

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

void WORK_Test_035__ExecuteImmediate_M::tag_impl::test_S012__insert__blob
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
 // XSQLDA_V1_Wrapper in_xsqlda(3);
 //
 // in_xsqlda->sqld=1;
 //
 // in_xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_blob;
 // in_xsqlda->sqlvar[0].sqllen =sizeof(newBlobID);
 // in_xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&newBlobID);
 // in_xsqlda->sqlvar[0].sqlind =nullptr;

 //------------------------------------------------- INPUT
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

 //----------------------------------------
 const auto input_value=newBlobID;

 const short input_ind=0;

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

 InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__quad;
 InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_blob;
 InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 InMsg__DATA_DESCRS[0].m_msg_value_block_size   =8;
 InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =8;

 //----------------------------------------
 memcpy(&InMsg__DATA[InMsg__DATA_DESCRS[0].m_msg_value_block_offset],&input_value,sizeof(input_value));
 memcpy(&InMsg__DATA[InMsg__DATA_DESCRS[0].m_msg_sqlind_offset],&input_ind,sizeof(input_ind));

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =InMsg__BLR;
 InMsg.data       =InMsg__DATA;
 InMsg.descrs     =InMsg__DATA_DESCRS;
 InMsg.data_align =4;

 //-----------------------------------------
 // XSQLDA_V1_Wrapper out_xsqlda(3);
 //
 // out_xsqlda->sqld=1;
 //
 // db_obj::DB_IBBLOBID out_xparam0_value={};
 //
 // out_xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_blob;
 // out_xsqlda->sqlvar[0].sqllen =sizeof(out_xparam0_value);
 // out_xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&out_xparam0_value);
 // out_xsqlda->sqlvar[0].sqlind =nullptr;

 //------------------------------------------------- OUTPUT
 const std::array<unsigned char,12> OutMsg__BLR=
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
 };//OutMsg__BLR

 //-----------------------------------------
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

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> OutMsg__DATA_DESCRS;

 OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__quad;
 OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_blob;
 OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =8;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =8;

 //-----------------------------------------
 svc::remote_fb_out_msg_v1 OutMsg;

 OutMsg.blr        =OutMsg__BLR;
 OutMsg.data       =OutMsg__DATA;
 OutMsg.descrs     =OutMsg__DATA_DESCRS;
 OutMsg.data_align =4;

 //-----------------------------------------
 svc::RemoteFB_Connector__ExecuteImmediate_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   (unsigned short)cns.db_dialect_Ex.value(),
   "insert into BIN_BLOB_TABLE (BIN_DATA) values (?) returning BIN_DATA;",
   &InMsg,
   &OutMsg);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hTr->m_ID.has_value());

 //-----------------------------------------
 db_obj::DB_IBBLOBID out_xparam0_value={structure::negative_one,structure::negative_one};

 {
  const auto& descr=OutMsg__DATA_DESCRS[0];

  short out_null_indicator=123;

  memcpy(&out_null_indicator,&OutMsg__DATA.data()[descr.m_msg_sqlind_offset],sizeof(out_null_indicator));

  if(out_null_indicator!=0)
  {
   tracer(tso_msg_error,-1)
    <<L"The wrong OUT-parameter null indiciator: "<<out_null_indicator<<L". The expected value is "<<0<<"."<<send;

   return;
  }//if

  tracer
   <<L"OK. The OUT-parameter null indiciator is correct: "<<out_null_indicator<<L"."<<send;

  memcpy(&out_xparam0_value,&OutMsg__DATA.data()[descr.m_msg_value_block_offset],sizeof(out_xparam0_value));
 }//local

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

const wchar_t* WORK_Test_035__ExecuteImmediate_M::tag_impl::helper__get_exec_immed_bugcheck_src
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
   return L"RemoteFB__API_P12__ExecuteImmediate_M::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__ExecuteImmediate_M::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_exec_immed_bugcheck_src

//------------------------------------------------------------------------
const wchar_t* WORK_Test_035__ExecuteImmediate_M::tag_impl::helper__get_exec_immed_subsystem
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
//struct WORK_Test_035__ExecuteImmediate_M::tag_descr

struct WORK_Test_035__ExecuteImmediate_M::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_035__ExecuteImmediate_M::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_035__ExecuteImmediate_M::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_035__ExecuteImmediate_M::tag_descr
 WORK_Test_035__ExecuteImmediate_M::sm_Tests[]=
{
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("001.bug_check.bad_tr",
   test_001__bug_check__bad_tr)

 DEF_TEST_DESCR
  ("002.bug_check.bad_owner_cn_of_tr",
   test_002__bug_check__bad_owner_cn_of_tr)
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
//class WORK_Test_035__ExecuteImmediate_M

void WORK_Test_035__ExecuteImmediate_M::create(TTSO_PushTest*      const pTestPusher,
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
  ftestID("RemoteFB.WORK.035.ExecuteImmediate_M.ptype__%1.%2");

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
