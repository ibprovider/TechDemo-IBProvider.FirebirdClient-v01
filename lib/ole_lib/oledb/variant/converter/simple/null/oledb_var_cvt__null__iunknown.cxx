////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_NULL->iunknown implementation.
//                                                  Kovalenko Dmitry, 26.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbnull,iunknown)::internal__convert_value_to_iunknown
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             REFIID               /*result_iid*/,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_NULL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return this->helper__convert_null_to_iunknown(result);
}//internal__convert_value_to_iunknown

//------------------------------------------------------------------------
bool OLEDB_TYPE_CONVERTER_NAME(dbnull,iunknown)::CanConvertTo
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBBINDING&     DEBUG_CODE(Bind))const
{
 assert(OLEDB_EXTRACT_DBTYPE(Bind.wType)==DBTYPE_IUNKNOWN);

 return true;
}//CanConvertTo

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbnull,iunknown)

////////////////////////////////////////////////////////////////////////////////
