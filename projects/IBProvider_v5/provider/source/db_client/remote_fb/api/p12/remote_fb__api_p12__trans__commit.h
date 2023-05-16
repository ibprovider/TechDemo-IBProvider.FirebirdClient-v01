////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__trans__commit.h
//! \brief   Коммит транзакции.
//! \author  Kovalenko Dmitry
//! \date    18.02.2015
#ifndef _remote_fb__api_p12__trans__commit_H_
#define _remote_fb__api_p12__trans__commit_H_

#include "source/db_client/remote_fb/api/remote_fb__api__trans__commit.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__Commit

/// <summary>
///  Откат транзакции.
/// </summary>
class RemoteFB__API_P12__Commit LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__Commit)
{
 private:
  typedef RemoteFB__API_P12__Commit                      self_type;

  RemoteFB__API_P12__Commit(const self_type&);
  self_type& operator = (const self_type&);

 private:
  RemoteFB__API_P12__Commit();

  virtual ~RemoteFB__API_P12__Commit();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  Откат транзакции.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pTrHandle
  //!  Not null. На входе должен указывать на ненулевое значение.
  //!
  //! В случае успешного коммита транзакции, в (*pTrHandle) будет сброшен ID.
  virtual void exec(RemoteFB__ConnectorData* pData,
                    tr_handle_type*          pTrHandle) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P12__Commit

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
