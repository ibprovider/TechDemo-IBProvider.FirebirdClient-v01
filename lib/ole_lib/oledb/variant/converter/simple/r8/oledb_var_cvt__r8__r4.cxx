////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_R8->r4 implementation.
//                                                     Roman Piminov, 02.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(r8,r4)::internal__convert_value_to_r4
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_R8);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(dbvar.valR8<structure::t_numeric_limits<result_value_type>::min_value() ||
    dbvar.valR8>structure::t_numeric_limits<result_value_type>::max_value())
 {
  return TDBTypeConverterCode::numeric_overflow;
 }

 (*result)=static_cast<result_value_type>(dbvar.valR8);

 return S_OK;
}//internal__convert_value_to_r4

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(r8,r4)

////////////////////////////////////////////////////////////////////////////////
