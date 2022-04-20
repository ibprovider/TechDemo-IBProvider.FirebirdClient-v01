////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/StmtFetch/WORK_StmtFetch_Test_10__rollback_retaining.h"
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
//struct WORK_StmtFetch_Test_10__rollback_retaining::tag_rs_descr

struct WORK_StmtFetch_Test_10__rollback_retaining::tag_rs_descr
{
 size_t cRows;
 size_t cFetch;
};//WORK_StmtFetch_Test_10__rollback_retaining::tag_rs_descr

////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_Test_10__rollback_retaining::tag_impl

class WORK_StmtFetch_Test_10__rollback_retaining::tag_impl
 :public structure::t_basic_smart_interface_impl__dynamic<TTSO_Test,TTSO_MemoryAllocator>
{
 private:
  typedef tag_impl                                     self_type;

  tag_impl(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~tag_impl();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>     self_ptr;

  typedef TTSO_MemoryAllocator                         allocator_type;
  typedef structure::t_stl_vector
           <tag_rs_descr,
            allocator_type>                            rs_descrs_type;

 public:
  const tag_rs_descr m_ResultSet;

 public:
  tag_impl(TTSO_GlobalContext*     pParams,
           const char*             pTestID,
           const TTSO_TestData_v2& Data,
           const tag_rs_descr&     ResultSet);

  //test interface -------------------------------------------------------
  virtual std::string get_id()const COMP_W000004_OVERRIDE_FINAL;

  virtual bool can_exec()const COMP_W000004_OVERRIDE_FINAL;

  virtual void run(context_type* pCtx)const COMP_W000004_OVERRIDE_FINAL;

 private:
  TTSO_GlobalContext::self_ptr const m_spParams;

  std::string const m_TestID;

  TTSO_TestData_v2 const m_Data;
};//class WORK_StmtFetch_Test_10__rollback_retaining::tag_impl

////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_Test_10__rollback_retaining::tag_impl

WORK_StmtFetch_Test_10__rollback_retaining::tag_impl::tag_impl
                                           (TTSO_GlobalContext* const pParams,
                                            const char*         const pTestID,
                                            const TTSO_TestData_v2&   Data,
                                            const tag_rs_descr&       ResultSet)
 :m_spParams(structure::not_null_ptr(pParams))
 ,m_TestID(structure::not_null_ptr(pTestID))
 ,m_Data(Data)
 ,m_ResultSet(ResultSet)
{
 assert(m_spParams);
 assert(m_ResultSet.cFetch<=m_ResultSet.cRows);
}//tag_impl

//------------------------------------------------------------------------
WORK_StmtFetch_Test_10__rollback_retaining::tag_impl::~tag_impl()
{;}

//test interface ---------------------------------------------------------
std::string WORK_StmtFetch_Test_10__rollback_retaining::tag_impl::get_id()const
{
 return m_TestID;
}//get_id

//------------------------------------------------------------------------
bool WORK_StmtFetch_Test_10__rollback_retaining::tag_impl::can_exec()const
{
 assert(m_spParams);

 if(!m_Data.can_exec(m_spParams))
  return false;

 return true;
}//can_exec

//------------------------------------------------------------------------
void WORK_StmtFetch_Test_10__rollback_retaining::tag_impl::run(context_type* const pCtx)const
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
 const char* const c_sql_templ
  ="execute block\n"
   "returns(X INTEGER)\n"
   "as\n"
   "begin\n"
     " X=0;\n"
     " while(X<%1)do begin suspend; X=X+1; end\n"
    "end;";

 structure::str_formatter fSQL(c_sql_templ);

 fSQL<<m_ResultSet.cRows;

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   fSQL.str());

 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   /*in*/nullptr,
   /*out*/nullptr);

 //-----------------------------------------
 size_t nFetch=0;

 for(;nFetch<m_ResultSet.cFetch;++nFetch)
 {
  svc::RemoteFB_Connector__StmtFetch_ToRow
   (spConnector,
    OpCtx,
    &hStmt,
    /*pOutXSQLDA*/xsqlda);

  _TSO_CHECK(hStmt);

  _TSO_CHECK_MSG(columnValue==nFetch,"columnValue="<<columnValue);

  _TSO_CHECK_MSG(columnInd==0,"columnInd="<<columnInd);
 }//for nFetch

 //-----------------------------------------
 svc::RemoteFB_Connector__RollbackRetaining
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr);
 _TSO_CHECK(hStmt->m_pParentTr==hTr);

 //-----------------------------------------
 for(;nFetch<m_ResultSet.cRows;++nFetch)
 {
  svc::RemoteFB_Connector__StmtFetch_ToRow
   (spConnector,
    OpCtx,
    &hStmt,
    /*pOutXSQLDA*/xsqlda);

  _TSO_CHECK(hStmt);

  _TSO_CHECK_MSG(columnValue==nFetch,"columnValue="<<columnValue);

  _TSO_CHECK_MSG(columnInd==0,"columnInd="<<columnInd);
 }//for nFetch

 //-----------------------------------------
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
//class WORK_StmtFetch_Test_10__rollback_retaining

void WORK_StmtFetch_Test_10__rollback_retaining::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 const tag_rs_descr dataS[]=
 {
  {0,0},
  {1,0},
  {1,1},
  {100000,0},
  {100000,1},
  {100000,50000},
  {100000,99999},
  {100000,100000},
 };//dataS

 //-----------------------------------------
 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(dataS)-1);                                 // 0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);    // 1

 //-----------------------------------------
 structure::str_formatter
  ftestID("RemoteFB.WORK.StmtFetch.10.rollback_retaining.ptype__%1.%2");

 TTSO_TestData_v2 Data;

 size_t testNum=0;

 for(;it;++it)
 {
  const auto& s=dataS[it[0]];

  Data.m_RemoteFB__ProtocolType=g_TestCfg__RemoteFB__ProtocolTypes[it[1]];

  ++testNum;

  ftestID<<structure::flush
         <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value())
         <<testNum;

  const tag_impl::self_ptr
   spTest
    (structure::not_null_ptr
      (new tag_impl
        (pParams,
         ftestID.c_str(),
         Data,
         s)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
