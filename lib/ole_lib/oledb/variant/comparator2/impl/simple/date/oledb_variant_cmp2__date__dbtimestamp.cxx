////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 26.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(DATE,DBTIMESTAMP)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(DATE,DBTIMESTAMP)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_DATE);
 assert(v2.wType==DBTYPE_DBTIMESTAMP);

 const_cast<const oledb_lib::t_oledb_value__DATE*>(&v1.dateVal);
 const_cast<const oledb_lib::t_oledb_value__DBTIMESTAMP*>(&v2.dbstampVal);

 //-----------
 t_oledb_value__DBTIMESTAMP ts1;

 if(!date_to_dbstamp(v1.dateVal,&ts1))
  return DBVariantCmpCode__err__generic;

 //-----------
 return DBValueComparator::compare__timestamp
         (ts1,
          v2.dbstampVal);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
