////////////////////////////////////////////////////////////////////////////////
//Classes and functions for work with "WIN32-TIME"
//                                                 Dmitry Kovalenko. 13.04.2004.
#ifndef _win32_time_H_
#define _win32_time_H_

#include <win32lib/win32_base.h>
#include <cstdint>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//containings

class TFileTime;
class TSystemTime;
class TThreadTime;

////////////////////////////////////////////////////////////////////////////////
//FILETIME transformer

inline std::int64_t FileTimeToQuad(const FILETIME& FileTime)
{
 return (static_cast<std::int64_t>(FileTime.dwHighDateTime)<<32)+FileTime.dwLowDateTime;
}//FileTimeToQuad

//------------------------------------------------------------------------
inline LARGE_INTEGER FileTimeToLargeInt(const FILETIME& FileTime)
{
 const std::int64_t i64=FileTimeToQuad(FileTime);

 return *reinterpret_cast<const LARGE_INTEGER*>(&i64);
}//FileTimeToLargeInt

//------------------------------------------------------------------------
inline FILETIME& QuadToFileTime(std::int64_t i64,FILETIME& file_time)
{
 file_time.dwHighDateTime=*(reinterpret_cast<const DWORD*>(&i64)+1);
 file_time.dwLowDateTime =*(reinterpret_cast<const DWORD*>(&i64));

 return file_time;
}//QuadToFileTime

//------------------------------------------------------------------------
inline FILETIME& LargeIntToFileTime(LARGE_INTEGER large_int,FILETIME& file_time)
{
 file_time.dwHighDateTime=*(reinterpret_cast<const DWORD*>(&large_int.QuadPart)+1);
 file_time.dwLowDateTime =*(reinterpret_cast<const DWORD*>(&large_int.QuadPart));

 return file_time;
}//LargeIntToFileTime

////////////////////////////////////////////////////////////////////////////////
//class TFileTime

class TFileTime LCPI_CPP_CFG__CLASS__FINAL
{
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

  TFileTime(std::int64_t large_int)
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

  operator std::int64_t    () const {return FileTimeToQuad(m_ftime);}
  operator LARGE_INTEGER   () const {return FileTimeToLargeInt(m_ftime);}

 private:
  FILETIME m_ftime;
};//class TFileTime

////////////////////////////////////////////////////////////////////////////////
//class TSystemTime

class TSystemTime LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  static t_string Date(const SYSTEMTIME& sys);

  static t_string Time(const SYSTEMTIME& sys);

  static t_string DateTime(const SYSTEMTIME& sys);
};//class TSystemTime

////////////////////////////////////////////////////////////////////////////////
//struct TThreadTime

class TThreadTime LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  using time_ticks_type=std::int64_t;

 public:
  TThreadTime()
  {
   this->Start();
  }

  BOOL Start(bool restart=true);

  BOOL Stop();

  time_ticks_type KernelTime ()const  {return m_KernelSumTime;}
  time_ticks_type UserTime   ()const  {return m_UserSumTime;}

  time_ticks_type TotalTime  ()const  {return m_KernelSumTime+m_UserSumTime;}

 private:
  FILETIME m_KernelStartTime;//kernel mode
  FILETIME m_UserStartTime;  //user mode

  time_ticks_type m_KernelSumTime;
  time_ticks_type m_UserSumTime;
};//class TThreadTime

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
#endif
