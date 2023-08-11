////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/api/helpers/xsqlda/v01/RemoteFB__API_HLP__XSQLDA_v01_Utilities/TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE.h"
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
//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl

class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl
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

 public:
  static void test_t01___bug_check__incorrect_sqllen__varchar
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t02___bug_check__incorrect_sqllen__char
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t03___bug_check__incorrect_sqllen__short
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t04___bug_check__incorrect_sqllen__long
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t05___bug_check__incorrect_sqllen__int64
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t06___bug_check__incorrect_sqllen__float
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t07___bug_check__incorrect_sqllen__double
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t08___bug_check__incorrect_sqllen__time
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t09___bug_check__incorrect_sqllen__date
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t10___bug_check__incorrect_sqllen__timestamp
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t11___bug_check__incorrect_sqllen__blob
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t12___bug_check__incorrect_sqllen__array
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t13___bug_check__incorrect_sqllen__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t14___bug_check__incorrect_sqllen__boolean
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t15___bug_check__incorrect_sqllen__int128
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t16___bug_check__incorrect_sqllen__decfloat16
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t17___bug_check__incorrect_sqllen__decfloat34
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_t18___bug_check__incorrect_sqllen__timestamp_with_tz
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

  static void test_d13__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d14__boolean
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d15__int128
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d16__decfloat16
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d17__decfloat34
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d18__timestamp_with_tz
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_a01__varchar
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a02__char
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a03__short
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a04__long
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a05__int64
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a06__float
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a07__double
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a08__time
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a09__date
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a10__timestamp
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a11__blob
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a12__array
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a13__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a14__boolean
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a15__int128
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a16__decfloat16
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a17__decfloat34
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a18__timestamp_with_tz
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
};//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_001___null_ptr
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(nullptr);

 _TSO_CHECK(sz==0);
}//test_001___null_ptr

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_002___empty
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 XSQLDA_V1_Wrapper xsqlda(0);

 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 _TSO_CHECK(sz==0);
}//test_002___empty

////////////////////////////////////////////////////////////////////////////////
//TEST 003

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_003___err__unk_sql_type
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=24;

 for(;;)
 {
  try
  {
   xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   errSvc::check_err_rec__xsqlda_err__unknown_sqltype
    (tracer,
     exc.get_record(0),
     24);

   errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_data
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__remote_fb,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_003___err__unk_sql_type

////////////////////////////////////////////////////////////////////////////////
//TEST T01

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t01___bug_check__incorrect_sqllen__varchar
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_varying,
            -1,
            L"sql_varying");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_varying|1,
            -1,
            L"sql_varying");

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

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t02___bug_check__incorrect_sqllen__char
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_text,
            -1,
            L"sql_text");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_isc_sql_text|1,
            -1,
            L"sql_text");
}//test_t02___bug_check__incorrect_sqllen__char

////////////////////////////////////////////////////////////////////////////////
//TEST T03

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t03___bug_check__incorrect_sqllen__short
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
}//test_t03___bug_check__incorrect_sqllen__short

////////////////////////////////////////////////////////////////////////////////
//TEST T04

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t04___bug_check__incorrect_sqllen__long
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
}//test_t04___bug_check__incorrect_sqllen__long

////////////////////////////////////////////////////////////////////////////////
//TEST T05

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t05___bug_check__incorrect_sqllen__int64
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
}//test_t05___bug_check__incorrect_sqllen__int64

////////////////////////////////////////////////////////////////////////////////
//TEST T06

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t06___bug_check__incorrect_sqllen__float
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
}//test_t06___bug_check__incorrect_sqllen__float

////////////////////////////////////////////////////////////////////////////////
//TEST T07

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t07___bug_check__incorrect_sqllen__double
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
}//test_t07___bug_check__incorrect_sqllen__double

////////////////////////////////////////////////////////////////////////////////
//TEST T08

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t08___bug_check__incorrect_sqllen__time
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
}//test_t08___bug_check__incorrect_sqllen__time

////////////////////////////////////////////////////////////////////////////////
//TEST T09

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t09___bug_check__incorrect_sqllen__date
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
}//test_t09___bug_check__incorrect_sqllen__date

////////////////////////////////////////////////////////////////////////////////
//TEST T10

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t10___bug_check__incorrect_sqllen__timestamp
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
}//test_t10___bug_check__incorrect_sqllen__timestamp

////////////////////////////////////////////////////////////////////////////////
//TEST T11

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t11___bug_check__incorrect_sqllen__blob
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
}//test_t11___bug_check__incorrect_sqllen__blob

////////////////////////////////////////////////////////////////////////////////
//TEST T12

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t12___bug_check__incorrect_sqllen__array
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
}//test_t12___bug_check__incorrect_sqllen__array

////////////////////////////////////////////////////////////////////////////////
//TEST T13

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t13___bug_check__incorrect_sqllen__null
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
}//test_t13___bug_check__incorrect_sqllen__null

////////////////////////////////////////////////////////////////////////////////
//TEST T14

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t14___bug_check__incorrect_sqllen__boolean
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
}//test_t14___bug_check__incorrect_sqllen__boolean

////////////////////////////////////////////////////////////////////////////////
//TEST T15

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t15___bug_check__incorrect_sqllen__int128
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
}//test_t15___bug_check__incorrect_sqllen__int128

////////////////////////////////////////////////////////////////////////////////
//TEST T16

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t16___bug_check__incorrect_sqllen__decfloat16
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_fb040_sql_decfloat16,
            7,
            L"sql_decfloat16");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_fb040_sql_decfloat16|1,
            9,
            L"sql_decfloat16");
}//test_t16___bug_check__incorrect_sqllen__decfloat16

////////////////////////////////////////////////////////////////////////////////
//TEST T17

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t17___bug_check__incorrect_sqllen__decfloat34
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_fb040_sql_decfloat34,
            15,
            L"sql_decfloat34");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_fb040_sql_decfloat34|1,
            17,
            L"sql_decfloat34");
}//test_t17___bug_check__incorrect_sqllen__decfloat34

////////////////////////////////////////////////////////////////////////////////
//TEST T18

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_t18___bug_check__incorrect_sqllen__timestamp_with_tz
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx(pParams,
            pCtx,
            isc_api::ibp_fb040_sql_timestamp_with_tz,
            11,
            L"sql_timestamp_with_tz");

 helper_txx(pParams,
            pCtx,
            isc_api::ibp_fb040_sql_timestamp_with_tz|1,
            13,
            L"sql_timestamp_with_tz");
}//test_t18___bug_check__incorrect_sqllen__timestamp_with_tz

////////////////////////////////////////////////////////////////////////////////
//HELPER TXX

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::helper_txx
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
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=sqltype;
 xsqlda->sqlvar[0].sqllen =sqllen;

 for(;;)
 {
  try
  {
   xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);
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
//TEST D01

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d01__varchar
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_varying|1;
 xsqlda->sqlvar[0].sqllen  =11;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+4+12);
}//test_d01__varchar

////////////////////////////////////////////////////////////////////////////////
//TEST D02

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d02__char
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[0].sqllen  =11;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+12);
}//test_d02__char

////////////////////////////////////////////////////////////////////////////////
//TEST D03

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d03__short
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_short|1;
 xsqlda->sqlvar[0].sqlscale =-2;
 xsqlda->sqlvar[0].sqllen   =2;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+4);
}//test_d03__short

////////////////////////////////////////////////////////////////////////////////
//TEST D04

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d04__long
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqlscale =-5;
 xsqlda->sqlvar[0].sqllen   =4;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+4);
}//test_d04__long

////////////////////////////////////////////////////////////////////////////////
//TEST D05

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d05__int64
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[0].sqlscale =-15;
 xsqlda->sqlvar[0].sqllen   =8;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+8);
}//test_d05__int64

////////////////////////////////////////////////////////////////////////////////
//TEST D06

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d06__float
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_float|1;
 xsqlda->sqlvar[0].sqllen  =4;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+4);
}//test_d06__float

////////////////////////////////////////////////////////////////////////////////
//TEST D07

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d07__double
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_double|1;
 xsqlda->sqlvar[0].sqllen  =8;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+8);
}//test_d07__double

////////////////////////////////////////////////////////////////////////////////
//TEST D08

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d08__time
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_type_time|1;
 xsqlda->sqlvar[0].sqllen  =4;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+4);
}//test_d08__time

////////////////////////////////////////////////////////////////////////////////
//TEST D09

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d09__date
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_type_date|1;
 xsqlda->sqlvar[0].sqllen  =4;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+4);
}//test_d09__date

////////////////////////////////////////////////////////////////////////////////
//TEST D10

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d10__timestamp
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_timestamp|1;
 xsqlda->sqlvar[0].sqllen  =8;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+8);
}//test_d10__timestamp

////////////////////////////////////////////////////////////////////////////////
//TEST D11

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d11__blob
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_blob|1;
 xsqlda->sqlvar[0].sqllen  =8;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+8);
}//test_d11__blob

////////////////////////////////////////////////////////////////////////////////
//TEST D12

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d12__array
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_array|1;
 xsqlda->sqlvar[0].sqllen  =8;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+8);
}//test_d12__array

////////////////////////////////////////////////////////////////////////////////
//TEST D13

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d13__null
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb025_sql_null|1;
 xsqlda->sqlvar[0].sqllen  =0;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+0);
}//test_d13__null

////////////////////////////////////////////////////////////////////////////////
//TEST D14

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d14__boolean
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb030_sql_boolean|1;
 xsqlda->sqlvar[0].sqllen  =1;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK_MSG(sz==4+4,"sz="<<sz);
}//test_d14__boolean

////////////////////////////////////////////////////////////////////////////////
//TEST D15

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d15__int128
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_fb040_sql_int128|1;
 xsqlda->sqlvar[0].sqlscale =-15;
 xsqlda->sqlvar[0].sqllen   =16;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+16);
}//test_d15__int128

////////////////////////////////////////////////////////////////////////////////
//TEST D16

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d16__decfloat16
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_fb040_sql_decfloat16|1;
 xsqlda->sqlvar[0].sqlscale =0;
 xsqlda->sqlvar[0].sqllen   =8;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK_MSG(sz==4+8,"sz="<<sz);
}//test_d16__decfloat16

////////////////////////////////////////////////////////////////////////////////
//TEST D17

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d17__decfloat34
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_fb040_sql_decfloat34|1;
 xsqlda->sqlvar[0].sqlscale =0;
 xsqlda->sqlvar[0].sqllen   =16;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK_MSG(sz==4+16,"sz="<<sz);
}//test_d17__decfloat34

////////////////////////////////////////////////////////////////////////////////
//TEST D18

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_d18__timestamp_with_tz
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_fb040_sql_timestamp_with_tz|1;
 xsqlda->sqlvar[0].sqlscale =0;
 xsqlda->sqlvar[0].sqllen   =12;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK_MSG(sz==4+12,"sz="<<sz);
}//test_d18__timestamp_with_tz

////////////////////////////////////////////////////////////////////////////////
//TEST A01

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a01__varchar
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[0].sqllen  =1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_varying|1;
 xsqlda->sqlvar[1].sqllen  =11;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+4+4+4+12);
}//test_a01__varchar

////////////////////////////////////////////////////////////////////////////////
//TEST A02

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a02__char
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[0].sqllen  =1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[1].sqllen  =11;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+4+4+12);
}//test_a02__char

////////////////////////////////////////////////////////////////////////////////
//TEST A03

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a03__short
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[0].sqllen  =1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_short|1;
 xsqlda->sqlvar[1].sqllen  =2;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+4+4+4);
}//test_a03__short

////////////////////////////////////////////////////////////////////////////////
//TEST A04

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a04__long
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb025_sql_null|1;
 xsqlda->sqlvar[0].sqllen  =0;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[1].sqllen  =4;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+0+4+4);
}//test_a04__long

////////////////////////////////////////////////////////////////////////////////
//TEST A05

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a05__int64
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[0].sqllen  =1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[1].sqllen  =8;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+4+4+8);
}//test_a05__int64

////////////////////////////////////////////////////////////////////////////////
//TEST A06

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a06__float
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb025_sql_null|1;
 xsqlda->sqlvar[0].sqllen  =0;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_float|1;
 xsqlda->sqlvar[1].sqllen  =4;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+0+4+4);
}//test_a06__float

////////////////////////////////////////////////////////////////////////////////
//TEST A07

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a07__double
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqllen  =4;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_double|1;
 xsqlda->sqlvar[1].sqllen  =8;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+4+4+8);
}//test_a07__double

////////////////////////////////////////////////////////////////////////////////
//TEST A08

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a08__time
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb025_sql_null|1;
 xsqlda->sqlvar[0].sqllen  =0;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_type_time|1;
 xsqlda->sqlvar[1].sqllen  =4;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+0+4+4);
}//test_a08__time

////////////////////////////////////////////////////////////////////////////////
//TEST A09

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a09__date
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb025_sql_null|1;
 xsqlda->sqlvar[0].sqllen  =0;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_type_date|1;
 xsqlda->sqlvar[1].sqllen  =4;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+0+4+4);
}//test_a09__date

////////////////////////////////////////////////////////////////////////////////
//TEST A10

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a10__timestamp
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb025_sql_null|1;
 xsqlda->sqlvar[0].sqllen  =0;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_timestamp|1;
 xsqlda->sqlvar[1].sqllen  =8;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+0+4+8);
}//test_a10__timestamp

////////////////////////////////////////////////////////////////////////////////
//TEST A11

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a11__blob
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb025_sql_null|1;
 xsqlda->sqlvar[0].sqllen  =0;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_blob|1;
 xsqlda->sqlvar[1].sqllen  =8;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+0+4+8);
}//test_a11__blob

////////////////////////////////////////////////////////////////////////////////
//TEST A12

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a12__array
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb025_sql_null|1;
 xsqlda->sqlvar[0].sqllen  =0;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_array|1;
 xsqlda->sqlvar[1].sqllen  =8;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+0+4+8);
}//test_a12__array

////////////////////////////////////////////////////////////////////////////////
//TEST A13

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a13__null
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb025_sql_null|1;
 xsqlda->sqlvar[0].sqllen  =0;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb025_sql_null|1;
 xsqlda->sqlvar[1].sqllen  =0;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+0+4+0);
}//test_a13__null

////////////////////////////////////////////////////////////////////////////////
//TEST A14

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a14__boolean
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb025_sql_null|1;
 xsqlda->sqlvar[0].sqllen  =0;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb030_sql_boolean|1;
 xsqlda->sqlvar[1].sqllen  =1;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+0+4+4);
}//test_a14__boolean

////////////////////////////////////////////////////////////////////////////////
//TEST A15

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a15__int128
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[0].sqllen  =1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb040_sql_int128|1;
 xsqlda->sqlvar[1].sqllen  =16;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+4+4+16);
}//test_a15__int128

////////////////////////////////////////////////////////////////////////////////
//TEST A16

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a16__decfloat16
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[0].sqllen  =1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb040_sql_decfloat16|1;
 xsqlda->sqlvar[1].sqllen  =8;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+4+4+8);
}//test_a16__decfloat16

////////////////////////////////////////////////////////////////////////////////
//TEST A17

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a17__decfloat34
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[0].sqllen  =1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb040_sql_decfloat34|1;
 xsqlda->sqlvar[1].sqllen  =16;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+4+4+16);
}//test_a17__decfloat34

////////////////////////////////////////////////////////////////////////////////
//TEST A18

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::test_a18__timestamp_with_tz
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[0].sqllen  =1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb040_sql_timestamp_with_tz|1;
 xsqlda->sqlvar[1].sqllen  =12;

 //-----------------------------------------
 size_t const sz=xsqlda_utils_type::Calc_XSQLDA_MAX_XDR_SIZE(xsqlda);

 //-----------------------------------------
 _TSO_CHECK(sz==4+4+4+12);
}//test_a18__timestamp_with_tz

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_descr

struct TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_impl::func},

const TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::tag_descr
 TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::sm_Tests[]=
{
 DEF_TEST_DESCR("001.null_ptr",
                test_001___null_ptr)
 DEF_TEST_DESCR("002.empty",
                test_002___empty)
 DEF_TEST_DESCR("003.err.unk_sql_type",
                test_003___err__unk_sql_type)

 DEF_TEST_DESCR("T01.bug_check.incorrect_sqllen.varying",
                test_t01___bug_check__incorrect_sqllen__varchar)
 DEF_TEST_DESCR("T02.bug_check.incorrect_sqllen.char",
                test_t02___bug_check__incorrect_sqllen__char)
 DEF_TEST_DESCR("T03.bug_check.incorrect_sqllen.short",
                test_t03___bug_check__incorrect_sqllen__short)
 DEF_TEST_DESCR("T04.bug_check.incorrect_sqllen.long",
                test_t04___bug_check__incorrect_sqllen__long)
 DEF_TEST_DESCR("T05.bug_check.incorrect_sqllen.int64",
                test_t05___bug_check__incorrect_sqllen__int64)
 DEF_TEST_DESCR("T06.bug_check.incorrect_sqllen.float",
                test_t06___bug_check__incorrect_sqllen__float)
 DEF_TEST_DESCR("T07.bug_check.incorrect_sqllen.double",
                test_t07___bug_check__incorrect_sqllen__double)
 DEF_TEST_DESCR("T08.bug_check.incorrect_sqllen.time",
                test_t08___bug_check__incorrect_sqllen__time)
 DEF_TEST_DESCR("T09.bug_check.incorrect_sqllen.date",
                test_t09___bug_check__incorrect_sqllen__date)
 DEF_TEST_DESCR("T10.bug_check.incorrect_sqllen.timestamp",
                test_t10___bug_check__incorrect_sqllen__timestamp)
 DEF_TEST_DESCR("T11.bug_check.incorrect_sqllen.blob",
                test_t11___bug_check__incorrect_sqllen__blob)
 DEF_TEST_DESCR("T12.bug_check.incorrect_sqllen.array",
                test_t12___bug_check__incorrect_sqllen__array)
 DEF_TEST_DESCR("T13.bug_check.incorrect_sqllen.null",
                test_t13___bug_check__incorrect_sqllen__null)
 DEF_TEST_DESCR("T14.bug_check.incorrect_sqllen.boolean",
                test_t14___bug_check__incorrect_sqllen__boolean)
 DEF_TEST_DESCR("T15.bug_check.incorrect_sqllen.int128",
                test_t15___bug_check__incorrect_sqllen__int128)
 DEF_TEST_DESCR("T16.bug_check.incorrect_sqllen.decfloat16",
                test_t16___bug_check__incorrect_sqllen__decfloat16)
 DEF_TEST_DESCR("T17.bug_check.incorrect_sqllen.decfloat34",
                test_t17___bug_check__incorrect_sqllen__decfloat34)
 DEF_TEST_DESCR("T18.bug_check.incorrect_sqllen.timestamp_with_tz",
                test_t17___bug_check__incorrect_sqllen__decfloat34)

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
 DEF_TEST_DESCR("D13.null",
                test_d13__null)
 DEF_TEST_DESCR("D14.boolean",
                test_d14__boolean)
 DEF_TEST_DESCR("D15.int128",
                test_d15__int128)
 DEF_TEST_DESCR("D16.decfloat16",
                test_d16__decfloat16)
 DEF_TEST_DESCR("D17.decfloat34",
                test_d17__decfloat34)
 DEF_TEST_DESCR("D18.timestamp_with_tz",
                test_d18__timestamp_with_tz)

 DEF_TEST_DESCR("A01.varchar",
                test_a01__varchar)
 DEF_TEST_DESCR("A02.char",
                test_a02__char)
 DEF_TEST_DESCR("A03.short",
                test_a03__short)
 DEF_TEST_DESCR("A04.long",
                test_a04__long)
 DEF_TEST_DESCR("A05.int64",
                test_a05__int64)
 DEF_TEST_DESCR("A06.float",
                test_a06__float)
 DEF_TEST_DESCR("A07.double",
                test_a07__double)
 DEF_TEST_DESCR("A08.time",
                test_a08__time)
 DEF_TEST_DESCR("A09.date",
                test_a09__date)
 DEF_TEST_DESCR("A10.timestamp",
                test_a10__timestamp)
 DEF_TEST_DESCR("A11.blob",
                test_a11__blob)
 DEF_TEST_DESCR("A12.array",
                test_a12__array)
 DEF_TEST_DESCR("A13.null",
                test_a13__null)
 DEF_TEST_DESCR("A14.boolean",
                test_a14__boolean)
 DEF_TEST_DESCR("A15.int128",
                test_a15__int128)
 DEF_TEST_DESCR("A16.decfloat16",
                test_a16__decfloat16)
 DEF_TEST_DESCR("A17.decfloat34",
                test_a17__decfloat34)
 DEF_TEST_DESCR("A18.timestamp_with_tz",
                test_a18__timestamp_with_tz)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE

void TestsFor__RemoteFB__API_HLP__XSQLDA_v01_Utilities___Calc_XSQLDA_MAX_XDR_SIZE::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter
  ftestID("RemoteFB.API.HLP.XSQLDA_V01_Utilities.Calc_XSQLDA_MAX_XDR_SIZE.%1");

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
