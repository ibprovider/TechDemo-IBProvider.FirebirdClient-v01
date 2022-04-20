////////////////////////////////////////////////////////////////////////////////
//VARIANT Comparator
//                                                Kovalenko Dmitry. 16.02.2017.
#ifndef _ole_auto_variant__comparator_descr2_H_
#define _ole_auto_variant__comparator_descr2_H_

#include <ole_lib/ole_auto/variant/comparator/ole_auto_variant__comparator.h>

namespace ole_lib{namespace variant_comparator{
////////////////////////////////////////////////////////////////////////////////
//struct TVariantComparatorDescr2

struct TVariantComparatorDescr2
{
 public:
  const TVariantComparator* ptr;

 #ifndef NDEBUG
  VARTYPE vt1;
  VARTYPE vt2;
 #endif

 public:
 #ifdef NDEBUG
  TVariantComparatorDescr2(const TVariantComparator* const _ptr)
   :ptr(_ptr)
  {;}
 #else
  TVariantComparatorDescr2(const TVariantComparator* const _ptr,
                           VARTYPE                   const _vt1,
                           VARTYPE                   const _vt2)
   :ptr(_ptr)
   ,vt1(_vt1)
   ,vt2(_vt2)
  {;}
 #endif
};//struct TVariantComparatorDescr2

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator*/}/*nms ole_lib*/
#endif
