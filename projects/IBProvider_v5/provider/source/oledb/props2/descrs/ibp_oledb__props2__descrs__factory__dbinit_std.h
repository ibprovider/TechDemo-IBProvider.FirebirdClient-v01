////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__factory__dbinit_std.h
//! \brief   Фабрика набора описаний свойств
//! \author  Kovalenko Dmitry
//! \date    14.12.2018
#ifndef _ibp_oledb__props2__descrs__factory__dbinit_std_H_
#define _ibp_oledb__props2__descrs__factory__dbinit_std_H_

#include <ole_lib/oledb/provider/props2/oledb_props2__data__descrs.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs_Factory__DBINIT_STD

class IBP_OLEDB_Props2__Descrs_Factory__DBINIT_STD
{
 private:
  typedef IBP_OLEDB_Props2__Descrs_Factory__DBINIT_STD  self_type;

 public:
  static oledb_lib::OLEDB_Props2__Data__Descrs::self_cptr CreatePropDescrs();

  static oledb_lib::OLEDB_Props2__Data__Descrs::self_cptr GetPropDescrs();
};//class IBP_OLEDB_Props2__Descrs_Factory__DBINIT_STD

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
