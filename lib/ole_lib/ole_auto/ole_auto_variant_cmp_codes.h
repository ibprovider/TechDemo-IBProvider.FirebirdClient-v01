////////////////////////////////////////////////////////////////////////////////
//Variant Compare Result Codes.
//                                                  Kovalenko Dmtry. 16.02.2017.
#ifndef _ole_auto_variant_cmp_codes_H_
#define _ole_auto_variant_cmp_codes_H_

#include <ole_lib/ole_lib_cfg.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//enum EnumVariantCmpCode

enum EnumVariantCmpCode
{
 VariantCmpCode__ok__equal,
 VariantCmpCode__ok__less,
 VariantCmpCode__ok__great,
 VariantCmpCode__ok__not_equal,

 VariantCmpCode__err__generic,
 VariantCmpCode__err__not_supported,
};//enum EnumVariantCmpCode

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
#endif
