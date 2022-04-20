////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 13.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(UI8,UI1)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(UI8,UI1)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_UI8);
 assert(v2.wType==DBTYPE_UI1);

 const_cast<const oledb_lib::t_oledb_value__UI8*>(&v1.valUI8.QuadPart);
 const_cast<const oledb_lib::t_oledb_value__UI1*>(&v2.valUI1);

 return DBValueComparator::compare__std
         (v1.valUI8.QuadPart,
          v2.valUI1);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
