////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++.
//                                                 Dmitry Kovalenko. 20.11.2018.
#ifndef _oledb_props2__data__descr_H_
#define _oledb_props2__data__descr_H_

#include <ole_lib/oledb/provider/oledb_wms.h>
#include <structure/t_smart_object.h>
#include <oledb.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////

#define OLEDB_PROPFLAGS_ROWSETRO          (DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ)
#define OLEDB_PROPFLAGS_ROWSETRW          (DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ | DBPROPFLAGS_WRITE)

#define OLEDB_PROPFLAGS_DATASOURCER       (DBPROPFLAGS_DATASOURCE | DBPROPFLAGS_READ)
#define OLEDB_PROPFLAGS_DATASOURCEW       (DBPROPFLAGS_DATASOURCE | DBPROPFLAGS_WRITE)
#define OLEDB_PROPFLAGS_DATASOURCERW      (DBPROPFLAGS_DATASOURCE | DBPROPFLAGS_READ | DBPROPFLAGS_WRITE)

#define OLEDB_PROPFLAGS_DATASOURCEINFOR   (DBPROPFLAGS_DATASOURCEINFO | DBPROPFLAGS_READ)

#define OLEDB_PROPFLAGS_DBINITR           (DBPROPFLAGS_DBINIT | DBPROPFLAGS_READ)
#define OLEDB_PROPFLAGS_DBINITRW          (DBPROPFLAGS_DBINIT | DBPROPFLAGS_READ | DBPROPFLAGS_WRITE)
#define OLEDB_PROPFLAGS_DBINITRWR         (DBPROPFLAGS_DBINIT | DBPROPFLAGS_READ | DBPROPFLAGS_WRITE | DBPROPFLAGS_REQUIRED)

#define OLEDB_PROPFLAGS_SESSIONRO         (DBPROPFLAGS_SESSION|DBPROPFLAGS_READ)
#define OLEDB_PROPFLAGS_SESSIONRW         (DBPROPFLAGS_SESSION|DBPROPFLAGS_READ|DBPROPFLAGS_WRITE)

#define OLEDB_PROPFLAGS_DATASOURCECREATEW (DBPROPFLAGS_DATASOURCECREATE|DBPROPFLAGS_WRITE)

////////////////////////////////////////////////////////////////////////////////

#define OLEDB_PDESCR2(wDescr) MAKE_OLEDB_WMS(wDescr)

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__Descr

class OLEDB_Props2__Data__Descr
 :public structure::t_basic_smart_interface_impl__static_v2<structure::t_smart_interface>
{
 private:
  typedef OLEDB_Props2__Data__Descr                          self_type;

  OLEDB_Props2__Data__Descr(const self_type& x);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<const self_type>     self_cptr;

  ///ƒл€ создани€ экземпл€ра этого класса используйте OLEDB_PDESCR2
  typedef tagOLEDB_WMS                                       wms_type;

 public:
  /// <summary>
  ///  ѕеречисление управл€ющих флагов свойства
  /// </summary>
  enum enum_rule_flags
  {
   /// »гнорирование установки значени€ свойства (SetDBPROP)
   rule_flag__ignore_assign        =0x01,

   /// <summary>
   ///  «начение €вл€етс€ динамическим, поэтому его нельз€ перезаписывать и сбрасывать.
   /// </summary>
   /// Example: read-only property, which returns the size of database.
   rule_flag__has_dynamic_value    =0x08,

   //---------------------------------------
   rule_flag__user1                =0x10,
   rule_flag__user2                =0x20,
   rule_flag__user3                =0x30,
   rule_flag__user4                =0x40,

  };//enum_flags

  typedef unsigned                                     rule_flags_type;

 public:
  OLEDB_Props2__Data__Descr(DBPROPID         propID,
                            wms_type         propDescr,
                            DBPROPFLAGS      propFlags,
                            VARTYPE          propVarType,
                            rule_flags_type  ruleFlags=0);

 ~OLEDB_Props2__Data__Descr();

  //interface ------------------------------------------------------------
  DBPROPID GetPropId()const;

  wms_type GetPropDescr()const;

  DBPROPFLAGS GetPropFlags()const;

  VARTYPE GetPropVarType()const;

  rule_flags_type GetRuleFlags()const;

  //test function --------------------------------------------------------
  bool TestPropFlag__IsWrite()const;

  bool TestPropFlag__IsRead()const;

  bool TestRuleFlag__has_dynamic_value()const;

 private:
  DBPROPID        m_PropId;
  wms_type        m_PropDescr;
  DBPROPFLAGS     m_PropFlags;
  VARTYPE         m_PropVarType;
  rule_flags_type m_RuleFlags;
};//class OLEDB_Props2__Data__Descr

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
