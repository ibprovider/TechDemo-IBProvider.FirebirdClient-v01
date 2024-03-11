////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_031__GetArraySlice.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/isc_base/isc_api__array_sdl__writer_funcs.h"
#include "source/db_obj/isc_base/isc_api__op_data__writer_buffer__external.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_031__GetArraySlice::tag_impl

class WORK_Test_031__GetArraySlice::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
 #ifdef NDEBUG
  static void test_001__bug_check__bad_owner_cn_of_tr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_002__bug_check__bad_tr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_003__bug_check__no_tr
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);
 #endif

  static void test_004__err__bad_tr_handle
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

  static void test_005__err__bad_buf_size
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_GetArraySlice_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_031__GetArraySlice::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void WORK_Test_031__GetArraySlice::tag_impl::test_001__bug_check__bad_owner_cn_of_tr
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams);
 assert(pCtx);

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
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 isc_base::t_isc_connection_settings cns2;

 const svc::remote_fb_connector_ptr
  spConnector2
   (svc::RemoteFB_Connector__ConnectToDatabase
     (tracer,
      params,
      cns2));

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 db_obj::DB_IBARRAYID arrayId={};

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__GetArraySlice
    (tracer,
     spConnector2,
     OpCtx,
     &hTr,
     arrayId,
     /*szArraySDL*/0,
     /*pArraySDL*/nullptr,
     /*szArrayData*/0,
     /*pArrayData*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__tr_err__bug_check__bad_tr_handle
    (tracer,
     exc.get_record(0),
     helper__get_GetArraySlice_bugcheck_src(spConnector),
     L"#003");

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;
  break;
 }//for[ever]

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector2);
}//test_001__bug_check__bad_owner_cn_of_tr

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 002

#ifdef NDEBUG

void WORK_Test_031__GetArraySlice::tag_impl::test_002__bug_check__bad_tr
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
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 svc::RemoteFB_Connector__StartTransaction
  (tracer,
   spConnector,
   &hTr);

 _TSO_CHECK(hTr!=nullptr);

 _TSO_CHECK(hTr->m_pParentPort==spConnector->GetPort());

 //-----------------------------------------
 remote_fb::handles::RemoteFB__TrHandle hTr_copy(hTr);

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr_copy);

 _TSO_CHECK(!hTr_copy);

 _TSO_CHECK(hTr);

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 db_obj::DB_IBARRAYID arrayId={};

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__GetArraySlice
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     arrayId,
     /*szArraySDL*/0,
     /*pArraySDL*/nullptr,
     /*szArrayData*/0,
     /*pArrayData*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__tr_err__bug_check__bad_tr_handle
    (tracer,
     exc.get_record(0),
     helper__get_GetArraySlice_bugcheck_src(spConnector),
     L"#002");

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;
  break;
 }//for[ever]

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_002__bug_check__bad_tr

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void WORK_Test_031__GetArraySlice::tag_impl::test_003__bug_check__no_tr
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
 remote_fb::handles::RemoteFB__TrHandle hTr(nullptr);

 //-----------------------------------------
 TestOperationContext OpCtx(params);

 db_obj::DB_IBARRAYID arrayId={};

 //-----------------------------------------
 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__GetArraySlice
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     arrayId,
     /*szArraySDL*/0,
     /*pArraySDL*/nullptr,
     /*szArrayData*/0,
     /*pArrayData*/nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__tr_err__bug_check__bad_tr_handle
    (tracer,
     exc.get_record(0),
     helper__get_GetArraySlice_bugcheck_src(spConnector),
     L"#001");

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;
  break;
 }//for[ever]

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_003__bug_check__no_tr

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 004

void WORK_Test_031__GetArraySlice::tag_impl::test_004__err__bad_tr_handle
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
  writer_funcs::stuff_byte_s(buf,isc_api::ibp_isc_blr_dtype__short);
  writer_funcs::stuff_byte_s(buf,/*scale*/0);
 }

 writer_funcs::stuff_string(buf,
                            isc_api::ibp_isc_sdl_relation,
                            "TEST_ARRAY_DIM1");

 writer_funcs::stuff_string(buf,
                            isc_api::ibp_isc_sdl_field,
                            "COL_I2");

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
 const db_obj::t_dbvalue__i2 arrayData[3]={SHRT_MIN,0,SHRT_MAX};

 //-----------------------------------------
 TestOperationContext OpCtx(params);

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
 svc::HACK__CommitTr
  (tracer,
   spConnector,
   &hTr);

 //-----------------------------------------
 for(;;)
 {
  try
  {
   db_obj::t_dbvalue__i2 arrayData2[_DIM_(arrayData)]={};

   svc::RemoteFB_Connector__GetArraySlice
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     arrayId,
     buf.get_size(),
     arraySDL,
     sizeof(arrayData2),
     arrayData2);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__srv_err__bad_tr_handle
    (tracer,
     spConnector->GetData()->m_DBMS_Name,
     exc.get_record(0));

   break;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;
  break;
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_004__err__bad_tr_handle

////////////////////////////////////////////////////////////////////////////////
//TEST 005

void WORK_Test_031__GetArraySlice::tag_impl::test_005__err__bad_buf_size
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
  writer_funcs::stuff_byte_s(bufSDL,isc_api::ibp_isc_blr_dtype__short);
  writer_funcs::stuff_byte_s(bufSDL,/*scale*/0);
 }

 writer_funcs::stuff_string(bufSDL,
                            isc_api::ibp_isc_sdl_relation,
                            "TEST_ARRAY_DIM1");

 writer_funcs::stuff_string(bufSDL,
                            isc_api::ibp_isc_sdl_field,
                            "COL_I2");

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
 TestOperationContext OpCtx(params);

 db_obj::DB_IBARRAYID arrayID2={};

 for(;;)
 {
  try
  {
   svc::RemoteFB_Connector__GetArraySlice
    (tracer,
     spConnector,
     OpCtx,
     &hTr,
     arrayID2,
     bufSDL.get_size(),
     arraySDL,
     0,
     nullptr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__slice_err__get_fail__invalid_array_buffer_size
    (tracer,
     exc.get_record(0),
     helper__get_GetArraySlice_bugcheck_src(spConnector),
     L"#005",
     L"TEST_ARRAY_DIM1",
     L"COL_I2",
     0,
     6);

   break;
  }//catch

  tracer(tso_msg_error,-1)<<"We wait the exception!"<<send;
  break;
 }//for[ever]

 //-----------------------------------------
 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_005__err__bad_buf_size

////////////////////////////////////////////////////////////////////////////////

const wchar_t* WORK_Test_031__GetArraySlice::tag_impl::helper__get_GetArraySlice_bugcheck_src
                                           (remote_fb::RemoteFB__Connector* const pConnector)
{
 assert(pConnector);

 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 switch(const auto v=pConnector->GetPort()->get_protocol_version())
 {
  case remote_fb::protocol::FB_PROTOCOL_VERSION10:
  case remote_fb::protocol::FB_PROTOCOL_VERSION11:
  case remote_fb::protocol::FB_PROTOCOL_VERSION12:
   return L"RemoteFB__API_P12__GetArraySlice::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__GetArraySlice::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_GetArraySlice_bugcheck_src

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_031__GetArraySlice::tag_descr

struct WORK_Test_031__GetArraySlice::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class WORK_Test_031__GetArraySlice::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,WORK_Test_031__GetArraySlice::tag_impl::func},

const WORK_Test_031__GetArraySlice::tag_descr
 WORK_Test_031__GetArraySlice::sm_Tests[]=
{
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("001.bug_check.bad_owner_cn_of_tr",
   test_001__bug_check__bad_owner_cn_of_tr)

 DEF_TEST_DESCR
  ("002.bug_check.bad_tr",
   test_002__bug_check__bad_tr)

 DEF_TEST_DESCR
  ("003.bug_check.no_tr",
   test_003__bug_check__no_tr)
#endif

 DEF_TEST_DESCR
  ("004.err.bad_tr_handle",
   test_004__err__bad_tr_handle)

 DEF_TEST_DESCR
  ("005.err.bad_buf_size",
   test_005__err__bad_buf_size)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_031__GetArraySlice

void WORK_Test_031__GetArraySlice::create(TTSO_PushTest*      const pTestPusher,
                                          TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;

 it.add(0,_DIM_(sm_Tests)-1);                              //0
 it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes)-1);    //1

 //-----------------------------------------
 enum
 {
  iTest   =0,
  iPType  =1,
 };//enum

 //-----------------------------------------
 structure::str_formatter ftestID("RemoteFB.WORK.031.GetArraySlice.ptype__%1.%2");

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
         Data)));

  pTestPusher->PushTest(spTest);
 }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
