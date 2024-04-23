////////////////////////////////////////////////////////////////////////////////
//LCPI instrumental C++ library.
//                                                 Dmitry Kovalenko. 11.04.2024.
#ifndef _lcpi_lib_structure__t_str_cvt_traits__utf8_H_
#define _lcpi_lib_structure__t_str_cvt_traits__utf8_H_

#include <structure/charsets/cs_cvt__wchar_to_utf8.h>
#include <structure/t_const_str_box.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_str_cvt_traits__utf8

class t_str_cvt_traits__utf8 LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_str_cvt_traits__utf8;

 public:
  template<class charTraits,class Allocator>
  static void tstr_to_tstr
               (std::basic_string<char,charTraits,Allocator>* pDest,
                t_const_wstr_box                              src);

  //----------------------------------------------------------------------
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void helper__throw_error(const char* const msg)
  {
   LCPI__assert(msg);

   throw std::runtime_error(std::string("[BUG CHECK][t_str_cvt_traits__utf8] ").append(msg));
  }//helper__throw_error
};//class t_str_cvt_traits__utf8

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_str_cvt_traits__utf8.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
