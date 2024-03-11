////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++.
//                                                 Dmitry Kovalenko. 20.11.2018.
#ifndef _oledb_props2__data__values_H_
#define _oledb_props2__data__values_H_

#include <ole_lib/oledb/provider/props2/oledb_props2__data__op_ctx.h>
#include <ole_lib/oledb/oledb_common.h>

#include <ole_lib/ole_auto/ole_auto_variant.h>

#include <structure/tree/t_tree_avl.h>
#include <structure/t_fix_vector.h>

#include <structure/stl/t_stl_map.h>
#include <structure/stl/t_stl_set.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__Values

class OLEDB_Props2__Data__Values:public t_oledb_smart_memory_object
{
 private:
  typedef OLEDB_Props2__Data__Values                       self_type;

  OLEDB_Props2__Data__Values(const self_type&);
  self_type& operator = (const self_type&);

 protected:
  virtual ~OLEDB_Props2__Data__Values();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>         self_ptr;

  typedef structure::t_smart_object_ptr<const self_type>   self_cptr;

  typedef structure::t_const_wstr_box                      wstr_box_type;

  typedef structure::t_const_str_box                       str_box_type;

  typedef structure::t_value_with_null<SHORT>              short_type_n;

  typedef structure::t_value_with_null<LONG>               long_type_n;

  struct tagCopyKind_Clone{};

  struct tagCopyKind_Child{};

  struct tagCopyKind_ReadOnly{};

 public:
  typedef bool (*PFnFilter_ByGuid)(REFGUID propGuid);
 
  typedef structure::t_stl_set
           <DBPROPID,
            std::less<DBPROPID>,
            TOLEDBMemoryAllocator>                         ids2_type;

  typedef structure::t_stl_map
           <GUID,
            ids2_type,
            ole_lib::TGuidLess,
            TOLEDBMemoryAllocator>                         ids1_type;

 public:
  OLEDB_Props2__Data__Values();

  OLEDB_Props2__Data__Values(const self_type*  pX,
                             tagCopyKind_Clone copyTag);

  OLEDB_Props2__Data__Values(const self_type*  pX,
                             tagCopyKind_Child copyTag);

  OLEDB_Props2__Data__Values(const self_type*     pX,
                             tagCopyKind_ReadOnly copyTag);

  //interface ------------------------------------------------------------
  bool HasValueOrDefault
        (REFGUID                    propGuid,
         DBPROPID                   propId)const;

  void PrepareGetValue
        (OLEDB_Props2__Data__OpCtx& op_ctx,
         REFGUID                    propGuid,
         DBPROPID                   propId)const;

  bool GetValue
        (OLEDB_Props2__Data__OpCtx& op_ctx,
         REFGUID                    propGuid,
         DBPROPID                   propId,
         DBPROPOPTIONS*             pResult_dwOptions,
         VARIANT*                   pResult_Value)const;

  bool ExtractValue
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         VARTYPE                    propVarType,
         const VARIANT&             sourceValue,
         VARIANT*                   pResultValue)const;

  void PrepareSetValue
        (OLEDB_Props2__Data__OpCtx& op_ctx,
         REFGUID                    propGuid,
         DBPROPID                   propId,
         DBPROPOPTIONS              dwOptions,
         const VARIANT&             Value,
         DBPROPSTATUS*              pResult_dwStatus,
         VARIANT*                   pResult_Value)const;

 public: //---------------------------------------------------------------
  bool Direct__GetValue
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         DBPROPOPTIONS*             pResult_dwOptions,
         VARIANT*                   pResult_Value)const;

  bool Direct__GetDefaultValue
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         VARIANT*                   pResult_Value)const;

  void Direct__SetValue
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         DBPROPOPTIONS              dwOptions,
         const VARIANT&             Value);

  void Direct__ForceResetTopValues();

 public: //---------------------------------------------------------------
  ids1_type AUX__GetAllIDs
        (PFnFilter_ByGuid           pfnFilter)const;

  std::wstring AUX__GetValue__wstr
        (REFGUID                    propGuid,
         DBPROPID                   propId)const;

  std::wstring AUX__GetValue__wstr_e
        (REFGUID                    propGuid,
         DBPROPID                   propId)const;

  SHORT AUX__GetValue__short
        (REFGUID                    propGuid,
         DBPROPID                   propId)const;

  short_type_n AUX__GetValue__short_n
        (REFGUID                    propGuid,
         DBPROPID                   propId)const;

  LONG AUX__GetValue__long
        (REFGUID                    propGuid,
         DBPROPID                   propId)const;

  long_type_n AUX__GetValue__long_n
        (REFGUID                    propGuid,
         DBPROPID                   propId)const;

  bool AUX__GetValue__bool
        (REFGUID                    propGuid,
         DBPROPID                   propId)const;

  template<typename TFlag>
  TFlag AUX__GetValue__BoolAsFlag
        (REFGUID                   propGuid,
         DBPROPID                  propId,
         TFlag                     Flag)const;

 public:
  void AUX__SetValue__req
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         const VARIANT&             Value);

  void AUX__SetValue__req__bstr
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         wstr_box_type              Value);

  void AUX__SetValue__req__bstr
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         str_box_type               Value);

  void AUX__SetValue__req__bool
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         bool                       Value);

  void AUX__SetValue__req__short
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         SHORT                      Value);

  void AUX__SetValue__req__long
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         LONG                       Value);

 protected: //------------------------------------------------------------
  virtual bool Internal__HasValueOrDefault
        (REFGUID                    propGuid,
         DBPROPID                   propId)const;

  virtual void Internal__PrepareGetValue
        (OLEDB_Props2__Data__OpCtx& op_ctx,
         REFGUID                    propGuid,
         DBPROPID                   propId)const;

  virtual bool Internal__GetValue
        (OLEDB_Props2__Data__OpCtx& op_ctx,
         REFGUID                    propGuid,
         DBPROPID                   propId,
         DBPROPOPTIONS*             pResult_dwOptions,
         VARIANT*                   pResult_Value)const;

  virtual bool Internal__ExtractValue
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         VARTYPE                    propVarType,
         const VARIANT&             sourceValue,
         VARIANT*                   pResultValue)const;

  virtual void Internal__PrepareSetValue
        (OLEDB_Props2__Data__OpCtx& op_ctx,
         REFGUID                    propGuid,
         DBPROPID                   propId,
         DBPROPOPTIONS              dwOptions,
         const VARIANT&             Value,
         DBPROPSTATUS*              pResult_dwStatus,
         VARIANT*                   pResult_Value)const;

  virtual bool Internal__Direct__GetValue
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         DBPROPOPTIONS*             pResult_dwOptions,
         VARIANT*                   pResult_Value)const;

  virtual bool Internal__Direct__GetDefaultValue
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         VARIANT*                   pResult_Value)const;

  virtual void Internal__Direct__SetValue
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         DBPROPOPTIONS              dwOptions,
         const VARIANT&             Value);

  virtual void Internal__Direct__ForceResetTopValues();

 private:
  bool Helper__GetValue
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         DBPROPOPTIONS*             pResult_dwOptions,
         VARIANT*                   pResult_Value)const;

  bool Helper__GetDefaultValue
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         VARIANT*                   pResult_Value)const;

 private:
  bool Helper__AUX__GetValue__bool
        (REFGUID                    propGuid,
         DBPROPID                   propId,
         const char                 bugcheck_src[])const;

 private:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Helper__ThrowBugCheck__NoValue
         (const char* place,
          REFGUID     propGuid,
          DBPROPID    propId);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Helper__ThrowBugCheck__BadValueType
         (const char* place,
          REFGUID     propGuid,
          DBPROPID    propId,
          VARTYPE     actualVarType);

 private:
  class tag_prop_value
  {
   private:
    typedef tag_prop_value self_type;

    self_type& operator = (const self_type&);

   public:
    ole_lib::TVariant m_varValue;
    DBPROPOPTIONS     m_dwOptions;

   public:
    tag_prop_value(const self_type&);

    explicit tag_prop_value(DBPROPID propId);

   ~tag_prop_value();

    //--------------------------------------
    DBPROPID GetPropId()const;

   private:
    DBPROPID m_propId;
  };//class tag_prop_value

 private:
  class tag_prop_value_less
  {
   public:
    bool operator () (const tag_prop_value& x1,const tag_prop_value& x2)const;

    bool operator () (const tag_prop_value& x,DBPROPID id)const;

    bool operator () (DBPROPID id,const tag_prop_value& x)const;
  };//class tag_item_less

 private:
  typedef structure::t_tree_avl
          <tag_prop_value,
           tag_prop_value_less,
           TOLEDBMemoryAllocator>           tag_prop_values;

 private:
  class tag_prop_set
  {
   private:
    typedef tag_prop_set    self_type;

    self_type& operator = (const self_type&);

   public:
    GUID               m_PropSetGuid;
    tag_prop_values    m_PropValues;

   public:
    tag_prop_set(const self_type&);

    explicit tag_prop_set(REFGUID propSetGuid);

    bool operator == (REFGUID propSetGuid)const;
  };//class tag_prop_set

 private:
  class tag_prop_sets:public t_oledb_smart_memory_object
  {
   private:
    typedef tag_prop_sets                               self_type;

    tag_prop_sets(const self_type&);
    self_type& operator = (const self_type&);

   ~tag_prop_sets();

   public: //typedefs ----------------------------------------------------
    typedef structure::t_smart_object_ptr<self_type>    self_ptr;

   public:
    structure::t_fix_vector<tag_prop_set,6> m_items;

    tag_prop_sets();

    self_ptr clone()const;
  };//class tag_prop_sets

 private:
  // [data source init property values, data source initialized]
  // [command default props, command props, rowset props]
  // [session default props, session props]
  using stack_type
   =structure::t_fix_vector<tag_prop_sets::self_ptr,3> ;

 private:
  stack_type m_stack;

  const bool m_is_read_only;

#ifndef NDEBUG
  bool m_DEBUG__in_reset_top_values;
#endif
};//class OLEDB_Props2__Data__Values

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__Values

template<typename TFlag>
TFlag OLEDB_Props2__Data__Values::AUX__GetValue__BoolAsFlag
                                           (REFGUID        propGuid,
                                            DBPROPID const propId,
                                            TFlag    const Flag)const
{
 const bool v=this->Helper__AUX__GetValue__bool
               (propGuid,
                propId,
                "OLEDB_Props2__Data__Values::AUX__GetValue__BoolAsFlag"); //throw

 if(v)
 {
  return Flag;
 }//if

 return TFlag();
}//AUX__GetValue__BoolAsFlag

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
