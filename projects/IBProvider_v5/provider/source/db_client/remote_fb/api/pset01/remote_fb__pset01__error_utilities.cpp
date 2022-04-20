////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_pset01
//! \file    remote_fb__pset01__error_utilities.cpp
//! \brief   Утилиты для обработки ошибок протокола SET01.
//! \author  Kovalenko Dmitry
//! \date    09.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__srv_error_utils_v1.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__ErrorUtilites

isc_api::t_ibp_isc_status
 RemoteFB__PSET01__ErrorUtilites::GetResultCode
                                           (RemoteFB__ConnectorData*    const _pData,
                                            protocol::set01::P_OP       const _op_id,
                                            const protocol::set01::P_OP_RESP& _p_resp)
{
 assert(_pData);

 return RemoteFB__SrvErrorUtils_v1::GetResultCode
         (_pData,
          _op_id,
          _p_resp.p_resp__status_vector);
}//GetResultCode

//------------------------------------------------------------------------
t_ibp_error_element::self_ptr
 RemoteFB__PSET01__ErrorUtilites::BuildServerErrorRecord
                                           (RemoteFB__ConnectorData*  const   _pData,
                                            protocol::set01::P_OP     const   _op_id,
                                            const protocol::set01::P_OP_RESP& _p_resp,
                                            HRESULT                   const   _hr)
{
 assert(_pData);

 return RemoteFB__SrvErrorUtils_v1::BuildServerErrorRecord
         (_pData,
          _op_id,
          _p_resp.p_resp__status_vector,
          _hr);
}//BuildServerErrorRecord

//------------------------------------------------------------------------
void
 RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
                                           (RemoteFB__ConnectorData*    const _pData,
                                            protocol::set01::P_OP       const _op_id,
                                            const protocol::set01::P_OP_RESP& _p_resp,
                                            HRESULT                     const _hr)
{
 assert(_pData);

 return RemoteFB__SrvErrorUtils_v1::ProcessServerResult
         (_pData,
          _op_id,
          _p_resp.p_resp__status_vector,
          _hr);
}//ProcessServerResult

//------------------------------------------------------------------------
void
 RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
                                           (RemoteFB__Port*             const _pPort,
                                            protocol::set01::P_OP       const _op_id,
                                            const protocol::set01::P_OP_RESP& _p_resp,
                                            HRESULT                     const _hr)
{
 assert(_pPort);

 return RemoteFB__SrvErrorUtils_v1::ProcessServerResult
         (_pPort,
          _op_id,
          _p_resp.p_resp__status_vector,
          _hr);
}//ProcessServerResult - Port

////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
