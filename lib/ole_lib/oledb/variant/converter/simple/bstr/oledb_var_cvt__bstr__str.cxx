////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BSTR->str implementation.
//                                                     Roman Piminov, 14.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bstr,str)::internal__convert_value_to_str
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BSTR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(dbvar.bstrVal==NULL)
 {
  result->set_not_null().value().erase();

  return S_OK;
 }

 bool error=false;

 std::string tmp;

 structure::unicode_to_ansi
  (&tmp,
   dbvar.bstrVal,
   LCPI_OS__SysStringLen(dbvar.bstrVal),
   &error);

 if(error)
  return DB_E_CANTCONVERTVALUE;

 result->set_not_null().value().swap(tmp);

 return S_OK;
}//internal__convert_value_to_str

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bstr,str)

////////////////////////////////////////////////////////////////////////////////
