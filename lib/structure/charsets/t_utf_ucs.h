////////////////////////////////////////////////////////////////////////////////
//Утилиты конвертирования UTF <--> UCS кодировок
// Содрано с www.unicode.org/public/programs/cvtutf
//                                       Коваленко Дмитрий. 3 апреля 2002 года.

#ifndef _structure_charsets_t_utf_ucs_H_
#define _structure_charsets_t_utf_ucs_H_

#include <structure/t_common.h>

namespace structure{namespace charsets{
////////////////////////////////////////////////////////////////////////////////
//struct t_utf8_traits

struct t_utf8_traits
{
 public: //typedefs ------------------------------------------------------
  typedef unsigned long               UCS4;
  typedef unsigned short              UCS2;
  typedef unsigned char               UTF8;

 public: //consts --------------------------------------------------------
  static const UCS4 byteMask              = 0xBF;
  static const UCS4 byteMark              = 0x80;
  //static const int  halfShift             = 10;
  //static const UCS4 halfBase              = 0x0010000UL;
  //static const UCS4 halfMask              = 0x3FFUL;
  //static const UCS4 kSurrogateHighStart   = 0xD800UL;
  //static const UCS4 kSurrogateHighEnd     = 0xDBFFUL;
  //static const UCS4 kSurrogateLowStart    = 0xDC00UL;
  //static const UCS4 kSurrogateLowEnd      = 0xDFFFUL;
  //static const UCS4 kMaximumUCS2          = 0x0000FFFFUL;
  //static const UCS4 kMaximumUCS4          = 0x7FFFFFFFUL;
  //static const UCS4 kReplacementCharacter = 0x0000FFFDUL;

 public:
  struct tag_utf8_ucs_map
  {
   UTF8   cmask;  //mask of first byte mark
   UTF8   cval;   //first byte mark
   int    shift;
   UCS4   lmask;  //mask of ucs value
   UCS4   lval;   //min value of ucs
  };//tag_utf8_ucs_map

  static const tag_utf8_ucs_map sm_utf8_ucs_map[7];
};//struct t_utf8_traits

////////////////////////////////////////////////////////////////////////////////

enum tag_cs_cvt_result
{
 cs_cvt_result__ok          =0,
 cs_cvt_result__bad_input   =1,
 cs_cvt_result__trunc_input =2,
 cs_cvt_result__small_output=3,
};

typedef tag_cs_cvt_result t_cs_cvt_result;

////////////////////////////////////////////////////////////////////////////////
//single ucs2<-->utf8 convertor

template<class TForwardIterator>
TForwardIterator __single_ucs2_to_utf8(TForwardIterator        source_beg,
                                       TForwardIterator        source_end,
                                       t_utf8_traits::UTF8*    utf8,
                                       /*in-out*/size_t&       sz_utf8,
                                       /*out*/t_cs_cvt_result* cvt_result);

//------------------------------------------------------------------------
template<class TForwardIterator>
TForwardIterator __single_utf8_to_ucs2(TForwardIterator        source_beg,
                                       TForwardIterator        source_end,
                                       t_utf8_traits::UCS2*    ucs2,
                                       /*in-out*/size_t&       sz_ucs2,
                                       /*out*/t_cs_cvt_result* cvt_result);

////////////////////////////////////////////////////////////////////////////////

template<class TForwardIterator>
TForwardIterator single_ucs2_to_utf8(TForwardIterator        source_beg,
                                     TForwardIterator        source_end,
                                     char*                   utf8,
                                     /*in-out*/size_t&       sz_utf8,
                                     /*out*/t_cs_cvt_result* cvt_result);

//------------------------------------------------------------------------
template<class TForwardIterator>
TForwardIterator single_utf8_to_ucs2(TForwardIterator        source_beg,
                                     TForwardIterator        source_end,
                                     wchar_t*                ucs2,
                                     /*in-out*/size_t&       sz_ucs2,
                                     /*out*/t_cs_cvt_result* cvt_result);

////////////////////////////////////////////////////////////////////////////////
//char sequential ucs2<-->utf8 converter

template<class TForwardIterator,class TDestIterator>
TForwardIterator ucs2_to_utf8(TForwardIterator        source_beg,
                              TForwardIterator        source_end,
                              TDestIterator           dest,
                              /*out*/t_cs_cvt_result* cvt_result);

template<class TForwardIterator,class TDestIterator>
TForwardIterator utf8_to_ucs2(TForwardIterator        source_beg,
                              TForwardIterator        source_end,
                              TDestIterator           dest,
                              /*out*/t_cs_cvt_result* cvt_result);

////////////////////////////////////////////////////////////////////////////////
}/*nms charsets*/}//nms structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/charsets/t_utf_ucs.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
