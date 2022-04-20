////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 26.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(DBDATE,DATE)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(DBDATE,DATE)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_DBDATE);
 assert(v2.wType==DBTYPE_DATE);

 const_cast<const oledb_lib::t_oledb_value__DBDATE*> (&v1.dbdateVal);
 const_cast<const oledb_lib::t_oledb_value__DATE*>   (&v2.dateVal);

 //-----------
 t_oledb_value__DBTIMESTAMP ts1;

 dbdate_to_dbstamp(v1.dbdateVal,&ts1);

 //-----------
 t_oledb_value__DBTIMESTAMP ts2;

 if(!date_to_dbstamp(v2.dateVal,&ts2))
  return DBVariantCmpCode__err__generic;

 //-----------
 return DBValueComparator::compare__timestamp
         (ts1,
          ts2);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
