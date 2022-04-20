////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.

////////////////////////////////////////////////////////////////////////////////

#include <ole_lib/oledb/variant/comparator2/impl/simple/r4/oledb_variant_cmp2__r4__i1.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/r4/oledb_variant_cmp2__r4__i2.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/r4/oledb_variant_cmp2__r4__ui1.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/r4/oledb_variant_cmp2__r4__ui2.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/r4/oledb_variant_cmp2__r4__r4.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/r4/oledb_variant_cmp2__r4__r8.cxx>

////////////////////////////////////////////////////////////////////////////////

extern const TDBVariantComparator2_Descr2 g_DBVariantComparator2_Descrs2__R4__Simple[]=
{
 /* 0*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_EMPTY
 /* 1*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NULL2(R4),               //DBTYPE_NULL
 /* 2*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(R4,I2),           //DBTYPE_I2
 /* 3*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_I4
 /* 4*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(R4,R4),           //DBTYPE_R4
 /* 5*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(R4,R8),           //DBTYPE_R8
 /* 6*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_CY
 /* 7*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_DATE
 /* 8*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_BSTR
 /* 9*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*10*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*11*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_BOOL
 /*12*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__VARIANT2(R4),
 /*13*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*14*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*15*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*16*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(R4,I1),           //DBTYPE_I1
 /*17*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(R4,UI1),          //DBTYPE_UI1
 /*18*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(R4,UI2),          //DBTYPE_UI2
 /*19*/                                                            //DBTYPE_UI4
 /*20*/                                                            //DBTYPE_I8
 /*21*/                                                            //DBTYPE_UI8
};//g_DBVariantComparator2_Descrs2__R4__Simple

////////////////////////////////////////////////////////////////////////////////

extern const TDBVariantComparator2_Descr1
 g_DBVariantComparator2_Descr1__R4__Simple
  (_DIM_(g_DBVariantComparator2_Descrs2__R4__Simple),
   g_DBVariantComparator2_Descrs2__R4__Simple
   _DEBUG_ARG(oledb_typeid__R4)
   _DEBUG_ARG(0));

////////////////////////////////////////////////////////////////////////////////
