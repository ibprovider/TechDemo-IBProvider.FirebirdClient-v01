////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BOOL->i8 implementation.
//                                                     Roman Piminov, 01.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bool,i8)::internal__convert_value_to_i8
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BOOL);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=static_cast<result_value_type>(dbvar.boolVal?1:0);

 return S_OK;
}//internal__convert_value_to_i8

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bool,i8)

////////////////////////////////////////////////////////////////////////////////
