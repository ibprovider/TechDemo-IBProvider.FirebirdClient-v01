////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. COM interfaces for work with Registry Storage
//                                                 Kovalenko Dmitry. 16.12.2022.
#include <_pch_.h>
#pragma hdrstop

#include <lcpi/infrastructure/os/lcpi_svcs-registry_storage.h>

namespace lcpi{namespace infrastructure{namespace os{namespace lcpi_svcs{namespace registry_storage{
////////////////////////////////////////////////////////////////////////////////

// AC3EC6A5-7D2A-11ED-9757-80A589A03F33
extern const IID IID_LCPI_IRegistryStorageNames
 ={0xAC3EC6A5,0x7D2A,0x11ED,{0x97,0x57,0x80,0xA5,0x89,0xA0,0x3F,0x33}};

// AC3EC6A6-7D2A-11ED-9757-80A589A03F33
extern const IID IID_LCPI_IRegistryStorage
 ={0xAC3EC6A6,0x7D2A,0x11ED,{0x97,0x57,0x80,0xA5,0x89,0xA0,0x3F,0x33}};

////////////////////////////////////////////////////////////////////////////////
}/*nms registry_storage*/}/*nms lcpi_svcs*/}/*nms os*/}/*nms infrastructure*/}/*nms lcpi*/
