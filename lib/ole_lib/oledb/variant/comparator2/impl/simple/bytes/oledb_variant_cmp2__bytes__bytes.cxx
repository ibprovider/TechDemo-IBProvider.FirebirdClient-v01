////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 12.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(BYTES,BYTES)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(BYTES,BYTES)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_BYTES);
 assert(v2.wType==DBTYPE_BYTES);

 CHECK_READ_PTR(v1.bytesVal.ptr,v1.bytesVal.len);
 CHECK_READ_PTR(v2.bytesVal.ptr,v2.bytesVal.len);

 return DBValueComparator::compare__str
         (v1.bytesVal.bytes(),
          v1.bytesVal.len,
          v2.bytesVal.bytes(),
          v2.bytesVal.len);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
