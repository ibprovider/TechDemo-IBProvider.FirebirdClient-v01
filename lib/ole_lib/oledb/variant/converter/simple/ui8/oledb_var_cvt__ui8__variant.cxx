////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_UI8->variant implementation.
//                                                     Roman Piminov, 11.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(ui8,variant)::internal__convert_value_to_variant
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_UI8);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //----------------------------------
 DECIMAL dec;

 const HRESULT cvt_hr=DBVARIANT_CVT_UTILS::IntToDecimal
                       (dbvar.valUI8.QuadPart,
                        &dec,
                        0);
 if(FAILED(cvt_hr))
  return cvt_hr;

 assert(cvt_hr==S_OK);

 //----------------------------------
 return DBVARIANT_CVT_UTILS::DecimalToVariant(dec,result);
}//internal__convert_value_to_variant

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(ui8,variant)

////////////////////////////////////////////////////////////////////////////////
