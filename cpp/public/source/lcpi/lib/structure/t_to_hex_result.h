////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 14.11.2022
#ifndef _cpp_public_lcpi_lib_structure__t_to_hex_result_H_
#define _cpp_public_lcpi_lib_structure__t_to_hex_result_H_

#include <lcpi/lib/.config.h>
#include <array>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_to_hex_result

template<typename charT,typename T>
class t_to_hex_result
{
 private:
  typedef t_to_hex_result<charT,T> self_type;

 public:
  t_to_hex_result();

  const charT* c_str() const;

  void set(size_t i,charT ch);

  void set_term(size_t i);

 private:
  static const size_t c_N=2*sizeof(T);

  std::array<charT,c_N+1> m_buffer;
};//class t_to_hex_result

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "lcpi/lib/structure/t_to_hex_result.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
