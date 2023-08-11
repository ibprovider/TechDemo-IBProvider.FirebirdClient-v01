////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_custom_error_object__sql.cpp
//! \brief   The interface of internal object with custom error data
//! \author  Kovalenko Dmitry
//! \date    24.10.2022
#include <_pch_.h>
#pragma hdrstop

#include "source/error_services/ibp_custom_error_object__sql.h"
#include "source/oledb/error/ibp_oledb__sql_error_info.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_custom_error_object

t_ibp_custom_error_object__sql::t_ibp_custom_error_object__sql
                                  (str_arg_type      const strSQLState,
                                   native_error_type const lNativeError)
 :m_SQLState(strSQLState.str())
 ,m_lNativeError(lNativeError)
{
}

//------------------------------------------------------------------------
t_ibp_custom_error_object__sql::~t_ibp_custom_error_object__sql()
{
}

//------------------------------------------------------------------------
t_ibp_custom_error_object__sql::self_ptr
 t_ibp_custom_error_object__sql::create(str_arg_type      const strSQLState,
                                        native_error_type const lNativeError)
{
 return lib::structure::not_null_ptr
         (new self_type
           (strSQLState,
            lNativeError));
}//create

//interface --------------------------------------------------------------
const std::string& t_ibp_custom_error_object__sql::get_sqlstate()const
{
 return m_SQLState;
}//get_sqlstate

//------------------------------------------------------------------------
lib::com::base::IUnknownPtr
 t_ibp_custom_error_object__sql::get_custom_error_object
                             (IUnknown*             const pUnkOuter,
                              const COM_SERVER_LINK_TYPE& ComServerLink)const
{
 return oledb::IBP_OLEDB__SQLErrorInfo::Create
         (pUnkOuter,
          ComServerLink,
          m_SQLState,
          m_lNativeError);
}//get_custom_error_object

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
