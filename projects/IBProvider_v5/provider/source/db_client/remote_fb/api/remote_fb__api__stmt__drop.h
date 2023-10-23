////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__stmt__drop.h
//! \brief   ������������ ����������� �������.
//! \author  Kovalenko Dmitry
//! \date    25.02.2015
#ifndef _remote_fb__api__stmt__drop_H_
#define _remote_fb__api__stmt__drop_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__statement.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__DropStatement

/// <summary>
///  ������������ ����������� �������.
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE RemoteFB__API__DropStatement
 :public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  using stmt_handle_type=handles::RemoteFB__StmtHandle;

 public:
  /// <summary>
  ///  ������������ ����������� �������.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in,out] pStmtHandle
  //!  Not null. �� ����� ������ ��������� �� ��������� ��������.
  //!  �� ������ ��������� ���������� ������� ��������.
  virtual void exec(RemoteFB__ConnectorData* pData,
                    stmt_handle_type*        pStmtHandle)=0;
};//class RemoteFB__API__DropStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
