////////////////////////////////////////////////////////////////////////////////
//Type converter ARRAY|TYPE->variant implementation.
//                                                     Piminov Roman. 21.05.2008
////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(array_common,variant)::internal__convert_value_to_variant
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(OLEDB_EXTRACT_DBTYPE_INDICATOR(dbvar.wType)==DBTYPE_ARRAY);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 //---------------------------------
 const DBTYPE wElementType=OLEDB_EXTRACT_SIMPLE_DBTYPE(dbvar.wType);

 assert(wElementType!=DBTYPE_EMPTY);
 assert(wElementType!=DBTYPE_NULL);

 DBVARIANT::LPCTYPEINFO
  const pElementTypeInfo=DBVARIANT::GetInfo(wElementType);

 assert(pElementTypeInfo!=NULL);
 assert(pElementTypeInfo->varType!=DBTYPE_EMPTY);

 if(pElementTypeInfo->varType==DBTYPE_EMPTY)
  return DB_E_CANTCONVERTVALUE;

 VARTYPE ElementVarType=pElementTypeInfo->varType;

 if((pElementTypeInfo->varType&VT_ARRAY)==VT_ARRAY)
  ElementVarType=VT_VARIANT;

#ifndef NDEBUG
 DBVARIANT::LPCTYPEINFO
  const pElementTypeInfo2=DBVARIANT::GetInfo(ElementVarType);

 assert(pElementTypeInfo2);
 assert(pElementTypeInfo2->varType==ElementVarType);
#endif

 ole_lib::TSafeArray sa;

 if(dbvar.arrayVal2.ptr==NULL)
 {
  SAFEARRAYBOUND bound;

  bound.cElements=0;
  bound.lLbound=0;

  sa.ref_sa()=LCPI_OS__SafeArrayCreate(ElementVarType,1,&bound);

  if(sa.sa()==NULL)
   return E_OUTOFMEMORY;
 }
 else
 {
  assert(dbvar.arrayVal2.ptr!=NULL);

  const HRESULT
   to_array_hr
    =DBVariant__to_ARRAY_ex
      (pConvCtx,
       dbvar,
       DBTYPE(DBTYPE_ARRAY|ElementVarType),
       IID_IUnknown,
       &sa.ref_sa());

  if(FAILED(to_array_hr))
   return to_array_hr;

  assert(to_array_hr==S_OK);
 }//else

 //-----------------------------------------
 const HRESULT clear_hr=ole_lib::Variant_Clear(result);

 if(FAILED(clear_hr))
  return E_FAIL;

 assert(clear_hr==S_OK);

 assert(result->vt==VT_EMPTY);

 //-----------------------------------------
 assert(sa.sa()!=NULL);

 result->parray=sa.Release();
 result->vt    =VARTYPE(VT_ARRAY|ElementVarType);

 //-----------------------------------------
 return S_OK;
}//internal__convert_value_to_variant

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(array_common,variant)

////////////////////////////////////////////////////////////////////////////////
