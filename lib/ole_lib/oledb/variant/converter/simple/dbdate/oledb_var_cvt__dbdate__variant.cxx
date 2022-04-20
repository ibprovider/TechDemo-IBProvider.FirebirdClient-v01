////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBDATE->variant implementation.
//                                                     Roman Piminov, 11.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbdate,variant)::internal__convert_value_to_variant
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DBDATE);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //-----------------------------------------
 DATE dt;

 if(!dbdate_to_date(dbvar.dbdateVal,dt))
  return DB_E_CANTCONVERTVALUE;

 //-----------------------------------------
 const HRESULT clear_hr=ole_lib::Variant_Clear(result);

 if(FAILED(clear_hr))
  return E_FAIL;

 assert(clear_hr==S_OK);

 assert(result->vt==VT_EMPTY);

 //-----------------------------------------
 result->date =dt;
 result->vt   =VT_DATE;

 //-----------------------------------------
 return S_OK;
}//internal__convert_value_to_variant

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbdate,variant)

////////////////////////////////////////////////////////////////////////////////
