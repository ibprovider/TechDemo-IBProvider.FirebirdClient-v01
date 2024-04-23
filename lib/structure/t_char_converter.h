////////////////////////////////////////////////////////////////////////////////
//Chars convertions library
//                                                 Dmitry Kovalenko. 19.04.2004
#ifndef _lcpi_lib_structure__t_char_converter_H_
#define _lcpi_lib_structure__t_char_converter_H_

#include <structure/t_char_base.h>
#include <structure/t_const_str_box.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//functions for translating between ANSI and UNICODE

//ANSI --> UNICODE
inline std::wstring ansi_to_unicode(const char* t,size_t n,bool* error=NULL,UINT CodePage=CP_ACP);

inline std::wstring ansi_to_unicode(t_const_str_box t,bool* error=NULL,UINT CodePage=CP_ACP);

inline std::wstring& ansi_to_unicode(std::wstring* result,const char* t,size_t n,bool* error=NULL,UINT CodePage=CP_ACP);

inline std::wstring& ansi_to_unicode(std::wstring* result,t_const_str_box t,bool* error=NULL,UINT CodePage=CP_ACP);

//UNICODE --> ANSI
inline std::string unicode_to_ansi(const wchar_t* t,size_t n,bool* error=NULL,UINT CodePage=CP_ACP);

inline std::string unicode_to_ansi(t_const_wstr_box t,bool* error=NULL,UINT CodePage=CP_ACP);

inline std::string& unicode_to_ansi(std::string* result,const wchar_t* t,size_t n,bool* error=NULL,UINT CodePage=CP_ACP);

inline std::string& unicode_to_ansi(std::string* result,t_const_wstr_box t,bool* error=NULL,UINT CodePage=CP_ACP);

//ANSI --> OEM
inline std::string& ansi_to_oem(std::string* result,const char* s,size_t n,bool* error=NULL);

inline std::string& ansi_to_oem(std::string* result,t_const_str_box s,bool* error=NULL);

inline std::string  ansi_to_oem(const char* s,size_t n,bool* error=NULL);

inline std::string  ansi_to_oem(t_const_str_box s,bool* error=NULL);

//OEM --> ANSI
inline std::string& oem_to_ansi(std::string* result,const char* s,size_t n,bool* error=NULL);

inline std::string& oem_to_ansi(std::string* result,t_const_str_box s,bool* error=NULL);

inline std::string  oem_to_ansi(const char* s,size_t n,bool* error=NULL);

inline std::string  oem_to_ansi(t_const_str_box s,bool* error=NULL);

////////////////////////////////////////////////////////////////////////////////
//functions for transparent conversion

//from ANSI
inline std::wstring& tstr_to_tstr(std::wstring* result,t_const_str_box s,bool* error,UINT CodePage=CP_ACP);
inline std::string&  tstr_to_tstr(std::string*  result,t_const_str_box s,bool* error,UINT CodePage=CP_ACP);

inline std::wstring& tstr_to_tstr(std::wstring* result,t_const_str_box s);
inline std::string&  tstr_to_tstr(std::string*  result,t_const_str_box s);

//from UNICODE
inline std::wstring& tstr_to_tstr(std::wstring* result,t_const_wstr_box s,bool* error,UINT CodePage=CP_ACP);
inline std::string&  tstr_to_tstr(std::string*  result,t_const_wstr_box s,bool* error,UINT CodePage=CP_ACP);

inline std::wstring& tstr_to_tstr(std::wstring* result,t_const_wstr_box s);
inline std::string&  tstr_to_tstr(std::string*  result,t_const_wstr_box s);

//TSTR --> ANSI
inline std::string tstr_to_str(const char* t);

inline std::string tstr_to_str(const wchar_t* t);

//[2018-02-17]
//inline std::string tstr_to_str(const char* t,size_t n);
//
//inline std::string tstr_to_str(const wchar_t* t,size_t n);

inline const std::string& tstr_to_str(const std::string& t);

inline std::string tstr_to_str(const t_const_str_box& t);

inline std::string tstr_to_str(const t_const_wstr_box& t);

//TSTR --> UNICODE
inline std::wstring tstr_to_wstr(const char* t);

inline std::wstring tstr_to_wstr(const wchar_t* t);

//[2018-02-17]
//inline std::wstring tstr_to_wstr(const char* t,size_t n);
//
//inline std::wstring tstr_to_wstr(const wchar_t* t,size_t n);

inline const std::wstring& tstr_to_wstr(const std::wstring& t);

inline std::wstring tstr_to_wstr(const t_const_str_box& t);

inline std::wstring tstr_to_wstr(const t_const_wstr_box& t);

#ifndef _UNICODE  //TSTR IS ANSI

//ANSI --> TSTR
inline t_string tstr_to_tstr(const char* t,size_t n=-1);

inline const t_string& tstr_to_tstr(const std::string& s);

inline t_string str_to_tstr(const char* t,size_t n=-1);

inline const t_string& str_to_tstr(const std::string& t);

//UNICODE --> TSTR
inline t_string tstr_to_tstr(const wchar_t* t,size_t n=-1);

inline t_string tstr_to_tstr(const std::wstring& s);

inline t_string wstr_to_tstr(const wchar_t* t,size_t n=-1);

inline t_string wstr_to_tstr(const std::wstring& t);

#else //TSTR IS UNICODE

//ANSI --> TSTR
inline t_string tstr_to_tstr(const char* t,size_t n=-1);

inline t_string tstr_to_tstr(const std::string& t);

inline t_string str_to_tstr(const char* t,size_t n=-1);

inline t_string str_to_tstr(const std::string& t);

//UNICODE --> TSTR
inline t_string tstr_to_tstr(const wchar_t* t,size_t n=-1);

inline const t_string& tstr_to_tstr(const std::wstring& t);

inline t_string wstr_to_tstr(const wchar_t* t,size_t n=-1);

inline const t_string& wstr_to_tstr(const std::wstring& t);

#endif //_UNICODE

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_char_converter.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
