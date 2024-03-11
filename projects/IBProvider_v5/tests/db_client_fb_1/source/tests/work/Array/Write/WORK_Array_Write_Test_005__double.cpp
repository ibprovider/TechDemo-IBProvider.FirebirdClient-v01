////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/Array/Write/WORK_Array_Write_Test_005__double.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/isc_base/isc_api__array_sdl__writer_funcs.h"
#include "source/db_obj/isc_base/isc_api__op_data__writer_buffer__external.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Array_Write_Test_005__double::tag_impl

class WORK_Array_Write_Test_005__double::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 private:
  typedef db_obj::t_dbvalue__r8             element_type;

  static const isc_api::XSQLVAR_V1::sqltype_type
   c_element_sqltypeid=isc_api::ibp_isc_sql_double;

  static const short
   c_element_blrtypeid=isc_api::ibp_isc_blr_dtype__double;

 public:
  static void test_001
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_002__dim2l
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
};//class WORK_Array_Write_Test_005__double::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void WORK_Array_Write_Test_005__double::tag_impl::test_001
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

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 //----------------------------------------- Build SDL
 typedef isc_base::t_isc_api__op_data__writer_buffer__external   buf_type;
 typedef isc_base::t_isc_api__array_sdl__writer_funcs<buf_type>  writer_funcs;

 typedef buf_type::byte_type                                     byte_type;

 byte_type arraySDL[1024];

 buf_type buf(arraySDL,_DIM_(arraySDL));

 writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_version1);
 writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_struct);
 writer_funcs::stuff_byte_s(buf,/*std const*/1);

 {
  writer_funcs::stuff_byte_s(buf,c_element_blrtypeid);
 }

 writer_funcs::stuff_string(buf,
                            isc_api::ibp_isc_sdl_relation,
                            "TEST_ARRAY_DIM1");

 writer_funcs::stuff_string(buf,
                            isc_api::ibp_isc_sdl_field,
                            "COL_R8");

 //---- dimensions
 {
  writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_do2);
  writer_funcs::stuff_byte_s(buf,/*dimension index*/0);

  writer_funcs::stuff_literal(buf,0);  //lower bound
  writer_funcs::stuff_literal(buf,2);  //upper bound
 }

 //----
 writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_element);
 writer_funcs::stuff_byte_s(buf,1);
 writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_scalar);
 writer_funcs::stuff_byte_s(buf,0);
 writer_funcs::stuff_byte_s(buf,/*dimension count*/1);

 //---- dimension nums
 {
  writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_variable);
  writer_funcs::stuff_byte_s(buf,/*dim_idx*/0);
 }

 writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_eoc);

 //----------------------------------------- Build Array Slice Data
 const element_type arrayData[3]={SHRT_MIN,0,SHRT_MAX};

 //-----------------------------------------
 db_obj::DB_IBARRAYID arrayId={};

 svc::RemoteFB_Connector__PutArraySlice
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &arrayId,
   buf.get_size(),
   arraySDL,
   sizeof(arrayData),
   arrayData);

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "insert into TEST_ARRAY_DIM1 (COL_R8) values (?) returning TEST_ID;");

 //-----------------------------------------
 XSQLDA_V1_Wrapper inXSQLDA(1);

 inXSQLDA->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_array;
 inXSQLDA->sqlvar[0].sqlsubtype =0;
 inXSQLDA->sqlvar[0].sqlscale   =0;
 inXSQLDA->sqlvar[0].sqllen     =sizeof(arrayId);
 inXSQLDA->sqlvar[0].sqldata    =reinterpret_cast<char*>(&arrayId);
 inXSQLDA->sqlvar[0].sqlind     =nullptr;

 inXSQLDA->sqld=1;

 //-----------------------------------------
 db_obj::t_dbvalue__i8 testRecID=0;

 XSQLDA_V1_Wrapper outXSQLDA(1);

 outXSQLDA->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_int64;
 outXSQLDA->sqlvar[0].sqlsubtype =0;
 outXSQLDA->sqlvar[0].sqlscale   =0;
 outXSQLDA->sqlvar[0].sqllen     =sizeof(testRecID);
 outXSQLDA->sqlvar[0].sqldata    =reinterpret_cast<char*>(&testRecID);
 outXSQLDA->sqlvar[0].sqlind     =nullptr;

 outXSQLDA->sqld=1;

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   inXSQLDA,
   outXSQLDA);

 //----------------------------------------- теперь провер€ем значени€ элементов массива
 structure::str_formatter fSQL("select COL_R8[%%1] from TEST_ARRAY_DIM1 where TEST_ID=%1");

 fSQL<<testRecID<<structure::self_init;

 //-----------
 element_type elementValue=0;

 XSQLDA_V1_Wrapper fetchXSQLDA(1);

 fetchXSQLDA->sqlvar[0].sqltype    =c_element_sqltypeid;
 fetchXSQLDA->sqlvar[0].sqlsubtype =0;
 fetchXSQLDA->sqlvar[0].sqlscale   =0;
 fetchXSQLDA->sqlvar[0].sqllen     =sizeof(elementValue);
 fetchXSQLDA->sqlvar[0].sqldata    =reinterpret_cast<char*>(&elementValue);
 fetchXSQLDA->sqlvar[0].sqlind     =nullptr;

 fetchXSQLDA->sqld=1;

 for(size_t iElement=0;iElement!=_DIM_(arrayData);++iElement)
 {
  tracer<<L"---------------------------- check element ["<<iElement<<L"]"<<send;

  fSQL<<structure::flush
      <<iElement;

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

  svc::RemoteFB_Connector__StmtFetch_ToRow
   (spConnector,
    OpCtx,
    &hStmt,
    fetchXSQLDA);

  _TSO_CHECK(elementValue==arrayData[iElement]);

  svc::RemoteFB_Connector__StmtFetch_ToEOF
   (spConnector,
    OpCtx,
    &hStmt,
    fetchXSQLDA);

  svc::RemoteFB_Connector__StmtClose
   (tracer,
    spConnector,
    &hStmt);
 }//for iElement

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_001

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void WORK_Array_Write_Test_005__double::tag_impl::test_002__dim2l
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

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 //----------------------------------------- Build SDL
 typedef isc_base::t_isc_api__op_data__writer_buffer__external   buf_type;
 typedef isc_base::t_isc_api__array_sdl__writer_funcs<buf_type>  writer_funcs;

 typedef buf_type::byte_type                                     byte_type;

 byte_type arraySDL[1024];

 buf_type buf(arraySDL,_DIM_(arraySDL));

 writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_version1);
 writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_struct);
 writer_funcs::stuff_byte_s(buf,/*std const*/1);

 {
  writer_funcs::stuff_byte_s(buf,c_element_blrtypeid);
 }

 writer_funcs::stuff_string(buf,
                            isc_api::ibp_isc_sdl_relation,
                            "TEST_ARRAY_DIM2L");

 writer_funcs::stuff_string(buf,
                            isc_api::ibp_isc_sdl_field,
                            "COL_R8");

 //---- dimensions
 {
  writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_do2);
  writer_funcs::stuff_byte_s(buf,/*dimension index*/1);

  writer_funcs::stuff_literal(buf,0);  //lower bound
  writer_funcs::stuff_literal(buf,3);  //upper bound
 }

 {
  writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_do2);
  writer_funcs::stuff_byte_s(buf,/*dimension index*/0);

  writer_funcs::stuff_literal(buf,-32768);  //lower bound
  writer_funcs::stuff_literal(buf,32767);   //upper bound
 }

 //----
 writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_element);
 writer_funcs::stuff_byte_s(buf,1);
 writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_scalar);
 writer_funcs::stuff_byte_s(buf,0);
 writer_funcs::stuff_byte_s(buf,/*dimension count*/2);

 //---- dimension nums
 {
  writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_variable);
  writer_funcs::stuff_byte_s(buf,/*dim_idx*/0);
 }

 {
  writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_variable);
  writer_funcs::stuff_byte_s(buf,/*dim_idx*/1);
 }

 writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_sdl_eoc);

 //----------------------------------------- Build Array Slice Data
 const size_t nTotalCount=(32767L-(-32768L)+1)*4;

 structure::t_typed_simple_buffer<element_type,TTSO_MemoryAllocator>
  arrayData(nTotalCount);

 {
  element_type v(123);

  for(size_t i=0;i!=nTotalCount;++i,++v)
   arrayData[i]=v;
 }

 //-----------------------------------------
 db_obj::DB_IBARRAYID arrayId={};

 svc::RemoteFB_Connector__PutArraySlice
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &arrayId,
   buf.get_size(),
   arraySDL,
   arrayData.memory_size(),
   arrayData.buffer());

 //-----------------------------------------
 svc::remote_fb_stmt_handle_type hStmt(nullptr);

 svc::RemoteFB_Connector__StmtAllocate
  (tracer,
   spConnector,
   &hStmt);

 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   "insert into TEST_ARRAY_DIM2L (COL_R8) values (?) returning TEST_ID;");

 //-----------------------------------------
 XSQLDA_V1_Wrapper inXSQLDA(1);

 inXSQLDA->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_array;
 inXSQLDA->sqlvar[0].sqlsubtype =0;
 inXSQLDA->sqlvar[0].sqlscale   =0;
 inXSQLDA->sqlvar[0].sqllen     =sizeof(arrayId);
 inXSQLDA->sqlvar[0].sqldata    =reinterpret_cast<char*>(&arrayId);
 inXSQLDA->sqlvar[0].sqlind     =nullptr;

 inXSQLDA->sqld=1;

 //-----------------------------------------
 db_obj::t_dbvalue__i8 testRecID=0;

 XSQLDA_V1_Wrapper outXSQLDA(1);

 outXSQLDA->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_int64;
 outXSQLDA->sqlvar[0].sqlsubtype =0;
 outXSQLDA->sqlvar[0].sqlscale   =0;
 outXSQLDA->sqlvar[0].sqllen     =sizeof(testRecID);
 outXSQLDA->sqlvar[0].sqldata    =reinterpret_cast<char*>(&testRecID);
 outXSQLDA->sqlvar[0].sqlind     =nullptr;

 outXSQLDA->sqld=1;

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtExecute
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   inXSQLDA,
   outXSQLDA);

 tracer<<L"testRecID: "<<testRecID<<send;

 //----------------------------------------- теперь провер€ем значени€ элементов массива
 structure::str_formatter fSQL("select COL_R8[%%1,%%2] from TEST_ARRAY_DIM2L where TEST_ID=%1");

 fSQL<<testRecID<<structure::self_init;

 //-----------
 element_type elementValue=0;

 XSQLDA_V1_Wrapper fetchXSQLDA(1);

 fetchXSQLDA->sqlvar[0].sqltype    =c_element_sqltypeid;
 fetchXSQLDA->sqlvar[0].sqlsubtype =0;
 fetchXSQLDA->sqlvar[0].sqlscale   =0;
 fetchXSQLDA->sqlvar[0].sqllen     =sizeof(elementValue);
 fetchXSQLDA->sqlvar[0].sqldata    =reinterpret_cast<char*>(&elementValue);
 fetchXSQLDA->sqlvar[0].sqlind     =nullptr;

 fetchXSQLDA->sqld=1;

 //-----------
 typedef structure::t_dimension_iterator<long,TTSO_MemoryAllocator> it_type;

 it_type it;

 it.add(-32768,32767);
 it.add(0,3);

 //-----------
 for(size_t iElement=0;;++iElement,++it)
 {
  if(iElement==nTotalCount)
  {
   _TSO_CHECK(!it);

   break;
  }

  _TSO_CHECK(it);

  fSQL<<structure::flush
      <<it[0]
      <<it[1];

  unsigned long iscStmtTypeID=0;

  spConnector->StmtPrepare
   (OpCtx,
    &hTr,
    &hStmt,
    static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
    fSQL.str(),
    &iscStmtTypeID);

  spConnector->StmtExecute
   (OpCtx,
    &hTr,
    &hStmt,
    /*in*/nullptr,
    /*out*/nullptr);

  svc::RemoteFB_Connector__StmtFetch_ToRow
   (spConnector,
    OpCtx,
    &hStmt,
    fetchXSQLDA);

  if(elementValue!=arrayData[iElement])
  {
   tracer(tso_msg_error,-1)
    <<L"Incorrect value of ["<<it[0]<<L","<<it[1]<<L"] element [index:"<<iElement<<L"].\n"
    <<L"Expected: "<<arrayData[iElement]<<L"\n"
    <<L"Obtained: "<<elementValue
    <<send;

    break;
  }//if

  svc::RemoteFB_Connector__StmtFetch_ToEOF
   (spConnector,
    OpCtx,
    &hStmt,
    fetchXSQLDA);

  spConnector->StmtClose(&hStmt);
 }//for iElement

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_002__dim2l

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Array_Write_Test_005__double::tag_descr

struct WORK_Array_Write_Test_005__double::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class WORK_Array_Write_Test_005__double::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,WORK_Array_Write_Test_005__double::tag_impl::func},

const WORK_Array_Write_Test_005__double::tag_descr
 WORK_Array_Write_Test_005__double::sm_Tests[]=
{
 DEF_TEST_DESCR("001",
                test_001)
 DEF_TEST_DESCR("002.dim2l",
                test_002__dim2l)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class WORK_Array_Write_Test_005__double

void WORK_Array_Write_Test_005__double::create(TTSO_PushTest*      const pTestPusher,
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
 structure::str_formatter ftestID("RemoteFB.WORK.Array.Write.005.double.ptype__%1.%2");

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
    (lib::structure::not_null_ptr
      (new TTSO_TestFunc_v2
        (pParams,
         ftestID.c_str(),
         sm_Tests[it[iTest]].Func,
         Data)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
