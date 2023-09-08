////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/Params/OUT/WORK_Params_OUT_016__decfloat34.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Params_OUT_016__decfloat34::tag_impl

class WORK_Params_OUT_016__decfloat34::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_002_null
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_005_generic
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  struct tag_data_005;

  static const short c_test_005__dummy_sqlind=1845;

  static const tag_data_005 sm_data_005[];
};//class WORK_Params_OUT_016__decfloat34

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void WORK_Params_OUT_016__decfloat34::tag_impl::test_001
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
   "insert into TEST_MODIFY_ROW (COL_DECFLOAT34) values (2.94143517338616406433624442481776E+3741) returning COL_DECFLOAT34;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 isc_api::t_ibp_fb040_decfloat34 xparam0_value=db_obj::make_fb040_decfloat34(0,0);
 short                           xparam0_ind=-1234;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_fb040_sql_decfloat34|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/xsqlda);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 isc_api::t_ibp_fb040_decfloat34 c_expected_value=db_obj::make_fb040_decfloat34(7501365068327038966, 4730844092388830769);

 _TSO_CHECK(xparam0_value==c_expected_value);
 _TSO_CHECK(xparam0_ind==0);

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
}//test_001

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void WORK_Params_OUT_016__decfloat34::tag_impl::test_002_null
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
   "insert into TEST_MODIFY_ROW (COL_DECFLOAT34) values (NULL) returning COL_DECFLOAT34;");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 isc_api::t_ibp_fb040_decfloat34 xparam0_value=db_obj::make_fb040_decfloat34(5084382762143122012, 8378497661203018938);
 short                           xparam0_ind=-1234;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_fb040_sql_decfloat34|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xparam0_value);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xparam0_value);
 xsqlda->sqlvar[0].sqlind =&xparam0_ind;

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*pInXSQLDA*/nullptr,
   /*pOutXSQLDA*/xsqlda);

 _TSO_CHECK(hTr==hTrCopy);
 _TSO_CHECK(hTr->m_ID.has_value());

 _TSO_CHECK(hStmt==hStmtCopy);
 _TSO_CHECK(hStmt->m_ID.has_value());

 //-----------------------------------------
 _TSO_CHECK(xparam0_value==isc_api::__null__fb040_decfloat34);
 _TSO_CHECK(xparam0_ind==-1);

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
}//test_002_null

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Params_OUT_016__decfloat34::tag_impl::tag_data_005

struct WORK_Params_OUT_016__decfloat34::tag_impl::tag_data_005
{
 public:
  const char* sql;

  bool  nullable;
  short sqlscale;

  isc_api::t_ibp_fb040_decfloat34 result_value;
  short                       result_sqlind;
};//struct WORK_Params_OUT_016__decfloat34::tag_impl::tag_data_005

////////////////////////////////////////////////////////////////////////////////

#define DEF_DATA(sql,nullable,scale,value,sqlind) \
 {sql,nullable,scale,value,sqlind},

//------------------------------------------------------------------------

const WORK_Params_OUT_016__decfloat34::tag_impl::tag_data_005
 WORK_Params_OUT_016__decfloat34::tag_impl::sm_data_005[]=
{
 DEF_DATA("insert into TEST_MODIFY_ROW (COL_DECFLOAT34) values(NULL) returning COL_DECFLOAT34;",
           /*nullable*/ true,
           /*scale*/    0,
           /*value*/    isc_api::__null__fb040_decfloat34,
           /*sqlind*/  -1)

 DEF_DATA("insert into TEST_MODIFY_ROW (COL_DECFLOAT34) values(2.65352351209744174678070487903736E-1431) returning COL_DECFLOAT34;",
           /*nullable*/ true,
           /*scale*/    0,
           /*value*/    db_obj::make_fb040_decfloat34(4887382082931013558, 2349285088527729276),
           /*sqlind*/   0)

 DEF_DATA("insert into TEST_MODIFY_ROW (COL_DECFLOAT34) values(2.031448310168714873483368144400202E-5442) returning COL_DECFLOAT34;",
           /*nullable*/ false,
           /*scale*/    0,
           /*value*/    db_obj::make_fb040_decfloat34(5041264636079898882, 625792648444131897),
           /*sqlind*/   c_test_005__dummy_sqlind)

 DEF_DATA("insert into TEST_MODIFY_ROW (COL_DECFLOAT34) values(1.088707170151712483826644087449249E+1453) returning COL_DECFLOAT34;",
           /*nullable*/ true,
           /*scale*/    0,
           /*value*/    db_obj::make_fb040_decfloat34(2931611158714066249, 2840369410721461369),
           /*sqlind*/   0)

 DEF_DATA("insert into TEST_MODIFY_ROW (COL_DECFLOAT34) values('Infinity') returning COL_DECFLOAT34;",
           /*nullable*/ true,
           /*scale*/    0,
           /*value*/    db_obj::make_fb040_decfloat34(0, 8646911284551352320),
           /*sqlind*/   0)

 DEF_DATA("insert into TEST_MODIFY_ROW (COL_DECFLOAT34) values(0.0000) returning COL_DECFLOAT34;",
           /*nullable*/ false,
           /*scale*/    0,
           /*value*/    db_obj::make_fb040_decfloat34(0, 2451928522126524416),
           /*sqlind*/   c_test_005__dummy_sqlind)

 DEF_DATA("insert into TEST_MODIFY_ROW_WD (TEST_ID) values(NULL) returning COL_DECFLOAT34;",
           /*nullable*/ true,
           /*scale*/    0,
           /*value*/    db_obj::make_fb040_decfloat34(5120087485820898868, 11675159851796033763), // -343434343434343434343434.343434
           /*sqlind*/   0)
};//sm_data_005

//------------------------------------------------------------------------
#undef DEF_DATA

////////////////////////////////////////////////////////////////////////////////
//TEST 005

void WORK_Params_OUT_016__decfloat34::tag_impl::test_005_generic
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
 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 for(size_t iData=0;iData!=_DIM_(sm_data_005);++iData)
 {
  const tag_data_005& Data=sm_data_005[iData];

  tracer<<L"----------------- ["<<iData<<"] - "<<Data.sql<<send;

  tracer<<L"nullable     : "<<Data.nullable<<send;
  tracer<<L"sqlscale     : "<<Data.sqlscale<<send;
  tracer<<L"result_value : "<<Data.result_value<<send;
  tracer<<L"result_sqlind: "<<Data.result_sqlind<<send;

  svc::RemoteFB_Connector__StmtPrepare
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    (unsigned short)cns.db_dialect_Ex.value(),
    Data.sql);

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_ID.has_value());

  //-----------------------------------------
  XSQLDA_V1_Wrapper xsqlda(1);

  xsqlda->sqld=1;

  isc_api::t_ibp_fb040_decfloat34 xparam0_value=db_obj::make_fb040_decfloat34(structure::negative_one,structure::negative_one);
  short                           xparam0_ind=c_test_005__dummy_sqlind;

  xsqlda->sqlvar[0].sqltype  =isc_api::ibp_fb040_sql_decfloat34|(Data.nullable?1:0);
  xsqlda->sqlvar[0].sqlscale =Data.sqlscale;
  xsqlda->sqlvar[0].sqllen   =sizeof(xparam0_value);
  xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(&xparam0_value);
  xsqlda->sqlvar[0].sqlind   =&xparam0_ind;

  //-----------------------------------------
  svc::RemoteFB_Connector__StmtExecute
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    /*pInXSQLDA*/nullptr,
    /*pOutXSQLDA*/xsqlda);

  _TSO_CHECK(hTr==hTrCopy);
  _TSO_CHECK(hTr->m_ID.has_value());

  _TSO_CHECK(hStmt==hStmtCopy);
  _TSO_CHECK(hStmt->m_ID.has_value());

  //-----------------------------------------
  if(xparam0_value!=Data.result_value)
  {
   tracer(tso_msg_error,-1)
    <<L"Incorrect value: ["<<xparam0_value<<L"]. Expected: ["<<Data.result_value<<"]."<<send;
  }//if

  if(xparam0_ind!=Data.result_sqlind)
  {
   tracer(tso_msg_error,-1)
    <<L"Incorrect indicator: ["<<xparam0_ind<<L"]. Expected: ["<<Data.result_sqlind<<"]."<<send;
  }//if
 }//for iData

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
}//test_005_generic

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Params_OUT_016__decfloat34::tag_descr

struct WORK_Params_OUT_016__decfloat34::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class WORK_Params_OUT_016__decfloat34::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,WORK_Params_OUT_016__decfloat34::tag_impl::func},

const WORK_Params_OUT_016__decfloat34::tag_descr
 WORK_Params_OUT_016__decfloat34::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001",
   test_001)

 DEF_TEST_DESCR
  ("002.null",
   test_002_null)

 DEF_TEST_DESCR
  ("005.generic",
   test_005_generic)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class WORK_Params_OUT_016__decfloat34

void WORK_Params_OUT_016__decfloat34::create
                             (TTSO_PushTest*      const pTestPusher,
                              TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                               //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);     //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter
  ftestID("RemoteFB.WORK.Params.OUT.014.decfloat34.ptype__%1.%2");

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
         "NE__DECFLOAT34")));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
