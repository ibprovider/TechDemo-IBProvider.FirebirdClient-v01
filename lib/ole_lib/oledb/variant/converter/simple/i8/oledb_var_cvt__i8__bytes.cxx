////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_I8->bytes implementation.
//                                                     Roman Piminov, 29.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(i8,bytes)::internal__convert_value_to_bytes
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_I8);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 result->write(&dbvar.valI8,sizeof(dbvar.valI8));

 return S_OK;
}//internal__convert_value_to_bytes

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(i8,bytes)

////////////////////////////////////////////////////////////////////////////////
