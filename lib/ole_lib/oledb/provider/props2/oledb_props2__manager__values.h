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
            const VARIANT&>                 SetPropValueTriggerType;


 public:
  OLEDB_Props2__Manager__Values();

  OLEDB_Props2__Manager__Values(const self_type& x);

 ~OLEDB_Props2__Manager__Values();

  self_type& operator = (const self_type&);

  //interface ------------------------------------------------------------
  void AddInfo(const OLEDB_Props2__Data__Descrs* pDescrs);

  //----------------------------------------------------------------------
  /// <summary>
  ///  ������ �������� �������. THROW.
  /// </summary>
  //!
  //! ���������� �������� pfnGetFilter:
  //!  - DBPROPSTATUS_OK
  //!  - DBPROPSTATUS_NOTSUPPORTED
  template<class TCallCtx>
  HRESULT GetProperties(TCallCtx&                         callCtx,
                        const OLEDB_Props2__Data__Values* pValues,
                        const ULONG                       cPropertyIDSets,
                        const DBPROPIDSET                 rgPropertyIDSets[],
                        ULONG*                            pcPropertySets,
                        DBPROPSET**                       prgPropertySets,
                        PFnFilter                         pfnGetFilter)const;//throw

  /// <summary>
  ///  ��������� �������� �������. THROW.
  /// </summary>
  //! \param[in] pValues
  //! \param[in] cPropertySets
  //! \param[in] rgPropertySets
  //! \param[in] Captious
  //!  "�����������" ��������� �������� �������
  //! \param[in] pfnSetFilter
  //! \param[in] setPropValueTrigger__OnBefore
  //!  May be not defined.
  //! \param[in] setPropValueTrigger__OnAfter
  //!  May be not defined.
  //!
  //! ���������� �������� pfnSetFilter:
  //!  - DBPROPSTATUS_OK
  //!  - DBPROPSTATUS_NOTSETTABLE
  //!  - DBPROPSTATUS_NOTSUPPORTED
  template<class TCallCtx>
  HRESULT SetProperties(TCallCtx&                   callCtx,
                        OLEDB_Props2__Data__Values* pValues,
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
  ///  ���������� ��������� ��� ��������� �������� �������
  /// </summary>
  //! \param[in] op_ctx
  //! \param[in] pDescrs
  //!  Not null.
  //! \param[in] pPropIDSet
  //!  ���� NULL, �� ����� ��������� �������� ���� �������
  void Helper__PrepareGetValues
        (tag_internal_get_props_ctx&       op_ctx,
         const OLEDB_Props2__Data__Descrs* pDescrs,
         const DBPROPIDSET*                pPropIDSet)const;

  /// <summary>
  ///  ���������� ��������� ��� ��������� �������� ��������
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
  ///  ��������� �������� �������
  /// </summary>
  //! \param[in,out] callCtx,
  //! \param[in]     op_ctx
  //! \param[in]     pDescrs
  //!  Not null.
  //! \param[in]     pPropIDSet
  //! \param[in,out] PropSet
  template<class TCallCtx>
  void Helper__GetValues
        (TCallCtx&                         callCtx,
         tag_internal_get_props_ctx&       op_ctx,
         const OLEDB_Props2__Data__Descrs* pDescrs,
         const DBPROPIDSET*                pPropIDSet,
         DBPROPSET&                        PropSet)const;

  /// <summary>
  ///  ��������� �������� ��������
  /// </summary>
  //! \param[in,out] callCtx,
  //! \param[in]     op_ctx
  //! \param[in]     propGuid,
  //! \param[in]     Descr
  //! \param[in,out] DbProp
  template<class TCallCtx>
  void Helper__GetValue
        (TCallCtx&                         callCtx,
         tag_internal_get_props_ctx&       op_ctx,
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
////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/oledb/provider/props2/oledb_props2__manager__values__get.cc>
#include <ole_lib/oledb/provider/props2/oledb_props2__manager__values__set.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
