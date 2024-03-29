////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_pset01
//! \file    remote_fb__pset01__error_utilities.h
//! \brief   ������� ��� ��������� ������ ��������� SET01.
//! \author  Kovalenko Dmitry
//! \date    09.08.2016
#ifndef _remote_fb__pset01__error_utilities_H_
#define _remote_fb__pset01__error_utilities_H_

#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/isc_base/isc_api.h"
#include "source/error_services/ibp_error_element.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_pset01
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__ErrorUtilites

/// <summary>
///  ������� ��� ��������� ������
/// </summary>
///  �������� ���������� ����� ������ - �������� ���������� ��� �� ���������
///  � ���������� ������ protocol::set01::P_OP_RESP.
class RemoteFB__PSET01__ErrorUtilites
{
 private:
  using self_type=RemoteFB__PSET01__ErrorUtilites;

 public:
  /// <summary>
  ///  ����������� ��������� ���� ���������� ��������
  /// </summary>
  //! \param[in] _pData
  //!  Not null.
  //! \param[in] _op_id
  //! \param[in] _p_resp
  static isc_api::t_ibp_isc_status
   GetResultCode
    (RemoteFB__ConnectorData*          _pData,
     protocol::set01::P_OP             _op_id,
     const protocol::set01::P_OP_RESP& _p_resp);

  /// <summary>
  ///  ������������ ������� � ��������� ��������� ������
  /// </summary>
  //! \param[in] _pData
  //!  Not null.
  //! \param[in] _op_id
  //!  ������������� ��������. ������������ � BUG-CHECK ����������.
  //! \param[in] _p_resp
  //! \param[in] _hr
  //! \return
  //!  Not null.
  static t_ibp_error_element::self_ptr
   BuildServerErrorRecord
    (RemoteFB__ConnectorData*          _pData,
     protocol::set01::P_OP             _op_id,
     const protocol::set01::P_OP_RESP& _p_resp,
     HRESULT                           _hr);

  /// <summary>
  ///  ����������� ��������� RESPONSE-������
  /// </summary>
  //! \param[in] _pData
  //!  Not null.
  //! \param[in] _op_id
  //!  ������������� ��������. ������������ � BUG-CHECK ����������.
  //! \param[in] _p_resp
  //! \param[in] _hr
  static void
   ProcessServerResult
    (RemoteFB__ConnectorData*          _pData,
     protocol::set01::P_OP             _op_id,
     const protocol::set01::P_OP_RESP& _p_resp,
     HRESULT                           _hr);

 public:
  /// <summary>
  ///  ����������� ��������� RESPONSE-������
  /// </summary>
  //! \param[in] _pPort
  //!  Not null.
  //! \param[in] _op_id
  //!  ������������� ��������. ������������ � BUG-CHECK ����������.
  //! \param[in] _p_resp
  //! \param[in] _hr
  static void
   ProcessServerResult2
    (RemoteFB__Port*                   _pPort,
     protocol::set01::P_OP             _op_id,
     const protocol::set01::P_OP_RESP& _p_resp,
     HRESULT                           _hr);
};//class RemoteFB__PSET01__ErrorUtilites

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
