////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 01.11.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(R4,I2)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(R4,I2)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_R4);
 assert(v2.wType==DBTYPE_I2);

 const_cast<const oledb_lib::t_oledb_value__R4*>(&v1.valR4);
 const_cast<const oledb_lib::t_oledb_value__I2*>(&v2.valI2);

 const oledb_lib::t_oledb_value__R8 v2_as_R8(v2.valI2);

 assert(v2_as_R8==v2.valI2);

 return DBValueComparator::compare__std
         (v1.valR4,
          v2_as_R8);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
