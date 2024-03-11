////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/api/p13/RemoteFB__P13__AddServerKeys/TestsFor__RemoteFB__P13__AddServerKeys.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__add_server_keys.h"
#include "source/db_client/remote_fb/remote_fb__client_connect_block_v2.h"
#include <structure/test_obj/t_tso_user.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__P13__AddServerKeys::tag_impl

class TestsFor__RemoteFB__P13__AddServerKeys::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_impl;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

  static const unsigned char TAG_KEY_TYPE      = 0;
  static const unsigned char TAG_KEY_PLUGINS   = 1;
  static const unsigned char TAG_KNOWN_PLUGINS = 2;

 public:
  static void test_001__empty_buf
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_002__bugcheck__001
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_003__bugcheck__002
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_004__bugcheck__003
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_005__bugcheck__004
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_006__bugcheck__005
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_007__bugcheck__006
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_008__bugcheck__007
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_009__bugcheck__008
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_010__bugcheck__009
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_011__bugcheck__010
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_012__bugcheck__011
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_013__bugcheck__012
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_014__bugcheck__013
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_015__ok__sep_space
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_016__ok__sep_comma
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_017__err__duplication
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
};//class TestsFor__RemoteFB__P13__AddServerKeys::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_001__empty_buf
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
  (clientConnectBlock,
   0,
   nullptr);

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.empty());
}//test_001__empty_buf

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_002__bugcheck__001
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char badTags[]
 ={TAG_KEY_PLUGINS,
   TAG_KNOWN_PLUGINS,
   255};

 for(size_t i=0;i!=_DIM_(badTags);++i)
 {
  tracer<<L"-------------------------------------------- "<<i<<L"."<<send;

  const unsigned char buf[]={badTags[i]};

  try
  {
   remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
    (clientConnectBlock,
     sizeof(buf),
     buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_rec__info_buf_bug_check__unexpected_element
    (tracer,
     exc.get_record(0),
     L"RemoteFB__P13__AddServerKeys::exec",
     L"#001",
     badTags[i]);

   break;
  }//catch

  tracer(tso_msg_error,-1)
   <<L"We wait the error!"
   <<send;
 }//for i

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.empty());
}//test_002__bugcheck__001

////////////////////////////////////////////////////////////////////////////////
//TEST 003

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_003__bugcheck__002
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char buf[]={TAG_KEY_TYPE};

 for(;;)
 {
  try
  {
   remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
    (clientConnectBlock,
     sizeof(buf),
     buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_rec__info_buf_bug_check__unexpected_buffer_end
    (tracer,
     exc.get_record(0),
     L"RemoteFB__P13__AddServerKeys::exec",
     L"#002");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.empty());
}//test_003__bugcheck__002

////////////////////////////////////////////////////////////////////////////////
//TEST 004

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_004__bugcheck__003
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char buf[]={TAG_KEY_TYPE,100,0};

 for(;;)
 {
  try
  {
   remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
    (clientConnectBlock,
     sizeof(buf),
     buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_rec__info_buf_bug_check__too_large_value
    (tracer,
     exc.get_record(0),
     L"RemoteFB__P13__AddServerKeys::exec",
     L"#003",
     L"TAG_KEY_TYPE",
     /*actualSize*/100,
     /*maxSize*/1);

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.empty());
}//test_004__bugcheck__003

////////////////////////////////////////////////////////////////////////////////
//TEST 005

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_005__bugcheck__004
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char buf[]={TAG_KEY_TYPE,2,0xFF,0xFF};

 for(;;)
 {
  try
  {
   remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
    (clientConnectBlock,
     sizeof(buf),
     buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_rec__cn_err__bug_check__cant_translate_wire_crypt_key_type
    (tracer,
     exc.get_record(0),
     L"RemoteFB__P13__AddServerKeys::exec",
     L"#004",
     L"UTF8",
     L"WSTR");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.empty());
}//test_005__bugcheck__004

////////////////////////////////////////////////////////////////////////////////
//TEST 006

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_006__bugcheck__005
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char buf[]={TAG_KEY_TYPE,0};

 for(;;)
 {
  try
  {
   remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
    (clientConnectBlock,
     sizeof(buf),
     buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_rec__info_buf_bug_check__bad_format
    (tracer,
     exc.get_record(0),
     L"RemoteFB__P13__AddServerKeys::exec",
     L"#005",
     L"TAG_KEY_TYPE");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.empty());
}//test_006__bugcheck__005

////////////////////////////////////////////////////////////////////////////////
//TEST 007

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_007__bugcheck__006
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char buf[]={TAG_KEY_TYPE,1,'a'};

 for(;;)
 {
  try
  {
   remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
    (clientConnectBlock,
     sizeof(buf),
     buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_rec__info_buf_bug_check__unexpected_buffer_end
    (tracer,
     exc.get_record(0),
     L"RemoteFB__P13__AddServerKeys::exec",
     L"#006");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.empty());
}//test_007__bugcheck__006

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_008__bugcheck__007
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char badTags[]
 ={TAG_KEY_TYPE,
   TAG_KNOWN_PLUGINS,
   255};

 for(size_t i=0;i!=_DIM_(badTags);++i)
 {
  tracer<<L"-------------------------------------------- "<<i<<L"."<<send;

  const unsigned char buf[]={TAG_KEY_TYPE,2,'s','s',badTags[i]};

  try
  {
   remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
    (clientConnectBlock,
     sizeof(buf),
     buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_rec__info_buf_bug_check__unexpected_element
    (tracer,
     exc.get_record(0),
     L"RemoteFB__P13__AddServerKeys::exec",
     L"#007",
     badTags[i]);

   break;
  }//catch

  tracer(tso_msg_error,-1)
   <<L"We wait the error!"
   <<send;
 }//for i

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.empty());
}//test_008__bugcheck__007

////////////////////////////////////////////////////////////////////////////////
//TEST 009

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_009__bugcheck__008
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char buf[]={TAG_KEY_TYPE,2,'a','b',TAG_KEY_PLUGINS};

 for(;;)
 {
  try
  {
   remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
    (clientConnectBlock,
     sizeof(buf),
     buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_rec__info_buf_bug_check__unexpected_buffer_end
    (tracer,
     exc.get_record(0),
     L"RemoteFB__P13__AddServerKeys::exec",
     L"#008");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.empty());
}//test_009__bugcheck__008

////////////////////////////////////////////////////////////////////////////////
//TEST 010

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_010__bugcheck__009
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char buf[]={TAG_KEY_TYPE,2,'a','b',TAG_KEY_PLUGINS,32,1,2,3};

 for(;;)
 {
  try
  {
   remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
    (clientConnectBlock,
     sizeof(buf),
     buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_rec__info_buf_bug_check__too_large_value
    (tracer,
     exc.get_record(0),
     L"RemoteFB__P13__AddServerKeys::exec",
     L"#009",
     L"TAG_KEY_PLUGINS",
     32,
     3);

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.empty());
}//test_010__bugcheck__009

////////////////////////////////////////////////////////////////////////////////
//TEST 011

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_011__bugcheck__010
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char buf[]={TAG_KEY_TYPE,2,'a','b',TAG_KEY_PLUGINS,2,0xFF,0xFF};

 for(;;)
 {
  try
  {
   remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
    (clientConnectBlock,
     sizeof(buf),
     buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_rec__cn_err__bug_check__cant_translate_wire_crypt_svc_names
    (tracer,
     exc.get_record(0),
     L"RemoteFB__P13__AddServerKeys::exec",
     L"#010",
     L"UTF8",
     L"WSTR");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.empty());
}//test_011__bugcheck__010

////////////////////////////////////////////////////////////////////////////////
//TEST 012

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_012__bugcheck__011
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char buf[]={TAG_KEY_TYPE,2,'a','b',TAG_KEY_PLUGINS,4,' ','\t','\n','\r'};

 for(;;)
 {
  try
  {
   remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
    (clientConnectBlock,
     sizeof(buf),
     buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_rec__info_buf_bug_check__bad_format
    (tracer,
     exc.get_record(0),
     L"RemoteFB__P13__AddServerKeys::exec",
     L"#011",
     L"TAG_KEY_PLUGINS");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.empty());
}//test_012__bugcheck__011

////////////////////////////////////////////////////////////////////////////////
//TEST 013

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_013__bugcheck__012
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char buf[]
  ={TAG_KEY_TYPE,2,'a','b',TAG_KEY_PLUGINS,5,' ','\t','\n','\r',','};

 for(;;)
 {
  try
  {
   remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
    (clientConnectBlock,
     sizeof(buf),
     buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_rec__info_buf_bug_check__bad_format
    (tracer,
     exc.get_record(0),
     L"RemoteFB__P13__AddServerKeys::exec",
     L"#012",
     L"TAG_KEY_PLUGINS");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.empty());
}//test_013__bugcheck__012

////////////////////////////////////////////////////////////////////////////////
//TEST 014

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_014__bugcheck__013
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char buf[]
  ={TAG_KEY_TYPE,2,'a','b',TAG_KEY_PLUGINS,5,'a',',','b',' ','c'};

 for(;;)
 {
  try
  {
   remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
    (clientConnectBlock,
     sizeof(buf),
     buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_rec__info_buf_bug_check__bad_format
    (tracer,
     exc.get_record(0),
     L"RemoteFB__P13__AddServerKeys::exec",
     L"#013",
     L"TAG_KEY_PLUGINS");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.size()==2);

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[0]->wstrType==L"ab");
 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[0]->wstrPlugin==L"a");

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[1]->wstrType==L"ab");
 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[1]->wstrPlugin==L"b");
}//test_014__bugcheck__013

////////////////////////////////////////////////////////////////////////////////
//TEST 015

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_015__ok__sep_space
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char buf[]
  ={TAG_KEY_TYPE,2,'a','b',TAG_KEY_PLUGINS,5,'a',' ','b','\t','c'};

 remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
  (clientConnectBlock,
   sizeof(buf),
   buf);

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.size()==3);

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[0]->wstrType==L"ab");
 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[0]->wstrPlugin==L"a");

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[1]->wstrType==L"ab");
 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[1]->wstrPlugin==L"b");

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[2]->wstrType==L"ab");
 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[2]->wstrPlugin==L"c");
}//test_015__ok__sep_space

////////////////////////////////////////////////////////////////////////////////
//TEST 016

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_016__ok__sep_comma
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char buf[]
  ={TAG_KEY_TYPE,2,'a','b',TAG_KEY_PLUGINS,7,'a',' ',',','b',',','\t','c'};

 remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
  (clientConnectBlock,
   sizeof(buf),
   buf);

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.size()==3);

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[0]->wstrType==L"ab");
 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[0]->wstrPlugin==L"a");

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[1]->wstrType==L"ab");
 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[1]->wstrPlugin==L"b");

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[2]->wstrType==L"ab");
 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[2]->wstrPlugin==L"c");
}//test_016__ok__sep_comma

////////////////////////////////////////////////////////////////////////////////
//TEST 017

void TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::test_017__err__duplication
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from TEST!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 //-----------------------------------------
 svc::dbprops_type
  cn_params(pParams);

 remote_fb::RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(cn_params);

 const unsigned char buf[]
  ={TAG_KEY_TYPE,2,'a','b',TAG_KEY_PLUGINS,5,'a',',','b',',','b'};

 for(;;)
 {
  try
  {
   remote_fb::api::p13::RemoteFB__P13__AddServerKeys::exec
    (clientConnectBlock,
     sizeof(buf),
     buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok
    (tracer,
     exc);

   errSvc::check_err_count
    (exc,
     1);

   errSvc::check_err_rec__cn_err__mult_def_known_server_key
    (tracer,
     exc.get_record(0),
     errSvc::sm_subsysID__remote_fb,
     L"ab",
     L"b");

   break;
  }//catch

  svc::Throw_WeWaitTheError();
 }//for[ever]

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys.size()==2);

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[0]->wstrType==L"ab");
 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[0]->wstrPlugin==L"a");

 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[1]->wstrType==L"ab");
 _TSO_CHECK(clientConnectBlock.m_knownServerKeys[1]->wstrPlugin==L"b");
}//test_017__err__duplication

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__RemoteFB__P13__AddServerKeys::tag_descr

struct TestsFor__RemoteFB__P13__AddServerKeys::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
  const char* pExecRules;
};//class TestsFor__RemoteFB__P13__AddServerKeys::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR2(sign,func,exec_rules)                            \
 {sign,TestsFor__RemoteFB__P13__AddServerKeys::tag_impl::func,exec_rules},

#define DEF_TEST_DESCR(sign,func)                                        \
 DEF_TEST_DESCR2(sign,func,nullptr)

const TestsFor__RemoteFB__P13__AddServerKeys::tag_descr
 TestsFor__RemoteFB__P13__AddServerKeys::sm_Tests[]=
{
 DEF_TEST_DESCR
  ("001.empty_buf",
   test_001__empty_buf)

 DEF_TEST_DESCR
  ("002.bug_check.001",
   test_002__bugcheck__001)

 DEF_TEST_DESCR
  ("003.bug_check.002",
   test_003__bugcheck__002)

#ifdef NDEBUG
 DEF_TEST_DESCR
  ("004.bug_check.003",
   test_004__bugcheck__003)
#endif

 DEF_TEST_DESCR
  ("005.bug_check.004",
   test_005__bugcheck__004)

 DEF_TEST_DESCR
  ("006.bug_check.005",
   test_006__bugcheck__005)

 DEF_TEST_DESCR
  ("007.bug_check.006",
   test_007__bugcheck__006)

 DEF_TEST_DESCR
  ("008.bug_check.007",
   test_008__bugcheck__007)

 DEF_TEST_DESCR
  ("009.bug_check.008",
   test_009__bugcheck__008)

#ifdef NDEBUG
 DEF_TEST_DESCR
  ("010.bug_check.009",
   test_010__bugcheck__009)
#endif

 DEF_TEST_DESCR
  ("011.bug_check.010",
   test_011__bugcheck__010)

 DEF_TEST_DESCR
  ("012.bug_check.011",
   test_012__bugcheck__011)

 DEF_TEST_DESCR
  ("013.bug_check.012",
   test_013__bugcheck__012)

 DEF_TEST_DESCR
  ("014.bug_check.013",
   test_014__bugcheck__013)

 DEF_TEST_DESCR
  ("015.ok.sep_space",
   test_015__ok__sep_space)

 DEF_TEST_DESCR
  ("016.ok.sep_comma",
   test_016__ok__sep_comma)

 DEF_TEST_DESCR
  ("017.err.duplication",
   test_017__err__duplication)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__P13__AddServerKeys

void TestsFor__RemoteFB__P13__AddServerKeys::create
                                     (TTSO_PushTest*      const pTestPusher,
                                      TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter
  ftestID("RemoteFB.API.P13.AddServerKeys.%1");

 for(const tag_descr& d : sm_Tests)
 {
  ftestID<<structure::flush
         <<d.pTestSign;

  const TTSO_TestPtr spTest(new TTSO_TestFunc(pParams,
                                              ftestID.c_str(),
                                              d.Func,
                                              d.pExecRules));
  pTestPusher->PushTest(spTest);
 }//for d
}//create

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
