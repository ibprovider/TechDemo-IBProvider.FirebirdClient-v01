////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_UI4->i1 implementation.
//                                                     Roman Piminov, 25.03.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(ui4,i1)::internal__convert_value_to_i1
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_UI4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(!structure::can_numeric_cast<result_value_type>(dbvar.valUI4))
  return TDBTypeConverterCode::numeric_overflow;

 (*result)=static_cast<result_value_type>(dbvar.valUI4);

 return S_OK;
}//internal__convert_value_to_i1

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(ui4,i1)

////////////////////////////////////////////////////////////////////////////////
