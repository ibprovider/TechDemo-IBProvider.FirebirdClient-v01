////////////////////////////////////////////////////////////////////////////////
//Implementation of conversion utilities from <t_char.h>
//                                           Dmitry Kovalenko. 19 august,2002.
#ifndef _t_char_converter_CC_
#define _t_char_converter_CC_

#include <structure/utilities/string/string_builder.h>
#include <structure/t_simple_buffer.h>
#include <structure/t_limits.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containing

template<class unicode_string>
struct t_ansi_to_unicode;        //helper class

template<class ansi_string>
struct t_unicode_to_ansi;        //helper class

template<class dummy>
struct t_ansi1_to_ansi2;         //helper class

////////////////////////////////////////////////////////////////////////////////
//struct t_ansi_to_unicode

template<class unicode_string>
struct t_ansi_to_unicode
{
 private:
  typedef t_ansi_to_unicode<unicode_string>                 self_type;

 public:
  typedef unicode_string                                    string_type;
  typedef typename string_type::value_type                  char_type;
  typedef t_void_allocator                                  allocator_type;
  typedef t_typed_simple_buffer<char_type,allocator_type>   buffer_type;

  //convert 't' to 'result' and return 'result'
  static string_type& convert(string_type* result,const char* t,size_t n=-1,bool* error=NULL,UINT CodePage=CP_ACP);

  static string_type convert(const char* t,size_t n=-1,bool* error=NULL,UINT CodePage=CP_ACP);
};//struct t_ansi_to_unicode

////////////////////////////////////////////////////////////////////////////////
//template struct t_ansi_to_unicode

template<class unicode_string>
typename t_ansi_to_unicode<unicode_string>::string_type&
 t_ansi_to_unicode<unicode_string>::convert(string_type* const result,
                                            const char*  const str,
                                            size_t             str_len,
                                            bool*        const error,
                                            UINT         const CodePage)
{
 assert(result);

 if(error)
  (*error)=false;

 if(str_len==0)
  return result->erase();

 if(structure::is_negative_one(str_len))
 {
  if(str==nullptr)
   return result->erase();

  str_len=strlen(str);

  if(str_len==0)
   return result->erase();
 }
#ifndef NDEBUG
 else
 {
  assert_hint(!structure::is_negative_one(str_len));

  assert_hint(str_len>0);

  assert(str!=nullptr);

  CHECK_READ_TYPED_PTR(str,str_len);
 }//else
#endif

 assert_hint(str_len>0);

 if(str_len>size_t(t_numeric_limits<int>::max_value()))
  throw std::length_error("Length error in t_ansi_to_unicode::convert");

 const int int_str_len=static_cast<int>(str_len);

 assert_hint(int_str_len>0);

 //if int_str_len==-1 then MBTOWC include in wlen terminate null-char
 const int wlen=::MultiByteToWideChar(CodePage,0,str,int_str_len,NULL,0);

 assert(wlen>=0);

 if(wlen==0)//error
 {
#ifndef NDEBUG
  DWORD const dwLastError=::GetLastError();

  assert(dwLastError!=0);
#endif

  if(error)
   (*error)=true;

  return result->erase();
 }//if wlen==0

 //reserve memory for all symbols (without terminal symbol)
 assert(structure::can_numeric_cast<buffer_type::size_type>(wlen));

 buffer_type buf(static_cast<typename buffer_type::size_type>(wlen));

 assert_hint(int_str_len>0);

 const int wlen2=::MultiByteToWideChar(CodePage,0,str,int_str_len,buf.buffer(),wlen);

 if(wlen2==0)
 {
#ifndef NDEBUG
  DWORD const dwLastError=::GetLastError();

  assert(dwLastError!=0);
#endif

  if(error)
   (*error)=true;

  return result->erase();
 }//if wlen2==0

 assert(wlen>0);

 if(wlen!=wlen2)
 {
  assert_msg(false,"wlen: "<<wlen<<". wlen2: "<<wlen2);

  throw std::runtime_error("[BUG CHECK] unexpected error in t_ansi_to_unicode::convert. Check point: #001.");
 }//if

 result->assign(buf.buffer(),wlen);

 return *result;
}//t_ansi_to_unicode::convert (result...)

//------------------------------------------------------------------------
template<class unicode_string>
typename t_ansi_to_unicode<unicode_string>::string_type
 t_ansi_to_unicode<unicode_string>::convert(const char* const str,
                                            size_t      const str_len,
                                            bool*       const error,
                                            UINT        const CodePage)
{
 string_type result;

 return __STL_MOVE_VALUE(self_type::convert(&result,str,str_len,error,CodePage));
}//t_ansi_to_unicode::convert

////////////////////////////////////////////////////////////////////////////////
//inline implementation

inline std::wstring ansi_to_unicode(const char* t,size_t n,bool* error,UINT CodePage)
{
 typedef t_ansi_to_unicode<std::wstring> convertor_type;

 return convertor_type::convert(t,n,error,CodePage);
}//ansi_to_unicode

//------------------------------------------------------------------------
inline std::wstring ansi_to_unicode(t_const_str_box t,bool* error,UINT CodePage)
{
 typedef t_ansi_to_unicode<std::wstring> convertor_type;

 return convertor_type::convert(t.data(),t.size(),error,CodePage);
}//ansi_to_unicode

//------------------------------------------------------------------------
inline std::wstring& ansi_to_unicode(std::wstring* result,const char* t,size_t n,bool* error,UINT CodePage)
{
 typedef t_ansi_to_unicode<std::wstring> convertor_type;

 return convertor_type::convert(result,t,n,error,CodePage);
}//ansi_to_unicode

//------------------------------------------------------------------------
inline std::wstring& ansi_to_unicode(std::wstring* result,t_const_str_box t,bool* error,UINT CodePage)
{
 typedef t_ansi_to_unicode<std::wstring> convertor_type;

 return convertor_type::convert(result,t.data(),t.size(),error,CodePage);
}

////////////////////////////////////////////////////////////////////////////////
//struct t_unicode_to_ansi

template<class ansi_string>
struct t_unicode_to_ansi
{
 private:
  typedef t_unicode_to_ansi<ansi_string>                    self_type;

 public:
  typedef ansi_string                                       string_type;
  typedef typename string_type::value_type                  char_type;
  typedef t_void_allocator                                  allocator_type;
  typedef t_typed_simple_buffer<char_type,allocator_type>   buffer_type;

  //convert 't' to 'result' and resurn 'result'
  static string_type& convert(string_type* result,const wchar_t* t,size_t n=-1,bool* error=NULL,UINT CodePage=CP_ACP);

  static string_type  convert(const wchar_t* t,size_t n=-1,bool* error=NULL,UINT CodePage=CP_ACP);
};//struct t_unicode_to_ansi

////////////////////////////////////////////////////////////////////////////////
//template struct t_unicode_to_ansi

template<class ansi_string>
typename t_unicode_to_ansi<ansi_string>::string_type&
 t_unicode_to_ansi<ansi_string>::convert(string_type*   const result,
                                         const wchar_t* const wstr,
                                         size_t               wstr_len,
                                         bool*          const error,
                                         UINT           const CodePage)
{
 assert(result);

 if(error)
  (*error)=false;

 if(wstr_len==0)
  return result->erase();

 if(structure::is_negative_one(wstr_len))
 {
  if(wstr==nullptr)
   return result->erase();

  wstr_len=wcslen(wstr);

  if(wstr_len==0)
   return result->erase();
 }
#ifndef NDEBUG
 else
 {
  assert(!structure::is_negative_one(wstr_len));

  assert_hint(wstr_len>0);

  assert(wstr!=nullptr);

  CHECK_READ_TYPED_PTR(wstr,wstr_len);
 }//else
#endif

 assert_hint(wstr_len>0);

 if(wstr_len>size_t(t_numeric_limits<int>::max_value()))
  throw std::length_error("Length error in t_unicode_to_ansi::convert");

 const int int_wstr_len=static_cast<int>(wstr_len);

 assert_hint(int_wstr_len>0);

 //if int_wstr_len==-1, then WCTMB return length with terminate symbol
 const int alen=::WideCharToMultiByte(CodePage,0,wstr,int_wstr_len,NULL,0,NULL,NULL);

 assert(alen>=0);

 if(alen==0)//error
 {
#ifndef NDEBUG
  DWORD const dwLastError=::GetLastError();

  assert(dwLastError!=0);
#endif

  if(error)
   (*error)=true;

  return result->erase();
 }//if alen==0

 //reserve memory for all symbols (without terminal symbol)
 assert(structure::can_numeric_cast<buffer_type::size_type>(alen));

 buffer_type buf(static_cast<typename buffer_type::size_type>(alen));

 assert_hint(int_wstr_len>0);

 const int alen2=::WideCharToMultiByte(CodePage,0,wstr,int_wstr_len,buf.buffer(),alen,NULL,NULL);

 if(alen2==0)
 {
#ifndef NDEBUG
  DWORD const dwLastError=::GetLastError();

  assert(dwLastError!=0);
#endif

  if(error)
   (*error)=true;

  return result->erase();
 }//if alen2==0

 assert(alen>0);

 if(alen!=alen2)
 {
  assert_msg(false,"alen: "<<alen<<". alen2: "<<alen2);

  throw std::runtime_error("[BUG CHECK] unexpected error in t_unicode_to_ansi::convert. Check point: #001.");
 }//if

 result->assign(buf.buffer(),alen);

 return *result;
}//t_unicode_to_ansi::convert

//------------------------------------------------------------------------
template<class ansi_string>
typename t_unicode_to_ansi<ansi_string>::string_type
 t_unicode_to_ansi<ansi_string>::convert(const wchar_t* const wstr,
                                         size_t         const wstr_len,
                                         bool*          const error,
                                         UINT           const CodePage)
{
 string_type result;

 return __STL_MOVE_VALUE(self_type::convert(&result,wstr,wstr_len,error,CodePage));
}//t_unicode_to_ansi::convert

//////////////////////////////////////////////////////////////////////////
//inline implementation

inline std::string unicode_to_ansi(const wchar_t* t,size_t n,bool* error,UINT CodePage)
{
 typedef t_unicode_to_ansi<std::string> convertor_type;

 return convertor_type::convert(t,n,error,CodePage);
}

//------------------------------------------------------------------------
inline std::string unicode_to_ansi(t_const_wstr_box t,bool* error,UINT CodePage)
{
 typedef t_unicode_to_ansi<std::string> convertor_type;

 return convertor_type::convert(t.data(),t.size(),error,CodePage);
}

//------------------------------------------------------------------------
inline std::string& unicode_to_ansi(std::string* result,const wchar_t* t,size_t n,bool* error,UINT CodePage)
{
 typedef t_unicode_to_ansi<std::string> convertor_type;

 return convertor_type::convert(result,t,n,error,CodePage);
}

//------------------------------------------------------------------------
inline std::string& unicode_to_ansi(std::string* result,t_const_wstr_box t,bool* error,UINT CodePage)
{
 typedef t_unicode_to_ansi<std::string> convertor_type;

 return convertor_type::convert(result,t.data(),t.size(),error,CodePage);
}

////////////////////////////////////////////////////////////////////////////////
//functions for transparent conversion

inline std::wstring& tstr_to_tstr(std::wstring* result,const char* t,size_t n,bool* error,UINT CodePage)
{
 return ansi_to_unicode(result,t,n,error,CodePage);
}

//------------------------------------------------------------------------
inline std::string& tstr_to_tstr(std::string* result,const char* t,size_t n,bool* error,UINT /*CodePage*/)
{
 typedef basic_string_builder<std::string> str_builder;

 if(error!=NULL)
  (*error)=false;

 return str_builder::build(result,t,n);
}//tstr_to_tstr (ansi->ansi)

//------------------------------------------------------------------------
inline std::wstring& tstr_to_tstr(std::wstring* result,const std::string& s,bool* error,UINT CodePage)
{
 return ansi_to_unicode(result,s,error,CodePage);
}//tstr_to_tstr (ansi->unicode)

//------------------------------------------------------------------------
inline std::string& tstr_to_tstr(std::string* result,const std::string& s,bool* error,UINT /*CodePage*/)
{
 if(error!=NULL)
  (*error)=false;

 return (*result)=s;
}//tstr_to_tstr (ansi->ansi)

//------------------------------------------------------------------------
inline std::wstring& tstr_to_tstr(std::wstring* result,const wchar_t* t,size_t n,bool* error,UINT /*CodePage*/)
{
 typedef basic_string_builder<std::wstring> str_builder;

 if(error!=NULL)
  (*error)=false;

 return str_builder::build(result,t,n);
}//tstr_to_tstr (unicode->unicode)

//------------------------------------------------------------------------
inline std::string& tstr_to_tstr(std::string* result,const wchar_t* t,size_t n,bool* error,UINT CodePage)
{
 return unicode_to_ansi(result,t,n,error,CodePage);
}//tstr_to_tstr (unicode->ansi)

//------------------------------------------------------------------------
inline std::wstring& tstr_to_tstr(std::wstring* result,const std::wstring& s,bool* error,UINT /*CodePage*/)
{
 if(error!=NULL)
  (*error)=false;

 return (*result)=s;
}//tstr_to_tstr (unicode->unicode)

//------------------------------------------------------------------------
inline std::string& tstr_to_tstr(std::string* result,const std::wstring& s,bool* error,UINT CodePage)
{
 return unicode_to_ansi(result,s,error,CodePage);
}//tstr_to_tstr (unicode->ansi)

//TSTR --> ANSI ----------------------------------------------------------
inline std::string tstr_to_str(const char* const t)
{
 return tstr_to_str(t_const_str_box(t));
}//tstr_to_str

//------------------------------------------------------------------------
inline std::string tstr_to_str(const wchar_t* const t)
{
 return tstr_to_str(t_const_wstr_box(t));
}//tstr_to_str

//------------------------------------------------------------------------
//[2018-02-17]
//inline std::string tstr_to_str(const char* t,size_t n)
//{
// typedef basic_string_builder<std::string> str_builder;
//
// return str_builder::build(t,n);
//}//tstr_to_str
//
////------------------------------------------------------------------------
//inline std::string tstr_to_str(const wchar_t* t,size_t n)
//{
// return unicode_to_ansi(t,n);
//}//tstr_to_str

//------------------------------------------------------------------------
inline const std::string& tstr_to_str(const std::string& t)
{
 return t;
}//tstr_to_str

//------------------------------------------------------------------------
inline std::string tstr_to_str(const t_const_str_box& t)
{
 return t.make_str();
}//tstr_to_str

//------------------------------------------------------------------------
inline std::string tstr_to_str(const t_const_wstr_box& t)
{
 CHECK_READ_TYPED_PTR(t.data(),t.size());

 return unicode_to_ansi(t.data(),t.size());
}//tstr_to_str

//TSTR --> UNICODE -------------------------------------------------------
inline std::wstring tstr_to_wstr(const char* const t)
{
 return tstr_to_wstr(t_const_str_box(t));
}

//------------------------------------------------------------------------
inline std::wstring tstr_to_wstr(const wchar_t* const t)
{
 return tstr_to_wstr(t_const_wstr_box(t));
}

//------------------------------------------------------------------------
//inline std::wstring tstr_to_wstr(const char* t,size_t n)
//{
// return ansi_to_unicode(t,n);
//}
//
////------------------------------------------------------------------------
//inline std::wstring tstr_to_wstr(const wchar_t* t,size_t n)
//{
// typedef basic_string_builder<std::wstring> str_builder;
//
// return str_builder::build(t,n);
//}

//------------------------------------------------------------------------
inline const std::wstring& tstr_to_wstr(const std::wstring& t)
{
 return t;
}

//------------------------------------------------------------------------
inline std::wstring tstr_to_wstr(const t_const_str_box& t)
{
 CHECK_READ_TYPED_PTR(t.data(),t.size());

 return ansi_to_unicode(t.data(),t.size());
}

//------------------------------------------------------------------------
inline std::wstring tstr_to_wstr(const t_const_wstr_box& t)
{
 return t.make_str();
}

////////////////////////////////////////////////////////////////////////////////
//functions for transparent conversion

#ifndef _UNICODE  //TSTR IS ANSI

//ANSI --> TSTR
inline t_string tstr_to_tstr(const char* t,size_t n)
{
 typedef basic_string_builder<t_string> str_builder;

 return str_builder::build(t,n);
}//tstr_to_tstr

//------------------------------------------------------------------------
inline const t_string& tstr_to_tstr(const std::string& t)
{
 return t;
}//tstr_to_tstr

//------------------------------------------------------------------------
inline t_string str_to_tstr(const char* t,size_t n)
{
 typedef basic_string_builder<t_string> str_builder;

 return str_builder::build(t,n);
}//str_to_tstr

//------------------------------------------------------------------------
inline const t_string& str_to_tstr(const std::string& t)
{
 return t;
}

//UNICODE --> TSTR -------------------------------------------------------
inline t_string tstr_to_tstr(const wchar_t* t,size_t n)
{
 return unicode_to_ansi(t,n);
}//tstr_to_tstr

//------------------------------------------------------------------------
inline t_string tstr_to_tstr(const std::wstring& t)
{
 return unicode_to_ansi(t.c_str(),t.size());
}//tstr_to_tstr

//------------------------------------------------------------------------
inline t_string wstr_to_tstr(const wchar_t* t,size_t n)
{
 return unicode_to_ansi(t,n);
}//wstr_to_tstr

//------------------------------------------------------------------------
inline t_string wstr_to_tstr(const std::wstring& t)
{
 return unicode_to_ansi(t.c_str(),t.size());
}//wstr_to_tstr

#else //TSTR IS UNICODE

//ANSI --> TSTR ----------------------------------------------------------
inline t_string tstr_to_tstr(const char* t,size_t n)
{
 return ansi_to_unicode(t,n);
}//tstr_to_tstr

//------------------------------------------------------------------------
inline t_string tstr_to_tstr(const std::string& t)
{
 return ansi_to_unicode(t.c_str(),t.size());
}//tstr_to_tstr

//------------------------------------------------------------------------
inline t_string str_to_tstr(const char* t,size_t n)
{
 return ansi_to_unicode(t,n);
}//str_to_tstr

//------------------------------------------------------------------------
inline t_string str_to_tstr(const std::string& t)
{
 return ansi_to_unicode(t.c_str(),t.size());
}//str_to_tstr

//UNICODE --> TSTR -------------------------------------------------------
inline t_string tstr_to_tstr(const wchar_t* t,size_t n)
{
 typedef basic_string_builder<t_string> str_builder;

 return str_builder::build(t,n);
}//tstr_to_tstr

//------------------------------------------------------------------------
inline const t_string& tstr_to_tstr(const std::wstring& t)
{
 return t;
}//tstr_to_tstr

//------------------------------------------------------------------------
inline t_string wstr_to_tstr(const wchar_t* t,size_t n)
{
 typedef basic_string_builder<t_string> str_builder;

 return str_builder::build(t,n);
}//wstr_to_tstr

//------------------------------------------------------------------------
inline const t_string& wstr_to_tstr(const std::wstring& t)
{
 return t;
}//wstr_to_tstr

#endif //_UNICODE

////////////////////////////////////////////////////////////////////////////////
//class t_ansi1_to_ansi2

template<class ansi_string>
struct t_ansi1_to_ansi2
{
 public:
  typedef ansi_string                   string_type;

 public:
  t_ansi1_to_ansi2(UINT SourceCP,UINT DestCP);

  string_type& convert(string_type* result,const char* s,size_t n,bool* error)const;

  string_type  convert(const char* s,size_t n,bool* error)const;

 private:
  UINT m_SourceCP;
  UINT m_DestCP;
};//struct t_ansi1_to_ansi2

////////////////////////////////////////////////////////////////////////////////
//class t_ansi_to_oem

template<class ansi_string>
t_ansi1_to_ansi2<ansi_string>::t_ansi1_to_ansi2(UINT const SourceCP,
                                                UINT const DestCP)
 :m_SourceCP(SourceCP)
 ,m_DestCP(DestCP)
{;}

//------------------------------------------------------------------------
template<class ansi_string>
typename t_ansi1_to_ansi2<ansi_string>::string_type&
 t_ansi1_to_ansi2<ansi_string>::convert(string_type* const result,
                                        const char*  const s,
                                        size_t       const n,
                                        bool*        const error)const
{
 assert(result);

 result->erase();

 if(error!=NULL)
  (*error)=false;

 bool _err=false;

 std::wstring wstr;

 t_ansi_to_unicode<std::wstring>::convert(&wstr,
                                          s,
                                          n,
                                          &_err,
                                          m_SourceCP/*CP_ACP*/);

 if(!_err)
 {
  t_unicode_to_ansi<string_type>::convert(result,
                                          wstr.c_str(),
                                          wstr.size(),
                                          &_err,
                                          m_DestCP/*CP_OEMCP*/);
 }//if !_err

 if(error!=NULL)
  (*error)=_err;

 return *result;
}//t_ansi1_to_ansi2::convert

//------------------------------------------------------------------------
template<class ansi_string>
typename t_ansi1_to_ansi2<ansi_string>::string_type
 t_ansi1_to_ansi2<ansi_string>::convert(const char* const s,
                                        size_t      const n,
                                        bool*       const error)const
{
 string_type result;

 return __STL_MOVE_VALUE(this->convert(&result,s,n,error));
}//t_ansi1_to_ansi2::convert

////////////////////////////////////////////////////////////////////////////////
//ANSI --> OEM

inline std::string& ansi_to_oem(std::string* result,const char* s,size_t n,bool* error)
{
 return t_ansi1_to_ansi2<std::string>(CP_ACP,CP_OEMCP).convert(result,s,n,error);
}//ansi_to_oem

//------------------------------------------------------------------------
inline std::string& ansi_to_oem(std::string* result,t_const_str_box s,bool* error)
{
 return t_ansi1_to_ansi2<std::string>(CP_ACP,CP_OEMCP).convert(result,s.data(),s.size(),error);
}//ansi_to_oem

//------------------------------------------------------------------------
inline std::string ansi_to_oem(const char* s,size_t n,bool* error)
{
 return t_ansi1_to_ansi2<std::string>(CP_ACP,CP_OEMCP).convert(s,n,error);
}

//------------------------------------------------------------------------
inline std::string ansi_to_oem(t_const_str_box s,bool* error)
{
 return t_ansi1_to_ansi2<std::string>(CP_ACP,CP_OEMCP).convert(s.data(),s.size(),error);
}

////////////////////////////////////////////////////////////////////////////////
//OEM --> ANSI

inline std::string& oem_to_ansi(std::string* result,const char* s,size_t n,bool* error)
{
 return t_ansi1_to_ansi2<std::string>(CP_OEMCP,CP_ACP).convert(result,s,n,error);
}//oem_to_ansi

//------------------------------------------------------------------------
inline std::string& oem_to_ansi(std::string* result,t_const_str_box s,bool* error)
{
 return t_ansi1_to_ansi2<std::string>(CP_OEMCP,CP_ACP).convert(result,s.data(),s.size(),error);
}//oem_to_ansi

//------------------------------------------------------------------------
inline std::string oem_to_ansi(const char* s,size_t n,bool* error)
{
 return t_ansi1_to_ansi2<std::string>(CP_OEMCP,CP_ACP).convert(s,n,error);
}

//------------------------------------------------------------------------
inline std::string oem_to_ansi(t_const_str_box s,bool* error)
{
 return t_ansi1_to_ansi2<std::string>(CP_OEMCP,CP_ACP).convert(s.data(),s.size(),error);
}

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif