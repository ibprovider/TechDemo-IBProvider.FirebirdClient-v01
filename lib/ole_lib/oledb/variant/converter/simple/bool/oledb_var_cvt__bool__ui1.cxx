////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BOOL->ui1 implementation.
//                                                     Roman Piminov, 04.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bool,ui1)::internal__convert_value_to_ui1
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BOOL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=static_cast<result_value_type>(dbvar.boolVal?1:0);

 return S_OK;
}//internal__convert_value_to_ui1

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bool,ui1)

////////////////////////////////////////////////////////////////////////////////
