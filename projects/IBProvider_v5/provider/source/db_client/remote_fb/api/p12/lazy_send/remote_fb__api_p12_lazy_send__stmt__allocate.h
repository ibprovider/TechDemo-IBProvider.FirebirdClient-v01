////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12_lazy_send
//! \file    remote_fb__api_p12_lazy_send__stmt__allocate.h
//! \brief   Создание дескриптора запроса. Версия для lazy_send-протокола.
//! \author  Kovalenko Dmitry
//! \date    26.10.2015
#ifndef _remote_fb__api_p12_lazy_send__stmt__allocate_H_
#define _remote_fb__api_p12_lazy_send__stmt__allocate_H_

#include "source/db_client/remote_fb/api/remote_fb__api__stmt__allocate.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12_lazy_send
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12_LAZY_SEND__AllocateStatement

/// <summary>
///  Создание дескриптора запроса. Версия для lazy_send-протокола.
/// </summary>
class RemoteFB__API_P12_LAZY_SEND__AllocateStatement LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__AllocateStatement)
{
 private:
  using self_type=RemoteFB__API_P12_LAZY_SEND__AllocateStatement;

  RemoteFB__API_P12_LAZY_SEND__AllocateStatement(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private:
  RemoteFB__API_P12_LAZY_SEND__AllocateStatement();

  virtual ~RemoteFB__API_P12_LAZY_SEND__AllocateStatement();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //Interface ------------------------------------------------------------
  /// <summary>
  ///  Создание дескриптора запроса.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in,out] pStmtHandle
  //!  Not null. На входе должен указывать на нулевое значение.
  //!  На выходе параметру присвоится дескриптор запроса.
  virtual void exec(RemoteFB__ConnectorData* pData,
                    stmt_handle_type*        pStmtHandle)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P12_LAZY_SEND__AllocateStatement

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
