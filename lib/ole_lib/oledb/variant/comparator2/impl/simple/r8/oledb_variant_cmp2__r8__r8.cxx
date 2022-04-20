////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(R8,R8)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(R8,R8)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_R8);
 assert(v2.wType==DBTYPE_R8);

 const_cast<const oledb_lib::t_oledb_value__R8*>(&v1.valR8);
 const_cast<const oledb_lib::t_oledb_value__R8*>(&v2.valR8);

 return DBValueComparator::compare__std
         (v1.valR8,
          v2.valR8);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
