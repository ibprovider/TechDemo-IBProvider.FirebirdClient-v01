////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/variant/oledb_variant_cvt.h>
#include "structure/t_str_formatter.h"

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class TDBTypeConverterPropertyNames

const wchar_t TDBTypeConverterPropertyNames::GuidToText__LowerCase[]
 =L"STD:GuidToText__LowerCase";

const wchar_t TDBTypeConverterPropertyNames::GuidToText__FBrackets[]
 =L"STD:GuidToText__FBrackets";

////////////////////////////////////////////////////////////////////////////////
//class TDBTypeConverterPropertyValues

const wchar_t TDBTypeConverterPropertyValues::Bool__True[]
 =L"true";

const wchar_t TDBTypeConverterPropertyValues::Bool__False[]
 =L"false";

////////////////////////////////////////////////////////////////////////////////
//class TDBTypeConverterPropertyUtils

TDBTypeConverterPropertyUtils::bool_value_type_n
 TDBTypeConverterPropertyUtils::GetValue_Bool_N(const ctx_type* const pCtx,
                                                const wchar_t*  const pPropName)
{
 assert(pCtx);
 assert(pPropName);

 //-----------------------------------------
 const wchar_t c_bugcheck_place[]
  =L"TDBTypeConverterPropertyUtils::GetValue_Bool_N";

 //-----------------------------------------
 const wchar_t* const pPropValue=pCtx->GetConverterProperty(pPropName);

 if(!pPropValue)
  return bool_value_type_n();

 if(wcscmp(pPropValue,values_type::Bool__True)==0)
  return bool_value_type_n(true);

 if(wcscmp(pPropValue,values_type::Bool__False)==0)
  return bool_value_type_n(false);

 self_type::Helper__ThrowBugCheck__UnknownPropertyValue
  (c_bugcheck_place,
   L"#001",
   pPropName,
   pPropValue);
}//GetValue_Bool_N

//------------------------------------------------------------------------
const wchar_t* TDBTypeConverterPropertyUtils::ToValue_Bool(bool const v)
{
 if(v)
  return values_type::Bool__True;

 return values_type::Bool__False;
}//ToValue_Bool

//Helper methods ---------------------------------------------------------
void TDBTypeConverterPropertyUtils::Helper__ThrowBugCheck__UnknownPropertyValue
               (const wchar_t* const CheckPlace,
                const wchar_t* const CheckPoint,
                const wchar_t* const pPropName,
                const wchar_t* const pPropValue)
{
 assert(CheckPlace);
 assert(CheckPoint);
 assert(pPropName);
 assert(pPropValue);

 structure::str_formatter
  fmsg("[BUG CHECK] Unexpected OLE DB type converter property value: \"%4\". "
       "Property name: \"%3\". Check point [%1][%2].");

 fmsg<<CheckPlace
     <<CheckPoint
     <<pPropName
     <<pPropValue;

 throw std::runtime_error(fmsg.str());
}//Helper__ThrowBugCheck__UnknownPropertyValue

////////////////////////////////////////////////////////////////////////////////
//struct TDBTypeConverter - Basic struct for type converters

TDBTypeConverter::~TDBTypeConverter()
{;}

////////////////////////////////////////////////////////////////////////////////
//struct TDBTypeConverter_BindingTest

TDBTypeConverter_BindingTest::~TDBTypeConverter_BindingTest()
{;}

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
