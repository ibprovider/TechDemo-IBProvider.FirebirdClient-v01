////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_IUNKNOWN->bytes implementation.
//                                                Kovalenko Dmitry, 07.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(iunknown,bytes)::internal__convert_value_to_bytes
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_IUNKNOWN);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //-----------------------------------------------------------------------
 if(dbvar.unkVal.iid==IID_ISequentialStream)
 {
  if(dbvar.unkVal.ptr==NULL)
   return S_OK; //Zero length binary data

  const ole_lib::ISequentialStreamPtr
   spSS(structure::not_null_ptr(dbvar.unkVal.ptr));

  if(!spSS)
   return DB_E_CANTCONVERTVALUE;

  return DBVARIANT_CVT_UTILS::StorageObjectToBuffer_v2(spSS.ptr(),result);
 }//if STD_SS

 //-----------------------------------------------------------------------
 typedef t_oledb_type_cvt_impl_helper impl_helper;

 if(!impl_helper::CanHimselfDetectStorageObjectInterface(dbvar.unkVal.iid))
  return DB_E_CANTCONVERTVALUE;

 //-----------------------------------------------------------------------
 if(dbvar.unkVal.ptr==NULL)
  return S_OK; //Zero length binary data

 if(const ole_lib::ISequentialStreamPtr spSS=structure::not_null_ptr(dbvar.unkVal.ptr))
  return DBVARIANT_CVT_UTILS::StorageObjectToBuffer_v2(spSS.ptr(),result);

 return DB_E_CANTCONVERTVALUE;
}//internal__convert_value_to_bytes

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(iunknown,bytes)

////////////////////////////////////////////////////////////////////////////////
