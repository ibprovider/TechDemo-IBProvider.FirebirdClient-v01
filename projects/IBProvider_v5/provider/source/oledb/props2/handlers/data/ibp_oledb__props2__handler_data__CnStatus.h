////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler_data__CnStatus.h
//! \brief   ƒанные дл€ получени€ значени€ свойства "Connection Status"
//! \author  Kovalenko Dmitry
//! \date    30.12.2018
#ifndef _ibp_oledb__props2__handler_data__CnStatus_H_
#define _ibp_oledb__props2__handler_data__CnStatus_H_

#include "source/ibp_memory.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__HandlerData__CnStatus

class IBP_OLEDB_Props2__HandlerData__CnStatus:public IBP_SmartMemoryObject
{
 private:
  typedef IBP_OLEDB_Props2__HandlerData__CnStatus              self_type;

  IBP_OLEDB_Props2__HandlerData__CnStatus(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>              self_ptr;

 private:
  IBP_OLEDB_Props2__HandlerData__CnStatus(LONG CnStatus);

  virtual ~IBP_OLEDB_Props2__HandlerData__CnStatus();

 public:
  static self_ptr Create(LONG CnStatus);

  static REFGUID GetID();

  //interface ------------------------------------------------------------
  LONG GetCnStatus()const;

 private:
  const LONG m_CnStatus;

 private:
  static const GUID sm_ID;
};//class IBP_OLEDB_Props2__HandlerData__CnStatus

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
