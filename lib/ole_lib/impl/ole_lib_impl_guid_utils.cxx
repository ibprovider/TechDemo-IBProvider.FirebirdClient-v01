////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//CLSID --> TEXT conversions

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

////////////////////////////////////////////////////////////////////////////////
//TEXT --> CLSID conversions

//UNICODE ----------------------------------------------------------------
HRESULT string_to_clsid(structure::wstr_parameter str_clsid,GUID* pguid)
{
 assert(pguid!=NULL);

 if(LCPI_OS__CLSIDFromString(const_cast<wchar_t* const>(str_clsid.c_str()),pguid)==S_OK)
  return S_OK;

 return LCPI_OS__CLSIDFromProgID(str_clsid.c_str(),pguid);//second attempt
}//wstring_to_clsid

//ANSI -------------------------------------------------------------------
HRESULT string_to_clsid(const structure::str_parameter _str_clsid,GUID* pguid)
{
 assert(pguid!=NULL);

 const std::wstring str_clsid(structure::ansi_to_unicode(_str_clsid.c_str()));

 if(LCPI_OS__CLSIDFromString(const_cast<std::wstring::value_type*>(str_clsid.c_str()),pguid)==S_OK)
  return S_OK;

 return LCPI_OS__CLSIDFromProgID(str_clsid.c_str(),pguid);//second attempt
}//string_to_clsid

////////////////////////////////////////////////////////////////////////////////
//GUID to TEXT

static const char g_hex_chars_for_guid_to_text[16]
 ={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

//------------------------------------------------------------------------
template<typename TChar>
__STL_DEF_BASIC_STRING(TChar) guid_to_text(REFGUID guid)
{
 //12345678901234567890123456789012345678  38
 //{xxXXxxXX-xxXX-xxXX-xxXX-xxXXxxXXxxXX}

 TChar buffer[38];

 TChar* p=buffer;

#ifndef NDEBUG
 const TChar* const e=_END_(buffer);
#endif

 //-----------------------------------------
#define PUSH_CH(ch)                                                       \
 {                                                                        \
  assert(p!=e);                                                           \
                                                                          \
  (*p)=(ch);                                                              \
                                                                          \
  ++p;                                                                    \
 }

#define PUSH_HEX(x)                                                       \
 {                                                                        \
  assert(unsigned(x)<_DIM_(g_hex_chars_for_guid_to_text));                \
                                                                          \
  PUSH_CH(g_hex_chars_for_guid_to_text[unsigned(x)]);                     \
 }

#define PUSH_BYTE_AS_HEX(b)                                               \
 {                                                                        \
  const unsigned char b1=static_cast<unsigned char>(b);                   \
                                                                          \
  PUSH_HEX(b1>>4)                                                         \
  PUSH_HEX(0x0F&(b1))                                                     \
 }

 //-----------------------------------------
 PUSH_CH('{')                               //1
 PUSH_BYTE_AS_HEX(guid.Data1>>24)           //2 3
 PUSH_BYTE_AS_HEX(guid.Data1>>16)           //4 5
 PUSH_BYTE_AS_HEX(guid.Data1>>8)            //6 7
 PUSH_BYTE_AS_HEX(guid.Data1)               //8 9
 PUSH_CH('-')                               //10
 PUSH_BYTE_AS_HEX(guid.Data2>>8)            //11 12
 PUSH_BYTE_AS_HEX(guid.Data2)               //13 14
 PUSH_CH('-')                               //15
 PUSH_BYTE_AS_HEX(guid.Data3>>8)            //16 17
 PUSH_BYTE_AS_HEX(guid.Data3)               //18 19
 PUSH_CH('-')                               //20
 PUSH_BYTE_AS_HEX(guid.Data4[0])            //21 22
 PUSH_BYTE_AS_HEX(guid.Data4[1])            //23 24
 PUSH_CH('-')                               //25
 PUSH_BYTE_AS_HEX(guid.Data4[2])            //26 27
 PUSH_BYTE_AS_HEX(guid.Data4[3])            //28 29
 PUSH_BYTE_AS_HEX(guid.Data4[4])            //30 31
 PUSH_BYTE_AS_HEX(guid.Data4[5])            //32 33
 PUSH_BYTE_AS_HEX(guid.Data4[6])            //34 35
 PUSH_BYTE_AS_HEX(guid.Data4[7])            //36 37
 PUSH_CH('}')                               //38

//------------------------------------------
#undef PUSH_BYTE_AS_HEX
#undef PUSH_HEX
#undef PUSH_CH

//------------------------------------------
 assert(p==e);

 return __STL_DEF_BASIC_STRING(TChar)(buffer,_DIM_(buffer));
}//guid_to_text

//------------------------------------------------------------------------
std::wstring guid_to_wstring(REFGUID guid)
{
 return guid_to_text<wchar_t>(guid);
}//guid_to_wstring

//------------------------------------------------------------------------
std::string guid_to_string(REFGUID guid)
{
 return guid_to_text<char>(guid);
}//guid_to_string

//------------------------------------------------------------------------
t_string guid_to_tstr(REFGUID guid)
{
 return guid_to_text<structure::t_char>(guid);
}//guid_to_tstr

////////////////////////////////////////////////////////////////////////////////
