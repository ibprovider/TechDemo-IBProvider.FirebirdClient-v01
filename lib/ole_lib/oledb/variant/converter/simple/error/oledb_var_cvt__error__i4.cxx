////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_ERROR->i4 implementation.
//                                                 Kovalenko Dmitry. 27.12.2012.
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(error,i4)::internal__convert_value_to_i4
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_ERROR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 assert(sizeof(result->value())==sizeof(dbvar.scodeVal));

 (*result)=dbvar.scodeVal;

 return S_OK;
}//internal__convert_value_to_i4

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(error,i4)

////////////////////////////////////////////////////////////////////////////////
