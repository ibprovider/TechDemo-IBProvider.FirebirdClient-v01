////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__trans__rollback.h
//! \brief   Откат транзакции.
//! \author  Kovalenko Dmitry
//! \date    17.02.2015
#ifndef _remote_fb__api__trans__rollback_H_
#define _remote_fb__api__trans__rollback_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__transaction.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__Rollback

/// <summary>
///  Откат транзакции.
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE RemoteFB__API__Rollback:public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  typedef handles::RemoteFB__TrHandle       tr_handle_type;

 public:
  /// <summary>
  ///  Откат транзакции.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pTrHandle
  //!  Not null. На входе должен указывать на ненулевое значение.
  //!
  //! В случае успешного отката транзакции, в (*pTrHandle) будет сброшен ID.
  virtual void exec(RemoteFB__ConnectorData* pData,
                    tr_handle_type*          pTrHandle)=0;
};//class RemoteFB__API__Rollback

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
