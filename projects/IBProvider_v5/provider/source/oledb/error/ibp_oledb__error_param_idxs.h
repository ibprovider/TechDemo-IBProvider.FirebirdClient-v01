////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error_param_idxs.h
//! \brief   Описание индексов параметров ошибки
//! \author  Kovalenko Dmitry
//! \date    05.12.2014
#ifndef _ibp_oledb__error_param_idxs_H_
#define _ibp_oledb__error_param_idxs_H_

#include <structure/t_common.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//enum

enum
{
 ibp_oledb_err_param_idx__source_id         =0,

 ibp_oledb_err_param_idx__subsystem_id      =1,

 ibp_oledb_err_param_idx__arg0              =2,
};//enum

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
