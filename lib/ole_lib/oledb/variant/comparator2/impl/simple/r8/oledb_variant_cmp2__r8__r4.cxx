////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 13.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(R8,R4)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(R8,R4)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_R8);
 assert(v2.wType==DBTYPE_R4);

 const_cast<const oledb_lib::t_oledb_value__R8*>(&v1.valR8);
 const_cast<const oledb_lib::t_oledb_value__R4*>(&v2.valR4);

 return DBValueComparator::compare__std
         (v1.valR8,
          v2.valR4);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
