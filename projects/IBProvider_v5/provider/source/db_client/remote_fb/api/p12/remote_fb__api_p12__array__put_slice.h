////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__array__put_slice.h
//! \brief   —охранение массива.
//! \author  Kovalenko Dmitry.
//! \date    22.09.2015
#ifndef _remote_fb__api_p12__array__put_slice_H_
#define _remote_fb__api_p12__array__put_slice_H_

#include "source/db_client/remote_fb/api/remote_fb__api__array__put_slice.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__PutArraySlice

/// <summary>
///  —охранение массива.
/// </summary>
class RemoteFB__API_P12__PutArraySlice LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__PutArraySlice)
{
 private:
  using self_type=RemoteFB__API_P12__PutArraySlice;

  RemoteFB__API_P12__PutArraySlice(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  RemoteFB__API_P12__PutArraySlice();

  virtual ~RemoteFB__API_P12__PutArraySlice();

 public:
  /// ≈динственный экземпл€р класса
  static self_type Instance;

  //interface ------------------------------------------------------------
  /// <summary>
  ///  —охранение массива.
  /// </summary>
  //! \param[in] opCtx
  //! \param[in] pData
  //!  Not null
  //! \param[in] pTrHandle
  //!  ”казатель на дескриптор активной транзакции. Not null.
  //! \param[in,out] pArrayID
  //!  ”казатель на идентификатор обновл€емого (создаваемого) массива. Not null.
  //! \param[in] szArraySDL
  //! \param[in] pArraySDL
  //! \param[in] szArrayData
  //! \param[in] pArrayData
  virtual void exec(db_obj::t_db_operation_context& opCtx,
                    RemoteFB__ConnectorData*        pData,
                    tr_handle_type*                 pTrHandle,
                    db_obj::DB_IBARRAYID*           pArrayID,
                    size_t                          szArraySDL,
                    const unsigned char*            pArraySDL,
                    size_t                          szArrayData,
                    const void*                     pArrayData)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  class tagOpGetArraySliceDescr;
};//class RemoteFB__API_P12__PutArraySlice

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
