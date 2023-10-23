////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__first_week_day.cpp
//! \brief   Реализация ExtractValue для свойства "first_week_day".
//! \author  Kovalenko Dmitry
//! \date    17.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__first_week_day.h"
#include "source/oledb/props2/ibp_oledb__props2__utils.h"
#include "source/error_services/ibp_error_bug_check.h"

#include <ole_lib/ole_auto/ole_auto_variant.h>
#include <structure/t_str_formatter.h>
#include <structure/t_latin_lower.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//struct IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_day_aliase

/// <summary>
///  Отображение названий дней недели
/// </summary>
struct IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_day_aliase
{
 public:
  /// Имя дня недели [lower latin chars]
  const wchar_t*   day_aliase;

  /// Имя дня недели [lower latin chars]
  const wchar_t*   day_name;

 public:
  bool operator == (const structure::t_const_wstr_box& _Aliase)const;

  bool operator != (const structure::t_const_wstr_box& _Aliase)const
  {
   return !((*this)==_Aliase);
  }
};//struct IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_day_aliase

////////////////////////////////////////////////////////////////////////////////
//struct IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_day_aliase

bool IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_day_aliase::operator == (const structure::t_const_wstr_box& _Aliase)const
{
 assert(this->day_aliase);
 assert(*this->day_aliase);

 const wchar_t* s1=this->day_aliase;

 assert(s1);

 auto       p2(_Aliase.begin());
 auto const e2(_Aliase.end());

 for(;;++s1,++p2)
 {
  if(p2==e2)
   return (*s1)==0;

  if((*s1)==0)
   return false;

  assert(structure::latin_lower(*s1)==(*s1));

  if((*s1)!=structure::latin_lower(*p2))
   return false;
 }//for[ever]
}//operator ==

////////////////////////////////////////////////////////////////////////////////
//struct IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_day_number

/// <summary>
///  Отображение допустимых названий дней недели на номер дня
/// </summary>
struct IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_day_number
{
 public:
  /// Номер дня недели
  long             day_number;

  /// Имя дня недели [lower latin chars]
  const wchar_t*   day_name;

 public:
  bool operator == (const structure::t_const_wstr_box& _Name)const;

  bool operator != (const structure::t_const_wstr_box& _Name)const
  {
   return !((*this)==_Name);
  }
};//struct IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_day_number

////////////////////////////////////////////////////////////////////////////////
//struct IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_day_number

bool IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_day_number::operator == (const structure::t_const_wstr_box& _Name)const
{
 assert(this->day_name);
 assert(*this->day_name);

 const wchar_t* s1=this->day_name;

 auto       p2(_Name.begin());
 auto const e2(_Name.end());

 for(;;++s1,++p2)
 {
  if(p2==e2)
   return (*s1)==0;

  if((*s1)==0)
   return false;

  assert(structure::latin_lower(*s1)==(*s1));
  assert(structure::latin_lower(*p2)==(*p2));

  if((*s1)!=(*p2))
   return false;
 }//for[ever]
}//operator ==

////////////////////////////////////////////////////////////////////////////////
//struct IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_data

struct IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_data
{
 private:
  static const wchar_t sm_dayname__monday[];
  static const wchar_t sm_dayname__tuesday[];
  static const wchar_t sm_dayname__wednesday[];
  static const wchar_t sm_dayname__thursday[];
  static const wchar_t sm_dayname__friday[];
  static const wchar_t sm_dayname__saturday[];
  static const wchar_t sm_dayname__sunday[];

 public:
  static const tag_day_aliase sm_day_aliases[];
  static const tag_day_number sm_day_numbers[];
};//struct IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_data

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day

const wchar_t IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_data::sm_dayname__monday[]
 =L"monday";

//------------------------------------------------------------------------
const wchar_t IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_data::sm_dayname__tuesday[]
 =L"tuesday";

//------------------------------------------------------------------------
const wchar_t IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_data::sm_dayname__wednesday[]
 =L"wednesday";

//------------------------------------------------------------------------
const wchar_t IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_data::sm_dayname__thursday[]
 =L"thursday";

//------------------------------------------------------------------------
const wchar_t IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_data::sm_dayname__friday[]
 =L"friday";

//------------------------------------------------------------------------
const wchar_t IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_data::sm_dayname__saturday[]
 =L"saturday";

//------------------------------------------------------------------------
const wchar_t IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_data::sm_dayname__sunday[]
 =L"sunday";

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_day_aliase
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_data::sm_day_aliases[]=
{
 //! \todo
 //!  Разрешение указания номеров - это достаточно сомнительная идея.
 {L"1"                  ,sm_dayname__monday},
 {L"2"                  ,sm_dayname__tuesday},
 {L"3"                  ,sm_dayname__wednesday},
 {L"4"                  ,sm_dayname__thursday},
 {L"5"                  ,sm_dayname__friday},
 {L"6"                  ,sm_dayname__saturday},
 {L"7"                  ,sm_dayname__sunday},
 {sm_dayname__monday    ,sm_dayname__monday},
 {sm_dayname__tuesday   ,sm_dayname__tuesday},
 {sm_dayname__wednesday ,sm_dayname__wednesday},
 {sm_dayname__thursday  ,sm_dayname__thursday},
 {sm_dayname__friday    ,sm_dayname__friday},
 {sm_dayname__saturday  ,sm_dayname__saturday},
 {sm_dayname__sunday    ,sm_dayname__sunday},
};//tag_data::sm_day_aliases

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_day_number
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::tag_data::sm_day_numbers[]=
{
 {1, sm_dayname__monday},
 {2, sm_dayname__tuesday},
 {3, sm_dayname__wednesday},
 {4, sm_dayname__thursday},
 {5, sm_dayname__friday},
 {6, sm_dayname__saturday},
 {7, sm_dayname__sunday},
};//tag_data::sm_day_numbers

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day

IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::sm_Instance;

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day()
{
}//IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::~IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day()
{
}//~IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::GetInstancePtr()
{
 return &sm_Instance;
}//GetInstancePtr

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::long_type_N
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::GetFirstDayNum(const VARIANT& propValue)
{
 const wchar_t* const c_bug_check_src
  =L"IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::GetFirstDayNum";

 //-----------------------------------------
 if(propValue.vt==VT_EMPTY)
  return long_type_N();

 if(propValue.vt!=VT_BSTR)
 {
  IBP_ThrowBugCheck__UnexpectedPropValueType
   (c_bug_check_src,
    L"#001",
    L"first_week_day",
    propValue.vt);
 }//if

 assert(propValue.vt==VT_BSTR);

 const auto strValue=ole_lib::BStrToBox(propValue.bstrVal);

 const tag_day_number* const x
  =std::find(tag_data::sm_day_numbers,_END_(tag_data::sm_day_numbers),strValue);

 if(x!=_END_(tag_data::sm_day_numbers))
  return long_type_N(x->day_number);

 IBP_ThrowBugCheck__UnexpectedPropValue
  (c_bug_check_src,
   L"#002",
   L"first_week_day",
   strValue);

#if(COMP_BUILD_UNUSED_CODE!=0)
 return long_type_N();
#endif
}//GetFirstDayNum

//IBP_OLEDB_Props2__Handler__ExtractValue interface ----------------------
bool IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::ExtractValue
                                           (const VARIANT& sourceValue,
                                            VARIANT* const pResultValue)const
{
 assert(sourceValue.vt!=VT_EMPTY);
 assert(pResultValue!=nullptr);

 ole_lib::TVariant tmpValue;

 if(!IBP_OLEDB_Props2__Utils::ExtractValue__BSTR(sourceValue,&tmpValue)) //throw
  return false;

 assert(tmpValue.vt==VT_BSTR);

 const auto strValue=structure::trim(ole_lib::BStrToBox(tmpValue.bstrVal));

 const tag_day_aliase* const x
  =std::find(tag_data::sm_day_aliases,_END_(tag_data::sm_day_aliases),strValue);

 if(x==_END_(tag_data::sm_day_aliases))
  return false;

 tmpValue=x->day_name; //throw

 assert(tmpValue.vt==VT_BSTR);
 assert(tmpValue.bstrVal);

 tmpValue.swap(*pResultValue);

 assert(pResultValue->vt==VT_BSTR);
 assert(pResultValue->bstrVal);

 return true;
}//ExtractValue

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
