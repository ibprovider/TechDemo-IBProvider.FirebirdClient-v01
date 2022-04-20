////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBDATE->dbtime implementation.
//                                                     Roman Piminov, 23.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbdate,dbtime)::internal__convert_value_to_dbtime
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DBDATE);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=__null_dbtime__;

 return S_OK;
}//internal__convert_value_to_dbtime

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbdate,dbtime)

////////////////////////////////////////////////////////////////////////////////
