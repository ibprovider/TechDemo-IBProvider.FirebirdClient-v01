////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_sqlncli
//! \file    ibp_sqlncli.cpp
//! \brief   Конструкции SQLNCLI, поддерживаемые IBProvider'ом.
//! \author  Kovalenko Dmitry.
//! \date    25.12.2012.
#include <_pch_.h>
#pragma hdrstop

#include "source/ibp_sqlncli.h"

namespace lcpi{namespace ibp{namespace sqlncli{
////////////////////////////////////////////////////////////////////////////////
//DBPROPSET GUIDs

extern const GUID DBPROPSET_SQLSERVERROWSET=
 {0x5CF4CA11,0xEF21,0x11D0,{0x97,0xE7,0x0,0xC0,0x4F,0xC2,0xAD,0x98}};

////////////////////////////////////////////////////////////////////////////////
//IIDs

//"1FF1F743-8BB0-4C00-ACC4-C10E43B08FC1"
extern const IID IID_ISSAsynchStatus
 ={0x1FF1F743,0x8BB0,0x4C00,{0xAC,0xC4,0xC1,0x0E,0x43,0xB0,0x8F,0xC1}};

//"5CF4CA12-EF21-11d0-97E7-00C04FC2AD98"
extern const IID IID_ISQLServerErrorInfo
 ={0x5CF4CA12,0xEF21,0x11d0,{0x97,0xE7,0x00,0xC0,0x4F,0xC2,0xAD,0x98}};

////////////////////////////////////////////////////////////////////////////////
}/*nms sqlncli*/}/*nms ibp*/}/*nms lcpi*/
