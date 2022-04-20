////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error.inl
//! \brief   Класс исключения для обработки OLEDB-ошибок
//! \author  Kovalenko Dmitry
//! \date    03.02.2003
#ifndef _ibp_error_INL_
#define _ibp_error_INL_

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//struct t_ibp_error_traits

inline t_ibp_error_traits::out_return_type&
t_ibp_error_traits::out_ret(args_type& x)
{
 return *static_cast<out_return_type*>(&x);
}//out_ret

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error

inline t_ibp_error& t_ibp_error::set_last_error_as_primary()
{
 assert(!m_errors.empty());

 m_primary_err_idx=m_errors.size()-1;

 return *this;
}//set_last_error_as_primary

//------------------------------------------------------------------------
inline void t_ibp_error::raise(HRESULT const new_err_code)//throw
{
 m_code=new_err_code;

 this->raise();
}//raise

//------------------------------------------------------------------------
inline void t_ibp_error::raise_me(HRESULT const new_err_code)//throw
{
 m_code=new_err_code;

 this->raise_me();
}//raise_me

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
