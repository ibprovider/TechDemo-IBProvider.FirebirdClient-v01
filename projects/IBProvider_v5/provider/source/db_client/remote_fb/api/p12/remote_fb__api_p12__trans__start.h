////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__trans__start.h
//! \brief   Старт транзакции.
//! \author  Kovalenko Dmitry
//! \date    17.02.2015
#ifndef _remote_fb__api_p12__trans__start_H_
#define _remote_fb__api_p12__trans__start_H_

#include "source/db_client/remote_fb/api/remote_fb__api__trans__start.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__StartTransaction

/// <summary>
///  Старт транзакции.
/// </summary>
class RemoteFB__API_P12__StartTransaction LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__StartTransaction)
{
 private:
  typedef RemoteFB__API_P12__StartTransaction              self_type;

  RemoteFB__API_P12__StartTransaction(const self_type&);
  self_type& operator = (const self_type&);

 private:
  RemoteFB__API_P12__StartTransaction();

  virtual ~RemoteFB__API_P12__StartTransaction();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //Interface ------------------------------------------------------------

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
                    const unsigned char*     tpb)COMP_W000004_OVERRIDE_FINAL;
};//class RemoteFB__API_P12__StartTransaction

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
