////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb
//! \file    ibp_oledb__prop__system_ids.cpp
//! \brief   �������������� ��������� OLE DB ������� ����������
//! \author  Kovalenko Dmitry
//! \date    09.01.2019
#ifndef _ibp_oledb__prop__system_ids_H_
#define _ibp_oledb__prop__system_ids_H_

#include <oledb.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////

///������������� ����������� ��������������� ������ �������
extern const GUID IBP_DBPROPSET_SYS_DATASOURCEINFO;

enum:DBPROPID
{
 /// ���� ��������� ������� ���� "INSERT ... RETURNING ..."
 IBP_DBPROP__SYS_DSINFO__CAN_GET_SERVER_DATA_ON_INSERT          =1,

 /// ���� ��������� ������� ���� "UPDATE ... RETURNING ..."
 IBP_DBPROP__SYS_DSINFO__CAN_GET_SERVER_DATA_ON_UPDATE          =2,

 /// ���� ��������� ������� ���� "DELETE ... RETURNING ..."
 IBP_DBPROP__SYS_DSINFO__CAN_GET_SERVER_DATA_ON_DELETE          =3,
};//enum

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
