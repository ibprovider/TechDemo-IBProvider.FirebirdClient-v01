////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__trans__commit_retaining.h
//! \brief   Коммит транзакции с сохранением контекста.
//! \author  Kovalenko Dmitry
//! \date    18.02.2015
#ifndef _remote_fb__api_p12__trans__commit_retaining_H_
#define _remote_fb__api_p12__trans__commit_retaining_H_

#include "source/db_client/remote_fb/api/remote_fb__api__trans__commit_retaining.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__CommitRetaining

/// <summary>
///  Коммит транзакции с сохранением контекста.
/// </summary>
//! \note
//!  Операция доступна начиная с 4-го протокола.
class RemoteFB__API_P12__CommitRetaining LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__CommitRetaining)
{
 private:
  typedef RemoteFB__API_P12__CommitRetaining               self_type;

  RemoteFB__API_P12__CommitRetaining(const self_type&);
  self_type& operator = (const self_type&);

 private:
  RemoteFB__API_P12__CommitRetaining();

  virtual ~RemoteFB__API_P12__CommitRetaining();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  Коммит транзакции с сохранением контекста.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pTrHandle
  //!  Not null. На входе должен указывать на ненулевое значение.
  virtual void exec(RemoteFB__ConnectorData* pData,
                    tr_handle_type*          pTrHandle)COMP_W000004_OVERRIDE_FINAL;
};//class RemoteFB__API_P12__CommitRetaining

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
