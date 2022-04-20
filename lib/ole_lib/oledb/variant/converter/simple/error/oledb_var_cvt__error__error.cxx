////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_ERROR->error implementation.
//                                                     Roman Piminov, 23.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(error,error)::internal__convert_value_to_error
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_ERROR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=dbvar.scodeVal;

 return S_OK;
}//internal__convert_value_to_error

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(error,error)

////////////////////////////////////////////////////////////////////////////////
