////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__remote_wire_compression.h
//! \brief   Реализация ExtractValue для свойства "remote:wire_compression".
//! \author  Kovalenko Dmitry
//! \date    07.01.2019
#ifndef _ibp_oledb__props2__handler__extract_value__prop__remote_wire_compression_H_
#define _ibp_oledb__props2__handler__extract_value__prop__remote_wire_compression_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////

#if(IBP_ENGINE_DIRECT_FB==0)
# error Incorrect usage of file!
#endif

////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_wire_compression

/// <summary>
///  Реализация ExtractValue для свойства "remote:wire_compression".
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_wire_compression
{
 private:
  class tag_data;

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_wire_compression

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
