////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__data__session_ext.h
//! \brief   ќписание специализированных свойств сессии
//! \author  Kovalenko Dmitry
//! \date    13.12.2018
#ifndef _ibp_oledb__props2__descrs__data__session_ext_H_
#define _ibp_oledb__props2__descrs__data__session_ext_H_

#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{namespace data{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__SESSION_EXT

class IBP_OLEDB_Props2__Descrs__Data__SESSION_EXT
{
 public:
  static IBP_OLEDB_Props2__DescrDataPtrRange GetDataPtrRange();

  static const IBP_OLEDB_Props2__DescrData* Find(DBPROPID propId);

 private:
  static const IBP_OLEDB_Props2__DescrData* const sm_descrs[];
};//class IBP_OLEDB_Props2__Descrs__Data__SESSION_EXT

////////////////////////////////////////////////////////////////////////////////
}/*nms data*/}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
