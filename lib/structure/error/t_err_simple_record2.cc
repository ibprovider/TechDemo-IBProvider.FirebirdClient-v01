////////////////////////////////////////////////////////////////////////////////
#ifndef _t_err_simple_record_CC_
#define _t_err_simple_record_CC_

#include <structure/mt/t_lock_guard.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_err_simple_record2

template<class StrCvtTraits,class Allocator>
t_err_simple_record2<StrCvtTraits,Allocator>::t_err_simple_record2()
 :m_system_id    (t_err_record::system_user)
 ,m_subsystem_id (0)
 ,m_error_code   (0)
 ,m_help_ctx_id  (0)
{
}

//------------------------------------------------------------------------
template<class StrCvtTraits,class Allocator>
t_err_simple_record2<StrCvtTraits,Allocator>::t_err_simple_record2
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
template<class StrCvtTraits,class Allocator>
t_err_simple_record2<StrCvtTraits,Allocator>::~t_err_simple_record2()
{
}

//t_err_record interface -------------------------------------------------
template<class StrCvtTraits,class Allocator>
const char* t_err_simple_record2<StrCvtTraits,Allocator>::what()const throw()
{
 t_lock_guard<t_guard> __lock(m_what_guard);

 try
 {
  try
  {
   str_cvt_traits_type::tstr_to_tstr(&m_what,m_description);
  }
  catch(...)
  {
   m_what="[t_err_simple_record2::what] Translation into multibyte string failed.";
  }
 }
 catch(...)
 {
  return "[t_err_simple_record2::what] critical error";
 }

 return m_what.c_str();
}//what

//------------------------------------------------------------------------
template<class StrCvtTraits,class Allocator>
typename t_err_simple_record2<StrCvtTraits,Allocator>::system_id_type
 t_err_simple_record2<StrCvtTraits,Allocator>::get_system_id()const
{
 return m_system_id;
}//get_system_id

//------------------------------------------------------------------------
template<class StrCvtTraits,class Allocator>
typename t_err_simple_record2<StrCvtTraits,Allocator>::subsystem_id_type
 t_err_simple_record2<StrCvtTraits,Allocator>::get_subsystem_id()const
{
 return m_subsystem_id;
}//get_subsystem_id

//------------------------------------------------------------------------
template<class StrCvtTraits,class Allocator>
typename t_err_simple_record2<StrCvtTraits,Allocator>::error_code_type
 t_err_simple_record2<StrCvtTraits,Allocator>::get_error_code()const
{
 return m_error_code;
}//get_error_code

//------------------------------------------------------------------------
template<class StrCvtTraits,class Allocator>
bool t_err_simple_record2<StrCvtTraits,Allocator>::get_description
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
template<class StrCvtTraits,class Allocator>
bool t_err_simple_record2<StrCvtTraits,Allocator>::get_help_info
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