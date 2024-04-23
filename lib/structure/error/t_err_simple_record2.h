////////////////////////////////////////////////////////////////////////////////
//Simple implementation of t_err_record
//                                                 Dmitry Kovalenko. 12.04.2024.
#ifndef _t_err_simple_record2_H_
#define _t_err_simple_record2_H_

#include <structure/error/t_err_record.h>
#include <structure/mt/t_guard.h>
#include <structure/t_smart_object.h>
#include <structure/t_str_parameter.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<class StrCvtTraits,class Allocator>
class t_err_simple_record2;

////////////////////////////////////////////////////////////////////////////////
//class t_err_basic_record

template<class StrCvtTraits,class Allocator>
class t_err_simple_record2
 :public t_basic_smart_interface_impl__dynamic<t_err_record,Allocator>
{
 private:
  using self_type=t_err_simple_record2;

  t_err_simple_record2(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 protected:
  virtual ~t_err_simple_record2();

 public: //typedefs ------------------------------------------------------
  using str_cvt_traits_type = StrCvtTraits;

  using self_ptr            = t_smart_object_ptr<self_type>;

  using string_type         = typename t_err_record::string_type;
  using error_code_type     = typename t_err_record::error_code_type;
  using system_id_type      = typename t_err_record::system_id_type;
  using subsystem_id_type   = typename t_err_record::subsystem_id_type;
  using lcid_type           = typename t_err_record::lcid_type;
  using help_ctx_id_type    = typename t_err_record::help_ctx_id_type;

  using str_param_type      = t_str_parameter<typename string_type::value_type>;

 public: //---------------------------------------------------------------
  system_id_type     m_system_id;
  subsystem_id_type  m_subsystem_id;
  error_code_type    m_error_code;
  string_type        m_source;
  string_type        m_description;
  string_type        m_help_file;
  help_ctx_id_type   m_help_ctx_id;

 public: //---------------------------------------------------------------
  t_err_simple_record2();

  t_err_simple_record2(system_id_type    system_id,
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
  mutable t_guard     m_what_guard;
  mutable std::string m_what;
};//class t_err_simple_record2

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/error/t_err_simple_record2.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
