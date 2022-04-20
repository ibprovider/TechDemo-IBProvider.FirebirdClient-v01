////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_I4->bool implementation.
//                                                     Roman Piminov, 12.03.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(i4,bool)::internal__convert_value_to_bool
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_I4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=(dbvar.valI4!=0);

 return S_OK;
}//internal__convert_value_to_bool

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(i4,bool)

////////////////////////////////////////////////////////////////////////////////
