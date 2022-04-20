////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_STR->r8 implementation.
//                                                     Roman Piminov, 03.04.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(str,r8)::internal__convert_value_to_r8
                                            (LPCCONVCONTEXT const /*pConvCtx*/,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_STR);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 CHECK_READ_TYPED_PTR(dbvar.strVal.ptr,dbvar.strVal.length());

 result_value_type tmp(0);

 HRESULT const hr=DBVARIANT_CVT_UTILS::StrToR8(dbvar.strVal.ptr,
                                               dbvar.strVal.length(),
                                               &tmp);
 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 (*result)=tmp;

 return S_OK;
}//internal__convert_value_to_r8

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(str,r8)

////////////////////////////////////////////////////////////////////////////////
