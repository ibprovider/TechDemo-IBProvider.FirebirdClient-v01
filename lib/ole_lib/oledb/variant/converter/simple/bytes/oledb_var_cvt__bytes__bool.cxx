////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BYTES->bool implementation.
//                                                     Roman Piminov, 12.03.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bytes,bool)::internal__convert_value_to_bool
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BYTES);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(dbvar.bytesVal.byte_count()!=sizeof(VARIANT_BOOL))
  return DB_E_CANTCONVERTVALUE;

 CHECK_READ_PTR(dbvar.bytesVal.ptr,dbvar.bytesVal.byte_count());

 VARIANT_BOOL var_bool;

 memcpy(&var_bool,dbvar.bytesVal.ptr,sizeof(var_bool));

 (*result)=(var_bool!=VARIANT_FALSE);

 return S_OK;
}//internal__convert_value_to_bool

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bytes,bool)

////////////////////////////////////////////////////////////////////////////////
