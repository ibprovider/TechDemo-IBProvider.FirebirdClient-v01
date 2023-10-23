////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__trans__start.h
//! \brief   Старт транзакции.
//! \author  Kovalenko Dmitry
//! \date    17.02.2015
#ifndef _remote_fb__api__trans__start_H_
#define _remote_fb__api__trans__start_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__transaction.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__StartTransaction

/// <summary>
///  Старт транзакции.
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE RemoteFB__API__StartTransaction
 :public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  using tr_handle_type=handles::RemoteFB__TrHandle;

 public:
  /// <summary>
  ///  Создание транзакции.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in,out] pTrHandle
  //!  Not null. На входе должен указывать на нулевое значение.
  //!  На выходе параметру присвоится дескриптор созданной транзакции.
  //! \param[in] tpb_length
  //! \param[in] tpb
  virtual void exec(RemoteFB__ConnectorData* pData,
                    tr_handle_type*          pTrHandle,
                    size_t                   tpb_length,
                    const unsigned char*     tpb)=0;
};//class RemoteFB__API__StartTransaction

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
