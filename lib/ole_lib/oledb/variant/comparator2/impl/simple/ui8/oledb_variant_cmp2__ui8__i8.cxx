////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 13.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(UI8,I8)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(UI8,I8)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_UI8);
 assert(v2.wType==DBTYPE_I8);

 const_cast<const oledb_lib::t_oledb_value__UI8*>(&v1.valUI8.QuadPart);
 const_cast<const oledb_lib::t_oledb_value__I8*>(&v2.valI8.QuadPart);

 return DBValueComparator::compare__unsigned_and_signed
         (v1.valUI8.QuadPart,
          v2.valI8.QuadPart);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
