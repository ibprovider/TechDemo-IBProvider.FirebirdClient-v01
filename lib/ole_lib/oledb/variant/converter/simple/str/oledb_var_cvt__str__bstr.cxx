////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_STR->bstr implementation.
//                                                     Roman Piminov, 18.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(str,bstr)::internal__convert_value_to_bstr
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(pConvCtx);
 assert(dbvar.wType==DBTYPE_STR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //[2018-01-12]
 CHECK_READ_TYPED_PTR(dbvar.strVal.ptr,dbvar.strVal.len);

 //
 // STR -> WSTR -> BSTR
 //

 t_oledb_value__CPP_WSTR_n tmp_wstr;

 const HRESULT cvt_hr1=DBVariant__to_WSTR_ex(pConvCtx,dbvar,&tmp_wstr);

 if(FAILED(cvt_hr1))
  return cvt_hr1;

 assert(cvt_hr1==S_OK);

 if(tmp_wstr.null())
 {
  //
  // [2022-09-12] Not expected.
  //
  assert(false);

  return E_UNEXPECTED;
 }//if

 DBVARIANT dbvar2;

 dbvar2.SetDataStatus__OK();

 dbvar2.wstrVal.ptr=const_cast<WCHAR*>(tmp_wstr.value().c_str());
 dbvar2.wstrVal.len=tmp_wstr.value().size();

 dbvar2.wType=oledb_typeid__WSTR;

 const HRESULT cvt_hr2=DBVariant__to_BSTR_ex(pConvCtx,dbvar2,result);

 return cvt_hr2;
}//internal__convert_value_to_bstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(str,bstr)

////////////////////////////////////////////////////////////////////////////////
