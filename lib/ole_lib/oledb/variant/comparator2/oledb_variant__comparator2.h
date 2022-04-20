////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator
//                                                Kovalenko Dmitry. 04.10.2017.
#ifndef _oledb_variant__comparator2_H_
#define _oledb_variant__comparator2_H_

#include <ole_lib/oledb/variant/comparator2/oledb_variant__comparator2_forward.h>
#include <ole_lib/oledb/variant/oledb_variant_cmp_codes.h>
#include <ole_lib/oledb/variant/oledb_variant_fwrd.h>

namespace oledb_lib{namespace variant_comparator2{
////////////////////////////////////////////////////////////////////////////////
//class TDBVariantComparator2

class TDBVariantComparator2
{
 public: //typedefs ------------------------------------------------------
  typedef EnumDBVariantCmpCode           cmp_code_type;

  typedef TDBVariantComparator2_Context  ctx_type;

 public:
  cmp_code_type exec(ctx_type&        ctx,
                     const DBVARIANT& v1,
                     const DBVARIANT& v2)const;

 private:
  virtual cmp_code_type compare_values(ctx_type&        ctx,
                                       const DBVARIANT& v1,
                                       const DBVARIANT& v2)const=0;
 private:
  static bool helper__can_compare(const DBVARIANT& v);
};//class TDBVariantComparator2

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator2*/}/*nms oledb_lib*/
#endif
