////////////////////////////////////////////////////////////////////////////////
#ifndef _t_err_exception_with_params_CC_
#define _t_err_exception_with_params_CC_

#include <structure/error/t_err_simple_record.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_err_exception_with_params

template<class t_record,class charT>
t_err_exception_with_params<t_record,charT>::t_err_exception_with_params
                                           (const structure::t_dummy&)
{;}

//------------------------------------------------------------------------
template<class t_record,class charT>
t_err_exception_with_params<t_record,charT>::t_err_exception_with_params
                                           (const self_type& x)
 :inherited    (x)
 ,m_cur_record (x.m_cur_record)
 ,m_records    (x.m_records)
{;}

//------------------------------------------------------------------------
 #if 0 //03.06.2007, 05.06.2019

template<class t_record,class charT>
t_err_exception_with_params<t_record,charT>::t_err_exception_with_params
                                           (record_type* const record)
 :m_cur_record(record)
{
 assert(m_cur_record);

 if(m_cur_record)
  m_records.push_back(m_cur_record);
}//t_err_exception_with_params

#endif

//------------------------------------------------------------------------
template<class t_record,class charT>
t_err_exception_with_params<t_record,charT>::t_err_exception_with_params
                                           (const std::exception& exc)
{
 this->add(exc);
}//t_err_exception_with_params

//------------------------------------------------------------------------
template<class t_record,class charT>
t_err_exception_with_params<t_record,charT>::t_err_exception_with_params
                                             (system_id_type    const system_id,
                                              subsystem_id_type const subsystem_id,
                                              error_code_type   const error_code,
                                              source_id_type    const source_id,
                                              msg_id_type       const msg_id,
                                              help_file_id_type const help_file_id,
                                              help_ctx_id_type  const help_ctx_id)
 :m_cur_record(structure::not_null_ptr
                (new record_type(system_id,
                                 subsystem_id,
                                 error_code,
                                 source_id,
                                 msg_id,
                                 help_file_id,
                                 help_ctx_id)))
{
 assert(m_cur_record);

 m_records.push_back(m_cur_record); //throw
}//t_err_exception_with_params

//------------------------------------------------------------------------
template<class t_record,class charT>
t_err_exception_with_params<t_record,charT>::t_err_exception_with_params
                               (source_id_type const source_id,
                                msg_id_type    const msg_id)
 :m_cur_record(structure::not_null_ptr
                (new record_type(record_type::get_def_system_id(),
                                 record_type::get_def_subsystem_id(),
                                 static_cast<error_code_type>(msg_id),
                                 source_id,
                                 msg_id,
                                 0,0)))
{
 assert(m_cur_record);

 m_records.push_back(m_cur_record); //throw
}//t_err_exception_with_params

//------------------------------------------------------------------------
template<class t_record,class charT>
t_err_exception_with_params<t_record,charT>::t_err_exception_with_params
                               (msg_id_type const msg_id)
 :m_cur_record(structure::not_null_ptr
                (new record_type(record_type::get_def_system_id(),
                                 record_type::get_def_subsystem_id(),
                                 static_cast<error_code_type>(msg_id),
                                 record_type::get_def_source_id(),
                                 msg_id,
                                 0,0)))
{
 assert(m_cur_record);

 m_records.push_back(m_cur_record); //throw
}//t_err_exception_with_params

//------------------------------------------------------------------------
template<class t_record,class charT>
t_err_exception_with_params<t_record,charT>::~t_err_exception_with_params()__STL_EXCEPTION_DCR_THROW_SPEC
{;}

//exception interface ----------------------------------------------------
template<class t_record,class charT>
const char* t_err_exception_with_params<t_record,charT>::what()const throw()
{
 assert(!m_records.empty());

 if(m_records.empty())
  return "Error without description.";

 //Description of first error.
 return m_records.front()->what();
}//what

//t_exception interface --------------------------------------------------
template<class t_record,class charT>
void t_err_exception_with_params<t_record,charT>::raise()const
{
 //Internal error? - empty err_records list
 assert(!m_records.empty());

 throw *this;
}//raise

//t_error_with_params_base interface -------------------------------------
template<class t_record,class charT>
t_err_exception_with_params<t_record,charT>&
 t_err_exception_with_params<t_record,charT>::add_arg(const arg_type& arg)
{
 assert(m_cur_record);

 m_cur_record->add_arg(arg);

 return *this;
}//add_arg

//t_err_records interface ------------------------------------------------

template<class t_record,class charT>
size_t
 t_err_exception_with_params<t_record,charT>::get_record_count()const
{
 return m_records.size();
}//get_record_count

//------------------------------------------------------------------------
template<class t_record,class charT>
t_err_record::self_ptr
 t_err_exception_with_params<t_record,charT>::get_record(size_t record_num)const
{
 assert(record_num<m_records.size());

 return m_records[record_num];
}//get_record

//------------------------------------------------------------------------
template<class t_record,class charT>
void t_err_exception_with_params<t_record,charT>::add_record(t_err_record* const record)
{
 assert(record);
 
#ifndef NDEBUG
 assert(std::find(m_records.begin(),m_records.end(),record)==m_records.end());
#endif

 m_records.emplace_back(structure::not_null_ptr(record)); //throw

 m_cur_record.Release();
}//add_record

//add error record argument object ---------------------------------------
template<class t_record,class charT>
t_err_exception_with_params<t_record,charT>&
 t_err_exception_with_params<t_record,charT>::add_arg__exc
                                           (const std::exception& e)
{
 assert(m_cur_record);

 m_cur_record->add_arg__exc(e);

 return *this;
}//add_arg__exc

//------------------------------------------------------------------------
template<class t_record,class charT>
t_err_exception_with_params<t_record,charT>&
 t_err_exception_with_params<t_record,charT>::add_arg__obj
                                           (typename self_type::record_type::arg_obj_type* const obj)
{
 assert(m_cur_record);
 assert(obj);

 m_cur_record->add_arg__obj(obj);

 return *this;
}//add_arg__obj

//------------------------------------------------------------------------
template<class t_record,class charT>
t_err_exception_with_params<t_record,charT>&
 t_err_exception_with_params<t_record,charT>::add_arg__source(t_err_record* const x)
{
 assert(m_cur_record);
 assert(x);

 m_cur_record->add_arg__source(x);

 return *this;
}//add_arg__source

//------------------------------------------------------------------------
template<class t_record,class charT>
t_err_exception_with_params<t_record,charT>&
 t_err_exception_with_params<t_record,charT>::add(const std::exception& exc)
{
 if(&exc==this)
  return *this;

 m_cur_record.Release();

 if(const t_err_records_r* const x=dynamic_cast<const t_err_records_r*>(&exc))
 {
  for(size_t i(0),_c(x->get_record_count());i!=_c;++i)
  {
   const t_err_record::self_ptr err_record(x->get_record(i));

   assert(err_record);

   if(err_record)
    this->add_record(err_record);
  }//for

  return *this;
 }//if - t_err_records_r

 //create simple err_record for this exception
 typedef t_err_simple_record simple_record_type;

 const simple_record_type::self_ptr
  simple_err_record(structure::not_null_ptr(new simple_record_type()));

 tstr_to_tstr(&simple_err_record->m_source,L"unknown");

 tstr_to_tstr(&simple_err_record->m_description,exc.what());

 this->add_record(simple_err_record);

 return *this;
}//add

//------------------------------------------------------------------------
template<class t_record,class charT>
t_err_exception_with_params<t_record,charT>&
 t_err_exception_with_params<t_record,charT>::add_error(source_id_type const source_id,
                                                        msg_id_type    const msg_id)
{
 record_ptr x
  =structure::not_null_ptr
     (new record_type
        (record_type::get_def_system_id(),
         record_type::get_def_subsystem_id(),
         /*error_code*/msg_id,
         source_id,
         msg_id,
         /*help_file_id*/0,
         /*help_ctx_id*/0)); //throw

 assert(x);

 m_records.emplace_back(structure::not_null_ptr(x.ptr())); //throw

 assert(!m_records.empty());

 assert(x);

 m_cur_record.swap(x);

 assert(m_cur_record);
 assert(m_cur_record==m_records.back().ptr());

 return *this;
}//add_error

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
#endif
