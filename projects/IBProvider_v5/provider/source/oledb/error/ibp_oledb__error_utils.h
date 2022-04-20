////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error_utils.h
//! \brief   Утилиты для работы с OLEDB-ошибками
//! \author  Kovalenko Dmitry
//! \date    03.06.2010
#ifndef _ibp_oledb__error_utils_H_
#define _ibp_oledb__error_utils_H_

#include "source/error_services/ibp_error_codes.h"

#include "source/ibp_forward.h"

#include <ole_lib/oledb/variant/oledb_variant_fwrd.h>

#include <structure/error/t_err_record.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__err
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__ErrorUtils

/// <summary>
///  Утилиты для работы с OLEDB-ошибками
/// </summary>
class IBP_OLEDB__ErrorUtils LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef IBP_OLEDB__ErrorUtils                     self_type;

 public: //typedefs ------------------------------------------------------
  typedef structure::t_err_record                   base_error_record_type;

  typedef t_ibp_error_element                       error_record_type;

  typedef ibp_msg_code_type                         mc_type;

 public:
  static HRESULT add_oledb_error(REFCLSID                      providerClassID,
                                 IErrorRecords*                pErrorRecords,
                                 REFIID                        exc_riid,
                                 const base_error_record_type* pError);

 private:
  static HRESULT helper__add_oledb_error
                                (REFCLSID                      providerClassID,
                                 IErrorRecords*                pErrorRecords,
                                 REFIID                        exc_riid,
                                 const base_error_record_type* pError,
                                 HRESULT                       err_code,
                                 const VARIANT&                varSourceID,
                                 const VARIANT&                varSubSystemID,
                                 mc_type                       msg_code,
                                 size_t                        cArgs,
                                 const oledb_lib::DBVARIANT*   rgArgs);
};//class IBP_OLEDB__ErrorUtils

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
