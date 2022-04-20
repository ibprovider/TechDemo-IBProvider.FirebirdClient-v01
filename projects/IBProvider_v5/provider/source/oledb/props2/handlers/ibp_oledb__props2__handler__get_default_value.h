////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__get_default_value.h
//! \brief   Интерфейс расширения метода GetDefaultValue
//! \author  Kovalenko Dmitry
//! \date    21.12.2018
#ifndef _ibp_oledb__props2__handler__get_default_value_H_
#define _ibp_oledb__props2__handler__get_default_value_H_

#include <ole_lib/oledb/provider/props2/oledb_props2__data__values.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__GetDefaultValue

class COMP_CONF_DECLSPEC_NOVTABLE IBP_OLEDB_Props2__Handler__GetDefaultValue
{
 public:
  virtual bool GetDefaultValue
                (const oledb_lib::OLEDB_Props2__Data__Values* pValues,
                 DBPROPOPTIONS*                               pResult_dwOptions,
                 VARIANT*                                     pResult_Value)const=0;
};//class IBP_OLEDB_Props2__Handler__GetDefaultValue

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
