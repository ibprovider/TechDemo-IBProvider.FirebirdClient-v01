////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descr_data__index_by_name.h
//! \brief   Конструкции для индексирования описаний свойств по имени
//! \author  Kovalenko Dmitry
//! \date    31.01.2019
#ifndef _ibp_oledb__props2__descr_data__index_by_name_H_
#define _ibp_oledb__props2__descr_data__index_by_name_H_

#include "source/oledb/props2/ibp_oledb__props2__forward.h"

#include <structure/t_const_str_box.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//content

class IBP_OLEDB_Props2__DescrData_IndexByName_Item;
class IBP_OLEDB_Props2__DescrData_IndexByName_Less;

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__DescrData_IndexByName_Item

class IBP_OLEDB_Props2__DescrData_IndexByName_Item
{
 private:
  typedef IBP_OLEDB_Props2__DescrData_IndexByName_Item   self_type;

 public:
  const wchar_t*                      pName;
  const IBP_OLEDB_Props2__DescrData*  pDescr;

#ifndef NDEBUG
  const wchar_t*                      DEBUG__pName;
#endif

 public:
#ifndef NDEBUG
  static void DEBUG_Check_Range(const self_type* pFirst,
                                const self_type* pLast);
#endif
};//struct IBP_OLEDB_Props2__DescrData_IndexByName_Item

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__DescrData_IndexByName_Less

class IBP_OLEDB_Props2__DescrData_IndexByName_Less
{
 public:
  typedef structure::t_const_wstr_box       wstr_box_type;

 public:
  bool operator () (const IBP_OLEDB_Props2__DescrData_IndexByName_Item& x1,
                    const IBP_OLEDB_Props2__DescrData_IndexByName_Item& x2)const=delete;

#ifdef NDEBUG
  bool operator () (const IBP_OLEDB_Props2__DescrData_IndexByName_Item& x,
                    const wchar_t*                                      name)const=delete;

  bool operator () (const wchar_t*                                      name,
                    const IBP_OLEDB_Props2__DescrData_IndexByName_Item& x)const=delete;
#endif

  bool operator () (const IBP_OLEDB_Props2__DescrData_IndexByName_Item& x,
                    const wstr_box_type&                                name)const;

  bool operator () (const wstr_box_type&                                name,
                    const IBP_OLEDB_Props2__DescrData_IndexByName_Item& x)const;
};//class IBP_OLEDB_Props2__DescrData_IndexByName_Less

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
