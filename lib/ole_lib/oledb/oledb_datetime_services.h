////////////////////////////////////////////////////////////////////////////////
//OLEDB Library. Datetime services
//                                                 Kovalenko Dmitry. 05.05.2008
#ifndef _oledb_datetime_services_H_
#define _oledb_datetime_services_H_

////////////////////////////////////////////////////////////////////////////////
#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma hdrstop
#endif

////////////////////////////////////////////////////////////////////////////////

#include <ole_lib/oledb/oledb_data_types.h>
#include <structure/t_common.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class charT>
class basic_dbdatetime_parser;

////////////////////////////////////////////////////////////////////////////////
//datetime comparasion

int compare_dbstamp(const DBTIMESTAMP& ts1,const DBTIMESTAMP& ts2);

int compare_dbdate(const DBDATE& d1,const DBDATE& d2);

int compare_dbtime(const t_oledb_value__DBTIME& t1,const t_oledb_value__DBTIME& t2);

int compare_dbtime2(const t_oledb_value__DBTIME2& t1,const t_oledb_value__DBTIME2& t2);

////////////////////////////////////////////////////////////////////////////////
//Date conversion utils

enum dbstamp_to_str_mode
{
 dbstamp_to_str_mode_smart          =0x00,
 dbstamp_to_str_mode_with_time      =0x01,
 dbstamp_to_str_mode_with_fraction  =0x03,
};//enum dbstamp_to_str_mode

bool dbdate_to_date (const DBDATE& dbdate,DATE& date);

bool dbtime_to_date (const DBTIME& dbtime,DATE& date);

bool dbtime2_to_date(const t_oledb_value__DBTIME2& dbtime2,
                     t_oledb_value__DATE*          date);

bool dbstamp_to_date(const DBTIMESTAMP& dbstamp,DATE& date);

void dbdate_to_dbstamp(const DBDATE& dbdate,DBTIMESTAMP* dbstamp);

////////////////////////////////////////////////////////////////////////////////

std::string  dbdate_to_str  (const t_oledb_value__DBDATE& dbdate);

std::wstring dbdate_to_wstr (const t_oledb_value__DBDATE& dbdate);

////////////////////////////////////////////////////////////////////////////////

std::string  dbtime_to_str  (const t_oledb_value__DBTIME& dbtime);

std::wstring dbtime_to_wstr (const t_oledb_value__DBTIME& dbtime);

////////////////////////////////////////////////////////////////////////////////

std::string  dbtime2_to_str (const t_oledb_value__DBTIME2& dbtime2);

std::wstring dbtime2_to_wstr(const t_oledb_value__DBTIME2& dbtime2);

////////////////////////////////////////////////////////////////////////////////

std::string dbstamp_to_str(const t_oledb_value__DBTIMESTAMP&  dbstamp,
                           dbstamp_to_str_mode mode=dbstamp_to_str_mode_smart);

std::wstring dbstamp_to_wstr(const t_oledb_value__DBTIMESTAMP&  dbstamp,
                             dbstamp_to_str_mode mode=dbstamp_to_str_mode_smart);

////////////////////////////////////////////////////////////////////////////////

template<class charT>
bool str_to_dbdate(t_oledb_value__DBDATE* dbdate,const charT* str,size_t n=-1);

template<class charT>
bool str_to_dbtime(t_oledb_value__DBTIME* dbtime,const charT* str,size_t n=-1);

template<class charT>
bool str_to_dbtime2(t_oledb_value__DBTIME2* dbtime2,const charT* str,size_t n=-1);

template<class charT>
bool str_to_dbtimestamp(t_oledb_value__DBTIMESTAMP* dbstamp,const charT* str,size_t n=-1);

template<class charT>
bool str_to_date(t_oledb_value__DATE* date,const charT* str,size_t n=-1);

template<class charT>
bool str_to_filetime(t_oledb_value__FILETIME* filetime,const charT* str,size_t n=-1);

//------------------------------------------------------------------------
bool date_to_dbdate (const DATE& date,t_oledb_value__DBDATE& dbdate);

bool date_to_dbtime (const DATE& date,t_oledb_value__DBTIME& dbtime);

bool date_to_dbtime2(const DATE& date,t_oledb_value__DBTIME2* dbtime2);

bool date_to_dbstamp(const DATE& date,t_oledb_value__DBTIMESTAMP* dbstamp);

//------------------------------------------------------------------------
bool systime_to_dbstamp (const SYSTEMTIME& systime,DBTIMESTAMP* dbstamp);

//------------------------------------------------------------------------
bool dbdate_to_systime  (const t_oledb_value__DBDATE& dbdate,SYSTEMTIME* systime);

bool dbtime_to_systime  (const t_oledb_value__DBTIME& dbtime,SYSTEMTIME* systime);

bool dbtime2_to_systime (const t_oledb_value__DBTIME2& dbtime2,SYSTEMTIME* systime);

bool dbstamp_to_systime (const t_oledb_value__DBTIMESTAMP& dbstamp,SYSTEMTIME* systime);

//------------------------------------------------------------------------
bool filetime_to_dbstamp(const FILETIME& filetime,DBTIMESTAMP* ts);

bool dbstamp_to_filetime(const DBTIMESTAMP& ts,FILETIME* filetime);

//------------------------------------------------------------------------
bool filetime_to_dbdate(const FILETIME& filetime,DBDATE* dbdate);

bool dbdate_to_filetime(const DBDATE& dbdate,FILETIME* filetime);

//------------------------------------------------------------------------
bool filetime_to_dbtime2(const t_oledb_value__FILETIME& filetime,
                         t_oledb_value__DBTIME2*        t);

bool dbtime2_to_filetime(const t_oledb_value__DBTIME2&  t,
                         t_oledb_value__FILETIME*       filetime);

////////////////////////////////////////////////////////////////////////////////
//class TDBDateTimeParser_Base

class TDBDateTimeParser_Base
{
 public: //typedefs ------------------------------------------------------
  enum expect_datetime_type
  {
   expect_timestamp,
   expect_sql_date,
   expect_sql_time
  };

  enum result_type
  {
   result__ok             =0,
   result__cant_convert   =1,
   result__fail           =2,
  };//enum result_type

 public: //---------------------------------------------------------------
  static result_type ConvertTwoDigitYear(LONG  CurrentYear,
                                         LONG  TwoDigitYear,
                                         LONG* pResultYear);

  static bool IsValidDate(LONG Year,
                          LONG Month,
                          LONG Day);

 private:
  static const USHORT g_DaysPerMonthOfNormalYears[];
};//class TDBDateTimeParser_Base

////////////////////////////////////////////////////////////////////////////////
//class TDBDateTimeParser_Traits

template<class charT>
class TDBDateTimeParser_Traits
{
 public: //typedefs ------------------------------------------------------
  typedef charT                            char_type;
};//class TDBDateTimeParser_Traits

////////////////////////////////////////////////////////////////////////////////
//class TDBDateTimeParser_Traits<char>

template<>
class TDBDateTimeParser_Traits<char>
{
 private:
  typedef TDBDateTimeParser_Traits<char>                 self_type;

 public: //typedefs ------------------------------------------------------
  typedef char                             char_type;

 public:
  static char_type ch_point()        {return '.';}
  static char_type ch_minus()        {return '-';}
  static char_type ch_double_point() {return ':';}

 public:
  static bool is_digit(char_type const c)
   {return c>='0' && c<='9';}

  static bool is_space(char_type const c)
   {return c==' ' || c=='\t';}

  static unsigned char to_digit(char_type const c)
  {
   assert(self_type::is_digit(c));

   return (unsigned char)(c-'0');
  }
};//class TDBDateTimeParser_Traits<char>

////////////////////////////////////////////////////////////////////////////////
//class TDBDateTimeParser_Traits<wchar_t>

template<>
class TDBDateTimeParser_Traits<wchar_t>
{
 private:
  typedef TDBDateTimeParser_Traits<wchar_t>              self_type;

 public: //typedefs ------------------------------------------------------
  typedef wchar_t                           char_type;

 public:
  static char_type ch_point()        {return L'.';}
  static char_type ch_minus()        {return L'-';}
  static char_type ch_double_point() {return L':';}

 public:
  static bool is_digit(char_type const c)
   {return c>=L'0' && c<=L'9';}

  static bool is_space(char_type c)
   {return c==L' ' || c==L'\t';}

  static unsigned char to_digit(char_type const c)
  {
   assert(self_type::is_digit(c));

   return (unsigned char)(c-L'0');
  }
};//class TDBDateTimeParser_Traits<wchar_t>

////////////////////////////////////////////////////////////////////////////////
//class basic_dbdatetime_parser

template<class charT>
class basic_dbdatetime_parser:public TDBDateTimeParser_Base
{
 private:
  typedef basic_dbdatetime_parser<charT>               self_type;
  typedef TDBDateTimeParser_Base                       inherited;

 public: //typedefs ------------------------------------------------------
  typedef charT                                        char_type;
  typedef const char_type*                             char_pointer;

  //Solution of problem with BCB5
  typedef typename inherited::result_type              result_type;
  typedef typename inherited::expect_datetime_type     expect_datetime_type;

  typedef TDBDateTimeParser_Traits<char_type>          traits_type;

 public: //---------------------------------------------------------------
  static result_type Process(char_pointer          first,
                             char_pointer          last,
                             expect_datetime_type  expect_kind,
                             LONG*                 pYear,
                             USHORT*               pMonth,
                             USHORT*               pDay,
                             USHORT*               pHour,
                             USHORT*               pMinute,
                             USHORT*               pSecond,
                             ULONG*                pNanoFraction);

 private:
  struct tag_sep_rule
  {
   bool          can_terminate;
   char_pointer  chars;
  };//struct tag_sep_rule

 private:
  static bool process_digit(char_pointer first,
                            char_pointer last,
                            LONG*        result,
                            LONG         min_value,
                            LONG         max_value);

  static bool process_nano_fraction(char_pointer first,
                                    char_pointer last,
                                    LONG*        result);

  static char_pointer skeep_space(char_pointer first,
                                  char_pointer last);
};//class basic_dbdatetime_parser

////////////////////////////////////////////////////////////////////////////////
//typedefs

typedef basic_dbdatetime_parser<char>                  TDBDateTimeParser;
typedef basic_dbdatetime_parser<wchar_t>               TDBDateTimeParserW;

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/oledb/oledb_datetime_services.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
