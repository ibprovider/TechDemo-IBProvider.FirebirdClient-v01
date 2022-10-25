////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler_data__CnStatus.cpp
//! \brief   ƒанные дл€ получени€ значени€ свойства "Connection Status"
//! \author  Kovalenko Dmitry
//! \date    30.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/data/ibp_oledb__props2__handler_data__CnStatus.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__HandlerData__CnStatus

const GUID IBP_OLEDB_Props2__HandlerData__CnStatus::sm_ID
 ={0xAB03FC87,0x5EF2,0x4EA5,{0xB7,0x44,0x7A,0x5F,0x79,0xFF,0x1B,0xA4}};

//------------------------------------------------------------------------
IBP_OLEDB_Props2__HandlerData__CnStatus::IBP_OLEDB_Props2__HandlerData__CnStatus
                                           (LONG const CnStatus)
 :m_CnStatus(CnStatus)
{
}//IBP_OLEDB_Props2__HandlerData__CnStatus

//------------------------------------------------------------------------
IBP_OLEDB_Props2__HandlerData__CnStatus::~IBP_OLEDB_Props2__HandlerData__CnStatus()
{
}//~IBP_OLEDB_Props2__HandlerData__CnStatus

//------------------------------------------------------------------------
IBP_OLEDB_Props2__HandlerData__CnStatus::self_ptr
 IBP_OLEDB_Props2__HandlerData__CnStatus::Create(LONG const CnStatus)
{
 return lib::structure::not_null_ptr(new self_type(CnStatus));
}//Create

//------------------------------------------------------------------------
REFGUID IBP_OLEDB_Props2__HandlerData__CnStatus::GetID()
{
 return sm_ID;
}//GetID

//interface --------------------------------------------------------------
LONG IBP_OLEDB_Props2__HandlerData__CnStatus::GetCnStatus()const
{
 return m_CnStatus;
}//GetCnStatus

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
