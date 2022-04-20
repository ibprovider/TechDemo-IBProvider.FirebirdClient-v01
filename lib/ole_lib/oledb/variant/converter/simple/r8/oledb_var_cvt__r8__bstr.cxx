////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_R8->bstr implementation.
//                                                 Kovalenko Dmitry, 22.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(r8,bstr)::internal__convert_value_to_bstr
                                            (LPCCONVCONTEXT const DEBUG_CODE(pConvCtx),
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(pConvCtx);
 assert(dbvar.wType==DBTYPE_R8);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 wchar_t temp[64];

 const int l=_GCRT_swprintf_s_n1(temp,_DIM_(temp),L"%.16lg",dbvar.valR8);

 if(l<0)
  return DB_E_CANTCONVERTVALUE;

 assert(l<_DIM_(temp));

 return DBVARIANT_CVT_UTILS::WStrToBStr
         (result,
          temp,
          unsigned(l));
}//internal__convert_value_to_bstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(r8,bstr)

////////////////////////////////////////////////////////////////////////////////
