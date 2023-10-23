////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__array__get_slice.h
//! \brief   ������ �������.
//! \author  Kovalenko Dmitry.
//! \date    05.10.2015
#ifndef _remote_fb__api_p12__array__get_slice_H_
#define _remote_fb__api_p12__array__get_slice_H_

#include "source/db_client/remote_fb/api/remote_fb__api__array__get_slice.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__GetArraySlice

/// <summary>
///  ������ �������.
/// </summary>
class RemoteFB__API_P12__GetArraySlice LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__GetArraySlice)
{
 private:
  using self_type=RemoteFB__API_P12__GetArraySlice;

  RemoteFB__API_P12__GetArraySlice(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  RemoteFB__API_P12__GetArraySlice();

  virtual ~RemoteFB__API_P12__GetArraySlice();

 public:
  /// ������������ ��������� ������
  static self_type Instance;

  //interface ------------------------------------------------------------
  /// <summary>
  ///  ������ �������.
  /// </summary>
  //! \param[in] opCtx
  //! \param[in] pData
  //!  Not null
  //! \param[in] pTrHandle
  //!  ��������� �� ���������� �������� ����������. Not null.
  //! \param[in] ArrayID
  //!  ������������� ������������ �������.
  //! \param[in] szArraySDL
  //! \param[in] pArraySDL
  //! \param[in] szArrayData
  //! \param[out] pArrayData
  virtual void exec(db_obj::t_db_operation_context& opCtx,
                    RemoteFB__ConnectorData*        pData,
                    tr_handle_type*                 pTrHandle,
                    const db_obj::DB_IBARRAYID&     ArrayID,
                    size_t                          szArraySDL,
                    const unsigned char*            pArraySDL,
                    size_t                          szArrayData,
                    void*                           pArrayData)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  class tagOpMemoryBuffer;
  class tagOpGetArraySliceDescr;
};//class RemoteFB__API_P12__GetArraySlice

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
