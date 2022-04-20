////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_UI1->r4 implementation.
//                                                     Roman Piminov, 02.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(ui1,r4)::internal__convert_value_to_r4
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_UI1);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=static_cast<result_value_type>(dbvar.valUI1);

 return S_OK;
}//internal__convert_value_to_r4

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(ui1,r4)

////////////////////////////////////////////////////////////////////////////////
