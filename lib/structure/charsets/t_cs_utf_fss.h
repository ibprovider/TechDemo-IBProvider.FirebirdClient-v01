////////////////////////////////////////////////////////////////////////////////
//Structures for work with UTF_FSS [UNICODE_FSS] charset
//                                                Kovalenko Dmitry. 20.07.2011.

#ifndef _structure_charsets_t_cs_utf_fss_H_
#define _structure_charsets_t_cs_utf_fss_H_

#include <structure/t_common.h>

namespace structure{namespace charsets{namespace cs_utf_fss{
////////////////////////////////////////////////////////////////////////////////
//struct t_traits

struct traits
{
 public: //typedefs ------------------------------------------------------
  typedef wchar_t                     UCS2;
  typedef unsigned char               UTF_FSS;
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
//single ucs2<-->utf_fss convertor

template<class TForwardIterator>
TForwardIterator single_ucs2_to_fss(TForwardIterator        source_beg,
                                    TForwardIterator        source_end,
                                    unsigned char*          utf_fss,
                                    /*in-out*/size_t&       sz_utf_fss,
                                    /*out*/t_cs_cvt_result* cvt_result);

//------------------------------------------------------------------------
template<class TForwardIterator>
TForwardIterator single_ucs2_to_fss(TForwardIterator        source_beg,
                                    TForwardIterator        source_end,
                                    signed char*            utf_fss,
                                    /*in-out*/size_t&       sz_utf_fss,
                                    /*out*/t_cs_cvt_result* cvt_result);

//------------------------------------------------------------------------
template<class TForwardIterator>
TForwardIterator single_ucs2_to_fss(TForwardIterator        source_beg,
                                    TForwardIterator        source_end,
                                    char*                   utf_fss,
                                    /*in-out*/size_t&       sz_utf_fss,
                                    /*out*/t_cs_cvt_result* cvt_result);

//------------------------------------------------------------------------
template<class TForwardIterator>
TForwardIterator single_fss_to_ucs2(TForwardIterator        source_beg,
                                    TForwardIterator        source_end,
                                    traits::UCS2*           ucs2,
                                    /*in-out*/size_t&       sz_ucs2,
                                    /*out*/t_cs_cvt_result* cvt_result);

////////////////////////////////////////////////////////////////////////////////
//char sequential ucs2<-->utf8 converter

template<class TForwardIterator,class TDestIterator>
TForwardIterator ucs2_to_fss(TForwardIterator         source_beg,
                              TForwardIterator        source_end,
                              TDestIterator           dest,
                              /*out*/t_cs_cvt_result* cvt_result);

//------------------------------------------------------------------------
template<class TForwardIterator,class TDestIterator>
TForwardIterator fss_to_ucs2(TForwardIterator        source_beg,
                             TForwardIterator        source_end,
                             TDestIterator           dest,
                             /*out*/t_cs_cvt_result* cvt_result);

////////////////////////////////////////////////////////////////////////////////
}/*nms cs_utf_fss*/}/*nms charsets*/}/*nms structure*/
////////////////////////////////////////////////////////////////////////////////
#include <structure/charsets/t_cs_utf_fss.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
