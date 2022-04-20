////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__stmt__get_info.h
//! \brief   Получение сведений о запросе.
//! \author  Kovalenko Dmitry
//! \date    19.09.2016
#ifndef _remote_fb__api_p13__stmt__get_info_H_
#define _remote_fb__api_p13__stmt__get_info_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__get_info.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__GetStatementInfo

/// <summary>
///  Получение сведений о запросе.
/// </summary>
class RemoteFB__API_P13__GetStatementInfo LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__GetStatementInfo)
{
 private:
  typedef RemoteFB__API_P13__GetStatementInfo            self_type;

  RemoteFB__API_P13__GetStatementInfo(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef stmt_handle_type::item_type                    stmt_data_type;

 private:
  RemoteFB__API_P13__GetStatementInfo();

  virtual ~RemoteFB__API_P13__GetStatementInfo();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //Interface ------------------------------------------------------------

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
                    RemoteFB__InfoBuffer&           ResultBuffer)COMP_W000004_OVERRIDE_FINAL;

 private:
  class tagOpMemoryBuffer;
};//class RemoteFB__API_P13__GetStatementInfo

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
