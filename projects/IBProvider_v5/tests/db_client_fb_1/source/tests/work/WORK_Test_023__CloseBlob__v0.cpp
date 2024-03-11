////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_023__CloseBlob__v0.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_023__CloseBlob__v0::tag_impl

class WORK_Test_023__CloseBlob__v0::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

 public: //typedefs ------------------------------------------------------
  using context_type=TTSO_Test::context_type;

 public:
  static void test_001__write_blob__op_cancel
               (TTSO_GlobalContext*     pParams,
                context_type*           pCtx,
                const TTSO_TestData_v2& Data);

 private:
  static const wchar_t* helper__get_close_blob_subsystem_id
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_023__CloseBlob__v0::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 200

void WORK_Test_023__CloseBlob__v0::tag_impl::test_001__write_blob__op_cancel
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx,
                                            const TTSO_TestData_v2&   Data)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 using svc=TestServices;

 //-----------------------------------------
 svc::dbprops_type params(pParams);

 params.set_dbprop_init__location(svc::BuildLocationString(pParams));
 params.set_dbprop_init__user_id(L"SYSDBA");
 params.set_dbprop_init__password(L"masterkey");

 Data.SetParams(params);

 //-----------------------------------------
 TestOperationContext OpCtx(params);

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
 db_obj::DB_IBBLOBID blobID={};

 remote_fb::handles::RemoteFB__BlobHandle hBlob(nullptr);

 svc::RemoteFB_Connector__CreateBlob
  (tracer,
   spConnector,
   &hTr,
   &hBlob,
   &blobID);

 _TSO_CHECK(hBlob);

 _TSO_CHECK(hBlob->m_ID.has_value());

 _TSO_CHECK(hBlob->m_pParentTr==hTr);

 _TSO_CHECK(hBlob->m_BlobMode==hBlob->BlobMode__Create);

 //-----------------------------------------
 const char blobData[1]={123};

 svc::RemoteFB_Connector__WriteBlob
  (tracer,
   spConnector,
   OpCtx,
   &hBlob,
   sizeof(blobData),
   blobData);

 //-----------------------------------------
 OpCtx.cancel();

 {
  for(size_t pass=0;pass!=3;)
  {
   ++pass;

   tracer<<L"------------------------------- pass: "<<pass<<send;

   try
   {
    svc::RemoteFB_Connector__CloseBlob
     (tracer,
      spConnector,
      OpCtx,
      &hBlob);
   }
   catch(const ibp::t_ibp_error& exc)
   {
    using errSvc=TestCheckErrors;

    errSvc::print_exception_ok
     (tracer,
      exc);

    errSvc::check_err_count
     (exc,
      2);

    errSvc::check_err_code
     (exc.com_code(),
      DB_E_CANCELED);

    _TSO_CHECK(exc.get_record(0));

    errSvc::check_err_rec__srv_err__op_was_cancelled
     (tracer,
      errSvc::sm_srcID_wstr__IBProvider,
      exc.get_record(0));

    errSvc::check_err_rec__blob_err__fail_write_to_db_0
     (tracer,
      exc.get_record(1),
      self_type::helper__get_close_blob_subsystem_id(spConnector));

    continue;
   }//catch

   svc::Trace_WeWaitTheException(tracer);
   break;
  }//for pass
 }//local

 svc::RemoteFB_Connector__CancelBlob
  (tracer,
   spConnector,
   &hBlob);

 svc::RemoteFB_Connector__Commit
  (tracer,
   spConnector,
   &hTr);

 svc::RemoteFB_Connector__DetachDatabase
  (tracer,
   spConnector);
}//test_001__write_blob__op_cancel

//------------------------------------------------------------------------
const wchar_t* WORK_Test_023__CloseBlob__v0::tag_impl::helper__get_close_blob_subsystem_id
                                           (remote_fb::RemoteFB__Connector* const pConnector)
{
 assert(pConnector);

 using svc=TestServices;

 using errSvc=TestCheckErrors;

 switch(const auto v=pConnector->GetPort()->get_protocol_version())
 {
  case remote_fb::protocol::FB_PROTOCOL_VERSION10:
  case remote_fb::protocol::FB_PROTOCOL_VERSION11:
  case remote_fb::protocol::FB_PROTOCOL_VERSION12:
   return errSvc::sm_subsysID__remote_fb_p12;

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return errSvc::sm_subsysID__remote_fb_p13;

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_close_blob_subsystem_id

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_023__CloseBlob__v0::tag_descr

struct WORK_Test_023__CloseBlob__v0::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class WORK_Test_023__CloseBlob__v0::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,WORK_Test_023__CloseBlob__v0::tag_impl::func},

const WORK_Test_023__CloseBlob__v0::tag_descr
 WORK_Test_023__CloseBlob__v0::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001.write_blob.op_cancel",
   test_001__write_blob__op_cancel)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_023__CloseBlob__v0

void WORK_Test_023__CloseBlob__v0::create(TTSO_PushTest*      const pTestPusher,
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
 structure::str_formatter ftestID("RemoteFB.WORK.023.CloseBlob.v0.ptype__%1.%2");

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
