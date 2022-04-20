////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__array_type.h
//! \brief   ���������� ExtractValue ��� �������� "array_type".
//! \author  Kovalenko Dmitry
//! \date    18.12.2018
#ifndef _ibp_oledb__props2__handler__extract_value__prop__array_type_H_
#define _ibp_oledb__props2__handler__extract_value__prop__array_type_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__array_type

/// <summary>
///  ���������� ExtractValue ��� �������� "array_type".
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__array_type
{
 private:
  class tag_data;

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__array_type

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
