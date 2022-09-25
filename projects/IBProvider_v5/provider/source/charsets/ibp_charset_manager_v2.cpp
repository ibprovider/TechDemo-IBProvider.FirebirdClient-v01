////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_charset_manager_v2.cpp
//! \brief   Реализация интерфейса t_db_charsets_manager_v2
//! \author  Kovalenko Dmitry
//! \date    05.10.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/ibp_charset_manager_v2__data.h"

#include "source/charsets/cs_code/icu/v003/ibp_cs_icu_v003__provider.h"
#include "source/charsets/cs_code/icu/v052/ibp_cs_icu_v052__provider.h"

#include "source/os/ibp_os__dll_version_info.h"

#include "source/error_services/ibp_error_utils.h"

#include "source/ibp_global_objects_data__dlls.h"

#include <win32lib/win32lib.h>

#include <structure/utilities/string/trim.h>
#include <structure/utilities/string/string_compare.h>
#include <structure/utilities/to_underlying.h>
#include <structure/t_str_version.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//упорядоченной перечисление описания поддерживаемых кодовых страниц

//по имени
static const t_ibp_charset_manager_v2::tag_own_cs* const
 g_ibp_own_cp_info_by_name[]=
{
 &g_ibp_own_cp_info_ASCII,
 &g_ibp_own_cp_info_BASE64,
 &g_ibp_own_cp_info_BIG_5,
 &g_ibp_own_cp_info_CP943C,
 &g_ibp_own_cp_info_CYRL,
 &g_ibp_own_cp_info_DOS437,
 &g_ibp_own_cp_info_DOS737,
 &g_ibp_own_cp_info_DOS775,
 &g_ibp_own_cp_info_DOS850,
 &g_ibp_own_cp_info_DOS852,
 &g_ibp_own_cp_info_DOS857,
 &g_ibp_own_cp_info_DOS858,
 &g_ibp_own_cp_info_DOS860,
 &g_ibp_own_cp_info_DOS861,
 &g_ibp_own_cp_info_DOS862,
 &g_ibp_own_cp_info_DOS863,
 &g_ibp_own_cp_info_DOS864,
 &g_ibp_own_cp_info_DOS865,
 &g_ibp_own_cp_info_DOS866,
 &g_ibp_own_cp_info_DOS869,
 &g_ibp_own_cp_info_EUCJ_0208,
 &g_ibp_own_cp_info_GB18030,
 &g_ibp_own_cp_info_GBK,
 &g_ibp_own_cp_info_GB_2312,
 &g_ibp_own_cp_info_ISO8859_1,
 &g_ibp_own_cp_info_ISO8859_13,
 &g_ibp_own_cp_info_ISO8859_15,
 &g_ibp_own_cp_info_ISO8859_2,
 &g_ibp_own_cp_info_ISO8859_3,
 &g_ibp_own_cp_info_ISO8859_4,
 &g_ibp_own_cp_info_ISO8859_5,
 &g_ibp_own_cp_info_ISO8859_6,
 &g_ibp_own_cp_info_ISO8859_7,
 &g_ibp_own_cp_info_ISO8859_8,
 &g_ibp_own_cp_info_ISO8859_9,
 &g_ibp_own_cp_info_KOI8R,
 &g_ibp_own_cp_info_KOI8U,
 &g_ibp_own_cp_info_KSC_5601,
 &g_ibp_own_cp_info_NEXT,
 &g_ibp_own_cp_info_NONE,
 &g_ibp_own_cp_info_OCTETS,
 &g_ibp_own_cp_info_SJIS_0208,
 &g_ibp_own_cp_info_TIS620,
 &g_ibp_own_cp_info_UNICODE_FSS,
 &g_ibp_own_cp_info_UTF8,
 &g_ibp_own_cp_info_WIN1250,
 &g_ibp_own_cp_info_WIN1251,
 &g_ibp_own_cp_info_WIN1252,
 &g_ibp_own_cp_info_WIN1253,
 &g_ibp_own_cp_info_WIN1254,
 &g_ibp_own_cp_info_WIN1255,
 &g_ibp_own_cp_info_WIN1256,
 &g_ibp_own_cp_info_WIN1257,
 &g_ibp_own_cp_info_WIN1258,
};//g_ibp_own_cp_info_by_name

////////////////////////////////////////////////////////////////////////////////
//Проверка упорядоченности таблиц описания поддерживаемых кодовых страниц

#ifndef NDEBUG

static void __ibp_check_own_cs_info_order__()
{
 for(size_t i=0;i!=_DIM_(g_ibp_own_cp_info_by_name);++i)
 {
  const t_ibp_charset_manager_v2::tag_own_cs*
   const cs1=g_ibp_own_cp_info_by_name[i];

  assert(cs1);
  assert(cs1->name);

  if(i==0)
   continue;

  const t_ibp_charset_manager_v2::tag_own_cs*
   const cs0=g_ibp_own_cp_info_by_name[i-1];

  assert(cs0);
  assert(cs0->name);

  assert_msg(structure::string_compare(cs0->name,cs1->name)<0,"i="<<i);
 }//for
}//__ibp_check_own_cs_info_order__

STARTUP_CODE__DEBUG(__ibp_check_own_cs_info_order__)

#endif //NDEBUG - проверка упорядоченности таблиц

////////////////////////////////////////////////////////////////////////////////
//перечисление кодовых страниц, которые можно использовать для подключения

//по имени
static const t_ibp_charset_manager_v2::tag_own_cs* const
 g_ibp_cn_cp_info_by_name[]=
{
 &g_ibp_own_cp_info_ASCII,
 &g_ibp_own_cp_info_BIG_5,
 &g_ibp_own_cp_info_CP943C,
 &g_ibp_own_cp_info_CYRL,
 &g_ibp_own_cp_info_DOS437,
 &g_ibp_own_cp_info_DOS737,
 &g_ibp_own_cp_info_DOS775,
 &g_ibp_own_cp_info_DOS850,
 &g_ibp_own_cp_info_DOS852,
 &g_ibp_own_cp_info_DOS857,
 &g_ibp_own_cp_info_DOS858,
 &g_ibp_own_cp_info_DOS860,
 &g_ibp_own_cp_info_DOS861,
 &g_ibp_own_cp_info_DOS862,
 &g_ibp_own_cp_info_DOS863,
 &g_ibp_own_cp_info_DOS864,
 &g_ibp_own_cp_info_DOS865,
 &g_ibp_own_cp_info_DOS866,
 &g_ibp_own_cp_info_DOS869,
 &g_ibp_own_cp_info_EUCJ_0208,
 &g_ibp_own_cp_info_GB18030,
 &g_ibp_own_cp_info_GBK,
 &g_ibp_own_cp_info_GB_2312,
 &g_ibp_own_cp_info_ISO8859_1,
 &g_ibp_own_cp_info_ISO8859_13,
 &g_ibp_own_cp_info_ISO8859_15,
 &g_ibp_own_cp_info_ISO8859_2,
 &g_ibp_own_cp_info_ISO8859_3,
 &g_ibp_own_cp_info_ISO8859_4,
 &g_ibp_own_cp_info_ISO8859_5,
 &g_ibp_own_cp_info_ISO8859_6,
 &g_ibp_own_cp_info_ISO8859_7,
 &g_ibp_own_cp_info_ISO8859_8,
 &g_ibp_own_cp_info_ISO8859_9,
 &g_ibp_own_cp_info_KOI8R,
 &g_ibp_own_cp_info_KOI8U,
 &g_ibp_own_cp_info_KSC_5601,
 &g_ibp_own_cp_info_NEXT,
 &g_ibp_own_cp_info_NONE,
 &g_ibp_own_cp_info_SJIS_0208,
 &g_ibp_own_cp_info_TIS620,
 &g_ibp_own_cp_info_UNICODE_FSS,
 &g_ibp_own_cp_info_UTF8,
 &g_ibp_own_cp_info_WIN1250,
 &g_ibp_own_cp_info_WIN1251,
 &g_ibp_own_cp_info_WIN1252,
 &g_ibp_own_cp_info_WIN1253,
 &g_ibp_own_cp_info_WIN1254,
 &g_ibp_own_cp_info_WIN1255,
 &g_ibp_own_cp_info_WIN1256,
 &g_ibp_own_cp_info_WIN1257,
 &g_ibp_own_cp_info_WIN1258,
};//g_ibp_cn_cp_info_by_name

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Получение количества кодовых страниц, которые можно использовать для подключения
/// </summary>
size_t ibp_get_count_of_connection_charsets()
{
 return _DIM_(g_ibp_cn_cp_info_by_name);
}//ibp_get_count_of_connection_charsets

//------------------------------------------------------------------------
/// <summary>
///  Получение имени кодовой страницы из списка кодировок для подключения
/// </summary>
//! \param[in] index
//!  Порядковый номер кодовой страницы [0..ibp_count_of_connection_charsets]
const t_ibp_char* ibp_get_connection_charset_name(size_t index)
{
 assert(index<_DIM_(g_ibp_cn_cp_info_by_name));
 assert(g_ibp_cn_cp_info_by_name[index]);
 assert(g_ibp_cn_cp_info_by_name[index]->name);

 return g_ibp_cn_cp_info_by_name[index]->name;
}//ibp_get_connection_charset_name

////////////////////////////////////////////////////////////////////////////////

#define CS_ALIASE(ALIASE_NAME,CS)                                 \
 {IBP_T(ALIASE_NAME),&g_ibp_own_cp_info_##CS},

/// <summary>
///  Статическая таблица с описаниями псевдонимов кодовых страниц.
/// <summary>
//!  Отсортированы по именам
static const t_ibp_charset_manager_v2::tag_aliase g_ibp_aliase_cs_by_name[]=
{
 CS_ALIASE("ANSI"                           ,ISO8859_1)
 CS_ALIASE("ASCII"                          ,ASCII)
 CS_ALIASE("ASCII7"                         ,ASCII)

 CS_ALIASE("BASE64"                         ,BASE64)      //IBP

 CS_ALIASE("BIG-5"                          ,BIG_5)       //IBP
 CS_ALIASE("BIG5"                           ,BIG_5)
 CS_ALIASE("BIG_5"                          ,BIG_5)

 CS_ALIASE("CP943C"                         ,CP943C)
 CS_ALIASE("CYRILLIC"                       ,CYRL)
 CS_ALIASE("CYRL"                           ,CYRL)

 CS_ALIASE("DOS-437"                        ,DOS437)
 CS_ALIASE("DOS-737"                        ,DOS737)
 CS_ALIASE("DOS-775"                        ,DOS775)
 CS_ALIASE("DOS-850"                        ,DOS850)
 CS_ALIASE("DOS-852"                        ,DOS852)
 CS_ALIASE("DOS-857"                        ,DOS857)
 CS_ALIASE("DOS-858"                        ,DOS858)
 CS_ALIASE("DOS-860"                        ,DOS860)
 CS_ALIASE("DOS-861"                        ,DOS861)
 CS_ALIASE("DOS-862"                        ,DOS862)
 CS_ALIASE("DOS-863"                        ,DOS863)
 CS_ALIASE("DOS-864"                        ,DOS864)
 CS_ALIASE("DOS-865"                        ,DOS865)
 CS_ALIASE("DOS-866"                        ,DOS866)
 CS_ALIASE("DOS-869"                        ,DOS869)
 CS_ALIASE("DOS-936"                        ,GB_2312)     //IBP
 CS_ALIASE("DOS-949"                        ,KSC_5601)    //IBP
 CS_ALIASE("DOS-950"                        ,BIG_5)       //IBP

 CS_ALIASE("DOS437"                         ,DOS437)
 CS_ALIASE("DOS737"                         ,DOS737)
 CS_ALIASE("DOS775"                         ,DOS775)
 CS_ALIASE("DOS850"                         ,DOS850)
 CS_ALIASE("DOS852"                         ,DOS852)
 CS_ALIASE("DOS857"                         ,DOS857)
 CS_ALIASE("DOS858"                         ,DOS858)
 CS_ALIASE("DOS860"                         ,DOS860)
 CS_ALIASE("DOS861"                         ,DOS861)
 CS_ALIASE("DOS862"                         ,DOS862)
 CS_ALIASE("DOS863"                         ,DOS863)
 CS_ALIASE("DOS864"                         ,DOS864)
 CS_ALIASE("DOS865"                         ,DOS865)
 CS_ALIASE("DOS866"                         ,DOS866)
 CS_ALIASE("DOS869"                         ,DOS869)
 CS_ALIASE("DOS936"                         ,GB_2312)     //IBP
 CS_ALIASE("DOS949"                         ,KSC_5601)    //IBP
 CS_ALIASE("DOS950"                         ,BIG_5)       //IBP

 CS_ALIASE("DOS_437"                        ,DOS437)
 CS_ALIASE("DOS_737"                        ,DOS737)
 CS_ALIASE("DOS_775"                        ,DOS775)
 CS_ALIASE("DOS_850"                        ,DOS850)
 CS_ALIASE("DOS_852"                        ,DOS852)
 CS_ALIASE("DOS_857"                        ,DOS857)
 CS_ALIASE("DOS_858"                        ,DOS858)
 CS_ALIASE("DOS_860"                        ,DOS860)
 CS_ALIASE("DOS_861"                        ,DOS861)
 CS_ALIASE("DOS_862"                        ,DOS862)
 CS_ALIASE("DOS_863"                        ,DOS863)
 CS_ALIASE("DOS_864"                        ,DOS864)
 CS_ALIASE("DOS_865"                        ,DOS865)
 CS_ALIASE("DOS_866"                        ,DOS866)
 CS_ALIASE("DOS_869"                        ,DOS869)
 CS_ALIASE("DOS_936"                        ,GB_2312)
 CS_ALIASE("DOS_949"                        ,KSC_5601)
 CS_ALIASE("DOS_950"                        ,BIG_5)

 CS_ALIASE("EUCJ"                           ,EUCJ_0208)
 CS_ALIASE("EUCJ-0208"                      ,EUCJ_0208)   //IBP
 CS_ALIASE("EUCJ_0208"                      ,EUCJ_0208)

 CS_ALIASE("GB-18030"                       ,GB18030)     //IBP
 CS_ALIASE("GB-2312"                        ,GB_2312)     //IBP

 CS_ALIASE("GB18030"                        ,GB18030)
 CS_ALIASE("GB2312"                         ,GB_2312)

 CS_ALIASE("GBK"                            ,GBK)

 CS_ALIASE("GB_18030"                       ,GB18030)     //IBP
 CS_ALIASE("GB_2312"                        ,GB_2312)

 CS_ALIASE("ISO-8859-1"                     ,ISO8859_1)
 CS_ALIASE("ISO-8859-13"                    ,ISO8859_13)
 CS_ALIASE("ISO-8859-15"                    ,ISO8859_15)
 CS_ALIASE("ISO-8859-2"                     ,ISO8859_2)
 CS_ALIASE("ISO-8859-3"                     ,ISO8859_3)
 CS_ALIASE("ISO-8859-4"                     ,ISO8859_4)
 CS_ALIASE("ISO-8859-5"                     ,ISO8859_5)
 CS_ALIASE("ISO-8859-6"                     ,ISO8859_6)
 CS_ALIASE("ISO-8859-7"                     ,ISO8859_7)
 CS_ALIASE("ISO-8859-8"                     ,ISO8859_8)
 CS_ALIASE("ISO-8859-9"                     ,ISO8859_9)

 CS_ALIASE("ISO8859-1"                      ,ISO8859_1)
 CS_ALIASE("ISO8859-13"                     ,ISO8859_13)
 CS_ALIASE("ISO8859-15"                     ,ISO8859_15)
 CS_ALIASE("ISO8859-2"                      ,ISO8859_2)
 CS_ALIASE("ISO8859-3"                      ,ISO8859_3)
 CS_ALIASE("ISO8859-4"                      ,ISO8859_4)
 CS_ALIASE("ISO8859-5"                      ,ISO8859_5)
 CS_ALIASE("ISO8859-6"                      ,ISO8859_6)
 CS_ALIASE("ISO8859-7"                      ,ISO8859_7)
 CS_ALIASE("ISO8859-8"                      ,ISO8859_8)
 CS_ALIASE("ISO8859-9"                      ,ISO8859_9)

 CS_ALIASE("ISO88591"                       ,ISO8859_1)
 CS_ALIASE("ISO885913"                      ,ISO8859_13)
 CS_ALIASE("ISO885915"                      ,ISO8859_15)
 CS_ALIASE("ISO88592"                       ,ISO8859_2)
 CS_ALIASE("ISO88593"                       ,ISO8859_3)
 CS_ALIASE("ISO88594"                       ,ISO8859_4)
 CS_ALIASE("ISO88595"                       ,ISO8859_5)
 CS_ALIASE("ISO88596"                       ,ISO8859_6)
 CS_ALIASE("ISO88597"                       ,ISO8859_7)
 CS_ALIASE("ISO88598"                       ,ISO8859_8)
 CS_ALIASE("ISO88599"                       ,ISO8859_9)

 CS_ALIASE("ISO8859_1"                      ,ISO8859_1)
 CS_ALIASE("ISO8859_13"                     ,ISO8859_13)
 CS_ALIASE("ISO8859_15"                     ,ISO8859_15)
 CS_ALIASE("ISO8859_2"                      ,ISO8859_2)
 CS_ALIASE("ISO8859_3"                      ,ISO8859_3)
 CS_ALIASE("ISO8859_4"                      ,ISO8859_4)
 CS_ALIASE("ISO8859_5"                      ,ISO8859_5)
 CS_ALIASE("ISO8859_6"                      ,ISO8859_6)
 CS_ALIASE("ISO8859_7"                      ,ISO8859_7)
 CS_ALIASE("ISO8859_8"                      ,ISO8859_8)
 CS_ALIASE("ISO8859_9"                      ,ISO8859_9)

 CS_ALIASE("KOI8-R"                         ,KOI8R)
 CS_ALIASE("KOI8-U"                         ,KOI8U)

 CS_ALIASE("KOI8R"                          ,KOI8R)
 CS_ALIASE("KOI8U"                          ,KOI8U)

 CS_ALIASE("KSC-5601"                       ,KSC_5601)    //IBP
 CS_ALIASE("KSC5601"                        ,KSC_5601)
 CS_ALIASE("KSC_5601"                       ,KSC_5601)

 CS_ALIASE("LATIN1"                         ,ISO8859_1)
 CS_ALIASE("LATIN2"                         ,ISO8859_2)
 CS_ALIASE("LATIN3"                         ,ISO8859_3)
 CS_ALIASE("LATIN4"                         ,ISO8859_4)
 CS_ALIASE("LATIN5"                         ,ISO8859_9)   //<- это именно так (FB)
 CS_ALIASE("LATIN7"                         ,ISO8859_13)  //<- это именно так (FB)

 CS_ALIASE("NEXT"                           ,NEXT)
 CS_ALIASE("NONE"                           ,NONE)

 CS_ALIASE("OCTETS"                         ,OCTETS)

 CS_ALIASE("SJIS"                           ,SJIS_0208)
 CS_ALIASE("SJIS-0208"                      ,SJIS_0208)   //IBP
 CS_ALIASE("SJIS_0208"                      ,SJIS_0208)

 CS_ALIASE("SQL-TEXT"                       ,UNICODE_FSS) //IBP
 CS_ALIASE("SQL_TEXT"                       ,UNICODE_FSS)

 CS_ALIASE("TIS620"                         ,TIS620)

 CS_ALIASE("UNICODE-FSS"                    ,UNICODE_FSS)
 CS_ALIASE("UNICODE_FSS"                    ,UNICODE_FSS)

 CS_ALIASE("USASCII"                        ,ASCII)

 CS_ALIASE("UTF-8"                          ,UTF8)
 CS_ALIASE("UTF-FSS"                        ,UNICODE_FSS)

 CS_ALIASE("UTF8"                           ,UTF8)

 CS_ALIASE("UTF_8"                          ,UTF8)
 CS_ALIASE("UTF_FSS"                        ,UNICODE_FSS)

 CS_ALIASE("WIN-1250"                       ,WIN1250)     //IBP
 CS_ALIASE("WIN-1251"                       ,WIN1251)     //IBP
 CS_ALIASE("WIN-1252"                       ,WIN1252)     //IBP
 CS_ALIASE("WIN-1253"                       ,WIN1253)     //IBP
 CS_ALIASE("WIN-1254"                       ,WIN1254)     //IBP
 CS_ALIASE("WIN-1255"                       ,WIN1255)     //IBP
 CS_ALIASE("WIN-1256"                       ,WIN1256)     //IBP
 CS_ALIASE("WIN-1257"                       ,WIN1257)     //IBP
 CS_ALIASE("WIN-1258"                       ,WIN1258)     //IBP
 CS_ALIASE("WIN-936"                        ,GB_2312)     //IBP
 CS_ALIASE("WIN-949"                        ,KSC_5601)    //IBP
 CS_ALIASE("WIN-950"                        ,BIG_5)       //IBP

 CS_ALIASE("WIN1250"                        ,WIN1250)
 CS_ALIASE("WIN1251"                        ,WIN1251)
 CS_ALIASE("WIN1252"                        ,WIN1252)
 CS_ALIASE("WIN1253"                        ,WIN1253)
 CS_ALIASE("WIN1254"                        ,WIN1254)
 CS_ALIASE("WIN1255"                        ,WIN1255)
 CS_ALIASE("WIN1256"                        ,WIN1256)
 CS_ALIASE("WIN1257"                        ,WIN1257)
 CS_ALIASE("WIN1258"                        ,WIN1258)
 CS_ALIASE("WIN936"                         ,GB_2312)     //IBP
 CS_ALIASE("WIN949"                         ,KSC_5601)    //IBP
 CS_ALIASE("WIN950"                         ,BIG_5)       //IBP

 CS_ALIASE("WINDOWS-1250"                   ,WIN1250)     //IBP
 CS_ALIASE("WINDOWS-1251"                   ,WIN1251)     //IBP
 CS_ALIASE("WINDOWS-1252"                   ,WIN1252)     //IBP
 CS_ALIASE("WINDOWS-1253"                   ,WIN1253)     //IBP
 CS_ALIASE("WINDOWS-1254"                   ,WIN1254)     //IBP
 CS_ALIASE("WINDOWS-1255"                   ,WIN1255)     //IBP
 CS_ALIASE("WINDOWS-1256"                   ,WIN1256)     //IBP
 CS_ALIASE("WINDOWS-1257"                   ,WIN1257)     //IBP
 CS_ALIASE("WINDOWS-1258"                   ,WIN1258)     //IBP
 CS_ALIASE("WINDOWS-936"                    ,GB_2312)     //IBP
 CS_ALIASE("WINDOWS-949"                    ,KSC_5601)    //IBP
 CS_ALIASE("WINDOWS-950"                    ,BIG_5)       //IBP

 CS_ALIASE("WINDOWS1250"                    ,WIN1250)     //IBP
 CS_ALIASE("WINDOWS1251"                    ,WIN1251)     //IBP
 CS_ALIASE("WINDOWS1252"                    ,WIN1252)     //IBP
 CS_ALIASE("WINDOWS1253"                    ,WIN1253)     //IBP
 CS_ALIASE("WINDOWS1254"                    ,WIN1254)     //IBP
 CS_ALIASE("WINDOWS1255"                    ,WIN1255)     //IBP
 CS_ALIASE("WINDOWS1256"                    ,WIN1256)     //IBP
 CS_ALIASE("WINDOWS1257"                    ,WIN1257)     //IBP
 CS_ALIASE("WINDOWS1258"                    ,WIN1258)     //IBP
 CS_ALIASE("WINDOWS936"                     ,GB_2312)     //IBP
 CS_ALIASE("WINDOWS949"                     ,KSC_5601)    //IBP
 CS_ALIASE("WINDOWS950"                     ,BIG_5)       //IBP

 CS_ALIASE("WINDOWS_1250"                   ,WIN1250)     //IBP
 CS_ALIASE("WINDOWS_1251"                   ,WIN1251)     //IBP
 CS_ALIASE("WINDOWS_1252"                   ,WIN1252)     //IBP
 CS_ALIASE("WINDOWS_1253"                   ,WIN1253)     //IBP
 CS_ALIASE("WINDOWS_1254"                   ,WIN1254)     //IBP
 CS_ALIASE("WINDOWS_1255"                   ,WIN1255)     //IBP
 CS_ALIASE("WINDOWS_1256"                   ,WIN1256)     //IBP
 CS_ALIASE("WINDOWS_1257"                   ,WIN1257)     //IBP
 CS_ALIASE("WINDOWS_1258"                   ,WIN1258)     //IBP
 CS_ALIASE("WINDOWS_936"                    ,GB_2312)     //IBP
 CS_ALIASE("WINDOWS_949"                    ,KSC_5601)    //IBP
 CS_ALIASE("WINDOWS_950"                    ,BIG_5)       //IBP

 CS_ALIASE("WIN_1250"                       ,WIN1250)
 CS_ALIASE("WIN_1251"                       ,WIN1251)
 CS_ALIASE("WIN_1252"                       ,WIN1252)
 CS_ALIASE("WIN_1253"                       ,WIN1253)
 CS_ALIASE("WIN_1254"                       ,WIN1254)
 CS_ALIASE("WIN_1255"                       ,WIN1255)
 CS_ALIASE("WIN_1256"                       ,WIN1256)
 CS_ALIASE("WIN_1257"                       ,WIN1257)
 CS_ALIASE("WIN_1258"                       ,WIN1258)
 CS_ALIASE("WIN_936"                        ,GB_2312)
 CS_ALIASE("WIN_949"                        ,KSC_5601)
 CS_ALIASE("WIN_950"                        ,BIG_5)
};//g_ibp_aliase_cs_by_name

#undef CS_ALIASE

////////////////////////////////////////////////////////////////////////////////
//Проверка упорядоченности g_aliase_cs_by_name

#ifndef NDEBUG

static void __check_order_in__g_aliase_cs_by_name()
{
 t_ibp_charset_manager_v2::tag_aliase_less_by_name ln;

 for(size_t i=0;i!=_DIM_(g_ibp_aliase_cs_by_name);++i)
 {
  const t_ibp_charset_manager_v2::tag_aliase& cs1=g_ibp_aliase_cs_by_name[i];

  assert(!cs1.name.empty());
  assert(cs1.own_cs);

  assert(!ln(cs1,cs1));
  assert(!ln(cs1.name,cs1));
  assert(!ln(cs1,cs1.name));

  if(i==0)
   continue;

  const t_ibp_charset_manager_v2::tag_aliase& cs0=g_ibp_aliase_cs_by_name[i-1];

  assert_msg(ln(cs0,cs1),"["<<i<<"]"<<structure::tstr_to_str(cs0.name));
  assert_msg(!ln(cs1,cs0),"i="<<i);

  assert_msg(ln(cs0.name,cs1),"i="<<i);
  assert_msg(!ln(cs1,cs0.name),"i="<<i);

  assert_msg(ln(cs0,cs1.name),"i="<<i);
  assert_msg(!ln(cs1.name,cs0),"i="<<i);
 }//for

 //проверка полноты таблицы псевдонимов ----------------------------------
 for(size_t iCS=0;iCS!=_DIM_(g_ibp_own_cp_info_by_name);++iCS)
 {
  assert(g_ibp_own_cp_info_by_name[iCS]);
  assert(g_ibp_own_cp_info_by_name[iCS]->name!=NULL);

  bool has      =false;
  bool has_name =false;

  for(size_t iA=0;iA!=_DIM_(g_ibp_aliase_cs_by_name);++iA)
  {
   assert(!g_ibp_aliase_cs_by_name[iA].name.empty());
   assert(g_ibp_aliase_cs_by_name[iA].own_cs);

   has=(g_ibp_aliase_cs_by_name[iA].own_cs==g_ibp_own_cp_info_by_name[iCS]);

   has_name=(g_ibp_aliase_cs_by_name[iA].name.equal(g_ibp_own_cp_info_by_name[iCS]->name));

   if(has_name && has)
    break;
  }//for

  assert_msg(has,"CS:"<<structure::tstr_to_str(g_ibp_own_cp_info_by_name[iCS]->name));

  assert_msg(has_name,"CS:"<<structure::tstr_to_str(g_ibp_own_cp_info_by_name[iCS]->name));
 }//for iCS
}//__check_order_in__g_aliase_cs_by_name

STARTUP_CODE__DEBUG(__check_order_in__g_aliase_cs_by_name)

#endif //NDEBUG

//------------------------------------------------------------------------
/// <summary>
///  Получение перечисления стандартных collations кодовой страницы
/// </summary>
//! \param[in] cset_name
//!  Имя кодовой страницы. Can be NULL.
//!
//! Поддерживаются псевдонимы кодовых страниц.
const t_ibp_char* const* ibp_get_charset_std_collations(const t_ibp_str_box& cset_name)
{
 t_ibp_string n=cset_name.make_str();

 structure::total_self_trim(n);

 IBP_GetStdLocaleC()->toupper_str(&n);

 if(n.empty())
  n=IBP_T("NONE");

 typedef structure::t_search_result<const t_ibp_charset_manager_v2::tag_aliase*> result_type;

 if(const result_type x=structure::lower_search(g_ibp_aliase_cs_by_name,
                                                _END_(g_ibp_aliase_cs_by_name),
                                                n,
                                                t_ibp_charset_manager_v2::tag_aliase_less_by_name()))
 {
  assert((x.position)!=NULL);
  assert(!(*x.position).name.empty());
  assert((*x.position).own_cs!=NULL);

  const t_ibp_charset_manager_v2::tag_own_cs* const own_cs=(*x.position).own_cs;

  assert(own_cs);

  return own_cs->std_collations;
 }//if

 return nullptr;
}//ibp_get_charset_std_collations

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_charset_manager_v2

t_ibp_charset_manager_v2::t_ibp_charset_manager_v2
                                           (const string_type&       icu_library,
                                            const BYTE               wchars_in_utf8_symbol)
 :m_spStdLocaleC
    (IBP_GetStdLocaleC())
 ,m_icu_library
   (icu_library)
 ,m_wchars_in_utf8_symbol
   (wchars_in_utf8_symbol)
{
 assert(m_spStdLocaleC);

 assert(m_wchars_in_utf8_symbol==1 ||
        m_wchars_in_utf8_symbol==2);
}//t_ibp_charset_manager_v2

//------------------------------------------------------------------------
t_ibp_charset_manager_v2::~t_ibp_charset_manager_v2()
{
}

//------------------------------------------------------------------------
void t_ibp_charset_manager_v2::reg_cs_id_name(db_obj::db_cs_id  const cs_id,
                                              const cs_name_box_type& cs_name)
{
 const wchar_t c_bugcheck_src[]
  =L"t_ibp_charset_manager_v2::reg_cs_id_name";

 const size_t idx=structure::to_underlying(cs_id);

 if(!(idx<m_cs_id_names.size()))
 {
  IBP_ErrorUtils::Throw__BugCheck__DEBUG
   (c_bugcheck_src,
    L"#001",
    L"unknown cs_id [%1]",
    structure::to_underlying(cs_id));
 }//if

 assert(idx<m_cs_id_names.size());

 if(m_cs_id_names[idx])
 {
  IBP_ErrorUtils::Throw__BugCheck__DEBUG
   (c_bugcheck_src,
    L"#002",
    L"cs_id [%1] already registered for [%2]",
    structure::to_underlying(cs_id),
    m_cs_id_names[idx]->get_info().name);
 }//if

 assert(!m_cs_id_names[idx]);

 switch(cs_id)
 {
  case db_obj::db_cs_id::cn:
  {
   const auto name
    =self_type::helper__make_std_cs_name
      (cs_name,
       /*process_empty_name*/true);

   m_cs_id_names[idx]
    =this->helper__get_charset
      (name,
       db_obj::db_cs_mng_flag__get_txt_cs_only,
       ibp_mce_dbobj__unknown_connection_charset_1); //throw

   assert(m_cs_id_names[idx]);

   break;
  }//case cn

  //------------------------------------------------------------
  case db_obj::db_cs_id::user:
  {
   const auto name
    =self_type::helper__translate_user_cs_name
      (cs_name,
       ibp_mce_dbobj__cant_translate_user_charset_name_1); //throw

   m_cs_id_names[idx]
    =this->helper__get_charset
      (name,
       db_obj::db_cs_mng_flag__get_txt_cs_only,
       ibp_mce_dbobj__unknown_user_charset_1); //throw

   assert(m_cs_id_names[idx]);

   break;
  }//case user

  //------------------------------------------------------------
  case db_obj::db_cs_id::none:
  {
   const auto name
    =self_type::helper__translate_user_cs_name
      (cs_name,
       ibp_mce_dbobj__cant_translate_none_charset_name_1); //throw

   m_cs_id_names[idx]
    =this->helper__get_charset
      (name,
       db_obj::db_cs_mng_flag__get_txt_cs_only,
       ibp_mce_dbobj__unknown_none_charset_1); //throw

   assert(m_cs_id_names[idx]);

   break;
  }//case none

  //------------------------------------------------------------
  case db_obj::db_cs_id::ods:
  {
   const auto name
    =self_type::helper__make_std_cs_name
      (cs_name,
       /*process_empty_name*/false);

   m_cs_id_names[idx]
    =this->helper__get_charset
      (name,
       db_obj::db_cs_mng_flag__get_txt_cs_only,
       ibp_mce_dbobj__unknown_ods_charset_1); //throw

   assert(m_cs_id_names[idx]);

   break;
  }//case ods

  //------------------------------------------------------------
  default:
  {
   IBP_ErrorUtils::Throw__BugCheck__DEBUG
    (c_bugcheck_src,
     L"#003",
     L"unexpected cs_id [%1]",
     structure::to_underlying(cs_id));
  }//default
 }//switch(cs_id)
}//reg_cs_id_name

//t_db_charsets_manager_v2 interface -------------------------------------
db_obj::t_db_charset_const_ptr t_ibp_charset_manager_v2::get_charset
                                           (const cs_name_box_type&         cs_name,
                                            db_obj::t_db_cs_mng_flags const flags)
{
 ///Нормализация имени кодовой страницы. Пустое имя не заменяется на "NONE"
 const charset_name_type
  std_cs_name
   (self_type::helper__make_std_cs_name
     (cs_name,
      /*process empty name*/false));

 return this->helper__get_charset
          (std_cs_name,
           flags,
           ibp_mce_dbobj__unknown_charset_name_1);
}//get_charset

//------------------------------------------------------------------------
db_obj::t_db_charset_const_ptr t_ibp_charset_manager_v2::get_charset
                                           (db_obj::db_cs_id const cs_id)
{
 const wchar_t c_bugcheck_src[]
  =L"t_ibp_charset_manager_v2::get_charset";

 const size_t idx=structure::to_underlying(cs_id);

 if(!(idx<m_cs_id_names.size()))
 {
  IBP_ErrorUtils::Throw__BugCheck__DEBUG
   (c_bugcheck_src,
    L"#001",
    L"unknown cs_id [%1]",
    structure::to_underlying(cs_id));
 }//if

 assert(idx<m_cs_id_names.size());

 if(!m_cs_id_names[idx])
 {
  IBP_ErrorUtils::Throw__BugCheck__DEBUG
   (c_bugcheck_src,
    L"#002",
    L"unknown cs_id [%1]",
    structure::to_underlying(cs_id));
 }//if

 assert(m_cs_id_names[idx]);

 return m_cs_id_names[idx].not_null_ptr();
}//get_charset

//helper methods ---------------------------------------------------------
db_obj::t_db_charset_const_ptr
 t_ibp_charset_manager_v2::helper__get_charset(const charset_name_type&        cs_name,
                                               db_obj::t_db_cs_mng_flags const flags,
                                               ibp_msg_code_type         const mce_unk_cs_1)
{
 db_obj::t_db_charset_const_ptr /*const*/
  spCS(this->helper__get_charset(cs_name,mce_unk_cs_1));

 assert(spCS);

 if((flags&db_obj::db_cs_mng_flag__get_txt_cs_only)==db_obj::db_cs_mng_flag__get_txt_cs_only)
 {
  if(spCS->get_info().is_octets())
  {
   t_ibp_error exc(E_FAIL,mce_unk_cs_1);

   exc<<cs_name;

   exc.raise_me();
  }//if
 }//if

 assert(spCS);

 return spCS; //move
}//helper__get_charset

//------------------------------------------------------------------------
db_obj::t_db_charset_const_ptr
 t_ibp_charset_manager_v2::helper__get_charset(const charset_name_type& cs_name,
                                               ibp_msg_code_type const  mce_unk_cs_1)
{
 const lock_guard_type __lock(m_guard);

 {
  const cs_map_type::const_iterator i(m_cache.find(cs_name));

  if(i!=m_cache.end())
  {
   assert(*i);

   return (*i).not_null_ptr();
  }//if
 }//local

 //создаем экземпляр новой кодовой страницы

 typedef structure::t_search_result<const tag_aliase*> result_type;

 if(const result_type x=structure::lower_search(g_ibp_aliase_cs_by_name,
                                                _END_(g_ibp_aliase_cs_by_name),
                                                cs_name,
                                                tag_aliase_less_by_name()))
 {
  assert((x.position)!=NULL);
  assert(!(*x.position).name.empty());
  assert((*x.position).own_cs!=NULL);

  const tag_own_cs* const own_cs=(*x.position).own_cs;

  assert(own_cs);

  if(own_cs->creator!=NULL)
  {
   //Built-In кодовая страница

   {
    //повторный поиск по базовому имени кодовой страницы
    const cs_map_type::const_iterator
     i(m_cache.find(structure::make_str_box(own_cs->name)));

    if(i!=m_cache.end())
    {
     assert(*i);

     return (*i).not_null_ptr();
    }//if
   }//local

   assert(own_cs);

   //--
   db_obj::t_db_charset_const_ptr /*const*/ spCS(own_cs->creator(this));

   assert(spCS);

   _VERIFY(m_cache.insert(spCS.not_null_ptr()).second);

   //--
   assert(spCS);

   return spCS; //move
  }//if - указана функция для создания объекта
 }//if - нашли в списке собственных страниц

 //создание кодовой страницы, привязанной к внешней ICU библиотеке
 if(!cs_name.empty())
 {
  if(db_obj::t_db_charset_const_ptr /*const*/ x=this->helper__create_icu_charset(cs_name))
  {
   assert(x);

   _VERIFY(m_cache.insert(x.not_null_ptr()).second);

   //--
   assert(x);

   return x; //move
  }//if
 }//if !cs_name.empty()

 //---
 t_ibp_error exc(E_FAIL,mce_unk_cs_1);

 exc<<cs_name;

 exc.raise_me();

 //---
#if(COMP_BUILD_UNUSED_CODE)
 return nullptr;
#endif
}//helper__get_charset

//------------------------------------------------------------------------
db_obj::t_db_charset_const_ptr
 t_ibp_charset_manager_v2::helper__create_icu_charset(const cs_name_box_type& cs_name)
{
 DEBUG_CODE(m_guard.debug__CheckCurrentThreadIsOwner();)

 if(m_icu_library.empty())
  return nullptr;

 db_obj::t_db_charset_const_ptr spCS;

 try
 {
  if(!m_icu_provider)
   this->helper__create_icu_provider(); //throw

  assert(m_icu_provider);

  spCS=m_icu_provider->load_cs(cs_name); //can throw
 }
 catch(const std::exception& exc)
 {
  //Добавляем информацию об имени кодовой страницы
  t_ibp_error new_exc(exc);

  new_exc.add_error(E_FAIL,ibp_mce_cs__create_charset_object_1);

  new_exc<<cs_name;

  new_exc.raise_me();
 }//catch

 return spCS; //move
}//helper__create_icu_charset

//------------------------------------------------------------------------
void t_ibp_charset_manager_v2::helper__create_icu_provider()
{
 typedef os::t_ibp_os__dll_ptr dll_ptr;

 ///Загрузка DLL
 const dll_ptr
  spDLL
   (IBP_GlobalObjectsData__DLLs::GetDLL
     (m_icu_library,
      ibprovider::ibp_propval_dll_lock_rule__force_unload));

 ///Загрузка сведений о версии DLL
 os::t_ibp_os__dll_version_info dll_ver_info;

 if(!dll_ver_info.load(spDLL->get_dll_handle()))
 {
  //ERROR - в DLL нет ресурса VERSIONINFO

  t_ibp_error exc(E_FAIL,
                  ibp_mce_common__dll_not_has_versioninfo_1);

  exc<<win32lib::GetModuleFileName(spDLL->get_dll_handle());

  exc.raise_me();
 }//if

 //-----------------------------------------  read module descr
 if(dll_ver_info.m_file_descr.empty())
 {
  //ERROR - в VERSIONINFO отсутствует описание модуля

  t_ibp_error exc(E_FAIL,
                  ibp_mce_common__dll_versioninfo_not_has_file_descr_1);

  exc<<win32lib::GetModuleFileName(spDLL->get_dll_handle());

  exc.raise_me();
 }//if

 assert(!dll_ver_info.m_file_descr.empty());

 //-----------------------------------------  read module version
 if(dll_ver_info.m_prod_version.empty())
 {
  //ERROR - в VERSIONINFO отсутствует информация о версии модуля

  t_ibp_error exc(E_FAIL,
                  ibp_mce_common__dll_versioninfo_not_has_prod_version_1);

  exc<<win32lib::GetModuleFileName(spDLL->get_dll_handle());

  exc.raise_me();
 }//if

 assert(!dll_ver_info.m_prod_version.empty());

 if(dll_ver_info.m_file_descr==L"IBM ICU Common DLL")
 {
  //Это ICU из FB2.1, FB2.5
  const structure::wstr_version ver(dll_ver_info.m_prod_version);

  if(structure::eq_str_version_prefix(ver,L"3.0"))
  {
   ///Создание провайдера ICU API v3
   namespace icu_ns=ibp::charsets::cs_code::icu::v003;

   m_icu_provider
    =structure::not_null_ptr
      (new icu_ns::t_ibp_icu_provider(spDLL));
  }//if
  else
  {
   //ERROR - неподдерживаемая версия ICU

   t_ibp_error exc(E_FAIL,
                   ibp_mce_cs__unsupported_external_provider_3);

   exc<<win32lib::GetModuleFileName(spDLL->get_dll_handle())
      <<dll_ver_info.m_file_descr
      <<dll_ver_info.m_prod_version;

   exc.raise_me();
  }//else
 }
 else
 if(dll_ver_info.m_file_descr==L"ICU Common DLL")
 {
  //Это ICU из FB3
  const structure::wstr_version ver(dll_ver_info.m_prod_version);

  if(structure::eq_str_version_prefix(ver,L"52.1"))
  {
   ///Создание провайдера ICU API v52
   namespace icu_ns=ibp::charsets::cs_code::icu::v052;

   m_icu_provider
    =structure::not_null_ptr
      (new icu_ns::t_ibp_icu_provider(spDLL));
  }
  else
  {
   //ERROR - неподдерживаемая версия ICU

   t_ibp_error exc(E_FAIL,
                   ibp_mce_cs__unsupported_external_provider_3);

   exc<<win32lib::GetModuleFileName(spDLL->get_dll_handle())
      <<dll_ver_info.m_file_descr
      <<dll_ver_info.m_prod_version;

   exc.raise_me();
  }//else

  assert(m_icu_provider);
 }
 else
 {
  //ERROR - указанная DLL не является поставщиком ICU

  t_ibp_error exc(E_FAIL,
                  ibp_mce_cs__unknown_external_provider_3);

  exc<<win32lib::GetModuleFileName(spDLL->get_dll_handle())
     <<dll_ver_info.m_file_descr
     <<dll_ver_info.m_prod_version;

  exc.raise_me();
 }//else

 assert(m_icu_provider);
}//helper__create_icu_provider

//------------------------------------------------------------------------
t_ibp_charset_manager_v2::charset_name_type
 t_ibp_charset_manager_v2::helper__translate_user_cs_name
                                      (const cs_name_box_type& user_cs_name,
                                       ibp_msg_code_type const mce_1)const
{
 const charset_name_type
  cs_name
   (self_type::helper__make_std_cs_name
     (user_cs_name,
      /*process_empty_name*/true));

 UINT  SysCodePageID=0;
 const t_ibp_char* NamePrefix=NULL;

 if(cs_name==IBP_T("ACP"))
 {
  SysCodePageID=::GetACP();

  NamePrefix=IBP_T("WINDOWS");
 }
 else
 if(cs_name==IBP_T("OCP"))
 {
  SysCodePageID=::GetOEMCP();

  NamePrefix=IBP_T("DOS");
 }
 else
 {
  return cs_name;
 }

 if(SysCodePageID==0)
 {
  t_ibp_error exc(E_FAIL,mce_1);

  exc<<user_cs_name.make_str();

  exc.raise_me();
 }//if

 structure::t_basic_str_formatter<t_ibp_char> result(IBP_T("%1-%2"));

 result<<NamePrefix<<SysCodePageID;

 return result.str();
}//helper__translate_user_cs_name

//------------------------------------------------------------------------
t_ibp_charset_manager_v2::charset_name_type
 t_ibp_charset_manager_v2::helper__make_std_cs_name(const cs_name_box_type& cs_name,
                                                    bool              const process_empty_name)const
{
 CHECK_READ_TYPED_PTR(cs_name.ptr,cs_name.len);

 charset_name_type std_cs_name(cs_name.begin(),cs_name.end());

 structure::total_self_trim(std_cs_name);

 if(std_cs_name.empty() && process_empty_name)
 {
  std_cs_name=IBP_T("NONE");
 }
 else
 {
  m_spStdLocaleC->toupper_str(&std_cs_name);
 }//else

 return std_cs_name;
}//helper__make_std_cs_name

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
