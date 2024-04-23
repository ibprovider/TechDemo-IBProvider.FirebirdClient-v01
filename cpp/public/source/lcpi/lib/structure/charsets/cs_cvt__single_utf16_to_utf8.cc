////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 01.04.2024.
#ifndef _cpp_public_lcpi_lib_structure__cs_cvt__single_utf16_to_utf8_CC_
#define _cpp_public_lcpi_lib_structure__cs_cvt__single_utf16_to_utf8_CC_

#include <lcpi/lib/structure/charsets/cs_traits__utf8.h>
#include <lcpi/lib/structure/charsets/cs_traits__utf16.h>
#include <lcpi/lib/structure/charsets/cs_cvt_result.h>

#include <type_traits>

////////////////////////////////////////////////////////////////////////////////

/*
* Bits  Hex Min  Hex Max  Byte Sequence in Binary
*   7  00000000 0000007F 0vvvvvvv
*  11  00000080 000007FF 110vvvvv 10vvvvvv
*  16  00000800 0000FFFF 1110vvvv 10vvvvvv 10vvvvvv
*  21  00010000 001FFFFF 11110vvv 10vvvvvv 10vvvvvv 10vvvvvv
*  26  00200000 03FFFFFF 111110vv 10vvvvvv 10vvvvvv 10vvvvvv 10vvvvvv
*  31  04000000 7FFFFFFF 1111110v 10vvvvvv 10vvvvvv 10vvvvvv 10vvvvvv 10vvvvvv
*
*  UTF8-symbols have up to 4 bytes.
*/

namespace lcpi{namespace lib{namespace structure{namespace charsets{
////////////////////////////////////////////////////////////////////////////////
//cs_cvt__single_utf16_to_utf8

#define OUT_UTF8_CH(value)                             \
{                                                      \
 if(target_beg==target_end)                            \
 {                                                     \
  return detail::make_cs_cvt_result                    \
   (cs_cvt_result_code::small_output,                  \
    source_beg,                                        \
    target_beg);                                       \
 }                                                     \
                                                       \
 using target_item_type                                \
  =typename std::iterator_traits<ForwardOutputIterator>::value_type; \
                                                       \
 (*target_beg)=static_cast<target_item_type>(value);   \
                                                       \
 ++target_beg;                                         \
}

//------------------------------------------------------------------------
template<class ForwardInputIterator,class ForwardOutputIterator>
cs_cvt_result<ForwardInputIterator,ForwardOutputIterator>
 cs_cvt__single_utf16_to_utf8
  (ForwardInputIterator  source_beg,
   ForwardInputIterator  source_end,
   ForwardOutputIterator target_beg,
   ForwardOutputIterator target_end)
{
 using UTF8=cs_traits__utf8::UTF8;

 LCPI__assert_s(sizeof(UTF8)==1);

 LCPI__assert_s(std::is_unsigned<UTF8>::value);

 //-----------------------------------------
 using source_item_type_x
  =typename std::iterator_traits<ForwardInputIterator>::value_type;

 using source_item_type
  =typename std::make_unsigned<source_item_type_x>::type;

 //consts ----------------------------------
 const std::uint32_t c_byteMask = 0xBF; //1011 1111
 const std::uint32_t c_byteMark = 0x80; //1000 0000

 //-----------------------------------------
 if(source_beg==source_end) //empty input
 {
  return detail::make_cs_cvt_result
           (cs_cvt_result_code::ok,
            source_beg,
            target_beg);
 }//if

 //-----------------------------------------
 auto wc1
  =static_cast<source_item_type>(*source_beg);

 if(wc1<0x0080)
 {
  //  1 byte sequence
  //
  //* Bits  Hex Min  Hex Max  Byte Sequence in Binary
  //*   7  00000000 0000007F 0vvvvvvv

  ++source_beg;

  //------------ install OUT parameters
  OUT_UTF8_CH(static_cast<UTF8>(wc1));

  //----------------------------------------
  return detail::make_cs_cvt_result
   (cs_cvt_result_code::ok,
    source_beg,
    target_beg);
 }//if wc1<0x0080

 LCPI__assert(!(wc1<0x0080));

 //-----------------------------------------------------------------------
 if(wc1<0x0800)
 {
  //  2 bytes sequence
  //
  //* Bits  Hex Min  Hex Max  Byte Sequence in Binary
  //*  11  00000080 000007FF 110vvvvv 10vvvvvv

  ++source_beg;

  //------------ install OUT parameters

  const auto rch1=static_cast<UTF8>((wc1 | c_byteMark) & c_byteMask);

  wc1>>=6;

  LCPI__assert(wc1<=0x1F);

  const auto rch0=static_cast<UTF8>(wc1 | 0xC0);

  //----------------------------------------
  OUT_UTF8_CH(rch0);
  OUT_UTF8_CH(rch1);

  return detail::make_cs_cvt_result
   (cs_cvt_result_code::ok,
    source_beg,
    target_beg);
 }//if wc<0x0800

 LCPI__assert(!(wc1<0x0800));

 //-----------------------------------------------------------------------
 if(wc1<0x010000)
 {
  //  3 or 4 bytes sequence
  //
  //* Bits  Hex Min  Hex Max  Byte Sequence in Binary
  //*  16  00000800 0000FFFF 1110vvvv 10vvvvvv 10vvvvvv
  //*  21  00010000 001FFFFF 11110vvv 10vvvvvv 10vvvvvv 10vvvvvv

  if(!cs_traits__utf16::is_surrogate(static_cast<std::uint32_t>(wc1)))
  {
   //  3 bytes sequence
   //
   //* Bits  Hex Min  Hex Max  Byte Sequence in Binary
   //*  16  00000800 0000FFFF 1110vvvv 10vvvvvv 10vvvvvv

   ++source_beg;

   //------------ install OUT parameters
   const auto rch2=static_cast<UTF8>((wc1 | c_byteMark) & c_byteMask);

   wc1>>=6;

   const auto rch1=static_cast<UTF8>((wc1 | c_byteMark) & c_byteMask);

   wc1>>=6;

   LCPI__assert(wc1<=0x0F);

   const auto rch0=static_cast<UTF8>(wc1 | 0xE0);

   //---------------------------------------
   OUT_UTF8_CH(rch0);
   OUT_UTF8_CH(rch1);
   OUT_UTF8_CH(rch2);

   return detail::make_cs_cvt_result
    (cs_cvt_result_code::ok,
     source_beg,
     target_beg);
  }//if !cs_traits__utf16::is_surrogate(wc1)

  LCPI__assert_hint(cs_traits__utf16::is_surrogate(static_cast<std::uint32_t>(wc1)));

  //----------------------------------------------------------------------
  //  4 byte sequence
  //
  //* Bits  Hex Min  Hex Max  Byte Sequence in Binary
  //*  21  00010000 001FFFFF 11110vvv 10vvvvvv 10vvvvvv 10vvvvvv

  if(!cs_traits__utf16::is_surrogate_ch1(static_cast<std::uint32_t>(wc1)))
  {
   return detail::make_cs_cvt_result
    (cs_cvt_result_code::bad_input,
     source_beg,
     target_beg);
  }//if !is_surrogate_ch1

  LCPI__assert(wc1>=cs_traits__utf16::c_SURROGATE_HIGH_START);
  LCPI__assert(wc1<=cs_traits__utf16::c_SURROGATE_HIGH_END);

  ++source_beg;

  //----------------------------------------
  if(source_beg==source_end)
  {
   return detail::make_cs_cvt_result
    (cs_cvt_result_code::trunc_input,
     source_beg,
     target_beg);
  }//if

  const auto wc2
   =static_cast<source_item_type>(*source_beg);

  if(!(wc2<0x010000))
  {
   return detail::make_cs_cvt_result
    (cs_cvt_result_code::bad_input,
     source_beg,
     target_beg);
  }//if wc2 is not UTF16

  LCPI__assert_hint(wc2<0x010000);

  if(!cs_traits__utf16::is_surrogate_ch2(static_cast<std::uint32_t>(wc2)))
  {
   return detail::make_cs_cvt_result
    (cs_cvt_result_code::bad_input,
     source_beg,
     target_beg);
  }//if !is_surrogate_ch2

  LCPI__assert(wc2>=cs_traits__utf16::c_SURROGATE_LOW_START);
  LCPI__assert(wc2<=cs_traits__utf16::c_SURROGATE_LOW_END);

  ++source_beg;

  //----------------------------------------
  std::uint32_t wc=static_cast<std::uint32_t>(wc1);

  wc<<=cs_traits__utf16::c_HALF_SHIFT;

  wc+=static_cast<std::uint32_t>(wc2);

  wc-=cs_traits__utf16::c_SURROGATE_OFFSET;

  //----------------------------------------
  LCPI__assert(wc>=cs_traits__utf16::c_SURROGATE_BASE);
  LCPI__assert(wc<=cs_traits__utf16::c_SURROGATE_END);

  LCPI__assert_s(cs_traits__utf16::c_SURROGATE_BASE ==0x00010000);
  LCPI__assert_s(cs_traits__utf16::c_SURROGATE_END  ==0x0010FFFF);

  //------------ install OUT parameters
  const auto rch3=static_cast<UTF8>((wc | c_byteMark) & c_byteMask);

  wc>>=6;

  const auto rch2=static_cast<UTF8>((wc | c_byteMark) & c_byteMask);

  wc>>=6;

  const auto rch1=static_cast<UTF8>((wc | c_byteMark) & c_byteMask);

  wc>>=6;

  LCPI__assert(wc<=0x07);

  const auto rch0=static_cast<UTF8>(wc | 0xF0);

  //----------------------------------------
  OUT_UTF8_CH(rch0);
  OUT_UTF8_CH(rch1);
  OUT_UTF8_CH(rch2);
  OUT_UTF8_CH(rch3);

  return detail::make_cs_cvt_result
   (cs_cvt_result_code::ok,
    source_beg,
    target_beg);
 }//if wc<0x010000

 return detail::make_cs_cvt_result
  (cs_cvt_result_code::bad_input,
   source_beg,
   target_beg);
}//cs_cvt__single_utf16_to_utf8

//------------------------------------------------------------------------
#undef OUT_UTF8_CH

////////////////////////////////////////////////////////////////////////////////
}/*nms charsets*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
