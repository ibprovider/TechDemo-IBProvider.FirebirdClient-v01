////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_WSTR->date implementation.
//                                                     Roman Piminov, 22.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(wstr,date)::internal__convert_value_to_date
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_WSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DATE x;

 if(!oledb_lib::str_to_date(&x,dbvar.wstrVal.ptr,dbvar.wstrVal.length()))
  return DB_E_CANTCONVERTVALUE;

 (*result)=x;

 return S_OK;
}//internal__convert_value_to_date

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(wstr,date)

////////////////////////////////////////////////////////////////////////////////
