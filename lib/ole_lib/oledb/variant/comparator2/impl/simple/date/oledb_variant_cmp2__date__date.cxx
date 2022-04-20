////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(DATE,DATE)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(DATE,DATE)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_DATE);
 assert(v2.wType==DBTYPE_DATE);

 const_cast<const oledb_lib::t_oledb_value__DATE*>(&v1.dateVal);
 const_cast<const oledb_lib::t_oledb_value__DATE*>(&v2.dateVal);

 return DBValueComparator::compare__std
         (v1.dateVal,
          v2.dateVal);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
