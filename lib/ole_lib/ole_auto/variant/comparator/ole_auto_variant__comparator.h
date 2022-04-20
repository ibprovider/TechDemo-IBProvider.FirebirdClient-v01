////////////////////////////////////////////////////////////////////////////////
//VARIANT Comparator
//                                                Kovalenko Dmitry. 15.02.2017.
#ifndef _ole_auto_variant__comparator_H_
#define _ole_auto_variant__comparator_H_

#include <ole_lib/ole_auto/ole_auto_variant_cmp_codes.h>
#include <OleAuto.h>

namespace ole_lib{namespace variant_comparator{
////////////////////////////////////////////////////////////////////////////////
//forward declarations

class TVariantComparatorContext;

////////////////////////////////////////////////////////////////////////////////
//class TVariantComparator

class TVariantComparator
{
 public: //typedefs ------------------------------------------------------
  typedef EnumVariantCmpCode           cmp_code_type;

  typedef TVariantComparatorContext    ctx_type;

 public:
  virtual cmp_code_type exec(ctx_type&       ctx,
                             const VARIANT&  v1,
                             const VARIANT&  v2)const=0;
};//class TVariantComparator

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator*/}/*nms ole_lib*/
#endif
