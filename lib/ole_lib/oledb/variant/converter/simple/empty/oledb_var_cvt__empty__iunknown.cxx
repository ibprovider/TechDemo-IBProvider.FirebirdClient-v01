////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_EMPTY->IUnknown implementation.
//                                                  Kovalenko Dmitry, 26.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(empty,iunknown)::internal__convert_value_to_iunknown
                                            (LPCCONVCONTEXT const UNUSED_ARG(pConvCtx),
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             REFIID               UNUSED_ARG(result_iid),
                                             result_type*   const DEBUG_CODE(result))const
{
 assert(dbvar.wType==DBTYPE_EMPTY);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return DB_E_CANTCONVERTVALUE;
}//internal__convert_value_to_iunknown

//------------------------------------------------------------------------
bool OLEDB_TYPE_CONVERTER_NAME(empty,iunknown)::CanConvertTo
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBBINDING&     Bind)const
{
 assert(OLEDB_EXTRACT_DBTYPE(Bind.wType)==DBTYPE_IUNKNOWN);

 if(Bind.pObject==NULL)
  return true;

 if(Bind.pObject->dwFlags!=STGM_READ)
  return false;

 return true;
}//CanConvertTo

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(empty,iunknown)

////////////////////////////////////////////////////////////////////////////////
