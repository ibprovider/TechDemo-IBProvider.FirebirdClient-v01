////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 05.10.2017.

////////////////////////////////////////////////////////////////////////////////

#include <ole_lib/oledb/variant/comparator2/impl/simple/i1/oledb_variant_cmp2__i1__i1.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/i1/oledb_variant_cmp2__i1__i2.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/i1/oledb_variant_cmp2__i1__i4.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/i1/oledb_variant_cmp2__i1__i8.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/i1/oledb_variant_cmp2__i1__ui1.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/i1/oledb_variant_cmp2__i1__ui2.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/i1/oledb_variant_cmp2__i1__ui4.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/i1/oledb_variant_cmp2__i1__ui8.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/i1/oledb_variant_cmp2__i1__decimal.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/i1/oledb_variant_cmp2__i1__numeric.cxx>

#include <ole_lib/oledb/variant/comparator2/impl/simple/i1/oledb_variant_cmp2__i1__r4.cxx>
#include <ole_lib/oledb/variant/comparator2/impl/simple/i1/oledb_variant_cmp2__i1__r8.cxx>

////////////////////////////////////////////////////////////////////////////////

extern const TDBVariantComparator2_Descr2 g_DBVariantComparator2_Descrs2__I1__Simple[]=
{
 /*  0*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_EMPTY
 /*  1*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NULL2(I1),               //DBTYPE_NULL
 /*  2*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(I1,I2),           //DBTYPE_I2
 /*  3*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(I1,I4),           //DBTYPE_I4
 /*  4*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(I1,R4),           //DBTYPE_R4
 /*  5*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(I1,R8),           //DBTYPE_R8
 /*  6*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_CY
 /*  7*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_DATE
 /*  8*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_BSTR
 /*  9*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 10*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 11*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),                  //DBTYPE_BOOL
 /* 12*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__VARIANT2(I1),            //DBTYPE_VARIANT
 /* 13*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 14*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(I1,DECIMAL),
 /* 15*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 16*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(I1,I1),           //DBTYPE_I1
 /* 17*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(I1,UI1),          //DBTYPE_UI1
 /* 18*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(I1,UI2),          //DBTYPE_UI2
 /* 19*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(I1,UI4),          //DBTYPE_UI4
 /* 20*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(I1,I8),           //DBTYPE_I8
 /* 21*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(I1,UI8),          //DBTYPE_UI8
 /* 22*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 23*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 24*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 25*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 26*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 27*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 28*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 29*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 30*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 31*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 32*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 33*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 34*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 35*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 36*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 37*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 38*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 39*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 40*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 41*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 42*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 43*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 44*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 45*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 46*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 47*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 48*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 49*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 50*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 51*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 52*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 53*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 54*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 55*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 56*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 57*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 58*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 59*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 60*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 61*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 62*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 63*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 64*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 65*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 66*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 67*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 68*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 69*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 70*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 71*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 72*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 73*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 74*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 75*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 76*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 77*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 78*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 79*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 80*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 81*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 82*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 83*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 84*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 85*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 86*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 87*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 88*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 89*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 90*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 91*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 92*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 93*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 94*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 95*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 96*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 97*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 98*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /* 99*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*100*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*101*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*102*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*103*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*104*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*105*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*106*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*107*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*108*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*109*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*110*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*111*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*112*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*113*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*114*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*115*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*116*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*117*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*118*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*119*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*120*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*121*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*122*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*123*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*124*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*125*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*126*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*127*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*128*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*129*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*130*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE(),
 /*131*/ OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(I1,NUMERIC)
};//g_DBVariantComparator2_Descrs2__I1__Simple

////////////////////////////////////////////////////////////////////////////////

extern const TDBVariantComparator2_Descr1
 g_DBVariantComparator2_Descr1__I1__Simple
  (_DIM_(g_DBVariantComparator2_Descrs2__I1__Simple),
   g_DBVariantComparator2_Descrs2__I1__Simple
   _DEBUG_ARG(oledb_typeid__I1)
   _DEBUG_ARG(0));

////////////////////////////////////////////////////////////////////////////////
