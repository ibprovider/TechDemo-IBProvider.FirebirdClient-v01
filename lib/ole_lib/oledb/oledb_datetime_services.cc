////////////////////////////////////////////////////////////////////////////////
#ifndef _oledb_datetime_services_CC_
#define _oledb_datetime_services_CC_

#include <ole_lib/oledb/oledb_common.h>
#include <structure/t_first_last.h>

#include <array>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class basic_dbdatetime_parser

/*************************************************************************
 *
 * Functional description [for Firebird string_to_datetime]
 *      Convert an arbitrary string to a date and/or time.
 *
 *      String must be formed using ASCII characters only.
 *      Conversion routine can handle the following input formats
 *      "now"           current date & time
 *      "today"         Today's date       0:0:0.0 time
 *      "tomorrow"      Tomorrow's date    0:0:0.0 time
 *      "yesterday"     Yesterday's date   0:0:0.0 time
 *      YYYY-MM-DD [HH:[Min:[SS.[Thou]]]]]
 *      MM:DD[:YY [HH:[Min:[SS.[Thou]]]]]
 *      DD.MM[:YY [HH:[Min:[SS.[Thou]]]]]
 *      Where:
 *        DD = 1  .. 31    (Day of month)
 *        YY = 00 .. 99    2-digit years are converted to the nearest year
 *                         in a 50 year range.  Eg: if this is 1996
 *                              96 ==> 1996
 *                              97 ==> 1997
 *                              ...
 *                              00 ==> 2000
 *                              01 ==> 2001
 *                              ...
 *                              44 ==> 2044
 *                              45 ==> 2045
 *                              46 ==> 1946
 *                              47 ==> 1947
 *                              ...
 *                              95 ==> 1995
 *                         If the current year is 1997, then 46 is converted
 *                         to 2046 (etc).
 *           = 100.. 5200  (Year)
 *        MM = 1  .. 12    (Month of year)
 *           = "JANUARY"... (etc)
 *        HH = 0  .. 23    (Hour of day)
 *       Min = 0  .. 59    (Minute of hour)
 *        SS = 0  .. 59    (Second of minute - LEAP second not supported)
 *      Thou = 0  .. 9999  (Fraction of second)
 *      HH, Min, SS, Thou default to 0 if missing.
 *      YY defaults to current year if missing.
 *      Note: ANY punctuation can be used instead of : (eg: / - etc)
 *            Using . (period) in either of the first two separation
 *            points will cause the date to be parsed in European DMY
 *            format.
 *            Arbitrary whitespace (space or TAB) can occur between
 *            components.
 *
 ************************************************************************/

template<class charT>
typename basic_dbdatetime_parser<charT>::result_type
 basic_dbdatetime_parser<charT>::Process(char_pointer               first,
                                         char_pointer         const last,
                                         expect_datetime_type const expect_kind,
                                         LONG*                const pYear,
                                         USHORT*              const pMonth,
                                         USHORT*              const pDay,
                                         USHORT*              const pHour,
                                         USHORT*              const pMinute,
                                         USHORT*              const pSecond,
                                         ULONG*               const pNanoFraction)
{
 assert(first<=last);

 //-------------
 typedef structure::t_first_last<char_pointer>   component_data_type;
 typedef char_type                               separator_data_type;

 //-------------
 const char_type c_str__point_minus[]=
  {
   traits_type::ch_point(),
   traits_type::ch_minus(),
   0
  };

 //-------------
 const char_type c_str__double_point[]=
  {
   traits_type::ch_double_point(),
   0
  };

 //-------------
 const char_type c_str__point[]=
  {
   traits_type::ch_point(),
   0
  };

 //-------------
 const tag_sep_rule sep_rules[]=
 {
  {false ,c_str__point_minus   },
  {false ,c_str__point_minus   },
  {false ,NULL },
  {false ,c_str__double_point  },
  {false ,c_str__double_point  },
  {true  ,c_str__point         },
 };//sep_rules

 //-------------
 std::array<component_data_type,7> components;
 std::array<separator_data_type,6> separators={0,0,0,0,0,0};

 const size_t start_component=((expect_kind==expect_sql_time)?3:0);

 size_t component_count=0;

 for(size_t i_component=start_component;/*i_component!=_DIM_(components)*/;++i_component)
 {
  assert(i_component<_DIM_(components));
  assert(i_component<=_DIM_(sep_rules));

  first=self_type::skeep_space(first,last);

  if(first==last)
   break; //exit from component's scaner

  if(traits_type::is_digit(*first))
  {
   components[i_component].first=first;

   ++first;

   for(;first!=last;++first)
   {
    if(!traits_type::is_digit(*first))
     break;
   }//for

   components[i_component].last=first;
  }
  else
  {
   //wrong component
   break;
  }//else

  ++component_count;

  first=self_type::skeep_space(first,last);

  if(first==last)
   break; //exit from component's scaner

  if(i_component==_DIM_(sep_rules))
   break; //last component was processed

  assert(i_component<_DIM_(sep_rules));

  if(sep_rules[i_component].chars!=nullptr)
  {
   const auto* pch=sep_rules[i_component].chars;

   for(;;++pch)
   {
    if((*pch)==0)
     break; //separator not found

    if((*first)!=(*pch))
     continue;

    separators[i_component]=*first;

    ++first;

    break;
   }//for pch

   if((*pch)==0)
   {
    //exit from component's scaner - valid separator not found.
    break;
   }//if
  }//if sep_rules[i_component].chars!=nullptr
 }//for i_component

 assert_s(result__cant_convert>0);

 if(component_count==0)
 {
  //no components - this is conversion error.

  return result__cant_convert;
 }//if

 assert_hint(component_count>0);

 //verification of terminate separator
 if((start_component+component_count)==_DIM_(components))
 {
  //all components
 }
 else
 {
  assert((start_component+component_count-1)<_DIM_(components));
  assert((start_component+component_count-1)<_DIM_(separators));

  if(separators[start_component+component_count-1]!=0)
  {
   assert((start_component+component_count-1)<_DIM_(sep_rules));

   if(!sep_rules[start_component+component_count-1].can_terminate)
    return result__cant_convert;
  }//if
 }//else

 //Scan string's tail
 for(;first!=last;++first)
 {
  if(traits_type::is_space(*first))
   continue;

  //
  // [2021-02-18] WTF?
  //
  // if((*first)==0)
  //  continue;

  return result__cant_convert;
 }//for first

 //----------- verification of component_count
 switch(expect_kind)
 {
  case expect_timestamp:
  {
   if(component_count<3)  //minimum: year, month, day
    return result__cant_convert;

   if(component_count==4) //single time digit
    return result__cant_convert;

   break;
  }//expect_timestamp

  case expect_sql_date:
  {
   if(component_count!=3)  //only: year, month, day
    return result__cant_convert;

   break;
  }//expect_sql_date

  case expect_sql_time:
  {
   if(component_count<2) //minimum: hour, minute
    return result__cant_convert;

   break;
  }//expect_sql_time

  default:
  {
   assert(false);
  }
 }//switch

 //-----------
 LONG Year  =0;
 LONG Month =0;
 LONG Day   =0;

 //-----------
 if(expect_kind!=expect_sql_time)
 {
  size_t year_position   DEBUG_CODE(=structure::negative_one);
  size_t month_position  DEBUG_CODE(=structure::negative_one);
  size_t day_position    DEBUG_CODE(=structure::negative_one);

  assert(component_count>=3); //year, month, day

  if(separators[0]==traits_type::ch_minus() &&
     separators[1]==traits_type::ch_minus())                //YYYY-MM-DD
  {
   year_position  =0;
   month_position =1;
   day_position   =2;
  }
  else
  if(separators[0]==traits_type::ch_point() &&
     separators[1]==traits_type::ch_point())                //DD.MM.YYYY
  {
   day_position   =0;
   month_position =1;
   year_position  =2;
  }
  else //unknown date format
  {
   return result__cant_convert;
  }

  assert_hint(year_position  <components.size());
  assert_hint(month_position <components.size());
  assert_hint(day_position   <components.size());

  if(!self_type::process_digit(components[year_position].first,
                               components[year_position].last,
                               &Year,
                               0,LONG_MAX))
  {
   return result__cant_convert;
  }

  if((components[year_position].last-components[year_position].first)<=2)
  {
   SYSTEMTIME st;

   ::GetLocalTime(&st);

   if(const result_type r=self_type::ConvertTwoDigitYear(st.wYear,Year,&Year))
    return r;
  }//if - two digit at year component

  if(!self_type::process_digit(components[month_position].first,
                               components[month_position].last,
                               &Month,
                               1,12))
  {
   return result__cant_convert;
  }

  if(!self_type::process_digit(components[day_position].first,
                               components[day_position].last,
                               &Day,
                               1,31))
  {
   return result__cant_convert;
  }

  if(!self_type::IsValidDate(Year,Month,Day))
  {
   return result__cant_convert;
  }
 }//if !=expect_sql_time

 //-----------
 LONG Hour         =0;
 LONG Minute       =0;
 LONG Second       =0;
 LONG NanoFraction =0;

 if((expect_kind==expect_sql_time) ||
    (expect_kind==expect_timestamp && component_count>3))
 {
  if(!self_type::process_digit(components[3].first,
                               components[3].last,
                               &Hour,
                               0,23))
  {
   return result__cant_convert;
  }

  if(!self_type::process_digit(components[4].first,
                               components[4].last,
                               &Minute,
                               0,59))
  {
   return result__cant_convert;
  }
 }//if sql_time/timestamp

 if(expect_kind!=expect_sql_date)
 {
  //optional: second
  if(components[5].first!=components[5].last &&
     !self_type::process_digit(components[5].first,
                               components[5].last,
                               &Second,
                               0,59))
  {
   return result__cant_convert;
  }

  //optional: fraction
  if(components[6].first!=components[6].last &&
     !self_type::process_nano_fraction(components[6].first,
                                       components[6].last,
                                       &NanoFraction))
  {
   return result__cant_convert;
  }
 }//if !=expect_sql_date

 //install result --------------------------------------------------------

 if(expect_kind!=expect_sql_time)
 {
  assert(pYear);
  assert(pMonth);
  assert(pDay);

  structure::static_numeric_cast(pYear   ,Year);
  structure::static_numeric_cast(pMonth  ,Month);
  structure::static_numeric_cast(pDay    ,Day);
 }//if !=expect_sql_time

 //----------
 if(expect_kind!=expect_sql_date)
 {
  assert(pHour);
  assert(pMinute);
  assert(pSecond);

  structure::static_numeric_cast(pHour         ,Hour);
  structure::static_numeric_cast(pMinute       ,Minute);
  structure::static_numeric_cast(pSecond       ,Second);

  if(pNanoFraction)
  {
   structure::static_numeric_cast(pNanoFraction,NanoFraction);
  }
 }//if !=expect_sql_date

 return result__ok;
}//Process

//------------------------------------------------------------------------
template<class charT>
bool basic_dbdatetime_parser<charT>::process_digit(char_pointer first,
                                                   char_pointer last,
                                                   LONG*  const result,
                                                   LONG   const min_value,
                                                   LONG   const max_value)
{
 assert(first<=last);
 assert(result);

 *result=0;

 if(first==last)
  return false;

 LONG x=0;

 for(;first!=last;++first)
 {
  assert(traits_type::is_digit(*first));

  if(x>(structure::get_numeric_limits(x).max_value()/10))
   return false;

  x=x*10;

  if(x>(structure::get_numeric_limits(x).max_value()-traits_type::to_digit(*first)))
   return false;

  x=x+traits_type::to_digit(*first);
 }//for

 if(x<min_value)
  return false;

 if(x>max_value)
  return false;

 (*result)=x;

 return true;
}//process_digit

//------------------------------------------------------------------------
template<class charT>
bool basic_dbdatetime_parser<charT>::process_nano_fraction(char_pointer first,
                                                           char_pointer last,
                                                           LONG* const  result)
{
 assert(first<=last);
 assert(result);

 if(first==last)
  return false;

 LONG x=0;
 UINT n=0;

 for(;first!=last && n!=9;++first,++n)
 {
  assert(traits_type::is_digit(*first));

  x=x*10+traits_type::to_digit(*first);
 }

 for(;n!=9;++n)
 {
  x=x*10;
 }

 (*result)=x;

 return true;
}//process_nano_fraction

//------------------------------------------------------------------------
template<class charT>
typename basic_dbdatetime_parser<charT>::char_pointer
 basic_dbdatetime_parser<charT>::skeep_space(char_pointer first,char_pointer last)
{
 assert(first<=last);

 for(;first!=last && traits_type::is_space(*first);++first);

 return first;
}//skeep_space

////////////////////////////////////////////////////////////////////////////////

template<class charT>
bool str_to_dbdate(t_oledb_value__DBDATE* dbdate,const charT* str,size_t n)
{
 assert(dbdate);

 if(str==NULL)
  return false;

 if(n==structure::get_numeric_limits(n).max_value())
  n=std::char_traits<charT>::length(str);

 if(n==0)
  return false;

 LONG    Year;
 USHORT  Month;
 USHORT  Day;
 USHORT  Hour;
 USHORT  Minute;
 USHORT  Second;
 ULONG   NanoFraction;

 typedef basic_dbdatetime_parser<charT> parser_type;

 if(parser_type::Process(str,
                         str+n,
                         parser_type::expect_timestamp,
                         &Year,
                         &Month,
                         &Day,
                         &Hour,
                         &Minute,
                         &Second,
                         &NanoFraction)!=parser_type::result__ok)
 {
  return false;
 }

 if(!structure::can_numeric_cast(&dbdate->year,Year))
  return false;

 assert(structure::can_numeric_cast(&dbdate->month,Month));
 assert(structure::can_numeric_cast(&dbdate->day,Day));

 structure::static_numeric_cast(&dbdate->year,Year);

 dbdate->month=Month;
 dbdate->day  =Day;

 return true;
}//str_to_dbdate

////////////////////////////////////////////////////////////////////////////////

template<class charT>
bool str_to_dbtime(t_oledb_value__DBTIME* const dbtime,const charT* str,size_t n)
{
 assert(dbtime);

 if(str==NULL)
  return false;

 if(n==structure::get_numeric_limits(n).max_value())
  n=std::char_traits<charT>::length(str);

 if(n==0)
  return false;

 USHORT  Hour;
 USHORT  Minute;
 USHORT  Second;

 typedef basic_dbdatetime_parser<charT> parser_type;

 if(parser_type::Process(str,
                         str+n,
                         parser_type::expect_sql_time,
                         NULL,
                         NULL,
                         NULL,
                         &Hour,
                         &Minute,
                         &Second,
                         NULL)!=parser_type::result__ok)
 {
  LONG    Year;
  USHORT  Month;
  USHORT  Day;

  if(parser_type::Process(str,
                          str+n,
                          parser_type::expect_timestamp,
                          &Year,
                          &Month,
                          &Day,
                          &Hour,
                          &Minute,
                          &Second,
                          NULL)!=parser_type::result__ok)
  {
   return false;
  }
 }//if

 dbtime->hour   =Hour;
 dbtime->minute =Minute;
 dbtime->second =Second;

 return true;
}//str_to_dbtime

////////////////////////////////////////////////////////////////////////////////

template<class charT>
bool str_to_dbtime2(t_oledb_value__DBTIME2* const dbtime2,const charT* str,size_t n)
{
 assert(dbtime2);

 if(str==NULL)
  return false;

 if(n==structure::get_numeric_limits(n).max_value())
  n=std::char_traits<charT>::length(str);

 if(n==0)
  return false;

 USHORT  Hour;
 USHORT  Minute;
 USHORT  Second;
 ULONG   Fraction;

 typedef basic_dbdatetime_parser<charT> parser_type;

 if(parser_type::Process(str,
                         str+n,
                         parser_type::expect_sql_time,
                         NULL,
                         NULL,
                         NULL,
                         &Hour,
                         &Minute,
                         &Second,
                         &Fraction)!=parser_type::result__ok)
 {
  LONG    Year;
  USHORT  Month;
  USHORT  Day;

  if(parser_type::Process(str,
                          str+n,
                          parser_type::expect_timestamp,
                          &Year,
                          &Month,
                          &Day,
                          &Hour,
                          &Minute,
                          &Second,
                          &Fraction)!=parser_type::result__ok)
  {
   return false;
  }
 }//if

 dbtime2->hour     =Hour;
 dbtime2->minute   =Minute;
 dbtime2->second   =Second;
 dbtime2->fraction =Fraction;

 return true;
}//str_to_dbtime2

////////////////////////////////////////////////////////////////////////////////

template<class charT>
bool str_to_dbtimestamp(t_oledb_value__DBTIMESTAMP* const dbstamp,const charT* str,size_t n)
{
 assert(dbstamp);

 if(str==NULL)
  return false;

 if(n==structure::get_numeric_limits(n).max_value())
  n=std::char_traits<charT>::length(str);

 if(n==0)
  return false;

 LONG    Year;
 USHORT  Month;
 USHORT  Day;
 USHORT  Hour;
 USHORT  Minute;
 USHORT  Second;
 ULONG   NanoFraction;

 typedef basic_dbdatetime_parser<charT> parser_type;

 if(parser_type::Process(str,
                         str+n,
                         parser_type::expect_timestamp,
                         &Year,
                         &Month,
                         &Day,
                         &Hour,
                         &Minute,
                         &Second,
                         &NanoFraction)!=parser_type::result__ok)
 {
  if(parser_type::Process(str,
                          str+n,
                          parser_type::expect_sql_time,
                          NULL,
                          NULL,
                          NULL,
                          &Hour,
                          &Minute,
                          &Second,
                          &NanoFraction)!=parser_type::result__ok)
  {
   return false;
  }//if

  Year  =__zero_dbdate__.year;
  Month =__zero_dbdate__.month;
  Day   =__zero_dbdate__.day;
 }//if

 if(!structure::can_numeric_cast(&dbstamp->year,Year))
  return false;

 assert(structure::can_numeric_cast(&dbstamp->month,Month));
 assert(structure::can_numeric_cast(&dbstamp->day,Day));

 structure::static_numeric_cast(&dbstamp->year,Year);

 dbstamp->month    =Month;
 dbstamp->day      =Day;
 dbstamp->hour     =Hour;
 dbstamp->minute   =Minute;
 dbstamp->second   =Second;
 dbstamp->fraction =NanoFraction;

 return true;
}//str_to_dbtimestamp

////////////////////////////////////////////////////////////////////////////////

template<class charT>
bool str_to_date(t_oledb_value__DATE* const date,const charT* str,size_t n)
{
 assert(date);

 if(str==NULL)
  return false;

 if(n==structure::get_numeric_limits(n).max_value())
  n=std::char_traits<charT>::length(str);

 if(n==0)
  return false;

 LONG    Year;
 USHORT  Month;
 USHORT  Day;
 USHORT  Hour;
 USHORT  Minute;
 USHORT  Second;
 ULONG   NanoFraction;

 typedef basic_dbdatetime_parser<charT> parser_type;

 if(parser_type::Process(str,
                         str+n,
                         parser_type::expect_timestamp,
                         &Year,
                         &Month,
                         &Day,
                         &Hour,
                         &Minute,
                         &Second,
                         &NanoFraction)!=parser_type::result__ok)
 {
  if(parser_type::Process(str,
                          str+n,
                          parser_type::expect_sql_time,
                          NULL,
                          NULL,
                          NULL,
                          &Hour,
                          &Minute,
                          &Second,
                          &NanoFraction)!=parser_type::result__ok)
  {
   return false;
  }

  //! \todo
  //!  This code do not correlated with other convertors:
  //!   - DBTIME->DATE
  //!   - DBTIME2->DATE
  //! In these convertors we use __zero_dbdate__

  Year  =__zero_dbdate__.year;
  Month =__zero_dbdate__.month;
  Day   =__zero_dbdate__.day;
 }//if

 SYSTEMTIME systime;

 if(!structure::can_numeric_cast(&systime.wYear,Year))
  return false;

 assert(structure::can_numeric_cast(&systime.wMonth        ,Month));
 assert(structure::can_numeric_cast(&systime.wDay          ,Day));
 assert(structure::can_numeric_cast(&systime.wHour         ,Hour));
 assert(structure::can_numeric_cast(&systime.wMinute       ,Minute));
 assert(structure::can_numeric_cast(&systime.wSecond       ,Second));
 assert(structure::can_numeric_cast(&systime.wMilliseconds ,NanoFraction/1000000));

 structure::static_numeric_cast(&systime.wYear,Year);

 systime.wMonth        =Month;
 systime.wDayOfWeek    =0;
 systime.wDay          =Day;
 systime.wHour         =Hour;
 systime.wMinute       =Minute;
 systime.wSecond       =Second;

 structure::static_numeric_cast(&systime.wMilliseconds,
                                NanoFraction/1000000);

 t_oledb_value__DATE tmp;

 if(!::SystemTimeToVariantTime(&systime,&tmp))
  return false;

 (*date)=tmp;

 return true;
}//str_to_date

////////////////////////////////////////////////////////////////////////////////

template<class charT>
bool str_to_filetime(t_oledb_value__FILETIME* const filetime,const charT* str,size_t n)
{
 t_oledb_value__DBTIMESTAMP dbstamp;

 if(!str_to_dbtimestamp(&dbstamp,str,n))
  return false;

 return dbstamp_to_filetime(dbstamp,filetime);
}//str_to_filetime

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
