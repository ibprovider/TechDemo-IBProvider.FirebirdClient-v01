////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 16.02.2017.

////////////////////////////////////////////////////////////////////////////////

#include <ole_lib/ole_auto/variant/comparator/impl/simple/bstr/ole_auto_variant_cmp__bstr__bstr.cxx>

////////////////////////////////////////////////////////////////////////////////

extern const TVariantComparatorDescr2 g_VariantComparatorDescrs2__BSTR__Simple[]=
{
 /* 0*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE(),                //VT_EMPTY
 /* 1*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE(),                //VT_NULL
 /* 2*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE(),                //VT_I2
 /* 3*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE(),                //VT_I4
 /* 4*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE(),                //VT_R4
 /* 5*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE(),                //VT_R8
 /* 6*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE(),
 /* 7*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE(),                //VT_BOOL
 /* 8*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__SIMPLE(BSTR,BSTR),     //VT_BSTR
};//g_VariantComparatorDescrs2__BSTR__Simple

////////////////////////////////////////////////////////////////////////////////

extern const TVariantComparatorDescr1
 g_VariantComparatorDescr1__BSTR__Simple
  (_DIM_(g_VariantComparatorDescrs2__BSTR__Simple),
   g_VariantComparatorDescrs2__BSTR__Simple
   _DEBUG_ARG(VT_BSTR));

////////////////////////////////////////////////////////////////////////////////
