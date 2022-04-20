////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/inet/PortFactory/INET_PortFactory_Test_004__Analyze_v3__inet6.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/db_client/remote_fb/ports/factories/inet/remote_fb__ports__factories__inet.h"
#include <structure/test_obj/t_tso_user.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class INET_PortFactory_Test_004__Analyze_v3__inet6::tag_impl

class INET_PortFactory_Test_004__Analyze_v3__inet6::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test__001
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test__002__err_no_port
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test__003__err_bad_format
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 private:
  struct tag_data_vx_001
  {
   public:
    typedef structure::t_const_wstr_box str_type;

   public:
    str_type         src;

    bool             result;
    str_type         result_hostName;
    str_type         result_portName;
    str_type         result_dbName;
  };//struct tag_data_vx_001

  struct tag_data_vx_002
  {
   public:
    typedef structure::t_const_wstr_box str_type;

   public:
    str_type         src;
    str_type         hostName;
  };//struct tag_data_vx_002

  struct tag_data_vx_003
  {
   public:
    typedef structure::t_const_wstr_box str_type;

   public:
    str_type         src;
  };//struct tag_data_vx_003

 private:
  static const tag_data_vx_001 sm_data__001[];

  static const tag_data_vx_002 sm_data__002[];

  static const tag_data_vx_003 sm_data__003[];
};//class INET_PortFactory_Test_004__Analyze_v3__inet6::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST v3_inet6 001

#define DEF_DATA(src,                       \
                 result,                    \
                 host_name,                 \
                 port_name,                 \
                 db_name)                   \
{                                           \
 src,                                       \
 result,                                    \
 host_name,                                 \
 port_name,                                 \
 db_name                                    \
},

//------------------------------------------------------------------------
const INET_PortFactory_Test_004__Analyze_v3__inet6::tag_impl::tag_data_vx_001
 INET_PortFactory_Test_004__Analyze_v3__inet6::tag_impl::sm_data__001[]=
{
 DEF_DATA(nullptr,
          false,
          L"",
          L"",
          L"")

 DEF_DATA(L"",
          false,
          L"",
          L"",
          L"")

 DEF_DATA(L"localhost",
          false,
          L"",
          L"",
          L"")

 //-----------------------------------------
 DEF_DATA(L"inet6://g/b",
          true,
          L"g",
          L"",
          L"b")

 DEF_DATA(L"inet6:// g/b",
          true,
          L" g",
          L"",
          L"b")

 DEF_DATA(L"inet6://g /b",
          true,
          L"g ",
          L"",
          L"b")

 DEF_DATA(L"inet6:// / ",
          true,
          L" ",
          L"",
          L" ")

 DEF_DATA(L"inet6://localhost/base",
          true,
          L"localhost",
          L"",
          L"base")

 DEF_DATA(L"inet6:// localhost / base ",
          true,
          L" localhost ",
          L"",
          L" base ")

 DEF_DATA(L"inet6://\t localhost \t/ \tbase\t ",
          true,
          L"\t localhost \t",
          L"",
          L" \tbase\t ")

 DEF_DATA(L"inet6:// [g] /b",
          true,
          L" [g] ",
          L"",
          L"b")

 //-----------------------------------------
 DEF_DATA(L"inet6://g:p/b",
          true,
          L"g",
          L"p",
          L"b")

 DEF_DATA(L"inet6://g: p /b",
          true,
          L"g",
          L"p",
          L"b")

 DEF_DATA(L"inet6://g:\tp\t/b",
          true,
          L"g",
          L"p",
          L"b")

 //-----------------------------------------
 DEF_DATA(L"inet6://[]/b",
          true,
          L"",
          L"",
          L"b")

 DEF_DATA(L"inet6://[ ]/ ",
          true,
          L" ",
          L"",
          L" ")

 DEF_DATA(L"inet6://[\t]/\t",
          true,
          L"\t",
          L"",
          L"\t")

 DEF_DATA(L"inet6://[:]/\t",
          true,
          L":",
          L"",
          L"\t")

 //-----------------------------------------
 DEF_DATA(L"inet6://[]:p/b",
          true,
          L"",
          L"p",
          L"b")

 DEF_DATA(L"inet6://[]: p /b",
          true,
          L"",
          L"p",
          L"b")

 DEF_DATA(L"inet6://[]:\tp\t/b",
          true,
          L"",
          L"p",
          L"b")

 DEF_DATA(L"inet6://[] :\tp\t/b",
          true,
          L"",
          L"p",
          L"b")

 DEF_DATA(L"inet6://[]\t:\tp\t/b",
          true,
          L"",
          L"p",
          L"b")

 DEF_DATA(L"inet6://[]   :\tp\t/b",
          true,
          L"",
          L"p",
          L"b")
};//sm_data__001

//------------------------------------------------------------------------
#undef DEF_DATA

//------------------------------------------------------------------------
void INET_PortFactory_Test_004__Analyze_v3__inet6::tag_impl::test__001
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices                svc;
 typedef structure::t_const_wstr_box wstr_box_type;

 //-----------------------------------------
 size_t n=0;

 for(const tag_data_vx_001& Data : sm_data__001)
 {
  ++n;

  tracer<<L" --------------------- "<<n<<L"."<<send;

  tracer<<L"src: "<<svc::PrepareStrForPrint(Data.src)<<send;

  //-----------
  std::wstring result__hostName;
  std::wstring result__portName;
  std::wstring result__dbName;

  const bool result=remote_fb_inet_factory::RemoteFB__PortFactory__INET::Analyze_v3__inet6
                                           (Data.src,
                                            &result__hostName,
                                            &result__portName,
                                            &result__dbName);

  //-----------
  if(Data.result!=result)
  {
   tracer(tso_msg_error,-1)
    <<L"Wrong result: "<<result<<L".\n"
      L"Expected: "<<Data.result
    <<send;
  }//if

  //-----------
  if(!Data.result_hostName.equal(result__hostName))
  {
   tracer(tso_msg_error,-1)
    <<L"Wrong hostName: "<<svc::PrepareStrForPrint(wstr_box_type(result__hostName))<<L".\n"
    <<L"Expected: "<<svc::PrepareStrForPrint(Data.result_hostName)
    <<send;
  }//if

  //-----------
  if(!Data.result_portName.equal(result__portName))
  {
   tracer(tso_msg_error,-1)
    <<L"Wrong portName: "<<svc::PrepareStrForPrint(wstr_box_type(result__portName))<<L".\n"
    <<L"Expected: "<<svc::PrepareStrForPrint(Data.result_portName)
    <<send;
  }//if

  //-----------
  if(!Data.result_dbName.equal(result__dbName))
  {
   tracer(tso_msg_error,-1)
    <<L"Wrong dbName: "<<svc::PrepareStrForPrint(wstr_box_type(result__dbName))<<L".\n"
    <<L"Expected: "<<svc::PrepareStrForPrint(Data.result_dbName)
    <<send;
  }//if
 }//for Data
}//test__001

////////////////////////////////////////////////////////////////////////////////
//TEST v3_inet6 002

#define DEF_DATA(src,                       \
                 host_name)                 \
{                                           \
 src,                                       \
 host_name,                                 \
},

//------------------------------------------------------------------------
const INET_PortFactory_Test_004__Analyze_v3__inet6::tag_impl::tag_data_vx_002
 INET_PortFactory_Test_004__Analyze_v3__inet6::tag_impl::sm_data__002[]=
{
 DEF_DATA(L"inet6:// :/ ",
          L" ")
 DEF_DATA(L"inet6:// : / ",
          L" ")
 DEF_DATA(L"inet6:// :\t/ ",
          L" ")
 DEF_DATA(L"inet6:// localhost :/ ",
          L" localhost ")

 DEF_DATA(L"inet6://[]:/ ",
          L"")
 DEF_DATA(L"inet6://[]: / ",
          L"")
 DEF_DATA(L"inet6://[]:\t/ ",
          L"")
 DEF_DATA(L"inet6://[ local:host ]:/ ",
          L" local:host ")
};//sm_data__002

//------------------------------------------------------------------------
#undef DEF_DATA

//------------------------------------------------------------------------
void INET_PortFactory_Test_004__Analyze_v3__inet6::tag_impl::test__002__err_no_port
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices                svc;
 typedef TestCheckErrors             errSvc;
 typedef structure::t_const_wstr_box wstr_box_type;

 //-----------------------------------------
 size_t n=0;

 for(const tag_data_vx_002& Data : sm_data__002)
 {
  ++n;

  tracer<<L" --------------------- "<<n<<L"."<<send;

  tracer<<L"src: "<<svc::PrepareStrForPrint(Data.src)<<send;

  //-----------
  std::wstring result__hostName;
  std::wstring result__portName;
  std::wstring result__dbName;

  try
  {
   remote_fb_inet_factory::RemoteFB__PortFactory__INET::Analyze_v3__inet6
                                           (Data.src,
                                            &result__hostName,
                                            &result__portName,
                                            &result__dbName);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   errSvc::print_exception_ok(tracer,exc);

   _TSO_CHECK(exc.get_record_count()==1);

   const structure::t_err_record::self_cptr spErrRec(exc.get_record(0));

   _TSO_CHECK(spErrRec);

   errSvc::check_err_rec__direct_fb__bad_format_of_str_for_inet_cn_to_db__no_port
    (tracer,
     spErrRec,
     errSvc::sm_subsysID__remote_fb_inet,
     Data.hostName);

   continue;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;
 }//for Data
}//test__002__err_no_port

////////////////////////////////////////////////////////////////////////////////
//TEST v3_inet6 003

#define DEF_DATA(src)                       \
{                                           \
 src                                        \
},

//------------------------------------------------------------------------
const INET_PortFactory_Test_004__Analyze_v3__inet6::tag_impl::tag_data_vx_003
 INET_PortFactory_Test_004__Analyze_v3__inet6::tag_impl::sm_data__003[]=
{
 DEF_DATA(L"inet6://")
 DEF_DATA(L"inet6:///")
 DEF_DATA(L"inet6://:p/")

 DEF_DATA(L"inet6://[/")
 DEF_DATA(L"inet6://[]/")
 DEF_DATA(L"inet6://[]:p/")

 DEF_DATA(L"inet6://[]sssss/")
 DEF_DATA(L"inet6://[]sssss:p/")
};//sm_data_v3__002

//------------------------------------------------------------------------
#undef DEF_DATA

//------------------------------------------------------------------------
void INET_PortFactory_Test_004__Analyze_v3__inet6::tag_impl::test__003__err_bad_format
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 typedef TestServices                svc;
 typedef TestCheckErrors             errSvc;
 typedef structure::t_const_wstr_box wstr_box_type;

 //-----------------------------------------
 size_t n=0;

 for(const tag_data_vx_003& Data : sm_data__003)
 {
  ++n;

  tracer<<L" --------------------- "<<n<<L"."<<send;

  tracer<<L"src: "<<svc::PrepareStrForPrint(Data.src)<<send;

  //-----------
  std::wstring result__hostName;
  std::wstring result__portName;
  std::wstring result__dbName;

  try
  {
   remote_fb_inet_factory::RemoteFB__PortFactory__INET::Analyze_v3__inet6
                                           (Data.src,
                                            &result__hostName,
                                            &result__portName,
                                            &result__dbName);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   errSvc::print_exception_ok(tracer,exc);

   _TSO_CHECK(exc.get_record_count()==1);

   const structure::t_err_record::self_cptr spErrRec(exc.get_record(0));

   _TSO_CHECK(spErrRec);

   errSvc::check_err_rec__direct_fb__bad_format_of_str_for_inet_cn_to_db
    (tracer,
     spErrRec,
     errSvc::sm_subsysID__remote_fb_inet);

   continue;
  }//catch

  tracer(tso_msg_error,-1)<<L"We wait the exception!"<<send;
 }//for Data
}//test__003__err_bad_format

////////////////////////////////////////////////////////////////////////////////
//struct INET_PortFactory_Test_004__Analyze_v3__inet6::tag_descr

struct INET_PortFactory_Test_004__Analyze_v3__inet6::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class INET_PortFactory_Test_004__Analyze_v3__inet6::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                                         \
 {sign,INET_PortFactory_Test_004__Analyze_v3__inet6::tag_impl::func},

const INET_PortFactory_Test_004__Analyze_v3__inet6::tag_descr
 INET_PortFactory_Test_004__Analyze_v3__inet6::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001",
   test__001)

 DEF_TEST_DESCR
  ("002.err.no_port",
   test__002__err_no_port)

 DEF_TEST_DESCR
  ("003.err.bad_format",
   test__003__err_bad_format)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class INET_PortFactory_Test_004__Analyze_v3__inet6

void INET_PortFactory_Test_004__Analyze_v3__inet6::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter ftestID("RemoteFB.INET.RemotePortFactory.004.Analyze_v3__inet6.%1");

 for(const tag_descr& d : sm_Tests)
 {
  ftestID<<structure::flush
         <<d.pTestSign;

  const TTSO_TestPtr
   spTest
    (structure::not_null_ptr
      (new TTSO_TestFunc
        (pParams,
         ftestID.c_str(),
         d.Func)));

  pTestPusher->PushTest(spTest);
 }//for d
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
