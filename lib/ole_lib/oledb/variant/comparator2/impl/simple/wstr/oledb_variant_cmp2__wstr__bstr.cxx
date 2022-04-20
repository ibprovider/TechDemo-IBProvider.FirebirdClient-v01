////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(WSTR,BSTR)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(WSTR,BSTR)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_WSTR);
 assert(v2.wType==DBTYPE_BSTR);

 CHECK_READ_TYPED_PTR(v1.wstrVal.ptr,v1.wstrVal.len);

 const size_t n2=(v2.bstrVal?::SysStringLen(v2.bstrVal):0);

 return DBValueComparator::compare__str
         (v1.wstrVal.ptr,
          v1.wstrVal.len,
          v2.bstrVal,
          n2);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
