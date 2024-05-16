////////////////////////////////////////////////////////////////////////////////
//exception class for t_err_record_with_params
//                                                 Dmitry Kovalenko. 13.04.2024
#ifndef _t_err_exception_with_params2_H_
#define _t_err_exception_with_params2_H_

#include <structure/error/t_err_records.h>
#include <structure/t_exception.h>
#include <structure/t_str_args.h>
#include <structure/t_smart_vector.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class t_record,class charT,class StrCvtTraits,class Allocator>
class t_err_exception_with_params2;

////////////////////////////////////////////////////////////////////////////////
//class t_err_exception_with_params2

template<class t_record,class charT,class StrCvtTraits,class Allocator>
class t_err_exception_with_params2
 :virtual public t_exception
 ,public t_basic_str_args<wchar_t,t_err_exception_with_params2<t_record,charT,StrCvtTraits,Allocator> >
 ,public t_err_records_r
 ,public t_err_records_w
{
 private:
  using self_type      =t_err_exception_with_params2<t_record,charT,StrCvtTraits,Allocator>;
  using inherited      =t_exception;
  using base_args_type =t_basic_str_args<wchar_t,self_type>;

  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  using str_cvt_traits_type
   =StrCvtTraits;

  using char_type
   =typename base_args_type::char_type;

  using arg_type
   =typename base_args_type::string_type;

  typedef t_record                                          record_type;
  typedef typename record_type::self_ptr                    record_ptr;
  typedef typename record_type::system_id_type              system_id_type;
  typedef typename record_type::subsystem_id_type           subsystem_id_type;
  typedef typename record_type::error_code_type             error_code_type;
  typedef typename record_type::source_id_type              source_id_type;
  typedef typename record_type::msg_id_type                 msg_id_type;
  typedef typename record_type::help_file_id_type           help_file_id_type;
  typedef typename record_type::help_ctx_id_type            help_ctx_id_type;

  using record_vector
   =t_smart_vector<t_err_record,Allocator>;

  using size_type
   =size_t;

 public:
  t_err_exception_with_params2(const self_type& x);

  explicit t_err_exception_with_params2(const std::exception& exc);

  explicit t_err_exception_with_params2(record_type* record)=delete;

  t_err_exception_with_params2(system_id_type     system_id,
                              subsystem_id_type  subsystem_id,
                              error_code_type    error_code,
                              source_id_type     source_id,
                              msg_id_type        msg_id,
                              help_file_id_type  help_file_id,
                              help_ctx_id_type   help_ctx_id);

  t_err_exception_with_params2(source_id_type source_id,
                              msg_id_type    msg_id);

  explicit t_err_exception_with_params2(msg_id_type msg_id);

  virtual ~t_err_exception_with_params2() LCPI_STL_EXCEPTION_DCR_THROW_SPEC;

  //selectors ------------------------------------------------------------
  const record_ptr& cur_record()const
   {return m_cur_record;}

  const record_vector& records()const
   {return m_records;}

  //exception interface --------------------------------------------------
  virtual const char* what()const throw() LCPI_CPP_CFG__METHOD__OVERRIDE;

  //t_exception interface ------------------------------------------------
  LCPI_CPP_CFG__DECLSPEC__NORETURN virtual void raise()const LCPI_CPP_CFG__METHOD__OVERRIDE;

  //t_error_with_params_base interface -----------------------------------
  virtual self_type& add_arg(const arg_type& arg) LCPI_CPP_CFG__METHOD__OVERRIDE;//abstract

  virtual self_type& add_arg__exc(const std::exception& e) LCPI_CPP_CFG__METHOD__OVERRIDE; //override

  //t_err_records interface ----------------------------------------------
  virtual size_t get_record_count()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual t_err_record::self_ptr get_record(size_t record_num)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  //! \brief
  //!  Add new err_record to collection. Current error_record reset to NULL.
  virtual void add_record(t_err_record* record) LCPI_CPP_CFG__METHOD__OVERRIDE;

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
};//class t_err_exception_with_params2

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
#include <structure/error/t_err_exception_with_params2.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
