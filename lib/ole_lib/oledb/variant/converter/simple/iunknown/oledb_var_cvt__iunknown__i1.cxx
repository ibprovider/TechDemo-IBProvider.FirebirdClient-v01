////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_IUNKNOWN->i1 implementation.
//                                                     Roman Piminov, 29.03.2008
////////////////////////////////////////////////////////////////////////////////
//class tag_cvt_funcs

class OLEDB_TYPE_CONVERTER_NAME(iunknown,i1)::tag_cvt_funcs
{
 public: //typedefs ------------------------------------------------------
  typedef OLEDB_TYPE_CONVERTER_NAME(iunknown,i1)::LPCCONVCONTEXT LPCCONVCONTEXT;
  typedef OLEDB_TYPE_CONVERTER_NAME(iunknown,i1)::result_type    result_type;

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
            DBVariant__to_I1_ex,
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
            DBVariant__to_I1_ex,
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

   return DBVARIANT_CVT_UTILS::StorageObjectToSimpleType_v2
           (pSS,
            result);
  }//From_STD_SS
};//class xxx::tag_cvt_funcs

////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(iunknown,i1)::internal__convert_value_to_i1
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
}//internal__convert_value_to_i1

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(iunknown,i1)

////////////////////////////////////////////////////////////////////////////////
