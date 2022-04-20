////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.

////////////////////////////////////////////////////////////////////////////////

#include <ole_lib/oledb/variant/comparator2/impl/simple/bool/oledb_variant_cmp2__bool__bool.cxx>

////////////////////////////////////////////////////////////////////////////////

extern const TDBVariantComparator2_Descr2 g_DBVariantComparator2_Descrs2__BOOL__Simple[]=
{
 /* 0*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_EMPTY
 /* 1*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NULL2(BOOL),             //DBTYPE_NULL
 /* 2*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_I2
 /* 3*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_I4
 /* 4*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_R4
 /* 5*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_R8
 /* 6*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_CY
 /* 7*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_DATE
 /* 8*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_BSTR
 /* 9*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*10*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*11*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(BOOL,BOOL),       //DBTYPE_BOOL
 /*12*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__VARIANT2(BOOL),          //DBTYPE_VARIANT
};//g_DBVariantComparator2_Descrs2__BOOL__Simple

////////////////////////////////////////////////////////////////////////////////

extern const TDBVariantComparator2_Descr1
 g_DBVariantComparator2_Descr1__BOOL__Simple
  (_DIM_(g_DBVariantComparator2_Descrs2__BOOL__Simple),
   g_DBVariantComparator2_Descrs2__BOOL__Simple
   _DEBUG_ARG(oledb_typeid__BOOL)
   _DEBUG_ARG(0));

////////////////////////////////////////////////////////////////////////////////
