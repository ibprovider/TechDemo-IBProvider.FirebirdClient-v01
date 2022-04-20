////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__integ_auth.h
//! \brief   Реализация ExtractValue для свойства "Integrated Security".
//! \author  Kovalenko Dmitry
//! \date    15.12.2018
#ifndef _ibp_oledb__props2__handler__extract_value__prop__integ_auth_H_
#define _ibp_oledb__props2__handler__extract_value__prop__integ_auth_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth

/// <summary>
///  Реализация ExtractValue для свойства "Integrated Security".
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth
 :public IBP_OLEDB_Props2__Handler__ExtractValue
{
 private:
  typedef IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth   self_type;

  IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth(const self_type&);
  self_type& operator = (const self_type&);

 private:
  IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth();

 ~IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth();

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();

  //IBP_OLEDB_Props2__Handler__ExtractValue interface --------------------
  virtual bool ExtractValue(const VARIANT&  sourceValue,
                            VARIANT*        pResultValue)const COMP_W000004_OVERRIDE_FINAL;

 private:
  static IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
