////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_get_custom_error_object.h
//! \brief   ��������� ��� ��������� CustomErrorObject ������������ � �������� ������
//! \author  Kovalenko Dmitry
//! \date    03.08.2015
#ifndef _ibp_get_custom_error_object_H_
#define _ibp_get_custom_error_object_H_

#include <ole_lib/ole_ptr.h>
#include <structure/t_smart_object.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_get_custom_error_object

/// <summary>
///  ��������� ��� ��������� CustomErrorObject ������������ � �������� ������
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE t_ibp_get_custom_error_object:public structure::t_smart_interface
{
 public:
  /// <summary>
  ///  ��������� CustomErrorObject
  /// </summary>
  //! \param[in] pUnkOuter
  //!  ��������� �� �������������� ���������. Can be null.
  //! \return
  //!  Can be null
  virtual ole_lib::IUnknownPtr get_custom_error_object(IUnknown* pUnkOuter)const=0;
};//class t_ibp_get_custom_error_object

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
