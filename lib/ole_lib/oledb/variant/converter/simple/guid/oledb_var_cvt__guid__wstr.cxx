////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_GUID->wstr implementation.
//                                                     Roman Piminov, 17.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(guid,wstr)::internal__convert_value_to_wstr
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(pConvCtx);
 assert(dbvar.wType==DBTYPE_GUID);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //----
 wchar_t tmp[DBVARIANT_CVT_UTILS::c_min_buffer_size_for_cvt_from_guid_to_text];

 const size_t n=DBVARIANT_CVT_UTILS::GuidToWStr
                 (pConvCtx,
                  dbvar.guidVal,
                  _DIM_(tmp),
                  tmp);

 assert(n>0);
 assert(n<=_DIM_(tmp));

 result->assign(tmp,tmp+n);

 //----
 return S_OK;
}//internal__convert_value_to_wstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(guid,wstr)

////////////////////////////////////////////////////////////////////////////////
