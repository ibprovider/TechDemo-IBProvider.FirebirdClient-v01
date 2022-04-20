////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Compare.
//                                                  Kovalenko Dmtry. 04.10.2017.
#ifndef _oledb_variant_compare2_H_
#define _oledb_variant_compare2_H_

#include <ole_lib/oledb/variant/comparator2/oledb_variant__comparator2_forward.h>
#include <ole_lib/oledb/variant/oledb_variant_compare2_settings.h>
#include <ole_lib/oledb/variant/oledb_variant_cmp_codes.h>
#include <ole_lib/oledb/variant/oledb_variant_fwrd.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////

EnumDBVariantCmpCode DBVariant_Compare2
                      (variant_comparator2::TDBVariantComparator2_Context& ctx,
                       const DBVARIANT&                                    var1,
                       const DBVARIANT&                                    var2);

////////////////////////////////////////////////////////////////////////////////

EnumDBVariantCmpCode DBVariant_Compare2
                      (const DBVARIANT&                   var1,
                       const DBVARIANT&                   var2,
                       const TDBVariantCompare2_Settings& settings);

////////////////////////////////////////////////////////////////////////////////

EnumDBVariantCmpCode DBVariant_Compare2
                      (const DBVARIANT& var1,
                       const DBVARIANT& var2);

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
