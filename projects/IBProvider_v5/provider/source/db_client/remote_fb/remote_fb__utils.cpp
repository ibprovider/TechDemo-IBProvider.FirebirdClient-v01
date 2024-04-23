////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__utils.cpp
//! \brief   Набор вспомогательных утилит.
//! \author  Kovalenko Dmitry
//! \date    06.11.2014.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__utils.h"
#include "source/db_client/remote_fb/remote_fb__memory.h"
#include "source/error_services/ibp_error_utils.h"
#include "source/ibp_utils.h"

#include <win32lib/win32lib.h>
#include "source/Version/ibp_v05_info_data.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Utils

bool RemoteFB__Utils::EqualPluginNames(const wstr_box_type& name1,
                                       const wstr_box_type& name2)
{
 return IBP_Utils::EqualAsciiStr_i
         (name1,
          name2);
}//EqualPluginNames

//------------------------------------------------------------------------
t_ibp_string RemoteFB__Utils::GetSystemUserName()
{
 win32lib::t_string tUserName;

 const DWORD dwError=win32lib::GetUserName(&tUserName);

 if(dwError!=NOERROR)
 {
  // ERROR - can't detect the system userName

  IBP_ThrowSimpleError
   (HRESULT_FROM_WIN32(dwError),
    ibp_mce_win32__cant_get_current_system_user_name_0);
 }//if

 using tmp_buf_type
  =structure::t_typed_simple_buffer<win32lib::t_char,RemoteFB__MemoryAllocator>;

 tmp_buf_type tmp_buf(tUserName.c_str(),tUserName.size());

 self_type::System_CharUpperBuff
  (tmp_buf.buffer(),
   tmp_buf.size(),
   L"SystemUserName"); //throw

 bool CvtFailed=false;

 t_ibp_string UserName;

 structure::tstr_to_tstr
  (&UserName,
   lib::structure::make_str_box(tmp_buf.buffer(),tmp_buf.size()),
   &CvtFailed);

 if(CvtFailed)
 {
  // ERROR - Can't translate system UserName between codepages

  IBP_ThrowCantTranslateSysData<t_ibp_string::value_type>(L"Current System User Name");
 }//if CvtFailed

 return UserName;
}//GetSystemUserName

//------------------------------------------------------------------------
t_ibp_string RemoteFB__Utils::GetComputerName()
{
 win32lib::t_string tComputerName;

 const DWORD dwError=win32lib::GetComputerName(&tComputerName);

 if(dwError!=NOERROR)
 {
  //ERROR - can't detect the computer name

  IBP_ThrowSimpleError
   (HRESULT_FROM_WIN32(dwError),
    ibp_mce_win32__cant_get_local_computer_name_0);
 }//if

 using tmp_buf_type
  =structure::t_typed_simple_buffer<win32lib::t_char,RemoteFB__MemoryAllocator>;

 tmp_buf_type tmp_buf(tComputerName.c_str(),tComputerName.size());

 self_type::System_CharLowerBuff
  (tmp_buf.buffer(),
   tmp_buf.size(),
   L"Local Computer Name");

 bool CvtFailed=false;

 t_ibp_string ComputerName;

 structure::tstr_to_tstr
  (&ComputerName,
   lib::structure::make_str_box(tmp_buf.buffer(),tmp_buf.size()),
   &CvtFailed);

 if(CvtFailed)
 {
  // ERROR - Can't translate ComputerName between code pages

  IBP_ThrowCantTranslateSysData<t_ibp_string::value_type>(L"Local Computer Name");
 }//if CvtFailed

 return ComputerName;
}//GetComputerName

//------------------------------------------------------------------------
t_ibp_string RemoteFB__Utils::GetComputerName_U()
{
 win32lib::t_string tComputerName;

 const DWORD dwError=win32lib::GetComputerName(&tComputerName);

 if(dwError!=NOERROR)
 {
  //ERROR - can't detect the computer name

  IBP_ThrowSimpleError
   (HRESULT_FROM_WIN32(dwError),
    ibp_mce_win32__cant_get_local_computer_name_0);
 }//if

 using tmp_buf_type
  =structure::t_typed_simple_buffer<win32lib::t_char,RemoteFB__MemoryAllocator>;

 tmp_buf_type tmp_buf(tComputerName.c_str(),tComputerName.size());

 self_type::System_CharUpperBuff
  (tmp_buf.buffer(),
   tmp_buf.size(),
   L"Local Computer Name");

 bool CvtFailed=false;

 t_ibp_string ComputerName;

 structure::tstr_to_tstr
  (&ComputerName,
   lib::structure::make_str_box(tmp_buf.buffer(),tmp_buf.size()),
   &CvtFailed);

 if(CvtFailed)
 {
  // ERROR - Can't translate ComputerName between code pages

  IBP_ThrowCantTranslateSysData<t_ibp_string::value_type>(L"Local Computer Name");
 }//if CvtFailed

 return ComputerName;
}//GetComputerName_U

//------------------------------------------------------------------------
t_ibp_string RemoteFB__Utils::GetCurrentProcessName()
{
 win32lib::t_string tProcessName(win32lib::GetModuleFileName(NULL));

 if(tProcessName.empty())
 {
  const DWORD dwError=::GetLastError();

  const HRESULT hr=dwError?HRESULT_FROM_WIN32(dwError):E_FAIL;

  //ERROR - can't detect the current process name

  IBP_ThrowSimpleError
   (hr,
    ibp_mce_win32__cant_get_current_process_name_0);
 }//if

 using tmp_buf_type
  =structure::t_typed_simple_buffer<win32lib::t_char,RemoteFB__MemoryAllocator>;

 tmp_buf_type tmp_buf(tProcessName.c_str(),tProcessName.size());

 bool CvtFailed=false;

 t_ibp_string ProcessName;

 structure::tstr_to_tstr
  (&ProcessName,
   tProcessName,
   &CvtFailed);

 if(CvtFailed)
 {
  // ERROR - Can't translate ProcessName between code pages

  IBP_ThrowCantTranslateSysData<t_ibp_string::value_type>(L"Current Process Name");
 }//if CvtFailed

 return ProcessName;
}//GetCurrentProcessName

//------------------------------------------------------------------------
void RemoteFB__Utils::System_CharLowerBuff(TCHAR*         const p,
                                           size_t         const n,
                                           const wchar_t* const sourceSign)
{
 const TCHAR* const e=p+n;

 TCHAR* p1=p;

 const DWORD dwMax=structure::t_numeric_limits<DWORD>::max_value();

 while(p1!=e)
 {
  assert(p1<e);

  const size_t n_tail=static_cast<size_t>(e-p1);

  assert(n_tail<=n);

  DWORD n1;

  if(dwMax<n_tail)
   n1=dwMax;
  else
   structure::static_numeric_cast(&n1,n_tail);

  assert(n1>0);
  assert(n1<=n_tail);
  assert(n1<=dwMax);

  const size_t x=::CharLowerBuff(p1,n1);

  assert(x<=n1);

  if(x==0)
   break;

  p1+=x;
 }//while p1!=e

 assert(p<=p1);
 assert(p1<=e);

 const size_t n_processed
  =static_cast<size_t>(p1-p);

 if(n_processed!=n)
 {
  IBP_ThrowErr__FailedToMakeLowerStr
   (sourceSign,
    n,
    n_processed);
 }//if

 assert_hint(n_processed==n);
}//System_CharLowerBuff

//------------------------------------------------------------------------
void RemoteFB__Utils::System_CharUpperBuff(CHAR*          const p,
                                           size_t         const n,
                                           const wchar_t* const sourceSign)
{
 const CHAR* const e=p+n;

 CHAR* p1=p;

 const DWORD dwMax=structure::t_numeric_limits<DWORD>::max_value();

 while(p1!=e)
 {
  assert(p1<e);

  const size_t n_tail=static_cast<size_t>(e-p1);

  assert(n_tail<=n);

  DWORD n1;

  if(dwMax<n_tail)
   n1=dwMax;
  else
   structure::static_numeric_cast(&n1,n_tail);

  assert(n1>0);
  assert(n1<=n_tail);
  assert(n1<=dwMax);

  const size_t x=::CharUpperBuffA(p1,n1);

  assert(x<=n1);

  if(x==0)
   break;

  p1+=x;
 }//while p1!=e

 assert(p<=p1);
 assert(p1<=e);

 const size_t n_processed
  =static_cast<size_t>(p1-p);

 if(n_processed!=n)
 {
  IBP_ThrowErr__FailedToMakeUpperStr
   (sourceSign,
    n,
    n_processed);
 }//if

 assert_hint(n_processed==n);
}//System_CharUpperBuff

//------------------------------------------------------------------------
void RemoteFB__Utils::System_CharUpperBuff(WCHAR*         const p,
                                           size_t         const n,
                                           const wchar_t* const sourceSign)
{
 const WCHAR* const e=p+n;

 WCHAR* p1=p;

 const DWORD dwMax=structure::t_numeric_limits<DWORD>::max_value();

 while(p1!=e)
 {
  assert(p1<e);

  const size_t n_tail=static_cast<size_t>(e-p1);

  assert(n_tail<=n);

  DWORD n1;

  if(dwMax<n_tail)
   n1=dwMax;
  else
   structure::static_numeric_cast(&n1,n_tail);

  assert(n1>0);
  assert(n1<=n_tail);
  assert(n1<=dwMax);

  const size_t x=::CharUpperBuffW(p1,n1);

  assert(x<=n1);

  if(x==0)
   break;

  p1+=x;
 }//while p1!=e

 assert(p<=p1);
 assert(p1<=e);

 const size_t n_processed
  =static_cast<size_t>(p1-p);

 if(n_processed!=n)
 {
  IBP_ThrowErr__FailedToMakeUpperStr
   (sourceSign,
    n,
    n_processed);
 }//if

 assert_hint(n_processed==n);
}//System_CharUpperBuff

//------------------------------------------------------------------------
void RemoteFB__Utils::System_CharUpperBStr(BSTR           const bstr,
                                           const wchar_t* const sourceSign)
{
 assert(sourceSign);

 if(!bstr)
  return;

 const UINT n=LCPI_OS__SysStringLen(bstr);

 self_type::System_CharUpperBuff
  (bstr,
   n,
   sourceSign);
}//System_CharUpperBStr

//------------------------------------------------------------------------
const wchar_t* RemoteFB__Utils::BuildFbClientSign()
{
 return IBP_UCS2(IBP_SUBSYSTEM_SIGN__REMOTE_FB)
        L" "
        IBP_UCS2(IBP_VI_PRODUCT_VER_STRING1)
        L" ("
        IBP_UCS2(IBP_PLATFORM_ID_SIGN_T)
        L")";
}//BuildFbClientSign

//------------------------------------------------------------------------
t_ibp_string RemoteFB__Utils::BuildWinSspiUserName()
{
 t_ibp_string result=RemoteFB__Utils::GetComputerName_U();

 result+=IBP_T("\\");

 result+=RemoteFB__Utils::GetSystemUserName();

 return result;
}//BuildWinSspiUserName

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
