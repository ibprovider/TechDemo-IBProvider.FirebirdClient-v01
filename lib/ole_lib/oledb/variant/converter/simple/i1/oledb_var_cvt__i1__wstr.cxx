////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_I1->wstr implementation.
//                                                 Kovalenko Dmitry, 22.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(i1,wstr)::internal__convert_value_to_wstr
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_I1);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 wchar_t temp[64];

 assert(sizeof(dbvar.valI1)<=sizeof(long));

 _VERIFY_EQ(_GCRT_ltow_s(dbvar.valI1,temp,_DIM_(temp),10),0);

 wchar_t* const e=std::find(temp,_END_(temp),0);

 assert(e!=_END_(temp));

 if(e==_END_(temp))
  return E_FAIL;

 (*result).assign(temp,e);

 return S_OK;
}//internal__convert_value_to_wstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(i1,wstr)

////////////////////////////////////////////////////////////////////////////////
