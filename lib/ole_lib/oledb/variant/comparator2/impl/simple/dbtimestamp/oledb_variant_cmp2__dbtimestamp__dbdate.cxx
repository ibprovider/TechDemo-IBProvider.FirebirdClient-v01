////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 26.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(DBTIMESTAMP,DBDATE)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(DBTIMESTAMP,DBDATE)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_DBTIMESTAMP);
 assert(v2.wType==DBTYPE_DBDATE);

 const_cast<const oledb_lib::t_oledb_value__DBTIMESTAMP*>(&v1.dbstampVal);
 const_cast<const oledb_lib::t_oledb_value__DBDATE*>(&v2.dbdateVal);

 //-----------
 t_oledb_value__DBTIMESTAMP ts2;

 dbdate_to_dbstamp(v2.dbdateVal,&ts2);

 //-----------
 return DBValueComparator::compare__timestamp
         (v1.dbstampVal,
          ts2);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
