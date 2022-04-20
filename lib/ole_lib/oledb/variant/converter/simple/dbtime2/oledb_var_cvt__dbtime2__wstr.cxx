////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBTIME2->wstr implementation.
//                                                 Kovalenko Dmitry. 22.09.2010
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbtime2,wstr)::internal__convert_value_to_wstr
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==oledb_lib::oledb_typeid__DBTIME2);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=oledb_lib::dbtime2_to_wstr(dbvar.dbtime2Val);

 return S_OK;
}//internal__convert_value_to_wstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbtime2,wstr)

////////////////////////////////////////////////////////////////////////////////
