////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBTIME->dbtime2 implementation.
//                                                 Kovalenko Dmitry. 08.09.2010.
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbtime,dbtime2)::internal__convert_value_to_dbtime2
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_DBTIME);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 t_oledb_value__DBTIME2 x;

 x.hour     =dbvar.dbtimeVal.hour;
 x.minute   =dbvar.dbtimeVal.minute;
 x.second   =dbvar.dbtimeVal.second;
 x.fraction =0;

 (*result)=x;

 return S_OK;
}//internal__convert_value_to_dbtime2

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbtime,dbtime2)

////////////////////////////////////////////////////////////////////////////////
