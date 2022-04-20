////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 14.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(I2,DECIMAL)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(I2,DECIMAL)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_I2);
 assert(v2.wType==DBTYPE_DECIMAL);

 const_cast<const oledb_lib::t_oledb_value__I2*>(&v1.valI2);
 const_cast<const oledb_lib::t_oledb_value__DECIMAL*>(&v2.decVal);

 t_oledb_value__DECIMAL decVal1;

 const HRESULT hr=DBVARIANT_CVT_UTILS::IntToDecimal(v1.valI2,&decVal1);

 if(FAILED(hr))
  return DBVariantCmpCode__err__generic;

 assert(hr==S_OK);

 return DBValueComparator::compare__decimal
         (decVal1,
          v2.decVal);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
