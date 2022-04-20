////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_FILETIME->str implementation.
//                                                  Kovalenko Dmitry, 25.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(filetime,str)::internal__convert_value_to_str
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_FILETIME);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DBTIMESTAMP ts;

 if(!filetime_to_dbstamp(dbvar.filetimeVal,&ts))
  return DB_E_CANTCONVERTVALUE;

 (*result)=dbstamp_to_str(ts);

 return S_OK;
}//internal__convert_value_to_str

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(filetime,str)

////////////////////////////////////////////////////////////////////////////////
