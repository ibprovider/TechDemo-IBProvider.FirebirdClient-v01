////////////////////////////////////////////////////////////////////////////////
//Classes and functions for work with "WIN32-TIME"
//                                                 Dmitry Kovalenko. 13.04.2004.
#ifndef _win32_time_H_
#define _win32_time_H_

#include <win32lib/win32_base.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//containings

class TFileTime;
class TSystemTime;
class TThreadTime;

////////////////////////////////////////////////////////////////////////////////
//FILETIME transformer

inline __int64 FileTimeToQuad(const FILETIME& FileTime)
{
 return (static_cast<__int64>(FileTime.dwHighDateTime)<<32)+FileTime.dwLowDateTime;
}

//------------------------------------------------------------------------
inline LARGE_INTEGER FileTimeToLargeInt(const FILETIME& FileTime)
{
 const __int64 i64=FileTimeToQuad(FileTime);

 return *reinterpret_cast<const LARGE_INTEGER*>(&i64);
}

//------------------------------------------------------------------------
inline FILETIME& QuadToFileTime(__int64 i64,FILETIME& file_time)
{
 file_time.dwHighDateTime=*(reinterpret_cast<const DWORD*>(&i64)+1);
 file_time.dwLowDateTime =*(reinterpret_cast<const DWORD*>(&i64));

 return file_time;
}

//------------------------------------------------------------------------
inline FILETIME& LargeIntToFileTime(LARGE_INTEGER large_int,FILETIME& file_time)
{
 file_time.dwHighDateTime=*(reinterpret_cast<const DWORD*>(&large_int.QuadPart)+1);
 file_time.dwLowDateTime =*(reinterpret_cast<const DWORD*>(&large_int.QuadPart));

 return file_time;
}

////////////////////////////////////////////////////////////////////////////////
//class TFileTime

class TFileTime
{
 private:
  FILETIME m_ftime;

 public:
  TFileTime()
  {
   ::GetSystemTimeAsFileTime(&m_ftime);
  }

  TFileTime(const TFileTime& ft)
   :m_ftime(ft.m_ftime)
  {;}

  TFileTime(const FILETIME& ftime)
   :m_ftime(ftime)
  {;}

  TFileTime(LARGE_INTEGER large_int)
  {
   LargeIntToFileTime(large_int,m_ftime);
  }

  TFileTime(__int64 large_int)
  {
   QuadToFileTime(large_int,m_ftime);
  }

  TFileTime(const SYSTEMTIME& systime)
  {
   ::SystemTimeToFileTime(&systime,&m_ftime);
  }

  TFileTime& operator = (const TFileTime& ft)
  {
   m_ftime=ft.m_ftime;
   return *this;
  }

  t_string Time()const;
  t_string Date()const;
  t_string DateTime()const;

  bool operator == (FILETIME time)const
   {return memcmp(&m_ftime,&time,sizeof(FILETIME))==0;}

  bool operator != (FILETIME time)const
   {return memcmp(&m_ftime,&time,sizeof(FILETIME))!=0;}

  bool operator < (FILETIME time)const
   {return FileTimeToQuad(m_ftime)<FileTimeToQuad(time);}

  bool operator <=(FILETIME time)const
   {return FileTimeToQuad(m_ftime)<=FileTimeToQuad(time);}

  bool operator > (FILETIME time)const
   {return FileTimeToQuad(m_ftime)>FileTimeToQuad(time);}

  bool operator >=(FILETIME time)const
   {return FileTimeToQuad(m_ftime)>=FileTimeToQuad(time);}

  operator FILETIME&       ()       {return m_ftime;}
  operator FILETIME*       ()       {return &m_ftime;}
  operator const FILETIME* () const {return &m_ftime;}

  operator __int64         () const {return FileTimeToQuad(m_ftime);}
  operator LARGE_INTEGER   () const {return FileTimeToLargeInt(m_ftime);}
};//TFileTime

////////////////////////////////////////////////////////////////////////////////
//class TSystemTime

class TSystemTime
{
 public:
  static t_string Date(const SYSTEMTIME& sys);

  static t_string Time(const SYSTEMTIME& sys);

  static t_string DateTime(const SYSTEMTIME& sys);
};//class TSystemTime

////////////////////////////////////////////////////////////////////////////////
//struct TThreadTime

class TThreadTime
{
 private:
  FILETIME m_KernelStartTime;//kernel mode
  FILETIME m_UserStartTime;  //user mode

  __int64  m_KernelSumTime;
  __int64  m_UserSumTime;

 public:
  TThreadTime()
  {
   this->Start();
  }

  BOOL Start(bool restart=true);
  BOOL Stop();

  const __int64& KernelTime ()const  {return m_KernelSumTime;}
  const __int64& UserTime   ()const  {return m_UserSumTime;}
  __int64        Time       ()const  {return KernelTime()+UserTime();}
};//TThreadTime

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
#endif
