////////////////////////////////////////////////////////////////////////////////
//! \ingroup  ole_lib
//! \file     ole_auto_utils.cc
//! \brief    Utilities for work with OLE Automation structures/objects
//! \author   Kovalenko Dmitry
//! \date     05.04.2004.
#ifndef _ole_auto_utils_CC_
#define _ole_auto_utils_CC_

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//Unpack VARIANT structure. Remove VT_VARIANT|VT_BYREF levels

inline const VARIANT* Variant_UnpackIgnoreNULL(const VARIANT* pVariant)
{
 if((pVariant=Variant_Unpack(pVariant))==NULL || pVariant->vt==VT_NULL)
  return NULL;

 return pVariant;
}//Variant_UnpackIgnoreNULL

//------------------------------------------------------------------------
inline VARTYPE Variant_DetectType(const VARIANT* const pVariant,VARTYPE vtDefault)
{
 return pVariant?VARTYPE(pVariant->vt):VARTYPE(vtDefault);
}//Variant_DetectType

//------------------------------------------------------------------------
inline bool Variant_IsMissingArg(const VARIANT* const pVariant)
{
 if(pVariant==NULL)
  return true;

 return pVariant->vt==VT_ERROR && pVariant->scode==DISP_E_PARAMNOTFOUND;
}//Variant_IsMissingArg

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
#endif
