////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 14.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(NUMERIC,I4)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(NUMERIC,I4)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_NUMERIC);
 assert(v2.wType==DBTYPE_I4);

 const_cast<const oledb_lib::t_oledb_value__NUMERIC*>(&v1.dbnumVal);
 const_cast<const oledb_lib::t_oledb_value__I4*>(&v2.valI4);

 t_oledb_value__NUMERIC dbnumVal2;

 const HRESULT hr=DBVARIANT_CVT_UTILS::IntToNumeric(v2.valI4,&dbnumVal2);

 if(FAILED(hr))
  return DBVariantCmpCode__err__generic;

 assert(hr==S_OK);

 return DBValueComparator::compare__numeric
         (v1.dbnumVal,
          dbnumVal2);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
