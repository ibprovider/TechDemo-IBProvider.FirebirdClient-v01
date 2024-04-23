////////////////////////////////////////////////////////////////////////////////
//Sevice for build text from template with parameters
//                                              Dmitry Kovalenko. 08.01.2002.
//Sammple
// string msg=t_str_formatter("%1 %2 !")<<"Hello"<<"World";
#ifndef _lcpi_lib_structure__t_str_formatter_H_
#define _lcpi_lib_structure__t_str_formatter_H_

#include <structure/t_str_formatter_traits.h>
#include <structure/t_str_parameter.h>
#include <structure/t_const_str_box.h>
#include <structure/t_memory.h>
#include <structure/t_char_base.h>

#include <structure/stl/t_stl_vector.h>
#include <structure/stl/t_stl_map.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containing

template<class charT,
         class traits=t_str_formatter_traits<charT>,
         class allocator=t_void_allocator>
class t_basic_str_formatter;

////////////////////////////////////////////////////////////////////////////////
//template class t_basic_str_formatter__fpart

template<typename TString>
class t_basic_str_formatter__fpart LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_basic_str_formatter__fpart<TString>;

 public: //typedefs ------------------------------------------------------
  using string_type=TString;

  using char_type=typename string_type::value_type;

 public:
  bool        is_arg;
  string_type value;

 public:
  t_basic_str_formatter__fpart();

  t_basic_str_formatter__fpart(const bool       _is_arg,
                               const char_type* beg,
                               const char_type* end);

  t_basic_str_formatter__fpart(const self_type& f);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  t_basic_str_formatter__fpart(self_type&& x);
 #endif

  self_type& operator = (const self_type& x);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& operator = (self_type&& x);
 #endif

  void swap(self_type& x);
};//class t_basic_str_formatter__fpart

////////////////////////////////////////////////////////////////////////////////
//template class t_basic_str_formatter__arg_value

template<typename TString>
class t_basic_str_formatter__arg_value LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_basic_str_formatter__arg_value<TString>;

 public: //typedefs ------------------------------------------------------
  using string_type=TString;

 public:
  t_basic_str_formatter__arg_value();

  t_basic_str_formatter__arg_value(const self_type& x);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  t_basic_str_formatter__arg_value(self_type&& x);
 #endif

  self_type& operator = (const self_type& x);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& operator = (self_type&& x);
 #endif

  void swap(self_type& x);

  //selectors ---------------------------------------------------
  bool is_assigned()const;

  const string_type& get_value()const;

  //modificator -------------------------------------------------
  void set_value(const string_type& v);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  void set_value(string_type&& v);
 #endif

  void reset();

 private:
  string_type     m_value;
  bool            m_assign;
};//class t_basic_str_formatter__arg_value

////////////////////////////////////////////////////////////////////////////////
//template struct t_basic_str_formatter__symbol

template<typename charT>
struct t_basic_str_formatter__symbol LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  charT symbol;

  t_basic_str_formatter__symbol(charT const s)
   :symbol(s)
  {;}
};//struct t_basic_str_formatter__symbol

////////////////////////////////////////////////////////////////////////////////
//class t_basic_str_formatter_base

class t_basic_str_formatter_base
{
 public: //typedefs ------------------------------------------------------
  using modes_type=unsigned int;

  enum
  {
   fl_support_number_arg          =0x01, // %1
   fl_support_named_arg           =0x02, // %name%
   fl_support_mult_arg            =0x04, // %*

   fl_save_prefix_of_unknown_arg  =0x10,

   fl_defaults=fl_support_number_arg|fl_support_named_arg,
  };//enum
};//class t_basic_str_formatter_base

////////////////////////////////////////////////////////////////////////////////
//template class t_basic_str_formatter

template<class charT,class traits,class allocator>
class t_basic_str_formatter LCPI_CPP_CFG__CLASS__FINAL
 :public t_basic_str_formatter_base
{
 private:
  using self_type=t_basic_str_formatter<charT,traits,allocator>;

 public://typedefs -------------------------------------------------------
  typedef traits                                               traits_type;
  typedef allocator                                            allocator_type;

  typedef typename traits::string_type                         string_type;
  typedef typename traits::char_type                           char_type;
  typedef typename traits::size_type                           size_type;

  typedef structure::str_parameter                             astr_param_type;
  typedef structure::wstr_parameter                            wstr_param_type;

  typedef structure::t_basic_const_str_box<char_type>          str_box_type;
  typedef structure::t_basic_const_str_box<char>               astr_box_type;
  typedef structure::t_basic_const_str_box<wchar_t>            wstr_box_type;

  typedef t_basic_str_formatter__symbol<char>                  asymbol_type;
  typedef t_basic_str_formatter__symbol<wchar_t>               wsymbol_type;

  typedef size_type                                            num_arg_index_type;
  typedef structure::t_str_parameter<char_type>                name_arg_type;
  typedef string_type                                          name_type;

  enum
  {
   first_num_arg_idx=1
  };

 public: //---------------------------------------------------------------
  using fpart_type
   =t_basic_str_formatter__fpart<string_type>;

  using arg_value_type
   =t_basic_str_formatter__arg_value<string_type>;

  using fparts_type
   =t_stl_vector<fpart_type,allocator_type>;

  using args_type
   =t_stl_map<string_type,arg_value_type,std::less<string_type>,allocator_type>;

 public: //constructors/destructor ---------------------------------------
  traits_type m_traits;
  modes_type  m_modes;

 public:
  t_basic_str_formatter();

  explicit t_basic_str_formatter(str_box_type fstr);

  t_basic_str_formatter(const char_type* fstr,size_type n);

  t_basic_str_formatter(const self_type& x);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  t_basic_str_formatter(self_type&& x);
 #endif

#if !defined( __BCPLUSPLUS__) || (__BCPLUSPLUS__>0x0530)
 ~t_basic_str_formatter();
#else
 ~t_basic_str_formatter(){;} //BCB3 problems
#endif

  self_type& operator = (const self_type& x);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& operator = (self_type&& x);
 #endif

  void swap(self_type& x);

 public: //user interface ------------------------------------------------
  const args_type& args() const
   {return m_args;}

  args_type& args()
   {return m_args;}

  self_type& init(str_box_type fstr);

  self_type& init(const char_type* fstr,size_type n);

  self_type& add_text(str_box_type text);

  self_type& add_text(const char_type* text,size_type n);

  self_type& flush();

  //create formated string
  const string_type& str()const;

  const char_type* c_str()const
   {return this->str().c_str();}

  //access prepared string
  const fparts_type& fparts()const
   {return m_fparts;}

  operator const string_type& ()const
   {return this->str();}

  operator const t_str_parameter<char_type> () const
   {return this->str();}

  void reserve_result_space(size_type n)
   {m_result.reserve(n);}

 public:
  static asymbol_type as_symbol(char const x)
   {return asymbol_type(x);}

  static wsymbol_type as_symbol(wchar_t const x)
   {return wsymbol_type(x);}

 public: //insert arguments ----------------------------------------------
  self_type& operator () (str_box_type fstr);

  self_type& operator () (const char_type* fstr,size_type n);

  self_type& operator << (bool                   );
  self_type& operator << (signed   char          );
  self_type& operator << (unsigned char          );
  self_type& operator << (std::int16_t           );
  self_type& operator << (std::uint16_t          );
  self_type& operator << (std::int32_t           );
  self_type& operator << (std::uint32_t          );

#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  self_type& operator << (signed   long          );
#endif

#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
  self_type& operator << (unsigned long          );
#endif

  self_type& operator << (std::int64_t           );
  self_type& operator << (std::uint64_t          );
  self_type& operator << (float                  );
  self_type& operator << (double                 );
  self_type& operator << (long double            );
  self_type& operator << (const char*            );
  self_type& operator << (const std::string&     );
  self_type& operator << (const wchar_t*         );
  self_type& operator << (const std::wstring&    );
  self_type& operator << (const asymbol_type&    );
  self_type& operator << (const wsymbol_type&    );
  self_type& operator << (const astr_box_type&   );
  self_type& operator << (const wstr_box_type&   );

  self_type& operator << (const astr_param_type& );
  self_type& operator << (const wstr_param_type& );

#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& operator << (std::string&&          );
  self_type& operator << (std::wstring&&         );
#endif

  //support for manipulators ---------------------------------------------
  typedef const char_type*    tf_fmsg_getter1(self_type&);
  typedef const string_type&  tf_fmsg_getter2(self_type&);

  typedef self_type&          (*t_fmsg_manip) (self_type&);
  typedef tf_fmsg_getter1*    t_fmsg_getter1;
  typedef tf_fmsg_getter2*    t_fmsg_getter2;

  self_type&         operator << (t_fmsg_manip   );
  const char_type*   operator << (t_fmsg_getter1 );
  const string_type& operator << (t_fmsg_getter2 );

 public: //direct assign args values -------------------------------------

  //number args
  self_type& set(num_arg_index_type const idx,bool                       );
  self_type& set(num_arg_index_type const idx,signed   char              );
  self_type& set(num_arg_index_type const idx,unsigned char              );
  self_type& set(num_arg_index_type const idx,std::int16_t               );
  self_type& set(num_arg_index_type const idx,std::uint16_t              );
  self_type& set(num_arg_index_type const idx,std::int32_t               );
  self_type& set(num_arg_index_type const idx,std::uint32_t              );

#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  self_type& set(num_arg_index_type const idx,signed   long              );
#endif

#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  self_type& set(num_arg_index_type const idx,unsigned long              );
#endif

  self_type& set(num_arg_index_type const idx,std::int64_t               );
  self_type& set(num_arg_index_type const idx,std::uint64_t              );
  self_type& set(num_arg_index_type const idx,float                      );
  self_type& set(num_arg_index_type const idx,double                     );
  self_type& set(num_arg_index_type const idx,long double                );
  self_type& set(num_arg_index_type const idx,const char*                );
  self_type& set(num_arg_index_type const idx,const std::string&         );
  self_type& set(num_arg_index_type const idx,const wchar_t*             );
  self_type& set(num_arg_index_type const idx,const std::wstring&        );
  self_type& set(num_arg_index_type const idx,const asymbol_type&        );
  self_type& set(num_arg_index_type const idx,const wsymbol_type&        );
  self_type& set(num_arg_index_type const idx,const astr_param_type&     );
  self_type& set(num_arg_index_type const idx,const wstr_param_type&     );

#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& set(num_arg_index_type const idx,std::string&&              );
  self_type& set(num_arg_index_type const idx,std::wstring&&             );
#endif

  //named and number args
  self_type& set_by_name(name_arg_type const name,bool                   );
  self_type& set_by_name(name_arg_type const name,signed   char          );
  self_type& set_by_name(name_arg_type const name,unsigned char          );
  self_type& set_by_name(name_arg_type const name,std::int16_t           );
  self_type& set_by_name(name_arg_type const name,std::uint16_t          );
  self_type& set_by_name(name_arg_type const name,std::int32_t           );
  self_type& set_by_name(name_arg_type const name,std::uint32_t          );

#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  self_type& set_by_name(name_arg_type const name,signed   long          );
#endif

#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
  self_type& set_by_name(name_arg_type const name,unsigned long          );
#endif

  self_type& set_by_name(name_arg_type const name,std::int64_t           );
  self_type& set_by_name(name_arg_type const name,std::uint64_t          );
  self_type& set_by_name(name_arg_type const name,float                  );
  self_type& set_by_name(name_arg_type const name,double                 );
  self_type& set_by_name(name_arg_type const name,long double            );
  self_type& set_by_name(name_arg_type const name,const char*            );
  self_type& set_by_name(name_arg_type const name,const std::string&     );
  self_type& set_by_name(name_arg_type const name,const wchar_t*         );
  self_type& set_by_name(name_arg_type const name,const std::wstring&    );
  self_type& set_by_name(name_arg_type const name,const asymbol_type&    );
  self_type& set_by_name(name_arg_type const name,const wsymbol_type&    );
  self_type& set_by_name(name_arg_type const name,const astr_param_type& );
  self_type& set_by_name(name_arg_type const name,const wstr_param_type& );

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& set_by_name(name_arg_type const name,std::string&&          );
  self_type& set_by_name(name_arg_type const name,std::wstring&&         );
#endif

 private:
  void append_fpart(const bool       is_arg,
                    const char_type* beg,
                    const char_type* end);

  //----------------------------------------------------------------------
  self_type& push_next_num_arg(const string_type& value);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& push_next_num_arg(string_type&& value);
 #endif

  //----------------------------------------------------------------------
  self_type& set_num_arg(num_arg_index_type idx,
                         const string_type& value);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& set_num_arg(num_arg_index_type idx,
                         string_type&&      value);
 #endif

  //----------------------------------------------------------------------
  self_type& set_named_arg(name_arg_type      name,
                           const string_type& value);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& set_named_arg(name_arg_type name,
                           string_type&& value);
 #endif

 private: //internal data ------------------------------------------------
  fparts_type           m_fparts;       //prepared string template
  args_type             m_args;         //arguments
  num_arg_index_type    m_next_num_arg;

  mutable string_type   m_result;       //result string
};//class t_basic_str_formatter

////////////////////////////////////////////////////////////////////////////////
//standard formatters

using str_formatter
 =t_basic_str_formatter<char>;

using wstr_formatter
 =t_basic_str_formatter<wchar_t>;

using tstr_formatter
 =t_basic_str_formatter<t_char>;

////////////////////////////////////////////////////////////////////////////////
//stream support

template<class charT,class traits,class allocator>
inline std::basic_ostream<charT>& operator <<
 (std::basic_ostream<charT>& os,const t_basic_str_formatter<charT,traits,allocator>& f)
{
 return os<<f.str();
}

////////////////////////////////////////////////////////////////////////////////
//str_formatter manipulators

template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 flush(t_basic_str_formatter<charT,traits,allocator>& f)
{
 return f.flush();
}//flush

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
t_basic_str_formatter<charT,traits,allocator>&
 self_init(t_basic_str_formatter<charT,traits,allocator>& f)
{
 return f(f.str());
}//self_init

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
const typename t_basic_str_formatter<charT,traits,allocator>::char_type*
 c_str(t_basic_str_formatter<charT,traits,allocator>& f)
{
 return f.c_str();
}//c_str

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
const typename t_basic_str_formatter<charT,traits,allocator>::string_type&
 str(t_basic_str_formatter<charT,traits,allocator>& f)
{
 return f.str();
}//str

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
//STL specialization

namespace std{
////////////////////////////////////////////////////////////////////////////////

template<typename TString>
inline
void swap(structure::t_basic_str_formatter__fpart<TString>& a,
          structure::t_basic_str_formatter__fpart<TString>& b)
{
 a.swap(b);
}//swap for structure::t_basic_str_formatter__fpart

//------------------------------------------------------------------------
template<typename TString>
inline
void swap(structure::t_basic_str_formatter__arg_value<TString>& a,
          structure::t_basic_str_formatter__arg_value<TString>& b)
{
 a.swap(b);
}//swap for structure::t_basic_str_formatter__arg_value

//------------------------------------------------------------------------
template<class charT,class traits,class allocator>
inline
void swap(structure::t_basic_str_formatter<charT,traits,allocator>& a,
          structure::t_basic_str_formatter<charT,traits,allocator>& b)
{
 a.swap(b);
}//swap for t_basic_str_formatter<charT,traits,allocator>

////////////////////////////////////////////////////////////////////////////////
}//namespace std

////////////////////////////////////////////////////////////////////////////////
#include <structure/t_str_formatter.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
