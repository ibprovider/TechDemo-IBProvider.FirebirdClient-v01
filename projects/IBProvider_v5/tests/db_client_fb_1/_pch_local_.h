////////////////////////////////////////////////////////////////////////////////
#ifndef __pch_local__H_
#define __pch_local__H_

////////////////////////////////////////////////////////////////////////////////

#define LCPI_IBP_NMS lcpi::ibp

////////////////////////////////////////////////////////////////////////////////
//config ole_lib library

#define OLE_LIB_NO_BASE_UNKNOWN2
#define OLE_LIB_NO_COM_MODULE
#define OLE_LIB_NO_OLE_AUTO

#define OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO 0

#define OLEDB_LIB_NO_ADODB_TYPES

////////////////////////////////////////////////////////////////////////////////
//IBProvider code configuration

#define IBP_BUILD_TESTCODE

#define IBP_ENGINE_GLOBAL_OBJECTS 0

#define IBP_EDITION_ID 1

////////////////////////////////////////////////////////////////////////////////

#include <lcpi/sdk/ibprovider/v05/lcpi_sdk__ibprovider__v05.h>
#include <lcpi/sdk/ibprovider/v05/lcpi_sdk__ibprovider__v05__clsids.h>
#include <lcpi/sdk/ibprovider/v05/lcpi_sdk__ibprovider__v05__private_clsids.h>
#include <lcpi/sdk/ibprovider/v05/lcpi_sdk__ibprovider__v05__props_values.h>
#include <lcpi/sdk/ibprovider/v05/lcpi_sdk__ibprovider__v05__props_ids.h>

namespace ibprovider=lcpi::sdk::ibprovider::v05;

////////////////////////////////////////////////////////////////////////////////

#include "source/ibp_cfg_compile.h"

////////////////////////////////////////////////////////////////////////////////
//own implementation of ole_lib::TBaseUnknown2

#include "source_lib/ole_lib/ibp--ole_lib__base_unknown2.h"

////////////////////////////////////////////////////////////////////////////////
//own implementation of _Module

#include "source/ibp_com.h"

extern LCPI_IBP_NMS::IBP_ComModule _Module;

////////////////////////////////////////////////////////////////////////////////

namespace ibp=LCPI_IBP_NMS;

////////////////////////////////////////////////////////////////////////////////
#endif
