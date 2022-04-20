////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 12.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(I4,UI4)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(I4,UI4)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_I4);
 assert(v2.wType==DBTYPE_UI4);

 const_cast<const oledb_lib::t_oledb_value__I4*> (&v1.valI4);
 const_cast<const oledb_lib::t_oledb_value__UI4*>(&v2.valUI4);

 return DBValueComparator::compare__signed_and_unsigned
         (v1.valI4,
          v2.valUI4);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
