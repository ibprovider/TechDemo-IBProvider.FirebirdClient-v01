////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__prepare_get_value.h
//! \brief   Интерфейс расширения метода PrepareGetValue
//! \author  Kovalenko Dmitry
//! \date    30.12.2018
#ifndef _ibp_oledb__props2__handler__prepare_get_value_H_
#define _ibp_oledb__props2__handler__prepare_get_value_H_

#include <ole_lib/oledb/provider/props2/oledb_props2__data__values.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__PrepareGetValue

/// <summary>
///  Интерфейс расширения метода PrepareGetValue.
/// <summary>
class COMP_CONF_DECLSPEC_NOVTABLE IBP_OLEDB_Props2__Handler__PrepareGetValue
{
 public:
  /// <summary>
  ///  Подготовка данных для получения значения свойства. THROW.
  /// <summary>
  virtual void PrepareGetValue
                (const oledb_lib::OLEDB_Props2__Data__Values* pValues,
                 oledb_lib::OLEDB_Props2__Data__OpCtx&        op_ctx,
                 REFGUID                                      propGuid,
                 DBPROPID                                     propId)const=0; //throw
};//class IBP_OLEDB_Props2__Handler__PrepareGetValue

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
