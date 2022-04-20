////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(DBDATE,DBDATE)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(DBDATE,DBDATE)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_DBDATE);
 assert(v2.wType==DBTYPE_DBDATE);

 const_cast<const oledb_lib::t_oledb_value__DBDATE*>(&v1.dbdateVal);
 const_cast<const oledb_lib::t_oledb_value__DBDATE*>(&v2.dbdateVal);

 //-----------
 assert(TDBDateTimeParser_Base::IsValidDate
         (v1.dbdateVal.year,
          v1.dbdateVal.month,
          v1.dbdateVal.day));

 assert(TDBDateTimeParser_Base::IsValidDate
         (v2.dbdateVal.year,
          v2.dbdateVal.month,
          v2.dbdateVal.day));

 //-----------
 if(v1.dbdateVal.year<v2.dbdateVal.year)
  return DBVariantCmpCode__ok__less;

 if(v2.dbdateVal.year<v1.dbdateVal.year)
  return DBVariantCmpCode__ok__great;

 assert(v1.dbdateVal.year==v2.dbdateVal.year);

 //-----------
 if(v1.dbdateVal.month<v2.dbdateVal.month)
  return DBVariantCmpCode__ok__less;

 if(v2.dbdateVal.month<v1.dbdateVal.month)
  return DBVariantCmpCode__ok__great;

 assert(v1.dbdateVal.month==v2.dbdateVal.month);

 //-----------
 if(v1.dbdateVal.day<v2.dbdateVal.day)
  return DBVariantCmpCode__ok__less;

 if(v2.dbdateVal.day<v1.dbdateVal.day)
  return DBVariantCmpCode__ok__great;

 assert(v1.dbdateVal.day==v2.dbdateVal.day);

 //-----------
 return DBVariantCmpCode__ok__equal;
}//compare_values

////////////////////////////////////////////////////////////////////////////////
