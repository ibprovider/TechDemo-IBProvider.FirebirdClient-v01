////////////////////////////////////////////////////////////////////////////////
//Standart implementation of test interfaces
//                                                 Dmitry Kovalenko. 27.01.2005.
#ifndef _t_tso_lib_H_
#define _t_tso_lib_H_

#include <structure/test_obj/t_tso_message.h>
#include <structure/test_obj/t_tso_log.h>
#include <structure/t_smart_object.h>
#include <structure/t_smart_vector.h>
#include <structure/t_str_args.h>
#include <structure/t_string_au.h>
#include <structure/t_threads.h>

namespace structure{namespace tso_obj{
////////////////////////////////////////////////////////////////////////////////
//content

template<class Allocator,class StrCvtTraits>
class t_basic_message;

template<class Allocator>
class t_basic_tracer;

template<class Allocator>
class t_basic_root_log;

class t_basic_exception_router;

////////////////////////////////////////////////////////////////////////////////
//class t_basic_message

template<class Allocator,class StrCvtTraits>
class t_basic_message LCPI_CPP_CFG__CLASS__FINAL
 :public structure::t_basic_smart_interface_impl__dynamic<t_message,Allocator>
{
 private:
  using self_type=t_basic_message<Allocator,StrCvtTraits>;

  t_basic_message(const self_type&);
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr
   =structure::t_smart_object_ptr<self_type>;

  using string_type
   =t_message::string_type;

  using lcid_type
   =t_message::lcid_type;

  using error_code_type
   =t_message::error_code_type;

   using msg_kind_type
   =t_message::msg_kind_type;

  using string_au_type
   =structure::t_string_au<string_type,StrCvtTraits>;

 public:
  error_code_type  m_error_code;
  msg_kind_type    m_msg_kind;
  string_au_type   m_source;
  string_au_type   m_description;

  t_basic_message();

  virtual ~t_basic_message();

  //t_message interface --------------------------------------------------
  virtual error_code_type get_error_code()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual msg_kind_type get_msg_kind()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool get_description(lcid_type    /*lcid*/,
                               string_type* source,
                               string_type* description)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual t_message_ptr clone()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class t_basic_message

////////////////////////////////////////////////////////////////////////////////
//class t_basic_tracer

template<class Allocator>
class t_basic_tracer LCPI_CPP_CFG__CLASS__FINAL
 :public t_basic_str_args<t_message::string_type::value_type,t_basic_tracer<Allocator> >
{
 private:
  using self_type=t_basic_tracer<Allocator>;
  using inherited=t_basic_str_args<t_message::string_type::value_type,self_type>;

  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using arg_type
   =typename inherited::string_type;

  using str_cvt_traits_type
   =typename inherited::traits_type::str_cvt_traits_type;

  using log_type
   =t_simple_log;

  using message_type
   =t_basic_message<Allocator,str_cvt_traits_type>;

  using error_code_type
   =typename message_type::error_code_type;

  using msg_kind_type
   =typename message_type::msg_kind_type;

  using string_au_type
   =typename message_type::string_au_type;

 public:
  t_basic_tracer(const self_type& x);

  t_basic_tracer(const self_type& x,const string_au_type& source);

  explicit t_basic_tracer(log_type* const log);

  t_basic_tracer(log_type* const log,const string_au_type& source);

  virtual ~t_basic_tracer();

  //initialize -----------------------------------------------------------
  self_type& operator() (msg_kind_type,error_code_type);

  self_type& operator() ();//msg_kind=info,error_code=0

  self_type& operator() (const string_au_type& source);//msg_kind=info,error_code=0

  //modificators ---------------------------------------------------------
  self_type& change_msg_type(msg_kind_type,error_code_type);

  //send message and init tracer -----------------------------------------
  self_type& send();

  //selectors ------------------------------------------------------------
  const log_type::self_ptr& log()const
   {return m_log;}

 public:
  static self_type& build_outer_type(inherited& x)
   {return *static_cast<self_type*>(&x);}

 private:
  virtual self_type& add_arg(const arg_type& x);

 private:
  const log_type::self_ptr               m_log;
  const typename message_type::self_ptr  m_message;
};//class t_basic_tracer

////////////////////////////////////////////////////////////////////////////////
//t_push_data - tracer manipulator

struct t_push_data LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  using msg_kind_type   =t_message::msg_kind_type;
  using error_code_type =t_message::error_code_type;

 public:
  msg_kind_type   m_msg_kind;
  error_code_type m_code;

  t_push_data(msg_kind_type   const msg_kind,
              error_code_type const code)
   :m_msg_kind (msg_kind)
   ,m_code     (code)
  {
  }
};//struct t_push_data

//------------------------------------------------------------------------
template<class t_traits>
t_basic_tracer<t_traits>& operator << (t_basic_tracer<t_traits>& t,const t_push_data& x)
{
 return t(x.m_msg_kind,x.m_code);
}//operator <<

//------------------------------------------------------------------------
inline const t_push_data push_error(t_push_data::error_code_type const code)
{
 return t_push_data(tso_msg_error,code);
}//push_error

//------------------------------------------------------------------------
inline const t_push_data push_warning(t_push_data::error_code_type const code)
{
 return t_push_data(tso_msg_warning,code);
}//push_warning

//------------------------------------------------------------------------
template<class t_traits>
t_basic_tracer<t_traits>& send(t_basic_tracer<t_traits>& tracer)
{
 return tracer.send();
}//send

////////////////////////////////////////////////////////////////////////////////
//class t_basic_log_stream__console

template<class Allocator>
class t_basic_log_stream__console LCPI_CPP_CFG__CLASS__FINAL
 :public structure::t_basic_smart_interface_impl__dynamic<t_log_stream,Allocator>
{
 private:
  using self_type=t_basic_log_stream__console<Allocator>;

  t_basic_log_stream__console(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=structure::t_smart_object_ptr<self_type>;
 
  using char_type=t_log_stream::char_type;

 private:
  t_basic_log_stream__console();

  virtual ~t_basic_log_stream__console();

 public:
  static self_ptr create();

  //t_log_stream interface -----------------------------------------------
  virtual void out(const char_type* s) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;//abstract
};//class t_basic_log_stream__console

////////////////////////////////////////////////////////////////////////////////
//class t_basic_root_log__printer

template<class t_log_stream>
class t_basic_root_log__printer LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_basic_root_log__printer<t_log_stream>;

  t_basic_root_log__printer(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using log_stream_type
   =t_log_stream;

  using log_stream_ptr
   =typename log_stream_type::self_ptr;

  using char_type
   =typename log_stream_type::char_type;

  using str_arg_type
   =structure::t_str_parameter<char_type>;

  using string_type
   =LCPI_STL_DEF_BASIC_STRING(char_type);

 public:
  t_basic_root_log__printer(log_stream_type*    stream,
                            const string_type&  line_prefix);

 ~t_basic_root_log__printer();

  self_type& out(str_arg_type);

  self_type& send();

 private:
  const log_stream_ptr  m_stream;
  const string_type     m_line_prefix;

 private:
  string_type m_buffer;
};//class t_basic_root_log__printer

////////////////////////////////////////////////////////////////////////////////
//class t_basic_root_log

template<class Allocator>
class t_basic_root_log
 :public structure::t_basic_smart_interface_impl__dynamic<t_log,Allocator>
{
 private:
  using self_type=t_basic_root_log<Allocator>;

  t_basic_root_log(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr
   =structure::t_smart_object_ptr<self_type>;

  using message_type
   =typename t_simple_log::message_type;

  using thread_traits
   =t_def_thread_traits;

  using guard_type
   =thread_traits::guard_type;

  using lock_guard_type
   =thread_traits::lock_guard_type;

  using count_type
   =std::uint64_t;

 public:
  bool print_ts;
  bool print_thread_id;

  explicit t_basic_root_log(t_log* pParent,t_log_stream* pOutputStream);

  virtual ~t_basic_root_log();

  //selectors ------------------------------------------------------------
  count_type get_unhandled_error_count()const;

  virtual count_type get_error_count()const;

  virtual count_type get_warning_count()const;

  count_type get_child_error_count()const;

  count_type get_child_warning_count()const;

  count_type get_total_error_count2()const;

  count_type get_total_warning_count2()const;

  //modificators ---------------------------------------------------------
  void inc_unhandled_error_count();

  //t_simple_log interface -----------------------------------------------
  virtual void trace(message_type* msg) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  //t_log interface ------------------------------------------------------
  virtual void inc_child_error_count() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void inc_child_warning_count() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  //modificators ---------------------------------------------------------
  void push_empty_line();

 private:
  std::wstring build_log_line_prefix()const;

 private:
  structure::t_smart_object_ptr<t_log> const m_parent;

 private:
  guard_type                    m_output_guard;
  t_log_stream::self_ptr const  m_output_stream;

 private:
  count_type m_unhandled_error_count;

  count_type m_error_count;
  count_type m_warning_count;

 private:
  count_type m_child_error_count;
  count_type m_child_warning_count;
};//class t_basic_root_log

////////////////////////////////////////////////////////////////////////////////
//class t_basic_exception_router

class t_basic_exception_router LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_basic_exception_router;

 public:
  template<class t_tracer>
  static void route(t_tracer& tracer);

  template<class t_tracer>
  static void route(t_tracer& tracer,const std::exception* exc);
};//class t_basic_exception_router

////////////////////////////////////////////////////////////////////////////////
}/*nms tso_obj*/}/*nms structure*/

////////////////////////////////////////////////////////////////////////////////
#include <structure/test_obj/t_tso_lib.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
