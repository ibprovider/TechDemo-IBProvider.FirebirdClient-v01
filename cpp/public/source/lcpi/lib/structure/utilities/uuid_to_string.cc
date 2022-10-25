////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 27.09.2022.
#ifndef _cpp_public_lcpi_lib_structure_utilities__uuid_to_string_CC_
#define _cpp_public_lcpi_lib_structure_utilities__uuid_to_string_CC_

#include <lcpi/lib/structure/t_char_traits2.h>
#include <lcpi/lib/structure/debug/assert_s.h>
#include <lcpi/lib/common_utilities.h>

#include <iterator> //std::iterator_traits
#include <type_traits>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<typename OutputIterator>
OutputIterator uuid_to_string(REFGUID uuid,OutputIterator dest)
{
 //123456789012345678901234567890123456  36
 //xxXXxxXX-xxXX-xxXX-xxXX-xxXXxxXXxxXX

 //-----------------------------------------
 typedef typename std::iterator_traits<OutputIterator>::value_type   char_type;

 typedef structure::t_char_traits2<char_type>                        char_traits2;

 //-----------------------------------------
#define PUSH_CH(ch)                                                       \
 {                                                                        \
  (*dest)=(ch);                                                           \
                                                                          \
  ++dest;                                                                 \
 }

#define PUSH_HEX(x)                                                       \
 {                                                                        \
  PUSH_CH(char_traits2::to_hex(unsigned(x)));                             \
 }

#define PUSH_BYTE_AS_HEX(b)                                               \
 {                                                                        \
  const unsigned char b1=static_cast<unsigned char>(b);                   \
                                                                          \
  PUSH_HEX(b1>>4)                                                         \
  PUSH_HEX(0x0F&(b1))                                                     \
 }

 //-----------------------------------------
 PUSH_BYTE_AS_HEX(uuid.Data1>>24)           //2 3
 PUSH_BYTE_AS_HEX(uuid.Data1>>16)           //4 5
 PUSH_BYTE_AS_HEX(uuid.Data1>>8)            //6 7
 PUSH_BYTE_AS_HEX(uuid.Data1)               //8 9
 PUSH_CH(char_traits2::ch_minus())          //10
 PUSH_BYTE_AS_HEX(uuid.Data2>>8)            //11 12
 PUSH_BYTE_AS_HEX(uuid.Data2)               //13 14
 PUSH_CH(char_traits2::ch_minus())          //15
 PUSH_BYTE_AS_HEX(uuid.Data3>>8)            //16 17
 PUSH_BYTE_AS_HEX(uuid.Data3)               //18 19
 PUSH_CH(char_traits2::ch_minus())          //20
 PUSH_BYTE_AS_HEX(uuid.Data4[0])            //21 22
 PUSH_BYTE_AS_HEX(uuid.Data4[1])            //23 24
 PUSH_CH(char_traits2::ch_minus())          //25
 PUSH_BYTE_AS_HEX(uuid.Data4[2])            //26 27
 PUSH_BYTE_AS_HEX(uuid.Data4[3])            //28 29
 PUSH_BYTE_AS_HEX(uuid.Data4[4])            //30 31
 PUSH_BYTE_AS_HEX(uuid.Data4[5])            //32 33
 PUSH_BYTE_AS_HEX(uuid.Data4[6])            //34 35
 PUSH_BYTE_AS_HEX(uuid.Data4[7])            //36 37

//------------------------------------------
#undef PUSH_BYTE_AS_HEX
#undef PUSH_HEX
#undef PUSH_CH

 return dest;
}//uuid_to_string

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif //_cpp_public_lcpi_lib_structure_utilities__uuid_to_string_CC_
