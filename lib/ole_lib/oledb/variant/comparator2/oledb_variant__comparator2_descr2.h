////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator
//                                                Kovalenko Dmitry. 05.10.2017.
#ifndef _oledb_variant__comparator2_descr2_H_
#define _oledb_variant__comparator2_descr2_H_

#include <ole_lib/oledb/variant/comparator2/oledb_variant__comparator2.h>

namespace oledb_lib{namespace variant_comparator2{
////////////////////////////////////////////////////////////////////////////////
//struct TDBVariantComparator2_Descr2

struct TDBVariantComparator2_Descr2
{
 public:
  const TDBVariantComparator2* ptr;

 #ifndef NDEBUG
  DBTYPE dbtype1;
  DBTYPE dbtype2;
 #endif

 public:
 #ifdef NDEBUG
  TDBVariantComparator2_Descr2(const TDBVariantComparator2* const _ptr)
   :ptr(_ptr)
  {;}
 #else
  TDBVariantComparator2_Descr2(const TDBVariantComparator2* const _ptr,
                               DBTYPE                       const _dbtype1,
                               DBTYPE                       const _dbtype2)
   :ptr(_ptr)
   ,dbtype1(_dbtype1)
   ,dbtype2(_dbtype2)
  {;}
 #endif
};//struct TDBVariantComparator2_Descr2

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator2*/}/*nms oledb_lib*/
#endif
