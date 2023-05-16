////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__values.h
//! \brief   Ѕазовый класс контейнера значений свойств
//! \author  Kovalenko Dmitry
//! \date    01.01.2019
#ifndef _ibp_oledb__props2__values_H_
#define _ibp_oledb__props2__values_H_

#include "source/oledb/props2/ibp_oledb__props2__forward.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__data__values.h>
#include <ole_lib/oledb/provider/oledb_wms.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//!  @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Values

/// <summary>
///  Ѕазовый класс контейнера значений свойств
/// </summary>
class IBP_OLEDB_Props2__Values
 :public oledb_lib::OLEDB_Props2__Data__Values
{
 private:
  typedef IBP_OLEDB_Props2__Values                  self_type;
  typedef oledb_lib::OLEDB_Props2__Data__Values     inherited;

  IBP_OLEDB_Props2__Values(const self_type&);
  self_type& operator = (const self_type&);

 protected:
  IBP_OLEDB_Props2__Values();

  IBP_OLEDB_Props2__Values(const self_type*  pX,
                           tagCopyKind_Clone copyTag);

  IBP_OLEDB_Props2__Values(const self_type*  pX,
                           tagCopyKind_Child copyTag);

  virtual ~IBP_OLEDB_Props2__Values();

 public:
#ifndef NDEBUG
  bool DEBUG__IsChild()const;
#endif

 public:
  bool HasEqualPropValue
        (const IBP_OLEDB_Props2__Values* pOtherValues,
         REFGUID                         propGuid,
         DBPROPID                        propId)const;

  /// <summary>
  ///  ѕолучение строки с названи€ми свойства.
  /// </summary>
  /// \param[in] propGuid
  /// \param[in] propId
  oledb_lib::tagOLEDB_WMS GetPropName(REFGUID propGuid,DBPROPID propId)const;

  /// <summary>
  ///  „тение пользовательского значени€ свойства.
  /// </summary>
  bool Direct__GetUserValue
        (REFGUID         propGuid,
         DBPROPID        propId,
         DBPROPOPTIONS*  pResult_dwOptions,
         VARIANT*        pResult_Value)const;

#ifdef IBP_BUILD_TESTCODE
  bool TESTCODE__Base__GetValue
        (REFGUID         propGuid,
         DBPROPID        propId,
         DBPROPOPTIONS*  pResult_dwOptions,
         VARIANT*        pResult_Value)const;
#endif

 private:
  virtual bool Internal__HasValueOrDefault
        (REFGUID                               propGuid,
         DBPROPID                              propId)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void Internal__PrepareGetValue
        (oledb_lib::OLEDB_Props2__Data__OpCtx& op_ctx,
         REFGUID                               propGuid,
         DBPROPID                              propId)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool Internal__GetValue
        (oledb_lib::OLEDB_Props2__Data__OpCtx& op_ctx,
         REFGUID                               propGuid,
         DBPROPID                              propId,
         DBPROPOPTIONS*                        pResult_dwOptions,
         VARIANT*                              pResult_Value)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool Internal__ExtractValue
        (REFGUID                               propGuid,
         DBPROPID                              propId,
         VARTYPE                               propVarType,
         const VARIANT&                        sourceValue,
         VARIANT*                              pResultValue)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void Internal__PrepareSetValue
        (oledb_lib::OLEDB_Props2__Data__OpCtx& op_ctx,
         REFGUID                               propGuid,
         DBPROPID                              propId,
         DBPROPOPTIONS                         dwOptions,
         const VARIANT&                        Value,
         DBPROPSTATUS*                         pResult_dwStatus,
         VARIANT*                              pResult_Value)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool Internal__Direct__GetValue
        (REFGUID                               propGuid,
         DBPROPID                              propId,
         DBPROPOPTIONS*                        pResult_dwOptions,
         VARIANT*                              pResult_Value)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual bool Internal__Direct__GetDefaultValue
        (REFGUID                               propGuid,
         DBPROPID                              propId,
         VARIANT*                              pResult_Value)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual void Internal__Direct__SetValue
        (REFGUID                               propGuid,
         DBPROPID                              propId,
         DBPROPOPTIONS                         dwOptions,
         const VARIANT&                        Value) COMP_W000004_OVERRIDE;

 private:
  bool Helper__GetValueFromStaticPropData
        (REFGUID                               propGuid,
         DBPROPID                              propId,
         DBPROPOPTIONS*                        pResult_dwOptions,
         VARIANT*                              pResult_Value)const;

 private:
  virtual const IBP_OLEDB_Props2__DescrData& Internal__GetStaticPropData
        (REFGUID                               propGuid,
         DBPROPID                              propId)const=0;

 protected:
  void Helper__Direct__CopyUserValue
        (const IBP_OLEDB_Props2__Values* pSourceValues,
         REFGUID                         sourcePropGuid,
         DBPROPID                        sourcePropId,
         REFGUID                         targetPropGuid,
         DBPROPID                        targetPropId);

 private:
#ifndef NDEBUG
  const bool m_DEBUG__IsChild;
#endif
};//class IBP_OLEDB_Props2__Values

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
