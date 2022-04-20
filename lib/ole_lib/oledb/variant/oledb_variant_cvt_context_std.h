////////////////////////////////////////////////////////////////////////////////
//Standard implementation of DBVARIANT conversion context
//                                                 Kovalenko Dmitry. 23.10.2008
#ifndef _oledb_variant_cvt_context_std_H_
#define _oledb_variant_cvt_context_std_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <ole_lib/oledb/variant/oledb_variant_cvt.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class TDBVariantCvtContext_Std

class TDBVariant_TypeCvtContext_Std:public TDBTypeConverterContext
{
 private:
  typedef TDBVariant_TypeCvtContext_Std                self_type;
  typedef TDBTypeConverterContext                      inherited;

  TDBVariant_TypeCvtContext_Std(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef const TDBTypeConverter*                      LPCTYPECONVERTOR;

 public:
  TDBVariant_TypeCvtContext_Std()
  {;}

  //TTypeConvContext interface -------------------------------------------
  virtual const wchar_t* GetConverterProperty(const wchar_t* PropName)const COMP_W000004_OVERRIDE;

  virtual bool EqualType(DBTYPE wFromType,DBTYPE wToType)const COMP_W000004_OVERRIDE;

  virtual LPCTYPECONVERTOR GetTypeConverter(DBTYPE wFromType,DBTYPE wToType)const COMP_W000004_OVERRIDE;
};//class TDBVariant_TypeCvtContext_Std

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
