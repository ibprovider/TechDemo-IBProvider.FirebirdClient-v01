////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__get_default_value__prop__ProviderName.h
//! \brief   Реализация GetDefaultValue для свойства "Provider Name".
//! \author  Kovalenko Dmitry
//! \date    14.01.2019
#ifndef _ibp_oledb__props2__handler__get_default_value__prop__ProviderName_H_
#define _ibp_oledb__props2__handler__get_default_value__prop__ProviderName_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__get_default_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName

/// <summary>
///  Реализация GetDefaultValue для свойства "Provider Name".
/// </summary>
class IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName
 :public IBP_OLEDB_Props2__Handler__GetDefaultValue
{
 private:
  typedef IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName self_type;

  IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName(const self_type&);
  self_type& operator = (const self_type&);

 private:
  IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName();

 ~IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName();

 public:
  static const IBP_OLEDB_Props2__Handler__GetDefaultValue* GetInstancePtr();

  //IBP_OLEDB_Props2__Handler__GetValue interface ------------------------
  virtual bool GetDefaultValue
                (const oledb_lib::OLEDB_Props2__Data__Values* pValues,
                 DBPROPOPTIONS*                               pResult_dwOptions,
                 VARIANT*                                     pResult_Value)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  static const IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName sm_Instance;
};//class IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
