////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_base__dbparams_for_create__processor.cpp
//! \brief   ”тилиты обработки параметров новой базы данных.
//! \author  Kovalenko Dmitry
//! \date    16.02.2019
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_base__dbparams_for_create__processor.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__data__values.h>
#include <ole_lib/ole_auto/ole_auto_variant.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//class isc_base__dbparams_for_create__processor

void isc_base__dbparams_for_create__processor::set_newdb_params
      (const oledb_lib::OLEDB_Props2__Data__Values* const pDsPropValues,
       isc_base__dbparams_for_create__installer*    const pDbParamInstaller)
{
 assert(pDsPropValues);
 assert(pDbParamInstaller);

 ole_lib::TVariant propValue;

 //----------------------------------------- DB DIALECT
 if(pDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_DATASOURCECREATE,ibprovider::IBP_DBPROP__DSCREATE__DATABASE_DIALECT,nullptr,&propValue))
 {
  assert(propValue.vt==VT_I4);

  pDbParamInstaller->set_newdb_param___db_dialect(propValue.lVal);
 }//if

 //----------------------------------------- PAGE SIZE
 if(pDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_DATASOURCECREATE,ibprovider::IBP_DBPROP__DSCREATE__DATABASE_PAGE_SIZE,nullptr,&propValue))
 {
  assert(propValue.vt==VT_I4);

  pDbParamInstaller->set_newdb_param___page_size(propValue.lVal);
 }//if

 //----------------------------------------- TYPE OF DB USERS
 if(pDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_DATASOURCECREATE,ibprovider::IBP_DBPROP__DSCREATE__TYPE_OF_DATABASE_USERS,nullptr,&propValue))
 {
  assert(propValue.vt==VT_I4);

  pDbParamInstaller->set_newdb_param___type_of_db_users(propValue.lVal);
 }//if
}//set_newdb_params

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
