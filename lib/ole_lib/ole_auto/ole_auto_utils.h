////////////////////////////////////////////////////////////////////////////////
//! \ingroup  ole_lib
//! \file     ole_auto_utils.h
//! \brief    Utilities for work with OLE Automation structures/objects
//! \author   Kovalenko Dmitry
//! \date     05.04.2004.
#ifndef _ole_auto_utils_H_
#define _ole_auto_utils_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <structure/t_common.h>
#include <OleAuto.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//Unpack VARIANT structure. Remove VT_VARIANT|VT_BYREF levels

//return:
// - E_FAIL: detect the pointer self-reference
HRESULT Variant_Unpack(const VARIANT** ppResult,const VARIANT* pVariant,const VARIANT* NullPtr=NULL);

const VARIANT* Variant_Unpack(const VARIANT* pVariant,const VARIANT* NullPtr=NULL); //throw

inline const VARIANT* Variant_UnpackIgnoreNULL(const VARIANT* pVariant); //throw

inline VARTYPE Variant_DetectType(const VARIANT* const pVariant,VARTYPE vtDefault);

inline bool Variant_IsMissingArg(const VARIANT* const pVariant);

////////////////////////////////////////////////////////////////////////////////

HRESULT Variant_Clear(VARIANT* pVariant);

HRESULT Variant_Copy(VARIANT* pDest,const VARIANT* pSource);

HRESULT Variant_CopyInd(VARIANT* pDest,const VARIANT* pSource);

////////////////////////////////////////////////////////////////////////////////
//Throw version

void Variant_Clear_Throw(VARIANT* pVariant);

void Variant_Copy_Throw(VARIANT* pDest,const VARIANT* pSource);

void Variant_CopyInd_Throw(VARIANT* pDest,const VARIANT* pSource);

////////////////////////////////////////////////////////////////////////////////
//SafeArray Functions

HRESULT SafeArray_Destroy(SAFEARRAY* pSA);

HRESULT SafeArray_Copy(SAFEARRAY* psa,SAFEARRAY** pout);

HRESULT SafeArray_GetVarType(SAFEARRAY* psa,VARTYPE* pElementType);

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib

////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/ole_auto/ole_auto_utils.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
