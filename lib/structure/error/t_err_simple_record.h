////////////////////////////////////////////////////////////////////////////////
//Simple implementation of t_err_record
//                                            Dmitry Kovalenko. 15.08.2004.
#ifndef _t_err_simple_record_H_
#define _t_err_simple_record_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <structure/error/t_err_record.h>
#include <structure/t_smart_object.h>
#include <structure/t_str_parameter.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containing

template<class Allocator>
class t_err_basic_record_v2;

////////////////////////////////////////////////////////////////////////////////
//typedefs

typedef t_err_basic_record_v2<t_void_allocator>   t_err_simple_record;

////////////////////////////////////////////////////////////////////////////////
//class t_err_basic_record

template<class Allocator>
class t_err_basic_record_v2
 :public t_basic_smart_interface_impl__dynamic<t_err_record,Allocator>
{
 private:
  typedef t_err_basic_record_v2                                 self_type;
  typedef t_basic_smart_interface_impl__dynamic<t_err_record,
                                                Allocator>      inherited;

  t_err_basic_record_v2(const self_type&);
  self_type& operator = (const self_type&);

 protected:
  virtual ~t_err_basic_record_v2();

 public: //typedefs ------------------------------------------------------
  typedef t_smart_object_ptr<self_type>             self_ptr;

  typedef typename inherited::string_type           string_type;
  typedef typename inherited::error_code_type       error_code_type;
  typedef typename inherited::system_id_type        system_id_type;
  typedef typename inherited::subsystem_id_type     subsystem_id_type;
  typedef typename inherited::lcid_type             lcid_type;
  typedef typename inherited::help_ctx_id_type      help_ctx_id_type;

  typedef t_str_parameter<typename string_type::value_type>  str_param_type;

 public: //---------------------------------------------------------------
  system_id_type     m_system_id;
  subsystem_id_type  m_subsystem_id;
  error_code_type    m_error_code;
  string_type        m_source;
  string_type        m_description;
  string_type        m_help_file;
  help_ctx_id_type   m_help_ctx_id;

 public: //---------------------------------------------------------------
  t_err_basic_record_v2();

  t_err_basic_record_v2(system_id_type    system_id,
                        subsystem_id_type subsystem_id,
                        error_code_type   error_code,
                        str_param_type    source,
                        str_param_type    description,
                        str_param_type    help_file,
                        help_ctx_id_type  help_ctx_id);

  //t_err_record interface -----------------------------------------------
  virtual const char*        what             ()const throw() COMP_W000004_OVERRIDE_FINAL;

  virtual system_id_type     get_system_id    ()const COMP_W000004_OVERRIDE_FINAL;
  virtual subsystem_id_type  get_subsystem_id ()const COMP_W000004_OVERRIDE_FINAL;
  virtual error_code_type    get_error_code   ()const COMP_W000004_OVERRIDE_FINAL;

  virtual bool  get_description (lcid_type    lcid,
                                 string_type* source,
                                 string_type* description)const COMP_W000004_OVERRIDE_FINAL;

  virtual bool  get_help_info   (lcid_type         lcid,
                                 string_type*      help_file,
                                 help_ctx_id_type* help_context_id)const COMP_W000004_OVERRIDE_FINAL;
 private:
  mutable std::string m_what;
};//class t_err_basic_record_v2

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/error/t_err_simple_record.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
