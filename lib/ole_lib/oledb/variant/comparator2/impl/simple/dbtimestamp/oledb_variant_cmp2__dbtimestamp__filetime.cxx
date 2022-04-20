////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 14.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(DBTIMESTAMP,FILETIME)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(DBTIMESTAMP,FILETIME)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_DBTIMESTAMP);
 assert(v2.wType==DBTYPE_FILETIME);

 const_cast<const oledb_lib::t_oledb_value__DBTIMESTAMP*>(&v1.dbstampVal);
 const_cast<const oledb_lib::t_oledb_value__FILETIME*>(&v2.filetimeVal);

 //-----------
 t_oledb_value__DBTIMESTAMP ts2={};

 if(!filetime_to_dbstamp(v2.filetimeVal,&ts2))
  return DBVariantCmpCode__err__generic;

 //-----------
 return DBValueComparator::compare__timestamp
         (v1.dbstampVal,
          ts2);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
