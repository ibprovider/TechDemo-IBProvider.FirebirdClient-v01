////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 09.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(DBTIME,DBTIME)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(DBTIME,DBTIME)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_DBTIME);
 assert(v2.wType==DBTYPE_DBTIME);

 const_cast<const oledb_lib::t_oledb_value__DBTIME*>(&v1.dbtimeVal);
 const_cast<const oledb_lib::t_oledb_value__DBTIME*>(&v2.dbtimeVal);

 //-----------
 if(v1.dbtimeVal.hour<v2.dbtimeVal.hour)
  return DBVariantCmpCode__ok__less;

 if(v2.dbtimeVal.hour<v1.dbtimeVal.hour)
  return DBVariantCmpCode__ok__great;

 assert(v1.dbtimeVal.hour==v2.dbtimeVal.hour);

 //-----------
 if(v1.dbtimeVal.minute<v2.dbtimeVal.minute)
  return DBVariantCmpCode__ok__less;

 if(v2.dbtimeVal.minute<v1.dbtimeVal.minute)
  return DBVariantCmpCode__ok__great;

 assert(v1.dbtimeVal.minute==v2.dbtimeVal.minute);

 //-----------
 if(v1.dbtimeVal.second<v2.dbtimeVal.second)
  return DBVariantCmpCode__ok__less;

 if(v2.dbtimeVal.second<v1.dbtimeVal.second)
  return DBVariantCmpCode__ok__great;

 assert(v1.dbtimeVal.second==v2.dbtimeVal.second);

 //-----------
 return DBVariantCmpCode__ok__equal;
}//compare_values

////////////////////////////////////////////////////////////////////////////////
