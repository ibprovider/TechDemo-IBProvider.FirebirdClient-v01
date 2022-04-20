////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/variant/comparator2/utils/oledb_variant_cmp2__utils.h>

#include <ole_lib/oledb/variant/oledb_variant.h>
#include <ole_lib/oledb/variant/oledb_variant_cmp_utils.h>

#include <ole_lib/oledb/oledb_datetime_services.h>

namespace oledb_lib{namespace variant_comparator2{
////////////////////////////////////////////////////////////////////////////////
//class DBValueComparator

EnumDBVariantCmpCode DBValueComparator::compare__decimal
                               (const t_oledb_value__DECIMAL& v1,
                                const t_oledb_value__DECIMAL& v2)
{
 return DBVARIANT_CMP_UTILS::DecimalCompare
         (v1,
          v2);
}//compare__decimal

//------------------------------------------------------------------------
EnumDBVariantCmpCode DBValueComparator::compare__numeric
                               (const t_oledb_value__NUMERIC& v1,
                                const t_oledb_value__NUMERIC& v2)
{
 return DBVARIANT_CMP_UTILS::NumericCompare
         (v1,
          v2);
}//compare__numeric

//------------------------------------------------------------------------
EnumDBVariantCmpCode DBValueComparator::compare__timestamp
                               (const t_oledb_value__DBTIMESTAMP& v1,
                                const t_oledb_value__DBTIMESTAMP& v2)
{
 //-----------
 assert(TDBDateTimeParser_Base::IsValidDate
         (v1.year,
          v1.month,
          v1.day));

 assert(TDBDateTimeParser_Base::IsValidDate
         (v2.year,
          v2.month,
          v2.day));

 //-----------
 if(v1.year<v2.year)
  return DBVariantCmpCode__ok__less;

 if(v2.year<v1.year)
  return DBVariantCmpCode__ok__great;

 assert(v1.year==v2.year);

 //-----------
 if(v1.month<v2.month)
  return DBVariantCmpCode__ok__less;

 if(v2.month<v1.month)
  return DBVariantCmpCode__ok__great;

 assert(v1.month==v2.month);

 //-----------
 if(v1.day<v2.day)
  return DBVariantCmpCode__ok__less;

 if(v2.day<v1.day)
  return DBVariantCmpCode__ok__great;

 assert(v1.day==v2.day);

 //-----------
 if(v1.hour<v2.hour)
  return DBVariantCmpCode__ok__less;

 if(v2.hour<v1.hour)
  return DBVariantCmpCode__ok__great;

 assert(v1.hour==v2.hour);

 //-----------
 if(v1.minute<v2.minute)
  return DBVariantCmpCode__ok__less;

 if(v2.minute<v1.minute)
  return DBVariantCmpCode__ok__great;

 assert(v1.minute==v2.minute);

 //-----------
 if(v1.second<v2.second)
  return DBVariantCmpCode__ok__less;

 if(v2.second<v1.second)
  return DBVariantCmpCode__ok__great;

 assert(v1.second==v2.second);

 //-----------
 if(v1.fraction<v2.fraction)
  return DBVariantCmpCode__ok__less;

 if(v2.fraction<v1.fraction)
  return DBVariantCmpCode__ok__great;

 assert(v1.fraction==v2.fraction);

 //-----------
 return DBVariantCmpCode__ok__equal;
}//compare__timestamp

////////////////////////////////////////////////////////////////////////////////
}/*nms variant_comparator2*/}//namespace oledb_lib
