////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_BYTES->bstr implementation.
//                                                     Roman Piminov, 18.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(bytes,bstr)::internal__convert_value_to_bstr
                                            (LPCCONVCONTEXT const DEBUG_CODE(pConvCtx),
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(pConvCtx);
 assert(dbvar.wType==DBTYPE_BYTES);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //[2018-01-12]
 CHECK_READ_PTR(dbvar.bytesVal.ptr,dbvar.bytesVal.len);

 CHECK_READ_PTR(dbvar.bytesVal.ptr,dbvar.bytesVal.byte_count());

 if(dbvar.bytesVal.byte_count()%sizeof(wchar_t))
  return DB_E_CANTCONVERTVALUE;

 if(!structure::can_numeric_cast<UINT>(dbvar.bytesVal.byte_count()))
  return DB_E_CANTCONVERTVALUE;

 assert(static_cast<UINT>(dbvar.bytesVal.byte_count())==dbvar.bytesVal.byte_count());

 BSTR bstrTmp=::SysAllocStringByteLen(reinterpret_cast<char*>(dbvar.bytesVal.ptr),
                                      static_cast<UINT>(dbvar.bytesVal.byte_count()));

 if(bstrTmp==NULL)
  return E_OUTOFMEMORY;

 result->set_not_null().value().AssignBStr(bstrTmp);

 assert(bstrTmp==NULL);

 return S_OK;
}//internal__convert_value_to_bstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(bytes,bstr)

////////////////////////////////////////////////////////////////////////////////
