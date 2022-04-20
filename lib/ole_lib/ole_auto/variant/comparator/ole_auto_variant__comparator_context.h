////////////////////////////////////////////////////////////////////////////////
//VARIANT Comparator
//                                                Kovalenko Dmitry. 15.02.2017.
#ifndef _ole_auto_variant__comparator_context_H_
#define _ole_auto_variant__comparator_context_H_

#include <ole_lib/ole_auto/ole_auto_variant_cmp_codes.h>
#include <OleAuto.h>

namespace ole_lib{namespace variant_comparator{
////////////////////////////////////////////////////////////////////////////////
//forward declarations

class TVariantComparator;

////////////////////////////////////////////////////////////////////////////////
//class TVariantComparatorContext

class TVariantComparatorContext
{
 public: //typedefs ------------------------------------------------------
  typedef EnumVariantCmpCode           cmp_code_type;

 public:
  virtual cmp_code_type Compare(const VARIANT& v1,
                                const VARIANT& v2)=0;
};//class TVariantComparatorContext

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator*/}/*nms ole_lib*/
#endif
