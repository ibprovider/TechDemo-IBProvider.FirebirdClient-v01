////////////////////////////////////////////////////////////////////////////////
//VARIANT Comparator
//                                                Kovalenko Dmitry. 16.02.2017.
#ifndef _ole_auto_variant__comparator_descr1_H_
#define _ole_auto_variant__comparator_descr1_H_

#include <ole_lib/ole_auto/variant/comparator/ole_auto_variant__comparator_descr2.h>

namespace ole_lib{namespace variant_comparator{
////////////////////////////////////////////////////////////////////////////////
//struct TVariantComparatorDescr1

struct TVariantComparatorDescr1
{
 public:
  size_t                          cDescrs2;
  const TVariantComparatorDescr2* pDescrs2;

 #ifndef NDEBUG
  VARTYPE vt1;
 #endif

 public:
 #ifdef NDEBUG
  TVariantComparatorDescr1(size_t                          const _cDescrs2,
                           const TVariantComparatorDescr2* const _pDescrs2)
   :cDescrs2(_cDescrs2)
   ,pDescrs2(_pDescrs2)
  {
  }
 #else
  TVariantComparatorDescr1(size_t                          const _cDescrs2,
                           const TVariantComparatorDescr2* const _pDescrs2,
                           VARTYPE                         const _vt1)
   :cDescrs2(_cDescrs2)
   ,pDescrs2(_pDescrs2)
   ,vt1     (_vt1)
  {
   CHECK_READ_TYPED_PTR(this->pDescrs2,this->cDescrs2);

   for(size_t i=0;i!=this->cDescrs2;++i)
   {
    if(!this->pDescrs2[i].ptr)
     continue;

    assert(this->pDescrs2[i].vt1==this->vt1);

    assert(size_t(this->pDescrs2[i].vt2)==i);
   }//for i
  }//TVariantComparatorDescr1
 #endif
};//struct TVariantComparatorDescr1

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator*/}/*nms ole_lib*/
#endif
