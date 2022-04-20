////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 12.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(UI2,I4)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(UI2,I4)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_UI2);
 assert(v2.wType==DBTYPE_I4);

 const_cast<const oledb_lib::t_oledb_value__UI2*>(&v1.valUI2);
 const_cast<const oledb_lib::t_oledb_value__I4*>(&v2.valI4);

 return DBValueComparator::compare__unsigned_and_signed
         (v1.valUI2,
          v2.valI4);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
