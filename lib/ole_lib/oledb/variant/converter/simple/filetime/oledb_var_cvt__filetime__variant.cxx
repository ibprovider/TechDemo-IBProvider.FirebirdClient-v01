////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_FILETIME->variant implementation.
//                                                 Kovalenko Dmitry, 25.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(filetime,variant)::internal__convert_value_to_variant
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_FILETIME);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //----------------------------------
 SYSTEMTIME st;

 if(!::FileTimeToSystemTime(&dbvar.filetimeVal,&st))
  return DB_E_CANTCONVERTVALUE;

 DATE dt;

 if(LCPI_OS__SystemTimeToVariantTime(&st,&dt)==FALSE)
  return DB_E_CANTCONVERTVALUE;

 //----------------------------------
 const HRESULT clear_hr=ole_lib::Variant_Clear(result);

 if(FAILED(clear_hr))
  return E_FAIL;

 assert(clear_hr==S_OK);

 assert(result->vt==VT_EMPTY);

 //----------------------------------
 result->date =dt;
 result->vt   =VT_DATE;

 //----------------------------------
 return S_OK;
}//internal__convert_value_to_variant

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(filetime,variant)

////////////////////////////////////////////////////////////////////////////////
