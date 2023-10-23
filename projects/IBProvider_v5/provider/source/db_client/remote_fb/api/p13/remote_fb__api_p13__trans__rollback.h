////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__trans__rollback.h
//! \brief   ����� ����������.
//! \author  Kovalenko Dmitry
//! \date    15.09.2016
#ifndef _remote_fb__api_p13__trans__rollback_H_
#define _remote_fb__api_p13__trans__rollback_H_

#include "source/db_client/remote_fb/api/remote_fb__api__trans__rollback.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__Rollback

/// <summary>
///  ����� ����������.
/// </summary>
class RemoteFB__API_P13__Rollback LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__Rollback)
{
 private:
  using self_type=RemoteFB__API_P13__Rollback;

  RemoteFB__API_P13__Rollback(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private:
  RemoteFB__API_P13__Rollback();

  virtual ~RemoteFB__API_P13__Rollback();

 public:
  /// ������������ ��������� ������
  static self_type Instance;

  //Interface ------------------------------------------------------------

  /// <summary>
  ///  ����� ����������.
  /// </summary>
  //! \param[in] pData
  //!  Not null.
  //! \param[in] pTrHandle
  //!  Not null. �� ����� ������ ��������� �� ��������� ��������.
  //!
  //! � ������ ��������� ������ ����������, � (*pTrHandle) ����� ������� ID.
  virtual void exec(RemoteFB__ConnectorData* pData,
                    tr_handle_type*          pTrHandle)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
};//class RemoteFB__API_P13__Rollback

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
