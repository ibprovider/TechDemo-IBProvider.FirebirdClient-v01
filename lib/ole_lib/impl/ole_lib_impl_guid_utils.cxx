////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//CLSID --> TEXT conversions

#if 0 // [2022-09-22] Temporary removed. They must have a different meaning.

//UNICODE ----------------------------------------------------------------
std::wstring clsid_to_wstring(REFCLSID rclsid)
{
 OLECHAR wsz_guid[128];

 //len will be containing terminate null
 const int len=LCPI_OS__StringFromGUID2(rclsid,wsz_guid,_DIM_(wsz_guid)-1);

 assert(len>0);
 assert(len<_DIM_(wsz_guid));
                               //no terminate null
 return std::wstring(wsz_guid,len-1);
}//clsid_to_wstring

//ANSI -------------------------------------------------------------------
std::string clsid_to_string(REFCLSID rclsid)
{
 OLECHAR wsz_guid[128];

 //len will be containing terminal null
 const int len=LCPI_OS__StringFromGUID2(rclsid,wsz_guid,_DIM_(wsz_guid)-1);

 assert(len>0);
 assert(len<_DIM_(wsz_guid));
                               //no terminate null
 return structure::unicode_to_ansi(wsz_guid,len-1);
}//clsid_to_string

//TSTR -------------------------------------------------------------------
t_string clsid_to_tstr(REFCLSID rclsid)
{
 OLECHAR wsz_guid[128];

 //len will be containing terminal null
 const int len=LCPI_OS__StringFromGUID2(rclsid,wsz_guid,_DIM_(wsz_guid)-1);

 assert(len>0);
 assert(len<_DIM_(wsz_guid));
                               //no terminate null
 return structure::wstr_to_tstr(wsz_guid,len-1);
}//clsid_to_tstr

#endif // if 0

////////////////////////////////////////////////////////////////////////////////
//TEXT --> CLSID conversions

//UNICODE ----------------------------------------------------------------
HRESULT string_to_clsid(structure::wstr_parameter str_clsid,GUID* pclsid)
{
 assert(pclsid!=NULL);

 const wchar_t* const p=str_clsid.c_str();

 if(p==nullptr)
  return E_INVALIDARG;

 if((*p)==0)
  return CO_E_CLASSSTRING;

 if(p[0]==L'{')
 {
  if(::lcpi::lib::com::base::string_to_guid(p,pclsid))
   return S_OK;

  return CO_E_CLASSSTRING;
 }//if

 assert(p[0]!=L'{');

 //second attempt
 return LCPI_OS__CLSIDFromProgID(p,pclsid);
}//string_to_clsid - UNICODE

//ANSI -------------------------------------------------------------------
HRESULT string_to_clsid(const structure::str_parameter str_clsid,GUID* pclsid)
{
 assert(pclsid!=NULL);

 const std::wstring wstr_clsid(structure::ansi_to_unicode(str_clsid.c_str()));

 return string_to_clsid(wstr_clsid,pclsid);
}//string_to_clsid - ANSI

////////////////////////////////////////////////////////////////////////////////
//GUID to TEXT

structure::t_string guid_to_tstr(REFGUID guid)
{
 return lcpi::lib::com::base::detail::guid_to_text<structure::t_char>(guid);
}//guid_to_tstr

////////////////////////////////////////////////////////////////////////////////
