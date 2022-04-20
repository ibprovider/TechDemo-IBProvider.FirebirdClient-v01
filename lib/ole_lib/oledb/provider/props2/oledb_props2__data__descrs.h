////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++.
//                                                 Dmitry Kovalenko. 20.11.2018.
#ifndef _oledb_props2__data__descrs_H_
#define _oledb_props2__data__descrs_H_

#include <ole_lib/oledb/provider/props2/oledb_props2__data__descr.h>
#include <ole_lib/oledb/oledb_memory.h>
#include <ole_lib/ole_auto/ole_auto_variant.h>

#include <structure/tree/t_tree_avl.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__Descrs

class OLEDB_Props2__Data__Descrs:public t_oledb_smart_memory_object
{
 private:
  typedef OLEDB_Props2__Data__Descrs                     self_type;

  OLEDB_Props2__Data__Descrs(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~OLEDB_Props2__Data__Descrs();

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>       self_ptr;

  typedef structure::t_smart_object_ptr<const self_type> self_cptr;

  typedef OLEDB_Props2__Data__Descr::wms_type            wms_type;

  typedef OLEDB_Props2__Data__Descr::rule_flags_type     rule_flags_type;

 private: //--------------------------------------------------------------
  typedef OLEDB_Props2__Data__Descr                      item_type;

  class tag_item_less
  {
   public:
    bool operator () (const item_type& x1,
                      const item_type& x2)const;

    bool operator () (const item_type& x,
                      DBPROPID         id)const;

    bool operator () (DBPROPID         id,
                      const item_type& x)const;
  };//class tag_item_less

  typedef structure::t_tree_avl
           <item_type,
            tag_item_less,
            TOLEDBMemoryAllocator>                       items_type;

 public: //---------------------------------------------------------------
  typedef items_type::const_iterator                     const_iterator;

 public: //---------------------------------------------------------------
  REFGUID m_Guid;
  REFGUID m_SpecialGuid;

  OLEDB_Props2__Data__Descrs(REFGUID Guid,
                             REFGUID SpecialGuid,
                             size_t  nCapacity=0);

  //interface ------------------------------------------------------------

  /// <summary>
  ///  Compare with set's guid
  /// </summary>
  //! \param[in] Guid
  //! \return
  //!  true - equal identifiers
  bool IsGuid(REFGUID Guid) const;

  /// <summary>
  ///  Compare with group set's guid
  /// </summary>
  //! \param[in] SpecialGuid
  //! \return
  //!  true - equal identifiers
  bool IsSpecialGuid(REFCLSID SpecialGuid) const;

  //----------------------------------------------------------------------
  /// <summary>
  ///  Number of property descriptions
  /// </summary>
  size_t Count()const;

  const_iterator cbegin()const;

  const_iterator cend()const;

  const_iterator begin()const;

  const_iterator end()const;

  //----------------------------------------------------------------------
  /// <summary>
  ///  Finding a property by Id.
  /// </summary>
  //! \param[in] propId
  //! \return
  //!  end(), if property not found.
  const_iterator find(DBPROPID propId) const;

  //----------------------------------------------------------------------
  /// <summary>
  ///  Append new property.
  /// </summary>
  //! \param[in] dwPropID
  //! \param[in] dwFlags
  //! \param[in] VarType
  //! \param[in] Data
  //! \param[in] wmsDescription
  //!  Для формирования используйте макрос OLEDB_PDESCR2
  //! \param[in] ruleFlags
  void Add(DBPROPID                 dwPropID,
           DBPROPFLAGS              dwFlags,
           VARTYPE                  VarType,
           wms_type                 wmsDescription,
           rule_flags_type          ruleFlags=0);

 private:
  items_type m_items;
};//class OLEDB_Props2__Data__Descrs

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
