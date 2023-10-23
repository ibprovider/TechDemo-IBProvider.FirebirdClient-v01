////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__stmt__get_parameters.h
//! \brief   Получение описаний параметров запроса.
//! \author  Kovalenko Dmitry
//! \date    06.05.2015
#ifndef _remote_fb__api__stmt__get_parameters_H_
#define _remote_fb__api__stmt__get_parameters_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__statement.h"
#include "source/db_obj/isc_base/isc_api.h"
#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__GetParameters

/// <summary>
///  Получение описаний параметров запроса.
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE RemoteFB__API__GetParameters
 :public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  using stmt_handle_type=handles::RemoteFB__StmtHandle;

 public:
  /// <summary>
  ///  Получение описаний колонок запроса.
  /// </summary>
  //! \param[in] OpCtx
  //!  Контекст операции.
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pStmtHandle
  //!  Not null. Дескриптор подготовленого запроса.
  //! \param[in,out] xsqlda
  //!  Not null.
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    stmt_handle_type*               pStmtHandle,
                    isc_api::XSQLDA_V1*             xsqlda)=0;
};//class RemoteFB__API__GetParameters

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
