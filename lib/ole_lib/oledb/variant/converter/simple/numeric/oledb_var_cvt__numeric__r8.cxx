////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_NUMERIC->r8 implementation.
//                                                     Roman Piminov, 03.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(numeric,r8)::internal__convert_value_to_r8
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_NUMERIC);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DBVARIANT_CVT_UTILS::NumericToR8(dbvar.dbnumVal,
                                         &result->set_not_null().value());
}//internal__convert_value_to_r8

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(numeric,r8)

////////////////////////////////////////////////////////////////////////////////
