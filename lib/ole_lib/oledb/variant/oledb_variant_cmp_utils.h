////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Compare Utilitis.
//                                                  Kovalenko Dmtry. 18.10.2017.
#ifndef _oledb_variant_cmp_utils_H_
#define _oledb_variant_cmp_utils_H_

#include <ole_lib/oledb/variant/oledb_variant_cmp_codes.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////

class DBVARIANT_CMP_UTILS
{
 private:
  typedef DBVARIANT_CMP_UTILS               self_type;

 public:
  //comparation of two NUMERIC values
  static EnumDBVariantCmpCode NumericCompare
                               (const DB_NUMERIC& dbnum1,
                                const DB_NUMERIC& dbnum2);

  //comparation of two DECIMAL values
  static EnumDBVariantCmpCode DecimalCompare
                               (const tagDEC& dec1,
                                const tagDEC& dec2);
};//class DBVARIANT_CMP_UTILS

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
