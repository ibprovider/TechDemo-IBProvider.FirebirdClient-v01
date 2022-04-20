////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BSTR->date implementation.
//                                                     Roman Piminov, 22.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bstr,date)::internal__convert_value_to_date
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DATE x;

 const size_t bstrLen=dbvar.bstrVal?::SysStringLen(dbvar.bstrVal):0;

 if(!oledb_lib::str_to_date(&x,dbvar.bstrVal,bstrLen))
  return DB_E_CANTCONVERTVALUE;

 (*result)=x;

 return S_OK;
}//internal__convert_value_to_date

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bstr,date)

////////////////////////////////////////////////////////////////////////////////
