////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 12.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(FILETIME,FILETIME)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(FILETIME,FILETIME)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_FILETIME);
 assert(v2.wType==DBTYPE_FILETIME);

 const_cast<const oledb_lib::t_oledb_value__FILETIME*>(&v1.filetimeVal);
 const_cast<const oledb_lib::t_oledb_value__FILETIME*>(&v2.filetimeVal);

 //-----------
 if(v1.filetimeVal.dwHighDateTime<v2.filetimeVal.dwHighDateTime)
  return DBVariantCmpCode__ok__less;

 if(v2.filetimeVal.dwHighDateTime<v1.filetimeVal.dwHighDateTime)
  return DBVariantCmpCode__ok__great;

 assert(v1.filetimeVal.dwHighDateTime==v2.filetimeVal.dwHighDateTime);

 //-----------
 if(v1.filetimeVal.dwLowDateTime<v2.filetimeVal.dwLowDateTime)
  return DBVariantCmpCode__ok__less;

 if(v2.filetimeVal.dwLowDateTime<v1.filetimeVal.dwLowDateTime)
  return DBVariantCmpCode__ok__great;

 assert(v1.filetimeVal.dwLowDateTime==v2.filetimeVal.dwLowDateTime);

 //-----------
 return DBVariantCmpCode__ok__equal;
}//compare_values

////////////////////////////////////////////////////////////////////////////////
