////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_IUNKNOWN->bstr implementation.
//                                                     Roman Piminov, 18.04.2008
////////////////////////////////////////////////////////////////////////////////
//class tag_cvt_funcs

class OLEDB_TYPE_CONVERTER_NAME(iunknown,bstr)::tag_cvt_funcs
{
 private:
  typedef tag_cvt_funcs                     self_type;

 public: //typedefs ------------------------------------------------------
  typedef OLEDB_TYPE_CONVERTER_NAME(iunknown,bstr)::LPCCONVCONTEXT LPCCONVCONTEXT;
  typedef OLEDB_TYPE_CONVERTER_NAME(iunknown,bstr)::result_type    result_type;

 public:
  static HRESULT From_NULL_PTR(LPCCONVCONTEXT const DEBUG_CODE(pConvCtx),
                               result_type*   const result)
  {
   assert(pConvCtx);
   assert(result);

   return DBVARIANT_CVT_UTILS::EmptyBStr(result);
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
    return DBVARIANT_CVT_UTILS::EmptyBStr(result);
   }//if

   return self_type::from_ibp_ss_wc(pConvCtx,
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
   {
    return DBVARIANT_CVT_UTILS::EmptyBStr(result);
   }//if

   return t_oledb_type_cvt_impl_helper::StorageObjectToValue
           (pConvCtx,
            DBVariant__to_BSTR_ex,
            pSS,
            result);
  }//From_IBP_SS_MBC

  //----------------------------------------------------------------------
  static HRESULT From_STD_SS(LPCCONVCONTEXT     const pConvCtx,
                             ISequentialStream* const pSS,
                             result_type*       const result)
  {
   assert(pConvCtx);
   assert(result);

   if(!pSS)
   {
    return DBVARIANT_CVT_UTILS::EmptyBStr(result);
   }//if

   return self_type::from_ss(pConvCtx,
                             pSS,
                             result);
  }//From_STD_SS

 private:
  static HRESULT from_ibp_ss_wc
                  (LPCCONVCONTEXT                                              pConvCtx,
                   lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_WideChar* pSS,
                   result_type*                                                result);

  static HRESULT from_ss(LPCCONVCONTEXT     pConvCtx,
                         ISequentialStream* pSS,
                         result_type*       result);
};//class xxx::tag_cvt_funcs

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_NAME(iunknown,bstr)::tag_cvt_funcs::from_ibp_ss_wc
          (LPCCONVCONTEXT                                              const DEBUG_CODE(pConvCtx),
           lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_WideChar* const pSS,
           result_type*                                                const result)
{
 assert(pConvCtx);
 assert(pSS);
 assert(result);

 TDBVariantWCharsWriter WChars;

 {
  const HRESULT hr=DBVARIANT_CVT_UTILS::StorageObjectToBuffer_v2(pSS,&WChars);

  if(FAILED(hr))
   return hr;

  assert(hr==S_OK);
 }//local

 //-----------------------------------------
 if(WChars.m_buffer.empty())
 {
  return DBVARIANT_CVT_UTILS::EmptyBStr(result);
 }//if

 //-----------------------------------------
 assert(!WChars.m_buffer.empty());

 size_t const ch_size=sizeof(*((BSTR)NULL));

 assert(ch_size==sizeof(OLECHAR));

 size_t const result_cch=WChars.m_buffer.size();

 UINT const max_cch=structure::t_numeric_limits<UINT>::max_value()/ch_size;

 if(max_cch<result_cch)
  return DB_E_DATAOVERFLOW;

 UINT const cBytes=static_cast<UINT>(result_cch*ch_size);

 ole_lib::TBSTR tmp;

 tmp.ref_bstr()=::SysAllocStringByteLen(NULL,static_cast<UINT>(cBytes));

 if(tmp.bstr()==NULL)
  return E_OUTOFMEMORY;

 _VERIFY_EQ(WChars.m_buffer.copy(tmp.bstr(),result_cch),
            result_cch);

 result->set_not_null().value().swap(tmp);

 return S_OK;
}//from_ibp_ss_wc

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_NAME(iunknown,bstr)::tag_cvt_funcs::from_ss
                                            (LPCCONVCONTEXT     const DEBUG_CODE(pConvCtx),
                                             ISequentialStream* const pSS,
                                             result_type*       const result)
{
 assert(pConvCtx);
 assert(pSS);
 assert(result);

 TDBVariantBytesWriter Bytes;

 {
  const HRESULT hr=DBVARIANT_CVT_UTILS::StorageObjectToBuffer_v2(pSS,&Bytes);

  if(FAILED(hr))
   return hr;

  assert(hr==S_OK);
 }//local

 //-----------------------------------------
 if(Bytes.m_buffer.empty())
 {
  return DBVARIANT_CVT_UTILS::EmptyBStr(result);
 }//if

 //----------------------------------------- copy from Bytes into new BSTR
 assert(!Bytes.m_buffer.empty());

 size_t const ch_size=sizeof(*((BSTR)NULL));

 assert(ch_size==sizeof(OLECHAR));

 size_t const cBytes=Bytes.m_buffer.size();

 assert(cBytes>0);

 if((cBytes%ch_size)!=0)
  return DB_E_CANTCONVERTVALUE;

 if(!structure::can_numeric_cast<UINT>(cBytes))
  return DB_E_DATAOVERFLOW;

 ole_lib::TBSTR tmp;

 tmp.ref_bstr()=::SysAllocStringByteLen(NULL,static_cast<UINT>(cBytes));

 if(tmp.bstr()==NULL)
  return E_OUTOFMEMORY;

 _VERIFY_EQ(Bytes.m_buffer.copy_binary(tmp.bstr(),cBytes),
            cBytes);

 result->set_not_null().value().swap(tmp);

 return S_OK;
}//from_ss

////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(iunknown,bstr)::internal__convert_value_to_bstr
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
}//internal__convert_value_to_bstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(iunknown,bstr)

////////////////////////////////////////////////////////////////////////////////
