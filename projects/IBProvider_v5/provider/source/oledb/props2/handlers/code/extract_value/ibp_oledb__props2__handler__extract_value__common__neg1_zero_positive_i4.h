////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__common__neg1_zero_positive_i4.h
//! \brief   Реализация ExtractValue для I4-свойств больше или равных -1.
//! \author  Kovalenko Dmitry
//! \date    18.12.2018
#ifndef _ibp_oledb__props2__handler__extract_value__common__neg1_zero_positive_i4_H_
#define _ibp_oledb__props2__handler__extract_value__common__neg1_zero_positive_i4_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__neg1_zero_positive_i4

/// <summary>
///  Реализация ExtractValue для I4-свойств больше или равных -1.
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Common__neg1_zero_positive_i4
 :public IBP_OLEDB_Props2__Handler__ExtractValue
{
 private:
  typedef IBP_OLEDB_Props2__Handler__ExtractValue__Common__neg1_zero_positive_i4   self_type;

  IBP_OLEDB_Props2__Handler__ExtractValue__Common__neg1_zero_positive_i4(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef LONG                              value_type;

 private:
  IBP_OLEDB_Props2__Handler__ExtractValue__Common__neg1_zero_positive_i4();

 ~IBP_OLEDB_Props2__Handler__ExtractValue__Common__neg1_zero_positive_i4();

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();

  //IBP_OLEDB_Props2__Handler__ExtractValue interface --------------------
  virtual bool ExtractValue(const VARIANT&  sourceValue,
                            VARIANT*        pResultValue)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  static self_type sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__neg1_zero_positive_i4

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
