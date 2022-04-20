////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_UI8->bytes implementation.
//                                                     Roman Piminov, 29.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(ui8,bytes)::internal__convert_value_to_bytes
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_UI8);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 result->write(&dbvar.valUI8,sizeof(dbvar.valUI8));

 return S_OK;
}//internal__convert_value_to_bytes

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(ui8,bytes)

////////////////////////////////////////////////////////////////////////////////
