////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_I1->str implementation.
//                                                     Roman Piminov, 15.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(i1,str)::internal__convert_value_to_str
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_I1);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 char temp[64];

 assert(sizeof(dbvar.valI1)<=sizeof(long));

 _VERIFY_EQ(_GCRT_ltoa_s(dbvar.valI1,temp,_DIM_(temp),10),0);

 char* const e=std::find(temp,_END_(temp),0);

 assert(e!=_END_(temp));

 if(e==_END_(temp))
  return E_FAIL;

 (*result).assign(temp,e);

 return S_OK;
}//internal__convert_value_to_str

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(i1,str)

////////////////////////////////////////////////////////////////////////////////
