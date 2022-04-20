////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_CY->bytes implementation.
//                                                     Roman Piminov, 29.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(cy,bytes)::internal__convert_value_to_bytes
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_CY);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 result->write(&dbvar.valCY,sizeof(dbvar.valCY));

 return S_OK;
}//internal__convert_value_to_bytes

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(cy,bytes)

////////////////////////////////////////////////////////////////////////////////
