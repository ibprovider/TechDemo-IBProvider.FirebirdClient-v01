////////////////////////////////////////////////////////////////////////////////
//Structures for work with UTF8 charset.
//                                                Kovalenko Dmitry. 20.07.2011.
#ifndef _structure_charsets_t_cs_utf8_H_
#define _structure_charsets_t_cs_utf8_H_

#include <lcpi/lib/.config.h>

namespace structure{namespace charsets{namespace cs_utf8{
////////////////////////////////////////////////////////////////////////////////
//struct traits

struct traits
{
 public:
  typedef unsigned char                     UTF8;
  typedef wchar_t                           UCS2;
  typedef unsigned long                     UCS4;

 public:
                                                     //        hh hhhh hhhh
  static const UCS4 c_SURROGATE_HIGH_START  =0xD800; // 1101 1000|0000 0000
  static const UCS4 c_SURROGATE_HIGH_END    =0xDBFF; // 1101 1011|1111 1111
  
                                                     //        ll llll llll
  static const UCS4 c_SURROGATE_LOW_START   =0xDC00; // 1101 1100|0000 0000
  static const UCS4 c_SURROGATE_LOW_END     =0xDFFF; // 1101 1111|1111 1111

  // 0x0FFFFF = hhhh hhhh hhll llll llll

  static const UCS4 c_HALF_SHIFT            =10;
  static const UCS4 c_HALF_MASK             =0x03FF; // 0000 0011|1111 1111
  static const UCS4 c_SURROGATE_BASE        =0x010000;
  static const UCS4 c_SURROGATE_END         =0x10FFFF;

  static const UCS4 c_SURROGATE_OFFSET      =(c_SURROGATE_HIGH_START<<c_HALF_SHIFT)
                                             +c_SURROGATE_LOW_START
                                             -c_SURROGATE_BASE;

  static const UCS4 c_MAXIMUM_UCS2          =0x0000FFFF;
  static const UCS4 c_MAXIMUM_UTF           =0x0010FFFF;
  static const UCS4 c_MAXIMUM_UCS4          =0x7FFFFFFF;

 public:
  static bool is_surrogate(UCS4 const wc)
  {
   return (wc&0xFFFFF800)==0xD800;
  }//is_surrogate

  //[c_SURROGATE_HIGH_START ... c_SURROGATE_HIGH_END]
  static bool is_surrogate_ch1(UCS4 const wc)
  {
   return ((wc)&0xFFFFFC00)==0xD800;
  }//is_surrogate_ch1

  //[c_SURROGATE_LOW_START ... c_SURROGATE_LOW_END]
  static bool is_surrogate_ch2(UCS4 const wc)
  {
   return (wc&0xFFFFFC00)==0xDC00;
  }//is_surrogate_ch2
};//struct traits

////////////////////////////////////////////////////////////////////////////////
//Enumerate of result code

enum tag_cs_cvt_result
{
 cs_cvt_result__ok                =0,
 cs_cvt_result__bad_input         =1,
 cs_cvt_result__trunc_input       =2,
 cs_cvt_result__small_output      =3,
 cs_cvt_result__bad_input_packing =4,
};//enum tag_cs_cvt_result

typedef tag_cs_cvt_result t_cs_cvt_result;

////////////////////////////////////////////////////////////////////////////////
//single ucs2-->utf8 convertor

template<class TForwardIterator>
TForwardIterator single_ucs2_to_utf8(TForwardIterator        source_beg,
                                     TForwardIterator        source_end,
                                     unsigned char*          utf8,
                                     /*in-out*/size_t&       sz_utf8,
                                     /*out*/t_cs_cvt_result* cvt_result);

//------------------------------------------------------------------------
template<class TForwardIterator>
TForwardIterator single_ucs2_to_utf8(TForwardIterator        source_beg,
                                     TForwardIterator        source_end,
                                     signed char*            utf8,
                                     /*in-out*/size_t&       sz_utf8,
                                     /*out*/t_cs_cvt_result* cvt_result);

//------------------------------------------------------------------------
template<class TForwardIterator>
TForwardIterator single_ucs2_to_utf8(TForwardIterator        source_beg,
                                     TForwardIterator        source_end,
                                     char*                   utf8,
                                     /*in-out*/size_t&       sz_utf8,
                                     /*out*/t_cs_cvt_result* cvt_result);

////////////////////////////////////////////////////////////////////////////////
//single utf8-->ucs2 convertor

template<class TForwardIterator>
TForwardIterator single_utf8_to_ucs2(TForwardIterator        source_beg,
                                     TForwardIterator        source_end,
                                     traits::UCS2*           ucs2,
                                     /*in-out*/size_t&       sz_ucs2,
                                     /*out*/t_cs_cvt_result* cvt_result);

////////////////////////////////////////////////////////////////////////////////
//char sequential ucs2-->utf8 converter

template<class TForwardIterator,class TDestIterator>
TForwardIterator ucs2_to_utf8(TForwardIterator        source_beg,
                              TForwardIterator        source_end,
                              TDestIterator           dest,
                              /*out*/t_cs_cvt_result* cvt_result);

////////////////////////////////////////////////////////////////////////////////
//char sequential utf8-->ucs2 converter

template<class TForwardIterator,class TDestIterator>
TForwardIterator utf8_to_ucs2(TForwardIterator        source_beg,
                              TForwardIterator        source_end,
                              TDestIterator           dest,
                              /*out*/t_cs_cvt_result* cvt_result);

////////////////////////////////////////////////////////////////////////////////
}/*nms cs_utf8*/}/*charsets*/}/*nms structure*/
////////////////////////////////////////////////////////////////////////////////
#include "structure/charsets/t_cs_utf8.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
