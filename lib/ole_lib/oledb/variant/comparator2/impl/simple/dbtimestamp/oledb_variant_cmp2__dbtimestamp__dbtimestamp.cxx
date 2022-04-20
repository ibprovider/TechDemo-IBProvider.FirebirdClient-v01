////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 12.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(DBTIMESTAMP,DBTIMESTAMP)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(DBTIMESTAMP,DBTIMESTAMP)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_DBTIMESTAMP);
 assert(v2.wType==DBTYPE_DBTIMESTAMP);

 const_cast<const oledb_lib::t_oledb_value__DBTIMESTAMP*>(&v1.dbstampVal);
 const_cast<const oledb_lib::t_oledb_value__DBTIMESTAMP*>(&v2.dbstampVal);

 //-----------
 return DBValueComparator::compare__timestamp
         (v1.dbstampVal,
          v2.dbstampVal);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
