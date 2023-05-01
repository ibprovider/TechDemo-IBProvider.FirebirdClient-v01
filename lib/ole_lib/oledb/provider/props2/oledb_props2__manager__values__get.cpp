////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++.
//                                                 Dmitry Kovalenko. 08.12.2018.
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/provider/props2/oledb_props2__manager__values.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Manager__Values::tag_internal_get_props_ctx

OLEDB_Props2__Manager__Values::tag_internal_get_props_ctx::tag_internal_get_props_ctx
                                (const OLEDB_Props2__Data__Values* const pValues)
 :m_spValues(structure::not_null_ptr(pValues))
 ,m_external_ctx()
{
}//tag_internal_get_props_ctx

//------------------------------------------------------------------------
OLEDB_Props2__Manager__Values::tag_internal_get_props_ctx::~tag_internal_get_props_ctx()
{
}//~tag_internal_get_props_ctx

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Manager__Values

void OLEDB_Props2__Manager__Values::Helper__PrepareGetValues
                        (tag_internal_get_props_ctx&             op_ctx,
                         const OLEDB_Props2__Data__Descrs* const pDescrs,
                         const DBPROPIDSET*                const pPropIDSet)const
{
 assert(pDescrs);

 //[2018-11-24] Обеспечивается вызывающей стороной
 assert(!pPropIDSet || pPropIDSet->cPropertyIDs==0 || pPropIDSet->rgPropertyIDs);

 assert(!pPropIDSet || ole_lib::GuidEqual(pPropIDSet->guidPropertySet,pDescrs->m_Guid));

 if(pPropIDSet==NULL)
 {
  //запрос значений всех свойств
  for(auto iProp(pDescrs->begin()),_eProp(pDescrs->end());iProp!=_eProp;++iProp)
  {
   if(!op_ctx.m_spValues->HasValueOrDefault(pDescrs->m_Guid,(*iProp).GetPropId()))
    continue;

   this->Helper__PrepareGetValue
    (op_ctx,
     pDescrs->m_Guid,
     *iProp);
  }//for
 }
 else
 if(pPropIDSet->cPropertyIDs==0)
 {
  //запрос значений всех свойств
  for(auto iProp(pDescrs->begin()),_eProp(pDescrs->end());iProp!=_eProp;++iProp)
  {
   this->Helper__PrepareGetValue
    (op_ctx,
     pDescrs->m_Guid,
     *iProp);
  }//for
 }
 else
 {
  assert_hint(pPropIDSet);
  assert_hint(pPropIDSet->cPropertyIDs>0);

  CHECK_READ_TYPED_PTR
   (pPropIDSet->rgPropertyIDs,
    pPropIDSet->cPropertyIDs);

  const DBPROPID*       pPropID=pPropIDSet->rgPropertyIDs;
  const DBPROPID* const ePropID=pPropID+pPropIDSet->cPropertyIDs;

  for(;pPropID!=ePropID;++pPropID)
  {
   auto const xDescr=pDescrs->find(*pPropID);

   if(xDescr!=pDescrs->cend())
   {
    assert((*xDescr).GetPropId()==*pPropID);

    this->Helper__PrepareGetValue
     (op_ctx,
      pDescrs->m_Guid,
      *xDescr);
   }
  }//for
 }//else
}//Helper__PrepareGetValues

//------------------------------------------------------------------------
void OLEDB_Props2__Manager__Values::Helper__PrepareGetValue
                        (tag_internal_get_props_ctx&      op_ctx,
                         REFGUID                          propGuid,
                         const OLEDB_Props2__Data__Descr& Descr)const
{
 return op_ctx.m_spValues->PrepareGetValue
         (op_ctx.m_external_ctx,
          propGuid,
          Descr.GetPropId());
}//Helper__PrepareGetValue

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
