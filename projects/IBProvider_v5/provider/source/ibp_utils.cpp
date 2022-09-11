////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_utils.cpp
//! \brief   Утилиты общего назначения
//! \author  Kovalenko Dmitry
//! \date    28.11.2012
#include <_pch_.h>
#pragma hdrstop

#include "source/ibp_utils.h"
#include "source/ibp_cfg_structure.h"

#include <structure/charsets/t_cs_utf8.h>
#include <structure/t_latin.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_Utils

HRESULT IBP_Utils::GetAsynchRowsetOpStatus__Complete
                                           (DBCOUNTITEM*   const pulProgress,
                                            DBCOUNTITEM*   const pulProgressMax,
                                            DBASYNCHPHASE* const peAsynchPhase)
{
 if(pulProgress!=NULL)
  (*pulProgress)=1;

 if(pulProgressMax!=NULL)
  (*pulProgressMax)=1;

 if(peAsynchPhase!=NULL)
  (*peAsynchPhase)=DBASYNCHPHASE_COMPLETE;

 return S_OK;
}//GetAsynchRowsetOpStatus__Complete

//------------------------------------------------------------------------
HRESULT IBP_Utils::GetAsynchRowsetOpStatus__Canceled
                                           (DBCOUNTITEM*   const pulProgress,
                                            DBCOUNTITEM*   const pulProgressMax,
                                            DBASYNCHPHASE* const peAsynchPhase)
{
 if(pulProgress!=NULL)
  (*pulProgress)=0;

 if(pulProgressMax!=NULL)
  (*pulProgressMax)=1;

 if(peAsynchPhase!=NULL)
  (*peAsynchPhase)=DBASYNCHPHASE_CANCELED;

 return DB_E_CANCELED;
}//GetAsynchRowsetOpStatus__Canceled

//------------------------------------------------------------------------
HRESULT IBP_Utils::GetAsynchRowsetOpStatus__Population
                                           (DBASYNCHOP     const eOperation,
                                            DBCOUNTITEM*   const pulProgress,
                                            DBCOUNTITEM*   const pulProgressMax,
                                            DBASYNCHPHASE* const peAsynchPhase)
{
 if(pulProgress!=NULL)
  (*pulProgress)=((eOperation==DBASYNCHOP_OPEN)?0:1);

 if(pulProgressMax!=NULL)
  (*pulProgressMax)=1;

 if(peAsynchPhase!=NULL)
  (*peAsynchPhase)=DBASYNCHPHASE_POPULATION;

 return S_OK;
}//GetAsynchRowsetOpStatus__Population

//------------------------------------------------------------------------
std::wstring IBP_Utils::GetStmtSign(structure::t_const_wstr_box const stmt)
{
 CHECK_READ_TYPED_PTR(stmt.ptr,stmt.len);

 structure::t_const_wstr_box::iterator b(stmt.begin());
 structure::t_const_wstr_box::iterator e(stmt.end());

 b=structure::miss_space2(b,e);

 assert(b<=e);

 e=structure::miss_space2_back(b,e);

 assert(b<=e);

 const bool truncated=(cfg::ibp_cfg__max_stmt_sign_length<static_cast<size_t>(e-b));

 if(truncated)
 {
  assert_s(cfg::ibp_cfg__max_stmt_sign_length>4);

  e=(b+(cfg::ibp_cfg__max_stmt_sign_length-4));

  e=structure::miss_space2_back(b,e);

  assert(b<e);
 }//if truncated

 std::wstring result;

 assert(b<=e);

 for(;b!=e;++b)
 {
  switch(*b)
  {
   case L'\n':
   case L'\r':
   case L'\t':
    result+=L' ';
    break;

   case L'\0':
    result+=L"\\0";
    break;

   default:
    result+=(*b);
    break;
  }//switch
 }//for b

 if(truncated)
  result+=L" ...";

 return result;
}//GetStmtSign

//------------------------------------------------------------------------
bool IBP_Utils::IsSSPI(structure::t_const_wstr_box const authName)
{
 if(authName.empty())
  return true;

 return authName.equal(ibprovider::g_IBP_IntegratedAuth__SSPI);
}//IsSSPI

//------------------------------------------------------------------------
bool IBP_Utils::Utf8ToWStr__Fast
               (const structure::t_basic_const_str_box<char>& Utf8Str,
                std::wstring*                           const pWStr)
{
 assert(pWStr);

 //[2016-09-02] На всякий случай пока будем контролировать пустоту OUT-значения
 assert(pWStr->empty());

 CHECK_READ_TYPED_PTR(Utf8Str.ptr,Utf8Str.len);

 namespace utf8=structure::charsets::cs_utf8;

 utf8::t_cs_cvt_result cvt_result=utf8::cs_cvt_result__ok;

 utf8::utf8_to_ucs2(Utf8Str.begin(),
                    Utf8Str.end(),
                    std::back_inserter(*pWStr),
                    &cvt_result);

 return cvt_result==utf8::cs_cvt_result__ok;
}//Utf8ToWStr__Fast

//------------------------------------------------------------------------
bool IBP_Utils::WStrToUtf8__Fast
               (const structure::t_const_wstr_box& WStr,
                std::string*                 const pUtf8Str)
{
 assert(pUtf8Str);

 //[2016-09-02] На всякий случай пока будем контролировать пустоту OUT-значения
 assert(pUtf8Str->empty());

 CHECK_READ_TYPED_PTR(WStr.ptr,WStr.len);

 namespace utf8=structure::charsets::cs_utf8;

 utf8::t_cs_cvt_result cvt_result=utf8::cs_cvt_result__ok;

 utf8::ucs2_to_utf8(WStr.begin(),
                    WStr.end(),
                    std::back_inserter(*pUtf8Str),
                    &cvt_result);

 return cvt_result==utf8::cs_cvt_result__ok;
}//WStrToUtf8__Fast

//------------------------------------------------------------------------
std::wstring IBP_Utils::EscapingText(structure::t_const_wstr_box const text)
{
 std::wstring result;

 for(structure::t_const_wstr_box::iterator i(text.begin()),
                                          _e(text.end());
     i!=_e;
     ++i)
 {
  switch(*i)
  {
   case L'\\':
    result+=L"\\\\";
    break;

   case L'\0':
    result+=L"\\0";
    break;

   case L'\t':
    result+=L"\\t";
    break;

   case L'\r':
    result+=L"\\r";
    break;

   case L'\n':
    result+=L"\\n";
    break;

   default:
    result+=*i;
    break;
  }//switch *i
 }//for[ever]

 return result;
}//EscapingText

//------------------------------------------------------------------------
bool IBP_Utils::EqualAsciiStr_i(const structure::t_const_wstr_box& s1,
                                const structure::t_const_wstr_box& s2)
{
 return structure::equal(s1.begin(),
                         s1.end(),
                         s2.begin(),
                         s2.end(),
                         structure::t_latin_equal_i<wchar_t>());
}//EqualAsciiStr_i

//------------------------------------------------------------------------
bool IBP_Utils::TestProviderErrorRules__explain_dbms_error(long const rules)
{
 return rules!=0;
}//TestProviderErrorRules__explain_dbms_error

//------------------------------------------------------------------------
bool IBP_Utils::TestProviderErrorRules__append_additional_records(long const rules)
{
 return rules!=0;
}//TestProviderErrorRules__append_additional_records

//------------------------------------------------------------------------
bool IBP_Utils::TestProviderErrorRules__append_summary_info(long const rules)
{
 return rules!=0;
}//TestProviderErrorRules__append_summary_info

//------------------------------------------------------------------------
bool IBP_Utils::TestChar_IsLatin(wchar_t const ch)
{
 if(L'a'<=ch && ch<=L'z')
  return true;

 if(L'A'<=ch && ch<=L'Z')
  return true;

 return false;
}//TestChar_IsLatin

//------------------------------------------------------------------------
bool IBP_Utils::TestChar_IsDigit(wchar_t const ch)
{
 if(L'0'<=ch && ch<=L'9')
  return true;

 return false;
}//TestChar_IsLatin

//------------------------------------------------------------------------
bool IBP_Utils::IsValidCharsetName(const structure::t_const_wstr_box& name)
{
 auto       p=name.begin();
 auto const e=name.end();

 if(p==e)
  return false;

 if(!self_type::TestChar_IsLatin(*p))
  return false;

 for(++p;p!=e;++p)
 {
  if(self_type::TestChar_IsLatin(*p))
   continue;

  if(self_type::TestChar_IsDigit(*p))
   continue;

  if((*p)==L'_')
   continue;

  return false;
 }//for p

 return true;
}//IsValidCharsetName

//------------------------------------------------------------------------
bool IBP_Utils::IsValidCharsetCollationName(const structure::t_const_wstr_box& name)
{
 return self_type::IsValidCharsetName(name);
}//IsValidCharsetCollationName

//------------------------------------------------------------------------
bool IBP_Utils::IsValidSimpleString(const structure::t_const_wstr_box& name)
{
 for(auto p=name.begin(),_e=name.end();p!=_e;++p)
 {
  switch(*p)
  {
   case 0:
    return false;
  }//switch
 }//for p

 return true;
}//return 

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
