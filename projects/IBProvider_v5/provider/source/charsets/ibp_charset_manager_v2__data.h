////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_charset_manager_v2__data.h
//! \brief   Определение таблиц с данными для t_ibp_charset_manager_v2
//! \author  Kovalenko Dmitry
//! \date    18.11.2010
#ifndef _ibp_charset_manager_v2__data_H_
#define _ibp_charset_manager_v2__data_H_

#include "source/charsets/ibp_charset_manager_v2__helper.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

#define DECLARE_IBP_CP_INFO(name)                                         \
 extern const t_ibp_charset_manager_v2::tag_own_cs                        \
  g_ibp_own_cp_info_##name

////////////////////////////////////////////////////////////////////////////////

DECLARE_IBP_CP_INFO(ASCII);

DECLARE_IBP_CP_INFO(BASE64);

DECLARE_IBP_CP_INFO(CYRL);

DECLARE_IBP_CP_INFO(NONE);

DECLARE_IBP_CP_INFO(OCTETS);

DECLARE_IBP_CP_INFO(UNICODE_FSS);

DECLARE_IBP_CP_INFO(UTF8);

DECLARE_IBP_CP_INFO(DOS437);

DECLARE_IBP_CP_INFO(DOS737);

DECLARE_IBP_CP_INFO(DOS775);

DECLARE_IBP_CP_INFO(DOS850);

DECLARE_IBP_CP_INFO(DOS852);

DECLARE_IBP_CP_INFO(DOS857);

DECLARE_IBP_CP_INFO(DOS858);

DECLARE_IBP_CP_INFO(DOS860);

DECLARE_IBP_CP_INFO(DOS861);

DECLARE_IBP_CP_INFO(DOS862);

DECLARE_IBP_CP_INFO(DOS863);

DECLARE_IBP_CP_INFO(DOS864);

DECLARE_IBP_CP_INFO(DOS865);

DECLARE_IBP_CP_INFO(DOS866);

DECLARE_IBP_CP_INFO(DOS869);

DECLARE_IBP_CP_INFO(ISO8859_1);

DECLARE_IBP_CP_INFO(ISO8859_13);

DECLARE_IBP_CP_INFO(ISO8859_15);

DECLARE_IBP_CP_INFO(ISO8859_2);

DECLARE_IBP_CP_INFO(ISO8859_3);

DECLARE_IBP_CP_INFO(ISO8859_4);

DECLARE_IBP_CP_INFO(ISO8859_5);

DECLARE_IBP_CP_INFO(ISO8859_6);

DECLARE_IBP_CP_INFO(ISO8859_7);

DECLARE_IBP_CP_INFO(ISO8859_8);

DECLARE_IBP_CP_INFO(ISO8859_9);

DECLARE_IBP_CP_INFO(WIN1250);

DECLARE_IBP_CP_INFO(WIN1251);

DECLARE_IBP_CP_INFO(WIN1252);

DECLARE_IBP_CP_INFO(WIN1253);

DECLARE_IBP_CP_INFO(WIN1254);

DECLARE_IBP_CP_INFO(WIN1255);

DECLARE_IBP_CP_INFO(WIN1256);

DECLARE_IBP_CP_INFO(WIN1257);

DECLARE_IBP_CP_INFO(WIN1258);

DECLARE_IBP_CP_INFO(NEXT);

DECLARE_IBP_CP_INFO(KOI8R);

DECLARE_IBP_CP_INFO(KOI8U);

DECLARE_IBP_CP_INFO(TIS620);

DECLARE_IBP_CP_INFO(BIG_5);

DECLARE_IBP_CP_INFO(GB_2312);

DECLARE_IBP_CP_INFO(KSC_5601);

DECLARE_IBP_CP_INFO(EUCJ_0208);

DECLARE_IBP_CP_INFO(SJIS_0208);

DECLARE_IBP_CP_INFO(CP943C);

DECLARE_IBP_CP_INFO(GBK);

DECLARE_IBP_CP_INFO(GB18030);

////////////////////////////////////////////////////////////////////////////////
#undef DECLARE_IBP_CP_INFO
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
