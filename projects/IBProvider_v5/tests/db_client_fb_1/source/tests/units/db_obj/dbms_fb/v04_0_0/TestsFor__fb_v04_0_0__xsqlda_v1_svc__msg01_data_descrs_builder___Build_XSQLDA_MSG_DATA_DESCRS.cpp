////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/units/db_obj/dbms_fb/v04_0_0/TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/dbms_fb/v04_0_0/db_obj__dbms_fb__v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/isc_base/isc_integer_to_portable_format.h"
#include <structure/test_obj/t_tso_user.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl

class TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef tag_impl                                              self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type                               context_type;

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

  static void test_t19___bug_check__incorrect_sqllen__time_with_tz
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

  static void test_d19__time_with_tz
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

  static void test_a19__time_with_tz
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 private:
  using msg_data_descrs_type
   =isc_base::t_isc_xsqlda_v1_svc__msg_data_descrs_builder::msg_data_descrs_type;

  static void Helper__Build_XSQLDA_MSG_DATA_DESCRS
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_data_descrs_type&     MsgDescrs,
                              size_t*                   pResult_DataSize,
                              size_t*                   pResult_DataAlign);
};//class TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl

////////////////////////////////////////////////////////////////////////////////

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::Helper__Build_XSQLDA_MSG_DATA_DESCRS
                             (const isc_api::XSQLDA_V1* pXSQLDA,
                              msg_data_descrs_type&     MsgDescrs,
                              size_t*                   pResult_DataSize,
                              size_t*                   pResult_DataAlign)
{
 const db_obj::t_db_object_ptr
  spObj
   (ibp::db_obj::dbms_fb::v04_0_0::fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder::create());

 const isc_base::t_isc_xsqlda_v1_svc__msg_data_descrs_builder_ptr
  spBuilder
   (dynamic_cast<isc_base::t_isc_xsqlda_v1_svc__msg_data_descrs_builder*>(spObj.ptr()));

 _TSO_CHECK(spBuilder);

 spBuilder->Build_XSQLDA_MSG_DATA_DESCRS
  (pXSQLDA,
   MsgDescrs,
   pResult_DataSize,
   pResult_DataAlign);
}//Helper__Build_XSQLDA_MSG_DATA_DESCRS

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_001___null_ptr
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 msg_data_descrs_type descrs(100);

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (nullptr,
   descrs,
   &sz,
   &align);

 _TSO_CHECK(descrs.empty());

 _TSO_CHECK(sz==0);
 _TSO_CHECK(align==1);
}//test_001___null_ptr

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_002___empty
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 msg_data_descrs_type descrs(100);

 XSQLDA_V1_Wrapper xsqlda(0);

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 _TSO_CHECK(descrs.empty());

 _TSO_CHECK(sz==0);
 _TSO_CHECK(align==1);
}//test_002___empty

////////////////////////////////////////////////////////////////////////////////
//TEST 003

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_003___err__unk_sql_type
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 msg_data_descrs_type descrs(100);


 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=24;

 for(;;)
 {
  try
  {
   size_t sz=0;
   size_t align=0;

   self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
    (xsqlda,
     descrs,
     &sz,
     &align);
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
     errSvc::sm_subsysID__isc_api__fb4_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_003___err__unk_sql_type

////////////////////////////////////////////////////////////////////////////////
//TEST T01

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t01___bug_check__incorrect_sqllen__varchar
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_varying,
   -1,
   L"sql_varying");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_varying|1,
   -1,
   L"sql_varying");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_varying,
   SHRT_MAX,
   L"sql_varying");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_varying|1,
   SHRT_MAX,
   L"sql_varying");
}//test_t01___bug_check__incorrect_sqllen__varchar

////////////////////////////////////////////////////////////////////////////////
//TEST T02

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t02___bug_check__incorrect_sqllen__char
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_text,
   -1,
   L"sql_text");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_text|1,
   -1,
   L"sql_text");
}//test_t02___bug_check__incorrect_sqllen__char

////////////////////////////////////////////////////////////////////////////////
//TEST T03

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t03___bug_check__incorrect_sqllen__short
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_short,
   1,
   L"sql_short");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_short|1,
   3,
   L"sql_short");
}//test_t03___bug_check__incorrect_sqllen__short

////////////////////////////////////////////////////////////////////////////////
//TEST T04

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t04___bug_check__incorrect_sqllen__long
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_long,
   3,
   L"sql_long");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_long|1,
   5,
   L"sql_long");
}//test_t04___bug_check__incorrect_sqllen__long

////////////////////////////////////////////////////////////////////////////////
//TEST T05

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t05___bug_check__incorrect_sqllen__int64
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_int64,
   7,
   L"sql_int64");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_int64|1,
   9,
   L"sql_int64");
}//test_t05___bug_check__incorrect_sqllen__int64

////////////////////////////////////////////////////////////////////////////////
//TEST T06

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t06___bug_check__incorrect_sqllen__float
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_float,
   3,
   L"sql_float");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_float|1,
   5,
   L"sql_float");
}//test_t06___bug_check__incorrect_sqllen__float

////////////////////////////////////////////////////////////////////////////////
//TEST T07

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t07___bug_check__incorrect_sqllen__double
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_double,
   7,
   L"sql_double");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_double|1,
   9,
   L"sql_double");
}//test_t07___bug_check__incorrect_sqllen__double

////////////////////////////////////////////////////////////////////////////////
//TEST T08

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t08___bug_check__incorrect_sqllen__time
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_type_time,
   3,
   L"sql_type_time");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_type_time|1,
   5,
   L"sql_type_time");
}//test_t08___bug_check__incorrect_sqllen__time

////////////////////////////////////////////////////////////////////////////////
//TEST T09

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t09___bug_check__incorrect_sqllen__date
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_type_date,
   3,
   L"sql_type_date");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_type_date|1,
   5,
   L"sql_type_date");
}//test_t09___bug_check__incorrect_sqllen__date

////////////////////////////////////////////////////////////////////////////////
//TEST T10

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t10___bug_check__incorrect_sqllen__timestamp
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_timestamp,
   7,
   L"sql_timestamp");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_timestamp|1,
   9,
   L"sql_timestamp");
}//test_t10___bug_check__incorrect_sqllen__timestamp

////////////////////////////////////////////////////////////////////////////////
//TEST T11

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t11___bug_check__incorrect_sqllen__blob
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_blob,
   7,
   L"sql_blob");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_blob|1,
   9,
   L"sql_blob");
}//test_t11___bug_check__incorrect_sqllen__blob

////////////////////////////////////////////////////////////////////////////////
//TEST T12

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t12___bug_check__incorrect_sqllen__array
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_array,
   7,
   L"sql_array");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_isc_sql_array|1,
   9,
   L"sql_array");
}//test_t12___bug_check__incorrect_sqllen__array

////////////////////////////////////////////////////////////////////////////////
//TEST T13

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t13___bug_check__incorrect_sqllen__null
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_fb025_sql_null,
   1,
   L"sql_null");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_fb025_sql_null|1,
   2,
   L"sql_null");
}//test_t13___bug_check__incorrect_sqllen__null

////////////////////////////////////////////////////////////////////////////////
//TEST T14

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t14___bug_check__incorrect_sqllen__boolean
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_fb030_sql_boolean,
   3,
   L"sql_boolean");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_fb030_sql_boolean|1,
   5,
   L"sql_boolean");
}//test_t14___bug_check__incorrect_sqllen__boolean

////////////////////////////////////////////////////////////////////////////////
//TEST T15

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t15___bug_check__incorrect_sqllen__int128
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_fb040_sql_int128,
   15,
   L"sql_int128");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_fb040_sql_int128|1,
   17,
   L"sql_int128");
}//test_t15___bug_check__incorrect_sqllen__int128

////////////////////////////////////////////////////////////////////////////////
//TEST T16

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t16___bug_check__incorrect_sqllen__decfloat16
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_fb040_sql_decfloat16,
   7,
   L"sql_decfloat16");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_fb040_sql_decfloat16|1,
   9,
   L"sql_decfloat16");
}//test_t16___bug_check__incorrect_sqllen__decfloat16

////////////////////////////////////////////////////////////////////////////////
//TEST T17

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t17___bug_check__incorrect_sqllen__decfloat34
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_fb040_sql_decfloat34,
   15,
   L"sql_decfloat34");

 helper_txx
  (pParams,
   pCtx,
   isc_api::ibp_fb040_sql_decfloat34|1,
   17,
   L"sql_decfloat34");
}//test_t17___bug_check__incorrect_sqllen__decfloat34

////////////////////////////////////////////////////////////////////////////////
//TEST T18

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t18___bug_check__incorrect_sqllen__timestamp_with_tz
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 for(short x=-33;x!=33;++x)
 {
  if(x==12)
   continue;

  helper_txx
   (pParams,
    pCtx,
    isc_api::ibp_fb040_sql_timestamp_with_tz,
    x,
    L"sql_timestamp_with_tz");

  helper_txx
   (pParams,
    pCtx,
    isc_api::ibp_fb040_sql_timestamp_with_tz|1,
    x,
    L"sql_timestamp_with_tz");
 }//for x
}//test_t18___bug_check__incorrect_sqllen__timestamp_with_tz

////////////////////////////////////////////////////////////////////////////////
//TEST T19

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_t19___bug_check__incorrect_sqllen__time_with_tz
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 for(short x=-33;x!=33;++x)
 {
  if(x==8)
   continue;

  helper_txx
   (pParams,
    pCtx,
    isc_api::ibp_fb040_sql_time_with_tz,
    x,
    L"sql_time_with_tz");

  helper_txx
   (pParams,
    pCtx,
    isc_api::ibp_fb040_sql_time_with_tz|1,
    x,
    L"sql_time_with_tz");
 }//for x
}//test_t19___bug_check__incorrect_sqllen__time_with_tz

////////////////////////////////////////////////////////////////////////////////
//HELPER TXX

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::helper_txx
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
 msg_data_descrs_type descrs(100);

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=sqltype;
 xsqlda->sqlvar[0].sqllen =sqllen;

 for(;;)
 {
  try
  {
   size_t sz=0;
   size_t align=0;

   self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
    (xsqlda,
     descrs,
     &sz,
     &align);
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
     errSvc::sm_subsysID__isc_api__fb4_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//helper_txx

////////////////////////////////////////////////////////////////////////////////
//TEST D01

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d01__varchar
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==13);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==14);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__varying);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_varying);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==16);
 _TSO_CHECK(align==2);
}//test_d01__varchar

////////////////////////////////////////////////////////////////////////////////
//TEST D02

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d02__char
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==11);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==12);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_text);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==14);
 _TSO_CHECK(align==2);
}//test_d02__char

////////////////////////////////////////////////////////////////////////////////
//TEST D03

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d03__short
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==2);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==2);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__short);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_short);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-2);

 _TSO_CHECK(sz==4);
 _TSO_CHECK(align==2);
}//test_d03__short

////////////////////////////////////////////////////////////////////////////////
//TEST D04

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d04__long
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==4);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==4);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__long);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_long);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-5);

 _TSO_CHECK(sz==6);
 _TSO_CHECK(align==4);
}//test_d04__long

////////////////////////////////////////////////////////////////////////////////
//TEST D05

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d05__int64
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==8);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==8);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__int64);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_int64);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-15);

 _TSO_CHECK(sz==10);
 _TSO_CHECK(align==8);
}//test_d05__int64

////////////////////////////////////////////////////////////////////////////////
//TEST D06

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d06__float
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==4);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==4);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__float);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_float);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==6);
 _TSO_CHECK(align==4);
}//test_d06__float

////////////////////////////////////////////////////////////////////////////////
//TEST D07

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d07__double
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==8);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==8);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__double);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_double);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==10);
 _TSO_CHECK(align==8);
}//test_d07__double

////////////////////////////////////////////////////////////////////////////////
//TEST D08

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d08__time
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==4);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==4);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__sql_time);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_type_time);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==6);
 _TSO_CHECK(align==4);
}//test_d08__time

////////////////////////////////////////////////////////////////////////////////
//TEST D09

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d09__date
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==4);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==4);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__sql_date);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_type_date);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==6);
 _TSO_CHECK(align==4);
}//test_d09__date

////////////////////////////////////////////////////////////////////////////////
//TEST D10

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d10__timestamp
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==8);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==8);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__timestamp);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_timestamp);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==10);
 _TSO_CHECK(align==4);
}//test_d10__timestamp

////////////////////////////////////////////////////////////////////////////////
//TEST D11

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d11__blob
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==8);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==8);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__quad);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_blob);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==10);
 _TSO_CHECK(align==4);
}//test_d11__blob

////////////////////////////////////////////////////////////////////////////////
//TEST D12

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d12__array
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==8);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==8);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__quad);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_array);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==10);
 _TSO_CHECK(align==4);
}//test_d12__array

////////////////////////////////////////////////////////////////////////////////
//TEST D13

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d13__null
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==0);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==0);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb025_sql_null);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==2);
 _TSO_CHECK(align==2);
}//test_d13__null

////////////////////////////////////////////////////////////////////////////////
//TEST D14

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d14__boolean
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==1);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==2);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_fb030_blr_dtype__bool);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb030_sql_boolean);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==4);
 _TSO_CHECK(align==2);
}//test_d14__boolean

////////////////////////////////////////////////////////////////////////////////
//TEST D15

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d15__int128
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==16);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==16);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_fb040_blr_dtype__int128);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb040_sql_int128);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-15);

 _TSO_CHECK(sz==18);
 _TSO_CHECK(align==8);
}//test_d15__int128

////////////////////////////////////////////////////////////////////////////////
//TEST D16

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d16__decfloat16
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==8);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==8);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_fb040_blr_dtype__decfloat16);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb040_sql_decfloat16);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==10);
 _TSO_CHECK(align==8);
}//test_d16__decfloat16

////////////////////////////////////////////////////////////////////////////////
//TEST D17

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d17__decfloat34
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==16);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==16);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_fb040_blr_dtype__decfloat34);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb040_sql_decfloat34);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==18);
 _TSO_CHECK(align==8);
}//test_d17__decfloat34

////////////////////////////////////////////////////////////////////////////////
//TEST D18

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d18__timestamp_with_tz
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==12);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==12);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_fb040_blr_dtype__timestamp_with_tz);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb040_sql_timestamp_with_tz);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==14);
 _TSO_CHECK(align==4);
}//test_d18__timestamp_with_tz

////////////////////////////////////////////////////////////////////////////////
//TEST D19

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_d19__time_with_tz
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams!=nullptr);
 assert(pCtx!=nullptr);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_fb040_sql_time_with_tz|1;
 xsqlda->sqlvar[0].sqlscale =0;
 xsqlda->sqlvar[0].sqllen   =8;

 //-----------------------------------------
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==1);

 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==8);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==8);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_fb040_blr_dtype__time_with_tz);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb040_sql_time_with_tz);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==10);
 _TSO_CHECK(align==4);
}//test_d19__time_with_tz

////////////////////////////////////////////////////////////////////////////////
//TEST A01

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a01__varchar
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==1);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==2);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_text);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==4);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==13);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==18);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__varying);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_isc_sql_varying);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==20);
 _TSO_CHECK(align==2);
}//test_a01__varchar

////////////////////////////////////////////////////////////////////////////////
//TEST A02

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a02__char
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==1);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==2);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_text);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==4);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==11);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==16);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_isc_sql_text);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==18);
 _TSO_CHECK(align==2);
}//test_a02__char

////////////////////////////////////////////////////////////////////////////////
//TEST A03

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a03__short
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==1);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==2);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_text);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==4);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==2);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==6);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__short);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_isc_sql_short);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==0);

 _TSO_CHECK(sz==8);
 _TSO_CHECK(align==2);
}//test_a03__short

////////////////////////////////////////////////////////////////////////////////
//TEST A04

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a04__long
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==0);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==0);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb025_sql_null);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==4);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==4);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==8);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__long);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_isc_sql_long);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==0);

 _TSO_CHECK(sz==10);
 _TSO_CHECK(align==4);
}//test_a04__long

////////////////////////////////////////////////////////////////////////////////
//TEST A05

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a05__int64
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

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[1].sqllen  =8;

 //-----------------------------------------
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==4);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==4);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__long);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_long);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==0);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==8);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==8);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==16);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__int64);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_isc_sql_int64);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==0);

 _TSO_CHECK(sz==18);
 _TSO_CHECK(align==8);
}//test_a05__int64

////////////////////////////////////////////////////////////////////////////////
//TEST A06

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a06__float
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==0);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==0);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb025_sql_null);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==4);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==4);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==8);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__float);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_isc_sql_float);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==10);
 _TSO_CHECK(align==4);
}//test_a06__float

////////////////////////////////////////////////////////////////////////////////
//TEST A07

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a07__double
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==4);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==4);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__long);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_long);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==0);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==8);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==8);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==16);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__double);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_isc_sql_double);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==18);
 _TSO_CHECK(align==8);
}//test_a07__double

////////////////////////////////////////////////////////////////////////////////
//TEST A08

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a08__time
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==0);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==0);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb025_sql_null);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==4);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==4);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==8);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__sql_time);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_isc_sql_type_time);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==10);
 _TSO_CHECK(align==4);
}//test_a08__time

////////////////////////////////////////////////////////////////////////////////
//TEST A09

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a09__date
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==0);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==0);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb025_sql_null);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==4);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==4);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==8);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__sql_date);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_isc_sql_type_date);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==10);
 _TSO_CHECK(align==4);
}//test_a09__date

////////////////////////////////////////////////////////////////////////////////
//TEST A10

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a10__timestamp
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==0);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==0);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb025_sql_null);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==4);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==8);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==12);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__timestamp);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_isc_sql_timestamp);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==14);
 _TSO_CHECK(align==4);
}//test_a10__timestamp

////////////////////////////////////////////////////////////////////////////////
//TEST A11

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a11__blob
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==0);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==0);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb025_sql_null);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==4);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==8);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==12);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__quad);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_isc_sql_blob);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==14);
 _TSO_CHECK(align==4);
}//test_a11__blob

////////////////////////////////////////////////////////////////////////////////
//TEST A12

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a12__array
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==0);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==0);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb025_sql_null);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==4);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==8);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==12);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__quad);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_isc_sql_array);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==14);
 _TSO_CHECK(align==4);
}//test_a12__array

////////////////////////////////////////////////////////////////////////////////
//TEST A13

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a13__null
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==0);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==0);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb025_sql_null);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==2);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==0);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==2);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_fb025_sql_null);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==4);
 _TSO_CHECK(align==2);
}//test_a13__null

////////////////////////////////////////////////////////////////////////////////
//TEST A14

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a14__boolean
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
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==0);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==0);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__text);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_fb025_sql_null);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==-1);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==2);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==1);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==4);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_fb030_blr_dtype__bool);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_fb030_sql_boolean);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==6);
 _TSO_CHECK(align==2);
}//test_a14__boolean

////////////////////////////////////////////////////////////////////////////////
//TEST A15

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a15__int128
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

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb040_sql_int128|1;
 xsqlda->sqlvar[1].sqllen  =16;

 //-----------------------------------------
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==4);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==4);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__long);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_long);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==0);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==8);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==16);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==24);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_fb040_blr_dtype__int128);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_fb040_sql_int128);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==0);

 _TSO_CHECK(sz==26);
 _TSO_CHECK(align==8);
}//test_a15__int128

////////////////////////////////////////////////////////////////////////////////
//TEST A16

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a16__decfloat16
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

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb040_sql_decfloat16|1;
 xsqlda->sqlvar[1].sqllen  =8;

 //-----------------------------------------
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==4);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==4);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__long);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_long);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==0);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==8);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==8);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==16);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_fb040_blr_dtype__decfloat16);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_fb040_sql_decfloat16);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==18);
 _TSO_CHECK(align==8);
}//test_a16__decfloat16

////////////////////////////////////////////////////////////////////////////////
//TEST A17

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a17__decfloat34
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

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb040_sql_decfloat34|1;
 xsqlda->sqlvar[1].sqllen  =16;

 //-----------------------------------------
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==4);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==4);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__long);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_long);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==0);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==8);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==16);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==24);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_fb040_blr_dtype__decfloat34);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_fb040_sql_decfloat34);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==26);
 _TSO_CHECK(align==8);
}//test_a17__decfloat34

////////////////////////////////////////////////////////////////////////////////
//TEST A18

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a18__timestamp_with_tz
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

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb040_sql_timestamp_with_tz|1;
 xsqlda->sqlvar[1].sqllen  =12;

 //-----------------------------------------
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==4);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==4);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__long);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_long);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==0);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==8);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==12);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==20);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_fb040_blr_dtype__timestamp_with_tz);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_fb040_sql_timestamp_with_tz);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==22);
 _TSO_CHECK(align==4);
}//test_a18__timestamp_with_tz

////////////////////////////////////////////////////////////////////////////////
//TEST A19

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::test_a19__time_with_tz
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

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb040_sql_time_with_tz|1;
 xsqlda->sqlvar[1].sqllen  =8;

 //-----------------------------------------
 msg_data_descrs_type descrs;

 size_t sz=0;
 size_t align=0;

 self_type::Helper__Build_XSQLDA_MSG_DATA_DESCRS
  (xsqlda,
   descrs,
   &sz,
   &align);

 //-----------------------------------------
 _TSO_CHECK(descrs.size()==2);

 //-----------------------------------------
 _TSO_CHECK(descrs[0].m_msg_value_block_offset==0);
 _TSO_CHECK(descrs[0].m_msg_value_block_size  ==4);
 _TSO_CHECK(descrs[0].m_msg_sqlind_offset     ==4);
 _TSO_CHECK(descrs[0].m_msg_blrtype           ==isc_api::ibp_isc_blr_dtype__long);

 _TSO_CHECK(descrs[0].m_xvar_sqltype          ==isc_api::ibp_isc_sql_long);
 _TSO_CHECK(descrs[0].m_xvar_sqlscale         ==0);

 //-----------------------------------------
 _TSO_CHECK(descrs[1].m_msg_value_block_offset==8);
 _TSO_CHECK(descrs[1].m_msg_value_block_size  ==8);
 _TSO_CHECK(descrs[1].m_msg_sqlind_offset     ==16);
 _TSO_CHECK(descrs[1].m_msg_blrtype           ==isc_api::ibp_fb040_blr_dtype__time_with_tz);

 _TSO_CHECK(descrs[1].m_xvar_sqltype          ==isc_api::ibp_fb040_sql_time_with_tz);
 _TSO_CHECK(descrs[1].m_xvar_sqlscale         ==-1);

 _TSO_CHECK(sz==18);
 _TSO_CHECK(align==4);
}//test_a19__time_with_tz

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_descr

struct TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_impl::func},

const TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::tag_descr
 TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::sm_Tests[]=
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
                test_t18___bug_check__incorrect_sqllen__timestamp_with_tz)
 DEF_TEST_DESCR("T19.bug_check.incorrect_sqllen.time_with_tz",
                test_t19___bug_check__incorrect_sqllen__time_with_tz)

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
 DEF_TEST_DESCR("D19.time_with_tz",
                test_d19__time_with_tz)

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
 DEF_TEST_DESCR("A19.time_with_tz",
                test_a19__time_with_tz)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg01_data_descrs_builder___Build_XSQLDA_MSG_DATA_DESCRS::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter
  ftestID
   ("DB_OBJ.UNITS.DBMS_FB.V04_0_0.xsqlda_v1_svc__msg01_data_descrs_builder.Build_XSQLDA_MSG_DATA_DESCRS.%1");

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
}/*nms ibp_tests*/}/*nms lcpi*/
