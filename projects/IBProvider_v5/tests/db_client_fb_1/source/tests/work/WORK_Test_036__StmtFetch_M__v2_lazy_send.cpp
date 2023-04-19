////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_036__StmtFetch_M__v2_lazy_send.h"
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
//class WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl

class WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_201__reexecution__without_close_in_new_trs
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_202__reexecution__with_close_in_new_trs
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_203__reexecution__with_params
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_210__reexecution__with_hack_closed_prev_cursor
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_211__reexecution__with_hack_closed_prev_cursor_v2
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public:
  static void test_220__err2__fbbug4983
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_220__err2__fbbug4983__fb3
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public:
  static void test_221__err2
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_221__err2__fb3
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 public:
  static void test_222__err3
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_222__err3__fb3
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
};//class WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 201

void WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl::test_201__reexecution__without_close_in_new_trs
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
 _TSO_CHECK(hStmt->m_ID.is_defer());

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

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 for(size_t pass=0;pass!=5;)
 {
  ++pass;

  tracer<<L"-------------------------------- pass: "<<pass<<send;

  svc::RemoteFB_Connector__StartTransaction
   (tracer,
    spConnector,
    &hTr);

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
  _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
  _TSO_CHECK(!hStmt->m_spFetchResult);
  _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

  //----------------------------------------
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
  //_TSO_CHECK(columnValue==1);
  //_TSO_CHECK(columnInd==0);

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
  svc::RemoteFB_Connector__Commit
   (tracer,
    spConnector,
    &hTr);

  _TSO_CHECK(!hTr);

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_pParentTr==nullptr);
  _TSO_CHECK(!hStmt->m_spFetchResult);

  _TSO_CHECK(hStmt->m_pClosingTr==nullptr);
 }//for pass

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_201__reexecution__without_close_in_new_trs

////////////////////////////////////////////////////////////////////////////////
//TEST 202

void WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl::test_202__reexecution__with_close_in_new_trs
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
 _TSO_CHECK(hStmt->m_ID.is_defer());

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

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 for(size_t pass=0;pass!=5;)
 {
  ++pass;

  tracer<<L"-------------------------------- pass: "<<pass<<send;

  svc::RemoteFB_Connector__StartTransaction
   (tracer,
    spConnector,
    &hTr);

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
  _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
  _TSO_CHECK(!hStmt->m_spFetchResult);
  _TSO_CHECK(hStmt->m_pClosingTr==nullptr);

  //----------------------------------------
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
  //_TSO_CHECK(columnValue==1);
  //_TSO_CHECK(columnInd==0);

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

  _TSO_CHECK(hStmt->m_pClosingTr==hTr);

  //-----------------------------------------
  svc::RemoteFB_Connector__Commit
   (tracer,
    spConnector,
    &hTr);

  _TSO_CHECK(!hTr);

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_pParentTr==nullptr);
  _TSO_CHECK(!hStmt->m_spFetchResult);

  _TSO_CHECK(hStmt->m_pClosingTr==nullptr);
 }//for pass

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_202__reexecution__with_close_in_new_trs

////////////////////////////////////////////////////////////////////////////////
//TEST 203

void WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl::test_203__reexecution__with_params
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
 _TSO_CHECK(hStmt->m_ID.is_defer());

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
    "execute block (A integer=?)\n"
    "returns(X INTEGER)\n"
    "AS\n"
    "BEGIN\n"
    " x=a; SUSPEND;\n"
    " SUSPEND;\n"
    "END;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 for(db_obj::t_dbvalue__i4 pass=0;pass!=5;)
 {
  ++pass;

  tracer<<L"-------------------------------- pass: "<<pass<<send;

  //XSQLDA_V1_Wrapper xsqlda(/*n*/1);
  //
  //db_obj::t_dbvalue__i4   columnValue=pass;
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

  //------------------------------------------------- CMD_MSG
  const std::array<unsigned char,12> CmdMsg__BLR=
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
  };//CmdMsg__BLR

  //-----------------------------------------
  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> CmdMsg__DATA=
  {
   //---- value [long]
   0xFF,
   0xFF,
   0xFF,
   0xFF,
   //---- indicator [short]
   0,
   0,
  };//CmdMsg__DATA

  assert_s(sizeof(pass)==4);

  memcpy(&CmdMsg__DATA[0],&pass,sizeof(pass));

  //-----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> CmdMsg__DATA_DESCRS;

  CmdMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
  CmdMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
  CmdMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  CmdMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
  CmdMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  CmdMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

  //-----------------------------------------
  svc::remote_fb_in_msg_v1 InMsg;

  InMsg.blr        =CmdMsg__BLR;
  InMsg.data       =CmdMsg__DATA;
  InMsg.descrs     =CmdMsg__DATA_DESCRS;
  InMsg.data_align =4;

  //----------------------------------------
  svc::RemoteFB_Connector__StmtExecute_M
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    &InMsg,
    /*out*/nullptr);

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_pParentTr==hTr);
  _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
  _TSO_CHECK(!hStmt->m_spFetchResult);

  if(pass>1)
  {
   //продолжает висеть отложенное закрытие курсора
   _TSO_CHECK(hStmt->m_pClosingTr==hTr);
  }

  //----------------------------------------
  std::fill(CmdMsg__DATA.begin(),CmdMsg__DATA.end(),0xAA);

  //-----------------------------------------
  svc::remote_fb_out_msg_v1 OutMsg;

  OutMsg.blr        =CmdMsg__BLR;
  OutMsg.data       =CmdMsg__DATA;
  OutMsg.descrs     =CmdMsg__DATA_DESCRS;
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
  //_TSO_CHECK(columnValue==pass);
  //_TSO_CHECK(columnInd==0);

  //----------------------------------------
  {
   db_obj::t_dbvalue__i4 columnValue;

   assert_s(sizeof(columnValue)==4);

   memcpy(&columnValue,&CmdMsg__DATA[CmdMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(columnValue));

   _TSO_CHECK_MSG(columnValue==pass,"columnValue="<<columnValue);
  }//local

  //-----------------------------------------
  {
   db_obj::t_dbvalue__i2 columnInd;

   assert_s(sizeof(columnInd)==2);

   memcpy(&columnInd,&CmdMsg__DATA[CmdMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(columnInd));

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

  _TSO_CHECK(hStmt->m_pClosingTr==hTr);
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
}//test_203__reexecution__with_params

////////////////////////////////////////////////////////////////////////////////
//TEST 210

void WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl::test_210__reexecution__with_hack_closed_prev_cursor
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
 _TSO_CHECK(hStmt->m_ID.is_defer());

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
    "execute block (A integer=?)\n"
    "returns(X INTEGER)\n"
    "AS\n"
    "BEGIN\n"
    " x=a; SUSPEND;\n"
    " SUSPEND;\n"
    "END;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 for(db_obj::t_dbvalue__i4 pass=0;pass!=5;)
 {
  ++pass;

  tracer<<L"-------------------------------- pass: "<<pass<<send;

  //-----------------------------------------
  svc::RemoteFB_Connector__StartTransaction
   (tracer,
    spConnector,
    &hTr);

  //-----------------------------------------
  //XSQLDA_V1_Wrapper xsqlda(/*n*/1);
  //
  //db_obj::t_dbvalue__i4   columnValue=pass;
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

  //------------------------------------------------- CMD_MSG
  const std::array<unsigned char,12> CmdMsg__BLR=
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
  };//CmdMsg__BLR

  //-----------------------------------------
  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> CmdMsg__DATA=
  {
   //---- value [long]
   0xFF,
   0xFF,
   0xFF,
   0xFF,
   //---- indicator [short]
   0,
   0,
  };//CmdMsg__DATA

  assert_s(sizeof(pass)==4);

  memcpy(&CmdMsg__DATA[0],&pass,sizeof(pass));

  //-----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> CmdMsg__DATA_DESCRS;

  CmdMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
  CmdMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
  CmdMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  CmdMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
  CmdMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  CmdMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

  //-----------------------------------------
  svc::remote_fb_in_msg_v1 InMsg;

  InMsg.blr        =CmdMsg__BLR;
  InMsg.data       =CmdMsg__DATA;
  InMsg.descrs     =CmdMsg__DATA_DESCRS;
  InMsg.data_align =4;

  //----------------------------------------
  svc::RemoteFB_Connector__StmtExecute_M
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    /*in*/&InMsg,
    /*out*/nullptr);

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_pParentTr==hTr);
  _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
  _TSO_CHECK(!hStmt->m_spFetchResult);

  //продолжает висеть отложенное закрытие курсора
  if(pass>1)
  {
   _TSO_CHECK(hStmt->m_pClosingTr);
  }//if

  //----------------------------------------
  std::fill(CmdMsg__DATA.begin(),CmdMsg__DATA.end(),0xAA);

  //-----------------------------------------
  svc::remote_fb_out_msg_v1 OutMsg;

  OutMsg.blr        =CmdMsg__BLR;
  OutMsg.data       =CmdMsg__DATA;
  OutMsg.descrs     =CmdMsg__DATA_DESCRS;
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
  //_TSO_CHECK(columnValue==pass);
  //_TSO_CHECK(columnInd==0);

  //----------------------------------------
  {
   db_obj::t_dbvalue__i4 columnValue;

   assert_s(sizeof(columnValue)==4);

   memcpy(&columnValue,&CmdMsg__DATA[CmdMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(columnValue));

   _TSO_CHECK_MSG(columnValue==pass,"columnValue="<<columnValue);
  }//local

  //-----------------------------------------
  {
   db_obj::t_dbvalue__i2 columnInd;

   assert_s(sizeof(columnInd)==2);

   memcpy(&columnInd,&CmdMsg__DATA[CmdMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(columnInd));

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

  _TSO_CHECK(hStmt->m_pClosingTr==hTr);

  //-----------------------------------------
  //неявно закрываем наш отложенный курсор

  svc::HACK__CommitTr
   (tracer,
    spConnector,
    &hTr);

  _TSO_CHECK(hStmt->m_pClosingTr==hTr);

  //save and forgot about this transaction
  hTr=nullptr;

  _TSO_CHECK(hStmt->m_pClosingTr);
 }//for pass

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_210__reexecution__with_hack_closed_prev_cursor

////////////////////////////////////////////////////////////////////////////////
//TEST 211

void WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl::test_211__reexecution__with_hack_closed_prev_cursor_v2
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
 _TSO_CHECK(hStmt->m_ID.is_defer());

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
    "execute block (A integer=?)\n"
    "returns(X INTEGER)\n"
    "AS\n"
    "BEGIN\n"
    " x=a; SUSPEND;\n"
    " SUSPEND;\n"
    "END;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 for(db_obj::t_dbvalue__i4 pass=0;pass!=5;)
 {
  ++pass;

  tracer<<L"-------------------------------- pass: "<<pass<<send;

  //-----------------------------------------
  //XSQLDA_V1_Wrapper xsqlda(/*n*/1);
  //
  //db_obj::t_dbvalue__i4   columnValue=pass;
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

  //------------------------------------------------- CMD_MSG
  const std::array<unsigned char,12> CmdMsg__BLR=
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
  };//CmdMsg__BLR

  //----------------------------------------
  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> CmdMsg__DATA=
  {
   //---- value [long]
   0xFF,
   0xFF,
   0xFF,
   0xFF,
   //---- indicator [short]
   0,
   0,
  };//CmdMsg__DATA

  assert_s(sizeof(pass)==4);

  memcpy(&CmdMsg__DATA[0],&pass,sizeof(pass));

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> CmdMsg__DATA_DESCRS;

  CmdMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
  CmdMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
  CmdMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  CmdMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
  CmdMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  CmdMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

  //----------------------------------------
  svc::remote_fb_in_msg_v1 InMsg;

  InMsg.blr        =CmdMsg__BLR;
  InMsg.data       =CmdMsg__DATA;
  InMsg.descrs     =CmdMsg__DATA_DESCRS;
  InMsg.data_align =4;

  //----------------------------------------
  svc::RemoteFB_Connector__StmtExecute_M
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    /*in*/&InMsg,
    /*out*/nullptr);

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_ID.has_value());
  _TSO_CHECK(hStmt->m_pParentTr==hTr);
  _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
  _TSO_CHECK(!hStmt->m_spFetchResult);

  //продолжает висеть отложенное закрытие курсора
  if(pass>1)
  {
   _TSO_CHECK(hStmt->m_pClosingTr);
  }//if

  //----------------------------------------
  std::fill(CmdMsg__DATA.begin(),CmdMsg__DATA.end(),0xAA);

  //-----------------------------------------
  svc::remote_fb_out_msg_v1 OutMsg;

  OutMsg.blr        =CmdMsg__BLR;
  OutMsg.data       =CmdMsg__DATA;
  OutMsg.descrs     =CmdMsg__DATA_DESCRS;
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

   memcpy(&columnValue,&CmdMsg__DATA[CmdMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(columnValue));

   _TSO_CHECK_MSG(columnValue==pass,"columnValue="<<columnValue);
  }//local

  //----------------------------------------
  {
   db_obj::t_dbvalue__i2 columnInd;

   assert_s(sizeof(columnInd)==2);

   memcpy(&columnInd,&CmdMsg__DATA[CmdMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(columnInd));

   _TSO_CHECK_MSG(columnInd==0,"columnInd="<<columnInd);
  }//local

  //----------------------------------------
  svc::RemoteFB_Connector__StmtClose
   (tracer,
    spConnector,
    &hStmt);

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_pParentTr==nullptr);
  _TSO_CHECK(!hStmt->m_spFetchResult);

  _TSO_CHECK(hStmt->m_pClosingTr==hTr);

  //-----------------------------------------
  //неявно закрываем наш отложенный курсор

  svc::HACK__CloseStmt
   (tracer,
    spConnector,
    &hStmt);

  _TSO_CHECK(hStmt->m_pClosingTr==hTr);
 }//for pass

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_211__reexecution__with_hack_closed_prev_cursor_v2

////////////////////////////////////////////////////////////////////////////////
//TEST 220

void WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl::test_220__err2__fbbug4983
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
 _TSO_CHECK(hStmt->m_ID.is_defer());

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
    "END;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 //XSQLDA_V1_Wrapper xsqlda(/*n*/1);
 //
 //db_obj::t_dbvalue__i4   columnValue=-123;
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
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(!hStmt->m_pClosingTr);

 //-----------------------------------------
 svc::HACK__UnprepareStmt
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(!hStmt->m_pClosingTr);

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtFetch_M_ToRow
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

   // 1. error from server
   // 2. error from execute
   // 3. error from server
   errSvc::check_err_count(exc,3);

   errSvc::check_err_rec__srv_err__attempt_to_execute_unprepared_sql_stmt
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   errSvc::check_err_rec__stmt_srv_err__execute_fail
    (tracer,
     exc.get_record(1));

   errSvc::check_err_rec__srv_err__cursor_is_not_open
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(2));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 //состояние запроса не должно меняться. Появится только m_spFetchResult.
 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_pParentTr)
 _TSO_CHECK(hStmt->m_spFetchResult);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_pClosingTr)

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr)
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(!hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_pClosingTr)

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_220__err2__fbbug4983

////////////////////////////////////////////////////////////////////////////////
//TEST 220

void WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl::test_220__err2__fbbug4983__fb3
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
 _TSO_CHECK(hStmt->m_ID.is_defer());

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
    "END;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 //XSQLDA_V1_Wrapper xsqlda(/*n*/1);
 //
 //db_obj::t_dbvalue__i4   columnValue=-123;
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
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(!hStmt->m_pClosingTr);

 //-----------------------------------------
 svc::HACK__UnprepareStmt
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(!hStmt->m_pClosingTr);

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtFetch_M_ToRow
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

   // 1. error from server
   // 2. error from execute
   // 3. error from server
   errSvc::check_err_count(exc,3);

   errSvc::check_err_rec__srv_err__attempt_to_execute_unprepared_sql_stmt__fb3
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   errSvc::check_err_rec__stmt_srv_err__execute_fail
    (tracer,
     exc.get_record(1));

   errSvc::check_err_rec__srv_err__cursor_is_not_open__fb3
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(2));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 //состояние запроса не должно меняться. Появится только m_spFetchResult.
 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_pParentTr)
 _TSO_CHECK(hStmt->m_spFetchResult);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_pClosingTr)

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr)
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(!hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_pClosingTr)

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_220__err2__fbbug4983__fb3

////////////////////////////////////////////////////////////////////////////////
//TEST 221

void WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl::test_221__err2
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
 _TSO_CHECK(hStmt->m_ID.is_defer());

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
    "select ID from DUAL where ID=?");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(/*n*/1);
 //
 // db_obj::t_dbvalue__i4   columnValue=-123;
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
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(!hStmt->m_pClosingTr);

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtFetch_M_ToRow
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

   // 1. error from execute
   // 2. ibprovider hint
   // 3. error from fetch
   errSvc::check_err_count(exc,3);

   //Dynamic SQL Error
   errSvc::check_err_rec__partially
    (tracer,
     exc.get_record(0),
     spConnector->GetData()->m_DBMS_Name,
     L"-804");

   errSvc::check_err_rec__stmt_srv_err__execute_fail
    (tracer,
     exc.get_record(1));

   //Cursor is not open
   errSvc::check_err_rec__partially
    (tracer,
     exc.get_record(2),
     spConnector->GetData()->m_DBMS_Name,
     L"-504");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 //состояние запроса не должно меняться. Появится только m_spFetchResult.
 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_pParentTr)
 _TSO_CHECK(hStmt->m_spFetchResult);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_pClosingTr)

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr)
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(!hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_pClosingTr)

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_221__err2

////////////////////////////////////////////////////////////////////////////////
//TEST 221

void WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl::test_221__err2__fb3
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
 _TSO_CHECK(hStmt->m_ID.is_defer());

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
    "select ID from DUAL where ID=?");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(/*n*/1);
 //
 // db_obj::t_dbvalue__i4   columnValue=-123;
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
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(!hStmt->m_pClosingTr);

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtFetch_M_ToRow
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

   // 1. error from execute
   // 2. ibprovider hint
   // 3. error from fetch
   errSvc::check_err_count(exc,3);

   //Dynamic SQL Error
   errSvc::check_err_rec__partially
    (tracer,
     exc.get_record(0),
     spConnector->GetData()->m_DBMS_Name,
     L"No SQLDA for input values provided");

   errSvc::check_err_rec__stmt_srv_err__execute_fail
    (tracer,
     exc.get_record(1));

   //Cursor is not open
   errSvc::check_err_rec__srv_err__cursor_is_not_open__fb3
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(2));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 //состояние запроса не должно меняться. Появится только m_spFetchResult.
 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_pParentTr)
 _TSO_CHECK(hStmt->m_spFetchResult);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_pClosingTr)

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr)
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(!hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_pClosingTr)

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_221__err2__fb3

////////////////////////////////////////////////////////////////////////////////
//TEST 222

void WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl::test_222__err3
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
 _TSO_CHECK(hStmt->m_ID.is_defer());

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
    "select ID from DUAL where ID=?");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 // XSQLDA_V1_Wrapper xsqlda(/*n*/1);
 //
 db_obj::t_dbvalue__i4   columnValue=-123;
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

 //------------------------------------------------- CMD_MSG
 const std::array<unsigned char,12> CmdMsg__BLR=
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
 };//CmdMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> CmdMsg__DATA=
 {
  //---- value [long]
  0xFF,
  0xFF,
  0xFF,
  0xFF,
  //---- indicator [short]
  0,
  0,
 };//CmdMsg__DATA

 assert_s(sizeof(columnValue)==4);

 memcpy(&CmdMsg__DATA[0],&columnValue,sizeof(columnValue));

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> CmdMsg__DATA_DESCRS;

 CmdMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 CmdMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 CmdMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 CmdMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 CmdMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 CmdMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =CmdMsg__BLR;
 InMsg.data       =CmdMsg__DATA;
 InMsg.descrs     =CmdMsg__DATA_DESCRS;
 InMsg.data_align =4;

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*out*/nullptr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(!hStmt->m_pClosingTr);

 //-----------------------------------------
 std::fill(CmdMsg__DATA.begin(),CmdMsg__DATA.end(),0xAA);

 //-----------------------------------------
 svc::remote_fb_out_msg_v1 OutMsg;

 OutMsg.blr        =CmdMsg__BLR;
 OutMsg.data       =CmdMsg__DATA;
 OutMsg.descrs     =CmdMsg__DATA_DESCRS;
 OutMsg.data_align =4;

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtFetch_M_ToEOF
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   &OutMsg);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(!hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult); //was released after EOF
 _TSO_CHECK(!hStmt->m_pClosingTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtClose
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(!hStmt->m_pParentTr);
 _TSO_CHECK(!hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr); //deferred close

 //-----------------------------------------
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
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr);

 //-----------------------------------------
 svc::HACK__CloseStmt
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr);

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtFetch_M_ToRow
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

   // 1. error from close
   // 2. ibprovider hint
   // 3. error from execute
   // 4. ibprovider hint
   // 5. error from fetch
   errSvc::check_err_count(exc,5);

   errSvc::check_err_rec__srv_err__failed_to_close_stmt__reclose
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   errSvc::check_err_rec__stmt_err__failed_to_close_stmt
    (tracer,
     exc.get_record(1));

   //SQLDA missing or incorrect version, or incorrect number/type of variables
   errSvc::check_err_rec__partially
    (tracer,
     exc.get_record(2),
     spConnector->GetData()->m_DBMS_Name,
     L"-804");

   errSvc::check_err_rec__stmt_srv_err__execute_fail
    (tracer,
     exc.get_record(3));

   //Cursor is not open
   errSvc::check_err_rec__partially
    (tracer,
     exc.get_record(4),
     spConnector->GetData()->m_DBMS_Name,
     L"-504");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 //состояние запроса не должно меняться. Появится только m_spFetchResult.
 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_pParentTr==hTr)
 _TSO_CHECK(hStmt->m_spFetchResult);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(hStmt->m_pClosingTr==hTr)

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr)
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(!hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_pClosingTr)

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_222__err3

////////////////////////////////////////////////////////////////////////////////
//TEST 222

void WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl::test_222__err3__fb3
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
 _TSO_CHECK(hStmt->m_ID.is_defer());

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
    "select ID from DUAL where ID=?");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 //XSQLDA_V1_Wrapper xsqlda(/*n*/1);
 //
 db_obj::t_dbvalue__i4   columnValue=-123;
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

 //------------------------------------------------- CMD_MSG
 const std::array<unsigned char,12> CmdMsg__BLR=
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
 };//CmdMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> CmdMsg__DATA=
 {
  //---- value [long]
  0xFF,
  0xFF,
  0xFF,
  0xFF,
  //---- indicator [short]
  0,
  0,
 };//CmdMsg__DATA

 assert_s(sizeof(columnValue)==4);

 memcpy(&CmdMsg__DATA[0],&columnValue,sizeof(columnValue));

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> CmdMsg__DATA_DESCRS;

 CmdMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_isc_blr_dtype__long;
 CmdMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 CmdMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 CmdMsg__DATA_DESCRS[0].m_msg_value_block_size   =4;
 CmdMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 CmdMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 svc::remote_fb_in_msg_v1 InMsg;

 InMsg.blr        =CmdMsg__BLR;
 InMsg.data       =CmdMsg__DATA;
 InMsg.descrs     =CmdMsg__DATA_DESCRS;
 InMsg.data_align =4;

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute_M
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   &InMsg,
   /*out*/nullptr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(!hStmt->m_pClosingTr);

 //-----------------------------------------
 std::fill(CmdMsg__DATA.begin(),CmdMsg__DATA.end(),0xAA);

 //-----------------------------------------
 svc::remote_fb_out_msg_v1 OutMsg;

 OutMsg.blr        =CmdMsg__BLR;
 OutMsg.data       =CmdMsg__DATA;
 OutMsg.descrs     =CmdMsg__DATA_DESCRS;
 OutMsg.data_align =4;

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtFetch_M_ToEOF
  (tracer,
   spConnector,
   OpCtx,
   &hStmt,
   &OutMsg);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(!hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult); //was released after EOF
 _TSO_CHECK(!hStmt->m_pClosingTr);

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtClose
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(!hStmt->m_pParentTr);
 _TSO_CHECK(!hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr); //deferred close

 //-----------------------------------------
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
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr);

 //-----------------------------------------
 svc::HACK__CloseStmt
  (tracer,
   spConnector,
   &hStmt);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());
 _TSO_CHECK(hStmt->m_pParentTr==hTr);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(hStmt->m_pClosingTr==hTr);

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__StmtFetch_M_ToRow
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

   // 1. error from close
   // 2. ibprovider hint
   // 3. error from execute
   // 4. ibprovider hint
   // 5. error from fetch
   errSvc::check_err_count(exc,5);

   errSvc::check_err_rec__srv_err__failed_to_close_stmt__reclose__fb3
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   errSvc::check_err_rec__stmt_err__failed_to_close_stmt
    (tracer,
     exc.get_record(1));

   //SQLDA missing or incorrect version, or incorrect number/type of variables
   errSvc::check_err_rec__partially
    (tracer,
     exc.get_record(2),
     spConnector->GetData()->m_DBMS_Name,
     L"No SQLDA for input values provided");

   errSvc::check_err_rec__stmt_srv_err__execute_fail
    (tracer,
     exc.get_record(3));

   //Cursor is not open
   errSvc::check_err_rec__srv_err__cursor_is_not_open__fb3
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(4));

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 //состояние запроса не должно меняться. Появится только m_spFetchResult.
 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_pParentTr==hTr)
 _TSO_CHECK(hStmt->m_spFetchResult);
 _TSO_CHECK(hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(hStmt->m_pClosingTr==hTr)

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hStmt);
 _TSO_CHECK(!hStmt->m_pParentTr)
 _TSO_CHECK(!hStmt->m_spFetchResult);
 _TSO_CHECK(!hStmt->m_EFlags.test(hStmt->EFLAG__EXECUTION_WAS_DEFERRED));
 _TSO_CHECK(!hStmt->m_pClosingTr)

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_222__err3__fb3

////////////////////////////////////////////////////////////////////////////////

const wchar_t* WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl::helper__get_fetch_bugcheck_src
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
   return L"RemoteFB__API_P12_LAZY_SEND__FetchStatement_M::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13_LAZY_SEND__FetchStatement_M::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_fetch_bugcheck_src

//------------------------------------------------------------------------
const wchar_t* WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl::helper__get_fetch_subsystem
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
//struct WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_descr

struct WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_036__StmtFetch_M__v2_lazy_send::tag_descr
 WORK_Test_036__StmtFetch_M__v2_lazy_send::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("201.reexecution.without_close_in_new_trs",
   test_201__reexecution__without_close_in_new_trs)

 DEF_TEST_DESCR
  ("202.reexecution.with_close_in_new_trs",
   test_202__reexecution__with_close_in_new_trs)

 DEF_TEST_DESCR
  ("203.reexecution.with_params",
   test_203__reexecution__with_params)

 DEF_TEST_DESCR
  ("210.reexecution.with_hack_closed_prev_cursor",
   test_210__reexecution__with_hack_closed_prev_cursor)

 DEF_TEST_DESCR
  ("211.reexecution.with_hack_closed_prev_cursor.v2",
   test_211__reexecution__with_hack_closed_prev_cursor_v2)

 //-----------------------------------------
 DEF_TEST_DESCR2
  ("220.err2.fbbug4983",
   test_220__err2__fbbug4983,
   "SRV<FB-3")

 DEF_TEST_DESCR2
  ("220.err2.fbbug4983.fb3",
   test_220__err2__fbbug4983__fb3,
   "SRV>=FB-3")

 //-----------------------------------------
 DEF_TEST_DESCR2
  ("221.err2",
   test_221__err2,
   "SRV<FB-3")

 DEF_TEST_DESCR2
  ("221.err2.fb3",
   test_221__err2__fb3,
   "SRV>=FB-3")

 //-----------------------------------------
 DEF_TEST_DESCR2
  ("222.err3",
   test_222__err3,
   "SRV<FB-3")

 DEF_TEST_DESCR2
  ("222.err3.fb3",
   test_222__err3__fb3,
   "SRV>=FB-3")
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_036__StmtFetch_M__v2_lazy_send

void WORK_Test_036__StmtFetch_M__v2_lazy_send::create
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
 structure::str_formatter
  ftestID("RemoteFB.WORK.036.StmtFetch_M.v2.ptype__%1.%2");

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
}//namespace ibp_test
