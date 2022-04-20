////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBTIME2->dbtime implementation.
//                                                 Kovalenko Dmitry. 09.09.2010.
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbtime2,dbtime)::internal__convert_value_to_dbtime
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==oledb_lib::oledb_typeid__DBTIME2);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 result->set_not_null();

 t_oledb_value__DBTIME x;

 x.hour     =dbvar.dbtime2Val.hour;
 x.minute   =dbvar.dbtime2Val.minute;
 x.second   =dbvar.dbtime2Val.second;

 (*result)=x;

 return S_OK;
}//internal__convert_value_to_dbtime

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbtime2,dbtime)

////////////////////////////////////////////////////////////////////////////////
