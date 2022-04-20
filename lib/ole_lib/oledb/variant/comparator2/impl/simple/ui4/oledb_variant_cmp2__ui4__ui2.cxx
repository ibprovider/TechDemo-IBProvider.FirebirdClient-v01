////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 13.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(UI4,UI2)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(UI4,UI2)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_UI4);
 assert(v2.wType==DBTYPE_UI2);

 const_cast<const oledb_lib::t_oledb_value__UI4*>(&v1.valUI4);
 const_cast<const oledb_lib::t_oledb_value__UI2*>(&v2.valUI2);

 return DBValueComparator::compare__std
         (v1.valUI4,
          v2.valUI2);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
