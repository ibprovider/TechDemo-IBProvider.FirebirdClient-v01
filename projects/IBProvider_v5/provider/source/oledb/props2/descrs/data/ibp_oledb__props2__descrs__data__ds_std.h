////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__data__ds_std.h
//! \brief   ќписание стандартных свойств источника данных
//! \author  Kovalenko Dmitry
//! \date    28.12.2018
#ifndef _ibp_oledb__props2__descrs__data__ds_std_H_
#define _ibp_oledb__props2__descrs__data__ds_std_H_

#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{namespace data{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__DATASOURCE_STD

class IBP_OLEDB_Props2__Descrs__Data__DATASOURCE_STD
{
 public:
  static IBP_OLEDB_Props2__DescrDataRange GetDataRange();

  static const IBP_OLEDB_Props2__DescrData* Find(DBPROPID propId);

 private:
  static const IBP_OLEDB_Props2__DescrData sm_descrs[];
};//class IBP_OLEDB_Props2__Descrs__Data__DATASOURCE_STD

////////////////////////////////////////////////////////////////////////////////
}/*nms data*/}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
