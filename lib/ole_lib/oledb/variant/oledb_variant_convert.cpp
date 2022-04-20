////////////////////////////////////////////////////////////////////////////////
//Implemenation of conversion method of DBVARIANT
//                                   Kovalenko Dmitry. 24 september, 2001.
#include <_pch_.h>
#pragma hdrstop

#ifndef OLEDB_LIB_TYPE_CONVERTOR_OWN_CPP
# include <ole_lib/oledb/variant/converter/common/oledb_var_cvt__common.h>
# include <ole_lib/oledb/variant/converter/oledb_var_cvt_impl_helper.h>
# include <ole_lib/oledb/variant/oledb_variant_sstream.h>
# include <ole_lib/oledb/variant/oledb_variant_ibp_sstreams.h>
#endif

#include <ole_lib/oledb/variant/oledb_variant_cvt_routers.h>
#include <ole_lib/oledb/variant/oledb_variant_cvt_context_std.h>
#include <ole_lib/oledb/variant/oledb_variant_cvt_utils.h>
#include <ole_lib/oledb/variant/oledb_xvariant_stream_writer.h>
#include <ole_lib/oledb/oledb_datetime_services.h>
#include <ole_lib/ole_auto/ole_auto_variant_type_info.h>
#include <structure/t_numeric_cast.h>
#include <structure/t_function.h>
#include <structure/t_latin.h>
#include <structure/t_zero.h>

#include <math.h>
#include <float.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////

namespace oledb_lib_utils{
////////////////////////////////////////////////////////////////////////////////

#ifndef OLEDB_LIB_TYPE_CONVERTOR_OWN_CPP

#include <ole_lib/oledb/variant/converter/oledb_var_cvt_interfaces.cxx>

#include <ole_lib/oledb/variant/converter/oledb_var_cvt_impl_helper.cxx>

#include <ole_lib/oledb/variant/converter/common/oledb_var_cvt__common.cxx>

#include <ole_lib/oledb/variant/converter/simple/empty/oledb_var_cvt__empty.cxx>

#include <ole_lib/oledb/variant/converter/simple/null/oledb_var_cvt__null.cxx>

#include <ole_lib/oledb/variant/converter/simple/error/oledb_var_cvt__error.cxx>

#include <ole_lib/oledb/variant/converter/simple/i1/oledb_var_cvt__i1.cxx>

#include <ole_lib/oledb/variant/converter/simple/i2/oledb_var_cvt__i2.cxx>

#include <ole_lib/oledb/variant/converter/simple/i4/oledb_var_cvt__i4.cxx>

#include <ole_lib/oledb/variant/converter/simple/i8/oledb_var_cvt__i8.cxx>

#include <ole_lib/oledb/variant/converter/simple/ui1/oledb_var_cvt__ui1.cxx>

#include <ole_lib/oledb/variant/converter/simple/ui2/oledb_var_cvt__ui2.cxx>

#include <ole_lib/oledb/variant/converter/simple/ui4/oledb_var_cvt__ui4.cxx>

#include <ole_lib/oledb/variant/converter/simple/ui8/oledb_var_cvt__ui8.cxx>

#include <ole_lib/oledb/variant/converter/simple/r4/oledb_var_cvt__r4.cxx>

#include <ole_lib/oledb/variant/converter/simple/r8/oledb_var_cvt__r8.cxx>

#include <ole_lib/oledb/variant/converter/simple/cy/oledb_var_cvt__cy.cxx>

#include <ole_lib/oledb/variant/converter/simple/decimal/oledb_var_cvt__decimal.cxx>

#include <ole_lib/oledb/variant/converter/simple/numeric/oledb_var_cvt__numeric.cxx>

#include <ole_lib/oledb/variant/converter/simple/date/oledb_var_cvt__date.cxx>

#include <ole_lib/oledb/variant/converter/simple/dbdate/oledb_var_cvt__dbdate.cxx>

#include <ole_lib/oledb/variant/converter/simple/dbtime/oledb_var_cvt__dbtime.cxx>

#include <ole_lib/oledb/variant/converter/simple/dbtime2/oledb_var_cvt__dbtime2.cxx>

#include <ole_lib/oledb/variant/converter/simple/dbtimestamp/oledb_var_cvt__dbtimestamp.cxx>

#include <ole_lib/oledb/variant/converter/simple/filetime/oledb_var_cvt__filetime.cxx>

#include <ole_lib/oledb/variant/converter/simple/str/oledb_var_cvt__str.cxx>

#include <ole_lib/oledb/variant/converter/simple/wstr/oledb_var_cvt__wstr.cxx>

#include <ole_lib/oledb/variant/converter/simple/bstr/oledb_var_cvt__bstr.cxx>

#include <ole_lib/oledb/variant/converter/simple/bool/oledb_var_cvt__bool.cxx>

#include <ole_lib/oledb/variant/converter/simple/guid/oledb_var_cvt__guid.cxx>

#include <ole_lib/oledb/variant/converter/simple/bytes/oledb_var_cvt__bytes.cxx>

#include <ole_lib/oledb/variant/converter/simple/variant/oledb_var_cvt__variant.cxx>

#include <ole_lib/oledb/variant/converter/simple/iunknown/oledb_var_cvt__iunknown.cxx>

#include <ole_lib/oledb/variant/converter/simple/idispatch/oledb_var_cvt__idispatch.cxx>

#include <ole_lib/oledb/variant/converter/array/i1/oledb_var_cvt__array_i1.cxx>

#include <ole_lib/oledb/variant/converter/array/i2/oledb_var_cvt__array_i2.cxx>

#include <ole_lib/oledb/variant/converter/array/i4/oledb_var_cvt__array_i4.cxx>

#include <ole_lib/oledb/variant/converter/array/i8/oledb_var_cvt__array_i8.cxx>

#include <ole_lib/oledb/variant/converter/array/ui1/oledb_var_cvt__array_ui1.cxx>

#include <ole_lib/oledb/variant/converter/array/ui2/oledb_var_cvt__array_ui2.cxx>

#include <ole_lib/oledb/variant/converter/array/ui4/oledb_var_cvt__array_ui4.cxx>

#include <ole_lib/oledb/variant/converter/array/ui8/oledb_var_cvt__array_ui8.cxx>

#include <ole_lib/oledb/variant/converter/array/r4/oledb_var_cvt__array_r4.cxx>

#include <ole_lib/oledb/variant/converter/array/r8/oledb_var_cvt__array_r8.cxx>

#include <ole_lib/oledb/variant/converter/array/cy/oledb_var_cvt__array_cy.cxx>

#include <ole_lib/oledb/variant/converter/array/decimal/oledb_var_cvt__array_decimal.cxx>

#include <ole_lib/oledb/variant/converter/array/numeric/oledb_var_cvt__array_numeric.cxx>

#include <ole_lib/oledb/variant/converter/array/bool/oledb_var_cvt__array_bool.cxx>

#include <ole_lib/oledb/variant/converter/array/error/oledb_var_cvt__array_error.cxx>

#include <ole_lib/oledb/variant/converter/array/variant/oledb_var_cvt__array_variant.cxx>

#include <ole_lib/oledb/variant/converter/array/date/oledb_var_cvt__array_date.cxx>

#include <ole_lib/oledb/variant/converter/array/dbdate/oledb_var_cvt__array_dbdate.cxx>

#include <ole_lib/oledb/variant/converter/array/dbtime/oledb_var_cvt__array_dbtime.cxx>

#include <ole_lib/oledb/variant/converter/array/dbtime2/oledb_var_cvt__array_dbtime2.cxx>

#include <ole_lib/oledb/variant/converter/array/dbtimestamp/oledb_var_cvt__array_dbtimestamp.cxx>

#include <ole_lib/oledb/variant/converter/array/filetime/oledb_var_cvt__array_filetime.cxx>

#include <ole_lib/oledb/variant/converter/array/guid/oledb_var_cvt__array_guid.cxx>

#include <ole_lib/oledb/variant/converter/array/bstr/oledb_var_cvt__array_bstr.cxx>

#include <ole_lib/oledb/variant/converter/array/str/oledb_var_cvt__array_str.cxx>

#include <ole_lib/oledb/variant/converter/array/wstr/oledb_var_cvt__array_wstr.cxx>

#include <ole_lib/oledb/variant/converter/array/bytes/oledb_var_cvt__array_bytes.cxx>

#include <ole_lib/oledb/variant/converter/array/iunknown/oledb_var_cvt__array_iunknown.cxx>

#include <ole_lib/oledb/variant/converter/array/idispatch/oledb_var_cvt__array_idispatch.cxx>

#endif //OLEDB_LIB_TYPE_CONVERTOR_OWN_CPP

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb_lib_utils*/

////////////////////////////////////////////////////////////////////////////////

// to signed char
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_i1.cxx>

// to signed __int16
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_i2.cxx>

// to signed __int32
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_i4.cxx>

// to byte
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_ui1.cxx>

// to bool
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_bool.cxx>

// to unsigned __int16
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_ui2.cxx>

// to unsigned __int32
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_ui4.cxx>

// to signed __int64
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_i8.cxx>

// to unsigned __int64
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_ui8.cxx>

// to CY
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_cy.cxx>

// to float
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_r4.cxx>

// to double
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_r8.cxx>

// to numeric
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_numeric.cxx>

// to decimal
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_decimal.cxx>

// to ERROR
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_error.cxx>

// to str
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_str.cxx>

// to wstr
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_wstr.cxx>

// to bstr
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_bstr.cxx>

// to variant
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_variant.cxx>

// to guid
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_guid.cxx>

// to IUnknown*
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_iunknown.cxx>

// to IDispatch*
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_idispatch.cxx>

// to date
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_date.cxx>

// to dbdate
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_dbdate.cxx>

// to dbtime
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_dbtime.cxx>

// to dbtimestamp
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_dbtimestamp.cxx>

// to filetime
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_filetime.cxx>

// to bytes
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_bytes.cxx>

// to array
#include <ole_lib/oledb/variant/converter/to/oledb_var_cvt__to_array.cxx>

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib