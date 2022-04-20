////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__remote_protocol_arch.h
//! \brief   Реализация ExtractValue для свойства "remote:protocol_arch".
//! \author  Kovalenko Dmitry
//! \date    18.12.2018
#ifndef _ibp_oledb__props2__handler__extract_value__prop__remote_protocol_arch_H_
#define _ibp_oledb__props2__handler__extract_value__prop__remote_protocol_arch_H_

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
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch

/// <summary>
///  Реализация ExtractValue для свойства "remote:protocol_arch".
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch
 :public IBP_OLEDB_Props2__Handler__ExtractValue
{
 private:
  typedef IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch   self_type;

  IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch(const self_type&);
  self_type& operator = (const self_type&);

 private:
  IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch();

 ~IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch();

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();

  //IBP_OLEDB_Props2__Handler__ExtractValue interface --------------------
  virtual bool ExtractValue(const VARIANT&  sourceValue,
                            VARIANT*        pResultValue)const COMP_W000004_OVERRIDE_FINAL;

 private:
  static IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
