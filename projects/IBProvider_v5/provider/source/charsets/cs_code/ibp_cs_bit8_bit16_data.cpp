////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_bit8_bit16_data.cpp
//! \brief   ƒанные дл€ преобразовани€ кодовых страниц BIT8-BIT16
//! \author  Kovalenko Dmitry
//! \date    28.09.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/ibp_cs_bit8_bit16_data.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

namespace cs_data_BIG_5{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_big5.h"

////////////////////////////////////////////////////////////////////////////////
static bool IsSingleChSymbol(const t_ibp_cs_bit8_bit16_traits::uchar_type x)
{
 return (x&0x80)==0;
}//IsSingleChSymbol

//------------------------------------------------------------------------
static bool IsValidCh_1(const t_ibp_cs_bit8_bit16_traits::uchar_type x)
{
 typedef t_ibp_cs_bit8_bit16_traits::uchar_type uchar_type;

 return uchar_type(x&0xff)>=0xA1 && uchar_type(x&0xff)<=0xFE;
}//IsValidCh_1

//------------------------------------------------------------------------
static bool IsValidCh_2(const t_ibp_cs_bit8_bit16_traits::uchar_type x)
{
 typedef t_ibp_cs_bit8_bit16_traits::uchar_type uchar_type;

 return uchar_type(x&0xff)>=0x40 && uchar_type(x&0xff)<=0xFE;
}//IsValidCh_2

////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_BIG_5

namespace cs_data_GB_2312{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_gb2312.h"

////////////////////////////////////////////////////////////////////////////////
static bool IsSingleChSymbol(const t_ibp_cs_bit8_bit16_traits::uchar_type x)
{
 return (x&0x80)==0;
}//IsSingleChSymbol

//------------------------------------------------------------------------
static bool IsValidCh_1(const t_ibp_cs_bit8_bit16_traits::uchar_type x)
{
 typedef t_ibp_cs_bit8_bit16_traits::uchar_type uchar_type;

 return uchar_type(x&0xff)>=0xA1 && uchar_type(x&0xff)<=0xFE;
}//IsValidCh_1

//------------------------------------------------------------------------
static bool IsValidCh_2(const t_ibp_cs_bit8_bit16_traits::uchar_type x)
{
 typedef t_ibp_cs_bit8_bit16_traits::uchar_type uchar_type;

 return uchar_type(x&0xff)>=0xA1 && uchar_type(x&0xff)<=0xFE;
}//IsValidCh_2

////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_GB_2312

namespace cs_data_KSC_5601{
////////////////////////////////////////////////////////////////////////////////
#include "source/charsets/data/cs_ksc5601.h"

////////////////////////////////////////////////////////////////////////////////
static bool IsSingleChSymbol(const t_ibp_cs_bit8_bit16_traits::uchar_type x)
{
 return (x&0x80)==0;
}//IsSingleChSymbol

//------------------------------------------------------------------------
static bool IsValidCh_1(const t_ibp_cs_bit8_bit16_traits::uchar_type x)
{
 typedef t_ibp_cs_bit8_bit16_traits::uchar_type uchar_type;

 return (x&0x80)!=0;
}//IsValidCh_1

//------------------------------------------------------------------------
static bool IsValidCh_2(const t_ibp_cs_bit8_bit16_traits::uchar_type x)
{
 typedef t_ibp_cs_bit8_bit16_traits::uchar_type uchar_type;

 return uchar_type(x&0xff)>=0x41;
}//IsValidCh_2

////////////////////////////////////////////////////////////////////////////////
}//namespace cs_data_KSC_5601

////////////////////////////////////////////////////////////////////////////////

#define DEF_CS_MAP(CS_NAME)                                              \
extern const t_ibp_cs_bit8_bit16_traits g_ibp_cs_map_##CS_NAME           \
(                                                                        \
 cs_data_##CS_NAME::to_unicode_mapping_array,                            \
 _DIM_(cs_data_##CS_NAME::to_unicode_mapping_array),                     \
                                                                         \
 cs_data_##CS_NAME::to_unicode_map,                                      \
 _DIM_(cs_data_##CS_NAME::to_unicode_map),                               \
                                                                         \
 cs_data_##CS_NAME::from_unicode_mapping_array,                          \
 _DIM_(cs_data_##CS_NAME::from_unicode_mapping_array),                   \
                                                                         \
 cs_data_##CS_NAME::from_unicode_map,                                    \
 _DIM_(cs_data_##CS_NAME::from_unicode_map),                             \
                                                                         \
 cs_data_##CS_NAME::IsSingleChSymbol,                                    \
                                                                         \
 cs_data_##CS_NAME::IsValidCh_1,                                         \
 cs_data_##CS_NAME::IsValidCh_2                                          \
)

////////////////////////////////////////////////////////////////////////////////

DEF_CS_MAP(BIG_5);
DEF_CS_MAP(GB_2312);
DEF_CS_MAP(KSC_5601);

////////////////////////////////////////////////////////////////////////////////

#undef DEF_CS_MAP

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
