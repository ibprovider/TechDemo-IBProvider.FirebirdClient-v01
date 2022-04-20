////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 27.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(STR,WSTR)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(STR,WSTR)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_STR);
 assert(v2.wType==DBTYPE_WSTR);

 //------
 CHECK_READ_TYPED_PTR(v2.wstrVal.ptr,v2.wstrVal.len);

 //------
 std::wstring wstrVal1;

 bool error=false;

 structure::ansi_to_unicode(&wstrVal1,v1.strVal.ptr,v1.strVal.len,&error);

 if(error)
  return DBVariantCmpCode__err__generic;

 //------
 return DBValueComparator::compare__str
         (wstrVal1.c_str(),
          wstrVal1.size(),
          v2.wstrVal.ptr,
          v2.wstrVal.len);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
