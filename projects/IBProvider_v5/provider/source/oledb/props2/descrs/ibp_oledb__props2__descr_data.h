////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descr_data.h
//! \brief   —туктура дл€ статического описани€ OLEDB свойства
//! \author  Kovalenko Dmitry
//! \date    13.12.2018
#ifndef _ibp_oledb__props2__descr_data_H_
#define _ibp_oledb__props2__descr_data_H_

#include "source/oledb/props2/ibp_oledb__props2__forward.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__data__descr.h>
#include <ole_lib/oledb/oledb_data_types.h>
#include <structure/t_first_last.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//struct IBP_OLEDB_Props2__DescrData

struct IBP_OLEDB_Props2__DescrData
{
 private:
  typedef IBP_OLEDB_Props2__DescrData                   self_type;

 public:
  typedef oledb_lib::OLEDB_Props2__Data__Descr::wms_type        wms_type;
  typedef oledb_lib::OLEDB_Props2__Data__Descr::rule_flags_type rule_flags_type;

 public:
  typedef oledb_lib::t_oledb_value__I2                  value_i2_type;
  typedef oledb_lib::t_oledb_value__I4                  value_i4_type;
  typedef const oledb_lib::t_oledb_value__WCHAR*        value_wstr_type;

 public:
  //ќписание дескриптора формируетс€ динамически
  static const rule_flags_type rule_flag__ibp_runtime_descr
   =oledb_lib::OLEDB_Props2__Data__Descr::rule_flag__user1;

  //«начение по-умолчанию определ€етс€ динамически
  static const rule_flags_type rule_flag__ibp_runtime_default
   =oledb_lib::OLEDB_Props2__Data__Descr::rule_flag__user2;

 public:
  enum DefaultValueTypeID
  {
   DefaultValueTypeID__empty  =0,
   DefaultValueTypeID__i2     =1,
   DefaultValueTypeID__i4     =2,
   DefaultValueTypeID__wstr   =3,
   DefaultValueTypeID__bool   =4,
  };//enum DefaultValueTypeID

  struct tagDefaultValue
  {
   DefaultValueTypeID  typeID;

   union
   {
    value_i2_type     valI2;
    value_i4_type     valI4;
    value_wstr_type   valWStr;
    bool              valBool;
   } value;
  };//struct tagDefaultValue

  typedef const IBP_OLEDB_Props2__Handler__ExtractValue* phandler__extract_value;

  typedef const IBP_OLEDB_Props2__Handler__PrepareSetValue* phandler__prepare_set_value;

  typedef const IBP_OLEDB_Props2__Handler__PrepareGetValue* phandler__prepare_get_value;

  typedef const IBP_OLEDB_Props2__Handler__GetValue* phandler__get_value;

  typedef const IBP_OLEDB_Props2__Handler__GetDefaultValue* phandler__get_default_value;

 public:
  struct tag_init__empty{};
  struct tag_init__i2{};
  struct tag_init__i4{};
  struct tag_init__wstr{};
  struct tag_init__bool{};

 public:
  class tag_ref_less;
  class tag_ptr_less;

 public:
  DBPROPID         m_PropId;
  wms_type         m_PropDescr;
  DBPROPFLAGS      m_PropFlags;
  rule_flags_type  m_RuleFlags;
  VARTYPE          m_PropVarType;

  DBPROPOPTIONS    m_DefaultOpt;
  tagDefaultValue  m_Default;

 public:
  phandler__extract_value      m_pHandler__ExtractValue;
  phandler__prepare_set_value  m_pHandler__PrepareSetValue;
  phandler__prepare_get_value  m_pHandler__PrepareGetValue;
  phandler__get_value          m_pHandler__GetValue;
  phandler__get_default_value  m_pHandler__GetDefaultValue;

 public:
  IBP_OLEDB_Props2__DescrData
   (tag_init__empty,
    DBPROPID                 PropId,
    wms_type                 PropDescr,
    DBPROPFLAGS              PropFlags,
    rule_flags_type          RuleFlags,
    VARTYPE                  PropVarType,
    DBPROPOPTIONS            DefaultOpt);

  IBP_OLEDB_Props2__DescrData
   (tag_init__i2,
    DBPROPID                 PropId,
    wms_type                 PropDescr,
    DBPROPFLAGS              PropFlags,
    rule_flags_type          RuleFlags,
    DBPROPOPTIONS            DefaultOpt,
    value_i2_type            DefaultValue);

  IBP_OLEDB_Props2__DescrData
   (tag_init__i4,
    DBPROPID                 PropId,
    wms_type                 PropDescr,
    DBPROPFLAGS              PropFlags,
    rule_flags_type          RuleFlags,
    DBPROPOPTIONS            DefaultOpt,
    value_i4_type            DefaultValue);

  IBP_OLEDB_Props2__DescrData
   (tag_init__wstr,
    DBPROPID                 PropId,
    wms_type                 PropDescr,
    DBPROPFLAGS              PropFlags,
    rule_flags_type          RuleFlags,
    DBPROPOPTIONS            DefaultOpt,
    value_wstr_type          staticDefaultValue);

  IBP_OLEDB_Props2__DescrData
   (tag_init__bool,
    DBPROPID                 PropId,
    wms_type                 PropDescr,
    DBPROPFLAGS              PropFlags,
    rule_flags_type          RuleFlags,
    DBPROPOPTIONS            DefaultOpt,
    bool                     DefaultValue);

  //post init interface --------------------------------------------------
  self_type& PostInit_SetHandler_ExtractValue
   (phandler__extract_value pHandler);

  self_type& PostInit_SetHandler_PrepareSetValue
   (phandler__prepare_set_value pHandler);

  self_type& PostInit_SetHandler_PrepareGetValue
   (phandler__prepare_get_value pHandler);

  self_type& PostInit_SetHandler_GetValue
   (phandler__get_value pHandler);

  self_type& PostInit_SetHandler_GetDefaultValue
   (phandler__get_default_value pHandler);

  //interface ------------------------------------------------------------
  void CopyDefaultValueTo(VARIANT* pResult_Value)const;
};//class IBP_OLEDB_Props2__DescrData

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__DescrData::tag_ref_less

class IBP_OLEDB_Props2__DescrData::tag_ref_less
{
 public:
  bool operator () (const IBP_OLEDB_Props2__DescrData& x1,const IBP_OLEDB_Props2__DescrData& x2)const;

  bool operator () (const IBP_OLEDB_Props2__DescrData& x,DBPROPID id)const;

  bool operator () (DBPROPID id,const IBP_OLEDB_Props2__DescrData& x)const;
};//class IBP_OLEDB_Props2__DescrData::tag_ref_less

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__DescrData::tag_ptr_less

class IBP_OLEDB_Props2__DescrData::tag_ptr_less
{
 public:
  bool operator () (const IBP_OLEDB_Props2__DescrData* p1,const IBP_OLEDB_Props2__DescrData* p2)const;

  bool operator () (const IBP_OLEDB_Props2__DescrData* p,DBPROPID id)const;

  bool operator () (DBPROPID id,const IBP_OLEDB_Props2__DescrData* p)const;
};//class IBP_OLEDB_Props2__DescrData::tag_ptr_less

////////////////////////////////////////////////////////////////////////////////

typedef structure::t_first_last<const IBP_OLEDB_Props2__DescrData*>
 IBP_OLEDB_Props2__DescrDataRange;

////////////////////////////////////////////////////////////////////////////////

typedef structure::t_first_last<const IBP_OLEDB_Props2__DescrData*const*>
 IBP_OLEDB_Props2__DescrDataPtrRange;

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
