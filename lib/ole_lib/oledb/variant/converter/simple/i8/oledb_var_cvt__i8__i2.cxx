////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_I8->i2 implementation.
//                                                     Roman Piminov, 29.03.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(i8,i2)::internal__convert_value_to_i2
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_I8);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(!structure::can_numeric_cast<result_value_type>(dbvar.valI8.QuadPart))
  return TDBTypeConverterCode::numeric_overflow;

 (*result)=static_cast<result_value_type>(dbvar.valI8.QuadPart);

 return S_OK;
}//internal__convert_value_to_i2

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(i8,i2)

////////////////////////////////////////////////////////////////////////////////
