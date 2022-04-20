////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 12.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(DECIMAL,NUMERIC)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(DECIMAL,NUMERIC)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_DECIMAL);
 assert(v2.wType==DBTYPE_NUMERIC);

 const_cast<const oledb_lib::t_oledb_value__DECIMAL*>(&v1.decVal);
 const_cast<const oledb_lib::t_oledb_value__NUMERIC*>(&v1.dbnumVal);

 //-----------------------------------------
 DB_NUMERIC dbnum1={};

 {
  const HRESULT hr1=DBVARIANT_CVT_UTILS::DecimalToNumeric(v1.decVal,&dbnum1);

  if(FAILED(hr1))
   return DBVariantCmpCode__err__generic;

  assert(hr1==S_OK);
 }//local

 //-----------------------------------------
 return DBValueComparator::compare__numeric
         (dbnum1,
          v2.dbnumVal);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
