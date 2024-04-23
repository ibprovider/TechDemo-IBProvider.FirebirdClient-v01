////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//class t_ole_error

class t_ole_error:public t_base_ole_error
{
 private:
  using self_type=t_ole_error;
  using inherited=t_base_ole_error;

  t_ole_error& operator = (const self_type& exc)=delete;

 public: //typedefs ------------------------------------------------------
  using str_box_type=structure::t_const_str_box;

 public:
  t_ole_error(const self_type& exc);

  t_ole_error(HRESULT hr,str_box_type what_arg,str_box_type text);

  explicit t_ole_error(const TOleStatus& status);

  virtual ~t_ole_error() LCPI_STL_EXCEPTION_DCR_THROW_SPEC;

  //std::exception interface ---------------------------------------------
  virtual const char* what() const LCPI_STL_EXCEPTION_WHAT_THROW_SPEC LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  //structure::t_exception interface -------------------------------------
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  virtual void raise()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 public:
  //direct throw exception
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void generate(HRESULT hr,str_box_type what_arg,str_box_type text);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void generate(const TOleStatus& status);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void throw_error     (HRESULT hr,str_box_type verb);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void throw_error     (HRESULT hr);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void throw_disp_error(HRESULT hr,str_box_type verb);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void throw_disp_error(HRESULT hr);

 private:
  static void helper__append_line(std::string* result,const std::string& line);

  static void helper__append_com_error_code(std::string* what_arg,HRESULT hr);

 private:
  const std::string m_what_arg;
};//class t_ole_error

////////////////////////////////////////////////////////////////////////////////
