////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/work/WORK_Test_036__StmtFetch_M__v1_no_lazy.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func_v2.h"
#include "source/test_utilities.h"
#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__encoder.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__msg_v1.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/error_services/ibp_sqlstate_codes.h"
#include <structure/test_obj/t_tso_user.h>
#include <structure/t_dimension_iterator.h>

#include <array>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_036__StmtFetch_M__v1_no_lazy::tag_impl

class WORK_Test_036__StmtFetch_M__v1_no_lazy::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 private:
  static const wchar_t* helper__get_fetch_bugcheck_src
                          (remote_fb::RemoteFB__Connector* pConnector);

  static const wchar_t* helper__get_fetch_subsystem
                          (remote_fb::RemoteFB__Connector* pConnector);
};//class WORK_Test_036__StmtFetch_M__v1_no_lazy

////////////////////////////////////////////////////////////////////////////////

const wchar_t* WORK_Test_036__StmtFetch_M__v1_no_lazy::tag_impl::helper__get_fetch_bugcheck_src
                                           (remote_fb::RemoteFB__Connector* pConnector)
{
 assert(pConnector);

 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

 switch(const auto v=pConnector->GetPort()->get_protocol_version())
 {
  case remote_fb::protocol::FB_PROTOCOL_VERSION10:
  case remote_fb::protocol::FB_PROTOCOL_VERSION11:
  case remote_fb::protocol::FB_PROTOCOL_VERSION12:
   return L"RemoteFB__API_P12__FetchStatement_M::exec";

  case remote_fb::protocol::FB_PROTOCOL_VERSION13:
   return L"RemoteFB__API_P13__FetchStatement_M::exec";

  default:
   assert(false);

   svc::Throw_UnknownProtocolVersion(v);
 }//switch
}//helper__get_fetch_bugcheck_src

//------------------------------------------------------------------------
const wchar_t* WORK_Test_036__StmtFetch_M__v1_no_lazy::tag_impl::helper__get_fetch_subsystem
                                           (remote_fb::RemoteFB__Connector* pConnector)
{
 assert(pConnector);

 typedef TestServices svc;

 typedef TestCheckErrors errSvc;

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
}//helper__get_fetch_subsystem

////////////////////////////////////////////////////////////////////////////////
//struct WORK_Test_036__StmtFetch_M__v1_no_lazy::tag_descr

struct WORK_Test_036__StmtFetch_M__v1_no_lazy::tag_descr
{
 public:
  typedef TTSO_TestFunc_v2::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class WORK_Test_036__StmtFetch_M__v1_no_lazy::tag_descr

////////////////////////////////////////////////////////////////////////////////

// #define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
//  {sign,WORK_Test_036__StmtFetch_M__v1_no_lazy::tag_impl::func,exec_rules},
//
// #define DEF_TEST_DESCR(sign,func)                                        \
//  DEF_TEST_DESCR2(sign,func,nullptr)
//
// const WORK_Test_036__StmtFetch_M__v1_no_lazy::tag_descr
//  WORK_Test_036__StmtFetch_M__v1_no_lazy::sm_Tests[]=
// {
// };//sm_Tests
//
// #undef DEF_TEST_DESCR
// #undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class WORK_Test_036__StmtFetch_M__v1_no_lazy

void WORK_Test_036__StmtFetch_M__v1_no_lazy::create
                                           (TTSO_PushTest*      const DEBUG_CODE(pTestPusher),
                                            TTSO_GlobalContext* const DEBUG_CODE(pParams))
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

// structure::t_dimension_iterator<size_t,TTSO_MemoryAllocator> it;
//
// it.add(0,_DIM_(sm_Tests)-1);                                       //0
// it.add(0,_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__no_lazy)-1);    //1
//
// //-----------------------------------------
// enum
// {
//  iTest   =0,
//  iPType  =1,
// };//enum
//
// //-----------------------------------------
// structure::str_formatter
//  ftestID("RemoteFB.WORK.036.StmtFetch_M.v1.ptype__%1.%2");
//
// TTSO_TestData_v2 Data;
//
// for(;it;++it)
// {
//  assert(it[iTest]<_DIM_(sm_Tests));
//  assert(it[iPType]<_DIM_(g_TestCfg__RemoteFB__ProtocolTypes__no_lazy));
//
//  //----------------------------------------
//  Data.m_RemoteFB__ProtocolType
//   =g_TestCfg__RemoteFB__ProtocolTypes__no_lazy[it[iPType]];
//
//  ftestID
//   <<structure::flush
//   <<TSO_RemoteFB_GetProtocolTypeSign(Data.m_RemoteFB__ProtocolType.value())
//   <<sm_Tests[it[iTest]].pTestSign;
//
//  const TTSO_TestPtr
//   spTest
//    (structure::not_null_ptr
//      (new TTSO_TestFunc_v2
//        (pParams,
//         ftestID.c_str(),
//         sm_Tests[it[iTest]].Func,
//         Data,
//         sm_Tests[it[iTest]].pExecRules)));
//
//  pTestPusher->PushTest(spTest);
// }//for it
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
