////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_EMPTY->ARRAY implementation.
//                                                  Kovalenko Dmitry, 05.06.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(empty,array)::internal__convert_value_to_array
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     DEBUG_CODE(dbvar),
                                             REFIID               /*result_iid*/,
                                             result_type*   const result)const
{
 assert(OLEDB_EXTRACT_DBTYPE_INDICATOR(m_wToType)==DBTYPE_ARRAY);
 assert(dbvar.wType==DBTYPE_EMPTY);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 (*result)=NULL;

 return DB_E_CANTCONVERTVALUE;
}//internal__convert_value_to_array

////////////////////////////////////////////////////////////////////////////////
