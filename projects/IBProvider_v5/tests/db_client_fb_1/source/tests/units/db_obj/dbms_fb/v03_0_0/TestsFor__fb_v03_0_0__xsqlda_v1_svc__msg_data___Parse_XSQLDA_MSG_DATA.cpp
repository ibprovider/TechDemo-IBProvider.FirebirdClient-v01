////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/units/db_obj/dbms_fb/v03_0_0/TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA.h"
#include "source/test_services.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/xsqlda_v1_wrapper.h"
#include "source/db_obj/dbms_fb/v03_0_0/db_obj__dbms_fb__v03_0_0__xsqlda_v1_svc__msg_data.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/isc_base/isc_integer_to_portable_format.h"
#include <structure/test_obj/t_tso_user.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl

class TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef tag_impl                                              self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type                               context_type;

 public:
  static void test_001___null_ptr
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_002___zero_sqld
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_e01__err__not_eq_count
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_e02__err__incorrect_xvar_sqltype
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_e03__err__xvar_not_supports_null_value
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_e04__err__xvar_supports_null_value_but_has_null_ptr_in_sqlind
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_e05__err__xvar_has_incorrect_null_ptr_in_sqlind
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

  static void test_t13___bug_check__incorrect_sqllen__boolean
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_s01___bug_check__not_stable_sqlscale__short
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_s02___bug_check__not_stable_sqlscale__long
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_s03___bug_check__not_stable_sqlscale__int64
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_L01___bug_check__not_stable_sqllen__text
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_L02___bug_check__not_stable_sqllen__varying
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_V01___err__varchar__negative_length_of_value
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_V02___err__varchar__too_large_value
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_D01__short_01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D01__short_02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D01__short_03
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D01__short_03_2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D01__short_04__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_D02__long_01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D02__long_02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D02__long_03
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D02__long_03_2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D02__long_04__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_D03__int64_01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D03__int64_02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D03__int64_03
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D03__int64_03_2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D03__int64_04__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_D04__float_01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D04__float_02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D04__float_03
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D04__float_03_2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D04__float_04__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_D05__double_01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D05__double_02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D05__double_03
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D05__double_03_2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D05__double_04__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_D06__time_01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D06__time_02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D06__time_03
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D06__time_03_2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D06__time_04__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_D07__date_01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D07__date_02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D07__date_03
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D07__date_03_2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D07__date_04__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_D08__timestamp_01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D08__timestamp_02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D08__timestamp_03
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D08__timestamp_03_2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D08__timestamp_04__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_D09__blob_01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D09__blob_02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D09__blob_03
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D09__blob_03_2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D09__blob_04__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_D10__array_01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D10__array_02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D10__array_03
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D10__array_03_2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D10__array_04__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_D11__text_01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D11__text_02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D11__text_03
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D11__text_03_2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D11__text_04__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_D12__varying_01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D12__varying_02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D12__varying_03
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D12__varying_03_2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D12__varying_04__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_D14__boolean_01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D14__boolean_02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D14__boolean_03
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D14__boolean_03_2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_D14__boolean_04__null
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 private:
  using msg_data_descrs_type
   =isc_base::t_isc_xsqlda_v1_svc__msg_data::msg_data_descrs_type;

  using msg_data_buffer_type
   =isc_base::t_isc_xsqlda_v1_svc__msg_data::msg_data_buffer_type;

  static void Helper__Parse_XSQLDA_MSG_DATA
               (const msg_data_descrs_type& MsgDescrs,
                size_t                      cbMsgData,
                const void*                 pMsgData,
                const isc_api::XSQLDA_V1*   pXSQLDA);
};//class TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl

////////////////////////////////////////////////////////////////////////////////

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::Helper__Parse_XSQLDA_MSG_DATA
                                           (const msg_data_descrs_type& MsgDescrs,
                                            size_t                      cbMsgData,
                                            const void*                 pMsgData,
                                            const isc_api::XSQLDA_V1*   pXSQLDA)
{
 const db_obj::t_db_object_ptr
  spObj
   (ibp::db_obj::dbms_fb::v03_0_0::fb_v03_0_0__xsqlda_v1_svc__msg_data::create());

 const isc_base::t_isc_xsqlda_v1_svc__msg_data_ptr
  spMsgDataSvc
   (dynamic_cast<isc_base::t_isc_xsqlda_v1_svc__msg_data*>(spObj.ptr()));

 _TSO_CHECK(spMsgDataSvc);

 spMsgDataSvc->Parse_XSQLDA_MSG_DATA
  (MsgDescrs,
   cbMsgData,
   pMsgData,
   pXSQLDA);
}//Helper__Parse_XSQLDA_MSG_DATA

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_001___null_ptr
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 msg_data_descrs_type descrs;

 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/0,
   /*pMsgData*/nullptr,
   /*pXSQLDA*/nullptr);
}//test_001___null_ptr

////////////////////////////////////////////////////////////////////////////////
//TEST 001

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_002___zero_sqld
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const DEBUG_CODE(pCtx))
{
 assert(pParams);
 assert(pCtx);

 msg_data_descrs_type descrs;

 XSQLDA_V1_Wrapper xsqlda(0);

 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/0,
   /*pMsgData*/nullptr,
   /*pXSQLDA*/xsqlda);
}//test_002___zero_sqld

////////////////////////////////////////////////////////////////////////////////
//TEST E01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_e01__err__not_eq_count
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs;

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/0,
     /*pMsgData*/nullptr,
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__xsqlda_err__bug_check__other_count_of_xvars
    (tracer,
     exc.get_record(0),
     errSvc::sm_subsysID__isc_api__fb3_0,
     1,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_e01__err__not_eq_count

////////////////////////////////////////////////////////////////////////////////
//TEST E02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_e02__err__incorrect_xvar_sqltype
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype  =isc_api::ibp_isc_sql_short;
 descrs[0].m_xvar_sqlscale =0;
 descrs[0].m_msg_value_block_offset=0;
 descrs[0].m_msg_value_block_size  =2;
 descrs[0].m_msg_sqlind_offset     =2;

 //-----------------------------------------
 msg_data_buffer_type buf(4);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long;
 xsqlda->sqlvar[0].sqllen =4;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__bug_check__other_sqltype_of_xvar
    (tracer,
     exc.get_record(0),
     isc_api::ibp_isc_sql_long,
     isc_api::ibp_isc_sql_short);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_e02__err__incorrect_xvar_sqltype

////////////////////////////////////////////////////////////////////////////////
//TEST E03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_e03__err__xvar_not_supports_null_value
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype  =isc_api::ibp_isc_sql_short;
 descrs[0].m_xvar_sqlscale =0;
 descrs[0].m_msg_value_block_offset=0;
 descrs[0].m_msg_value_block_size  =2;
 descrs[0].m_msg_sqlind_offset     =2;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(4);

 *reinterpret_cast<unsigned __int16*>(buf.ptr_at(0))=12345;

 *reinterpret_cast<short*>(buf.ptr_at(2))=-1; //NULL

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_short;
 xsqlda->sqlvar[0].sqllen =2;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__xsqlvar_not_supports_null_state
    (tracer,
     exc.get_record(0),
     isc_api::ibp_isc_sql_short);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_e03__err__xvar_not_supports_null_value

////////////////////////////////////////////////////////////////////////////////
//TEST E04

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_e04__err__xvar_supports_null_value_but_has_null_ptr_in_sqlind
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype  =isc_api::ibp_isc_sql_short;
 descrs[0].m_xvar_sqlscale =0;
 descrs[0].m_msg_value_block_offset=0;
 descrs[0].m_msg_value_block_size  =2;
 descrs[0].m_msg_sqlind_offset     =2;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(4);

 *reinterpret_cast<unsigned __int16*>(buf.ptr_at(0))=12345;

 *reinterpret_cast<short*>(buf.ptr_at(2))=-1; //NULL

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_short|1;
 xsqlda->sqlvar[0].sqllen =2;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_sqlind_ptr
    (tracer,
     exc.get_record(0),
     isc_api::ibp_isc_sql_short|1);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_e04__err__xvar_supports_null_value_but_has_null_ptr_in_sqlind

////////////////////////////////////////////////////////////////////////////////
//TEST E05

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_e05__err__xvar_has_incorrect_null_ptr_in_sqlind
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype  =isc_api::ibp_isc_sql_short;
 descrs[0].m_xvar_sqlscale =0;
 descrs[0].m_msg_value_block_offset=0;
 descrs[0].m_msg_value_block_size  =2;
 descrs[0].m_msg_sqlind_offset     =2;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(4);

 *reinterpret_cast<unsigned __int16*>(buf.ptr_at(0))=12345;

 *reinterpret_cast<short*>(buf.ptr_at(2))=0; //NOT NULL

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_short|1;
 xsqlda->sqlvar[0].sqllen =2;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_sqlind_ptr
    (tracer,
     exc.get_record(0),
     isc_api::ibp_isc_sql_short|1);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_e05__err__xvar_has_incorrect_null_ptr_in_sqlind

////////////////////////////////////////////////////////////////////////////////
//TEST T01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_t01___bug_check__incorrect_sqllen__varchar
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_varying;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =4;
 descrs[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(6);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_varying;
 xsqlda->sqlvar[0].sqllen =-1;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_sqllen
    (tracer,
     exc.get_record(0),
     L"sql_varying",
     -1);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_t01___bug_check__incorrect_sqllen__varchar

////////////////////////////////////////////////////////////////////////////////
//TEST T02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_t02___bug_check__incorrect_sqllen__char
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_text;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =2;
 descrs[0].m_msg_sqlind_offset      =2;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(4);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_text;
 xsqlda->sqlvar[0].sqllen =-1;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_sqllen
    (tracer,
     exc.get_record(0),
     L"sql_text",
     -1);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_t02___bug_check__incorrect_sqllen__char

////////////////////////////////////////////////////////////////////////////////
//TEST T03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_t03___bug_check__incorrect_sqllen__short
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_short;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =2;
 descrs[0].m_msg_sqlind_offset      =2;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(4);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_short;
 xsqlda->sqlvar[0].sqllen =3;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_sqllen
    (tracer,
     exc.get_record(0),
     L"sql_short",
     3);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_t03___bug_check__incorrect_sqllen__short

////////////////////////////////////////////////////////////////////////////////
//TEST T04

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_t04___bug_check__incorrect_sqllen__long
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =4;
 descrs[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(6);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long;
 xsqlda->sqlvar[0].sqllen =1;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_sqllen
    (tracer,
     exc.get_record(0),
     L"sql_long",
     1);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_t04___bug_check__incorrect_sqllen__long

////////////////////////////////////////////////////////////////////////////////
//TEST T05

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_t05___bug_check__incorrect_sqllen__int64
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_int64;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =8;
 descrs[0].m_msg_sqlind_offset      =8;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(10);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_int64;
 xsqlda->sqlvar[0].sqllen =9;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_sqllen
    (tracer,
     exc.get_record(0),
     L"sql_int64",
     9);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_t05___bug_check__incorrect_sqllen__int64

////////////////////////////////////////////////////////////////////////////////
//TEST T06

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_t06___bug_check__incorrect_sqllen__float
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_float;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =4;
 descrs[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(6);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_float;
 xsqlda->sqlvar[0].sqllen =5;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_sqllen
    (tracer,
     exc.get_record(0),
     L"sql_float",
     5);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_t06___bug_check__incorrect_sqllen__float

////////////////////////////////////////////////////////////////////////////////
//TEST T07

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_t07___bug_check__incorrect_sqllen__double
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_double;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =8;
 descrs[0].m_msg_sqlind_offset      =8;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(10);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_double;
 xsqlda->sqlvar[0].sqllen =7;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_sqllen
    (tracer,
     exc.get_record(0),
     L"sql_double",
     7);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_t07___bug_check__incorrect_sqllen__double

////////////////////////////////////////////////////////////////////////////////
//TEST T08

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_t08___bug_check__incorrect_sqllen__time
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_type_time;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =4;
 descrs[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(6);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_type_time;
 xsqlda->sqlvar[0].sqllen =23;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_sqllen
    (tracer,
     exc.get_record(0),
     L"sql_type_time",
     23);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_t08___bug_check__incorrect_sqllen__time

////////////////////////////////////////////////////////////////////////////////
//TEST T09

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_t09___bug_check__incorrect_sqllen__date
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_type_date;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =4;
 descrs[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(6);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_type_date;
 xsqlda->sqlvar[0].sqllen =23;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_sqllen
    (tracer,
     exc.get_record(0),
     L"sql_type_date",
     23);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_t09___bug_check__incorrect_sqllen__date

////////////////////////////////////////////////////////////////////////////////
//TEST T10

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_t10___bug_check__incorrect_sqllen__timestamp
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_timestamp;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =8;
 descrs[0].m_msg_sqlind_offset      =8;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(10);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_timestamp;
 xsqlda->sqlvar[0].sqllen =11;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_sqllen
    (tracer,
     exc.get_record(0),
     L"sql_timestamp",
     11);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_t10___bug_check__incorrect_sqllen__timestamp

////////////////////////////////////////////////////////////////////////////////
//TEST T11

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_t11___bug_check__incorrect_sqllen__blob
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_blob;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =8;
 descrs[0].m_msg_sqlind_offset      =8;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(10);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_blob;
 xsqlda->sqlvar[0].sqllen =11;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_sqllen
    (tracer,
     exc.get_record(0),
     L"sql_blob",
     11);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_t11___bug_check__incorrect_sqllen__blob

////////////////////////////////////////////////////////////////////////////////
//TEST T12

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_t12___bug_check__incorrect_sqllen__array
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_array;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =8;
 descrs[0].m_msg_sqlind_offset      =8;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(10);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_array;
 xsqlda->sqlvar[0].sqllen =11;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_sqllen
    (tracer,
     exc.get_record(0),
     L"sql_array",
     11);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_t12___bug_check__incorrect_sqllen__array

////////////////////////////////////////////////////////////////////////////////
//TEST T13

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_t13___bug_check__incorrect_sqllen__boolean
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_fb030_sql_boolean;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =1;
 descrs[0].m_msg_sqlind_offset      =2;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(4);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_fb030_sql_boolean;
 xsqlda->sqlvar[0].sqllen =2;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_sqllen
    (tracer,
     exc.get_record(0),
     L"sql_boolean",
     2);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_t13___bug_check__incorrect_sqllen__boolean

////////////////////////////////////////////////////////////////////////////////
//TEST S01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_s01___bug_check__not_stable_sqlscale__short
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_short;
 descrs[0].m_xvar_sqlscale          =-2;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =2;
 descrs[0].m_msg_sqlind_offset      =2;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(4);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_short;
 xsqlda->sqlvar[0].sqlscale =-3;
 xsqlda->sqlvar[0].sqllen   =2;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__bug_check__other_sqlscale_of_xvar
    (tracer,
     exc.get_record(0),
     L"sql_short",
     -3,
     -2);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_s01___bug_check__not_stable_sqlscale__short

////////////////////////////////////////////////////////////////////////////////
//TEST S02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_s02___bug_check__not_stable_sqlscale__long
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 descrs[0].m_xvar_sqlscale          =-5;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =4;
 descrs[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(6);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_long;
 xsqlda->sqlvar[0].sqlscale =-7;
 xsqlda->sqlvar[0].sqllen   =4;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__bug_check__other_sqlscale_of_xvar
    (tracer,
     exc.get_record(0),
     L"sql_long",
     -7,
     -5);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_s02___bug_check__not_stable_sqlscale__long

////////////////////////////////////////////////////////////////////////////////
//TEST S03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_s03___bug_check__not_stable_sqlscale__int64
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_int64;
 descrs[0].m_xvar_sqlscale          =-15;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =8;
 descrs[0].m_msg_sqlind_offset      =8;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(10);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_int64;
 xsqlda->sqlvar[0].sqlscale =-17;
 xsqlda->sqlvar[0].sqllen   =8;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__bug_check__other_sqlscale_of_xvar
    (tracer,
     exc.get_record(0),
     L"sql_int64",
     -17,
     -15);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_s03___bug_check__not_stable_sqlscale__int64

////////////////////////////////////////////////////////////////////////////////
//TEST L01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_L01___bug_check__not_stable_sqllen__text
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_text;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =2;
 descrs[0].m_msg_sqlind_offset      =2;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(4);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_text;
 xsqlda->sqlvar[0].sqllen   =1;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__bug_check__other_sqllen_of_xvar
    (tracer,
     exc.get_record(0),
     L"sql_text",
     1,
     2);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_L01___bug_check__not_stable_sqllen__text

////////////////////////////////////////////////////////////////////////////////
//TEST L02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_L02___bug_check__not_stable_sqllen__varying
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_varying;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =4;
 descrs[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(6);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_varying;
 xsqlda->sqlvar[0].sqllen   =1;

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__bug_check__other_sqllen_of_xvar
    (tracer,
     exc.get_record(0),
     L"sql_varying",
     1,
     2);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_L02___bug_check__not_stable_sqllen__varying

////////////////////////////////////////////////////////////////////////////////
//TEST V01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_V01___err__varchar__negative_length_of_value
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_varying;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =4;   //sqllen==2
 descrs[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 assert_s(sizeof(isc_api::isc_varchar_size_type)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(6);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<isc_api::isc_varchar_size_type*>(buf.buffer())=-1;

 //-----------------------------------------
 typedef structure::t_typed_simple_buffer<char,TTSO_MemoryAllocator> xval_buf_type;

 xval_buf_type xvalue(4);

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_varying;
 xsqlda->sqlvar[0].sqllen   =2;
 xsqlda->sqlvar[0].sqldata  =xvalue.buffer();

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__incorrect_varchar_data_length
    (tracer,
     exc.get_record(0),
     -1);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_V01___err__varchar__negative_length_of_value

////////////////////////////////////////////////////////////////////////////////
//TEST V02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_V02___err__varchar__too_large_value
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_varying;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =4;   //sqllen==2
 descrs[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 assert_s(sizeof(isc_api::isc_varchar_size_type)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(6);

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<isc_api::isc_varchar_size_type*>(buf.buffer())=3;

 //-----------------------------------------
 typedef structure::t_typed_simple_buffer<char,TTSO_MemoryAllocator> xval_buf_type;

 xval_buf_type xvalue(4);

 XSQLDA_V1_Wrapper xsqlda(1);

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype  =isc_api::ibp_isc_sql_varying;
 xsqlda->sqlvar[0].sqllen   =2;
 xsqlda->sqlvar[0].sqldata  =xvalue.buffer();

 for(;;)
 {
  try
  {
   self_type::Helper__Parse_XSQLDA_MSG_DATA
    (descrs,
     /*cbMsgData*/buf.size(),
     /*pMsgData*/buf.buffer(),
     xsqlda); //throw!
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,2);

   _TSO_CHECK(exc.get_record(0));
   _TSO_CHECK(exc.get_record(1));

   errSvc::check_err_rec__xsqlda_err__varchar_data_length_is_greater_than_buffer_size
    (tracer,
     exc.get_record(0),
     3,
     2);

   errSvc::check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
    (tracer,
     exc.get_record(1),
     errSvc::sm_subsysID__isc_api__fb3_0,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_V02___err__varchar__too_large_value

////////////////////////////////////////////////////////////////////////////////
//TEST D01-01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D01__short_01
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__i2 xvalue_type;

 const xvalue_type c_test_value =4321;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_short;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==2);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_short;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
}//test_D01__short_01

////////////////////////////////////////////////////////////////////////////////
//TEST D01-02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D01__short_02
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__i2 xvalue_type;

 const xvalue_type    c_test_value =4321;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_short;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==2);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_short;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==c_init_sqlind);
}//test_D01__short_02

////////////////////////////////////////////////////////////////////////////////
//TEST D01-03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D01__short_03
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__i2 xvalue_type;

 const xvalue_type    c_test_value =4321;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_short;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==2);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_short|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==0);
}//test_D01__short_03

////////////////////////////////////////////////////////////////////////////////
//TEST D01-03-2

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D01__short_03_2
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 const short c_sql_type=isc_api::ibp_isc_sql_short;

 typedef db_obj::t_dbvalue__i2 xvalue_type;

 const xvalue_type    c_test_value1 =4321;
 const xvalue_type    c_test_value2 =12345;

 const short          c_test_sqlind=0;

 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(2);

 size_t offset=0;

 descrs[0].m_xvar_sqltype           =c_sql_type;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =offset;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);
 offset+=0;//align

 descrs[1].m_xvar_sqltype           =c_sql_type;
 descrs[1].m_xvar_sqlscale          =0;
 descrs[1].m_msg_value_block_offset =offset;
 descrs[1].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[1].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==2);

 //-----------------------------------------
 std::vector<unsigned char> buf;

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value1),
           reinterpret_cast<const unsigned char*>(&c_test_value1)+sizeof(c_test_value1),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //---- align
 //----

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value2),
           reinterpret_cast<const unsigned char*>(&c_test_value2)+sizeof(c_test_value2),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xvalue_type xvalue1=1234;
 short       xsqlind1=c_init_sqlind;

 xvalue_type xvalue2=-2342;
 short       xsqlind2=c_init_sqlind;

 xsqlda->sqld=2;

 assert_s(sizeof(xvalue1)==2);

 xsqlda->sqlvar[0].sqltype=c_sql_type|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue1);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue1);
 xsqlda->sqlvar[0].sqlind =&xsqlind1;

 xsqlda->sqlvar[1].sqltype=c_sql_type|1;
 xsqlda->sqlvar[1].sqllen =sizeof(xvalue2);
 xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xvalue2);
 xsqlda->sqlvar[1].sqlind =&xsqlind2;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.data(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue1 ==c_test_value1);
 _TSO_CHECK(xsqlind1==0);

 _TSO_CHECK(xvalue2 ==c_test_value2);
 _TSO_CHECK(xsqlind2==0);
}//test_D01__short_03_2

////////////////////////////////////////////////////////////////////////////////
//TEST D01-04

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D01__short_04__null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__i2 xvalue_type;

 const xvalue_type    c_test_value =4321;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_short;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())               =c_test_value;
 *reinterpret_cast<short*>(buf.buffer()+sizeof(xvalue_type)) =-1;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==2);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_short|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==0);
 _TSO_CHECK(xsqlind==-1);
}//test_D01__short_04__null

////////////////////////////////////////////////////////////////////////////////
//TEST D02-01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D02__long_01
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__i4 xvalue_type;

 const xvalue_type c_test_value =432104321;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
}//test_D02__long_01

////////////////////////////////////////////////////////////////////////////////
//TEST D02-02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D02__long_02
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__i4 xvalue_type;

 const xvalue_type    c_test_value =432109876;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==c_init_sqlind);
}//test_D01__short_02

////////////////////////////////////////////////////////////////////////////////
//TEST D02-03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D02__long_03
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__i4 xvalue_type;

 const xvalue_type    c_test_value =43211234;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==0);
}//test_D02__long_03

////////////////////////////////////////////////////////////////////////////////
//TEST D01-03-2

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D02__long_03_2
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 const short c_sql_type=isc_api::ibp_isc_sql_long;

 typedef db_obj::t_dbvalue__i4 xvalue_type;

 const xvalue_type    c_test_value1 =544321;
 const xvalue_type    c_test_value2 =1234533;

 const short          c_test_sqlind=0;

 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(2);

 size_t offset=0;

 descrs[0].m_xvar_sqltype           =c_sql_type;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =offset;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);
 offset+=2;//align

 descrs[1].m_xvar_sqltype           =c_sql_type;
 descrs[1].m_xvar_sqlscale          =0;
 descrs[1].m_msg_value_block_offset =offset;
 descrs[1].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[1].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 std::vector<unsigned char> buf;

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value1),
           reinterpret_cast<const unsigned char*>(&c_test_value1)+sizeof(c_test_value1),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //---- align
 buf.push_back(0);
 buf.push_back(0);

 //----
 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value2),
           reinterpret_cast<const unsigned char*>(&c_test_value2)+sizeof(c_test_value2),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xvalue_type xvalue1=1234;
 short       xsqlind1=c_init_sqlind;

 xvalue_type xvalue2=-2342;
 short       xsqlind2=c_init_sqlind;

 xsqlda->sqld=2;

 assert_s(sizeof(xvalue1)==4);

 xsqlda->sqlvar[0].sqltype=c_sql_type|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue1);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue1);
 xsqlda->sqlvar[0].sqlind =&xsqlind1;

 xsqlda->sqlvar[1].sqltype=c_sql_type|1;
 xsqlda->sqlvar[1].sqllen =sizeof(xvalue2);
 xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xvalue2);
 xsqlda->sqlvar[1].sqlind =&xsqlind2;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.data(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue1 ==c_test_value1);
 _TSO_CHECK(xsqlind1==0);

 _TSO_CHECK(xvalue2 ==c_test_value2);
 _TSO_CHECK(xsqlind2==0);
}//test_D02__long_03_2

////////////////////////////////////////////////////////////////////////////////
//TEST D02-04

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D02__long_04__null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__i4 xvalue_type;

 const xvalue_type    c_test_value =432176543;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_long;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())                =c_test_value;
 *reinterpret_cast<short*>(buf.buffer()+sizeof(xvalue_type))  =-1;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_long|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==0);
 _TSO_CHECK(xsqlind==-1);
}//test_D02__long_04__null

////////////////////////////////////////////////////////////////////////////////
//TEST D03-01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D03__int64_01
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__i8 xvalue_type;

 const xvalue_type c_test_value =43210432101234567i64;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_int64;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_int64;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
}//test_D03__int64_01

////////////////////////////////////////////////////////////////////////////////
//TEST D03-02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D03__int64_02
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__i8 xvalue_type;

 const xvalue_type    c_test_value =43210432101234567i64;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_int64;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_int64;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==c_init_sqlind);
}//test_D03__int64_02

////////////////////////////////////////////////////////////////////////////////
//TEST D03-03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D03__int64_03
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__i8 xvalue_type;

 const xvalue_type    c_test_value =43210432101234567i64;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_int64;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==0);
}//test_D03__int64_03

////////////////////////////////////////////////////////////////////////////////
//TEST D03-03-2

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D03__int64_03_2
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 const short c_sql_type=isc_api::ibp_isc_sql_int64;

 typedef db_obj::t_dbvalue__i8 xvalue_type;

 const xvalue_type    c_test_value1 =987654321032158i64;
 const xvalue_type    c_test_value2 =-1234533i64;

 const short          c_test_sqlind=0;

 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(2);

 size_t offset=0;

 descrs[0].m_xvar_sqltype           =c_sql_type;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =offset;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);
 offset+=6;//align

 descrs[1].m_xvar_sqltype           =c_sql_type;
 descrs[1].m_xvar_sqlscale          =0;
 descrs[1].m_msg_value_block_offset =offset;
 descrs[1].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[1].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 std::vector<unsigned char> buf;

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value1),
           reinterpret_cast<const unsigned char*>(&c_test_value1)+sizeof(c_test_value1),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //---- align
 buf.push_back(0);
 buf.push_back(0);
 buf.push_back(0);
 buf.push_back(0);
 buf.push_back(0);
 buf.push_back(0);

 //----
 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value2),
           reinterpret_cast<const unsigned char*>(&c_test_value2)+sizeof(c_test_value2),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xvalue_type xvalue1=1234;
 short       xsqlind1=c_init_sqlind;

 xvalue_type xvalue2=-2342;
 short       xsqlind2=c_init_sqlind;

 xsqlda->sqld=2;

 assert_s(sizeof(xvalue1)==8);

 xsqlda->sqlvar[0].sqltype=c_sql_type|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue1);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue1);
 xsqlda->sqlvar[0].sqlind =&xsqlind1;

 xsqlda->sqlvar[1].sqltype=c_sql_type|1;
 xsqlda->sqlvar[1].sqllen =sizeof(xvalue2);
 xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xvalue2);
 xsqlda->sqlvar[1].sqlind =&xsqlind2;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.data(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue1 ==c_test_value1);
 _TSO_CHECK(xsqlind1==0);

 _TSO_CHECK(xvalue2 ==c_test_value2);
 _TSO_CHECK(xsqlind2==0);
}//test_D03__int64_03_2

////////////////////////////////////////////////////////////////////////////////
//TEST D03-04

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D03__int64_04__null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__i8 xvalue_type;

 const xvalue_type    c_test_value =43210432101234567i64;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_int64;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())                =c_test_value;
 *reinterpret_cast<short*>(buf.buffer()+sizeof(xvalue_type))  =-1;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_int64|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==0);
 _TSO_CHECK(xsqlind==-1);
}//test_D03__int64_04__null

////////////////////////////////////////////////////////////////////////////////
//TEST D04-01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D04__float_01
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__r4 xvalue_type;

 const xvalue_type c_test_value =4321;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_float;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_float;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
}//test_D04__float_01

////////////////////////////////////////////////////////////////////////////////
//TEST D04-02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D04__float_02
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__r4 xvalue_type;

 const xvalue_type    c_test_value =0.5F;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_float;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_float;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==c_init_sqlind);
}//test_D04__float_02

////////////////////////////////////////////////////////////////////////////////
//TEST D04-03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D04__float_03
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__r4 xvalue_type;

 const xvalue_type    c_test_value =1.5F;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_float;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_float|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==0);
}//test_D04__float_03

////////////////////////////////////////////////////////////////////////////////
//TEST D04-03-2

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D04__float_03_2
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 const short c_sql_type=isc_api::ibp_isc_sql_float;

 typedef db_obj::t_dbvalue__r4 xvalue_type;

 const xvalue_type    c_test_value1 =12321;
 const xvalue_type    c_test_value2 =-32134;

 const short          c_test_sqlind=0;

 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(2);

 size_t offset=0;

 descrs[0].m_xvar_sqltype           =c_sql_type;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =offset;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);
 offset+=2;//align

 descrs[1].m_xvar_sqltype           =c_sql_type;
 descrs[1].m_xvar_sqlscale          =0;
 descrs[1].m_msg_value_block_offset =offset;
 descrs[1].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[1].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 std::vector<unsigned char> buf;

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value1),
           reinterpret_cast<const unsigned char*>(&c_test_value1)+sizeof(c_test_value1),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //---- align
 buf.push_back(0);
 buf.push_back(0);

 //----
 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value2),
           reinterpret_cast<const unsigned char*>(&c_test_value2)+sizeof(c_test_value2),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xvalue_type xvalue1=1234;
 short       xsqlind1=c_init_sqlind;

 xvalue_type xvalue2=-2342;
 short       xsqlind2=c_init_sqlind;

 xsqlda->sqld=2;

 assert_s(sizeof(xvalue1)==4);

 xsqlda->sqlvar[0].sqltype=c_sql_type|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue1);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue1);
 xsqlda->sqlvar[0].sqlind =&xsqlind1;

 xsqlda->sqlvar[1].sqltype=c_sql_type|1;
 xsqlda->sqlvar[1].sqllen =sizeof(xvalue2);
 xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xvalue2);
 xsqlda->sqlvar[1].sqlind =&xsqlind2;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.data(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue1 ==c_test_value1);
 _TSO_CHECK(xsqlind1==0);

 _TSO_CHECK(xvalue2 ==c_test_value2);
 _TSO_CHECK(xsqlind2==0);
}//test_D04__float_03_2

////////////////////////////////////////////////////////////////////////////////
//TEST D04-04

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D04__float_04__null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__r4 xvalue_type;

 const xvalue_type    c_test_value =12345;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_float;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())                =c_test_value;
 *reinterpret_cast<short*>(buf.buffer()+sizeof(xvalue_type))  =-1;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_float|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==0);
 _TSO_CHECK(xsqlind==-1);
}//test_D04__float_04__null

////////////////////////////////////////////////////////////////////////////////
//TEST D05-01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D05__double_01
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__r8 xvalue_type;

 const xvalue_type c_test_value =4321;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_double;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_double;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
}//test_D05__double_01

////////////////////////////////////////////////////////////////////////////////
//TEST D05-02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D05__double_02
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__r8 xvalue_type;

 const xvalue_type    c_test_value =0.5F;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_double;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_double;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==c_init_sqlind);
}//test_D05__double_02

////////////////////////////////////////////////////////////////////////////////
//TEST D05-03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D05__double_03
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__r8 xvalue_type;

 const xvalue_type    c_test_value =1.5F;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_double;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_double|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==0);
}//test_D05__double_03

////////////////////////////////////////////////////////////////////////////////
//TEST D05-03-2

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D05__double_03_2
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 const short c_sql_type=isc_api::ibp_isc_sql_double;

 typedef db_obj::t_dbvalue__r8 xvalue_type;

 const xvalue_type    c_test_value1 =12321444;
 const xvalue_type    c_test_value2 =-32134343;

 const short          c_test_sqlind=0;

 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(2);

 size_t offset=0;

 descrs[0].m_xvar_sqltype           =c_sql_type;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =offset;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);
 offset+=6;//align

 descrs[1].m_xvar_sqltype           =c_sql_type;
 descrs[1].m_xvar_sqlscale          =0;
 descrs[1].m_msg_value_block_offset =offset;
 descrs[1].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[1].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 std::vector<unsigned char> buf;

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value1),
           reinterpret_cast<const unsigned char*>(&c_test_value1)+sizeof(c_test_value1),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //---- align
 buf.push_back(0);
 buf.push_back(0);
 buf.push_back(0);
 buf.push_back(0);
 buf.push_back(0);
 buf.push_back(0);

 //----
 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value2),
           reinterpret_cast<const unsigned char*>(&c_test_value2)+sizeof(c_test_value2),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xvalue_type xvalue1=1234;
 short       xsqlind1=c_init_sqlind;

 xvalue_type xvalue2=-2342;
 short       xsqlind2=c_init_sqlind;

 xsqlda->sqld=2;

 assert_s(sizeof(xvalue1)==8);

 xsqlda->sqlvar[0].sqltype=c_sql_type|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue1);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue1);
 xsqlda->sqlvar[0].sqlind =&xsqlind1;

 xsqlda->sqlvar[1].sqltype=c_sql_type|1;
 xsqlda->sqlvar[1].sqllen =sizeof(xvalue2);
 xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xvalue2);
 xsqlda->sqlvar[1].sqlind =&xsqlind2;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.data(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue1 ==c_test_value1);
 _TSO_CHECK(xsqlind1==0);

 _TSO_CHECK(xvalue2 ==c_test_value2);
 _TSO_CHECK(xsqlind2==0);
}//test_D05__double_03_2

////////////////////////////////////////////////////////////////////////////////
//TEST D05-04

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D05__double_04__null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::t_dbvalue__r8 xvalue_type;

 const xvalue_type    c_test_value =12345;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_double;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())                =c_test_value;
 *reinterpret_cast<short*>(buf.buffer()+sizeof(xvalue_type))  =-1;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_double|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==0);
 _TSO_CHECK(xsqlind==-1);
}//test_D05__double_04__null

////////////////////////////////////////////////////////////////////////////////
//TEST D06-01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D06__time_01
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_isc_time xvalue_type;

 const xvalue_type c_test_value =1234567;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_type_time;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_type_time;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
}//test_D06__time_01

////////////////////////////////////////////////////////////////////////////////
//TEST D06-02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D06__time_02
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_isc_time xvalue_type;

 const xvalue_type    c_test_value =1234565;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_type_time;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_type_time;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==c_init_sqlind);
}//test_D06__time_02

////////////////////////////////////////////////////////////////////////////////
//TEST D06-03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D06__time_03
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_isc_time xvalue_type;

 const xvalue_type    c_test_value =1234569;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_type_time;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_type_time|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==0);
}//test_D06__time_03

////////////////////////////////////////////////////////////////////////////////
//TEST D06-03-2

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D06__time_03_2
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 const short c_sql_type=isc_api::ibp_isc_sql_type_time;

 typedef isc_api::t_ibp_isc_time xvalue_type;

 const xvalue_type    c_test_value1 =123456;
 const xvalue_type    c_test_value2 =987654;

 const short          c_test_sqlind=0;

 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(2);

 size_t offset=0;

 descrs[0].m_xvar_sqltype           =c_sql_type;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =offset;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);
 offset+=2;//align

 descrs[1].m_xvar_sqltype           =c_sql_type;
 descrs[1].m_xvar_sqlscale          =0;
 descrs[1].m_msg_value_block_offset =offset;
 descrs[1].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[1].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 std::vector<unsigned char> buf;

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value1),
           reinterpret_cast<const unsigned char*>(&c_test_value1)+sizeof(c_test_value1),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //---- align
 buf.push_back(0);
 buf.push_back(0);

 //----
 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value2),
           reinterpret_cast<const unsigned char*>(&c_test_value2)+sizeof(c_test_value2),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xvalue_type xvalue1=1234;
 short       xsqlind1=c_init_sqlind;

 xvalue_type xvalue2=-2342;
 short       xsqlind2=c_init_sqlind;

 xsqlda->sqld=2;

 assert_s(sizeof(xvalue1)==4);

 xsqlda->sqlvar[0].sqltype=c_sql_type|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue1);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue1);
 xsqlda->sqlvar[0].sqlind =&xsqlind1;

 xsqlda->sqlvar[1].sqltype=c_sql_type|1;
 xsqlda->sqlvar[1].sqllen =sizeof(xvalue2);
 xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xvalue2);
 xsqlda->sqlvar[1].sqlind =&xsqlind2;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.data(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue1 ==c_test_value1);
 _TSO_CHECK(xsqlind1==0);

 _TSO_CHECK(xvalue2 ==c_test_value2);
 _TSO_CHECK(xsqlind2==0);
}//test_D06__time_03_2

////////////////////////////////////////////////////////////////////////////////
//TEST D06-04

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D06__time_04__null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_isc_time xvalue_type;

 const xvalue_type    c_test_value =1234563;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_type_time;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())                =c_test_value;
 *reinterpret_cast<short*>(buf.buffer()+sizeof(xvalue_type))  =-1;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_type_time|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==0);
 _TSO_CHECK(xsqlind==-1);
}//test_D06__time_04__null

////////////////////////////////////////////////////////////////////////////////
//TEST D07-01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D07__date_01
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_isc_date xvalue_type;

 const xvalue_type c_test_value =1;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_type_date;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_type_date;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
}//test_D07__date_01

////////////////////////////////////////////////////////////////////////////////
//TEST D07-02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D07__date_02
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_isc_date xvalue_type;

 const xvalue_type    c_test_value =123456;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_type_date;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_type_date;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==c_init_sqlind);
}//test_D07__date_02

////////////////////////////////////////////////////////////////////////////////
//TEST D07-03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D07__date_03
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_isc_date xvalue_type;

 const xvalue_type    c_test_value =123457;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_type_date;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_type_date|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==0);
}//test_D07__date_03

////////////////////////////////////////////////////////////////////////////////
//TEST D07-03-2

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D07__date_03_2
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 const short c_sql_type=isc_api::ibp_isc_sql_type_date;

 typedef isc_api::t_ibp_isc_date xvalue_type;

 const xvalue_type    c_test_value1 =123456;
 const xvalue_type    c_test_value2 =987654;

 const short          c_test_sqlind=0;

 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(2);

 size_t offset=0;

 descrs[0].m_xvar_sqltype           =c_sql_type;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =offset;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);
 offset+=2;//align

 descrs[1].m_xvar_sqltype           =c_sql_type;
 descrs[1].m_xvar_sqlscale          =0;
 descrs[1].m_msg_value_block_offset =offset;
 descrs[1].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[1].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 std::vector<unsigned char> buf;

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value1),
           reinterpret_cast<const unsigned char*>(&c_test_value1)+sizeof(c_test_value1),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //---- align
 buf.push_back(0);
 buf.push_back(0);

 //----
 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value2),
           reinterpret_cast<const unsigned char*>(&c_test_value2)+sizeof(c_test_value2),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xvalue_type xvalue1=1234;
 short       xsqlind1=c_init_sqlind;

 xvalue_type xvalue2=-2342;
 short       xsqlind2=c_init_sqlind;

 xsqlda->sqld=2;

 assert_s(sizeof(xvalue1)==4);

 xsqlda->sqlvar[0].sqltype=c_sql_type|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue1);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue1);
 xsqlda->sqlvar[0].sqlind =&xsqlind1;

 xsqlda->sqlvar[1].sqltype=c_sql_type|1;
 xsqlda->sqlvar[1].sqllen =sizeof(xvalue2);
 xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xvalue2);
 xsqlda->sqlvar[1].sqlind =&xsqlind2;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.data(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue1 ==c_test_value1);
 _TSO_CHECK(xsqlind1==0);

 _TSO_CHECK(xvalue2 ==c_test_value2);
 _TSO_CHECK(xsqlind2==0);
}//test_D07__date_03_2

////////////////////////////////////////////////////////////////////////////////
//TEST D07-04

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D07__date_04__null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_isc_date xvalue_type;

 const xvalue_type    c_test_value =654321;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_type_date;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==4);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())                =c_test_value;
 *reinterpret_cast<short*>(buf.buffer()+sizeof(xvalue_type))  =-1;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=1234;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==4);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_type_date|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==0);
 _TSO_CHECK(xsqlind==-1);
}//test_D07__date_04__null

////////////////////////////////////////////////////////////////////////////////
//TEST D08-01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D08__timestamp_01
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_isc_timestamp xvalue_type;

 const xvalue_type c_test_value ={1,1234567};

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_timestamp;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue={1234,23232};

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_timestamp;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
}//test_D08__timestamp_01

////////////////////////////////////////////////////////////////////////////////
//TEST D08-02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D08__timestamp_02
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_isc_timestamp xvalue_type;

 const xvalue_type    c_test_value ={123456,1234567};
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_timestamp;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue={1234,23232};
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_timestamp;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==c_init_sqlind);
}//test_D08__timestamp_02

////////////////////////////////////////////////////////////////////////////////
//TEST D08-03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D08__timestamp_03
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_isc_timestamp xvalue_type;

 const xvalue_type    c_test_value ={123456,1234567};
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_timestamp;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue={1234,23232};
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_timestamp|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==0);
}//test_D08__timestamp_03

////////////////////////////////////////////////////////////////////////////////
//TEST D07-03-2

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D08__timestamp_03_2
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 const short c_sql_type=isc_api::ibp_isc_sql_timestamp;

 typedef isc_api::t_ibp_isc_timestamp xvalue_type;

 const xvalue_type    c_test_value1 ={123456,321238};
 const xvalue_type    c_test_value2 ={987654,2134234};

 const short          c_test_sqlind=0;

 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(2);

 size_t offset=0;

 descrs[0].m_xvar_sqltype           =c_sql_type;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =offset;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);
 offset+=2;//align

 descrs[1].m_xvar_sqltype           =c_sql_type;
 descrs[1].m_xvar_sqlscale          =0;
 descrs[1].m_msg_value_block_offset =offset;
 descrs[1].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[1].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 std::vector<unsigned char> buf;

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value1),
           reinterpret_cast<const unsigned char*>(&c_test_value1)+sizeof(c_test_value1),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //---- align
 buf.push_back(0);
 buf.push_back(0);

 //----
 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value2),
           reinterpret_cast<const unsigned char*>(&c_test_value2)+sizeof(c_test_value2),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xvalue_type xvalue1={1234,22};
 short       xsqlind1=c_init_sqlind;

 xvalue_type xvalue2={2342,332};
 short       xsqlind2=c_init_sqlind;

 xsqlda->sqld=2;

 assert_s(sizeof(xvalue1)==8);

 xsqlda->sqlvar[0].sqltype=c_sql_type|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue1);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue1);
 xsqlda->sqlvar[0].sqlind =&xsqlind1;

 xsqlda->sqlvar[1].sqltype=c_sql_type|1;
 xsqlda->sqlvar[1].sqllen =sizeof(xvalue2);
 xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xvalue2);
 xsqlda->sqlvar[1].sqlind =&xsqlind2;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.data(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue1 ==c_test_value1);
 _TSO_CHECK(xsqlind1==0);

 _TSO_CHECK(xvalue2 ==c_test_value2);
 _TSO_CHECK(xsqlind2==0);
}//test_D08__timestamp_03_2

////////////////////////////////////////////////////////////////////////////////
//TEST D08-04

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D08__timestamp_04__null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_isc_timestamp xvalue_type;

 const xvalue_type    c_test_value ={654321,1234567};
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_timestamp;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())                =c_test_value;
 *reinterpret_cast<short*>(buf.buffer()+sizeof(xvalue_type))  =-1;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue={1234,23232};
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_timestamp|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==isc_api::__null__isc_timestamp);
 _TSO_CHECK(xsqlind==-1);
}//test_D08__timestamp_04__null

////////////////////////////////////////////////////////////////////////////////
//TEST D09-01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D09__blob_01
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::DB_IBBLOBID xvalue_type;

 const xvalue_type c_test_value ={1,1234567};

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_blob;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue={1234,23232};

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_blob;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
}//test_D09__blob_01

////////////////////////////////////////////////////////////////////////////////
//TEST D09-02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D09__blob_02
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::DB_IBBLOBID xvalue_type;

 const xvalue_type    c_test_value ={123456,1234567};
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_blob;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue={1234,23232};
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_blob;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==c_init_sqlind);
}//test_D09__blob_02

////////////////////////////////////////////////////////////////////////////////
//TEST D09-03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D09__blob_03
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::DB_IBBLOBID xvalue_type;

 const xvalue_type    c_test_value ={123456,1234567};
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_blob;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue={1234,23232};
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_blob|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==0);
}//test_D09__blob_03

////////////////////////////////////////////////////////////////////////////////
//TEST D09-03-2

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D09__blob_03_2
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 const short c_sql_type=isc_api::ibp_isc_sql_blob;

 typedef db_obj::DB_IBBLOBID xvalue_type;

 const xvalue_type    c_test_value1 ={123456,321238};
 const xvalue_type    c_test_value2 ={987654,2134234};

 const short          c_test_sqlind=0;

 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(2);

 size_t offset=0;

 descrs[0].m_xvar_sqltype           =c_sql_type;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =offset;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);
 offset+=2;//align

 descrs[1].m_xvar_sqltype           =c_sql_type;
 descrs[1].m_xvar_sqlscale          =0;
 descrs[1].m_msg_value_block_offset =offset;
 descrs[1].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[1].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 std::vector<unsigned char> buf;

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value1),
           reinterpret_cast<const unsigned char*>(&c_test_value1)+sizeof(c_test_value1),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //---- align
 buf.push_back(0);
 buf.push_back(0);

 //----
 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value2),
           reinterpret_cast<const unsigned char*>(&c_test_value2)+sizeof(c_test_value2),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xvalue_type xvalue1={1234,22};
 short       xsqlind1=c_init_sqlind;

 xvalue_type xvalue2={2342,332};
 short       xsqlind2=c_init_sqlind;

 xsqlda->sqld=2;

 assert_s(sizeof(xvalue1)==8);

 xsqlda->sqlvar[0].sqltype=c_sql_type|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue1);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue1);
 xsqlda->sqlvar[0].sqlind =&xsqlind1;

 xsqlda->sqlvar[1].sqltype=c_sql_type|1;
 xsqlda->sqlvar[1].sqllen =sizeof(xvalue2);
 xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xvalue2);
 xsqlda->sqlvar[1].sqlind =&xsqlind2;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.data(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue1 ==c_test_value1);
 _TSO_CHECK(xsqlind1==0);

 _TSO_CHECK(xvalue2 ==c_test_value2);
 _TSO_CHECK(xsqlind2==0);
}//test_D09__blob_03_2

////////////////////////////////////////////////////////////////////////////////
//TEST D09-04

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D09__blob_04__null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::DB_IBBLOBID xvalue_type;

 const xvalue_type    c_test_value ={654321,1234567};
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_blob;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())                =c_test_value;
 *reinterpret_cast<short*>(buf.buffer()+sizeof(xvalue_type))  =-1;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue={1234,23232};
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_blob|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==db_obj::__null_ib_blob_id);
 _TSO_CHECK(xsqlind==-1);
}//test_D09__blob_04__null

////////////////////////////////////////////////////////////////////////////////
//TEST D10-01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D10__array_01
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::DB_IBARRAYID xvalue_type;

 const xvalue_type c_test_value ={1,1234567};

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_array;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue={1234,23232};

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_array;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
}//test_D10__array_01

////////////////////////////////////////////////////////////////////////////////
//TEST D10-02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D10__array_02
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::DB_IBARRAYID xvalue_type;

 const xvalue_type    c_test_value ={123456,1234567};
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_array;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue={1234,23232};
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_array;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==c_init_sqlind);
}//test_D10__array_02

////////////////////////////////////////////////////////////////////////////////
//TEST D10-03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D10__array_03
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::DB_IBARRAYID xvalue_type;

 const xvalue_type    c_test_value ={123456,1234567};
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_array;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue={1234,23232};
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_array|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==0);
}//test_D10__array_03

////////////////////////////////////////////////////////////////////////////////
//TEST D10-03-2

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D10__array_03_2
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 const short c_sql_type=isc_api::ibp_isc_sql_array;

 typedef db_obj::DB_IBARRAYID xvalue_type;

 const xvalue_type    c_test_value1 ={123456,321238};
 const xvalue_type    c_test_value2 ={987654,2134234};

 const short          c_test_sqlind=0;

 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(2);

 size_t offset=0;

 descrs[0].m_xvar_sqltype           =c_sql_type;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =offset;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);
 offset+=2;//align

 descrs[1].m_xvar_sqltype           =c_sql_type;
 descrs[1].m_xvar_sqlscale          =0;
 descrs[1].m_msg_value_block_offset =offset;
 descrs[1].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[1].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type));

 offset+=sizeof(c_test_sqlind);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 std::vector<unsigned char> buf;

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value1),
           reinterpret_cast<const unsigned char*>(&c_test_value1)+sizeof(c_test_value1),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //---- align
 buf.push_back(0);
 buf.push_back(0);

 //----
 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value2),
           reinterpret_cast<const unsigned char*>(&c_test_value2)+sizeof(c_test_value2),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xvalue_type xvalue1={1234,22};
 short       xsqlind1=c_init_sqlind;

 xvalue_type xvalue2={2342,332};
 short       xsqlind2=c_init_sqlind;

 xsqlda->sqld=2;

 assert_s(sizeof(xvalue1)==8);

 xsqlda->sqlvar[0].sqltype=c_sql_type|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue1);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue1);
 xsqlda->sqlvar[0].sqlind =&xsqlind1;

 xsqlda->sqlvar[1].sqltype=c_sql_type|1;
 xsqlda->sqlvar[1].sqllen =sizeof(xvalue2);
 xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xvalue2);
 xsqlda->sqlvar[1].sqlind =&xsqlind2;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.data(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue1 ==c_test_value1);
 _TSO_CHECK(xsqlind1==0);

 _TSO_CHECK(xvalue2 ==c_test_value2);
 _TSO_CHECK(xsqlind2==0);
}//test_D10__array_03_2

////////////////////////////////////////////////////////////////////////////////
//TEST D10-04

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D10__array_04__null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef db_obj::DB_IBARRAYID xvalue_type;

 const xvalue_type    c_test_value ={654321,1234567};
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_array;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =sizeof(xvalue_type);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==8);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())                =c_test_value;
 *reinterpret_cast<short*>(buf.buffer()+sizeof(xvalue_type))  =-1;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue={1234,23232};
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==8);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_array|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==db_obj::__null_ib_array_id);
 _TSO_CHECK(xsqlind==-1);
}//test_D10__array_04__null

////////////////////////////////////////////////////////////////////////////////
//TEST D11-01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D11__text_01
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_text;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =3; //char(3)
 descrs[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(descrs[0].m_msg_sqlind_offset+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 reinterpret_cast<char*>(buf.buffer())[0]='1';
 reinterpret_cast<char*>(buf.buffer())[1]='2';
 reinterpret_cast<char*>(buf.buffer())[2]=' ';

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 char xvalue[3+/*guard*/2];

 memset(xvalue,0xFE,sizeof(xvalue));

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_text;
 xsqlda->sqlvar[0].sqllen =3;
 xsqlda->sqlvar[0].sqldata=xvalue;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue[0]=='1');
 _TSO_CHECK(xvalue[1]=='2');
 _TSO_CHECK(xvalue[2]==' ');
 _TSO_CHECK(xvalue[3]==(char)0xFE);
 _TSO_CHECK(xvalue[4]==(char)0xFE);
}//test_D11__text_01

////////////////////////////////////////////////////////////////////////////////
//TEST D11-02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D11__text_02
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const short c_init_sqlind=5487;

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_text;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =3; //char(3)
 descrs[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(descrs[0].m_msg_sqlind_offset+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 reinterpret_cast<char*>(buf.buffer())[0]='1';
 reinterpret_cast<char*>(buf.buffer())[1]='2';
 reinterpret_cast<char*>(buf.buffer())[2]=' ';

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 char xvalue[3+/*guard*/2];

 memset(xvalue,0xFE,sizeof(xvalue));

 short xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_text;
 xsqlda->sqlvar[0].sqllen =3;
 xsqlda->sqlvar[0].sqldata=xvalue;
 xsqlda->sqlvar[0].sqlind =&xsqlind; //not changed

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xsqlind==c_init_sqlind);

 _TSO_CHECK(xvalue[0]=='1');
 _TSO_CHECK(xvalue[1]=='2');
 _TSO_CHECK(xvalue[2]==' ');
 _TSO_CHECK(xvalue[3]==(char)0xFE);
 _TSO_CHECK(xvalue[4]==(char)0xFE);
}//test_D11__text_02

////////////////////////////////////////////////////////////////////////////////
//TEST D11-03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D11__text_03
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_text;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =3; //char(3)
 descrs[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(descrs[0].m_msg_sqlind_offset+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 reinterpret_cast<char*>(buf.buffer())[0]='1';
 reinterpret_cast<char*>(buf.buffer())[1]='2';
 reinterpret_cast<char*>(buf.buffer())[2]=' ';

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 char xvalue[3+/*guard*/2];

 memset(xvalue,0xFE,sizeof(xvalue));

 short xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[0].sqllen =3;
 xsqlda->sqlvar[0].sqldata=xvalue;
 xsqlda->sqlvar[0].sqlind =&xsqlind; //not changed

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xsqlind==0);

 _TSO_CHECK(xvalue[0]=='1');
 _TSO_CHECK(xvalue[1]=='2');
 _TSO_CHECK(xvalue[2]==' ');
 _TSO_CHECK(xvalue[3]==(char)0xFE);
 _TSO_CHECK(xvalue[4]==(char)0xFE);
}//test_D11__text_03

////////////////////////////////////////////////////////////////////////////////
//TEST D11-03-2

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D11__text_03_2
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 const short c_sql_type=isc_api::ibp_isc_sql_text;

 struct xvalue1_type
 {
  char data[3];

  bool operator == (const xvalue1_type& x)const
  {
   return structure::equal(this->data,
                           _END_(this->data),
                           x.data,
                           _END_(x.data));
  }//operator ==
 };//struct xvalue1_type

 struct xvalue2_type
 {
  char data[5];

  bool operator == (const xvalue2_type& x)const
  {
   return structure::equal(this->data,
                           _END_(this->data),
                           x.data,
                           _END_(x.data));
  }//operator ==
 };//struct xvalue2_type

 const xvalue1_type    c_test_value1 ={3,2,1};
 const xvalue2_type    c_test_value2 ={1,2,3,4,5};

 const short          c_test_sqlind=0;

 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(2);

 size_t offset=0;

 descrs[0].m_xvar_sqltype           =c_sql_type;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =offset;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue1_type);
 offset+=sizeof(xvalue1_type);
 offset+=1;//align
 descrs[0].m_msg_sqlind_offset      =offset;

 offset+=sizeof(c_test_sqlind);
 offset+=0;//align

 descrs[1].m_xvar_sqltype           =c_sql_type;
 descrs[1].m_xvar_sqlscale          =0;
 descrs[1].m_msg_value_block_offset =offset;
 descrs[1].m_msg_value_block_size   =sizeof(xvalue2_type);
 offset+=sizeof(xvalue2_type);
 offset+=1;//align
 descrs[1].m_msg_sqlind_offset      =offset;

 offset+=sizeof(c_test_sqlind);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue1_type)==3);
 assert_s(sizeof(xvalue2_type)==5);

 //-----------------------------------------
 std::vector<unsigned char> buf;

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value1),
           reinterpret_cast<const unsigned char*>(&c_test_value1)+sizeof(c_test_value1),
           std::back_inserter(buf));

 buf.push_back(0);

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //---- align

 //----
 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value2),
           reinterpret_cast<const unsigned char*>(&c_test_value2)+sizeof(c_test_value2),
           std::back_inserter(buf));

 buf.push_back(0);

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xvalue1_type xvalue1={};
 short        xsqlind1=c_init_sqlind;

 xvalue2_type xvalue2={};
 short        xsqlind2=c_init_sqlind;

 xsqlda->sqld=2;

 assert_s(sizeof(xvalue1)==3);
 assert_s(sizeof(xvalue2)==5);

 xsqlda->sqlvar[0].sqltype=c_sql_type|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue1);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue1);
 xsqlda->sqlvar[0].sqlind =&xsqlind1;

 xsqlda->sqlvar[1].sqltype=c_sql_type|1;
 xsqlda->sqlvar[1].sqllen =sizeof(xvalue2);
 xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xvalue2);
 xsqlda->sqlvar[1].sqlind =&xsqlind2;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.data(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue1 ==c_test_value1);
 _TSO_CHECK(xsqlind1==0);

 _TSO_CHECK(xvalue2 ==c_test_value2);
 _TSO_CHECK(xsqlind2==0);
}//test_D11__text_03_2

////////////////////////////////////////////////////////////////////////////////
//TEST D11-04

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D11__text_04__null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const short c_init_sqlind=5487;

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_text;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =3; //char(3)
 descrs[0].m_msg_sqlind_offset      =4;

 //-----------------------------------------
 assert_s(sizeof(short)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(descrs[0].m_msg_sqlind_offset+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 reinterpret_cast<char*>(buf.buffer())[0]='1';
 reinterpret_cast<char*>(buf.buffer())[1]='2';
 reinterpret_cast<char*>(buf.buffer())[2]=' ';

 *reinterpret_cast<short*>(buf.ptr_at(descrs[0].m_msg_sqlind_offset))=-1;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 char xvalue[3+/*guard*/2];

 memset(xvalue,0xFE,sizeof(xvalue));

 short xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_text|1;
 xsqlda->sqlvar[0].sqllen =3;
 xsqlda->sqlvar[0].sqldata=xvalue;
 xsqlda->sqlvar[0].sqlind =&xsqlind; //not changed

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xsqlind==-1);

 _TSO_CHECK(xvalue[0]==0);
 _TSO_CHECK(xvalue[1]==0);
 _TSO_CHECK(xvalue[2]==0);
 _TSO_CHECK(xvalue[3]==(char)0xFE);
 _TSO_CHECK(xvalue[4]==(char)0xFE);
}//test_D11__text_04__null

////////////////////////////////////////////////////////////////////////////////
//TEST D12-01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D12__varying_01
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_varying;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =5; //varchar(3)
 descrs[0].m_msg_sqlind_offset      =6;

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(isc_api::isc_varchar_size_type)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(descrs[0].m_msg_sqlind_offset+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<isc_api::isc_varchar_size_type*>(buf.buffer())=2;

 reinterpret_cast<char*>(buf.ptr_at(sizeof(isc_api::isc_varchar_size_type)))[0]='1';
 reinterpret_cast<char*>(buf.ptr_at(sizeof(isc_api::isc_varchar_size_type)))[1]=' ';

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 char xvalue[sizeof(isc_api::isc_varchar_size_type)+3+/*guard*/2]={};

 memset(xvalue,0xFE,sizeof(xvalue));

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_varying;
 xsqlda->sqlvar[0].sqllen =3;
 xsqlda->sqlvar[0].sqldata=xvalue;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK((*reinterpret_cast<const isc_api::isc_varchar_size_type*>(xvalue))==2);

 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[0]=='1');
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[1]==' ');
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[2]==0);
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[3]==(char)0xFE);
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[4]==(char)0xFE);
}//test_D12__varying_01

////////////////////////////////////////////////////////////////////////////////
//TEST D12-02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D12__varying_02
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const short c_init_sqlind=5487;

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_varying;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =5; //varchar(3)
 descrs[0].m_msg_sqlind_offset      =6;

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(isc_api::isc_varchar_size_type)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(descrs[0].m_msg_sqlind_offset+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<isc_api::isc_varchar_size_type*>(buf.buffer())=2;

 reinterpret_cast<char*>(buf.ptr_at(sizeof(isc_api::isc_varchar_size_type)))[0]='1';
 reinterpret_cast<char*>(buf.ptr_at(sizeof(isc_api::isc_varchar_size_type)))[1]=' ';

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 char xvalue[sizeof(isc_api::isc_varchar_size_type)+3+/*guard*/2]={};

 memset(xvalue,0xFE,sizeof(xvalue));

 short xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_varying;
 xsqlda->sqlvar[0].sqllen =3;
 xsqlda->sqlvar[0].sqldata=xvalue;
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xsqlind==c_init_sqlind);

 _TSO_CHECK((*reinterpret_cast<const isc_api::isc_varchar_size_type*>(xvalue))==2);

 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[0]=='1');
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[1]==' ');
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[2]==0);
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[3]==(char)0xFE);
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[4]==(char)0xFE);
}//test_D12__varying_02

////////////////////////////////////////////////////////////////////////////////
//TEST D12-03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D12__varying_03
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const short c_init_sqlind=5487;

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_varying;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =5; //varchar(3)
 descrs[0].m_msg_sqlind_offset      =6;

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(isc_api::isc_varchar_size_type)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(descrs[0].m_msg_sqlind_offset+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<isc_api::isc_varchar_size_type*>(buf.buffer())=2;

 reinterpret_cast<char*>(buf.ptr_at(sizeof(isc_api::isc_varchar_size_type)))[0]='1';
 reinterpret_cast<char*>(buf.ptr_at(sizeof(isc_api::isc_varchar_size_type)))[1]=' ';

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 char xvalue[sizeof(isc_api::isc_varchar_size_type)+3+/*guard*/2]={};

 memset(xvalue,0xFE,sizeof(xvalue));

 short xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_varying|1;
 xsqlda->sqlvar[0].sqllen =3;
 xsqlda->sqlvar[0].sqldata=xvalue;
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xsqlind==0);

 _TSO_CHECK((*reinterpret_cast<const isc_api::isc_varchar_size_type*>(xvalue))==2);

 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[0]=='1');
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[1]==' ');
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[2]==0);
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[3]==(char)0xFE);
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[4]==(char)0xFE);
}//test_D12__varying_03

////////////////////////////////////////////////////////////////////////////////
//TEST D12-03-2

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D12__varying_03_2
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 const short c_sql_type=isc_api::ibp_isc_sql_varying;

 struct xvalue1_type
 {
  db_obj::t_dbvalue__i2 len;

  char data[3];
 };//struct xvalue1_type

 struct xvalue2_type
 {
  db_obj::t_dbvalue__i2 len;

  char data[5];
 };//struct xvalue2_type

 const xvalue1_type    c_test_value1 ={1,{33,22,11}};
 const xvalue2_type    c_test_value2 ={3,{77,66,55,45,44}};

 const short          c_test_sqlind=0;

 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(2);

 size_t offset=0;

 descrs[0].m_xvar_sqltype           =c_sql_type;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =offset;
 descrs[0].m_msg_value_block_size   =sizeof(c_test_value1.len)+sizeof(c_test_value1.data);
 offset+=descrs[0].m_msg_value_block_size;
 offset+=1;//align
 descrs[0].m_msg_sqlind_offset      =offset;

 offset+=sizeof(c_test_sqlind);
 offset+=0;//align

 descrs[1].m_xvar_sqltype           =c_sql_type;
 descrs[1].m_xvar_sqlscale          =0;
 descrs[1].m_msg_value_block_offset =offset;
 descrs[1].m_msg_value_block_size   =sizeof(c_test_value2.len)+sizeof(c_test_value2.data);
 offset+=descrs[1].m_msg_value_block_size;
 offset+=1;//align
 descrs[1].m_msg_sqlind_offset      =offset;

 offset+=sizeof(c_test_sqlind);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(c_test_value1.data)==3);
 assert_s(sizeof(c_test_value2.data)==5);

 //-----------------------------------------
 std::vector<unsigned char> buf;

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value1.len),
           reinterpret_cast<const unsigned char*>(&c_test_value1.len)+sizeof(c_test_value1.len),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value1.data),
           reinterpret_cast<const unsigned char*>(&c_test_value1.data)+sizeof(c_test_value1.data),
           std::back_inserter(buf));

 buf.push_back(0);

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //---- align

 //----
 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value2.len),
           reinterpret_cast<const unsigned char*>(&c_test_value2.len)+sizeof(c_test_value2.len),
           std::back_inserter(buf));

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value2.data),
           reinterpret_cast<const unsigned char*>(&c_test_value2.data)+sizeof(c_test_value2.data),
           std::back_inserter(buf));

 buf.push_back(0);

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xvalue1_type xvalue1={};
 short        xsqlind1=c_init_sqlind;

 xvalue2_type xvalue2={};
 short        xsqlind2=c_init_sqlind;

 xsqlda->sqld=2;

 assert_s(sizeof(c_test_value1.data)==3);
 assert_s(sizeof(c_test_value2.data)==5);

 xsqlda->sqlvar[0].sqltype=c_sql_type|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue1.data);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue1);
 xsqlda->sqlvar[0].sqlind =&xsqlind1;

 xsqlda->sqlvar[1].sqltype=c_sql_type|1;
 xsqlda->sqlvar[1].sqllen =sizeof(xvalue2.data);
 xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xvalue2);
 xsqlda->sqlvar[1].sqlind =&xsqlind2;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.data(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xsqlind1==0);
 _TSO_CHECK(xvalue1.len ==1);
 _TSO_CHECK(xvalue1.data[0] ==33);
 _TSO_CHECK(xvalue1.data[1] ==0);
 _TSO_CHECK(xvalue1.data[2] ==0);

 //----------
 _TSO_CHECK(xsqlind2==0);
 _TSO_CHECK(xvalue2.len ==3);
 _TSO_CHECK(xvalue2.data[0] ==77);
 _TSO_CHECK(xvalue2.data[1] ==66);
 _TSO_CHECK(xvalue2.data[2] ==55);
 _TSO_CHECK(xvalue2.data[3] ==0);
 _TSO_CHECK(xvalue2.data[4] ==0);
}//test_D12__varying_03_2

////////////////////////////////////////////////////////////////////////////////
//TEST D12-04

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D12__varying_04__null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 const short c_init_sqlind=5487;

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_isc_sql_varying;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =5; //varchar(3)
 descrs[0].m_msg_sqlind_offset      =6;

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(isc_api::isc_varchar_size_type)==2);

 //-----------------------------------------
 msg_data_buffer_type buf(descrs[0].m_msg_sqlind_offset+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<isc_api::isc_varchar_size_type*>(buf.buffer())=2;

 reinterpret_cast<char*>(buf.ptr_at(sizeof(isc_api::isc_varchar_size_type)))[0]='1';
 reinterpret_cast<char*>(buf.ptr_at(sizeof(isc_api::isc_varchar_size_type)))[1]=' ';

 *reinterpret_cast<short*>(buf.ptr_at(descrs[0].m_msg_sqlind_offset))=-1;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 char xvalue[sizeof(isc_api::isc_varchar_size_type)+3+/*guard*/2]={};

 memset(xvalue,0xFE,sizeof(xvalue));

 short xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_isc_sql_varying|1;
 xsqlda->sqlvar[0].sqllen =3;
 xsqlda->sqlvar[0].sqldata=xvalue;
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xsqlind==-1);

 _TSO_CHECK((*reinterpret_cast<const isc_api::isc_varchar_size_type*>(xvalue))==0);

 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[0]==0);
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[1]==0);
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[2]==0);
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[3]==(char)0xFE);
 _TSO_CHECK((xvalue+sizeof(isc_api::isc_varchar_size_type))[4]==(char)0xFE);
}//test_D12__varying_04__null

////////////////////////////////////////////////////////////////////////////////
//TEST D14-01

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D14__boolean_01
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_fb030_bool xvalue_type;

 const xvalue_type c_test_value =isc_api::ibp_fb030_true;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_fb030_sql_boolean;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =2;

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==1);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+1+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=17;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==1);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_fb030_sql_boolean;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
}//test_D14__boolean_01

////////////////////////////////////////////////////////////////////////////////
//TEST D14-02

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D14__boolean_02
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_fb030_bool xvalue_type;

 const xvalue_type    c_test_value =isc_api::ibp_fb030_false;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_fb030_sql_boolean;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =2;

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==1);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+1+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=18;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==1);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_fb030_sql_boolean;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==c_init_sqlind);
}//test_D14__boolean_02

////////////////////////////////////////////////////////////////////////////////
//TEST D14-03

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D14__boolean_03
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_fb030_bool xvalue_type;

 const xvalue_type    c_test_value =isc_api::ibp_fb030_true;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_fb030_sql_boolean;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =2;

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==1);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+1+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())=c_test_value;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=31;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==1);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_fb030_sql_boolean|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==c_test_value);
 _TSO_CHECK(xsqlind==0);
}//test_D14__boolean_03

////////////////////////////////////////////////////////////////////////////////
//TEST D14-03-2

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D14__boolean_03_2
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 const short c_sql_type=isc_api::ibp_fb030_sql_boolean;

 typedef isc_api::t_ibp_fb030_bool xvalue_type;

 const xvalue_type    c_test_value1 =12;
 const xvalue_type    c_test_value2 =32;

 const short          c_test_sqlind=0;

 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(2);

 size_t offset=0;

 descrs[0].m_xvar_sqltype           =c_sql_type;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =offset;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type)+1);

 offset+=sizeof(c_test_sqlind);

 descrs[1].m_xvar_sqltype           =c_sql_type;
 descrs[1].m_xvar_sqlscale          =0;
 descrs[1].m_msg_value_block_offset =offset;
 descrs[1].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[1].m_msg_sqlind_offset      =(offset+=sizeof(xvalue_type)+1);

 offset+=sizeof(c_test_sqlind);

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==1);

 //-----------------------------------------
 std::vector<unsigned char> buf;

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value1),
           reinterpret_cast<const unsigned char*>(&c_test_value1)+sizeof(c_test_value1),
           std::back_inserter(buf));

 buf.push_back(0);

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //---- align

 //----
 std::copy(reinterpret_cast<const unsigned char*>(&c_test_value2),
           reinterpret_cast<const unsigned char*>(&c_test_value2)+sizeof(c_test_value2),
           std::back_inserter(buf));

 buf.push_back(0);

 std::copy(reinterpret_cast<const unsigned char*>(&c_test_sqlind),
           reinterpret_cast<const unsigned char*>(&c_test_sqlind)+sizeof(c_test_sqlind),
           std::back_inserter(buf));

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(2);

 xvalue_type xvalue1=35;
 short       xsqlind1=c_init_sqlind;

 xvalue_type xvalue2=53;
 short       xsqlind2=c_init_sqlind;

 xsqlda->sqld=2;

 assert_s(sizeof(xvalue1)==1);

 xsqlda->sqlvar[0].sqltype=c_sql_type|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue1);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue1);
 xsqlda->sqlvar[0].sqlind =&xsqlind1;

 xsqlda->sqlvar[1].sqltype=c_sql_type|1;
 xsqlda->sqlvar[1].sqllen =sizeof(xvalue2);
 xsqlda->sqlvar[1].sqldata=reinterpret_cast<char*>(&xvalue2);
 xsqlda->sqlvar[1].sqlind =&xsqlind2;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.data(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue1 ==c_test_value1);
 _TSO_CHECK(xsqlind1==0);

 _TSO_CHECK(xvalue2 ==c_test_value2);
 _TSO_CHECK(xsqlind2==0);
}//test_D14__boolean_03_2

////////////////////////////////////////////////////////////////////////////////
//TEST D14-04

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::test_D14__boolean_04__null
                                           (TTSO_GlobalContext* const DEBUG_CODE(pParams),
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 //-----------------------------------------
 typedef isc_api::t_ibp_fb030_bool xvalue_type;

 const xvalue_type    c_test_value =isc_api::ibp_fb030_true;
 const short          c_init_sqlind=5487;

 //-----------------------------------------
 TTSO_Tracer tracer(pCtx,L"test");

 //-----------------------------------------
 msg_data_descrs_type descrs(1);

 descrs[0].m_xvar_sqltype           =isc_api::ibp_fb030_sql_boolean;
 descrs[0].m_xvar_sqlscale          =0;
 descrs[0].m_msg_value_block_offset =0;
 descrs[0].m_msg_value_block_size   =sizeof(xvalue_type);
 descrs[0].m_msg_sqlind_offset      =2;

 //-----------------------------------------
 assert_s(sizeof(short)==2);
 assert_s(sizeof(xvalue_type)==1);

 //-----------------------------------------
 msg_data_buffer_type buf(sizeof(xvalue_type)+1+sizeof(short));

 std::fill(buf.buffer(),buf.buffer_end(),0);

 *reinterpret_cast<xvalue_type*>(buf.buffer())                  =c_test_value;
 *reinterpret_cast<short*>(buf.buffer()+sizeof(xvalue_type)+1)  =-1;

 //-----------------------------------------
 XSQLDA_V1_Wrapper xsqlda(1);

 xvalue_type xvalue=73;
 short       xsqlind=c_init_sqlind;

 xsqlda->sqld=1;

 assert_s(sizeof(xvalue)==1);

 xsqlda->sqlvar[0].sqltype=isc_api::ibp_fb030_sql_boolean|1;
 xsqlda->sqlvar[0].sqllen =sizeof(xvalue);
 xsqlda->sqlvar[0].sqldata=reinterpret_cast<char*>(&xvalue);
 xsqlda->sqlvar[0].sqlind =&xsqlind;

 //-----------------------------------------
 self_type::Helper__Parse_XSQLDA_MSG_DATA
  (descrs,
   /*cbMsgData*/buf.size(),
   /*pMsgData*/buf.buffer(),
   xsqlda); //throw!

 //-----------------------------------------
 _TSO_CHECK(xvalue==0);
 _TSO_CHECK(xsqlind==-1);
}//test_D14__boolean_04__null

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_descr

struct TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_impl::func},

const TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::tag_descr
 TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::sm_Tests[]=
{
 DEF_TEST_DESCR("001.null_ptr",
                test_001___null_ptr)
 DEF_TEST_DESCR("002.zero_sqld",
                test_002___zero_sqld)

 DEF_TEST_DESCR("E01.err.not_eq_count",
                test_e01__err__not_eq_count)
 DEF_TEST_DESCR("E02.err.incorrect_xvar_sqltype",
                test_e02__err__incorrect_xvar_sqltype)
 DEF_TEST_DESCR("E03.err.xvar_not_supports_null_value",
                test_e03__err__xvar_not_supports_null_value)
 DEF_TEST_DESCR("E04.err.xvar_supports_null_value_but_has_null_ptr_in_sqlind",
                test_e04__err__xvar_supports_null_value_but_has_null_ptr_in_sqlind)
 DEF_TEST_DESCR("E05.err.xvar_has_incorrect_null_ptr_in_sqlind",
                test_e05__err__xvar_has_incorrect_null_ptr_in_sqlind)

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
 DEF_TEST_DESCR("T13.bug_check.incorrect_sqllen.boolean",
                test_t13___bug_check__incorrect_sqllen__boolean)

 DEF_TEST_DESCR("S01.bug_check.not_stable_sqlscale.short",
                test_s01___bug_check__not_stable_sqlscale__short)
 DEF_TEST_DESCR("S02.bug_check.not_stable_sqlscale.long",
                test_s02___bug_check__not_stable_sqlscale__long)
 DEF_TEST_DESCR("S03.bug_check.not_stable_sqlscale.int64",
                test_s03___bug_check__not_stable_sqlscale__int64)

 DEF_TEST_DESCR("L01.bug_check.not_stable_sqllen.text",
                test_L01___bug_check__not_stable_sqllen__text)
 DEF_TEST_DESCR("L02.bug_check.not_stable_sqllen.varying",
                test_L02___bug_check__not_stable_sqllen__varying)

 DEF_TEST_DESCR("V01.err.varchar.negative_length_of_value",
                test_V01___err__varchar__negative_length_of_value)
 DEF_TEST_DESCR("V02.err.varchar.too_large_value",
                test_V02___err__varchar__too_large_value)

 DEF_TEST_DESCR("D01.short.01",
                test_D01__short_01)
 DEF_TEST_DESCR("D01.short.02",
                test_D01__short_02)
 DEF_TEST_DESCR("D01.short.03",
                test_D01__short_03)
 DEF_TEST_DESCR("D01.short.03.2",
                test_D01__short_03_2)
 DEF_TEST_DESCR("D01.short.04.null",
                test_D01__short_04__null)

 DEF_TEST_DESCR("D02.long.01",
                test_D02__long_01)
 DEF_TEST_DESCR("D02.long.02",
                test_D02__long_02)
 DEF_TEST_DESCR("D02.long.03.2",
                test_D02__long_03_2)
 DEF_TEST_DESCR("D02.long.03",
                test_D02__long_03)
 DEF_TEST_DESCR("D02.long.04.null",
                test_D02__long_04__null)

 DEF_TEST_DESCR("D03.int64.01",
                test_D03__int64_01)
 DEF_TEST_DESCR("D03.int64.02",
                test_D03__int64_02)
 DEF_TEST_DESCR("D03.int64.03",
                test_D03__int64_03)
 DEF_TEST_DESCR("D03.int64.03.2",
                test_D03__int64_03_2)
 DEF_TEST_DESCR("D03.int64.04.null",
                test_D03__int64_04__null)

 DEF_TEST_DESCR("D04.float.01",
                test_D04__float_01)
 DEF_TEST_DESCR("D04.float.02",
                test_D04__float_02)
 DEF_TEST_DESCR("D04.float.03",
                test_D04__float_03)
 DEF_TEST_DESCR("D04.float.03.2",
                test_D04__float_03_2)
 DEF_TEST_DESCR("D04.float.04.null",
                test_D04__float_04__null)

 DEF_TEST_DESCR("D05.double.01",
                test_D05__double_01)
 DEF_TEST_DESCR("D05.double.02",
                test_D05__double_02)
 DEF_TEST_DESCR("D05.double.03",
                test_D05__double_03)
 DEF_TEST_DESCR("D05.double.03.2",
                test_D05__double_03_2)
 DEF_TEST_DESCR("D05.double.04.null",
                test_D05__double_04__null)

 DEF_TEST_DESCR("D06.time.01",
                test_D06__time_01)
 DEF_TEST_DESCR("D06.time.02",
                test_D06__time_02)
 DEF_TEST_DESCR("D06.time.03",
                test_D06__time_03)
 DEF_TEST_DESCR("D06.time.03.2",
                test_D06__time_03_2)
 DEF_TEST_DESCR("D06.time.04.null",
                test_D06__time_04__null)

 DEF_TEST_DESCR("D07.date.01",
                test_D07__date_01)
 DEF_TEST_DESCR("D07.date.02",
                test_D07__date_02)
 DEF_TEST_DESCR("D07.date.03",
                test_D07__date_03)
 DEF_TEST_DESCR("D07.date.03.2",
                test_D07__date_03_2)
 DEF_TEST_DESCR("D07.date.04.null",
                test_D07__date_04__null)

 DEF_TEST_DESCR("D08.timestamp.01",
                test_D08__timestamp_01)
 DEF_TEST_DESCR("D08.timestamp.02",
                test_D08__timestamp_02)
 DEF_TEST_DESCR("D08.timestamp.03",
                test_D08__timestamp_03)
 DEF_TEST_DESCR("D08.timestamp.03.2",
                test_D08__timestamp_03_2)
 DEF_TEST_DESCR("D08.timestamp.04.null",
                test_D08__timestamp_04__null)

 DEF_TEST_DESCR("D09.blob.01",
                test_D09__blob_01)
 DEF_TEST_DESCR("D09.blob.02",
                test_D09__blob_02)
 DEF_TEST_DESCR("D09.blob.03",
                test_D09__blob_03)
 DEF_TEST_DESCR("D09.blob.03.2",
                test_D09__blob_03_2)
 DEF_TEST_DESCR("D09.blob.04.null",
                test_D09__blob_04__null)

 DEF_TEST_DESCR("D10.array.01",
                test_D10__array_01)
 DEF_TEST_DESCR("D10.array.02",
                test_D10__array_02)
 DEF_TEST_DESCR("D10.array.03",
                test_D10__array_03)
 DEF_TEST_DESCR("D10.array.03.2",
                test_D10__array_03_2)
 DEF_TEST_DESCR("D10.array.04.null",
                test_D10__array_04__null)

 DEF_TEST_DESCR("D11.text.01",
                 test_D11__text_01)
 DEF_TEST_DESCR("D11.text.02",
                 test_D11__text_02)
 DEF_TEST_DESCR("D11.text.03",
                 test_D11__text_03)
 DEF_TEST_DESCR("D11.text.03.2",
                 test_D11__text_03_2)
 DEF_TEST_DESCR("D11.text.04.null",
                 test_D11__text_04__null)

 DEF_TEST_DESCR("D12.varying.01",
                 test_D12__varying_01)
 DEF_TEST_DESCR("D12.varying.02",
                 test_D12__varying_02)
 DEF_TEST_DESCR("D12.varying.03",
                 test_D12__varying_03)
 DEF_TEST_DESCR("D12.varying.03.2",
                 test_D12__varying_03_2)
 DEF_TEST_DESCR("D12.varying.04.null",
                 test_D12__varying_04__null)

 DEF_TEST_DESCR("D14.boolean.01",
                test_D14__boolean_01)
 DEF_TEST_DESCR("D14.boolean.02",
                test_D14__boolean_02)
 DEF_TEST_DESCR("D14.boolean.03",
                test_D14__boolean_03)
 DEF_TEST_DESCR("D14.boolean.03.2",
                test_D14__boolean_03_2)
 DEF_TEST_DESCR("D14.boolean.04.null",
                test_D14__boolean_04__null)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA

void TestsFor__fb_v03_0_0__xsqlda_v1_svc__msg_data___Parse_XSQLDA_MSG_DATA::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter
  ftestID
   ("DB_OBJ.UNITS.DBMS_FB.V03_0_0.xsqlda_v1_svc__msg_data.Parse_XSQLDA_MSG_DATA.%1");

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
