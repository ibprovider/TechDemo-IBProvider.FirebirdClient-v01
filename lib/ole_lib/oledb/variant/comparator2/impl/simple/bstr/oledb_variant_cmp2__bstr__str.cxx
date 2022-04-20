////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 27.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(BSTR,STR)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(BSTR,STR)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_BSTR);
 assert(v2.wType==DBTYPE_STR);

 //------
 const size_t n1=(v1.bstrVal?::SysStringLen(v1.bstrVal):0);

 //------
 std::wstring wstrVal2;

 bool error=false;

 structure::ansi_to_unicode(&wstrVal2,v2.strVal.ptr,v2.strVal.len,&error);

 if(error)
  return DBVariantCmpCode__err__generic;

 //------
 return DBValueComparator::compare__str
         (v1.bstrVal,
          n1,
          wstrVal2.c_str(),
          wstrVal2.size());
}//compare_values

////////////////////////////////////////////////////////////////////////////////
