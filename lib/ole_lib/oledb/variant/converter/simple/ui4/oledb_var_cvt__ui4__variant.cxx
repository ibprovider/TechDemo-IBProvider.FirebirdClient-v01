////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_UI4->variant implementation.
//                                                     Roman Piminov, 09.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(ui4,variant)::internal__convert_value_to_variant
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_UI4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //----------------------------------
 DECIMAL dec;

 const HRESULT cvt_hr=DBVARIANT_CVT_UTILS::IntToDecimal
                       (dbvar.valUI4,
                        &dec,
                        0);
 if(FAILED(cvt_hr))
  return cvt_hr;

 assert(cvt_hr==S_OK);

 //----------------------------------
 return DBVARIANT_CVT_UTILS::DecimalToVariant(dec,result);
}//internal__convert_value_to_variant

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(ui4,variant)

////////////////////////////////////////////////////////////////////////////////
