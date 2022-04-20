////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_UI4->bool implementation.
//                                                     Roman Piminov, 14.03.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(ui4,bool)::internal__convert_value_to_bool
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_UI4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=(dbvar.valUI4!=0);

 return S_OK;
}//internal__convert_value_to_bool

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(ui4,bool)

////////////////////////////////////////////////////////////////////////////////
