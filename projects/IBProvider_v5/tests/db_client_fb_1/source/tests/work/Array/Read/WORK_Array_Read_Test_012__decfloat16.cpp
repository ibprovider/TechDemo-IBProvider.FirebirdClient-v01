////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/Array/Read/WORK_Array_Read_Test_012__decfloat16.h"
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
//class WORK_Array_Read_Test_012__decfloat16::tag_impl

class WORK_Array_Read_Test_012__decfloat16::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 private:
  typedef db_obj::t_dbvalue__fb040_decfloat16   element_type;

  static const short
   c_element_blrtypeid=isc_api::ibp_fb040_blr_dtype__decfloat16;

 public:
  static void test_001
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_002__dim2l
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
};//class WORK_Array_Read_Test_012__decfloat16::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void WORK_Array_Read_Test_012__decfloat16::tag_impl::test_001
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

 buf_type bufSDL(arraySDL,_DIM_(arraySDL));

 writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_version1);
 writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_struct);
 writer_funcs::stuff_byte_s(bufSDL,/*std const*/1);

 {
  writer_funcs::stuff_byte_s(bufSDL,c_element_blrtypeid);
 }

 writer_funcs::stuff_string(bufSDL,
                            isc_api::ibp_isc_sdl_relation,
                            "TEST_ARRAY_DIM1");

 writer_funcs::stuff_string(bufSDL,
                            isc_api::ibp_isc_sdl_field,
                            "COL_DECFLOAT16");

 //---- dimensions
 {
  writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_do2);
  writer_funcs::stuff_byte_s(bufSDL,/*dimension index*/0);

  writer_funcs::stuff_literal(bufSDL,0);  //lower bound
  writer_funcs::stuff_literal(bufSDL,2);  //upper bound
 }

 //----
 writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_element);
 writer_funcs::stuff_byte_s(bufSDL,1);
 writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_scalar);
 writer_funcs::stuff_byte_s(bufSDL,0);
 writer_funcs::stuff_byte_s(bufSDL,/*dimension count*/1);

 //---- dimension nums
 {
  writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_variable);
  writer_funcs::stuff_byte_s(bufSDL,/*dim_idx*/0);
 }

 writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_eoc);

 //----------------------------------------- Build Array Slice Data
 const element_type arrayData[3]=
  {
   db_obj::make_fb040_decfloat16(9079256848778919936), // sNaN
   db_obj::make_fb040_decfloat16(2465720795985346561), // 1
   db_obj::make_fb040_decfloat16(2465720795985346560), // 0
  };

 //-----------------------------------------
 db_obj::DB_IBARRAYID arrayId={};

 svc::RemoteFB_Connector__PutArraySlice
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &arrayId,
   bufSDL.get_size(),
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
   "insert into TEST_ARRAY_DIM1 (COL_DECFLOAT16) values (?) returning TEST_ID;");

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

 tracer<<L"restRecID: "<<testRecID<<send;

 svc::RemoteFB_Connector__CommitRetaining
  (tracer,
   spConnector,
   &hTr);

 //----------------------------------------- теперь провер€ем значени€ элементов массива
 structure::str_formatter fSQL("select COL_DECFLOAT16 from TEST_ARRAY_DIM1 where TEST_ID=%1");

 fSQL<<testRecID<<structure::self_init;

 //-----------
 db_obj::DB_IBARRAYID arrayID2={};

 XSQLDA_V1_Wrapper fetchXSQLDA(1);

 fetchXSQLDA->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_array;
 fetchXSQLDA->sqlvar[0].sqlsubtype =0;
 fetchXSQLDA->sqlvar[0].sqlscale   =0;
 fetchXSQLDA->sqlvar[0].sqllen     =sizeof(arrayID2);
 fetchXSQLDA->sqlvar[0].sqldata    =reinterpret_cast<char*>(&arrayID2);
 fetchXSQLDA->sqlvar[0].sqlind     =nullptr;

 fetchXSQLDA->sqld=1;

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   fSQL.c_str());

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

 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------------------------------------
 element_type arrayData2[_DIM_(arrayData)];

 svc::RemoteFB_Connector__GetArraySlice
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   arrayID2,
   bufSDL.get_size(),
   arraySDL,
   sizeof(arrayData),
   arrayData2);

 for(size_t iElement=0;iElement!=_DIM_(arrayData);++iElement)
 {
  tracer<<L"---------------------------- check element ["<<iElement<<L"]"<<send;

  _TSO_CHECK(arrayData2[iElement]==arrayData[iElement]);
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

void WORK_Array_Read_Test_012__decfloat16::tag_impl::test_002__dim2l
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

 buf_type bufSDL(arraySDL,_DIM_(arraySDL));

 writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_version1);
 writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_struct);
 writer_funcs::stuff_byte_s(bufSDL,/*std const*/1);

 {
  writer_funcs::stuff_byte_s(bufSDL,c_element_blrtypeid);
 }

 writer_funcs::stuff_string(bufSDL,
                            isc_api::ibp_isc_sdl_relation,
                            "TEST_ARRAY_DIM2L");

 writer_funcs::stuff_string(bufSDL,
                            isc_api::ibp_isc_sdl_field,
                            "COL_DECFLOAT16");

 //---- dimensions
 {
  writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_do2);
  writer_funcs::stuff_byte_s(bufSDL,/*dimension index*/1);

  writer_funcs::stuff_literal(bufSDL,0);  //lower bound
  writer_funcs::stuff_literal(bufSDL,3);  //upper bound
 }

 {
  writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_do2);
  writer_funcs::stuff_byte_s(bufSDL,/*dimension index*/0);

  writer_funcs::stuff_literal(bufSDL,-32768);  //lower bound
  writer_funcs::stuff_literal(bufSDL,32767);   //upper bound
 }

 //----
 writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_element);
 writer_funcs::stuff_byte_s(bufSDL,1);
 writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_scalar);
 writer_funcs::stuff_byte_s(bufSDL,0);
 writer_funcs::stuff_byte_s(bufSDL,/*dimension count*/2);

 //---- dimension nums
 {
  writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_variable);
  writer_funcs::stuff_byte_s(bufSDL,/*dim_idx*/0);
 }

 {
  writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_variable);
  writer_funcs::stuff_byte_s(bufSDL,/*dim_idx*/1);
 }

 writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_sdl_eoc);

 //----------------------------------------- Build Array Slice Data
 const size_t nTotalCount=(32767L-(-32768L)+1)*4;

 structure::t_typed_simple_buffer<element_type,TTSO_MemoryAllocator>
  arrayData(nTotalCount);

 {
  element_type v=db_obj::make_fb040_decfloat16(2465720795985346560); // "0"

  for(size_t i=0;i!=nTotalCount;++i,++v.value)
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
   bufSDL.get_size(),
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
   "insert into TEST_ARRAY_DIM2L (COL_DECFLOAT16) values (?) returning TEST_ID;");

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

 tracer<<L"restRecID: "<<testRecID<<send;

 svc::RemoteFB_Connector__CommitRetaining
  (tracer,
   spConnector,
   &hTr);

 //----------------------------------------- теперь провер€ем значени€ элементов массива
 structure::str_formatter fSQL("select COL_DECFLOAT16 from TEST_ARRAY_DIM2L where TEST_ID=%1");

 fSQL<<testRecID<<structure::self_init;

 //-----------
 db_obj::DB_IBARRAYID arrayID2={};

 XSQLDA_V1_Wrapper fetchXSQLDA(1);

 fetchXSQLDA->sqlvar[0].sqltype    =isc_api::ibp_isc_sql_array;
 fetchXSQLDA->sqlvar[0].sqlsubtype =0;
 fetchXSQLDA->sqlvar[0].sqlscale   =0;
 fetchXSQLDA->sqlvar[0].sqllen     =sizeof(arrayID2);
 fetchXSQLDA->sqlvar[0].sqldata    =reinterpret_cast<char*>(&arrayID2);
 fetchXSQLDA->sqlvar[0].sqlind     =nullptr;

 fetchXSQLDA->sqld=1;

 //-----------------------------------------
 svc::RemoteFB_Connector__StmtPrepare
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   &hStmt,
   static_cast<remote_fb::protocol::P_USHORT>(cns.db_dialect_Ex.value()),
   fSQL.c_str());

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

 svc::RemoteFB_Connector__StmtDrop
  (tracer,
   spConnector,
   &hStmt);

 //-----------
 structure::t_typed_simple_buffer<element_type,TTSO_MemoryAllocator>
  arrayData2(nTotalCount);

 svc::RemoteFB_Connector__GetArraySlice
  (tracer,
   spConnector,
   OpCtx,
   &hTr,
   arrayID2,
   bufSDL.get_size(),
   arraySDL,
   arrayData2.memory_size(),
   arrayData2.buffer());

 //-----------
 for(size_t iElement=0;iElement!=nTotalCount;++iElement)
 {
  _TSO_CHECK(arrayData2[iElement]==arrayData[iElement]);
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
//struct WORK_Array_Read_Test_012__decfloat16::tag_descr

struct WORK_Array_Read_Test_012__decfloat16::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class WORK_Array_Read_Test_012__decfloat16::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,WORK_Array_Read_Test_012__decfloat16::tag_impl::func},

const WORK_Array_Read_Test_012__decfloat16::tag_descr
 WORK_Array_Read_Test_012__decfloat16::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001",
   test_001)

 DEF_TEST_DESCR
  ("002.dim2l",
   test_002__dim2l)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class WORK_Array_Read_Test_012__decfloat16

void WORK_Array_Read_Test_012__decfloat16::create
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
 structure::str_formatter ftestID("RemoteFB.WORK.Array.Read.012.decfloat16.ptype__%1.%2");

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
    (lib::structure::not_null_ptr
      (new TTSO_TestFunc_v2
        (pParams,
         ftestID.c_str(),
         sm_Tests[it[iTest]].Func,
         Data,
         "NE__DECFLOAT16")));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
