////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_I8->bstr implementation.
//                                                 Kovalenko Dmitry, 22.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(i8,bstr)::internal__convert_value_to_bstr
                                            (LPCCONVCONTEXT const DEBUG_CODE(pConvCtx),
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(pConvCtx);
 assert(dbvar.wType==DBTYPE_I8);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 wchar_t temp[64];

 _VERIFY_EQ(_GCRT_i64tow_s(dbvar.valI8.QuadPart,temp,_DIM_(temp),10),0L);

 wchar_t* const e=std::find(temp,_END_(temp),0);

 assert(e!=_END_(temp));

 if(e==_END_(temp))
  return E_FAIL;

 return DBVARIANT_CVT_UTILS::WStrToBStr
         (result,
          temp,
          e-temp);
}//internal__convert_value_to_bstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(i8,bstr)

////////////////////////////////////////////////////////////////////////////////
