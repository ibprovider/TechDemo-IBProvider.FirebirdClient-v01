////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__common__tr_iso_level.h
//! \brief   Реализация ExtractValue для свойства с уровнем изоляции транзакции.
//! \author  Kovalenko Dmitry
//! \date    17.12.2018
#ifndef _ibp_oledb__props2__handler__extract_value__common__tr_iso_level_H_
#define _ibp_oledb__props2__handler__extract_value__common__tr_iso_level_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__tr_iso_level

/// <summary>
///  Реализация ExtractValue для свойства с уровнем изоляции транзакции.
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Common__tr_iso_level
{
 private:
  class tag_data;

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__tr_iso_level

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
