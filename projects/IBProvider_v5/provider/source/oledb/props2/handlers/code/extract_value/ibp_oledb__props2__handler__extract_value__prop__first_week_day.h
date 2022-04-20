////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__first_week_day.h
//! \brief   Реализация ExtractValue для свойства "first_week_day".
//! \author  Kovalenko Dmitry
//! \date    17.12.2018
#ifndef _ibp_oledb__props2__handler__extract_value__prop__first_week_day_H_
#define _ibp_oledb__props2__handler__extract_value__prop__first_week_day_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

#include <structure/t_const_str_box.h>
#include <structure/t_value_with_null.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day

/// <summary>
///  Реализация ExtractValue для свойства "first_week_day".
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day
 :public IBP_OLEDB_Props2__Handler__ExtractValue
{
 private:
  typedef IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day   self_type;

  IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_value_with_null<long>        long_type_N;

 private:
  IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day();

 ~IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day();

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();

  /// <summary>
  ///  Получение номера первого дня недели
  /// </summary>
  //! \param[in] propValue
  //!  VT_EMPTY or VT_BSTR with valid string
  static long_type_N GetFirstDayNum(const VARIANT& propValue);

  //IBP_OLEDB_Props2__Handler__ExtractValue interface --------------------
  virtual bool ExtractValue(const VARIANT&  sourceValue,
                            VARIANT*        pResultValue)const COMP_W000004_OVERRIDE_FINAL;

 private:
  struct tag_day_aliase;
  struct tag_day_number;
  struct tag_data;

 private:
  static IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
