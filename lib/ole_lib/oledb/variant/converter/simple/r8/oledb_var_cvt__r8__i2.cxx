////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_R8->i2 implementation.
//                                                     Roman Piminov, 29.03.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(r8,i2)::internal__convert_value_to_i2
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_R8);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //The floor of 2.8 is 2.000000
 //The floor of -2.8 is -3.000000

 const double x=(dbvar.valR8<0)
                ?-floor(-dbvar.valR8+0.5)
                :floor(dbvar.valR8+0.5);

 if(x<structure::t_numeric_limits<result_value_type>::min_value() ||
    x>structure::t_numeric_limits<result_value_type>::max_value())
 {
  return TDBTypeConverterCode::numeric_overflow;
 }

 (*result)=static_cast<result_value_type>(x);

 return S_OK;
}//internal__convert_value_to_i2

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(r8,i2)

////////////////////////////////////////////////////////////////////////////////
