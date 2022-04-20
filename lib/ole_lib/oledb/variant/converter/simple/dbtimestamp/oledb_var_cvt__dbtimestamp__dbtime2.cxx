////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBTIMESTAMP->dbtime2 implementation.
//                                                 Kovalenko Dmitry. 08.09.2010
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbtimestamp,dbtime2)::internal__convert_value_to_dbtime2
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DBTIMESTAMP);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 t_oledb_value__DBTIME2 x;

 x.hour     =dbvar.dbstampVal.hour;
 x.minute   =dbvar.dbstampVal.minute;
 x.second   =dbvar.dbstampVal.second;
 x.fraction =dbvar.dbstampVal.fraction;

 (*result)=x;

 return S_OK;
}//internal__convert_value_to_dbtime2

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbtimestamp,dbtime2)

////////////////////////////////////////////////////////////////////////////////
