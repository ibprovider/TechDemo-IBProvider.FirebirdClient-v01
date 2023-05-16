////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__db__drop.h
//! \brief   �������� ���� ������.
//! \author  Kovalenko Dmitry
//! \date    15.09.2016
#ifndef _remote_fb__api_p13__db__drop_H_
#define _remote_fb__api_p13__db__drop_H_

#include "source/db_client/remote_fb/api/remote_fb__api__db__drop.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__DropDatabase

/// <summary>
///  ���������� �� ���� ������.
/// </summary>
class RemoteFB__API_P13__DropDatabase LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__DropDatabase)
{
 private:
  typedef RemoteFB__API_P13__DropDatabase                      self_type;

  RemoteFB__API_P13__DropDatabase(const self_type&);
  self_type& operator = (const self_type&);

 private:
  RemoteFB__API_P13__DropDatabase();

  virtual ~RemoteFB__API_P13__DropDatabase();

 public:
  /// ������������ ��������� ������
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  ����� ����������.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  virtual void exec(RemoteFB__ConnectorData* pData)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P13__DropDatabase

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
