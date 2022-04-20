////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Components. Structures for oledb type converters
//                                                Kovalenko Dmitry. 14.01.2018.
#ifndef _oledb_variant_cvt_H_
#define _oledb_variant_cvt_H_

#include <ole_lib/oledb/variant/oledb_variant_cvt_fwrd.h>
#include <oledb.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//containings

class TDBTypeConverterPropertyNames;
class TDBTypeConverterPropertyValues;
class TDBTypeConverterPropertyDefaults;
class TDBTypeConverterPropertyUtils;

struct TDBTypeConverter;
struct TDBTypeConverter_BindingTest;
struct TDBTypeConverterContext;

////////////////////////////////////////////////////////////////////////////////
//class TDBTypeConverterPropertyNames

class TDBTypeConverterPropertyNames
{
 public:
  //Lower case symbols
  static const wchar_t GuidToText__LowerCase[];

  //Figure brackets around
  static const wchar_t GuidToText__FBrackets[];
};//class TDBTypeConverterPropertyNames

////////////////////////////////////////////////////////////////////////////////
//class TDBTypeConverterPropertyValues

class TDBTypeConverterPropertyValues
{
 public:
  static const wchar_t Bool__True[];

  static const wchar_t Bool__False[];
};//class TDBTypeConverterPropertyValues

////////////////////////////////////////////////////////////////////////////////
//class TDBTypeConverterPropertyDefaults

class TDBTypeConverterPropertyDefaults
{
 public:
  //Lower case symbols
  static const bool GuidToText__LowerCase
    =false;

  //Figure brackets around
  static const bool GuidToText__FBrackets
   =false;
};//class TDBTypeConverterPropertyDefaults

////////////////////////////////////////////////////////////////////////////////
//class TDBTypeConverterPropertyUtils

class TDBTypeConverterPropertyUtils
{
 private:
  typedef TDBTypeConverterPropertyUtils               self_type;

 public:
  typedef TDBTypeConverterContext                     ctx_type;
  typedef TDBTypeConverterPropertyValues              values_type;

  typedef structure::t_value_with_null<bool>          bool_value_type_n;

 public:
  static bool_value_type_n GetValue_Bool_N
          (const ctx_type* pCtx,
           const wchar_t*  pPropName);

 public:
  static const wchar_t* ToValue_Bool
          (bool v);

 private:
  COMP_CONF_DECLSPEC_NORETURN
  static void Helper__ThrowBugCheck__UnknownPropertyValue
               (const wchar_t* CheckPlace,
                const wchar_t* CheckPoint,
                const wchar_t* pPropName,
                const wchar_t* pPropValue);
};//class TDBTypeConverterPropertyUtils

////////////////////////////////////////////////////////////////////////////////
//struct TDBTypeConverterCode

struct TDBTypeConverterCode
{
 static const HRESULT data_overflow
  =DB_E_DATAOVERFLOW;

 static const HRESULT numeric_overflow
  =DB_E_DATAOVERFLOW;
};//struct TDBTypeConverterCode

////////////////////////////////////////////////////////////////////////////////
//struct TDBTypeConverter - Basic struct for type converters

struct TDBTypeConverter
{
 public:
  virtual ~TDBTypeConverter();
};//struct TDBTypeConverter

////////////////////////////////////////////////////////////////////////////////
//struct TDBTypeConverter_BindingTest

struct TDBTypeConverter_BindingTest
{
 public:
  virtual ~TDBTypeConverter_BindingTest();

  virtual bool CanConvertTo(const TDBTypeConverterContext* pConvCtx,
                            const DBBINDING&               Bind)const=0;
};//struct TDBTypeConverter_BindingTest

////////////////////////////////////////////////////////////////////////////////
//struct TDBTypeConverterContext

struct COMP_CONF_DECLSPEC_NOVTABLE TDBTypeConverterContext
{
 public:
  virtual const wchar_t* GetConverterProperty(const wchar_t* PropName)const=0;

  virtual bool EqualType(DBTYPE wFromType,DBTYPE wToType)const=0;

  virtual const TDBTypeConverter* GetTypeConverter(DBTYPE wFromType,DBTYPE wToType)const=0;
};//struct TDBTypeConverterContext

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
