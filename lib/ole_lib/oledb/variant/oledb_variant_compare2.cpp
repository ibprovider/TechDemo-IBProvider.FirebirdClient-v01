////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/variant/oledb_variant_compare2.h>
#include <ole_lib/oledb/variant/comparator2/oledb_variant__comparator2_context_std.h>
#include <ole_lib/oledb/variant/comparator2/oledb_variant__comparator2.h>
#include <ole_lib/oledb/variant/oledb_variant.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////

EnumDBVariantCmpCode DBVariant_Compare2
                      (variant_comparator2::TDBVariantComparator2_Context& ctx,
                       const DBVARIANT&                                    var1,
                       const DBVARIANT&                                    var2)
{
 if(const variant_comparator2::TDBVariantComparator2* const p=ctx.GetComparator(var1.wType,var2.wType))
  return p->exec(ctx,var1,var2);

 return DBVariantCmpCode__err__not_supported;
}//DBVariant_Compare2

////////////////////////////////////////////////////////////////////////////////

EnumDBVariantCmpCode DBVariant_Compare2
                      (const DBVARIANT&                   var1,
                       const DBVARIANT&                   var2,
                       const TDBVariantCompare2_Settings& settings)
{
 variant_comparator2::TDBVariantComparator2_Context_STD ctx(settings);

 return DBVariant_Compare2(ctx,var1,var2);
}//DBVariant_Compare2

////////////////////////////////////////////////////////////////////////////////

EnumDBVariantCmpCode DBVariant_Compare2
                      (const DBVARIANT& var1,
                       const DBVARIANT& var2)
{
 variant_comparator2::TDBVariantComparator2_Context_STD ctx;

 return DBVariant_Compare2(ctx,var1,var2);
}//DBVariant_Compare2

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
