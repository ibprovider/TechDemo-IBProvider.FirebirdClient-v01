////////////////////////////////////////////////////////////////////////////////
//OLEDB Variant Services. Numeric Installer
//                                               Kovalenko Dmitry. 14.04.2009
#ifndef _oledb_variant_numeric_installer_H_
#define _oledb_variant_numeric_installer_H_

#include <ole_lib/oledb/variant/oledb_variant.h>
#include <structure/t_limits.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class TDBVariant_NumericInstaller

template<bool Signed,size_t NumericSize>
class TDBVariant__NumericInstaller{};

////////////////////////////////////////////////////////////////////////////////
//I1

template<>
class TDBVariant__NumericInstaller<true,1>
{
 public:
  RELEASE_CODE(inline)
  static void exec(DBVARIANT* const pvar,signed __int8 const x)
  {
   assert(pvar);
   assert(pvar->wType==DBTYPE_EMPTY);

   pvar->valI1   =x;
   pvar->wType   =DBTYPE_I1;
  }//exec
};//class TDBVariant__NumericInstaller<true,1>

////////////////////////////////////////////////////////////////////////////////
//UI1

template<>
class TDBVariant__NumericInstaller<false,1>
{
 public:
  RELEASE_CODE(inline)
  static void exec(DBVARIANT* const pvar,unsigned __int8 const x)
  {
   assert(pvar);
   assert(pvar->wType==DBTYPE_EMPTY);

   pvar->valUI1  =x;
   pvar->wType   =DBTYPE_UI1;
  }//exec
};//class TDBVariant__NumericInstaller<false,1>

////////////////////////////////////////////////////////////////////////////////
//I2

template<>
class TDBVariant__NumericInstaller<true,2>
{
 public:
  RELEASE_CODE(inline)
  static void exec(DBVARIANT* const pvar,signed __int16 const x)
  {
   assert(pvar);
   assert(pvar->wType==DBTYPE_EMPTY);

   pvar->valI2   =x;
   pvar->wType   =DBTYPE_I2;
  }//exec
};//class TDBVariant__NumericInstaller<true,2>

////////////////////////////////////////////////////////////////////////////////
//UI2

template<>
class TDBVariant__NumericInstaller<false,2>
{
 public:
  RELEASE_CODE(inline)
  static void exec(DBVARIANT* const pvar,unsigned __int16 const x)
  {
   assert(pvar);
   assert(pvar->wType==DBTYPE_EMPTY);

   pvar->valUI2  =x;
   pvar->wType   =DBTYPE_UI2;
  }//exec
};//class TDBVariant__NumericInstaller<false,2>

////////////////////////////////////////////////////////////////////////////////
//I4

template<>
class TDBVariant__NumericInstaller<true,4>
{
 public:
  RELEASE_CODE(inline)
  static void exec(DBVARIANT* const pvar,signed __int32 const x)
  {
   assert(pvar);
   assert(pvar->wType==DBTYPE_EMPTY);

   pvar->valI4   =x;
   pvar->wType   =DBTYPE_I4;
  }//exec
};//class TDBVariant__NumericInstaller<true,4>

////////////////////////////////////////////////////////////////////////////////
//UI4

template<>
class TDBVariant__NumericInstaller<false,4>
{
 public:
  RELEASE_CODE(inline)
  static void exec(DBVARIANT* const pvar,unsigned __int32 const x)
  {
   assert(pvar);
   assert(pvar->wType==DBTYPE_EMPTY);

   pvar->valUI4  =x;
   pvar->wType   =DBTYPE_UI4;
  }//exec
};//class TDBVariant__NumericInstaller<false,4>

////////////////////////////////////////////////////////////////////////////////
//I8

template<>
class TDBVariant__NumericInstaller<true,8>
{
 public:
  RELEASE_CODE(inline)
  static void exec(DBVARIANT* const pvar,signed __int64 const x)
  {
   assert(pvar);
   assert(pvar->wType==DBTYPE_EMPTY);

   pvar->valI8.QuadPart =x;
   pvar->wType          =DBTYPE_I8;
  }//exec
};//class TDBVariant__NumericInstaller<true,8>

////////////////////////////////////////////////////////////////////////////////
//UI8

template<>
class TDBVariant__NumericInstaller<false,8>
{
 public:
  RELEASE_CODE(inline)
  static void exec(DBVARIANT* const pvar,unsigned __int64 const x)
  {
   assert(pvar);
   assert(pvar->wType==DBTYPE_EMPTY);

   pvar->valUI8.QuadPart =x;
   pvar->wType           =DBTYPE_UI8;
  }//exec
};//class TDBVariant__NumericInstaller<false,8>

////////////////////////////////////////////////////////////////////////////////

template<typename T>
inline void DBVariant__NumericInstaller(DBVARIANT* const pvar,T const x)
{
 typedef structure::t_numeric_limits<T>                                  lt;
 typedef TDBVariant__NumericInstaller<lt::is_signed,sizeof(T)>    installer;

 installer::exec(pvar,x);
}//DBVariant__NumericInstaller

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif