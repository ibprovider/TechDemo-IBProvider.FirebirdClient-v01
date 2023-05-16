////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13_lazy_send
//! \file    remote_fb__api_p13_lazy_send__stmt__fetch.h
//! \brief   Выборка результатов выполнения запроса. Версия для lazy_send-протокола.
//! \author  Kovalenko Dmitry
//! \date    22.09.2016
#ifndef _remote_fb__api_p13_lazy_send__stmt__fetch_H_
#define _remote_fb__api_p13_lazy_send__stmt__fetch_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__fetch.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13_lazy_send
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13_LAZY_SEND__FetchStatement

/// <summary>
///  Выборка результатов выполнения запроса. Версия для lazy_send-протокола.
/// </summary>
class RemoteFB__API_P13_LAZY_SEND__FetchStatement
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__FetchStatement)
{
 private:
  typedef RemoteFB__API_P13_LAZY_SEND__FetchStatement              self_type;

  RemoteFB__API_P13_LAZY_SEND__FetchStatement(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef stmt_handle_type::item_type                    stmt_data_type;

 private:
  RemoteFB__API_P13_LAZY_SEND__FetchStatement();

  virtual ~RemoteFB__API_P13_LAZY_SEND__FetchStatement();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  Выборка результатов запроса.
  /// </summary>
  //! \param[in] OpCtx
  //!  Контекст операции.
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pStmtHandle
  //!  Not null. На входе должен указывать на ненулевое значение.
  //! \param[in] pOutXSQLDA
  //!  Not null.
  //! \return
  //!  false, если запись не выбрана (достигнут конец результирующего множества).
  virtual bool exec(db_obj::t_db_operation_context& OpCtx,
                    RemoteFB__ConnectorData*        pData,
                    stmt_handle_type*               pStmtHandle,
                    const isc_api::XSQLDA_V1*       pOutXSQLDA)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P13_LAZY_SEND__FetchStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
