////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_parameter_list_parser.h
//! \brief   Класс для обработки списка параметров
//! \author  Kovalenko Dmitry
//! \date    05.12.2018
#ifndef _ibp_parameter_list_parser_H_
#define _ibp_parameter_list_parser_H_

#include "source/ibp_memory.h"
#include <structure/t_parameter_list.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

template<typename charT>
struct IBP_ParameterListParserSelector LCPI_CPP_CFG__CLASS__FINAL
{
 using type
  =structure::t_basic_parameter_list
    <charT,
     IBP_MemoryAllocator>;
};//struct IBP_ParameterListParserSelector

////////////////////////////////////////////////////////////////////////////////

using IBP_ParameterListParser_WSTR
 =IBP_ParameterListParserSelector<wchar_t>::type;

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
