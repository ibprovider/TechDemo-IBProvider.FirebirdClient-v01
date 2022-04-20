////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api__array__put_slice.h
//! \brief   Сохранение массива.
//! \author  Kovalenko Dmitry
//! \date    22.09.2015
#ifndef _remote_fb__api__array__put_slice_H_
#define _remote_fb__api__array__put_slice_H_

#include "source/db_client/remote_fb/handles/remote_fb__handle__transaction.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API__PutArraySlice

/// <summary>
///  Сохранение массива.
/// </summary>
class COMP_CONF_DECLSPEC_NOVTABLE RemoteFB__API__PutArraySlice:public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  typedef handles::RemoteFB__TrHandle       tr_handle_type;

 public:
  /// <summary>
  ///  Сохранение массива.
  /// </summary>
  //! \param[in] opCtx
  //! \param[in] pData
  //!  Not null
  //! \param[in] pTrHandle
  //!  Указатель на дескриптор активной транзакции. Not null.
  //! \param[in,out] pArrayID
  //!  Указатель на идентификатор обновляемого (создаваемого) массива. Not null.
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
                    const void*                     pArrayData)=0;
};//class RemoteFB__API__PutArraySlice

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
