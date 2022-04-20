////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator
//                                                Kovalenko Dmitry. xx.10.2017.
#ifndef _oledb_variant_cmp2__utils_H_
#define _oledb_variant_cmp2__utils_H_

#include <ole_lib/oledb/oledb_data_types.h>
#include <ole_lib/oledb/variant/oledb_variant_cmp_codes.h>

namespace oledb_lib{namespace variant_comparator2{
////////////////////////////////////////////////////////////////////////////////
//class DBValueComparator

class DBValueComparator
{
 public:
  template<typename T1,typename T2>
  static EnumDBVariantCmpCode compare__std
                               (T1 v1,
                                T2 v2);

  template<typename T1,typename T2>
  static EnumDBVariantCmpCode compare__signed_and_unsigned
                               (T1 v1,
                                T2 v2);

  template<typename T1,typename T2>
  static EnumDBVariantCmpCode compare__unsigned_and_signed
                               (T1 v1,
                                T2 v2);

  template<typename TChar>
  static EnumDBVariantCmpCode compare__str
                               (const TChar* s1,
                                size_t       n1,
                                const TChar* s2,
                                size_t       n2);

  static EnumDBVariantCmpCode compare__decimal
                               (const t_oledb_value__DECIMAL& v1,
                                const t_oledb_value__DECIMAL& v2);

  static EnumDBVariantCmpCode compare__numeric
                               (const t_oledb_value__NUMERIC& v1,
                                const t_oledb_value__NUMERIC& v2);

  static EnumDBVariantCmpCode compare__timestamp
                               (const t_oledb_value__DBTIMESTAMP& v1,
                                const t_oledb_value__DBTIMESTAMP& v2);
};//class DBValueComparator

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator2*/}//namespace oledb_lib
////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/oledb/variant/comparator2/utils/oledb_variant_cmp2__utils.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
