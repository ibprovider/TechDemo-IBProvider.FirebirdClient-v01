////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_034__StmtExecute_M__v4__IN_OUT.h"
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

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_impl

class WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001__short
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_002__long
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_003__int64
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_004__float
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_005__double
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_012__int128
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_012__int128__NUM30_3
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_013__decfloat16
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_014__decfloat34
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_015__timestamp_with_tz
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_016__time_with_tz
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
};//class WORK_Test_034__StmtExecute_M__v4__IN_OUT

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_impl::test_001__short
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
}//test_001__short

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_impl::test_002__long
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
}//test_002__long

////////////////////////////////////////////////////////////////////////////////
//TEST 003

void WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_impl::test_003__int64
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
}//test_003__int64

////////////////////////////////////////////////////////////////////////////////
//TEST 004

void WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_impl::test_004__float
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
}//test_004__float

////////////////////////////////////////////////////////////////////////////////
//TEST 005

void WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_impl::test_005__double
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
   //---- value [double]
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
}//test_005__double

////////////////////////////////////////////////////////////////////////////////
//TEST 012

void WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_impl::test_012__int128
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 using value_type=db_obj::t_dbvalue__fb040_int128;

 assert_s(sizeof(value_type)==16);

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
   "insert into TEST_MODIFY_ROW (COL_INT128) values (?) RETURNING COL_INT128;");

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
  { {0,0}                    ,    0, {0,0}                    ,    0},   //  0
  { {1,0}                    ,    0, {1,0}                    ,    0},   //  1
  { {_UI64_MAX,_UI64_MAX}    ,    0, {_UI64_MAX,_UI64_MAX}    ,    0},   // -1
  { {_UI64_MAX-1,_UI64_MAX}  ,    0, {_UI64_MAX-1,_UI64_MAX}  ,    0},   // -2
  { {2,0}                    ,    0, {2,0}                    ,    0},   //  2
  { {_UI64_MAX,_UI64_MAX}    ,   -1, {0,0}                    ,   -1},   //  NULL
  { {_UI64_MAX,_I64_MAX}     ,    0, {_UI64_MAX,_I64_MAX}     ,    0},   //  INT128_MAX
  { {_UI64_MAX-1,_I64_MAX}   ,    0, {_UI64_MAX-1,_I64_MAX}   ,    0},   //  INT128_MAX-1
  { {0,1ui64<<63}            ,    0, {0,1ui64<<63}            ,    0},   //  INT128_MIN
  { {1,1ui64<<63}            ,    0, {1,1ui64<<63}            ,    0},   //  INT128_MIN+1
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
   /*  6 */ isc_api::ibp_fb040_blr_dtype__int128, // data type
   /*  7 */ 0,                                    // data scale
   /*  8 */ isc_api::ibp_isc_blr_dtype__short,    // indicator type
   /*  9 */ 0,                                    // indicator scale
   /* 10 */ isc_api::ibp_isc_blr_end,
   /* 11 */ isc_api::ibp_isc_blr_eoc,
  };//InMsg__BLR

  //----------------------------------------
  const auto input_value=testValue.set_value;

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

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

  InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_fb040_blr_dtype__int128;
  InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_fb040_sql_int128;
  InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  InMsg__DATA_DESCRS[0].m_msg_value_block_size   =16;
  InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =16;

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
   /*  6 */ isc_api::ibp_fb040_blr_dtype__int128, // data type
   /*  7 */ 0,                                    // data scale
   /*  8 */ isc_api::ibp_isc_blr_dtype__short,    // indicator type
   /*  9 */ 0,                                    // indicator scale
   /* 10 */ isc_api::ibp_isc_blr_end,
   /* 11 */ isc_api::ibp_isc_blr_eoc,
  };//OutMsg__BLR

  //----------------------------------------
  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
  {
   //---- value [int128]
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   //---- indicator [short]
   0xFE,
   0xFE,
  };//OutMsg__DATA

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> OutMsg__DATA_DESCRS;

  OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_fb040_blr_dtype__int128;
  OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_fb040_sql_int128;
  OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =16;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =16;

  //----------------------------------------
  {
   value_type c_neg_one=db_obj::make_fb040_int128(structure::negative_one,structure::negative_one);

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
   auto out_value=input_value; out_value=db_obj::__null_dbvalue__fb040_int128;

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
}//test_012__int128

//------------------------------------------------------------------------
void WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_impl::test_012__int128__NUM30_3
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 using value_type=db_obj::t_dbvalue__fb040_int128;

 assert_s(sizeof(value_type)==16);

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
   "insert into NUM (N_30_3) values (?) RETURNING N_30_3;");

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
  { {0,0}                    ,    0, {0,0}                    ,    0},   //  0
  { {1,0}                    ,    0, {1,0}                    ,    0},   //  1
  { {_UI64_MAX,_UI64_MAX}    ,    0, {_UI64_MAX,_UI64_MAX}    ,    0},   // -1
  { {_UI64_MAX-1,_UI64_MAX}  ,    0, {_UI64_MAX-1,_UI64_MAX}  ,    0},   // -2
  { {2,0}                    ,    0, {2,0}                    ,    0},   //  2
  { {_UI64_MAX,_UI64_MAX}    ,   -1, {0,0}                    ,   -1},   //  NULL
  { {_UI64_MAX,_I64_MAX}     ,    0, {_UI64_MAX,_I64_MAX}     ,    0},   //  INT128_MAX
  { {_UI64_MAX-1,_I64_MAX}   ,    0, {_UI64_MAX-1,_I64_MAX}   ,    0},   //  INT128_MAX-1
  { {0,1ui64<<63}            ,    0, {0,1ui64<<63}            ,    0},   //  INT128_MIN
  { {1,1ui64<<63}            ,    0, {1,1ui64<<63}            ,    0},   //  INT128_MIN+1
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
   /*  6 */ isc_api::ibp_fb040_blr_dtype__int128, // data type
   /*  7 */ (unsigned char)-3,                    // data scale
   /*  8 */ isc_api::ibp_isc_blr_dtype__short,    // indicator type
   /*  9 */ 0,                                    // indicator scale
   /* 10 */ isc_api::ibp_isc_blr_end,
   /* 11 */ isc_api::ibp_isc_blr_eoc,
  };//InMsg__BLR

  //----------------------------------------
  const auto input_value=testValue.set_value;

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

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

  InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_fb040_blr_dtype__int128;
  InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_fb040_sql_int128;
  InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =-3;
  InMsg__DATA_DESCRS[0].m_msg_value_block_size   =16;
  InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =16;

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
   /*  6 */ isc_api::ibp_fb040_blr_dtype__int128, // data type
   /*  7 */ (unsigned char)-3,                    // data scale
   /*  8 */ isc_api::ibp_isc_blr_dtype__short,    // indicator type
   /*  9 */ 0,                                    // indicator scale
   /* 10 */ isc_api::ibp_isc_blr_end,
   /* 11 */ isc_api::ibp_isc_blr_eoc,
  };//OutMsg__BLR

  //----------------------------------------
  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
  {
   //---- value [int128]
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   //---- indicator [short]
   0xFE,
   0xFE,
  };//OutMsg__DATA

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> OutMsg__DATA_DESCRS;

  OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_fb040_blr_dtype__int128;
  OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_fb040_sql_int128;
  OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =-3;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =16;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =16;

  //----------------------------------------
  {
   value_type c_neg_one=db_obj::make_fb040_int128(structure::negative_one,structure::negative_one);

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
   auto out_value=input_value; out_value=db_obj::__null_dbvalue__fb040_int128;

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
}//test_012__int128__NUM30_3

////////////////////////////////////////////////////////////////////////////////
//TEST 013

void WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_impl::test_013__decfloat16
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 using value_type=db_obj::t_dbvalue__fb040_decfloat16;

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
   "insert into TEST_MODIFY_ROW (COL_DECFLOAT16) values (?) RETURNING COL_DECFLOAT16;");

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
  { {17870283321406128128}   ,    0,
    {17870283321406128128}   ,    0},   //  -Infinity

  { {8646911284551352320}    ,    0,
    {8646911284551352320}    ,    0},   //   Infinity

  { {8646911284551352320}    ,   -1,
    {0}                      ,   -1},   //   NULL

  { {8935141660703064064}    ,    0,
    {8935141660703064064}    ,    0},   //   NaN

  { {18158513697557839872}   ,    0,
    {18158513697557839872}   ,    0},   //  -NaN

  { {2736276221030731351}    ,    0,
    {2736276221030731351}    ,    0},   //  0.1234567890123457
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
   /*  6 */ isc_api::ibp_fb040_blr_dtype__decfloat16, // data type
   /*  7 */ isc_api::ibp_isc_blr_dtype__short,        // indicator type
   /*  8 */ 0,                                        // indicator scale
   /*  9 */ isc_api::ibp_isc_blr_end,
   /* 10 */ isc_api::ibp_isc_blr_eoc,
  };//InMsg__BLR

  //----------------------------------------
  const auto input_value=testValue.set_value;

  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
  {
   //---- value [decfloat16]
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

  InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_fb040_blr_dtype__decfloat16;
  InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_fb040_sql_decfloat16;
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
   /*  6 */ isc_api::ibp_fb040_blr_dtype__decfloat16, // data type
   /*  7 */ isc_api::ibp_isc_blr_dtype__short,        // indicator type
   /*  8 */ 0,                                        // indicator scale
   /*  9 */ isc_api::ibp_isc_blr_end,
   /* 10 */ isc_api::ibp_isc_blr_eoc,
  };//OutMsg__BLR

  //----------------------------------------
  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
  {
   //---- value [decfloat16]
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

  OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_fb040_blr_dtype__decfloat16;
  OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_fb040_sql_decfloat16;
  OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =8;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =8;

  //----------------------------------------
  {
   value_type c_neg_one=db_obj::make_fb040_decfloat16(structure::negative_one);

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
   auto out_value=input_value; out_value=db_obj::__null_dbvalue__fb040_decfloat16;

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
}//test_013__decfloat16

////////////////////////////////////////////////////////////////////////////////
//TEST 014

void WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_impl::test_014__decfloat34
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 using value_type=db_obj::t_dbvalue__fb040_decfloat34;

 assert_s(sizeof(value_type)==16);

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
   "insert into TEST_MODIFY_ROW (COL_DECFLOAT34) values (?) RETURNING COL_DECFLOAT34;");

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
  { {0,17870283321406128128}                     ,    0,
    {0,17870283321406128128}                     ,    0},   //  -Infinity

  { {0,8646911284551352320}                      ,    0,
    {0,8646911284551352320}                      ,    0},   //   Infinity

  { {0,8646911284551352320}                      ,   -1,
    {0}                                          ,   -1},   //   NULL

  { {0,8935141660703064064}                      ,    0,
    {0,8935141660703064064}                      ,    0},   //   NaN

  { {0,18158513697557839872}                     ,    0,
    {0,18158513697557839872}                     ,    0},   //  -NaN

  { {8015301715358266677,2738069051415603429}    ,    0,
    {8015301715358266677,2738069051415603429}    ,    0},   //   0.1234567890123456789012345678901235
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
   /*  6 */ isc_api::ibp_fb040_blr_dtype__decfloat34, // data type
   /*  7 */ isc_api::ibp_isc_blr_dtype__short,        // indicator type
   /*  8 */ 0,                                        // indicator scale
   /*  9 */ isc_api::ibp_isc_blr_end,
   /* 10 */ isc_api::ibp_isc_blr_eoc,
  };//InMsg__BLR

  //----------------------------------------
  const auto input_value=testValue.set_value;

  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
  {
   //---- value [decfloat34]
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

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

  InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_fb040_blr_dtype__decfloat34;
  InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_fb040_sql_decfloat34;
  InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  InMsg__DATA_DESCRS[0].m_msg_value_block_size   =16;
  InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =16;

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
   /*  6 */ isc_api::ibp_fb040_blr_dtype__decfloat34, // data type
   /*  7 */ isc_api::ibp_isc_blr_dtype__short,        // indicator type
   /*  8 */ 0,                                        // indicator scale
   /*  9 */ isc_api::ibp_isc_blr_end,
   /* 10 */ isc_api::ibp_isc_blr_eoc,
  };//OutMsg__BLR

  //----------------------------------------
  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
  {
   //---- value [decfloat34]
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   //---- indicator [short]
   0xFE,
   0xFE,
  };//OutMsg__DATA

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> OutMsg__DATA_DESCRS;

  OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_fb040_blr_dtype__decfloat34;
  OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_fb040_sql_decfloat34;
  OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =16;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =16;

  //----------------------------------------
  {
   value_type c_neg_one=db_obj::make_fb040_decfloat34(structure::negative_one,structure::negative_one);

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
   auto out_value=input_value; out_value=db_obj::__null_dbvalue__fb040_decfloat34;

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
}//test_014__decfloat34

////////////////////////////////////////////////////////////////////////////////
//TEST 015

void WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_impl::test_015__timestamp_with_tz
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 using value_type=db_obj::t_dbvalue__fb040_timestamp_with_tz;

 assert_s(sizeof(value_type)==12);

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
   "insert into TEST_MODIFY_ROW (COL_TIMESTAMP_WITH_TZ) values (?) RETURNING COL_TIMESTAMP_WITH_TZ;");

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
  { db_obj::make_fb040_timestamp_with_tz(60114,253500000,3*60+1439 /*==1619*/) ,    0,    //  2023-06-19 10:02:30 +03:00
    db_obj::make_fb040_timestamp_with_tz(60114,253500000,3*60+1439 /*==1619*/) ,    0},

  { db_obj::make_fb040_timestamp_with_tz(60114,253500000,3*60+1439 /*==1619*/) ,   -1,    //   NULL
    db_obj::make_fb040_timestamp_with_tz(0,0,0)                                ,   -1},

  { db_obj::make_fb040_timestamp_with_tz(60114,253500000, 65064)               ,    0,    //   2023-06-19 10:02:30 Europe/Moscow
    db_obj::make_fb040_timestamp_with_tz(60114,253500000, 65064)               ,    0},
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
   /*  6 */ isc_api::ibp_fb040_blr_dtype__timestamp_with_tz, // data type
   /*  7 */ isc_api::ibp_isc_blr_dtype__short,               // indicator type
   /*  8 */ 0,                                               // indicator scale
   /*  9 */ isc_api::ibp_isc_blr_end,
   /* 10 */ isc_api::ibp_isc_blr_eoc,
  };//InMsg__BLR

  //----------------------------------------
  const auto input_value=testValue.set_value;

  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
  {
   //---- value [timestamp_with_tz]
   0,0,
   0,0,
   0,0,
   0,0,
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

  InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_fb040_blr_dtype__timestamp_with_tz;
  InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_fb040_sql_timestamp_with_tz;
  InMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  InMsg__DATA_DESCRS[0].m_msg_value_block_size   =12;
  InMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  InMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =12;

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
   /*  6 */ isc_api::ibp_fb040_blr_dtype__timestamp_with_tz, // data type
   /*  7 */ isc_api::ibp_isc_blr_dtype__short,               // indicator type
   /*  8 */ 0,                                               // indicator scale
   /*  9 */ isc_api::ibp_isc_blr_end,
   /* 10 */ isc_api::ibp_isc_blr_eoc,
  };//OutMsg__BLR

  //----------------------------------------
  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
  {
   //---- value [timestamp_with_tz]
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
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

  OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_fb040_blr_dtype__timestamp_with_tz;
  OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_fb040_sql_timestamp_with_tz;
  OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =12;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =12;

  //----------------------------------------
  {
   value_type c_neg_one
    =db_obj::make_fb040_timestamp_with_tz
      (structure::negative_one,
       structure::negative_one,
       structure::negative_one);

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
   auto out_value=input_value; out_value=db_obj::__null_dbvalue__fb040_timestamp_with_tz;

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
}//test_015__timestamp_with_tz

////////////////////////////////////////////////////////////////////////////////
//TEST 016

void WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_impl::test_016__time_with_tz
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 using value_type=db_obj::t_dbvalue__fb040_time_with_tz;

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
   "insert into TEST_MODIFY_ROW (COL_TIMESTAMP_WITH_TZ) values (?) RETURNING COL_TIMESTAMP_WITH_TZ;");

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
  { db_obj::make_fb040_time_with_tz(253500000,3*60+1439 /*==1619*/) ,    0,    //  10:02:30 +03:00
    db_obj::make_fb040_time_with_tz(253500000,3*60+1439 /*==1619*/) ,    0},

  { db_obj::make_fb040_time_with_tz(253500000,3*60+1439 /*==1619*/) ,   -1,    //  NULL
    db_obj::make_fb040_time_with_tz(0,0)                            ,   -1},

  { db_obj::make_fb040_time_with_tz(253500000, 65064)               ,    0,    //  10:02:30 Europe/Moscow
    db_obj::make_fb040_time_with_tz(253500000, 65064)               ,    0},
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
   /*  6 */ isc_api::ibp_fb040_blr_dtype__time_with_tz, // data type
   /*  7 */ isc_api::ibp_isc_blr_dtype__short,          // indicator type
   /*  8 */ 0,                                          // indicator scale
   /*  9 */ isc_api::ibp_isc_blr_end,
   /* 10 */ isc_api::ibp_isc_blr_eoc,
  };//InMsg__BLR

  //----------------------------------------
  const auto input_value=testValue.set_value;

  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> InMsg__DATA=
  {
   //---- value [time_with_tz]
   0,0,
   0,0,
   0,0,
   0,0,
   //---- indicator [short]
   0,
   0,
  };//InMsg__DATA

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> InMsg__DATA_DESCRS;

  InMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_fb040_blr_dtype__time_with_tz;
  InMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_fb040_sql_time_with_tz;
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
   /*  6 */ isc_api::ibp_fb040_blr_dtype__time_with_tz, // data type
   /*  7 */ isc_api::ibp_isc_blr_dtype__short,          // indicator type
   /*  8 */ 0,                                          // indicator scale
   /*  9 */ isc_api::ibp_isc_blr_end,
   /* 10 */ isc_api::ibp_isc_blr_eoc,
  };//OutMsg__BLR

  //----------------------------------------
  structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
  {
   //---- value [time_with_tz]
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   0xFF,0xFF,
   //---- indicator [short]
   0xFE,
   0xFE,
  };//OutMsg__DATA

  //----------------------------------------
  std::array<svc::remote_fb_in_msg_v1::descr_type,1> OutMsg__DATA_DESCRS;

  OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_fb040_blr_dtype__time_with_tz;
  OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_fb040_sql_time_with_tz;
  OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =8;
  OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
  OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =8;

  //----------------------------------------
  {
   value_type c_neg_one
    =db_obj::make_fb040_time_with_tz
      (structure::negative_one,
       structure::negative_one);

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
   auto out_value=input_value; out_value=db_obj::__null_dbvalue__fb040_time_with_tz;

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
}//test_016__time_with_tz

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_descr

struct WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const WORK_Test_034__StmtExecute_M__v4__IN_OUT::tag_descr
 WORK_Test_034__StmtExecute_M__v4__IN_OUT::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001.short",
   test_001__short)

 DEF_TEST_DESCR
  ("002.long",
   test_002__long)

 DEF_TEST_DESCR
  ("003.int64",
   test_003__int64)

 DEF_TEST_DESCR
  ("004.float",
   test_004__float)

 DEF_TEST_DESCR
  ("005.double",
   test_005__double)

 DEF_TEST_DESCR2
  ("012.int128",
   test_012__int128,
   "NE__INT128")

 DEF_TEST_DESCR2
  ("012.int128__NUM30_3",
   test_012__int128__NUM30_3,
   "NE__INT128")

 DEF_TEST_DESCR2
  ("013.decfloat16",
   test_013__decfloat16,
   "NE__DECFLOAT16")

 DEF_TEST_DESCR2
  ("014.decfloat34",
   test_014__decfloat34,
   "NE__DECFLOAT34")

 DEF_TEST_DESCR2
  ("015.timestamp_with_tz",
   test_015__timestamp_with_tz,
   "NE__TIMESTAMP_WITH_TZ")

 DEF_TEST_DESCR2
  ("016.time_with_tz",
   test_016__time_with_tz,
   "NE__TIME_WITH_TZ")
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_034__StmtExecute_M__v4__IN_OUT

void WORK_Test_034__StmtExecute_M__v4__IN_OUT::create
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
  ftestID("RemoteFB.WORK.034.StmtExecute_M.v4.IN_OUT.ptype__%1.%2");

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
