////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/Params/OUT/WORK_Params_OUT_005__double.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Params_OUT_005__double::tag_impl

class WORK_Params_OUT_005__double::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_005_generic
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  struct tag_data_005;

  static const short c_test_005__dummy_sqlind=1845;

  static const tag_data_005 sm_data_005[];
};//class WORK_Params_OUT_005__double

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Params_OUT_005__double::tag_impl::tag_data_005

struct WORK_Params_OUT_005__double::tag_impl::tag_data_005
{
 public:
  const char* sql;

  bool    nullable;

  double   result_value;
  short   result_sqlind;
};//struct WORK_Params_OUT_005__double::tag_impl::tag_data_005

////////////////////////////////////////////////////////////////////////////////

#define DEF_DATA(sql,nullable,value,sqlind) \
 {sql,nullable,value,sqlind},

//------------------------------------------------------------------------

const WORK_Params_OUT_005__double::tag_impl::tag_data_005
 WORK_Params_OUT_005__double::tag_impl::sm_data_005[]=
{
 DEF_DATA("insert into TEST_MODIFY_ROW (COL_DOUBLE) values(NULL) returning COL_DOUBLE;",
           /*nullable*/ true,
           /*value*/    0,
           /*sqlind*/  -1)

 DEF_DATA("insert into TEST_MODIFY_ROW (COL_DOUBLE) values(-3) returning COL_DOUBLE;",
           /*nullable*/ true,
           /*value*/    -3,
           /*sqlind*/   0)

 DEF_DATA("insert into TEST_MODIFY_ROW (COL_DOUBLE) values(-3) returning COL_DOUBLE;",
           /*nullable*/ false,
           /*value*/    -3,
           /*sqlind*/   c_test_005__dummy_sqlind)

 DEF_DATA("insert into TEST_MODIFY_ROW (COL_DOUBLE) values(-1234567.5) returning COL_DOUBLE;",
           /*nullable*/ true,
           /*value*/    -1234567.5,
           /*sqlind*/   0)
};//sm_data_005

//------------------------------------------------------------------------
#undef DEF_DATA

////////////////////////////////////////////////////////////////////////////////
//TEST 005

void WORK_Params_OUT_005__double::tag_impl::test_005_generic
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

  tracer<<"----------------- ["<<iData<<"] - "<<Data.sql<<send;

  tracer<<"nullable     : "<<Data.nullable<<send;
  tracer<<"result_value : "<<Data.result_value<<send;
  tracer<<"result_sqlind: "<<Data.result_sqlind<<send;

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

  double  xparam0_value=-23431;
  short  xparam0_ind=c_test_005__dummy_sqlind;

  xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_double|(Data.nullable?1:0);
  xsqlda->sqlvar[0].sqllen   =sizeof(xparam0_value);
  xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(&xparam0_value);
  xsqlda->sqlvar[0].sqlind   =&xparam0_ind;

  //-----------------------------------------
  svc::RemoteFB_Connector__StmtExecute(tracer,
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
    <<"Incorrect value: ["<<xparam0_value<<"]. Expected: ["<<Data.result_value<<"]."<<send;
  }//if

  if(xparam0_ind!=Data.result_sqlind)
  {
   tracer(tso_msg_error,-1)
    <<"Incorrect indicator: ["<<xparam0_ind<<"]. Expected: ["<<Data.result_sqlind<<"]."<<send;
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
//struct WORK_Params_OUT_005__double::tag_descr

struct WORK_Params_OUT_005__double::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class WORK_Params_OUT_005__double::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,WORK_Params_OUT_005__double::tag_impl::func},

const WORK_Params_OUT_005__double::tag_descr
 WORK_Params_OUT_005__double::sm_Tests[]=
{
 DEF_TEST_DESCR("005.generic",
                test_005_generic)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class WORK_Params_OUT_005__double

void WORK_Params_OUT_005__double::create
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
 structure::str_formatter ftestID("RemoteFB.WORK.Params.OUT.005.double.ptype__%1.%2");

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

  const TTSO_TestPtr
   spTest
    (structure::not_null_ptr
      (new TTSO_TestFunc_v2
        (pParams,
         ftestID.c_str(),
         sm_Tests[it[iTest]].Func,
         Data)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
