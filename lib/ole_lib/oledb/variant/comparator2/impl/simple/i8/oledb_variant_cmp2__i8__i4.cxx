////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(I8,I4)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(I8,I4)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_I8);
 assert(v2.wType==DBTYPE_I4);

 const_cast<const oledb_lib::t_oledb_value__I8*>(&v1.valI8.QuadPart);
 const_cast<const oledb_lib::t_oledb_value__I4*>(&v2.valI4);

 return DBValueComparator::compare__std
         (v1.valI8.QuadPart,
          v2.valI4);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
