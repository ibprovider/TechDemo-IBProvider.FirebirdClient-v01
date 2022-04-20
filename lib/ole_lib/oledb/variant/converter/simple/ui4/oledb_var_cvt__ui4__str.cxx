////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_UI4->str implementation.
//                                                     Roman Piminov, 15.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(ui4,str)::internal__convert_value_to_str
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_UI4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 char temp[64];

 assert(sizeof(dbvar.valUI4)<=sizeof(unsigned long));

 _VERIFY_EQ(_GCRT_ultoa_s(dbvar.valUI4,temp,_DIM_(temp),10),0);

 char* const e=std::find(temp,_END_(temp),0);

 assert(e!=_END_(temp));

 if(e==_END_(temp))
  return E_FAIL;

 (*result).assign(temp,e);

 return S_OK;
}//internal__convert_value_to_str

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(ui4,str)

////////////////////////////////////////////////////////////////////////////////
