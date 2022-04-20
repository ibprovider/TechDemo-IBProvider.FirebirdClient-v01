////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 27.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(STR,BSTR)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(STR,BSTR)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_STR);
 assert(v2.wType==DBTYPE_BSTR);

 //------
 std::wstring wstrVal1;

 bool error=false;

 structure::ansi_to_unicode(&wstrVal1,v1.strVal.ptr,v1.strVal.len,&error);

 if(error)
  return DBVariantCmpCode__err__generic;

 //------
 const size_t n2=(v2.bstrVal?::SysStringLen(v2.bstrVal):0);

 //------
 return DBValueComparator::compare__str
         (wstrVal1.c_str(),
          wstrVal1.size(),
          v2.bstrVal,
          n2);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
