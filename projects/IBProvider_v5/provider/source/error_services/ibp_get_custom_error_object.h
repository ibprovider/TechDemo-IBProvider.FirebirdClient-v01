////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_get_custom_error_object.h
//! \brief   ��������� ��� ��������� CustomErrorObject ������������ � �������� ������
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
///  ��������� ��� ��������� CustomErrorObject ������������ � �������� ������
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE t_ibp_get_custom_error_object:public lib::structure::t_smart_interface
{
 public:
  /// <summary>
  ///  ��������� CustomErrorObject
  /// </summary>
  //! \param[in] pUnkOuter
  //!  ��������� �� �������������� ���������. Can be null.
  //! \return
  //!  Can be null
  virtual lib::com::base::IUnknownPtr get_custom_error_object(IUnknown* pUnkOuter)const=0;
};//class t_ibp_get_custom_error_object

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
