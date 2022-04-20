////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Comparator.
//                                                Kovalenko Dmitry. 07.10.2017.

////////////////////////////////////////////////////////////////////////////////

OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__INSTANCE(VARIANT,VARIANT)

//------------------------------------------------------------------------
OLEDB_VARIANT_COMPARATOR2_CLASS__SIMPLE__COMPARE_VALUES2(VARIANT,VARIANT)
{
 assert(v1.TestDataStatus__IsOK());
 assert(v2.TestDataStatus__IsOK());

 //----------------------------------------------- unpack v1
 assert(v1.wType==DBTYPE_VARIANT);

 DBVARIANT::TCvtAdapter adapter1;

 const HRESULT hr1=adapter1.Unpack_Variant(v1);

 if(hr1==DB_E_CANTCONVERTVALUE)
  return DBVariantCmpCode__err__not_supported;

 if(FAILED(hr1))
  return DBVariantCmpCode__err__generic;

 assert(hr1==S_OK);

 assert(adapter1.dbvar().wType!=DBTYPE_VARIANT);

 //----------------------------------------------- unpack v2
 assert(v2.wType==DBTYPE_VARIANT);

 DBVARIANT::TCvtAdapter adapter2;

 const HRESULT hr2=adapter2.Unpack_Variant(v2);

 if(hr2==DB_E_CANTCONVERTVALUE)
  return DBVariantCmpCode__err__not_supported;

 if(FAILED(hr2))
  return DBVariantCmpCode__err__generic;

 assert(hr2==S_OK);

 assert(adapter2.dbvar().wType!=DBTYPE_VARIANT);

 //-----------------------------------------------
 return DBVariant_Compare2
         (ctx,
          adapter1.dbvar(),
          adapter2.dbvar());
}//compare_values

////////////////////////////////////////////////////////////////////////////////
