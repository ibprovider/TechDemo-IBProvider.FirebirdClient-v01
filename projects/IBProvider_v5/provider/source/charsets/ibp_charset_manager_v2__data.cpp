////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_charset_manager_v2__data.cpp
//! \brief   Определение таблиц с данными для t_ibp_charset_manager_v2
//! \author  Kovalenko Dmitry
//! \date    18.11.2010
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/ibp_charset_manager_v2__data.h"
#include "source/charsets/cs_code/ibp_cs_bit8.h"
#include "source/charsets/cs_code/ibp_cs_bit8_data.h"
#include "source/charsets/cs_code/ibp_cs_bit8_bit16.h"
#include "source/charsets/cs_code/ibp_cs_bit8_bit16_data.h"
#include "source/charsets/cs_code/ibp_cs_jis_traits.h"
#include "source/charsets/cs_code/ibp_cs_ascii_traits.h"
#include "source/charsets/cs_code/ibp_cs_unicode_fss_traits.h"
#include "source/charsets/cs_code/ibp_cs_utf8_traits.h"
#include "source/charsets/cs_code/ibp_cs_base64_mime.h"
#include "source/charsets/cs_code/ibp_cs_octets.h"
#include "source/charsets/ibp_charset_std_collations.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

#define IBP_CS_FACTORY_NAME(cs_name) ibp_create_cs_##cs_name

////////////////////////////////////////////////////////////////////////////////
//фабрики кодовых страниц BIT8

#define DEF_IBP_CS_BIT8__EX(_cs_name,                                     \
                            _cs_base)                                     \
static db_obj::t_db_charset_ptr IBP_CS_FACTORY_NAME(_cs_name)             \
                                 (const t_ibp_charset_manager_v2*)        \
{                                                                         \
 db_obj::t_db_charset_info cs_info;                                       \
                                                                          \
 cs_info.name               =IBP_T(#_cs_name);                            \
 cs_info.min_bytes_per_char =1;                                           \
 cs_info.bytes_per_char     =1;                                           \
 cs_info.ucs2_for_char      =1;                                           \
 cs_info.flags              =0;                                           \
                                                                          \
 return structure::not_null_ptr                                           \
         (new t_ibp_cs_bit8                                               \
           (cs_info,                                                      \
            &g_ibp_cs_map_##_cs_base));                                   \
}

//------------------------------------------------------------------------
#define DEF_IBP_CS_BIT8(_cs_name)                                         \
 DEF_IBP_CS_BIT8__EX                                                      \
  (_cs_name,                                                              \
   _cs_name)

//------------------------------------------------------------------------
DEF_IBP_CS_BIT8     (DOS437)
DEF_IBP_CS_BIT8     (DOS737)
DEF_IBP_CS_BIT8     (DOS775)
DEF_IBP_CS_BIT8     (DOS850)
DEF_IBP_CS_BIT8     (DOS852)
DEF_IBP_CS_BIT8     (DOS857)
DEF_IBP_CS_BIT8     (DOS858)
DEF_IBP_CS_BIT8     (DOS860)
DEF_IBP_CS_BIT8     (DOS861)
DEF_IBP_CS_BIT8     (DOS862)
DEF_IBP_CS_BIT8     (DOS863)
DEF_IBP_CS_BIT8     (DOS864)
DEF_IBP_CS_BIT8     (DOS865)
DEF_IBP_CS_BIT8     (DOS866)
DEF_IBP_CS_BIT8     (DOS869)

DEF_IBP_CS_BIT8     (WIN1250)
DEF_IBP_CS_BIT8     (WIN1251)
DEF_IBP_CS_BIT8     (WIN1252)
DEF_IBP_CS_BIT8     (WIN1253)
DEF_IBP_CS_BIT8     (WIN1254)
DEF_IBP_CS_BIT8     (WIN1255)
DEF_IBP_CS_BIT8     (WIN1256)
DEF_IBP_CS_BIT8     (WIN1257)
DEF_IBP_CS_BIT8     (WIN1258)

DEF_IBP_CS_BIT8__EX (CYRL       ,WIN1251)

DEF_IBP_CS_BIT8     (NEXT);

DEF_IBP_CS_BIT8     (ISO8859_1)
DEF_IBP_CS_BIT8     (ISO8859_2)
DEF_IBP_CS_BIT8     (ISO8859_3)
DEF_IBP_CS_BIT8     (ISO8859_4)
DEF_IBP_CS_BIT8     (ISO8859_5)
DEF_IBP_CS_BIT8     (ISO8859_6)
DEF_IBP_CS_BIT8     (ISO8859_7)
DEF_IBP_CS_BIT8     (ISO8859_8)
DEF_IBP_CS_BIT8     (ISO8859_9)
DEF_IBP_CS_BIT8     (ISO8859_13)
DEF_IBP_CS_BIT8     (ISO8859_15)

DEF_IBP_CS_BIT8     (KOI8R)
DEF_IBP_CS_BIT8     (KOI8U)

DEF_IBP_CS_BIT8     (TIS620)

//------------------------------------------------------------------------
#undef DEF_IBP_CS_BIT8

////////////////////////////////////////////////////////////////////////////////
//Фабрики кодовых страниц BIT8-BIT16

static db_obj::t_db_charset_ptr IBP_CS_FACTORY_NAME(BIG_5)
                                 (const t_ibp_charset_manager_v2* const /*mng*/)
{
 typedef t_ibp_cs_bit8_bit16<t_ibp_cs_bit8_bit16_traits> cs_type;

 db_obj::t_db_charset_info cs_info;

 cs_info.name               =L"BIG_5";
 cs_info.min_bytes_per_char =1;
 cs_info.bytes_per_char     =2;
 cs_info.ucs2_for_char      =1;
 cs_info.flags              =0;

 return structure::not_null_ptr(new cs_type(cs_info,&g_ibp_cs_map_BIG_5));
}//BIG_5

//------------------------------------------------------------------------
static db_obj::t_db_charset_ptr IBP_CS_FACTORY_NAME(GB_2312)
                                 (const t_ibp_charset_manager_v2* const /*mng*/)
{
 typedef t_ibp_cs_bit8_bit16<t_ibp_cs_bit8_bit16_traits> cs_type;

 db_obj::t_db_charset_info cs_info;

 cs_info.name               =L"GB_2312";
 cs_info.min_bytes_per_char =1;
 cs_info.bytes_per_char     =2;
 cs_info.ucs2_for_char      =1;
 cs_info.flags              =0;

 return structure::not_null_ptr(new cs_type(cs_info,&g_ibp_cs_map_GB_2312));
}//GB_2312

//------------------------------------------------------------------------
static db_obj::t_db_charset_ptr IBP_CS_FACTORY_NAME(KSC_5601)
                                 (const t_ibp_charset_manager_v2* const /*mng*/)
{
 typedef t_ibp_cs_bit8_bit16<t_ibp_cs_bit8_bit16_traits> cs_type;

 db_obj::t_db_charset_info cs_info;

 cs_info.name               =L"KSC_5601";
 cs_info.min_bytes_per_char =1;
 cs_info.bytes_per_char     =2;
 cs_info.ucs2_for_char      =1;
 cs_info.flags              =0;

 return structure::not_null_ptr(new cs_type(cs_info,&g_ibp_cs_map_KSC_5601));
}//KSC_5601

//------------------------------------------------------------------------
static const t_ibp_cs_eucj_0208_traits g_ibp_cs_EUCJ_0208_traits;

static db_obj::t_db_charset_ptr IBP_CS_FACTORY_NAME(EUCJ_0208)
                                 (const t_ibp_charset_manager_v2* const /*mng*/)
{
 typedef t_ibp_cs_bit8_bit16<t_ibp_cs_eucj_0208_traits> cs_type;

 db_obj::t_db_charset_info cs_info;

 cs_info.name               =L"EUCJ_0208";
 cs_info.min_bytes_per_char =1;
 cs_info.bytes_per_char     =2;
 cs_info.ucs2_for_char      =1;
 cs_info.flags              =0;

 return structure::not_null_ptr(new cs_type(cs_info,&g_ibp_cs_EUCJ_0208_traits));
}//EUCJ_0208

//------------------------------------------------------------------------
static const t_ibp_cs_sjis_0208_traits g_ibp_cs_SJIS_0208_traits;

static db_obj::t_db_charset_ptr IBP_CS_FACTORY_NAME(SJIS_0208)
                                 (const t_ibp_charset_manager_v2* const /*mng*/)
{
 typedef t_ibp_cs_bit8_bit16<t_ibp_cs_sjis_0208_traits> cs_type;

 db_obj::t_db_charset_info cs_info;

 cs_info.name               =L"SJIS_0208";
 cs_info.min_bytes_per_char =1;
 cs_info.bytes_per_char     =2;
 cs_info.ucs2_for_char      =1;
 cs_info.flags              =0;

 return structure::not_null_ptr(new cs_type(cs_info,&g_ibp_cs_SJIS_0208_traits));
}//SJIS_0208

//------------------------------------------------------------------------
static const t_ibp_cs_ascii_traits g_ibp_cs_ASCII_traits;

static db_obj::t_db_charset_ptr IBP_CS_FACTORY_NAME(ASCII)
                                 (const t_ibp_charset_manager_v2* const /*mng*/)
{
 typedef t_ibp_cs_bit8_bit16<t_ibp_cs_ascii_traits> cs_type;

 db_obj::t_db_charset_info cs_info;

 cs_info.name               =L"ASCII";
 cs_info.min_bytes_per_char =1;
 cs_info.bytes_per_char     =1;
 cs_info.ucs2_for_char      =1;
 cs_info.flags              =0;

 return structure::not_null_ptr(new cs_type(cs_info,&g_ibp_cs_ASCII_traits));
}//ASCII

//------------------------------------------------------------------------
static const t_ibp_cs_unicode_fss_traits g_ibp_cs_UNICODE_FSS_traits;

static db_obj::t_db_charset_ptr IBP_CS_FACTORY_NAME(UNICODE_FSS)
                                 (const t_ibp_charset_manager_v2* const /*mng*/)
{
 typedef t_ibp_cs_bit8_bit16<t_ibp_cs_unicode_fss_traits> cs_type;

 db_obj::t_db_charset_info cs_info;

 cs_info.name               =L"UNICODE_FSS";
 cs_info.min_bytes_per_char =1;
 cs_info.bytes_per_char     =3;
 cs_info.ucs2_for_char      =1;
 cs_info.flags              =0;

 return structure::not_null_ptr(new cs_type(cs_info,&g_ibp_cs_UNICODE_FSS_traits));
}//UNICODE_FSS

//------------------------------------------------------------------------
static const t_ibp_cs_utf8_traits g_ibp_cs_UTF8_traits;

static db_obj::t_db_charset_ptr IBP_CS_FACTORY_NAME(UTF8)
                                 (const t_ibp_charset_manager_v2* const mng)
{
 assert(mng);
 assert(mng->m_wchars_in_utf8_symbol==1 ||
        mng->m_wchars_in_utf8_symbol==2);

 typedef t_ibp_cs_bit8_bit16<t_ibp_cs_utf8_traits> cs_type;

 db_obj::t_db_charset_info cs_info;

 cs_info.name               =L"UTF8";
 cs_info.min_bytes_per_char =1;
 cs_info.bytes_per_char     =4;
 cs_info.ucs2_for_char      =mng->m_wchars_in_utf8_symbol;
 cs_info.flags              =0;

 return structure::not_null_ptr(new cs_type(cs_info,&g_ibp_cs_UTF8_traits));
}//UTF8

//------------------------------------------------------------------------
static db_obj::t_db_charset_ptr IBP_CS_FACTORY_NAME(NONE)
                                 (const t_ibp_charset_manager_v2* const /*mng*/)
{
 typedef t_ibp_cs_bit8_bit16<t_ibp_cs_ascii_traits> cs_type;

 db_obj::t_db_charset_info cs_info;

 cs_info.name               =L"NONE";
 cs_info.min_bytes_per_char =1;
 cs_info.bytes_per_char     =1;
 cs_info.ucs2_for_char      =1;
 cs_info.flags              =db_obj::db_charset_info_flag__is_none|db_obj::db_charset_info_flag__is_stable;

 return structure::not_null_ptr(new cs_type(cs_info,&g_ibp_cs_ASCII_traits));
}//NONE

//------------------------------------------------------------------------
static db_obj::t_db_charset_ptr IBP_CS_FACTORY_NAME(OCTETS)
                                 (const t_ibp_charset_manager_v2* const /*mng*/)
{
 typedef t_ibp_cs_octets cs_type;

 db_obj::t_db_charset_info cs_info;

 cs_info.name               =L"OCTETS";
 cs_info.min_bytes_per_char =1;
 cs_info.bytes_per_char     =1;
 cs_info.ucs2_for_char      =1;
 cs_info.flags              =db_obj::db_charset_info_flag__is_octets|db_obj::db_charset_info_flag__is_stable;

 return structure::not_null_ptr(new cs_type(cs_info));
}//OCTETS

//------------------------------------------------------------------------
static db_obj::t_db_charset_ptr IBP_CS_FACTORY_NAME(BASE64)
                                 (const t_ibp_charset_manager_v2* const /*mng*/)
{
 typedef t_ibp_cs_base64_mime cs_type;

 db_obj::t_db_charset_info cs_info;

 cs_info.name               =L"BASE64";
 cs_info.min_bytes_per_char =1;
 cs_info.bytes_per_char     =1;
 cs_info.ucs2_for_char      =1;
 cs_info.flags              =db_obj::db_charset_info_flag__is_stable;

 return structure::not_null_ptr(new cs_type(cs_info));
}//BASE64

////////////////////////////////////////////////////////////////////////////////
//Определение статических объектов с описанием собственных кодовых страниц

#define DEF_IBP_CP_INFO_EX(name,                                            \
                           creator)                                         \
extern const t_ibp_charset_manager_v2::tag_own_cs                           \
 g_ibp_own_cp_info_##name={IBP_T(#name),                                    \
                           creator,                                         \
                           ibp::g_ibp_##name##_std_collations}

//------------------------------------------
#define DEF_IBP_CP_INFO_F(name)                                             \
 DEF_IBP_CP_INFO_EX(name,                                                   \
                    IBP_CS_FACTORY_NAME(name))

//------------------------------------------------------------------------
DEF_IBP_CP_INFO_F (ASCII);

DEF_IBP_CP_INFO_F (BASE64);

DEF_IBP_CP_INFO_F (CYRL);

DEF_IBP_CP_INFO_F (NONE);

DEF_IBP_CP_INFO_F (OCTETS);

DEF_IBP_CP_INFO_F (UNICODE_FSS);

DEF_IBP_CP_INFO_F (UTF8);

DEF_IBP_CP_INFO_F (DOS437);

DEF_IBP_CP_INFO_F (DOS737);

DEF_IBP_CP_INFO_F (DOS775);

DEF_IBP_CP_INFO_F (DOS850);

DEF_IBP_CP_INFO_F (DOS852);

DEF_IBP_CP_INFO_F (DOS857);

DEF_IBP_CP_INFO_F (DOS858);

DEF_IBP_CP_INFO_F (DOS860);

DEF_IBP_CP_INFO_F (DOS861);

DEF_IBP_CP_INFO_F (DOS862);

DEF_IBP_CP_INFO_F (DOS863);

DEF_IBP_CP_INFO_F (DOS864);

DEF_IBP_CP_INFO_F (DOS865);

DEF_IBP_CP_INFO_F (DOS866);

DEF_IBP_CP_INFO_F (DOS869);

DEF_IBP_CP_INFO_F (ISO8859_1);

DEF_IBP_CP_INFO_F (ISO8859_13);

DEF_IBP_CP_INFO_F (ISO8859_15);

DEF_IBP_CP_INFO_F (ISO8859_2);

DEF_IBP_CP_INFO_F (ISO8859_3);

DEF_IBP_CP_INFO_F (ISO8859_4);

DEF_IBP_CP_INFO_F (ISO8859_5);

DEF_IBP_CP_INFO_F (ISO8859_6);

DEF_IBP_CP_INFO_F (ISO8859_7);

DEF_IBP_CP_INFO_F (ISO8859_8);

DEF_IBP_CP_INFO_F (ISO8859_9);

DEF_IBP_CP_INFO_F (WIN1250);

DEF_IBP_CP_INFO_F (WIN1251);

DEF_IBP_CP_INFO_F (WIN1252);

DEF_IBP_CP_INFO_F (WIN1253);

DEF_IBP_CP_INFO_F (WIN1254);

DEF_IBP_CP_INFO_F (WIN1255);

DEF_IBP_CP_INFO_F (WIN1256);

DEF_IBP_CP_INFO_F (WIN1257);

DEF_IBP_CP_INFO_F (WIN1258);

DEF_IBP_CP_INFO_F (NEXT);

DEF_IBP_CP_INFO_F (KOI8R);

DEF_IBP_CP_INFO_F (KOI8U);

DEF_IBP_CP_INFO_F (TIS620);

DEF_IBP_CP_INFO_F (BIG_5);

DEF_IBP_CP_INFO_F (GB_2312);

DEF_IBP_CP_INFO_F (KSC_5601);

DEF_IBP_CP_INFO_F (EUCJ_0208);

DEF_IBP_CP_INFO_F (SJIS_0208);

DEF_IBP_CP_INFO_EX(CP943C,
                   nullptr);

DEF_IBP_CP_INFO_EX(GBK,
                   nullptr);

DEF_IBP_CP_INFO_EX(GB18030,
                   nullptr);

//------------------------------------------------------------------------
#undef DEF_IBP_CP_INFO_F
#undef DEF_IBP_CP_INFO_EX

////////////////////////////////////////////////////////////////////////////////
#undef IBP_CS_FACTORY_NAME
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
