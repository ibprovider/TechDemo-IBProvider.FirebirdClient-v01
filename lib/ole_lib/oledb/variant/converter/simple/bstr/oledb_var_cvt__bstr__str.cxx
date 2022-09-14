////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BSTR->str implementation.
//                                                     Roman Piminov, 14.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bstr,str)::internal__convert_value_to_str
                                            (LPCCONVCONTEXT const pConvCtx,
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

 DBVARIANT dbvar2;

 dbvar2.SetDataStatus__OK();

 dbvar2.wstrVal.ptr=dbvar.bstrVal;
 dbvar2.wstrVal.len=LCPI_OS__SysStringLen(dbvar.bstrVal);

 dbvar2.wType=oledb_typeid__WSTR;

 const HRESULT cvt_hr2=DBVariant__to_STR_ex(pConvCtx,dbvar2,result);

 return cvt_hr2;
}//internal__convert_value_to_str

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bstr,str)

////////////////////////////////////////////////////////////////////////////////
