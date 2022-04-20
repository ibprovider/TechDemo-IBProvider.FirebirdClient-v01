////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_IUNKNOWN->str implementation.
//                                                     Roman Piminov, 14.04.2008
////////////////////////////////////////////////////////////////////////////////
//class tag_cvt_funcs

class OLEDB_TYPE_CONVERTER_NAME(iunknown,str)::tag_cvt_funcs
{
 private:
  typedef tag_cvt_funcs                     self_type;

 public: //typedefs ------------------------------------------------------
  typedef OLEDB_TYPE_CONVERTER_NAME(iunknown,str)::LPCCONVCONTEXT LPCCONVCONTEXT;
  typedef OLEDB_TYPE_CONVERTER_NAME(iunknown,str)::result_type    result_type;

 public:
  static HRESULT From_NULL_PTR(LPCCONVCONTEXT const /*pConvCtx*/,
                               result_type*   const result)
  {
   assert(result);

   result->set_not_null().value().clear();

   return S_OK;
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
   {
    result->set_not_null().value().clear();

    return S_OK;
   }//if

   return t_oledb_type_cvt_impl_helper::StorageObjectToValue
           (pConvCtx,
            DBVariant__to_STR_ex,
            pSS,
            result);
  }//From_IBP_SS_WC

  //----------------------------------------------------------------------
  static HRESULT From_IBP_SS_MBC
                  (LPCCONVCONTEXT                                                   const DEBUG_CODE(pConvCtx),
                   lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_MultiByteChar* const pSS,
                   result_type*                                                     const result)
  {
   assert(pConvCtx);
   assert(result);

   if(!pSS)
   {
    result->set_not_null().value().clear();

    return S_OK;
   }//if

   return from_ibp_ss_mbc(pSS,
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
   {
    result->set_not_null().value().clear();

    return S_OK;
   }//if

   return from_ss(pSS,
                  result);
  }//From_STD_SS

 private:
  static HRESULT from_ibp_ss_mbc
                  (lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_MultiByteChar* pSS,
                   result_type*                                                     result);

  static HRESULT from_ss
                  (ISequentialStream* pSS,
                   result_type*       result);
};//class xxx::tag_cvt_funcs

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_NAME(iunknown,str)::tag_cvt_funcs::from_ibp_ss_mbc
           (lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_MultiByteChar* const pSS,
            result_type*                                                     const result)
{
 assert(pSS);
 assert(result);

 TDBVariantCharsWriter Chars;

 {
  const HRESULT hr=DBVARIANT_CVT_UTILS::StorageObjectToBuffer_v2(pSS,&Chars);

  if(FAILED(hr))
   return hr;

  assert(hr==S_OK);
 }//local

 std::string tmp;

 tmp.reserve(Chars.m_buffer.size());

 Chars.m_buffer.append_to(tmp);

 assert(tmp.size()==Chars.m_buffer.size());

 result->set_not_null().value().swap(tmp);

 return S_OK;
}//from_ibp_ss_mbc

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_NAME(iunknown,str)::tag_cvt_funcs::from_ss
                                            (ISequentialStream* const pSS,
                                             result_type*       const result)
{
 assert(pSS);
 assert(result);

 typedef TDBVariantCharsWriter chars_type;

 assert(sizeof(char)==1);

 assert(sizeof(chars_type::item_type)==sizeof(char));

 chars_type Chars;

 {
  const HRESULT hr=DBVARIANT_CVT_UTILS::StorageObjectToBuffer_v2(pSS,&Chars);

  if(FAILED(hr))
   return hr;

  assert(hr==S_OK);
 }//if

 std::string tmp_str;

 tmp_str.reserve(Chars.m_buffer.size());

 Chars.m_buffer.append_to(tmp_str);

 result->set_not_null().value().swap(tmp_str);

 return S_OK;
}//from_ss

////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(iunknown,str)::internal__convert_value_to_str
                                            (LPCCONVCONTEXT const pConvCtx,
                                             const DBVARIANT&     dbvar,
                                             result_type*   const result)const
{
 assert(dbvar.wType==DBTYPE_IUNKNOWN);
 assert(dbvar.TestDataStatus__IsOK());
 assert(result);

 return t_oledb_type_cvt_impl_helper::IUnknownToValue__CompleteImpl<tag_cvt_funcs>
         (pConvCtx,
          dbvar.unkVal,
          result);
}//internal__convert_value_to_str

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(iunknown,str)

////////////////////////////////////////////////////////////////////////////////
