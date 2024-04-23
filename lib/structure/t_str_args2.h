////////////////////////////////////////////////////////////////////////////////
//Base class for string arguments/parameters managements
//                                                 Dmitry Kovalenko. 09.04.2024
#ifndef _lcpi_lib_structure__t_str_args2_H_
#define _lcpi_lib_structure__t_str_args2_H_

#include <structure/t_str_args_traits.h>
#include <structure/t_str_parameter.h>

#include <cstdint>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class charT,class t_outer,class str_args_traits>
class t_basic_str_args2;

////////////////////////////////////////////////////////////////////////////////
//class t_basic_str_args2

//outer_type
// - the derivative class

template<class charT,class t_outer,class str_args_traits>
class t_basic_str_args2
{
 private:
  using self_type=t_basic_str_args2<charT,t_outer,str_args_traits>;

  t_basic_str_args2(const self_type&) COMP_W000002_COPY_CTOR_IMPL
  self_type& operator = (const self_type&);

 public: //typedef -------------------------------------------------------
  using traits_type
   =str_args_traits;

  using outer_type
   =t_outer;

  using size_type
   =typename traits_type::size_type;

  using char_type
   =typename traits_type::char_type;

  using string_type
   =typename traits_type::string_type;

  using astr_param_type
   =structure::str_parameter;

  using wstr_param_type
   =structure::wstr_parameter;

  using astr_box_type
   =structure::t_const_str_box;

  using wstr_box_type
   =structure::t_const_wstr_box;

  using manip1_type=outer_type& (*)(outer_type&);

  using manip2_type=void (*)(outer_type&);

 public: //---------------------------------------------------------------
  struct t_symbol
  {
   char_type symbol;
  };

  static const t_symbol as_symbol(char_type symbol)
  {
   t_symbol s;
   s.symbol=symbol;
   return s;
  }//as_symbol

 protected: //------------------------------------------------------------
  t_basic_str_args2();

  virtual ~t_basic_str_args2();

 public: //append arguments ----------------------------------------------
  outer_type& operator << (bool);

  outer_type& operator << (signed   char);
  outer_type& operator << (unsigned char);

  outer_type& operator << (std::int16_t);
  outer_type& operator << (std::uint16_t);
  outer_type& operator << (std::int32_t);
  outer_type& operator << (std::uint32_t);

#if(LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  outer_type& operator << (signed   long);
#endif

#if(LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
  outer_type& operator << (unsigned long);
#endif

  outer_type& operator << (std::int64_t);
  outer_type& operator << (std::uint64_t);

  outer_type& operator << (float);
  outer_type& operator << (double);
  outer_type& operator << (long double);

  outer_type& operator << (const char*);
  outer_type& operator << (const std::string&);
  outer_type& operator << (const wchar_t*);
  outer_type& operator << (const std::wstring&);

  outer_type& operator << (const t_symbol&);

  outer_type& operator << (const astr_param_type&);
  outer_type& operator << (const wstr_param_type&);

  outer_type& operator << (const astr_box_type&);
  outer_type& operator << (const wstr_box_type&);

  outer_type& operator << (const std::exception&);

  //support of manipulator
  outer_type& operator << (manip1_type);

  void operator << (manip2_type);

 private: //DONE: replace on private ?
  virtual outer_type& add_arg(const string_type& x) COMP_W000001_PURE_METHOD;

  virtual outer_type& add_arg__exc(const std::exception& x);
};//class t_basic_str_args2

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
#include <structure/t_str_args2.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
