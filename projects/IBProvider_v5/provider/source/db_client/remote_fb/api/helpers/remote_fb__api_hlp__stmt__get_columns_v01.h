////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__stmt__get_columns_v01.h
//! \brief   Getting the column definitions of statement (V01).
//! \author  Kovalenko Dmitry
//! \date    28.03.2023
#ifndef _remote_fb__api_hlp__stmt__get_columns_v01_H_
#define _remote_fb__api_hlp__stmt__get_columns_v01_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__get_columns.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_hlp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__GetColumns_v01

/// <summary>
///  Getting the column definitions of statement (V01).
/// </summary>
class RemoteFB__API_HLP__GetColumns_v01 LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__GetColumns)
{
 private:
  typedef RemoteFB__API_HLP__GetColumns_v01        self_type;

  RemoteFB__API_HLP__GetColumns_v01(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef stmt_handle_type::item_type              stmt_data_type;

 private:
  RemoteFB__API_HLP__GetColumns_v01();

  virtual ~RemoteFB__API_HLP__GetColumns_v01();

 public:
  /// The single instance of class
  static self_type Instance;

  //interface ------------------------------------------------------------

  /// <summary>
  ///  Getting the column definitions of statement.
  /// </summary>
  //! \param[in] OpCtx
  //!  The context of operation.
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pStmtHandle
  //!  Not null. The handle of prepared statement.
  //! \param[in,out] xsqlda
  //!  Not null.
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    stmt_handle_type*               pStmtHandle,
                    isc_api::XSQLDA_V1*             xsqlda)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_HLP__GetColumns_v01

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
