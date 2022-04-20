////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_UI8->ui1 implementation.
//                                                     Roman Piminov, 04.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(ui8,ui1)::internal__convert_value_to_ui1
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_UI8);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(!structure::can_numeric_cast<result_value_type>(dbvar.valUI8.QuadPart))
  return TDBTypeConverterCode::numeric_overflow;

 (*result)=static_cast<result_value_type>(dbvar.valUI8.QuadPart);

 return S_OK;
}//internal__convert_value_to_ui1

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(ui8,ui1)

////////////////////////////////////////////////////////////////////////////////
