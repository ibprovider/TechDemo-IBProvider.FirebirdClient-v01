////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error_text_factory.h
//! \brief   Фабрика класса IBP_OLEDB__ErrorText
//! \author  Kovalenko Dmitry
//! \date    01.02.2011
#ifndef _ibp_oledb__error_text_factory_H_
#define _ibp_oledb__error_text_factory_H_

#include "source/error_services/ibp_error_codes.h"
#include <ole_lib/ole_lib.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////

//реализация находится в "ibp_error_text.cpp"
ole_lib::IUnknownPtr IBP_CreateErrorText(ibp_msg_code_type mce_code_0);

ole_lib::IUnknownPtr IBP_CreateErrorText_ForWin32ErrorMsg(DWORD errorCode);

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
