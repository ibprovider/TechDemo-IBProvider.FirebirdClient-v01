////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 01.11.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(I4,R8)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(I4,R8)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 assert(v1.wType==DBTYPE_I4);
 assert(v2.wType==DBTYPE_R8);

 const_cast<const oledb_lib::t_oledb_value__I4*>(&v1.valI4);
 const_cast<const oledb_lib::t_oledb_value__R8*>(&v2.valR8);

 const oledb_lib::t_oledb_value__R8 v1_as_R8=v1.valI4;

 assert(v1_as_R8==v1.valI4);

 return DBValueComparator::compare__std
         (v1_as_R8,
          v2.valR8);
}//compare_values

////////////////////////////////////////////////////////////////////////////////
