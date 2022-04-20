////////////////////////////////////////////////////////////////////////////////
//exception class for t_err_record_with_params
//                                                 Dmitry Kovalenko. 16.08.2004
#ifndef _t_err_exception_with_params_H_
#define _t_err_exception_with_params_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <structure/error/t_err_records.h>
#include <structure/t_exception.h>
#include <structure/t_str_args.h>
#include <structure/t_smart_vector.h>
#include <structure/t_dummy.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class t_record,class charT=typename t_record::char_type>
class t_err_exception_with_params;

////////////////////////////////////////////////////////////////////////////////
//class t_err_exception_with_params

//t_record
// typedefs
//  - self_ptr
//
// methods
//  - add_arg(const arg_type&)
//  - const char* what()

template<class t_record,class charT>
class t_err_exception_with_params
       :virtual public t_exception
       ,public t_basic_str_args<charT,t_err_exception_with_params<t_record,charT> >
       ,public t_err_records_r
       ,public t_err_records_w
{
 private:
  typedef t_err_exception_with_params<t_record,charT>       self_type;
  typedef t_exception                                       inherited;
  typedef t_basic_str_args<charT,self_type>                 base_args_type;

  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef typename base_args_type::char_type                char_type;
  typedef typename base_args_type::string_type              arg_type;

  typedef t_record                                          record_type;
  typedef typename record_type::self_ptr                    record_ptr;
  typedef typename record_type::system_id_type              system_id_type;
  typedef typename record_type::subsystem_id_type           subsystem_id_type;
  typedef typename record_type::error_code_type             error_code_type;
  typedef typename record_type::source_id_type              source_id_type;
  typedef typename record_type::msg_id_type                 msg_id_type;
  typedef typename record_type::help_file_id_type           help_file_id_type;
  typedef typename record_type::help_ctx_id_type            help_ctx_id_type;

  typedef typename t_smart_vector<t_err_record>             record_vector;

  typedef size_t                                            size_type;

 public:
  //Временный вариант. Лет на 100. Изменено поведение конструктора по-умолчанию.
  // Поэтому добавлен этот параметр t_dummy
  explicit t_err_exception_with_params(const structure::t_dummy&);

  t_err_exception_with_params(const self_type& x);

  explicit t_err_exception_with_params(const std::exception& exc);

 #if 0 //03.06.2007, 05.06.2019
  explicit t_err_exception_with_params(record_type* record);
#endif

  t_err_exception_with_params(system_id_type     system_id,
                              subsystem_id_type  subsystem_id,
                              error_code_type    error_code,
                              source_id_type     source_id,
                              msg_id_type        msg_id,
                              help_file_id_type  help_file_id,
                              help_ctx_id_type   help_ctx_id);

  t_err_exception_with_params(source_id_type source_id,
                              msg_id_type    msg_id);

  explicit t_err_exception_with_params(msg_id_type msg_id);

  virtual ~t_err_exception_with_params() __STL_EXCEPTION_DCR_THROW_SPEC;

  //selectors ------------------------------------------------------------
  const record_ptr& cur_record()const
   {return m_cur_record;}

  const record_vector& records()const
   {return m_records;}

  //exception interface --------------------------------------------------
  virtual const char* what()const throw() COMP_W000004_OVERRIDE;

  //t_exception interface ------------------------------------------------
  COMP_CONF_DECLSPEC_NORETURN virtual void raise()const COMP_W000004_OVERRIDE;

  //t_error_with_params_base interface -----------------------------------
  virtual self_type& add_arg(const arg_type& arg) COMP_W000004_OVERRIDE;//abstract

  virtual self_type& add_arg__exc(const std::exception& e) COMP_W000004_OVERRIDE; //override

  //t_err_records interface ----------------------------------------------
  virtual size_t get_record_count()const COMP_W000004_OVERRIDE_FINAL;

  virtual t_err_record::self_ptr get_record(size_t record_num)const COMP_W000004_OVERRIDE_FINAL;

  //! \brief
  //!  Add new err_record to collection. Current error_record reset to NULL.
  virtual void add_record(t_err_record* record) COMP_W000004_OVERRIDE;

  //add error record argument object -------------------------------------
  self_type& add_arg__obj(typename record_type::arg_obj_type* obj);

  self_type& add_arg__source(t_err_record* x);

  //----------------------------------------------------------------------
  self_type& add(const std::exception& exc);

  //----------------------------------------------------------------------
  self_type& add_error(source_id_type source_id,
                       msg_id_type    msg_id);

 private: //--------------------------------------------------------------
  friend base_args_type;

  static self_type& build_outer_type(base_args_type& x)
  {
   return *static_cast<self_type*>(&x);
  }

 private:
  record_ptr      m_cur_record;
  record_vector   m_records;
};//class t_err_exception_with_params

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
#include <structure/error/t_err_exception_with_params.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
