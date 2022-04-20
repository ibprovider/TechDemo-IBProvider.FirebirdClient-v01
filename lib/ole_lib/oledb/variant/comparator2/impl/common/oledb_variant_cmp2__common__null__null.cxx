////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 14.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(null,null)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES(null,null)
{
 //prevent compiler warnings 'unused argument'
 v1;v2;

 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 //----------------------------------------------- unpack v2
 assert(false);

 return DBVariantCmpCode__err__generic;
}//compare_values

////////////////////////////////////////////////////////////////////////////////
