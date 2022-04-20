////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <structure/charsets/t_utf_ucs.h>

namespace structure{namespace charsets{
////////////////////////////////////////////////////////////////////////////////
//struct t_utf8_traits

/*
* Bits  Hex Min  Hex Max  Byte Sequence in Binary
*   7  00000000 0000007F 0vvvvvvv
*  11  00000080 000007FF 110vvvvv 10vvvvvv
*  16  00000800 0000FFFF 1110vvvv 10vvvvvv 10vvvvvv
*  21  00010000 001FFFFF 11110vvv 10vvvvvv 10vvvvvv 10vvvvvv
*  26  00200000 03FFFFFF 111110vv 10vvvvvv 10vvvvvv 10vvvvvv 10vvvvvv
*  31  04000000 7FFFFFFF 1111110v 10vvvvvv 10vvvvvv 10vvvvvv 10vvvvvv 10vvvvvv
*/

const t_utf8_traits::tag_utf8_ucs_map t_utf8_traits::sm_utf8_ucs_map[7]=
{//cmask    cval         lmask       lval
 { 0x00,    0x00, 0 * 0, 0x00      , 0x0         },
 { 0x80,    0x00, 0 * 6, 0x7F      , 0x0         }, /* 1 byte sequence */
 { 0xE0,    0xC0, 1 * 6, 0x7FF     , 0x80        }, /* 2 byte sequence */
 { 0xF0,    0xE0, 2 * 6, 0xFFFF    , 0x800       }, /* 3 byte sequence */
 { 0xF8,    0xF0, 3 * 6, 0x1FFFFF  , 0x10000     }, /* 4 byte sequence */
 { 0xFC,    0xF8, 4 * 6, 0x3FFFFFF , 0x200000    }, /* 5 byte sequence */
 { 0xFE,    0xFC, 5 * 6, 0x7FFFFFFF, 0x4000000   }, /* 6 byte sequence */
};//t_utf8_traits::sm_utf8_ucs_map

////////////////////////////////////////////////////////////////////////////////
}/*nms charsets*/}//namespace structure


