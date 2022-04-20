////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb
//! \file    ibp_oledb__prop__value_var_types.h
//! \brief   Определение идентификаторов VT-типов для OLE DB свойств провайдера
//! \author  Kovalenko Dmitry
//! \date    05.09.2011
#ifndef _ibp_oledb__prop__value_var_types_H_
#define _ibp_oledb__prop__value_var_types_H_

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////

#if(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_AMD64)

# define IBP_VT_WINDOW_HANDLE                VT_I8

#elif(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_X86)

# define IBP_VT_WINDOW_HANDLE                VT_I4

#else

# error Unexpected Platform ID!

#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
