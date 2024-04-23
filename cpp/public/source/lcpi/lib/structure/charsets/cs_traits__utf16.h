////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 29.03.2024.
#ifndef _cpp_public_lcpi_lib_structure__cs_traits__utf16_H_
#define _cpp_public_lcpi_lib_structure__cs_traits__utf16_H_

#include <lcpi/lib/.config.h>
#include <cstdint>

namespace lcpi{namespace lib{namespace structure{namespace charsets{
////////////////////////////////////////////////////////////////////////////////
//class cs_traits__utf16

class cs_traits__utf16 LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  using UTF16=std::uint16_t;

  static const unsigned c_SURROGATE_HIGH_START  =0xD800; // 1101 1000|0000 0000
  static const unsigned c_SURROGATE_HIGH_END    =0xDBFF; // 1101 1011|1111 1111

  static const unsigned c_SURROGATE_LOW_START   =0xDC00; // 1101 1100|0000 0000
  static const unsigned c_SURROGATE_LOW_END     =0xDFFF; // 1101 1111|1111 1111

  // 0x0FFFFF = hhhh hhhh hhll llll llll

  static const std::uint32_t c_HALF_SHIFT       =10;
  static const std::uint32_t c_HALF_MASK        =0x03FF; // 0000 0011|1111 1111
  static const std::uint32_t c_SURROGATE_BASE   =0x010000;
  static const std::uint32_t c_SURROGATE_END    =0x10FFFF;

  static const std::uint32_t c_SURROGATE_OFFSET
   =(c_SURROGATE_HIGH_START<<c_HALF_SHIFT)+c_SURROGATE_LOW_START-c_SURROGATE_BASE;

  static const std::uint32_t c_MAXIMUM_UTF      =0x0010FFFF;

 public:
  static bool is_surrogate(std::uint32_t const wc)
  {
   return (wc&0xFFFFF800)==0xD800;
  }//is_surrogate

  //[c_SURROGATE_HIGH_START ... c_SURROGATE_HIGH_END]
  static bool is_surrogate_ch1(std::uint32_t const wc)
  {
   return ((wc)&0xFFFFFC00)==0xD800;
  }//is_surrogate_ch1

  //[c_SURROGATE_LOW_START ... c_SURROGATE_LOW_END]
  static bool is_surrogate_ch2(std::uint32_t const wc)
  {
   return (wc&0xFFFFFC00)==0xDC00;
  }//is_surrogate_ch2
};//class cs_traits__utf16

////////////////////////////////////////////////////////////////////////////////
}/*nms charsets*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
