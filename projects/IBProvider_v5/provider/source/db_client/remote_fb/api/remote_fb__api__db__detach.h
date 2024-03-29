////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__db__detach.h
//! \brief   ���������� �� ���� ������.
//! \author  Kovalenko Dmitry
//! \date    20.02.2015
#ifndef _remote_fb__api__db__detach_H_
#define _remote_fb__api__db__detach_H_

#include "source/db_client/remote_fb/remote_fb__memory.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__DetachDatabase

/// <summary>
///  ���������� �� ���� ������.
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE RemoteFB__API__DetachDatabase
 :public RemoteFB__SmartInterface
{
 public:
  /// <summary>
  ///  ����� ����������.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  virtual void exec(RemoteFB__ConnectorData* pData)=0;
};//class RemoteFB__API__DetachDatabase

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
