////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//class t_base_com_error

t_base_com_error::t_base_com_error(const self_type& x)
 :inherited(x)
 ,m_code(x.m_code)
{
}

//------------------------------------------------------------------------
t_base_com_error::t_base_com_error(HRESULT const code)
 :m_code(code)
{
}

//------------------------------------------------------------------------
t_base_com_error::~t_base_com_error() LCPI_STL_EXCEPTION_DCR_THROW_SPEC
{
}

//------------------------------------------------------------------------
void t_base_com_error::throw_error(HRESULT const code)
{
 t_base_com_error(code).raise();//throw
}//throw_error

//------------------------------------------------------------------------
void t_base_com_error::swap(self_type& x)
{
 std::swap(m_code,x.m_code);
}//swap

//------------------------------------------------------------------------
const char* t_base_com_error::what()const LCPI_STL_EXCEPTION_WHAT_THROW_SPEC
{
 return "base com error";
}//what

//------------------------------------------------------------------------
void t_base_com_error::raise()const
{
 throw *this;
}//raise

//------------------------------------------------------------------------
#if(OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO!=0)

HRESULT t_base_com_error::set_error_info(REFIID UNUSED_ARG(exc_iid))const
{
 return S_OK;
}//set_error_info

#endif

////////////////////////////////////////////////////////////////////////////////

