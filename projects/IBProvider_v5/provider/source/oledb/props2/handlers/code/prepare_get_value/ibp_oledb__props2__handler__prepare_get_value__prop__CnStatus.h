////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__prepare_get_value__prop__CnStatus.h
//! \brief   Реализация PrepareGetValue для свойства "Connection Status".
//! \author  Kovalenko Dmitry
//! \date    30.12.2018
#ifndef _ibp_oledb__props2__handler__prepare_get_value__prop__CnStatus_H_
#define _ibp_oledb__props2__handler__prepare_get_value__prop__CnStatus_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__prepare_get_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus

/// <summary>
///  Реализация PrepareGetValue для свойства "Connection Status".
/// </summary>
class IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus
 :public IBP_OLEDB_Props2__Handler__PrepareGetValue
{
 private:
  typedef IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus   self_type;

  IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus(const self_type&);
  self_type& operator = (const self_type&);

 private:
  IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus();

 ~IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus();

 public:
  static const IBP_OLEDB_Props2__Handler__PrepareGetValue* GetInstancePtr();

  //IBP_OLEDB_Props2__Handler__PrepareSetValue interface -----------------
  virtual void PrepareGetValue
                (const oledb_lib::OLEDB_Props2__Data__Values* pValues,
                 oledb_lib::OLEDB_Props2__Data__OpCtx&        op_ctx,
                 REFGUID                                      propGuid,
                 DBPROPID                                     propId)const COMP_W000004_OVERRIDE_FINAL;

 private:
  static const IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus sm_Instance;
};//class IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
