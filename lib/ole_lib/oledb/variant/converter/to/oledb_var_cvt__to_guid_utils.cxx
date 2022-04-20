////////////////////////////////////////////////////////////////////////////////
//GUID convertion utilities
//                                               Dmitry Kovalenko. 21.04.2008.

////////////////////////////////////////////////////////////////////////////////

HRESULT DBVARIANT::StrToGUID(const char* const str,
                             size_type   const length,
                             GUID*       const pguid)
{
 return dbvariant_utils::TextToGUID(str,length,pguid);
}//StrToGUID

//-------------------------------------------------------------------------
HRESULT DBVARIANT::WStrToGUID(const wchar_t* const str,
                              size_type      const length,
                              GUID*          const pguid)
{
 return dbvariant_utils::TextToGUID(str,length,pguid);
}//WStrToGUID

////////////////////////////////////////////////////////////////////////////////
