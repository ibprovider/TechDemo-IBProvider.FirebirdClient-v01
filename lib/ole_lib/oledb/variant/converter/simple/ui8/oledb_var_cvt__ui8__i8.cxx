////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_UI8->i8 implementation.
//                                                     Roman Piminov, 01.04.2008
////////////////////////////////////////////////////////////////////////////////

#ifndef COMP_CONF_HAS_PROBLEM_WITH_CAN_NUMERIC_CAST_I64_UI64
# error "COMP_CONF_HAS_PROBLEM_WITH_CAN_NUMERIC_CAST_I64_UI64 is not defined"
#endif

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_NAME(ui8,i8)::internal__convert_value_to_i8
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_UI8);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

#if(COMP_CONF_HAS_PROBLEM_WITH_CAN_NUMERIC_CAST_I64_UI64)
 if(dbvar.valUI8.QuadPart>_I64_MAX)
  return TDBTypeConverterCode::numeric_overflow;
#else
 if(!structure::can_numeric_cast<result_value_type>(dbvar.valUI8.QuadPart))
  return TDBTypeConverterCode::numeric_overflow;
#endif

 (*result)=static_cast<result_value_type>(dbvar.valUI8.QuadPart);

 return S_OK;
}//internal__convert_value_to_i8

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(ui8,i8)

////////////////////////////////////////////////////////////////////////////////
