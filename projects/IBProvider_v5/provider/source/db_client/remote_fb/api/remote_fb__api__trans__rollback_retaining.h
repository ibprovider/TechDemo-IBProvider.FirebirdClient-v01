////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__trans__rollback_retaining.h
//! \brief   Откат транзакции с сохранением контекста.
//! \author  Kovalenko Dmitry
//! \date    18.02.2015
#ifndef _remote_fb__api__trans__rollback_retaining_H_
#define _remote_fb__api__trans__rollback_retaining_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__transaction.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__RollbackRetaining

/// <summary>
///  Откат транзакции с сохранением контекста.
/// </summary>
//! \note
//!  Операция доступна начиная с 10-го протокола.
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE RemoteFB__API__RollbackRetaining
 :public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  using tr_handle_type=handles::RemoteFB__TrHandle;

 public:
  /// <summary>
  ///  Откат транзакции с сохранением контекста.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pTrHandle
  //!  Not null. На входе должен указывать на ненулевое значение.
  virtual void exec(RemoteFB__ConnectorData* pData,
                    tr_handle_type*          pTrHandle)=0;
};//class RemoteFB__API__RollbackRetaining

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
