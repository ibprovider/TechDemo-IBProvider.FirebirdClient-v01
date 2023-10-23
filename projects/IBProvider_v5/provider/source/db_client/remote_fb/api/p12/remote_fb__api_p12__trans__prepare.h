////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__trans__prepare.h
//! \brief   Подготовка транзакции.
//! \author  Kovalenko Dmitry
//! \date    18.02.2015
#ifndef _remote_fb__api_p12__trans__prepare_H_
#define _remote_fb__api_p12__trans__prepare_H_

#include "source/db_client/remote_fb/api/remote_fb__api__trans__prepare.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__PrepareTransaction

/// <summary>
///  Подготовка транзакции.
/// </summary>
class RemoteFB__API_P12__PrepareTransaction LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__PrepareTransaction)
{
 private:
  using self_type=RemoteFB__API_P12__PrepareTransaction;

  RemoteFB__API_P12__PrepareTransaction(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private:
  RemoteFB__API_P12__PrepareTransaction();

  virtual ~RemoteFB__API_P12__PrepareTransaction();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //Interface ------------------------------------------------------------

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
                    const void*              data)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P12__PrepareTransaction

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
