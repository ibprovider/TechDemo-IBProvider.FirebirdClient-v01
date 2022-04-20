////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DATE->str implementation.
//                                                     Roman Piminov, 15.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(date,str)::internal__convert_value_to_str
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DATE);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DBTIMESTAMP ts;

 if(!date_to_dbstamp(dbvar.dateVal,&ts))
  return DB_E_CANTCONVERTVALUE;

 (*result)=dbstamp_to_str(ts);

 return S_OK;
}//internal__convert_value_to_str

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(date,str)

////////////////////////////////////////////////////////////////////////////////
