////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 12.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(NUMERIC,DECIMAL)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(NUMERIC,DECIMAL)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_NUMERIC);
 assert(v2.wType==DBTYPE_DECIMAL);

 const_cast<const oledb_lib::t_oledb_value__NUMERIC*>(&v1.dbnumVal);
 const_cast<const oledb_lib::t_oledb_value__DECIMAL*>(&v2.decVal);

 //-----------------------------------------
 DB_NUMERIC dbnum2={};

 {
  const HRESULT hr2=DBVARIANT_CVT_UTILS::DecimalToNumeric(v2.decVal,&dbnum2);

  if(FAILED(hr2))
   return DBVariantCmpCode__err__generic;

  assert(hr2==S_OK);
 }//local

 //-----------------------------------------
 return DBValueComparator::compare__numeric
         (v1.dbnumVal,
          dbnum2);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
