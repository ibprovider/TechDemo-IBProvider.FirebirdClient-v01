////////////////////////////////////////////////////////////////////////////////
//Simple implementation of t_err_record
//                                            Dmitry Kovalenko. 15.08.2004.
#ifndef _t_err_simple_record_H_
#define _t_err_simple_record_H_

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

using t_err_simple_record=t_err_basic_record_v2<t_void_allocator>;

////////////////////////////////////////////////////////////////////////////////
//class t_err_basic_record

template<class Allocator>
class t_err_basic_record_v2
 :public t_basic_smart_interface_impl__dynamic<t_err_record,Allocator>
{
 private:
  using self_type=t_err_basic_record_v2;
  using inherited=t_basic_smart_interface_impl__dynamic<t_err_record,Allocator>;

  t_err_basic_record_v2(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 protected:
  virtual ~t_err_basic_record_v2();

 public: //typedefs ------------------------------------------------------
  using self_ptr          = t_smart_object_ptr<self_type>;

  using string_type       = typename inherited::string_type;
  using error_code_type   = typename inherited::error_code_type;
  using system_id_type    = typename inherited::system_id_type;
  using subsystem_id_type = typename inherited::subsystem_id_type;
  using lcid_type         = typename inherited::lcid_type;
  using help_ctx_id_type  = typename inherited::help_ctx_id_type;

  using str_param_type    = t_str_parameter<typename string_type::value_type>;

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
  virtual const char*        what             ()const throw() LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual system_id_type     get_system_id    ()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
  virtual subsystem_id_type  get_subsystem_id ()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
  virtual error_code_type    get_error_code   ()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool  get_description (lcid_type    lcid,
                                 string_type* source,
                                 string_type* description)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool  get_help_info   (lcid_type         lcid,
                                 string_type*      help_file,
                                 help_ctx_id_type* help_context_id)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
 private:
  mutable std::string m_what;
};//class t_err_basic_record_v2

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/error/t_err_simple_record.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
