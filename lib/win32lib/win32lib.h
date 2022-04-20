////////////////////////////////////////////////////////////////////////////////
//Base module of library for work with Win32 object and functions
//                                                  Dmitry Kovalenko. 98 year.
#ifndef _win32lib_H_
#define _win32lib_H_

#include <win32lib/win32_base.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////

using ::MessageBox;

inline int MessageBox(HWND hWnd,const t_string& msg,const t_string& capt,UINT uFlags)
{
 return ::MessageBox(hWnd,msg.c_str(),capt.c_str(),uFlags);
}

//------------------------------------------------------------------------
t_string GetModuleFileName(HINSTANCE hModule);

//------------------------------------------------------------------------
t_string GetUserName();

DWORD GetUserName(t_string* pUserName); //throw

//------------------------------------------------------------------------
t_string GetComputerName();

DWORD GetComputerName(t_string* pComputerName); //throw

//------------------------------------------------------------------------
t_string ExpandEnvironmentStrings(const t_string& s);

//------------------------------------------------------------------------
t_string GetEnvironmentVariable(const t_string& name);

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
#endif
