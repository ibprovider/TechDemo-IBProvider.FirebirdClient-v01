////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Compare Result Codes.
//                                                  Kovalenko Dmtry. 04.10.2017.
#ifndef _oledb_variant_cmp_codes_H_
#define _oledb_variant_cmp_codes_H_

#include <structure/t_common.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//enum EnumDBVariantCmpCode

enum EnumDBVariantCmpCode
{
 DBVariantCmpCode__ok__equal,
 DBVariantCmpCode__ok__less,
 DBVariantCmpCode__ok__great,
 DBVariantCmpCode__ok__not_equal,

 DBVariantCmpCode__err__generic,
 DBVariantCmpCode__err__not_supported,
};//enum EnumDBVariantCmpCode

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
