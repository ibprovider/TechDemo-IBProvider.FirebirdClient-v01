////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/api/p13/RemoteFB__P13__XSQLDA_Utilities/TestsFor__RemoteFB__P13__XSQLDA_Utilities___Alloc_XSQLDA_MSG_NULLS.h"
#include "source/test_func.h"
#include "source/test_services.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__xsqlda_utilities.h"
#include <structure/test_obj/t_tso_user.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__P13__XSQLDA_Utilities___Alloc_XSQLDA_MSG_NULLS::tag_impl

class TestsFor__RemoteFB__P13__XSQLDA_Utilities___Alloc_XSQLDA_MSG_NULLS::tag_impl
{
 private:
  typedef tag_impl                                              self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type                               context_type;

  typedef remote_fb::api::p13::RemoteFB__P13__XSQLDA_Utilities  xsqlda_utils_type;

 public:
  static void test_000
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_001
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
};//class TestsFor__RemoteFB__P13__XSQLDA_Utilities___Alloc_XSQLDA_MSG_NULLS::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__RemoteFB__P13__XSQLDA_Utilities___Alloc_XSQLDA_MSG_NULLS::tag_impl::test_000
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 xsqlda_utils_type::msg_nulls_buffer_type nulls;

 nulls.alloc(1024*1024);

 std::fill(nulls.buffer(),nulls.buffer_end(),0xFF);

 xsqlda_utils_type::Alloc_XSQLDA_MSG_NULLS
  (nullptr,
   nulls);

 _TSO_CHECK(nulls.size()==0);
}//test_000

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__RemoteFB__P13__XSQLDA_Utilities___Alloc_XSQLDA_MSG_NULLS::tag_impl::test_001
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 xsqlda_utils_type::msg_nulls_buffer_type nulls;

 for(unsigned short nV=0;;++nV)
 {
  XSQLDA_V1_Wrapper xsqlda(nV);

  xsqlda->sqld=nV;

  nulls.alloc(1024*1024);

  std::fill(nulls.buffer(),nulls.buffer_end(),0xFF);

  xsqlda_utils_type::Alloc_XSQLDA_MSG_NULLS
   (xsqlda,
    nulls);

  _TSO_CHECK(nulls.size()==((nV/8)+((nV%8)?1:0)));

  //----------------------------------------
  for(size_t i=0,_c=nulls.size();i!=_c;++i)
  {
   _TSO_CHECK(nulls[i]==0);
  }

  //----------------------------------------
  if(nV==SHRT_MAX)
   break;
 }//for
}//test_001

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__RemoteFB__P13__XSQLDA_Utilities___Alloc_XSQLDA_MSG_NULLS::tag_descr

struct TestsFor__RemoteFB__P13__XSQLDA_Utilities___Alloc_XSQLDA_MSG_NULLS::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class TestsFor__RemoteFB__P13__XSQLDA_Utilities___Alloc_XSQLDA_MSG_NULLS::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,TestsFor__RemoteFB__P13__XSQLDA_Utilities___Alloc_XSQLDA_MSG_NULLS::tag_impl::func},

const TestsFor__RemoteFB__P13__XSQLDA_Utilities___Alloc_XSQLDA_MSG_NULLS::tag_descr
 TestsFor__RemoteFB__P13__XSQLDA_Utilities___Alloc_XSQLDA_MSG_NULLS::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("000",
   test_000)

 DEF_TEST_DESCR
  ("001",
   test_001)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__P13__XSQLDA_Utilities___Alloc_XSQLDA_MSG_NULLS

void TestsFor__RemoteFB__P13__XSQLDA_Utilities___Alloc_XSQLDA_MSG_NULLS::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter
  ftestID("RemoteFB.API.P13.XSQLDA_Utilities.Alloc_XSQLDA_MSG_NULLS.%1");

 for(const tag_descr& d : sm_Tests)
 {
  ftestID<<structure::flush
         <<d.pTestSign;

  const TTSO_TestPtr spTest(new TTSO_TestFunc(pParams,
                                              ftestID.c_str(),
                                              d.Func));
  pTestPusher->PushTest(spTest);
 }//for d
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
