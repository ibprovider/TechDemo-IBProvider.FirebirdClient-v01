////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator
//                                                Kovalenko Dmitry. 04.10.2017.
#ifndef _oledb_variant__comparator2_context_H_
#define _oledb_variant__comparator2_context_H_

#include <ole_lib/oledb/variant/comparator2/oledb_variant__comparator2_forward.h>
#include <ole_lib/oledb/variant/oledb_variant_compare2_settings.h>
#include <oledb.h>

namespace oledb_lib{namespace variant_comparator2{
////////////////////////////////////////////////////////////////////////////////
//class TDBVariantComparator2_Context

class TDBVariantComparator2_Context
{
 public:
  virtual const TDBVariantCompare2_Settings& GetSettings()const=0;

  virtual const TDBVariantComparator2* GetComparator(DBTYPE dbtype1,
                                                     DBTYPE dbtype2)=0;
};//class TDBVariantComparator2_Context

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator2*/}/*nms oledb_lib*/
#endif
