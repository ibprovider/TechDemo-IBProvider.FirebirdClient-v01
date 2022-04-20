////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BYTES->dbdate implementation.
//                                                     Roman Piminov, 23.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bytes,dbdate)::internal__convert_value_to_dbdate
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_BYTES);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 if(dbvar.bytesVal.byte_count()!=sizeof(result_value_type))
  return DB_E_CANTCONVERTVALUE;

 CHECK_READ_PTR(dbvar.bytesVal.ptr,dbvar.bytesVal.byte_count());

 result_value_type v;

 memcpy(&v,dbvar.bytesVal.ptr,sizeof(v));

 (*result)=v;

 return S_OK;
}//internal__convert_value_to_dbdate

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bytes,dbdate)

////////////////////////////////////////////////////////////////////////////////
