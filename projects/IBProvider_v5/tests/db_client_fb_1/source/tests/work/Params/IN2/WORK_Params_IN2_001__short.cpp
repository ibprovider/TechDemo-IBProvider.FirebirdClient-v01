////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/Params/IN2/WORK_Params_IN2_001__short.h"
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
//class WORK_Params_IN2_001__short::tag_impl

class WORK_Params_IN2_001__short::tag_impl
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

 public:
  typedef unsigned char                     byte_type;

  typedef db_obj::t_dbvalue__i2             xvalue_type;

  static const short c_xvalue_typeID=isc_api::ibp_isc_sql_short;

  static const short c_xvalue_sqllen=sizeof(xvalue_type);

 public:
  struct tag_guard_block
  {
   private:
    typedef tag_guard_block self_type;

   public:
    byte_type     data[16*sizeof(size_t)];

   public:
    bool operator == (const self_type& x)const
    {
     return memcmp(this->data,x.data,sizeof(this->data))==0;
    }
  };//struct tag_guard_block

  struct tag_data_block
  {
   private:
    typedef tag_data_block self_type;

   public:
    tag_guard_block  guard1_1;
    xvalue_type      value1;
    tag_guard_block  guard1_2;
    short            sqlind1;
    tag_guard_block  guard2_1;
    xvalue_type      value2;
    tag_guard_block  guard2_2;
    short            sqlind2;
    tag_guard_block  guard3;

   public:
    void check(const self_type& x)const;
  };//struct tag_data_block
};//class WORK_Params_IN2_001__short::tag_impl

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Params_IN2_001__short::tag_data_block

void WORK_Params_IN2_001__short::tag_impl::tag_data_block::check(const self_type& x)const
{
 _TSO_CHECK(this->guard1_1 == x.guard1_1);
 _TSO_CHECK(this->value1   == x.value1);
 _TSO_CHECK(this->guard1_2 == x.guard1_2);
 _TSO_CHECK(this->sqlind1  == x.sqlind1);
 _TSO_CHECK(this->guard2_1 == x.guard2_1);
 _TSO_CHECK(this->value2   == x.value2);
 _TSO_CHECK(this->guard2_2 == x.guard2_2);
 _TSO_CHECK(this->sqlind2  == x.sqlind2);
 _TSO_CHECK(this->guard3   == x.guard3);

 _TSO_CHECK(memcmp(this,&x,sizeof(x))==0);
}//check

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void WORK_Params_IN2_001__short::tag_impl::test_001
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
   "execute block (IN1 SMALLINT=?, IN2 SMALLINT=?)\n"
   "returns (OUT1 smallint, OUT2 smallint)\n"
   "as\n"
   "BEGIN\n"
   " OUT1=IN1;\n"
   " OUT2=IN2;\n"
   " SUSPEND;\n"
   "END");

 _TSO_CHECK(hStmt);
 _TSO_CHECK(hStmt->m_ID.has_value());

 remote_fb::handles::RemoteFB__TrHandle   hTrCopy(hTr);
 remote_fb::handles::RemoteFB__StmtHandle hStmtCopy(hStmt);

 //-----------------------------------------
 XSQLDA_V1_Wrapper in_xsqlda(2);

 in_xsqlda->sqld=2;

 tag_data_block in_data_block;

 in_xsqlda->sqlvar[0].sqltype  =c_xvalue_typeID|1;
 in_xsqlda->sqlvar[0].sqllen   =c_xvalue_sqllen;
 in_xsqlda->sqlvar[0].sqlscale =0;
 in_xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(&in_data_block.value1);
 in_xsqlda->sqlvar[0].sqlind   =&in_data_block.sqlind1;

 in_xsqlda->sqlvar[1].sqltype  =c_xvalue_typeID|1;
 in_xsqlda->sqlvar[1].sqllen   =c_xvalue_sqllen;
 in_xsqlda->sqlvar[1].sqlscale =0;
 in_xsqlda->sqlvar[1].sqldata  =reinterpret_cast<char*>(&in_data_block.value2);
 in_xsqlda->sqlvar[1].sqlind   =&in_data_block.sqlind2;

 //-----------------------------------------
 XSQLDA_V1_Wrapper out_xsqlda(2);

 out_xsqlda->sqld=2;

 tag_data_block out_data_block;

 out_xsqlda->sqlvar[0].sqltype  =c_xvalue_typeID|1;
 out_xsqlda->sqlvar[0].sqllen   =c_xvalue_sqllen;
 out_xsqlda->sqlvar[0].sqlscale =0;
 out_xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(&out_data_block.value1);
 out_xsqlda->sqlvar[0].sqlind   =&out_data_block.sqlind1;

 out_xsqlda->sqlvar[1].sqltype  =c_xvalue_typeID|1;
 out_xsqlda->sqlvar[1].sqllen   =c_xvalue_sqllen;
 out_xsqlda->sqlvar[1].sqlscale =0;
 out_xsqlda->sqlvar[1].sqldata  =reinterpret_cast<char*>(&out_data_block.value2);
 out_xsqlda->sqlvar[1].sqlind   =&out_data_block.sqlind2;

 {
  const byte_type c_guard_byte=0xAB;

  //----------------------------------------
  memset(&in_data_block,c_guard_byte,sizeof(in_data_block));

  in_data_block.value1 =15;
  in_data_block.sqlind1=0;

  in_data_block.value2 =73;
  in_data_block.sqlind2=0;

  const tag_data_block in_data_block__copy(in_data_block);

  //----------------------------------------
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

  in_data_block.check(in_data_block__copy);

  //-----------------------------------------
  memset(&out_data_block,c_guard_byte,sizeof(out_data_block));

  svc::RemoteFB_Connector__StmtFetch_ToRow
   (tracer,
    spConnector,
    OpCtx,
    &hStmt,
    out_xsqlda);

  _TSO_CHECK(hTr==hTrCopy);
  _TSO_CHECK(hTr->m_ID.has_value());

  _TSO_CHECK(hStmt==hStmtCopy);
  _TSO_CHECK(hStmt->m_ID.has_value());

  out_data_block.check(in_data_block__copy);

  //-----------------------------------------
  memset(&out_data_block,c_guard_byte,sizeof(out_data_block));

  const auto out_data_block__copy=out_data_block;

  svc::RemoteFB_Connector__StmtFetch_ToEOF
   (tracer,
    spConnector,
    OpCtx,
    &hStmt,
    out_xsqlda);

  _TSO_CHECK(hTr==hTrCopy);
  _TSO_CHECK(hTr->m_ID.has_value());

  _TSO_CHECK(hStmt==hStmtCopy);
  _TSO_CHECK(hStmt->m_ID.has_value());

  out_data_block.check(out_data_block__copy);

  //----------------------------------------
  svc::RemoteFB_Connector__StmtClose
   (tracer,
    spConnector,
    &hStmt);
 }//local

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
//struct WORK_Params_IN2_001__short::tag_descr

struct WORK_Params_IN2_001__short::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class WORK_Params_IN2_001__short::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,WORK_Params_IN2_001__short::tag_impl::func},

const WORK_Params_IN2_001__short::tag_descr
 WORK_Params_IN2_001__short::sm_Tests[]=
{
 DEF_TEST_DESCR("001",
                test_001)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class WORK_Params_IN2_001__short

void WORK_Params_IN2_001__short::create(TTSO_PushTest*      const pTestPusher,
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
 structure::str_formatter ftestID("RemoteFB.WORK.Params.IN2.001.short.ptype__%1.%2");

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

  const TTSO_TestPtr spTest(new TTSO_TestFunc_v2(pParams,
                                                 ftestID.c_str(),
                                                 sm_Tests[it[iTest]].Func,
                                                 Data));
  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
