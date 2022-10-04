////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 21.01.2002.
#ifndef _cpp_public_lcpi_lib_structure__t_char_traits2_CC_
#define _cpp_public_lcpi_lib_structure__t_char_traits2_CC_

#include <lcpi/lib/structure/debug/assert.h>

#include <lcpi/lib/structure/t_negative_one.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//specialization t_char_traits2<char>

inline
 bool t_char_traits2<char>::is_alpha(char_type const c)
{
 if(c>=self_type::ch_letter_A() && c<=self_type::ch_letter_Z())
  return true;

 if(c>=self_type::ch_letter_a() && c<=self_type::ch_letter_z())
  return true;

 return false;
}//is_alpha

//------------------------------------------------------------------------
inline
 bool t_char_traits2<char>::is_alnum(char_type const c)
{
 if(self_type::is_alpha(c))
  return true;

 if(self_type::is_digit(c))
  return true;

 return false;
}//is_alnum

//------------------------------------------------------------------------
inline
t_char_traits2<char>::char_type
t_char_traits2<char>::to_hex_u(byte_type const x)
{
 LCPI__assert(x<16);

 return "0123456789ABCDEF"[x];
}//to_hex_u

//------------------------------------------------------------------------
inline
t_char_traits2<char>::char_type
t_char_traits2<char>::to_hex_l(byte_type const x)
{
 LCPI__assert(x<16);

 return "0123456789abcdef"[x];
}//to_hex_l

//------------------------------------------------------------------------
inline
t_char_traits2<char>::char_type
t_char_traits2<char>::to_hex(byte_type const x,bool const upper)
{
 if(upper)
  return to_hex_u(x);

 return to_hex_l(x);
}//to_hex

//------------------------------------------------------------------------
inline bool t_char_traits2<char>::is_hex(char_type const c)
{
 return (c>='0' && c<='9') ||
        (c>='a' && c<='f') ||
        (c>='A' && c<='F');
}//is_hex

//------------------------------------------------------------------------
inline t_char_traits2<char>::byte_type
 t_char_traits2<char>::from_hex(char_type const c)
{
 if(c>='0' && c<='9')
  return byte_type(c-'0');

 if(c>='a' && c<='f')
  return byte_type(c-'a'+10);

 if(c>='A' && c<='F')
  return byte_type(c-'A'+10);

 return structure::negative_one;
}//from_hex

//------------------------------------------------------------------------
inline bool t_char_traits2<char>::is_digit(char_type const c)
{
 return (c>='0' && c<='9');
}//is_digit

//------------------------------------------------------------------------
inline t_char_traits2<char>::byte_type
 t_char_traits2<char>::from_dec(char_type const c)
{
 if(c>='0' && c<='9')
  return byte_type(c-'0');

 return structure::negative_one;
}//from_dec

////////////////////////////////////////////////////////////////////////////////
//specialization t_char_traits2<wchar_t>

inline
 bool t_char_traits2<wchar_t>::is_alpha(char_type const c)
{
 if(c>=self_type::ch_letter_A() && c<=self_type::ch_letter_Z())
  return true;

 if(c>=self_type::ch_letter_a() && c<=self_type::ch_letter_z())
  return true;

 return false;
}//is_alpha

//------------------------------------------------------------------------
inline
 bool t_char_traits2<wchar_t>::is_alnum(char_type const c)
{
 if(self_type::is_alpha(c))
  return true;

 if(self_type::is_digit(c))
  return true;

 return false;
}//is_alnum

//------------------------------------------------------------------------
inline
t_char_traits2<wchar_t>::char_type
t_char_traits2<wchar_t>::to_hex_u(byte_type const x)
{
 LCPI__assert(x<16);

 return L"0123456789ABCDEF"[x];
}//to_hex_u

//------------------------------------------------------------------------
inline
t_char_traits2<wchar_t>::char_type
t_char_traits2<wchar_t>::to_hex_l(byte_type const x)
{
 LCPI__assert(x<16);

 return L"0123456789abcdef"[x];
}//to_hex_l

//------------------------------------------------------------------------
inline
t_char_traits2<wchar_t>::char_type
t_char_traits2<wchar_t>::to_hex(byte_type const x,bool const upper)
{
 if(upper)
  return to_hex_u(x);

 return to_hex_l(x);
}//to_hex

//------------------------------------------------------------------------
inline bool t_char_traits2<wchar_t>::is_hex(char_type const c)
{
 return (c>=L'0' && c<=L'9') ||
        (c>=L'a' && c<=L'f') ||
        (c>=L'A' && c<=L'F');
}//is_hex

//------------------------------------------------------------------------
inline t_char_traits2<wchar_t>::byte_type
 t_char_traits2<wchar_t>::from_hex(char_type const c)
{
 if(c>=L'0' && c<=L'9')
  return byte_type(c-L'0');

 if(c>=L'a' && c<=L'f')
  return byte_type(c-L'a'+10);

 if(c>=L'A' && c<=L'F')
  return byte_type(c-L'A'+10);

 return structure::negative_one;
}//from_hex

//------------------------------------------------------------------------
inline bool t_char_traits2<wchar_t>::is_digit(char_type const c)
{
 return (c>=L'0' && c<=L'9');
}//is_digit

//------------------------------------------------------------------------
inline t_char_traits2<wchar_t>::byte_type
 t_char_traits2<wchar_t>::from_dec(char_type const c)
{
 if(c>=L'0' && c<=L'9')
  return byte_type(c-L'0');

 return structure::negative_one;
}//from_dec

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
