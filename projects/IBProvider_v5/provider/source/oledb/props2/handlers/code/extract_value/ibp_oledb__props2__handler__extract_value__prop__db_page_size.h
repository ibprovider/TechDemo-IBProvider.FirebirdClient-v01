////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__db_page_size.h
//! \brief   Реализация ExtractValue для свойства "IBP_NEWDB: Database Page Size".
//! \author  Kovalenko Dmitry
//! \date    30.01.2019
#ifndef _ibp_oledb__props2__handler__extract_value__prop__db_page_size_H_
#define _ibp_oledb__props2__handler__extract_value__prop__db_page_size_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__db_page_size

/// <summary>
///  Реализация ExtractValue для свойства "IBP_NEWDB: Database Page Size".
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__db_page_size
{
 private:
  class tag_data;

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__db_page_size

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
