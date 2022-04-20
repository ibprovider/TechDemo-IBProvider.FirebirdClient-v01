////////////////////////////////////////////////////////////////////////////////
#ifndef _t_err_simple_record_CC_
#define _t_err_simple_record_CC_

#include <structure/t_char_converter.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_err_basic_record_v2

template<class Allocator>
t_err_basic_record_v2<Allocator>::t_err_basic_record_v2()
 :m_system_id    (inherited::system_user)
 ,m_subsystem_id (0)
 ,m_error_code   (0)
 ,m_help_ctx_id  (0)
{
}

//------------------------------------------------------------------------
template<class Allocator>
t_err_basic_record_v2<Allocator>::t_err_basic_record_v2
                                           (system_id_type    const system_id,
                                            subsystem_id_type const subsystem_id,
                                            error_code_type   const error_code,
                                            str_param_type    const source,
                                            str_param_type    const description,
                                            str_param_type    const help_file,
                                            help_ctx_id_type  const help_ctx_id)
 :m_system_id    (system_id)
 ,m_subsystem_id (subsystem_id)
 ,m_error_code   (error_code)
 ,m_source       (source.str())
 ,m_description  (description.str())
 ,m_help_file    (help_file.str())
 ,m_help_ctx_id  (help_ctx_id)
{
}

//------------------------------------------------------------------------
template<class Allocator>
t_err_basic_record_v2<Allocator>::~t_err_basic_record_v2()
{
}

//t_err_record interface -------------------------------------------------
template<class Allocator>
const char* t_err_basic_record_v2<Allocator>::what()const throw()
{
 try
 {
  tstr_to_tstr(&m_what,m_description);
 }
 catch(...)
 {
  return "[t_err_basic_record_v2::what] critical error";
 }

 return m_what.c_str();
}//what

//------------------------------------------------------------------------
template<class Allocator>
typename t_err_basic_record_v2<Allocator>::system_id_type
 t_err_basic_record_v2<Allocator>::get_system_id()const
{
 return m_system_id;
}//get_system_id

//------------------------------------------------------------------------
template<class Allocator>
typename t_err_basic_record_v2<Allocator>::subsystem_id_type
 t_err_basic_record_v2<Allocator>::get_subsystem_id()const
{
 return m_subsystem_id;
}//get_subsystem_id

//------------------------------------------------------------------------
template<class Allocator>
typename t_err_basic_record_v2<Allocator>::error_code_type
 t_err_basic_record_v2<Allocator>::get_error_code()const
{
 return m_error_code;
}//get_error_code

//------------------------------------------------------------------------
template<class Allocator>
bool t_err_basic_record_v2<Allocator>::get_description
                                                (lcid_type    const /*lcid*/,
                                                 string_type* const source,
                                                 string_type* const description)const
{
 if(source)
  (*source)=m_source;

 if(description)
  (*description)=m_description;

 return true;
}//get_description

//------------------------------------------------------------------------
template<class Allocator>
bool t_err_basic_record_v2<Allocator>::get_help_info
                                                (lcid_type         const /*lcid*/,
                                                 string_type*      const help_file,
                                                 help_ctx_id_type* const help_context)const
{
 if(help_file)
  (*help_file)=m_help_file;

 if(help_context)
  (*help_context)=m_help_ctx_id;

 return true;
}//get_help_info

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif