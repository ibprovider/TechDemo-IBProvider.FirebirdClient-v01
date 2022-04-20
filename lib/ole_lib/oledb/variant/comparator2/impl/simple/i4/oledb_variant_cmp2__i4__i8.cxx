////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 12.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(I4,I8)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(I4,I8)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_I4);
 assert(v2.wType==DBTYPE_I8);

 const_cast<const oledb_lib::t_oledb_value__I4*>(&v1.valI4);
 const_cast<const oledb_lib::t_oledb_value__I8*>(&v2.valI8.QuadPart);

 return DBValueComparator::compare__std
         (v1.valI4,
          v2.valI8.QuadPart);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
