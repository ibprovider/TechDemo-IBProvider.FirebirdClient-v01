////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 12.10.2017.
#ifndef _oledb_variant_cmp2__dbtimestamp_HXX_
#define _oledb_variant_cmp2__dbtimestamp_HXX_

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE
 (DBTIMESTAMP,
  DATE)

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE
 (DBTIMESTAMP,
  FILETIME)

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE
 (DBTIMESTAMP,
  DBDATE)

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE
 (DBTIMESTAMP,
  DBTIMESTAMP)

////////////////////////////////////////////////////////////////////////////////

extern const TDBVariantComparator2_Descr1 g_DBVariantComparator2_Descr1__DBTIMESTAMP__Simple;

////////////////////////////////////////////////////////////////////////////////
#endif