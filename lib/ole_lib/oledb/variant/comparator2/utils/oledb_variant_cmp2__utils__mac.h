////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator
//                                                Kovalenko Dmitry. xx.10.2017.
#ifndef _oledb_variant_cmp2__utils__mac_H_
#define _oledb_variant_cmp2__utils__mac_H_

#include <ole_lib/oledb/variant/comparator2/oledb_variant__comparator2.h>
#include <ole_lib/oledb/variant/comparator2/oledb_variant__comparator2_descr1.h>
#include <ole_lib/oledb/variant/oledb_variant.h>
#include <ole_lib/oledb/variant/oledb_variant_config.h>

namespace oledb_lib{namespace variant_comparator2{
////////////////////////////////////////////////////////////////////////////////

#define OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(dbtype1,dbtype2)           \
 TVariantComparator2__##dbtype1##__##dbtype2

#define OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE(dbtype1,dbtype2)          \
 class OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(dbtype1,dbtype2)            \
  :public TDBVariantComparator2                                           \
{                                                                         \
 private:                                                                 \
  typedef OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(dbtype1,                 \
                                                 dbtype2)    self_type;   \
                                                                          \
  OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(dbtype1,                         \
                                         dbtype2)(const self_type&);      \
                                                                          \
  self_type& operator = (const self_type&);                               \
                                                                          \
 private:                                                                 \
  OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(dbtype1,dbtype2)(){;}            \
                                                                          \
 ~OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(dbtype1,dbtype2)(){;}            \
                                                                          \
 public:                                                                  \
  static const self_type sm_Instance;                                     \
                                                                          \
 private:                                                                 \
  virtual cmp_code_type compare_values                                    \
                         (ctx_type&                   ctx,                \
                          const oledb_lib::DBVARIANT& v1,                 \
                          const oledb_lib::DBVARIANT& v2)const COMP_W000004_OVERRIDE_FINAL; \
};

////////////////////////////////////////////////////////////////////////////////

#define OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(dbtype1,dbtype2)\
                                                                          \
const OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(dbtype1,dbtype2)             \
 OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(dbtype1,dbtype2)::sm_Instance;

////////////////////////////////////////////////////////////////////////////////

#define OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(dbtype1,  \
                                                                dbtype2)  \
                                                                          \
OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(dbtype1,dbtype2)::cmp_code_type    \
 OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(dbtype1,dbtype2)::compare_values  \
                   (ctx_type&                   UNUSED_ARG(ctx),          \
                    const oledb_lib::DBVARIANT& v1,                       \
                    const oledb_lib::DBVARIANT& v2)const

//------------------------------------------------------------------------
#define OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES2(dbtype1, \
                                                                 dbtype2) \
                                                                          \
OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(dbtype1,dbtype2)::cmp_code_type    \
 OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(dbtype1,dbtype2)::compare_values  \
                   (ctx_type&                   ctx,                      \
                    const oledb_lib::DBVARIANT& v1,                       \
                    const oledb_lib::DBVARIANT& v2)const

////////////////////////////////////////////////////////////////////////////////

#ifdef NDEBUG
#define OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE()                          \
 TDBVariantComparator2_Descr2                                             \
  (nullptr)
#else
#define OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE()                          \
 TDBVariantComparator2_Descr2                                             \
  (nullptr,                                                               \
   0,                                                                     \
   0)
#endif

////////////////////////////////////////////////////////////////////////////////

#ifdef NDEBUG

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(dbtype1,dbtype2)         \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(dbtype1,dbtype2)::sm_Instance)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__VARIANT1(dbtype2)               \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(VARIANT,value)::sm_Instance)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__VARIANT2(dbtype1)               \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(value,VARIANT)::sm_Instance)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__NULL1(dbtype2)                  \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(null,null)::sm_Instance)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__NULL2(dbtype1)                  \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(null,null)::sm_Instance)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__NULL1_A(dbtype2)                \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(null,null)::sm_Instance)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__NULL2_A(dbtype1)                \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(null,null)::sm_Instance)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__VARIANT1_A(dbtype2)             \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(VARIANT,value)::sm_Instance)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__VARIANT2_A(dbtype1)             \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(value,VARIANT)::sm_Instance)

#else

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(dbtype1,dbtype2)         \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(dbtype1,dbtype2)::sm_Instance, \
   oledb_lib::oledb_typeid__##dbtype1,                                    \
   oledb_lib::oledb_typeid__##dbtype2)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__VARIANT1(dbtype2)               \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(VARIANT,value)::sm_Instance,   \
   oledb_lib::oledb_typeid__VARIANT,                                      \
   oledb_lib::oledb_typeid__##dbtype2)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__VARIANT2(dbtype1)               \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(value,VARIANT)::sm_Instance,   \
   oledb_lib::oledb_typeid__##dbtype1,                                    \
   oledb_lib::oledb_typeid__VARIANT)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__NULL1(dbtype2)                  \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(null,null)::sm_Instance,       \
   oledb_lib::oledb_typeid__NULL,                                         \
   oledb_lib::oledb_typeid__##dbtype2)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__NULL2(dbtype1)                  \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(null,null)::sm_Instance,       \
   oledb_lib::oledb_typeid__##dbtype1,                                    \
   oledb_lib::oledb_typeid__NULL)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__NULL1_A(dbtype2)                \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(null,null)::sm_Instance,       \
   oledb_lib::oledb_typeid__NULL,                                         \
   oledb_lib::oledb_typeid__ARRAY|oledb_lib::oledb_typeid__##dbtype2)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__NULL2_A(dbtype1)                \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(null,null)::sm_Instance,       \
   oledb_lib::oledb_typeid__ARRAY|oledb_lib::oledb_typeid__##dbtype1,     \
   oledb_lib::oledb_typeid__NULL)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__VARIANT1_A(dbtype2)             \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(VARIANT,value)::sm_Instance,   \
   oledb_lib::oledb_typeid__VARIANT,                                      \
   oledb_lib::oledb_typeid__ARRAY|oledb_lib::oledb_typeid__##dbtype2)

#define OLEDB_VARIANT_COMPARATOR2_DESCR2__VARIANT2_A(dbtype1)             \
 TDBVariantComparator2_Descr2                                             \
  (&OLEDB_VARIANT_COMPARATOR2_NAME__SIMPLE(value,VARIANT)::sm_Instance,   \
   oledb_lib::oledb_typeid__ARRAY|oledb_lib::oledb_typeid__##dbtype1,     \
   oledb_lib::oledb_typeid__VARIANT)

#endif

////////////////////////////////////////////////////////////////////////////////

#ifndef OLEDB_VARIANT_COMPARATOR2__LEVEL
# error OLEDB_VARIANT_COMPARATOR2__LEVEL not defined
#endif

//------------------------------------------------------------------------
#if  (OLEDB_VARIANT_COMPARATOR2__LEVEL==OLEDB_VARIANT_COMPARATOR2__LEVEL0)

# define OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE_LV1(dbtype1,dbtype2)    \
  OLEDB_VARIANT_COMPARATOR2_DESCR2__NONE()

#elif(OLEDB_VARIANT_COMPARATOR2__LEVEL==OLEDB_VARIANT_COMPARATOR2__LEVEL1)

# define OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE_LV1(dbtype1,dbtype2)    \
  OLEDB_VARIANT_COMPARATOR2_DESCR2__SIMPLE(dbtype1,dbtype2)

#else
# error Unknown OLEDB_VARIANT_COMPARATOR2__LEVEL
#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator2*/}//namespace oledb_lib
#endif
