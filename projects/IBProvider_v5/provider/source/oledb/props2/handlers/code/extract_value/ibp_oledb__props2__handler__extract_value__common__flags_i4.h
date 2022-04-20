////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__common__flags_i4.h
//! \brief   Реализация ExtractValue для битовых I4-свойств со списком допустимых значений.
//! \author  Kovalenko Dmitry
//! \date    18.12.2018
#ifndef _ibp_oledb__props2__handler__extract_value__common__flags_i4_H_
#define _ibp_oledb__props2__handler__extract_value__common__flags_i4_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__flags_i4

/// <summary>
///  Реализация ExtractValue для битовых I4-свойств со списком допустимых значений.
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Common__flags_i4
 :public IBP_OLEDB_Props2__Handler__ExtractValue
{
 private:
  typedef IBP_OLEDB_Props2__Handler__ExtractValue__Common__flags_i4   self_type;

  IBP_OLEDB_Props2__Handler__ExtractValue__Common__flags_i4(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef LONG                              value_type;

 public:
  IBP_OLEDB_Props2__Handler__ExtractValue__Common__flags_i4
                                           (const value_type* first,
                                            const value_type* last);

 ~IBP_OLEDB_Props2__Handler__ExtractValue__Common__flags_i4();

  //IBP_OLEDB_Props2__Handler__ExtractValue interface --------------------
  virtual bool ExtractValue(const VARIANT&  sourceValue,
                            VARIANT*        pResultValue)const COMP_W000004_OVERRIDE_FINAL;

 private:
  const value_type* const m_first;
  const value_type* const m_last;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__flags_i4

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
