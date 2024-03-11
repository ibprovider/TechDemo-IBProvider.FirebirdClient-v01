////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <win32lib/win32_error.h>
#include <structure/utilities/string/trim.h>
#include <structure/t_function.h>
#include <tchar.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//Utilities

t_string GetErrorMsg(DWORD const dwErrorCode,
                     bool  const AppendErrCode)
{
 t_string retValue;

 TCHAR* Pointer=nullptr;

 const DWORD res=::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                                 FORMAT_MESSAGE_IGNORE_INSERTS |
                                 FORMAT_MESSAGE_FROM_SYSTEM,
                                 0,
                                 dwErrorCode,
                                 0,
                                 (TCHAR*)&Pointer,
                                 0,
                                 nullptr);
 if(Pointer && res>0)
 {
  typedef HLOCAL __stdcall t_local_free(HLOCAL);

  //automated call of LocalFree
  typedef structure::t_auto_fun_1<t_local_free*,HLOCAL> auto_free_type;

  const auto_free_type _local_free(::LocalFree,Pointer);

  retValue.assign(Pointer,res);

  structure::total_self_trim(retValue);
 }//if Pointer && res>0

 if(AppendErrCode)
 {
  TCHAR tmpStr[160]={};

  LCPI_GCRT_stprintf_s_n1(tmpStr,_DIM_(tmpStr),_T("WIN32 Error: 0x%X"),dwErrorCode);

  const TCHAR* const e=std::find(tmpStr,_END_(tmpStr),0);

  if(e!=tmpStr)
  {
   if(!retValue.empty())
    retValue+=_T("\n");

   retValue.append(tmpStr,e-tmpStr);
  }//if
 }//if AppendErrCode
 
 return retValue;
}//GetErrorMsg

////////////////////////////////////////////////////////////////////////////////
//class t_base_win32_error

t_base_win32_error::~t_base_win32_error() LCPI_STL_EXCEPTION_DCR_THROW_SPEC
{
}

//structure::t_exception -------------------------------------------------
void t_base_win32_error::raise()const
{
 throw *this;
}//raise

////////////////////////////////////////////////////////////////////////////////
//class t_win32_error

t_win32_error::t_win32_error(const self_type& x)
 :inherited(x)
 ,m_msg (x.m_msg)
 ,m_what(x.m_what)
{
}

//------------------------------------------------------------------------
t_win32_error::t_win32_error(win32_code_type const win32_code)
 :inherited(win32_code)
 ,m_what(self_type::helper__build_what_msg(win32_code))
{
}//t_win32_error - win32_code

//------------------------------------------------------------------------
t_win32_error::t_win32_error(win32_code_type const win32_code,
                             str_arg_type    const msg)
 :inherited(win32_code)
 ,m_msg(msg.str())
 ,m_what(self_type::helper__build_what_msg(win32_code,msg))
{
}//t_win32_error - win32_code, msg

//------------------------------------------------------------------------
t_win32_error::~t_win32_error() LCPI_STL_EXCEPTION_DCR_THROW_SPEC
{
}

//std::exception ---------------------------------------------------------
const char* t_win32_error::what()const LCPI_STL_EXCEPTION_WHAT_THROW_SPEC
{
 return m_what.c_str();
}//what

//structure::t_exception -------------------------------------------------
void t_win32_error::raise()const
{
 throw *this;
}//raise

//throw generators -------------------------------------------------------
void t_win32_error::throw_error(win32_code_type const win32_code)
{
 self_type(win32_code).raise();
}//throw_error

//------------------------------------------------------------------------
void t_win32_error::throw_error(win32_code_type const win32_code,
                                str_arg_type    const msg)
{
 self_type(win32_code,msg).raise();
}//throw_error

//helper methods ---------------------------------------------------------
std::string t_win32_error::helper__build_what_msg(win32_code_type const win32_code)
{
 const t_string err_msg(win32lib::GetErrorMsg(win32_code,true));

 return structure::tstr_to_str(err_msg);
}//helper__build_what_msg

//------------------------------------------------------------------------
std::string t_win32_error::helper__build_what_msg(win32_code_type const win32_code,
                                                  str_arg_type    const msg)
{
 if(msg.empty())
  return self_type::helper__build_what_msg(win32_code);

 //---
 const t_string err_msg(win32lib::GetErrorMsg(win32_code,true));

 if(err_msg.empty())
  return msg.str();

 //---
 std::string result;

 result.reserve(msg.length()+1+err_msg.length());

 //---
 result+=msg.str();

 result+='\n';

 result+=structure::tstr_to_str(err_msg);

 //---
 return result;
}//helper__build_what_msg

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
