////////////////////////////////////////////////////////////////////////////////
//Implementation of t_oledb_type_cvt_impl_helper
//                                                 Kovalenko Dmitry. 05.09.2012.

////////////////////////////////////////////////////////////////////////////////
//class t_oledb_type_cvt_impl_helper

bool t_oledb_type_cvt_impl_helper::CanHimselfDetectStorageObjectInterface
                                       (REFIID dbvar_unkVal_iid)
{
 if(dbvar_unkVal_iid==IID_IUnknown)
  return true;

 return false;
}//CanHimselfDetectStorageObjectInterface

//------------------------------------------------------------------------
bool t_oledb_type_cvt_impl_helper::IsRequestOf_DEFAULT_SEQ_STREAM(REFIID riid)
{
 typedef oledb_lib::TDBVariantSequentialStream sstream_type;

 return sstream_type::IsSupportIID(riid);
}//IsRequestOf_DEFAULT_SEQ_STREAM

//------------------------------------------------------------------------
HRESULT t_oledb_type_cvt_impl_helper::Create_DEFAULT_SEQ_STREAM
                                       (size_t                         const cb,
                                        const void*                    const pv,
                                        REFIID                               result_iid,
                                        t_oledb_value__CPP_IUNKNOWN_n* const result)
{
 assert(result!=NULL);

 if(!self_type::IsRequestOf_DEFAULT_SEQ_STREAM(result_iid))
  return E_NOINTERFACE;

 typedef oledb_lib::TDBVariantSequentialStream sstream_type;

 assert(sstream_type::IsSupportIID(result_iid));

 (*result)=sstream_type::Create(cb,pv);

 assert(!result->null());
 assert(result->value());

 return S_OK;
}//Create_DEFAULT_SEQ_STREAM

//------------------------------------------------------------------------
bool t_oledb_type_cvt_impl_helper::IsRequestOf_IBP_SEQ_STREAM_MBC(REFIID riid)
{
 return ole_lib::GuidEqual(riid,lcpi::sdk::ibprovider::v05::IID_IBP_ISequentialStream_MultiByteChar);
}//IsRequestOf_IBP_SEQ_STREAM_MBC

//------------------------------------------------------------------------
HRESULT t_oledb_type_cvt_impl_helper::Create_IBP_SEQ_STREAM_MBC
                                       (size_t                         const cch,
                                        const char*                    const pchars,
                                        t_oledb_value__CPP_IUNKNOWN_n* const result)
{
 assert(result);

 typedef TDBVariant_IBP_SequentialStream_MultiByteChar sstream_type;

 (*result)=sstream_type::Create(cch,pchars);

 assert(!result->null());
 assert(result->value());

 return S_OK;
}//Create_IBP_SEQ_STREAM_MBC

//------------------------------------------------------------------------
HRESULT t_oledb_type_cvt_impl_helper::Create_IBP_SEQ_STREAM_MBC
                                       (LPCCONVCONTEXT                 const pConvCtx,
                                        const DBVARIANT&                     dbvar,
                                        t_oledb_value__CPP_IUNKNOWN_n* const result)
{
 assert(result);

 t_oledb_value__CPP_STR_n str;

 const HRESULT hr=DBVariant__to_STR_ex(pConvCtx,dbvar,&str);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 if(str.null())
 {
  result->reset();

  return S_OK;
 }//if

 return self_type::Create_IBP_SEQ_STREAM_MBC(str.value().length(),
                                             str.value().c_str(),
                                             result);
}//Create_IBP_SEQ_STREAM_MBC

//------------------------------------------------------------------------
bool t_oledb_type_cvt_impl_helper::IsRequestOf_IBP_SEQ_STREAM_WC(REFIID riid)
{
 return ole_lib::GuidEqual(riid,lcpi::sdk::ibprovider::v05::IID_IBP_ISequentialStream_WideChar);
}//IsRequestOf_IBP_SEQ_STREAM_WC

//------------------------------------------------------------------------------
HRESULT t_oledb_type_cvt_impl_helper::Create_IBP_SEQ_STREAM_WC
                                       (size_t                         const cch,
                                        const wchar_t*                 const pchars,
                                        t_oledb_value__CPP_IUNKNOWN_n* const result)
{
 assert(result);

 typedef TDBVariant_IBP_SequentialStream_WideChar sstream_type;

 (*result)=sstream_type::Create(cch,pchars);

 assert(!result->null());
 assert(result->value());

 return S_OK;
}//Create_IBP_SEQ_STREAM_WC

//------------------------------------------------------------------------------
HRESULT t_oledb_type_cvt_impl_helper::Create_IBP_SEQ_STREAM_WC
                                       (LPCCONVCONTEXT                 const pConvCtx,
                                        const DBVARIANT&                     dbvar,
                                        t_oledb_value__CPP_IUNKNOWN_n* const result)
{
 assert(result);

 t_oledb_value__CPP_WSTR_n wstr;

 const HRESULT hr=DBVariant__to_WSTR_ex(pConvCtx,dbvar,&wstr);

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 if(wstr.null())
 {
  result->reset();

  return S_OK;
 }//if

 return self_type::Create_IBP_SEQ_STREAM_WC(wstr.value().length(),
                                            wstr.value().c_str(),
                                            result);
}//Create_IBP_SEQ_STREAM_WC

////////////////////////////////////////////////////////////////////////////////
