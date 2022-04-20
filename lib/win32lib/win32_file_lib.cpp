////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <win32lib/win32_file_lib.h>
#include <win32lib/win32_error.h>
#include <structure/t_limits.h>
#include <tchar.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//Utility

t_string GetFullPathName(LPCTSTR const lpszFileName)
{
 assert(lpszFileName!=NULL);

 enum{stack_buffer_size=512};

 TCHAR Buffer[stack_buffer_size+1]={};

 LPTSTR lpFilePart=NULL;

 DWORD dwLen=::GetFullPathName(lpszFileName,_DIM_(Buffer),Buffer,&lpFilePart);

 if(dwLen<=stack_buffer_size)
  return t_string(Buffer,dwLen); //this processed also dwLen==0

 assert_hint(dwLen>stack_buffer_size);

 //выделяем память под строку
 using namespace structure;

 typedef t_typed_simple_buffer<t_string::value_type,t_void_allocator> buffer_type;

 buffer_type result;
 DWORD       dwLen1=0;

 assert_hint(dwLen>stack_buffer_size);

 while(dwLen1<dwLen)
 {
  assert_hint(dwLen>0);

  if(dwLen==structure::t_numeric_limits<DWORD>::max_value())
   throw std::overflow_error("Overflow in win32lib::GetFullPathName");

  //+1 symbol for terminate symbol
  //+1 symbol for vsjkii pozarnii
  result.alloc(size_t(dwLen1=(dwLen+1))+1);//throw

  dwLen=::GetFullPathName(lpszFileName,dwLen1,result.buffer(),&lpFilePart);
 }//while

 return t_string(result.buffer(),dwLen);
}//GetFullPathName

//------------------------------------------------------------------------------
t_string GetTempPath()
{
 enum{stack_buffer_size=MAX_PATH};

 TCHAR szTempPath[stack_buffer_size+1]={};

 DWORD dwLen=::GetTempPath(stack_buffer_size,szTempPath);

 if(dwLen<=stack_buffer_size)
  return t_string(szTempPath,dwLen); //this processed also dwLen==0

 assert_hint(dwLen>stack_buffer_size);

 //--------------
 using namespace structure;

 typedef t_typed_simple_buffer<TCHAR,t_void_allocator> buffer_type;

 buffer_type result;
 DWORD       dwLen1=0;

 assert_hint(dwLen>stack_buffer_size);

 while(dwLen1<dwLen)
 {
  assert_hint(dwLen>0);

  if(dwLen==structure::t_numeric_limits<DWORD>::max_value())
   throw std::overflow_error("Overflow in win32lib::GetTempPath");

  //+1 symbol for terminate symbol
  //+1 symbol for vsjkii pozarnii
  result.alloc(size_t(dwLen1=(dwLen+1))+1);//throw

  dwLen=::GetTempPath(dwLen1,result.buffer());
 }//while

 return t_string(result.buffer(),dwLen);
}//GetTempPath

//------------------------------------------------------------------------------
t_string GetCurrentDirectory()
{
 DWORD x=0;

 {
  TCHAR stack_buf[MAX_PATH];

  x=::GetCurrentDirectory(_DIM_(stack_buf),stack_buf);

  //+case "x==0"
  if(x<_DIM_(stack_buf))
   return t_string(stack_buf,x);

  if(x==_DIM_(stack_buf))
   throw std::runtime_error("[BUG CHECK] Unexpected situation in win32lib::GetCurrentDirectory. Check point: #001.");
 }//local

 for(;;)
 {
  structure::t_typed_simple_buffer<TCHAR,structure::t_void_allocator> buf(x);

  x=::GetCurrentDirectory(x,buf.buffer());

  //+case "x==0"
  if(x<buf.size())
   return t_string(buf.buffer(),x);

  if(x==buf.size())
   throw std::runtime_error("[BUG CHECK] Unexpected situation in win32lib::GetCurrentDirectory. Check point: #002.");
 }//for[ever]
}//GetCurrentDirectory

////////////////////////////////////////////////////////////////////////////////
//class TFileHandle

BOOL TFileHandle::Create(tstr_parameter        const name,
                         DWORD                 const dwDesiredAccess,
                         DWORD                 const dwShareMode,
                         LPSECURITY_ATTRIBUTES const lpSecurityAttributes,
                         DWORD                 const dwCreationDistribution,
                         DWORD                 const dwFlagsAndAttributes,
                         HANDLE                const hTemplateFile)
{
 if(!this->Close())
  return FALSE;

 this->handle=::CreateFile(name.c_str(),
                           dwDesiredAccess,
                           dwShareMode,
                           lpSecurityAttributes,
                           dwCreationDistribution,
                           dwFlagsAndAttributes,
                           hTemplateFile);

 return (this->handle!=INVALID_HANDLE_VALUE)?TRUE:FALSE;
}//Create

//------------------------------------------------------------------------
BOOL TFileHandle::Close()
{
 if(this->handle==INVALID_HANDLE_VALUE)
  return TRUE;

 if(!::CloseHandle(this->handle))
  return FALSE;

 this->handle=INVALID_HANDLE_VALUE;

 return TRUE;
}//Close

//------------------------------------------------------------------------
BOOL TFileHandle::Write(LPCVOID      const lpBuffer,
                        DWORD        const nNumberOfBytesToWrite,
                        DWORD&             nNumberOfBytesWritten,
                        LPOVERLAPPED const lpOverlapped)
{
 assert(this->handle!=INVALID_HANDLE_VALUE);

 CHECK_READ_PTR(lpBuffer,nNumberOfBytesToWrite);

 return ::WriteFile(this->handle,
                    lpBuffer,
                    nNumberOfBytesToWrite,
                    &nNumberOfBytesWritten,
                    lpOverlapped);
}//Write

//------------------------------------------------------------------------
BOOL TFileHandle::Read(LPVOID       const lpBuffer,
                       DWORD        const nNumberOfBytesToRead,
                       DWORD&             nNumberOfBytesRead,
                       LPOVERLAPPED const lpOverlapped)
{
 assert(this->handle!=INVALID_HANDLE_VALUE);

 CHECK_WRITE_PTR(lpBuffer,nNumberOfBytesToRead);

 return ::ReadFile(this->handle,
                   lpBuffer,
                   nNumberOfBytesToRead,
                   &nNumberOfBytesRead,
                   lpOverlapped);
}//Read

//------------------------------------------------------------------------
DWORD TFileHandle::SetPointer(LONG  const lDistanceToMove,
                              PLONG const lpDistanceToMoveHight,
                              DWORD const dwMoveMethod)
{
 assert(this->handle!=INVALID_HANDLE_VALUE);

 return ::SetFilePointer(this->handle,
                         lDistanceToMove,
                         lpDistanceToMoveHight,
                         dwMoveMethod);
}//SetPointer

//------------------------------------------------------------------------
BOOL TFileHandle::SetEOF()
{
 assert(this->handle!=INVALID_HANDLE_VALUE);

 return ::SetEndOfFile(this->handle);
}//SetEOF

//------------------------------------------------------------------------
BOOL TFileHandle::FlushBuffers()
{
 assert(this->handle!=INVALID_HANDLE_VALUE);

 return ::FlushFileBuffers(this->handle);
}//FlushBuffers

//------------------------------------------------------------------------
BOOL TFileHandle::GetTime(LPFILETIME const lpCreationTime,
                          LPFILETIME const lpLastAccessTime,
                          LPFILETIME const lpLastWriteTime)
{
 assert(this->handle!=INVALID_HANDLE_VALUE);

 return ::GetFileTime(this->handle,
                      lpCreationTime,
                      lpLastAccessTime,
                      lpLastWriteTime);
}//GetTime

//------------------------------------------------------------------------
BOOL TFileHandle::SetTime(LPCFILETIME const lpCreationTime,
                          LPCFILETIME const lpLastAccessTime,
                          LPCFILETIME const lpLastWriteTime)
{
 assert(this->handle!=INVALID_HANDLE_VALUE);

 return ::SetFileTime(this->handle,
                      lpCreationTime,
                      lpLastAccessTime,
                      lpLastWriteTime);
}//SetTime

////////////////////////////////////////////////////////////////////////////////
//class TFindFileHandle

TFindFileHandle::TFindFileHandle()
 :m_handle(INVALID_HANDLE_VALUE)
{;}

//------------------------------------------------------------------------
TFindFileHandle::~TFindFileHandle()
{
 _VERIFY(this->Close());
}//~TFindFileHandle

//------------------------------------------------------------------------
BOOL TFindFileHandle::Close()
{
 if(m_handle==INVALID_HANDLE_VALUE)
  return true;

 const BOOL res=::FindClose(m_handle);

 if(res)
  m_handle=INVALID_HANDLE_VALUE;

 return res;
}//Close

//------------------------------------------------------------------------
BOOL TFindFileHandle::Find(const t_string& FileName,WIN32_FIND_DATA& FindData)
{
 BOOL res;

 if(m_handle!=INVALID_HANDLE_VALUE)
 {
  res=::FindNextFile(m_handle,&FindData);

  if(!res)
   this->Close();
 }
 else
 {
  m_handle=::FindFirstFile(FileName.c_str(),&FindData);

  res=(m_handle!=INVALID_HANDLE_VALUE);
 }

 return res;
}//Find

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
