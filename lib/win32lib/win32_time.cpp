////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <win32lib/win32_time.h>
#include <tchar.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//class TFileTime

t_string TFileTime::Time()const
{
 SYSTEMTIME systime;

 if(::FileTimeToSystemTime(&m_ftime,&systime)==FALSE)
  return t_string();

 return TSystemTime::Time(systime);
}//Time

//------------------------------------------------------------------------
t_string TFileTime::Date()const
{
 SYSTEMTIME systime;
 
 if(::FileTimeToSystemTime(&m_ftime,&systime)==FALSE)
  return t_string();

 return TSystemTime::Date(systime);
}//Date

//------------------------------------------------------------------------
t_string TFileTime::DateTime()const
{
 SYSTEMTIME systime;

 if(::FileTimeToSystemTime(&m_ftime,&systime)==FALSE)
  return t_string();

 return TSystemTime::DateTime(systime);
}//DateTime

////////////////////////////////////////////////////////////////////////////////
//class TSystemTime

t_string TSystemTime::Date(const SYSTEMTIME& sys)
{
 TCHAR tmp[128];

 LCPI_GCRT_stprintf_s_n3
  (tmp,_DIM_(tmp),
   _T("%02d.%02d.%04d"),
   sys.wDay,
   sys.wMonth,
   sys.wYear);

 return t_string(tmp);
}//Date

//------------------------------------------------------------------------
t_string TSystemTime::Time(const SYSTEMTIME& sys)
{
 TCHAR tmp[128];

 LCPI_GCRT_stprintf_s_n3
  (tmp,_DIM_(tmp),
   _T("%02d:%02d:%02d"),
   sys.wHour,
   sys.wMinute,
   sys.wSecond);

 return t_string(tmp);
}//Time

//------------------------------------------------------------------------
t_string TSystemTime::DateTime(const SYSTEMTIME& sys)
{
 TCHAR tmp[256];

 LCPI_GCRT_stprintf_s_n6
  (tmp,_DIM_(tmp),
   _T("%02d.%02d.%04d %02d:%02d:%02d"),
   sys.wDay,
   sys.wMonth,
   sys.wYear,
   sys.wHour,
   sys.wMinute,
   sys.wSecond);

 return t_string(tmp);
}//DateTime

////////////////////////////////////////////////////////////////////////////////
//struct TThreadTime

BOOL TThreadTime::Start(bool restart)
{
 if(restart)
 {
  m_KernelSumTime=0;
  m_UserSumTime  =0;
 }

 FILETIME tmp;

 return ::GetThreadTimes(GetCurrentThread(),
                         &tmp,               //creation time
                         &tmp,               //exit time
                         &m_KernelStartTime,
                         &m_UserStartTime);
}//Start

//------------------------------------------------------------------------
BOOL TThreadTime::Stop()
{
 FILETIME tmp;
 FILETIME KernelTime;
 FILETIME UserTime;

 //Stop and start must be called in one thread :)
 if(BOOL const bRes=::GetThreadTimes(GetCurrentThread(),&tmp,&tmp,&KernelTime,&UserTime))
 {
  m_KernelSumTime+=FileTimeToQuad(KernelTime)-FileTimeToQuad(m_KernelStartTime);
  m_UserSumTime  +=FileTimeToQuad(UserTime)-FileTimeToQuad(m_UserStartTime);

  return TRUE;
 }

 return FALSE;
}//Stop

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
