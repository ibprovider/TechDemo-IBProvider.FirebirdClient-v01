////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/StmtFetch/Types/decimal/WORK_StmtFetch__Types__decimal_001__D03_01.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch__Types__decimal_001__D03_01::tag_impl

class WORK_StmtFetch__Types__decimal_001__D03_01::tag_impl LCPI_CPP_CFG__CLASS__FINAL
 :public structure::t_basic_smart_interface_impl__dynamic<TTSO_Test,TTSO_MemoryAllocator>
{
 private:
  typedef tag_impl                                     self_type;

  tag_impl(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~tag_impl();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>     self_ptr;

 public:
  tag_impl(TTSO_GlobalContext*  pParams,
           const char*             pTestID,
           const TTSO_TestData_v2& Data);

  //test interface -------------------------------------------------------
  virtual std::string get_id()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool can_exec()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  TTSO_GlobalContext::self_ptr const m_spParams;

  std::string const m_TestID;

  TTSO_TestData_v2 const m_Data;
};//class WORK_StmtFetch__Types__decimal_001__D03_01::tag_impl

////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch__Types__decimal_001__D03_01::tag_impl

WORK_StmtFetch__Types__decimal_001__D03_01::tag_impl::tag_impl
                                           (TTSO_GlobalContext* const pParams,
                                            const char*         const pTestID,
                                            const TTSO_TestData_v2&   Data)
 :m_spParams(structure::not_null_ptr(pParams))
 ,m_TestID(structure::not_null_ptr(pTestID))
 ,m_Data(Data)
{
 assert(m_spParams);
}//tag_impl

//------------------------------------------------------------------------
WORK_StmtFetch__Types__decimal_001__D03_01::tag_impl::~tag_impl()
{
}

//test interface ---------------------------------------------------------
std::string WORK_StmtFetch__Types__decimal_001__D03_01::tag_impl::get_id()const
{
 return m_TestID;
}//get_id

//------------------------------------------------------------------------
bool WORK_StmtFetch__Types__decimal_001__D03_01::tag_impl::can_exec()const
{
 assert(m_spParams);

 if(!m_Data.can_exec(m_spParams))
  return false;

 return true;
}//can_exec

//------------------------------------------------------------------------
void WORK_StmtFetch__Types__decimal_001__D03_01::tag_impl::run(context_type* const pCtx)const
{
 assert(pCtx);
 assert(m_spParams);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices  svc;

 //-----------------------------------------
 svc::dbprops_type params(m_spParams);

 params.set_dbprop_init__location(svc::BuildLocationString(m_spParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 m_Data.SetParams(params);

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
 XSQLDA_V1_Wrapper xsqlda(/*n*/1);

 db_obj::t_dbvalue__i4   columnValue=0;
 short                   columnInd=0;

 xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
 xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqlsubtype =0;
 xsqlda->sqlvar[0].sqlscale   =-1;
 xsqlda->sqlvar[0].sqldata    =reinterpret_cast<char*>(&columnValue);
 xsqlda->sqlvar[0].sqlind     =&columnInd;

 xsqlda->sqld=1;

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 //----------------------------------------
 const char* const c_SQL
  ="execute block\n"
   "returns(X DECIMAL(3,1))\n"
   "as\n"
   "begin\n"
     " X=-99.9;  suspend;\n"    // 0
     " X=NULL;   suspend;\n"    // 1
     " X=-1.5;   suspend;\n"    // 2
     " X=-1;     suspend;\n"    // 3
     " X=NULL;   suspend;\n"    // 4
     " X=0;      suspend;\n"    // 5
     " X=NULL;   suspend;\n"    // 6
     " X=1;      suspend;\n"    // 7
     " X=1.5;    suspend;\n"    // 8
     " X=NULL;   suspend;\n"    // 9
     " X=99.9;   suspend;\n"    // 10
     " X=NULL;   suspend;\n"    // 11
    "end;";

 //-----------------------------------------
 struct tag_result
 {
  short                  sqlInd;
  db_obj::t_dbvalue__i4  sqlValue;
 }
  const results[]=
 {
  { 0,-999},  // 0
  {-1,0},     // 1
  { 0,-15},   // 2
  { 0,-10},   // 3
  {-1,0},     // 4
  { 0,0},     // 5
  {-1,0},     // 6
  { 0,10},    // 7
  { 0,15},    // 8
  {-1,0},     // 9
  { 0,999},   // 10
  {-1,0},     // 11
 };//results

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   c_SQL);

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 //-----------------------------------------
 for(size_t iRec=0,_cRecs=_DIM_(results);iRec!=_cRecs;++iRec)
 {
  tracer<<L"-------------------------------- "<<iRec<<send;

  svc::RemoteFB_Connector__StmtFetch_ToRow
   (spConnector,
    OpCtx,
    &hStmt,
    /*pOutXSQLDA*/xsqlda);

  svc::checkValue__I4
   (tracer,
    columnInd,
    columnValue,
    results[iRec].sqlInd,
    results[iRec].sqlValue);
 }//for iRec

 svc::RemoteFB_Connector__StmtFetch_ToEOF
  (spConnector,
   OpCtx,
   &hStmt,
   /*pOutXSQLDA*/xsqlda);

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
}//run

////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch__Types__decimal_001__D03_01

void WORK_StmtFetch__Types__decimal_001__D03_01::create
                             (TTSO_PushTest*      const pTestPusher,
                              TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 //-----------------------------------------
 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);    // 0

 //-----------------------------------------
 structure::str_formatter
  ftestID("RemoteFB.WORK.StmtFetch.Types.decimal.001.D3_1.ptype__%1");

 TTSO_TestData_v2 Data;

 //-----------------------------------------
 for(;it;++it)
 {
  Data.m_RemoteFB__ProtocolType=g_TestCfg__RemoteFB__ProtocolTypes[it[0]];

  ftestID
   <<structure::flush
   <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value());

  const tag_impl::self_ptr
   spTest
    (structure::not_null_ptr
      (new tag_impl
        (pParams,
         ftestID.c_str(),
         Data)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test