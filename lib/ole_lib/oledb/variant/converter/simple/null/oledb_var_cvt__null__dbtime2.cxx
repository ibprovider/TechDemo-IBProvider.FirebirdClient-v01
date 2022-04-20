////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_NULL->dbtime2 implementation.
//                                                Kovalenko Dmitry. 08.09.2010
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbnull,dbtime2)::internal__convert_value_to_dbtime2
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_NULL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return this->helper__convert_null_to_dbtime2(result);
}//internal__convert_value_to_dbtime2

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbnull,dbtime2)

////////////////////////////////////////////////////////////////////////////////
