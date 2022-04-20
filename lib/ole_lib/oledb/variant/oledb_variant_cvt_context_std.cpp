////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/variant/oledb_variant_cvt_context_std.h>
#include <ole_lib/oledb/variant/oledb_variant.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class TDBVariantCvtContext_Std

const wchar_t*
 TDBVariant_TypeCvtContext_Std::GetConverterProperty(const wchar_t* const DEBUG_CODE(PropName))const
{
 assert(PropName);

 return nullptr;
}//GetConverterProperty

//------------------------------------------------------------------------
bool TDBVariant_TypeCvtContext_Std::EqualType(DBTYPE const wFromType,
                                              DBTYPE const wToType)const
{
 return OLEDB_EXTRACT_DBTYPE(wFromType)==OLEDB_EXTRACT_DBTYPE(wToType);
}//EqualType

//------------------------------------------------------------------------
TDBVariant_TypeCvtContext_Std::LPCTYPECONVERTOR
 TDBVariant_TypeCvtContext_Std::GetTypeConverter(DBTYPE const wFromType,
                                                 DBTYPE const wToType)const
{
 return DBVARIANT::GetTypeConverter(wFromType,wToType);
}//GetTypeConverter

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
