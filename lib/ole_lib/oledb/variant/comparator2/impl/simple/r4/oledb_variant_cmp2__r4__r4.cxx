////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(R4,R4)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(R4,R4)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_R4);
 assert(v2.wType==DBTYPE_R4);

 const_cast<const oledb_lib::t_oledb_value__R4*>(&v1.valR4);
 const_cast<const oledb_lib::t_oledb_value__R4*>(&v2.valR4);

 return DBValueComparator::compare__std
         (v1.valR4,
          v2.valR4);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
