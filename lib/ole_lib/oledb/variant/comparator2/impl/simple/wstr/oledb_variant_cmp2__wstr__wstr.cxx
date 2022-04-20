////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(WSTR,WSTR)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(WSTR,WSTR)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_WSTR);
 assert(v2.wType==DBTYPE_WSTR);

 CHECK_READ_TYPED_PTR(v1.wstrVal.ptr,v1.wstrVal.len);
 CHECK_READ_TYPED_PTR(v2.wstrVal.ptr,v2.wstrVal.len);

 return DBValueComparator::compare__str
         (v1.wstrVal.ptr,
          v1.wstrVal.len,
          v2.wstrVal.ptr,
          v2.wstrVal.len);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
