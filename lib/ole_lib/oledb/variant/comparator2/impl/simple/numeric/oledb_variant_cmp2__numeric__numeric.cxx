////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 12.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(NUMERIC,NUMERIC)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(NUMERIC,NUMERIC)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_NUMERIC);
 assert(v2.wType==DBTYPE_NUMERIC);

 const_cast<const oledb_lib::t_oledb_value__NUMERIC*>(&v1.dbnumVal);
 const_cast<const oledb_lib::t_oledb_value__NUMERIC*>(&v2.dbnumVal);

 return DBValueComparator::compare__numeric
         (v1.dbnumVal,
          v2.dbnumVal);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
