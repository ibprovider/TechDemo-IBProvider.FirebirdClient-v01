////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. COM API Identifiers.
//                                                 Kovalenko Dmitry. 14.11.2022.
#ifndef _lcpi_infrastructure_os__com_api_ids_H_
#define _lcpi_infrastructure_os__com_api_ids_H_

#include <lcpi/infrastructure/os/.config.h>

#include <guiddef.h>

namespace lcpi{namespace infrastructure{namespace os{
////////////////////////////////////////////////////////////////////////////////
//Standard Windows COM API

//{A7602B24-06D8-4111-B5A1-DAC303A5CDB1}
extern const GUID COM_API_ID__STANDARD;

////////////////////////////////////////////////////////////////////////////////
//LCPI Easy COM API

//{BDCD0100-D1F4-4FED-BD6F-B9E29F105BD4}
extern const GUID COM_API_ID__LCPI_EASY_COM;

////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
