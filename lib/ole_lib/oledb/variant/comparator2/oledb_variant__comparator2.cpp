////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/variant/comparator2/oledb_variant__comparator2.h>
#include <ole_lib/oledb/variant/comparator2/oledb_variant__comparator2_context.h>
#include <ole_lib/oledb/variant/oledb_variant.h>

namespace oledb_lib{namespace variant_comparator2{
////////////////////////////////////////////////////////////////////////////////
//class TDBVariantComparator2

TDBVariantComparator2::cmp_code_type
 TDBVariantComparator2::exec(ctx_type&        ctx,
                             const DBVARIANT& v1,
                             const DBVARIANT& v2)const
{
 if(!helper__can_compare(v1))
  return DBVariantCmpCode__err__generic;

 if(!helper__can_compare(v2))
  return DBVariantCmpCode__err__generic;

 if(v1.IsNull_Ext())
 {
  if(v2.IsNull_Ext())
   return DBVariantCmpCode__ok__equal;

  if(ctx.GetSettings().null_is_less)
   return DBVariantCmpCode__ok__less;

  return DBVariantCmpCode__ok__great;
 }//if

 assert(!v1.IsNull_Ext());

 if(v2.IsNull_Ext())
 {
  if(ctx.GetSettings().null_is_less)
   return DBVariantCmpCode__ok__great;

  return DBVariantCmpCode__ok__less;
 }//if

 assert(!v2.IsNull_Ext());

 return this->compare_values(ctx,v1,v2);
}//exec

//------------------------------------------------------------------------
bool TDBVariantComparator2::helper__can_compare(const DBVARIANT& v)
{
 if(v.TestDataStatus__IsOK())
  return true;

 if(v.TestDataStatus__IsNull())
  return true;

 return false;
}//helper__can_compare

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator2*/}/*nms oledb_lib*/
