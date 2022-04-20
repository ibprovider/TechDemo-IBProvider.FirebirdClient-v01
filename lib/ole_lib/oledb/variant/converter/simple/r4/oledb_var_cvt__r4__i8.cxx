////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_R4->i8 implementation.
//                                                     Roman Piminov, 01.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(r4,i8)::internal__convert_value_to_i8
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_R4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //The floor of 2.8 is 2.000000
 //The floor of -2.8 is -3.000000

 const float x=(dbvar.valR4<0)
                ?-floor(float(-dbvar.valR4+0.5F))
                :floor(float(dbvar.valR4+0.5F));

 if(x<structure::t_numeric_limits<result_value_type>::min_value() ||
    x>structure::t_numeric_limits<result_value_type>::max_value())
 {
  return TDBTypeConverterCode::numeric_overflow;
 }

 (*result)=static_cast<result_value_type>(x);

 return S_OK;
}//internal__convert_value_to_i8

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(r4,i8)

////////////////////////////////////////////////////////////////////////////////
