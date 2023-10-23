////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__op_svc__get_array_slice_descr.h
//! \brief   Сервис для предоставления описания массива
//! \author  Kovalenko Dmitry
//! \date    06.10.2015
#ifndef _remote_fb__op_svc__get_array_slice_descr_H_
#define _remote_fb__op_svc__get_array_slice_descr_H_

#include "source/db_client/remote_fb/remote_fb__array_slice_descr.h"
#include "source/db_client/remote_fb/remote_fb__memory.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__OpSvc__GetArraySliceDescr

/// <summary>
///  Сервис для предоставления описания массива
/// </summary>
class RemoteFB__OpSvc__GetArraySliceDescr:public RemoteFB__SmartInterface
{
 public:
  /// <summary>
  ///  Идентификатор сервиса.
  /// </summary>
  static const GUID svcID;

 public:
  /// <summary>
  ///  Получение ссылки на объект с описанием массива.
  /// </summary>
  virtual const RemoteFB__ArraySliceDescr& GetArraySliceDescr()const=0;
};//class RemoteFB__OpSvc__GetArraySliceDescr

////////////////////////////////////////////////////////////////////////////////
//typedefs

/// <summary>
///  Смарт указатель на объекты класса RemoteFB__OpSvc__GetArraySliceDescr
/// </summary>
using RemoteFB__OpSvc__GetArraySliceDescrPtr
 =lib::structure::t_smart_object_ptr<RemoteFB__OpSvc__GetArraySliceDescr>;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
