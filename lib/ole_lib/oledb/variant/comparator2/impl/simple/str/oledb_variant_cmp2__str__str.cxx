////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(STR,STR)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(STR,STR)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_STR);
 assert(v2.wType==DBTYPE_STR);

 CHECK_READ_TYPED_PTR(v1.strVal.ptr,v1.strVal.len);
 CHECK_READ_TYPED_PTR(v2.strVal.ptr,v2.strVal.len);

 return DBValueComparator::compare__str
         (v1.strVal.ptr,
          v1.strVal.len,
          v2.strVal.ptr,
          v2.strVal.len);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
