////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__get_value__prop__ResetDs.h
//! \brief   Реализация GetValue для свойства "Reset Datasource".
//! \author  Kovalenko Dmitry
//! \date    08.01.2019
#ifndef _ibp_oledb__props2__handler__get_value__prop__ResetDs_H_
#define _ibp_oledb__props2__handler__get_value__prop__ResetDs_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__get_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs

/// <summary>
///  Реализация GetValue для свойства "Reset Datasource".
/// </summary>
class IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs
 :public IBP_OLEDB_Props2__Handler__GetValue
{
 private:
  typedef IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs   self_type;

  IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs(const self_type&);
  self_type& operator = (const self_type&);

 private:
  IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs();

 ~IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs();

 public:
  static const IBP_OLEDB_Props2__Handler__GetValue* GetInstancePtr();

  //IBP_OLEDB_Props2__Handler__GetValue interface ------------------------
  virtual bool GetValue
                (const oledb_lib::OLEDB_Props2__Data__Values* pValues,
                 oledb_lib::OLEDB_Props2__Data__OpCtx&        op_ctx,
                 REFGUID                                      propGuid,
                 DBPROPID                                     propId,
                 DBPROPOPTIONS*                               pResult_dwOptions,
                 VARIANT*                                     pResult_Value)const COMP_W000004_OVERRIDE_FINAL;

 private:
  static const IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs sm_Instance;
};//class IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
