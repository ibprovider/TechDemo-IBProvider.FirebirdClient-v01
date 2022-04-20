////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 12.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(I4,I2)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(I4,I2)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_I4);
 assert(v2.wType==DBTYPE_I2);

 const_cast<const oledb_lib::t_oledb_value__I4*>(&v1.valI4);
 const_cast<const oledb_lib::t_oledb_value__I2*>(&v2.valI2);

 return DBValueComparator::compare__std
         (v1.valI4,
          v2.valI2);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
