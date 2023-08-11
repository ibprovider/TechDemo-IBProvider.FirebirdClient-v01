////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/tests/api/helpers/RemoteFB__API_HLP__ArraySlice_V01__Utilities/TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL.h"
#include "source/test_services.h"
#include "source/test_operation_context.h"
#include "source/test_check_errors.h"
#include "source/test_func.h"
#include "source/db_client/remote_fb/api/helpers/remote_fb__api_hlp__array_slice_v01__utilities.h"
#include <structure/test_obj/t_tso_user.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl

class TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl
{
 private:
  typedef tag_impl                                                  self_type;

 public: //typedefs ------------------------------------------------------
  typedef TTSO_Test::context_type                                   context_type;

  typedef remote_fb::api::helpers::RemoteFB__API_HLP__ArraySlice_v01__Utilities  array_utils_type;

 public:
#ifdef NDEBUG
  static void test_001__err__empty_buffer
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_002__err__unk_version
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_003__err__check_point_004
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_004__err__check_point_R01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_005__err__check_point_R02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_006__err__check_point_F01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_007__err__check_point_F02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_008__err__check_point_R00
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_009__err__check_point_F00
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_010__err__check_point_S01
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_011__err__check_point_S02
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_012__err__check_point_S00
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_013__err__check_point_D101
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_014__err__check_point_D102
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_015__err__check_point_D103
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_016__err__check_point_D104
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_017__err__check_point_D201
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_018__err__check_point_D202
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_019__err__check_point_D203
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_020__err__check_point_D204
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_021__err__check_point_E00
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_022__err__check_point_X00
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_023__err__check_point_005
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_024__err__check_point_006
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_025__err__check_point_007
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_026__err__check_point_008
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_027__err__check_point_009
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_028__err__check_point_010
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
#endif

 public:
#ifdef NDEBUG
  static void test_100__ReadLiteral__err__check_point_001
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_101__ReadLiteral__err__check_point_002
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_102__ReadLiteral__err__check_point_003
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_103__ReadLiteral__err__check_point_004
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_104__ReadLiteral__err__check_point_005
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
#endif

 public:
#ifdef NDEBUG
  static void test_200__ReadElement__err__check_point_001
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_201__ReadElement__err__check_point_002
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_202__ReadElement__err__check_point_003
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_203__ReadElement__err__check_point_004
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_204__ReadElement__err__check_point_005
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_205__ReadElement__err__check_point_006
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_206__ReadElement__err__check_point_007
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_207__ReadElement__err__check_point_008
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_208__ReadElement__err__check_point_009
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_209__ReadElement__err__check_point_010
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
#endif

 public:
#ifdef NDEBUG
  static void test_300__ReadElementType__err__check_point_Z00
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_301__ReadElementType__err__check_point_001
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_302__ReadElementType__err__check_point_002
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_303__ReadElementType__err__check_point_003
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_304__ReadElementType__err__check_point_004
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_305__ReadElementType__err__check_point_005
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_306__ReadElementType__err__check_point_006
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_307__ReadElementType__err__check_point_007
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_308__ReadElementType__err__check_point_008
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_309__ReadElementType__err__check_point_009
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_310__ReadElementType__err__check_point_010
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
#endif

  static void test_311__ReadElementType__err__check_point_L01__len0
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_312__ReadElementType__err__check_point_L01__len32768
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_313__ReadElementType__err__check_point_L02__len0
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_314__ReadElementType__err__check_point_L02__len32766
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_315__ReadElementType__err__check_point_L03__len0
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_316__ReadElementType__err__check_point_L03__len32768
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

#ifdef NDEBUG
  static void test_330__ReadElementType__err__check_point_011___int128
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
#endif

 public:
  static void test_400__short_integer
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_401__long_integer
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

 public:
  static void test_501__short__scale_n2
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_502__long__scale_n5
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_503__int64__scale_n12
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_504__float
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_505__double
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_506__time
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_507__date
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_508__timestamp
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_509__text2__len1
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_509__text2__len32767
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_510__varying2__len1
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_510__varying2__len32765
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_511__cstring2__len1
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_511__cstring2__len32767
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_512__boolean
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_513__int128__scale_n12
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_514__decfloat16
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_515__decfloat34
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);

  static void test_516__timestamp_with_tz
               (TTSO_GlobalContext* pParams,
                context_type*       pCtx);
};//class TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl

////////////////////////////////////////////////////////////////////////////////
//TEST 001

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_001__err__empty_buffer
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL(OpCtx,
                              0,
                              nullptr,
                              &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__no_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#001");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_001__err__empty_buffer

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 002

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_002__err__unk_version
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]={0xFF};

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unk_version
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#003",
     0xFF);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_002__err__unk_version

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 003

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_003__err__check_point_004
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]={isc_api::ibp_isc_sdl_version1};

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#004");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_003__err__check_point_004

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 004

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_004__err__check_point_R01
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_relation};

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#R01");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_004__err__check_point_R01

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 005

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_005__err__check_point_R02
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_relation,
  0x1};

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__str_len_exceed_size_of_buffer_tail
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#R02",
     1,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_005__err__check_point_R02

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 006

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_006__err__check_point_F01
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_field};

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#F01");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_006__err__check_point_F01

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 007

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_007__err__check_point_F02
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_field,
  0x1};

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__str_len_exceed_size_of_buffer_tail
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#F02",
     1,
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_007__err__check_point_F02

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 008

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_008__err__check_point_R00
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,   // 0
  isc_api::ibp_isc_sdl_relation,   // 1
  1,                               // 2
  ' ',                             // 3
  isc_api::ibp_isc_sdl_relation};  // 4

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__mult_def_of_element_value
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#R00",
     L"isc_sdl_relation",
     /*offset*/4);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_008__err__check_point_R00

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 009

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_009__err__check_point_F00
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,  // 0
  isc_api::ibp_isc_sdl_field,     // 1
  1,                              // 2
  ' ',                            // 3
  isc_api::ibp_isc_sdl_field};    // 4

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__mult_def_of_element_value
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#F00",
     L"isc_sdl_field",
     /*offset*/4);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_009__err__check_point_F00

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 010

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_010__err__check_point_S01
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct};

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#S01");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_010__err__check_point_S01

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 011

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_011__err__check_point_S02
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  2};

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__wrong_count_of_struct_fields
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#S02",
     2);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_011__err__check_point_S02

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 012

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_012__err__check_point_S00
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,        // 0
  isc_api::ibp_isc_sdl_struct,          // 1
  1,                                    // 2
  isc_api::ibp_isc_blr_dtype__short,    // 3
  0, //scale                            // 4
  isc_api::ibp_isc_sdl_struct};         // 5

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__mult_def_of_element_value
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#S00",
     L"isc_sdl_struct",
     /*offset*/5);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_012__err__check_point_S00

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 013

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_013__err__check_point_D101
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_do1
 };

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#D101");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_013__err__check_point_D101

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 014

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_014__err__check_point_D102
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_do1,
  16,
 };

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__wrong_index_of_bound
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#D102",
     16,
     16);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_014__err__check_point_D102

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 015

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_015__err__check_point_D103
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  100,
  isc_api::ibp_isc_sdl_do1,
  0,                              //duplication
 };

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__mult_def_of_bound_range
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#D103",
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_015__err__check_point_D103

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 016

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_016__err__check_point_D104
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_do1,
  1, //dimension index
  isc_api::ibp_isc_sdl_tiny_integer,
  0xFF, //-1
 };

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__bad_bound_range
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#D104",
     1,
     1,
     -1);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_016__err__check_point_D104

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 017

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_017__err__check_point_D201
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_do2
 };

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#D201");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_017__err__check_point_D201

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 018

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_018__err__check_point_D202
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_do2,
  16,
 };

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__wrong_index_of_bound
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#D202",
     16,
     16);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_018__err__check_point_D202

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 019

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_019__err__check_point_D203
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_do2,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  100,
  isc_api::ibp_isc_sdl_tiny_integer,
  101,
  isc_api::ibp_isc_sdl_do2,
  0,                              //duplication
 };

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__mult_def_of_bound_range
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#D203",
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_019__err__check_point_D203

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 020

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_020__err__check_point_D204
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_do2,
  1, //dimension index
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_tiny_integer,
  1,
 };

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__bad_bound_range
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#D204",
     1,
     2,
     1);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_020__err__check_point_D204

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 021

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_021__err__check_point_E00
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,        // 0
  isc_api::ibp_isc_sdl_do1,             // 1
  0, //dimension index                  // 2
  isc_api::ibp_isc_sdl_tiny_integer,    // 3
  2,                                    // 4
  isc_api::ibp_isc_sdl_element,         // 5
  1,                                    // 6
  isc_api::ibp_isc_sdl_scalar,          // 7
  0,                                    // 8
  1, //variable count                   // 9
  isc_api::ibp_isc_sdl_variable,        // 10
  0,                                    // 11
  isc_api::ibp_isc_sdl_element,         // 12
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__mult_def_of_element_value
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#E00",
     L"isc_sdl_element",
     /*offset*/12);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_021__err__check_point_E00

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 022

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_022__err__check_point_X00
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,        // 0
  253,                                  // 1
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_tag
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#X00",
     253,
     /*offset*/1);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_022__err__check_point_X00

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 023

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_023__err__check_point_005
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_eoc,
  0,
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__inconsistent_sizes_of_buffer_and_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#005",
     3,
     2);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_023__err__check_point_005

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 024

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_024__err__check_point_006
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  //isc_api::ibp_isc_sdl_struct,
  //1,
  //isc_api::ibp_isc_blr_dtype__short,
  //0,//scale
  isc_api::ibp_isc_sdl_relation,
  1,
  'x',
  isc_api::ibp_isc_sdl_field,
  1,
  'y',
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  1,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  1,
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__no_data_of_tag
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#006",
     L"isc_sdl_struct");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_024__err__check_point_006

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 025

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_025__err__check_point_007
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__short,
  0,//scale
  //isc_api::ibp_isc_sdl_relation,
  //1,
  //'x',
  isc_api::ibp_isc_sdl_field,
  1,
  'y',
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  1,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  1,
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__no_data_of_tag
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#007",
     L"isc_sdl_relation");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_025__err__check_point_007

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 026

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_026__err__check_point_008
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__short,
  0,//scale
  isc_api::ibp_isc_sdl_relation,
  1,
  'x',
  //isc_api::ibp_isc_sdl_field,
  //1,
  //'y',
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  1,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  1,
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__no_data_of_tag
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#008",
     L"isc_sdl_field");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_026__err__check_point_008

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 027

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_027__err__check_point_009
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__short,
  0,//scale
  isc_api::ibp_isc_sdl_relation,
  1,
  'x',
  isc_api::ibp_isc_sdl_field,
  1,
  'y',
  //isc_api::ibp_isc_sdl_do1,
  //0,
  //isc_api::ibp_isc_sdl_tiny_integer,
  //1,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  1,
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__no_data_of_dimensions
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#009");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_027__err__check_point_009

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 028

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_028__err__check_point_010
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__short,
  0,//scale
  isc_api::ibp_isc_sdl_relation,
  1,
  'x',
  isc_api::ibp_isc_sdl_field,
  1,
  'y',
  //isc_api::ibp_isc_sdl_do1,
  //0,
  //isc_api::ibp_isc_sdl_tiny_integer,
  //1,
  isc_api::ibp_isc_sdl_do1,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  1,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__no_data_of_dimension
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::ParseSDL",
     L"#010",
     0);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_028__err__check_point_010

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 100

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_100__ReadLiteral__err__check_point_001
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1,
   isc_api::ibp_isc_sdl_do1,
   1,
   /*expected literal kind tag*/
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadLiteral",
     L"#001");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_100__ReadLiteral__err__check_point_001

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 101

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_101__ReadLiteral__err__check_point_002
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1,
   isc_api::ibp_isc_sdl_do1,
   1,
   isc_api::ibp_isc_sdl_tiny_integer,
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadLiteral",
     L"#002");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_101__ReadLiteral__err__check_point_002

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 102

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_102__ReadLiteral__err__check_point_003
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1,           // 1
   isc_api::ibp_isc_sdl_do1,                // 2
   1,                                       // 3
   isc_api::ibp_isc_sdl_short_integer,      // 4
   0                                        // 5
   /*end*/
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(size_t szSDL=4;szSDL!=6;++szSDL)
 {
  tracer<<L"----------------- szSDL: "<<szSDL<<send;

  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     szSDL,
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadLiteral",
     L"#003");

   continue;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for szSDL
}//test_102__ReadLiteral__err__check_point_003

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 103

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_103__ReadLiteral__err__check_point_004
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1,           // 1
   isc_api::ibp_isc_sdl_do1,                // 2
   1,                                       // 3
   isc_api::ibp_isc_sdl_long_integer,       // 4
   0,                                       // 5
   0,                                       // 6
   0,                                       // 7
   /*end*/
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(size_t szSDL=4;szSDL!=8;++szSDL)
 {
  tracer<<L"----------------- szSDL: "<<szSDL<<send;

  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     szSDL,
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadLiteral",
     L"#004");

   continue;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_103__ReadLiteral__err__check_point_004

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 104

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_104__ReadLiteral__err__check_point_005
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1,      // 0
   isc_api::ibp_isc_sdl_do1,           // 1
   1,                                  // 2
   254, //incorrect kubd of literal    // 3
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unknown_kind_of_literal
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadLiteral",
     L"#005",
     /*literalKind*/254,
     /*offset*/3);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_104__ReadLiteral__err__check_point_005

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 200

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_200__ReadElement__err__check_point_001
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1,
   isc_api::ibp_isc_sdl_element,
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElement",
     L"#001");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_200__ReadElement__err__check_point_001

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 201

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_201__ReadElement__err__check_point_002
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1,
   isc_api::ibp_isc_sdl_element,
   12,
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__wrong_count_of_element_fields
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElement",
     L"#002",
     12);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_201__ReadElement__err__check_point_002

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 202

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_202__ReadElement__err__check_point_003
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1,
   isc_api::ibp_isc_sdl_element,
   1,
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElement",
     L"#003");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_202__ReadElement__err__check_point_003

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 203

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_203__ReadElement__err__check_point_004
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1, // 0
   isc_api::ibp_isc_sdl_element,  // 1
   1,                             // 2
   254,/*wrong tag*/              // 3
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_tag
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElement",
     L"#004",
     254,
     /*offset*/3);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_203__ReadElement__err__check_point_004

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 204

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_204__ReadElement__err__check_point_005
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1, // 0
   isc_api::ibp_isc_sdl_element,  // 1
   1,                             // 2
   isc_api::ibp_isc_sdl_scalar    // 3
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElement",
     L"#005");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_204__ReadElement__err__check_point_005

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 205

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_205__ReadElement__err__check_point_006
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1, // 0
   isc_api::ibp_isc_sdl_element,  // 1
   1,                             // 2
   isc_api::ibp_isc_sdl_scalar,   // 3
   7                              // 4
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__incorrect_index_property_of_scalar_tag
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElement",
     L"#006",
     7,
     /*offset*/4);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_205__ReadElement__err__check_point_006

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 206

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_206__ReadElement__err__check_point_007
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1, // 0
   isc_api::ibp_isc_sdl_element,  // 1
   1,                             // 2
   isc_api::ibp_isc_sdl_scalar,   // 3
   0                              // 4
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElement",
     L"#007");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_206__ReadElement__err__check_point_007

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 207

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_207__ReadElement__err__check_point_008
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1, // 0
   isc_api::ibp_isc_sdl_element,  // 1
   1,                             // 2
   isc_api::ibp_isc_sdl_scalar,   // 3
   0,                             // 4
   1, // count of variables
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElement",
     L"#008");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_207__ReadElement__err__check_point_008

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 208

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_208__ReadElement__err__check_point_009
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1, // 0
   isc_api::ibp_isc_sdl_element,  // 1
   1,                             // 2
   isc_api::ibp_isc_sdl_scalar,   // 3
   0,                             // 4
   1, // count of variables,      // 5
   253, //unknown tag             // 6
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_tag
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElement",
     L"#009",
     253,
     /*offset*/6);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_208__ReadElement__err__check_point_009

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 209

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_209__ReadElement__err__check_point_010
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1, // 0
   isc_api::ibp_isc_sdl_element,  // 1
   1,                             // 2
   isc_api::ibp_isc_sdl_scalar,   // 3
   0,                             // 4
   1, // count of variables,      // 5
   isc_api::ibp_isc_sdl_variable, // 6
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElement",
     L"#010");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_209__ReadElement__err__check_point_010

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 300

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_300__ReadElementType__err__check_point_Z00
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1, // 0
   isc_api::ibp_isc_sdl_struct,   // 1
   1,                             // 2
   255,                           // 3
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unknown_blr_type_id
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#Z00",
     255,
     /*offset*/3);

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_300__ReadElementType__err__check_point_Z00

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 301

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_301__ReadElementType__err__check_point_001
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1, // 0
   isc_api::ibp_isc_sdl_struct,   // 1
   1,                             // 2
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#001");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_301__ReadElementType__err__check_point_001

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 302

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_302__ReadElementType__err__check_point_002
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1, // 0
   isc_api::ibp_isc_sdl_struct,   // 1
   1,                             // 2
   isc_api::ibp_isc_blr_dtype__short,
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#002");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_302__ReadElementType__err__check_point_002

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 303

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_303__ReadElementType__err__check_point_003
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1, // 0
   isc_api::ibp_isc_sdl_struct,   // 1
   1,                             // 2
   isc_api::ibp_isc_blr_dtype__long,
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#003");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_303__ReadElementType__err__check_point_003

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 304

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_304__ReadElementType__err__check_point_004
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1, // 0
   isc_api::ibp_isc_sdl_struct,   // 1
   1,                             // 2
   isc_api::ibp_isc_blr_dtype__int64,
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#004");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_304__ReadElementType__err__check_point_004

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 305

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_305__ReadElementType__err__check_point_005
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1,       // 1
   isc_api::ibp_isc_sdl_struct,         // 2
   1,                                   // 3
   isc_api::ibp_isc_blr_dtype__text2,   // 4
   0                                    // 5
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(size_t sz=4;sz!=5;++sz)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     sz,
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#005");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_305__ReadElementType__err__check_point_005

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 306

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_306__ReadElementType__err__check_point_006
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1,       // 1
   isc_api::ibp_isc_sdl_struct,         // 2
   1,                                   // 3
   isc_api::ibp_isc_blr_dtype__text2,   // 4
   0,                                   // 5
   0,                                   // 6
   0,                                   // 7
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(size_t sz=6;sz!=7;++sz)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     sz,
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#006");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_306__ReadElementType__err__check_point_006

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 307

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_307__ReadElementType__err__check_point_007
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1,       // 1
   isc_api::ibp_isc_sdl_struct,         // 2
   1,                                   // 3
   isc_api::ibp_isc_blr_dtype__varying2,// 4
   0                                    // 5
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(size_t sz=4;sz!=5;++sz)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     sz,
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#007");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_307__ReadElementType__err__check_point_007

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 308

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_308__ReadElementType__err__check_point_008
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1,       // 1
   isc_api::ibp_isc_sdl_struct,         // 2
   1,                                   // 3
   isc_api::ibp_isc_blr_dtype__varying2,// 4
   0,                                   // 5
   0,                                   // 6
   0,                                   // 7
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(size_t sz=6;sz!=7;++sz)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     sz,
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#008");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_308__ReadElementType__err__check_point_008

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 309

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_309__ReadElementType__err__check_point_009
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1,       // 1
   isc_api::ibp_isc_sdl_struct,         // 2
   1,                                   // 3
   isc_api::ibp_isc_blr_dtype__cstring2,// 4
   0                                    // 5
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(size_t sz=4;sz!=5;++sz)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     sz,
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#009");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_309__ReadElementType__err__check_point_009

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 310

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_310__ReadElementType__err__check_point_010
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1,       // 1
   isc_api::ibp_isc_sdl_struct,         // 2
   1,                                   // 3
   isc_api::ibp_isc_blr_dtype__cstring2,// 4
   0,                                   // 5
   0,                                   // 6
   0,                                   // 7
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(size_t sz=6;sz!=7;++sz)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     sz,
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#010");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_310__ReadElementType__err__check_point_010

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 311

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_311__ReadElementType__err__check_point_L01__len0
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__text2,
  1,2, //charsetID: 1+2*256
  0,0, //sqllength: 0
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__invalid_element_length
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#L01",
     0,
     L"text2");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_311__ReadElementType__err__check_point_L01__len0

////////////////////////////////////////////////////////////////////////////////
//TEST 312

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_312__ReadElementType__err__check_point_L01__len32768
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__text2,
  1,2, //charsetID: 1+2*256
  0,0x80, //sqllength: 32768
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__invalid_element_length
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#L01",
     32768,
     L"text2");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_312__ReadElementType__err__check_point_L01__len32768

////////////////////////////////////////////////////////////////////////////////
//TEST 313

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_313__ReadElementType__err__check_point_L02__len0
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__varying2,
  1,2, //charsetID: 1+2*256
  0,0, //sqllength: 0
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__invalid_element_length
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#L02",
     0,
     L"varying2");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_313__ReadElementType__err__check_point_L02__len0

////////////////////////////////////////////////////////////////////////////////
//TEST 314

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_314__ReadElementType__err__check_point_L02__len32766
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__varying2,
  1,2, //charsetID: 1+2*256
  0xFE,0x7F, //sqllength: 32766
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__invalid_element_length
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#L02",
     32766,
     L"varying2");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_314__ReadElementType__err__check_point_L02__len32766

////////////////////////////////////////////////////////////////////////////////
//TEST 315

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_315__ReadElementType__err__check_point_L03__len0
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__cstring2,
  1,2, //charsetID: 1+2*256
  0,0, //sqllength: 0
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__invalid_element_length
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#L03",
     0,
     L"cstring2");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_315__ReadElementType__err__check_point_L03__len0

////////////////////////////////////////////////////////////////////////////////
//TEST 316

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_316__ReadElementType__err__check_point_L03__len32768
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__cstring2,
  1,2, //charsetID: 1+2*256
  0,0x80, //sqllength: 32768
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__invalid_element_length
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#L03",
     32768,
     L"cstring2");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_316__ReadElementType__err__check_point_L03__len32768

////////////////////////////////////////////////////////////////////////////////
//TEST 330

#ifdef NDEBUG

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_330__ReadElementType__err__check_point_011___int128
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 remote_fb::RemoteFB__ArraySliceDescr descr;

 const array_utils_type::byte_type sdl[]=
  {
   isc_api::ibp_isc_sdl_version1, // 0
   isc_api::ibp_isc_sdl_struct,   // 1
   1,                             // 2
   isc_api::ibp_fb040_blr_dtype__int128,
  };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 for(;;)
 {
  try
  {
   array_utils_type::ParseSDL
    (OpCtx,
     _LCPI_DIM_(sdl),
     sdl,
     &descr);
  }
  catch(const ibp::t_ibp_error& exc)
  {
   typedef TestCheckErrors errSvc;

   errSvc::print_exception_ok(tracer,exc);

   errSvc::check_err_count(exc,1);

   _TSO_CHECK(exc.get_record(0));

   errSvc::check_err_rec__sdl_err__unexpected_end_of_data
    (tracer,
     exc.get_record(0),
     L"RemoteFB__API_HLP__ArraySlice_v01__Utilities::Helper__ParseSDL__ReadElementType",
     L"#011");

   break;
  }//catch

  TestServices::Throw_WeWaitTheError();
 }//for[ever]
}//test_330__ReadElementType__err__check_point_011___int128

#endif

////////////////////////////////////////////////////////////////////////////////
//TEST 400

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_400__short_integer
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__cstring2,
  1,2, //charsetID: 1+2*256
  7,3, //sqllength: 7+3*256
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do2,
  0,
  isc_api::ibp_isc_sdl_short_integer,
  0x1,
  0xFF,
  isc_api::ibp_isc_sdl_short_integer,
  0x02,
  0x01,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  1,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__cstring2);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_text_props==(1+2*256));

 _TSO_CHECK(descr.m_element_sql_length==(7+3*256));

 _TSO_CHECK(descr.m_element_total_length==(7+3*256));

 _TSO_CHECK(descr.m_bounds_number==1);

 _TSO_CHECK(descr.m_bounds[0].lower==-255);
 _TSO_CHECK(descr.m_bounds[0].upper==258);
}//test_400__short_integer

////////////////////////////////////////////////////////////////////////////////
//TEST 401

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_401__long_integer
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__cstring2,
  1,2, //charsetID: 1+2*256
  7,3, //sqllength: 7+3*256
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do2,
  0,
  isc_api::ibp_isc_sdl_long_integer,
  0x1,
  0x2,
  0x3,
  0xFF,
  isc_api::ibp_isc_sdl_long_integer,
  0x04,
  0x03,
  0x02,
  0x01,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  1,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__cstring2);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_text_props==(1+2*256));

 _TSO_CHECK(descr.m_element_sql_length==(7+3*256));

 _TSO_CHECK(descr.m_element_total_length==(7+3*256));

 _TSO_CHECK(descr.m_bounds_number==1);

 _TSO_CHECK(descr.m_bounds[0].lower==-16580095);
 _TSO_CHECK(descr.m_bounds[0].upper==16909060);
}//test_401__long_integer

////////////////////////////////////////////////////////////////////////////////
//TEST 501

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_501__short__scale_n2
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__short,
  (array_utils_type::byte_type)-2,//scale
  isc_api::ibp_isc_sdl_relation,
  1,
  'x',
  isc_api::ibp_isc_sdl_field,
  2,
  'y',
  'z',
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"x");

 _TSO_CHECK(descr.m_field_name==L"yz");

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__short);

 _TSO_CHECK(descr.m_element_sql_scale==-2);

 _TSO_CHECK(descr.m_element_sql_length==2);

 _TSO_CHECK(descr.m_element_total_length==2);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_501__short__scale_n2

////////////////////////////////////////////////////////////////////////////////
//TEST 502

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_502__long__scale_n5
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__long,
  (array_utils_type::byte_type)-5,//scale
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__long);

 _TSO_CHECK(descr.m_element_sql_scale==-5);

 _TSO_CHECK(descr.m_element_sql_length==4);

 _TSO_CHECK(descr.m_element_total_length==4);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_502__long__scale_n5

////////////////////////////////////////////////////////////////////////////////
//TEST 503

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_503__int64__scale_n12
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__int64,
  (array_utils_type::byte_type)-12,//scale
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__int64);

 _TSO_CHECK(descr.m_element_sql_scale==-12);

 _TSO_CHECK(descr.m_element_sql_length==8);

 _TSO_CHECK(descr.m_element_total_length==8);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_503__int64__scale_n12

////////////////////////////////////////////////////////////////////////////////
//TEST 504

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_504__float
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__float,
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__float);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_length==4);

 _TSO_CHECK(descr.m_element_total_length==4);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_504__float

////////////////////////////////////////////////////////////////////////////////
//TEST 505

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_505__double
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__double,
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__double);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_length==8);

 _TSO_CHECK(descr.m_element_total_length==8);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_505__double

////////////////////////////////////////////////////////////////////////////////
//TEST 506

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_506__time
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__sql_time,
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__sql_time);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_length==4);

 _TSO_CHECK(descr.m_element_total_length==4);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_506__time

////////////////////////////////////////////////////////////////////////////////
//TEST 507

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_507__date
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__sql_date,
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__sql_date);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_length==4);

 _TSO_CHECK(descr.m_element_total_length==4);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_507__date

////////////////////////////////////////////////////////////////////////////////
//TEST 508

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_508__timestamp
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__timestamp,
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__timestamp);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_length==8);

 _TSO_CHECK(descr.m_element_total_length==8);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_508__timestamp

////////////////////////////////////////////////////////////////////////////////
//TEST 509

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_509__text2__len1
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__text2,
  1,2, //charsetID: 1+2*256
  1,0, //sqllength: 1
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__text2);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_text_props==(1+2*256));

 _TSO_CHECK(descr.m_element_sql_length==1);

 _TSO_CHECK(descr.m_element_total_length==1);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_509__text2__len1

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_509__text2__len32767
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__text2,
  1,2, //charsetID: 1+2*256
  0xFF,0x7F, //sqllength: 32767
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__text2);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_text_props==(1+2*256));

 _TSO_CHECK(descr.m_element_sql_length==32767);

 _TSO_CHECK(descr.m_element_total_length==32767);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_509__text2__len32767

////////////////////////////////////////////////////////////////////////////////
//TEST 510

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_510__varying2__len1
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__varying2,
  1,2, //charsetID: 1+2*256
  1,0, //sqllength: 7+3*256
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__varying2);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_text_props==(1+2*256));

 _TSO_CHECK(descr.m_element_sql_length==1);

 _TSO_CHECK(descr.m_element_total_length==2+1);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_510__varying2__len1

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_510__varying2__len32765
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__varying2,
  1,2, //charsetID: 1+2*256
  0xFD,0x7F, //sqllength: 32765
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__varying2);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_text_props==(1+2*256));

 _TSO_CHECK(descr.m_element_sql_length==32765);

 _TSO_CHECK(descr.m_element_total_length==2+32765);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_510__varying2__len32765

////////////////////////////////////////////////////////////////////////////////
//TEST 511

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_511__cstring2__len1
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__cstring2,
  1,2, //charsetID: 1+2*256
  1,0, //sqllength: 1
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__cstring2);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_text_props==(1+2*256));

 _TSO_CHECK(descr.m_element_sql_length==1);

 _TSO_CHECK(descr.m_element_total_length==1);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_511__cstring2__len1

//------------------------------------------------------------------------
void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_511__cstring2__len32767
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_isc_blr_dtype__cstring2,
  1,2, //charsetID: 1+2*256
  0xFF,0x7F, //sqllength: 32767
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_isc_blr_dtype__cstring2);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_text_props==(1+2*256));

 _TSO_CHECK(descr.m_element_sql_length==32767);

 _TSO_CHECK(descr.m_element_total_length==32767);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_511__cstring2__len32767

////////////////////////////////////////////////////////////////////////////////
//TEST 512

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_512__boolean
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_fb030_blr_dtype__bool,
  isc_api::ibp_isc_sdl_relation,
  3,'a','B','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _LCPI_DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"aBc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_fb030_blr_dtype__bool);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_length==1);

 _TSO_CHECK(descr.m_element_total_length==1);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_512__boolean

////////////////////////////////////////////////////////////////////////////////
//TEST 513

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_513__int128__scale_n12
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_fb040_blr_dtype__int128,
  (array_utils_type::byte_type)-12,//scale
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_fb040_blr_dtype__int128);

 _TSO_CHECK(descr.m_element_sql_scale==-12);

 _TSO_CHECK(descr.m_element_sql_length==16);

 _TSO_CHECK(descr.m_element_total_length==16);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_513__int128__scale_n12

////////////////////////////////////////////////////////////////////////////////
//TEST 514

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_514__decfloat16
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_fb040_blr_dtype__decfloat16,
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_fb040_blr_dtype__decfloat16);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_length==8);

 _TSO_CHECK(descr.m_element_total_length==8);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_514__decfloat16

////////////////////////////////////////////////////////////////////////////////
//TEST 515

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_515__decfloat34
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_fb040_blr_dtype__decfloat34,
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_fb040_blr_dtype__decfloat34);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_length==16);

 _TSO_CHECK(descr.m_element_total_length==16);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_515__decfloat34

////////////////////////////////////////////////////////////////////////////////
//TEST 516

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::test_516__timestamp_with_tz
                                           (TTSO_GlobalContext* const pParams,
                                            context_type*       const pCtx)
{
 assert(pParams);
 assert(pCtx);

 TTSO_Tracer tracer(pCtx,L"test");

 const array_utils_type::byte_type sdl[]=
 {
  isc_api::ibp_isc_sdl_version1,
  isc_api::ibp_isc_sdl_struct,
  1,
  isc_api::ibp_fb040_blr_dtype__timestamp_with_tz,
  isc_api::ibp_isc_sdl_relation,
  3,'a','b','c',
  isc_api::ibp_isc_sdl_field,
  0,
  isc_api::ibp_isc_sdl_do1,
  0,
  isc_api::ibp_isc_sdl_tiny_integer,
  2,
  isc_api::ibp_isc_sdl_do2,
  1,
  isc_api::ibp_isc_sdl_tiny_integer,
  (array_utils_type::byte_type)-10,
  isc_api::ibp_isc_sdl_tiny_integer,
  10,
  isc_api::ibp_isc_sdl_element,
  1,
  isc_api::ibp_isc_sdl_scalar,
  0,
  2,                                        //count of dimensions
  isc_api::ibp_isc_sdl_variable,
  0,
  isc_api::ibp_isc_sdl_variable,
  1,
  isc_api::ibp_isc_sdl_eoc
 };

 TestCnParams params(pParams);

 TestOperationContext OpCtx(params);

 remote_fb::RemoteFB__ArraySliceDescr descr;

 array_utils_type::ParseSDL
  (OpCtx,
   _DIM_(sdl),
   sdl,
   &descr);

 //-----------------------------------------

 _TSO_CHECK(descr.m_relation_name==L"abc");

 _TSO_CHECK(descr.m_field_name.empty());

 _TSO_CHECK(descr.m_element_blr_typeid==isc_api::ibp_fb040_blr_dtype__timestamp_with_tz);

 _TSO_CHECK(descr.m_element_sql_scale==0);

 _TSO_CHECK(descr.m_element_sql_length==12);

 _TSO_CHECK(descr.m_element_total_length==12);

 _TSO_CHECK(descr.m_bounds_number==2);

 _TSO_CHECK(descr.m_bounds[0].lower==1);
 _TSO_CHECK(descr.m_bounds[0].upper==2);

 _TSO_CHECK(descr.m_bounds[1].lower==-10);
 _TSO_CHECK(descr.m_bounds[1].upper==10);
}//test_516__timestamp_with_tz

////////////////////////////////////////////////////////////////////////////////
//struct TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_descr

struct TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_descr
{
 public:
  typedef TTSO_TestFunc::TTestFunc          func_type;

 public:
  const char* pTestSign;
  func_type   Func;
};//class TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_descr

////////////////////////////////////////////////////////////////////////////////

#define DEF_TEST_DESCR(sign,func)                            \
 {sign,TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_impl::func},

const TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::tag_descr
 TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::sm_Tests[]=
{
#ifdef NDEBUG
 DEF_TEST_DESCR("001.err.empty_buffer",
                test_001__err__empty_buffer)
 DEF_TEST_DESCR("002.err.unk_version",
                test_002__err__unk_version)
 DEF_TEST_DESCR("003.err.check_point_004",
                test_003__err__check_point_004)
 DEF_TEST_DESCR("004.err.check_point_R01",
                test_004__err__check_point_R01)
 DEF_TEST_DESCR("005.err.check_point_R02",
                test_005__err__check_point_R02)
 DEF_TEST_DESCR("006.err.check_point_F01",
                test_006__err__check_point_F01)
 DEF_TEST_DESCR("007.err.check_point_F02",
                test_007__err__check_point_F02)
 DEF_TEST_DESCR("008.err.check_point_R00",
                test_008__err__check_point_R00)
 DEF_TEST_DESCR("009.err.check_point_F00",
                test_009__err__check_point_F00)
 DEF_TEST_DESCR("010.err.check_point_S01",
                test_010__err__check_point_S01)
 DEF_TEST_DESCR("011.err.check_point_S02",
                 test_011__err__check_point_S02)
 DEF_TEST_DESCR("012.err.check_point_S00",
                test_012__err__check_point_S00)

 DEF_TEST_DESCR("013.err.check_point_D101",
                test_013__err__check_point_D101)
 DEF_TEST_DESCR("014.err.check_point_D102",
                test_014__err__check_point_D102)
 DEF_TEST_DESCR("015.err.check_point_D103",
                test_015__err__check_point_D103)
 DEF_TEST_DESCR("016.err.check_point_D104",
                test_016__err__check_point_D104)

 DEF_TEST_DESCR("017.err.check_point_D201",
                test_017__err__check_point_D201)
 DEF_TEST_DESCR("018.err.check_point_D202",
                test_018__err__check_point_D202)
 DEF_TEST_DESCR("019.err.check_point_D203",
                test_019__err__check_point_D203)
 DEF_TEST_DESCR("020.err.check_point_D204",
                test_020__err__check_point_D204)

 DEF_TEST_DESCR("021.err.check_point_E00",
                test_021__err__check_point_E00)
 DEF_TEST_DESCR("022.err.check_point_X00",
                test_022__err__check_point_X00)
 DEF_TEST_DESCR("023.err.check_point_005",
                test_023__err__check_point_005)
 DEF_TEST_DESCR("024.err.check_point_006",
                test_024__err__check_point_006)
 DEF_TEST_DESCR("025.err.check_point_007",
                test_025__err__check_point_007)
 DEF_TEST_DESCR("026.err.check_point_008",
                test_026__err__check_point_008)
 DEF_TEST_DESCR("027.err.check_point_009",
                test_027__err__check_point_009)
 DEF_TEST_DESCR("028.err.check_point_010",
                test_028__err__check_point_010)

 DEF_TEST_DESCR("100.ReadLiteral.err.check_point_001",
                test_100__ReadLiteral__err__check_point_001)
 DEF_TEST_DESCR("101.ReadLiteral.err.check_point_002",
                test_101__ReadLiteral__err__check_point_002)
 DEF_TEST_DESCR("102.ReadLiteral.err.check_point_003",
                test_102__ReadLiteral__err__check_point_003)
 DEF_TEST_DESCR("103.ReadLiteral.err.check_point_004",
                test_103__ReadLiteral__err__check_point_004)
 DEF_TEST_DESCR("104.ReadLiteral.err.check_point_005",
                test_104__ReadLiteral__err__check_point_005)

 DEF_TEST_DESCR("200.ReadElement.err.check_point_001",
                test_200__ReadElement__err__check_point_001)
 DEF_TEST_DESCR("201.ReadElement.err.check_point_002",
                test_201__ReadElement__err__check_point_002)
 DEF_TEST_DESCR("202.ReadElement.err.check_point_003",
                test_202__ReadElement__err__check_point_003)
 DEF_TEST_DESCR("203.ReadElement.err.check_point_004",
                test_203__ReadElement__err__check_point_004)
 DEF_TEST_DESCR("204.ReadElement.err.check_point_005",
                test_204__ReadElement__err__check_point_005)
 DEF_TEST_DESCR("205.ReadElement.err.check_point_006",
                test_205__ReadElement__err__check_point_006)
 DEF_TEST_DESCR("206.ReadElement.err.check_point_007",
                test_206__ReadElement__err__check_point_007)
 DEF_TEST_DESCR("207.ReadElement.err.check_point_008",
                test_207__ReadElement__err__check_point_008)
 DEF_TEST_DESCR("208.ReadElement.err.check_point_009",
                test_208__ReadElement__err__check_point_009)
 DEF_TEST_DESCR("209.ReadElement.err.check_point_010",
                test_209__ReadElement__err__check_point_010)

 DEF_TEST_DESCR("300.ReadElementType.err.check_point_Z00",
                test_300__ReadElementType__err__check_point_Z00)
 DEF_TEST_DESCR("301.ReadElementType.err.check_point_001",
                test_301__ReadElementType__err__check_point_001)
 DEF_TEST_DESCR("302.ReadElementType.err.check_point_002",
                test_302__ReadElementType__err__check_point_002)
 DEF_TEST_DESCR("303.ReadElementType.err.check_point_003",
                test_303__ReadElementType__err__check_point_003)
 DEF_TEST_DESCR("304.ReadElementType.err.check_point_004",
                test_304__ReadElementType__err__check_point_004)
 DEF_TEST_DESCR("305.ReadElementType.err.check_point_005",
                test_305__ReadElementType__err__check_point_005)
 DEF_TEST_DESCR("306.ReadElementType.err.check_point_006",
                test_306__ReadElementType__err__check_point_006)
 DEF_TEST_DESCR("307.ReadElementType.err.check_point_007",
                test_307__ReadElementType__err__check_point_007)
 DEF_TEST_DESCR("308.ReadElementType.err.check_point_008",
                test_308__ReadElementType__err__check_point_008)
 DEF_TEST_DESCR("309.ReadElementType.err.check_point_009",
                test_309__ReadElementType__err__check_point_009)
 DEF_TEST_DESCR("310.ReadElementType.err.check_point_010",
                test_310__ReadElementType__err__check_point_010)
#endif
 DEF_TEST_DESCR("311.ReadElementType.err.check_point_L01.len0",
                test_311__ReadElementType__err__check_point_L01__len0)

 DEF_TEST_DESCR("312.ReadElementType.err.check_point_L01.len32768",
                test_312__ReadElementType__err__check_point_L01__len32768)

 DEF_TEST_DESCR("313.ReadElementType.err.check_point_L02.len0",
                test_313__ReadElementType__err__check_point_L02__len0)

 DEF_TEST_DESCR("314.ReadElementType.err.check_point_L02.len32766",
                test_314__ReadElementType__err__check_point_L02__len32766)

 DEF_TEST_DESCR("315.ReadElementType.err.check_point_L03.len0",
                test_315__ReadElementType__err__check_point_L03__len0)

 DEF_TEST_DESCR("316.ReadElementType.err.check_point_L03.len32768",
                test_316__ReadElementType__err__check_point_L03__len32768)
#ifdef NDEBUG
 DEF_TEST_DESCR("330.ReadElementType.err.check_point_011.int128",
                test_330__ReadElementType__err__check_point_011___int128)
#endif

 DEF_TEST_DESCR("400.short_integer",
                test_400__short_integer)

 DEF_TEST_DESCR("401.long_integer",
                test_401__long_integer)

 DEF_TEST_DESCR("501.short.scale_n2",
                test_501__short__scale_n2)

 DEF_TEST_DESCR("502.long.scale_n5",
                test_502__long__scale_n5)

 DEF_TEST_DESCR("503.int64.scale_n12",
                test_503__int64__scale_n12)

 DEF_TEST_DESCR("504.float",
                test_504__float)

 DEF_TEST_DESCR("505.double",
                test_505__double)

 DEF_TEST_DESCR("506.time",
                test_506__time)

 DEF_TEST_DESCR("507.date",
                test_507__date)

 DEF_TEST_DESCR("508.timestamp",
                test_508__timestamp)

 DEF_TEST_DESCR("509.text2.len1",
                test_509__text2__len1)

 DEF_TEST_DESCR("509.text2.len32767",
                test_509__text2__len32767)

 DEF_TEST_DESCR("510.varying2.len1",
                test_510__varying2__len1)

 DEF_TEST_DESCR("510.varying2.len32765",
                test_510__varying2__len32765)

 DEF_TEST_DESCR("511.cstring2.len1",
                test_511__cstring2__len1)

 DEF_TEST_DESCR("511.cstring2.len32767",
                test_511__cstring2__len32767)

 DEF_TEST_DESCR("512.boolean",
                test_512__boolean)

 DEF_TEST_DESCR("513.int128.scale_n12",
                test_513__int128__scale_n12)

 DEF_TEST_DESCR("514.decfloat16",
                test_514__decfloat16)

 DEF_TEST_DESCR("515.decfloat34",
                test_515__decfloat34)

 DEF_TEST_DESCR("516.timestamp_with_tz",
                test_516__timestamp_with_tz)
};//sm_Tests

#undef DEF_TEST_DESCR

////////////////////////////////////////////////////////////////////////////////
//class TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL

void TestsFor__RemoteFB__API_HLP__ArraySlice_V01__Utilities__ParseSDL::create
                                           (TTSO_PushTest*      const pTestPusher,
                                            TTSO_GlobalContext* const pParams)
{
 assert(pTestPusher!=nullptr);
 assert(pParams!=nullptr);

 structure::str_formatter
  ftestID("RemoteFB.API.HLP.ARRAY_SLICE_V01_Utilities.ParseSDL.%1");

 for(const tag_descr& d : sm_Tests)
 {
  ftestID
   <<structure::flush
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
