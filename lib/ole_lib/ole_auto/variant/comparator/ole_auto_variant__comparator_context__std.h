////////////////////////////////////////////////////////////////////////////////
//VARIANT Comparator
//                                                Kovalenko Dmitry. 15.02.2017.
#ifndef _ole_auto_variant__comparator_context__std_H_
#define _ole_auto_variant__comparator_context__std_H_

#include <ole_lib/ole_auto/variant/comparator/ole_auto_variant__comparator_context.h>

namespace ole_lib{namespace variant_comparator{
////////////////////////////////////////////////////////////////////////////////
//class TVariantComparatorContext_STD

class TVariantComparatorContext_STD:public TVariantComparatorContext
{
 private:
  typedef TVariantComparatorContext_STD             self_type;

  TVariantComparatorContext_STD(const self_type&);
  self_type& operator = (const self_type&);

 public:
  TVariantComparatorContext_STD();

 ~TVariantComparatorContext_STD();

  //interface ------------------------------------------------------------
  virtual cmp_code_type Compare(const VARIANT& v1,
                                const VARIANT& v2) LCPI_CPP_CFG__METHOD__OVERRIDE;

 private: //typedefs -----------------------------------------------------
  class tag_helpers;
  class tag_get_descr;
  class tag_data;

 private:
  typedef const TVariantComparator*    pcomparator_type;

  typedef pcomparator_type (*pfn_GetCompWith)(VARTYPE vt2);

 private:
  static pcomparator_type Helper__Get_Comparator(VARTYPE vt1,
                                                 VARTYPE vt2);

  static pfn_GetCompWith Helper__Get_GetCompWith(VARTYPE vt1);
};//class TVariantComparatorContext_STD

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator*/}/*nms ole_lib*/
#endif
