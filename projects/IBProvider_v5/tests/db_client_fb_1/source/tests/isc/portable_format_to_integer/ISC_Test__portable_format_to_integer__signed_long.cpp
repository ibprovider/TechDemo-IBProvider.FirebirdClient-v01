////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/isc/portable_format_to_integer/ISC_Test__portable_format_to_integer__signed_long.h"
#include "source/test_services.h"
#include "source/test_func.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include <structure/test_obj/t_tso_user.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class ISC_Test__portable_format_to_integer__signed_long::tag_impl

class ISC_Test__portable_format_to_integer__signed_long::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

  typedef signed long                       target_type;

 public:
  static void test_01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_03__sbyte
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_04__sshort
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_05__slong
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_06__err
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_07__err
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
};//class ISC_Test__portable_format_to_integer__signed_long::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 01

void ISC_Test__portable_format_to_integer__signed_long::tag_impl::test_01
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 target_type v=1;

 _TSO_CHECK(isc_base::isc_portable_format_to_integer::exec_r
                (0,
                 nullptr,
                 &v));

 _TSO_CHECK(v==0);
}//test_01

////////////////////////////////////////////////////////////////////////////////
//TEST 02

void ISC_Test__portable_format_to_integer__signed_long::tag_impl::test_02
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 {
  target_type v=1;

  const unsigned char data[]={0xFF};

  _TSO_CHECK(isc_base::isc_portable_format_to_integer::exec_r
                (sizeof(data),
                 data,
                 &v));

  _TSO_CHECK(v==-1);
 }

 {
  target_type v=1;

  const unsigned char data[]={0xFF,0xFF};

  _TSO_CHECK(isc_base::isc_portable_format_to_integer::exec_r
                (sizeof(data),
                 data,
                 &v));

  _TSO_CHECK(v==-1);
 }

 {
  target_type v=1;

  const unsigned char data[]={0xFF,0xFF,0xFF};

  _TSO_CHECK(isc_base::isc_portable_format_to_integer::exec_r
                (sizeof(data),
                 data,
                 &v));

  _TSO_CHECK(v==-1);
 }

 {
  target_type v=1;

  const unsigned char data[]={0xFF,0xFF,0xFF,0xFF};

  _TSO_CHECK(isc_base::isc_portable_format_to_integer::exec_r
                (sizeof(data),
                 data,
                 &v));

  _TSO_CHECK(v==-1);
 }

 {
  target_type v=1;

  const unsigned char data[]={0xFF,0xFF,0xFF,0xFF,0xFF};

  _TSO_CHECK(isc_base::isc_portable_format_to_integer::exec_r
                (sizeof(data),
                 data,
                 &v));

  _TSO_CHECK(v==-1);
 }
}//test_02

////////////////////////////////////////////////////////////////////////////////
//TEST 03

void ISC_Test__portable_format_to_integer__signed_long::tag_impl::test_03__sbyte
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 typedef signed char    value_type;
 typedef unsigned char  uvalue_type;

 uvalue_type uv=0;

 for(;;)
 {
  unsigned char data[sizeof(uvalue_type)];

  data[0]=uv;

  target_type v=1;

  _TSO_CHECK(isc_base::isc_portable_format_to_integer::exec_r
                (sizeof(data),
                 data,
                 &v));

  _TSO_CHECK(v==(value_type)uv);

  if(uv==structure::get_numeric_limits(uv).max_value())
   break;

  ++uv;
 }//for[ever]
}//test_03__sbyte

////////////////////////////////////////////////////////////////////////////////
//TEST 04

void ISC_Test__portable_format_to_integer__signed_long::tag_impl::test_04__sshort
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 typedef signed short    value_type;
 typedef unsigned short  uvalue_type;

 uvalue_type uv=0;

 for(;;)
 {
  unsigned char data[sizeof(uvalue_type)];

  data[0]=(uv&0xFF);
  data[1]=((uv>>8)&0xFF);

  target_type v=1;

  _TSO_CHECK(isc_base::isc_portable_format_to_integer::exec_r
                (sizeof(data),
                 data,
                 &v));

  _TSO_CHECK(v==(value_type)uv);

  if(uv==structure::get_numeric_limits(uv).max_value())
   break;

  ++uv;
 }//for[ever]
}//test_04__sshort

////////////////////////////////////////////////////////////////////////////////
//TEST 05

void ISC_Test__portable_format_to_integer__signed_long::tag_impl::test_05__slong
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 typedef signed long    value_type;
 typedef unsigned long  uvalue_type;

 uvalue_type uv=0;

 for(;;)
 {
  unsigned char data[sizeof(uvalue_type)];

  data[0]=(uv&0xFF);
  data[1]=((uv>>8)&0xFF);
  data[2]=((uv>>16)&0xFF);
  data[3]=((uv>>24)&0xFF);

  target_type v=1;

  _TSO_CHECK(isc_base::isc_portable_format_to_integer::exec_r
                (sizeof(data),
                 data,
                 &v));

  _TSO_CHECK(v==(value_type)uv);

  if(uv==structure::get_numeric_limits(uv).max_value())
   break;

  ++uv;
 }//for[ever]
}//test_05__slong

////////////////////////////////////////////////////////////////////////////////
//TEST 06

void ISC_Test__portable_format_to_integer__signed_long::tag_impl::test_06__err
                                           (TTSO_GlobalContext* const UNUSED_ARG(pParams),
                                            context_type*       const UNUSED_ARG(pCtx))
{
 {
  target_type v=1;

  const unsigned char data[]={1,1,1,1,1};

  _TSO_CHECK(!isc_base::isc_portable_format_to_integer::exec_r
                (sizeof(data),
                 data,
                 &v));

  _TSO_CHECK(v==0);
 }//local
}//test_06__err

////////////////////////////////////////////////////////////////////////////////
//TEST 07

void ISC_Test__portable_format_to_integer__signed_long::tag_impl::test_07__err
                                           (TTSO_GlobalContext* const UNUSED_ARG(pParams),
                                            context_type*       const UNUSED_ARG(pCtx))
{
 {
  target_type v=1;

  const unsigned char data[]={0xFF,0xFF,0xFF,0xFF,1};

  _TSO_CHECK(!isc_base::isc_portable_format_to_integer::exec_r
                (sizeof(data),
                 data,
                 &v));

  _TSO_CHECK(v==0);
 }//local
}//test_07__err

////////////////////////////////////////////////////////////////////////////////
//struct ISC_Test__portable_format_to_integer__signed_long::tag_descr

struct ISC_Test__portable_format_to_integer__signed_long::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class ISC_Test__portable_format_to_integer__signed_long::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,ISC_Test__portable_format_to_integer__signed_long::tag_impl::func},

const ISC_Test__portable_format_to_integer__signed_long::tag_descr
 ISC_Test__portable_format_to_integer__signed_long::sm_Tests[]=
{
 DEF_TEST_DESCR("01",
                test_01)
 DEF_TEST_DESCR("02",
                test_02)
 DEF_TEST_DESCR("03.sbyte",
                test_03__sbyte)
 DEF_TEST_DESCR("04.sshort",
                test_04__sshort)
 DEF_TEST_DESCR("05.slong",
                test_05__slong)
 DEF_TEST_DESCR("06.err",
                test_06__err)
 DEF_TEST_DESCR("07.err",
                test_07__err)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class ISC_Test__portable_format_to_integer__signed_long

void ISC_Test__portable_format_to_integer__signed_long::create(TTSO_PushTest*      pTestPusher,
                                   TTSO_GlobalContext* pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter ftestID("RemoteFB.ISC.portable_format_to_integer.exec.signed_long.%1");

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
}/*nms ibp_tests*/}/*nms lcpi*/
