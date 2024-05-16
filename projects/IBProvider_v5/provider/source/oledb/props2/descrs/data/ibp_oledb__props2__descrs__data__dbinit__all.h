////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__data__dbinit__all.h
//! \brief   Определение описаний всех свойств инициализации подключения
//! \author  Kovalenko Dmitry
//! \date    21.12.2018
#ifndef _ibp_oledb__props2__descrs__data__dbinit__all_H_
#define _ibp_oledb__props2__descrs__data__dbinit__all_H_

#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data.h"
#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data__helpers.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{namespace data{
////////////////////////////////////////////////////////////////////////////////

#define IBP_OLEDB_PROPS2__DESCR_DATA(InitTag,                             \
                                     PropId,                              \
                                     PropDescr,                           \
                                     PropFlags,                           \
                                     PropRules,                           \
                                     ListOfAdditionalParams,              \
                                     POST_INIT_CALLS)                     \
static const IBP_OLEDB_Props2__DescrData                                  \
 sm_DescrFor__##PropId;

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL

class IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL;

 public: //typedefs ------------------------------------------------------
  class tag_data;

  using find_result_type=std::pair<const GUID*,const IBP_OLEDB_Props2__DescrData*>;

  using wstr_box_type=lib::structure::t_const_wstr_box;

 public:
  struct STD
  {
# include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit_std.dat"
  };

  struct EXT
  {
# include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit_ext.dat"
  };

 public:
#ifdef NDEBUG
  //В релизной сборке этот метод не должен вызываться!
  //А для отладочной использование BOX-версии не критично.
  static find_result_type Find(const wchar_t* pName)=delete;
#endif

  static find_result_type Find(const wstr_box_type& Name);

 public:
#ifndef NDEBUG
  static void DEBUG__Check_sm_IndexByName();

  using DEBUG__items_range_type
   =lib::structure::t_first_last<const IBP_OLEDB_Props2__DescrData_IndexByName_Item*>;

  static DEBUG__items_range_type DEBUG__GetRange_STD();

  static DEBUG__items_range_type DEBUG__GetRange_EXT();
#endif
};//class IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL

////////////////////////////////////////////////////////////////////////////////
#undef IBP_OLEDB_PROPS2__DESCR_DATA
////////////////////////////////////////////////////////////////////////////////
}/*nms data*/}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
