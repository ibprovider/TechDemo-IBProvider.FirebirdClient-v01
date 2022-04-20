////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BYTES->bytes implementation.
//                                                     Roman Piminov, 29.03.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bytes,bytes)::internal__convert_value_to_bytes
                                            (LPCCONVCONTEXT   /*pConvCtx*/,
                                             const DBVARIANT& dbvar,
                                             result_type*     result)const
{
 assert(dbvar.wType==DBTYPE_BYTES);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 CHECK_READ_PTR(dbvar.bytesVal.ptr,dbvar.bytesVal.byte_count())

 result->write(dbvar.bytesVal.ptr,dbvar.bytesVal.byte_count());

 return S_OK;
}//internal__convert_value_to_bytes

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bytes,bytes)

////////////////////////////////////////////////////////////////////////////////