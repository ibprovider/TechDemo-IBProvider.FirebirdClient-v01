////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__prepare_set_value__prop__ExtProps.h
//! \brief   Реализация PrepareSetValue для свойства "Extended Properties".
//! \author  Kovalenko Dmitry
//! \date    20.12.2018
#ifndef _ibp_oledb__props2__handler__prepare_set_value__prop__ExtProps_H_
#define _ibp_oledb__props2__handler__prepare_set_value__prop__ExtProps_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__prepare_set_value.h"

#include "source/oledb/props2/values/datasource/ibp_oledb__props2__values__datasource.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps

/// <summary>
///  Реализация PrepareSetValue для свойства "Extended Properties".
/// </summary>
class IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps
 :public IBP_OLEDB_Props2__Handler__PrepareSetValue
{
 private:
  typedef IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps   self_type;

  IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps(const self_type&);
  self_type& operator = (const self_type&);

 private:
  IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps();

 ~IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps();

 public:
  static const IBP_OLEDB_Props2__Handler__PrepareSetValue* GetInstancePtr();

  //IBP_OLEDB_Props2__Handler__PrepareSetValue interface -----------------
  virtual void PrepareSetValue
                (const oledb_lib::OLEDB_Props2__Data__Values* pValues,
                 oledb_lib::OLEDB_Props2__Data__OpCtx&        op_ctx,
                 DBPROPOPTIONS                                sourceOptions,
                 const VARIANT&                               sourceValue,
                 DBPROPSTATUS*                                pResult_dwStatus,
                 VARIANT*                                     pResult_Value)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  typedef std::pair<const GUID*,const IBP_OLEDB_Props2__DescrData*> find_result_type;

  typedef structure::t_const_wstr_box                               wstr_box_type;

  typedef find_result_type (*PFnFind)(const wstr_box_type& propName);

 private:
  static PFnFind Helper__SelectFindFunc
                            (IBP_OLEDB_Props2__Values__DATASOURCE::enumAllowedValuesKind valuesKind);

 private:
  static find_result_type Helper__Find1__DbInit
                            (const wstr_box_type& propName);

  static find_result_type Helper__Find2__DbInit_DsCreate
                            (const wstr_box_type& propName);

  static find_result_type Helper__Find3__DbInit_DsCreate_Sess
                            (const wstr_box_type& propName);

 private:
  static const IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps sm_Instance;
};//class IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
