////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__stmt__get_parameters.h
//! \brief   Получение описаний параметров запроса.
//! \author  Kovalenko Dmitry
//! \date    20.09.2016
#ifndef _remote_fb__api_p13__stmt__get_parameters_H_
#define _remote_fb__api_p13__stmt__get_parameters_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__get_parameters.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__GetParameters

/// <summary>
///  Получение описаний параметров запроса.
/// </summary>
class RemoteFB__API_P13__GetParameters LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__GetParameters)
{
 private:
  typedef RemoteFB__API_P13__GetParameters            self_type;

  RemoteFB__API_P13__GetParameters(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef stmt_handle_type::item_type                 stmt_data_type;

 private:
  RemoteFB__API_P13__GetParameters();

  virtual ~RemoteFB__API_P13__GetParameters();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //interface ------------------------------------------------------------

  /// <summary>
  ///  Получение описаний параметров запроса.
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
};//class RemoteFB__API_P13__GetParameters

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
