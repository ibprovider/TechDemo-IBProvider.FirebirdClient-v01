////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__db__detach.h
//! \brief   ���������� �� ���� ������.
//! \author  Kovalenko Dmitry
//! \date    20.02.2015
#ifndef _remote_fb__api_p12__db__detach_H_
#define _remote_fb__api_p12__db__detach_H_

#include "source/db_client/remote_fb/api/remote_fb__api__db__detach.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__DetachDatabase

/// <summary>
///  ���������� �� ���� ������.
/// </summary>
class RemoteFB__API_P12__DetachDatabase LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__DetachDatabase)
{
 private:
  using self_type=RemoteFB__API_P12__DetachDatabase;

  RemoteFB__API_P12__DetachDatabase(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private:
  RemoteFB__API_P12__DetachDatabase();

  virtual ~RemoteFB__API_P12__DetachDatabase();

 public:
  /// ������������ ��������� ������
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  ���������� �� ���� ������.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  virtual void exec(RemoteFB__ConnectorData* pData)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P12__DetachDatabase

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
