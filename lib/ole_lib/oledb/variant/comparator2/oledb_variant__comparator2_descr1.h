////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator
//                                                Kovalenko Dmitry. 05.10.2017.
#ifndef _oledb_variant__comparator2_descr1_H_
#define _oledb_variant__comparator2_descr1_H_

#include <ole_lib/oledb/variant/comparator2/oledb_variant__comparator2_descr2.h>

namespace oledb_lib{namespace variant_comparator2{
////////////////////////////////////////////////////////////////////////////////
//struct TDBVariantComparator2_Descr1

struct TDBVariantComparator2_Descr1
{
 public:
  size_t                              cDescrs2;
  const TDBVariantComparator2_Descr2* pDescrs2;

 #ifndef NDEBUG
  DBTYPE dbtype1;
 #endif

 public:
 #ifdef NDEBUG
  TDBVariantComparator2_Descr1(size_t                              const _cDescrs2,
                               const TDBVariantComparator2_Descr2* const _pDescrs2)
   :cDescrs2(_cDescrs2)
   ,pDescrs2(_pDescrs2)
  {
  }
 #else
  TDBVariantComparator2_Descr1(size_t                              const _cDescrs2,
                               const TDBVariantComparator2_Descr2* const _pDescrs2,
                               DBTYPE                              const _dbtype1,
                               DBTYPE                              const _dbtype2modificator)
   :cDescrs2(_cDescrs2)
   ,pDescrs2(_pDescrs2)
   ,dbtype1 (_dbtype1)
  {
   CHECK_READ_TYPED_PTR(this->pDescrs2,this->cDescrs2);

   for(size_t i=0;i!=this->cDescrs2;++i)
   {
    if(!this->pDescrs2[i].ptr)
     continue;

    assert(this->pDescrs2[i].dbtype1==this->dbtype1);

    assert(size_t(this->pDescrs2[i].dbtype2)==(i|_dbtype2modificator));
   }//for i
  }//TDBVariantComparator2_Descr1
 #endif
};//struct TDBVariantComparator2_Descr1

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator2*/}/*nms oledb_lib*/
#endif
