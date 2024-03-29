////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/units/db_obj/dbms_fb/v04_0_0/TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/dbms_fb/v04_0_0/db_obj__dbms_fb__v04_0_0__xsqlda_v1_svc__msg_data.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/isc_base/isc_integer_to_portable_format.h"
#include <structure/test_obj/t_tso_user.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl

class TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl LCPI_CPP_CFG__CLASS__FINAL
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

  static void test_004___err__null_ptr_in_sqlind
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

#ifdef NDEBUG
  static void test_005___err__incorrect_varchar_data_length
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_006___err__varchar_data_length_is_greater_than_buffer_size
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
#endif
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
  static void test_d01___short
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d02___long
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d03___int64
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d04___float
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d05___double
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d06___time
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d07___date
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d08___timestamp
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d09___text
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d10___varying
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d11___null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d12___blob
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d13___array
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d14___boolean
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d15___int128
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d16___decfloat16
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d17___decfloat34
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d18___timestamp_with_tz
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_d19___time_with_tz
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_n01___short
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n02___long
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n03___int64
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n04___float
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n05___double
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n06___time
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n07___date
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n08___timestamp
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n09___text
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n10___varying
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n12___blob
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n13___array
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n14___boolean
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n15___int128
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n16___decfloat16
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n17___decfloat34
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n18___timestamp_with_tz
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_n19___time_with_tz
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_a01___short
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a02___long
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a03___int64
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a04___float
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a05___double
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a06___time
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a07___date
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a08___timestamp
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a09___text
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a10___varying
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a11___null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a12___blob
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a13___array
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a14___boolean
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a15___int128
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a16___decfloat16
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a17___decfloat34
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a18___timestamp_with_tz
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_a19___time_with_tz
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 private:
  using msg_data_buffer_type
   =isc_base::t_isc_xsqlda_v1_svc__msg_data::msg_data_buffer_type;

  static void EXEC__Build_XSQLDA_MSG_DATA
               (const isc_api::XSQLDA_V1* pXSQLDA,
                msg_data_buffer_type&     DataBuffer);
};//class TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA

////////////////////////////////////////////////////////////////////////////////

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::EXEC__Build_XSQLDA_MSG_DATA
                                           (const isc_api::XSQLDA_V1* pXSQLDA,
                                            msg_data_buffer_type&     DataBuffer)
{
 const db_obj::t_db_object_ptr
  spObj
   (ibp::db_obj::dbms_fb::v04_0_0::fb_v04_0_0__xsqlda_v1_svc__msg_data::create());

 const isc_base::t_isc_xsqlda_v1_svc__msg_data_ptr
  spMsgDataSvc
   (dynamic_cast<isc_base::t_isc_xsqlda_v1_svc__msg_data*>(spObj.ptr()));

 _TSO_CHECK(spMsgDataSvc);

 spMsgDataSvc->Build_XSQLDA_MSG_DATA
  (pXSQLDA,
   DataBuffer);
}//EXEC__Build_XSQLDA_MSG_DATA

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_001___null_ptr
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 msg_data_buffer_type buf(100);

 self_type::EXEC__Build_XSQLDA_MSG_DATA(nullptr,buf);

 _TSO_CHECK(buf.empty());
}//test_001___null_ptr

////////////////////////////////////////////////////////////////////////////////
//TEST 002

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_002___empty
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 msg_data_buffer_type buf(100);

 XSQLDA_V1_Wrapper xsqlda(0);

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 _TSO_CHECK(buf.empty());
}//test_002___empty

////////////////////////////////////////////////////////////////////////////////
//TEST 003

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_003___err__unk_sql_type
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 msg_data_buffer_type buf(100);

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=24;

 for(;;)
 {
  try
  {
   self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);
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
//TEST 004

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_004___err__null_ptr_in_sqlind
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 msg_data_buffer_type buf(100);

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 db_obj::t_dbvalue__i4 value=0;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =nullptr;

 for(;;)
 {
  try
  {
   self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   errSvc::check_err_rec__xsqlda_err__incorrect_sqlind_ptr
    (tracer,
     exc.get_record(0),
     isc_api::ibp_isc_sql_long|1);

   errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_data
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb4_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_004___err__null_ptr_in_sqlind

////////////////////////////////////////////////////////////////////////////////
//TEST 005

#ifdef NDEBUG

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_005___err__incorrect_varchar_data_length
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 struct tag_varchar
 {
  db_obj::t_dbvalue__i2 len;
  char                  data[100];
 };//tag_varchar

 tag_varchar value={-10,{0}};

 //-----------------------------------------
 msg_data_buffer_type buf(100);

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_varying;
 xsqlda->sqlvar[0].sqllen  =sizeof(value.data);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =nullptr;

 for(;;)
 {
  try
  {
   self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   errSvc::check_err_rec__xsqlda_err__incorrect_varchar_data_length
    (tracer,
     exc.get_record(0),
     -10);

   errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_data
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb4_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_005___err__incorrect_varchar_data_length

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 006

#ifdef NDEBUG

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_006___err__varchar_data_length_is_greater_than_buffer_size
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 tracer<<L"Hello from test!"<<send;

 //-----------------------------------------
 struct tag_varchar
 {
  db_obj::t_dbvalue__i2 len;
  char                  data[100];
 };//tag_varchar

 tag_varchar value={101,{0}};

 //-----------------------------------------
 msg_data_buffer_type buf(100);

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_varying;
 xsqlda->sqlvar[0].sqllen  =sizeof(value.data);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =nullptr;

 for(;;)
 {
  try
  {
   self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   errSvc::check_err_rec__xsqlda_err__varchar_data_length_is_greater_than_buffer_size
    (tracer,
     exc.get_record(0),
     101,
     sizeof(value.data));

   errSvc::check_err_rec__xsqlda_err__failed_to_process_xsqlvar_data
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb4_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_006___err__varchar_data_length_is_greater_than_buffer_size

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST T01

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t01___bug_check__incorrect_sqllen__varchar
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

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t02___bug_check__incorrect_sqllen__char
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

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t03___bug_check__incorrect_sqllen__short
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

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t04___bug_check__incorrect_sqllen__long
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

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t05___bug_check__incorrect_sqllen__int64
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

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t06___bug_check__incorrect_sqllen__float
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

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t07___bug_check__incorrect_sqllen__double
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

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t08___bug_check__incorrect_sqllen__time
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

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t09___bug_check__incorrect_sqllen__date
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

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t10___bug_check__incorrect_sqllen__timestamp
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 for(short x=-33;x!=33;++x)
 {
  if(x==8)
   continue;

  helper_txx(pParams,
             pCtx,
             isc_api::ibp_isc_sql_timestamp,
             x,
             L"sql_timestamp");

  helper_txx(pParams,
             pCtx,
             isc_api::ibp_isc_sql_timestamp|1,
             x,
             L"sql_timestamp");
 }//for x
}//test_t10___bug_check__incorrect_sqllen__timestamp

////////////////////////////////////////////////////////////////////////////////
//TEST T11

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t11___bug_check__incorrect_sqllen__blob
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

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t12___bug_check__incorrect_sqllen__array
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

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t13___bug_check__incorrect_sqllen__null
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

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t14___bug_check__incorrect_sqllen__boolean
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

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t15___bug_check__incorrect_sqllen__int128
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

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t16___bug_check__incorrect_sqllen__decfloat16
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 for(short sz=-32;sz!=33;++sz)
 {
  if(sz==8)
   continue;

  helper_txx
   (pParams,
    pCtx,
    isc_api::ibp_fb040_sql_decfloat16,
    sz,
    L"sql_decfloat16");

  helper_txx
   (pParams,
    pCtx,
    isc_api::ibp_fb040_sql_decfloat16|1,
    sz,
    L"sql_decfloat16");
 }//for sz
}//test_t16___bug_check__incorrect_sqllen__decfloat16

////////////////////////////////////////////////////////////////////////////////
//TEST T17

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t17___bug_check__incorrect_sqllen__decfloat34
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 for(short sz=-32;sz!=33;++sz)
 {
  if(sz==16)
   continue;

  helper_txx
   (pParams,
    pCtx,
    isc_api::ibp_fb040_sql_decfloat34,
    sz,
    L"sql_decfloat34");

  helper_txx
   (pParams,
    pCtx,
    isc_api::ibp_fb040_sql_decfloat34|1,
    sz,
    L"sql_decfloat34");
 }//for sz
}//test_t17___bug_check__incorrect_sqllen__decfloat34

////////////////////////////////////////////////////////////////////////////////
//TEST T18

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t18___bug_check__incorrect_sqllen__timestamp_with_tz
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 for(short sz=-32;sz!=33;++sz)
 {
  if(sz==12)
   continue;

  helper_txx
   (pParams,
    pCtx,
    isc_api::ibp_fb040_sql_timestamp_with_tz,
    sz,
    L"sql_timestamp_with_tz");

  helper_txx
   (pParams,
    pCtx,
    isc_api::ibp_fb040_sql_timestamp_with_tz|1,
    sz,
    L"sql_timestamp_with_tz");
 }//for sz
}//test_t18___bug_check__incorrect_sqllen__timestamp_with_tz

////////////////////////////////////////////////////////////////////////////////
//TEST T18

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_t19___bug_check__incorrect_sqllen__time_with_tz
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 for(short sz=-32;sz!=33;++sz)
 {
  if(sz==8)
   continue;

  helper_txx
   (pParams,
    pCtx,
    isc_api::ibp_fb040_sql_time_with_tz,
    sz,
    L"sql_time_with_tz");

  helper_txx
   (pParams,
    pCtx,
    isc_api::ibp_fb040_sql_time_with_tz|1,
    sz,
    L"sql_time_with_tz");
 }//for sz
}//test_t19___bug_check__incorrect_sqllen__time_with_tz

////////////////////////////////////////////////////////////////////////////////
//HELPER TXX

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::helper_txx
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
 msg_data_buffer_type buf(100);

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=sqltype;
 xsqlda->sqlvar[0].sqllen =sqllen;

 for(;;)
 {
  try
  {
   self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);
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
//D01

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d01___short
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i2  value=12345;
 short                  sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_short|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value),
           reinterpret_cast<unsigned char*>(&value)+sizeof(value),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d01___short

////////////////////////////////////////////////////////////////////////////////
//D02

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d02___long
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i4  value=-123456789;
 short                  sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value),
           reinterpret_cast<unsigned char*>(&value)+sizeof(value),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d02___long

////////////////////////////////////////////////////////////////////////////////
//D03

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d03___int64
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i8  value=-12345678901234567;
 short                  sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value),
           reinterpret_cast<unsigned char*>(&value)+sizeof(value),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d03___int64

////////////////////////////////////////////////////////////////////////////////
//D04

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d04___float
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__r4  value=-12345;
 short                  sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_float|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value),
           reinterpret_cast<unsigned char*>(&value)+sizeof(value),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d04___float

////////////////////////////////////////////////////////////////////////////////
//D05

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d05___double
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__r8  value=-123456789.5;
 short                  sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_double|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value),
           reinterpret_cast<unsigned char*>(&value)+sizeof(value),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d05___double

////////////////////////////////////////////////////////////////////////////////
//D06

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d06___time
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 isc_api::t_ibp_isc_time  value=1234567;
 short                    sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_type_time|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value),
           reinterpret_cast<unsigned char*>(&value)+sizeof(value),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d06___time

////////////////////////////////////////////////////////////////////////////////
//D07

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d07___date
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 isc_api::t_ibp_isc_date  value=1234567;
 short                    sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_type_date|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value),
           reinterpret_cast<unsigned char*>(&value)+sizeof(value),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d07___date

////////////////////////////////////////////////////////////////////////////////
//D08

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d08___timestamp
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 isc_api::t_ibp_isc_timestamp  value={1234567,7654321};
 short                         sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_timestamp|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value),
           reinterpret_cast<unsigned char*>(&value)+sizeof(value),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d08___timestamp

////////////////////////////////////////////////////////////////////////////////
//D09

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d09___text
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 char  value[]={1,2,3,4,5,6,7,0,9};
 short sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value),
           reinterpret_cast<unsigned char*>(&value)+sizeof(value),
           std::back_inserter(expected_buf));

 expected_buf.push_back(0); //align

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d09___text

////////////////////////////////////////////////////////////////////////////////
//D10

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d10___varying
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_varchar
 {
  db_obj::t_dbvalue__i2 len;
  char                  data[9];
 };//class tag_varchar

 tag_varchar value={7,{1,2,3,4,5,0,9,1,1}};
 short       sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_varying|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value.data);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value.len),
           reinterpret_cast<unsigned char*>(&value.len)+sizeof(value.len),
           std::back_inserter(expected_buf));

 std::copy(value.data,
           value.data+value.len,
           std::back_inserter(expected_buf));

 for(size_t i=(size_t)value.len;i!=sizeof(value.data);++i)
  expected_buf.push_back(0);

 expected_buf.push_back(0); //align

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d10___varying

////////////////////////////////////////////////////////////////////////////////
//D11

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d11___null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 short sqlind=-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb025_sql_null|1;
 xsqlda->sqlvar[0].sqllen  =0;
 xsqlda->sqlvar[0].sqldata =nullptr;
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d11___null

////////////////////////////////////////////////////////////////////////////////
//D12

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d12___blob
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::DB_IBBLOBID  value={1234567,7654321};
 short                sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_blob|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value),
           reinterpret_cast<unsigned char*>(&value)+sizeof(value),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d12___blob

////////////////////////////////////////////////////////////////////////////////
//D13

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d13___array
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::DB_IBARRAYID value={1234567,7654321};
 short                sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_array|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value),
           reinterpret_cast<unsigned char*>(&value)+sizeof(value),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d13___array

////////////////////////////////////////////////////////////////////////////////
//D14

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d14___boolean
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 isc_api::t_ibp_fb030_bool  value=isc_api::ibp_fb030_true;
 short                      sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb030_sql_boolean|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value),
           reinterpret_cast<unsigned char*>(&value)+sizeof(value),
           std::back_inserter(expected_buf));

 expected_buf.push_back(0); //align

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d14___boolean

////////////////////////////////////////////////////////////////////////////////
//D15

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d15___int128
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__fb040_int128 value=db_obj::make_fb040_int128(12345678901234567,987654321098765);
 short                           sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb040_sql_int128|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value),
           reinterpret_cast<unsigned char*>(&value)+sizeof(value),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d15___int128

////////////////////////////////////////////////////////////////////////////////
//D16

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d16___decfloat16
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__fb040_decfloat16 value=db_obj::make_fb040_decfloat16(12345678901234567);
 short                               sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb040_sql_decfloat16|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value),
           reinterpret_cast<unsigned char*>(&value)+sizeof(value),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d16___decfloat16

////////////////////////////////////////////////////////////////////////////////
//D17

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d17___decfloat34
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__fb040_decfloat34 value=db_obj::make_fb040_decfloat34(5792501206129316193, 5824638083864100507);
 short                               sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb040_sql_decfloat34|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value),
           reinterpret_cast<unsigned char*>(&value)+sizeof(value),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_d17___decfloat34

////////////////////////////////////////////////////////////////////////////////
//D18

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d18___timestamp_with_tz
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 using value_type=db_obj::t_dbvalue__fb040_timestamp_with_tz;

 value_type value=db_obj::make_fb040_timestamp_with_tz(1,2,3);
 short      sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb040_sql_timestamp_with_tz|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 _TSO_CHECK(buf.size()==(sizeof(value)+sizeof(sqlind)));

 _TSO_CHECK(*reinterpret_cast<const value_type*>(buf.data())==value);

 _TSO_CHECK(*reinterpret_cast<const short*>(buf.ptr_at(sizeof(value_type)))==sqlind);
}//test_d18___timestamp_with_tz

////////////////////////////////////////////////////////////////////////////////
//D18

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_d19___time_with_tz
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 using value_type=db_obj::t_dbvalue__fb040_time_with_tz;

 value_type value=db_obj::make_fb040_time_with_tz(2,3);
 short      sqlind=0;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb040_sql_time_with_tz|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 _TSO_CHECK(buf.size()==(sizeof(value)+sizeof(sqlind)));

 _TSO_CHECK(*reinterpret_cast<const value_type*>(buf.data())==value);

 _TSO_CHECK(*reinterpret_cast<const short*>(buf.ptr_at(sizeof(value_type)))==sqlind);
}//test_d19___time_with_tz

////////////////////////////////////////////////////////////////////////////////
//N01

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n01___short
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i2  value      =12345;
 db_obj::t_dbvalue__i2  value__null=0;
 short                  sqlind     =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_short|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value__null),
           reinterpret_cast<unsigned char*>(&value__null)+sizeof(value__null),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_n01___short

////////////////////////////////////////////////////////////////////////////////
//N02

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n02___long
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i4  value      =-123456789;
 db_obj::t_dbvalue__i4  value__null=0;
 short                  sqlind     =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value__null),
           reinterpret_cast<unsigned char*>(&value__null)+sizeof(value__null),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_n02___long

////////////////////////////////////////////////////////////////////////////////
//N03

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n03___int64
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i8  value      =-12345678901234567;
 db_obj::t_dbvalue__i8  value__null=0;
 short                  sqlind     =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value__null),
           reinterpret_cast<unsigned char*>(&value__null)+sizeof(value__null),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_n03___int64

////////////////////////////////////////////////////////////////////////////////
//N04

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n04___float
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__r4  value      =-12345;
 db_obj::t_dbvalue__r4  value__null=0;
 short                  sqlind     =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_float|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value__null),
           reinterpret_cast<unsigned char*>(&value__null)+sizeof(value__null),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_n04___float

////////////////////////////////////////////////////////////////////////////////
//N05

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n05___double
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__r8  value      =-123456789.5;
 db_obj::t_dbvalue__r8  value__null=0;
 short                  sqlind     =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_double|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value__null),
           reinterpret_cast<unsigned char*>(&value__null)+sizeof(value__null),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_n05___double

////////////////////////////////////////////////////////////////////////////////
//N06

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n06___time
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 isc_api::t_ibp_isc_time  value      =1234567;
 isc_api::t_ibp_isc_time  value__null=0;
 short                    sqlind     =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_type_time|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value__null),
           reinterpret_cast<unsigned char*>(&value__null)+sizeof(value__null),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_n06___time

////////////////////////////////////////////////////////////////////////////////
//N07

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n07___date
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 isc_api::t_ibp_isc_date  value      =1234567;
 isc_api::t_ibp_isc_date  value__null=0;
 short                    sqlind     =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_type_date|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value__null),
           reinterpret_cast<unsigned char*>(&value__null)+sizeof(value__null),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_n07___date

////////////////////////////////////////////////////////////////////////////////
//N08

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n08___timestamp
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 isc_api::t_ibp_isc_timestamp  value      ={1234567,7654321};
 isc_api::t_ibp_isc_timestamp  value__null={0,0};
 short                         sqlind     =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_timestamp|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value__null),
           reinterpret_cast<unsigned char*>(&value__null)+sizeof(value__null),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_n08___timestamp

////////////////////////////////////////////////////////////////////////////////
//N09

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n09___text
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 char  value[]      ={1,2,3,4,5,6,7,0,9};
 char  value__null[]={0,0,0,0,0,0,0,0,0};
 short sqlind       =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value__null),
           reinterpret_cast<unsigned char*>(&value__null)+sizeof(value__null),
           std::back_inserter(expected_buf));

 expected_buf.push_back(0); //align

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_n09___text

////////////////////////////////////////////////////////////////////////////////
//N09

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n10___varying
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_varchar
 {
  db_obj::t_dbvalue__i2 len;
  char                  data[9];
 };//class tag_varchar

 tag_varchar value      ={7,{1,2,3,4,5,0,9,1,1}};
 tag_varchar value__null={0,{0,0,0,0,0,0,0,0,0}};
 short       sqlind     =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_varying|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value.data);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value__null.len),
           reinterpret_cast<unsigned char*>(&value__null.len)+sizeof(value__null.len),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&value__null.data),
           reinterpret_cast<unsigned char*>(&value__null.data)+sizeof(value__null.data),
           std::back_inserter(expected_buf));

 expected_buf.push_back(0); //align

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_n10___varying

////////////////////////////////////////////////////////////////////////////////
//N12

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n12___blob
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::DB_IBBLOBID  value       ={1234567,7654321};
 db_obj::DB_IBBLOBID  value__null ={0,0};
 short                sqlind      =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_blob|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value__null),
           reinterpret_cast<unsigned char*>(&value__null)+sizeof(value__null),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_n12___blob

////////////////////////////////////////////////////////////////////////////////
//N13

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n13___array
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::DB_IBARRAYID value       ={1234567,7654321};
 db_obj::DB_IBARRAYID value__null ={0,0};
 short                sqlind      =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_array|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value__null),
           reinterpret_cast<unsigned char*>(&value__null)+sizeof(value__null),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_n13___array

////////////////////////////////////////////////////////////////////////////////
//N14

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n14___boolean
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 isc_api::t_ibp_fb030_bool value      =isc_api::ibp_fb030_true;
 isc_api::t_ibp_fb030_bool value__null=0;
 short                     sqlind     =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb030_sql_boolean|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value__null),
           reinterpret_cast<unsigned char*>(&value__null)+sizeof(value__null),
           std::back_inserter(expected_buf));

 expected_buf.push_back(0); //align

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_n14___boolean

////////////////////////////////////////////////////////////////////////////////
//N15

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n15___int128
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__fb040_int128  value      =db_obj::make_fb040_int128(12345678901234567,76543210987654321);
 db_obj::t_dbvalue__fb040_int128  value__null=db_obj::make_fb040_int128(0,0);
 short                  sqlind               =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb040_sql_int128|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&value__null),
           reinterpret_cast<unsigned char*>(&value__null)+sizeof(value__null),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind),
           reinterpret_cast<unsigned char*>(&sqlind)+sizeof(sqlind),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_n15___int128

////////////////////////////////////////////////////////////////////////////////
//N16

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n16___decfloat16
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 using value_type=db_obj::t_dbvalue__fb040_decfloat16;

 value_type value  ={12345678901234567ui64};
 short      sqlind =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb040_sql_decfloat16|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 assert_s(sizeof(value_type)+sizeof(short)==8+2);
 assert_s(sizeof(sqlind)==2);

 _TSO_CHECK(buf.size()==8+2);

 _TSO_CHECK(*reinterpret_cast<const value_type*>(buf.ptr_at(0))==isc_api::__null__fb040_decfloat16);

 _TSO_CHECK(*reinterpret_cast<const short*>(buf.ptr_at(8))==sqlind);
}//test_n16___decfloat16

////////////////////////////////////////////////////////////////////////////////
//N17

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n17___decfloat34
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 using value_type=db_obj::t_dbvalue__fb040_decfloat34;

 value_type value  ={12345678901234567ui64,76543210987654321ui64};
 short      sqlind =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb040_sql_decfloat34|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 assert_s(sizeof(value_type)+sizeof(short)==16+2);
 assert_s(sizeof(sqlind)==2);

 _TSO_CHECK(buf.size()==16+2);

 _TSO_CHECK(*reinterpret_cast<const value_type*>(buf.ptr_at(0))==isc_api::__null__fb040_decfloat34);

 _TSO_CHECK(*reinterpret_cast<const short*>(buf.ptr_at(16))==sqlind);
}//test_n17___decfloat34

////////////////////////////////////////////////////////////////////////////////
//N18

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n18___timestamp_with_tz
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 using value_type=db_obj::t_dbvalue__fb040_timestamp_with_tz;

 value_type value  =db_obj::make_fb040_timestamp_with_tz(123456789,765432109,23456);
 short      sqlind =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb040_sql_timestamp_with_tz|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 assert_s(sizeof(value_type)+sizeof(short)==14);

 _TSO_CHECK(buf.size()==12+2);

 _TSO_CHECK(*reinterpret_cast<const value_type*>(buf.ptr_at(0))==isc_api::__null__fb040_timestamp_with_tz);

 _TSO_CHECK(*reinterpret_cast<const short*>(buf.ptr_at(12))==sqlind);
}//test_n18___timestamp_with_tz

////////////////////////////////////////////////////////////////////////////////
//N18

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_n19___time_with_tz
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 using value_type=db_obj::t_dbvalue__fb040_time_with_tz;

 value_type value  =db_obj::make_fb040_time_with_tz(765432109,23456);
 short      sqlind =-1;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb040_sql_time_with_tz|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value);
 xsqlda->sqlvar[0].sqlind  =&sqlind;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 assert_s(sizeof(value_type)+sizeof(short)==10);

 _TSO_CHECK(buf.size()==8+2);

 _TSO_CHECK(*reinterpret_cast<const value_type*>(buf.ptr_at(0))==isc_api::__null__fb040_time_with_tz);

 _TSO_CHECK(*reinterpret_cast<const short*>(buf.ptr_at(8))==sqlind);
}//test_n19___time_with_tz

////////////////////////////////////////////////////////////////////////////////
//A01

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a01___short
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i8 value1=_I64_MIN;
 short                 sqlind1=0;

 db_obj::t_dbvalue__i2 value2=4321;
 short                 sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_short|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1),
           reinterpret_cast<unsigned char*>(&value1)+sizeof(value1),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //----- align

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2),
           reinterpret_cast<unsigned char*>(&value2)+sizeof(value2),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a01___short

////////////////////////////////////////////////////////////////////////////////
//A02

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a02___long
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i8 value1=_I64_MIN;
 short                 sqlind1=0;

 db_obj::t_dbvalue__i4 value2=4321222;
 short                 sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1),
           reinterpret_cast<unsigned char*>(&value1)+sizeof(value1),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //----- align
 expected_buf.push_back(0);
 expected_buf.push_back(0);

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2),
           reinterpret_cast<unsigned char*>(&value2)+sizeof(value2),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a02___long

////////////////////////////////////////////////////////////////////////////////
//A03

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a03___int64
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i8 value1=_I64_MIN;
 short                 sqlind1=0;

 db_obj::t_dbvalue__i8 value2=432122265432187654i64;
 short                 sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1),
           reinterpret_cast<unsigned char*>(&value1)+sizeof(value1),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //----- align
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2),
           reinterpret_cast<unsigned char*>(&value2)+sizeof(value2),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a03___int64

////////////////////////////////////////////////////////////////////////////////
//A04

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a04___float
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i8 value1=_I64_MIN;
 short                 sqlind1=0;

 db_obj::t_dbvalue__r4 value2=12345;
 short                 sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_float|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1),
           reinterpret_cast<unsigned char*>(&value1)+sizeof(value1),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //----- align
 expected_buf.push_back(0);
 expected_buf.push_back(0);

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2),
           reinterpret_cast<unsigned char*>(&value2)+sizeof(value2),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a04___float

////////////////////////////////////////////////////////////////////////////////
//A05

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a05___double
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i8 value1=_I64_MIN;
 short                 sqlind1=0;

 db_obj::t_dbvalue__r8 value2=1234567890123;
 short                 sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_double|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1),
           reinterpret_cast<unsigned char*>(&value1)+sizeof(value1),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //----- align
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2),
           reinterpret_cast<unsigned char*>(&value2)+sizeof(value2),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a05___double

////////////////////////////////////////////////////////////////////////////////
//A06

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a06___time
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i8 value1=_I64_MIN;
 short                 sqlind1=0;

 isc_api::t_ibp_isc_time  value2=12345678;
 short                    sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_type_time|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1),
           reinterpret_cast<unsigned char*>(&value1)+sizeof(value1),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //----- align
 expected_buf.push_back(0);
 expected_buf.push_back(0);

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2),
           reinterpret_cast<unsigned char*>(&value2)+sizeof(value2),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a06___time

////////////////////////////////////////////////////////////////////////////////
//A07

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a07___date
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i8 value1=_I64_MIN;
 short                 sqlind1=0;

 isc_api::t_ibp_isc_date  value2=12345678;
 short                    sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_type_date|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1),
           reinterpret_cast<unsigned char*>(&value1)+sizeof(value1),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //----- align
 expected_buf.push_back(0);
 expected_buf.push_back(0);

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2),
           reinterpret_cast<unsigned char*>(&value2)+sizeof(value2),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a07___date

////////////////////////////////////////////////////////////////////////////////
//A08

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a08___timestamp
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i8 value1=_I64_MIN;
 short                 sqlind1=0;

 isc_api::t_ibp_isc_timestamp value2={12345678,87654321};
 short                        sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_timestamp|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1),
           reinterpret_cast<unsigned char*>(&value1)+sizeof(value1),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //----- align
 expected_buf.push_back(0);
 expected_buf.push_back(0);

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2),
           reinterpret_cast<unsigned char*>(&value2)+sizeof(value2),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a08___timestamp

////////////////////////////////////////////////////////////////////////////////
//A09

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a09___text
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 char    value1[5]={1,2,' ',4,' '};
 short   sqlind1=0;

 char    value2[7]={7,6,' ',' ',' ',' ',' '};
 short   sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1),
           reinterpret_cast<unsigned char*>(&value1)+sizeof(value1),
           std::back_inserter(expected_buf));

 expected_buf.push_back(0);

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //----- align

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2),
           reinterpret_cast<unsigned char*>(&value2)+sizeof(value2),
           std::back_inserter(expected_buf));

 expected_buf.push_back(0);

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a09___text

////////////////////////////////////////////////////////////////////////////////
//A10

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a10___varying
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 struct tag_varchar
 {
  db_obj::t_dbvalue__i2 len;
  char                  data[9];
 };//tag_varchar

 //-----------------------------------------
 tag_varchar  value1={5,{1,2,' ',4,' '}};
 short        sqlind1=0;

 tag_varchar  value2={7,{7,6,' ',' ',' ',' ',' '}};
 short        sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_varying|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1.data);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_varying|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2.data);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1.len),
           reinterpret_cast<unsigned char*>(&value1.len)+sizeof(value1.len),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&value1.data),
           reinterpret_cast<unsigned char*>(&value1.data)+sizeof(value1.data),
           std::back_inserter(expected_buf));

 expected_buf.push_back(0);

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //----- align

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2.len),
           reinterpret_cast<unsigned char*>(&value2.len)+sizeof(value2.len),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&value2.data),
           reinterpret_cast<unsigned char*>(&value2.data)+sizeof(value2.data),
           std::back_inserter(expected_buf));

 expected_buf.push_back(0);

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a10___varying

////////////////////////////////////////////////////////////////////////////////
//A11

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a11___null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 short sqlind1=-1;
 short sqlind2=0;
 short sqlind3=-0;

 XSQLDA_V1_Wrapper xsqlda(3);

 xsqlda->sqld=3;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb025_sql_null|1;
 xsqlda->sqlvar[0].sqllen  =0;
 xsqlda->sqlvar[0].sqldata =nullptr;
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb025_sql_null|1;
 xsqlda->sqlvar[1].sqllen  =0;
 xsqlda->sqlvar[1].sqldata =nullptr;
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 xsqlda->sqlvar[2].sqltype =isc_api::ibp_fb025_sql_null|1;
 xsqlda->sqlvar[2].sqllen  =0;
 xsqlda->sqlvar[2].sqldata =nullptr;
 xsqlda->sqlvar[2].sqlind  =&sqlind3;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind3),
           reinterpret_cast<unsigned char*>(&sqlind3)+sizeof(sqlind3),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a11___null

////////////////////////////////////////////////////////////////////////////////
//A12

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a12___blob
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i8 value1=_I64_MIN;
 short                 sqlind1=0;

 db_obj::DB_IBBLOBID   value2={1234567,7654321};
 short                 sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_blob|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1),
           reinterpret_cast<unsigned char*>(&value1)+sizeof(value1),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //----- align
 expected_buf.push_back(0);
 expected_buf.push_back(0);

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2),
           reinterpret_cast<unsigned char*>(&value2)+sizeof(value2),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a12___blob

////////////////////////////////////////////////////////////////////////////////
//A13

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a13___array
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__i8 value1=_I64_MIN;
 short                 sqlind1=0;

 db_obj::DB_IBBLOBID   value2={1234567,7654321};
 short                 sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_isc_sql_array|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1),
           reinterpret_cast<unsigned char*>(&value1)+sizeof(value1),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //----- align
 expected_buf.push_back(0);
 expected_buf.push_back(0);

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2),
           reinterpret_cast<unsigned char*>(&value2)+sizeof(value2),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a13___array

////////////////////////////////////////////////////////////////////////////////
//A14

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a14___boolean
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 isc_api::t_ibp_fb030_bool value1=isc_api::ibp_fb030_true;
 short                     sqlind1=0;

 isc_api::t_ibp_fb030_bool value2=isc_api::ibp_fb030_false;
 short                     sqlind2=0;

 isc_api::t_ibp_fb030_bool value3=isc_api::ibp_fb030_true;
 short                     sqlind3=0;

 XSQLDA_V1_Wrapper xsqlda(3);

 xsqlda->sqld=3;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb030_sql_boolean|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb030_sql_boolean|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 xsqlda->sqlvar[2].sqltype =isc_api::ibp_fb030_sql_boolean|1;
 xsqlda->sqlvar[2].sqllen  =sizeof(value3);
 xsqlda->sqlvar[2].sqldata =reinterpret_cast<char*>(&value3);
 xsqlda->sqlvar[2].sqlind  =&sqlind3;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1),
           reinterpret_cast<unsigned char*>(&value1)+sizeof(value1),
           std::back_inserter(expected_buf));

 expected_buf.push_back(0); //align

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2),
           reinterpret_cast<unsigned char*>(&value2)+sizeof(value2),
           std::back_inserter(expected_buf));

 expected_buf.push_back(0); //align

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value3),
           reinterpret_cast<unsigned char*>(&value3)+sizeof(value3),
           std::back_inserter(expected_buf));

 expected_buf.push_back(0); //align

 std::copy(reinterpret_cast<unsigned char*>(&sqlind3),
           reinterpret_cast<unsigned char*>(&sqlind3)+sizeof(sqlind3),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a14___boolean

////////////////////////////////////////////////////////////////////////////////
//A15

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a15___int128
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__fb040_int128 value1=db_obj::make_fb040_int128(123456789012345ui64,543210987654321ui64);
 short                           sqlind1=0;

 db_obj::t_dbvalue__fb040_int128 value2=db_obj::make_fb040_int128(444444444444444ui64,555555555555555ui64);
 short                           sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb040_sql_int128|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb040_sql_int128|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1),
           reinterpret_cast<unsigned char*>(&value1)+sizeof(value1),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //----- align
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2),
           reinterpret_cast<unsigned char*>(&value2)+sizeof(value2),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a15___int128

////////////////////////////////////////////////////////////////////////////////
//A16

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a16___decfloat16
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__fb040_decfloat16 value1=db_obj::make_fb040_decfloat16(123456789012345ui64);
 short                               sqlind1=0;

 db_obj::t_dbvalue__fb040_decfloat16 value2=db_obj::make_fb040_decfloat16(444444444444444ui64);
 short                               sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb040_sql_decfloat16|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb040_sql_decfloat16|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1),
           reinterpret_cast<unsigned char*>(&value1)+sizeof(value1),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //----- align
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2),
           reinterpret_cast<unsigned char*>(&value2)+sizeof(value2),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a16___decfloat16

////////////////////////////////////////////////////////////////////////////////
//A17

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a17___decfloat34
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 db_obj::t_dbvalue__fb040_decfloat34 value1=db_obj::make_fb040_decfloat34(123456789012345ui64,543210987654321ui64);
 short                               sqlind1=0;

 db_obj::t_dbvalue__fb040_decfloat34 value2=db_obj::make_fb040_decfloat34(444444444444444ui64,555555555555555ui64);
 short                               sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb040_sql_decfloat34|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb040_sql_decfloat34|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 structure::t_fix_vector<unsigned char,100> expected_buf;

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value1),
           reinterpret_cast<unsigned char*>(&value1)+sizeof(value1),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind1),
           reinterpret_cast<unsigned char*>(&sqlind1)+sizeof(sqlind1),
           std::back_inserter(expected_buf));

 //----- align
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);
 expected_buf.push_back(0);

 //-----
 std::copy(reinterpret_cast<unsigned char*>(&value2),
           reinterpret_cast<unsigned char*>(&value2)+sizeof(value2),
           std::back_inserter(expected_buf));

 std::copy(reinterpret_cast<unsigned char*>(&sqlind2),
           reinterpret_cast<unsigned char*>(&sqlind2)+sizeof(sqlind2),
           std::back_inserter(expected_buf));

 //-----------------------------------------
 _TSO_CHECK(structure::equal(buf.buffer(),
                             buf.buffer_end(),
                             expected_buf.cbegin(),
                             expected_buf.cend()));
}//test_a17___decfloat34

////////////////////////////////////////////////////////////////////////////////
//A18

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a18___timestamp_with_tz
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 using value_type=db_obj::t_dbvalue__fb040_timestamp_with_tz;

 value_type value1=db_obj::make_fb040_timestamp_with_tz(123456789,987654321,54321);
 short      sqlind1=0;

 value_type value2=db_obj::make_fb040_timestamp_with_tz(234567890,345678901,33333);
 short      sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb040_sql_timestamp_with_tz|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb040_sql_timestamp_with_tz|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 assert_s(2*(sizeof(value_type)+sizeof(short))+2==30);

 _TSO_CHECK(buf.size()==30);

 _TSO_CHECK(*reinterpret_cast<const value_type*>(buf.ptr_at(0))==value1);

 _TSO_CHECK(*reinterpret_cast<const short*>(buf.ptr_at(12))==sqlind1);

 _TSO_CHECK(*reinterpret_cast<const value_type*>(buf.ptr_at(16))==value2);

 _TSO_CHECK(*reinterpret_cast<const short*>(buf.ptr_at(28))==sqlind2);
}//test_a18___timestamp_with_tz

////////////////////////////////////////////////////////////////////////////////
//A18

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::test_a19___time_with_tz
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 using value_type=db_obj::t_dbvalue__fb040_time_with_tz;

 value_type value1=db_obj::make_fb040_time_with_tz(987654321,54321);
 short      sqlind1=0;

 value_type value2=db_obj::make_fb040_time_with_tz(345678901,33333);
 short      sqlind2=0;

 XSQLDA_V1_Wrapper xsqlda(2);

 xsqlda->sqld=2;

 xsqlda->sqlvar[0].sqltype =isc_api::ibp_fb040_sql_time_with_tz|1;
 xsqlda->sqlvar[0].sqllen  =sizeof(value1);
 xsqlda->sqlvar[0].sqldata =reinterpret_cast<char*>(&value1);
 xsqlda->sqlvar[0].sqlind  =&sqlind1;

 xsqlda->sqlvar[1].sqltype =isc_api::ibp_fb040_sql_time_with_tz|1;
 xsqlda->sqlvar[1].sqllen  =sizeof(value2);
 xsqlda->sqlvar[1].sqldata =reinterpret_cast<char*>(&value2);
 xsqlda->sqlvar[1].sqlind  =&sqlind2;

 //-----------------------------------------
 msg_data_buffer_type buf;

 self_type::EXEC__Build_XSQLDA_MSG_DATA(xsqlda,buf);

 //-----------------------------------------
 assert_s(2*(sizeof(value_type)+sizeof(short))+2==22);

 _TSO_CHECK(buf.size()==22);

 _TSO_CHECK(*reinterpret_cast<const value_type*>(buf.ptr_at(0))==value1);

 _TSO_CHECK(*reinterpret_cast<const short*>(buf.ptr_at(8))==sqlind1);

 _TSO_CHECK(*reinterpret_cast<const value_type*>(buf.ptr_at(12))==value2);

 _TSO_CHECK(*reinterpret_cast<const short*>(buf.ptr_at(20))==sqlind2);
}//test_a19___time_with_tz

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_descr

struct TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_impl::func},

const TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::tag_descr
 TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::sm_Tests[]=
{
 DEF_TEST_DESCR("001.null_ptr",
                test_001___null_ptr)
 DEF_TEST_DESCR("002.empty",
                test_002___empty)
 DEF_TEST_DESCR("003.err.unk_sql_type",
                test_003___err__unk_sql_type)
 DEF_TEST_DESCR("004.err.null_ptr_in_sqlind",
                test_004___err__null_ptr_in_sqlind)
#ifdef NDEBUG
 DEF_TEST_DESCR("005.err.incorrect_varchar_data_length",
                test_005___err__incorrect_varchar_data_length)
 DEF_TEST_DESCR("006.err.varchar_data_length_is_greater_than_buffer_size",
                test_006___err__varchar_data_length_is_greater_than_buffer_size)
#endif

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

 DEF_TEST_DESCR("D01.short",
                test_d01___short)
 DEF_TEST_DESCR("D02.long",
                test_d02___long)
 DEF_TEST_DESCR("D03.int64",
                test_d03___int64)
 DEF_TEST_DESCR("D04.float",
                test_d04___float)
 DEF_TEST_DESCR("D05.double",
                test_d05___double)
 DEF_TEST_DESCR("D06.time",
                test_d06___time)
 DEF_TEST_DESCR("D07.date",
                test_d07___date)
 DEF_TEST_DESCR("D08.timestamp",
                test_d08___timestamp)
 DEF_TEST_DESCR("D09.text",
                test_d09___text)
 DEF_TEST_DESCR("D10.varying",
                test_d10___varying)
 DEF_TEST_DESCR("D11.null",
                test_d11___null)
 DEF_TEST_DESCR("D12.blob",
                test_d12___blob)
 DEF_TEST_DESCR("D13.array",
                test_d13___array)
 DEF_TEST_DESCR("D14.boolean",
                test_d14___boolean)
 DEF_TEST_DESCR("D15.int128",
                test_d15___int128)
 DEF_TEST_DESCR("D16.decfloat16",
                test_d16___decfloat16)
 DEF_TEST_DESCR("D17.decfloat34",
                test_d17___decfloat34)
 DEF_TEST_DESCR("D18.timestamp_with_tz",
                test_d18___timestamp_with_tz)
 DEF_TEST_DESCR("D19.time_with_tz",
                test_d19___time_with_tz)

 //-----
 DEF_TEST_DESCR("N01.short",
                test_n01___short)
 DEF_TEST_DESCR("N02.long",
                test_n02___long)
 DEF_TEST_DESCR("N03.int64",
                test_n03___int64)
 DEF_TEST_DESCR("N04.float",
                test_n04___float)
 DEF_TEST_DESCR("N05.double",
                test_n05___double)
 DEF_TEST_DESCR("N06.time",
                test_n06___time)
 DEF_TEST_DESCR("N07.date",
                test_n07___date)
 DEF_TEST_DESCR("N08.timestamp",
                test_n08___timestamp)
 DEF_TEST_DESCR("N09.text",
                test_n09___text)
 DEF_TEST_DESCR("N10.varying",
                test_n10___varying)
 DEF_TEST_DESCR("N12.blob",
                test_n12___blob)
 DEF_TEST_DESCR("N13.array",
                test_n13___array)
 DEF_TEST_DESCR("N14.boolean",
                test_n14___boolean)
 DEF_TEST_DESCR("N15.int128",
                test_n15___int128)
 DEF_TEST_DESCR("N16.decfloat16",
                test_n16___decfloat16)
 DEF_TEST_DESCR("N17.decfloat34",
                test_n17___decfloat34)
 DEF_TEST_DESCR("N18.timestamp_with_tz",
                test_n18___timestamp_with_tz)
 DEF_TEST_DESCR("N19.time_with_tz",
                test_n19___time_with_tz)

 //-----
 DEF_TEST_DESCR("A01.short",
                test_a01___short)
 DEF_TEST_DESCR("A02.long",
                test_a02___long)
 DEF_TEST_DESCR("A03.int64",
                test_a03___int64)
 DEF_TEST_DESCR("A04.float",
                test_a04___float)
 DEF_TEST_DESCR("A05.double",
                test_a05___double)
 DEF_TEST_DESCR("A06.time",
                test_a06___time)
 DEF_TEST_DESCR("A07.date",
                test_a07___date)
 DEF_TEST_DESCR("A08.timestamp",
                test_a08___timestamp)
 DEF_TEST_DESCR("A09.text",
                test_a09___text)
 DEF_TEST_DESCR("A10.varying",
                test_a10___varying)
 DEF_TEST_DESCR("A11.null",
                test_a11___null)
 DEF_TEST_DESCR("A12.blob",
                test_a12___blob)
 DEF_TEST_DESCR("A13.array",
                test_a13___array)
 DEF_TEST_DESCR("A14.boolean",
                test_a14___boolean)
 DEF_TEST_DESCR("A15.int128",
                test_a15___int128)
 DEF_TEST_DESCR("A16.decfloat16",
                test_a16___decfloat16)
 DEF_TEST_DESCR("A17.decfloat34",
                test_a17___decfloat34)
 DEF_TEST_DESCR("A18.timestamp_with_tz",
                test_a18___timestamp_with_tz)
 DEF_TEST_DESCR("A19.time_with_tz",
                test_a19___time_with_tz)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA

void TestsFor__fb_v04_0_0__xsqlda_v1_svc__msg_data___Build_XSQLDA_MSG_DATA::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter
  ftestID
   ("DB_OBJ.UNITS.DBMS_FB.V04_0_0.xsqlda_v1_svc__msg_data.Build_XSQLDA_MSG_DATA.%1");

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
