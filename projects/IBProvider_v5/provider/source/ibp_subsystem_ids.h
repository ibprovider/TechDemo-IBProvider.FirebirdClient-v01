////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_subsystem_ids.h
//! \brief   Перечисление идентификаторов подсистем провайдера.
//! \author  Kovalenko Dmitry
//! \date    05.12.2014
#ifndef _ibp_subsystem_ids_H_
#define _ibp_subsystem_ids_H_

#include "rc/ibp_msg_subsystems.rh"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////
//enum ibp_subsystem_id

/// <summary>
///  Перечисление идентификаторов подсистем провайдера.
/// </summary>
enum t_ibp_subsystem_id
{
 //----------------------------------------- ISC API.
 ibp_subsystem__isc_api
  =IBP_SUBSYSTEM__ISC_API,

 ibp_subsystem__isc_api_v1
  =IBP_SUBSYSTEM__ISC_API_V1,

 ibp_subsystem__isc_api_v2
  =IBP_SUBSYSTEM__ISC_API_V2,

 ibp_subsystem__isc_api__init_cn
  =IBP_SUBSYSTEM__ISC_API__INIT_CN,

 //----------------------------------------- ISC API. Firebird.
 ibp_subsystem__isc_api__init_cn_to_fb
  =IBP_SUBSYSTEM__ISC_API__INIT_CN_TO_FB,
 
 //----------
 ibp_subsystem__isc_api__fb0_9
  =IBP_SUBSYSTEM__ISC_API__FB0_9,

 ibp_subsystem__isc_api__fb1_0
  =IBP_SUBSYSTEM__ISC_API__FB1_0,

 ibp_subsystem__isc_api__fb1_5
  =IBP_SUBSYSTEM__ISC_API__FB1_5,

 ibp_subsystem__isc_api__fb2_0
  =IBP_SUBSYSTEM__ISC_API__FB2_0,

 ibp_subsystem__isc_api__fb2_1
  =IBP_SUBSYSTEM__ISC_API__FB2_1,

 ibp_subsystem__isc_api__fb2_5
  =IBP_SUBSYSTEM__ISC_API__FB2_5,

 ibp_subsystem__isc_api__fb2_5_1
  =IBP_SUBSYSTEM__ISC_API__FB2_5_1,

 ibp_subsystem__isc_api__fb3_0
  =IBP_SUBSYSTEM__ISC_API__FB3_0,

 ibp_subsystem__isc_api__fb3_0_4
  =IBP_SUBSYSTEM__ISC_API__FB3_0_4,

 //----------------------------------------- ISC API. InterBase.
 ibp_subsystem__isc_api__init_cn_to_ib
  =IBP_SUBSYSTEM__ISC_API__INIT_CN_TO_IB,
 
 //----------
 ibp_subsystem__isc_api__ib4_0
  =IBP_SUBSYSTEM__ISC_API__IB4_0,

 ibp_subsystem__isc_api__ib5_0
  =IBP_SUBSYSTEM__ISC_API__IB5_0,

 ibp_subsystem__isc_api__ib6_0
  =IBP_SUBSYSTEM__ISC_API__IB6_0,

 ibp_subsystem__isc_api__ib6_5
  =IBP_SUBSYSTEM__ISC_API__IB6_5,

 ibp_subsystem__isc_api__ib7_0
  =IBP_SUBSYSTEM__ISC_API__IB7_0,

 ibp_subsystem__isc_api__ib7_1
  =IBP_SUBSYSTEM__ISC_API__IB7_1,

 ibp_subsystem__isc_api__ib7_5
  =IBP_SUBSYSTEM__ISC_API__IB7_5,

 ibp_subsystem__isc_api__ib8_0
  =IBP_SUBSYSTEM__ISC_API__IB8_0,

 ibp_subsystem__isc_api__ib9_0
  =IBP_SUBSYSTEM__ISC_API__IB9_0,

 ibp_subsystem__isc_api__ib10_0
  =IBP_SUBSYSTEM__ISC_API__IB10_0,

 ibp_subsystem__isc_api__ib11_0
  =IBP_SUBSYSTEM__ISC_API__IB11_0,

 ibp_subsystem__isc_api__ib12_0
  =IBP_SUBSYSTEM__ISC_API__IB12_0,

 ibp_subsystem__isc_api__ib13_0
  =IBP_SUBSYSTEM__ISC_API__IB13_0,

 ibp_subsystem__isc_api__ib14_0
  =IBP_SUBSYSTEM__ISC_API__IB14_0,

 //----------------------------------------- ISC API. Yaffil.
 ibp_subsystem__isc_api__init_cn_to_ya
  =IBP_SUBSYSTEM__ISC_API__INIT_CN_TO_YA,

 ibp_subsystem__isc_api__ya
  =IBP_SUBSYSTEM__ISC_API__YA,

 //----------------------------------------- RemoteFB
 ibp_subsystem__remote_fb
  =IBP_SUBSYSTEM__REMOTE_FB,

 ibp_subsystem__remote_fb__inet
  =IBP_SUBSYSTEM__REMOTE_FB__INET,

 ibp_subsystem__remote_fb__pset01
  =IBP_SUBSYSTEM__REMOTE_FB__PSET01,

 ibp_subsystem__remote_fb__pset02
  =IBP_SUBSYSTEM__REMOTE_FB__PSET02,

 ibp_subsystem__remote_fb__p10
  =IBP_SUBSYSTEM__REMOTE_FB__P10,

 ibp_subsystem__remote_fb__p11
  =IBP_SUBSYSTEM__REMOTE_FB__P11,

 ibp_subsystem__remote_fb__p12
  =IBP_SUBSYSTEM__REMOTE_FB__P12,

 ibp_subsystem__remote_fb__p13
  =IBP_SUBSYSTEM__REMOTE_FB__P13,

 //----------------------------------------- DirectFB
 ibp_subsystem__direct_fb
  =IBP_SUBSYSTEM__DIRECT_FB,

 ibp_subsystem__direct_fb__init_cn
  =IBP_SUBSYSTEM__DIRECT_FB__INIT_CN,
};//enum t_ibp_subsystem_id

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
