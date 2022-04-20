////////////////////////////////////////////////////////////////////////////////
#ifndef _t_err_record_with_params_CC_
#define _t_err_record_with_params_CC_

#include <structure/error/t_err_records.h>
#include <structure/t_str_formatter.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_err_record_arg_string

template<class t_string>
t_err_record_arg_string<t_string>::~t_err_record_arg_string()
{;}

//------------------------------------------------------------------------
template<class t_string>
bool t_err_record_arg_string<t_string>::get_arg_string(lcid_type,string_type& s)const
{
 s=m_str;

 return true;
}//get_arg_string

////////////////////////////////////////////////////////////////////////////////
//class t_err_record_arg_source_name

template<class t_string>
RELEASE_CODE(inline)
t_err_record_arg_source_name<t_string>::t_err_record_arg_source_name(record_type* const x)
 :m_record(not_null_ptr(x))
{
 assert(m_record);
}

//------------------------------------------------------------------------
template<class t_string>
t_err_record_arg_source_name<t_string>::~t_err_record_arg_source_name()
{;}

//------------------------------------------------------------------------
template<class t_string>
bool t_err_record_arg_source_name<t_string>::get_arg_string(lcid_type lcid,string_type& s)const
{
 assert(m_record);

 record_type::string_type t;

 if(!m_record->get_description(lcid,&t,NULL))
  return false;

 tstr_to_tstr(/*dest*/&s,/*source*/t);

 return true;
}//get_arg_string

////////////////////////////////////////////////////////////////////////////////
//class t_err_record_with_params_base

template<class charT>
t_err_record_with_params_base<charT>::t_err_record_with_params_base()
{;}

//------------------------------------------------------------------------
template<class charT>
t_err_record_with_params_base<charT>::~t_err_record_with_params_base()
{;}

//convert utility --------------------------------------------------------
template<class charT>
bool t_err_record_with_params_base<charT>::arg_to_str(lcid_type                 lcid,
                                                      const arg_obj_type* const arg,
                                                      arg_string_type&          str)
{
 if(const record_arg_string_type* const x=dynamic_cast<const record_arg_string_type*>(arg))
 {
  return x->get_arg_string(lcid,str);
 }

 if(const t_err_record* const x=dynamic_cast<const t_err_record*>(arg))
 {
  string_type rs;

  x->get_description(lcid,NULL,&rs);

  tstr_to_tstr(/*dest*/&str,/*source*/rs);

  return true;
 }//if

 return false;
}//arg_to_str

//t_basic_str_args interface ---------------------------------------------
template<class charT>
t_err_record_with_params_base<charT>&
 t_err_record_with_params_base<charT>::add_arg(const arg_string_type& x)
{
 const arg_obj_ptr sp(not_null_ptr(new record_arg_string_type(x)));

 //! \todo
 //!  Use move operation
 m_args.push_back(sp);

 return *this;
}//add_arg

//------------------------------------------------------------------------
template<class charT>
t_err_record_with_params_base<charT>&
 t_err_record_with_params_base<charT>::add_arg__exc(const std::exception& e)
{
 if(const auto* const x=dynamic_cast<const t_err_records_r*>(&e))
 {
  if(x->get_record_count()!=0)
   return this->add_arg__obj(x->get_record(0));
 }//if

 arg_string_type s;

 return this->add_arg(tstr_to_tstr(&s,e.what()));
}//add_arg__exc

//------------------------------------------------------------------------
template<class charT>
t_err_record_with_params_base<charT>&
 t_err_record_with_params_base<charT>::add_arg__source(t_err_record* const x)
{
 assert(x);
 assert(this!=x);

 const arg_obj_ptr sp(new record_arg_source_name_type(x));

 m_args.push_back(sp);

 return *this;
}//add_arg__source

//------------------------------------------------------------------------
template<class charT>
RELEASE_CODE(inline)
t_err_record_with_params_base<charT>&
 t_err_record_with_params_base<charT>::add_arg__obj(arg_obj_type* const x)
{
 assert(x);

 m_args.push_back(x);

 return *this;
}//add_arg__obj

////////////////////////////////////////////////////////////////////////////////
//class t_err_record_with_params

template<class record_traits,class charT>
t_err_record_with_params<record_traits,charT>::t_err_record_with_params()
 :m_system_id     (traits_type::get_def_system_id()),
  m_subsystem_id  (traits_type::get_def_subsystem_id()),
  m_error_code    (traits_type::get_def_error_code()),
  m_source_id     (source_id_type()),
  m_msg_id        (msg_id_type()),
  m_help_file_id  (help_file_id_type()),
  m_help_ctx_id   (0)
{;}

//------------------------------------------------------------------------
template<class record_traits,class charT>
t_err_record_with_params<record_traits,charT>::t_err_record_with_params
                          (system_id_type     system_id,
                           subsystem_id_type  subsystem_id,
                           error_code_type    error_code,
                           source_id_type     source_id,
                           msg_id_type        msg_id,
                           help_file_id_type  help_file_id,
                           help_ctx_id_type   help_ctx_id)
 :m_system_id     (system_id),
  m_subsystem_id  (subsystem_id),
  m_error_code    (error_code),
  m_source_id     (source_id),
  m_msg_id        (msg_id),
  m_help_file_id  (help_file_id),
  m_help_ctx_id   (help_ctx_id)
{;}

//------------------------------------------------------------------------
template<class record_traits,class charT>
t_err_record_with_params<record_traits,charT>::~t_err_record_with_params()
{;}

//t_err_record interface -------------------------------------------------
template<class record_traits,class charT>
const char* t_err_record_with_params<record_traits,charT>::what()const throw()
{
 try
 {
  string_type source;
  string_type description;

  this->get_description(lcid_type(),&source,&description);

  if(source.empty())
  {
   tstr_to_tstr(&m_what,description);
  }
  else
  {
   source.reserve(source.size()+description.size()+3);

   source.insert(0,L"[").append(L"]:").append(description);

   tstr_to_tstr(&m_what,source);
  }
 }
 catch(...)
 {
  return m_traits.get_critical_error_msg(lcid_type());
 }

 return m_what.c_str();
}//what

//------------------------------------------------------------------------
template<class record_traits,class charT>
typename t_err_record_with_params<record_traits,charT>::system_id_type
 t_err_record_with_params<record_traits,charT>::get_system_id()const
{
 return m_system_id;
}//get_system_id

//------------------------------------------------------------------------
template<class record_traits,class charT>
typename t_err_record_with_params<record_traits,charT>::subsystem_id_type
 t_err_record_with_params<record_traits,charT>::get_subsystem_id()const
{
 return m_subsystem_id;
}//get_subsystem_id

//------------------------------------------------------------------------
template<class record_traits,class charT>
typename t_err_record_with_params<record_traits,charT>::error_code_type
 t_err_record_with_params<record_traits,charT>::get_error_code()const
{
 return m_error_code;
}//get_error_code

//------------------------------------------------------------------------
template<class record_traits,class charT>
bool t_err_record_with_params<record_traits,charT>::get_description
                                     (lcid_type    lcid,
                                      string_type* source,
                                      string_type* description)const
{
 const bool r1=description?this->build_description(lcid,*description):true;

 const bool r2=source?m_traits.get_source_name(lcid,m_source_id,*source):true;

 return r1 && r2;
}//get_description

//------------------------------------------------------------------------
template<class record_traits,class charT>
bool t_err_record_with_params<record_traits,charT>::get_help_info
                                     (lcid_type         lcid,
                                      string_type*      help_file,
                                      help_ctx_id_type* help_ctx_id)const
{
 if(help_ctx_id)
  *help_ctx_id=m_help_ctx_id;

 if(help_file)
  return m_traits.get_help_file(lcid,m_help_file_id,*help_file);

 return true;
}//get_help_file

//------------------------------------------------------------------------
template<class record_traits,class charT>
bool t_err_record_with_params<record_traits,charT>::build_description
                                     (lcid_type lcid,string_type& msg)const
{
 msg.erase();

 structure::wstr_formatter fmsg;

 string_type s;

 const bool res=m_traits.get_msg(lcid,m_msg_id,s);

 if(!res)
 {
  m_traits.get_unknown_msg(lcid,s);

  fmsg(s)<<tag_msgID_to_num::exec(m_msg_id);
 }
 else
 {
  fmsg(s);

  arg_string_type s_arg;

  for(auto i(this->args().cbegin()),_e(this->args().cend());i!=_e;++i)
  {
   if(self_type::arg_to_str(lcid,*i,s_arg.erase()))
    fmsg<<s_arg;
   else
    fmsg<<L"?unk_arg_type?";
  }//for
 }//else

 msg=fmsg.str();

 return res;
}//build_description

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
