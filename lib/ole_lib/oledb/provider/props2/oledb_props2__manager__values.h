////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++.
//                                                 Dmitry Kovalenko. 24.11.2018.
#ifndef _oledb_props2__manager__values_H_
#define _oledb_props2__manager__values_H_

#include <ole_lib/oledb/provider/props2/oledb_props2__data__descrs.h>
#include <ole_lib/oledb/provider/props2/oledb_props2__data__values.h>

#include <structure/t_fix_vector.h>
#include <structure/t_closure.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Manager__Values

class OLEDB_Props2__Manager__Values COMP_W000006_CLASS_FINAL
{
 private:
  typedef OLEDB_Props2__Manager__Values     self_type;

 public: //typedefs ------------------------------------------------------
  /// <summary>
  ///  Function of read property filter
  /// </summary>
  typedef DBPROPSTATUS (TFnFilter)(const OLEDB_Props2__Data__Descrs* pDescrs);

  typedef TFnFilter*                        PFnFilter;

  typedef structure::t_closure
           <void,
           const OLEDB_Props2__Data__Values*,
           REFGUID,
           DBPROPID,
           DBPROPOPTIONS,
           const VARIANT&>                  SetPropValueTriggerType;


 public:
  OLEDB_Props2__Manager__Values();

  OLEDB_Props2__Manager__Values(const self_type& x);

 ~OLEDB_Props2__Manager__Values();

  self_type& operator = (const self_type&);

  //interface ------------------------------------------------------------
  void AddInfo(const OLEDB_Props2__Data__Descrs* pDescrs);

  //----------------------------------------------------------------------
  /// <summary>
  ///  Запрос значений свойств. THROW.
  /// </summary>
  //!
  //! Допустимые значения pfnGetFilter:
  //!  - DBPROPSTATUS_OK
  //!  - DBPROPSTATUS_NOTSUPPORTED
  HRESULT GetProperties(const OLEDB_Props2__Data__Values* pValues,
                        const ULONG                       cPropertyIDSets,
                        const DBPROPIDSET                 rgPropertyIDSets[],
                        ULONG*                            pcPropertySets,
                        DBPROPSET**                       prgPropertySets,
                        PFnFilter                         pfnGetFilter)const;//throw

  /// <summary>
  ///  Установка значений свойств. THROW.
  /// </summary>
  //! \param[in] pValues
  //! \param[in] cPropertySets
  //! \param[in] rgPropertySets
  //! \param[in] Captious
  //!  "Придирчивая" установка значений свойств
  //! \param[in] pfnSetFilter
  //! \param[in] setPropValueTrigger__OnBefore
  //!  May be not defined.
  //! \param[in] setPropValueTrigger__OnAfter
  //!  May be not defined.
  //!
  //! Допустимые значения pfnSetFilter:
  //!  - DBPROPSTATUS_OK
  //!  - DBPROPSTATUS_NOTSETTABLE
  //!  - DBPROPSTATUS_NOTSUPPORTED
  HRESULT SetProperties(OLEDB_Props2__Data__Values* pValues,
                        ULONG                       cPropertySets,
                        const DBPROPSET             rgPropertySets[],
                        bool                        Captious,
                        PFnFilter                   pfnSetFilter,
                        SetPropValueTriggerType     setPropValueTrigger__OnBefore=nullptr,
                        SetPropValueTriggerType     setPropValueTrigger__OnAfter=nullptr);

 private:
  const OLEDB_Props2__Data__Descrs* Helper__FindDescrs(REFGUID Guid)const;

 private: //--------------------------------------------------------------
  class tag_internal_get_props_ctx;

  /// <summary>
  ///  Подготовка контекста для получения значений свойств
  /// </summary>
  //! \param[in] op_ctx
  //! \param[in] pDescrs
  //!  Not null.
  //! \param[in] pPropIDSet
  //!  Если NULL, то будут запрошены значения всех свойств
  void Helper__PrepareGetValues
        (tag_internal_get_props_ctx&       op_ctx,
         const OLEDB_Props2__Data__Descrs* pDescrs,
         const DBPROPIDSET*                pPropIDSet)const;

  /// <summary>
  ///  Подготовка контекста для получения значения свойства
  /// <summary>
  //! \param[in] op_ctx
  //! \param[in] propGuid
  //! \param[in] Descr
  void Helper__PrepareGetValue
        (tag_internal_get_props_ctx&      op_ctx,
         REFGUID                          propGuid,
         const OLEDB_Props2__Data__Descr& Descr)const;

 private: //--------------------------------------------------------------
  /// <summary>
  ///  Получение значений свойств
  /// </summary>
  //! \param[in]     op_ctx
  //! \param[in]     pDescrs
  //!  Not null.
  //! \param[in]     pPropIDSet
  //! \param[in,out] PropSet
  void Helper__GetValues
        (tag_internal_get_props_ctx&       op_ctx,
         const OLEDB_Props2__Data__Descrs* pDescrs,
         const DBPROPIDSET*                pPropIDSet,
         DBPROPSET&                        PropSet)const;

  /// <summary>
  ///  Получение значения свойства
  /// </summary>
  //! \param[in]     op_ctx
  //! \param[in]     propGuid,
  //! \param[in]     Descr
  //! \param[in,out] DbProp
  void Helper__GetValue
        (tag_internal_get_props_ctx&       op_ctx,
         REFGUID                           propGuid,
         const OLEDB_Props2__Data__Descr&  Descr,
         DBPROP&                           DbProp)const;

 private: //--------------------------------------------------------------
  class tag_internal_set_props_ctx;

  class tag_internal_set_prop_data;

  class tag_internal_set_prop_result_state;

  class tag_internal_set_prop_data_less_by_id;

  class tag_set_prop_data_less_by_id;

  class tag_set_op_helper;

 private: //--------------------------------------------------------------
  typedef structure::t_fix_vector
           <8,
            OLEDB_Props2__Data__Descrs::self_cptr>    descrs_set_type;

 private: //--------------------------------------------------------------
  descrs_set_type m_descr_sets;
};//class OLEDB_Props2__Manager__Values

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Manager__Values::tag_internal_get_props_ctx

class OLEDB_Props2__Manager__Values::tag_internal_get_props_ctx COMP_W000006_CLASS_FINAL
{
 private:
  typedef tag_internal_get_props_ctx        self_type;

  tag_internal_get_props_ctx(const self_type&);
  self_type& operator = (const self_type&);

 public:
  const OLEDB_Props2__Data__Values::self_cptr m_spValues;

  OLEDB_Props2__Data__OpCtx m_external_ctx;

 public:
  explicit tag_internal_get_props_ctx(const OLEDB_Props2__Data__Values* pValues);

 ~tag_internal_get_props_ctx();
};//class OLEDB_Props2__Manager__Values::tag_internal_get_props_ctx

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
