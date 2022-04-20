////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 13.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(I2,UI2)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(I2,UI2)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_I2);
 assert(v2.wType==DBTYPE_UI2);

 const_cast<const oledb_lib::t_oledb_value__I2*>(&v1.valI2);
 const_cast<const oledb_lib::t_oledb_value__UI2*>(&v2.valUI2);

 return DBValueComparator::compare__signed_and_unsigned
         (v1.valI2,
          v2.valUI2);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
