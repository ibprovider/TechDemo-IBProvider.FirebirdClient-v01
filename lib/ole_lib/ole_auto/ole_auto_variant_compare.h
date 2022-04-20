////////////////////////////////////////////////////////////////////////////////
//! \ingroup  ole_lib
//! \file     ole_auto_variant_compare.h
//! \brief    Comparison of VARIANT values
//! \author   Kovalenko Dmitry
//! \date     16.02.2017
#ifndef _ole_auto_variant_compare_H_
#define _ole_auto_variant_compare_H_

#include <ole_lib/ole_auto/ole_auto_variant_cmp_codes.h>
#include <OleAuto.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//Comparison function

EnumVariantCmpCode Variant_Compare(const VARIANT& v1,const VARIANT& v2);

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
#endif
