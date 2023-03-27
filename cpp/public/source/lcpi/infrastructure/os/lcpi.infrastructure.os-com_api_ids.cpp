////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. COM API Identifiers.
//                                                 Kovalenko Dmitry. 14.11.2022.
#include <_pch_.h>
#pragma hdrstop

#include <lcpi/infrastructure/os/lcpi.infrastructure.os-com_api_ids.h>

namespace lcpi{namespace infrastructure{namespace os{
////////////////////////////////////////////////////////////////////////////////
//Standard Windows COM API

//{A7602B24-06D8-4111-B5A1-DAC303A5CDB1}
extern const GUID COM_API_ID__STANDARD
 ={0xA7602B24,0x06D8,0x4111,{0xB5,0xA1,0xDA,0xC3,0x03,0xA5,0xCD,0xB1}};

////////////////////////////////////////////////////////////////////////////////
//LCPI Easy COM API

//{BDCD0100-D1F4-4FED-BD6F-B9E29F105BD4}
extern const GUID COM_API_ID__LCPI_EASY_COM
 ={0xBDCD0100,0xD1F4,0x4FED,{0xBD,0x6F,0xB9,0xE2,0x9F,0x10,0x5B,0xD4}};

////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms infrastructure*/}/*nms lcpi*/
