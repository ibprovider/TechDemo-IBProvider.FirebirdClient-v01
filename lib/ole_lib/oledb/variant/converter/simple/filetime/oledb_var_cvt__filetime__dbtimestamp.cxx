////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_FILETIME->dbtimestamp implementation.
//                                                  Kovalenko Dmitry, 25.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(filetime,dbtimestamp)::internal__convert_value_to_dbtimestamp
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_FILETIME);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(!filetime_to_dbstamp(dbvar.filetimeVal,&result->set_not_null().value()))
  return DB_E_CANTCONVERTVALUE;

 return S_OK;
}//internal__convert_value_to_dbtimestamp

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(filetime,dbtimestamp)

////////////////////////////////////////////////////////////////////////////////
