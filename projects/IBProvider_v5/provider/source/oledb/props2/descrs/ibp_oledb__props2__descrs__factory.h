////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__factory.h
//! \brief   Базовая фабрика набора описаний свойств
//! \author  Kovalenko Dmitry
//! \date    13.12.2018
#ifndef _ibp_oledb__props2__descrs__factory_H_
#define _ibp_oledb__props2__descrs__factory_H_

#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__data__descrs.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__DescrsFactories

class IBP_OLEDB_Props2__Descrs_Factory
{
 private:
  typedef IBP_OLEDB_Props2__Descrs_Factory  self_type;

 public:
  static void
   AppendDescrs
    (oledb_lib::OLEDB_Props2__Data__Descrs* pDescrs,
     IBP_OLEDB_Props2__DescrDataRange       dataRange);

  static void
   AppendDescrs
    (oledb_lib::OLEDB_Props2__Data__Descrs* pDescrs,
     IBP_OLEDB_Props2__DescrDataPtrRange    dataRange);
};//class IBP_OLEDB_Props2__Descrs_Factory__DBINIT_STD

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
