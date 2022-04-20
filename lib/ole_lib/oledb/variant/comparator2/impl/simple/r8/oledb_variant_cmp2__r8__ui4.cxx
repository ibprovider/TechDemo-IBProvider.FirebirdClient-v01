////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 01.11.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(R8,UI4)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(R8,UI4)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_R8);
 assert(v2.wType==DBTYPE_UI4);

 const_cast<const oledb_lib::t_oledb_value__R8*> (&v1.valR8);
 const_cast<const oledb_lib::t_oledb_value__UI4*>(&v2.valUI4);

 const oledb_lib::t_oledb_value__R8 v2_as_R8(v2.valUI4);

 assert(v2_as_R8==v2.valUI4);

 return DBValueComparator::compare__std
         (v1.valR8,
          v2_as_R8);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
