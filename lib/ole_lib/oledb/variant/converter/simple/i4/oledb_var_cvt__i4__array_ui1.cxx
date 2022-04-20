////////////////////////////////////////////////////////////////////////////////
//OLEDB Type converter: I4 to ARRAY_UI1
//                                                Kovalenko Dmitry. 19.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(i4,array_ui1)::internal__convert_value_to_array
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             REFIID               /*result_iid*/,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_I4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DBVARIANT_CVT_UTILS::BytesToArrayUI1(&dbvar.valI4,
                                             sizeof(dbvar.valI4),
                                             result);
}//internal__convert_value_to_array

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(i4,array_ui1)

////////////////////////////////////////////////////////////////////////////////
