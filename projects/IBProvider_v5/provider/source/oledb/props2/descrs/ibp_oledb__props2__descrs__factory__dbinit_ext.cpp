////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__factory__dbinit_ext.cpp
//! \brief   Фабрика набора описаний свойств
//! \author  Kovalenko Dmitry
//! \date    14.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/descrs/ibp_oledb__props2__descrs__factory__dbinit_ext.h"
#include "source/oledb/props2/descrs/ibp_oledb__props2__descrs__factory.h"

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit_ext.h"

#ifndef IBP_BUILD_TESTCODE
#include "source/ibp_global_objects.h"
#endif

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs_Factory__DBINIT_EXT

oledb_lib::OLEDB_Props2__Data__Descrs::self_cptr
 IBP_OLEDB_Props2__Descrs_Factory__DBINIT_EXT::CreatePropDescrs()
{
 const auto r1
  =data::IBP_OLEDB_Props2__Descrs__Data__DBINIT_EXT::GetDataPtrRange();

 const size_t nCapacity
  =(r1.last-r1.first);

 const oledb_lib::OLEDB_Props2__Data__Descrs::self_ptr
  spDescrs
   (structure::not_null_ptr
     (new oledb_lib::OLEDB_Props2__Data__Descrs
       (ibprovider::IBP_DBPROPSET_INIT,
        DBPROPSET_DBINITALL,
        nCapacity)));

 assert(spDescrs);

 IBP_OLEDB_Props2__Descrs_Factory::AppendDescrs
  (spDescrs,
   r1);

 assert(spDescrs);
 assert(spDescrs->Count()==nCapacity);

 return structure::not_null_ptr(spDescrs.ptr());
}//CreatePropDescrs

//------------------------------------------------------------------------
oledb_lib::OLEDB_Props2__Data__Descrs::self_cptr
 IBP_OLEDB_Props2__Descrs_Factory__DBINIT_EXT::GetPropDescrs()
{
#ifdef IBP_BUILD_TESTCODE
 return self_type::CreatePropDescrs();
#else
 const IBP_GlobalObjects::TDataAccessor dataAccessor;

 assert(dataAccessor.GetData()
         ->m_spOleDbPropDescrs__DBINIT_EXT);

 assert(dataAccessor.GetData()
         ->m_spOleDbPropDescrs__DBINIT_EXT
         ->IsGuid(ibprovider::IBP_DBPROPSET_INIT));

 assert(dataAccessor.GetData()
         ->m_spOleDbPropDescrs__DBINIT_EXT
         ->IsSpecialGuid(DBPROPSET_DBINITALL));

 return dataAccessor.GetData()->m_spOleDbPropDescrs__DBINIT_EXT.not_null_ptr();
#endif
}//GetPropDescrs

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
