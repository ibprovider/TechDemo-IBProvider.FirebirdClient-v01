////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/oledb_datetime_services.h>
#include <ole_lib/oledb/oledb_common.h>
#include <structure/t_fix_stream.h>
#include <iomanip>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class TDBDateTimeParser_Base

TDBDateTimeParser_Base::result_type
 TDBDateTimeParser_Base::ConvertTwoDigitYear(LONG  const CurrentYear,
                                             LONG  const TwoDigitYear,
                                             LONG* const pResultYear)
{
 assert(TwoDigitYear>=0);
 assert(TwoDigitYear<=99);
 assert(pResultYear);

 if(CurrentYear<0)
  return result__fail;

 if(CurrentYear<50)
 {
  (*pResultYear)=TwoDigitYear;

  return result__ok;
 }//if

 assert_hint(CurrentYear>=50);

 const auto c_MAX
  =structure::get_numeric_limits(CurrentYear).max_value();

 if((c_MAX-50)<CurrentYear)
  return result__fail;

 const LONG year2000
  =((CurrentYear+50)/100)*100;

 assert(year2000>=100);

 const LONG year1900
  =year2000-100;

 assert(year1900<year2000);
 assert(year1900>=0);

 if(TwoDigitYear<(CurrentYear+50-year2000))
 {
  if((c_MAX-TwoDigitYear)<year2000)
   return result__fail;

  (*pResultYear)=TwoDigitYear+year2000;
 }
 else
 {
  (*pResultYear)=TwoDigitYear+year1900;
 }//else

 return result__ok;
}//ConvertTwoDigitYear

//------------------------------------------------------------------------
const USHORT TDBDateTimeParser_Base::g_DaysPerMonthOfNormalYears[]=
 {31,29,31,30,31,30,31,31,30,31,30,31};

bool TDBDateTimeParser_Base::IsValidDate(LONG const Year,
                                         LONG const Month,
                                         LONG const Day)
{
 if(Year<0)
  return false;

 //-----
 if(Month<1)
  return false;

 if(12<Month)
  return false;

 //-----
 if(Day<1) // [*]
  return false;

 if(31<Day)
  return false;

 //-----
 assert_s(_DIM_(g_DaysPerMonthOfNormalYears)==12);

 assert_hint(Month>=1);
 assert_hint(size_t(Month)<=_DIM_(g_DaysPerMonthOfNormalYears));

 LONG max_days_count DEBUG_CODE(=0);

 if(Month!=2)
  max_days_count=g_DaysPerMonthOfNormalYears[Month-1];
 else
 if(/*year>=1600 && */(Year%400)==0)//correction at the border of 400 years
  max_days_count=29;                //has a 29 february
 else
 if(/*year>1600 && */(Year%100)==0)//border od century. Starting at 1600 year
  max_days_count=28;               //not has a 29 february
 else
 if((Year%4)==0)//leap year (before 1600 year, all x4 years)
  max_days_count=29;
 else
  max_days_count=28; //Simple year

 assert(max_days_count!=0);

 assert_hint(Day>=1); // see [*]

 if(max_days_count<Day)
  return false;

 assert_hint(Day<=max_days_count);

 return true;
}//IsValidDate

////////////////////////////////////////////////////////////////////////////////
//datetime comparasion

int compare_dbstamp(const DBTIMESTAMP& ts1,const DBTIMESTAMP& ts2)
{
#define CMP_PART(part_name)                 \
 if(ts1.##part_name<ts2.##part_name)        \
  return -1;                                \
                                            \
 if(ts2.##part_name<ts1.##part_name)        \
  return 1;

 CMP_PART(year)
 CMP_PART(month)
 CMP_PART(day)
 CMP_PART(hour)
 CMP_PART(minute)
 CMP_PART(second)
 CMP_PART(fraction)

#undef CMP_PART

 return 0;
}//compare_dbstamp

//------------------------------------------------------------------------
int compare_dbdate(const DBDATE& d1,const DBDATE& d2)
{
#define CMP_PART(part_name)                 \
 if(d1.##part_name<d2.##part_name)          \
  return -1;                                \
                                            \
 if(d2.##part_name<d1.##part_name)          \
  return 1;

 CMP_PART(year)
 CMP_PART(month)
 CMP_PART(day)

#undef CMP_PART

 return 0;
}//compare_dbdate

//------------------------------------------------------------------------
int compare_dbtime(const t_oledb_value__DBTIME& t1,
                   const t_oledb_value__DBTIME& t2)
{
#define CMP_PART(part_name)                 \
 if(t1.##part_name<t2.##part_name)          \
  return -1;                                \
                                            \
 if(t2.##part_name<t1.##part_name)          \
  return 1;

 CMP_PART(hour)
 CMP_PART(minute)
 CMP_PART(second)

#undef CMP_PART

 return 0;
}//compare_dbtime

//------------------------------------------------------------------------
int compare_dbtime2(const t_oledb_value__DBTIME2& t1,
                    const t_oledb_value__DBTIME2& t2)
{
#define CMP_PART(part_name)                 \
 if(t1.##part_name<t2.##part_name)          \
  return -1;                                \
                                            \
 if(t2.##part_name<t1.##part_name)          \
  return 1;

 CMP_PART(hour)
 CMP_PART(minute)
 CMP_PART(second)
 CMP_PART(fraction)

#undef CMP_PART

 return 0;
}//compare_dbtime2

////////////////////////////////////////////////////////////////////////////////

bool dbdate_to_date(const DBDATE& dbdate,DATE& date)
{
 SYSTEMTIME systime={};

 if(!dbdate_to_systime(dbdate,&systime))
  return false;

 return ::SystemTimeToVariantTime(&systime,&date)!=FALSE;
}//dbdate_to_date

//------------------------------------------------------------------------
bool dbtime_to_date(const DBTIME& dbtime,DATE& date)
{
 SYSTEMTIME systime={};

 if(!dbtime_to_systime(dbtime,&systime))
  return false;

 return ::SystemTimeToVariantTime(&systime,&date)!=FALSE;
}//dbtime_to_date

//------------------------------------------------------------------------
bool dbtime2_to_date(const t_oledb_value__DBTIME2& dbtime2,
                     t_oledb_value__DATE*    const date)
{
 assert(date);

 SYSTEMTIME systime={};

 if(!dbtime2_to_systime(dbtime2,&systime))
  return false;

 return ::SystemTimeToVariantTime(&systime,date)!=FALSE;
}//dbtime2_to_date

//------------------------------------------------------------------------
bool dbstamp_to_date(const DBTIMESTAMP& stamp,DATE& date)
{
 SYSTEMTIME systime={};

 if(!dbstamp_to_systime(stamp,&systime))
  return false;

 return ::SystemTimeToVariantTime(&systime,&date)!=FALSE;
}//dbstamp_to_date

//------------------------------------------------------------------------
void dbdate_to_dbstamp(const DBDATE& dbdate,DBTIMESTAMP* const stamp)
{
 assert(stamp);

 stamp->year    = dbdate.year;
 stamp->month   = dbdate.month;
 stamp->day     = dbdate.day;
 stamp->hour    = 0;
 stamp->minute  = 0;
 stamp->second  = 0;
 stamp->fraction= 0;

 return;
}//dbdate_to_dbstamp

////////////////////////////////////////////////////////////////////////////////

template<typename charT>
static __STL_DEF_BASIC_STRING(charT)
 dbdate_to_text(const t_oledb_value__DBDATE& dbdate)
{
 typedef charT                                             char_type;
 typedef structure::t_char_traits2<char_type>              char_traits2;
 typedef __STL_DEF_BASIC_STRING(char_type)                 string_type;
 typedef string_type::size_type                            size_type;
 typedef structure::t_basic_fix_ostream<char_type>         ostream_type;

 char_type temp[256];

 ostream_type os(temp,_DIM_(temp));

 if(dbdate.year<0)
  os<<char_traits2::ch_minus();

 os<<std::setfill(char_traits2::ch_0())<<std::setw(2)<<dbdate.day
   <<char_traits2::ch_point()
   <<std::setfill(char_traits2::ch_0())<<std::setw(2)<<dbdate.month
   <<char_traits2::ch_point()
   <<std::setfill(char_traits2::ch_0())<<std::setw(4)
   <<structure::remove_numeric_sign(dbdate.year);

 if(!os)
  return string_type();

 return string_type(os.buffer(),os.writed());
}//dbdate_to_text

//------------------------------------------------------------------------
std::string dbdate_to_str(const t_oledb_value__DBDATE& dbdate)
{
 return dbdate_to_text<std::string::value_type>(dbdate);
}//dbdate_to_str

//------------------------------------------------------------------------
std::wstring dbdate_to_wstr(const t_oledb_value__DBDATE& dbdate)
{
 return dbdate_to_text<std::wstring::value_type>(dbdate);
}//dbdate_to_wstr

////////////////////////////////////////////////////////////////////////////////

template<typename charT>
static __STL_DEF_BASIC_STRING(charT)
 dbtime_to_text(const t_oledb_value__DBTIME& dbtime)
{
 typedef charT                                             char_type;
 typedef structure::t_char_traits2<char_type>              char_traits2;
 typedef __STL_DEF_BASIC_STRING(char_type)                 string_type;
 typedef string_type::size_type                            size_type;
 typedef structure::t_basic_fix_ostream<char_type>         ostream_type;

 char_type temp[256];

 ostream_type os(temp,_DIM_(temp));

 os<<std::setfill(char_traits2::ch_0())<<std::setw(2)<<dbtime.hour
   <<char_traits2::ch_double_point()
   <<std::setfill(char_traits2::ch_0())<<std::setw(2)<<dbtime.minute
   <<char_traits2::ch_double_point()
   <<std::setfill(char_traits2::ch_0())<<std::setw(2)<<dbtime.second;

 if(!os)
  return string_type();

 return string_type(os.buffer(),os.writed());
}//dbtime_to_text

//------------------------------------------------------------------------
std::string dbtime_to_str(const t_oledb_value__DBTIME& dbtime)
{
 return dbtime_to_text<std::string::value_type>(dbtime);
}//dbtime_to_str

//------------------------------------------------------------------------
std::wstring dbtime_to_wstr(const t_oledb_value__DBTIME& dbtime)
{
 return dbtime_to_text<std::wstring::value_type>(dbtime);
}//dbtime_to_wstr

////////////////////////////////////////////////////////////////////////////////

template<typename charT>
static __STL_DEF_BASIC_STRING(charT)
 dbtime2_to_text(const t_oledb_value__DBTIME2& dbtime2)
{
 typedef charT                                             char_type;
 typedef structure::t_char_traits2<char_type>              char_traits2;
 typedef __STL_DEF_BASIC_STRING(char_type)                 string_type;
 typedef string_type::size_type                            size_type;
 typedef structure::t_basic_fix_ostream<char_type>         ostream_type;

 char_type temp[256];

 ostream_type os(temp,_DIM_(temp));

 os<<std::setfill(char_traits2::ch_0())<<std::setw(2)<<dbtime2.hour
   <<char_traits2::ch_double_point()
   <<std::setfill(char_traits2::ch_0())<<std::setw(2)<<dbtime2.minute
   <<char_traits2::ch_double_point()
   <<std::setfill(char_traits2::ch_0())<<std::setw(2)<<dbtime2.second;

 if(dbtime2.fraction!=0)
 {
  os<<char_traits2::ch_point();

  ULONG f=dbtime2.fraction;
  ULONG d=100000000;

  while(d!=0 && f!=0)
  {
   const ULONG x=f/d;

   if(x>9)
    return string_type();

   os<<char_type(char_traits2::ch_0()+x);

   assert((x*d)<=f);

   f=f-(x*d);

   d=d/10;
  }//while
 }//if fraction!=0

 if(!os)
  return string_type();

 return string_type(os.buffer(),os.writed());
}//dbtime2_to_text

//------------------------------------------------------------------------
std::string dbtime2_to_str(const t_oledb_value__DBTIME2& dbtime2)
{
 return dbtime2_to_text<std::string::value_type>(dbtime2);
}//dbtime2_to_str

//------------------------------------------------------------------------
std::wstring dbtime2_to_wstr(const t_oledb_value__DBTIME2& dbtime2)
{
 return dbtime2_to_text<std::wstring::value_type>(dbtime2);
}//dbtime2_to_wstr

////////////////////////////////////////////////////////////////////////////////

static inline bool dbstamp_to_text__need_print_time
                     (const t_oledb_value__DBTIMESTAMP& dbstamp,
                      dbstamp_to_str_mode   const       mode)
{
 if(mode!=dbstamp_to_str_mode_smart)
  return true;

 if(dbstamp.hour!=0 || dbstamp.minute!=0 || dbstamp.second!=0 || dbstamp.fraction!=0)
  return true;

 return false;
}//dbstamp_to_text__need_print_time

//------------------------------------------------------------------------
template<typename charT>
static __STL_DEF_BASIC_STRING(charT)
 dbstamp_to_text(const t_oledb_value__DBTIMESTAMP& dbstamp,
                 dbstamp_to_str_mode   const       mode)
{
 typedef charT                                             char_type;
 typedef structure::t_char_traits2<char_type>              char_traits2;
 typedef __STL_DEF_BASIC_STRING(char_type)                 string_type;
 typedef string_type::size_type                            size_type;
 typedef structure::t_basic_fix_ostream<char_type>         ostream_type;

 char_type temp[256];

 ostream_type os(temp,_DIM_(temp));

 if(dbstamp.year<0)
  os<<char_traits2::ch_minus();

 os<<std::setfill(char_traits2::ch_0())<<std::setw(2)<<dbstamp.day
   <<char_traits2::ch_point()
   <<std::setfill(char_traits2::ch_0())<<std::setw(2)<<dbstamp.month
   <<char_traits2::ch_point()
   <<std::setfill(char_traits2::ch_0())<<std::setw(4)
   <<structure::remove_numeric_sign(dbstamp.year);

 if(dbstamp_to_text__need_print_time(dbstamp,mode))
 {
  //append time part
  os<<char_traits2::ch_space()
    <<std::setfill(char_traits2::ch_0())<<std::setw(2)<<dbstamp.hour
    <<char_traits2::ch_double_point()
    <<std::setfill(char_traits2::ch_0())<<std::setw(2)<<dbstamp.minute
    <<char_traits2::ch_double_point()
    <<std::setfill(char_traits2::ch_0())<<std::setw(2)<<dbstamp.second;

  if(dbstamp.fraction!=0)
  {
   os<<char_traits2::ch_point();

   ULONG f=dbstamp.fraction;
   ULONG d=100000000;

   while(d!=0 && f!=0)
   {
    const ULONG x=f/d;

    if(x>9)
     return string_type();

    os<<char_type(char_traits2::ch_0()+x);

    assert((x*d)<=f);

    f=f-(x*d);

    d=d/10;
   }//while
  }//if fraction!=0
 }//if dbstamp_to_text__need_print_time

 if(!os)
  return string_type();

 assert(structure::can_numeric_cast<size_type>(__STL_GET_STREAM_TELLP_VALUE(os)));

 assert(__STL_GET_STREAM_TELLP_VALUE(os)<=_DIM_(temp));

 return string_type(temp,static_cast<size_type>(__STL_GET_STREAM_TELLP_VALUE(os)));
}//dbstamp_to_text

//------------------------------------------------------------------------
std::string dbstamp_to_str(const t_oledb_value__DBTIMESTAMP& dbstamp,
                           dbstamp_to_str_mode   const       mode)
{
 return dbstamp_to_text<std::string::value_type>(dbstamp,mode);
}//dbstamp_to_str

//------------------------------------------------------------------------
std::wstring dbstamp_to_wstr(const t_oledb_value__DBTIMESTAMP& dbstamp,
                             dbstamp_to_str_mode   const       mode)
{
 return dbstamp_to_text<std::wstring::value_type>(dbstamp,mode);
}//dbstamp_to_wstr

////////////////////////////////////////////////////////////////////////////////

bool date_to_dbdate(const DATE& date,DBDATE& dbdate)
{
 SYSTEMTIME systime={};

 if(!VariantTimeToSystemTime(date,&systime))
  return false;

 dbdate.year  = systime.wYear  ;
 dbdate.month = systime.wMonth ;
 dbdate.day   = systime.wDay   ;

 return true;
}//date_to_dbdate

//------------------------------------------------------------------------
bool date_to_dbtime(const DATE& date,DBTIME& dbtime)
{
 SYSTEMTIME systime={};

 if(!VariantTimeToSystemTime(date,&systime))
  return false;

 dbtime.hour   = systime.wHour   ;
 dbtime.minute = systime.wMinute ;
 dbtime.second = systime.wSecond ;

 return true;
}//date_to_dbtime

//------------------------------------------------------------------------
bool date_to_dbtime2(const DATE& date,t_oledb_value__DBTIME2* const dbtime2)
{
 assert(dbtime2);

 SYSTEMTIME systime={};

 if(!VariantTimeToSystemTime(date,&systime))
  return false;

 dbtime2->hour     = systime.wHour   ;
 dbtime2->minute   = systime.wMinute ;
 dbtime2->second   = systime.wSecond ;
 dbtime2->fraction = 1000000*systime.wMilliseconds;

 return true;
}//date_to_dbtime2

//------------------------------------------------------------------------
bool date_to_dbstamp(const DATE& date,DBTIMESTAMP* const dbstamp)
{
 assert(dbstamp);

 SYSTEMTIME systime={};

 if(!VariantTimeToSystemTime(date,&systime))
  return false;

 return systime_to_dbstamp(systime,dbstamp);
}//date_to_dbstamp

//------------------------------------------------------------------------
bool systime_to_dbstamp(const SYSTEMTIME& systime,DBTIMESTAMP* const dbstamp)
{
 assert(dbstamp);

 dbstamp->year    = systime.wYear  ;
 dbstamp->month   = systime.wMonth ;
 dbstamp->day     = systime.wDay   ;
 dbstamp->hour    = systime.wHour  ;
 dbstamp->minute  = systime.wMinute;
 dbstamp->second  = systime.wSecond;
 dbstamp->fraction= 1000000*systime.wMilliseconds;

 return true;
}//systime_to_dbstamp

//------------------------------------------------------------------------
bool dbdate_to_systime(const t_oledb_value__DBDATE& dbdate,
                       SYSTEMTIME*            const systime)
{
 assert(systime);

 systime->wYear          = dbdate.year;
 systime->wMonth         = dbdate.month;
 systime->wDayOfWeek     = 0;
 systime->wDay           = dbdate.day;
 systime->wHour          = 0;
 systime->wMinute        = 0;
 systime->wSecond        = 0;
 systime->wMilliseconds  = 0;

 return true;
}//dbdate_to_systime

//------------------------------------------------------------------------
bool dbtime_to_systime(const t_oledb_value__DBTIME& dbtime,
                       SYSTEMTIME*            const systime)
{
 assert(systime);

 systime->wYear          = __zero_dbdate__.year;
 systime->wMonth         = __zero_dbdate__.month;
 systime->wDayOfWeek     = __zero_dbdate_DayOfWeek__;
 systime->wDay           = __zero_dbdate__.day;
 systime->wHour          = dbtime.hour;
 systime->wMinute        = dbtime.minute;
 systime->wSecond        = dbtime.second;
 systime->wMilliseconds  = 0;

 return true;
}//dbtime_to_systime

//------------------------------------------------------------------------
bool dbtime2_to_systime(const t_oledb_value__DBTIME2& dbtime2,
                        SYSTEMTIME*             const systime)
{
 assert(systime);

 systime->wYear          = __zero_dbdate__.year;
 systime->wMonth         = __zero_dbdate__.month;
 systime->wDayOfWeek     = __zero_dbdate_DayOfWeek__;
 systime->wDay           = __zero_dbdate__.day;
 systime->wHour          = dbtime2.hour;
 systime->wMinute        = dbtime2.minute;
 systime->wSecond        = dbtime2.second;
 systime->wMilliseconds  = WORD(dbtime2.fraction/1000000);

 return true;
}//dbtime2_to_systime

//------------------------------------------------------------------------
bool dbstamp_to_systime(const t_oledb_value__DBTIMESTAMP& stamp,
                        SYSTEMTIME*                 const systime)
{
 assert(systime);

 systime->wYear          = stamp.year;
 systime->wMonth         = stamp.month;
 systime->wDayOfWeek     = 0;
 systime->wDay           = stamp.day;
 systime->wHour          = stamp.hour;
 systime->wMinute        = stamp.minute;
 systime->wSecond        = stamp.second;
 systime->wMilliseconds  = WORD(stamp.fraction/1000000);

 return true;
}//dbstamp_to_systime

//-------------------------------------------------------------------------
bool filetime_to_dbstamp(const FILETIME& filetime,DBTIMESTAMP* const ts)
{
 assert(ts);

 SYSTEMTIME systime={};

 if(!::FileTimeToSystemTime(&filetime,&systime))
  return false;

 ts->year   = systime.wYear;
 ts->month  = systime.wMonth;
 ts->day    = systime.wDay;
 ts->hour   = systime.wHour;
 ts->minute = systime.wMinute;
 ts->second = systime.wSecond;

 unsigned __int64 tmp =filetime.dwHighDateTime;

 tmp*=0x100000000;
 tmp+=filetime.dwLowDateTime;

 ts->fraction =ULONG(100*(tmp%10000000));

 return true;
}//filetime_to_dbstamp

//-------------------------------------------------------------------------
bool dbstamp_to_filetime(const DBTIMESTAMP& ts,FILETIME* const filetime)
{
 assert(filetime);

 if(ts.fraction>999999999)
  return false;

 if(ts.year<1601)
  return false;

 //14.09.30828 02:48:05.4775
 const DBTIMESTAMP max_ft={30828,9,14,2,48,5,477580700};

 if(compare_dbstamp(max_ft,ts)<0)
  return false;

 SYSTEMTIME systime={};

 systime.wYear   = ts.year;
 systime.wMonth  = ts.month;
 systime.wDay    = ts.day;
 systime.wHour   = ts.hour;
 systime.wMinute = ts.minute;
 systime.wSecond = ts.second;

 if(!SystemTimeToFileTime(&systime,filetime))
  return false;

 __int64 tmp=filetime->dwHighDateTime;

 tmp*=0x100000000;
 tmp+=filetime->dwLowDateTime;
 tmp+=ts.fraction/100;

 filetime->dwHighDateTime=DWORD(tmp/0x100000000);
 filetime->dwLowDateTime =DWORD(tmp-__int64(filetime->dwHighDateTime*0x100000000));

 return true;
}//dbstamp_to_filetime

////////////////////////////////////////////////////////////////////////////////

bool filetime_to_dbdate(const FILETIME& filetime,DBDATE* const dbdate)
{
 assert(dbdate);

 SYSTEMTIME st={};

 if(!::FileTimeToSystemTime(&filetime,&st))
  return false;

 //--------
 dbdate->year  = st.wYear;
 dbdate->month = st.wMonth;
 dbdate->day   = st.wDay;

 //--------
 return true;
}//filetime_to_dbdate

//------------------------------------------------------------------------
bool dbdate_to_filetime(const DBDATE& dbdate,FILETIME* const filetime)
{
 assert(filetime);

 if(dbdate.year<1601)
  return false;

 const DBDATE max_ft={30828,9,14};

 if(compare_dbdate(max_ft,dbdate)<0)
  return false;

 SYSTEMTIME systime={};

 if(!dbdate_to_systime(dbdate,&systime))
  return false;

 return ::SystemTimeToFileTime(&systime,filetime)!=FALSE;
}//dbdate_to_filetime

//------------------------------------------------------------------------
bool filetime_to_dbtime2(const t_oledb_value__FILETIME& filetime,
                         t_oledb_value__DBTIME2* const  t)
{
 assert(t);

 SYSTEMTIME systime={};

 if(!::FileTimeToSystemTime(&filetime,&systime))
  return false;

 t->hour   = systime.wHour;
 t->minute = systime.wMinute;
 t->second = systime.wSecond;

 unsigned __int64 tmp =filetime.dwHighDateTime;

 tmp*=0x100000000;
 tmp+=filetime.dwLowDateTime;

 t->fraction =ULONG(100*(tmp%10000000));

 return true;
}//filetime_to_dbtime2

//-------------------------------------------------------------------------
bool dbtime2_to_filetime(const t_oledb_value__DBTIME2&  t,
                         t_oledb_value__FILETIME* const filetime)
{
 assert(filetime);

 if(t.fraction>999999999)
  return false;

 SYSTEMTIME systime={};

 systime.wYear   = __zero_dbdate__.year;
 systime.wMonth  = __zero_dbdate__.month;
 systime.wDay    = __zero_dbdate__.day;
 systime.wHour   = t.hour;
 systime.wMinute = t.minute;
 systime.wSecond = t.second;

 if(!::SystemTimeToFileTime(&systime,filetime))
  return false;

 __int64 tmp=filetime->dwHighDateTime;

 tmp*=0x100000000;
 tmp+=filetime->dwLowDateTime;
 tmp+=t.fraction/100;

 filetime->dwHighDateTime=DWORD(tmp/0x100000000);
 filetime->dwLowDateTime =DWORD(tmp-__int64(filetime->dwHighDateTime*0x100000000));

 return true;
}//dbtime2_to_filetime

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
