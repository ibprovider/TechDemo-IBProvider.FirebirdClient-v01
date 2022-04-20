////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBTIME2->bytes implementation.
//                                                 Kovalenko Dmitry. 09.09.2010
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbtime2,bytes)::internal__convert_value_to_bytes
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==oledb_lib::oledb_typeid__DBTIME2);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 result->write(&dbvar.dbtime2Val,sizeof(dbvar.dbtime2Val));

 return S_OK;
}//internal__convert_value_to_bytes

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbtime2,bytes)

////////////////////////////////////////////////////////////////////////////////
