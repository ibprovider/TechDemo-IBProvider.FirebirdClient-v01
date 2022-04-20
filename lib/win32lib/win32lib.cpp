////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <win32lib/win32lib.h>
#include <structure/t_str_formatter.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////

t_string GetModuleFileName(HINSTANCE hModule)
{
 DWORD x=0;

 {
  TCHAR stack_buf[MAX_PATH];

  x=::GetModuleFileName(hModule,stack_buf,_DIM_(stack_buf));

  assert_msg(x<=_DIM_(stack_buf),"x: "<<x<<". _DIM_: "<<_DIM_(stack_buf));

  if(x==0)
   return t_string();

  if(x<_DIM_(stack_buf))
   return t_string(stack_buf,x);
 }//local

 for(;;)
 {
  const DWORD c_max=structure::t_numeric_limits<DWORD>::max_value();

  if(x==c_max)
   throw std::runtime_error("[BUG CHECK] win32lib::GetModuleFileName. Check point: #001.");

  if(x<c_max/2)
   x=2*x;
  else
   x=c_max;

  structure::t_typed_simple_buffer<TCHAR,structure::t_void_allocator> buf(x);

  x=::GetModuleFileName(hModule,buf.buffer(),x);

  assert_msg(x<=buf.size(),"x: "<<x<<". buf.size: "<<buf.size());

  if(x==0)
   return t_string();

  if(x<buf.size())
   return t_string(buf.buffer(),x);
 }//for[ever]
}//GetModuleFileName

////////////////////////////////////////////////////////////////////////////////

t_string GetUserName()
{
 t_string resultValue;

 DEBUG_CODE(DWORD const dwErr=)GetUserName(&resultValue);

 assert(dwErr==0 || resultValue.empty());

 return resultValue;
}//GetUserName

//------------------------------------------------------------------------
static void Helper__GetUserName__ThrowBugCheck__IncorrectSize(DWORD  const nSize,
                                                              size_t const nMaxSize)
{
 assert_msg(false,"nSize="<<nSize<<". nMaxSize="<<nMaxSize);

 structure::str_formatter
  fmsg("[BUG CHECK] Incorrect work of system function ::GetUserName(). nSize=%1. nMaxSize=%2");

 fmsg<<nSize<<nMaxSize;

 throw std::runtime_error(fmsg);
}//Helper__GetUserName__ThrowBugCheck__IncorrectSize

//------------------------------------------------------------------------
static void Helper__GetUserName__ThrowBugCheck__UnexpectedWork(DWORD  const nSize,
                                                               size_t const nMaxSize)
{
 assert_msg(false,"nSize="<<nSize<<". nMaxSize="<<nMaxSize);

 structure::str_formatter
  fmsg("[BUG CHECK] Unexpected work of system function ::GetUserName(). nSize=%1. nMaxSize=%2");

 fmsg<<nSize<<nMaxSize;

 throw std::runtime_error(fmsg);
}//Helper__GetUserName__ThrowBugCheck__UnexpectedWork

//------------------------------------------------------------------------
static void Helper__GetUserName__ThrowBugCheck__UnexpectedNOERROR()
{
 assert(false);

 throw std::runtime_error("[BUG CHECK] ::GetUserName return the FALSE. But ::GetLastError return the NOERROR.");
}//Helper__GetUserName__ThrowBugCheck__UnexpectedNOERROR

//------------------------------------------------------------------------
DWORD GetUserName(t_string* const pUserName)
{
 assert(pUserName!=nullptr);

 DWORD nSize;

 for(;;)
 {
  TCHAR Buffer[512]={};

  const DWORD c_nMaxSize=_DIM_(Buffer)-1;

  nSize=c_nMaxSize;

  if(::GetUserName(Buffer,&nSize))
  {
   //nSize contains len(UserName) + 1 ('\0')

   if(nSize==0 || nSize>c_nMaxSize)
   {
    Helper__GetUserName__ThrowBugCheck__IncorrectSize(nSize,c_nMaxSize);
   }//if

   assert_hint(nSize>0);
   assert_hint(nSize<=c_nMaxSize);

   pUserName->assign(Buffer,nSize-1);

   return 0;
  }//if ok

  const DWORD dwError=::GetLastError();

  if(dwError==ERROR_INSUFFICIENT_BUFFER)
  {
   if(nSize<c_nMaxSize)
   {
    Helper__GetUserName__ThrowBugCheck__UnexpectedWork(nSize,c_nMaxSize);
   }

   assert_hint(nSize>=c_nMaxSize);
   assert_s(c_nMaxSize>0);

   //So
   assert_hint(nSize>0);

   break; //exit from 'for'
  }//if ERROR_INSUFFICIENT_BUFFER

  if(dwError==0)
  {
   Helper__GetUserName__ThrowBugCheck__UnexpectedNOERROR();
  }

  return dwError;
 }//for[ever]

 assert_hint(nSize>0);

 typedef structure::t_typed_simple_buffer<TCHAR,structure::t_void_allocator> buf_type;

 {
  buf_type buf(nSize);

  if(::GetUserName(buf.buffer(),&nSize))
  {
   //nSize contains len(UserName) + 1 ('\0')

   if(nSize==0 || nSize>buf.size())
   {
    Helper__GetUserName__ThrowBugCheck__IncorrectSize(nSize,buf.size());
   }

   pUserName->assign(buf.buffer(),nSize-1);

   return NOERROR;
  }//if

  const DWORD dwError=::GetLastError();

  if(dwError==ERROR_INSUFFICIENT_BUFFER)
  {
   Helper__GetUserName__ThrowBugCheck__UnexpectedWork(nSize,buf.size());
  }//if ERROR_INSUFFICIENT_BUFFER

  if(dwError==0)
  {
   Helper__GetUserName__ThrowBugCheck__UnexpectedNOERROR();
  }//if

  return dwError;
 }//local
}//GetUserName

////////////////////////////////////////////////////////////////////////////////

t_string GetComputerName()
{
 t_string resultValue;

 DEBUG_CODE(DWORD const dwErr=)GetComputerName(&resultValue);

 assert(dwErr==0 || resultValue.empty());

 return resultValue;
}//GetComputerName

//------------------------------------------------------------------------
static void Helper__GetComputerName__ThrowBugCheck__IncorrectSize(DWORD  const nSize,
                                                                  size_t const nMaxSize)
{
 assert_msg(false,"nSize="<<nSize<<". nMaxSize="<<nMaxSize);

 structure::str_formatter
  fmsg("[BUG CHECK] Incorrect work of system function ::GetComputerName(). nSize=%1. nMaxSize=%2");

 fmsg<<nSize<<nMaxSize;

 throw std::runtime_error(fmsg);
}//Helper__GetComputerName__ThrowBugCheck__IncorrectSize

//------------------------------------------------------------------------
static void Helper__GetComputerName__ThrowBugCheck__UnexpectedWork(DWORD  const nSize,
                                                                   size_t const nMaxSize)
{
 assert_msg(false,"nSize="<<nSize<<". nMaxSize="<<nMaxSize);

 structure::str_formatter
  fmsg("[BUG CHECK] Unexpected work of system function ::GetComputerName(). nSize=%1. nMaxSize=%2");

 fmsg<<nSize<<nMaxSize;

 throw std::runtime_error(fmsg);
}//Helper__GetComputerName__ThrowBugCheck__UnexpectedWork

//------------------------------------------------------------------------
static void Helper__GetComputerName__ThrowBugCheck__UnexpectedNOERROR()
{
 assert(false);

 throw std::runtime_error("[BUG CHECK] ::GetComputerName return the FALSE. But ::GetLastError return the NOERROR.");
}//Helper__GetComputerName__ThrowBugCheck__UnexpectedNOERROR

//------------------------------------------------------------------------
DWORD GetComputerName(t_string* const pComputerName) //throw
{
 assert(pComputerName!=nullptr);

 DWORD nSize;

 for(;;)
 {
  TCHAR Buffer[MAX_COMPUTERNAME_LENGTH+1+1]={};

  const DWORD c_nMaxSize=_DIM_(Buffer)-1;

  nSize=c_nMaxSize;

  if(::GetComputerName(Buffer,&nSize))
  {
   //nSize contains len(Name) only

   if(nSize>=c_nMaxSize)
   {
    Helper__GetComputerName__ThrowBugCheck__IncorrectSize(nSize,c_nMaxSize);
   }//if

   pComputerName->assign(Buffer,nSize);

   return 0;
  }//if ok

  const DWORD dwError=::GetLastError();

  if(dwError==ERROR_BUFFER_OVERFLOW)
  {
   if(nSize<c_nMaxSize)
   {
    Helper__GetComputerName__ThrowBugCheck__UnexpectedWork(nSize,c_nMaxSize);
   }

   assert_hint(nSize>=c_nMaxSize);
   assert_s(c_nMaxSize>0);

   //So
   assert_hint(nSize>0);

   break; //exit from 'for'
  }//if ERROR_BUFFER_OVERFLOW

  if(dwError==0)
  {
   Helper__GetComputerName__ThrowBugCheck__UnexpectedNOERROR();
  }

  return dwError;
 }//for[ever]

 assert_hint(nSize>0);

 typedef structure::t_typed_simple_buffer<TCHAR,structure::t_void_allocator> buf_type;

 {
  buf_type buf(nSize);

  if(::GetComputerName(buf.buffer(),&nSize))
  {
   //nSize contains len(Name) only

   if(nSize>=buf.size())
   {
    Helper__GetComputerName__ThrowBugCheck__IncorrectSize(nSize,buf.size());
   }

   pComputerName->assign(buf.buffer(),nSize);

   return NOERROR;
  }//if

  const DWORD dwError=::GetLastError();

  if(dwError==ERROR_BUFFER_OVERFLOW)
  {
   Helper__GetComputerName__ThrowBugCheck__UnexpectedWork(nSize,buf.size());
  }//if ERROR_BUFFER_OVERFLOW

  if(dwError==0)
  {
   Helper__GetComputerName__ThrowBugCheck__UnexpectedNOERROR();
  }//if

  return dwError;
 }//local
}//GetComputerName

////////////////////////////////////////////////////////////////////////////////

t_string ExpandEnvironmentStrings(const t_string& s)
{
 if(s.empty())
  return s;

 typedef DWORD sz_type;

 sz_type sz=0;

 for(;;)
 {
  structure::t_typed_simple_buffer<t_char,structure::t_void_allocator> buf(sz);//throw

  sz_type const new_sz=::ExpandEnvironmentStrings(s.c_str(),buf.buffer(),static_cast<sz_type>(buf.size()));

  if(new_sz==0)
   return t_string();

  if(new_sz<=buf.size())
   return t_string(buf.buffer(),new_sz-1); //new_sz has terminate symbols

  sz=new_sz;
 }//while
}//ExpandEnvironmentStrings

//------------------------------------------------------------------------
t_string GetEnvironmentVariable(const t_string& name)
{
 typedef DWORD sz_type;
 
 sz_type sz=0;

 for(;;)
 {
  structure::t_typed_simple_buffer<t_char,structure::t_void_allocator> buf(sz);//throw

  sz_type const new_sz=::GetEnvironmentVariable(name.c_str(),buf.buffer(),static_cast<sz_type>(buf.size()));

  if(new_sz==0)
   return t_string();

  if(new_sz<=buf.size())
   return t_string(buf.buffer(),new_sz);//new_sz not include terminate symbols

  sz=new_sz; 
 }//while
}//GetEnvironmentVariable

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
