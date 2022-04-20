////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__common__tr_iso_level.h
//! \brief   Реализация ExtractValue для свойства с уровнем изоляции транзакции.
//! \author  Kovalenko Dmitry
//! \date    17.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__tr_iso_level.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__enum_i4.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__tr_iso_level::tag_data

class IBP_OLEDB_Props2__Handler__ExtractValue__Common__tr_iso_level::tag_data
{
 public:
  static const LONG sm_IsoLevels[];

  static const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_i4
   sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__tr_iso_level::tag_data

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__tr_iso_level::tag_data

const LONG IBP_OLEDB_Props2__Handler__ExtractValue__Common__tr_iso_level::tag_data::sm_IsoLevels[]
{
 {ISOLATIONLEVEL_READCOMMITTED  },
 {ISOLATIONLEVEL_REPEATABLEREAD },
 {ISOLATIONLEVEL_SERIALIZABLE   },
};//sm_IsoLevels

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_i4
 IBP_OLEDB_Props2__Handler__ExtractValue__Common__tr_iso_level::tag_data::sm_Instance
  (_BEG_END_(sm_IsoLevels));

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__tr_iso_level

const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Common__tr_iso_level::GetInstancePtr()
{
 return &tag_data::sm_Instance;
}//GetInstancePtr

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
