////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_I4->i4 implementation.
//                                                     Roman Piminov, 01.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(i4,i4)::internal__convert_value_to_i4
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_I4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=dbvar.valI4;

 return S_OK;
}//internal__convert_value_to_i4

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(i4,i4)

////////////////////////////////////////////////////////////////////////////////
