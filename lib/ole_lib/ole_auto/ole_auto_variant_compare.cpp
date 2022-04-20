////////////////////////////////////////////////////////////////////////////////
//! \ingroup  ole_lib
//! \file     ole_auto_variant_compare.cpp
//! \brief    Comparison of VARIANT values
//! \author   Kovalenko Dmitry
//! \date     16.02.2017
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/ole_auto/ole_auto_variant_compare.h>
#include <ole_lib/ole_auto/variant/comparator/ole_auto_variant__comparator_context__std.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////

EnumVariantCmpCode Variant_Compare(const VARIANT& v1,
                                   const VARIANT& v2)
{
 variant_comparator::TVariantComparatorContext_STD ctx;

 return ctx.Compare(v1,v2);
}//Variant_Compare

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
