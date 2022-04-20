////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_I4->error implementation.
//                                                 Kovalenko Dmitry. 27.12.2011.
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(i4,error)::internal__convert_value_to_error
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_I4);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 assert(sizeof(result->value())==sizeof(dbvar.valI4));

 (*result)=static_cast<result_value_type>(dbvar.valI4);

 return S_OK;
}//internal__convert_value_to_error

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(i4,error)

////////////////////////////////////////////////////////////////////////////////
