////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_base__dbparams_for_attach__processor.cpp
//! \brief   Утилиты обработки параметров инициализации подключения.
//! \author  Kovalenko Dmitry
//! \date    16.02.2019
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_base__dbparams_for_attach__processor.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__data__values.h>
#include <ole_lib/ole_auto/ole_auto_variant.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//class isc_base__dbparams_for_attach__processor

void isc_base__dbparams_for_attach__processor::set_dbinit_params
      (const oledb_lib::OLEDB_Props2__Data__Values* const pDsPropValues,
       isc_base__dbparams_for_attach__installer*    const pDbParamInstaller)
{
 assert(pDsPropValues);
 assert(pDbParamInstaller);

 ole_lib::TVariant propValue;

 //----------------------------------------- AUTH: INTEGRATED SECURITY
 if(pDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_INTEGRATED,nullptr,&propValue))
 {
  assert(propValue.vt==VT_BSTR);

  pDbParamInstaller->set_dbinit_param___auth__integrated(ole_lib::BStrToBox(propValue.bstrVal));
 }//if

 //----------------------------------------- AUTH: USER ID
 if(pDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_USERID,nullptr,&propValue))
 {
  assert(propValue.vt==VT_BSTR);

  pDbParamInstaller->set_dbinit_param___auth__user_id(ole_lib::BStrToBox(propValue.bstrVal));
 }//if

 //----------------------------------------- AUTH: PASSWORD
 if(pDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_PASSWORD,nullptr,&propValue))
 {
  assert(propValue.vt==VT_BSTR);

  pDbParamInstaller->set_dbinit_param___auth__password(ole_lib::BStrToBox(propValue.bstrVal));
 }//if

 //----------------------------------------- AUTH: ROLENAME
 if(pDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__ROLENAME,nullptr,&propValue))
 {
  assert(propValue.vt==VT_BSTR);

  pDbParamInstaller->set_dbinit_param___auth__rolename(ole_lib::BStrToBox(propValue.bstrVal));
 }//if

 //----------------------------------------- CTYPE
 if(pDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__CTYPE,nullptr,&propValue))
 {
  assert(propValue.vt==VT_BSTR);

  pDbParamInstaller->set_dbinit_param___ctype(ole_lib::BStrToBox(propValue.bstrVal));
 }//if

 //----------------------------------------- GARBAGE COLLECT
 if(pDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__GARBAGE_COLLECT,nullptr,&propValue))
 {
  assert(propValue.vt==VT_BOOL);

  pDbParamInstaller->set_dbinit_param___garbage_collect(propValue.boolVal!=VARIANT_FALSE);
 }//if

 //----------------------------------------- NUM BUFFERS
 if(pDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__NUM_BUFFERS,nullptr,&propValue))
 {
  assert(propValue.vt==VT_I4);

  pDbParamInstaller->set_dbinit_param___num_buffers(propValue.lVal);
 }//if

 //----------------------------------------- ENABLE DB TRIGGERS
 if(pDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__ENABLE_DB_TRIGGERS,nullptr,&propValue))
 {
  assert(propValue.vt==VT_BOOL);

  pDbParamInstaller->set_dbinit_param___enable_db_trigger(propValue.boolVal!=VARIANT_FALSE);
 }//if

 //----------------------------------------- SEP
 if(pDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__SYS_ENCRYPT_PASSWORD,nullptr,&propValue))
 {
  assert(propValue.vt==VT_BSTR);

  pDbParamInstaller->set_dbinit_param___sys_encrypt_password(ole_lib::BStrToBox(propValue.bstrVal));
 }//if
}//set_dbinit_params

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
