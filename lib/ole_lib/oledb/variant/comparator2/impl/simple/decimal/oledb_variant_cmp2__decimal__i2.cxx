////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 14.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(DECIMAL,I2)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(DECIMAL,I2)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_DECIMAL);
 assert(v2.wType==DBTYPE_I2);

 const_cast<const oledb_lib::t_oledb_value__DECIMAL*>(&v1.decVal);
 const_cast<const oledb_lib::t_oledb_value__I2*>(&v2.valI2);

 t_oledb_value__DECIMAL decVal2;

 const HRESULT hr=DBVARIANT_CVT_UTILS::IntToDecimal(v2.valI2,&decVal2);

 if(FAILED(hr))
  return DBVariantCmpCode__err__generic;

 assert(hr==S_OK);

 return DBValueComparator::compare__decimal
         (v1.decVal,
          decVal2);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
