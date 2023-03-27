////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 02.10.2019
#ifndef _cpp_public_lcpi_lib_structure_utilities__to_hex2_H_
#define _cpp_public_lcpi_lib_structure_utilities__to_hex2_H_

#include <lcpi/lib/structure/t_to_hex_result.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class to_hex2

// Translation to hex with removing leading zero BYTES.

class to_hex2
{
 private:
  typedef to_hex2    self_type;

 private: //typdefs ------------------------------------------------------
  template<size_t N>
  struct tag_sint_selector;

  template<>
  struct tag_sint_selector<sizeof(signed __int32)>
  {
   typedef signed __int32 type;
  };

  template<>
  struct tag_sint_selector<sizeof(signed __int64)>
  {
   typedef signed __int64 type;
  };

 private:
  template<size_t N>
  struct tag_uint_selector;

  template<>
  struct tag_uint_selector<sizeof(unsigned __int32)>
  {
   typedef unsigned __int32 type;
  };

  template<>
  struct tag_uint_selector<sizeof(unsigned __int64)>
  {
   typedef unsigned __int64 type;
  };

 private:
  typedef tag_sint_selector<sizeof(signed long)>::type   slong_sint_type;
  typedef tag_uint_selector<sizeof(unsigned long)>::type ulong_uint_type;

 public:
  template<typename charT,typename T>
  static const t_to_hex_result<charT,T> upper(T numeric);

  template<typename charT>
  static const t_to_hex_result<charT,signed __int8> upper(signed __int8 v);

  template<typename charT>
  static const t_to_hex_result<charT,signed __int16> upper(signed __int16 v);

  template<typename charT>
  static const t_to_hex_result<charT,signed __int32> upper(signed __int32 v);

  template<typename charT>
  static const t_to_hex_result<charT,signed __int64> upper(signed __int64 v);

  template<typename charT>
  static const t_to_hex_result<charT,slong_sint_type> upper(signed long const v)
  {
   return self_type::upper<charT>(slong_sint_type(v));
  }

  template<typename charT>
  static const t_to_hex_result<charT,unsigned __int8> upper(unsigned __int8 v);

  template<typename charT>
  static const t_to_hex_result<charT,unsigned __int16> upper(unsigned __int16 v);

  template<typename charT>
  static const t_to_hex_result<charT,unsigned __int32> upper(unsigned __int32 v);

  template<typename charT>
  static const t_to_hex_result<charT,unsigned __int64> upper(unsigned __int64 v);

  template<typename charT>
  static const t_to_hex_result<charT,ulong_uint_type> upper(unsigned long v)
  {
   return self_type::upper<charT>(ulong_uint_type(v));
  }

 private:
  template<typename charT,typename T>
  static const t_to_hex_result<charT,T> helper__upper(T v);
};//class to_hex2

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "lcpi/lib/structure/utilities/to_hex2.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
