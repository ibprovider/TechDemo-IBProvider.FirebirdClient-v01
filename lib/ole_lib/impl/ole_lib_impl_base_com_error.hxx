////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////

#ifndef OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO
# error OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO is not defined!
#endif

////////////////////////////////////////////////////////////////////////////////
//class t_base_com_error

class t_base_com_error:virtual public structure::t_exception
{
 private:
  typedef t_base_com_error                        self_type;
  typedef structure::t_exception                  inherited;

  self_type& operator = (const self_type&);

 public:
  t_base_com_error(const self_type&);

  explicit t_base_com_error(HRESULT code);

  virtual ~t_base_com_error() __STL_EXCEPTION_DCR_THROW_SPEC;

  COMP_CONF_DECLSPEC_NORETURN static void throw_error(HRESULT code);

  //-----------------------------------------------------------------
  void swap(self_type& x);

  //selectors -------------------------------------------------------
  HRESULT com_code()const;

  //std::exception interface ----------------------------------------
  virtual const char* what()const __STL_EXCEPTION_WHAT_THROW_SPEC LCPI_CPP_CFG__METHOD__OVERRIDE;

  //structure::t_exception interface --------------------------------
  COMP_CONF_DECLSPEC_NORETURN virtual void raise()const LCPI_CPP_CFG__METHOD__OVERRIDE;

  //interface -------------------------------------------------------

#if(OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO!=0)
  /// <summary>
  ///  Registration of object with error information (call LCPI_OS__SetErrorInfo). Can throw.
  /// </summary>
  //! \param[in] exc_iid
  //! \return
  //!  Result of registration(!) operation.
  virtual HRESULT set_error_info(REFIID exc_iid)const;
#endif

 protected:
  HRESULT m_code;
};//class t_base_com_error

////////////////////////////////////////////////////////////////////////////////
//class t_base_com_error - inline implementations

inline HRESULT t_base_com_error::com_code()const
{
 return m_code;
}//com_code

////////////////////////////////////////////////////////////////////////////////
