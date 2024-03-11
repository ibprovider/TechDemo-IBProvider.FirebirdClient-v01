////////////////////////////////////////////////////////////////////////////////
//Services for work with VARTYPE
//                                               Kovalenko Dmitry. 15.02.2008
#ifndef _ole_auto_variant_type_info_H_
#define _ole_auto_variant_type_info_H_

#include <lcpi/lib/.config.h>

#include <OleAuto.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
#ifdef VT_INT_PTR
# error "OLD SDK. Correct your VARENUM at wtypes.h from SDK. VT_INT_PTR=37"
#endif

//------------------------------------------------------------------------
#ifdef VT_UINT_PTR
# error "OLD SDK. Correct your VARENUM at wtypes.h from SDK. VT_UINT_PTR=38"
#endif

////////////////////////////////////////////////////////////////////////////////
//class TVariantTypeInfo

class TVariantTypeInfo
{
 public: //typedefs ------------------------------------------------------
  typedef HRESULT (*PF_VariantClear)  (VARIANT* pVar);
  typedef HRESULT (*PF_VariantCopy)   (VARIANT* pDest,const VARIANT* pSource);
  typedef HRESULT (*PF_VariantCopyInd)(VARIANT* pDest,const VARIANT* pSource);

 public: //---------------------------------------------------------------
  VARTYPE       vt;
  LPCWSTR       name;
  size_t        size;

  WORD          oledb_type_id;

 public:
  PF_VariantClear    pfVariantClear;
  PF_VariantCopy     pfVariantCopy;
  PF_VariantCopyInd  pfVariantCopyInd;
};//class TVariantTypeInfo

////////////////////////////////////////////////////////////////////////////////

const TVariantTypeInfo* GetVariantTypeInfo(VARTYPE vt);

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
#endif
