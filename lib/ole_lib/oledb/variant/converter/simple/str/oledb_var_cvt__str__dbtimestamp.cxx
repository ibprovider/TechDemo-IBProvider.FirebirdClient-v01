////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_STR->dbtimestamp implementation.
//                                                 Kovalenko Dmitry. 05.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(str,dbtimestamp)::internal__convert_value_to_dbtimestamp
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_STR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DBTIMESTAMP x;

 if(!oledb_lib::str_to_dbtimestamp(&x,dbvar.strVal.ptr,dbvar.strVal.length()))
  return DB_E_CANTCONVERTVALUE;

 (*result)=x;

 return S_OK;
}//internal__convert_value_to_dbtimestamp

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(str,dbtimestamp)

////////////////////////////////////////////////////////////////////////////////
