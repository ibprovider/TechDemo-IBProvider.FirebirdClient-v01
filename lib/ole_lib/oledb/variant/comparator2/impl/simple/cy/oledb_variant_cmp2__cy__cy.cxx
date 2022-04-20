////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 14.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(CY,CY)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(CY,CY)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_CY);
 assert(v2.wType==DBTYPE_CY);

 const_cast<const oledb_lib::t_oledb_value__CY*>(&v1.valCY);
 const_cast<const oledb_lib::t_oledb_value__CY*>(&v2.valCY);

 return DBValueComparator::compare__std
         (v1.valCY.int64,
          v2.valCY.int64);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
