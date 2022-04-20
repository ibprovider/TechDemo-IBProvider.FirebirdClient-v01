////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_UI1->ui4 implementation.
//                                                     Roman Piminov, 05.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(ui1,ui4)::internal__convert_value_to_ui4
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_UI1);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=dbvar.valUI1;

 return S_OK;
}//internal__convert_value_to_ui4

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(ui1,ui4)

////////////////////////////////////////////////////////////////////////////////
