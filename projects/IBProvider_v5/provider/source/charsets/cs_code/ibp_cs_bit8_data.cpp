////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_bit8_data.cpp
//! \brief   ������ ��� �������������� ������� ������� BIT8
//! \author  Kovalenko Dmitry
//! \date    27.09.2005
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/ibp_cs_bit8_data.h"
#include "source/charsets/ibp_charset_const.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//����������� ������ ��������������

const int CANT_MAP_CHARACTER=IBP_CS_BIT8_CANT_MAP_CHARACTER;

////////////////////////////////////////////////////////////////////////////////

namespace cs_data_DOS437{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_437.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_DOS437

//--------------------------------------------------------------------------
namespace cs_data_DOS737{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_737.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_DOS737

//--------------------------------------------------------------------------
namespace cs_data_DOS775{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_775.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_DOS775

//--------------------------------------------------------------------------
namespace cs_data_DOS850{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_850.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_DOS850

//--------------------------------------------------------------------------
namespace cs_data_DOS852{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_852.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_DOS852

//--------------------------------------------------------------------------
namespace cs_data_DOS857{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_857.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_DOS857

//--------------------------------------------------------------------------
namespace cs_data_DOS858{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_858.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_DOS858

//--------------------------------------------------------------------------
namespace cs_data_DOS860{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_860.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_DOS860

//--------------------------------------------------------------------------
namespace cs_data_DOS861{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_861.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_DOS861

//--------------------------------------------------------------------------
namespace cs_data_DOS862{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_862.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_DOS862

//--------------------------------------------------------------------------
namespace cs_data_DOS863{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_863.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_DOS863

//--------------------------------------------------------------------------
namespace cs_data_DOS864{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_864.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_DOS864

//--------------------------------------------------------------------------
namespace cs_data_DOS865{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_865.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_DOS865

//--------------------------------------------------------------------------
namespace cs_data_DOS866{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_866.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_DOS866

//--------------------------------------------------------------------------
namespace cs_data_DOS869{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_869.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_DOS869

//--------------------------------------------------------------------------
namespace cs_data_WIN1250{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_w1250.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_WIN1250

//--------------------------------------------------------------------------
namespace cs_data_WIN1251{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_w1251.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_WIN1251

//--------------------------------------------------------------------------
namespace cs_data_WIN1252{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_w1252.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_WIN1252

//--------------------------------------------------------------------------
namespace cs_data_WIN1253{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_w1253.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_WIN1253

//--------------------------------------------------------------------------
namespace cs_data_WIN1254{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_w1254.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_WIN1254

//--------------------------------------------------------------------------
namespace cs_data_WIN1255{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_w1255.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_WIN1255

//--------------------------------------------------------------------------
namespace cs_data_WIN1256{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_w1256.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_WIN1256

//--------------------------------------------------------------------------
namespace cs_data_WIN1257{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_w1257.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_WIN1257

//--------------------------------------------------------------------------
namespace cs_data_WIN1258{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_w1258.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_WIN1258

//--------------------------------------------------------------------------
namespace cs_data_NEXT{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_next.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_NEXT

//--------------------------------------------------------------------------
namespace cs_data_ISO8859_1{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_iso8859_1.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_ISO8859_1

//--------------------------------------------------------------------------
namespace cs_data_ISO8859_2{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_iso8859_2.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_ISO8859_2

//--------------------------------------------------------------------------
namespace cs_data_ISO8859_3{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_iso8859_3.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_ISO8859_3

//--------------------------------------------------------------------------
namespace cs_data_ISO8859_4{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_iso8859_4.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_ISO8859_4

//--------------------------------------------------------------------------
namespace cs_data_ISO8859_5{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_iso8859_5.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_ISO8859_5

//--------------------------------------------------------------------------
namespace cs_data_ISO8859_6{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_iso8859_6.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_ISO8859_6

//--------------------------------------------------------------------------
namespace cs_data_ISO8859_7{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_iso8859_7.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_ISO8859_7

//--------------------------------------------------------------------------
namespace cs_data_ISO8859_8{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_iso8859_8.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_ISO8859_8

//--------------------------------------------------------------------------
namespace cs_data_ISO8859_9{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_iso8859_9.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_ISO8859_9

//--------------------------------------------------------------------------
namespace cs_data_ISO8859_13{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_iso8859_13.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_ISO8859_13

//--------------------------------------------------------------------------
namespace cs_data_ISO8859_15{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_iso8859_15.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_ISO8859_15

//--------------------------------------------------------------------------
namespace cs_data_KOI8R{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_koi8r.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_KOI8R

//--------------------------------------------------------------------------
namespace cs_data_KOI8U{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_koi8u.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_KOI8U

//--------------------------------------------------------------------------
namespace cs_data_TIS620{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_tis620.h"
////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_TIS620

////////////////////////////////////////////////////////////////////////////////
//����������� ������ ��������������

#define DEF_CS_MAP(cs_name)                                         \
 const t_ibp_cs_bit8_map g_ibp_cs_map_##cs_name=                    \
  {&cs_data_##cs_name::to_unicode_map,                              \
    cs_data_##cs_name::from_unicode_mapping_array,                  \
   _DIM_(cs_data_##cs_name::from_unicode_mapping_array),            \
   &cs_data_##cs_name::from_unicode_map}

//------------------------------------------------------------------------
DEF_CS_MAP(DOS437);
DEF_CS_MAP(DOS737);
DEF_CS_MAP(DOS775);
DEF_CS_MAP(DOS850);
DEF_CS_MAP(DOS852);
DEF_CS_MAP(DOS857);
DEF_CS_MAP(DOS858);
DEF_CS_MAP(DOS860);
DEF_CS_MAP(DOS861);
DEF_CS_MAP(DOS862);
DEF_CS_MAP(DOS863);
DEF_CS_MAP(DOS864);
DEF_CS_MAP(DOS865);
DEF_CS_MAP(DOS866);
DEF_CS_MAP(DOS869);

DEF_CS_MAP(WIN1250);
DEF_CS_MAP(WIN1251);
DEF_CS_MAP(WIN1252);
DEF_CS_MAP(WIN1253);
DEF_CS_MAP(WIN1254);
DEF_CS_MAP(WIN1255);
DEF_CS_MAP(WIN1256);
DEF_CS_MAP(WIN1257);
DEF_CS_MAP(WIN1258);

DEF_CS_MAP(NEXT);

DEF_CS_MAP(ISO8859_1);
DEF_CS_MAP(ISO8859_2);
DEF_CS_MAP(ISO8859_3);
DEF_CS_MAP(ISO8859_4);
DEF_CS_MAP(ISO8859_5);
DEF_CS_MAP(ISO8859_6);
DEF_CS_MAP(ISO8859_7);
DEF_CS_MAP(ISO8859_8);
DEF_CS_MAP(ISO8859_9);
DEF_CS_MAP(ISO8859_13);
DEF_CS_MAP(ISO8859_15);

DEF_CS_MAP(KOI8R);
DEF_CS_MAP(KOI8U);

DEF_CS_MAP(TIS620);

//------------------------------------------------------------------------
#undef DEF_CS_MAP

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
