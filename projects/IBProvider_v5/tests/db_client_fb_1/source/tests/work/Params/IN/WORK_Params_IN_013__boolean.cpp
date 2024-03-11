////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/Params/IN/WORK_Params_IN_013__boolean.h"
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
//class WORK_Params_IN_013__boolean::tag_impl

class WORK_Params_IN_013__boolean::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

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
};//class WORK_Params_IN_013__boolean

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Params_IN_013__boolean::tag_impl::tag_data_005

struct WORK_Params_IN_013__boolean::tag_impl::tag_data_005
{
 public:
  bool nullable;

 public:
  isc_api::t_ibp_fb030_bool  result_value;
  short                      result_sqlind;
};//struct WORK_Params_IN_013__boolean::tag_impl::tag_data_005

////////////////////////////////////////////////////////////////////////////////

#define DEF_DATA(nullable,value,sqlind) \
 {nullable,value,sqlind},

//------------------------------------------------------------------------

const WORK_Params_IN_013__boolean::tag_impl::tag_data_005
 WORK_Params_IN_013__boolean::tag_impl::sm_data_005[]=
{
 DEF_DATA(/*nullable*/ true,
          /*value*/    0,
          /*sqlind*/  -1)

 DEF_DATA(/*nullable*/ true,
          /*value*/    1,
          /*sqlind*/   0)

 DEF_DATA(/*nullable*/ true,
          /*value*/    0,
          /*sqlind*/   0)

 DEF_DATA(/*nullable*/ false,
          /*value*/    1,
          /*sqlind*/   c_test_005__dummy_sqlind)

 DEF_DATA(/*nullable*/ false,
          /*value*/    0,
          /*sqlind*/   c_test_005__dummy_sqlind)
};//sm_data_005

//------------------------------------------------------------------------
#undef DEF_DATA

////////////////////////////////////////////////////////////////////////////////
//TEST 005

void WORK_Params_IN_013__boolean::tag_impl::test_005_generic
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

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   (unsigned short)cns.db_dialect_Ex.value(),
   "execute block(A BOOLEAN=?)returns(B BOOLEAN)as begin B=:A; suspend;end;");

  _TSO_CHECK(hTr==hTrCopy);
  _TSO_CHECK(hTr->m_ID.has_value());

  _TSO_CHECK(hStmt==hStmtCopy);
  _TSO_CHECK(hStmt->m_ID.has_value());

 for(size_t iData=0;iData!=_DIM_(sm_data_005);++iData)
 {
  const tag_data_005& Data=sm_data_005[iData];

  tracer<<"----------------- ["<<iData<<"]"<<send;

  tracer<<"nullable     : "<<Data.nullable<<send;
  tracer<<"result_value : "<<Data.result_value<<send;
  tracer<<"result_sqlind: "<<Data.result_sqlind<<send;

  _TSO_CHECK(hStmt);
  _TSO_CHECK(hStmt->m_ID.has_value());

  //-----------------------------------------
  XSQLDA_V1_Wrapper in_xsqlda(1);

  in_xsqlda->sqld=1;

  in_xsqlda->sqlvar[0].sqltype  =isc_api::ibp_fb030_sql_boolean|(Data.nullable?1:0);
  in_xsqlda->sqlvar[0].sqllen   =sizeof(Data.result_value);
  in_xsqlda->sqlvar[0].sqldata  =const_cast<char*>(reinterpret_cast<const char*>(&Data.result_value));
  in_xsqlda->sqlvar[0].sqlind   =const_cast<short*>(&Data.result_sqlind);

  //-----------------------------------------
  svc::RemoteFB_Connector__StmtExecute
   (tracer,
    spConnector,
    OpCtx,
    &hTr,
    &hStmt,
    /*pInXSQLDA*/in_xsqlda,
    /*pOutXSQLDA*/nullptr);

  _TSO_CHECK(hTr==hTrCopy);
  _TSO_CHECK(hTr->m_ID.has_value());

  _TSO_CHECK(hStmt==hStmtCopy);
  _TSO_CHECK(hStmt->m_ID.has_value());

  //----------------------------------------
  XSQLDA_V1_Wrapper out_xsqlda(1);

  out_xsqlda->sqld=1;

  isc_api::t_ibp_fb030_bool  xparam0_value=37;
  short                      xparam0_ind=c_test_005__dummy_sqlind;

  out_xsqlda->sqlvar[0].sqltype  =isc_api::ibp_fb030_sql_boolean|(Data.nullable?1:0);
  out_xsqlda->sqlvar[0].sqllen   =sizeof(xparam0_value);
  out_xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(&xparam0_value);
  out_xsqlda->sqlvar[0].sqlind   =&xparam0_ind;

  //----------------------------------------
  svc::RemoteFB_Connector__StmtFetch_ToRow
   (tracer,
    spConnector,
    OpCtx,
    &hStmt,
    out_xsqlda);

  //----------------------------------------
  svc::checkValue__BOOLEAN
   (tracer,
    xparam0_ind,
    xparam0_value,
    Data.result_sqlind,
    Data.result_value);

  //----------------------------------------
  svc::RemoteFB_Connector__StmtFetch_ToEOF
   (tracer,
    spConnector,
    OpCtx,
    &hStmt,
    out_xsqlda);

  //----------------------------------------
  svc::RemoteFB_Connector__StmtClose
   (tracer,
    spConnector,
    &hStmt);
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
//struct WORK_Params_IN_013__boolean::tag_descr

struct WORK_Params_IN_013__boolean::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class WORK_Params_IN_013__boolean::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,WORK_Params_IN_013__boolean::tag_impl::func},

const WORK_Params_IN_013__boolean::tag_descr
 WORK_Params_IN_013__boolean::sm_Tests[]=
{
 DEF_TEST_DESCR("005.generic",
                test_005_generic)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class WORK_Params_IN_013__boolean

void WORK_Params_IN_013__boolean::create(TTSO_PushTest*      const pTestPusher,
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
  ftestID("RemoteFB.WORK.Params.IN.013.boolean.ptype__%1.%2");

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

  const TTSO_TestPtr spTest(new TTSO_TestFunc_v2(pParams,
                                                 ftestID.c_str(),
                                                 sm_Tests[it[iTest]].Func,
                                                 Data,
                                                 "NE__BOOLEAN"));
  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
