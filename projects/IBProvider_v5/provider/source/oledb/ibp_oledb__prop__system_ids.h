////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb
//! \file    ibp_oledb__prop__system_ids.cpp
//! \brief   Идентификаторы системных OLE DB свойств провайдера
//! \author  Kovalenko Dmitry
//! \date    09.01.2019
#ifndef _ibp_oledb__prop__system_ids_H_
#define _ibp_oledb__prop__system_ids_H_

#include <oledb.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////

///Идентификатор внутреннего информационного набора свойств
extern const GUID IBP_DBPROPSET_SYS_DATASOURCEINFO;

enum:DBPROPID
{
 /// Есть поддержка запроса вида "INSERT ... RETURNING ..."
 IBP_DBPROP__SYS_DSINFO__CAN_GET_SERVER_DATA_ON_INSERT          =1,

 /// Есть поддержка запроса вида "UPDATE ... RETURNING ..."
 IBP_DBPROP__SYS_DSINFO__CAN_GET_SERVER_DATA_ON_UPDATE          =2,

 /// Есть поддержка запроса вида "DELETE ... RETURNING ..."
 IBP_DBPROP__SYS_DSINFO__CAN_GET_SERVER_DATA_ON_DELETE          =3,
};//enum

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
