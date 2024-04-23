////////////////////////////////////////////////////////////////////////////////
//Exception record with template message
//                                                 Dmitry Kovalenko. 13.04.2024.
#ifndef _t_err_record_with_params2_H_
#define _t_err_record_with_params2_H_

#include <structure/error/t_err_record.h>
#include <structure/mt/t_guard.h>
#include <structure/t_str_args2.h>
#include <structure/t_smart_vector.h>
#include <structure/t_smart_object.h>

#include <type_traits>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<class stringT>
class t_err_record_arg;

template<class stringT,class Allocator>
class t_err_record_arg_string;

template<class charT,class StrCvtTraits,class Allocator>
class t_err_record_with_params2_base;

template<class record_traits,class charT,class StrCvtTraits,class Allocator>
class t_err_record_with_params2;

////////////////////////////////////////////////////////////////////////////////
//class t_err_record_arg_string

template<class stringT>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE  t_err_record_arg
 :public t_smart_interface
{
 public:
  using string_type=stringT;
  using lcid_type  =t_err_record::lcid_type;

 public:
  virtual bool get_arg_string(lcid_type lcid,string_type& s)const=0;
};//class t_err_record_arg_string

////////////////////////////////////////////////////////////////////////////////
//class t_err_record_arg_string

template<class stringT,class Allocator>
class t_err_record_arg_string LCPI_CPP_CFG__CLASS__FINAL
 :public t_basic_smart_interface_impl__dynamic<t_err_record_arg<stringT>,Allocator>
{
 private:
  using self_type=t_err_record_arg_string<stringT,Allocator>;
  using inherited=t_basic_smart_interface_impl__dynamic<t_err_record_arg<stringT>,Allocator>;

  t_err_record_arg_string(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 protected:
  virtual ~t_err_record_arg_string();

 public: //typedefs ------------------------------------------------------
  using self_ptr    =t_smart_object_ptr<self_type>;
  using record_type =t_err_record;
  using string_type =typename inherited::string_type;
  using lcid_type   =typename inherited::lcid_type;

 public:
  t_err_record_arg_string()
  {
  }

  t_err_record_arg_string(const string_type& s)
   :m_str(s)
  {
  }

  //interface ------------------------------------------------------------
  virtual bool get_arg_string(lcid_type lcid,string_type& s)const;

 private:
  const string_type m_str;
};//class t_err_record_arg_string

////////////////////////////////////////////////////////////////////////////////
//class t_err_record_arg_source_name

template<class stringT,class StrCvtTraits,class Allocator>
class t_err_record_arg_source_name LCPI_CPP_CFG__CLASS__FINAL
 :public t_basic_smart_interface_impl__dynamic<t_err_record_arg<stringT>,Allocator>
{
 private:
  using self_type=t_err_record_arg_source_name<stringT,StrCvtTraits,Allocator>;
  using inherited=t_basic_smart_interface_impl__dynamic<t_err_record_arg<stringT>,Allocator>;

  t_err_record_arg_source_name(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  virtual ~t_err_record_arg_source_name();

 public: //typedefs ------------------------------------------------------
  using self_ptr    =t_smart_object_ptr<self_type>;
  using record_type =t_err_record;
  using string_type =typename inherited::string_type;
  using lcid_type   =typename inherited::lcid_type;

  using str_cvt_traits_type = StrCvtTraits;

 public:
  explicit t_err_record_arg_source_name(record_type* const x);

  //t_err_record_arg_source_name interface -------------------------------
  virtual bool get_arg_string(lcid_type lcid,string_type& s)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  typename record_type::self_ptr m_record;
};//class t_err_record_arg_source_name

////////////////////////////////////////////////////////////////////////////////
//class t_err_record_with_params2_base

template<class charT,class StrCvtTraits,class Allocator>
class t_err_record_with_params2_base
 :public t_basic_str_args2<charT,t_err_record_with_params2_base<charT,StrCvtTraits,Allocator>,t_str_args2_traits<charT,StrCvtTraits> >
 ,public t_basic_smart_interface_impl__dynamic<t_err_record,Allocator>

{
 private:
  using self_type=t_err_record_with_params2_base<charT,StrCvtTraits,Allocator>;

  using base_args_type=t_basic_str_args2<charT,self_type,t_str_args2_traits<charT,StrCvtTraits> >;

  t_err_record_with_params2_base(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using char_type
   =typename base_args_type::char_type;

  using arg_string_type
   =typename base_args_type::string_type;

  using arg_obj_type
   =structure::t_smart_interface;

  using arg_obj_ptr
   =t_smart_object_ptr<arg_obj_type>               ;

  using args_type
   =t_smart_vector<arg_obj_type>;

  using str_cvt_traits_type
   =StrCvtTraits;

  using record_arg_type
   =t_err_record_arg<arg_string_type>;

  using record_arg_string_type
   =t_err_record_arg_string<arg_string_type,Allocator>;

  using record_arg_source_name_type
   =t_err_record_arg_source_name<arg_string_type,str_cvt_traits_type,Allocator>;

 public:
  using string_type
   =typename t_err_record::string_type;

  using error_code_type
   =typename t_err_record::error_code_type;

  using system_id_type
   =typename t_err_record::system_id_type;

  using subsystem_id_type
   =typename t_err_record::subsystem_id_type;

  using lcid_type
   =typename t_err_record::lcid_type;

  using help_ctx_id_type
   =typename t_err_record::help_ctx_id_type;

 protected:
  t_err_record_with_params2_base();

  virtual ~t_err_record_with_params2_base();

 public:
  //selectors ------------------------------------------------------------
  const args_type& args()const
   {return m_args;}

  //convert utility ------------------------------------------------------
  static bool arg_to_str(lcid_type lcid,const arg_obj_type* const arg,arg_string_type& s);

  //base args interface --------------------------------------------------
  virtual self_type& add_arg(const arg_string_type& x);//abstract

  virtual self_type& add_arg__exc(const std::exception& e); //override

  //add argument objects -------------------------------------------------
  self_type& add_arg__obj(arg_obj_type* const x);

  self_type& add_arg__source(t_err_record* const x);

 private: //--------------------------------------------------------------
  friend base_args_type;

  static self_type& build_outer_type(base_args_type& x)
   {return *static_cast<self_type*>(&x);}

 private:
  args_type m_args;
};//class t_err_record_with_params2_base

////////////////////////////////////////////////////////////////////////////////
//class t_err_record_with_params2

//record_traits:
// typedefs
//  source_id_type
//  msg_id_type
//  help_file_id_type
//
//  record_data_ext_type - structure/class with additional record data
//
// methods
//  bool get_msg(lcid_type,msg_id_type,t_err_record::string_type&)const
//
//  void get_unknown_msg(lcid_type,t_err_record::string_type&)const
//
//  const char* get_critical_error_msg(lcid_type)const
//
//  bool get_source_name(lcid_type,source_id_type,t_err_record::string_type&)const
//
//  bool get_help_file(lcid_type,help_file_id_type,t_err_record::string_type&)const
//
//  [optional]
//  static system_id_type get_def_system_id()
//
//  static subsystem_id_type get_def_subsystem_id()
//
//  static error_code_type get_def_error_code()
//
//  static source_id_type get_def_source_id()

template<class record_traits,class charT,class StrCvtTraits,class Allocator>
class t_err_record_with_params2
 :public t_err_record_with_params2_base<charT,StrCvtTraits,Allocator>
 ,public record_traits::record_data_ext_type
{
 private:
  using self_type=t_err_record_with_params2<record_traits,charT,StrCvtTraits,Allocator>;
  using inherited=t_err_record_with_params2_base<charT,StrCvtTraits,Allocator>;

  t_err_record_with_params2(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using traits_type
   =record_traits;

  using self_ptr
   =t_smart_object_ptr<self_type>;

  using source_id_type
   =typename traits_type::source_id_type;

  using msg_id_type
   =typename traits_type::msg_id_type;

  using help_file_id_type
   =typename traits_type::help_file_id_type;

  using string_type
   =typename inherited::string_type;

  using error_code_type
   =typename inherited::error_code_type;

  using system_id_type
   =typename inherited::system_id_type;

  using subsystem_id_type
   =typename inherited::subsystem_id_type;

  using lcid_type
   =typename inherited::lcid_type;

  using help_ctx_id_type
   =typename inherited::help_ctx_id_type;

  using str_cvt_traits_type
   =typename inherited::str_cvt_traits_type;

 private:
  using arg_string_type
   =typename inherited::arg_string_type;

 public: //---------------------------------------------------------------
  traits_type       m_traits;

  system_id_type    m_system_id;
  subsystem_id_type m_subsystem_id;
  error_code_type   m_error_code;

  source_id_type    m_source_id;
  msg_id_type       m_msg_id;
  help_file_id_type m_help_file_id;
  help_ctx_id_type  m_help_ctx_id;

 public: //---------------------------------------------------------------
  t_err_record_with_params2();

  t_err_record_with_params2(system_id_type     system_id,
                           subsystem_id_type  subsystem_id,
                           error_code_type    error_code,
                           source_id_type     source_id,
                           msg_id_type        msg_id,
                           help_file_id_type  help_file_id,
                           help_ctx_id_type   help_ctx_id);

  virtual ~t_err_record_with_params2();

  //services -------------------------------------------------------------
  static system_id_type get_def_system_id()
   {return traits_type::get_def_system_id();}

  static subsystem_id_type get_def_subsystem_id()
   {return traits_type::get_def_subsystem_id();}

  static source_id_type get_def_source_id()
   {return traits_type::get_def_source_id();}

  //t_err_record interface -----------------------------------------------
  virtual const char*        what             ()const throw();

  virtual system_id_type     get_system_id    ()const;
  virtual subsystem_id_type  get_subsystem_id ()const;
  virtual error_code_type    get_error_code   ()const;

  virtual bool  get_description (lcid_type    lcid,
                                 string_type* source,
                                 string_type* description)const;

  virtual bool  get_help_info   (lcid_type         lcid,
                                 string_type*      help_file,
                                 help_ctx_id_type* help_context_id)const;

 private: //--------------------------------------------------------------
  bool build_description(lcid_type,string_type&)const;

 private:
  class tag_msgID_to_num___std LCPI_CPP_CFG__CLASS__FINAL
  {
   public:
    template<typename TMsgID>
    static TMsgID exec(TMsgID const x)
    {
     return x;
    }//exec
  };//class tag_msgID_to_num___std

  class tag_msgID_to_num___enum LCPI_CPP_CFG__CLASS__FINAL
  {
   public:
    template<typename TMsgID>
    static typename std::underlying_type<msg_id_type>::type exec(TMsgID const x)
    {
     return static_cast<typename std::underlying_type<msg_id_type>::type>(x);
    }//exec
  };//class tag_msgID_to_num___enum

  using tag_msgID_to_num
   =typename std::conditional
     <std::is_enum<msg_id_type>::value,
      tag_msgID_to_num___enum,
      tag_msgID_to_num___std>::type;

 private:
  mutable t_guard     m_what_guard;
  mutable std::string m_what;
};//class t_err_record_with_params2

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
#include <structure/error/t_err_record_with_params2.cc>
////////////////////////////////////////////////////////////////////////////////
#endif

