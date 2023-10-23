////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_custom_error_object__sql.h
//! \brief   The interface of internal object with custom error data
//! \author  Kovalenko Dmitry
//! \date    24.10.2022
#ifndef _ibp_custom_error_object__sql_H_
#define _ibp_custom_error_object__sql_H_

#include "source/error_services/ibp_get_custom_error_object.h"
#include "source/ibp_memory.h"

#include <structure/t_str_parameter.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_custom_error_object__sql

class t_ibp_custom_error_object__sql LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_INTERFACE_IMPL_DYNAMIC(t_ibp_get_custom_error_object)
{
 private:
  using self_type=t_ibp_custom_error_object__sql;

  t_ibp_custom_error_object__sql(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs -------------------------------------------------
  using self_ptr=lib::structure::t_smart_object_ptr<self_type>;

  using str_arg_type=structure::str_parameter;

  using native_error_type=LONG;

 private:
  t_ibp_custom_error_object__sql(str_arg_type      strSQLState,
                                 native_error_type lNativeError);

  virtual ~t_ibp_custom_error_object__sql();

 public:
  static self_ptr create(str_arg_type      strSQLState,
                         native_error_type lNativeError);

  //own interface ---------------------------------------------------
  const std::string& get_sqlstate()const;

  //interface -------------------------------------------------------
  virtual lib::com::base::IUnknownPtr
           get_custom_error_object
            (IUnknown*                   pUnkOuter,
             const COM_SERVER_LINK_TYPE& ComServerLink)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  std::string       const m_SQLState;
  native_error_type const m_lNativeError;
};//class t_ibp_custom_error_object

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
