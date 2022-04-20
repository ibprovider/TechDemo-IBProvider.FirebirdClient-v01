////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_I1->ui2 implementation.
//                                                     Roman Piminov, 05.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(i1,ui2)::internal__convert_value_to_ui2
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_I1);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(!structure::can_numeric_cast<result_value_type>(dbvar.valI1))
  return TDBTypeConverterCode::numeric_overflow;

 (*result)=static_cast<result_value_type>(dbvar.valI1);

 return S_OK;
}//internal__convert_value_to_ui2

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(i1,ui2)

////////////////////////////////////////////////////////////////////////////////
