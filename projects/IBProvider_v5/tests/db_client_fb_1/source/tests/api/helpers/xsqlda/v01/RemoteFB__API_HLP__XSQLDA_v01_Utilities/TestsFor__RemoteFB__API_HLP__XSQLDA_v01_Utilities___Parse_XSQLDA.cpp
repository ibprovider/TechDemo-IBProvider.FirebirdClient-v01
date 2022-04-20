////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/api/helpers/xsqlda/v01/RemoteFB__API_HLP__XSQLDA_v01_Utilities/TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/isc_base/isc_integer_to_portable_format.h"
#include <structure/test_obj/t_tso_user.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl

class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl
{
 private:
  typedef tag_impl                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type           context_type;

 public:
  static void test_001___bug_check__empty_buf
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_002___bug_check__no_sql_describe_vars
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_003___bug_check__bad_format_of_sql_describe_vars
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_004___bug_check__too_large_value_of_sql_describe_vars
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_005___bug_check__too_large_number_of_sql_describe_vars
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_006___bug_check__sqld_is_too_large
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_007__sqln_less_than_sqld
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_008__bug_check__second_block__mutable_sqld
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_009__bug_check__out_of_range_seq_number
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_009__bug_check__out_of_range_seq_number_0
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_010__bug_check__unexpected_elements_for_XSQLDA
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_011__bug_check__unexpected_truncation
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_012__bug_check__unexpected_seq_number
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_013__bug_check__unexpected_end_of_seq
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_014__bug_check__unk_element_in_xvar_definition
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_015__ok__xsqlvar1
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_016__bug_check__negative_sqllen
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_017__bug_check__incompleted_def_of_xsqlvars_0
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_017__bug_check__incompleted_def_of_xsqlvars_1
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_A01__bug_check__mult_def_of_xvar_field__sqltype
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_A02__bug_check__mult_def_of_xvar_field__sqlsubtype
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_A03__bug_check__mult_def_of_xvar_field__sqlscale
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_A04__bug_check__mult_def_of_xvar_field__sqllen
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_A05__bug_check__mult_def_of_xvar_field__sqlname
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_A06__bug_check__mult_def_of_xvar_field__relname
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_A07__bug_check__mult_def_of_xvar_field__ownname
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_A08__bug_check__mult_def_of_xvar_field__aliasname
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_B01__bug_check__not_def_xvar_field__sqltype
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_B02__bug_check__not_def_xvar_field__sqlsubtype
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_B03__bug_check__not_def_xvar_field__sqlscale
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_B04__bug_check__not_def_xvar_field__sqllen
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_B05__bug_check__not_def_xvar_field__sqlname
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_B06__bug_check__not_def_xvar_field__relname
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_B07__bug_check__not_def_xvar_field__ownname
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_B08__bug_check__not_def_xvar_field__aliasname
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
};//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_001___bug_check__empty_buf
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(0);

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (0,
    nullptr,
    true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__unexpected_buffer_end
   (tracer,
    exc.get_record(0),
    L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA",
    L"#001");

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_001___bug_check__empty_buf

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_002___bug_check__no_sql_describe_vars
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(0);

 const unsigned char buf[]={0};

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (_DIM_(buf),
    buf,
    true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__info_buf_bug_check__unexpected_element
   (tracer,
    exc.get_record(0),
    L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA",
    L"#002",
    buf[0]);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_002___bug_check__no_sql_describe_vars

////////////////////////////////////////////////////////////////////////////////
//TEST 003

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_003___bug_check__bad_format_of_sql_describe_vars
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(0);

 const unsigned char buf[]={isc_api::ibp_isc_info_sql_describe_vars,0};

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (_DIM_(buf),
    buf,
    true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__info_buf_bug_check__bad_format
   (tracer,
    exc.get_record(0),
    L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__ReadNumber",
    L"#001",
    L"isc_info_sql_describe_vars");

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_003___bug_check__bad_format_of_sql_describe_vars

////////////////////////////////////////////////////////////////////////////////
//TEST 004

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_004___bug_check__too_large_value_of_sql_describe_vars
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(0);

 const unsigned char buf[]={isc_api::ibp_isc_info_sql_describe_vars,1,0};

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (_DIM_(buf),
    buf,
    true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__info_buf_bug_check__too_large_value
   (tracer,
    exc.get_record(0),
    L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__ReadNumber",
    L"#002",
    L"isc_info_sql_describe_vars",
    /*actualSize*/1,
    /*maxSize*/0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_004___bug_check__too_large_value_of_sql_describe_vars

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 005

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_005___bug_check__too_large_number_of_sql_describe_vars
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(0);

 const unsigned char buf[]={isc_api::ibp_isc_info_sql_describe_vars,9,0,
                            0,0,0,0,0,0,0,0,1};

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (_DIM_(buf),
    buf,
    true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__info_buf_err__transport_data_to_integer__size_t
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_p12,
    L"isc_info_sql_describe_vars",
    /*bufferSize*/9);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_005___bug_check__too_large_number_of_sql_describe_vars

////////////////////////////////////////////////////////////////////////////////
//TEST 006

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_006___bug_check__sqld_is_too_large
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(0);

 //-----------------------------------------
 const unsigned char buf[]={isc_api::ibp_isc_info_sql_describe_vars,4,0,
                            0xFF,0xFF,0xFF,0xFF};

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (_DIM_(buf),
    buf,
    true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__xsqlda_err__too_many_vars
   (tracer,
    exc.get_record(0),
    errSvc::sm_subsysID__remote_fb_p12,
    structure::t_numeric_limits<unsigned __int32>::max_value(),
    SHRT_MAX);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_006___bug_check__sqld_is_too_large

////////////////////////////////////////////////////////////////////////////////
//TEST 007

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_007__sqln_less_than_sqld
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 typedef TestServices svc;

 XSQLDA_V1_Wrapper xsqlda(2);

 //-----------------------------------------
 const unsigned char buf[]={isc_api::ibp_isc_info_sql_describe_vars,1,0,
                            0xFF};

 const auto res=
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (_DIM_(buf),
    buf,
    true,
    0,
    xsqlda);//throw

 _TSO_CHECK(res.first==0);

 _TSO_CHECK(res.second==true);

 svc::XSQLDA_check_sqld(tracer,xsqlda,255);
}//test_007__sqln_less_than_sqld

////////////////////////////////////////////////////////////////////////////////
//TEST 008

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_008__bug_check__second_block__mutable_sqld
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 xsqlda->sqld=4;

 //-----------------------------------------
 const unsigned char buf[]={isc_api::ibp_isc_info_sql_describe_vars,1,0,
                            0xFE};

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (_DIM_(buf),
    buf,
    /*is_first_info_block*/false,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__incorrect_xsqlda_in_secondary_block
   (tracer,
    exc.get_record(0),
    L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA",
    L"#003",
    /*actualSQLD*/254,
    /*expectedSQLD*/4,
    /*StartIndex*/0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_008__bug_check__second_block__mutable_sqld

////////////////////////////////////////////////////////////////////////////////
//TEST 009

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_009__bug_check__out_of_range_seq_number
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 xsqlda->sqld=4;

 //-----------------------------------------
 const unsigned char buf[]={isc_api::ibp_isc_info_sql_describe_vars,1,0,4,
                            isc_api::ibp_isc_info_sql_sqlda_seq,1,0,5};

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (_DIM_(buf),
    buf,
    /*is_first_info_block*/false,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__xvar_seq_number_is_out_of_range
   (tracer,
    exc.get_record(0),
    L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA",
    L"#006",
    5,
    /*sqld*/4,
    /*index*/0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_009__bug_check__out_of_range_seq_number

////////////////////////////////////////////////////////////////////////////////
//TEST 009

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_009__bug_check__out_of_range_seq_number_0
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 xsqlda->sqld=4;

 //-----------------------------------------
 const unsigned char buf[]={isc_api::ibp_isc_info_sql_describe_vars,1,0,4,
                            isc_api::ibp_isc_info_sql_sqlda_seq,1,0,0};

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (_DIM_(buf),
    buf,
    /*is_first_info_block*/false,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__xvar_seq_number_is_out_of_range
   (tracer,
    exc.get_record(0),
    L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA",
    L"#006",
    0,
    /*sqld*/4,
    /*index*/0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_009__bug_check__out_of_range_seq_number_0

////////////////////////////////////////////////////////////////////////////////
//TEST 010

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_010__bug_check__unexpected_elements_for_XSQLDA
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 //-----------------------------------------
 const unsigned char buf[]={isc_api::ibp_isc_info_sql_describe_vars,1,0,0,
                            isc_api::ibp_isc_info_sql_sqlda_seq,1,0,5};

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (_DIM_(buf),
    buf,
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__unexpected_xvars_for_xsqlda
   (tracer,
    exc.get_record(0),
    L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA",
    L"#005",
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_010__bug_check__unexpected_elements_for_XSQLDA

////////////////////////////////////////////////////////////////////////////////
//TEST 010

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_011__bug_check__unexpected_truncation
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 //-----------------------------------------
 const unsigned char buf[]={isc_api::ibp_isc_info_sql_describe_vars,1,0,0,
                            isc_api::ibp_isc_info_truncated};

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (_DIM_(buf),
    buf,
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__unexpected_buffer_truncation
   (tracer,
    exc.get_record(0),
    L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA",
    L"#004",
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_011__bug_check__unexpected_truncation

////////////////////////////////////////////////////////////////////////////////
//TEST 012

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_012__bug_check__unexpected_seq_number
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 xsqlda->sqld=4;

 //-----------------------------------------
 const unsigned char buf[]={isc_api::ibp_isc_info_sql_describe_vars,1,0,4,
                            isc_api::ibp_isc_info_sql_sqlda_seq,1,0,2};

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (_DIM_(buf),
    buf,
    /*is_first_info_block*/false,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__unexpected_seq_number_of_xvar
   (tracer,
    exc.get_record(0),
    L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA",
    L"#007",
    2,
    1);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_012__bug_check__unexpected_seq_number

////////////////////////////////////////////////////////////////////////////////
//TEST 013

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_013__bug_check__unexpected_end_of_seq
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 xsqlda->sqld=4;

 //-----------------------------------------
 const unsigned char buf[]={isc_api::ibp_isc_info_sql_describe_vars,1,0,4,
                            isc_api::ibp_isc_info_sql_sqlda_seq,1,0,1};

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (_DIM_(buf),
    buf,
    /*is_first_info_block*/false,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__unexpected_buffer_end
   (tracer,
    exc.get_record(0),
    L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA",
    L"#008");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_013__bug_check__unexpected_end_of_seq

////////////////////////////////////////////////////////////////////////////////
//TEST 014

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_014__bug_check__unk_element_in_xvar_definition
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 xsqlda->sqld=4;

 //-----------------------------------------
 const unsigned char buf[]={isc_api::ibp_isc_info_sql_describe_vars,1,0,4,
                            isc_api::ibp_isc_info_sql_sqlda_seq,1,0,1,
                            isc_api::ibp_isc_info_sql_sqlda_seq};

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (_DIM_(buf),
    buf,
    /*is_first_info_block*/false,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__info_buf_bug_check__unexpected_element
   (tracer,
    exc.get_record(0),
    L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA",
    L"#009",
    isc_api::ibp_isc_info_sql_sqlda_seq);

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_014__bug_check__unk_element_in_xvar_definition

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_015__ok__xsqlvar1
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 {
  buf.push_back(isc_api::ibp_isc_info_sql_type);
  buf.push_back(2);
  buf.push_back(0);

  isc_base::isc_integer_to_portable_format::tag_buffer<2> p;
  isc_base::isc_integer_to_portable_format::exec<2,unsigned short>(&p,isc_api::ibp_isc_sql_long);
  std::copy(p.data,_END_(p.data),std::back_inserter(buf));
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_sub_type);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(1);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_scale);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(0xFF);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_length);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(4);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_field);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back('A');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_relation);
  buf.push_back(2);
  buf.push_back(0);
  buf.push_back('B');
  buf.push_back('C');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_owner);
  buf.push_back(3);
  buf.push_back(0);
  buf.push_back('D');
  buf.push_back('E');
  buf.push_back('F');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_alias);
  buf.push_back(32);
  buf.push_back(0);

  for(size_t n=0;n!=32;++n)
   buf.push_back('0'+(n%10));
 }

 buf.push_back(isc_api::ibp_isc_info_sql_describe_end);
 buf.push_back(isc_api::ibp_isc_info_end);

 remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
  (buf.size(),
   buf.data(),
   /*is_first_info_block*/true,
   0,
   xsqlda);//throw

 //-----------------------------------------
 typedef TestServices svc;

 svc::XSQLDA_check_sqld(tracer,xsqlda,1);

 svc::XSQLVAR_check(tracer,
                    &xsqlda->sqlvar[0],
                    isc_api::ibp_isc_sql_long,
                    1,
                    -1,
                    4,
                    "A",
                    "BC",
                    "DEF",
                    "01234567890123456789012345678901");
}//test_015__ok__xsqlvar1

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_016__bug_check__negative_sqllen
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 {
  buf.push_back(isc_api::ibp_isc_info_sql_type);
  buf.push_back(2);
  buf.push_back(0);

  isc_base::isc_integer_to_portable_format::tag_buffer<2> p;
  isc_base::isc_integer_to_portable_format::exec<2,unsigned short>(&p,isc_api::ibp_isc_sql_long);
  std::copy(p.data,_END_(p.data),std::back_inserter(buf));
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_sub_type);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(1);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_scale);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(0xFF);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_length);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(0xFF);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_field);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back('A');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_relation);
  buf.push_back(2);
  buf.push_back(0);
  buf.push_back('B');
  buf.push_back('C');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_owner);
  buf.push_back(3);
  buf.push_back(0);
  buf.push_back('D');
  buf.push_back('E');
  buf.push_back('F');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_alias);
  buf.push_back(4);
  buf.push_back(0);
  buf.push_back('G');
  buf.push_back('H');
  buf.push_back('I');
  buf.push_back('J');
 }

 buf.push_back(isc_api::ibp_isc_info_sql_describe_end);
 buf.push_back(isc_api::ibp_isc_info_end);

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__negative_sqllen
   (tracer,
    exc.get_record(0),
    -1);

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_016__bug_check__negative_sqllen

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_017__bug_check__incompleted_def_of_xsqlvars_0
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(4);

 buf.push_back(isc_api::ibp_isc_info_end);

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__incompleted_def_of_xvars
   (tracer,
    exc.get_record(0),
    0,
    4);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_017__bug_check__incompleted_def_of_xsqlvars_0

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_017__bug_check__incompleted_def_of_xsqlvars_1
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(4);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 {
  buf.push_back(isc_api::ibp_isc_info_sql_type);
  buf.push_back(2);
  buf.push_back(0);

  isc_base::isc_integer_to_portable_format::tag_buffer<2> p;
  isc_base::isc_integer_to_portable_format::exec<2,unsigned short>(&p,isc_api::ibp_isc_sql_long);
  std::copy(p.data,_END_(p.data),std::back_inserter(buf));
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_sub_type);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(1);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_scale);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(0xFF);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_length);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(4);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_field);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back('A');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_relation);
  buf.push_back(2);
  buf.push_back(0);
  buf.push_back('B');
  buf.push_back('C');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_owner);
  buf.push_back(3);
  buf.push_back(0);
  buf.push_back('D');
  buf.push_back('E');
  buf.push_back('F');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_alias);
  buf.push_back(4);
  buf.push_back(0);
  buf.push_back('G');
  buf.push_back('H');
  buf.push_back('I');
  buf.push_back('J');
 }

 buf.push_back(isc_api::ibp_isc_info_sql_describe_end);
 buf.push_back(isc_api::ibp_isc_info_end);

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,1);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__incompleted_def_of_xvars
   (tracer,
    exc.get_record(0),
    1,
    4);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_017__bug_check__incompleted_def_of_xsqlvars_1

////////////////////////////////////////////////////////////////////////////////
//TEST Axx

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_A01__bug_check__mult_def_of_xvar_field__sqltype
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 xsqlda->sqld=4;

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(4);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 for(size_t n=0;n!=2;++n)
 {
  buf.push_back(isc_api::ibp_isc_info_sql_type);
  buf.push_back(2);
  buf.push_back(0);

  isc_base::isc_integer_to_portable_format::tag_buffer<2> p;
  isc_base::isc_integer_to_portable_format::exec<2,unsigned short>(&p,isc_api::ibp_isc_sql_long);
  std::copy(p.data,_END_(p.data),std::back_inserter(buf));
 }//for n

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__mult_def_of_xsqvar_field_value
   (tracer,
    exc.get_record(0),
    L"sqltype");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_A01__bug_check__mult_def_of_xvar_field__sqltype

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_A02__bug_check__mult_def_of_xvar_field__sqlsubtype
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 xsqlda->sqld=4;

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(4);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 for(size_t n=0;n!=2;++n)
 {
  buf.push_back(isc_api::ibp_isc_info_sql_sub_type);
  buf.push_back(2);
  buf.push_back(0);

  isc_base::isc_integer_to_portable_format::tag_buffer<2> p;
  isc_base::isc_integer_to_portable_format::exec<2,unsigned short>(&p,1);
  std::copy(p.data,_END_(p.data),std::back_inserter(buf));
 }//for n

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__mult_def_of_xsqvar_field_value
   (tracer,
    exc.get_record(0),
    L"sqlsubtype");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_A02__bug_check__mult_def_of_xvar_field__sqlsubtype

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_A03__bug_check__mult_def_of_xvar_field__sqlscale
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 xsqlda->sqld=4;

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(4);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 for(size_t n=0;n!=2;++n)
 {
  buf.push_back(isc_api::ibp_isc_info_sql_scale);
  buf.push_back(2);
  buf.push_back(0);

  isc_base::isc_integer_to_portable_format::tag_buffer<2> p;
  isc_base::isc_integer_to_portable_format::exec<2,short>(&p,-1);
  std::copy(p.data,_END_(p.data),std::back_inserter(buf));
 }//for n

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__mult_def_of_xsqvar_field_value
   (tracer,
    exc.get_record(0),
    L"sqlscale");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_A03__bug_check__mult_def_of_xvar_field__sqlscale

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_A04__bug_check__mult_def_of_xvar_field__sqllen
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 xsqlda->sqld=4;

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(4);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 for(size_t n=0;n!=2;++n)
 {
  buf.push_back(isc_api::ibp_isc_info_sql_length);
  buf.push_back(2);
  buf.push_back(0);

  isc_base::isc_integer_to_portable_format::tag_buffer<2> p;
  isc_base::isc_integer_to_portable_format::exec<2,short>(&p,1);
  std::copy(p.data,_END_(p.data),std::back_inserter(buf));
 }//for n

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__mult_def_of_xsqvar_field_value
   (tracer,
    exc.get_record(0),
    L"sqllen");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_A04__bug_check__mult_def_of_xvar_field__sqllen

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_A05__bug_check__mult_def_of_xvar_field__sqlname
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 xsqlda->sqld=4;

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(4);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 for(size_t n=0;n!=2;++n)
 {
  buf.push_back(isc_api::ibp_isc_info_sql_field);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back('A');
 }//for n

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__mult_def_of_xsqvar_field_value
   (tracer,
    exc.get_record(0),
    L"sqlname");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_A05__bug_check__mult_def_of_xvar_field__sqlname

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_A06__bug_check__mult_def_of_xvar_field__relname
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 xsqlda->sqld=4;

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(4);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 for(size_t n=0;n!=2;++n)
 {
  buf.push_back(isc_api::ibp_isc_info_sql_relation);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back('B');
 }//for n

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__mult_def_of_xsqvar_field_value
   (tracer,
    exc.get_record(0),
    L"relname");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_A06__bug_check__mult_def_of_xvar_field__relname

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_A07__bug_check__mult_def_of_xvar_field__ownname
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 xsqlda->sqld=4;

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(4);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 for(size_t n=0;n!=2;++n)
 {
  buf.push_back(isc_api::ibp_isc_info_sql_owner);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back('C');
 }//for n

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__mult_def_of_xsqvar_field_value
   (tracer,
    exc.get_record(0),
    L"ownname");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_A07__bug_check__mult_def_of_xvar_field__ownname

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_A08__bug_check__mult_def_of_xvar_field__aliasname
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 xsqlda->sqld=4;

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(4);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 for(size_t n=0;n!=2;++n)
 {
  buf.push_back(isc_api::ibp_isc_info_sql_alias);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back('D');
 }//for n

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__mult_def_of_xsqvar_field_value
   (tracer,
    exc.get_record(0),
    L"aliasname");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_A08__bug_check__mult_def_of_xvar_field__aliasname

////////////////////////////////////////////////////////////////////////////////

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_B01__bug_check__not_def_xvar_field__sqltype
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 //{
 // buf.push_back(isc_api::ibp_isc_info_sql_type);
 // buf.push_back(2);
 // buf.push_back(0);
 //
 // isc_base::isc_integer_to_portable_format::tag_buffer<2> p;
 // isc_base::isc_integer_to_portable_format::exec<2,unsigned short>(&p,isc_api::ibp_isc_sql_long);
 // std::copy(p.data,_END_(p.data),std::back_inserter(buf));
 //}

 {
  buf.push_back(isc_api::ibp_isc_info_sql_sub_type);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(1);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_scale);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(0xFF);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_length);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(4);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_field);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back('A');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_relation);
  buf.push_back(2);
  buf.push_back(0);
  buf.push_back('B');
  buf.push_back('C');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_owner);
  buf.push_back(3);
  buf.push_back(0);
  buf.push_back('D');
  buf.push_back('E');
  buf.push_back('F');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_alias);
  buf.push_back(4);
  buf.push_back(0);
  buf.push_back('G');
  buf.push_back('H');
  buf.push_back('I');
  buf.push_back('J');
 }

 buf.push_back(isc_api::ibp_isc_info_sql_describe_end);
 buf.push_back(isc_api::ibp_isc_info_end);

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__not_def_xsqvar_field
   (tracer,
    exc.get_record(0),
    L"sqltype");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_B01__bug_check__not_def_xvar_field__sqltype

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_B02__bug_check__not_def_xvar_field__sqlsubtype
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 {
  buf.push_back(isc_api::ibp_isc_info_sql_type);
  buf.push_back(2);
  buf.push_back(0);

  isc_base::isc_integer_to_portable_format::tag_buffer<2> p;
  isc_base::isc_integer_to_portable_format::exec<2,unsigned short>(&p,isc_api::ibp_isc_sql_long);
  std::copy(p.data,_END_(p.data),std::back_inserter(buf));
 }

 //{
 // buf.push_back(isc_api::ibp_isc_info_sql_sub_type);
 // buf.push_back(1);
 // buf.push_back(0);
 // buf.push_back(1);
 //}

 {
  buf.push_back(isc_api::ibp_isc_info_sql_scale);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(0xFF);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_length);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(4);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_field);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back('A');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_relation);
  buf.push_back(2);
  buf.push_back(0);
  buf.push_back('B');
  buf.push_back('C');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_owner);
  buf.push_back(3);
  buf.push_back(0);
  buf.push_back('D');
  buf.push_back('E');
  buf.push_back('F');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_alias);
  buf.push_back(4);
  buf.push_back(0);
  buf.push_back('G');
  buf.push_back('H');
  buf.push_back('I');
  buf.push_back('J');
 }

 buf.push_back(isc_api::ibp_isc_info_sql_describe_end);
 buf.push_back(isc_api::ibp_isc_info_end);

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__not_def_xsqvar_field
   (tracer,
    exc.get_record(0),
    L"sqlsubtype");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_B02__bug_check__not_def_xvar_field__sqlsubtype

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_B03__bug_check__not_def_xvar_field__sqlscale
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 {
  buf.push_back(isc_api::ibp_isc_info_sql_type);
  buf.push_back(2);
  buf.push_back(0);

  isc_base::isc_integer_to_portable_format::tag_buffer<2> p;
  isc_base::isc_integer_to_portable_format::exec<2,unsigned short>(&p,isc_api::ibp_isc_sql_long);
  std::copy(p.data,_END_(p.data),std::back_inserter(buf));
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_sub_type);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(1);
 }

 //{
 // buf.push_back(isc_api::ibp_isc_info_sql_scale);
 // buf.push_back(1);
 // buf.push_back(0);
 // buf.push_back(0xFF);
 //}

 {
  buf.push_back(isc_api::ibp_isc_info_sql_length);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(4);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_field);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back('A');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_relation);
  buf.push_back(2);
  buf.push_back(0);
  buf.push_back('B');
  buf.push_back('C');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_owner);
  buf.push_back(3);
  buf.push_back(0);
  buf.push_back('D');
  buf.push_back('E');
  buf.push_back('F');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_alias);
  buf.push_back(4);
  buf.push_back(0);
  buf.push_back('G');
  buf.push_back('H');
  buf.push_back('I');
  buf.push_back('J');
 }

 buf.push_back(isc_api::ibp_isc_info_sql_describe_end);
 buf.push_back(isc_api::ibp_isc_info_end);

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__not_def_xsqvar_field
   (tracer,
    exc.get_record(0),
    L"sqlscale");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_B03__bug_check__not_def_xvar_field__sqlscale

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_B04__bug_check__not_def_xvar_field__sqllen
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 {
  buf.push_back(isc_api::ibp_isc_info_sql_type);
  buf.push_back(2);
  buf.push_back(0);

  isc_base::isc_integer_to_portable_format::tag_buffer<2> p;
  isc_base::isc_integer_to_portable_format::exec<2,unsigned short>(&p,isc_api::ibp_isc_sql_long);
  std::copy(p.data,_END_(p.data),std::back_inserter(buf));
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_sub_type);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(1);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_scale);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(0xFF);
 }

 //{
 // buf.push_back(isc_api::ibp_isc_info_sql_length);
 // buf.push_back(1);
 // buf.push_back(0);
 // buf.push_back(4);
 //}

 {
  buf.push_back(isc_api::ibp_isc_info_sql_field);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back('A');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_relation);
  buf.push_back(2);
  buf.push_back(0);
  buf.push_back('B');
  buf.push_back('C');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_owner);
  buf.push_back(3);
  buf.push_back(0);
  buf.push_back('D');
  buf.push_back('E');
  buf.push_back('F');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_alias);
  buf.push_back(4);
  buf.push_back(0);
  buf.push_back('G');
  buf.push_back('H');
  buf.push_back('I');
  buf.push_back('J');
 }

 buf.push_back(isc_api::ibp_isc_info_sql_describe_end);
 buf.push_back(isc_api::ibp_isc_info_end);

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__not_def_xsqvar_field
   (tracer,
    exc.get_record(0),
    L"sqllen");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_B04__bug_check__not_def_xvar_field__sqllen

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_B05__bug_check__not_def_xvar_field__sqlname
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 {
  buf.push_back(isc_api::ibp_isc_info_sql_type);
  buf.push_back(2);
  buf.push_back(0);

  isc_base::isc_integer_to_portable_format::tag_buffer<2> p;
  isc_base::isc_integer_to_portable_format::exec<2,unsigned short>(&p,isc_api::ibp_isc_sql_long);
  std::copy(p.data,_END_(p.data),std::back_inserter(buf));
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_sub_type);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(1);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_scale);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(0xFF);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_length);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(4);
 }

 //{
 // buf.push_back(isc_api::ibp_isc_info_sql_field);
 // buf.push_back(1);
 // buf.push_back(0);
 // buf.push_back('A');
 //}

 {
  buf.push_back(isc_api::ibp_isc_info_sql_relation);
  buf.push_back(2);
  buf.push_back(0);
  buf.push_back('B');
  buf.push_back('C');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_owner);
  buf.push_back(3);
  buf.push_back(0);
  buf.push_back('D');
  buf.push_back('E');
  buf.push_back('F');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_alias);
  buf.push_back(4);
  buf.push_back(0);
  buf.push_back('G');
  buf.push_back('H');
  buf.push_back('I');
  buf.push_back('J');
 }

 buf.push_back(isc_api::ibp_isc_info_sql_describe_end);
 buf.push_back(isc_api::ibp_isc_info_end);

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__not_def_xsqvar_field
   (tracer,
    exc.get_record(0),
    L"sqlname");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_B05__bug_check__not_def_xvar_field__sqlname

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_B06__bug_check__not_def_xvar_field__relname
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 {
  buf.push_back(isc_api::ibp_isc_info_sql_type);
  buf.push_back(2);
  buf.push_back(0);

  isc_base::isc_integer_to_portable_format::tag_buffer<2> p;
  isc_base::isc_integer_to_portable_format::exec<2,unsigned short>(&p,isc_api::ibp_isc_sql_long);
  std::copy(p.data,_END_(p.data),std::back_inserter(buf));
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_sub_type);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(1);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_scale);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(0xFF);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_length);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(4);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_field);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back('A');
 }

 //{
 // buf.push_back(isc_api::ibp_isc_info_sql_relation);
 // buf.push_back(2);
 // buf.push_back(0);
 // buf.push_back('B');
 // buf.push_back('C');
 //}

 {
  buf.push_back(isc_api::ibp_isc_info_sql_owner);
  buf.push_back(3);
  buf.push_back(0);
  buf.push_back('D');
  buf.push_back('E');
  buf.push_back('F');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_alias);
  buf.push_back(4);
  buf.push_back(0);
  buf.push_back('G');
  buf.push_back('H');
  buf.push_back('I');
  buf.push_back('J');
 }

 buf.push_back(isc_api::ibp_isc_info_sql_describe_end);
 buf.push_back(isc_api::ibp_isc_info_end);

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__not_def_xsqvar_field
   (tracer,
    exc.get_record(0),
    L"relname");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_B06__bug_check__not_def_xvar_field__relname

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_B07__bug_check__not_def_xvar_field__ownname
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 {
  buf.push_back(isc_api::ibp_isc_info_sql_type);
  buf.push_back(2);
  buf.push_back(0);

  isc_base::isc_integer_to_portable_format::tag_buffer<2> p;
  isc_base::isc_integer_to_portable_format::exec<2,unsigned short>(&p,isc_api::ibp_isc_sql_long);
  std::copy(p.data,_END_(p.data),std::back_inserter(buf));
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_sub_type);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(1);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_scale);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(0xFF);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_length);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(4);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_field);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back('A');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_relation);
  buf.push_back(2);
  buf.push_back(0);
  buf.push_back('B');
  buf.push_back('C');
 }

 //{
 // buf.push_back(isc_api::ibp_isc_info_sql_owner);
 // buf.push_back(3);
 // buf.push_back(0);
 // buf.push_back('D');
 // buf.push_back('E');
 // buf.push_back('F');
 //}

 {
  buf.push_back(isc_api::ibp_isc_info_sql_alias);
  buf.push_back(4);
  buf.push_back(0);
  buf.push_back('G');
  buf.push_back('H');
  buf.push_back('I');
  buf.push_back('J');
 }

 buf.push_back(isc_api::ibp_isc_info_sql_describe_end);
 buf.push_back(isc_api::ibp_isc_info_end);

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__not_def_xsqvar_field
   (tracer,
    exc.get_record(0),
    L"ownname");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_B07__bug_check__not_def_xvar_field__ownname

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::test_B08__bug_check__not_def_xvar_field__aliasname
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(4);

 //-----------------------------------------
 structure::t_fix_vector<128,unsigned char> buf;

 buf.push_back(isc_api::ibp_isc_info_sql_describe_vars);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 buf.push_back(isc_api::ibp_isc_info_sql_sqlda_seq);
 buf.push_back(1);
 buf.push_back(0);
 buf.push_back(1);

 {
  buf.push_back(isc_api::ibp_isc_info_sql_type);
  buf.push_back(2);
  buf.push_back(0);

  isc_base::isc_integer_to_portable_format::tag_buffer<2> p;
  isc_base::isc_integer_to_portable_format::exec<2,unsigned short>(&p,isc_api::ibp_isc_sql_long);
  std::copy(p.data,_END_(p.data),std::back_inserter(buf));
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_sub_type);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(1);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_scale);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(0xFF);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_length);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back(4);
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_field);
  buf.push_back(1);
  buf.push_back(0);
  buf.push_back('A');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_relation);
  buf.push_back(2);
  buf.push_back(0);
  buf.push_back('B');
  buf.push_back('C');
 }

 {
  buf.push_back(isc_api::ibp_isc_info_sql_owner);
  buf.push_back(3);
  buf.push_back(0);
  buf.push_back('D');
  buf.push_back('E');
  buf.push_back('F');
 }

 //{
 // buf.push_back(isc_api::ibp_isc_info_sql_alias);
 // buf.push_back(4);
 // buf.push_back(0);
 // buf.push_back('G');
 // buf.push_back('H');
 // buf.push_back('I');
 // buf.push_back('J');
 //}

 buf.push_back(isc_api::ibp_isc_info_sql_describe_end);
 buf.push_back(isc_api::ibp_isc_info_end);

 try
 {
  remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA
   (buf.size(),
    buf.data(),
    /*is_first_info_block*/true,
    0,
    xsqlda);//throw
 }
 catch(const ibp::t_ibp_error& exc)
 {
  typedef TestCheckErrors errSvc;

  errSvc::print_exception_ok(tracer,exc);

  errSvc::check_err_count(exc,2);

  errSvc::check_err_rec__xsqlda_info_data_bug_check__not_def_xsqvar_field
   (tracer,
    exc.get_record(0),
    L"aliasname");

  errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
   (tracer,
    exc.get_record(1),
    errSvc::sm_subsysID__remote_fb_p12,
    0);

  return;
 }//catch

 throw std::runtime_error("We wait the exception!");
}//test_B08__bug_check__not_def_xvar_field__aliasname

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_descr

struct TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_impl::func},

const TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::tag_descr
 TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::sm_Tests[]=
{
 DEF_TEST_DESCR("001.bug_check.empty_buffer",
                test_001___bug_check__empty_buf)
 DEF_TEST_DESCR("002.bug_check.no_sql_describe_vars",
                test_002___bug_check__no_sql_describe_vars)
 DEF_TEST_DESCR("003.bug_check.bad_format.sql_describe_vars",
                test_003___bug_check__bad_format_of_sql_describe_vars)
#ifdef NDEBUG
 DEF_TEST_DESCR("004.bug_check.too_large_value.sql_describe_vars",
                test_004___bug_check__too_large_value_of_sql_describe_vars)
#endif
 DEF_TEST_DESCR("005.bug_check.too_large_number.sql_describe_vars",
                test_005___bug_check__too_large_number_of_sql_describe_vars)
 DEF_TEST_DESCR("006.bug_check.sqld_is_too_large",
                test_006___bug_check__sqld_is_too_large)
 DEF_TEST_DESCR("007.sqln_less_than_sqld",
                test_007__sqln_less_than_sqld)
 DEF_TEST_DESCR("008.bug_check.second_block.mutable_sqld",
                test_008__bug_check__second_block__mutable_sqld)
 DEF_TEST_DESCR("009.bug_check.incorrect_seq_ordinal",
                test_009__bug_check__out_of_range_seq_number)
 DEF_TEST_DESCR("009.bug_check.incorrect_seq_ordinal_0",
                test_009__bug_check__out_of_range_seq_number_0)
 DEF_TEST_DESCR("010.bug_check.unexpected_elements_for_XSQLDA",
                test_010__bug_check__unexpected_elements_for_XSQLDA)
 DEF_TEST_DESCR("011.bug_check.unexpected_truncation",
                test_011__bug_check__unexpected_truncation)
 DEF_TEST_DESCR("012.bug_check.unexpected_seq_number",
                test_012__bug_check__unexpected_seq_number)
 DEF_TEST_DESCR("013.bug_check.unexpected_end_of_seq",
                 test_013__bug_check__unexpected_end_of_seq)
 DEF_TEST_DESCR("014.bug_check.unk_element_in_xvar_definition",
                 test_014__bug_check__unk_element_in_xvar_definition)
 DEF_TEST_DESCR("015.ok.xsqlvar1",
                 test_015__ok__xsqlvar1)
 DEF_TEST_DESCR("016.bug_check.negative_sqllen",
                 test_016__bug_check__negative_sqllen)
 DEF_TEST_DESCR("017.bug_check.incompleted_def_of_xsqlvars_0",
                test_017__bug_check__incompleted_def_of_xsqlvars_0)
 DEF_TEST_DESCR("017.bug_check.incompleted_def_of_xsqlvars_1",
                test_017__bug_check__incompleted_def_of_xsqlvars_1)

 DEF_TEST_DESCR("A01.bug_check.mult_def_of_xvar_field.sqltype",
                 test_A01__bug_check__mult_def_of_xvar_field__sqltype)
 DEF_TEST_DESCR("A02.bug_check.mult_def_of_xvar_field.sqlsubtype",
                 test_A02__bug_check__mult_def_of_xvar_field__sqlsubtype)
 DEF_TEST_DESCR("A03.bug_check.mult_def_of_xvar_field.sqlscale",
                 test_A03__bug_check__mult_def_of_xvar_field__sqlscale)
 DEF_TEST_DESCR("A04.bug_check.mult_def_of_xvar_field.sqllen",
                 test_A04__bug_check__mult_def_of_xvar_field__sqllen)
 DEF_TEST_DESCR("A05.bug_check.mult_def_of_xvar_field.sqlname",
                 test_A05__bug_check__mult_def_of_xvar_field__sqlname)
 DEF_TEST_DESCR("A06.bug_check.mult_def_of_xvar_field.relname",
                 test_A06__bug_check__mult_def_of_xvar_field__relname)
 DEF_TEST_DESCR("A07.bug_check.mult_def_of_xvar_field.ownname",
                 test_A07__bug_check__mult_def_of_xvar_field__ownname)
 DEF_TEST_DESCR("A08.bug_check.mult_def_of_xvar_field.aliasname",
                 test_A08__bug_check__mult_def_of_xvar_field__aliasname)

 DEF_TEST_DESCR("B01.bug_check.not_def_xvar_field.sqltype",
                 test_B01__bug_check__not_def_xvar_field__sqltype)
 DEF_TEST_DESCR("A02.bug_check.not_def_xvar_field.sqlsubtype",
                 test_B02__bug_check__not_def_xvar_field__sqlsubtype)
 DEF_TEST_DESCR("B03.bug_check.not_def_xvar_field.sqlscale",
                 test_B03__bug_check__not_def_xvar_field__sqlscale)
 DEF_TEST_DESCR("B04.bug_check.not_def_xvar_field.sqllen",
                 test_B04__bug_check__not_def_xvar_field__sqllen)
 DEF_TEST_DESCR("B05.bug_check.not_def_xvar_field.sqlname",
                 test_B05__bug_check__not_def_xvar_field__sqlname)
 DEF_TEST_DESCR("B06.bug_check.not_def_xvar_field.relname",
                 test_B06__bug_check__not_def_xvar_field__relname)
 DEF_TEST_DESCR("B07.bug_check.not_def_xvar_field.ownname",
                 test_B07__bug_check__not_def_xvar_field__ownname)
 DEF_TEST_DESCR("B08.bug_check.not_def_xvar_field.aliasname",
                 test_B08__bug_check__not_def_xvar_field__aliasname)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Parse_XSQLDA::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter ftestID("RemoteFB.API.HLP.XSQLDA_V01_Utilities.Parse_XSQLDA.%1");

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
