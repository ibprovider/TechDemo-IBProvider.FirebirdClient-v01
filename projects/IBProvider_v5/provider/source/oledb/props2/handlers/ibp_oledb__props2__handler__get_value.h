////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__get_value.h
//! \brief   Интерфейс расширения метода GetValue
//! \author  Kovalenko Dmitry
//! \date    21.12.2018
#ifndef _ibp_oledb__props2__handler__get_value_H_
#define _ibp_oledb__props2__handler__get_value_H_

#include <ole_lib/oledb/provider/props2/oledb_props2__data__values.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__GetValue

class LCPI_CPP_CFG__DECLSPEC__NOVTABLE IBP_OLEDB_Props2__Handler__GetValue
{
 public:
  virtual bool GetValue
                (const oledb_lib::OLEDB_Props2__Data__Values* pValues,
                 oledb_lib::OLEDB_Props2__Data__OpCtx&        op_ctx,
                 REFGUID                                      propGuid,
                 DBPROPID                                     propId,
                 DBPROPOPTIONS*                               pResult_dwOptions,
                 VARIANT*                                     pResult_Value)const=0;
};//class IBP_OLEDB_Props2__Handler__GetValue

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
