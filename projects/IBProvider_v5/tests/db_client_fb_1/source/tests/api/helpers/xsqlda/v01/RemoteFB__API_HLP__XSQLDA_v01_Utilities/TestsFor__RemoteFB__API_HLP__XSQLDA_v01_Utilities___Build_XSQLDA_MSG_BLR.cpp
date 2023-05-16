////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/api/helpers/xsqlda/v01/RemoteFB__API_HLP__XSQLDA_v01_Utilities/TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR.h"
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
//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl

class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl
{
 private:
  typedef tag_impl                                              self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type                               context_type;

  typedef remote_fb::api::helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities  xsqlda_utils_type;

 public:
  static void test_001___null_ptr
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_002___empty
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_003___err__unk_sql_type
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_004___bug_check__negative_sqllen
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_t01___bug_check__incorrect_sqllen__varchar
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t02___bug_check__incorrect_sqllen__short
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t03___bug_check__incorrect_sqllen__long
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t04___bug_check__incorrect_sqllen__int64
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t05___bug_check__incorrect_sqllen__float
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t06___bug_check__incorrect_sqllen__double
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t07___bug_check__incorrect_sqllen__time
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t08___bug_check__incorrect_sqllen__date
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t09___bug_check__incorrect_sqllen__timestamp
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t10___bug_check__incorrect_sqllen__blob
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t11___bug_check__incorrect_sqllen__array
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t12___bug_check__incorrect_sqllen__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t13___bug_check__incorrect_sqllen__boolean
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t14___bug_check__incorrect_sqllen__int128
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
 private:
  static void helper_txx
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx,
                short               sqltype,
                short               sqllen,
                const wchar_t*      sqlTypeSign);

 public:
  static void test_s01___bug_check__incorrect_sqlscale__short
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_s02___bug_check__incorrect_sqlscale__long
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_s03___bug_check__incorrect_sqlscale__int64
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_s04___bug_check__incorrect_sqlscale__int128
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 private:
  static void helper_sxx
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx,
                short               sqltype,
                short               sqllen,
                short               sqlscale,
                const wchar_t*      sqlTypeSign);

 public:
  static void test_d01__varchar
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d02__char
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d03__short
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d04__long
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d05__int64
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d06__float
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d07__double
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d08__time
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d09__date
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d10__timestamp
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d11__blob
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d12__array
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d13__sql_null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d14__short_scale1
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d15__long_scale7
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d16__int64_scale16
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d17__boolean
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d18__int128
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d19__int128_scale37
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
};//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_001___null_ptr
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 xsqlda_utils_type::msg_blr_buffer_type buf(100);

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(nullptr,buf);

 _TSO_CHECK(buf.empty());
}//test_001___null_ptr

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_002___empty
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 xsqlda_utils_type::msg_blr_buffer_type buf(100);

 XSQLDA_V1_Wrapper xsqlda(0);

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 _TSO_CHECK(buf.empty());
}//test_002___empty

////////////////////////////////////////////////////////////////////////////////
//TEST 003

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_003___err__unk_sql_type
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf(100);

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=24;

 for(;;)
 {
  try
  {
   xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   errSvc::check_err_rec__common__internal_err__unk_sql_type
    (tracer,
     exc.get_record(0),
     errSvc::sm_subsysID__remote_fb,
     0,
     24);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_003___err__unk_sql_type

////////////////////////////////////////////////////////////////////////////////
//TEST 004

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_004___bug_check__negative_sqllen
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf(100);

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long;
 xsqlda->sqlvar[0].sqllen =-4;

 for(;;)
 {
  try
  {
   xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   errSvc::check_err_rec__xsqlda_info_data_bug_check__negative_sqllen
    (tracer,
     exc.get_record(0),
     errSvc::sm_subsysID__remote_fb,
     -4);

   errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_data
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__remote_fb,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_004___bug_check__negative_sqllen

////////////////////////////////////////////////////////////////////////////////
//TEST T01

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_t01___bug_check__incorrect_sqllen__varchar
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_varying,
            SHRT_MAX,
            L"sql_varying");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_varying|1,
            SHRT_MAX,
            L"sql_varying");
}//test_t01___bug_check__incorrect_sqllen__varchar

////////////////////////////////////////////////////////////////////////////////
//TEST T02

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_t02___bug_check__incorrect_sqllen__short
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_short,
            1,
            L"sql_short");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_short|1,
            3,
            L"sql_short");
}//test_t02___bug_check__incorrect_sqllen__short

////////////////////////////////////////////////////////////////////////////////
//TEST T03

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_t03___bug_check__incorrect_sqllen__long
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_long,
            3,
            L"sql_long");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_long|1,
            5,
            L"sql_long");
}//test_t03___bug_check__incorrect_sqllen__long

////////////////////////////////////////////////////////////////////////////////
//TEST T04

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_t04___bug_check__incorrect_sqllen__int64
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_int64,
            7,
            L"sql_int64");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_int64|1,
            9,
            L"sql_int64");
}//test_t04___bug_check__incorrect_sqllen__int64

////////////////////////////////////////////////////////////////////////////////
//TEST T05

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_t05___bug_check__incorrect_sqllen__float
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_float,
            3,
            L"sql_float");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_float|1,
            5,
            L"sql_float");
}//test_t05___bug_check__incorrect_sqllen__float

////////////////////////////////////////////////////////////////////////////////
//TEST T06

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_t06___bug_check__incorrect_sqllen__double
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_double,
            7,
            L"sql_double");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_double|1,
            9,
            L"sql_double");
}//test_t06___bug_check__incorrect_sqllen__double

////////////////////////////////////////////////////////////////////////////////
//TEST T07

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_t07___bug_check__incorrect_sqllen__time
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_type_time,
            3,
            L"sql_type_time");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_type_time|1,
            5,
            L"sql_type_time");
}//test_t07___bug_check__incorrect_sqllen__time

////////////////////////////////////////////////////////////////////////////////
//TEST T08

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_t08___bug_check__incorrect_sqllen__date
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_type_date,
            3,
            L"sql_type_date");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_type_date|1,
            5,
            L"sql_type_date");
}//test_t08___bug_check__incorrect_sqllen__date

////////////////////////////////////////////////////////////////////////////////
//TEST T09

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_t09___bug_check__incorrect_sqllen__timestamp
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_timestamp,
            7,
            L"sql_timestamp");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_timestamp|1,
            9,
            L"sql_timestamp");
}//test_t09___bug_check__incorrect_sqllen__timestamp

////////////////////////////////////////////////////////////////////////////////
//TEST T10

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_t10___bug_check__incorrect_sqllen__blob
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_blob,
            7,
            L"sql_blob");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_blob|1,
            9,
            L"sql_blob");
}//test_t10___bug_check__incorrect_sqllen__blob

////////////////////////////////////////////////////////////////////////////////
//TEST T11

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_t11___bug_check__incorrect_sqllen__array
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_array,
            7,
            L"sql_array");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_array|1,
            9,
            L"sql_array");
}//test_t11___bug_check__incorrect_sqllen__array

////////////////////////////////////////////////////////////////////////////////
//TEST T12

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_t12___bug_check__incorrect_sqllen__null
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_fb025_sql_null,
            1,
            L"sql_null");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_fb025_sql_null|1,
            2,
            L"sql_null");
}//test_t12___bug_check__incorrect_sqllen__null

////////////////////////////////////////////////////////////////////////////////
//TEST T13

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_t13___bug_check__incorrect_sqllen__boolean
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_fb030_sql_boolean,
            3,
            L"sql_boolean");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_fb030_sql_boolean|1,
            5,
            L"sql_boolean");
}//test_t13___bug_check__incorrect_sqllen__boolean

////////////////////////////////////////////////////////////////////////////////
//TEST T14

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_t14___bug_check__incorrect_sqllen__int128
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_fb040_sql_int128,
            15,
            L"sql_int128");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_fb040_sql_int128|1,
            17,
            L"sql_int128");
}//test_t14___bug_check__incorrect_sqllen__int128

////////////////////////////////////////////////////////////////////////////////
//HELPER TXX

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::helper_txx
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx,
                                            short               const sqltype,
                                            short               const sqllen,
                                            const wchar_t*      const sqlTypeSign)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf(100);

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=sqltype;
 xsqlda->sqlvar[0].sqllen =sqllen;

 for(;;)
 {
  try
  {
   xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   errSvc::check_err_rec__xsqlda_err__incorrect_sqllen
    (tracer,
     exc.get_record(0),
     sqlTypeSign,
     sqllen);

   errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_data
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__remote_fb,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//helper_txx

////////////////////////////////////////////////////////////////////////////////
//TEST S01

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_s01___bug_check__incorrect_sqlscale__short
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_sxx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_short,
            2,
            1,
            L"sql_short");

 helper_sxx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_short|1,
            2,
            -5,
            L"sql_short");
}//test_s01___bug_check__incorrect_sqlscale__short

////////////////////////////////////////////////////////////////////////////////
//TEST S02

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_s02___bug_check__incorrect_sqlscale__long
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_sxx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_long,
            4,
            1,
            L"sql_long");

 helper_sxx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_long|1,
            4,
            -10,
            L"sql_long");
}//test_s02___bug_check__incorrect_sqlscale__long

////////////////////////////////////////////////////////////////////////////////
//TEST S03

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_s03___bug_check__incorrect_sqlscale__int64
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_sxx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_int64,
            8,
            1,
            L"sql_int64");

 helper_sxx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_int64|1,
            8,
            -19,
            L"sql_int64");
}//test_s03___bug_check__incorrect_sqlscale__int64

////////////////////////////////////////////////////////////////////////////////
//TEST S04

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_s04___bug_check__incorrect_sqlscale__int128
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_sxx(pParams,
            pCtx,
            isc_api::ibp_fb040_sql_int128,
            16,
            1,
            L"sql_int128");

 helper_sxx(pParams,
            pCtx,
            isc_api::ibp_fb040_sql_int128|1,
            16,
            -39,
            L"sql_int128");
}//test_s04___bug_check__incorrect_sqlscale__int128

////////////////////////////////////////////////////////////////////////////////
//HELPER SXX

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::helper_sxx
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx,
                                            short               const sqltype,
                                            short               const sqllen,
                                            short               const sqlscale,
                                            const wchar_t*      const sqlTypeSign)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf(100);

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =sqltype;
 xsqlda->sqlvar[0].sqllen   =sqllen;
 xsqlda->sqlvar[0].sqlscale =sqlscale;

 for(;;)
 {
  try
  {
   xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   errSvc::check_err_rec__xsqlda_err__incorrect_sqlscale
    (tracer,
     exc.get_record(0),
     sqlTypeSign,
     sqlscale);

   errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_data
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__remote_fb,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//helper_sxx

////////////////////////////////////////////////////////////////////////////////
//D01

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d01__varchar
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 const size_t c_len=12345;

 struct tag_varying
 {
  short len;
  char  data[c_len];

  tag_varying()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_varying

 const std::unique_ptr<tag_varying> var(new tag_varying());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_varying;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__varying,
  LOBYTE(c_len),
  HIBYTE(c_len),
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d01__varchar

////////////////////////////////////////////////////////////////////////////////
//D02

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d02__char
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 const size_t c_len=SHRT_MAX;

 struct tag_data
 {
  char  data[c_len];

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_text;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__text,
  LOBYTE(c_len),
  HIBYTE(c_len),
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d02__char

////////////////////////////////////////////////////////////////////////////////
//D03

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d03__short
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  db_obj::t_dbvalue__i2  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_short;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0, //scale
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d03__short

////////////////////////////////////////////////////////////////////////////////
//D04

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d04__long
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  db_obj::t_dbvalue__i4  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_long;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__long,
  0, //scale
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d04__long

////////////////////////////////////////////////////////////////////////////////
//D05

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d05__int64
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  db_obj::t_dbvalue__i8  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_int64;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__int64,
  0, //scale
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d05__int64

////////////////////////////////////////////////////////////////////////////////
//D06

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d06__float
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  db_obj::t_dbvalue__r4  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_float;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__float,
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d06__float

////////////////////////////////////////////////////////////////////////////////
//D07

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d07__double
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  db_obj::t_dbvalue__r8  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_double;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__double,
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d07__double

////////////////////////////////////////////////////////////////////////////////
//D08

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d08__time
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  isc_api::t_ibp_isc_time  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_type_time;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__sql_time,
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d08__time

////////////////////////////////////////////////////////////////////////////////
//D09

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d09__date
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  isc_api::t_ibp_isc_date  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_type_date;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__sql_date,
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d09__date

////////////////////////////////////////////////////////////////////////////////
//D10

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d10__timestamp
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  isc_api::t_ibp_isc_timestamp  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_timestamp;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__timestamp,
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d10__timestamp

////////////////////////////////////////////////////////////////////////////////
//D11

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d11__blob
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  db_obj::DB_IBBLOBID  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_blob;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__quad,
  0, //scale?
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d11__blob

////////////////////////////////////////////////////////////////////////////////
//D12

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d12__array
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  db_obj::DB_IBARRAYID  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_array;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__quad,
  0, //scale?
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d12__array

////////////////////////////////////////////////////////////////////////////////
//D13

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d13__sql_null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_fb025_sql_null;
 xsqlda->sqlvar[0].sqllen   =0;
 xsqlda->sqlvar[0].sqldata  =nullptr;

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__text,
  0,
  0,
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d13__sql_null

////////////////////////////////////////////////////////////////////////////////
//D03

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d14__short_scale1
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  db_obj::t_dbvalue__i2  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_short;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqlscale =-1;
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__short,
  (unsigned char)-1, //scale
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d14__short_scale1

////////////////////////////////////////////////////////////////////////////////
//D15

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d15__long_scale7
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  db_obj::t_dbvalue__i4  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_long;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqlscale =-7;
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__long,
  (unsigned char)-7, //scale
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d15__long_scale7

////////////////////////////////////////////////////////////////////////////////
//D16

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d16__int64_scale16
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  db_obj::t_dbvalue__i8  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_int64;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqlscale =-16;
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_isc_blr_dtype__int64,
  (unsigned char)-16, //scale
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d16__int64_scale16

////////////////////////////////////////////////////////////////////////////////
//D17

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d17__boolean
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  isc_api::t_ibp_fb030_bool  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_fb030_sql_boolean;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_fb030_blr_dtype__bool,
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d17__boolean

////////////////////////////////////////////////////////////////////////////////
//D18

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d18__int128
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  db_obj::t_dbvalue__fb040_int128  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_fb040_sql_int128;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_fb040_blr_dtype__int128,
  0, //scale
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d18__int128

////////////////////////////////////////////////////////////////////////////////
//D19

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::test_d19__int128_scale37
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_data
 {
  db_obj::t_dbvalue__fb040_int128  data;

  tag_data()
  {
   memset(this,0,sizeof(*this));
  }
 };//struct tag_data

 const std::unique_ptr<tag_data> var(new tag_data());

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_fb040_sql_int128;
 xsqlda->sqlvar[0].sqllen   =sizeof(var->data);
 xsqlda->sqlvar[0].sqlscale =-37;
 xsqlda->sqlvar[0].sqldata  =reinterpret_cast<char*>(var.get());

 //-----------------------------------------
 xsqlda_utils_type::msg_blr_buffer_type buf;

 xsqlda_utils_type::Build_XSQLDA_MSG_BLR(xsqlda,buf);

 unsigned char c_expected_blr[]=
 {
  isc_api::ibp_isc_blr_version5,
  isc_api::ibp_isc_blr_begin,
  isc_api::ibp_isc_blr_message,
  0,
  2, //cPars.low
  0, //cPars.high
  //----
  isc_api::ibp_fb040_blr_dtype__int128,
  (unsigned char)-37, //scale
  //----
  isc_api::ibp_isc_blr_dtype__short,
  0,
  //----
  isc_api::ibp_isc_blr_end,
  isc_api::ibp_isc_blr_eoc,
 };//c_expected_blr

 _TSO_CHECK(structure::equal(c_expected_blr,
                             _END_(c_expected_blr),
                             buf.buffer(),
                             buf.buffer_end()));
}//test_d19__int128_scale37

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_descr

struct TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_impl::func},

const TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::tag_descr
 TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::sm_Tests[]=
{
 DEF_TEST_DESCR("001.null_ptr",
                test_001___null_ptr)
 DEF_TEST_DESCR("002.empty",
                test_002___empty)
 DEF_TEST_DESCR("003.err.unk_sql_type",
                test_003___err__unk_sql_type)
 DEF_TEST_DESCR("004.bug_check.negative_sqllen",
                test_004___bug_check__negative_sqllen)

 DEF_TEST_DESCR("T01.bug_check.incorrect_sqllen.varying",
                test_t01___bug_check__incorrect_sqllen__varchar)
 DEF_TEST_DESCR("T02.bug_check.incorrect_sqllen.short",
                test_t02___bug_check__incorrect_sqllen__short)
 DEF_TEST_DESCR("T03.bug_check.incorrect_sqllen.long",
                test_t03___bug_check__incorrect_sqllen__long)
 DEF_TEST_DESCR("T04.bug_check.incorrect_sqllen.int64",
                test_t04___bug_check__incorrect_sqllen__int64)
 DEF_TEST_DESCR("T05.bug_check.incorrect_sqllen.float",
                test_t05___bug_check__incorrect_sqllen__float)
 DEF_TEST_DESCR("T06.bug_check.incorrect_sqllen.double",
                test_t06___bug_check__incorrect_sqllen__double)
 DEF_TEST_DESCR("T07.bug_check.incorrect_sqllen.time",
                test_t07___bug_check__incorrect_sqllen__time)
 DEF_TEST_DESCR("T08.bug_check.incorrect_sqllen.date",
                test_t08___bug_check__incorrect_sqllen__date)
 DEF_TEST_DESCR("T09.bug_check.incorrect_sqllen.timestamp",
                test_t09___bug_check__incorrect_sqllen__timestamp)
 DEF_TEST_DESCR("T10.bug_check.incorrect_sqllen.blob",
                test_t10___bug_check__incorrect_sqllen__blob)
 DEF_TEST_DESCR("T11.bug_check.incorrect_sqllen.array",
                test_t11___bug_check__incorrect_sqllen__array)
 DEF_TEST_DESCR("T12.bug_check.incorrect_sqllen.null",
                test_t12___bug_check__incorrect_sqllen__null)
 DEF_TEST_DESCR("T13.bug_check.incorrect_sqllen.boolean",
                test_t13___bug_check__incorrect_sqllen__boolean)
 DEF_TEST_DESCR("T14.bug_check.incorrect_sqllen.int128",
                test_t14___bug_check__incorrect_sqllen__int128)

 DEF_TEST_DESCR("S01.bug_check.incorrect_sqlscale.short",
                test_s01___bug_check__incorrect_sqlscale__short)
 DEF_TEST_DESCR("S02.bug_check.incorrect_sqlscale.long",
                test_s02___bug_check__incorrect_sqlscale__long)
 DEF_TEST_DESCR("S03.bug_check.incorrect_sqlscale.int64",
                test_s03___bug_check__incorrect_sqlscale__int64)
 DEF_TEST_DESCR("S04.bug_check.incorrect_sqlscale.int128",
                test_s04___bug_check__incorrect_sqlscale__int128)

 DEF_TEST_DESCR("D01.varchar",
                 test_d01__varchar)
 DEF_TEST_DESCR("D02.char",
                 test_d02__char)
 DEF_TEST_DESCR("D03.short",
                 test_d03__short)
 DEF_TEST_DESCR("D04.long",
                 test_d04__long)
 DEF_TEST_DESCR("D05.int64",
                 test_d05__int64)
 DEF_TEST_DESCR("D06.float",
                 test_d06__float)
 DEF_TEST_DESCR("D07.double",
                 test_d07__double)
 DEF_TEST_DESCR("D08.time",
                 test_d08__time)
 DEF_TEST_DESCR("D09.date",
                 test_d09__date)
 DEF_TEST_DESCR("D10.timestamp",
                 test_d10__timestamp)
 DEF_TEST_DESCR("D11.blob",
                 test_d11__blob)
 DEF_TEST_DESCR("D12.array",
                 test_d12__array)
 DEF_TEST_DESCR("D13.sql_null",
                 test_d13__sql_null)
 DEF_TEST_DESCR("D14.short.scale1",
                 test_d14__short_scale1)
 DEF_TEST_DESCR("D15.long.scale7",
                 test_d15__long_scale7)
 DEF_TEST_DESCR("D16.int64.scale16",
                 test_d16__int64_scale16)
 DEF_TEST_DESCR("D17.boolean",
                 test_d17__boolean)
 DEF_TEST_DESCR("D18.int128",
                 test_d18__int128)
 DEF_TEST_DESCR("D19.int128.scale37",
                 test_d19__int128_scale37)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Build_XSQLDA_MSG_BLR::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter
  ftestID("RemoteFB.API.HLP.XSQLDA_V01_Utilities.Build_XSQLDA_MSG_BLR.%1");

 for(const tag_descr& d : sm_Tests)
 {
  ftestID
   <<structure::flush
   <<d.pTestSign;

  const TTSO_TestPtr
   spTest
    (lcpi::lib::structure::not_null_ptr
      (new TTSO_TestFunc 
       (pParams,
        ftestID.c_str(),
        d.Func)));

  pTestPusher->PushTest(spTest);
 }//for d
}//create

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
