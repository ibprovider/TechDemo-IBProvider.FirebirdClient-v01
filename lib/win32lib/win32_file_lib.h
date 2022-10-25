////////////////////////////////////////////////////////////////////////////////
// Классы для работы с Win32 файлами
//                                     Коваленко Дмитрий. 17 ноября 2000 года.
#ifndef _win32_file_lib_H_
#define _win32_file_lib_H_

#include <win32lib/win32_base.h>
#include <structure/t_str_parameter.h>
#include <structure/t_threads.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//Containings

class  TFileHandle;

template<class ThreadTraits>
class  TTemporaryFile64; //64bit access

struct TFindFileData;
class  TFindFileHandle;

////////////////////////////////////////////////////////////////////////////////
//Utility

//return full file path or "" for any error (use ::GetLastError())
t_string GetFullPathName(LPCTSTR lpszFileName);

t_string GetTempPath();

t_string GetCurrentDirectory();

////////////////////////////////////////////////////////////////////////////////
//class TFileHandle

class TFileHandle
{
 private:
  typedef TFileHandle            self_type;

  TFileHandle(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef FILETIME*                            LPFILETIME;
  typedef const FILETIME*                      LPCFILETIME;

  typedef structure::t_str_parameter<t_char>   tstr_parameter;

 public:
  HANDLE handle;

  TFileHandle();

 ~TFileHandle();

  //operators ------------------------------------------------------------
  operator HANDLE () const;

  bool operator ! () const;

  bool IsOpen() const;

  //file manipulations ---------------------------------------------------
  BOOL Create(tstr_parameter        name,
              DWORD                 dwDesiredAccess,
              DWORD                 dwShareMode,
              LPSECURITY_ATTRIBUTES lpSecurityAttributes,
              DWORD                 dwCreationDistribution,
              DWORD                 dwFlagsAndAttributes,
              HANDLE                hTemplateFile=NULL);

  BOOL Close();

  DWORD GetSize(LPDWORD lpFileSizeHigh)const;

  BOOL GetSizeEx(PLARGE_INTEGER lpFileSize)const;

  BOOL Write(LPCVOID       lpBuffer,
             DWORD         nNumberOfBytesToWrite,
             DWORD&        nNumberOfBytesWritten,
             LPOVERLAPPED  lpOverlapped=NULL);

  //error code - GetLastError()
  // ERROR_HANDLE_EOF - EOF
  BOOL Read(LPVOID         lpBuffer,
            DWORD          nNumberOfBytesToRead,
            DWORD&         nNumberOfBytesRead,
            LPOVERLAPPED   lpOverlapped=NULL);

  DWORD SetPointer(LONG    lDistanceToMove,
                   PLONG   lpDistanceToMoveHight,
                   DWORD   dwMoveMethod);

  BOOL SetEOF();

  BOOL FlushBuffers();

  //file time manipulations ----------------------------------------------
  BOOL GetTime(LPFILETIME lpCreationTime,
               LPFILETIME lpLastAccessTime,
               LPFILETIME lpLastWriteTime);

  BOOL SetTime(LPCFILETIME lpCreationTime,
               LPCFILETIME lpLastAccessTime,
               LPCFILETIME lpLastWriteTime);
};//class TFileHandle

////////////////////////////////////////////////////////////////////////////////
//class TTemporaryFile64 (64bit)

template<class ThreadTraits>
class TTemporaryFile64
{
 private:
  typedef TTemporaryFile64<ThreadTraits>              self_type;

  TTemporaryFile64(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef size_t                                      size_type;
  typedef unsigned __int64                            position_type;
  typedef ThreadTraits                                thread_traits;

 private:
  typedef typename thread_traits::guard_type          guard_type;
  typedef typename thread_traits::lock_guard_type     lock_guard_type;

  typedef DWORD                                       win32_buffer_size_type;

 public:
  //default: FILE_ATTRIBUTE_TEMPORARY|FILE_FLAG_DELETE_ON_CLOSE
  DWORD m_dwFlagsAndAttributes;

  t_string m_TempFileDir;

 public:
  TTemporaryFile64();

 ~TTemporaryFile64();

  //interface ------------------------------------------------------------
  bool is_created();

  //в случае ошибки генерирует t_win32_error
  //return: always true
  bool  read(position_type       pos,
             size_type     const cbBuffer,
             void*         const lpBuffer,
             size_type&          nReadBytes);

  bool write(position_type       pos,
             size_type     const cbBuffer,
             const void*   const lpBuffer,
             size_type&          nWriteBytes);

  void flush();

  void clear(position_type /*pos*/,size_type /*length*/)
   {;}

  static position_type calc_position(position_type index,size_type scale)
   {return index*scale;}

 private:
  void throw_file_error(DWORD dwError,const char* msg_template_1);

 private:
  guard_type  m_guard;

  //handle of temporary file
  HANDLE      m_hFile;

  //full name of temporary file
  t_string    m_FileName;
};//class TTemporaryFile64

typedef TTemporaryFile64<structure::t_single_thread_traits>    TTemporaryFile64_ST;
typedef TTemporaryFile64<structure::t_multi_thread_traits>     TTemporaryFile64_MT;

////////////////////////////////////////////////////////////////////////////////
//struct TFindFileData

struct TFindFileData:public WIN32_FIND_DATA
{
 TFindFileData(DWORD Attributes=0)
 {
  Init(Attributes);
 }

 void Init(DWORD Attributes)
 {
  memset(this,0,sizeof(*this));

  dwFileAttributes=Attributes;
 }
};//class TFindFileData

////////////////////////////////////////////////////////////////////////////////
//class TFindFileHandle

class TFindFileHandle
{
 private:
  typedef TFindFileHandle                   self_type;

  TFindFileHandle(const self_type&);
  self_type& operator = (const self_type&);

 public:
  TFindFileHandle();

 ~TFindFileHandle();

  BOOL Close();

  BOOL Find(const t_string&  FileName,
            WIN32_FIND_DATA& FindData);

 private:
  HANDLE m_handle;
};//class TFindFileHandle

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
////////////////////////////////////////////////////////////////////////////////
#include <win32lib/win32_file_lib.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
