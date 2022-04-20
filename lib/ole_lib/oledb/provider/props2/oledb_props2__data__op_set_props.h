////////////////////////////////////////////////////////////////////////////////
//! \ingroup  oledb_lib_provider
//! \file     oledb_props2__data__op_set_props.h
//! \brief    Контекст операций со свойствами
//! \author   Kovalenko Dmitry
//! \date     28.11.2018
#ifndef _oledb_props2__data__op_set_props_H_
#define _oledb_props2__data__op_set_props_H_

#include <ole_lib/oledb/oledb_common.h>
#include <ole_lib/ole_auto/ole_auto_variant.h>

#include <structure/stl/t_stl_deque.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup oledb_lib_provider
//! @{
////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__OpSetProps

class OLEDB_Props2__Data__OpSetProps COMP_W000006_CLASS_FINAL
 :public structure::t_basic_smart_interface_impl__static_v2<structure::t_smart_interface>
{
 private:
  typedef OLEDB_Props2__Data__OpSetProps                     self_type;

  OLEDB_Props2__Data__OpSetProps(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>           self_ptr;

 public:
  enum value_kind_type
  {
   value_kind__IsSuperPrimary      =-1,
   value_kind__IsPrimary           =0,

   value_kind__IsRelated           =1,
   value_kind__IsRelated_Optional  =2,
   value_kind__IsRelated_Condition =3,
  };//enum value_kind_type

 public:
  enum cond_kind_type
  {
   cond_kind__None                 =0,
   cond_kind__Eq                   =1,
   cond_kind__NotEq                =2,
  };//enum cond_kind_type

 public:
  /// <summary>
  ///  Data with new value of property
  /// </summary>
  class tag_prop_data COMP_W000006_CLASS_FINAL
   :public structure::t_basic_smart_interface_impl__static_v2<structure::t_smart_interface>
  {
   private:
    typedef tag_prop_data                                    self_type;

    tag_prop_data(const self_type&);
    self_type& operator = (const self_type&);

    tag_prop_data(self_type&&);
    self_type& operator = (self_type&&);

   public: //typedefs ------------------------------------------------------
    const DBPROP&         m_DbProp;
#ifndef NDEBUG
    const GUID            m_DbPropGuid;
#endif

    //-------------------
    self_type*            m_pNext;

    //-------------------
    const TDBPropID       m_propID;

    const value_kind_type m_valueKind;

    const cond_kind_type  m_condKind;

    ole_lib::TVariant     m_value;
    DBPROPSTATUS          m_prepare_status;

    bool                  m_ignore_assign;

#ifndef NDEBUG
    bool                  m_DEBUG_was_prepared;
#endif

   public:
    tag_prop_data(const DBPROP&    DbProp,
                  REFGUID          DbPropGuid);

    tag_prop_data(const self_type* pMaster,
                  REFGUID          propGuid,
                  DBPROPID         propId,
                  value_kind_type  valueKind,
                  cond_kind_type   condKind=cond_kind__None);

   ~tag_prop_data();

   //interface -----------------------------------------------------------
   bool TestValueKind__IsSuperPrimary()const;

   bool TestValueKind__IsPrimary()const;

   bool TestValueKind__IsRelated()const;

   bool TestValueKind__IsRelated_Optional()const;

   bool TestValueKind__IsRelated_Condition()const;

   //---------------------------------------------------------------------
   bool TestValueWeight__IsPriority()const;
  };//class tag_prop_data

 public:
  class tag_master_prop_data_setup;

 public:
  typedef structure::t_smart_object_ptr<tag_prop_data>       prop_data_ptr;

  typedef structure::t_smart_object_ptr<const tag_prop_data> prop_data_cptr;

  typedef structure::t_stl_deque
           <tag_prop_data,
            TOLEDBMemoryAllocator>                           items_type;

  typedef items_type::const_iterator                         const_iterator;

 public:
  OLEDB_Props2__Data__OpSetProps();

 ~OLEDB_Props2__Data__OpSetProps();

  //interface ------------------------------------------------------------

  /// <summary>
  ///  Identifier of context data
  /// </summary>
  static REFGUID GetID();

  //----------------------------------------------------------------------
  //! \brief New property registration
  //! \param[in] DbProp
  //! \param[in] DbPropGuid
  //! \return
  //!  Not null
  prop_data_ptr Add_Primary
                 (const DBPROP& DbProp,
                  REFGUID       DbPropGuid);

  //----------------------------------------------------------------------
  prop_data_ptr AddFromQueue();

  //----------------------------------------------------------------------
  prop_data_ptr AddChildProp_Related
                 (REFGUID   propGuid,
                  DBPROPID  propId);

  prop_data_ptr AddChildProp_Related_Optional
                 (REFGUID   propGuid,
                  DBPROPID  propId);

  prop_data_ptr AddChildProp_Related_Condition__Eq
                 (REFGUID   propGuid,
                  DBPROPID  propId);

  prop_data_ptr AddChildProp_Related_Condition__NotEq
                 (REFGUID   propGuid,
                  DBPROPID  propId);

  //----------------------------------------------------------------------
  prop_data_ptr QueueChildProp_Primary
                 (REFGUID   propGuid,
                  DBPROPID  propId);

  prop_data_ptr QueueChildProp_SuperPrimary
                 (REFGUID   propGuid,
                  DBPROPID  propId);

  //----------------------------------------------------------------------
  const_iterator All_Begin()const;

  const_iterator All_End()const;

  //----------------------------------------------------------------------
  prop_data_cptr GetMainList_Head()const;

  prop_data_cptr GetConditionList_Head()const;

 private:
  prop_data_ptr Helper__AddChildProp_Related_Condition
                 (REFGUID        propGuid,
                  DBPROPID       propId,
                  cond_kind_type condKind);

 private:
  items_type m_items;

 private:
  tag_prop_data* m_MainList__pHead;

  tag_prop_data* m_QueueList__pHead;

  tag_prop_data* m_ConditionList__pHead;

 private:
  prop_data_cptr m_master_prop_data;

 private:
  static const GUID sm_id;
};//class OLEDB_Props2__Data__OpSetProps

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__OpSetProps::tag_master_prop_data_setup

class OLEDB_Props2__Data__OpSetProps::tag_master_prop_data_setup COMP_W000006_CLASS_FINAL
{
 private:
  typedef tag_master_prop_data_setup        self_type;

  tag_master_prop_data_setup(const self_type&);
  self_type& operator = (const self_type&);

 public:
  tag_master_prop_data_setup(OLEDB_Props2__Data__OpSetProps* pOpData,
                             const tag_prop_data*            pPropData);

 ~tag_master_prop_data_setup();

 private:
  OLEDB_Props2__Data__OpSetProps::self_ptr const m_spOpData;

  prop_data_cptr const m_spPropData;
};//class OLEDB_Props2__Data__OpSetProps::tag_master_prop_data_setup

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
