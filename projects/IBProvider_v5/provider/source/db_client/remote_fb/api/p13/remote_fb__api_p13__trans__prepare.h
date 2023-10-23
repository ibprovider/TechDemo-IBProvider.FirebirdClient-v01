////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__trans__prepare.h
//! \brief   Подготовка транзакции.
//! \author  Kovalenko Dmitry
//! \date    15.09.2016
#ifndef _remote_fb__api_p13__trans__prepare_H_
#define _remote_fb__api_p13__trans__prepare_H_

#include "source/db_client/remote_fb/api/remote_fb__api__trans__prepare.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__PrepareTransaction

/// <summary>
///  Подготовка транзакции.
/// </summary>
class RemoteFB__API_P13__PrepareTransaction LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__PrepareTransaction)
{
 private:
  using self_type=RemoteFB__API_P13__PrepareTransaction;

  RemoteFB__API_P13__PrepareTransaction(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private:
  RemoteFB__API_P13__PrepareTransaction();

  virtual ~RemoteFB__API_P13__PrepareTransaction();

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
};//class RemoteFB__API_P13__PrepareTransaction

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
