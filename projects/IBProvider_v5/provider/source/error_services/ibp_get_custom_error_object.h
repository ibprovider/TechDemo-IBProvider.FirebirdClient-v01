////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_get_custom_error_object.h
//! \brief   Интерфейс для получения CustomErrorObject привязанного к описанию ошибки
//! \author  Kovalenko Dmitry
//! \date    03.08.2015
#ifndef _ibp_get_custom_error_object_H_
#define _ibp_get_custom_error_object_H_

#include <lcpi/lib/com/base/com_base__ptr.h>
#include <lcpi/lib/structure/t_smart_interface.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_get_custom_error_object

/// <summary>
///  Интерфейс для получения CustomErrorObject привязанного к описанию ошибки
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_ibp_get_custom_error_object
 :public lib::structure::t_smart_interface
{
 public:
  using COM_SERVER_LINK_TYPE
   =ole_lib::TBaseUnknown2__SERVER_LINK;

 public:
  /// <summary>
  ///  Получение CustomErrorObject
  /// </summary>
  //! \param[in] pUnkOuter
  //!  Указатель на контролирующий интерфейс. Can be null.
  //! \param[in] ComServerLink
  //! \return
  //!  Can be null
  virtual lib::com::base::IUnknownPtr get_custom_error_object
                                           (IUnknown*                   pUnkOuter,
                                            const COM_SERVER_LINK_TYPE& ComServerLink)const=0;
};//class t_ibp_get_custom_error_object

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
