////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 29.03.2024.
#ifndef _cpp_public_lcpi_lib_structure__cs_cvt__single_utf8_to_utf16_CC_
#define _cpp_public_lcpi_lib_structure__cs_cvt__single_utf8_to_utf16_CC_

#include <lcpi/lib/structure/charsets/cs_traits__utf8.h>
#include <lcpi/lib/structure/charsets/cs_traits__utf16.h>
#include <lcpi/lib/structure/charsets/cs_cvt_result.h>

#include <type_traits>

namespace lcpi{namespace lib{namespace structure{namespace charsets{
////////////////////////////////////////////////////////////////////////////////
//cs_cvt__single_utf8_to_utf16

#define GET_UTF8_CH2(ch_utf8)                          \
 if(source_beg==source_end)                            \
 {                                                     \
  return detail::make_cs_cvt_result                    \
          (cs_cvt_result_code::trunc_input,            \
           source_beg,                                 \
           target_beg);                                \
 }                                                     \
                                                       \
 source_item_type ch_utf8                              \
  =static_cast<source_item_type>(*source_beg);         \
                                                       \
 if((ch_utf8>>6)!=2)                                   \
 {                                                     \
  return detail::make_cs_cvt_result                    \
          (cs_cvt_result_code::bad_input,              \
           source_beg,                                 \
           target_beg);                                \
 }                                                     \
                                                       \
 ch_utf8=(ch_utf8&0x3F);                               \
                                                       \
 LCPI__assert(ch_utf8<=0x3F);                          \
                                                       \
 ++source_beg;

//------------------------------------------------------------------------

#define OUT_UTF16_CH(value)                            \
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
 cs_cvt__single_utf8_to_utf16
  (ForwardInputIterator        source_beg,
   ForwardInputIterator  const source_end,
   ForwardOutputIterator       target_beg,
   ForwardOutputIterator const target_end)
{
 using UTF16=cs_traits__utf16::UTF16;

 LCPI__assert_s(sizeof(UTF16)==2);

 LCPI__assert_s(std::is_unsigned<UTF16>::value);

 //-----------------------------------------
 using source_item_type_x
  =typename std::iterator_traits<ForwardInputIterator>::value_type;

 using source_item_type
  =typename std::make_unsigned<source_item_type_x>::type;

 LCPI__assert_s(sizeof(source_item_type)==sizeof(source_item_type_x));

 LCPI__assert_s(std::is_unsigned<source_item_type>::value);

 //-----------------------------------------
 if(source_beg==source_end) //empty input
 {
  return detail::make_cs_cvt_result
           (cs_cvt_result_code::ok,
            source_beg,
            target_beg);
 }//if

 //-----------------------------------------
 //
 //1   7bits   0xxxxxxx                              0x000000 ... 0x00007F
 //2   11bits  110xxxxx 10xxxxxx                     0x000080 ... 0x0007FF
 //3   16bits  1110xxxx 10xxxxxx 10xxxxxx            0x000800 ... 0x00FFFF
 //4   21bits  11110xxx 10xxxxxx 10xxxxxx 10xxxxxx   0x010000 ... 0x10FFFF (c_MAXIMUM_UTF)
 //
 //-----------------------------------------

 //Let's remember the first byte of UTF8 sequence
 const source_item_type c0
  =static_cast<source_item_type>(*source_beg);

 //----------------------------------------- 1 byte
 //
 //1  0xxxxxxx
 //

 if((c0>>7)==0x00)
 {
  //1 byte sequence
  ++source_beg;

  //There is no need to check the packaging for correctness!

  //------------ install OUT parameters

  LCPI__assert(!cs_traits__utf16::is_surrogate(static_cast<UTF16>(c0)));

  OUT_UTF16_CH(static_cast<UTF16>(c0))

  //----------------------------------------
  return detail::make_cs_cvt_result
   (cs_cvt_result_code::ok,
    source_beg,
    target_beg);
 }//if 1 byte sequence

 //----------------------------------------- 2 bytes
 //
 //2  110xxxxx 10xxxxxx
 //

 if((c0>>5)==0x06)
 {
  ++source_beg;

  GET_UTF8_CH2(c1)

  //------------ build
  UTF16 l=static_cast<UTF16>(c0&0x1F);

  l=static_cast<UTF16>((l<<6)+static_cast<UTF16>(c1));

  //the resulting number should not be less than the 0x80 (check that the packaging is correct)
  if(l<0x80)
  {
   return detail::make_cs_cvt_result
    (cs_cvt_result_code::bad_input_packing,
     source_beg,
     target_beg);
  }//if

  //------------ install OUT parameters

  LCPI__assert(!cs_traits__utf16::is_surrogate(l));

  OUT_UTF16_CH(l)

  //----------------------------------------
  return detail::make_cs_cvt_result
   (cs_cvt_result_code::ok,
    source_beg,
    target_beg);
 }//2 byte sequence

 //----------------------------------------- 3 bytes
 //
 //3  1110xxxx 10xxxxxx 10xxxxxx
 //

 if((c0>>4)==0x0E)
 {
  //3 byte sequence
  ++source_beg;

  GET_UTF8_CH2(c1)
  GET_UTF8_CH2(c2)

  //------------ build
  UTF16 l=(c0&0x0F);

  l=static_cast<UTF16>((l<<6)+static_cast<UTF16>(c1));
  l=static_cast<UTF16>((l<<6)+static_cast<UTF16>(c2));

  //the resulting number should not be less than the 0x800 (check that the packaging is correct)
  if(l<0x800)
  {
   return detail::make_cs_cvt_result
    (cs_cvt_result_code::bad_input_packing,
     source_beg,
     target_beg);
  }//if

  //the created number must not be a surrogate
  if(cs_traits__utf16::is_surrogate(l))
  {
   return detail::make_cs_cvt_result
    (cs_cvt_result_code::bad_input,
     source_beg,
     target_beg);
  }//if

  //------------ install OUT parameters

  OUT_UTF16_CH(l)

  //----------------------------------------
  return detail::make_cs_cvt_result
   (cs_cvt_result_code::ok,
    source_beg,
    target_beg);
 }//3 byte sequence

 //----------------------------------------- 4 bytes
 //
 //4   21bits  11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 //

 if((c0>>3)==0x1E)
 {
  //4 byte sequential
  ++source_beg;

  GET_UTF8_CH2(c1)
  GET_UTF8_CH2(c2)
  GET_UTF8_CH2(c3)

  //------------ build
  std::uint32_t l=(c0&0x07);

  l=static_cast<std::uint32_t>((l<<6)+static_cast<std::uint32_t>(c1));
  l=static_cast<std::uint32_t>((l<<6)+static_cast<std::uint32_t>(c2));
  l=static_cast<std::uint32_t>((l<<6)+static_cast<std::uint32_t>(c3));

  //the resulting number should not be less than the 0x10000 (check that the packaging is correct)

  LCPI__assert_s(0x10000==cs_traits__utf16::c_SURROGATE_BASE);

  if(l<0x10000)
  {
   return detail::make_cs_cvt_result
    (cs_cvt_result_code::bad_input_packing,
     source_beg,
     target_beg);
  }//if

  if(cs_traits__utf16::c_MAXIMUM_UTF<l)
  {
   return detail::make_cs_cvt_result
    (cs_cvt_result_code::bad_input,
     source_beg,
     target_beg);
  }//if

  //here is calculated an output value
  LCPI__assert(cs_traits__utf16::c_SURROGATE_BASE<=l);

  l-=cs_traits__utf16::c_SURROGATE_BASE;

  const auto rch0=static_cast<UTF16>((l >> cs_traits__utf16::c_HALF_SHIFT) + cs_traits__utf16::c_SURROGATE_HIGH_START);

  LCPI__assert(rch0>=cs_traits__utf16::c_SURROGATE_HIGH_START);
  LCPI__assert(rch0<=cs_traits__utf16::c_SURROGATE_HIGH_END);

  const auto rch1=static_cast<UTF16>((l & cs_traits__utf16::c_HALF_MASK) + cs_traits__utf16::c_SURROGATE_LOW_START);

  LCPI__assert(rch1>=cs_traits__utf16::c_SURROGATE_LOW_START);
  LCPI__assert(rch1<=cs_traits__utf16::c_SURROGATE_LOW_END);

  //------------ install OUT parameters

  OUT_UTF16_CH(rch0)

  OUT_UTF16_CH(rch1)

  //----------------------------------------
  return detail::make_cs_cvt_result
   (cs_cvt_result_code::ok,
    source_beg,
    target_beg);
 }//4 byte sequence

 //-----------------------------------------------------------------------
 return detail::make_cs_cvt_result
  (cs_cvt_result_code::bad_input,
   source_beg,
   target_beg);
}//cs_cvt__single_utf8_to_utf16

//------------------------------------------------------------------------
#undef OUT_UTF16_CH
#undef GET_UTF8_CH2

////////////////////////////////////////////////////////////////////////////////
}/*nms charsets*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
