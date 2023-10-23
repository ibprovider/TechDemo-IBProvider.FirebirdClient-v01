////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__db__create.h
//! \brief   �������� ���� ������.
//! \author  Kovalenko Dmitry
//! \date    21.02.2015.
#ifndef _remote_fb__api_p12__db__create_H_
#define _remote_fb__api_p12__db__create_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__CreateDatabase

/// <summary>
///  �������� ���� ������.
/// </summary>
class RemoteFB__API_P12__CreateDatabase LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__API_P12__CreateDatabase;

 public: //typedefs ------------------------------------------------------
  using wstr_box_type=lib::structure::t_const_wstr_box;

 public:
  /// <summary>
  ///  �������� ���� ������.
  /// </summary>
  //! \param[in] pPort
  //!  Not null.
  //! \param[in] ucs2_database_name
  //!  ������������ ��� ��� ���� ������.
  //! \param[in] clientConnectBlock
  //!  �������� �������� ����������� � ���� ������.
  static void exec(RemoteFB__Port*                   pPort,
                   wstr_box_type                     ucs2_database_name,
                   RemoteFB__ClientConnectBlock_v1&  clientConnectBlock);
};//class RemoteFB__API_P12__CreateDatabase

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
