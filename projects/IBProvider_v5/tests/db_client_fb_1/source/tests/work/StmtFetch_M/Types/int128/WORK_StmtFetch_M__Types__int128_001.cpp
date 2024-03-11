////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/StmtFetch_M/Types/int128/WORK_StmtFetch_M__Types__int128_001.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/db_client/remote_fb/remote_fb__msg_v1.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

#include <array>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__Types__int128_001::tag_impl

class WORK_StmtFetch_M__Types__int128_001::tag_impl LCPI_CPP_CFG__CLASS__FINAL
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
  tag_impl(TTSO_GlobalContext*     pParams,
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
};//class WORK_StmtFetch_M__Types__int128_001::tag_impl

////////////////////////////////////////////////////////////////////////////////
//class WORK_StmtFetch_M__Types__int128_001::tag_impl

WORK_StmtFetch_M__Types__int128_001::tag_impl::tag_impl(TTSO_GlobalContext* const pParams,
                                            const char*         const pTestID,
                                            const TTSO_TestData_v2&   Data)
 :m_spParams(lib::structure::not_null_ptr(pParams))
 ,m_TestID(lib::structure::not_null_ptr(pTestID))
 ,m_Data(Data)
{
 assert(m_spParams);
}//tag_impl

//------------------------------------------------------------------------
WORK_StmtFetch_M__Types__int128_001::tag_impl::~tag_impl()
{;}

//test interface ---------------------------------------------------------
std::string WORK_StmtFetch_M__Types__int128_001::tag_impl::get_id()const
{
 return m_TestID;
}//get_id

//------------------------------------------------------------------------
bool WORK_StmtFetch_M__Types__int128_001::tag_impl::can_exec()const
{
 assert(m_spParams);

 if(!m_Data.can_exec(m_spParams))
  return false;

 if(!m_spParams->calc_expression("NE__INT128"))
  return false;

 return true;
}//can_exec

//------------------------------------------------------------------------
void WORK_StmtFetch_M__Types__int128_001::tag_impl::run(context_type* const pCtx)const
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
 // XSQLDA_V1_Wrapper xsqlda(/*n*/1);

 isc_api::t_ibp_fb040_int128 columnValue=db_obj::make_fb040_int128(0,0);
 short                       columnInd=0;

 //xsqlda->sqlvar[0].sqllen     =sizeof(columnValue);
 //xsqlda->sqlvar[0].sqltype    =isc_api::ibp_fb040_sql_int128|1;
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
  /*  6 */ isc_api::ibp_fb040_blr_dtype__int128,  // data type
  /*  7 */ 0,                                     // data scale
  /*  8 */ isc_api::ibp_isc_blr_dtype__short,     // indicator type
  /*  9 */ 0,                                     // indicator scale
  /* 10 */ isc_api::ibp_isc_blr_end,
  /* 11 */ isc_api::ibp_isc_blr_eoc,
 };//OutMsg__BLR

 //-----------------------------------------
 structure::t_stl_vector<unsigned char,TTSO_MemoryAllocator> OutMsg__DATA=
 {
  //---- value [int128]
  0xAF, // 1
  0xAF, // 2
  0xAF, // 3
  0xAF, // 4
  0xAF, // 5
  0xAF, // 6
  0xAF, // 7
  0xAF, // 8
  0xAF, // 9
  0xAF, // 0
  0xAF, // 1
  0xAF, // 2
  0xAF, // 3
  0xAF, // 4
  0xAF, // 5
  0xAF, // 6
  //---- indicator [short]
  0xFE,
  0xFE,
 };//OutMsg__DATA

 //-----------------------------------------
 std::array<svc::remote_fb_in_msg_v1::descr_type,1> OutMsg__DATA_DESCRS;

 OutMsg__DATA_DESCRS[0].m_msg_blrtype            =isc_api::ibp_fb040_blr_dtype__int128;
 OutMsg__DATA_DESCRS[0].m_xvar_sqltype           =isc_api::ibp_fb040_sql_int128;
 OutMsg__DATA_DESCRS[0].m_xvar_sqlscale          =0;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_size   =16;
 OutMsg__DATA_DESCRS[0].m_msg_value_block_offset =0;
 OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset      =16;

 //-----------------------------------------
 svc::remote_fb_out_msg_v1 OutMsg;

 OutMsg.blr        =OutMsg__BLR;
 OutMsg.data       =OutMsg__DATA;
 OutMsg.descrs     =OutMsg__DATA_DESCRS;
 OutMsg.data_align =8;

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 //----------------------------------------
 const char* const c_SQL
  ="execute block\n"
   "returns(X INT128)\n"
   "as\n"
   "begin\n"
     " X=-1;                                       suspend;\n"    // 0
     " X=NULL;                                     suspend;\n"    // 1
     " X=0;                                        suspend;\n"    // 2
     " X=1;                                        suspend;\n"    // 3
     " X=-170141183460469231731687303715884105728; suspend;\n"    // 4
     " X=NULL;                                     suspend;\n"    // 5
     " X=170141183460469231731687303715884105727;  suspend;\n"    // 6
    "end;";

 //-----------------------------------------
 struct tag_result
 {
  short                        sqlInd;
  isc_api::t_ibp_fb040_int128  sqlValue;
 }
  const results[]=
 {
  { 0,db_obj::make_fb040_int128(_UI64_MAX,_UI64_MAX)}, // 0
  {-1,db_obj::make_fb040_int128(0,0)},                 // 1
  { 0,db_obj::make_fb040_int128(0,0)},                 // 2
  { 0,db_obj::make_fb040_int128(1,0)},                 // 3
  { 0,db_obj::make_fb040_int128(0,1ui64<<63)},         // 4
  {-1,db_obj::make_fb040_int128(0,0)},                 // 5
  { 0,db_obj::make_fb040_int128(_UI64_MAX,_I64_MAX)},  // 6
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

  svc::RemoteFB_Connector__StmtFetch_M_ToRow
   (spConnector,
    OpCtx,
    &hStmt,
    &OutMsg);

  //----------------------------------------
  assert_s(sizeof(columnValue)==16);

  memcpy(&columnValue,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_value_block_offset],sizeof(columnValue));

  //---------
  assert_s(sizeof(columnInd)==2);

  memcpy(&columnInd,&OutMsg__DATA[OutMsg__DATA_DESCRS[0].m_msg_sqlind_offset],sizeof(columnInd));

  //---------
  svc::checkValue__INT128
   (tracer,
    columnInd,
    columnValue,
    results[iRec].sqlInd,
    results[iRec].sqlValue);
 }//for iRec

 svc::RemoteFB_Connector__StmtFetch_M_ToEOF
  (spConnector,
   OpCtx,
   &hStmt,
   &OutMsg);

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
//class WORK_StmtFetch_M__Types__int128_001

void WORK_StmtFetch_M__Types__int128_001::create
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
  ftestID("RemoteFB.WORK.StmtFetch_M.Types.int128.001.ptype__%1");

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
    (lib::structure::not_null_ptr
      (new tag_impl
        (pParams,
         ftestID.c_str(),
         Data)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
