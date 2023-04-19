////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__stmt__fetch_m.h
//! \brief   API for fetching the row of result set.
//! \author  Kovalenko Dmitry
//! \date    16.04.2023
#ifndef _remote_fb__api_p12__stmt__fetch_m_H_
#define _remote_fb__api_p12__stmt__fetch_m_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__fetch_m.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__FetchStatement_M

/// <summary>
///  API for fetching the row of result set.
/// </summary>
class RemoteFB__API_P12__FetchStatement_M LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__FetchStatement_M)
{
 private:
  typedef RemoteFB__API_P12__FetchStatement_M            self_type;

  RemoteFB__API_P12__FetchStatement_M(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef stmt_handle_type::item_type                    stmt_data_type;

 private:
  RemoteFB__API_P12__FetchStatement_M();

  virtual ~RemoteFB__API_P12__FetchStatement_M();

 public:
  /// The single instance of class.
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  Fetching the row or result set.
  /// </summary>
  //! \param[in] OpCtx
  //!  The context of an operation.
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pStmtHandle
  //!  Not null. It must point on a not zero value.
  //! \param[in] pOutMsg
  //!  Not empty. Not null.
  //! \return
  //!  false when a record was not fetched (the end of result set was reached).
  virtual bool exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    stmt_handle_type*               pStmtHandle,
                    const RemoteFB__OutMsg_v1*      pOutMsg)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P12__FetchStatement_M

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
