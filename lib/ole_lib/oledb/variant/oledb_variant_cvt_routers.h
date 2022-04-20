////////////////////////////////////////////////////////////////////////////////
//Functions for DBVARIANT conversion
//                                                Kovalenko Dmitry. 21.10.2008
#ifndef _oledb_variant_cvt_routers_H_
#define _oledb_variant_cvt_routers_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <ole_lib/oledb/variant/oledb_variant.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////

HRESULT DBVariant__to_ERROR_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__SCODE_n*      pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_I1_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__I1_n*         pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_I2_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__I2_n*         pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_I4_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__I4_n*         pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_I8_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__I8_n*         pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_UI1_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__UI1_n*        pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_UI2_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__UI2_n*        pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_UI4_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__UI4_n*        pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_UI8_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__UI8_n*        pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_R4_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__R4_n*         pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_R8_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__R8_n*         pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_CY_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__CY_n*         pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_NUMERIC_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__NUMERIC_n*    pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_DECIMAL_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__DECIMAL_n*    pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_DATE_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__DATE_n*       pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_DBDATE_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__DBDATE_n*     pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_DBTIME_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__DBTIME_n*     pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_DBTIME2_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__DBTIME2_n*    pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_DBTIMESTAMP_ex
         (DBVARIANT::LPCCONVCONTEXT     pCvtContext,
          const DBVARIANT&              Source,
          t_oledb_value__DBTIMESTAMP_n* pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_FILETIME_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__FILETIME_n*   pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_STR_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__CPP_STR_n*    pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_WSTR_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__CPP_WSTR_n*   pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_BSTR_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__CPP_BSTR_n*   pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_BOOL_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__CPP_BOOL_n*   pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_GUID_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          t_oledb_value__GUID_n*       pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_BYTES_ex
         (DBVARIANT::LPCCONVCONTEXT      pCvtContext,
          const DBVARIANT&               Source,
          DBVARIANT::bytes_writer_type*  pResult);

//------------------------------------------------------------------------
//! \returns
//!  - S_OK
//!  - S_FALSE values was obtained from NULL-source
//!  - Failed code
HRESULT DBVariant__to_VARIANT_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          VARIANT*                     pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_IUNKNOWN_ex
         (DBVARIANT::LPCCONVCONTEXT       pCvtContext,
          const DBVARIANT&                Source,
          REFIID                          ResultIID,
          t_oledb_value__CPP_IUNKNOWN_n*  pResult);

//------------------------------------------------------------------------
HRESULT DBVariant__to_IDISPATCH_ex
         (DBVARIANT::LPCCONVCONTEXT       pCvtContext,
          const DBVARIANT&                Source,
          t_oledb_value__CPP_IDISPATCH_n* pResult);

////////////////////////////////////////////////////////////////////////////////

HRESULT DBVariant__to_ARRAY_ex
         (DBVARIANT::LPCCONVCONTEXT    pCvtContext,
          const DBVARIANT&             Source,
          DBTYPE                       ArrayType,
          REFIID                       ResultIID,
          SAFEARRAY**                  pResult);

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
