////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////

#ifndef OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO
# error OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO is not defined!
#endif

////////////////////////////////////////////////////////////////////////////////
//class t_base_ole_error

class t_base_ole_error:public t_base_com_error
{
 private:
  using self_type=t_base_ole_error;
  using inherited=t_base_com_error;

  t_base_ole_error& operator = (const self_type& exc)=delete;

 public: //typedefs ------------------------------------------------------
  using str_box_type=structure::t_const_str_box;

 public:
  t_base_ole_error(const self_type& exc);

  explicit t_base_ole_error(HRESULT code);

  t_base_ole_error(HRESULT code,str_box_type text);

  virtual ~t_base_ole_error() LCPI_STL_EXCEPTION_DCR_THROW_SPEC;

  //selectors ----------------------------------------------------------
  const std::string& text() const {return m_text;}

 public:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void throw_error(HRESULT code);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void throw_error(HRESULT code,str_box_type text);

 public:
  //std::exception interface -------------------------------------------
  virtual const char* what() const LCPI_STL_EXCEPTION_WHAT_THROW_SPEC LCPI_CPP_CFG__METHOD__OVERRIDE;

  //structure::t_exception interface -----------------------------------
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  virtual void raise()const LCPI_CPP_CFG__METHOD__OVERRIDE;//throw

  //t_base_com_error interface -----------------------------------------
 #if(OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO!=0)
  virtual HRESULT set_error_info(REFIID exc_riid)const LCPI_CPP_CFG__METHOD__OVERRIDE;
 #endif

 private:
  const std::string m_text;
};//class t_base_ole_error

////////////////////////////////////////////////////////////////////////////////
