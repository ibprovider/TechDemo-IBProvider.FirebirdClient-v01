////////////////////////////////////////////////////////////////////////////////
//Structures for work with UTF16-charset.
//                                                 Kovalenko Dmitry. 10.03.2023.
#ifndef _structure_charsets_t_cs_utf16_H_
#define _structure_charsets_t_cs_utf16_H_

#include <lcpi/lib/.config.h>

namespace structure{namespace charsets{namespace cs_utf16{
////////////////////////////////////////////////////////////////////////////////
//struct traits

struct traits
{
 public:
  using UTF16=unsigned __int16;

  static const unsigned c_SURROGATE_HIGH_START  =0xD800; // 1101 1000|0000 0000
  static const unsigned c_SURROGATE_HIGH_END    =0xDBFF; // 1101 1011|1111 1111

  static const unsigned c_SURROGATE_LOW_START   =0xDC00; // 1101 1100|0000 0000
  static const unsigned c_SURROGATE_LOW_END     =0xDFFF; // 1101 1111|1111 1111
};//struct traits

////////////////////////////////////////////////////////////////////////////////
//The enumeration of result code

enum tag_cs_cvt_result
{
 cs_cvt_result__ok                =0,
 cs_cvt_result__bad_input         =1,
 cs_cvt_result__trunc_input       =2,
 //cs_cvt_result__small_output      =3,
 //cs_cvt_result__bad_input_packing =4,

 cs_cvt_result__overflow          =5,
};//enum tag_cs_cvt_result

typedef tag_cs_cvt_result t_cs_cvt_result;

////////////////////////////////////////////////////////////////////////////////

inline bool is_surrogate_high(traits::UTF16 ch);

inline bool is_surrogate_low(traits::UTF16 ch);

////////////////////////////////////////////////////////////////////////////////

template<class TForwardIterator>
std::pair<TForwardIterator,t_cs_cvt_result>
 get_next_symbol(TForwardIterator source_beg,
                 TForwardIterator source_end);

////////////////////////////////////////////////////////////////////////////////

template<class TForwardIterator>
std::pair<size_t,t_cs_cvt_result>
 calc_symbol_count(TForwardIterator source_beg,
                   TForwardIterator source_end,
                   size_t           max_length);

//------------------------------------------------------------------------
template<class TForwardIterator>
std::pair<size_t,t_cs_cvt_result>
 calc_symbol_count(TForwardIterator source_beg,
                   TForwardIterator source_end);

////////////////////////////////////////////////////////////////////////////////
}/*nms cs_utf16*/}/*charsets*/}/*nms structure*/
////////////////////////////////////////////////////////////////////////////////
#include "structure/charsets/t_cs_utf16.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
