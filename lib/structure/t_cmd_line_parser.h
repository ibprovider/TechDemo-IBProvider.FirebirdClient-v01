////////////////////////////////////////////////////////////////////////////////
//Command line parser
//                                                Dmitry Kovalenko. 31.01.2005.
#ifndef _t_cmd_line_parser_H_
#define _t_cmd_line_parser_H_

#include <structure/t_smart_vector.h>
#include <structure/t_locale.h>
#include <structure/t_message_entry.h>
#include <structure/t_const_str_box.h>
#include <structure/error/t_err_exception_with_params.h>
#include <structure/error/t_err_record_with_params.h>
#include <map>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class ForwardIterator>
class t_cmd_line_part;

class t_cmd_line_error_codes;

template<class t_dummy>
class t_cmd_line_parser_error_traits;

template<class charT,class Allocator=t_void_allocator>
class t_basic_cmd_line_arg;

template<class charT,class Allocator=t_void_allocator>
class t_basic_cmd_line_parser;

////////////////////////////////////////////////////////////////////////////////
//class t_cmd_line_part

template<class ForwardIterator>
class t_cmd_line_part
{
 private:
  typedef t_cmd_line_part<ForwardIterator>               self_type;

 public:
  typedef ForwardIterator                                iterator_type;

 public:
  iterator_type  m_start;
  iterator_type  m_finish;
  iterator_type  m_value_beg;
  iterator_type  m_value_end;

  t_cmd_line_part();

  t_cmd_line_part(const self_type& x);

  t_cmd_line_part(ForwardIterator start,
                  ForwardIterator finish,
                  ForwardIterator value_beg,
                  ForwardIterator value_end);

 ~t_cmd_line_part();

  self_type& operator = (const self_type&);
};//class t_cmd_line_part

////////////////////////////////////////////////////////////////////////////////
//Free utilities

//partsT - class of container t_cmd_line_part
template<class ForwardIterator,class partsT>
void extract_cmd_line_parts(ForwardIterator first,
                            ForwardIterator last,
                            partsT&         parts);

////////////////////////////////////////////////////////////////////////////////
//class t_cmd_line_error_codes

class t_cmd_line_error_codes
{
 public:
  enum tag_msg_id
  {
   err_id_empty_arg_name        =1,
   err_id_bad_arg_name          =2,
   err_id_unk_arg_1             =3,
   err_id_bad_format_0          =4,
  };//tag_msg_id
};//t_cmd_line_error_codes

////////////////////////////////////////////////////////////////////////////////
//class t_cmd_line_parser_error_traits

template<class t_dummy>
class t_cmd_line_parser_error_traits:public t_cmd_line_error_codes
{
 public: //typedefs ------------------------------------------------------
  typedef tag_msg_id                        msg_id_type;
  typedef long                              source_id_type;
  typedef long                              help_file_id_type;

  struct record_data_ext_type{};

  typedef structure::t_message_entry<msg_id_type,const wchar_t*> msg_type;

 public: //---------------------------------------------------------------
  typedef t_err_record                      record_type;

  typedef record_type::lcid_type            lcid_type;
  typedef record_type::string_type          string_type;
  typedef record_type::system_id_type       system_id_type;
  typedef record_type::subsystem_id_type    subsystem_id_type;
  typedef record_type::error_code_type      error_code_type;

 public:
  static bool get_msg(lcid_type lcid,msg_id_type msg_id,string_type& msg);

  static void get_unknown_msg(lcid_type lcid,string_type& msg);

  static const char* get_critical_error_msg(lcid_type lcid);

  static bool get_source_name(lcid_type lcid,source_id_type,string_type& source);

  static bool get_help_file(lcid_type lcid,help_file_id_type,string_type& help_file);

  //-------------------
  static system_id_type get_def_system_id()
   {return record_type::system_user;}

  static subsystem_id_type get_def_subsystem_id()
   {return record_type::user_subsystem_unk;}

  static source_id_type get_def_source_id()
   {return 0;}

 private:
  static const msg_type sm_msgs[4];
};//class t_cmd_line_parser_error_traits

////////////////////////////////////////////////////////////////////////////////
//class t_basic_cmd_line_arg

template<class charT,class Allocator>
class t_basic_cmd_line_arg:public t_basic_smart_interface_impl__dynamic<t_smart_interface,Allocator>
{
 private:
  typedef t_basic_cmd_line_arg<charT,Allocator>       self_type;

  t_basic_cmd_line_arg(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~t_basic_cmd_line_arg();

 public:
  typedef t_smart_object_ptr<self_type>         self_ptr;
  typedef t_smart_object_ptr<const self_type>   self_cptr;

  typedef charT                                 char_type;
  typedef LCPI_STL_DEF_BASIC_STRING(char_type)  string_type;

 public:
  string_type m_name;
  string_type m_value;

 public:
  t_basic_cmd_line_arg();
};//class t_basic_cmd_line_arg

////////////////////////////////////////////////////////////////////////////////
//class t_basic_cmd_line_parser_base

template<class charT>
class t_basic_cmd_line_parser_base
{
 private:
  typedef t_basic_cmd_line_parser_base<charT>             self_type;

  t_basic_cmd_line_parser_base(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef charT                                           char_type;

 protected:
  t_basic_cmd_line_parser_base();
 ~t_basic_cmd_line_parser_base();

 public:
  bool is_name_char_1(const char_type c)const;

  bool is_name_char_2(const char_type c)const;

 public:
  const t_ctype<char_type>  m_ctype;
};//class t_basic_cmd_line_parser_base

////////////////////////////////////////////////////////////////////////////////
//class t_basic_cmd_line_parser

template<class charT,class Allocator>
class t_basic_cmd_line_parser:private t_basic_cmd_line_parser_base<charT>,
                              public  t_cmd_line_error_codes
{
 private:
  typedef t_basic_cmd_line_parser<charT,Allocator>               self_type;
  typedef t_basic_cmd_line_parser_base<charT>                    inherited;

  t_basic_cmd_line_parser(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  enum tag_arg_flags
  {
   arg_without_value            =0,
   arg_with_value               =1,
  };//enum tag_arg_flags

 public:
  typedef charT                                              char_type;
  typedef Allocator                                          allocator_type;

  typedef t_basic_const_str_box<char_type>                   str_box_type;

  typedef LCPI_STL_DEF_BASIC_STRING(char_type)               string_type;
  typedef typename string_type::size_type                    str_size_type;

  typedef tag_arg_flags                                      arg_flags_type;

  typedef t_basic_cmd_line_arg<char_type,allocator_type>     arg_type;
  typedef typename arg_type::self_ptr                        arg_ptr;
  typedef typename arg_type::self_cptr                       arg_cptr;

  typedef t_smart_vector<arg_type,allocator_type>            args_type;

  typedef typename args_type::size_type                      size_type;

  typedef typename args_type::iterator                       iterator;

  typedef typename args_type::const_iterator                 const_iterator;

  typedef std::map<string_type,arg_flags_type>               args_flags_map;

 public: //---------------------------------------------------------------
  typedef t_cmd_line_parser_error_traits<void*>              error_traits_type;
  typedef t_err_record_with_params<error_traits_type>        error_record_type;
  typedef t_err_exception_with_params<error_record_type>     error_type;

 public: //---------------------------------------------------------------
  t_basic_cmd_line_parser();

  explicit t_basic_cmd_line_parser(str_box_type s);

 ~t_basic_cmd_line_parser();

  //set parameters description -------------------------------------------
  self_type& reg_arg(str_box_type arg_name,arg_flags_type arg_flag);

  //----------------------------------------------------------------------
  //all
  // :true   - erase m_args_flags and m_args
  // :false  - erase m_args only
  self_type& clear(bool all);

  //parser ---------------------------------------------------------------
  self_type& parse(str_box_type s);

  //selectors ------------------------------------------------------------
  size_type size()const;

  bool empty()const;

  const arg_ptr& operator [] (size_type i)const;

  const arg_ptr get(str_box_type name,
                    bool         must_exists=true)const;//throw

  const string_type&
   value_or_default(str_box_type       name,
                    const string_type& default_value)const;

  bool has(str_box_type name)const;

  //iterators ------------------------------------------------------------
  typename iterator begin();
  typename iterator end();

  typename const_iterator begin()const;
  typename const_iterator end()const;

  typename const_iterator cbegin()const;
  typename const_iterator cend()const;

  //modificators ----------------------------------------------------------
  iterator erase(iterator x);

  iterator erase(iterator first,iterator last);

 private:
  bool helper__arg_has_value(const string_type& arg_name)const;

  void helper__install_arg_value(typename arg_type::self_ptr&    arg,
                                 typename str_box_type::iterator beg,
                                 typename str_box_type::iterator end);

 private:
  args_flags_map  m_args_flags;
  args_type       m_args;
};//class t_basic_cmd_line_parser

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
#include <structure/t_cmd_line_parser.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
