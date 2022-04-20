////////////////////////////////////////////////////////////////////////////////
//DBVARIANT_CVT_UTILS Implementation.
//                                                Kovalenko Dmitry. 11.02.2010

////////////////////////////////////////////////////////////////////////////////

size_t DBVARIANT_CVT_UTILS::GuidToStr(const cvt_ctx_type* const pCvtCtx,
                                      const GUID&               guid,
                                      size_t              const buffer_size,
                                      char                      buffer[])
{
 CHECK_WRITE_TYPED_PTR(buffer,buffer_size)

 return self_type::Helper__GuidToText
         (pCvtCtx,
          guid,
          buffer_size,
          buffer);
}//GuidToStr

//-------------------------------------------------------------------------
size_t DBVARIANT_CVT_UTILS::GuidToWStr(const cvt_ctx_type* const pCvtCtx,
                                       const GUID&               guid,
                                       size_t              const buffer_size,
                                       wchar_t                   buffer[])
{
 CHECK_WRITE_TYPED_PTR(buffer,buffer_size)

 return self_type::Helper__GuidToText
         (pCvtCtx,
          guid,
          buffer_size,
          buffer);
}//GuidToStr

////////////////////////////////////////////////////////////////////////////////

HRESULT DBVARIANT_CVT_UTILS::StrToGUID(const char* const str,
                                       size_type   const length,
                                       GUID*       const pguid)
{
 return self_type::Helper__TextToGUID(str,length,pguid);
}//StrToGUID

//-------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::WStrToGUID(const wchar_t* const str,
                                        size_type      const length,
                                        GUID*          const pguid)
{
 return self_type::Helper__TextToGUID(str,length,pguid);
}//WStrToGUID

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::TStrToGUID(const char* const str,
                                        size_type   const length,
                                        GUID*       const pguid)
{
 return self_type::Helper__TextToGUID(str,length,pguid);
}//TStrToGUID - str version

//------------------------------------------------------------------------
HRESULT DBVARIANT_CVT_UTILS::TStrToGUID(const wchar_t* const str,
                                        size_type      const length,
                                        GUID*          const pguid)
{
 return self_type::Helper__TextToGUID(str,length,pguid);
}//TStrToGUID - wstr version

////////////////////////////////////////////////////////////////////////////////
