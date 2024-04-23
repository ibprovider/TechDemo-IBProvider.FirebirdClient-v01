////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__connector__init_fb.cpp
//! \brief   The initialization of connection for Firebird server.
//! \author  Kovalenko Dmitry
//! \date    01.05.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__connector.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include <structure/t_str_version.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Connector

void RemoteFB__Connector::Helper__FinalInitialize__FB
                             (const oledb_lib::OLEDB_Props2__Data__Values* const pDsPropValues,
                              const cns_type&                                    cns)
{
 assert(pDsPropValues);
 assert(m_spData);
 assert(m_spData->GetPort());

 //----------------------------------------- DBMS Name
 structure::tstr_to_tstr
  (&m_spData->m_DBMS_Name,
   isc_base::g_dbms_name_Firebird);

 //----------------------------------------- Let's configure this connector for our server version
 structure::str_version const fb_ver_cur(cns.dbms.version);

 if(fb_ver_cur.empty())
 {
  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb,
    ibp_mce_common__no_dbms_version_0);
 }//if

 //--------------------------- FB v4+
 if(structure::cmp_str_version_prefix(fb_ver_cur,"4")>=0)
 {
#if(IBP_EDITION_ID==IBP_EDITION_ID__FREE)

  IBP_ThrowFreeVersionCanNotWorkWithThisServer
   (cns.dbms.name,
    cns.dbms.version,
    cns.dbms.descr_Ex.null()?"???":cns.dbms.descr_Ex.value().c_str());

#else
  return this->Helper__FinalInitialize__FB_04_00
          (pDsPropValues,
           cns);
#endif
 }//if

 //--------------------------- FB v3+
 if(structure::cmp_str_version_prefix(fb_ver_cur,"3")>=0)
 {
  return this->Helper__FinalInitialize__FB_03_00
          (pDsPropValues,
           cns);
 }//if

 //---------------------------
 {
  return this->Helper__FinalInitialize__FB_02_05
          (pDsPropValues,
           cns);
 }//local
}//Helper__FinalInitialize__FB

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
