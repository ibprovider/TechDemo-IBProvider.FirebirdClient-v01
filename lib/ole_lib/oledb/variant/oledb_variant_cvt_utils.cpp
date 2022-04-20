////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/variant/oledb_variant_cvt_utils.h>
#include <ole_lib/oledb/variant/oledb_variant_cvt.h>
#include <ole_lib/oledb/variant/oledb_xvariant_stream_writer.h>
#include <ole_lib/ole_auto/ole_auto_safe_array.h>
#include <structure/t_deque_adapter.h>
#include <structure/t_numeric_cast.h>
#include <structure/t_negative_one.h>
#include <structure/t_first_last.h>
#include <structure/t_zero.h>

#include <array>
#include <float.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class DBVARIANT_CVT_UTILS

const DBVARIANT_CVT_UTILS::size_type
 DBVARIANT_CVT_UTILS::npos=structure::t_negative_one();

////////////////////////////////////////////////////////////////////////////////
//struct DBVARIANT_CVT_UTILS::tag_power_2

struct DBVARIANT_CVT_UTILS::tag_power_2
{
 public:
  typedef size_t size_type;

 public:
  size_type  m_size;
  BYTE       m_digits[64];

  size_type size()const
   {return m_size;}

  const BYTE operator [] (size_type const i)const
   {
    assert(size()<=_DIM_(m_digits));
    assert(i<size());

    return m_digits[i];
   }
};//struct DBVARIANT_CVT_UTILS::tag_power_2

////////////////////////////////////////////////////////////////////////////////
//struct DBVARIANT_CVT_UTILS::tag_data

struct DBVARIANT_CVT_UTILS::tag_data
{
 public:
  static const double sm_DblPow10_Neg[];
  static const double sm_DblPow10[];

  static const float  sm_FltPow10[];

  static const tag_power_2 sm_power_2_map[];

  static const signed __int64 sm_min_cy_int64;
  static const signed __int64 sm_max_cy_int64;
};//tag_data

////////////////////////////////////////////////////////////////////////////////
//struct DBVARIANT_CVT_UTILS::tag_float_parts_in_str

template<class charT>
RELEASE_CODE(inline)
DBVARIANT_CVT_UTILS::tag_float_parts_in_str<charT>::tag_float_parts_in_str()
{
 this->init();
}//tag_float_parts_in_str

//------------------------------------------------------------------------
template<class charT>
RELEASE_CODE(inline)
void DBVARIANT_CVT_UTILS::tag_float_parts_in_str<charT>::init()
{
 this->mantisse_sign  = sign_kind__undefined;
 this->int_part_beg   = nullptr;
 this->int_part_end   = nullptr;
 this->float_part_beg = nullptr;
 this->float_part_end = nullptr;
 this->scale_sign     = sign_kind__undefined;
 this->scale_part_beg = nullptr;
 this->scale_part_end = nullptr;
}//init

////////////////////////////////////////////////////////////////////////////////

const DBVARIANT_CVT_UTILS::tag_power_2 DBVARIANT_CVT_UTILS::tag_data::sm_power_2_map[]=
{
 {1,{1}},
 #include <ole_lib/oledb/variant/converter_utils/oledb_variant_power_2_map.dat>
};//sm_power_2_map

////////////////////////////////////////////////////////////////////////////////

const double DBVARIANT_CVT_UTILS::tag_data::sm_DblPow10_Neg[]=
{
 1E-0  ,1E-1  ,1E-2  ,1E-3  ,1E-4  ,1E-5  ,1E-6  ,1E-7  ,1E-8  ,1E-9  ,
 1E-10 ,1E-11 ,1E-12 ,1E-13 ,1E-14 ,1E-15 ,1E-16 ,1E-17 ,1E-18 ,1E-19 ,
 1E-20 ,1E-21 ,1E-22 ,1E-23 ,1E-24 ,1E-25 ,1E-26 ,1E-27 ,1E-28 ,1E-29 ,
 1E-30 ,1E-31 ,1E-32 ,1E-33 ,1E-34 ,1E-35 ,1E-36 ,1E-37 ,1E-38 ,1E-39 ,
 1E-40 ,1E-41 ,1E-42 ,1E-43 ,1E-44 ,1E-45 ,1E-46 ,1E-47 ,1E-48 ,1E-49 ,
 1E-50 ,1E-51 ,1E-52 ,1E-53 ,1E-54 ,1E-55 ,1E-56 ,1E-57 ,1E-58 ,1E-59 ,
 1E-60 ,1E-61 ,1E-62 ,1E-63 ,1E-64 ,1E-65 ,1E-66 ,1E-67 ,1E-68 ,1E-69 ,
 1E-70 ,1E-71 ,1E-72 ,1E-73 ,1E-74 ,1E-75 ,1E-76 ,1E-77 ,1E-78 ,1E-79 ,
 1E-80 ,1E-81 ,1E-82 ,1E-83 ,1E-84 ,1E-85 ,1E-86 ,1E-87 ,1E-88 ,1E-89 ,
 1E-90 ,1E-91 ,1E-92 ,1E-93 ,1E-94 ,1E-95 ,1E-96 ,1E-97 ,1E-98 ,1E-99 ,
 1E-100,1E-101,1E-102,1E-103,1E-104,1E-105,1E-106,1E-107,1E-108,1E-109,
 1E-110,1E-111,1E-112,1E-113,1E-114,1E-115,1E-116,1E-117,1E-118,1E-119,
 1E-120,1E-121,1E-122,1E-123,1E-124,1E-125,1E-126,1E-127,1E-128,1E-129,
 1E-130,1E-131,1E-132,1E-133,1E-134,1E-135,1E-136,1E-137,1E-138,1E-139,
 1E-140,1E-141,1E-142,1E-143,1E-144,1E-145,1E-146,1E-147,1E-148,1E-149,
 1E-150,1E-151,1E-152,1E-153,1E-154,1E-155,1E-156,1E-157,1E-158,1E-159,
 1E-160,1E-161,1E-162,1E-163,1E-164,1E-165,1E-166,1E-167,1E-168,1E-169,
 1E-170,1E-171,1E-172,1E-173,1E-174,1E-175,1E-176,1E-177,1E-178,1E-179,
 1E-180,1E-181,1E-182,1E-183,1E-184,1E-185,1E-186,1E-187,1E-188,1E-189,
 1E-190,1E-191,1E-192,1E-193,1E-194,1E-195,1E-196,1E-197,1E-198,1E-199,
 1E-200,1E-201,1E-202,1E-203,1E-204,1E-205,1E-206,1E-207,1E-208,1E-209,
 1E-210,1E-211,1E-212,1E-213,1E-214,1E-215,1E-216,1E-217,1E-218,1E-219,
 1E-220,1E-221,1E-222,1E-223,1E-224,1E-225,1E-226,1E-227,1E-228,1E-229,
 1E-230,1E-231,1E-232,1E-233,1E-234,1E-235,1E-236,1E-237,1E-238,1E-239,
 1E-240,1E-241,1E-242,1E-243,1E-244,1E-245,1E-246,1E-247,1E-248,1E-249,
 1E-250,1E-251,1E-252,1E-253,1E-254,1E-255,1E-256,1E-257,1E-258,1E-259,
 1E-260,1E-261,1E-262,1E-263,1E-264,1E-265,1E-266,1E-267,1E-268,1E-269,
 1E-270,1E-271,1E-272,1E-273,1E-274,1E-275,1E-276,1E-277,1E-278,1E-279,
 1E-280,1E-281,1E-282,1E-283,1E-284,1E-285,1E-286,1E-287,1E-288,1E-289,
 1E-290,1E-291,1E-292,1E-293,1E-294,1E-295,1E-296,1E-297,1E-298,1E-299,
 1E-300,1E-301,1E-302,1E-303,1E-304,1E-305,1E-306,1E-307,1E-308
};//tag_data::sm_DblPow10_Neg

//------------------------------------------------------------------------------
const double DBVARIANT_CVT_UTILS::tag_data::sm_DblPow10[]=
{
 1E+0  ,1E+1  ,1E+2  ,1E+3  ,1E+4  ,1E+5  ,1E+6  ,1E+7  ,1E+8  ,1E+9  ,
 1E+10 ,1E+11 ,1E+12 ,1E+13 ,1E+14 ,1E+15 ,1E+16 ,1E+17 ,1E+18 ,1E+19 ,
 1E+20 ,1E+21 ,1E+22 ,1E+23 ,1E+24 ,1E+25 ,1E+26 ,1E+27 ,1E+28 ,1E+29 ,
 1E+30 ,1E+31 ,1E+32 ,1E+33 ,1E+34 ,1E+35 ,1E+36 ,1E+37 ,1E+38 ,1E+39 ,
 1E+40 ,1E+41 ,1E+42 ,1E+43 ,1E+44 ,1E+45 ,1E+46 ,1E+47 ,1E+48 ,1E+49 ,
 1E+50 ,1E+51 ,1E+52 ,1E+53 ,1E+54 ,1E+55 ,1E+56 ,1E+57 ,1E+58 ,1E+59 ,
 1E+60 ,1E+61 ,1E+62 ,1E+63 ,1E+64 ,1E+65 ,1E+66 ,1E+67 ,1E+68 ,1E+69 ,
 1E+70 ,1E+71 ,1E+72 ,1E+73 ,1E+74 ,1E+75 ,1E+76 ,1E+77 ,1E+78 ,1E+79 ,
 1E+80 ,1E+81 ,1E+82 ,1E+83 ,1E+84 ,1E+85 ,1E+86 ,1E+87 ,1E+88 ,1E+89 ,
 1E+90 ,1E+91 ,1E+92 ,1E+93 ,1E+94 ,1E+95 ,1E+96 ,1E+97 ,1E+98 ,1E+99 ,
 1E+100,1E+101,1E+102,1E+103,1E+104,1E+105,1E+106,1E+107,1E+108,1E+109,
 1E+110,1E+111,1E+112,1E+113,1E+114,1E+115,1E+116,1E+117,1E+118,1E+119,
 1E+120,1E+121,1E+122,1E+123,1E+124,1E+125,1E+126,1E+127,1E+128,1E+129,
 1E+130,1E+131,1E+132,1E+133,1E+134,1E+135,1E+136,1E+137,1E+138,1E+139,
 1E+140,1E+141,1E+142,1E+143,1E+144,1E+145,1E+146,1E+147,1E+148,1E+149,
 1E+150,1E+151,1E+152,1E+153,1E+154,1E+155,1E+156,1E+157,1E+158,1E+159,
 1E+160,1E+161,1E+162,1E+163,1E+164,1E+165,1E+166,1E+167,1E+168,1E+169,
 1E+170,1E+171,1E+172,1E+173,1E+174,1E+175,1E+176,1E+177,1E+178,1E+179,
 1E+180,1E+181,1E+182,1E+183,1E+184,1E+185,1E+186,1E+187,1E+188,1E+189,
 1E+190,1E+191,1E+192,1E+193,1E+194,1E+195,1E+196,1E+197,1E+198,1E+199,
 1E+200,1E+201,1E+202,1E+203,1E+204,1E+205,1E+206,1E+207,1E+208,1E+209,
 1E+210,1E+211,1E+212,1E+213,1E+214,1E+215,1E+216,1E+217,1E+218,1E+219,
 1E+220,1E+221,1E+222,1E+223,1E+224,1E+225,1E+226,1E+227,1E+228,1E+229,
 1E+230,1E+231,1E+232,1E+233,1E+234,1E+235,1E+236,1E+237,1E+238,1E+239,
 1E+240,1E+241,1E+242,1E+243,1E+244,1E+245,1E+246,1E+247,1E+248,1E+249,
 1E+250,1E+251,1E+252,1E+253,1E+254,1E+255,1E+256,1E+257,1E+258,1E+259,
 1E+260,1E+261,1E+262,1E+263,1E+264,1E+265,1E+266,1E+267,1E+268,1E+269,
 1E+270,1E+271,1E+272,1E+273,1E+274,1E+275,1E+276,1E+277,1E+278,1E+279,
 1E+280,1E+281,1E+282,1E+283,1E+284,1E+285,1E+286,1E+287,1E+288,1E+289,
 1E+290,1E+291,1E+292,1E+293,1E+294,1E+295,1E+296,1E+297,1E+298,1E+299,
 1E+300,1E+301,1E+302,1E+303,1E+304,1E+305,1E+306,1E+307,1E+308
};//tag_data::sm_DblPow10

//------------------------------------------------------------------------------
const float DBVARIANT_CVT_UTILS::tag_data::sm_FltPow10[]=
{
 1E+0F  ,1E+1F  ,1E+2F  ,1E+3F  ,1E+4F  ,1E+5F  ,1E+6F  ,1E+7F  ,1E+8F  ,1E+9F  ,
 1E+10F ,1E+11F ,1E+12F ,1E+13F ,1E+14F ,1E+15F ,1E+16F ,1E+17F ,1E+18F ,1E+19F ,
 1E+20F ,1E+21F ,1E+22F ,1E+23F ,1E+24F ,1E+25F ,1E+26F ,1E+27F ,1E+28F ,1E+29F ,
 1E+30F ,1E+31F ,1E+32F ,1E+33F ,1E+34F ,1E+35F ,1E+36F ,1E+37F ,1E+38F
};//sm_FltPow10

////////////////////////////////////////////////////////////////////////////////

#include <ole_lib/oledb/variant/converter_utils/oledb_var_cvt_utils.cxx>
#include <ole_lib/oledb/variant/converter_utils/oledb_var_cvt_utils__bstr.cxx>
#include <ole_lib/oledb/variant/converter_utils/oledb_var_cvt_utils__guid.cxx>
#include <ole_lib/oledb/variant/converter_utils/oledb_var_cvt_utils__bytes.cxx>
#include <ole_lib/oledb/variant/converter_utils/oledb_var_cvt_utils__iunknown.cxx>
#include <ole_lib/oledb/variant/converter_utils/oledb_var_cvt_utils__numeric.cxx>
#include <ole_lib/oledb/variant/converter_utils/oledb_var_cvt_utils__decimal.cxx>
#include <ole_lib/oledb/variant/converter_utils/oledb_var_cvt_utils__cy.cxx>
#include <ole_lib/oledb/variant/converter_utils/oledb_var_cvt_utils__r8.cxx>

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
