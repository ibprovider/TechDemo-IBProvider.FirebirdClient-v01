////////////////////////////////////////////////////////////////////////////////
//base class for string arguments/parameters managements
//                                                 Dmitry Kovalenko. 05.04.2004
#ifndef _t_str_args_H_
#define _t_str_args_H_

#include <structure/t_str_args_traits.h>
#include <structure/t_str_parameter.h>
#include <structure/t_const_str_box.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class charT,class t_outer>
class t_basic_str_args;

////////////////////////////////////////////////////////////////////////////////
//class t_basic_str_args

//outer_type
// - the derivative class

template<class charT,class t_outer>
class t_basic_str_args
{
 private:
  typedef t_basic_str_args<charT,t_outer>                    self_type;

  t_basic_str_args(const self_type&) COMP_W000002_COPY_CTOR_IMPL
  self_type& operator = (const self_type&);

 public: //typedef -------------------------------------------------------
  typedef t_str_args_traits<charT>                           traits_type;
  typedef t_outer                                            outer_type;

  typedef typename traits_type::size_type                    size_type;
  typedef typename traits_type::char_type                    char_type;
  typedef typename traits_type::string_type                  string_type;

  typedef structure::str_parameter                           astr_param_type;
  typedef structure::wstr_parameter                          wstr_param_type;

  typedef structure::t_const_str_box                         astr_box_type;
  typedef structure::t_const_wstr_box                        wstr_box_type;

  typedef outer_type& (*manip1_type)(outer_type&);

  typedef void (*manip2_type)(outer_type&);

 public: //---------------------------------------------------------------
  struct t_symbol
  {
   char_type symbol;
  };

  static const t_symbol as_symbol(char_type symbol)
   {t_symbol s;s.symbol=symbol;return s;}

 public: //---------------------------------------------------------------
  struct t_char_str
  {
   const char*  s;
   size_type    n;
  };

  static const t_char_str as_str(const char* s,size_type n)
   {t_char_str x;x.s=s;x.n=n;return x;}

 public: //---------------------------------------------------------------
  struct t_wchar_str
  {
   const wchar_t*  s;
   size_type       n;
  };

  static const t_wchar_str as_str(const wchar_t* s,size_type n)
   {t_wchar_str x;x.s=s;x.n=n;return x;}

 protected: //------------------------------------------------------------
  t_basic_str_args();

  virtual ~t_basic_str_args();

 public: //append arguments ----------------------------------------------
  outer_type& operator<<(bool);
  outer_type& operator<<(signed   char);
  outer_type& operator<<(unsigned char);
  outer_type& operator<<(signed   short);
  outer_type& operator<<(unsigned short);
  outer_type& operator<<(signed   int);
  outer_type& operator<<(unsigned int);
  outer_type& operator<<(signed   long);
  outer_type& operator<<(unsigned long);
  outer_type& operator<<(signed   __int64);
  outer_type& operator<<(unsigned __int64);
  outer_type& operator<<(float);
  outer_type& operator<<(double);
  outer_type& operator<<(long double);
  outer_type& operator<<(const char*);
  outer_type& operator<<(const std::string&);
  outer_type& operator<<(const wchar_t*);
  outer_type& operator<<(const std::wstring&);
  outer_type& operator<<(const t_symbol&);
  outer_type& operator<<(const t_char_str&);
  outer_type& operator<<(const t_wchar_str&);

  outer_type& operator<<(const astr_param_type&);
  outer_type& operator<<(const wstr_param_type&);

  outer_type& operator<<(const astr_box_type&);
  outer_type& operator<<(const wstr_box_type&);

  outer_type& operator<<(const std::exception&);

  //support of manipulator
  outer_type& operator<<(manip1_type);

  void operator<<(manip2_type);

 private: //DONE: replace on private ?
  virtual outer_type& add_arg(const string_type& x) COMP_W000001_PURE_METHOD;

  virtual outer_type& add_arg__exc(const std::exception& x);
};//class t_basic_str_args

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
#include <structure/t_str_args.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
