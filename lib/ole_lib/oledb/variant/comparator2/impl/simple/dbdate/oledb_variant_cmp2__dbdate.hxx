////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 09.10.2017.
#ifndef _oledb_variant_cmp2__dbdate_HXX_
#define _oledb_variant_cmp2__dbdate_HXX_

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE
 (DBDATE,
  DATE)

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE
 (DBDATE,
  DBDATE)

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE
 (DBDATE,
  DBTIMESTAMP)

////////////////////////////////////////////////////////////////////////////////

extern const TDBVariantComparator2_Descr1 g_DBVariantComparator2_Descr1__DBDATE__Simple;

////////////////////////////////////////////////////////////////////////////////
#endif