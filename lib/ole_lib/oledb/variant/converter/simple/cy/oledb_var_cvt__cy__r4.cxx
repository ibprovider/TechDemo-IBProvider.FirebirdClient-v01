////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_CY->r4 implementation.
//                                                     Roman Piminov, 02.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(cy,r4)::internal__convert_value_to_r4
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_CY);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DBVARIANT_CVT_UTILS::CYToR4(dbvar.valCY,result->set_not_null().value());
}//internal__convert_value_to_r4

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(cy,r4)

////////////////////////////////////////////////////////////////////////////////
