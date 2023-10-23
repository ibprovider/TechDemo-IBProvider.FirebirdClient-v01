////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__stmt__get_info.h
//! \brief   Получение сведений о запросе.
//! \author  Kovalenko Dmitry
//! \date    02.05.2015
#ifndef _remote_fb__api__stmt__get_info_H_
#define _remote_fb__api__stmt__get_info_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__statement.h"
#include "source/db_client/remote_fb/remote_fb__info_buffer.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__GetStatementInfo

/// <summary>
///  Получение сведений о запросе.
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE RemoteFB__API__GetStatementInfo
 :public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  using stmt_handle_type=handles::RemoteFB__StmtHandle;

 public:
  /// <summary>
  ///  Получение сведений о запросе.
  /// </summary>
  //! \param[in] OpCtx
  //!  Контекст операции.
  //! \param[in]  pData
  //!  Not null.
  //! \param[in]  pStmtHandle
  //!  Действительный дескриптор запроса. Not null.
  //! \param[in]  Incornation
  //! \param[in]  cItems
  //! \param[in]  pItems
  //! \param[out] ResultBuffer
  virtual void exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    stmt_handle_type*               pStmtHandle,
                    unsigned short                  Incornation,
                    unsigned short                  cItems,
                    const unsigned char*            pItems,
                    RemoteFB__InfoBuffer&           ResultBuffer)=0;
};//class RemoteFB__API__GetStatementInfo

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
