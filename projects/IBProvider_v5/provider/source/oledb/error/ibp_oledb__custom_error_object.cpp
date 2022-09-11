////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__custom_error_object.cpp
//! \brief   Стандартная реализация OLEDB CustomErrorObject.
//! \author  Kovalenko Dmitry
//! \date    03.08.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/error/ibp_oledb__custom_error_object.h"

#include "source/error_services/ibp_get_custom_error_object.h"
#include "source/error_services/ibp_error_build_message.h"
#include "source/error_services/ibp_error_utils.h"
//#include "source/error_services/ibp_error_codes.h"
#include <ole_lib/ole_auto/ole_auto_variant.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__CustomErrorObject

OLE_LIB__DEFINE_DEBUG_COM_LIVE(IBP_OLEDB__CustomErrorObject)

//------------------------------------------------------------------------
IBP_OLEDB__CustomErrorObject::IBP_OLEDB__CustomErrorObject
                                   (IUnknown*                      const pUnkOuter,
                                    const structure::t_err_record* const pErrRecord)
 :inherited(pUnkOuter)
 ,m_spErrRecord(structure::not_null_ptr(pErrRecord))
{
 assert(m_spErrRecord);

 OLE_LIB__CREATE_COMPONENT();
}//IBP_OLEDB__CustomErrorObject

//------------------------------------------------------------------------
IBP_OLEDB__CustomErrorObject::~IBP_OLEDB__CustomErrorObject()
{
 OLE_LIB__DESTROY_COMPONENT();
}//IBP_OLEDB__CustomErrorObject

//------------------------------------------------------------------------
HRESULT IBP_OLEDB__CustomErrorObject::Init()
{
 assert(m_spErrRecord);

 const HRESULT base_init_hr=inherited::Init();

 if(FAILED(base_init_hr))
  return base_init_hr;

 assert(base_init_hr==S_OK);

 //Запрашиваем у описания ошибки оригинальный CustomErrorObject

 if(const t_ibp_get_custom_error_object* const x=dynamic_cast<const t_ibp_get_custom_error_object*>(m_spErrRecord.ptr()))
  m_spOriginalCEO=x->get_custom_error_object(/*pUnkOuter*/this);

 return base_init_hr;
}//Init

//Root interface ---------------------------------------------------------
OLE_LIB__DEFINE_ROOT_INTERFACE(IBP_OLEDB__CustomErrorObject)
  if(riid!=IID_IUnknown && m_spOriginalCEO)
  {
   //запрашиваем интерфейс у агрегированного объекта
   const HRESULT hr=m_spOriginalCEO->QueryInterface(riid,ppv);

   if(hr!=E_NOINTERFACE)
    return hr;

   assert((*ppv)==nullptr);

   (*ppv)=nullptr;
  }//if

  using namespace sqlncli;

  OLE_LIB__ROOT_STATIC_INTERFACE(ISQLServerErrorInfo);
OLE_LIB__END_ROOT_INTERFACE(inherited)

//ISQLServerErrorInfo interface ------------------------------------------
HRESULT __stdcall IBP_OLEDB__CustomErrorObject::GetErrorInfo
                             (/*[out]*/ sqlncli::SSERRORINFO** const ppErrorInfo,
                              /*[out]*/ OLECHAR**              const ppStringsBuffer)
{
 /// Стандартная реализация интерфейса ISQLServerErrorInfo. Возвращаем
 /// описание ошибки, которое предоставляет m_spErrRecord

 OLE_LIB_IMETHOD_PROLOG

 LCPI_OS__SetErrorInfo(0,nullptr);

 if(ppErrorInfo!=nullptr)
  (*ppErrorInfo)=nullptr;

 if(ppStringsBuffer!=nullptr)
  (*ppStringsBuffer)=nullptr;

 if(ppErrorInfo==nullptr || ppStringsBuffer==nullptr)
  return E_INVALIDARG;

 OLE_LIB__DECLARE_HR(S_OK)

 _OLE_TRY_
 {
  assert(m_spErrRecord);

  std::wstring err_description;

  if(!m_spErrRecord->get_description(MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL),
                                     nullptr,
                                     &err_description))
  {
   //assign - error message unavailabled

   if(!TIBP_MessageTextBuilder::Build(&err_description,
                                      ole_lib::TVariant::empty_variant,
                                      ibp_mce_text__unavailable_0,
                                      MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL),
                                      0,
                                      reinterpret_cast<const oledb_lib::DBVARIANT*>(NULL),
                                      E_FAIL))
   {
    ole_lib::t_base_com_error::throw_error(DB_E_BADLOOKUPID);
   }//if
  }//if

  //----------------------------------------

  //выделенный буфер обнуляется
  CO_MEM_POINTER3(sqlncli::SSERRORINFO)
   tmp__spErrorInfo(ole_lib::CoTaskMemAllocate2<sqlncli::SSERRORINFO>(1)); //throw

  assert(tmp__spErrorInfo);

  //---------------------------------------- формируем StringsBuffer
  size_t szStringsBuffer=0;

  szStringsBuffer+=err_description.size();
  szStringsBuffer+=1;

  //выделенный буфер обнуляется
  CO_MEM_POINTER3(OLECHAR)
   tmp__spStringsBuffer(ole_lib::CoTaskMemAllocate2<OLECHAR>(szStringsBuffer)); //throw

  assert(tmp__spStringsBuffer);

  //----
        OLECHAR* const _bStringsBuffer=tmp__spStringsBuffer.ptr();
  const OLECHAR* const _eStringsBuffer=_bStringsBuffer+szStringsBuffer;

  OLECHAR* pStringsBuffer=_bStringsBuffer;

  //---------------------------------------- заполняем StringsBuffer и ErrorInfo

  //------ pwszMessage, pwszServer (empty), pwszProcedure (empty)
  tmp__spErrorInfo->pwszMessage=pStringsBuffer;

  pStringsBuffer=structure::copy(err_description.cbegin(),
                                 err_description.cend(),
                                 pStringsBuffer,
                                 const_cast<OLECHAR*>(_eStringsBuffer)).second;

  assert(pStringsBuffer>=_bStringsBuffer);
  assert(pStringsBuffer<_eStringsBuffer);

  tmp__spErrorInfo->pwszServer    =pStringsBuffer;
  tmp__spErrorInfo->pwszProcedure =pStringsBuffer;

  (*pStringsBuffer)=0; //terminate symbol

  ++pStringsBuffer;

  assert(pStringsBuffer==_eStringsBuffer);

  //------
  tmp__spErrorInfo->wLineNumber=0;

  //! \todo
  //!  Нужно разобраться с назначением этого поля
  tmp__spErrorInfo->bState=1;

  //------

  //Отображем HRESULT на код ошибки MSSQL.
  // Используем два нейтральных кода для предупреждения и для критической ошибки

  const HRESULT err_hr=IBP_MapErrorRecordToHRESULT(m_spErrRecord);

  if(err_hr==S_OK)
  {
   //реально странно.
   tmp__spErrorInfo->lNative=0;
   tmp__spErrorInfo->bClass =0;
  }
  else
  if(!FAILED(err_hr)) //warning
  {
   tmp__spErrorInfo->lNative=14634; //MSSQL: Warning: %s.
   tmp__spErrorInfo->bClass =10;
  }
  else
  {
   tmp__spErrorInfo->lNative=18052; //MSSQL: Ошибка: %1!, серьезность: %2!, состояние: %3!.
   tmp__spErrorInfo->bClass =16;
  }//else

  //---------------------------------------- Завершение работы
  (*ppErrorInfo)=tmp__spErrorInfo.release();

  (*ppStringsBuffer)=tmp__spStringsBuffer.release();
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetErrorInfo

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
