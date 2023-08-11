////////////////////////////////////////////////////////////////////////////////
//OLE Automation Library. Wrapper for work with VARIANT data type
//                                                Dmitry Kovalenko. 23.10.2006.
#ifndef _ole_auto_variant_H_
#define _ole_auto_variant_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <ole_lib/ole_base.h>
#include <structure/t_value_with_null.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//content

class TBaseVariant;
class TVariant;

////////////////////////////////////////////////////////////////////////////////

#define OLE_EXTRACT_VT_TYPE(vt) VARTYPE((vt)&(~VT_BYREF))

#define OLE_EXTRACT_VT_SIMPLE_TYPE(vt) VARTYPE((vt)&(~(VT_BYREF|VT_ARRAY)))

////////////////////////////////////////////////////////////////////////////////
//class TBaseVariant

class TBaseVariant:public VARIANT
{
 public:
  typedef TBaseVariant                  self_type;

  TBaseVariant(const self_type&);
  self_type& operator = (const self_type&);

 public:
  TBaseVariant();

 ~TBaseVariant();

 public:
  void CopyTo_Throw(VARIANT* pVariant)const;

  HRESULT CopyTo(VARIANT* pVariant)const;

  HRESULT Clear();

  bool IsEmpty() const;
  bool IsError() const;
  bool IsNull()  const;
  bool HasData() const;

  self_type& SetError(SCODE _scode);

  self_type& SetNull();
};//class TBaseVariant

////////////////////////////////////////////////////////////////////////////////
//class TVariant

class TVariant:public TBaseVariant
{
 private:
  typedef TVariant      self_type;

 public: //typedefs --------------------------------------------------------
  typedef structure::t_value_with_null<short>               value_i2_n_type;
  typedef structure::t_value_with_null<LONG>                value_i4_n_type;

  typedef structure::t_value_with_null<std::string>         value_str_n_type;
  typedef structure::t_value_with_null<std::wstring>        value_wstr_n_type;
  typedef structure::t_value_with_null<const char*>         value_pchar_n_type;
  typedef structure::t_value_with_null<const wchar_t*>      value_pwchar_n_type;

 public:
  struct tag_scode;

 public:
  static const VARIANT empty_variant;
  static const VARIANT null_variant;
  static const VARIANT missing_arg_variant;

 public:
  TVariant();

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  TVariant(self_type&& x);
 #endif

  TVariant(const self_type& variant);//throw

  TVariant(const VARIANT& Variant);//throw

  //[2022-10-26] Trap for unexpected pointers.
  TVariant(const void* pv)=delete;

  //ANSI
  TVariant(const char* s);//throw

#if 0 // [2020-04-04] Bye. Use str_box-version.
  TVariant(const char* s,size_t n);//throw
#endif

  TVariant(const std::string& s);//throw

  TVariant(structure::str_parameter s);//throw

  TVariant(const structure::t_const_str_box& s);//throw

  //UNICODE
  TVariant(const wchar_t* s);//throw

#if 0 // [2020-04-04] Bye. Use str_box-version.
  TVariant(const wchar_t* s,size_t n);//throw
#endif

  TVariant(const std::wstring& s);//throw

  TVariant(structure::wstr_parameter s);//throw

  TVariant(const structure::t_const_wstr_box& s);//throw

  //-------
  TVariant(LONG          data);
  TVariant(ULONG         data);
  TVariant(int           data);
  TVariant(short         data);
  TVariant(double        data);
  TVariant(float         data);
  TVariant(bool          data);

  TVariant(const tagCY&  data);
  TVariant(const tagDEC& data);

  TVariant(IDispatch*    data);
  TVariant(IUnknown*     data);

  TVariant(const value_i2_n_type&     x);
  TVariant(const value_i4_n_type&     x);
  TVariant(const value_str_n_type&    x);//throw
  TVariant(const value_wstr_n_type&   x);//throw
  TVariant(const value_pchar_n_type&  x);//throw
  TVariant(const value_pwchar_n_type& x);//throw

  TVariant(const tag_scode& x);

 public:
  void CopyInEnumerator(VARIANT* pVariant)const; //throw

 public:
  long         as_long   () const;
  short        as_short  () const;
  std::string  as_str    () const;
  std::wstring as_wstr   () const;
  t_string     as_tstr   () const;
  double       as_double () const;
  float        as_float  () const;
  bool         as_bool   () const;

 public:
  HRESULT SetVariant(const VARIANT& Variant);
  HRESULT SetVariant(const VARIANT* Variant);

  self_type& SetStr_v2(const structure::t_const_str_box& str); //throw

  self_type& SetWStr_v2(const structure::t_const_wstr_box& wstr); //throw

  self_type& SetBStr_v2(const BSTR bstr); //throw

  self_type& SetDate(DATE);

 public:
  self_type& swap(self_type& x);
  self_type& swap(VARIANT& x);

  self_type& operator = (const self_type& Variant); //throw
  self_type& operator = (const VARIANT& Variant); //throw

  //[2022-10-26] Trap for unexpected pointers.
  self_type& operator = (const void* pv)=delete;

  self_type& operator = (LONG);
  self_type& operator = (short);

  self_type& operator = (const char* const s)
   {return this->SetStr_v2(s);}

  self_type& operator = (const std::string& s)
   {return this->SetStr_v2(s);}

  self_type& operator = (structure::str_parameter const s)
   {return this->SetStr_v2(structure::make_str_box(s.c_str(),s.length()));}

  self_type& operator = (const structure::t_const_str_box& s)
   {return this->SetStr_v2(s);}

  self_type& operator = (const wchar_t* const s)
   {return this->SetWStr_v2(s);}

  self_type& operator = (const std::wstring& s)
   {return this->SetWStr_v2(s);}

  self_type& operator = (structure::wstr_parameter const s)
   {return this->SetWStr_v2(structure::make_str_box(s.c_str(),s.length()));}

  self_type& operator = (const structure::t_const_wstr_box& s)
   {return this->SetWStr_v2(s);}

  self_type& operator = (double);
  self_type& operator = (float);
  self_type& operator = (bool);

  self_type& operator = (const tagCY&);

  self_type& operator = (const tagDEC&);

  self_type& operator = (IDispatch*);
  self_type& operator = (IUnknown*);

  //----------------------------------------------------------------------
  HRESULT to_string (std::string*   pStr)const;
  HRESULT to_string (std::wstring*  pStr)const;

  //----------------------------------------------------------------------
  static HRESULT to_string (const VARIANT* variant,std::string*  pStr);
  static HRESULT to_string (const VARIANT* variant,std::wstring* pStr);
  static HRESULT to_bstr   (const VARIANT* variant,BSTR*   pBSTR);
  static HRESULT to_long   (const VARIANT* variant,LONG*   pLong);
  static HRESULT to_short  (const VARIANT* variant,short*  pShort);
  static HRESULT to_double (const VARIANT* variant,double* pDouble);
  static HRESULT to_float  (const VARIANT* variant,float*  pFloat);
  static HRESULT to_int64  (const VARIANT* variant,__int64* pInt64);
  static HRESULT to_uint64 (const VARIANT* variant,unsigned __int64* pUInt64);

  static HRESULT to_bool   (const VARIANT* variant,bool*   pBool);
  static HRESULT to_date   (const VARIANT* variant,DATE*   pDate);

  //-----------------------------------------------------
  static HRESULT to_unknown(const VARIANT* variant,IUnknown** ppUnk);
  static HRESULT to_dispatch(const VARIANT* variant,IDispatch** ppDisp);

  //-----------------------------------------------------
  static std::string  variant_date_to_str(DATE date,bool WithTime=false);
  static std::wstring variant_date_to_wstr(DATE date,bool WithTime=false);

 public: //---------------------------------------------------------------
  class tag_print_variant;

 private:
  static VARIANT build_variant_with_scode(SCODE x);
};//class TVariant

////////////////////////////////////////////////////////////////////////////////
//inner struct TVariant::tag_scode

struct TVariant::tag_scode
{
 public:
  SCODE value;

 public:
  tag_scode(SCODE const x)
   :value(x)
  {;}
};//struct TVariant::tag_scode

////////////////////////////////////////////////////////////////////////////////
//inner class TVariant::tag_print_variant

class TVariant::tag_print_variant
{
 private:
  tag_print_variant& operator = (const tag_print_variant&);

 public:
  const VARIANT& m_data;

  tag_print_variant(const VARIANT& data):m_data(data){;}

  std::wstring str()const;
};//class tag_print_variant

////////////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& os,const TVariant::tag_print_variant& data);

inline TVariant::tag_print_variant print(const VARIANT& data);

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib

namespace std{
////////////////////////////////////////////////////////////////////////////////
//specialization

template<>
inline void swap(ole_lib::TVariant& x1,ole_lib::TVariant& x2)
{
 x1.swap(x2);
}//swap

////////////////////////////////////////////////////////////////////////////////
}//namespace std

////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/ole_auto/ole_auto_variant.inl>
////////////////////////////////////////////////////////////////////////////////
#endif
