////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__array__get_slice.h
//! \brief   Чтение массива.
//! \author  Kovalenko Dmitry.
//! \date    24.09.2016
#ifndef _remote_fb__api_p13__array__get_slice_H_
#define _remote_fb__api_p13__array__get_slice_H_

#include "source/db_client/remote_fb/api/remote_fb__api__array__get_slice.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__GetArraySlice

/// <summary>
///  Чтение массива.
/// </summary>
class RemoteFB__API_P13__GetArraySlice LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__API__GetArraySlice)
{
 private:
  typedef RemoteFB__API_P13__GetArraySlice  self_type;

  RemoteFB__API_P13__GetArraySlice(const self_type&);
  self_type& operator = (const self_type&);

 public:
  RemoteFB__API_P13__GetArraySlice();

  virtual ~RemoteFB__API_P13__GetArraySlice();

 public:
  /// Единственный экземпляр класса
  static self_type Instance;

  //interface ------------------------------------------------------------
  /// <summary>
  ///  Чтение массива.
  /// </summary>
  //! \param[in] opCtx
  //! \param[in] pData
  //!  Not null
  //! \param[in] pTrHandle
  //!  Указатель на дескриптор активной транзакции. Not null.
  //! \param[in] ArrayID
  //!  Идентификатор загружаемого массива.
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
                    void*                           pArrayData)COMP_W000004_OVERRIDE_FINAL;

 private:
  class tagOpMemoryBuffer;
  class tagOpGetArraySliceDescr;
};//class RemoteFB__API_P13__GetArraySlice

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
