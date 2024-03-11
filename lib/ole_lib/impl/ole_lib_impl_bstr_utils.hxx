////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////

void FreeBStr(BSTR& bstr);

HRESULT CopyBStr2(BSTR Source,BSTR* pTarget);

////////////////////////////////////////////////////////////////////////////////
//ANSI --> BSTR

BSTR StringToBStr(const char* source,
                  size_t      source_len=-1,
                  bool        create_empty=false); //throw

HRESULT StringToBStr(BSTR*       bstr,
                     const char* source,
                     size_t      source_len=-1,
                     bool        create_empty=false); //throw

//------------------------------------------------------------------------
// std::string --> BSTR
inline BSTR StringToBStr(const std::string& source,bool create_empty=false)
{
 return StringToBStr(source.c_str(),source.size(),create_empty);
}

//------------------------------------------------------------------------
inline HRESULT StringToBStr(BSTR* bstr,const std::string& source,bool create_empty=false)
{
 return StringToBStr(bstr,source.c_str(),source.size(),create_empty);
}

////////////////////////////////////////////////////////////////////////////////
//BSTR --> ANSI

inline std::string BStrToString(std::string* const result,const BSTR bstr)
{
 return structure::unicode_to_ansi(result,bstr,(bstr?LCPI_OS__SysStringLen(bstr):0));
}

//------------------------------------------------------------------------
inline std::string BStrToString(const BSTR bstr)
{
 return structure::unicode_to_ansi(bstr,(bstr?LCPI_OS__SysStringLen(bstr):0));
}

////////////////////////////////////////////////////////////////////////////////
//BSTR --> UNICODE

inline std::wstring& BStrToWStr(std::wstring* const result,const BSTR source)
{
 if(!source)
  return result->clear(),*result;

 return result->assign(source,LCPI_OS__SysStringLen(source));
}//BStrToWStr

//------------------------------------------------------------------------
inline std::wstring BStrToWStr(const BSTR source)
{
 if(!source)
  return std::wstring();

 return std::wstring(source,LCPI_OS__SysStringLen(source));
}//BStrToWStr

// UNICODE -> BSTR -------------------------------------------------------
BSTR WStrToBStr(const wchar_t* source,
                size_t         source_len=-1,
                bool           create_empty=false); //throw

HRESULT WStrToBStr(BSTR*          bstr,
                   const wchar_t* source,
                   size_t         source_len=-1,
                   bool           create_empty=false);

//------------------------------------------------------------------------
inline BSTR WStrToBStr(const std::wstring& source,bool create_empty=false)//throw
{
 return WStrToBStr(source.c_str(),source.size(),create_empty);
}

//------------------------------------------------------------------------
inline HRESULT WStrToBStr(BSTR* bstr,const std::wstring& source,bool create_empty=false)
{
 return WStrToBStr(bstr,source.c_str(),source.size(),create_empty);
}

////////////////////////////////////////////////////////////////////////////////
//TSTR to BSTR

//ANSI version -----------------------------------------------------------
inline BSTR TStrToBStr(const char* source,size_t source_len=-1,bool create_empty=false)
{
 return StringToBStr(source,source_len,create_empty);
}

inline BSTR TStrToBStr(const std::string& source,bool create_empty=false)
{
 return StringToBStr(source.c_str(),source.size(),create_empty);
}

inline HRESULT TStrToBStr(BSTR* bstr,const char* source,size_t source_len=-1,bool create_empty=false)
{
 return StringToBStr(bstr,source,source_len,create_empty);
}

inline HRESULT TStrToBStr(BSTR* bstr,const std::string& source,bool create_empty=false)
{
 return StringToBStr(bstr,source.c_str(),source.size(),create_empty);
}

//UNICODE version --------------------------------------------------------
inline BSTR TStrToBStr(const wchar_t* source,size_t source_len=-1,bool create_empty=false)
{
 return WStrToBStr(source,source_len,create_empty);
}

inline BSTR TStrToBStr(const std::wstring& source,bool create_empty=false)
{
 return WStrToBStr(source.c_str(),source.size(),create_empty);
}

inline HRESULT TStrToBStr(BSTR* bstr,const wchar_t* source,size_t source_len=-1,bool create_empty=false)
{
 return WStrToBStr(bstr,source,source_len,create_empty);
}

inline HRESULT TStrToBStr(BSTR* bstr,const std::wstring& source,bool create_empty=false)
{
 return WStrToBStr(bstr,source.c_str(),source.size(),create_empty);
}

////////////////////////////////////////////////////////////////////////////////
//BSTR to TSTR

inline t_string BStrToTStr(const BSTR source)
{
 return structure::wstr_to_tstr(source,source?LCPI_OS__SysStringLen(source):0);
}//BStrToTStr

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_TEMPLATE_FUNC_SPECIALIZE_BY_RETURN)

template<class charT>
inline LCPI_STL_DEF_BASIC_STRING(charT) BStrToUnkStr(const BSTR bstr);

//------------------------------------------------------------------------
template<>
inline std::string BStrToUnkStr<char>(const BSTR bstr)
{
 return structure::unicode_to_ansi(bstr,bstr?LCPI_OS__SysStringLen(bstr):0);
}//BStrToUnkStr<char>

//------------------------------------------------------------------------
template<>
inline std::wstring BStrToUnkStr<wchar_t>(const BSTR bstr)
{
 return BStrToWStr(bstr);
}//BStrToUnkStr<wchar_t>

#endif //COMP_CONF_SUPPORT_TEMPLATE_FUNC_SPECIALIZE_BY_RETURN

////////////////////////////////////////////////////////////////////////////////

inline structure::t_const_wstr_box BStrToBox(const BSTR bstr)
{
 return structure::make_str_box(bstr,bstr?LCPI_OS__SysStringLen(bstr):0);
}//BStrToBox

////////////////////////////////////////////////////////////////////////////////
