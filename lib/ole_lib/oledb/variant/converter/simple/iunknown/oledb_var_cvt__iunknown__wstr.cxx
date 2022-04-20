////////////////////////////////////////////////////////////////////////////////
//Type converter DBTYPE_IUNKNOWN->wstr implementation.
//                                                     Roman Piminov, 17.04.2008
////////////////////////////////////////////////////////////////////////////////
//class tag_cvt_funcs

class OLEDB_TYPE_CONVERTER_NAME(iunknown,wstr)::tag_cvt_funcs
{
 private:
  typedef tag_cvt_funcs                     self_type;

 public: //typedefs ------------------------------------------------------
  typedef OLEDB_TYPE_CONVERTER_NAME(iunknown,wstr)::LPCCONVCONTEXT LPCCONVCONTEXT;
  typedef OLEDB_TYPE_CONVERTER_NAME(iunknown,wstr)::result_type    result_type;

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
                  (LPCCONVCONTEXT                                              const DEBUG_CODE(pConvCtx),
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

   return self_type::from_ibp_ss_wc(pSS,
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
    result->set_not_null().value().clear();

    return S_OK;
   }//if

   return t_oledb_type_cvt_impl_helper::StorageObjectToValue
           (pConvCtx,
            DBVariant__to_WSTR_ex,
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
   {
    result->set_not_null().value().clear();

    return S_OK;
   }//if

   return self_type::from_ss(pSS,
                             result);
  }//From_STD_SS

 private:
  static HRESULT from_ibp_ss_wc
                  (lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_WideChar* pSS,
                   result_type*                                                result);

  static HRESULT from_ss
                  (ISequentialStream* pSS,
                   result_type*       result);
};//class xxx::tag_cvt_funcs

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_NAME(iunknown,wstr)::tag_cvt_funcs::from_ibp_ss_wc
         (lcpi::sdk::ibprovider::v05::IBP_ISequentialStream_WideChar* pSS,
          result_type*                                                result)
{
 assert(pSS);
 assert(result);

 TDBVariantWCharsWriter WChars;

 {
  const HRESULT hr=DBVARIANT_CVT_UTILS::StorageObjectToBuffer_v2(pSS,&WChars);

  if(FAILED(hr))
   return hr;

  assert(hr==S_OK);
 }//local

 std::wstring tmp;

 tmp.reserve(WChars.m_buffer.size());

 WChars.m_buffer.append_to(tmp);

 assert(tmp.size()==WChars.m_buffer.size());

 result->set_not_null().value().swap(tmp);

 return S_OK;
}//from_ibp_ss_wc

//------------------------------------------------------------------------
HRESULT OLEDB_TYPE_CONVERTER_NAME(iunknown,wstr)::tag_cvt_funcs::from_ss
                                            (ISequentialStream* const pSS,
                                             result_type*       const result)
{
 assert(pSS);
 assert(result);

 //---------
 typedef TDBVariantBytesWriter  bytes_type;

 bytes_type Bytes;

 {
  const HRESULT read_hr=DBVARIANT_CVT_UTILS::StorageObjectToBuffer_v2(pSS,&Bytes);

  if(FAILED(read_hr))
   return read_hr;

  assert(read_hr==S_OK);
 }//local

 //-----------------------------------------
 typedef wchar_t        char_type;
 typedef unsigned char  byte_type;

 assert(sizeof(byte_type)==1);

 if((Bytes.m_buffer.size()%sizeof(char_type))!=0)
  return DB_E_CANTCONVERTVALUE;

 std::wstring tmp_wstr;

 const size_t total_cch=Bytes.m_buffer.size()/sizeof(char_type);

 tmp_wstr.reserve(total_cch);

 {
  size_t sz=0;

  byte_type buffer[1024];

  for(const bytes_type::buffer_type::seg_header_type* seg=Bytes.m_buffer.head();
      seg;
      seg=seg->next)
  {
   assert(seg->used<=seg->size);

   for(size_t cb_copy=0;cb_copy!=seg->used;)
   {
    assert(cb_copy<seg->used);
    assert(sz<sizeof(buffer));

    const size_t cb=min(sizeof(buffer)-sz,seg->used-cb_copy);

    assert(cb>0);

    assert(sizeof(*seg->data())==sizeof(byte_type));

    memcpy(buffer+sz,seg->data()+cb_copy,cb);

    sz+=cb;

    cb_copy+=cb;

    assert(sz<=sizeof(buffer));

    if(sz==sizeof(buffer))
    {
     assert_hint((sz%sizeof(char_type))==0);

     tmp_wstr.append(reinterpret_cast<const char_type*>(buffer),sz/sizeof(char_type));

     sz=0;
    }//if
   }//for cb_copy
  }//for seg

  assert((sz%sizeof(char_type))==0);

  if((sz%sizeof(char_type))!=0)
   return E_UNEXPECTED;

  assert(sz<=sizeof(buffer));

  tmp_wstr.append(reinterpret_cast<const char_type*>(buffer),sz/sizeof(char_type));

  assert(tmp_wstr.size()==total_cch);
 }//local

 result->set_not_null().value().swap(tmp_wstr);

 return S_OK;
}//from_ss

////////////////////////////////////////////////////////////////////////////////

HRESULT OLEDB_TYPE_CONVERTER_NAME(iunknown,wstr)::internal__convert_value_to_wstr
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
}//internal__convert_value_to_wstr

//------------------------------------------------------------------------
DEFINE_OLEDB_TYPE_CONVERTER_OBJ(iunknown,wstr)

////////////////////////////////////////////////////////////////////////////////
