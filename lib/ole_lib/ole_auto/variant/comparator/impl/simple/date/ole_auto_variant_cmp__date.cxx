////////////////////////////////////////////////////////////////////////////////
//Variant Comparator.
//                                                Kovalenko Dmitry. 16.02.2017.

////////////////////////////////////////////////////////////////////////////////

#include <ole_lib/ole_auto/variant/comparator/impl/simple/date/ole_auto_variant_cmp__date__date.cxx>

////////////////////////////////////////////////////////////////////////////////

extern const TVariantComparatorDescr2 g_VariantComparatorDescrs2__DATE__Simple[]=
{
 /* 0*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE(),                //VT_EMPTY
 /* 1*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE(),                //VT_NULL
 /* 2*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE(),                //VT_I2
 /* 3*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE(),                //VT_I4
 /* 4*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE(),                //VT_R4
 /* 5*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE(),                //VT_R8
 /* 6*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE(),
 /* 7*/ OLE_AUTO_VARIANT_COMPARATOR_DESCR2__SIMPLE(DATE,DATE),     //VT_DATE
};//g_VariantComparatorDescrs2__DATE__Simple

////////////////////////////////////////////////////////////////////////////////

extern const TVariantComparatorDescr1
 g_VariantComparatorDescr1__DATE__Simple
  (_DIM_(g_VariantComparatorDescrs2__DATE__Simple),
   g_VariantComparatorDescrs2__DATE__Simple
   _DEBUG_ARG(VT_DATE));

////////////////////////////////////////////////////////////////////////////////
