////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_IUNKNOWN->bool implementation.
//                                                     Roman Piminov, 12.03.2008
////////////////////////////////////////////////////////////////////////////////
//class tag_cvt_funcs

class OLEDB_TYPE_CONVERTER_NAME(iunknown,bool)::tag_cvt_funcs
{
 public: //typedefs ------------------------------------------------------
  typedef OLEDB_TYPE_CONVERTER_NAME(iunknown,bool)::LPCCONVCONTEXT LPCCONVCONTEXT;
  typedef OLEDB_TYPE_CONVERTER_NAME(iunknown,bool)::result_type    result_type;

 public:
  static HRESULT From_NULL_PTR(LPCCONVCONTEXT const /*pConvCtx*/,
                               result_type*   const /*result*/)
  {
   return DB_E_CANTCONVERTVALUE;
  }//From_NULL_PTR

  //----------------------------------------------------------------------
  static HRESULT From_IBP_SS_WC
                  (LPCCONVCONTEXT                                              const pConvCtx,
                   lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_WideChar* const pSS,
                   result_type*                                                const result)
  {
   assert(pConvCtx);
   assert(result);

   if(!pSS)
    return DB_E_CANTCONVERTVALUE;

   return t_oledb_type_cvt_impl_helper::StorageObjectToValue
           (pConvCtx,
            DBVariant__to_BOOL_ex,
            pSS,
            result);
  }//From_IBP_SS_WC

  //----------------------------------------------------------------------
  static HRESULT From_IBP_SS_MBC
                  (LPCCONVCONTEXT                                                   const pConvCtx,
                   lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_MultiByteChar* const pSS,
                   result_type*                                                     const result)
  {
   assert(pConvCtx);
   assert(result);

   if(!pSS)
    return DB_E_CANTCONVERTVALUE;

   return t_oledb_type_cvt_impl_helper::StorageObjectToValue
           (pConvCtx,
            DBVariant__to_BOOL_ex,
            pSS,
            result);
  }//From_IBP_SS_MBC

  //----------------------------------------------------------------------
  static HRESULT From_STD_SS(LPCCONVCONTEXT     const DEBUG_CODE(pConvCtx),
                             ISequentialStream* const pSS,
                             result_type*       const result)
  {
   assert(pConvCtx);
   assert(result);

   if(!pSS)
    return DB_E_CANTCONVERTVALUE;

   VARIANT_BOOL tmp=VARIANT_FALSE;

   const HRESULT hr=DBVARIANT_CVT_UTILS::StorageObjectToSimpleType_v2
                    (pSS,
                     &tmp,
                     sizeof(tmp));

   if(FAILED(hr))
    return hr;

   assert(hr==S_OK);

   (*result)=(tmp!=VARIANT_FALSE);

   return S_OK;
  }//From_STD_SS
};//class xxx::tag_cvt_funcs

////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(iunknown,bool)::internal__convert_value_to_bool
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_IUNKNOWN);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result!=NULL);

 return t_oledb_type_cvt_impl_helper::IUnknownToValue__CompleteImpl<tag_cvt_funcs>
         (pConvCtx,
          dbvar.unkVal,
          result);
}//internal__convert_value_to_bool

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(iunknown,bool)

////////////////////////////////////////////////////////////////////////////////
