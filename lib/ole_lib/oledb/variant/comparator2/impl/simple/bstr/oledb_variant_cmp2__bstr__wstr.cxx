////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(BSTR,WSTR)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(BSTR,WSTR)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_BSTR);
 assert(v2.wType==DBTYPE_WSTR);

 const size_t n1=(v1.bstrVal?LCPI_OS__SysStringLen(v1.bstrVal):0);

 CHECK_READ_TYPED_PTR(v2.wstrVal.ptr,v2.wstrVal.len);

 return DBValueComparator::compare__str
         (v1.bstrVal,
          n1,
          v2.wstrVal.ptr,
          v2.wstrVal.len);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
