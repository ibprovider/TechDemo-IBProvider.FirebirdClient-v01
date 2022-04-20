////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/Fields/time/WORK_Fields__time_001.h"
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
//class WORK_Fields__time_001::tag_impl

class WORK_Fields__time_001::tag_impl
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
  virtual std::string get_id()const COMP_W000004_OVERRIDE_FINAL;

  virtual bool can_exec()const COMP_W000004_OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const COMP_W000004_OVERRIDE_FINAL;

 private:
  TTSO_GlobalContext::self_ptr const m_spParams;

  std::string const m_TestID;

  TTSO_TestData_v2 const m_Data;
};//class WORK_Fields__time_001::tag_impl

////////////////////////////////////////////////////////////////////////////////
//class WORK_Fields__time_001::tag_impl

WORK_Fields__time_001::tag_impl::tag_impl(TTSO_GlobalContext* const pParams,
                                          const char*         const pTestID,
                                          const TTSO_TestData_v2&   Data)
 :m_spParams(structure::not_null_ptr(pParams))
 ,m_TestID(structure::not_null_ptr(pTestID))
 ,m_Data(Data)
{
 assert(m_spParams);
}//tag_impl

//------------------------------------------------------------------------
WORK_Fields__time_001::tag_impl::~tag_impl()
{;}

//test interface ---------------------------------------------------------
std::string WORK_Fields__time_001::tag_impl::get_id()const
{
 return m_TestID;
}//get_id

//------------------------------------------------------------------------
bool WORK_Fields__time_001::tag_impl::can_exec()const
{
 assert(m_spParams);

 if(!m_Data.can_exec(m_spParams))
  return false;

 return true;
}//can_exec

//------------------------------------------------------------------------
void WORK_Fields__time_001::tag_impl::run(context_type* const pCtx)const
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

 isc_api::t_ibp_isc_time columnValue=0;
 short                   columnInd=0;

 xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
 xsqlda->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_type_time|1;
 xsqlda->sqlvar[0].sqlsubtype =0;
 xsqlda->sqlvar[0].sqlscale   =0;
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
   "returns(X TIME)\n"
   "as\n"
   "begin\n"
     " X='05:06:07.1234';  suspend;\n"    // 0
     " X=NULL;             suspend;\n"    // 1
     " X='00:00:00.0001';  suspend;\n"    // 2
     " X=NULL;             suspend;\n"    // 3
     " X='00:00:00.0000';  suspend;\n"    // 4
     " X=NULL;             suspend;\n"    // 5
     " X='23:59:59.9999';  suspend;\n"    // 6
     " X=NULL;             suspend;\n"    // 7
    "end;";

 //-----------------------------------------
 isc_api::t_ibp_isc_time  c_m_sec=10000;
 isc_api::t_ibp_isc_time  c_m_min=60*c_m_sec;
 isc_api::t_ibp_isc_time  c_m_hour=60*c_m_min;

 //-----------------------------------------
 struct tag_result
 {
  short                    sqlInd;
  isc_api::t_ibp_isc_time  sqlValue;
 }
  const results[]=
 {
  { 0,5*c_m_hour+6*c_m_min+7*c_m_sec+1234},     // 0
  {-1,0},                                       // 1
  { 0,1},                                       // 2
  {-1,0},                                       // 3
  { 0,0},                                       // 4
  {-1,0},                                       // 5
  { 0,23*c_m_hour+59*c_m_min+59*c_m_sec+9999},  // 6
  {-1,0},                                       // 7
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

  svc::checkValue__TIME
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
//class WORK_Fields__time_001

void WORK_Fields__time_001::create(TTSO_PushTest*      const pTestPusher,
                                   TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 //-----------------------------------------
 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);    // 0

 //-----------------------------------------
 structure::str_formatter
  ftestID("RemoteFB.WORK.Fields.time.001.ptype__%1");

 TTSO_TestData_v2 Data;

 //-----------------------------------------
 for(;it;++it)
 {
  Data.m_RemoteFB__ProtocolType=g_TestCfg__RemoteFB__ProtocolTypes[it[0]];

  ftestID<<structure::flush
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
