////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//class t_ole_error

class t_ole_error:public t_base_ole_error
{
 private:
  typedef t_ole_error                   self_type;
  typedef t_base_ole_error              inherited;

  t_ole_error& operator = (const self_type& exc);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_const_str_box    str_box_type;

 public:
  t_ole_error(const self_type& exc);

  t_ole_error(HRESULT hr,str_box_type what_arg,str_box_type text);

  explicit t_ole_error(const TOleStatus& status);

  virtual ~t_ole_error() __STL_EXCEPTION_DCR_THROW_SPEC;

  //std::exception interface ---------------------------------------------
  virtual const char* what() const __STL_EXCEPTION_WHAT_THROW_SPEC COMP_W000004_OVERRIDE_FINAL;

  //structure::t_exception interface -------------------------------------
  COMP_CONF_DECLSPEC_NORETURN
  virtual void raise()const COMP_W000004_OVERRIDE_FINAL;

 public:
  //direct throw exception
  COMP_CONF_DECLSPEC_NORETURN
  static void generate(HRESULT hr,str_box_type what_arg,str_box_type text);

  COMP_CONF_DECLSPEC_NORETURN
  static void generate(const TOleStatus& status);

  COMP_CONF_DECLSPEC_NORETURN
  static void throw_error     (HRESULT hr,str_box_type verb);

  COMP_CONF_DECLSPEC_NORETURN
  static void throw_error     (HRESULT hr);

  COMP_CONF_DECLSPEC_NORETURN
  static void throw_disp_error(HRESULT hr,str_box_type verb);

  COMP_CONF_DECLSPEC_NORETURN
  static void throw_disp_error(HRESULT hr);

 private:
  static void helper__append_line(std::string* result,const std::string& line);

  static void helper__append_com_error_code(std::string* what_arg,HRESULT hr);

 private:
  const std::string m_what_arg;
};//class t_ole_error

////////////////////////////////////////////////////////////////////////////////
