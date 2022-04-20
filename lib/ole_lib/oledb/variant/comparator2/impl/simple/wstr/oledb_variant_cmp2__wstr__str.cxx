////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 27.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(WSTR,STR)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(WSTR,STR)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_WSTR);
 assert(v2.wType==DBTYPE_STR);

 //------
 CHECK_READ_TYPED_PTR(v1.wstrVal.ptr,v1.wstrVal.len);

 //------
 std::wstring wstrVal2;

 bool error=false;

 structure::ansi_to_unicode(&wstrVal2,v2.strVal.ptr,v2.strVal.len,&error);

 if(error)
  return DBVariantCmpCode__err__generic;

 //------
 return DBValueComparator::compare__str
         (v1.wstrVal.ptr,
          v1.wstrVal.len,
          wstrVal2.c_str(),
          wstrVal2.size());
}//compare_values

////////////////////////////////////////////////////////////////////////////////
