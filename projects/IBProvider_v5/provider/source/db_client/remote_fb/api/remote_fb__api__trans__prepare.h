////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__trans__prepare.h
//! \brief   Подготовка транзакции.
//! \author  Kovalenko Dmitry
//! \date    18.02.2015
#ifndef _remote_fb__api__trans__prepare_H_
#define _remote_fb__api__trans__prepare_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__transaction.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__PrepareTransaction

/// <summary>
///  Подготовка транзакции.
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE RemoteFB__API__PrepareTransaction
 :public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  using tr_handle_type=handles::RemoteFB__TrHandle;

 public:
  /// <summary>
  ///  Подготовка транзакции.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pTrHandle
  //!  Not null. На входе должен указывать на ненулевое значение.
  //! \param[in] data_length
  //! \param[in] data
  virtual void exec(RemoteFB__ConnectorData* pData,
                    tr_handle_type*          pTrHandle,
                    size_t                   data_length,
                    const void*              data)=0;
};//class RemoteFB__API__PrepareTransaction

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
