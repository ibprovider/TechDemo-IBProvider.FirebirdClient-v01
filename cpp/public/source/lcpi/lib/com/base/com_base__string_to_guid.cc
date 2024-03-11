////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 25.10.2022.
#ifndef _cpp_public_lcpi_lib_com_base__string_to_guid_CC_
#define _cpp_public_lcpi_lib_com_base__string_to_guid_CC_

#include <lcpi/lib/structure/utilities/string_to_uuid.h>
#include <lcpi/lib/structure/t_char_traits2.h>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////

template<typename charT>
bool string_to_guid(structure::t_basic_const_str_box<charT> str,GUID* const pGUID)
{
 assert(pGUID!=nullptr);

 (*pGUID)=GUID_NULL;

 //---------------------------------------------------
 typedef structure::t_char_traits2<charT> char_traits2;

 //---------------------------------------------------
 //
 //  12345678901234567890123456789012345678
 //  {6CB31410-F4E9-4565-83A7-D263FD3FB4F8}
 //

 const size_t c_UUID_STR_SIZE=36;

 const size_t c_GUID_STR_SIZE=c_UUID_STR_SIZE+2;

 //---------------------------------------------------
 if(str.len!=c_GUID_STR_SIZE)
  return false;

 const charT* const beg=str.data();
#ifndef NDEBUG
 const charT* const end=beg+str.size();
#endif

 LCPI__assert((end-beg)==c_GUID_STR_SIZE);

 //-----------------------------------------------------------------------
 const charT* s=beg;

 if(s[0]!=char_traits2::ch_open_fbracket()) // '{'
  return false;

 ++s;

 if(s[c_UUID_STR_SIZE]!=char_traits2::ch_close_fbracket()) // '}'
  return false;

 const auto* const e=s+c_UUID_STR_SIZE;

 const auto uuid_parser_r
  =lib::structure::string_to_uuid(s,e,pGUID);

 LCPI__assert(uuid_parser_r.first>=s);
 LCPI__assert(uuid_parser_r.first<=e);

#ifndef NDEBUG
 if(uuid_parser_r.second)
 {
  LCPI__assert(uuid_parser_r.first==e);

  LCPI__assert((*uuid_parser_r.first)==char_traits2::ch_close_fbracket());
 }
 else
 {
  LCPI__assert(uuid_parser_r.first<e);
 }
#endif

 return uuid_parser_r.second;
}//string_to_guid

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

inline bool string_to_guid(structure::t_const_str_box str,GUID* pGUID)
{
 return detail::string_to_guid(str,pGUID);
}//string_to_guid - char

//------------------------------------------------------------------------
inline bool string_to_guid(structure::t_const_wstr_box str,GUID* pGUID)
{
 return detail::string_to_guid(str,pGUID);
}//string_to_guid - wchar_t

////////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
#endif
