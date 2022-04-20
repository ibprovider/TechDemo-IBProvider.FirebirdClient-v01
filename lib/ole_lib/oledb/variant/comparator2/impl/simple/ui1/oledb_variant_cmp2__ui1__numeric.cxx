////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 14.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(UI1,NUMERIC)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(UI1,NUMERIC)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_UI1);
 assert(v2.wType==DBTYPE_NUMERIC);

 const_cast<const oledb_lib::t_oledb_value__UI1*>(&v1.valUI1);
 const_cast<const oledb_lib::t_oledb_value__NUMERIC*>(&v2.dbnumVal);

 t_oledb_value__NUMERIC dbnumVal1;

 const HRESULT hr=DBVARIANT_CVT_UTILS::IntToNumeric(v1.valUI1,&dbnumVal1);

 if(FAILED(hr))
  return DBVariantCmpCode__err__generic;

 assert(hr==S_OK);

 return DBValueComparator::compare__numeric
         (dbnumVal1,
          v2.dbnumVal);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
