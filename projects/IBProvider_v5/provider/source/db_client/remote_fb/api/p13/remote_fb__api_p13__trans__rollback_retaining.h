////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__trans__rollback_retaining.h
//! \brief   Откат транзакции с сохранением контекста.
//! \author  Kovalenko Dmitry
//! \date    15.09.2016
#ifndef _remote_fb__api_p13__trans__rollback_retaining_H_
#define _remote_fb__api_p13__trans__rollback_retaining_H_

#include "source/db_client/remote_fb/api/remote_fb__api__trans__rollback_retaining.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__RollbackRetaining

/// <summary>
///  Откат транзакции с сохранением контекста.
/// </summary>
//! \note
//!  Операция доступна начиная с 10-го протокола.
class RemoteFB__API_P13__RollbackRetaining LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__RollbackRetaining)
{
 private:
  typedef RemoteFB__API_P13__RollbackRetaining             self_type;

  RemoteFB__API_P13__RollbackRetaining(const self_type&);
  self_type& operator = (const self_type&);

 private:
  RemoteFB__API_P13__RollbackRetaining();

  virtual ~RemoteFB__API_P13__RollbackRetaining();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  Откат транзакции с сохранением контекста.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pTrHandle
  //!  Not null. На входе должен указывать на ненулевое значение.
  virtual void exec(RemoteFB__ConnectorData* pData,
                    tr_handle_type*          pTrHandle)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P13__RollbackRetaining

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
