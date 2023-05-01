////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++.
//                                                 Dmitry Kovalenko. 25.04.2023.
#ifndef _oledb_props2__manager__values__get_CC_
#define _oledb_props2__manager__values__get_CC_

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Manager__Values

template<class TCallCtx>
HRESULT OLEDB_Props2__Manager__Values::GetProperties
                          (TCallCtx&                               callCtx,
                           const OLEDB_Props2__Data__Values* const pValues,
                           ULONG                             const cPropertyIDSets,
                           const DBPROPIDSET                       rgPropertyIDSets[],
                           ULONG*                            const pcPropertySets,
                           DBPROPSET**                       const prgPropertySets,
                           PFnFilter                         const pfnGetFilter)const
{
 assert(pValues);

 if(pcPropertySets)
  (*pcPropertySets)=0;

 if(prgPropertySets)
  (*prgPropertySets)=nullptr;

 //if(cPropertyIDSets!=0 && !rgPropertyIDSets)
 // return E_INVALIDARG;

 if(!pcPropertySets)
  return E_INVALIDARG;

 if(!prgPropertySets)
  return E_INVALIDARG;

 //-----------------------------------------
 if(cPropertyIDSets!=0)
 {
  if(!rgPropertyIDSets)
   return E_INVALIDARG;

  for(const DBPROPIDSET *p=rgPropertyIDSets,* const _e=rgPropertyIDSets+cPropertyIDSets;p!=_e;++p)
  {
   if(p->cPropertyIDs!=0 && !p->rgPropertyIDs)
    return E_INVALIDARG;
  }//for iSet
 }//if cPropertyIDSets!=0

 //-----------------------------------------
 //количество возвращаемым наборов
 ULONG cDestDbSets=0;

 //подготовка контекста операции загрузки значений свойств
 tag_internal_get_props_ctx op_ctx(pValues);

 if(cPropertyIDSets==0)
 {
  //определяем число наборов, удовлетворяющих фильтру
  for(auto iPropSet(m_descr_sets.begin()),_ePropSet(m_descr_sets.end());
      iPropSet!=_ePropSet;
      ++iPropSet)
  {
   assert(*iPropSet);

   if(pfnGetFilter)
   {
    switch(DEBUG_CODE(const auto r=)pfnGetFilter(*iPropSet))
    {
     case DBPROPSTATUS_OK:
      break;

     default:
      assert_msg(false,"r="<<r);

     case DBPROPSTATUS_NOTSUPPORTED:
      continue;
    }//switch
   }//if pfnGetFilter

   this->Helper__PrepareGetValues
    (op_ctx,
     *iPropSet,
     nullptr); //throw

   ++cDestDbSets;
  }//for iPropSet
 }
 else
 {
  //возвращаем запрошенные наборы
  assert_hint(cPropertyIDSets>0);

  CHECK_READ_TYPED_PTR(rgPropertyIDSets,cPropertyIDSets);

  for(auto pCurIDSet=rgPropertyIDSets,pEndIDSet=rgPropertyIDSets+cPropertyIDSets;
      pCurIDSet!=pEndIDSet;
      ++pCurIDSet)
  {
   const OLEDB_Props2__Data__Descrs* const
    pPropertySet
     =this->Helper__FindDescrs(pCurIDSet->guidPropertySet);

   if(!pPropertySet)
    continue;

   if(pfnGetFilter)
   {
    switch(DEBUG_CODE(const auto r=)pfnGetFilter(pPropertySet))
    {
     case DBPROPSTATUS_OK:
      break;

     default:
      assert_msg(false,"r="<<r);

     case DBPROPSTATUS_NOTSUPPORTED:
      continue;
    }//switch
   }//if pfnGetFilter

   this->Helper__PrepareGetValues
    (op_ctx,
     pPropertySet,
     pCurIDSet); //throw
  }//for pCurIDSet

  cDestDbSets=cPropertyIDSets;
 }//else

 if(cDestDbSets==0)
  return NOERROR; //???

 //число не поддерживаемых наборов
 ULONG cNotSupportedDbSets=0;

 //локальный указатель на возвращаемые наборы значений свойств
 CO_MEM_POINTER3(DBPROPSET)
  spDestDbSets
   (ole_lib::CoTaskMemAllocate2<DBPROPSET>(cDestDbSets)); //throw

 assert(spDestDbSets);

 try // catch
 {
  if(cPropertyIDSets==0) //получение всех доступных наборов
  {
   //перечислитель элементов spPropSets
   DBPROPSET*             pCurDestDbSet=spDestDbSets.ptr();
   const DBPROPSET* const pEndDestDbSet=pCurDestDbSet+cDestDbSets;

   auto        pSet(m_descr_sets.begin());
  #ifndef NDEBUG
   auto const _eSet(m_descr_sets.end());
  #endif

   for(;pCurDestDbSet!=pEndDestDbSet;++pSet)
   {
    assert(pSet!=_eSet);
    assert(*pSet);

    //фильтр
    if(pfnGetFilter)
    {
     switch(DEBUG_CODE(const auto r=)pfnGetFilter(*pSet))
     {
      case DBPROPSTATUS_OK:
       break;

      default:
       assert_msg(false,"r="<<r);

      case DBPROPSTATUS_NOTSUPPORTED:
       continue;
     }//switch
    }//if pfnGetFilter

    assert(pCurDestDbSet<pEndDestDbSet);

    //установка GUID
    pCurDestDbSet->guidPropertySet=(*pSet)->m_Guid;

    //получение значений всех свойств
    this->Helper__GetValues
     (callCtx,
      op_ctx,
      *pSet,
      nullptr,
      *pCurDestDbSet); //throw

    assert(pCurDestDbSet->cProperties==0 || pCurDestDbSet->rgProperties);

    //переходим на заполнение следующего набора
    ++pCurDestDbSet;
   }//for pCurDestSet

   assert(pCurDestDbSet==pEndDestDbSet);
  }//if cPropertyIDSets == 0
  else
  {
   //возвращаем указанные наборы

   assert_hint(cPropertyIDSets>0);
   assert(rgPropertyIDSets);

   assert(cDestDbSets==cPropertyIDSets);

   //перечислитель элементов spPropSets
   DBPROPSET*             pCurDestDbSet=spDestDbSets.ptr();
   const DBPROPSET* const pEndDestDbSet=pCurDestDbSet+cDestDbSets;

   CHECK_READ_TYPED_PTR(rgPropertyIDSets,cPropertyIDSets);

   for(const DBPROPIDSET* pCurIDSet=rgPropertyIDSets;
       pCurDestDbSet!=pEndDestDbSet;
       ++pCurDestDbSet,++pCurIDSet)
   {
    assert(pCurIDSet!=(rgPropertyIDSets+cPropertyIDSets));

    pCurDestDbSet->guidPropertySet=pCurIDSet->guidPropertySet;

    const OLEDB_Props2__Data__Descrs* const
     pPropertySet
      =this->Helper__FindDescrs(pCurDestDbSet->guidPropertySet);

    //проверка через фильтр
    if(pPropertySet)
    {
     switch(DEBUG_CODE(const auto r=)(pfnGetFilter?pfnGetFilter(pPropertySet):DBPROPSTATUS_OK))
     {
      case DBPROPSTATUS_OK:
      {
       this->Helper__GetValues
        (callCtx,
         op_ctx,
         pPropertySet,
         pCurIDSet,
         *pCurDestDbSet);

       assert(pCurDestDbSet->cProperties==0 || pCurDestDbSet->rgProperties!=NULL);

       continue;
      }//case

      default:
       assert_msg(false,"r="<<r);

      case DBPROPSTATUS_NOTSUPPORTED:
       break;
     }//switch
    }//if pPropertySet

    //набор не поддерживается

    ++cNotSupportedDbSets;

    //набор не поддерживается - поэтому выделяем
    //память и отмечаем что DBPROPSTATUS_NOTSUPPORTED
    ODS_LEVEL_3("ERROR: GetProp "<<ole_lib::guid_to_string(pCurIDSet->guidPropertySet));

    if(pCurIDSet->cPropertyIDs==0)
     continue; //да он пустой - нас кинули :)

    assert_hint(pCurIDSet->cPropertyIDs>0);

    const auto cProps=pCurIDSet->cPropertyIDs;

    assert_hint(cProps>0);

    _VERIFY(pCurDestDbSet->rgProperties=ole_lib::CoTaskMemAllocate2<DBPROP>(cProps)); //throw

    //CoTaskMemAllocate2 возвращает обнуленную память

    pCurDestDbSet->cProperties=cProps;

    auto       pDest=pCurDestDbSet->rgProperties;
    auto const eDest=pCurDestDbSet->rgProperties+cProps;

    const DBPROPID* pQueryID=pCurIDSet->rgPropertyIDs;

    //отмечаем все свойства неизвестного набора как неподдерживаемые
    for(;pDest!=eDest;++pDest,++pQueryID)
    {
     pDest->dwPropertyID = *pQueryID;
     pDest->dwStatus     = DBPROPSTATUS_NOTSUPPORTED;

     assert(pDest->dwOptions==0);
     assert(pDest->vValue.vt==VT_EMPTY);
    }//for pDest

    assert(pDest==eDest);
   }//for pCurIDSet

   assert(pCurDestDbSet==pEndDestDbSet);
  }//else - возвращаем указанные наборы
 }
 catch(...)
 {
  //произошел сбой - поэтому очищаем все, что мы создали

  assert(spDestDbSets);

  //есть данные. анализ выхода из защищенной секции
  CHECK_READ_WRITE_TYPED_PTR(spDestDbSets.ptr(),cDestDbSets);

  const DBPROPSET*         pDestDbSet=spDestDbSets;
  const DBPROPSET* const  _eDestDbSet=pDestDbSet+cDestDbSets;

  for(;pDestDbSet!=_eDestDbSet;++pDestDbSet)
  {
   if(!pDestDbSet->rgProperties)
   {
    assert(pDestDbSet->cProperties==0);
    continue;
   }//if

   assert(pDestDbSet->rgProperties);
   assert(pDestDbSet->cProperties>0);

   CHECK_READ_WRITE_TYPED_PTR
    (pDestDbSet->rgProperties,
     pDestDbSet->cProperties);

   DBPROP*              pDbProp=pDestDbSet->rgProperties;
   const DBPROP* const _eDbProp=pDbProp+pDestDbSet->cProperties;

   for(;pDbProp!=_eDbProp;++pDbProp)
   {
    _VERIFY_EQ(ole_lib::Variant_Clear(&pDbProp->vValue),S_OK);
   }//for pDbProp

   assert(pDbProp==_eDbProp);

   LCPI_OS__CoTaskMemFree(pDestDbSet->rgProperties);
  }//for pDestDbSet

  assert(pDestDbSet==_eDestDbSet);

  throw;
 }//catch

 // Работа прошла без приключений

 assert(spDestDbSets);

 CHECK_READ_WRITE_TYPED_PTR(spDestDbSets.ptr(),cDestDbSets);

 //анализ количества неподдерживаемых свойств
 size_t cTotalProps=0;
 size_t cNotSupportedProps=0;

 const DBPROPSET*        pDestDbSet=spDestDbSets;
 const DBPROPSET* const _eDestDbSet=pDestDbSet+cDestDbSets;

 for(;pDestDbSet!=_eDestDbSet;++pDestDbSet)
 {
  if(pDestDbSet->cProperties==0)
  {
   assert(pDestDbSet->rgProperties==NULL);
   continue;
  }

  assert(pDestDbSet->rgProperties!=NULL);

  CHECK_READ_WRITE_TYPED_PTR
   (pDestDbSet->rgProperties,
    pDestDbSet->cProperties);

  cTotalProps+=pDestDbSet->cProperties;

  const DBPROP*        pDbProp=pDestDbSet->rgProperties;
  const DBPROP* const _eDbProp=pDbProp+pDestDbSet->cProperties;

  for(;pDbProp!=_eDbProp;++pDbProp)
  {
   if(pDbProp->dwStatus!=DBPROPSTATUS_OK)
    ++cNotSupportedProps;
  }//for pProp
 }//for pPropSet

 assert(cNotSupportedProps<=cTotalProps);
 assert(cNotSupportedDbSets<=cDestDbSets);

 (*pcPropertySets)   =cDestDbSets;
 (*prgPropertySets) =spDestDbSets.release();

 if(cNotSupportedProps>0)
  return (cNotSupportedProps<cTotalProps)?DB_S_ERRORSOCCURRED:DB_E_ERRORSOCCURRED;

 if(cNotSupportedDbSets>0)
  return (cNotSupportedDbSets<cDestDbSets)?DB_S_ERRORSOCCURRED:DB_E_ERRORSOCCURRED;

 return S_OK;
}//GetProperties

//Helper methods ---------------------------------------------------------
template<class TCallCtx>
void OLEDB_Props2__Manager__Values::Helper__GetValues
                        (TCallCtx&                               callCtx,
                         tag_internal_get_props_ctx&             op_ctx,
                         const OLEDB_Props2__Data__Descrs* const pDescrs,
                         const DBPROPIDSET*                const pPropIDSet,
                         DBPROPSET&                              PropSet)const
{
 assert(pDescrs);

 assert(!pPropIDSet || ole_lib::GuidEqual(pPropIDSet->guidPropertySet,pDescrs->m_Guid));

 assert(PropSet.cProperties==0 && !PropSet.rgProperties);

 assert(!pPropIDSet || pPropIDSet->cPropertyIDs==0 || pPropIDSet->rgPropertyIDs);

 ODS_LEVEL_2("OLEDB_Props2__Manager__Values::Helper__GetValues(guid:"<<ole_lib::guid_to_string(pDescrs->m_Guid)<<")");

 //------------------------------------------------------------------
 PropSet.rgProperties=nullptr;
 PropSet.cProperties =0;

 //подсчет количества возвращаемых свойств
 ULONG cProps=0;

 if(!pPropIDSet)
 {
  //возвращаем только свойства для которых были установлены значения,
  //или у которых есть значение по умолчанию.

 ODS_LEVEL_2("OLEDB_Props2__Manager__Values::Helper__GetValues - return NOT EMPTY values");

  auto        iSrcDescr=pDescrs->begin();
  auto const _eSrcDescr=pDescrs->end();

  for(;iSrcDescr!=_eSrcDescr;++iSrcDescr)
  {
   if(!op_ctx.m_spValues->HasValueOrDefault(pDescrs->m_Guid,(*iSrcDescr).GetPropId()))
    continue;

   ++cProps;
  }//for
 }
 else
 if(pPropIDSet->cPropertyIDs==0)
 {
  //возвращаем все доступные свойства
 ODS_LEVEL_2("OLEDB_Props2__Manager__Values::Helper__GetValues - returns ALL values");

  assert(structure::can_numeric_cast(&cProps,pDescrs->Count()));

  structure::static_numeric_cast(&cProps,pDescrs->Count());
 }
 else
 {
  //явно передали список свойств
 ODS_LEVEL_2("OLEDB_Props2__Manager__Values::Helper__GetValues - returns QUERIED values");

  cProps=pPropIDSet->cPropertyIDs;
 }//else

 ODS_LEVEL_2("OLEDB_Props2__Manager__Values::Helper__GetValues - cProps:"<<cProps);

 if(cProps==0)
  return;//ничего возвращать не надо.

 assert_hint(cProps>0);

 CO_MEM_POINTER3(DBPROP)
  spProps(ole_lib::CoTaskMemAllocate2<DBPROP>(cProps)); //throw

 assert(spProps);

 //Инициализация
 assert(VT_EMPTY==0);

 //CoTaskMemAllocate2 возвращает обнуленную память

 try // catch(...)
 {
  if(!pPropIDSet)
  {
   //возвращаем только свойства для которых были установлены значения,
   //или у которых есть значение по умолчанию.

   DBPROP*              pDestProp=spProps.ptr();
   const DBPROP* const _eDestProp=pDestProp+cProps;

   auto        iSrcDescr=pDescrs->begin();
   auto const _eSrcDescr=pDescrs->end();

   for(;pDestProp!=_eDestProp;++iSrcDescr)
   {
    assert(iSrcDescr!=_eSrcDescr);

    if(!op_ctx.m_spValues->HasValueOrDefault(pDescrs->m_Guid,(*iSrcDescr).GetPropId()))
     continue;

    this->Helper__GetValue
     (callCtx,
      op_ctx,
      pDescrs->m_Guid,
      *iSrcDescr,
      *pDestProp); //throw

    ++pDestProp;
   }//for
  }
  else
  if(pPropIDSet->cPropertyIDs==0)
  {
   DBPROP*              pDestProp=spProps.ptr();
#ifndef NDEBUG
   const DBPROP* const _eDestProp=pDestProp+cProps;
#endif

   auto        iSrcDescr=pDescrs->begin();
   auto const _eSrcDescr=pDescrs->end();

   for(;iSrcDescr!=_eSrcDescr;++iSrcDescr,++pDestProp)
   {
    assert(pDestProp!=_eDestProp);

    this->Helper__GetValue
     (callCtx,
      op_ctx,
      pDescrs->m_Guid,
      *iSrcDescr,
      *pDestProp); //throw
   }//for iSrcDescr

   assert(iSrcDescr==_eSrcDescr);
   assert(pDestProp==_eDestProp);
  }
  else
  {
   assert_hint(pPropIDSet);
   assert_hint(pPropIDSet->cPropertyIDs>0);
   assert(pPropIDSet->cPropertyIDs==cProps);

   assert(ole_lib::GuidEqual(pPropIDSet->guidPropertySet,pDescrs->m_Guid));

   DBPROP*              pDestProp=spProps.ptr();
#ifndef NDEBUG
   const DBPROP* const _eDestProp=pDestProp+cProps;
#endif

   const auto*        pPropID=pPropIDSet->rgPropertyIDs;
   const auto* const _ePropID=pPropID+cProps;

   for(;pPropID!=_ePropID;++pPropID,++pDestProp)
   {
    assert(pDestProp!=_eDestProp);

    auto const xDescr=pDescrs->find(*pPropID);

    if(xDescr!=pDescrs->cend())
    {
     assert((*xDescr).GetPropId()==*pPropID);

     this->Helper__GetValue
      (callCtx,
       op_ctx,
       pDescrs->m_Guid,
       *xDescr,
       *pDestProp); //throw

     continue;
    }//if

    assert(xDescr==pDescrs->cend());

    //свойcтво не поддерживается
    ODS_LEVEL_3("ERROR: GetProp 0x"<<std::hex<<*pPropID<<" - not supported");

    pDestProp->dwPropertyID =*pPropID;
    pDestProp->dwStatus     =DBPROPSTATUS_NOTSUPPORTED;
   }//for pPropID

   assert(pPropID==_ePropID);
   assert(pDestProp==_eDestProp);
  }//else
 }
 catch(...)
 {
  //откат изменений
  DBPROP*              pDestProp=spProps.ptr();
  const DBPROP* const _eDestProp=pDestProp+cProps;

  for(;pDestProp!=_eDestProp;++pDestProp)
  {
   _VERIFY_EQ(ole_lib::Variant_Clear(&pDestProp->vValue),S_OK);
  }

  assert(pDestProp==_eDestProp);

  throw;
 }//catch

 //возвращаем результат нашей работы
 PropSet.rgProperties=spProps.release();
 PropSet.cProperties =cProps;
}//Helper__GetValues

//------------------------------------------------------------------------
template<class TCallCtx>
void OLEDB_Props2__Manager__Values::Helper__GetValue
                        (TCallCtx&                         callCtx,
                         tag_internal_get_props_ctx&       op_ctx,
                         REFGUID                           propGuid,
                         const OLEDB_Props2__Data__Descr&  Descr,
                         DBPROP&                           DbProp)const
{
 // typedef struct tagDBPROP
 // {
 //  DBPROPID      dwPropertyID;
 //  DBPROPOPTIONS dwOptions;
 //  DBPROPSTATUS  dwStatus;
 //  DBID          colid;
 //  VARIANT       vValue;
 // } DBPROP;

 assert(DbProp.vValue.vt==VT_EMPTY);
 assert(DbProp.dwStatus==DBPROPSTATUS_OK);
 assert(DbProp.dwOptions==0);
 assert(TDBID::IsEqual(DbProp.colid,DB_NULLID));

 //-----------------------------------------
 DbProp.dwPropertyID=Descr.GetPropId();

 DbProp.dwStatus=DBPROPSTATUS_OK;

 //-----------------------------------------
 try
 {
  if(op_ctx.m_spValues->GetValue(op_ctx.m_external_ctx,
                                 propGuid,
                                 DbProp.dwPropertyID,
                                 &DbProp.dwOptions,
                                 &DbProp.vValue)) //throw
  {
   //Container return the property's value+option
   assert(DbProp.dwPropertyID==Descr.GetPropId());

   DbProp.dwStatus=DBPROPSTATUS_OK;
  }
  else
  {
   //No property value. will return EMPTY.

   assert(DbProp.dwPropertyID==Descr.GetPropId());

   assert(DbProp.dwStatus  ==DBPROPSTATUS_OK);
   assert(DbProp.vValue.vt ==VT_EMPTY);
   assert(DbProp.dwOptions ==0);

   DbProp.dwStatus=DBPROPSTATUS_OK;

   ole_lib::Variant_Clear_Throw(&DbProp.vValue);

   if((Descr.GetPropFlags()&DBPROPFLAGS_REQUIRED)==DBPROPFLAGS_REQUIRED)
    DbProp.dwOptions=DBPROPOPTIONS_REQUIRED;
   else
    DbProp.dwOptions=DBPROPOPTIONS_OPTIONAL;
  }//else
 }
 catch(const std::exception& exc)
 {
  ODS_LEVEL_3("ERROR: GetProp 0x"<<std::hex<<Descr.GetPropId()<<std::dec<<" - "<<exc.what());

  callCtx.Errors().add__no_throw(exc); // no throw!

  ole_lib::Variant_Clear_Throw(&DbProp.vValue);

  DbProp.dwStatus=DBPROPSTATUS_NOTAVAILABLE;
 }//catch

 /*END, no code*/
}//Helper__GetValue

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
