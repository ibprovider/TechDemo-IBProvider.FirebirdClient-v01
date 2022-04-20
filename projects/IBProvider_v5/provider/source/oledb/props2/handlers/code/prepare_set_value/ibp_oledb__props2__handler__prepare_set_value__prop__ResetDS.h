////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__prepare_set_value__prop__ResetDS.h
//! \brief   Реализация PrepareSetValue для свойства "Reset Datasource".
//! \author  Kovalenko Dmitry
//! \date    20.12.2018
#ifndef _ibp_oledb__props2__handler__prepare_set_value__prop__ResetDS_H_
#define _ibp_oledb__props2__handler__prepare_set_value__prop__ResetDS_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__prepare_set_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS

/// <summary>
///  Реализация PrepareSetValue для свойства "Reset Datasource".
/// </summary>
class IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS
 :public IBP_OLEDB_Props2__Handler__PrepareSetValue
{
 private:
  typedef IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS   self_type;

  IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS(const self_type&);
  self_type& operator = (const self_type&);

 private:
  IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS();

 ~IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS();

 public:
  static const IBP_OLEDB_Props2__Handler__PrepareSetValue* GetInstancePtr();

  //IBP_OLEDB_Props2__Handler__PrepareSetValue interface -----------------
  virtual void PrepareSetValue
                (const oledb_lib::OLEDB_Props2__Data__Values* pValues,
                 oledb_lib::OLEDB_Props2__Data__OpCtx&        op_ctx,
                 DBPROPOPTIONS                                sourceOptions,
                 const VARIANT&                               sourceValue,
                 DBPROPSTATUS*                                pResult_dwStatus,
                 VARIANT*                                     pResult_Value)const COMP_W000004_OVERRIDE_FINAL;

 private:
  static const IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS sm_Instance;
};//class IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
