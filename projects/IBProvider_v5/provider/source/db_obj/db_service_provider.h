////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_service_provider.h
//! \brief   ��������� ��� �������� �������� �������� � �������������� ��������.
//! \author  Kovalenko Dmitry
//! \date    26.07.2006
#ifndef _db_service_provider_H_
#define _db_service_provider_H_

#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//class t_db_service_provider

//! \ingroup db_obj
/// <summary>
///  ��������� ��� ��������� ��������� �������� ����������
/// </summary>
///  ������������ ��� ���������� �������� connection, transaction.
class COMP_CONF_DECLSPEC_NOVTABLE t_db_service_provider:public t_db_smart_interface
{
 public:

  //interface ------------------------------------------------------------

  /// <summary>
  /// ������ ���������� �������
  /// </summary>
  //! \param[in] rguidService
  //!   ������������� �������
  //! \return
  //!   ���������� ��������� �� ��������� ������. ���� �������������
  //!   ������ �� ��������������, �� ������������ NULL
  virtual t_db_object_ptr query_service(REFGUID rguidService)=0; //throw
};//class t_db_service_provider

////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
