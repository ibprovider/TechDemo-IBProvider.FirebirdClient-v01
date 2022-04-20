////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_I1->r8 implementation.
//                                                     Roman Piminov, 03.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(i1,r8)::internal__convert_value_to_r8
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_I1);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=static_cast<result_value_type>(dbvar.valI1);

 return S_OK;
}//internal__convert_value_to_r8

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(i1,r8)

////////////////////////////////////////////////////////////////////////////////
