////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__common__cset_name.h
//! \brief   Реализация ExtractValue для имен кодовых страниц.
//! \author  Kovalenko Dmitry
//! \date    20.02.2019
#ifndef _ibp_oledb__props2__handler__extract_value__common__cset_name_H_
#define _ibp_oledb__props2__handler__extract_value__common__cset_name_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_name

/// <summary>
///  Реализация ExtractValue для имен кодовых страниц.
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_name
 :public IBP_OLEDB_Props2__Handler__ExtractValue
{
 private:
  typedef IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_name   self_type;

  IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_name(const self_type&);
  self_type& operator = (const self_type&);

 private:
  IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_name();

 ~IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_name();

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();

  //IBP_OLEDB_Props2__Handler__ExtractValue interface --------------------
  virtual bool ExtractValue(const VARIANT&  sourceValue,
                            VARIANT*        pResultValue)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  static self_type sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_name

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
