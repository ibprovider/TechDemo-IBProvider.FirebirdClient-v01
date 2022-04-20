////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/ole_auto/variant/comparator/ole_auto_variant__comparator_context__std.h>

#include <ole_lib/ole_auto/variant/comparator/impl/simple/empty/ole_auto_variant_cmp__empty.h>

#include <ole_lib/ole_auto/variant/comparator/impl/simple/i1/ole_auto_variant_cmp__i1.h>
#include <ole_lib/ole_auto/variant/comparator/impl/simple/i2/ole_auto_variant_cmp__i2.h>
#include <ole_lib/ole_auto/variant/comparator/impl/simple/i4/ole_auto_variant_cmp__i4.h>
#include <ole_lib/ole_auto/variant/comparator/impl/simple/i8/ole_auto_variant_cmp__i8.h>

#include <ole_lib/ole_auto/variant/comparator/impl/simple/ui1/ole_auto_variant_cmp__ui1.h>
#include <ole_lib/ole_auto/variant/comparator/impl/simple/ui2/ole_auto_variant_cmp__ui2.h>
#include <ole_lib/ole_auto/variant/comparator/impl/simple/ui4/ole_auto_variant_cmp__ui4.h>
#include <ole_lib/ole_auto/variant/comparator/impl/simple/ui8/ole_auto_variant_cmp__ui8.h>

#include <ole_lib/ole_auto/variant/comparator/impl/simple/r4/ole_auto_variant_cmp__r4.h>
#include <ole_lib/ole_auto/variant/comparator/impl/simple/r8/ole_auto_variant_cmp__r8.h>

#include <ole_lib/ole_auto/variant/comparator/impl/simple/bool/ole_auto_variant_cmp__bool.h>

#include <ole_lib/ole_auto/variant/comparator/impl/simple/date/ole_auto_variant_cmp__date.h>

#include <ole_lib/ole_auto/variant/comparator/impl/simple/bstr/ole_auto_variant_cmp__bstr.h>

namespace ole_lib{namespace variant_comparator{
////////////////////////////////////////////////////////////////////////////////

#ifndef OLE_AUTO_VARIANT_COMPARATOR_OWN_CPP

namespace impl{
////////////////////////////////////////////////////////////////////////////////

#include <ole_lib/ole_auto/variant/comparator/impl/simple/empty/ole_auto_variant_cmp__empty.cxx>

#include <ole_lib/ole_auto/variant/comparator/impl/simple/i1/ole_auto_variant_cmp__i1.cxx>
#include <ole_lib/ole_auto/variant/comparator/impl/simple/i2/ole_auto_variant_cmp__i2.cxx>
#include <ole_lib/ole_auto/variant/comparator/impl/simple/i4/ole_auto_variant_cmp__i4.cxx>
#include <ole_lib/ole_auto/variant/comparator/impl/simple/i8/ole_auto_variant_cmp__i8.cxx>

#include <ole_lib/ole_auto/variant/comparator/impl/simple/ui1/ole_auto_variant_cmp__ui1.cxx>
#include <ole_lib/ole_auto/variant/comparator/impl/simple/ui2/ole_auto_variant_cmp__ui2.cxx>
#include <ole_lib/ole_auto/variant/comparator/impl/simple/ui4/ole_auto_variant_cmp__ui4.cxx>
#include <ole_lib/ole_auto/variant/comparator/impl/simple/ui8/ole_auto_variant_cmp__ui8.cxx>

#include <ole_lib/ole_auto/variant/comparator/impl/simple/r4/ole_auto_variant_cmp__r4.cxx>
#include <ole_lib/ole_auto/variant/comparator/impl/simple/r8/ole_auto_variant_cmp__r8.cxx>

#include <ole_lib/ole_auto/variant/comparator/impl/simple/bool/ole_auto_variant_cmp__bool.cxx>

#include <ole_lib/ole_auto/variant/comparator/impl/simple/date/ole_auto_variant_cmp__date.cxx>

#include <ole_lib/ole_auto/variant/comparator/impl/simple/bstr/ole_auto_variant_cmp__bstr.cxx>

////////////////////////////////////////////////////////////////////////////////
}//namespace impl

#endif //OLE_AUTO_VARIANT_COMPARATOR_OWN_CPP

////////////////////////////////////////////////////////////////////////////////
//class TVariantComparatorContext_STD::tag_helpers

class TVariantComparatorContext_STD::tag_helpers
{
 public:
  static pcomparator_type GetCompWith_EMPTY(VARTYPE vt2);

  static pcomparator_type GetCompWith_I1(VARTYPE vt2);

  static pcomparator_type GetCompWith_I2(VARTYPE vt2);

  static pcomparator_type GetCompWith_I4(VARTYPE vt2);

  static pcomparator_type GetCompWith_I8(VARTYPE vt2);

  static pcomparator_type GetCompWith_UI1(VARTYPE vt2);

  static pcomparator_type GetCompWith_UI2(VARTYPE vt2);

  static pcomparator_type GetCompWith_UI4(VARTYPE vt2);

  static pcomparator_type GetCompWith_UI8(VARTYPE vt2);

  static pcomparator_type GetCompWith_R4(VARTYPE vt2);

  static pcomparator_type GetCompWith_R8(VARTYPE vt2);

  static pcomparator_type GetCompWith_BOOL(VARTYPE vt2);

  static pcomparator_type GetCompWith_DATE(VARTYPE vt2);

  static pcomparator_type GetCompWith_BSTR(VARTYPE vt2);
};//TVariantComparatorContext_STD::tag_helpers

////////////////////////////////////////////////////////////////////////////////
//class TVariantComparatorContext_STD::tag_helpers

TVariantComparatorContext_STD::pcomparator_type
 TVariantComparatorContext_STD::tag_helpers::GetCompWith_EMPTY(VARTYPE const vt2)
{
 const_cast<const unsigned short*>(&vt2);

 if(vt2<impl::g_VariantComparatorDescr1__EMPTY__Simple.cDescrs2)
  return impl::g_VariantComparatorDescr1__EMPTY__Simple.pDescrs2[vt2].ptr;

 return nullptr;
}//GetCompWith_EMPTY

//------------------------------------------------------------------------
TVariantComparatorContext_STD::pcomparator_type
 TVariantComparatorContext_STD::tag_helpers::GetCompWith_I1(VARTYPE const vt2)
{
 const_cast<const unsigned short*>(&vt2);

 if(vt2<impl::g_VariantComparatorDescr1__I1__Simple.cDescrs2)
  return impl::g_VariantComparatorDescr1__I1__Simple.pDescrs2[vt2].ptr;

 return nullptr;
}//GetCompWith_I1

//------------------------------------------------------------------------
TVariantComparatorContext_STD::pcomparator_type
 TVariantComparatorContext_STD::tag_helpers::GetCompWith_I2(VARTYPE const vt2)
{
 const_cast<const unsigned short*>(&vt2);

 if(vt2<impl::g_VariantComparatorDescr1__I2__Simple.cDescrs2)
  return impl::g_VariantComparatorDescr1__I2__Simple.pDescrs2[vt2].ptr;

 return nullptr;
}//GetCompWith_I2

//------------------------------------------------------------------------
TVariantComparatorContext_STD::pcomparator_type
 TVariantComparatorContext_STD::tag_helpers::GetCompWith_I4(VARTYPE const vt2)
{
 const_cast<const unsigned short*>(&vt2);

 if(vt2<impl::g_VariantComparatorDescr1__I4__Simple.cDescrs2)
  return impl::g_VariantComparatorDescr1__I4__Simple.pDescrs2[vt2].ptr;

 return nullptr;
}//GetCompWith_I4

//------------------------------------------------------------------------
TVariantComparatorContext_STD::pcomparator_type
 TVariantComparatorContext_STD::tag_helpers::GetCompWith_I8(VARTYPE const vt2)
{
 const_cast<const unsigned short*>(&vt2);

 if(vt2<impl::g_VariantComparatorDescr1__I8__Simple.cDescrs2)
  return impl::g_VariantComparatorDescr1__I8__Simple.pDescrs2[vt2].ptr;

 return nullptr;
}//GetCompWith_I8

//------------------------------------------------------------------------
TVariantComparatorContext_STD::pcomparator_type
 TVariantComparatorContext_STD::tag_helpers::GetCompWith_UI1(VARTYPE const vt2)
{
 const_cast<const unsigned short*>(&vt2);

 if(vt2<impl::g_VariantComparatorDescr1__UI1__Simple.cDescrs2)
  return impl::g_VariantComparatorDescr1__UI1__Simple.pDescrs2[vt2].ptr;

 return nullptr;
}//GetCompWith_UI1

//------------------------------------------------------------------------
TVariantComparatorContext_STD::pcomparator_type
 TVariantComparatorContext_STD::tag_helpers::GetCompWith_UI2(VARTYPE const vt2)
{
 const_cast<const unsigned short*>(&vt2);

 if(vt2<impl::g_VariantComparatorDescr1__UI2__Simple.cDescrs2)
  return impl::g_VariantComparatorDescr1__UI2__Simple.pDescrs2[vt2].ptr;

 return nullptr;
}//GetCompWith_UI2

//------------------------------------------------------------------------
TVariantComparatorContext_STD::pcomparator_type
 TVariantComparatorContext_STD::tag_helpers::GetCompWith_UI4(VARTYPE const vt2)
{
 const_cast<const unsigned short*>(&vt2);

 if(vt2<impl::g_VariantComparatorDescr1__UI4__Simple.cDescrs2)
  return impl::g_VariantComparatorDescr1__UI4__Simple.pDescrs2[vt2].ptr;

 return nullptr;
}//GetCompWith_UI4

//------------------------------------------------------------------------
TVariantComparatorContext_STD::pcomparator_type
 TVariantComparatorContext_STD::tag_helpers::GetCompWith_UI8(VARTYPE const vt2)
{
 const_cast<const unsigned short*>(&vt2);

 if(vt2<impl::g_VariantComparatorDescr1__UI8__Simple.cDescrs2)
  return impl::g_VariantComparatorDescr1__UI8__Simple.pDescrs2[vt2].ptr;

 return nullptr;
}//GetCompWith_UI8

//------------------------------------------------------------------------
TVariantComparatorContext_STD::pcomparator_type
 TVariantComparatorContext_STD::tag_helpers::GetCompWith_R4(VARTYPE const vt2)
{
 const_cast<const unsigned short*>(&vt2);

 if(vt2<impl::g_VariantComparatorDescr1__R4__Simple.cDescrs2)
  return impl::g_VariantComparatorDescr1__R4__Simple.pDescrs2[vt2].ptr;

 return nullptr;
}//GetCompWith_R4

//------------------------------------------------------------------------
TVariantComparatorContext_STD::pcomparator_type
 TVariantComparatorContext_STD::tag_helpers::GetCompWith_R8(VARTYPE const vt2)
{
 const_cast<const unsigned short*>(&vt2);

 if(vt2<impl::g_VariantComparatorDescr1__R8__Simple.cDescrs2)
  return impl::g_VariantComparatorDescr1__R8__Simple.pDescrs2[vt2].ptr;

 return nullptr;
}//GetCompWith_R8

//------------------------------------------------------------------------
TVariantComparatorContext_STD::pcomparator_type
 TVariantComparatorContext_STD::tag_helpers::GetCompWith_BOOL(VARTYPE const vt2)
{
 const_cast<const unsigned short*>(&vt2);

 if(vt2<impl::g_VariantComparatorDescr1__BOOL__Simple.cDescrs2)
  return impl::g_VariantComparatorDescr1__BOOL__Simple.pDescrs2[vt2].ptr;

 return nullptr;
}//GetCompWith_BOOL

//------------------------------------------------------------------------
TVariantComparatorContext_STD::pcomparator_type
 TVariantComparatorContext_STD::tag_helpers::GetCompWith_DATE(VARTYPE const vt2)
{
 const_cast<const unsigned short*>(&vt2);

 if(vt2<impl::g_VariantComparatorDescr1__DATE__Simple.cDescrs2)
  return impl::g_VariantComparatorDescr1__DATE__Simple.pDescrs2[vt2].ptr;

 return nullptr;
}//GetCompWith_DATE

//------------------------------------------------------------------------
TVariantComparatorContext_STD::pcomparator_type
 TVariantComparatorContext_STD::tag_helpers::GetCompWith_BSTR(VARTYPE const vt2)
{
 const_cast<const unsigned short*>(&vt2);

 if(vt2<impl::g_VariantComparatorDescr1__BSTR__Simple.cDescrs2)
  return impl::g_VariantComparatorDescr1__BSTR__Simple.pDescrs2[vt2].ptr;

 return nullptr;
}//GetCompWith_BSTR

////////////////////////////////////////////////////////////////////////////////
//class TVariantComparatorContext_STD::tag_get_descr

class TVariantComparatorContext_STD::tag_get_descr
{
 public: //typedefs ------------------------------------------------------
  typedef pcomparator_type (*pfn_GetCompWith)(VARTYPE vt2);

 public:
  pfn_GetCompWith func;

 #ifndef NDEBUG
  VARTYPE         vt1;
 #endif

 public:
 #ifdef NDEBUG
  tag_get_descr(pfn_GetCompWith const _func)
   :func(_func)
  {;}
 #else
  tag_get_descr(pfn_GetCompWith const _func,
                VARTYPE         const _vt1)
   :func(_func)
   ,vt1(_vt1)
  {;}
 #endif
};//class TVariantComparatorContext_STD::tag_get_descr

////////////////////////////////////////////////////////////////////////////////
//class TVariantComparatorContext_STD::tag_data

class TVariantComparatorContext_STD::tag_data
{
 public:
  static const tag_get_descr sm_Simple[];

 private:
#ifndef NDEBUG
  static const tag_data sm_Instance;

  tag_data();

  static void debug__Check_sm_Simple();
#endif
};//class TVariantComparatorContext_STD::tag_data

////////////////////////////////////////////////////////////////////////////////
//TVariantComparatorContext_STD::tag_data::sm_Simple

#define DEF_GET_NONE()                                                    \
 TVariantComparatorContext_STD::tag_get_descr                             \
  (nullptr                                                    \
   _DEBUG_ARG(0))

#define DEF_GET_DESCR(vt1)                                                \
 TVariantComparatorContext_STD::tag_get_descr                             \
  (TVariantComparatorContext_STD::tag_helpers::GetCompWith_##vt1          \
   _DEBUG_ARG(VT_##vt1))

//------------------------------------------------------------------------
const TVariantComparatorContext_STD::tag_get_descr
 TVariantComparatorContext_STD::tag_data::sm_Simple[]=
{
 /* 0*/ DEF_GET_DESCR(EMPTY),
 /* 1*/ DEF_GET_NONE (),
 /* 2*/ DEF_GET_DESCR(I2),
 /* 3*/ DEF_GET_DESCR(I4),
 /* 4*/ DEF_GET_DESCR(R4),
 /* 5*/ DEF_GET_DESCR(R8),
 /* 6*/ DEF_GET_NONE (),
 /* 7*/ DEF_GET_DESCR(DATE),
 /* 8*/ DEF_GET_DESCR(BSTR),
 /* 9*/ DEF_GET_NONE (),
 /*10*/ DEF_GET_NONE (),
 /*11*/ DEF_GET_DESCR(BOOL),
 /*12*/ DEF_GET_NONE (),
 /*13*/ DEF_GET_NONE (),
 /*14*/ DEF_GET_NONE (),
 /*15*/ DEF_GET_NONE (),
 /*16*/ DEF_GET_DESCR(I1),
 /*17*/ DEF_GET_DESCR(UI1),
 /*18*/ DEF_GET_DESCR(UI2),
 /*19*/ DEF_GET_DESCR(UI4),
 /*20*/ DEF_GET_DESCR(I8),
 /*21*/ DEF_GET_DESCR(UI8),
};//sm_Simple

//------------------------------------------------------------------------
#undef DEF_GET_DESCR
#undef DEF_GET_NONE

////////////////////////////////////////////////////////////////////////////////
//class TVariantComparatorContext_STD::tag_data::

#ifndef NDEBUG

const TVariantComparatorContext_STD::tag_data
 TVariantComparatorContext_STD::tag_data::sm_Instance;

//------------------------------------------------------------------------
TVariantComparatorContext_STD::tag_data::tag_data()
{
 debug__Check_sm_Simple();
}//tag_data

//------------------------------------------------------------------------
void TVariantComparatorContext_STD::tag_data::debug__Check_sm_Simple()
{
 for(size_t i=0;i!=_DIM_(sm_Simple);++i)
 {
  if(!sm_Simple[i].func)
   continue;

  assert(size_t(sm_Simple[i].vt1)==i);
 }//for i
}//debug__Check_sm_Simple

#endif // !NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class TVariantComparatorContext_STD

TVariantComparatorContext_STD::TVariantComparatorContext_STD()
{;}

//------------------------------------------------------------------------
TVariantComparatorContext_STD::~TVariantComparatorContext_STD()
{;}

//interface --------------------------------------------------------------
TVariantComparatorContext_STD::cmp_code_type
 TVariantComparatorContext_STD::Compare(const VARIANT& v1,
                                        const VARIANT& v2)
{
 if(pcomparator_type const p=Helper__Get_Comparator(v1.vt,v2.vt))
  return p->exec(*this,v1,v2);

 return VariantCmpCode__err__not_supported;
}//Compare

//helper methods ---------------------------------------------------------

TVariantComparatorContext_STD::pcomparator_type
 TVariantComparatorContext_STD::Helper__Get_Comparator(VARTYPE const vt1,
                                                       VARTYPE const vt2)
{
 if(pfn_GetCompWith const pfn=Helper__Get_GetCompWith(vt1))
  return pfn(vt2);

 return nullptr;
}//Helper__Get_Comparator

//------------------------------------------------------------------------
TVariantComparatorContext_STD::pfn_GetCompWith
 TVariantComparatorContext_STD::Helper__Get_GetCompWith(VARTYPE const vt1)
{
 const_cast<const unsigned short*>(&vt1);

 if(vt1<_DIM_(tag_data::sm_Simple))
  return tag_data::sm_Simple[vt1].func;

 return nullptr;
}//Helper__Get_GetCompWith

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator*/}/*nms ole_lib*/
