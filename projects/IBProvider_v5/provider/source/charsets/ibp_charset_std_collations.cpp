////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_charset_std_collations.cpp
//! \brief   ѕеречисление стандартных collations дл€ кодовых страниц
//! \author  Kovalenko Dmitry
//! \date    25.08.2010
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/ibp_charset_std_collations.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

extern const t_ibp_char* const g_ibp_ASCII_std_collations[]
 ={IBP_T("ASCII"),
   NULL}; //g_ibp_ASCII_std_collations

extern const t_ibp_char* const g_ibp_BASE64_std_collations[]
 ={IBP_T("BASE64"),
   NULL}; //g_ibp_BASE64_std_collations

extern const t_ibp_char* const g_ibp_BIG_5_std_collations[]
 ={IBP_T("BIG_5"),
   NULL}; //g_ibp_BIG_5_std_collations

extern const t_ibp_char* const g_ibp_CP943C_std_collations[]
 ={IBP_T("CP943C"),
   IBP_T("CP943C_UNICODE"),
   NULL}; //g_ibp_CP943C_std_collations

extern const t_ibp_char* const g_ibp_CYRL_std_collations[]
 ={IBP_T("CYRL"),
   IBP_T("DB_RUS"),
   IBP_T("PDOX_CYRL"),
   NULL}; //g_ibp_CYRL_std_collations

extern const t_ibp_char* const g_ibp_DOS437_std_collations[]
 ={IBP_T("DB_DEU437"),
   IBP_T("DB_ESP437"),
   IBP_T("DB_FIN437"),
   IBP_T("DB_FRA437"),
   IBP_T("DB_ITA437"),
   IBP_T("DB_NLD437"),
   IBP_T("DB_SVE437"),
   IBP_T("DB_UK437"),
   IBP_T("DB_US437"),
   IBP_T("DOS437"),
   IBP_T("PDOX_ASCII"),
   IBP_T("PDOX_INTL"),
   IBP_T("PDOX_SWEDFIN"),
   NULL}; //g_ibp_DOS437_std_collations

extern const t_ibp_char* const g_ibp_DOS737_std_collations[]
 ={IBP_T("DOS737"),
   NULL}; //g_ibp_DOS737_std_collations

extern const t_ibp_char* const g_ibp_DOS775_std_collations[]
 ={IBP_T("DOS775"),
   NULL}; //g_ibp_DOS775_std_collations

extern const t_ibp_char* const g_ibp_DOS850_std_collations[]
 ={IBP_T("DB_DEU850"),
   IBP_T("DB_ESP850"),
   IBP_T("DB_FRA850"),
   IBP_T("DB_FRC850"),
   IBP_T("DB_ITA850"),
   IBP_T("DB_NLD850"),
   IBP_T("DB_PTB850"),
   IBP_T("DB_SVE850"),
   IBP_T("DB_UK850"),
   IBP_T("DB_US850"),
   IBP_T("DOS850"),
   NULL}; //g_ibp_DOS850_std_collations

extern const t_ibp_char* const g_ibp_DOS852_std_collations[]
 ={IBP_T("DB_CSY"),
   IBP_T("DB_PLK"),
   IBP_T("DB_SLO"),
   IBP_T("DOS852"),
   IBP_T("PDOX_CSY"),
   IBP_T("PDOX_HUN"),
   IBP_T("PDOX_PLK"),
   IBP_T("PDOX_SLO"),
   NULL}; //g_ibp_DOS852_std_collations

extern const t_ibp_char* const g_ibp_DOS857_std_collations[]
 ={IBP_T("DB_TRK"),
   IBP_T("DOS857"),
   NULL}; //g_ibp_DOS857_std_collations

extern const t_ibp_char* const g_ibp_DOS858_std_collations[]
 ={IBP_T("DOS858"),
   NULL}; //g_ibp_DOS858_std_collations

extern const t_ibp_char* const g_ibp_DOS860_std_collations[]
 ={IBP_T("DB_PTG860"),
   IBP_T("DOS860"),
   NULL}; //g_ibp_DOS860_std_collations

extern const t_ibp_char* const g_ibp_DOS861_std_collations[]
 ={IBP_T("DOS861"),
   IBP_T("PDOX_ISL"),
   NULL}; //g_ibp_DOS861_std_collations

extern const t_ibp_char* const g_ibp_DOS862_std_collations[]
 ={IBP_T("DOS862"),
   NULL}; //g_ibp_DOS862_std_collations

extern const t_ibp_char* const g_ibp_DOS863_std_collations[]
 ={IBP_T("DB_FRC863"),
   IBP_T("DOS863"),
   NULL}; //g_ibp_DOS863_std_collations

extern const t_ibp_char* const g_ibp_DOS864_std_collations[]
 ={IBP_T("DOS864"),
   NULL}; //g_ibp_DOS864_std_collations

extern const t_ibp_char* const g_ibp_DOS865_std_collations[]
 ={IBP_T("DB_DAN865"),
   IBP_T("DB_NOR865"),
   IBP_T("DOS865"),
   IBP_T("PDOX_NORDAN4"),
   NULL}; //g_ibp_DOS865_std_collations

extern const t_ibp_char* const g_ibp_DOS866_std_collations[]
 ={IBP_T("DOS866"),
   NULL}; //g_ibp_DOS866_std_collations

extern const t_ibp_char* const g_ibp_DOS869_std_collations[]
 ={IBP_T("DOS869"),
   NULL}; //g_ibp_DOS869_std_collations

extern const t_ibp_char* const g_ibp_EUCJ_0208_std_collations[]
 ={IBP_T("EUCJ_0208"),
   NULL}; //g_ibp_EUCJ_0208_std_collations

extern const t_ibp_char* const g_ibp_GB18030_std_collations[]
 ={IBP_T("GB18030"),
   IBP_T("GB18030_UNICODE"),
   NULL}; //g_ibp_GB18030_std_collations

extern const t_ibp_char* const g_ibp_GBK_std_collations[]
 ={IBP_T("GBK"),
   IBP_T("GBK_UNICODE"),
   NULL}; //g_ibp_GBK_std_collations

extern const t_ibp_char* const g_ibp_GB_2312_std_collations[]
 ={IBP_T("GB_2312"),
   NULL}; //g_ibp_GB_2312_std_collations

extern const t_ibp_char* const g_ibp_ISO8859_1_std_collations[]
 ={IBP_T("CC_ESPLAT1"),
   IBP_T("CC_PTBRLAT1"),
   IBP_T("DA_DA"),
   IBP_T("DE_DE"),
   IBP_T("DU_NL"),
   IBP_T("EN_UK"),
   IBP_T("EN_US"),
   IBP_T("ES_ES"),
   IBP_T("ES_ES_CI_AI"),
   IBP_T("FI_FI"),
   IBP_T("FR_CA"),
   IBP_T("FR_FR"),
   IBP_T("FR_FR_CI_AI"),
   IBP_T("ISO8859_1"),
   IBP_T("IS_IS"),
   IBP_T("IT_IT"),
   IBP_T("NO_NO"),
   IBP_T("PT_BR"),
   IBP_T("PT_PT"),
   IBP_T("SV_SV"),
   NULL}; //g_ibp_ISO8859_1_std_collations

extern const t_ibp_char* const g_ibp_ISO8859_13_std_collations[]
 ={IBP_T("ISO8859_13"),
   IBP_T("LT_LT"),
   NULL}; //g_ibp_ISO8859_13_std_collations

extern const t_ibp_char* const g_ibp_ISO8859_15_std_collations[]
 ={IBP_T("CC_ESPLAT9"),
   IBP_T("CC_PTBRLAT9"),
   IBP_T("DA_DA9"),
   IBP_T("DE_DE9"),
   IBP_T("DU_NL9"),
   IBP_T("EN_UK9"),
   IBP_T("EN_US9"),
   IBP_T("ES_ES9"),
   IBP_T("FI_FI9"),
   IBP_T("FR_CA9"),
   IBP_T("FR_FR9"),
   IBP_T("ISO8859_15"),
   IBP_T("IS_IS9"),
   IBP_T("IT_IT9"),
   IBP_T("NO_NO9"),
   IBP_T("PT_PT9"),
   IBP_T("SV_SV9"),
   NULL}; //g_ibp_ISO8859_15_std_collations

extern const t_ibp_char* const g_ibp_ISO8859_2_std_collations[]
 ={IBP_T("CS_CZ"),
   IBP_T("ISO8859_2"),
   IBP_T("ISO_HUN"),
   IBP_T("ISO_PLK"),
   IBP_T("PL_PL"),
   NULL}; //g_ibp_ISO8859_2_std_collations

extern const t_ibp_char* const g_ibp_ISO8859_3_std_collations[]
 ={IBP_T("ISO8859_3"),
   NULL}; //g_ibp_ISO8859_3_std_collations

extern const t_ibp_char* const g_ibp_ISO8859_4_std_collations[]
 ={IBP_T("ISO8859_4"),
   NULL}; //g_ibp_ISO8859_4_std_collations

extern const t_ibp_char* const g_ibp_ISO8859_5_std_collations[]
 ={IBP_T("ISO8859_5"),
   NULL}; //g_ibp_ISO8859_5_std_collations

extern const t_ibp_char* const g_ibp_ISO8859_6_std_collations[]
 ={IBP_T("ISO8859_6"),
   NULL}; //g_ibp_ISO8859_6_std_collations

extern const t_ibp_char* const g_ibp_ISO8859_7_std_collations[]
 ={IBP_T("ISO8859_7"),
   NULL}; //g_ibp_ISO8859_7_std_collations

extern const t_ibp_char* const g_ibp_ISO8859_8_std_collations[]
 ={IBP_T("ISO8859_8"),
   NULL}; //g_ibp_ISO8859_8_std_collations

extern const t_ibp_char* const g_ibp_ISO8859_9_std_collations[]
 ={IBP_T("ISO8859_9"),
   NULL}; //g_ibp_ISO8859_9_std_collations

extern const t_ibp_char* const g_ibp_KOI8R_std_collations[]
 ={IBP_T("KOI8R"),
   IBP_T("KOI8R_RU"),
   IBP_T("RU_RU"),
   NULL}; //g_ibp_KOI8R_std_collations

extern const t_ibp_char* const g_ibp_KOI8U_std_collations[]
 ={IBP_T("KOI8U"),
   IBP_T("KOI8U_UA"),
   NULL}; //g_ibp_KOI8U_std_collations

extern const t_ibp_char* const g_ibp_KSC_5601_std_collations[]
 ={IBP_T("KSC_5601"),
   IBP_T("KSC_DICTIONARY"),
   NULL}; //g_ibp_KSC_5601_std_collations

extern const t_ibp_char* const g_ibp_NEXT_std_collations[]
 ={IBP_T("NEXT"),
   IBP_T("NXT_DEU"),
   IBP_T("NXT_ESP"),
   IBP_T("NXT_FRA"),
   IBP_T("NXT_ITA"),
   IBP_T("NXT_US"),
   NULL}; //g_ibp_NEXT_std_collations

extern const t_ibp_char* const g_ibp_NONE_std_collations[]
 ={IBP_T("NONE"),
   NULL}; //g_ibp_NONE_std_collations

extern const t_ibp_char* const g_ibp_OCTETS_std_collations[]
 ={IBP_T("OCTETS"),
   NULL}; //g_ibp_OCTETS_std_collations

extern const t_ibp_char* const g_ibp_SJIS_0208_std_collations[]
 ={IBP_T("SJIS_0208"),
   NULL}; //g_ibp_SJIS_0208_std_collations

extern const t_ibp_char* const g_ibp_TIS620_std_collations[]
 ={IBP_T("TIS620"),
   IBP_T("TIS620_UNICODE"),
   NULL}; //g_ibp_TIS620_std_collations

extern const t_ibp_char* const g_ibp_UNICODE_BE_std_collations[]
 ={IBP_T("UNICODE_BE"),
   NULL}; //g_ibp_UNICODE_BE_std_collations

extern const t_ibp_char* const g_ibp_UNICODE_FSS_std_collations[]
 ={IBP_T("UNICODE_FSS"),
   NULL}; //g_ibp_UNICODE_FSS_std_collations

extern const t_ibp_char* const g_ibp_UNICODE_LE_std_collations[]
 ={IBP_T("UNICODE_LE"),
   NULL}; //g_ibp_UNICODE_LE_std_collations

extern const t_ibp_char* const g_ibp_UTF8_std_collations[]
 ={IBP_T("UCS_BASIC"),
   IBP_T("UNICODE"),
   IBP_T("UNICODE_CI"),
   IBP_T("UNICODE_CI_AI"),
   IBP_T("UTF8"),
   NULL}; //g_ibp_UTF8_std_collations

extern const t_ibp_char* const g_ibp_WIN1250_std_collations[]
 ={IBP_T("BS_BA"),
   IBP_T("PXW_CSY"),
   IBP_T("PXW_HUN"),
   IBP_T("PXW_HUNDC"),
   IBP_T("PXW_PLK"),
   IBP_T("PXW_SLOV"),
   IBP_T("WIN1250"),
   IBP_T("WIN_CZ"),
   IBP_T("WIN_CZ_CI_AI"),
   NULL}; //g_ibp_WIN1250_std_collations

extern const t_ibp_char* const g_ibp_WIN1251_std_collations[]
 ={IBP_T("PXW_CYRL"),
   IBP_T("WIN1251"),
   IBP_T("WIN1251_UA"),
   NULL}; //g_ibp_WIN1251_std_collations

extern const t_ibp_char* const g_ibp_WIN1252_std_collations[]
 ={IBP_T("CC_ESPWIN"),
   IBP_T("CC_PTBRWIN"),
   IBP_T("PXW_INTL"),
   IBP_T("PXW_INTL850"),
   IBP_T("PXW_NORDAN4"),
   IBP_T("PXW_SPAN"),
   IBP_T("PXW_SWEDFIN"),
   IBP_T("WIN1252"),
   IBP_T("WIN_PTBR"),
   NULL}; //g_ibp_WIN1252_std_collations

extern const t_ibp_char* const g_ibp_WIN1253_std_collations[]
 ={IBP_T("PXW_GREEK"),
   IBP_T("WIN1253"),
   NULL}; //g_ibp_WIN1253_std_collations

extern const t_ibp_char* const g_ibp_WIN1254_std_collations[]
 ={IBP_T("PXW_TURK"),
   IBP_T("WIN1254"),
   NULL}; //g_ibp_WIN1254_std_collations

extern const t_ibp_char* const g_ibp_WIN1255_std_collations[]
 ={IBP_T("WIN1255"),
   NULL}; //g_ibp_WIN1255_std_collations

extern const t_ibp_char* const g_ibp_WIN1256_std_collations[]
 ={IBP_T("WIN1256"),
   NULL}; //g_ibp_WIN1256_std_collations

extern const t_ibp_char* const g_ibp_WIN1257_std_collations[]
 ={IBP_T("WIN1257"),
   IBP_T("WIN1257_EE"),
   IBP_T("WIN1257_LT"),
   IBP_T("WIN1257_LV"),
   NULL}; //g_ibp_WIN1257_std_collations

extern const t_ibp_char* const g_ibp_WIN1258_std_collations[]
 ={IBP_T("WIN1258"),
   NULL}; //g_ibp_WIN1258_std_collations

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
