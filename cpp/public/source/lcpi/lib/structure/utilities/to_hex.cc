////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 02.10.2019
#ifndef _cpp_public_lcpi_lib_structure_utilities__to_hex_CC_
#define _cpp_public_lcpi_lib_structure_utilities__to_hex_CC_

#include <lcpi/lib/structure/t_numeric_utils.h>
#include <lcpi/lib/structure/t_char_traits2.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class to_hex

template<typename charT>
const t_to_hex_result<charT,signed __int8> to_hex::upper(signed __int8 const v)
{
 t_to_hex_result<charT,signed __int8> r;

 assert_s(sizeof(v)==1);
 assert_s(CHAR_BIT==8);

 r.set(0,t_char_traits2<charT>::to_hex_u((v>>4)&0x0F));
 r.set(1,t_char_traits2<charT>::to_hex_u(v&0xF));

 r.set_term(2);

 return r;
}//upper - i1

//------------------------------------------------------------------------
template<typename charT>
const t_to_hex_result<charT,signed __int16> to_hex::upper(signed __int16 const v)
{
 return self_type::helper__upper<charT>(v);
}//upper - i2

//------------------------------------------------------------------------
template<typename charT>
const t_to_hex_result<charT,signed __int32> to_hex::upper(signed __int32 const v)
{
 return self_type::helper__upper<charT>(v);
}//upper - i4

//------------------------------------------------------------------------
template<typename charT>
const t_to_hex_result<charT,signed __int64> to_hex::upper(signed __int64 const v)
{
 return self_type::helper__upper<charT>(v);
}//upper - i8

//------------------------------------------------------------------------
template<typename charT>
const t_to_hex_result<charT,unsigned __int8> to_hex::upper(unsigned __int8 const v)
{
 t_to_hex_result<charT,unsigned __int8> r;

 assert_s(sizeof(v)==1);
 assert_s(CHAR_BIT==8);

 r.set(0,t_char_traits2<charT>::to_hex_u(v>>4));
 r.set(1,t_char_traits2<charT>::to_hex_u(v&0xF));

 r.set_term(2);

 return r;
}//upper - ui1

//------------------------------------------------------------------------
template<typename charT>
const t_to_hex_result<charT,unsigned __int16> to_hex::upper(unsigned __int16 const v)
{
 return self_type::helper__upper<charT>(v);
}//upper - ui2

//------------------------------------------------------------------------
template<typename charT>
const t_to_hex_result<charT,unsigned __int32> to_hex::upper(unsigned __int32 const v)
{
 return self_type::helper__upper<charT>(v);
}//upper - ui4

//------------------------------------------------------------------------
template<typename charT>
const t_to_hex_result<charT,unsigned __int64> to_hex::upper(unsigned __int64 const v)
{
 return self_type::helper__upper<charT>(v);
}//upper - ui8

//------------------------------------------------------------------------
template<typename charT,typename T>
const t_to_hex_result<charT,T> to_hex::helper__upper(T const v)
{
 t_to_hex_result<charT,T> r;

 assert_s(CHAR_BIT==8);

 const auto bb=get_numeric_bytes(v);

 assert(bb.size()>0);

 size_t ir=0;

 for(size_t n=bb.size();;)
 {
  --n;

  const unsigned char b=bb[n];

  r.set(ir,t_char_traits2<charT>::to_hex_u(b>>4));

  ++ir;

  r.set(ir,t_char_traits2<charT>::to_hex_u(b&0xF));

  ++ir;

  if(n==0)
   break;
 }//for

 r.set_term(ir);

 return r;
}//helper__upper

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
