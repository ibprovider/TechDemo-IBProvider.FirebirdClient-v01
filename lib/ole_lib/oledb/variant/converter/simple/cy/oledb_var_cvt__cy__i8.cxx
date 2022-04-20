////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_CY->i8 implementation.
//                                                     Roman Piminov, 01.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(cy,i8)::internal__convert_value_to_i8
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_CY);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DBVARIANT_CVT_UTILS::CYToInt(dbvar.valCY,result->set_not_null().value());
}//internal__convert_value_to_i8

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(cy,i8)

////////////////////////////////////////////////////////////////////////////////
