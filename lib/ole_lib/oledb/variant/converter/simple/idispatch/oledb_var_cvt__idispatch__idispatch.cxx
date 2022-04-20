////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_IDISPATCH->idispatch implementation.
//                                                     Roman Piminov, 21.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(idispatch,idispatch)::internal__convert_value_to_idispatch
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_IDISPATCH);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=dbvar.dispVal.ptr;

 return S_OK;
}//internal__convert_value_to_idispatch

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(idispatch,idispatch)

////////////////////////////////////////////////////////////////////////////////
