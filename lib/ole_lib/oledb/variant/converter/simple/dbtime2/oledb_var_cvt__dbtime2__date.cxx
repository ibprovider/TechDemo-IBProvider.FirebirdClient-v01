////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_DBTIME2->date implementation.
//                                                 Kovalenko Dmitry. 09.09.2010
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(dbtime2,date)::internal__convert_value_to_date
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==oledb_lib::oledb_typeid__DBTIME2);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 DATE d(0);

 if(!dbtime2_to_date(dbvar.dbtime2Val,&d))
  return DB_E_CANTCONVERTVALUE;

 (*result)=d;

 return S_OK;
}//internal__convert_value_to_date

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(dbtime2,date)

////////////////////////////////////////////////////////////////////////////////
