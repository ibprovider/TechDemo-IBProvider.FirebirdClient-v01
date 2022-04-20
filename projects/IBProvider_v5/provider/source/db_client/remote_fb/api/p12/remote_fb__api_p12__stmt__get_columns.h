////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__stmt__get_columns.h
//! \brief   Получение описаний колонок запроса.
//! \author  Kovalenko Dmitry
//! \date    27.04.2015
#ifndef _remote_fb__api_p12__stmt__get_columns_H_
#define _remote_fb__api_p12__stmt__get_columns_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__get_columns.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__GetColumns

/// <summary>
///  Получение описаний колонок запроса.
/// </summary>
class RemoteFB__API_P12__GetColumns LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__GetColumns)
{
 private:
  typedef RemoteFB__API_P12__GetColumns            self_type;

  RemoteFB__API_P12__GetColumns(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef stmt_handle_type::item_type              stmt_data_type;

 private:
  RemoteFB__API_P12__GetColumns();

  virtual ~RemoteFB__API_P12__GetColumns();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //interface ------------------------------------------------------------

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
                    isc_api::XSQLDA_V1*             xsqlda)COMP_W000004_OVERRIDE_FINAL;
};//class RemoteFB__API_P12__GetColumns

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
