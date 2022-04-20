////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBTIMESTAMP->wstr implementation.
//                                                 Kovalenko Dmitry. 22.09.2010
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbtimestamp,wstr)::internal__convert_value_to_wstr
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DBTIMESTAMP);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //-------
 result_value_type tmp(dbstamp_to_wstr(dbvar.dbstampVal));

 result->set_not_null().value().swap(tmp);

 //-------
 return S_OK;
}//internal__convert_value_to_wstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbtimestamp,wstr)

////////////////////////////////////////////////////////////////////////////////
