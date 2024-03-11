////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_base64.h
//! \brief   Класс для работы с BASE64
//! \author  Kovalenko Dmitry
//! \date    03.07.2016
#ifndef _ibp_base64_H_
#define _ibp_base64_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

void IBP_OctetsToBase64(std::string* result,
                        size_t       cbOctets,
                        const void*  pOctets);

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
