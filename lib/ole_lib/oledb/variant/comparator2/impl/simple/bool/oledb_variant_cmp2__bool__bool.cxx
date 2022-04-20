////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(BOOL,BOOL)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(BOOL,BOOL)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_BOOL);
 assert(v2.wType==DBTYPE_BOOL);

 const bool b1=(v1.boolVal!=VARIANT_FALSE);
 const bool b2=(v2.boolVal!=VARIANT_FALSE);

 return DBValueComparator::compare__std
         (b1,
          b2);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
