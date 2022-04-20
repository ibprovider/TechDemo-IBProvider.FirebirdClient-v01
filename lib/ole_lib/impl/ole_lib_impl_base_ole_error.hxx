////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////

#ifndef OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO
# error OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO not defined!
#endif

////////////////////////////////////////////////////////////////////////////////
//class t_base_ole_error

class t_base_ole_error:public t_base_com_error
{
 private:
  typedef t_base_ole_error                          self_type;
  typedef t_base_com_error                          inherited;

  t_base_ole_error& operator = (const self_type& exc);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_const_str_box                str_box_type;

 public:
  t_base_ole_error(const self_type& exc);

  explicit t_base_ole_error(HRESULT code);

  t_base_ole_error(HRESULT code,str_box_type text);

  virtual ~t_base_ole_error() __STL_EXCEPTION_DCR_THROW_SPEC;

  //selectors ----------------------------------------------------------
  const std::string& text() const {return m_text;}

 public:
  COMP_CONF_DECLSPEC_NORETURN
  static void throw_error(HRESULT code);

  COMP_CONF_DECLSPEC_NORETURN
  static void throw_error(HRESULT code,str_box_type text);

 public:
  //std::exception interface -------------------------------------------
  virtual const char* what() const __STL_EXCEPTION_WHAT_THROW_SPEC COMP_W000004_OVERRIDE;

  //structure::t_exception interface -----------------------------------
  COMP_CONF_DECLSPEC_NORETURN
  virtual void raise()const COMP_W000004_OVERRIDE;//throw

  //t_base_com_error interface -----------------------------------------
 #if(OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO!=0)
  virtual HRESULT set_error_info(REFIID exc_riid)const COMP_W000004_OVERRIDE;
 #endif

 private:
  const std::string m_text;
};//class t_base_ole_error

////////////////////////////////////////////////////////////////////////////////
