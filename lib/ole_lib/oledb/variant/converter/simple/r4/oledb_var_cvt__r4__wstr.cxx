////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_R4->wstr implementation.
//                                                 Kovalenko Dmitry, 22.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(r4,wstr)::internal__convert_value_to_wstr
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_R4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 wchar_t temp[64];

 const int l=_GCRT_swprintf_s_n1(temp,_DIM_(temp),L"%.9lg",double(dbvar.valR4));

 if(l<0)
  return DB_E_CANTCONVERTVALUE;

 assert(l<_DIM_(temp));

 result->assign(temp,temp+l);

 return S_OK;
}//internal__convert_value_to_wstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(r4,wstr)

////////////////////////////////////////////////////////////////////////////////
