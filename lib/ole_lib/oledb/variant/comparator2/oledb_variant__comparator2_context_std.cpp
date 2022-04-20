////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/variant/comparator2/oledb_variant__comparator2_context_std.h>

#include <ole_lib/oledb/variant/comparator2/impl/simple/i1/oledb_variant_cmp2__i1.h>
#include <ole_lib/oledb/variant/comparator2/impl/simple/i2/oledb_variant_cmp2__i2.h>
#include <ole_lib/oledb/variant/comparator2/impl/simple/i4/oledb_variant_cmp2__i4.h>
#include <ole_lib/oledb/variant/comparator2/impl/simple/i8/oledb_variant_cmp2__i8.h>

#include <ole_lib/oledb/variant/comparator2/impl/simple/ui1/oledb_variant_cmp2__ui1.h>
#include <ole_lib/oledb/variant/comparator2/impl/simple/ui2/oledb_variant_cmp2__ui2.h>
#include <ole_lib/oledb/variant/comparator2/impl/simple/ui4/oledb_variant_cmp2__ui4.h>
#include <ole_lib/oledb/variant/comparator2/impl/simple/ui8/oledb_variant_cmp2__ui8.h>

#include <ole_lib/oledb/variant/comparator2/impl/simple/r4/oledb_variant_cmp2__r4.h>
#include <ole_lib/oledb/variant/comparator2/impl/simple/r8/oledb_variant_cmp2__r8.h>

#include <ole_lib/oledb/variant/comparator2/impl/simple/numeric/oledb_variant_cmp2__numeric.h>
#include <ole_lib/oledb/variant/comparator2/impl/simple/decimal/oledb_variant_cmp2__decimal.h>

#include <ole_lib/oledb/variant/comparator2/impl/simple/cy/oledb_variant_cmp2__cy.h>

#include <ole_lib/oledb/variant/comparator2/impl/simple/bstr/oledb_variant_cmp2__bstr.h>
#include <ole_lib/oledb/variant/comparator2/impl/simple/wstr/oledb_variant_cmp2__wstr.h>
#include <ole_lib/oledb/variant/comparator2/impl/simple/str/oledb_variant_cmp2__str.h>
#include <ole_lib/oledb/variant/comparator2/impl/simple/bytes/oledb_variant_cmp2__bytes.h>

#include <ole_lib/oledb/variant/comparator2/impl/simple/bool/oledb_variant_cmp2__bool.h>

#include <ole_lib/oledb/variant/comparator2/impl/simple/guid/oledb_variant_cmp2__guid.h>

#include <ole_lib/oledb/variant/comparator2/impl/simple/date/oledb_variant_cmp2__date.h>

#include <ole_lib/oledb/variant/comparator2/impl/simple/dbdate/oledb_variant_cmp2__dbdate.h>
#include <ole_lib/oledb/variant/comparator2/impl/simple/dbtime/oledb_variant_cmp2__dbtime.h>
#include <ole_lib/oledb/variant/comparator2/impl/simple/dbtime2/oledb_variant_cmp2__dbtime2.h>
#include <ole_lib/oledb/variant/comparator2/impl/simple/dbtimestamp/oledb_variant_cmp2__dbtimestamp.h>
#include <ole_lib/oledb/variant/comparator2/impl/simple/filetime/oledb_variant_cmp2__filetime.h>

#include <ole_lib/oledb/variant/comparator2/impl/simple/variant/oledb_variant_cmp2__variant.h>

#include <ole_lib/oledb/variant/comparator2/impl/simple/null/oledb_variant_cmp2__null.h>

#include <ole_lib/oledb/variant/comparator2/impl/array/i1/oledb_variant_cmp2__array_i1.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/i2/oledb_variant_cmp2__array_i2.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/i4/oledb_variant_cmp2__array_i4.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/i8/oledb_variant_cmp2__array_i8.h>

#include <ole_lib/oledb/variant/comparator2/impl/array/ui1/oledb_variant_cmp2__array_ui1.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/ui2/oledb_variant_cmp2__array_ui2.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/ui4/oledb_variant_cmp2__array_ui4.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/ui8/oledb_variant_cmp2__array_ui8.h>

#include <ole_lib/oledb/variant/comparator2/impl/array/r4/oledb_variant_cmp2__array_r4.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/r8/oledb_variant_cmp2__array_r8.h>

#include <ole_lib/oledb/variant/comparator2/impl/array/cy/oledb_variant_cmp2__array_cy.h>

#include <ole_lib/oledb/variant/comparator2/impl/array/decimal/oledb_variant_cmp2__array_decimal.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/numeric/oledb_variant_cmp2__array_numeric.h>

#include <ole_lib/oledb/variant/comparator2/impl/array/date/oledb_variant_cmp2__array_date.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/filetime/oledb_variant_cmp2__array_filetime.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/dbdate/oledb_variant_cmp2__array_dbdate.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/dbtime/oledb_variant_cmp2__array_dbtime.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/dbtimestamp/oledb_variant_cmp2__array_dbtimestamp.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/dbtime2/oledb_variant_cmp2__array_dbtime2.h>

#include <ole_lib/oledb/variant/comparator2/impl/array/bool/oledb_variant_cmp2__array_bool.h>

#include <ole_lib/oledb/variant/comparator2/impl/array/guid/oledb_variant_cmp2__array_guid.h>

#include <ole_lib/oledb/variant/comparator2/impl/array/bstr/oledb_variant_cmp2__array_bstr.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/bytes/oledb_variant_cmp2__array_bytes.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/str/oledb_variant_cmp2__array_str.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/wstr/oledb_variant_cmp2__array_wstr.h>

#include <ole_lib/oledb/variant/comparator2/impl/array/variant/oledb_variant_cmp2__array_variant.h>

#include <ole_lib/oledb/variant/comparator2/impl/array/error/oledb_variant_cmp2__array_error.h>

#include <ole_lib/oledb/variant/comparator2/impl/array/iunknown/oledb_variant_cmp2__array_iunknown.h>
#include <ole_lib/oledb/variant/comparator2/impl/array/idispatch/oledb_variant_cmp2__array_idispatch.h>

#ifndef OLEDB_VARIANT_COMPARATOR2_OWN_CPP

#include <ole_lib/oledb/variant/comparator2/impl/common/oledb_variant_cmp2__common.h>

#include <ole_lib/oledb/variant/comparator2/utils/oledb_variant_cmp2__utils.h>

#include <ole_lib/oledb/variant/oledb_variant_compare2.h>

#include <ole_lib/oledb/variant/oledb_variant_cvt_utils.h>

#include <ole_lib/oledb/oledb_datetime_services.h>

#endif

namespace oledb_lib{namespace variant_comparator2{
////////////////////////////////////////////////////////////////////////////////

#ifndef OLEDB_VARIANT_COMPARATOR2_OWN_CPP

namespace impl{
////////////////////////////////////////////////////////////////////////////////

#include <ole_lib/oledb/variant/comparator2/impl/common/oledb_variant_cmp2__common.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/bool/oledb_variant_cmp2__bool.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/date/oledb_variant_cmp2__date.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/dbdate/oledb_variant_cmp2__dbdate.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/dbtime/oledb_variant_cmp2__dbtime.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/dbtime2/oledb_variant_cmp2__dbtime2.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/dbtimestamp/oledb_variant_cmp2__dbtimestamp.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/filetime/oledb_variant_cmp2__filetime.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/guid/oledb_variant_cmp2__guid.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/i1/oledb_variant_cmp2__i1.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/i2/oledb_variant_cmp2__i2.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/i4/oledb_variant_cmp2__i4.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/i8/oledb_variant_cmp2__i8.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/ui1/oledb_variant_cmp2__ui1.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/ui2/oledb_variant_cmp2__ui2.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/ui4/oledb_variant_cmp2__ui4.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/ui8/oledb_variant_cmp2__ui8.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/r4/oledb_variant_cmp2__r4.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/r8/oledb_variant_cmp2__r8.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/numeric/oledb_variant_cmp2__numeric.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/decimal/oledb_variant_cmp2__decimal.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/cy/oledb_variant_cmp2__cy.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/bstr/oledb_variant_cmp2__bstr.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/wstr/oledb_variant_cmp2__wstr.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/str/oledb_variant_cmp2__str.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/bytes/oledb_variant_cmp2__bytes.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/variant/oledb_variant_cmp2__variant.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/null/oledb_variant_cmp2__null.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/array/i1/oledb_variant_cmp2__array_i1.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/i2/oledb_variant_cmp2__array_i2.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/i4/oledb_variant_cmp2__array_i4.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/i8/oledb_variant_cmp2__array_i8.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/array/ui1/oledb_variant_cmp2__array_ui1.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/ui2/oledb_variant_cmp2__array_ui2.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/ui4/oledb_variant_cmp2__array_ui4.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/ui8/oledb_variant_cmp2__array_ui8.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/array/r4/oledb_variant_cmp2__array_r4.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/r8/oledb_variant_cmp2__array_r8.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/array/cy/oledb_variant_cmp2__array_cy.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/array/decimal/oledb_variant_cmp2__array_decimal.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/numeric/oledb_variant_cmp2__array_numeric.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/array/date/oledb_variant_cmp2__array_date.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/filetime/oledb_variant_cmp2__array_filetime.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/dbdate/oledb_variant_cmp2__array_dbdate.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/dbtime/oledb_variant_cmp2__array_dbtime.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/dbtimestamp/oledb_variant_cmp2__array_dbtimestamp.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/dbtime2/oledb_variant_cmp2__array_dbtime2.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/array/bool/oledb_variant_cmp2__array_bool.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/guid/oledb_variant_cmp2__array_guid.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/array/bstr/oledb_variant_cmp2__array_bstr.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/bytes/oledb_variant_cmp2__array_bytes.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/str/oledb_variant_cmp2__array_str.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/wstr/oledb_variant_cmp2__array_wstr.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/array/variant/oledb_variant_cmp2__array_variant.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/array/error/oledb_variant_cmp2__array_error.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/array/iunknown/oledb_variant_cmp2__array_iunknown.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/array/idispatch/oledb_variant_cmp2__array_idispatch.cxx>

////////////////////////////////////////////////////////////////////////////////
}//namespace impl

#endif //OLEDB_VARIANT_COMPARATOR2_OWN_CPP

////////////////////////////////////////////////////////////////////////////////
//class TDBVariantComparator2_Context_STD::tag_helpers

class TDBVariantComparator2_Context_STD::tag_helpers
{
 public:
  template<const TDBVariantComparator2_Descr1& rSimple>
  static pcomparator_type GetCompWith_generic_s(DBTYPE dbtype2);

  template<const TDBVariantComparator2_Descr1& rSimple,const TDBVariantComparator2_Descr1& rArray>
  static pcomparator_type GetCompWith_generic_sa(DBTYPE dbtype2);
};//TDBVariantComparator2_Context_STD::tag_helpers

////////////////////////////////////////////////////////////////////////////////
//class TDBVariantComparator2_Context_STD::tag_helpers

template<const TDBVariantComparator2_Descr1& rSimple>
TDBVariantComparator2_Context_STD::pcomparator_type
 TDBVariantComparator2_Context_STD::tag_helpers::GetCompWith_generic_s(DBTYPE const dbtype2)
{
 const_cast<const unsigned short*>(&dbtype2);

 if(dbtype2<rSimple.cDescrs2)
  return rSimple.pDescrs2[dbtype2].ptr;

 return nullptr;
}//GetCompWith_generic_s

//------------------------------------------------------------------------
template<const TDBVariantComparator2_Descr1& rSimple,const TDBVariantComparator2_Descr1& rArray>
TDBVariantComparator2_Context_STD::pcomparator_type
 TDBVariantComparator2_Context_STD::tag_helpers::GetCompWith_generic_sa(DBTYPE const dbtype2)
{
 const_cast<const unsigned short*>(&dbtype2);

 if(dbtype2<rSimple.cDescrs2)
  return rSimple.pDescrs2[dbtype2].ptr;

 if((dbtype2&DBTYPE_ARRAY)==DBTYPE_ARRAY)
 {
  const DBTYPE i=(dbtype2&~DBTYPE_ARRAY);

  if(i<rArray.cDescrs2)
   return rArray.pDescrs2[i].ptr;
 }//if

 return nullptr;
}//GetCompWith_generic_sa

////////////////////////////////////////////////////////////////////////////////
//class TDBVariantComparator2_Context_STD::tag_get_descr

class TDBVariantComparator2_Context_STD::tag_get_descr
{
 public: //typedefs ------------------------------------------------------
  typedef pcomparator_type (*pfn_GetCompWith)(DBTYPE dbtype2);

 public:
  pfn_GetCompWith func;

 #ifndef NDEBUG
  DBTYPE          dbtype1;
 #endif

 public:
 #ifdef NDEBUG
  tag_get_descr(pfn_GetCompWith const _func)
   :func(_func)
  {;}
 #else
  tag_get_descr(pfn_GetCompWith const _func,
                DBTYPE          const _dbtype1)
   :func(_func)
   ,dbtype1(_dbtype1)
  {;}
 #endif
};//class TDBVariantComparator2_Context_STD::tag_get_descr

////////////////////////////////////////////////////////////////////////////////
//class TDBVariantComparator2_Context_STD::tag_data

class TDBVariantComparator2_Context_STD::tag_data
{
 public:
  static const tag_get_descr sm_Simple[];
  static const tag_get_descr sm_Array[];

 private:
#ifndef NDEBUG
  static const tag_data sm_Instance;

  tag_data();

  static void debug__Check_sm_Simple();

  static void debug__Check_sm_Array();
#endif
};//class TDBVariantComparator2_Context_STD::tag_data

////////////////////////////////////////////////////////////////////////////////
//TDBVariantComparator2_Context_STD::tag_data::sm_Simple

#define DEF_GET_NONE()                                                    \
 TDBVariantComparator2_Context_STD::tag_get_descr                         \
  (nullptr                                                                \
   _DEBUG_ARG(0))

#define DEF_GET_DESCR_S(dbtype1)                                          \
 TDBVariantComparator2_Context_STD::tag_get_descr                         \
  (TDBVariantComparator2_Context_STD::tag_helpers::GetCompWith_generic_s  \
     <impl::g_DBVariantComparator2_Descr1__##dbtype1##__Simple>           \
   _DEBUG_ARG(oledb_typeid__##dbtype1))

#define DEF_GET_DESCR_SA(dbtype1)                                         \
 TDBVariantComparator2_Context_STD::tag_get_descr                         \
  (TDBVariantComparator2_Context_STD::tag_helpers::GetCompWith_generic_sa \
     <impl::g_DBVariantComparator2_Descr1__##dbtype1##__Simple,           \
      impl::g_DBVariantComparator2_Descr1__##dbtype1##__Array>            \
   _DEBUG_ARG(oledb_typeid__##dbtype1))

//------------------------------------------------------------------------
const TDBVariantComparator2_Context_STD::tag_get_descr
 TDBVariantComparator2_Context_STD::tag_data::sm_Simple[]=
{
 /*  0*/ DEF_GET_NONE    (),
 /*  1*/ DEF_GET_DESCR_SA(NULL),
 /*  2*/ DEF_GET_DESCR_S (I2),
 /*  3*/ DEF_GET_DESCR_S (I4),
 /*  4*/ DEF_GET_DESCR_S (R4),
 /*  5*/ DEF_GET_DESCR_S (R8),
 /*  6*/ DEF_GET_DESCR_S (CY),
 /*  7*/ DEF_GET_DESCR_S (DATE),
 /*  8*/ DEF_GET_DESCR_S (BSTR),
 /*  9*/ DEF_GET_NONE    (),
 /* 10*/ DEF_GET_NONE    (),
 /* 11*/ DEF_GET_DESCR_S (BOOL),
 /* 12*/ DEF_GET_DESCR_SA(VARIANT),
 /* 13*/ DEF_GET_NONE    (),
 /* 14*/ DEF_GET_DESCR_S (DECIMAL),
 /* 15*/ DEF_GET_NONE    (),
 /* 16*/ DEF_GET_DESCR_S (I1),
 /* 17*/ DEF_GET_DESCR_S (UI1),
 /* 18*/ DEF_GET_DESCR_S (UI2),
 /* 19*/ DEF_GET_DESCR_S (UI4),
 /* 20*/ DEF_GET_DESCR_S (I8),
 /* 21*/ DEF_GET_DESCR_S (UI8),
 /* 22*/ DEF_GET_NONE    (),
 /* 23*/ DEF_GET_NONE    (),
 /* 24*/ DEF_GET_NONE    (),
 /* 25*/ DEF_GET_NONE    (),
 /* 26*/ DEF_GET_NONE    (),
 /* 27*/ DEF_GET_NONE    (),
 /* 28*/ DEF_GET_NONE    (),
 /* 29*/ DEF_GET_NONE    (),
 /* 30*/ DEF_GET_NONE    (),
 /* 31*/ DEF_GET_NONE    (),
 /* 32*/ DEF_GET_NONE    (),
 /* 33*/ DEF_GET_NONE    (),
 /* 34*/ DEF_GET_NONE    (),
 /* 35*/ DEF_GET_NONE    (),
 /* 36*/ DEF_GET_NONE    (),
 /* 37*/ DEF_GET_NONE    (),
 /* 38*/ DEF_GET_NONE    (),
 /* 39*/ DEF_GET_NONE    (),
 /* 40*/ DEF_GET_NONE    (),
 /* 41*/ DEF_GET_NONE    (),
 /* 42*/ DEF_GET_NONE    (),
 /* 43*/ DEF_GET_NONE    (),
 /* 44*/ DEF_GET_NONE    (),
 /* 45*/ DEF_GET_NONE    (),
 /* 46*/ DEF_GET_NONE    (),
 /* 47*/ DEF_GET_NONE    (),
 /* 48*/ DEF_GET_NONE    (),
 /* 49*/ DEF_GET_NONE    (),
 /* 50*/ DEF_GET_NONE    (),
 /* 51*/ DEF_GET_NONE    (),
 /* 52*/ DEF_GET_NONE    (),
 /* 53*/ DEF_GET_NONE    (),
 /* 54*/ DEF_GET_NONE    (),
 /* 55*/ DEF_GET_NONE    (),
 /* 56*/ DEF_GET_NONE    (),
 /* 57*/ DEF_GET_NONE    (),
 /* 58*/ DEF_GET_NONE    (),
 /* 59*/ DEF_GET_NONE    (),
 /* 60*/ DEF_GET_NONE    (),
 /* 61*/ DEF_GET_NONE    (),
 /* 62*/ DEF_GET_NONE    (),
 /* 63*/ DEF_GET_NONE    (),
 /* 64*/ DEF_GET_DESCR_S (FILETIME),
 /* 65*/ DEF_GET_NONE    (),
 /* 66*/ DEF_GET_NONE    (),
 /* 67*/ DEF_GET_NONE    (),
 /* 68*/ DEF_GET_NONE    (),
 /* 69*/ DEF_GET_NONE    (),
 /* 70*/ DEF_GET_NONE    (),
 /* 71*/ DEF_GET_NONE    (),
 /* 72*/ DEF_GET_DESCR_S (GUID),
 /* 73*/ DEF_GET_NONE    (),
 /* 74*/ DEF_GET_NONE    (),
 /* 75*/ DEF_GET_NONE    (),
 /* 76*/ DEF_GET_NONE    (),
 /* 77*/ DEF_GET_NONE    (),
 /* 78*/ DEF_GET_NONE    (),
 /* 79*/ DEF_GET_NONE    (),
 /* 80*/ DEF_GET_NONE    (),
 /* 81*/ DEF_GET_NONE    (),
 /* 82*/ DEF_GET_NONE    (),
 /* 83*/ DEF_GET_NONE    (),
 /* 84*/ DEF_GET_NONE    (),
 /* 85*/ DEF_GET_NONE    (),
 /* 86*/ DEF_GET_NONE    (),
 /* 87*/ DEF_GET_NONE    (),
 /* 88*/ DEF_GET_NONE    (),
 /* 89*/ DEF_GET_NONE    (),
 /* 90*/ DEF_GET_NONE    (),
 /* 91*/ DEF_GET_NONE    (),
 /* 92*/ DEF_GET_NONE    (),
 /* 93*/ DEF_GET_NONE    (),
 /* 94*/ DEF_GET_NONE    (),
 /* 95*/ DEF_GET_NONE    (),
 /* 96*/ DEF_GET_NONE    (),
 /* 97*/ DEF_GET_NONE    (),
 /* 98*/ DEF_GET_NONE    (),
 /* 99*/ DEF_GET_NONE    (),
 /*100*/ DEF_GET_NONE    (),
 /*101*/ DEF_GET_NONE    (),
 /*102*/ DEF_GET_NONE    (),
 /*103*/ DEF_GET_NONE    (),
 /*104*/ DEF_GET_NONE    (),
 /*105*/ DEF_GET_NONE    (),
 /*106*/ DEF_GET_NONE    (),
 /*107*/ DEF_GET_NONE    (),
 /*108*/ DEF_GET_NONE    (),
 /*109*/ DEF_GET_NONE    (),
 /*110*/ DEF_GET_NONE    (),
 /*111*/ DEF_GET_NONE    (),
 /*112*/ DEF_GET_NONE    (),
 /*113*/ DEF_GET_NONE    (),
 /*114*/ DEF_GET_NONE    (),
 /*115*/ DEF_GET_NONE    (),
 /*116*/ DEF_GET_NONE    (),
 /*117*/ DEF_GET_NONE    (),
 /*118*/ DEF_GET_NONE    (),
 /*119*/ DEF_GET_NONE    (),
 /*120*/ DEF_GET_NONE    (),
 /*121*/ DEF_GET_NONE    (),
 /*122*/ DEF_GET_NONE    (),
 /*123*/ DEF_GET_NONE    (),
 /*124*/ DEF_GET_NONE    (),
 /*125*/ DEF_GET_NONE    (),
 /*126*/ DEF_GET_NONE    (),
 /*127*/ DEF_GET_NONE    (),
 /*128*/ DEF_GET_DESCR_S (BYTES),
 /*129*/ DEF_GET_DESCR_S (STR),
 /*130*/ DEF_GET_DESCR_S (WSTR),
 /*131*/ DEF_GET_DESCR_S (NUMERIC),
 /*132*/ DEF_GET_NONE    (),
 /*133*/ DEF_GET_DESCR_S (DBDATE),
 /*134*/ DEF_GET_DESCR_S (DBTIME),
 /*135*/ DEF_GET_DESCR_S (DBTIMESTAMP),
 /*136*/ DEF_GET_NONE    (),
 /*137*/ DEF_GET_NONE    (),
 /*138*/ DEF_GET_NONE    (),
 /*139*/ DEF_GET_NONE    (),
 /*140*/ DEF_GET_NONE    (),
 /*141*/ DEF_GET_NONE    (),
 /*142*/ DEF_GET_NONE    (),
 /*143*/ DEF_GET_NONE    (),
 /*144*/ DEF_GET_NONE    (),
 /*145*/ DEF_GET_DESCR_S (DBTIME2),
};//sm_Simple

//------------------------------------------------------------------------
#undef DEF_GET_DESCR_S
#undef DEF_GET_NONE

////////////////////////////////////////////////////////////////////////////////
//TDBVariantComparator2_Context_STD::tag_data::sm_Simple

#define DEF_GET_NONE()                                                    \
 TDBVariantComparator2_Context_STD::tag_get_descr                         \
  (nullptr                                                                \
   _DEBUG_ARG(0))

#define DEF_GET_DESCR_S(dbtype1)                                          \
 TDBVariantComparator2_Context_STD::tag_get_descr                         \
  (TDBVariantComparator2_Context_STD::tag_helpers::GetCompWith_generic_s  \
     <impl::g_DBVariantComparator2_Descr1__ARRAY_##dbtype1##__Simple>     \
   _DEBUG_ARG(oledb_typeid__ARRAY|oledb_typeid__##dbtype1))

//------------------------------------------------------------------------
const TDBVariantComparator2_Context_STD::tag_get_descr
 TDBVariantComparator2_Context_STD::tag_data::sm_Array[]=
{
 /*  0*/ DEF_GET_NONE   (),
 /*  1*/ DEF_GET_NONE   (),
 /*  2*/ DEF_GET_DESCR_S(I2),
 /*  3*/ DEF_GET_DESCR_S(I4),
 /*  4*/ DEF_GET_DESCR_S(R4),
 /*  5*/ DEF_GET_DESCR_S(R8),
 /*  6*/ DEF_GET_DESCR_S(CY),
 /*  7*/ DEF_GET_DESCR_S(DATE),
 /*  8*/ DEF_GET_DESCR_S(BSTR),
 /*  9*/ DEF_GET_DESCR_S(IDISPATCH),
 /* 10*/ DEF_GET_DESCR_S(ERROR),
 /* 11*/ DEF_GET_DESCR_S(BOOL),
 /* 12*/ DEF_GET_DESCR_S(VARIANT),
 /* 13*/ DEF_GET_DESCR_S(IUNKNOWN),
 /* 14*/ DEF_GET_DESCR_S(DECIMAL),
 /* 15*/ DEF_GET_NONE   (),
 /* 16*/ DEF_GET_DESCR_S(I1),
 /* 17*/ DEF_GET_DESCR_S(UI1),
 /* 18*/ DEF_GET_DESCR_S(UI2),
 /* 19*/ DEF_GET_DESCR_S(UI4),
 /* 20*/ DEF_GET_DESCR_S(I8),
 /* 21*/ DEF_GET_DESCR_S(UI8),
 /* 22*/ DEF_GET_NONE   (),
 /* 23*/ DEF_GET_NONE   (),
 /* 24*/ DEF_GET_NONE   (),
 /* 25*/ DEF_GET_NONE   (),
 /* 26*/ DEF_GET_NONE   (),
 /* 27*/ DEF_GET_NONE   (),
 /* 28*/ DEF_GET_NONE   (),
 /* 29*/ DEF_GET_NONE   (),
 /* 30*/ DEF_GET_NONE   (),
 /* 31*/ DEF_GET_NONE   (),
 /* 32*/ DEF_GET_NONE   (),
 /* 33*/ DEF_GET_NONE   (),
 /* 34*/ DEF_GET_NONE   (),
 /* 35*/ DEF_GET_NONE   (),
 /* 36*/ DEF_GET_NONE   (),
 /* 37*/ DEF_GET_NONE   (),
 /* 38*/ DEF_GET_NONE   (),
 /* 39*/ DEF_GET_NONE   (),
 /* 40*/ DEF_GET_NONE   (),
 /* 41*/ DEF_GET_NONE   (),
 /* 42*/ DEF_GET_NONE   (),
 /* 43*/ DEF_GET_NONE   (),
 /* 44*/ DEF_GET_NONE   (),
 /* 45*/ DEF_GET_NONE   (),
 /* 46*/ DEF_GET_NONE   (),
 /* 47*/ DEF_GET_NONE   (),
 /* 48*/ DEF_GET_NONE   (),
 /* 49*/ DEF_GET_NONE   (),
 /* 50*/ DEF_GET_NONE   (),
 /* 51*/ DEF_GET_NONE   (),
 /* 52*/ DEF_GET_NONE   (),
 /* 53*/ DEF_GET_NONE   (),
 /* 54*/ DEF_GET_NONE   (),
 /* 55*/ DEF_GET_NONE   (),
 /* 56*/ DEF_GET_NONE   (),
 /* 57*/ DEF_GET_NONE   (),
 /* 58*/ DEF_GET_NONE   (),
 /* 59*/ DEF_GET_NONE   (),
 /* 60*/ DEF_GET_NONE   (),
 /* 61*/ DEF_GET_NONE   (),
 /* 62*/ DEF_GET_NONE   (),
 /* 63*/ DEF_GET_NONE   (),
 /* 64*/ DEF_GET_DESCR_S(FILETIME),
 /* 65*/ DEF_GET_NONE   (),
 /* 66*/ DEF_GET_NONE   (),
 /* 67*/ DEF_GET_NONE   (),
 /* 68*/ DEF_GET_NONE   (),
 /* 69*/ DEF_GET_NONE   (),
 /* 70*/ DEF_GET_NONE   (),
 /* 71*/ DEF_GET_NONE   (),
 /* 72*/ DEF_GET_DESCR_S(GUID),
 /* 73*/ DEF_GET_NONE   (),
 /* 74*/ DEF_GET_NONE   (),
 /* 75*/ DEF_GET_NONE   (),
 /* 76*/ DEF_GET_NONE   (),
 /* 77*/ DEF_GET_NONE   (),
 /* 78*/ DEF_GET_NONE   (),
 /* 79*/ DEF_GET_NONE   (),
 /* 80*/ DEF_GET_NONE   (),
 /* 81*/ DEF_GET_NONE   (),
 /* 82*/ DEF_GET_NONE   (),
 /* 83*/ DEF_GET_NONE   (),
 /* 84*/ DEF_GET_NONE   (),
 /* 85*/ DEF_GET_NONE   (),
 /* 86*/ DEF_GET_NONE   (),
 /* 87*/ DEF_GET_NONE   (),
 /* 88*/ DEF_GET_NONE   (),
 /* 89*/ DEF_GET_NONE   (),
 /* 90*/ DEF_GET_NONE   (),
 /* 91*/ DEF_GET_NONE   (),
 /* 92*/ DEF_GET_NONE   (),
 /* 93*/ DEF_GET_NONE   (),
 /* 94*/ DEF_GET_NONE   (),
 /* 95*/ DEF_GET_NONE   (),
 /* 96*/ DEF_GET_NONE   (),
 /* 97*/ DEF_GET_NONE   (),
 /* 98*/ DEF_GET_NONE   (),
 /* 99*/ DEF_GET_NONE   (),
 /*100*/ DEF_GET_NONE   (),
 /*101*/ DEF_GET_NONE   (),
 /*102*/ DEF_GET_NONE   (),
 /*103*/ DEF_GET_NONE   (),
 /*104*/ DEF_GET_NONE   (),
 /*105*/ DEF_GET_NONE   (),
 /*106*/ DEF_GET_NONE   (),
 /*107*/ DEF_GET_NONE   (),
 /*108*/ DEF_GET_NONE   (),
 /*109*/ DEF_GET_NONE   (),
 /*110*/ DEF_GET_NONE   (),
 /*111*/ DEF_GET_NONE   (),
 /*112*/ DEF_GET_NONE   (),
 /*113*/ DEF_GET_NONE   (),
 /*114*/ DEF_GET_NONE   (),
 /*115*/ DEF_GET_NONE   (),
 /*116*/ DEF_GET_NONE   (),
 /*117*/ DEF_GET_NONE   (),
 /*118*/ DEF_GET_NONE   (),
 /*119*/ DEF_GET_NONE   (),
 /*120*/ DEF_GET_NONE   (),
 /*121*/ DEF_GET_NONE   (),
 /*122*/ DEF_GET_NONE   (),
 /*123*/ DEF_GET_NONE   (),
 /*124*/ DEF_GET_NONE   (),
 /*125*/ DEF_GET_NONE   (),
 /*126*/ DEF_GET_NONE   (),
 /*127*/ DEF_GET_NONE   (),
 /*128*/ DEF_GET_DESCR_S(BYTES),
 /*129*/ DEF_GET_DESCR_S(STR),
 /*130*/ DEF_GET_DESCR_S(WSTR),
 /*131*/ DEF_GET_DESCR_S(NUMERIC),
 /*132*/ DEF_GET_NONE   (),
 /*133*/ DEF_GET_DESCR_S(DBDATE),
 /*134*/ DEF_GET_DESCR_S(DBTIME),
 /*135*/ DEF_GET_DESCR_S(DBTIMESTAMP),
 /*136*/ DEF_GET_NONE   (),
 /*137*/ DEF_GET_NONE   (),
 /*138*/ DEF_GET_NONE   (),
 /*139*/ DEF_GET_NONE   (),
 /*140*/ DEF_GET_NONE   (),
 /*141*/ DEF_GET_NONE   (),
 /*142*/ DEF_GET_NONE   (),
 /*143*/ DEF_GET_NONE   (),
 /*144*/ DEF_GET_NONE   (),
 /*145*/ DEF_GET_DESCR_S(DBTIME2),
};//sm_Array

//------------------------------------------------------------------------
#undef DEF_GET_DESCR_S
#undef DEF_GET_NONE

////////////////////////////////////////////////////////////////////////////////
//class TDBVariantComparator2_Context_STD::tag_data::

#ifndef NDEBUG

const TDBVariantComparator2_Context_STD::tag_data
 TDBVariantComparator2_Context_STD::tag_data::sm_Instance;

//------------------------------------------------------------------------
TDBVariantComparator2_Context_STD::tag_data::tag_data()
{
 debug__Check_sm_Simple();
 debug__Check_sm_Array();
}//tag_data

//------------------------------------------------------------------------
void TDBVariantComparator2_Context_STD::tag_data::debug__Check_sm_Simple()
{
 for(size_t i=0;i!=_DIM_(sm_Simple);++i)
 {
  if(!sm_Simple[i].func)
   continue;

  assert(size_t(sm_Simple[i].dbtype1)==i);
 }//for i
}//debug__Check_sm_Simple

//------------------------------------------------------------------------
void TDBVariantComparator2_Context_STD::tag_data::debug__Check_sm_Array()
{
 for(size_t i=0;i!=_DIM_(sm_Array);++i)
 {
  if(!sm_Array[i].func)
   continue;

  assert(size_t(sm_Array[i].dbtype1)==DBTYPE(oledb_typeid__ARRAY|i));
 }//for i
}//debug__Check_sm_Array

#endif // !NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class TDBVariantComparator2_Context_STD

TDBVariantComparator2_Context_STD::TDBVariantComparator2_Context_STD()
{
}//TDBVariantComparator2_Context_STD

//------------------------------------------------------------------------
TDBVariantComparator2_Context_STD::TDBVariantComparator2_Context_STD(const TDBVariantCompare2_Settings& Settings)
 :m_Settings(Settings)
{
}//TDBVariantComparator2_Context_STD

//------------------------------------------------------------------------
TDBVariantComparator2_Context_STD::~TDBVariantComparator2_Context_STD()
{
}//~TDBVariantComparator2_Context_STD

//interface --------------------------------------------------------------
const TDBVariantCompare2_Settings&
 TDBVariantComparator2_Context_STD::GetSettings()const
{
 return m_Settings;
}//GetSettings

//------------------------------------------------------------------------
const TDBVariantComparator2*
 TDBVariantComparator2_Context_STD::GetComparator(DBTYPE const dbtype1,
                                                  DBTYPE const dbtype2)
{
 return self_type::Helper__Get_Comparator(dbtype1,dbtype2);
}//GetComparator

//helper methods ---------------------------------------------------------

TDBVariantComparator2_Context_STD::pcomparator_type
 TDBVariantComparator2_Context_STD::Helper__Get_Comparator(DBTYPE const dbtype1,
                                                           DBTYPE const dbtype2)
{
 if(pfn_GetCompWith const pfn=Helper__Get_GetCompWith(dbtype1))
  return pfn(dbtype2);

 return nullptr;
}//Helper__Get_Comparator

//------------------------------------------------------------------------
TDBVariantComparator2_Context_STD::pfn_GetCompWith
 TDBVariantComparator2_Context_STD::Helper__Get_GetCompWith(DBTYPE const dbtype1)
{
 const_cast<const unsigned short*>(&dbtype1);

 if(dbtype1<_DIM_(tag_data::sm_Simple))
  return tag_data::sm_Simple[dbtype1].func;

 if((dbtype1&oledb_typeid__ARRAY)==oledb_typeid__ARRAY)
 {
  DBTYPE const i=DBTYPE(dbtype1&~oledb_typeid__ARRAY);

  if(i<_DIM_(tag_data::sm_Array))
   return tag_data::sm_Array[i].func;
 }//if ARRAY

 return nullptr;
}//Helper__Get_GetCompWith

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator2*/}/*nms oledb_lib*/
