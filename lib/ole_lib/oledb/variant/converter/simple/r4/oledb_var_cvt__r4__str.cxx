////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_R4->str implementation.
//                                                     Roman Piminov, 15.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(r4,str)::internal__convert_value_to_str
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_R4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 char temp[64];

 const int l=_GCRT_sprintf_s_n1(temp,_DIM_(temp),"%.9lg",double(dbvar.valR4));

 if(l<0)
  return DB_E_CANTCONVERTVALUE;

 assert(l<_DIM_(temp));

 result->assign(temp,temp+l);

 return S_OK;
}//internal__convert_value_to_str

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(r4,str)

////////////////////////////////////////////////////////////////////////////////
