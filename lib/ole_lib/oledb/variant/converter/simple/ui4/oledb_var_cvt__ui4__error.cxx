////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_UI4->error implementation.
//                                                 Kovalenko Dmitry. 20.01.2012.
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(ui4,error)::internal__convert_value_to_error
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_UI4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 assert(sizeof(result->value())==sizeof(dbvar.valUI4));

 (*result)=static_cast<result_value_type>(dbvar.valUI4);

 return S_OK;
}//internal__convert_value_to_error

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(ui4,error)

////////////////////////////////////////////////////////////////////////////////
