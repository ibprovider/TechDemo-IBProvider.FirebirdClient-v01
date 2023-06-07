////////////////////////////////////////////////////////////////////////////////
//Classes of exception for WIN32-errors
//                                              Dmitry Kovalenko. 12.04.2004.
#ifndef _win32_error_H_
#define _win32_error_H_

#include <win32Lib/win32_base.h>
#include <structure/t_exception.h>
#include <structure/t_str_parameter.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//containings

class t_base_win32_error;
class t_win32_error;

////////////////////////////////////////////////////////////////////////////////
//Utilities

t_string GetErrorMsg(DWORD dwErrorCode,bool AppendErrCode=true);

////////////////////////////////////////////////////////////////////////////////
//class t_base_win32_error

class t_base_win32_error:virtual public structure::t_exception
{
 private:
  typedef t_base_win32_error                        self_type;
  typedef structure::t_exception                    inherited;

  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef LONG                                      win32_code_type;

 public:
  t_base_win32_error(const self_type& x)
   :inherited(x)
   ,m_win32_code(x.m_win32_code)
  {
  }

  explicit t_base_win32_error(win32_code_type const win32_code)
   :m_win32_code(win32_code)
  {
  }

  virtual ~t_base_win32_error() __STL_EXCEPTION_DCR_THROW_SPEC;

  //t_exception interface ------------------------------------------------
  virtual void raise()const LCPI_CPP_CFG__METHOD__OVERRIDE;

  //selectors ------------------------------------------------------------
  win32_code_type win32_code()const
   {return m_win32_code;}
  
 private:
  const win32_code_type m_win32_code;
};//class t_base_win32_error

////////////////////////////////////////////////////////////////////////////////
//class t_win32_error

class t_win32_error:public t_base_win32_error
{
 private:
  typedef t_win32_error                          self_type;
  typedef t_base_win32_error                     inherited;

  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef std::string::value_type                char_type;
  typedef structure::t_str_parameter<char_type>  str_arg_type;

 public:
  t_win32_error(const self_type&);

  explicit t_win32_error(win32_code_type win32_code);

  t_win32_error(win32_code_type win32_code,str_arg_type msg);

  virtual ~t_win32_error() __STL_EXCEPTION_DCR_THROW_SPEC;

  //std::exception -------------------------------------------------------
  virtual const char* what()const __STL_EXCEPTION_WHAT_THROW_SPEC LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  //structure::t_exception -----------------------------------------------
  virtual void raise()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;//throw

  //selectors ------------------------------------------------------------
  const std::string& msg() const// throw()
   {return m_msg;}

  //----------------------------------------------------------------------
  COMP_CONF_DECLSPEC_NORETURN
  static void throw_error(win32_code_type win32_code);

  COMP_CONF_DECLSPEC_NORETURN
  static void throw_error(win32_code_type win32_code,str_arg_type msg);

 private:
  static std::string helper__build_what_msg(win32_code_type const win32_code);

  static std::string helper__build_what_msg(win32_code_type const win32_code,
                                            str_arg_type    const msg);

 private:
  const std::string  m_msg;
  const std::string  m_what;
};//class t_win32_error

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
#endif
