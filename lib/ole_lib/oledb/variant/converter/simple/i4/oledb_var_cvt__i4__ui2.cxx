////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_I4->ui2 implementation.
//                                                     Roman Piminov, 05.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(i4,ui2)::internal__convert_value_to_ui2
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_I4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(!structure::can_numeric_cast<result_value_type>(dbvar.valI4))
  return TDBTypeConverterCode::numeric_overflow;

 (*result)=static_cast<result_value_type>(dbvar.valI4);

 return S_OK;
}//internal__convert_value_to_ui2

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(i4,ui2)

////////////////////////////////////////////////////////////////////////////////
