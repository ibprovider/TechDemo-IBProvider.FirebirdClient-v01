////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__type_of_db_users.h
//! \brief   Реализация ExtractValue для свойства "IBP_NEWDB: Type Of Database Users".
//! \author  Kovalenko Dmitry
//! \date    31.12.2018
#ifndef _ibp_oledb__props2__handler__extract_value__prop__type_of_db_users_H_
#define _ibp_oledb__props2__handler__extract_value__prop__type_of_db_users_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__type_of_db_users

/// <summary>
///  Реализация ExtractValue для свойства "IBP_NEWDB: Type Of Database Users".
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__type_of_db_users
{
 private:
  class tag_data;

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__type_of_db_users

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
