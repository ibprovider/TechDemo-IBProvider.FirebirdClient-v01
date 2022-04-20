////////////////////////////////////////////////////////////////////////////////
//LCPI OLEDB Provider for InterBase/Firebird SDK.
//                                                 Kovalenko Dmitry. 25.01.2019
#include <_pch_.h>
#pragma hdrstop

#include <lcpi/sdk/ibprovider/v05/lcpi_sdk__ibprovider__v05__props_ids.h>

namespace lcpi{namespace sdk{namespace ibprovider{namespace v05{
////////////////////////////////////////////////////////////////////////////////
//Идентификаторы специфических наборов свойств

//параметры подключения
extern const GUID IBP_DBPROPSET_INIT
 ={0xD5781BA0,0x7B97,0x11D6,{0xAD,0x1E,0x00,0xA0,0xC9,0x07,0xDB,0x93}};

//информация о базе данных
extern const GUID IBP_DBPROPSET_DATASOURCEINFO
 ={0xD5781BA1,0x7B97,0x11D6,{0xAD,0x1E,0x00,0xA0,0xC9,0x07,0xDB,0x93}};

//свойства сессии
extern const GUID IBP_DBPROPSET_SESSION
 ={0xD5781BA2,0x7B97,0x11D6,{0xAD,0x1E,0x00,0xA0,0xC9,0x07,0xDB,0x93}};

//свойства набора рядов
extern const GUID IBP_DBPROPSET_ROWSET
 ={0xD5781BA3,0x7B97,0x11D6,{0xAD,0x1E,0x00,0xA0,0xC9,0x07,0xDB,0x93}};

//информационные свойства набора рядов
extern const GUID IBP_DBPROPSET_ROWSETINFO
 ={0xD5781BA4,0x7B97,0x11D6,{0xAD,0x1E,0x00,0xA0,0xC9,0x07,0xDB,0x93}};

//свойства новой базы данных
extern const GUID IBP_DBPROPSET_DATASOURCECREATE
 ={0xD5781BA5,0x7B97,0x11D6,{0xAD,0x1E,0x00,0xA0,0xC9,0x07,0xDB,0x93}};

//информационные свойства запроса
extern const GUID IBP_DBPROPSET_STATEMENTINFO
 ={0xD5781BA6,0x7B97,0x11D6,{0xAD,0x1E,0x00,0xA0,0xC9,0x07,0xDB,0x93}};

//{D5781BA7-7B97-11D6-AD1E-00A0C907DB93}

////////////////////////////////////////////////////////////////////////////////
}/*nms v05*/}/*nms ibprovider*/}/*nms sdk*/}/*nms lcpi*/
