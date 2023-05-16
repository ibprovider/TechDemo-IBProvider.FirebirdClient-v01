////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__stmt__drop.h
//! \brief   Освобождение дескриптора запроса.
//! \author  Kovalenko Dmitry
//! \date    17.09.2016
#ifndef _remote_fb__api_p13__stmt__drop_H_
#define _remote_fb__api_p13__stmt__drop_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__drop.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__DropStatement

/// <summary>
///  Освобождение дескриптора запроса.
/// </summary>
class RemoteFB__API_P13__DropStatement LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__DropStatement)
{
 private:
  typedef RemoteFB__API_P13__DropStatement                  self_type;

  RemoteFB__API_P13__DropStatement(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef handles::RemoteFB__StmtHandle                     stmt_handle_type;

 private:
  RemoteFB__API_P13__DropStatement();

  virtual ~RemoteFB__API_P13__DropStatement();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //Interface ------------------------------------------------------------
  /// <summary>
  ///  Освобождение дескриптора запроса.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pStmtHandle
  //!  Not null. На входе должен указывать на ненулевое значение.
  //!
  //! В случае успешного освобожения запроса, в (*pStmtHandle) будет сброшен ID
  //! и будет произведено отключение от транзакции.
  virtual void exec(RemoteFB__ConnectorData* pData,
                    stmt_handle_type*        pStmtHandle)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P13__DropStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
