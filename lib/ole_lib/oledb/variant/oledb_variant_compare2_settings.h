////////////////////////////////////////////////////////////////////////////////
//DBVARIANT Compare Settings.
//                                                  Kovalenko Dmtry. 04.10.2017.
#ifndef _oledb_variant_compare2_settings_H_
#define _oledb_variant_compare2_settings_H_

#include <structure/t_common.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class TDBVariantCompare2_Settings

class TDBVariantCompare2_Settings
{
 public:
  bool null_is_less;

 public:
  TDBVariantCompare2_Settings();
};//class TDBVariantCompare2_Settings

////////////////////////////////////////////////////////////////////////////////
//class TDBVariantCompare2_Settings

inline TDBVariantCompare2_Settings::TDBVariantCompare2_Settings()
 :null_is_less(true)
{
}

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
