////////////////////////////////////////////////////////////////////////////////
//OLEDB VARIANT Structures/Services configurations
//                                                 Dmitry Kovalenko. 27.10.2017.
#define _oledb_variant_config_H_
#define _oledb_variant_config_H_

////////////////////////////////////////////////////////////////////////////////
//OLEDB_VARIANT_COMPARATOR2__LEVEL

#define OLEDB_VARIANT_COMPARATOR2__LEVEL0           0

//Added comparators for:
// WSTR and STR
// BSTR and STR
#define OLEDB_VARIANT_COMPARATOR2__LEVEL1           1

//------------------------------------------------------------------------
#ifndef OLEDB_VARIANT_COMPARATOR2__LEVEL
# define OLEDB_VARIANT_COMPARATOR2__LEVEL OLEDB_VARIANT_COMPARATOR2__LEVEL0
#endif

////////////////////////////////////////////////////////////////////////////////