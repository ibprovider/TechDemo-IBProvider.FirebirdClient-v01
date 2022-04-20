////////////////////////////////////////////////////////////////////////////////
#ifndef _win32_file_lib_CC_
#define _win32_file_lib_CC_

#include <win32lib/win32_error.h>
#include <win32lib/win32lib.h>

#include <structure/utilities/string/trim.h>
#include <structure/t_algorithm.h>
#include <structure/t_str_formatter.h>
#include <structure/t_numeric_cast.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//class TFileHandle

inline TFileHandle::TFileHandle()
 :handle(INVALID_HANDLE_VALUE)
{;}

//------------------------------------------------------------------------
inline TFileHandle::~TFileHandle()
{
 _VERIFY(this->Close());
}//~TFileHandle

//operators --------------------------------------------------------------
inline TFileHandle::operator HANDLE ()const
{
 return this->handle;
}//operator HANDLE

//------------------------------------------------------------------------
inline bool TFileHandle::operator ! ()const
{
 return this->handle==INVALID_HANDLE_VALUE;
}//operator !

//------------------------------------------------------------------------
inline bool TFileHandle::IsOpen()const
{
 return this->handle!=INVALID_HANDLE_VALUE;
}//IsOpen

//------------------------------------------------------------------------
inline DWORD TFileHandle::GetSize(LPDWORD const lpFileSizeHigh)const
{
 assert(this->IsOpen());

 return ::GetFileSize(handle,lpFileSizeHigh);
}//GetSize

////////////////////////////////////////////////////////////////////////////////
//class TTemporaryFile64

template<class ThreadTraits>
TTemporaryFile64<ThreadTraits>::TTemporaryFile64()
 :m_hFile(INVALID_HANDLE_VALUE),
  m_dwFlagsAndAttributes(FILE_ATTRIBUTE_TEMPORARY|
                         FILE_FLAG_DELETE_ON_CLOSE)
{;}

//------------------------------------------------------------------------
template<class ThreadTraits>
TTemporaryFile64<ThreadTraits>::~TTemporaryFile64()
{
 if(m_hFile!=INVALID_HANDLE_VALUE)
 {
  _VERIFY(::CloseHandle(m_hFile));
 }

 m_hFile=INVALID_HANDLE_VALUE;
}//~TTemporaryFile64

//------------------------------------------------------------------------
template<class ThreadTraits>
bool TTemporaryFile64<ThreadTraits>::is_created()
{
 const lock_guard_type __lock(m_guard);

 return m_hFile!=INVALID_HANDLE_VALUE;
}//is_created

//------------------------------------------------------------------------
template<class ThreadTraits>
bool TTemporaryFile64<ThreadTraits>::read(position_type const pos,
                                          size_type     const cbBuffer,
                                          void*         const lpBuffer,
                                          size_type&          nReadBytes)
{
 nReadBytes=0;

 if(!structure::can_numeric_cast<win32_buffer_size_type>(cbBuffer))
 {
  structure::str_formatter fmsg("[win32] too large buffer size [%1] for read from file");

  fmsg<<cbBuffer;

  throw std::runtime_error(fmsg.str());
 }//if

 {
  const lock_guard_type __lock(m_guard);

  //если файл не создан, или чтение за пределами файла
  if(m_hFile==INVALID_HANDLE_VALUE)
  {
   //то говорим, что ничего не прочитали
   return true;
  }
 }//local

 //-------
 assert(m_hFile!=INVALID_HANDLE_VALUE);

 //-------
 LARGE_INTEGER liOffset;

 liOffset.QuadPart=pos;

 //-------
 {
  OVERLAPPED Overlapped;

  Overlapped.Offset       = liOffset.LowPart;
  Overlapped.OffsetHigh   = liOffset.HighPart;
  Overlapped.Internal     = 0;
  Overlapped.InternalHigh = 0;
  Overlapped.hEvent       = HANDLE(0);

  win32_buffer_size_type tmpReadBytes(0);

  const BOOL bResult=::ReadFile(m_hFile,
                                lpBuffer,
                                static_cast<win32_buffer_size_type>(cbBuffer),
                                &tmpReadBytes,
                                &Overlapped);

  assert(tmpReadBytes<=cbBuffer);

  assert(structure::can_numeric_cast(&nReadBytes,tmpReadBytes));

  structure::static_numeric_cast(&nReadBytes,tmpReadBytes);

  if(!bResult)
  {
   const DWORD dwError=::GetLastError();

   if(dwError!=ERROR_HANDLE_EOF)
   {
    this->throw_file_error(dwError,
                          "[win32] Can't read from temporary file [%1]");
   }
  }//if
 }//local

 return true;
}//read

//------------------------------------------------------------------------
template<class ThreadTraits>
bool TTemporaryFile64<ThreadTraits>::write(position_type const pos,
                                           size_type     const cbBuffer,
                                           const void*   const lpBuffer,
                                           size_type&          nWriteBytes)
{
 nWriteBytes=0;

 if(!structure::can_numeric_cast<win32_buffer_size_type>(cbBuffer))
 {
  structure::str_formatter fmsg("[win32] too large buffer size [%1] for write to file");

  fmsg<<cbBuffer;

  throw std::runtime_error(fmsg.str());
 }//if

 {
  lock_guard_type __lock(m_guard);

  if(m_hFile==INVALID_HANDLE_VALUE)//создание временного файла
  {
   structure::self_trim(m_FileName=m_TempFileDir);

   if(m_FileName.empty())
    m_FileName=win32lib::GetTempPath();

   structure::t_typed_simple_buffer<TCHAR,structure::t_void_allocator>
    tmpBuffer(m_FileName.size()+MAX_PATH+16+1);

   assert(!tmpBuffer.empty());

   if(::GetTempFileName(m_FileName.c_str(),_T("_db"),0,tmpBuffer.buffer())==0)
   {
    t_win32_error::throw_error(::GetLastError(),
                               "[win32] Can't generate the name for temporary file");
   }

   {
    TCHAR* const e=std::find(tmpBuffer.buffer(),tmpBuffer.buffer_end(),0);

    if(e==tmpBuffer.buffer())
    {
     throw std::runtime_error("[BUG CHECK] Incorrect work of GetTempFileName. Check point: #001.");
    }//if

    if(e==tmpBuffer.buffer_end())
    {
     throw std::runtime_error("[BUG CHECK] Incorrect work of GetTempFileName. Check point: #002.");
    }//if

    m_FileName.assign(tmpBuffer.buffer(),e);

    assert(!m_FileName.empty());

    m_hFile=::CreateFile(m_FileName.c_str(),
                         GENERIC_READ|GENERIC_WRITE,
                         0,
                         NULL,
                         CREATE_ALWAYS,
                         m_dwFlagsAndAttributes,NULL);
   }//local

   if(m_hFile==INVALID_HANDLE_VALUE)
   {
    this->throw_file_error(::GetLastError(),
                           "[win32] Can't create a temporary file [%1]");
   }
  }//if
 }//local

 //-------
 assert(m_hFile!=INVALID_HANDLE_VALUE);

 //-------
 LARGE_INTEGER liOffset;

 liOffset.QuadPart=pos;

 //-------
 {
  OVERLAPPED Overlapped;

  Overlapped.Offset       = liOffset.LowPart;
  Overlapped.OffsetHigh   = liOffset.HighPart;
  Overlapped.Internal     = 0;
  Overlapped.InternalHigh = 0;
  Overlapped.hEvent       = HANDLE(0);

  win32_buffer_size_type tmpWriteBytes(0);

  const BOOL bResult=::WriteFile(m_hFile,
                                 lpBuffer,
                                 static_cast<win32_buffer_size_type>(cbBuffer),
                                 &tmpWriteBytes,
                                 &Overlapped);

  assert(tmpWriteBytes<=cbBuffer);

  assert(structure::can_numeric_cast(&nWriteBytes,tmpWriteBytes));

  structure::static_numeric_cast(&nWriteBytes,tmpWriteBytes);

  if(!bResult)
  {
   this->throw_file_error(::GetLastError(),
                          "[win32] Can't write to temporary file [%1]");
  }
 }//local

 return true;
}//write

//------------------------------------------------------------------------
template<class ThreadTraits>
void TTemporaryFile64<ThreadTraits>::flush()
{
 {
  const lock_guard_type __lock(m_guard);

  //если файл не создан
  if(m_hFile==INVALID_HANDLE_VALUE)
  {
   //то ничего не делаем
   return;
  }
 }//local

 if(!::FlushFileBuffers(m_hFile))
 {
  this->throw_file_error(::GetLastError(),
                         "[win32] Can't flush the buffers of temporary file [%1]");
 }//if

 return;
}//flush

//------------------------------------------------------------------------
template<class ThreadTraits>
void TTemporaryFile64<ThreadTraits>::throw_file_error
                                           (DWORD const       dwError,
                                            const char* const msg_template_1)
{
 structure::str_formatter fmsg(msg_template_1);

 fmsg<<m_FileName;

 t_win32_error::throw_error(dwError,fmsg.str());
}//throw_file_error

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
#endif
