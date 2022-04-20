////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 14.10.2017.

////////////////////////////////////////////////////////////////////////////////

#include <ole_lib/oledb/variant/comparator2/impl/simple/cy/oledb_variant_cmp2__cy__cy.cxx>

////////////////////////////////////////////////////////////////////////////////

extern const TDBVariantComparator2_Descr2 g_DBVariantComparator2_Descrs2__CY__Simple[]=
{
 /* 0*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_EMPTY
 /* 1*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NULL2(CY),               //DBTYPE_NULL
 /* 2*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_I2
 /* 3*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_I4
 /* 4*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_R4
 /* 5*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_R8
 /* 6*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(CY,CY),           //DBTYPE_CY
 /* 7*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_DATE
 /* 8*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_BSTR
 /* 9*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*10*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*11*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_BOOL
 /*12*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__VARIANT2(CY),            //DBTYPE_VARIANT
 /*13*/
 /*14*/
 /*15*/
 /*16*/                                                            //DBTYPE_I1
 /*17*/                                                            //DBTYPE_UI1
 /*18*/                                                            //DBTYPE_UI2
 /*19*/                                                            //DBTYPE_UI4
 /*20*/                                                            //DBTYPE_I8
 /*21*/                                                            //DBTYPE_UI8
};//g_DBVariantComparator2_Descrs2__CY__Simple

////////////////////////////////////////////////////////////////////////////////

extern const TDBVariantComparator2_Descr1
 g_DBVariantComparator2_Descr1__CY__Simple
  (_DIM_(g_DBVariantComparator2_Descrs2__CY__Simple),
   g_DBVariantComparator2_Descrs2__CY__Simple
   _DEBUG_ARG(oledb_typeid__CY)
   _DEBUG_ARG(0));

////////////////////////////////////////////////////////////////////////////////
