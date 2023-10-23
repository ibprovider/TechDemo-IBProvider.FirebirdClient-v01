////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value.h
//! \brief   Интерфейс расширения метода ExtractValue
//! \author  Kovalenko Dmitry
//! \date    16.12.2018
#ifndef _ibp_oledb__props2__handler__extract_value_H_
#define _ibp_oledb__props2__handler__extract_value_H_

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue

/// <summary>
///  Интерфейс расширения метода ExtractValue
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE IBP_OLEDB_Props2__Handler__ExtractValue
{
 public:
  virtual bool ExtractValue(const VARIANT&  sourceValue,
                            VARIANT*        pResultValue)const=0;
};//class IBP_OLEDB_Props2__Handler__ExtractValue

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
