////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/api/p13/RemoteFB__P13__XSQLDA_Utilities/TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__002.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__xsqlda_utilities.h"
#include <structure/test_obj/t_tso_user.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__002::tag_impl

class TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__002::tag_impl
{
 private:
  typedef tag_impl                                              self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type                               context_type;

  typedef remote_fb::api::p13::RemoteFB__P13__XSQLDA_Utilities  xsqlda_utils_type;

 public:
  static void test_001___null_ptr
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_002___null_ptr_to_sqlind
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

#ifdef NDEBUG
  static void test_003___bad_sqlind
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
#endif
};//class TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__002::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__002::tag_impl::test_001___null_ptr
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 xsqlda_utils_type::msg_nulls_buffer_type nulls;

 nulls.alloc(1024*1024);

 std::fill(nulls.buffer(),nulls.buffer_end(),0xFF);

 xsqlda_utils_type::Build_XSQLDA_MSG_NULLS
  (nullptr,
   nulls);

 _TSO_CHECK(nulls.size()==0);
}//test_001___null_ptr

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__002::tag_impl::test_002___null_ptr_to_sqlind
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 xsqlda_utils_type::msg_nulls_buffer_type nulls;

 //-----------------------------------------
 const unsigned char c_N=131;

 for(unsigned char n=0;n!=c_N;++n)
 {
  tracer<<L"------------- n: "<<n<<send;

  //----------------------------------------
  XSQLDA_V1_Wrapper xsqlda(c_N);

  xsqlda->sqld=c_N;

  xsqlda->sqlvar[n].sqltype=isc_api::ibp_isc_sql_long|1;

  try
  {
   xsqlda_utils_type::Build_XSQLDA_MSG_NULLS
    (xsqlda,
     nulls); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     2);

   errSvc::check_err_rec__xsqlda_err__incorrect_sqlind_ptr
    (tracer,
     exc.get_record(0),
     isc_api::ibp_isc_sql_long|1);

   errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_data
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__remote_fb_p13,
     n);

   continue;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for n
}//test_002___null_ptr_to_sqlind

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__002::tag_impl::test_003___bad_sqlind
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 xsqlda_utils_type::msg_nulls_buffer_type nulls;

 //-----------------------------------------
 const unsigned char c_N=131;

 for(unsigned char n=0;n!=c_N;++n)
 {
  tracer<<L"------------- n: "<<n<<send;

  //----------------------------------------
  XSQLDA_V1_Wrapper xsqlda(c_N);

  xsqlda->sqld=c_N;

  xsqlda->sqlvar[n].sqltype=isc_api::ibp_isc_sql_long|1;

  short sqlind=-1234;

  xsqlda->sqlvar[n].sqlind=&sqlind;

  try
  {
   xsqlda_utils_type::Build_XSQLDA_MSG_NULLS
    (xsqlda,
     nulls); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     2);

   errSvc::check_err_rec__xsqlda_err__incorrect_sqlind_value
    (tracer,
     exc.get_record(0),
     L"XSQLVAR_V1::get_value_is_null__std",
     L"#001",
     -1234);

   errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_data
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__remote_fb_p13,
     n);

   continue;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for n
}//test_003___bad_sqlind

#endif

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__002::tag_descr

struct TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__002::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__002::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__002::tag_impl::func},

const TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__002::tag_descr
 TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__002::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001.null_ptr",
   test_001___null_ptr)

 DEF_TEST_DESCR
  ("002.null_ptr_to_sqlind",
   test_002___null_ptr_to_sqlind)

#ifdef NDEBUG
 DEF_TEST_DESCR
  ("003.bad_sqlind",
   test_003___bad_sqlind)
#endif
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__002

void TestsFor__RemoteFB__P13__XSQLDA_Utilities___Build_XSQLDA_MSG_NULLS__002::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter ftestID("RemoteFB.API.P13.XSQLDA_Utilities.Build_XSQLDA_MSG_NULLS.002.%1");

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
