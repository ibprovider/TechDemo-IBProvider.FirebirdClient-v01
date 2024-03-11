////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/units/RemoteFB__ErrorUtils/TestsFor__RemoteFB__ErrorUtils__01.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"

#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__ErrorUtils__01::tag_impl

class TestsFor__RemoteFB__ErrorUtils__01::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
#ifdef NDEBUG
  static void test__Throw__BugCheck__DEBUG
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
#endif //NDEBUG

  static void test__Throw__UnsupportedProtocolTypeID
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test__Throw__ReqProtocolTypeIdDoesNotSupported
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test__Throw__UnsupportedProtocolFlags
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test__Throw__ServerRejectedConnectionCompression
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test__Throw__ServerRequiredConnectionCompression
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test__Throw__UnsupportedWireCompressionType
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
#ifdef NDEBUG
  static void test__Throw_BugCheck__unknown_wire_crypt_permission
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test__Throw_BugCheck__unknown_wire_compression_rule
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
#endif //NDEBUG
};//class TestsFor__RemoteFB__ErrorUtils__01::tag_impl

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__ErrorUtils__01::tag_impl

////////////////////////////////////////////////////////////////////////////////

#ifdef NDEBUG

void TestsFor__RemoteFB__ErrorUtils__01::tag_impl::test__Throw__BugCheck__DEBUG
                                               (TTSO_GlobalContext* const pParams,
                                                context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"HELLO!"<<send;

 try
 {
  remote_fb::RemoteFB__ErrorUtils::Throw__BugCheck__DEBUG
   (L"AAA",
    L"BBB",
    L"problem with %1. arg: %2",
    L"zlib1",
    432);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  TestCheckErrors::print_exception_ok
   (tracer,
    exc);

  TestCheckErrors::check_err_count
   (exc,
    1);

  TestCheckErrors::check_err_rec__bug_check
   (tracer,
    exc.get_record(0),
    L"AAA",
    L"BBB",
    L"problem with zlib1. arg: 432");

  return;
 }//catch

 TestServices::Throw_WeWaitTheError();
}//test__Throw__BugCheck__DEBUG

#endif //!NDEBUG

////////////////////////////////////////////////////////////////////////////////

void TestsFor__RemoteFB__ErrorUtils__01::tag_impl::test__Throw__UnsupportedProtocolTypeID
                                               (TTSO_GlobalContext* const pParams,
                                                context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"HELLO!"<<send;

 try
 {
  remote_fb::RemoteFB__ErrorUtils::Throw__UnsupportedProtocolTypeID
   (ibp::ibp_subsystem__remote_fb__pset02,
    123,
    321); //throw!
 }
 catch(const ibp::t_ibp_error& exc)
 {
  TestCheckErrors::print_exception_ok
   (tracer,
    exc);

  TestCheckErrors::check_err_count
   (exc,
    1);

  TestCheckErrors::check_err_rec___ibp_mce_remote__unsupported_protocol_type_2
   (tracer,
    exc.get_record(0),
    TestCheckErrors::sm_subsysID__remote_fb_pset02,
    123,
    321);

  return;
 }//catch

 TestServices::Throw_WeWaitTheError();
}//test__Throw__UnsupportedProtocolTypeID

////////////////////////////////////////////////////////////////////////////////

void TestsFor__RemoteFB__ErrorUtils__01::tag_impl::test__Throw__ReqProtocolTypeIdDoesNotSupported
                                               (TTSO_GlobalContext* const pParams,
                                                context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"HELLO!"<<send;

 try
 {
  remote_fb::RemoteFB__ErrorUtils::Throw__ReqProtocolTypeIdDoesNotSupported
   (ibp::ibp_subsystem__remote_fb__pset02,
    123,
    L" ADD "); //throw!
 }
 catch(const ibp::t_ibp_error& exc)
 {
  TestCheckErrors::print_exception_ok
   (tracer,
    exc);

  TestCheckErrors::check_err_count
   (exc,
    1);

  TestCheckErrors::check_err_rec___ibp_mce_remote__requested_protocol_type_not_supported_2
   (tracer,
    exc.get_record(0),
    TestCheckErrors::sm_subsysID__remote_fb_pset02,
    L" ADD ",
    123);

  return;
 }//catch

 TestServices::Throw_WeWaitTheError();
}//test__Throw__ReqProtocolTypeIdDoesNotSupported

////////////////////////////////////////////////////////////////////////////////

void TestsFor__RemoteFB__ErrorUtils__01::tag_impl::test__Throw__UnsupportedProtocolFlags
                                               (TTSO_GlobalContext* const pParams,
                                                context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"HELLO!"<<send;

 try
 {
  remote_fb::RemoteFB__ErrorUtils::Throw__UnsupportedProtocolFlags
   (ibp::ibp_subsystem__remote_fb__pset02,
    1234,
    4321); //throw!
 }
 catch(const ibp::t_ibp_error& exc)
 {
  TestCheckErrors::print_exception_ok
   (tracer,
    exc);

  TestCheckErrors::check_err_count
   (exc,
    1);

  TestCheckErrors::check_err_rec___ibp_mce_remote__unsupported_protocol_flags_2
   (tracer,
    exc.get_record(0),
    TestCheckErrors::sm_subsysID__remote_fb_pset02,
    1234,
    4321);

  return;
 }//catch

 TestServices::Throw_WeWaitTheError();
}//test__Throw__UnsupportedProtocolFlags

////////////////////////////////////////////////////////////////////////////////

void TestsFor__RemoteFB__ErrorUtils__01::tag_impl::test__Throw__ServerRejectedConnectionCompression
                                               (TTSO_GlobalContext* const pParams,
                                                context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"HELLO!"<<send;

 try
 {
  remote_fb::RemoteFB__ErrorUtils::Throw__ServerRejectedConnectionCompression
   (ibp::ibp_subsystem__remote_fb__pset02); //throw!
 }
 catch(const ibp::t_ibp_error& exc)
 {
  TestCheckErrors::print_exception_ok
   (tracer,
    exc);

  TestCheckErrors::check_err_count
   (exc,
    1);

  TestCheckErrors::check_err_rec___ibp_mce_remote__server_rejected_cn_compression_0
   (tracer,
    exc.get_record(0),
    TestCheckErrors::sm_subsysID__remote_fb_pset02);

  return;
 }//catch

 TestServices::Throw_WeWaitTheError();
}//test__Throw__ServerRejectedConnectionCompression

////////////////////////////////////////////////////////////////////////////////

void TestsFor__RemoteFB__ErrorUtils__01::tag_impl::test__Throw__ServerRequiredConnectionCompression
                                               (TTSO_GlobalContext* const pParams,
                                                context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"HELLO!"<<send;

 try
 {
  remote_fb::RemoteFB__ErrorUtils::Throw__ServerRequiredConnectionCompression
   (ibp::ibp_subsystem__remote_fb__pset02); //throw!
 }
 catch(const ibp::t_ibp_error& exc)
 {
  TestCheckErrors::print_exception_ok
   (tracer,
    exc);

  TestCheckErrors::check_err_count
   (exc,
    1);

  TestCheckErrors::check_err_rec___ibp_mce_remote__server_required_cn_compression_0
   (tracer,
    exc.get_record(0),
    TestCheckErrors::sm_subsysID__remote_fb_pset02);

  return;
 }//catch

 TestServices::Throw_WeWaitTheError();
}//test__Throw__ServerRequiredConnectionCompression

////////////////////////////////////////////////////////////////////////////////

void TestsFor__RemoteFB__ErrorUtils__01::tag_impl::test__Throw__UnsupportedWireCompressionType
                                               (TTSO_GlobalContext* const pParams,
                                                context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"HELLO!"<<send;

 try
 {
  remote_fb::RemoteFB__ErrorUtils::Throw__UnsupportedWireCompressionType
   (ibp::ibp_subsystem__remote_fb__p13,
    L"qwerty"); //throw!
 }
 catch(const ibp::t_ibp_error& exc)
 {
  TestCheckErrors::print_exception_ok
   (tracer,
    exc);

  TestCheckErrors::check_err_count
   (exc,
    1);

  TestCheckErrors::check_err_rec___ibp_mce_remote__unsupported_wire_compression_type_1
   (tracer,
    exc.get_record(0),
    TestCheckErrors::sm_subsysID__remote_fb_p13,
    L"qwerty");

  return;
 }//catch

 TestServices::Throw_WeWaitTheError();
}//test__Throw__UnsupportedWireCompressionType

////////////////////////////////////////////////////////////////////////////////

#ifdef NDEBUG

void TestsFor__RemoteFB__ErrorUtils__01::tag_impl::test__Throw_BugCheck__unknown_wire_crypt_permission
                                               (TTSO_GlobalContext* const pParams,
                                                context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"HELLO!"<<send;

 try
 {
  remote_fb::RemoteFB__ErrorUtils::Throw_BugCheck__unknown_wire_crypt_permission
   (L"AAA",
    L"BBB",
    321);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  TestCheckErrors::print_exception_ok
   (tracer,
    exc);

  TestCheckErrors::check_err_count
   (exc,
    1);

  TestCheckErrors::check_err_rec__bug_check
   (tracer,
    exc.get_record(0),
    L"AAA",
    L"BBB",
    L"unknown wire crypt permission: 321");

  return;
 }//catch

 TestServices::Throw_WeWaitTheError();
}//test__Throw_BugCheck__unknown_wire_crypt_permission

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////

#ifdef NDEBUG

void TestsFor__RemoteFB__ErrorUtils__01::tag_impl::test__Throw_BugCheck__unknown_wire_compression_rule
                                               (TTSO_GlobalContext* const pParams,
                                                context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"HELLO!"<<send;

 try
 {
  remote_fb::RemoteFB__ErrorUtils::Throw_BugCheck__unknown_wire_compression_rule
   (L"AAA1",
    L"BBB1",
    4321);
 }
 catch(const ibp::t_ibp_error& exc)
 {
  TestCheckErrors::print_exception_ok
   (tracer,
    exc);

  TestCheckErrors::check_err_count
   (exc,
    1);

  TestCheckErrors::check_err_rec__bug_check
   (tracer,
    exc.get_record(0),
    L"AAA1",
    L"BBB1",
    L"unknown wire compression rule: 4321");

  return;
 }//catch

 TestServices::Throw_WeWaitTheError();
}//test__Throw_BugCheck__unknown_wire_compression_rule

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__RemoteFB__ErrorUtils__01::tag_descr

struct TestsFor__RemoteFB__ErrorUtils__01::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class TestsFor__RemoteFB__ErrorUtils__01::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,TestsFor__RemoteFB__ErrorUtils__01::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const TestsFor__RemoteFB__ErrorUtils__01::tag_descr
 TestsFor__RemoteFB__ErrorUtils__01::sm_Tests[]=
{
#ifdef NDEBUG
 DEF_TEST_DESCR
  ("Throw__BugCheck__DEBUG",
   test__Throw__BugCheck__DEBUG)
#endif //NDEBUG

 DEF_TEST_DESCR
  ("Throw__UnsupportedProtocolTypeID",
   test__Throw__UnsupportedProtocolTypeID)

 DEF_TEST_DESCR
  ("Throw__ReqProtocolTypeIdDoesNotSupported",
   test__Throw__ReqProtocolTypeIdDoesNotSupported)

 DEF_TEST_DESCR
  ("Throw__UnsupportedProtocolFlags",
   test__Throw__UnsupportedProtocolFlags)

 DEF_TEST_DESCR
  ("Throw__ServerRejectedConnectionCompression",
   test__Throw__ServerRejectedConnectionCompression)

 DEF_TEST_DESCR
  ("Throw__ServerRequiredConnectionCompression",
   test__Throw__ServerRequiredConnectionCompression)

 DEF_TEST_DESCR
  ("Throw__UnsupportedWireCompressionType",
   test__Throw__UnsupportedWireCompressionType)

#ifdef NDEBUG
 DEF_TEST_DESCR
  ("Throw_BugCheck__unknown_wire_crypt_permission",
   test__Throw_BugCheck__unknown_wire_crypt_permission)

 DEF_TEST_DESCR
  ("Throw_BugCheck__unknown_wire_compression_rule",
   test__Throw_BugCheck__unknown_wire_compression_rule)
#endif //NDEBUG
};//sm_Tests

#undef DEF_TEST_DESCR
#undef DEF_TEST_DESCR2

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__ErrorUtils__01

void TestsFor__RemoteFB__ErrorUtils__01::create(TTSO_PushTest*      const pTestPusher,
                                                TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter ftestID("RemoteFB.UNITS.RemoteFB__ErrorUtils.01.%1");

 for(const tag_descr& d : sm_Tests)
 {
  ftestID
   <<structure::flush
   <<d.pTestSign;

  const TTSO_TestPtr
   spTest
    (lib::structure::not_null_ptr
      (new TTSO_TestFunc
        (pParams,
         ftestID.c_str(),
         d.Func,
         d.pExecRules)));

  pTestPusher->PushTest(spTest);
 }//for d
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
