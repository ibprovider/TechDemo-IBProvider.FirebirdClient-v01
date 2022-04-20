////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p10
//! \file    remote_fb__p10__connect_helper.h
//! \brief   ��������������� ����� � ��������������� ����� �����������/�������� ���� ������.
//! \author  Kovalenko Dmitry
//! \date    03.12.2015
#ifndef _remote_fb__p10__connect_helper_H_
#define _remote_fb__p10__connect_helper_H_

#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p10{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p10
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P10__ConnectHelper

/// <summary>
///  ��������������� ����� � ��������������� ����� �����������/�������� ���� ������.
/// </summary>
class RemoteFB__P10__ConnectHelper LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef RemoteFB__P10__ConnectHelper             self_type;

 public: //typedefs ------------------------------------------------------
  typedef structure::t_const_wstr_box              wstr_box_type;

 public:
  /// <summary>
  ///  �����������/�������� ���� ������.
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] ucs2_database_name
  //!  ������������ ��� ��� ���� ������.
  //! \param[in] clientConnectBlock
  //!  �������� �������� ����������� � ���� ������.
  //! \param[in] operationID
  static void exec(RemoteFB__Port*                  pPort,
                   wstr_box_type                    ucs2_database_name,
                   RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                   protocol::set01::P_OP            operationID);
};//class RemoteFB__P10__ConnectHelper

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p10*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
