////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.
#ifndef _oledb_variant_cmp2__date_HXX_
#define _oledb_variant_cmp2__date_HXX_

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE
 (DATE,
  DATE)

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE
 (DATE,
  DBDATE)

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE
 (DATE,
  DBTIMESTAMP)

////////////////////////////////////////////////////////////////////////////////

extern const TDBVariantComparator2_Descr1 g_DBVariantComparator2_Descr1__DATE__Simple;

////////////////////////////////////////////////////////////////////////////////
#endif