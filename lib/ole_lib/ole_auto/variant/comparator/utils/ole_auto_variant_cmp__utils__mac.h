////////////////////////////////////////////////////////////////////////////////
#ifndef _ole_auto_variant_cmp__utils__mac_H_
#define _ole_auto_variant_cmp__utils__mac_H_

#include <ole_lib/ole_auto/variant/comparator/ole_auto_variant__comparator.h>
#include <ole_lib/ole_auto/variant/comparator/ole_auto_variant__comparator_descr1.h>

namespace ole_lib{namespace variant_comparator{
////////////////////////////////////////////////////////////////////////////////

#define OLE_AUTO_VARIANT_COMPARATOR_NAME__SIMPLE(vt1,vt2)                 \
 TVariantComparator__##vt1##__##vt2

#define OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE(vt1,vt2)                \
class OLE_AUTO_VARIANT_COMPARATOR_NAME__SIMPLE(vt1,vt2) LCPI_CPP_CFG__CLASS__FINAL \
 :public TVariantComparator                                               \
{                                                                         \
 private:                                                                 \
  using self_type=OLE_AUTO_VARIANT_COMPARATOR_NAME__SIMPLE(vt1,vt2);      \
                                                                          \
  OLE_AUTO_VARIANT_COMPARATOR_NAME__SIMPLE(vt1,vt2)(const self_type&)=delete;    \
  self_type& operator = (const self_type&)=delete;                               \
                                                                          \
 private:                                                                 \
  OLE_AUTO_VARIANT_COMPARATOR_NAME__SIMPLE(vt1,vt2)(){;}                  \
                                                                          \
 ~OLE_AUTO_VARIANT_COMPARATOR_NAME__SIMPLE(vt1,vt2)(){;}                  \
                                                                          \
 public:                                                                  \
  static const self_type sm_Instance;                                     \
                                                                          \
  virtual cmp_code_type exec(ctx_type&       ctx,                         \
                             const VARIANT&  v1,                          \
                             const VARIANT&  v2)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL; \
};

////////////////////////////////////////////////////////////////////////////////

#define OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__INSTANCE(vt1,vt2)      \
                                                                          \
const OLE_AUTO_VARIANT_COMPARATOR_NAME__SIMPLE(vt1,vt2)                   \
 OLE_AUTO_VARIANT_COMPARATOR_NAME__SIMPLE(vt1,vt2)::sm_Instance;

////////////////////////////////////////////////////////////////////////////////

#define OLE_AUTO_VARIANT_COMPARATOR_CLASS__SIMPLE__EXEC(vt1,vt2)          \
                                                                          \
OLE_AUTO_VARIANT_COMPARATOR_NAME__SIMPLE(vt1,vt2)::cmp_code_type          \
 OLE_AUTO_VARIANT_COMPARATOR_NAME__SIMPLE(vt1,vt2)::exec                  \
                                      (ctx_type& ctx,                     \
                                       const VARIANT&  v1,                \
                                       const VARIANT&  v2)const

////////////////////////////////////////////////////////////////////////////////

#ifdef NDEBUG
#define OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE()                        \
 TVariantComparatorDescr2                                                 \
  (nullptr)
#else
#define OLE_AUTO_VARIANT_COMPARATOR_DESCR2__NONE()                        \
 TVariantComparatorDescr2                                                 \
  (nullptr,                                                               \
   0,                                                                     \
   0)
#endif

////////////////////////////////////////////////////////////////////////////////

#ifdef NDEBUG
#define OLE_AUTO_VARIANT_COMPARATOR_DESCR2__SIMPLE(vt1,vt2)               \
 TVariantComparatorDescr2                                                 \
  (&OLE_AUTO_VARIANT_COMPARATOR_NAME__SIMPLE(vt1,vt2)::sm_Instance)
#else
#define OLE_AUTO_VARIANT_COMPARATOR_DESCR2__SIMPLE(vt1,vt2)               \
 TVariantComparatorDescr2                                                 \
  (&OLE_AUTO_VARIANT_COMPARATOR_NAME__SIMPLE(vt1,vt2)::sm_Instance,       \
   VT_##vt1,                                                              \
   VT_##vt2)
#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator*/}//namespace ole_lib
#endif
