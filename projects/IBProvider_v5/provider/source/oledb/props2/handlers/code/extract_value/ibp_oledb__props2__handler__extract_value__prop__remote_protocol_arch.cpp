////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__remote_protocol_arch.cpp
//! \brief   Реализация ExtractValue для свойства "remote:protocol_arch".
//! \author  Kovalenko Dmitry
//! \date    18.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__remote_protocol_arch.h"
#include "source/oledb/props2/ibp_oledb__props2__utils.h"

#include <ole_lib/ole_auto/ole_auto_variant.h>

#include <structure/utilities/string/equal_to_string.h>
#include <structure/t_fix_vector.h>
#include <structure/t_latin.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////

#if(IBP_ENGINE_DIRECT_FB==0)
# error Incorrect usage of file!
#endif

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch

IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch::sm_Instance;

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch::IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch()
{
}//IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch::~IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch()
{
}//~IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch::GetInstancePtr()
{
 return &sm_Instance;
}//GetInstancePtr

//IBP_OLEDB_Props2__Handler__ExtractValue interface ----------------------
bool IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_protocol_arch::ExtractValue
                                           (const VARIANT& sourceValue,
                                            VARIANT* const pResultValue)const
{
 assert(sourceValue.vt!=VT_EMPTY);
 assert(pResultValue!=nullptr);

 ole_lib::TVariant tmpValue;

 if(!IBP_OLEDB_Props2__Utils::ExtractValue__BSTR(sourceValue,&tmpValue)) //throw
  return false;

 assert(tmpValue.vt==VT_BSTR);

 const auto strPropValue=ole_lib::BStrToBox(tmpValue.bstrVal);

 auto       sPropValue(strPropValue.begin());

 auto const ePropValue(strPropValue.end());

 sPropValue=structure::miss_space(sPropValue,ePropValue);

 if(sPropValue==ePropValue)
  return false;

 assert(sPropValue!=ePropValue);

 //список идентификаторов обнаруженных имен
 structure::t_fix_vector<(_DIM_(ibprovider::g_IBP_PropValuesFor__remote__parch)),size_t>
  detected_parchs;

 //---------------------------------------- проверка списка имен

 for(;;)
 {
  if(sPropValue==ePropValue)
  {
   //ошибка в формате значения
   return false;
  }//if

  auto const sName(sPropValue);

  sPropValue=std::find(sPropValue,ePropValue,L',');

  auto const eName=structure::miss_space_back(sName,sPropValue);

  if(sName==eName)
  {
   //пустое имя - такого быть не должно
   return false;
  }

  //ищем имя в списке допустимых значений
  typedef structure::t_latin_equal_i<wchar_t> eq_op;

  size_t iArch=0;

  for(;iArch!=_DIM_(ibprovider::g_IBP_PropValuesFor__remote__parch);++iArch)
  {
   assert(ibprovider::g_IBP_PropValuesFor__remote__parch[iArch]);

   if(structure::equal_to_string(sName,
                                 eName,
                                 ibprovider::g_IBP_PropValuesFor__remote__parch[iArch],
                                 eq_op()))
   {
    break;
   }//if
  }//for iArch

  if(iArch==_DIM_(ibprovider::g_IBP_PropValuesFor__remote__parch))
  {
   //неизвестное имя протокола
   return false;
  }//if

  assert(iArch<_DIM_(ibprovider::g_IBP_PropValuesFor__remote__parch));

  //выявление дубля
  if(std::find(detected_parchs.cbegin(),detected_parchs.cend(),iArch)!=detected_parchs.cend())
  {
   //повторное определение имени
   return false;
  }//if

  //регистрируем индекс найденного имени
  assert(!detected_parchs.full());

  detected_parchs.push_back(iArch);

  //----------------------------------------
  if(sPropValue==ePropValue)
   break;

  //пропуск запятой и обработка следующего имени

  assert((*sPropValue)==L',');

  ++sPropValue;

  sPropValue=structure::miss_space(sPropValue,ePropValue);
 }//for[ever]

 //формируем нормализованную строку со списком имен.
 assert(!detected_parchs.empty());

 std::wstring tmpStrValue;

 for(size_t i=0,_c(detected_parchs.size());i!=_c;++i)
 {
  if(i!=0)
   tmpStrValue+=L',';

  assert(detected_parchs[i]<_DIM_(ibprovider::g_IBP_PropValuesFor__remote__parch));

  assert(ibprovider::g_IBP_PropValuesFor__remote__parch[detected_parchs[i]]);

  tmpStrValue+=ibprovider::g_IBP_PropValuesFor__remote__parch[detected_parchs[i]];
 }//for i

 tmpValue=tmpStrValue; //throw

 assert(tmpValue.vt==VT_BSTR);
 assert(tmpValue.bstrVal);

 tmpValue.swap(*pResultValue);

 assert(pResultValue->vt==VT_BSTR);
 assert(pResultValue->bstrVal);

 return true;
}//ExtractValue

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
