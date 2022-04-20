////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_ERROR->ui4 implementation.
//                                                 Kovalenko Dmitry. 20.01.2012.
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(error,ui4)::internal__convert_value_to_ui4
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_ERROR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 assert(sizeof(result->value())==sizeof(dbvar.scodeVal));

 (*result)=static_cast<result_value_type>(dbvar.scodeVal);

 return S_OK;
}//internal__convert_value_to_ui4

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(error,ui4)

////////////////////////////////////////////////////////////////////////////////
